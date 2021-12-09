#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char GRADE[3][10] = {"Deluxe", "Luxury", "Suite"}; // 객실등급 명칭

struct st_card {        // 객실 관리 카드 레코드
    int no;        // 객실번호 (3자리 숫자)
    int grade; // 객실 등급 (1:deluxe, 2:luxury, 3:suite)
    int capa;        // 수용최대인원 (2~10명)
    char name[20];    // 예약자 성명
    int person;        // 예약 인원
};

int loadCards(struct st_card *p[]);        // 객실정보 읽기
void listCards(struct st_card *p[], int n);    // 객실 목록 출력
void makeReserve(struct st_card *p[], int n);        // 객실 예약
void cancelReserve(struct st_card *p[], int n);    // 예약 취소
void findCards(struct st_card *p[], int n);    // 객실 검색
// void saveReport(struct st_card *p[], int n);  
void saveReport(struct st_card *p[], int n); //{  // 보고서 저장
void findRoom(struct st_card *p[], int n);    // 빈 객실 찾기
int addCards(struct st_card *p[], int n);    // 객실 추가

int main() {
    struct st_card *cards[50];    // 최대 50개의 객실을 관리할 수 있는 구조체 포인터 배열
    int count;    // 현재 등록된 카드 수
    int menu;    // 메뉴번호
    count = loadCards(cards);    // 시작 전에 파일로부터 객실 리스트를 모두 읽어온다.
    while (1) {
        // 메뉴 출력
        printf("\n[1]객실목록 [2]예약 [3]예약취소 [4]검색 [5]저장 [6]빈객실찾기 [7]객실추가 [0]종료 >> ");
        scanf("%d", &menu);    // 메뉴를 읽음

        if (menu == 1) {
            listCards(cards, count);    // 객실 목록 출력
        } else if (menu == 2) {
            makeReserve(cards, count);    // 예약하기
        } else if (menu == 3) {
            cancelReserve(cards, count); // 예약 취소
        } else if (menu == 4) {
            findCards(cards, count);    // 검색
        } else if (menu == 5) {
            saveReport(cards, count);    // 보고서 저장
        } else if (menu == 6) {
            findRoom(cards, count);    // 빈 객실 찾기
        } else if (menu == 7) {
            count = addCards(cards, count);    // 객실 추가
        } else {
            break;
        }
    }
}

int loadCards(struct st_card *p[]) {
    FILE *file;
    int n = 0;
    file = fopen("rooms.txt", "r");
    while (!feof(file)) {
        p[n] = (struct st_card *) malloc(sizeof(struct st_card));
        int result = fscanf(file, "%d %d %d", &(p[n]->no), &(p[n]->grade), &(p[n]->capa));
        if (result < 1) break;
        n++;
    }
    fclose(file);
    printf("%d개의 객실 정보를 읽었습니다.\n", n);
    return n;
}

void listCards(struct st_card *p[], int n) {
    int i;
    printf("\n전체 객실 목록입니다.\n");
    printf("객실번호 / 등급 / 최대인원 / 예약상황\n");

    for (i = 0; i < n; i++) {
        printf("%d호 / %s / %d명 / ", p[i]->no, GRADE[p[i]->grade - 1], p[i]->capa);
        if (p[i]->person > 0)
            printf("예약 : %s %d명\n", p[i]->name, p[i]->person);
        else
            printf("예약없음\n");
    }
}

// 15-5
void makeReserve(struct st_card *p[], int n) {
    char name[20];
    struct st_card *rp; // 예약할 카드레코드 구조체의 포인터값
    int i, roomno, newperson;


    printf("예약하실 고객 이름은? >> ");
    scanf("%s", name);
    printf("예약 인원수를 입력하시오. >> ");
    scanf("%d", &newperson);


    while (1) {
        printf("예약하실 객실 번호는? >> ");
        scanf("%d", &roomno);

        int value = 0;
        int person = 0;
        int pre = 0;
        // int person;
        for (int i = 0; i < n; i++) {
            if (p[i]->no == roomno) {
                value++;
                if (newperson > p[i]->capa)
                    person++;

                if (p[i]->person > 0)
                    pre++;
                break;
            }
        }
        if (pre) {
            printf("예약불가(예약된 객실)\n");
            continue;
        }


        if (person) {
            printf("예약불가(인원 초과)\n");
            continue;
        }
        if (!value) {
            printf("예약불가(객실번호 오류)\n");
            continue;
        }


        break;
    }

    for (i = 0; i < n; i++) {
        if (p[i]->no == roomno) {
            rp = p[i];
            break;
        }
    }
    rp->person = newperson;
    strcpy(rp->name, name);
    printf("예약완료!\n");
}

