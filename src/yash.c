//Project 1: Yash Shell - Yet Another Sh

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include "childchild.h"
#include "child.h"
#include "jobCtrl.h"

#define Read 0
#define Write 1
#define MaxCommandLength 1000
#define MaxWordLength 12

int fg;

// //exec inputted command
// void execCommand(char* arr[], int *fileRedir){
// 	int count = 0;
// 	int frIndex = 0;
// 	int pipeIndex = 0;

// 	if(strcmp(arr[count], "fg") == 0)
// 		foreground();
// 	else if(strcmp(arr[count], "bg") == 0)
// 		background();
// 	else if(strcmp(arr[count], "jobs") == 0){
// 		jobsP(0);
// 	}else{
// 		while(arr[count] != NULL){
// 			if(strcmp(arr[count], ">") == 0 || strcmp(arr[count], ">>") == 0 || strcmp(arr[count], "<") == 0 || strcmp(arr[count], "2>") == 0){
// 				fileRedir[frIndex] = count;
// 				frIndex++;
// 			}
// 			if(strcmp(arr[count], "|") == 0)
// 				pipeIndex = count;
// 			count++;
// 		}
// 		if(pipeIndex > 0)
// 			pipeFunc(arr, pipeIndex, fileRedir, fg);
// 		else
// 			nonpipeFunc(arr, fileRedir, fg);
// 	}
// }

char** parseCommand(char *command, char *arr[]) {
	int count = 0;
	// char *temp = (char*)malloc(2000 * sizeof(char));
	// strcpy(temp, command); //for printing process in jobCtrl()

	arr[count] = strtok(command, " ");
	while (arr[count] != NULL) {
		count++;
		arr[count] = strtok(NULL, " ");
		printf("%s\n", arr[count]);
	}

	// if(strcmp(arr[count - 1], "&") == 0){
	// 	//background process
	// 	fg = 0;
	// 	arr[count - 1] = NULL;
	// }else{
	// 	fg = 1;
	// 	arr[count] = NULL;
	// }

	// if(strcmp(arr[0], "jobs") != 0){
	// 	jobCtrl(temp, fg, 0);
	// }

	return arr;
}

// returns # of words on command
int commandSize(char *command) {
	char *token;
	int count = 0;

	token = strtok(command, " ");
	while (token != NULL) {
		token = strtok(NULL, " ");
		count++;
	}
	return count;
}

int main(int argc, char *argv[]) {
	char* command = (char*)malloc(MaxCommandLength * sizeof(char));
	int command_Size;

	while (1) {
		//check if done with pre command
		// signal(SIGTTOU, SIG_IGN);
		// tcsetpgrp(STDOUT_FILENO, getpgrp());

		printf("\n*********ENTERING SHELL*********\n");
		printf("# ");
		fgets(command, MaxCommandLength, stdin);
		if (command[0] == '\n') { // exit on enter
			printf("\n*********EXISTING SHELL*********\n");
			exit(0);
		}

		command[strlen(command) - 1] = 0; //truncate '\n'
		command_Size = commandSize(command);
		command_Size++;

		char** arr = (char**)malloc(sizeof(char*) * command_Size);
		for (int i = 0; i < command_Size; i++) {
			arr[i] = malloc(sizeof(char) * MaxWordLength);
		}
		parseCommand(command, arr);

		// printf("%s\n", arr[0]);
		// printf("%s\n", arr[1]);

		// for (int i = 0; i < command_Size; i++) {
		// 	printf("%s\n", arr[i]);
		// }

		// int *fileRedir = (int*)malloc(3 * sizeof(int)); //array of 3 elements*/
		// execCommand(arr, fileRedir);

		// free(command);
		// //free(fileRedir);
		// for (int i = 0; i < command_Size; i++)
		// 	free(arr[i]);
		// free(arr);
	}
	return 0;
}
