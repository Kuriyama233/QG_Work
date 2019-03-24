#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	LinkedList head;
	Status status = ERROR;
	if ((head = (LinkedList)malloc(sizeof(LinkedList)))!=NULL) {
		*L = head;				/*将头指针指向head*/
		head->data = NULL;
		head->next = NULL;
		status = SUCCESS;
	}
	return status;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList pre;
	while(*L) {
		pre = (*L)->next;		/*pre指向第二个节点*/
		free(*L);				/*free掉第一个节点*/
		*L = pre;				/* *L指向pre指向的节点*/
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	LNode *pre;
	Status status = ERROR;
	if(p) {
		pre = p->next;		/*pre记录p->next的位置*/
		p->next = q;		/*让p与pre分别与q联系*/
		q->next = pre;
		status = SUCCESS;
	}
	return status;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LNode *pre;
	Status status = ERROR;
	if (p && p->next) {
		pre = p->next;			/*pre指向p后面一个结点，将值传入e*/
		*e = pre->data;
		p->next = pre->next;
		free(pre);				/*free掉pre*/
		status = SUCCESS;
	}
	return status;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode *pre = L;
	while(pre){
		(*visit)(pre->data);		/*访问pre*/
		pre = pre->next;			/*到下一个结点*/
	}
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	static LNode *target;
	Status status = ERROR;
	if (L != NULL){
		target = L;				/*从L开始*/
		while(target->data != e && target->next != NULL){	/*找到e或者到最后一个结点时退出*/
			target = target->next;			/*到下一个结点*/
		}
		if(target->data == e)			/*判断最后一个结点是不是e*/
			status = SUCCESS;
	}
	return status;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LNode *pre, *Next, *cur;
	Status status = ERROR;
	if (*L != NULL && (*L)->next != NULL){	/*保证将判断的链表结点有两个或两个以上*/
		pre = *L;
		cur = pre->next;			/*pre在cur前面*/
		pre->next = NULL;
		while(cur){
			Next = cur->next;		/*next在cur后面*/
			cur->next = pre;		/*将cur指向前一个结点*/
			pre = cur;				/*三个结点往后指一位*/
			cur = Next;
		}
		*L = pre;					/*L指向新的头结点*/
		status = SUCCESS;
	}
	return status;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LNode *slow, *fast;
	Status status = ERROR;
	if(L != NULL && L->next != NULL){		/*保证将判断的链表结点有两个或两个以上*/
		slow = fast = L;
		while(slow != NULL && fast->next != NULL){
			slow = slow->next;			/*slow往后一个结点指*/
			fast = fast->next->next;	/*fast往后两个结点指*/
			if(slow == fast){			/*两个指针相遇则有循环*/
				status = SUCCESS;
				break;
			}
		}
	}
	return status;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LNode *pre, *Next;
	if(*L != NULL && (*L)->next != NULL){		/*保证将判断的链表结点有两个或两个以上*/
		pre = *L;
		*L = pre->next;			/*头指针指向第二个结点*/
		while(pre->next != NULL){
			Next = pre->next->next;		/*Next指向pre的后两个结点*/
			pre->next->next = pre;		/*pre后一个结点指向pre*/
			pre->next = Next;			/*pre指向Next*/
			pre = Next;					/*完成下一个两两反转*/
			if(Next == NULL)
				break;
		}
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LNode *middle = *L;
	ElemType cnt, i;
	for(cnt=0; middle; cnt++)		/*遍历一次算出所有结点数*/
		middle = middle->next;
	cnt = (cnt + 1) / 2;			/*算出中间结点的位置*/
	middle = *L;
	for(i=0; i<cnt+1; i++)			/*遍历到那个位置*/
		middle = middle->next;
	return middle;
}