// 15-6
void cancelReserve(struct st_card *p[], int n) {
    int roomno;
    int value = 0;
    int index;
    int no = 0;
    int input;
    printf("예약 취소하실 객실 번호는? >> ");
    scanf("%d", &roomno);

    for (int i = 0; i < n; i++) {
        if (p[i]->no == roomno) {
            value++;
            // printf("%d", p[i]->person);
            if (0 == p[i]->person)
                no = 1;
            index = i;
        }

    }
    if (!value) {
        printf("방이 존재하지 않습니다.\n");
        return;
    }
    if (no) {
        printf("예약된 객실이 아닙니다.\n");
        return;
    }

    printf("객실번호 / 등급 / 예약자 / 예약인원\n");


    printf("%d호 / %s / %s / %d명\n", p[index]->no, GRADE[p[index]->grade - 1], p[index]->name, p[index]->person);

    printf("위 예약을 취소할까요? (YES 1, NO 0) >> ");
    scanf("%d", &input);
    if (input == 1) {
        p[index]->person = 0;
        printf("취소했습니다.\n");
    }

}

// 15-7
void findCards(struct st_card *p[], int n) {
    int i, count = 0;
    int index[40];
    char name[20];
    while (1) {
        printf("검색하려는 고객 이름을 2글자 이상 입력하세요. >> ");
        scanf("%s", name);
        if (strlen(name) > 1) break;
    }
    for (i = 0; i < n; i++)
        if (p[i]->person > 0)
            for (int j = 0; j < strlen(p[i]->name) - strlen(name) + 1; j++)
                if (strncmp(p[i]->name + j, name, strlen(name)) == 0)
                    index[count++] = i;

    printf("객실번호 / 등급 / 예약자 / 예약인원 / 최대인원\n");

    if (count > 0)
        for (i = 0; i < count; i++)
            printf("%d호 / %6s / %s / %d명 / %d명\n", p[index[i]]->no, GRADE[p[index[i]]->grade - 1], p[index[i]]->name,
                   p[index[i]]->person, p[index[i]]->capa);


    printf("%d명 검색됨\n", count);


}

// 15-8
void saveReport(struct st_card *p[], int n) {
    FILE *fp = fopen("rooms_report.txt", "wt");
    int rooms[3] = {0}; //= {3, 8, 3};
    int count[3] = {0};
    int countPer[3] = {0};
    int max[3] = {0}; // {6, 26, 22};
    int perCount = 0;
    for (int i = 0; i < 14; i++) {
        rooms[p[i]->grade - 1]++;
        if (p[i]->person > 0) {
            count[p[i]->grade - 1]++;
            countPer[p[i]->grade - 1] += p[i]->person;
            perCount += p[i]->person;
        } else {
            max[p[i]->grade - 1] += p[i]->capa;
        }
    }


    fprintf(fp, "객실 현황 보고서\n");
    for (int i = 0; i < 3; i++) {
        fprintf(fp, "객실등급 : %s\n", GRADE[i]);
        fprintf(fp, "1. 객실 수 : 총 %d실 중 %d실 예약 중\n", rooms[i], count[i]);
        fprintf(fp, "2. 예약 고객 : 총 %d명\n", countPer[i]);
        fprintf(fp, "3. 남은 최대수용 고객 : 총 %d명\n", max[i] - countPer[i]);
    }


    fprintf(fp, "\n객실 예약 목록\n객실번호 / 등급 / 최대인원 / 예약상황\n");

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d호 / %s / %d명 / ", p[i]->no, GRADE[p[i]->grade - 1], p[i]->capa);
        if (p[i]->person > 0)
            fprintf(fp, "예약 : %s %d명\n", p[i]->name, p[i]->person);
        else
            fprintf(fp, "예약없음\n");
    }
    fprintf(fp, "예약 인원 합계 : %d명", perCount);


    printf("저장되었습니다.\n");

    fclose(fp);
}

//15-9
void findRoom(struct st_card *p[], int n) {
    int person;
    int grade;
    int count = 0;
    printf("투숙 인원수는? >> ");
    scanf("%d", &person);
    printf("원하시는 객실 등급은? (Deluxe 1, Luxury 2. Suite 3, 무관 0) >> ");
    scanf("%d", &grade);
    printf("객실번호 / 등급 / 최대인원\n");

    for (int i = 0; i < 14; i++) {
        if (p[i]->person == 0 && p[i]->capa >= person) {
            if (grade == 0 || grade == p[i]->grade) {
                printf("%d호 / %s / %d명\n", p[i]->no, GRADE[p[i]->grade - 1], p[i]->capa);
                count++;
            }
        }
    }
    printf("총 %d개의 객실이 예약 가능합니다.\n", count);

}

// 15-10
int addCards(struct st_card *p[], int n) {

    return n + 1;
}
