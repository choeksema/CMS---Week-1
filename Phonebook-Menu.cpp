/*
 * soundmenu.cpp - This file contains the sound menu functionality
 *
 * Copyright 2019 Caleb Hoeksema, Greg Huras
 *
 */

#include <stdio.h>
#include "menu.h"

int phoneBook(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("Sound Menu\n**********************************************************\n");

		printf("Record and play back (1)\nSettings (2)\nDiagnostic menu(3)\nReturn to main menu (4)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Calls function...\n**********************************************************\n");
			break;
			while ((c = getchar()) != '\n' && (c != EOF)) {}
		case ('2'):
			printf("Settings Menu\n**********************************************************\n");
			break;
		case ('3'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Diagnostic Menu\n**********************************************************\n");
			break;
		case('4'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			printf("Main Menu\n**********************************************************\n");
			Menu();
			break;
		case('\n'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
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