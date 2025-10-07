#include <stdio.h>
#include <ctype.h>

char enteredChars[1000];
int chars_end = 0;
int keyword_end = 0;
char keyword[36];
char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void clearBuffer(void) {
        int waste;
        while ( (waste = getchar()) != '\n');
}

void encrypt(void) {
 /*  TODO: Multiple words */	
	signed int curChar;
	signed int kwInt;
	char cChar;
	char Char;

	printf("Enter plaintext: ");
	int i = 1;
	while (enteredChars[i-1] != '\n' && i < 1000) {
		enteredChars[i] = tolower(getchar());
		i++;
		}
	chars_end = i - 2;
	if (i == 2) {
		return;
	}
	
	printf("\nEnter keyword: ");
	i = 1;
	while (i < 36 && keyword[i-1] != '\n') {
		keyword[i] = tolower(getchar());
		i++;
	}
	if (i == 2) {
		return;
	}
	keyword_end = i - 2;
	int kwPos = 1;
	printf("Ciphertext: ");
	for (int x = 1; x <= chars_end; x++) {
		Char = enteredChars[x];
		if ( Char == ' ' ) {
			printf(" ");
			continue;
		}
		curChar = (int) Char - (int) 'a';
		kwInt = (int) keyword[kwPos] - (int) 'a';
		curChar += kwInt;
		if (curChar > 25) {
			curChar -= 26;
		}
		cChar = alphabet[curChar];
		printf("%c",cChar);
		kwPos++;
		if (kwPos - 1  == keyword_end) {
			kwPos = 1;
			}
		}
printf("\n");
}

void decrypt(void) {
/* TODO: caps normalisation */	
	int curChar;
	int kwInt;
	char cChar;
	char Char;

	printf("Enter ciphertext: ");
	int i = 1;
	while (enteredChars[i-1] != '\n' && i < 1000) {
		enteredChars[i] = tolower(getchar());
		i++;
		}
	chars_end = i - 2;
	if (i == 2) {
		return;
	}
	
	printf("\nEnter keyword: ");
	i = 1;
	while (i < 36 && keyword[i-1] != '\n') {
		keyword[i] = tolower(getchar());
		i++;
	}
	if (i == 2) {
		return;
	}
	keyword_end = i - 2;
	int kwPos = 1;
	printf("Plaintext: ");
	for (int x = 1; x <= chars_end; x++) {
		Char = enteredChars[x];
		if ( Char == ' ' ) {
			printf(" ");
			continue;
		}
		curChar = (int) Char - (int) 'a';
		kwInt = (int) keyword[kwPos] - (int) 'a';
		curChar -= kwInt;
		if (curChar < 0) {
			curChar += 26;
		}
		cChar = alphabet[curChar];
		printf("%c",cChar);
		kwPos++;
		if (kwPos - 1  == keyword_end) {
			kwPos = 1;
			}
		}
printf("\n");
}


void Break(void) {
}

int main(void) {
while (1==1) {
	printf("\nSelect an option:\n1) Encrypt\n2) Decrypt\n3) Break\n4) Exit\n");
	char selection = getchar();
	clearBuffer();
	switch (selection) {
		case '1':
		encrypt();
		break;
		case '2':
		decrypt();
		break;
		case '3':
		Break();
		case '4':
		return 0;
		}
}
}
