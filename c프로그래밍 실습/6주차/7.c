#include <stdio.h>
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
    int count = 0;
    int index[13];

    // 변수 입력
    printf("Input >> ");
    scanf("%s", input);

    // 4글자 미만이면
    if (strlen(input) < 4) {
        printf("3글자 이상 입력해주세요.");
        return 0;
    }

    // data검사
    for (int i = 0 ; i < 13; i++) {
        short value = 1; // true 
        for (int j= 0 ; j < strlen(input) ; j++)            
            if (input[j] != names[i][j]) // 만약 다르면
                value = 0; // false 
            
        if (value) { // 일치
            index[count] = i; 
            count ++;
        }
    }

    // 결과 출력
    printf("Matching : \n");
    for (int i = 0 ; i < count ; i ++)
        printf ("[%s]\n",names[index[i]]);
    printf ("%d major found", count);

    return 0;
}
