#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*һ��ֻ���������ֵĶ���*/
Status save_get(ElemType *choice){
	Status status = SUCCESS;
	if(scanf("%d",choice)!=1){		/*���������֣����������ַ��ᶪ��*/
		while(getchar()!='\n')		/*�����ַ�׼����һ������*/
			continue;
		status = ERROR;
	}
	while(getchar()!='\n')			/*�������ֺ�Ļ��з�*/
		continue;
	return status;
}

/*һ����������ӡÿ�����ݵĺ���*/
void Traverse_List(LinkedList *L) {
	LNode *pre = *L;
	while(pre != NULL){
		printf("%d  ",pre->data);	/*��ӡ����*/
		pre = pre->next;			/*����һ�����*/
	}
	printf("\n\n");
}

/*һ����ȡ��ָ�����ĺ���*/
LNode* TraverseList_cnt(LinkedList *L, ElemType cnt) {
	LNode *pre = *L;
	for(int i=1; i<cnt; i++)
		pre = pre->next;
	return pre;
}

/*�ж��û��Ƿ���Ҫ����Ľ���*/
void init_print(){
	printf("\n\n\n\n\n"
	"\t\t\t|*******************************|\n"
	"\t\t\t|*         ����һ������        *|\n"
	"\t\t\t|*   1�����򴢴������������   *|\n"
	"\t\t\t|*   2���˳�����               *|\n"
	"\t\t\t|*******************************|\n"
	);
	printf("\n\t����������ѡ��1 or 2����");
}

/*�ж��û��������ݵĽ���*/
void data_print(){
	printf("\n\n\n\n\n"
	"\t\t\t|***************************************|\n"
	"\t\t\t|*    1��������ʾ����                  *|\n"
	"\t\t\t|*    2������1������                   *|\n"
	"\t\t\t|*    3��ɾ��1������                   *|\n"
	"\t\t\t|*    4����������                      *|\n"
	"\t\t\t|*    5����ת���ݴ���                  *|\n"
	"\t\t\t|*    6���ж������Ƿ�ѭ������          *|\n"
	"\t\t\t|*    7��ż���ڵ㷴ת���ݣ������ƣ�    *|\n"
	"\t\t\t|*    8���������м��1�����ݣ�δ��ɣ� *|\n"
	"\t\t\t|*    9���������ݣ�δ��ɣ�            *|\n"
	"\t\t\t|*   10���˳�����                      *|\n"
	"\t\t\t|***************************************|\n"
	);
	printf("\n\t����������ѡ��1-10����");
}

