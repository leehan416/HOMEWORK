
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_user {
    char userid[20];
    char userpw[20];
};

int loadUsers(struct st_user *list[], char *filename);

int findUsers(struct st_user *list[], struct st_user *input, int size);

int checkUser(struct st_user *list[], int size, struct st_user *temp);


int main() {
    struct st_user *list[10];
    struct st_user input;
    int count;
    count = loadUsers(list, "user.txt");
    while (1) {
        printf("로그인하려는 ID, PW를 입력하시오. > ");
        scanf("%s %s", input.userid, input.userpw);

        int value = checkUser(list, count, &input);
        
        if (value == 1) {
            printf("로그인 성공! : 어서오세요 %s님\n", input.userid);
            break;
        } else if (value == 2) {
            printf("로그인 실패! : 비밀번호가 틀렸습니다.\n");
        } else {
            printf("로그인 실패! : 존재하지 않는 ID입니다.\n");
        }
    }
    return 0;
}

int loadUsers(struct st_user *list[], char *filename) {
    FILE *fp = fopen(filename, "r");
    int i;
    for (i = 0; !feof(fp); i++) {
        list[i] = (struct st_user *) malloc(sizeof(struct st_user));
        fscanf(fp, "%s %s", list[i]->userid, list[i]->userpw);
    }
    printf("%d명의 로그인 정보를 읽었습니다.\n", i);
    return i;
}

int findUsers(struct st_user *list[], struct st_user *input, int size) {
    
    for (int i = 0; i < size; i++) 
        if (strcmp(list[i]->userid, input->userid) == 0) 
            return i;
    return -1;
}

int checkUser(struct st_user *list[], int size, struct st_user *temp) {
    int index = findUsers(list, temp, size);
    if (index == -1) return 3;
    if (strcmp(list[index]->userpw, temp->userpw) == 0) return 1;
    else return 2;
}