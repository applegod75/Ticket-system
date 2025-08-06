#include <openssl/evp.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <random>

#define SHA256_DIGEST_LENGTH 32
const std::string CHARACTERS[61] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z","a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

std::string SHA256(const std::string& input) {
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int lengthOfHash = 0;

    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if (!context)
        throw std::runtime_error("EVP_MD_CTX_new failed");

    if (EVP_DigestInit_ex(context, EVP_sha256(), nullptr) != 1)
        throw std::runtime_error("EVP_DigestInit_ex failed");

    if (EVP_DigestUpdate(context, input.c_str(), input.length()) != 1)
        throw std::runtime_error("EVP_DigestUpdate failed");

    if (EVP_DigestFinal_ex(context, hash, &lengthOfHash) != 1)
        throw std::runtime_error("EVP_DigestFinal_ex failed");

    EVP_MD_CTX_free(context);

    std::stringstream ss;
    for (unsigned int i = 0; i < lengthOfHash; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

    return ss.str();
}


std::string RandomStringGen(int length) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<>distribution(0, 61);
    std::string RandStr;
    for (int i = 0; i < length; i++) {
        RandStr += CHARACTERS[distribution(generator)];
    }
    return  RandStr;
}

std::vector<std::string> TicketGenerator(int amount) {
    std::vector<std::string> ReturnVal;
    for (int i = 0; i < amount; i++) {
        ReturnVal.push_back(SHA256(RandomStringGen(rand() % 32)));
        
    }
    return ReturnVal;
}

std::vector<std::string> TicketGeneratorFast(int amount) {
    std::vector<std::string> ReturnVal;
    for (int i = 0; i < amount; i++) {
        ReturnVal.push_back(RandomStringGen(32));

    }
    return ReturnVal;
}
