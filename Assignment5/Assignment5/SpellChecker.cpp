#include "SpellChecker.h"



// Constructor definition
SpellChecker::SpellChecker() {
    // You can initialize members here if you have any
}

// Destructor definition
SpellChecker::~SpellChecker() {
    
}

//_________________________________________________________-Functions-____________________________________________________________________________

/*
@Brief: Test
@Param:
@Return:
*/
vector<string> SpellChecker::GetUserWordList(string filepath) {
    ifstream in_file;
    string data;
    vector<string> userWords;

    in_file.open(filepath);


    if (!in_file.is_open()) {
        cerr << "Error opening file: " << filepath << endl;
        return userWords;

    }

    while (in_file >> data) {
        transform(data.begin(), data.end(), data.begin(), [](unsigned char c) {return toupper(c);});
        userWords.push_back(data);
    }

    in_file.close();

    return userWords;
}

/*
@Brief:
@Param:
@Return:
*/
vector<string> SpellChecker::GetDictionaryAsVector(string filepath) {
    ifstream in_file;
    string data;
    vector<string> wordlist;
    in_file.open(filepath);


    if (!in_file.is_open()) {
        cerr << "Error opening file: " << filepath << endl;
        return wordlist;

    }

    while (in_file >> data) {
        
        transform(data.begin(), data.end(), data.begin(), [](unsigned char c) {return toupper(c); });
        wordlist.push_back(data);
       
    }

    in_file.close();
  
    return wordlist;
}

/*
@Brief:
@Param:
@Return:
*/
string SpellChecker::WordsNotInDictionary(vector<string>DictionaryList, vector<string>UserWords) {
    string wordToCheck;
    string wordsNotInDictionary;

    for (string word : UserWords) {
        auto iter = find(DictionaryList.begin(), DictionaryList.end(), word);

        if (iter == DictionaryList.end()) {
            wordsNotInDictionary = wordsNotInDictionary + word + " ";
        }

    }
    return wordsNotInDictionary;
}

