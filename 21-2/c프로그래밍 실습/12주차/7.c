#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct st_user{
    char userid[20];
    char userpw[20];
};

struct st_user* get_User();

int main(void) {
    struct st_user *user;
    user = get_User();

    printf("\nUser ID: %s\n", user->userid);
    printf("Password: ");
    for (int i = 0; i < 2; i++)
        printf("%c",user->userpw[i]);
    for (int i = 2; i < strlen(user->userpw); i++)
        printf("*");

	return 0;
}

struct st_user* get_User(){
    struct st_user *p = (struct st_user *) malloc (sizeof(struct st_user));

    while(1){
        printf("User ID? ");
        scanf("%s", p->userid);
        if (strlen(p->userid) >= 4) break;
        printf("-> 4글자 이상 입력할 것\n");
    }   
    while(1){
        printf("Password? ");
        scanf("%s", p->userpw);
        if (strlen(p->userpw) >= 4) break;
        printf("-> 4글자 이상 입력할 것\n");
    } 

    return p;
}