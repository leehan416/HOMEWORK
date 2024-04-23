// 22100594 이한결
#include <iostream>

using namespace std;

struct Cl {
    string name; // 과목 명
    int hackjum; // 학점 수
    int grade; // 점수
    string g; // 등급
};


int main() {
    int num;
    cin >> num;
    Cl *c[num];
    float gpa = 0;
    int total = 0;
    int maxIndex = 0;

    for (int i = 0; i < num; i++) {
        c[i] = new Cl;
    }


    for (int i = 0; i < num; i++) {
        cin >> c[i]->hackjum;
        cin >> c[i]->grade;
        cin.ignore();
        getline(cin, c[i]->name);
        float val;
        total += c[i]->hackjum;
        if (c[i]->grade > c[maxIndex]->grade) maxIndex = i;

        if (c[i]->grade >= 95) {
            c[i]->g = "A+";
            val = 4.5f;
        } else if (c[i]->grade >= 90) {
            c[i]->g = "A0";
            val = 4.0f;
        } else if (c[i]->grade >= 85) {
            c[i]->g = "B+";
            val = 3.5f;
        } else if (c[i]->grade >= 80) {
            c[i]->g = "B0";
            val = 3.0f;
        } else if (c[i]->grade >= 75) {
            c[i]->g = "C+";
            val = 2.5f;
        } else if (c[i]->grade >= 70) {
            c[i]->g = "C0";
            val = 2.5f;
        } else {
            c[i]->g = "F";
            val = 0.0f;
        }
        val *= c[i]->hackjum;
        gpa += val;
    }


    gpa /= total;
    for (int i = 0; i < num; i++) {
        cout << c[i]->name << " " << c[i]->hackjum << " " << c[i]->g << endl;
    }
    cout << "================" << endl;
    cout << "Total Credits: " << total << endl;
    printf("GPA: %.1f \n", gpa);
    cout << "Top class: " << c[maxIndex]->name << " " << c[maxIndex]->grade << " " << c[maxIndex]->g << endl;


    for (int i = 0; i < num; i++)
        delete *(c + i);

    // delete[] c;
    return 0;
}
