#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char* pstr[20]; // 실제로 저장될 최대 20개의 문장을 위한 포인터 배열 
    char* longest;  // 가장 긴 문장을 가리키는 포인터
    char* shoetest;	// 가장 짧은 문장을 가리키는 포인터
    int max = -99;
    int min = 100;
    int index1,index2;
    int i = 0;

    FILE *file;
    file = fopen("data.txt", "r");
    char str[100]; 

    while (!feof(file)){
        if (!fgets(str, 100, file)) break;
        pstr[i] = (char *)malloc(sizeof(char) * strlen(str) + 1);
        strcpy(pstr[i], str);
        int value = strlen(pstr[i]);
        if (max < value){
            longest = pstr[i];
            max = value;
            index1 = i+1;
        }
        if (min > value){
            shoetest = pstr[i];
            min = value;
            index2 = i+1;
        }
        i ++;
    }

    printf("%d lines read.\n", i);
    printf("Longest #%d - %s", index1, longest);
    printf("Shortest #%d - %s", index2, shoetest);

    return 0;
}
