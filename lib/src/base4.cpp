#include <string>
#include <algorithm>
#include <unordered_map>
#include <base4.hpp>

const std::array<char, 4> wtlgo::base4_default_charset {
    '+', '-', '*', '%'
};

std::string wtlgo::base4_encode(const std::string& input, const std::array<char, 4>& charset) {
    std::string res;

    for(char c : input) {
        const std::array<uint8_t, 4> split {
            static_cast<uint8_t>((c >> 6) & 0b11),
            static_cast<uint8_t>((c >> 4) & 0b11),
            static_cast<uint8_t>((c >> 2) & 0b11),
            static_cast<uint8_t>(c & 0b11)
        };

        std::transform(split.cbegin(), split.cend(), std::back_inserter(res),
        [&charset](uint8_t code) {
            return charset[code];
        });
    }

    return res;
}

std::string wtlgo::base4_decode(const std::string& input, const std::array<char, 4>& charset) {
    if(input.size() % 4 != 0) {
        throw std::runtime_error("Invalid input: Incorrect length.");
    }

    if(std::any_of(input.cbegin(), input.cend(), [&charset](char c) {
        return std::find(charset.cbegin(), charset.cend(), c) == charset.cend();
    })) {
        throw std::runtime_error("Invalid input: Found characters that are not in the current char set.");
    }

    const std::unordered_map<char, uint8_t> char_map = [&charset]{
        std::unordered_map<char, uint8_t> res;
        uint8_t idx = 0;
        for(char c : charset) {
            res[c] = idx++;
        }
        return res;
    }();
    
    std::string res;
    for(auto it = input.cbegin(); it != input.cend(); it += 4) {
        const uint8_t next =
        (char_map.at(*it) << 6) +
        (char_map.at(*(it + 1)) << 4) +
        (char_map.at(*(it + 2)) << 2) +
        char_map.at(*(it + 3));

        res.push_back(next);
    }

    return res;
}
