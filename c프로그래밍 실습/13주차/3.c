#include <stdio.h>
#include <stdlib.h>
struct st_point{ 
    float x; 		// x좌표 값 
    float y; 		// y좌표 값 
}; 
struct st_point* getPoint();
void savePoints(struct st_point* list[], char* filename, int size); 

int main(){
    struct st_point* mypoint[50]; // 최대 50개의 좌표 저장용 
    int size;
    printf("좌표의 개수는? > ");
    scanf("%d", &size);
    for(int i=0;i<size;i++){
        printf("%d번째 좌표\n", i+1);
        mypoint[i] = getPoint();
    }
    savePoints(mypoint, "point.txt", size);
    return 0;
}

// 좌표 받기
struct st_point* getPoint() {
    // 메모리 할당
    struct st_point *p = (struct st_point *) malloc(sizeof(struct st_point));
    
    // 변수 입력
    printf("x, y값? ");
    scanf("%f %f", &p->x, &p->y);
    
    return p;
}

//좌표 저장하기
void savePoints(struct st_point* list[], char *filename, int size) {
    // 파일 열기
    FILE *fp = fopen(filename, "w");

    // 파일 기록
    for (int i = 0; i < size; i++)
        fprintf(fp, "%.1f %.1f\n", list[i]->x, list[i]->y);

    // 완료 메세지
    printf("\n10개의 좌표를 저장하였습니다.\n");

    // 파일 닫기
    fclose(fp);
}