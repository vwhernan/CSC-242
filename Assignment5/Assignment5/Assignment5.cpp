/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
** 
** Class: 	CSC 242
** Assignment: 	Lesson #5
** File: 	Assignment5.cpp
** Description: This application has 2 programs built in.  SpellChecker and Decrypter.
**
** Author: 	Vincent Hernandez
** Date: 	06/19/2025
** -------------------------------------------------------------------------*/
using namespace std;
#include <iostream>
#include <string>
#include "SpellChecker.h"
#include "DecrypterClass.h"

void runSpellChecker() {
    //Declarations
    string file = "Dictionary.txt";
    string wordsMisSpelled;
    vector<string> dictionaryList;
    vector <string> words;
    SpellChecker sp;

    //What is this code doing: GetDictionaryAsVector --> GetUserWordList --> WordsNotInDictionary --> OutPut Words misspelled
    dictionaryList = sp.GetWordList(file);
    file = "Words.txt";
    words = sp.GetWordList(file);
    wordsMisSpelled = sp.WordsNotInDictionary(dictionaryList, words);
    
                //Prints original user words
    cout << "\n\nThe following words are in the users word list:" << endl;
    for (string word : words) {
        cout << word + " ";
    }

               //prints miss spelled words
    cout << "\n\nThe following words are not in the systems dictionary: " << "\n" + wordsMisSpelled + "\n\n";

}


void runDecrypter() {
    //Delcarations
    int EncryptOrDecrypt;
    string file = "Message.txt";
    string encryptedAlphabet;
    string keyword;
    string message;
    DecrypterClass dc;

    //What is this code doing: Get Cypher KeyWord --> Encrypt or Decrypt --> 
    do {
        cout << "Enter A KeyWord for Cypher: " << endl;
        cin >> keyword;
    } while (keyword.empty());
    
    encryptedAlphabet = dc.CreateCypher(keyword);

    cout << "Would you like to: \n(1) Encrypt?\n(2) Decrypt?  " << endl;
    cin >> EncryptOrDecrypt;

    //What is this code doing: Encrytp --> get message to encrypt --> encrypt message --> write to file
    if (EncryptOrDecrypt == 1) {
        cout << "Type a Message to Encrypt: " << endl;
        // before using getline. Without this, getline will read an empty string.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, message);
        string eMessage = dc.EncryptMessage(message, encryptedAlphabet);
        dc.WriteMessageToFile(file, eMessage);
    }

    //What is this code doing: Decrypt --> get message from file --> decrypt message --> output decrypted message
    else if(EncryptOrDecrypt == 2){
        string EncryptedMessage = dc.GetMessageToDeCrypt(file);
        string DecryptedMessage = dc.DecryptMessage(EncryptedMessage, encryptedAlphabet);

        cout << DecryptedMessage;

    }
    //ends program if invalid choice Encrypt or Decrypt
    else {
        cout << "Invalid Selection" << endl;
    }
    
}

int main()
{
    //Declarations
    int choice;

   
    //What is this code doing: ask user to pick a program to run--> if 1 run spell check--> if 2 run decrypter--> if anything else end program.
    cout << "Select a program: 1 for spell checker, 2 for decrypter" << endl;
    cin >> choice;

    if (choice == 1) {
        runSpellChecker();
    }
    else if (choice == 2) {
        runDecrypter();
    }
    else {
        cout << "invalid entry" << endl;
    }

    return 0;
}

