#include <stdio.h>
#include "../head/linkedList.h"
#include <stdlib.h>

Status *save_get(ElemType *choice);
void init_print();

int main()
{
	ElemType choice;
	init_print();		/*�ж��û��Ƿ��������ݵ�menu*/
	while (1){
		save_get(&choice);
		switch(choice){
		case 1:			/*Ҫ��������*/
			system("cls");
			LinkedList *L;		/*��ʼ��һ��ָ��ͷ����ָ��*/
			L = (LinkedList*)malloc(sizeof(LinkedList));
			init_process(L);	/*��������*/
			break;
		case 2:			/*Ҫ�˳�����*/
			printf("\n\n\t�ټ���\n\t���س���������\n");
			exit(0);
			break;
		default:		/*��Ч����*/
			printf("��������������������ѡ��1 or 2����");
			continue;
		}
		break;
	}

}
