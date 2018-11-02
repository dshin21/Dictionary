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
            case 2:
                d.word_finder();
                d.print_menu();
                break;
            case 3:
                d.make_entry();
                d.print_menu();
                break;
            default:
                cout << "Invalid Option" << endl;
                d.print_menu();
        }


}