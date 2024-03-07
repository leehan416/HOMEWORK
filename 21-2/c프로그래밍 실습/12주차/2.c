#include <stdio.h>
#include <stdlib.h>

struct rectangle{ 
    int x1, y1; 		// 좌상점 좌표값 (왼쪽 위 모서리) 
    int x2, y2; 		// 우하점 좌표값 (오른 아래 모서리) 
}; 

int checkOverlap(struct rectangle* r1, struct rectangle* r2); // 겹치면 1리턴, 아니면 0리턴
struct rectangle* getPoints();	// 구조체 메모리를 할당받아 좌표를 입력받은 후 주소값 리턴

//main() 함수의 코드는 다음과 같다. (수정 금지!)
int main(){
	struct rectangle* rect1;  	// 첫 번째 직사각형을 위한 구조체 포인터
	struct rectangle* rect2;  	// 첫 번째 직사각형을 위한 구조체 포인터
	printf("직사각형 #1\n");
	rect1 = getPoints();
	printf("직사각형 #2\n");
	rect2 = getPoints();
	if (checkOverlap(rect1, rect2)) 
		printf("두 직사각형은 겹칩니다.\n");
	else
		printf("두 직사각형은 겹치지 않습니다.\n");
	return 0;
}


int checkOverlap(struct rectangle* r1, struct rectangle* r2){ // 겹치면 1리턴, 아니면 0리턴
    int value = 0;

    // 겹치는 부분 있는지 검사
    // x 
    for (int x = r2->x1; x < r2->x2; x++) {
        if (r1->x1 <= x && x <= r1->x2) {
            value++;
            break;
        }
    }
    
    // y
    for (int y = r2->y2; y < r2->y1; y++) {
        if (r1->y2 <= y && y <= r1->y1) {
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

struct rectangle* getPoints(){
    // 메모리 할당
    struct rectangle* p = (struct rectangle*)malloc(sizeof(struct rectangle));
    
    //입력
    printf("좌상점 좌표값(x, y)? ");
    scanf("%d %d", &p->x1, &p->y1);
    printf("우하점 좌표값(x, y)? ");
    scanf("%d %d", &p->x2, &p->y2);
    return p;
}