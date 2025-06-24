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
    dictionaryList = sp.GetDictionaryAsVector(file);
    file = "Words.txt";
    words = sp.GetUserWordList(file);
    wordsMisSpelled = sp.WordsNotInDictionary(dictionaryList, words);
    
                //Prints original user words
    cout << "\n\nThe following words are in the user word list:" << endl;
    for (string word : words) {
        cout << word + " ";
    }

               //prints miss spelled words
    cout << "\n\nThe following words are miss spelled: " << "\n" + wordsMisSpelled + "\n\n";

}


void runDecrypter() {
    //Delcarations
    int EncryptOrDecrypt;
    string encryptedAlphabet;
    string keyword;
    string message;
    DecrypterClass dc;

    //What is this code doing:
    cout << "Enter A KeyWord for Cyper: " << endl;
    cin >> keyword;
    encryptedAlphabet = dc.CreateCypher(keyword);

    cout << "Would you like to Encrypt (1)? Would you like to Decrypt (2)? Select 1 or 2." << endl;
    cin >> EncryptOrDecrypt;

    if (EncryptOrDecrypt == 1) {
        cout << "Type a Message to Encrypt: " << endl;
        cin >> message;
        string eMessage = dc.EncryptMessage(message, encryptedAlphabet);
        cout << message <<endl;
        cout << eMessage;
    }

    else if(EncryptOrDecrypt == 2){
      
    }

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

