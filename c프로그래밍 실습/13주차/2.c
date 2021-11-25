#include <stdio.h>
#include <stdlib.h>

#define size 10

struct st_point{ 
    float x; // x좌표 값 
    float y; // y좌표 값 
}; 

struct st_point* getPoint(); 
// 메모리 할당받아 좌표 구조체의 x,y 값을 입력받아 이 주소값을 리턴함

int getPosition(struct st_point* p);
// 리턴값 : 좌표의 사분면 위치 (0:축, 1:1사분면, 2:2사분면, 3:3사분면, 4:4사분면)
// 수행내용 : 전달받은 좌표의 위치를 파악하여 위치번호(0~4)를 리턴함

int main(void) {
    struct st_point* mypoint[10]; 
    
    // 겟수 저장 배열
    int count [5] = {0};
    
    //입력
    for (int i = 0;i < size; i++){
        printf("%d번째 좌표\n", i + 1);
        mypoint[i] = getPoint();
    }


    // 결과 출력
    for (int i = 0; i < size; i++) {
        int value = getPosition(mypoint[i]);
        if (value == 0){
                printf("%d번째 좌표 축에 위치\n", i + 1);
                count[0]++;
        } else {
            printf("%d번째 좌표 %d사분면에 위치\n", i + 1, value);
            count[value]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i == 0) printf("축의 좌표는 모두 %d개\n", count[0]);
        else printf("%d사분면의 좌표는 모두 %d개\n",i, count[i]);
    }

    // 메모리 해제
    for (int i = 0 ; i < size; i++)
        free(mypoint[i]);

    return 0;
}

struct st_point* getPoint(){
    //메모리 할당
    struct st_point* p = (struct st_point*) malloc(sizeof(struct st_point));

    // 입력
    printf("x, y값? ");
    scanf("%f %f", &(p->x) ,&(p->y));

    return p;
}

int getPosition(struct st_point* p){
    if ((p->x == 0.0) || (p->y == 0.0)){
        return 0;
    }

    if (p->x > 0.0){
        if (p->y < 0.0) return 4;
        else return 1;
    } else {
        if (p->y < 0.0) return 3;
        else return 2;
    }
}