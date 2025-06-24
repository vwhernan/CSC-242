#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class SpellChecker{
    public:
	// Constructor
	SpellChecker();

	// Destructor
	~SpellChecker();

	// Member function declaration
	vector<string>  GetUserWordList(string filepath);
	vector<string> GetDictionaryAsVector(string filepath);
	string WordsNotInDictionary(vector<string>DictionaryList, vector<string>UserWords);

};

