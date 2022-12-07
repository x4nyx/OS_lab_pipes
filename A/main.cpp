#include <iostream>
#include <sstream>

int N = 23;

int main() {
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    int value;
    std::string result;
    while (ss >> value) {
        result.append(std::to_string(value + N)+" ");
    }
    std::cout << result <<"\n";
    return 0;
}