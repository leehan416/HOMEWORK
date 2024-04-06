#include <iostream>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    if (input.size() > 50){
        cout << "50자 초과" << endl;
        return 0;
    }
    int arr[26] = {0,};
    for (auto i : input) {
        if (i == ' ') continue;
        else arr[toupper(i) - 'A']++;
    }



    for (int i = 0 ; i < 'z' - 'a'; i++){
        if(arr[i] > 0)
            cout << char('A' + i) <<  " : " << arr[i] << endl;
    } 
    return 0;
}