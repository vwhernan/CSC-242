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
@Brief:Checks the spelling of the input word and suggests corrections if necessary
@Param: the word to be checked for spelling errors
@Return: true if the word is spelled correctly; false otherwise
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
@Brief: Loads a list of words from a specified file and converts them to uppercase.
@Param: the path to the file containing words, with each word separated by whitespace.
@Return: a vector of uppercase strings read from the file. Returns an empty vector if the file cannot be opened.
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
@Brief: Loads a list of words from a dictionary file and converts them to uppercase.
@Param: The path to the text file containing dictionary words, separated by whitespace.
@Return: Avector of uppercase strings representing the words in the file. Returns an empty vector if the file cannot be opened.
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
@brief Identifies which words from the user's list are not found in the dictionary list.
@param DictionaryList A vector of uppercase dictionary words used for comparison.
@param UserWords A vector of uppercase words provided by the user.
@return A space-separated string containing words from UserWords that are not present in DictionaryList.
*/

