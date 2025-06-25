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
@Brief: Reads words from a text file and returns them as uppercase strings in a vector.
@Param: the path to the input file containing user-provided words,
@Return:  A vector of uppercase strings extracted from the file. Returns an empty vector if the file cannot be opened.
*/
vector<string> SpellChecker::GetWordList(string filepath) {
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
@Brief: Reads a list of words from a dictionary file and user file and compares what words are not in the dicitonary.
@Param: dictionary vector, userwords vector
@Return: A string containing the uppercase words not in the file. 
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

