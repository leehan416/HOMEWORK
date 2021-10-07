#include <stdio.h>
#include <string.h>

int main(void){
	int alphacount1[26]={0}, alphacount2[26]={0};
	char input[256];

    // 첫번째 문자열 입력
	printf("String 1 > ");
	fgets(input, sizeof(input),stdin);
	for (int i = 0 ; i < strlen(input) ; i++)  // 배열에 저장
		if (97<input[i] && input[i] <= 123)
			alphacount1[input[i] - 96]++;
	
    // 두번째 문자열 입력
	printf("String 2 > ");
	fgets(input, sizeof(input),stdin);
	for (int i = 0 ; i < strlen(input) ; i++) { // 배열에 저장
		if ( 97<input[i] && input[i] <= 123){
			alphacount2[input[i] - 96]++;
				}
	}

    // 결과 출력
	for (int i = 0 ;i < 26 ; i++){
		if(alphacount1[i] != alphacount2[i]){
			printf("Not anagram!");
			return 0;
        }
	}
	
	printf("Anagram!");




	return 0;
}