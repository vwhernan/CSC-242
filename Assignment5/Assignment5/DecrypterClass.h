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
	void WriteMessageToFile(string filename, string Message);
	string CreateCypher(string keyword);
	string EncryptMessage(string message, string encryptedAlphabet);
	string GetMessageToDeCrypt(string filepath);
	string DecryptMessage(string filename, string encryptedAlphabet);
};