#include <iostream>

int main() {
    auto ret = exec("primecount 1e12");
    std::cout << ret.first << ' ' << ret.second << std::endl;
    return 0;
}
