//
// Created by Daniel Shin on 2018-11-01.
//

#ifndef DICTIONARY_DICTIONARY_HPP
#define DICTIONARY_DICTIONARY_HPP

#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

class dictionary {
    map<string, string> dictionary_map;
    string file;

public:
    explicit dictionary(string);

    void read_file();

    map<string, string> &get_map() {
        return dictionary_map;
    }
};


#endif //DICTIONARY_DICTIONARY_HPP
