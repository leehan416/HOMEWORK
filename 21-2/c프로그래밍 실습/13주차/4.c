#include <stdio.h>
#include <stdlib.h>
struct st_point{ 
    float x; 	// x좌표 값 
    float y; 	// y좌표 값 
}; 
int loadPoints(struct st_point* list[], char* filename); 
int getPosition(struct st_point* p);

int main()
{
    struct st_point* mypoint[50]; // 최대 50개의 좌표 저장용 
    int size; // 좌표 총 개수
    int count[5]={0}; // 좌표위치별 개수 (0:축 좌표 개수, 1~4:1~4분면 좌표 개수)
    size = loadPoints(mypoint, "point.txt");
    for(int i=0;i<size;i++){
        int pos = getPosition(mypoint[i]);
        count[pos]++;
    }
    printf("축의 좌표는 모두 %d개\n", count[0]);
    for(int i=1;i<=4;i++)
        printf("%d사분면의 좌표는 모두 %d개\n", i, count[i]);
    return 0;
}

int loadPoints(struct st_point* list[], char* filename){
    // 파일 열기
    FILE *fp = fopen(filename, "r");
    
    int i; // 반복문 변수

    // 파일 읽기
    for (i = 0; !feof(fp);i++){
        // 메모리 할당
        list[i] = (struct st_point *)malloc(sizeof(struct st_point));
        fscanf(fp, "%f %f", &list[i]->x, &list[i]->y);
    }
    
    // 완료 메세지 출력
    printf("point.txt에서 %d개의 좌표정보를 읽었습니다.\n", i);
    
    // 파일 닫기
    fclose (fp);
    return i;
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