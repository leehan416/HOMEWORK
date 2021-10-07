#include<stdio.h>
#include <string.h>

int main(void) {
    char names[13][100] = {
        "Global Leadership School",
        "International Studies, Languages and Literature",
        "Management and Economics",
        "Law",
        "Counseling Psychology and Social Welfare",
        "Communication Arts",
        "Spatial Environment System Engineering",
        "Mechanical and Control Engineering",
        "Contents Convergence Design",
        "Life Science",
        "Computer Science and Electrical Engineering",
        "Global Entrepreneurship and ICT",
        "Creative Convergence Education"
    };
    char input[100];
    int count = 0; // 문자열 갯수
    int index[13] = {0,}; // 문자열 위치 저장
    int valCount; // 같은 글자 갯수
    
    // 변수 입력
    printf("Input >> ");
    scanf("%s", input);

    // 검사용 변수    
    short value[strlen(input)];

    for (int i = 0; i < 13; i++) {
        if (strlen(input) > strlen(names[i]))
            continue;
        
        for (int j = 0; j < strlen(names[i]) - strlen(input) + 1; j++) {

            for (int n = 0; n < strlen(input); n++) // 변수 초기화
                value[n] = 0;

            for (int k = 0; k < strlen(input) ; k++) { // 글자 내에서 비교

                if (input[k] == names[i][j + k]) // 동일하면
                    value[k]++; // 각 value 를 true 로 변경

                else
                    break;
            }

            valCount = 0;
            for (int k = 0; k < strlen(input); k++) {
                if (value[k])
                    valCount++;
            }
            if (valCount >= strlen(input)) {
                index[count++] = i;
                break;
            }
        }
    }

    // 결과 출력
    printf("Matching : \n");
    for (int i = 0; i < count; i++)
        printf("[%s]\n", names[index[i]]);
    printf("%d major found", count);
    
    return 0;
}