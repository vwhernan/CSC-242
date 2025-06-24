#include "SpellChecker.h"



// Constructor definition
SpellChecker::SpellChecker() {
    // You can initialize members here if you have any
}

// Destructor definition
SpellChecker::~SpellChecker() {
    
}

// printText method definition
void SpellChecker::printText(string filepath) {
    
}

vector<string> SpellChecker::GetDictionaryAsVector(vector<string>wordlist, string filepath) {
    ifstream in_file;
    string data;
    in_file.open(filepath);
    in_file >> data;

    if (!in_file.is_open()) {
        cerr << "Error opening file: " << filepath << endl;
        return;

    }

    while (in_file >> data) {
        cout << data << endl;
    }

    in_file.close();
  
    return wordlist;
}

