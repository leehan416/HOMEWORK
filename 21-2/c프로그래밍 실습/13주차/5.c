#include <stdio.h>
#include <stdlib.h>

struct st_jumsu {
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

struct st_jumsu* getJumsu();
void evalScore(struct st_jumsu* p);

int main(){
    struct st_jumsu* jumsu[5]; // 5명의 점수 저장용 포인터 배열 
    for(int i = 0; i < 5; i++){
        printf("%d번 학생\n", i+1);
        jumsu[i] = getJumsu();
		evalScore(jumsu[i]);
        // printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg, jumsu[i]->grade);
    }
    // 테스트 케이스 통과를 위해 main 함수를 수정했습니다.
    for(int i = 0; i < 5; i++)
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg, jumsu[i]->grade);
    return 0;
}

struct st_jumsu* getJumsu() {
    // 메모리 할당
    struct st_jumsu* p = (struct st_jumsu*) malloc(sizeof(struct st_jumsu));

    // 변수 입력
    printf("국어, 영어, 수학 점수를 입력하시오. > ");
    scanf("%d %d %d" , &p->kor, &p->eng, &p->mat);

    return  p;
}

void evalScore(struct st_jumsu* p) {
    // 연산
    p->sum =  p->kor + p->eng + p->mat;
    p->avg = p->sum / 3.0;
    p->grade = 'A';
    if (80 <= p->avg && p->avg < 90)
        p->grade++;
    else if (70 <= p->avg && p->avg < 80)
        p->grade+= 2;
    else if (60 <= p->avg && p->avg < 70)
        p->grade+= 3;
    else 
        p->grade+= 5;
}