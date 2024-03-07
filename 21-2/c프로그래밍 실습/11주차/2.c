#include <stdio.h>

struct rectangle {
    int x1, y1; // 좌상점 좌표값 (왼쪽 위 모서리)
    int x2, y2; // 우하점 좌표값 (오른 아래 모서리)
};

int check_overlap(struct rectangle r1, struct rectangle r2);

int main(void) {
    struct rectangle data[2]; // 구조체 선언

    // 변수 입력
    printf("첫 번째 직사각형 좌상점 좌표값(x, y)? ");
    scanf("%d %d", &data[0].x1, &data[0].y1);
    printf("첫 번째 직사각형 우하점 좌표값(x, y)? ");
    scanf("%d %d", &data[0].x2, &data[0].y2);
    printf("두 번째 직사각형 좌상점 좌표값(x, y)? ");
    scanf("%d %d", &data[1].x1, &data[1].y1);
    printf("두 번째 직사각형 우하점 좌표값(x, y)? ");
    scanf("%d %d", &data[1].x2, &data[1].y2);

    // 검사
    if (check_overlap(data[0], data[1]))
        printf("두 직사각형은 겹칩니다.");
    else
        printf("두 직사각형은 겹치지 않습니다.");
    return 0;
}


int check_overlap(struct rectangle r1, struct rectangle r2) {
    int value = 0;

    // 겹치는 부분 있는지 검사
    
    // x 
    for (int x = r2.x1; x < r2.x2; x++) {
        if (r1.x1 <= x && x <= r1.x2) {
            value++;
            break;
        }
    }
    
    // y
    for (int y = r2.y2; y < r2.y1; y++) {
        if (r1.y2 <= y && y <= r1.y1) {
            value++;
            break;
        }
    }

    // x, y 둘다 겹친다면
    if (value == 2)
        return 1;
    else
        return 0;

}