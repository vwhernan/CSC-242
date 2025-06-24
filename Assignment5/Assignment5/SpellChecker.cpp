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
@Brief: Constructs a new SpellChecker object and initializes internal state if necessary.
@Param: None needed since no parameters are accepted
@Return: None needed since nothing is returned
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
@Brief: Reads words from a file and returns them as uppercase strings in a vector.
@Param: The path to the input file containing user-provided words, separated by whitespace.
@Return: A vector of uppercase strings extracted from the file. Returns an empty vector if the file cannot be opened.
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
@Brief: Reads a list of words from a dictionary file and stores them in uppercase.
@Param: The path to the file containing dictionary words, separated by whitespace.
@Return: A vector of strings containing the uppercase words from the file. Returns an empty vector if the file fails to open.
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
/*
@Brief: Compares a list of user-provided words against a dictionary and identifies any that are not found.
@Param: DictionaryList A vector of uppercase dictionary words to check against.
@Param: UserWords A vector of uppercase words entered by the user.    
@Return:A single space-separated string of words that are present in UserWords but not found in DictionaryList.
