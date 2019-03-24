#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	DuLinkedList head;
	Status status = ERROR;
	if ((head = (DuLNode*)malloc(sizeof(DuLNode)))!=NULL) {
		*L = head;
		head->prior = NULL;
		head->next = NULL;
		status = SUCCESS;
	}
	return status;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode *pre;
	while(*L != NULL){
		pre = (*L)->next;
		pre->prior = NULL;
		free(*L);
		*L = pre;
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	Status status = ERROR;
	if(p != NULL){
		p->prior->next = q;
		q->prior = p->prior;
		q->next = p;
		p->prior = q;
		status = SUCCESS;
	}
	return status;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	Status status = ERROR;
	if(p != NULL){
		p->next->prior = q;
		q->next = p->next;
		q->prior = q;
		p->next = q;
		status = SUCCESS;
	}
	return status;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLNode *pre;
	Status status = ERROR;
	if(p != NULL && p->next != NULL){
		*e = p->next->data;
		pre = p->next;
		pre->next->prior = p;
		pre->next = pre->next;
		free(pre);
		status = SUCCESS;
	}
	return status;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode *pre;
	pre = L;
	while(pre != NULL){
		(*visit)(pre->data);
		pre = pre->next;
	}
}

