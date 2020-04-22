#ifndef _WTLGO_BASE4_
#define _WTLGO_BASE4_

#include <string>
#include <array>

namespace wtlgo {

std::string base4_encode(const std::string& input, const std::array<char, 4>& charset = {'+', '-', '*', '/'});
std::string base4_decode(const std::string& input, const std::array<char, 4>& charset = {'+', '-', '*', '/'});

}

#endif
