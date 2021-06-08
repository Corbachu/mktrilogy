//////////////////////////////////////////////////////////////////////////////////////////
// queue.c - Queue handling functions.
//
// Author: David Schwartz
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////

#include <ultra64.h>

#include "u64main.h"
#include "sys_defs.h"
//#include "typedefs.h"

#include "queue.h"
#include "sys.h"



//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// queue_add_head - adds to the front of the queue.
//
// If add is a null-pointer, queue_add_head simply returns a null-pointer. Interrupts
// are disabled through critical portions.
//////////////////////////////////////////////////////////////////////////////////////////
struct qlink *queue_add_head( struct queue *queue, struct qlink *add ) {
	CRITICAL_DEFS;

	if( add ) {
		ENTER_CRITICAL;

		add->plink = 0;
		if( add->nlink = queue->head ) {
			queue->head->plink = add;
		} else {
			queue->tail = add;
		}
		queue->head = add;

		LEAVE_CRITICAL;
	}

	return( add );
}


//////////////////////////////////////////////////////////////////////////////////////////
// queue_add_tail - adds to the end of the queue.
//
// If add is a null-pointer, queue_add_tail simply returns a null-pointer. Interrupts
// are disabled through critical portions.
//////////////////////////////////////////////////////////////////////////////////////////
struct qlink *queue_add_tail( struct queue *queue, struct qlink *add ) {
	CRITICAL_DEFS;

	if( add ) {
		ENTER_CRITICAL;

		add->nlink = 0;
		if( add->plink = queue->tail ) {
			queue->tail->nlink = add;
		} else {
			queue->head = add;
		}
		queue->tail = add;

		LEAVE_CRITICAL;
	}

	return( add );
}


//////////////////////////////////////////////////////////////////////////////////////////
// queue_remove - removes the specified entry from the queue.
//
// Returns a pointer to the removed entry, or 0 if the queue was empty. Interrupts are
// disabled through critical portions.
//////////////////////////////////////////////////////////////////////////////////////////
struct qlink *queue_remove( struct queue *queue, struct qlink *remove ) {
	CRITICAL_DEFS;

	ENTER_CRITICAL;

	if( queue->head ) {
		if( remove->plink ) {
			remove->plink->nlink = remove->nlink;
		} else {
			queue->head = remove->nlink;
		}
	
		if( remove->nlink ) {
			remove->nlink->plink = remove->plink;
		} else {
			queue->tail = remove->plink;
		}
	
		remove->nlink = 0;
		remove->plink = 0;
	} else {
		remove = 0;
	}

	LEAVE_CRITICAL;

	return( remove );
}


//////////////////////////////////////////////////////////////////////////////////////////
// queue_remove_head - removes from the head of the queue.
//
// Returns a pointer to the removed entry, or 0 if the queue was empty. Interrupts are
// disabled through critical portions.
//////////////////////////////////////////////////////////////////////////////////////////
struct qlink *queue_remove_head( struct queue *queue ) {
	CRITICAL_DEFS;
	struct qlink *qp;

	ENTER_CRITICAL;

	qp = queue_remove( queue, queue->head );

	LEAVE_CRITICAL;

	return( qp );
}


//////////////////////////////////////////////////////////////////////////////////////////
// queue_remove_tail - removes from the tail of the queue.
//
// Returns a pointer to the removed entry, or 0 if the queue was empty. Interrupts are
// disabled through critical portions.
//////////////////////////////////////////////////////////////////////////////////////////
struct qlink *queue_remove_tail( struct queue *queue ) {
	CRITICAL_DEFS;
	struct qlink *qp;

	ENTER_CRITICAL;

	qp = queue_remove( queue, queue->tail );

	LEAVE_CRITICAL;

	return( qp );
}


//////////////////////////////////////////////////////////////////////////////////////////
// queue_init - initializes a queue. Interrupts are disabled through critical portions.
//////////////////////////////////////////////////////////////////////////////////////////
void queue_init( struct queue *queue, void *first, int size, int num ) {
	CRITICAL_DEFS;
	int i;
	char *pqueue, *cqueue;

	ENTER_CRITICAL;

	if( !num ) {
		queue->head = 0;
		queue->tail = 0;
	} else {
		queue->head = (struct qlink *)first;
		cqueue = (char *)first;
		((struct qlink *)cqueue)->plink = 0;

		for( i=num; --i; ) {
			pqueue = cqueue;
			cqueue += size;

			((struct qlink *)cqueue)->plink = (struct qlink *)pqueue;
			((struct qlink *)pqueue)->nlink = (struct qlink *)cqueue;
		}

		((struct qlink *)cqueue)->nlink = 0;
		queue->tail = (struct qlink *)cqueue;
	}

	LEAVE_CRITICAL;
}
