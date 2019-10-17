/*
 * mainmenu.cpp - This file contains the main menu functionality
 * 
 * Copyright 2019 Caleb Hoeksema, Greg Huras
 *
 */


#include <stdio.h>
#include "menu.h"

int main(void) {

	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("CMS Main Menu\n**********************************************************\n");

		printf("Sound (S)\nPhonebook (P)\nSettings (X)\nDebug menu (D)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
			case ('s'):
			case ('S'):
				while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
				sound();
				// printf("Sound Menu\n**********************************************************\n");
				break;
			case('p'):
			case('P'):
				printf("Phonebook\n**********************************************************\n");
				break;
			case('X'):
			case('x'):
				printf("Settings Menu\n**********************************************************\n");
				break;
			case('D'):
			case('d'):
				printf("Debug Menu\n**********************************************************\n");
				break;
			case('\n'):
				error = 1;
				break;
			default:
				printf("Invalid input\n\n");
				error = 1;
				while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
				break;
		}
		
	}

	return(0);
}