/*��������ʱ�ľ���ʵ�ֹ���*/
void data_process(LinkedList *L, ElemType cnt){
	ElemType choice;
	DataPrint:		/*goto���յ�*/
	data_print();	/*�����û����ݵ�menu*/
	while (1){
		save_get(&choice);		/*����ѡ�ִ�в���*/
		switch(choice){

		case 1:		/*������ӡ*/
			system("cls");
			printf("�������£�\n");
			Traverse_List(L);		/*һ����ӡ����*/
			printf("�밴�س�������");
			while(getchar() !='\n');	/*�س�����menu*/
			system("cls");
			goto DataPrint;

		case 2:		/*������*/
			system("cls");
			printf("�������£�\n");
			Traverse_List(L);		/*��ʾ��¼������*/
			printf("������Ҫ���뵽�ڼ����ڵ���棨1-%d��",cnt);
			do{
				save_get(&choice);		/*ѡ������λ��*/
			}while(choice>cnt && choice<0);
			LNode *p = TraverseList_cnt(L, choice);		/*p��ȡλ����Ϣ*/
			printf("������Ҫ��������ݣ�");
			ElemType data;
			save_get(&data);			/*��ȡ�����������*/
			LNode *q = (LNode*)malloc(sizeof(LNode));	/*q�洢¼���������Ϣ*/
			q->data = data;
			q->next = NULL;
			if(InsertList(p, q))		/*����������*/
				printf("�������\n");
			else
				printf("����ʧ��\n");
			printf("�밴�س�������");	/*�س�����menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 3:			/*ɾ�����*/
			system("cls");
			printf("�������£�\n");
			Traverse_List(L);		/*��ʾ��¼������*/
			printf("������Ҫɾ���ĸ��ڵ㣨1-%d����",cnt);
			do{
				save_get(&choice);		/*��ȡɾ���Ľ��λ��*/
			}while(choice>cnt && choice<0);
			LNode *will_delete = TraverseList_cnt(L, choice-1);	/*��¼ɾ�����λ��*/
			ElemType *e = (ElemType*)malloc(sizeof(ElemType));	/*����ֵ*/
			if(DeleteList(will_delete, e)){		/*ɾ�����*/
				printf("ɾ�����\n");
				printf("ɾ����ֵe = %d\n",*e);
			}
			else
				printf("ɾ��ʧ��\n");
			printf("�밴�س�������");	/*�س�����menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 4:  		/*��������*/
			system("cls");
			printf("����Ҫ���ҵ������ǣ�");
				save_get(&data);	/*��ȡѰ�ҵ�����*/
			if(SearchList(*L, data))	/*��������*/
				printf("�����ҵ�������������\n");
			else
				printf("�����ҵ����ݲ���������\n");
			printf("�밴�س�������");		/*�س�����menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 5:			/*��ת����*/
			system("cls");
			printf("��ȷ��Ҫ��ת�����𣿣�1��ͬ��  0��ȡ������");
			save_get(&choice);
			switch (choice){
				case 1:			/*ͬ�ⷴת*/
					if(ReverseList(L))		/*��ת����*/
						printf("��ת�ɹ�\n");
					else
						printf("��תʧ��\n");
					printf("�밴�س�������");	/*�س�����menu*/
					while(getchar() !='\n');
				default:		/*��ͬ�ⷴת���ص�menu*/
					system("cls");
					goto DataPrint;
			}

		case 6:		/*�ж�ѭ��*/
			system("cls");
			if(IsLoopList(*L))	/*�ж�ѭ��*/
				printf("��������ѭ������\n");
			else
				printf("��������ѭ������\n");
			printf("�밴�س�������");		/*�س�����menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 7:					/*��תż����㣬δ���*/
			system("cls");
			printf("��ȷ��Ҫż���ڵ㷴ת�����𣿣�1��ͬ��  0��ȡ������");
			save_get(&choice);		/*�ж��Ƿ�ͬ��*/
			switch (choice){
				case 1:		/*ͬ��*/
//					ReverseEvenList(L);			/*��תż�����*/
					printf("��תʧ��\n�밴�س�������");
					while(getchar() !='\n');
				default:	/*��ͬ�⣬�ص�menu*/
					system("cls");
					goto DataPrint;
			}

		case 8:			/*Ѱ�����м�����*/
			system("cls");
//			LNode *middle;
//			middle = FindMidNode(L);		/*�����м����ָ��*/
//			printf("���м�������Ϊ��%d",middle->data);	/*��ӡ�м�������*/
			printf("����ʧ�ܣ��밴�س�������");		/*�س�����menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 9:		/*��������*/
			system("cls");
			printf("��ȷ��Ҫ���������𣿣�1��ͬ��  0��ȡ������");
			save_get(&choice);
			switch (choice){
				case 1:		/*ͬ������*/
//					DestroyList(L);			/*�������ٺ���*/
					printf("����ʧ��\n�밴�س�������");
					while(getchar() !='\n');
				default:		/*��ͬ�⣬�ص�menu*/
					system("cls");
					goto DataPrint;
			}

		case 10:	/*�Ƿ��˳�����*/
			system("cls");
			printf("��ȷ��Ҫ�˳������𣿣�1��ͬ��  0��ȡ������");
			save_get(&choice);
			switch (choice){
				case 1:			/*�˳�*/
					printf("�ټ�\n�������˳�����\n");
					exit(0);
				default:		/*����menu*/
					system("cls");
					goto DataPrint;
			}
		default:			/*������Ч����*/
			printf("��������������������ѡ��1 or 2����");
			continue;
		}
		break;
	}

}

/*һ������¼�����ݵĺ���*/
void init_process(LinkedList *L){
	ElemType data, cnt = 0;
	LNode *pre;
	printf("����������Ҫ���������(����886����¼��)��");
	InitList(L);			/*��ʼ��һ������ͷ*/
	while (1){
		while(save_get(&data)!=1);
		if (data == 886)		/*����886����¼��*/
			break;
		else{
			if((*L)->data == NULL){		/*��һ��¼�����*Lָ��λ��*/
				(*L)->data = data;
				pre = *L;
			}
			else{					/*ʹ�ò���ķ���¼����������*/
				LNode *q;
				q = (LNode*)malloc(sizeof(LNode));
				InsertList(pre, q);		/*���뵽������*/
				q->data = data;
				pre = q;
			}
			cnt++;		/*��¼¼��ĸ���*/
		}
		printf("����������������Ҫ���������(����886����¼��)��");
	}
	system("cls");
	data_process(L, cnt);		/*���봦������menu*/

}








