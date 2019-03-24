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
		*L = head;				/*��ͷָ��ָ��head*/
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
		pre = (*L)->next;		/*preָ��ڶ����ڵ�*/
		free(*L);				/*free����һ���ڵ�*/
		*L = pre;				/* *Lָ��preָ��Ľڵ�*/
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
		pre = p->next;		/*pre��¼p->next��λ��*/
		p->next = q;		/*��p��pre�ֱ���q��ϵ*/
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
		pre = p->next;			/*preָ��p����һ����㣬��ֵ����e*/
		*e = pre->data;
		p->next = pre->next;
		free(pre);				/*free��pre*/
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
		(*visit)(pre->data);		/*����pre*/
		pre = pre->next;			/*����һ�����*/
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
		target = L;				/*��L��ʼ*/
		while(target->data != e && target->next != NULL){	/*�ҵ�e���ߵ����һ�����ʱ�˳�*/
			target = target->next;			/*����һ�����*/
		}
		if(target->data == e)			/*�ж����һ������ǲ���e*/
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
	if (*L != NULL && (*L)->next != NULL){	/*��֤���жϵ�����������������������*/
		pre = *L;
		cur = pre->next;			/*pre��curǰ��*/
		pre->next = NULL;
		while(cur){
			Next = cur->next;		/*next��cur����*/
			cur->next = pre;		/*��curָ��ǰһ�����*/
			pre = cur;				/*�����������ָһλ*/
			cur = Next;
		}
		*L = pre;					/*Lָ���µ�ͷ���*/
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
	if(L != NULL && L->next != NULL){		/*��֤���жϵ�����������������������*/
		slow = fast = L;
		while(slow != NULL && fast->next != NULL){
			slow = slow->next;			/*slow����һ�����ָ*/
			fast = fast->next->next;	/*fast�����������ָ*/
			if(slow == fast){			/*����ָ����������ѭ��*/
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
	if(*L != NULL && (*L)->next != NULL){		/*��֤���жϵ�����������������������*/
		pre = *L;
		*L = pre->next;			/*ͷָ��ָ��ڶ������*/
		while(pre->next != NULL){
			Next = pre->next->next;		/*Nextָ��pre�ĺ��������*/
			pre->next->next = pre;		/*pre��һ�����ָ��pre*/
			pre->next = Next;			/*preָ��Next*/
			pre = Next;					/*�����һ��������ת*/
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
	for(cnt=0; middle; cnt++)		/*����һ��������н����*/
		middle = middle->next;
	cnt = (cnt + 1) / 2;			/*����м����λ��*/
	middle = *L;
	for(i=0; i<cnt+1; i++)			/*�������Ǹ�λ��*/
		middle = middle->next;
	return middle;
}
