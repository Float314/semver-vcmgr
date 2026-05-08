/* Demo file to test and see if it actually works lol :/  */
#include <iostream>
#include "version_control.hpp"

#ifndef PROGRAM_VERSION
#define PROGRAM_VERSION "v1.0.3-beta-1"

program_version Version = PROGRAM_VERSION;

#endif

int main() {
    auto major = Version.major();
    auto minor = Version.minor();
    auto subMinor = Version.subMinor();
    auto releaseType = Version.releaseType();
    auto relTypeVersion = Version.relTypeVersion();

    std::cout << "Version: " << Version.rawVersion << "\n";
    std::cout << "Major: " << major << "\n";
    std::cout << "Minor: " << minor << "\n";
    std::cout << "SubMinor: " << subMinor << "\n";
    std::cout << "Release Type: " << releaseType << "\n";
    std::cout << "Release Type Version: " << relTypeVersion << "\n";

    if (releaseType == "alpha" || releaseType == "beta") {
        std::cout << "You are using the " << releaseType << " build of the Program.\n"
                  << "Things May break!" << std::endl;
    }

    if (Version <= "v1.0.2-beta-2") {
        std::cout << "This version is <= v1.0.2-beta-2\n";
    }

    if (Version >= "v1.0.0-alpha-1") {
        std::cout << "This version is >= v1.0.0-alpha-1\n";
    }

    if (Version == "v1.0.3-beta-1") {
        std::cout << "This version is == v1.0.3-beta-1\n";
    }

    if (Version != "v1.0.0-alpha-1") {
        std::cout << "This version is != v1.0.0-alpha-1\n";
    }

    return 0;
}
