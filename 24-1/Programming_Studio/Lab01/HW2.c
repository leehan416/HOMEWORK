#include <stdio.h>

int main () {
    int person[4][3] = {0};    // 4개 층별 3개 호실의 점호 인원 수
    int sum[3] = {0};          // 점호 인원 수 합계 (남, 여, 전체) 
    float ratio[3] = {0};      // 점호 인원 수 비율 (남, 여, 전체)
    int i, j;            // 반복문을 위한 변수
 
    int numOfPerStudent = 24;

    for (i = 1; i < 5; i++) {
        if (i == 1 || i == 3){
            printf("Check Room (%s)\n", (i == 1) ? "MEN" : "WOMEN");
        }
        for (j = 1; j < 4; j++){
            int value;
            printf("Room #%d0%d > ", i, j);
            scanf("%d", &value);

            person[i - 1][j - 1] = value;
            
            if (i < 3) {
                sum[0] += value;
            } else {
                sum[1] += value;
            }
            sum[2] += value;
        }
    }
    for (i = 0; i < 3; i++) {
        ratio[i] = (float)sum[i] / (float)(numOfPerStudent * ((i == 2)? 2 : 1)) * 100;
    }
    printf("Check Result\n");
    printf("Men: %d / %d (%.1f %%)\n", sum[0], numOfPerStudent, ratio[0]);
    printf("Women: %d / %d (%.1f %%)\n", sum[1], numOfPerStudent, ratio[1]);
    printf("Total: %d / %d (%.1f %%)\n", sum[2], numOfPerStudent * 2, ratio[2]);

    return 0;
}


// Men: 9/24 (37.5%) Women: 21/24 (87.5%) Total: 30/48 (62.5%)