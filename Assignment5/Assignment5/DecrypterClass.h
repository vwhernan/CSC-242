#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class DecrypterClass {
public:
	// Constructor
	DecrypterClass();


	// Destructor
	~DecrypterClass();

	// Member function declaration
	void printText();
	string CreateCypher(string keyword);
	string EncryptMessage(string message, string encryptedAlphabet);
};