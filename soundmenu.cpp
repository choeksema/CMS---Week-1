/*
 * soundmenu.cpp - This file contains the sound menu functionality
 *
 * Copyright 2019 Caleb Hoeksema, Greg Huras
 *
 */

#include <stdio.h>

int sound(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("Sound Menu\n**********************************************************\n");

		printf("Record and play back (R)\nSettings (X)\nDiagnostic menu (D)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('r'):
		case ('R'):
			printf("Calls function...\n**********************************************************\n");
			break;
		case('X'):
		case('x'):
			printf("Settings Menu\n**********************************************************\n");
			break;
		case('D'):
		case('d'):
			printf("Diagnostic Menu\n**********************************************************\n");
			break;
		case('\n'):
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			break;
		}
		while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
	}

	return(0);
}