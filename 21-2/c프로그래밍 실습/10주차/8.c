#include <stdio.h>
#include <string.h>

int main(void) {
    char text[13][100];
    int max = -9, min = 100;
    int maxIndex, minIndex, i;
    FILE *file;
    //파일 열기
    file = fopen("name.txt", "r");

    // 데이터 읽기
    for (i = 0; !feof(file); i++) {
        fgets(text[i], sizeof(text), file);
        text[i][strlen(text[i]) - 1] = '\0';
        int value = strlen(text[i]);
        if (max < value) {
            max = value;
            maxIndex = i;
        }
        if (min > value) {
            min = value;
            minIndex = i;
        }

    }
    // 파일 닫기
    fclose(file);

    // 데이터 출력
    printf("Count : %d\n", i);
    printf("Longest name : %s\n", text[maxIndex]);
    printf("Shortest name : %s", text[minIndex]);

    return 0;
}