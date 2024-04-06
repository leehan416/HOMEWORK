#include <iostream>
#include <vector>

#define MAX 20
using namespace std;


int change(char t) {
   if (t == 'I') return 1;
   else if (t == 'V') return 5;
   else if (t == 'X') return 10;
   else if (t == 'L') return 50;
   else if (t == 'C') return 100;
   else if (t == 'D') return 500;
   else if (t == 'M') return 1000;
   else return 0;

}

int main() {
   string input;
   vector<char> vec;
   int sum = 0;
   cin >> input;

   // over 20
   if (input.length() > MAX) return 0;

   for (char i: input) vec.push_back(i);


   for (int i = 0; i < vec.size(); i++) {
       sum += change(vec[i]);
       if (i + 1 < vec.size()) {
           if (vec[i] == 'I') {
               if (vec[i + 1] == 'V' || vec[i + 1] == 'X') sum -= 2;
           } else if (vec[i] == 'X') {
               if (vec[i + 1] == 'L' || vec[i + 1] == 'C') sum -= 20;
           } else if (vec[i] == 'C') {
               if (vec[i + 1] == 'D' || vec[i + 1] == 'M') sum -= 200;
           }
       }

   }
   cout << sum << endl;
   return 0;
}