#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int countVowels(char *str);

int main(void){
    FILE *file = fopen("data.txt", "r");
    int i;
    char str[100];
    char *p[20];

    for (i = 0 ; !feof (file); i++){
        if (!fgets(str,100,file)) break;
        str[strlen(str) - 1] = '\0';
        p[i] = (char *) malloc(sizeof(char) * strlen(str) + 1);
        strcpy(p[i],str);
    }

    printf("%d lines read.\n", i);
    for (int j = 0 ;j < i ; j++)
        printf("#%d - %s [%d]\n", j+1, p[j],countVowels(p[j]));

    return 0;
}
int countVowels(char *str){
    char v[10]  = {'a','e','i','o','u','A','E','I','O','U'};
    int count = 0;

    for (int i =0 ; i < strlen(str); i++)
        for (int j = 0 ; j < 10; j++)
            if (*(str + i) == v[j])
                count ++;
            
        
    
    return count;
}