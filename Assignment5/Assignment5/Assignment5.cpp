/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
** 
** Class: 	CSC 242
** Assignment: 	Lesson #5
** File: 	Assignment5.cpp
** Description: This is a test for assignment 3
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
    runSpellChecker();
    rundecrypter();
    return 0;
}

