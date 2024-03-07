#include <stdio.h>
#include <string.h>

int main(void) {
    //data set
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
    // 최댓값 최솟값
    int max = 0;
    int min = 100;
    // index 저장 변수
    int index[2];

    for (int i =0 ; i < 13 ; i ++) { // 최솟값 최댓값 찾기
        if (max < strlen(names[i])){
            max = strlen(names[i]);
            index[0] = i;
        } else if (min > strlen(names[i])){
            min = strlen(names[i]);
            index[1] = i;
        }
    }

    // 걀과 출력
    printf("가장 긴 학부 이름은 %s\n",names[index[0]]);
    printf("가장 짧은 학부 이름은 %s 입니다.",names[index[1]]);

    return 0;
}