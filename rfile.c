// C program to read a file and print its characters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

static int verbose_flag;

void readfile (FILE* ptr)
{
	char ch;

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

int main(int argc, char **argv) {
	// for parsing command line arguments
	static struct option long_options[] = {
		{ "verbose", 0, NULL, 'v' },
		{ "help", 0, NULL, 'h' },
		{ "file", 1, NULL, 'f' },
		{ 0, 0, 0, 0 }
	};

	int option, index;

	opterr = 0;

	while ((option = getopt_long(argc, argv, "vhf:", long_options, NULL)) != -1){
		switch (option) {
			case 'v':
				verbose_flag = 1;
				printf("verbose_flag is %d\n", verbose_flag);
				break;
			case 'h':
				printf("usage: %s [-h] [-f file.html]\n", argv[0]);
				break;
			case 'f':
				printf("file is '%s'\n", optarg);
				break;
			case '?':
				fprintf(stderr, "Bad syntax. See %s -h\n", argv[0]);
				return 1;
			default:
				abort();
		}
	}

	/* Print any remaining command line arguments (not options). */
	if (optind < argc){
		printf ("non-option ARGV-elements: ");
		while (optind < argc)
			printf ("%s ", argv[optind++]);
		putchar ('\n');
		return 1;
	}

	FILE* ptr;

	readfile (ptr);
	
	return 0;
}