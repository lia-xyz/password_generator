/*
Password Generator in C++
Author: Natalia Semjonova
Date: 08.03.2025
Description:
This is a simple recursive C++ program that generates all possible passwords 
based on the specified maximum password length and the number of available characters (alphabet length). 
The program generates passwords consisting of lowercase English letters (a-z).
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void generator(string previous, int current_length, int max_length, string letters){
    // If the desired length is reached, print the password and return
    if(max_length == current_length){
        cout << previous << endl;
        return;
    }
    // Append each letter and generate the next character
    for(char letter : letters){
        generator(previous + letter, current_length + 1, max_length, letters);
    }
}

int main(int argc, char* argv[]){
    // Check if the correct number of arguments is provided
    if(argc != 3){
        cerr << "Usage: ./password_generator.exe -max_password_length -alphabet_length" <<endl;
        return 1;
    }

    // Convert arguments from string to integer
    int max_password_length = atoi(argv[1] + 1);
    int alphabet_length = atoi(argv[2] + 1);

    // Ensure positive values and that the alphabet length does not exceed 26
    if(max_password_length <= 0 || alphabet_length > 26 || alphabet_length <= 0){
        cerr << "Error: Both values should be positive integers, and alphabet_length should not exceed 26" << endl;
        return 1;
    }

    // Generate string of letters from 'a' to 'a' + alphabet_length
    string letters = "";
    for(char letter = 'a'; letter < 'a' + alphabet_length; letter++){
        letters += letter;
    }

    // Generate passwords of lengths from 1 to max_password_length
    for(int length = 1; length <= max_password_length; length++){
        generator("", 0, length, letters);
    }

    return 0;
}