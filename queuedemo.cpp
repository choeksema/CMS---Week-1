/*
 * main.cpp: client for queues functions in Queues.cpp and Queues.h
 *
 * Copyright	October 8, 2019 Caleb Hoeksema
 *				Thursday, October 3: Set up code outline
 *				Monday, October 7: flesh out code
 */

 // Header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include "Queues.h"
#include "message.h"


int
main() {
	
	// Variables
	int userIn;							// represents N in the handout (user input)
	int i = 0;							// loop counter
	int fileCount;						// number of quotes in the file
	long int* fileIndices;				// array holding quote offsets
	int* quoteLen;						// array holding quote lengths
	int quote;							// error code for GetMessageFromFile
	link tempLink;						// creates a pointer to a node

	printf("Enter a number of quotes.");
	scanf_s("%d",&userIn);

	// Initialise the queue
	InitQueue();

	// File setup
	fileCount = fnumQuotes();								// Count quotes 
	fileIndices = fquoteIndices(fileCount);					// Stores quote locations
	quoteLen = fquoteLength(fileCount, fileIndices);		// Finds the quote lengths up to 140	
	srand(time(NULL));										// Seed the random number generator

	// Add "N" messages to the queue
	for (i = 0; i < userIn; i++) {

		//Create a new node and clear the message
		tempLink = (link)malloc(sizeof(Node));

		quote = GetMessageFromFile(tempLink->Data.message, 140, frandNum(1, fileCount), fileCount, fileIndices, quoteLen);

		//Enqueue the message
		AddToQueue(tempLink);
	}

	for (i = 0; i < userIn; i++) {
		if (IsQueueEmpty()) {
			printf("\n\nEnd of messages******************************\n");
			break;
		}
		else {
			tempLink = DeQueue();							// save dequeued node to type "link"
			printf("\n\nMessage %d is:\n%s", i + 1, tempLink->Data.message);		// print message
			free(tempLink);									// free the space
		}
	}

	free(quoteLen);
	system("pause");

	return(0);
}