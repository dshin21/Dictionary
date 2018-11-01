#include <iostream>
#include "dictionary.hpp"

int main() {
    dictionary d{"../dictionary.txt"};
    d.read_file();
    for (auto const &x : d.get_map()) {
        cout << x.first << " : " << x.second << std::endl;
    }
}