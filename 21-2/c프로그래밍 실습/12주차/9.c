#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st_menu{ 
    int no; 				// 메뉴번호
    char name[20]; 			// 메뉴명 
    char madein[20]; 			// 원산지 
    int price; 				// 가격 
};

struct st_menu* getMenu();

int main(void) {
    struct st_menu *menu; 	// 메뉴 구조체 포인터
  
    menu = getMenu();
    printf("메뉴번호 메뉴이름 원산지 1인분가격\n");
    printf("%4d    %s %s   %d", menu->no, menu->name, menu->madein, menu->price);
    return 0;
}

struct st_menu *getMenu(){
    struct st_menu *p = (struct st_menu *) malloc (sizeof(struct st_menu)); 
    printf("메뉴번호, 메뉴명, 원산지, 가격을 입력하라. > ");
    scanf("%d %s %s %d", &p->no, p->name, p->madein, &p->price);
    return p;
}   