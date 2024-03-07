#include <stdio.h>
#include <string.h>

int main(void) {
    char input[256];
    int index = 0;
    short value = 1;
    
    // 변수 입력
    printf("Sentence > ");
    fgets(input, sizeof(input), stdin);

    for (int i = strlen(input); i > -1; i--) {
        if (97 <= input[i] && input[i] < 123) { // 알파벳 인지 검사
            while (!(97 <= input[index] && input[index] < 123)) // 알파벳인지 검사
                index++;
            if (input[index] != input[i]){ // 다른지 검사
                value = 0;
                break; // 다르면 반복문 나가기
            } else {
                index++;
            }
        } 
    }

    // 결과 출력
    if (value) 
        printf("Palindrome!");
    else 
        printf("Not Palindrome!");
    

    return 0;
}