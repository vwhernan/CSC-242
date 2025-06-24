#include "DecrypterClass.h"

// Constructor definition
DecrypterClass::DecrypterClass() {
    // You can initialize members here if you have any
    
}

// Destructor definition
DecrypterClass::~DecrypterClass() {
    
}

// printText method definition
void DecrypterClass::printText() {
    cout << "This message is from the DeCryptor class" << endl; 
}


string DecrypterClass::CreateCypher(string keyword) {
    string baseAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string processedKeyword = "";
    string remainingAlphabet = "";

    // Deduplicate keyword and convert to lowercase for consistent processing
    bool seenInKeyword[26] = { false }; // Tracks 'a' through 'z'

    // Only process letters
    for (char c : keyword) {
        c = tolower(c); 
        if (c >= 'a' && c <= 'z') { 
            if (!seenInKeyword[c - 'a']) {
                processedKeyword += c;
                seenInKeyword[c - 'a'] = true;
            }
        }
    }

    //Get the remaining alphabet (characters not in processedKeyword)
    bool seenInAlphabet[26] = { false }; // Tracks 'a' through 'z'

    // Mark characters from the processed keyword as 'seen' in the alphabet context
    for (char c : processedKeyword) {
        seenInAlphabet[c - 'a'] = true;
    }

    // Append characters from baseAlphabet that haven't been seen
    for (char c : baseAlphabet) {
        if (!seenInAlphabet[c - 'a']) {
            remainingAlphabet += c;
        }
    }
    // Reverses remaining alphabet
    reverse(remainingAlphabet.begin(), remainingAlphabet.end());

    //Combine them: processedKeyword + remainingAlphabet
    string cipherAlphabet = processedKeyword + remainingAlphabet;

    return cipherAlphabet;

}

string DecrypterClass::EncryptMessage(string message, string encryptedAlphabet) {
    string encryptedMessage = "";
    string standardAlphabet = "abcdefghijklmnopqrstuvwxyz";

    for (char c : message) {
        if (isalpha(c)) {
            char lowerC = tolower(c); 

            size_t index = standardAlphabet.find(lowerC);
            if (index != string::npos) {
                char encryptedChar = encryptedAlphabet[index];
                encryptedMessage += encryptedChar;
            }
        }
        else {
            encryptedMessage += c;
        }
    }

    return encryptedMessage;
}
