#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <fstream>
#include <iostream>
#include <string>

extern void say_hello();

int main(int argc, char* argv[]) {
    say_hello();

    std::ifstream sample_input("sample_input.txt");
    if (!sample_input.is_open()) {
        std::cerr << "Unable to open file sample_input.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(sample_input, line)) {
        std::cout << line << std::endl;
    }

    sample_input.close();
    return 0;
}