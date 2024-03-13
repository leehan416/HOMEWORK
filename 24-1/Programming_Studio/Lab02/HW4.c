//22100594 HanGyeol Lee

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class {
    int code;        // class code
    char name[30];    // class name
    int unit;        // credites
    int grading;    // grading (1:A+~F, 2:P/F)
};

char kname[2][10] = {"A+~F", "P/F"}; // String for grading

// Functions provided
int loadData(struct st_class *c[]); // Load all class list from data file.
void printAllClasses(struct st_class *c[], int csize); // Print all class list

// Functions for modifying
int addNewClass(struct st_class *c[], int csize); // Add a class into the list
void editClass(struct st_class *c[], int csize); // Modify a class in the list
void findClasses(char *name, struct st_class *c[], int csize); // Search a class by name from the list

// Functions for making
int applyMyClasses(int my[], int msize, struct st_class *c[], int csize); // Apply a class
void printMyClasses(int my[], int msize, struct st_class *c[], int csize); // Print my classes
void saveMyClass(int my[], int msize, struct st_class *c[], int csize); // Save my classes
void saveAllClasses(struct st_class *c[], int csize); // Save all class list


int main(void) {
    int no;    // menu number 
    struct st_class *classes[50]; // Class list (max. 50 classes)

    int myclass[10]; // My classes (max. 10 classes of code)
    int mycount = 0; // Amount of my classes

    srand(time(0));
    int count = loadData(classes);
    printf("> Load %d classes.\n", count);

    while (1) {
        printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n");
        printf(">> Menu? > ");
        scanf("%d", &no);

        if (no == 1) {
            printf("> 1.Class list (%d classes)\n", count);
            printAllClasses(classes, count);
        } else if (no == 2) {
            printf("> 2.Add a Class\n");
            count = addNewClass(classes, count);
        } else if (no == 3) {
            printf("> 3.Modify a Class\n");
            editClass(classes, count);
        } else if (no == 4) {
            printf("> 4.Search a Class\n");
            printf(">> Enter class name > ");
            char name[30];
            scanf("%s", name);
            findClasses(name, classes, count);
        } else if (no == 5) {
            printf("> 5.Apply a class\n");
            mycount = applyMyClasses(myclass, mycount, classes, count);
            printf("%d classes has been applied.\n", mycount);
        } else if (no == 6) {
            printf("> 6.My classes\n");
            printMyClasses(myclass, mycount, classes, count);
        } else if (no == 7) {
            printf("> 7.Save\n");
            saveMyClass(myclass, mycount, classes, count);
            printf("\n> All my classes ware saved to my_classes.txt.\n");
            saveAllClasses(classes, count);
            printf("\n> All of class list ware saved to classes.txt.\n");
        } else break;
    }
    return 0;
}

int loadData(struct st_class *c[]) {
    int count = 0;
    FILE *file;

    file = fopen("classes.txt", "r");
    while (!feof(file)) {
        c[count] = (struct st_class *) malloc(sizeof(struct st_class));
        int r = fscanf(file, "%d %s %d %d", &(c[count]->code), c[count]->name, &(c[count]->unit), &(c[count]->grading));
        if (r < 4) break;
        count++;
    }
    fclose(file);
    return count;
}

void printAllClasses(struct st_class *c[], int csize) {
    for (int i = 0; i < csize; i++) {
        printf("[%d] %s [credit %d - %s]\n", c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading - 1]);
    }
}


// 7-1) 교과목 목록 파일로 저장하기: saveAllClasses() 완성 코드 제공됨 > 현재의 교과목 목록 과목 목록을 classes.txt에 저장한다.
// > 저장 포맷 : 과목코드 과목명 학점수 평가방식
// > 과목 코드 : 3자리 숫자
// > 평가 방식 : 1 A+~F 방식, 2 Pass/Fail 방식
void saveAllClasses(struct st_class *c[], int csize) {
    FILE *file;
    file = fopen("classes.txt", "w");
    for (int i = 0; i < csize; i++) {
        fprintf(file, "%d %s %d %d\n", c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
    }
    fclose(file);
}


// 4) 교과목 목록 검색하기: findClasses() 완성 코드 제공됨 > 
// 과목이름 일부를 입력받아 과목 정보를 출력한다.
void findClasses(char *name, struct st_class *c[], int csize) {
    int count = 0;

    printf("Searching (keyword : %s)\n", name);
    for (int i = 0; i < csize; i++) {
        if (strstr(c[i]->name, name)) {
            printf("[%d] %s [credit %d - %s]\n", c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading - 1]);
            count++;
        }
    }
    printf("%d classes found.\n", count);
}

