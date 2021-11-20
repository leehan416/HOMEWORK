#include <stdio.h>
#include <stdlib.h>

struct st_jumsu{
 int kor, eng, mat;
 int sum;
 float avg;
 char grade;
};

struct st_jumsu* getScore();
void evalScore(struct st_jumsu* p);
//제공된 코드, main() 수정 금지
int main(){
	struct st_jumsu* score = getScore();
	evalScore(score);
	printf("학생의 총점은 %d 평균은 %.1f (등급 %c)\n",score->sum, score->avg, score->grade);
	return 0;
}


struct st_jumsu* getScore(){
    struct st_jumsu* p = (struct st_jumsu* )malloc(sizeof(struct st_jumsu));
    printf("국어 점수? > ");
    scanf("%d",&p->kor);
    printf("영어 점수? > ");
    scanf("%d",&p->eng);
    printf("수학 점수? > ");
    scanf("%d",&p->mat);
    
    return p;
}

void evalScore(struct st_jumsu* p){
    p->sum = p->kor + p->eng + p->mat;
    p->avg = (float) p->sum / 3.0;
    float value = p->avg;
    if (90 <= value)
        p->grade = 'A';
    else if (80 <= value && value < 90)
        p->grade = 'B';
    else if (70 <= value && value < 80)
        p->grade = 'C';
    else if (60 <= value && value < 70)
        p->grade = 'D';
    else
        p->grade = 'F';
}