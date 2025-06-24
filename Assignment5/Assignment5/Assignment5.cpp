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
#include "SpellChecker.h"
#include "DecrypterClass.h"

void runSpellChecker() {
    SpellChecker sp;
    sp.printText();
}


void rundecrypter() {
    DecrypterClass dc;
    dc.printText();
}

int main()
{
    int choice;
    cout << "Select a program: 1 for spell checker, 2 for decrypter" << endl;
    cin >> choice;

    if (choice == 1) {
        runSpellChecker();
    }
    else if (choice == 2) {
        rundecrypter();
    }
    else {
        cout << "invalid entry" << endl;
    }

    return 0;
}

