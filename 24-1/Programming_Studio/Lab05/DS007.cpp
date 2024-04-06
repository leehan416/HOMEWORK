#include <iostream>

#define MAX 20
using namespace std;

int change(char t) {
    if (t == 'I') return 1;
    else if (t == 'V') return 5;
    else if (t == 'X')  return 10;
    else if (t == 'L')  return 50;
    else if (t == 'C')  return 100;
    else if (t == 'D')  return 500;
    else if (t == 'M')  return 1000;
    else return 0;
}

int main() {
    string input;
    int sum = 0;
    cin >> input; 
    // over 20
    if (input.length() > MAX) return 0;

    for (auto i: input) sum += change(i);
    
    cout << sum << endl;
    return 0;
}