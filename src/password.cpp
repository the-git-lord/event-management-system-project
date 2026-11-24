#include <array>
#include <cstdint>
#include <iomanip>
#include <random>
#include <sstream>
#include <vector>

#include "password.hpp"

namespace {

// First 32 bits of the fractional parts of the cube roots of the first 64 prime numbers
const std::array<std::uint32_t, 64> K = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Rotate the bits of x right by n places
std::uint32_t rotr(std::uint32_t x, int n) {
    return (x >> n) | (x << (32 - n));
}

// Turn bytes into a hex string, two characters per byte
std::string toHex(const std::vector<std::uint8_t>& bytes) {
    std::ostringstream out;
    for (std::uint8_t byte : bytes)
        out << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    return out.str();
}

}

std::string sha256(const std::string& input) {
    // Starting hash values: first 32 bits of the fractional parts of the square roots of the first 8 prime numbers
    std::array<std::uint32_t, 8> h = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Padding: add a 1 bit, then 0s until 8 bytes short of a multiple of 64,
    // then the original length in bits as a 64-bit number
    std::vector<std::uint8_t> data(input.begin(), input.end());
    std::uint64_t bitLength = static_cast<std::uint64_t>(data.size()) * 8;

    data.push_back(0x80);
    while (data.size() % 64 != 56)
        data.push_back(0x00);
    for (int i = 7; i >= 0; i--)
        data.push_back(static_cast<std::uint8_t>(bitLength >> (i * 8)));

    // Process the data in 64-byte chunks
    for (std::size_t chunk = 0; chunk < data.size(); chunk += 64) {
        std::array<std::uint32_t, 64> w;

        for (int i = 0; i < 16; i++) {
            w[i] = (static_cast<std::uint32_t>(data[chunk + 4 * i]) << 24) 
                 | (static_cast<std::uint32_t>(data[chunk + 4 * i + 1]) << 16)
                 | (static_cast<std::uint32_t>(data[chunk + 4 * i + 2]) << 8)
                 |  static_cast<std::uint32_t>(data[chunk + 4 * i + 3]);
        }

        for (int i = 16; i < 64; i++) {
            std::uint32_t s0 = rotr(w[i - 15], 7) ^ rotr(w[i - 15], 18) ^ (w[i - 15] >> 3);
            std::uint32_t s1 = rotr(w[i - 2], 17) ^ rotr(w[i - 2], 19) ^ (w[i - 2] >> 10);
            w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        }

        std::uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        std::uint32_t e = h[4], f = h[5], g = h[6], hh = h[7];

        for (int i = 0; i < 64; i++) {
            std::uint32_t S1 = rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25);
            std::uint32_t ch = (e & f) ^ (~e & g);
            std::uint32_t temp1 = hh + S1 + ch + K[i] + w[i];
            std::uint32_t S0 = rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22);
            std::uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            std::uint32_t temp2 = S0 + maj;

            hh = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        h[0] += a;  h[1] += b; h[2] += c; h[3] += d;
        h[4] += e;  h[5] += f; h[6] += g; h[7] += hh;
    }

    // Write the 8 hash values out as 32 bytes
    std::vector<std::uint8_t> digest;
    for (std::uint32_t value : h) {
        digest.push_back(static_cast<std::uint8_t>(value >> 24));
        digest.push_back(static_cast<std::uint8_t>(value >> 16));
        digest.push_back(static_cast<std::uint8_t>(value >> 8));
        digest.push_back(static_cast<std::uint8_t>(value));
    }

    return toHex(digest);
}

std::string generateSalt() {
    std::random_device random;
    std::uniform_int_distribution<int> byte(0, 255);

    std::vector<std::uint8_t> salt;
    for (int i = 0; i < 16; i++)
        salt.push_back(static_cast<std::uint8_t>(byte(random)));

    return toHex(salt);
}

std::string hashPassword(const std::string& password, const std::string& salt) {
    return sha256(salt + password);
}