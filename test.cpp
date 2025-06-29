#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio> // for popen, pclose

std::vector<std::string> allcommands() {
    std::vector<std::string> words;
    std::string result;
    char buffer[128];

    // Open a pipe to the shell command
    FILE* pipe = popen("compgen -c", "r");
    if (!pipe) {
        std::cerr << "popen() failed!" << std::endl;
        return words;
    }

    // Read the output into a string
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);

    // Split the result by newlines
    std::istringstream iss(result);
    std::string line;
    while (std::getline(iss, line)) {
        if (!line.empty()) {
            words.push_back(line);
        }
    }

    return words;
}

int main() {
    auto commands = allcommands();
    for (const auto& cmd : commands) {
        std::cout << cmd << std::endl;
    }
    return 0;
}



