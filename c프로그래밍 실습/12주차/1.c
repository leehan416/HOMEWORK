#include <stdio.h>
#include <stdlib.h>

struct st_bmi{
  int height, weight; // 키(cm), 몸무게(kg)
  float bmi; // 비만도
  int bmi_index; // 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};

struct st_bmi* addBmi();
void evalBmi(struct st_bmi* p);

int main(void) {
  struct st_bmi* one;
	char bmi_string[4][20]={"저체중","정상","과체중","비만"};

	one = addBmi();

	printf("키: %d ", one->height);
	printf("몸무게: %d ", one->weight);
	printf("비만도: %.1f ", one->bmi);    
    printf("판정결과 : %s\n", bmi_string[one->bmi_index-1]);
	return 0;
}

struct st_bmi* addBmi(){
  struct st_bmi* p = (struct st_bmi*)malloc(sizeof(struct st_bmi));
  printf("키와 몸무게를 입력하시오 > ");
  scanf("%d %d", &(p->height), &(p->weight));
  evalBmi(p);
  return p;
}

void evalBmi(struct st_bmi* p){
    // 연산
    float value = (float)p->height * 0.01;
    p->bmi = (float)p->weight / (value * value);

    // 조건 검사
    if(p->bmi < 18.5)
        p->bmi_index = 1;
    else if(18.5<= p->bmi && p->bmi < 23)
        p->bmi_index = 2;
    else if(23 <= p->bmi && p->bmi < 25)
        p->bmi_index = 3;
    else 
        p->bmi_index = 4;
}
