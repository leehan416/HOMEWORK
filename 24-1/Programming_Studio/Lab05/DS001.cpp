#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int height, weight; // 신장(cm), 체중(kg) 
    double bmi; // 비만도 수치

    cin >> height >> weight;

    bmi = weight / pow((height * 0.01f), 2);
    cout << ((bmi >= 25) ? ("Yes") : ("No")) << endl;
}