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

    while (getline(is, line)) {
        istringstream iss{line};
//        string::iterator end_pos = remove(line.begin(), line.end(), '\n');
//        line.erase(end_pos, line.end());
        (++counter == 1) ? word = line : definition = line;
        if (counter % 2 == 0) {
            dictionary_map.insert(pair<string, string>(word, definition));
            counter = 0;
        }
    }
}

void dictionary::print_dictionary(map<string, string> &dictionary) {
    map<string, string>::iterator itr;
    cout << "============================================" << endl;
    for (itr = dictionary.begin(); itr != dictionary.end(); ++itr) {
        cout << itr->first << " - " << itr->second << endl;
    }
}

void dictionary::print_menu() {
    cout << "============================================" << endl;
    cout << "MENU" << endl;
    cout << "\t1 - Print Dictionary\n"
         << "\t2 - Find word definition\n"
         << "\t3 - Enter new word and definition\n"
         << "\t4 - Exit" << endl;
    cout << "============================================" << endl;
}

void dictionary::word_finder() {
    cout << "Please enter a word to find" << endl;
    string word;
    cin >> word;

    if ((dictionary_map.find(word) == dictionary_map.end())) {
        cout << "The does not exists in the dictionary." << endl;
    } else {
        cout << word << " - " << dictionary_map.find(word)->second << endl;
    }

}

void dictionary::make_entry() {
    cout << "Please enter a word" << endl;
    string word;
    string definition;
    bool exists = false;


    while (cin >> word && !exists)
        if ((dictionary_map.find(word) != dictionary_map.end())) {
            cout << "The exists in the dictionary. Please enter a new word.";
        } else {
            cout << "Enter a definition: " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getline(cin, definition);
            dictionary_map.insert(pair<string, string>(word, definition));
            write_to_file(word, definition);
            cout << word << " - " << definition << " added.\n" << endl;
            exists = true;
        }
}

void dictionary::write_to_file(string word, string definition) {
    ofstream of{"../dictionary.txt", ios_base::app};
    of << word << '\n' << definition << '\n';
}







