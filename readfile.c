// C program to read a file and print its characters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* ptr;
	char ch;
	ptr = fopen("test.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	printf("content of this file is \n");

	while (!feof(ptr)) {
		ch = fgetc(ptr);
		printf("%c", ch);
	}
	fclose(ptr);
	return 0;
}
