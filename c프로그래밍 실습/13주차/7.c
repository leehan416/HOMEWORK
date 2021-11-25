#include <stdio.h>
#include <stdlib.h>

struct st_menu{ 
    int no; 				// 메뉴번호
    char name[20]; 			// 메뉴명 
    char madein[20]; 		// 원산지 
    int price; 				// 가격 
};

struct st_menu* getMenu();
void saveMenu(struct st_menu* list[], char* filename, int size);

int main() {
    struct st_menu* menu[10]; 	// 최대 10개의 메뉴 저장용 포인터 배열 
    for(int i=0;i<5;i++){
        printf("%d번째 메뉴\n",i+1);
        menu[i] = getMenu();
    }
    saveMenu(menu,"menu.txt",5);
    return 0;
}

struct st_menu* getMenu() {
    struct st_menu *p = (struct st_menu *) malloc(sizeof(struct st_menu));
    printf("메뉴의 번호, 메뉴명, 원산지, 가격을 입력하라. > ");
    scanf("%d %s %s %d", &p->no, p->name, p->madein, &p->price);
    return p;
}

void saveMenu(struct st_menu* list[], char* filename, int size) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp,"메뉴번호 메뉴이름 원산지 1인분 가격\n");
    for (int i = 0 ; i < size; i++)
        fprintf(fp,"%d %s %s %d\n", list[i]->no, list[i]->name, list[i]->madein, list[i]->price);
    printf("%s에 저장했습니다.\n", filename);
    fclose(fp);
}
