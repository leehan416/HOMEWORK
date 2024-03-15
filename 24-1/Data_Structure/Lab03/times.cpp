// Step_1
#include<iostream>
#include<vector>

using namespace std;
#if 1

// multiply each element in the list by 10 if it is an even number // without using reference variable.
int main(int argc, char *argv[]) {
    vector<int> list = {0, 1, 2, 2, 4, 5, 6, 7, 8, 8, 10};
    for (size_t i = 0; i < list.size(); i++) {
        //----------------------------------------
        if (list[i] % 2 == 0) { // even num check
            list[i] *= 10;
        }
        //----------------------------------------
    }
    for (auto x: list) cout << x << " ";
    return 0;
}

#else

// multiply each element in the list by 10 if it is an even number // using reference variable.
int main(int argc, char *argv[]) {
    vector<int> list = {0, 1, 2, 2, 4, 5, 6, 7, 8, 8, 10};
    // cout << "your code here\n";

    //----------------------------------------
    for (auto &i: list){
        if (i % 2 == 0) { //even num check
            i *= 10;
        }
    }
    //----------------------------------------


    for (auto x: list) cout << x << " ";
    return 0;
}

#endif