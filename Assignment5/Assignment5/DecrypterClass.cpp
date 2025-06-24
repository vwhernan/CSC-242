#include "DecrypterClass.h"

// Constructor definition
DecrypterClass::DecrypterClass() {
    // You can initialize members here if you have any
    
}

// Destructor definition
DecrypterClass::~DecrypterClass() {
    
}
//_________________________________________________________-Functions-____________________________________________________________________________
/*
@Brief:
@Param:
@Return:
*/
void DecrypterClass::WriteMessageToFile(string filename, string Message) {
    ofstream out_file(filename);
    if (out_file.is_open()) {
        // Write the content string to the file.
        out_file << Message;

        // Close the file stream. It's good practice to explicitly close it,
        // although it will be automatically closed when outputFile goes out of scope.
        out_file.close();
         
        cout << "Successfully wrote to file: " + filename;
    }
    else {
        // If the file could not be opened, print an error message.
        cout << "Error: Unable to open file for writing: " + filename;
    }
    return;
}

/*
@Brief:
@Param:
@Return:
*/
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
/*
@Brief:
@Param:
@Return:
*/
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
/*
@Brief:
@Param:
@Return:
*/
string DecrypterClass::GetMessageToDeCrypt(string filepath) {
    ifstream in_file;
    string data;
    string message;
    in_file.open(filepath);


    if (!in_file.is_open()) {
        cerr << "Error opening file: " << filepath << endl;
        return message;

    }

    while (in_file >> data) {

        transform(data.begin(), data.end(), data.begin(), [](unsigned char c) {return tolower(c); });
        message= message + data;

    }

    in_file.close();

    return message;
}
/*
@Brief:
@Param:
@Return:
*/
string DecrypterClass::DecryptMessage(string message, string encryptedAlphabet) {
    string decryptedMessage = "";
    string standardAlphabet = "abcdefghijklmnopqrstuvwxyz"; 

    for (char c : message) {
        if (isalpha(c)) {
            char lowerC = tolower(c);     

            size_t index = encryptedAlphabet.find(lowerC);
            if (index != string::npos) {
                char decryptedChar = standardAlphabet[index];
                decryptedMessage = decryptedMessage + " " + decryptedChar;
            }
        
        }
        else {
            // Non-alphabetic characters are kept as is
            decryptedMessage = decryptedMessage + " " + c;
        }
    }
    return decryptedMessage;
}
