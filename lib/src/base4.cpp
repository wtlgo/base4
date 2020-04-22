#include <string>
#include <algorithm>
#include <unordered_map>
#include <base4.hpp>

std::string wtlgo::base4_encode(const std::string& input, const std::array<char, 4>& charset) {
    std::string res;

    for(char c : input) {
        std::array<uint8_t, 4> split;

        split[0] = (c >> 6) & 0b11;
        split[1] = (c >> 4) & 0b11;
        split[2] = (c >> 2) & 0b11;
        split[3] = c & 0b11;

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

    std::string res;

    std::unordered_map<char, uint8_t> char_map;
    for(uint8_t i = 0; i < charset.size(); ++i) {
        char_map[charset[i]] = i;
    }

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
