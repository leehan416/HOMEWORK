// 22100594 이한결 (HanGyeol Lee)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30] = {"Graphite", "Opal", "Bronze", "Silver", "Gold"}; // labels by level

struct st_channel {
    char name[100]; // Channel name
    int count;      // # of subscriptions
    int level;      // index of level (0~4)
};

int loadData(struct st_channel *c[]);

int findLevel(int num);

void printStatistics(struct st_channel *c[], int size);

void printChannels(struct st_channel *c[], int size);

void pickupRandomChannels(struct st_channel *c[], int size);

void searchChannel(struct st_channel *c[], int size);

int addChannel(struct st_channel *c[], int size);

void updateChannel(struct st_channel *c[], int size);

int deleteChannel(struct st_channel *c[], int size);

void makeReport(struct st_channel *c[], int size);

//----------------------------------------------------------
// 통계 데이터 얻어오는 함수 
// data -> call by adress 로 저장됨
void getStatisticsDatas(struct st_channel *c[], int size, int num[], int maxIndex[], int sumOfPeople[]);
//----------------------------------------------------------


int main(void) {
    int no;    // amount of channels
    struct st_channel *clist[SIZE]; // channel list
    int menu; // menu number

    srand(time(0));
    no = loadData(clist);

    while (1) {
        // Print menu
        printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
        scanf("%d", &menu);

        if (menu == 1) {
            printChannels(clist, no); // Print all list of channels
        } else if (menu == 2) {
            printStatistics(clist, no);    // Print statistics of each level
        } else if (menu == 3) {
            pickupRandomChannels(clist, no); // Pick up random channels
        } else if (menu == 4) {
            searchChannel(clist, no);    // Search a channel
        } else if (menu == 5) {
            no = addChannel(clist, no); // Add a channel
        } else if (menu == 6) {
            updateChannel(clist, no); // Modify a channel
        } else if (menu == 7) {
            no = deleteChannel(clist, no); // Delete a channel
        } else if (menu == 8) {
            makeReport(clist, no);    // Make a Report
        } else {
            break;
        }
    }
    return 0;
}

// 파일에서 데이터를 읽어오고, 이를 구조체 배열에 저장하는 함수
int loadData(struct st_channel *c[]) {
    int no = 0;
    FILE *file;

    file = fopen("channels.txt", "r");
    while (!feof(file)) {
        struct st_channel *t = (struct st_channel *) malloc(sizeof(struct st_channel));
        int r = fscanf(file, "%s %d", t->name, &(t->count));
        if (r < 2) break;
        t->level = findLevel(t->count);
        c[no] = t;
        no++;
    }
    fclose(file);
    printf("> %d channels are loaded.\n", no);
    return no;
}

// 체널의 데이터에 맞게 레벨을 설정하여 주는 함수
int findLevel(int num) {
    int range[5] = {1000, 10000, 100000, 1000000, 10000000}; // range for level
    for (int j = 0; j < 5; j++)
        if (num < range[j])
            return j;
    return 0;
}

