#include<iostream>

using namespace std;

struct st_score {
    int kor, eng, math; // 국어점수, 영어점수, 수학점수 
    int total; // 총점
    double average; // 평균점수
};

int main(){
    st_score * s = new st_score;


    cin >>  s->kor >> s->eng >> s->math ;
    s->total += s->kor;
    s->total += s->eng;
    s->total += s->math;
    s->average = double(s->total) / 3;
    cout << s->total << " " ;
    printf("%.1f\n", s->average);
    cout << "Korean - " << ((s->kor >= 70) ? "Pass" : "Fail"); 
    cout << endl;;
    cout << "English - " << ((s->eng >= 70) ? "Pass" : "Fail");
    cout << endl;
    cout << "Math - " << ((s->math >= 70) ? "Pass" : "Fail"); 
    cout << endl;

    return 0;
}