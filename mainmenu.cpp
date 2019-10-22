/*
 * mainmenu.cpp - This file contains the main menu functionality
 * 
 * Copyright 2019 Caleb Hoeksema, Greg Huras
 *
 */


#include <stdio.h>
#include "menu.h"
#include "message.h"
#include "Queues.h"
#include "sound.h"

int main(void) {

	Menu();
}

int Menu(void) {
	char c;

	char userIn[2] = { '\0' };
	int error = 1;

	while (error == 1) {
		printf("CMS Main Menu\n**********************************************************\n");

		printf("Sound (1)\nPhonebook (2)\nSettings (3)\nDebug menu (4)\n");
		scanf_s("%c", userIn, 2);

		error = 0;

		switch (userIn[0]) {
		case ('1'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
			sound();
			//printf("Sound Menu\n**********************************************************\n");
			break;
		case('2'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			//printf("Phonebook\n**********************************************************\n");
			phoneBook();
			break;
		case('3'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			//printf("Settings Menu\n**********************************************************\n");
			settings();
			break;
		case('4'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			//printf("Debug Menu\n**********************************************************\n");
			debug();
			break;
		case('\n'):
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			error = 1;
			break;
		default:
			printf("Invalid input\n\n");
			error = 1;
			while ((c = getchar()) != '\n' && (c != EOF)) {}				//flushes input 
			break;
		}

	}
	return 0;
}
