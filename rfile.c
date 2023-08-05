// C program to read a file and print its characters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readfile (FILE* ptr, char ch)
{
	ptr = fopen("test.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
		return;
	}

	printf("content of this file is: \n");

	while (!feof(ptr)) {
		ch = fgetc(ptr);
		printf("%c", ch);
	}
	fclose(ptr);
}

int main()
{
	FILE* ptr;
	char ch;

	readfile (ptr, ch);
	
	return 0;
}