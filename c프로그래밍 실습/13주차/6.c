#include <stdio.h>
#include <stdlib.h>

struct st_jumsu{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

int loadJumsu(struct st_jumsu* p[], char* filename);
void evalScore(struct st_jumsu* p);
void evalClass(struct st_jumsu* p[], int sum[], float avg[], int size);

int main()
{
    struct st_jumsu* jumsu[10]; 	// 최대 10명의 점수 저장용 포인터 배열 
    int count; // 점수 개수
    int classsum[3]; 			// 과목별 총점
    float classavg[3]; 			// 과목별 평균
    char classname[3][20]={"국어","영어","수학"};
    count = loadJumsu(jumsu, "data.txt");
    for(int i=0;i<count;i++)
        evalScore(jumsu[i]);
    evalClass(jumsu, classsum, classavg, count);
    printf("1) 각 과목별 총점과 평균점수\n");
    for(int i=0;i<3;i++)
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i],classsum[i], classavg[i]);
    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
    for(int i=0;i<5;i++)
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg, jumsu[i]->grade);
    return 0;
}

int loadJumsu(struct st_jumsu* p[], char* filename) {
    // 파일 열기
    FILE *fp = fopen (filename, "r");
    int i;
    
    // 파일 읽기
    for (i = 0 ; !feof(fp); i++){
        // 메모리 할당
        p[i] = (struct st_jumsu *)malloc(sizeof(struct st_jumsu));
        fscanf(fp, "%d %d %d", &p[i]->kor, &p[i]->eng, &p[i]->mat);
    }
    
    // 완료 메세지 출력
    printf("%d명의 점수를 읽었습니다.\n", i);
    return i;
}

void evalScore(struct st_jumsu* p) {
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

void evalClass(struct st_jumsu *p[], int sum[], float avg[], int size) {
    int _sum = 0;
    int index = 0;
    for (int i = 0; i < size; i++) 
        _sum += p[i]->kor;
    
    sum[index] = _sum;
    avg[index++] = _sum / size;

    _sum = 0;
    for (int i = 0; i < size; i++) 
        _sum += p[i]->eng;
    sum[index] = _sum;
    avg[index++] = _sum / size;

    _sum = 0;
    for (int i = 0; i < size; i++) 
        _sum += p[i]->mat;
    sum[index] = _sum;
    avg[index++] = _sum / size;
    
}