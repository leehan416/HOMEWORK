//5
//22100594 이한결
#include <stdio.h>
#include <string.h>

int checkLength(char str[100]);

int checkNumandEng(char str[100]);

int checkUseable(char str[100]);

int checkSame(char str[100]);

int main() {
    char pw[100];
    int value = 0; // isnt it pass?
    printf("Input Password");
    scanf("%s", pw);

    if (checkLength(pw)) {
        printf("5자리 이상, 12자리 이하의 길이가 필요합니다\n");
        value++;
    }
    if (checkNumandEng(pw)) {
        printf("영문자와 숫자를 반드시 포함하여야 합니다.\n");
        value++;
    }
    if (checkUseable(pw)) {
        printf("특수문자는 사용할 수 없습니다.\n");
        value++;
    }
    if (checkSame(pw)) {
        printf("동일문자를 3회이상 활용할 수 없습니다.\n");
        value++;
    }


    if (value == 0) {
        printf("정상적인 id입니다.");
    }

    return 0;
}


int checkLength(char str[100]) {
    int length = strlen(str);
    if (5 <= length && length <= 12)
        return 0;
    else
        return 1;
}

int checkNumandEng(char str[100]) {
    int length = strlen(str);
    int sum[2] = {0, 0};
    for (int i = 0; i < length; i++) {
        if ('0' <= str[i] && str[i] <= '9') // 숫자일 때
            sum[0]++;
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) // 영어일 때
            sum[1]++;
    }

    if (sum[0] && sum[1])
        return 0;
    else
        return 1;
}

int checkUseable(char str[100]) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (('0' <= str[i] && str[i] <= '9') || (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')))
            continue;
        else
            return 1;
    }
    return 0;
}

int checkSame(char str[100]) {

    int sum = 0;
    int length = strlen(str);
    for (int i = 0; i < length - 1; i++) {
        if (sum > 2) {
            return 1;
        } else {
            if (str[i] == str[i + 1])
                sum++;
            else sum = 0;
        }
    }
}