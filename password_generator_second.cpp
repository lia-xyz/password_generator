/*
Queue-based Password Generator in C++
Author: Natalia Semjonova
Date: 08.03.2025
Description:
This is a C++ program that generates all possible passwords 
based on a given maximum password length and a specified alphabet length. 
The program uses a queue data structure to generate passwords 
in a breadth-first manner, ensuring that shorter passwords are generated first.
The program generates passwords consisting of lowercase English letters (a-z).
*/

#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>

using namespace std;

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
    for (int i = 0; i < alphabet_length; ++i) {
        letters += ('a' + i);
    }

    // Queue to store generated passwords
    queue<string> q;

    // Enqueueing single letters
    for(char letter : letters){
        q.push(std::string(1, letter));
    }

    // Process queue until all possible passwords are generated
    while(!q.empty()){
        // Retrieve and remove the front element from the queue
        string current = q.front();
        q.pop();

         // Print the password
        cout << current << endl;

        // If current length is less than max_password_length, generate longer passwords
        if(max_password_length > current.length()){
            for(char letter : letters){
                q.push(current+letter);
            }
        }
    }

    return 0;
}