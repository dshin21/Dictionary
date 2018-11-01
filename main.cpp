#include <iostream>
#include "dictionary.hpp"

int main() {
    dictionary d{"../dictionary.txt"};
    d.read_file();

    d.print_dictionary(d.get_map());
}