#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio> // for popen, pclose

std::vector<std::string> allcommands() {
    std::vector<std::string> words;
    std::string result;
    char buffer[128];

    // pipe ex: echo {thing} | grep {thing}
    FILE* pipe = popen("compgen -c", "r");
    if (!pipe) {
        std::cerr << "popen() failed!" << std::endl;
        return words;
    }

    // since we know the size of the string we can finite get it for more performance
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);

    // since compgen -c outputs string separated by \n we separate it. 
    std::istringstream inpss(result);
    std::string line;
    while (std::getline(inpss, line)) {
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



