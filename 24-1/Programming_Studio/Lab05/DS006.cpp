#include <iostream>
#include <format>

using namespace std;

struct st_class
{
    string title;
    int num;
    double scored;
    string grade;
};

int main()
{
    float gpa = 0.0f;
    int all= 0;
    st_class *list[3];

    // 동적 할당 추가
    for (int i = 0; i < 3; i++) {
        list[i] = new st_class;
    }

    for (int i = 0; i < 3; i++) {
        float val;
        cin >> list[i]->title >> list[i]->num >> list[i]->scored;
        all += list[i]->num;
        if (list[i]->scored >= 95) {
            list[i]->grade = "A+";
            val = 4.5f;
            list[i]->scored = 4.5;
            
        } else if (list[i]->scored >= 90) {
            list[i]->grade = "A0";
            val = 4.0f;
            list[i]->scored = 4.0;
        }
        else if (list[i]->scored >= 85)
        {
            list[i]->grade = "B+";
            val = 3.5f;
            list[i]->scored = 3.5;
        }
        else if (list[i]->scored >= 80)
        {
            list[i]->grade = "B0";
            val = 3.0f;
            list[i]->scored = 3.0;
        }
        else if (list[i]->scored >= 75)
        {
            list[i]->grade = "C+";
            val = 2.5f;
            list[i]->scored = 2.5;
        } else if (list[i]->scored >= 70) {
            list[i]->grade = "C0";
            val = 2.5f;
            list[i]->scored = 2.5;
        } else {
             list[i]->grade = "F";
            val = 0.0f;
            list[i]->scored = 0.0;
        }
        val *= list[i]->num;
        gpa += val;
    }

    gpa /= all;
    cout << endl;

    for (int i = 0; i < 3; i++) {        
       list[i]->title += "("  + to_string(list[i]->num) + ")";
        printf("%-20s %-3s %.1f\n", list[i]->title.c_str(), list[i]->grade.c_str(), list[i]->scored);
    }
    cout << "Total Cradits" << " " << all << " " ;
    printf("%.2f", gpa);
    cout << endl;
    return 0;
}