// 체널 리스트를 출력하는 함수
void printChannels(struct st_channel *c[], int size) {
    printf("> List of Channels\n");
    for (int i = 0; i < size; i++) {
        printf("[%2d] %-20s %10d peoples [%s] \n", i + 1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
    }
}

// 새로운 체널을 추가하는 함수
int addChannel(struct st_channel *c[], int size) {
    struct st_channel *temp;
    printf("> Add a new Channel\n");
    temp = (struct st_channel *) malloc(sizeof(struct st_channel));
    
    //----------------------------------------------------------
    //입력
    printf("> Enter a name of channel > ");
    scanf("%s", temp->name);
    printf("> Enter an amount of peoples > ");
    scanf("%d", &(temp->count));
    temp->level = findLevel(temp->count);
    c[size] = temp;
    //----------------------------------------------------------

    printf("> New channel is added.\n");
    printf("[%2d] %-20s %10d peoples [%s] \n", size + 1, c[size]->name, c[size]->count, LNAME[c[size]->level]);
    return size + 1;
}

// 체널의 통계를 출력해주는 함수
void printStatistics(struct st_channel *c[], int size) {
    printf("> Statistics of Channels\n");
    //----------------------------------------------------------
    // 최대값 찾기
    int num[5] = {0}; // 갯수 저장
    int maxIndex[5] = {0}; // 최대값을 가지는 인덱스
    int sumOfPeople[5] = {0}; // 사람들의 함 (캣수로 나눠야함)
    getStatisticsDatas(c, size, num, maxIndex, sumOfPeople);
    // 함수 구현으로 아래 코드 주석처리
    // for (int i = 0; i < size; i++) { // search
    //     num[c[i]->level]++; // 갯수 추가
    //     sumOfPeople[c[i]->level] += c[i]->count; // 사람들 더하기

    //     if (c[i]->count > c[maxIndex[c[i]->level]]->count) { // 최댓값 찾기
    //         maxIndex[c[i]->level] = i;
    //     }
    // }

    //----------------------------------------------------------
    //출력
    for (int i = 0; i < 5; i++) {
        printf("%s : %d channels, Average %.1f peoples, Top channel: %s (%d peoples)\n",
               LNAME[i], num[i], (float) ((float) sumOfPeople[i] / (float) num[i]), c[maxIndex[i]]->name,
               c[maxIndex[i]]->count);
    }
}

// 랜덤 체널을 골라주는 함수
void pickupRandomChannels(struct st_channel *c[], int size) {
    printf("> Pick up Channels\n");
    printf("> How much channels you want to pick up? > ");

    //----------------------------------------------------------
    int num;
    int *arr;

    // 입력 가능한 수인지 검사
    while (1) {
        scanf("%d", &num);
        if (num > size) printf("다시 입력하세요.");
        else break;
    }
    // 숫자에 맞추어 배열 생성
    arr = (int *) malloc(sizeof(int) * num);

    printf("Random Channels\n");
    for (int i = 0; i < num; i++) {
        int index = 0;
        int value = 0;
        // 동일한 수 나오지 않을떄까지 반복, 랜덤 수 뽑기
        while (1) {
            value = rand() % (size - 1) + 0;
            for (int j = 0; j <= i; j++) // check
                if (arr[j] == value) index = -1;

            if (index == -1) continue;
            index = value;
            break;
        }

        //출력
        printf("[%d] %s (%slevel, %dpeoples)\n",
               index + 1, c[index]->name, LNAME[c[index]->level], c[index]->count);
    }
    free(arr);
    //----------------------------------------------------------
}

// 데이터를 받아 체널을 검색하는 함수
void searchChannel(struct st_channel *c[], int size) {
    printf("> Search Channels\n");
    printf("> Choose one (1:by peoples 2:by names) > ");
    //----------------------------------------------------------
    int value;
    int min, max;

    char arr[100];

    scanf("%d", &value);
    getchar();


    if (value == 1) { // peoples
        printf("> Enter the range of peoples (from ~ to) > ");
        scanf("%d %d", &min, &max);
    } else { // name
        printf("> Enter a names > ");

        fgets(arr, sizeof(arr), stdin);
        arr[strlen(arr) - 1] = '\0';
    }

    for (int i = 0; i < size; i++) { //search
        // 조건에 맞춰서 검사하고 맞으면 출력
        if ((value == 1) ? ((min <= c[i]->count) && (c[i]->count <= max)) : (strstr(c[i]->name, arr) != NULL)) {
            printf("[%2d] %-20s %10d peoples [%s] \n", i + 1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
        }
    }
    //----------------------------------------------------------
}

// 체널을 수정하는 함수
void updateChannel(struct st_channel *c[], int size) {
    printf("> Modify a new Channel\n");
    // printf("> Enter a number of channel > ");
    //----------------------------------------------------------
    int num;
    char arr[100];
    struct st_channel *temp = (struct st_channel *) malloc(sizeof(struct st_channel));

    printf("> Enter a number of channel > ");
    while (1) {
        scanf("%d", &num);
        getchar();
        if (size >= num) break;
        printf("!");
    }

    printf("> Channel Info.\n");
    printf("[%2d] %-20s %10d peoples [%s] \n", num, c[num - 1]->name, c[num - 1]->count, LNAME[c[num - 1]->level]);

    //데이터 입력
    printf("> Enter a new name of channel > ");

    fgets(temp->name, sizeof(arr), stdin);

    temp->name[strlen(temp->name) - 1] = '\0'; // remove '\n'

    printf("> Enter a new amount of peoples > ");
    scanf("%d", &temp->count);

    temp->level = findLevel(temp->count);
    
    //update
    *c[num - 1] = *temp;

    free(temp);

    printf("> Channel info. is modified.\n");

    //----------------------------------------------------------
}

// 체널을 삭제하는 함수
int deleteChannel(struct st_channel *c[], int size) {
    int yesno;
    printf("> Delete a new Channel\n");
    //----------------------------------------------------------

    int num;
    printf("> Enter a number of channel >");
    scanf("%d", &num);
    printf("> Channel Info.\n");
    printf("[%2d] %-20s %10d peoples [%s] \n", num, c[num - 1]->name, c[num - 1]->count, LNAME[c[num - 1]->level]);

    printf("> Do you want to delete the channel? (1:Yes 0:No) > ");
    scanf("%d", &yesno);

    if (yesno)
        printf("> Channel is deleted.");
    else
        printf("> Channel is not deleted.");

    // index 하나씩 끌어오기
    for (int i = num; i <= size && yesno; i++) {
        c[i - 1] = c[i];
    }
    // 삭제되면 줄여서 return
    return (yesno) ? --size : size;
    //----------------------------------------------------------

    // return size;
}

// 파일로 결과물을 작성하는 함수
void makeReport(struct st_channel *c[], int size) {
    //----------------------------------------------------------
    
    FILE *file;
    file = fopen("channels.txt", "wt");

    for (int i = 0; i < size; i++)
        fprintf(file, "%s %d\n", c[i]->name, c[i]->count);

    fclose(file);
    //----------------------------------------------------------

    file = fopen("report.txt", "wt");
    printf("> All information of channels are saved into channels.txt.\n");

    for (int i = 0; i < size; i++) {
        fprintf(file, "[%2d] %-20s %10d peoples [%s] \n", i + 1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
    }

    int num[5] = {0}; // 갯수 저장
    int maxIndex[5] = {0}; // 최대값을 가지는 인덱스
    int sumOfPeople[5] = {0}; // 사람들의 함 (캣수로 나눠야함)
    getStatisticsDatas(c, size, num, maxIndex, sumOfPeople); // 데이터 받아오기
    //----------------------------------------------------------
    //출력
    fprintf(file, "\n");
    for (int i = 0; i < 5; i++)
        fprintf(file, "%s : %d channels, Average %.1f peoples, Top channel: %s (%d peoples)\n",
                LNAME[i], num[i], (float) ((float) sumOfPeople[i] / (float) num[i]), c[maxIndex[i]]->name,
                c[maxIndex[i]]->count);

    fclose(file);
    printf("> Channel Statistics are saved into report.txt.\n");
}

//----------------------------------------------------------
// 통계결과를 계산, 저장하는 함수
// 로직이 반복되어 함수를 분리 구현
void getStatisticsDatas(struct st_channel *c[], int size, int num[], int maxIndex[], int sumOfPeople[]) {
    for (int i = 0; i < size; i++) { // search
        num[c[i]->level]++; // 갯수 추가
        sumOfPeople[c[i]->level] += c[i]->count; // 사람들 더하기

        if (c[i]->count > c[maxIndex[c[i]->level]]->count) { // 최댓값 찾기
            maxIndex[c[i]->level] = i;
        }
    }

}
//----------------------------------------------------------
