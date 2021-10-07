#include <stdio.h>
#include <string.h>
int main(void) {
    char input[8];
    int sum = 0;

    // 변수 입력
    printf("Enter your birthdate >> ");  
    scanf("%s",input);
    
    // 년도 더하기
    for (int i = 0; i < 4; i++) 
        sum += input[i] - 48;
    
    // month, day
    for (int i = 4; i < 8; i ++)
        if (i % 2 == 0) // 짝수번째 일 때
            sum += (input[i] - 48) * 10; // 10의 자리
        else 
            sum += (input[i] - 48);
    
    printf("Your birthdate number is %d.", sum);
    
    return 0;
}