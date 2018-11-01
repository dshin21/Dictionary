#include <utility>
#include <algorithm>

//
// Created by Daniel Shin on 2018-11-01.
//

#include "dictionary.hpp"

dictionary::dictionary(string file) : file(std::move(file)) {}

void dictionary::read_file() {
    ifstream is{file};
    string line;
    string word;
    string definition;
    int counter = 0;


    while (getline(is, line, '\r')) {
        istringstream iss{line};
        string::iterator end_pos = remove(line.begin(), line.end(), '\n');
        line.erase(end_pos, line.end());
        (++counter == 1) ? word = line : definition = line;
        if (counter % 2 == 0) {
            dictionary_map.insert(pair<string, string>(word, definition));
            counter = 0;
        }
    }
}



