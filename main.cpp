#include <iostream>
#include "dictionary.hpp"

int main() {
    dictionary d{"../dictionary.txt"};
    d.read_file();

    d.print_menu();

    int option;
    while (cin >> option && option != 4)
        switch (option) {
            case 1:
                d.print_dictionary(d.get_map());
                d.print_menu();
                break;
        }


}