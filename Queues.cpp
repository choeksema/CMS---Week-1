/* Queues.cpp - Implementation of Queue functions
 *
 * Copyright 2019 Caleb Hoeksema
 */

#include "Queues.h"
#include <stdlib.h>


static link pHead, pTail;		// private pointers to head and tail of queue

void InitQueue(void) {			// Iniialise the queue
	pHead = pTail = NULL;
}

int IsQueueEmpty(void) {		// check if queue is empty (you can't pop off of an empty queue)
	return(pHead == NULL);
}

void AddToQueue(link pn) {		// Enqueue new node provided and instantiated in main
	if (IsQueueEmpty()) {
		pHead = pTail = pn;		// pHead only stored for the first node added
	}
	else {						// push on the tail
		pTail->pNext = pn;		// old Tail points to the new node
		pTail = pn;				// make the Tail point to the end of the list (pn)
	}
	pTail->pNext = NULL;		// set the pointer from the last node to NULL
}

link DeQueue(void) {
	link pTemp;					// Holds current Head
	if (IsQueueEmpty()) {
		return NULL;
	}
	else {
		pTemp = pHead;			// store the current head
		pHead = pHead->pNext;	// the next node becomes the head
		return (pTemp);			// returns the original head
	}
}