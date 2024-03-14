#include<iostream>
#include <cctype> // to use toupper

using namespace std;

int main() {
    size_t i; // index of string
    string input; // user input
    
    cout << "Enter words: ";

    //input data
    getline(cin, input);

    // change to upper case
    for (i = 0; i < input.length(); i++) {
        input[i] = (char) toupper(input[i]);
    }
    
    // print
    cout << input << endl;

    return 0;
}