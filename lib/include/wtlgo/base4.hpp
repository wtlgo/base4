#ifndef _WTLGO_BASE4_
#define _WTLGO_BASE4_

#include <string>
#include <array>

namespace wtlgo {

extern const std::array<char, 4> base4_default_charset; 
std::string base4_encode(const std::string& input, const std::array<char, 4>& charset = base4_default_charset);
std::string base4_decode(const std::string& input, const std::array<char, 4>& charset = base4_default_charset);

}

#endif
