#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class SpellChecker{
    public:
	// Constructor
	SpellChecker();

	// Destructor
	~SpellChecker();

	// Member function declaration
	void printText(string filepath);
	vector<string> GetDictionaryAsVector(vector<string>wordlist, string filepath);

};

