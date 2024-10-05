#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cc(const char* line, const char* substring) {
    int count = 0;
    const char *tmp = line;
    while ((tmp = strstr(tmp, substring)) != NULL) {
        count++;
        tmp += strlen(substring);
    }
    return count;
}
int run(char *content){
	int a = cc(content, "malloc");
	int b = cc(content, "free");
	if (a > b){
		printf("MEMORY LEAK DETECTED\n");
	}	
	return 0;
}	
void readfile(const char* filename){
	FILE *file = fopen(filename, "r");
	if (file == NULL){
		printf("error: file not founded");
		exit(1);
	}
	fseek(file, 0, SEEK_END);
	long filesize = ftell(file);
	fseek(file, 0, SEEK_SET);

	char *content = malloc(filesize + 1);
	if (content == NULL){
		perror("FAILED ALLOCATE MEMORY");
		fclose(file);
		exit(1);
	}

	fread(content, 1, filesize, file);
	content[filesize] = '\0';
	run(content);
	free(content);
	fclose(file);
}

int main(int argc, char* argv[]){
	if (argc != 2){
		return 1;
	}
	readfile(argv[1]);
	return 0;
}
