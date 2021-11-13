#include <stdio.h>
#include <math.h>

struct point {
    float x; // x좌표 값
    float y; // y좌표 값
};

float calcDistance(struct point *p1, struct point *p2); // 두 점의 거리 구하는 함수

int main(void) {
    struct point p[2];

    // 변수 입력
    printf("첫 번째 좌표의 x값? ");
    scanf("%f", &p[0].x);
    printf("첫 번째 좌표의 y값? ");
    scanf("%f", &p[0].y);
    printf("두 번째 좌표의 x값? ");
    scanf("%f", &p[1].x);
    printf("두 번째 좌표의 y값? ");
    scanf("%f", &p[1].y);

    // 결과 출력
    printf("\n두 좌표 사이의 거리는 %.1f", calcDistance(&p[0], &p[1]));
    return 0;
}


float calcDistance(struct point *p1, struct point *p2) {
    float x = p1->x - p2->x;
    float y = p1->y - p2->y;
    return sqrtf(powf(x, 2) + powf(y, 2));
}