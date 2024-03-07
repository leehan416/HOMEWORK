#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_person{
 char name[20];
 char address[80];
 int age;
}; 

struct st_person* getPerson(); // 메모리를 동적 할당하여 인적사항을 입력받아 저장한 후 포인터 리턴

int main(void) {
    struct st_person* p[3];

    //제공된 코드 – main() 일부
    for(int i=0; i<3; i++){
        printf("#%d 인적사항을 입력하시오.\n",i+1);
        p[i] = getPerson();
    }

    for (int i = 0; i < 3; i++)
        printf("#%d : %s/ %s/ %d\n", i + 1, p[i]->name, p[i]->address, p[i]->age);

  return 0;
}

struct st_person *getPerson() {
    struct st_person *p = (struct st_person *)malloc(sizeof(struct st_person));
    char a[3];

    printf("이름은? ");
    fgets(p->name, 100, stdin);
    p->name[strlen(p->name) - 1] = '\0';
    printf("주소는? ");
    fgets(p->address, 100, stdin);
    p->address[strlen(p->address)] = '\0';
        
    char age[5];
    printf("나이는? ");
    fgets(age, 4, stdin);
    p->age = (age[0] - '0') * 10 + age[1] - '0';
    p->address[strlen(p->address) - 1] = '\0';

    return p;
}