// 2) 교과목 목록 추가하기: addNewClass() 함수에서 제공된 코드에 추가 구현하여 완성해야 함 int addNewClass(struct st_class* c[], int csize);
// 파라미터: 교과목 목록 구조체포인터 배열, 교과목 목록 과목 개수
// 리턴값: 추가되어 늘어난 총 과목 개수
// 하는 일: 현재 교과목 목록에 새로운 과목을 추가하고, 증가한 과목 개수를 리턴한다.
// > 수정해야 하는 내용: 과목 추가 시, 이미 등록된 과목코드가 추가되지 않도록 코드를 수정하라. (clear)

// You must complete these functions.
int addNewClass(struct st_class *c[], int csize) {
// Caution : Don't allow the duplicate class code.
// You must complete this function.

    struct st_class *p = (struct st_class *) malloc(sizeof(struct st_class));

//------------------------------------------------
    int value = 0; // true -> 존재하는 코드
    while (1) {
        printf(">> code number > ");
        scanf("%d", &(p->code));
        for (int i = 0; i < csize; i++) {
            if (p->code == c[i]->code) {
                printf("이미 존재하는 코드입니다.\n");
                value = 1;
            }
        }
        if (!value) break;
    }
//------------------------------------------------

    printf(">> class name > ");
    scanf("%s", p->name);
    printf(">> credits > ");
    scanf("%d", &(p->unit));
    printf(">> grading (1: A+~F, 2: P/F) > ");
    scanf("%d", &(p->grading));

    c[csize] = p;
    return csize + 1;
}

// 3) 교과목 목록 수정하기: editClass() 함수에서 제공된 코드에 추가 구현하여 완성해야 함 void editClass(struct st_class* c[], int csize);
// 파라미터: 교과목 목록 구조체포인터 배열, 수강목록 과목 개수
// 리턴값: 없음
// 하는 일: 현재 교과목 목록에서 입력된 과목코드에 해당하는 과목 정보를 새로 입력받아 수정한다.
// > 수정해야 하는 내용: 과목코드를 입력받은 후, 수정작업을 진행하기 위해 과목구조체 포인터의 값을 할당하는 과정을 코드에 반영하여 수정하라. (clear)
// 과목코드가 존재하지 않는 경우도 적절하게 처리하라. (clear)
void editClass(struct st_class *c[], int csize) {
    // struct st_class *p; 

    struct st_class *p = (struct st_class *) malloc(sizeof(struct st_class));

    int code;

//----------------------------------------------------------
    int index = -1; // index 저장용

    while (1) {
        //입력
        printf(">> Enter a code of class > ");
        scanf("%d", &code);

        //검색
        for (int i = 0; i < csize; i++) {
            if (code == c[i]->code) { // 찾음
                index = i;
            }
        }
        if (index != -1) { // 찾았다면
            *p = *c[index];
            break;
        } else {
            printf("과목 코드를 찾을 수 없습니다.\n");
        }
    }

//----------------------------------------------------------
    // You must complete this section.

    printf("> Current: [%d] %s [credits %d - %s]\n", p->code, p->name, p->unit, kname[p->grading - 1]);
    printf("> Enter new class name > ");
    scanf("%s", p->name);
    printf("> Enter new credits > ");
    scanf("%d", &(p->unit));
    printf("> Enter new grading(1:Grade, 2: P/F) > ");
    scanf("%d", &(p->grading));

//----------------------------------------------------------
    free(c[index]); //null
    c[index] = p; // 적용
//----------------------------------------------------------
    printf("> Modified.\n");
}


// You must make all these functions.




// 5) 내 수강과목 등록하기: applyMyClasses() 함수 내 코드를 직접 제작할 것
// int applyMyClasses(int my[], int msize, struct st_class* c[], int csize); 파라미터 : 내가 신청한 과목코드 배열, 신청한 과목 개수, 교과목 목록 구조체포인터 배열,
// 교과목 목록 과목 개수
// 리턴값 : 변경된 내 수강과목 개수
// 하는 일 : 과목코드를 입력받아 내 수강신청 과목을 추가로 등록하는 과정을 반복하다가 끝나면
// 최종 등록된 내 수강과목의 개수를 리턴한다.
// > 반드시 과목코드가 중복되는 경우, 과목코드가 존재하지 않는 경우를 검사해야 한다. (clear)


