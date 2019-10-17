/* Queues.h - Interface for Queue functionality
 *
 * Copyright 2019 Caleb Hoeksema
 */

#pragma once					// so it is only included once - could use ifndef instead
const int iLength = 140;		// Length of the array for storing the message

// Rename the structures
typedef struct node Node;
typedef struct item Item;
typedef Node* link;

struct item {
	char message[iLength];		// Message text
	short int sid;				// Sender ID
	short int rid;				// Receiver ID
	char priority;				// Priority of message
	short int seqNum;			// Message number (used in communications)
	char later[25];				// Might not use...
};

struct node {					
	link pNext;					// pointer to this type of structure (next node in linked list)
	Item Data;					// structure holding information
};

// Function Prototypes
void InitQueue(void);
int IsQueueEmpty(void);
void AddToQueue(link);
link DeQueue(void);




