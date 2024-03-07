#include <stdio.h>
#include <stdlib.h>

struct st_bmi{
    int height, weight; 	// 키(cm), 몸무게(kg)
    float bmi; 				// 비만도
    int bmi_index; 			// 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};

int loadBmi(struct st_bmi* list[], char* filename);
void evalBmi(struct st_bmi* p);

int main(void) {
	struct st_bmi* bmilist[50];  // 최대 50명의 비만도 데이터
	char bmi_string[4][20]={"저체중","정상","과체중","비만"};
	int count = loadBmi(bmilist, "data.txt");
	// 이곳에 코드 작성!

    printf("%d명의 데이터를 읽었습니다.\n", count);
    for (int i = 0 ;i < count;  i++)
        printf("%d번 분. 키: %d 몸무게: %d 비만도: %.1f 판정결과 : %s\n", i + 1, 
        bmilist[i]->height, bmilist[i]->weight, bmilist[i]->bmi, bmi_string[bmilist[i]->bmi_index-1]);
	return 0;
}


int loadBmi(struct st_bmi* list[], char* filename){
    int count = 0;
    // 파일 읽기
    FILE *file = fopen (filename, "r");
    int h, w; 

    for (int i = 0;  i < 10; i++) {
        fscanf(file, "%d %d",&h,&w );
        count++;
        list[i] = (struct st_bmi*) malloc(sizeof(struct st_bmi));
        list[i]->height = h;
        list[i]->weight = w;
        evalBmi(list[i]);
    }
    fclose(file);
    return count;
}

void evalBmi(struct st_bmi* p){
    // 비만도 연산
    float value = (float)p->height * 0.01;
    p->bmi = p->weight /(value * value);

    // 비만도 정도 
    if (p->bmi < 18.5 )
        p->bmi_index = 1;
    else if (18.5 <= p->bmi && p->bmi < 23)
        p->bmi_index = 2;
    else if (23 <= p->bmi && p->bmi < 25)
        p->bmi_index = 3;
    else
        p->bmi_index = 4;
}