int applyMyClasses(int my[], int msize, struct st_class *c[], int csize) {
    int code; // 입력 변수
    int index = -1;

    while (1) {
		index = -1;
        printf(">> Enter a class code > ");
        scanf("%d", &code);

        for (int i = 0; i < csize; i++) { // search
            if (code == c[i]->code) { // 찾았다면
                index = i;
                break;
            }
        }

        if (index != -1) {

            for (int i = 0; i < msize; i++) { // 중복 검사
                if (code == my[i]) { // 중복
                    printf("이미 추가된 수업입니다\n");
                    index = -2;
                    break;
                }
            }
            if (index == -2) { // 다시 입력 받으세요
                continue;
            }


            my[msize++] = code;

            printf(">> [%d] %s [credit %d - %s]\n", c[index]->code, c[index]->name, c[index]->unit,
                   (c[index]->grading == 1) ? "A+~F" : "P/F");


        } else {
            printf("No such code of class.\n");
        }

        printf(">> Add more?(1:Yes 2:No) > ");
        scanf("%d", &code);
        if (code == 2) break;

    }
    return msize;
}


// 6) 내 수강과목 출력하기: printMyClasses() 함수 내 코드를 직접 제작할 것
// void printMyClasses(int my[], int msize, struct st_class* c[], int csize);
// 파라미터 : 내가 신청한 과목코드 배열, 내가 신청한 과목 개수, 교과목 목록 구조체포인터 배열,
// 교과목 목록 과목 개수 리턴값 : 없음
// 하는 일 : 내가 수강신청한 과목의 모든 정보를 출력한다. (clear)


void printMyClasses(int my[], int msize, struct st_class *c[], int csize) {
    int index;
    int units = 0;
    for (int i = 0; i < msize; i++) {
        for (int j = 0; j < csize; j++) {
            if (c[j]->code == my[i]) {
                index = j;
                break;
            }
        }


        printf("[%d] %s [credit %d - %s]\n", c[index]->code, c[index]->name, c[index]->unit,
               (c[index]->grading == 1) ? "A+~F" : "P/F");
        units += c[index]->unit;
    }
    printf("All : %d credits\n", units);
}


// 7-2) 내 수강과목 파일로 저장하기: saveMyClass() 함수 내 코드를 직접 제작할 것
// void saveMyClass(int my[], int msize, struct st_class* c[], int csize);
// 파라미터 : 내가 신청한 과목코드 배열, 신청한 과목 개수, 교과목 목록 구조체포인터 배열, 교과목 목록 개수 리턴값 : 없음
// 하는 일 : 나의 수강신청 과목의 모든 과목정보를 my_classes.txt 파일로 저장한다.
// 파일에 포함해야 하는 내용 : 내가 신청한 수강 과목 목록 (과목코드, 과목명, 학점수, 평가방식),
// 총 수강학점, 평가방식별 수강학점, 수강과목수 등
void saveMyClass(int my[], int msize, struct st_class *c[], int csize) {

    int all = 0;
    int grade = 0;
    int pf = 0;

    FILE *file;
//---------------------------------------------------------
// my classes
    file = fopen("my_classes.txt", "wt");
    fprintf(file, "My Classes\n");

    for (int i = 0; i < msize; i++) {
        int index;
          for (int j = 0; j < csize; j++) {
            if (c[j]->code == my[i]) {
                index = j;
                break;
            }
        }
        // printf("! %d\n", index);
        fprintf(file, "%d. [%d] %s [credit %d - %s]\n", (i + 1), c[index]->code, c[index]->name, c[index]->unit,
               (c[index]->grading == 1) ? "A+~F" : "P/F");
        // printf("!! \n", index);

        
        
        if (c[index]->grading == 1) {
            grade += c[index]->unit;
        } else {
            pf += c[index]->unit;
        }
        all += c[index]->unit;

    }
    fprintf(file, "All : %d classes, %d credits (A+~F %d credits, P/F %d credits)\n", msize, all, grade, pf);
    fclose(file);

    printf("> All my classes ware saved to my_classes.txt.\n");
//---------------------------------------------------------
// all calsses

    saveAllClasses(c, csize);
    printf("> All of class list ware saved to classes.txt\n");

    return;
}