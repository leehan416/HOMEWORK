#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *findLongestWord(char *str);

int main(void) {

    char line[100];     // 입력받을 문장 
    // fgets(line, 100, stdin); 
    line[strlen(line) - 1] = '\0';

    // 이곳에 코드를 작성하라
    // -------------------------------------------------------
    char output[100];

    // 문자열 입력
    printf("문장 입력 > ");
    fgets(line, sizeof(line), stdin);

    line[strlen(line) - 1] = '\0';

    // 결과 출력
    printf("결과 > %s 중에 가장 긴 단어는 %s, 길이 %d입니다.",
           line, findLongestWord(line), (int) strlen(findLongestWord(line))
    );
    return 0;
}

char *findLongestWord(char *str) {
    static char words[100][100] = {0,};
    int wordIndex = 0;
    int textIndex = 0;

    int count = 0;
    int max = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n') {
            wordIndex++;
            textIndex = 0;
        } else
            words[wordIndex][textIndex++] = str[i];
    }

    for (int i = 0; words[i][0] != 0; i++) {
        count = 0;
        for (int j = 0; j < strlen(words[i]); j++)
            count++;
        if (max < count) {
            max = count;
            wordIndex = i;
        }
    }
    return words[wordIndex];
}