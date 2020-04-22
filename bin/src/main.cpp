#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <wtlgo/base4.hpp>

enum runtime_mode_t {
    NONE = 0, 
    ENCODE, DECODE, HELP, ERR_INVALID_ARG, ERR_CHARSET
};

struct Config {
    runtime_mode_t mode = NONE;
    bool new_charset = false;
    char charset[4];

    bool arg_input = false;
    std::string input;

    Config(int argv, const char* argc[]);
};

std::string generate_help(const std::string& pname);

int main(int argv, const char* argc[]) {
    using namespace wtlgo;
    Config config(argv, argc);

    switch(config.mode) {
        case ENCODE: {
            if(config.new_charset) {
                std::cout << base4_encode(config.input, { 
                    config.charset[0], 
                    config.charset[1], 
                    config.charset[2], 
                    config.charset[3]
                });
            }
            else {
                std::cout << base4_encode(config.input);
            }
        }
        break;
        case DECODE: try {
            if(config.new_charset) {
                std::cout << base4_decode(config.input, { 
                    config.charset[0], 
                    config.charset[1], 
                    config.charset[2], 
                    config.charset[3]
                });
            }
            else {
                std::cout << base4_decode(config.input);
            }
        }
        catch(const std::exception& exp) {
            std::cerr << exp.what() << std::endl;
        }
        break;
        
        case ERR_INVALID_ARG:
            std::cerr << "Invalid arguments." << std::endl;
            break;
        case ERR_CHARSET:
            std::cerr << "Invalid charset. It should consist of 4 ASCII characters" << std::endl;
            break;

        default:
            std::cout << generate_help(argc[0]) << std::endl;
            break;
    }

    return 0;
}

std::string generate_help(const std::string& pname) {
    std::ostringstream out;

    out
    << "Encode string:" << std::endl
    << "$ " << pname << " encode \"foo\"" << std::endl
    << std::endl
    << "Decode string:" << std::endl
    << "$ " << pname << " decode \"" << wtlgo::base4_encode("foo") << '\"' << std::endl
    << std::endl
    << "Encode string with specific charset:" << std::endl
    << "$ " << pname << " encode --charset ABCD \"foo\"" << std::endl
    << std::endl
    << "Decode string with specific charset:" << std::endl
    << "$ " << pname << " decode --charset ABCD \"" << wtlgo::base4_encode("foo", {'A', 'B', 'C', 'D'}) << '\"' << std::endl
    << std::endl
    << "Default charset is " << std::string(wtlgo::base4_default_charset.cbegin(), wtlgo::base4_default_charset.cend()) << std::endl
    << std::endl
    << "Help:" << std::endl
    << "$ " << pname << " --help";

    return out.str();
}

Config::Config(int argv, const char* argc[]) {
    int n = 1;

    while(n < argv) {
        if(strcmp("--help", argc[n]) == 0) {
            mode = HELP;
            break;
        }
        else if(strcmp("--charset", argc[n]) == 0) {
            if(++n >= argv || new_charset) {
                mode = ERR_INVALID_ARG;
                break;
            }
            
            if(strlen(argc[n]) != 4) {
                mode = ERR_CHARSET;
                break;
            }
            
            strncpy(charset, argc[n], 4);
            new_charset = true;
        }
        else if(strcmp("encode", argc[n]) == 0) {
            if(mode) {
                mode = ERR_INVALID_ARG;
                break;
            }
            
            mode = ENCODE;
        }
        else if(strcmp("decode", argc[n]) == 0) {
            if(mode) {
                mode = ERR_INVALID_ARG;
                break;
            }
            
            mode = DECODE;
        }
        else {
            if(arg_input) {
                mode = ERR_INVALID_ARG;
                break;
            }
            
            arg_input = true;
            input = argc[n];
        }
        
        ++n;
    }
}
