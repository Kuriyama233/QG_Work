#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*一个只能输入数字的读入*/
Status save_get(ElemType *choice){
	Status status = SUCCESS;
	if(scanf("%d",choice)!=1){		/*若不是数字，后面多余的字符会丢弃*/
		while(getchar()!='\n')		/*丢弃字符准备下一次输入*/
			continue;
		status = ERROR;
	}
	while(getchar()!='\n')			/*丢弃数字后的换行符*/
		continue;
	return status;
}

/*一个遍历并打印每个数据的函数*/
void Traverse_List(LinkedList *L) {
	LNode *pre = *L;
	while(pre != NULL){
		printf("%d  ",pre->data);	/*打印数据*/
		pre = pre->next;			/*到下一个结点*/
	}
	printf("\n\n");
}

/*一个读取到指定结点的函数*/
LNode* TraverseList_cnt(LinkedList *L, ElemType cnt) {
	LNode *pre = *L;
	for(int i=1; i<cnt; i++)
		pre = pre->next;
	return pre;
}

/*判断用户是否需要输入的界面*/
void init_print(){
	printf("\n\n\n\n\n"
	"\t\t\t|*******************************|\n"
	"\t\t\t|*         创建一个链表        *|\n"
	"\t\t\t|*   1、正序储存您输入的数据   *|\n"
	"\t\t\t|*   2、退出程序               *|\n"
	"\t\t\t|*******************************|\n"
	);
	printf("\n\t请输入您的选择（1 or 2）：");
}

/*判断用户处理数据的界面*/
void data_print(){
	printf("\n\n\n\n\n"
	"\t\t\t|***************************************|\n"
	"\t\t\t|*    1、遍历显示数据                  *|\n"
	"\t\t\t|*    2、插入1个数据                   *|\n"
	"\t\t\t|*    3、删除1个数据                   *|\n"
	"\t\t\t|*    4、查找数据                      *|\n"
	"\t\t\t|*    5、反转数据储存                  *|\n"
	"\t\t\t|*    6、判断数据是否循环储存          *|\n"
	"\t\t\t|*    7、偶数节点反转数据（不完善）    *|\n"
	"\t\t\t|*    8、查找正中间的1个数据（未完成） *|\n"
	"\t\t\t|*    9、销毁数据（未完成）            *|\n"
	"\t\t\t|*   10、退出程序                      *|\n"
	"\t\t\t|***************************************|\n"
	);
	printf("\n\t请输入您的选择（1-10）：");
}

/*处理数据时的具体实现过程*/
void data_process(LinkedList *L, ElemType cnt){
	ElemType choice;
	DataPrint:		/*goto的终点*/
	data_print();	/*处理用户数据的menu*/
	while (1){
		save_get(&choice);		/*输入选项，执行操作*/
		switch(choice){

		case 1:		/*遍历打印*/
			system("cls");
			printf("数据如下：\n");
			Traverse_List(L);		/*一个打印函数*/
			printf("请按回车继续。");
			while(getchar() !='\n');	/*回车返回menu*/
			system("cls");
			goto DataPrint;

		case 2:		/*插入结点*/
			system("cls");
			printf("数据如下：\n");
			Traverse_List(L);		/*显示现录入数据*/
			printf("请问您要插入到第几个节点后面（1-%d）",cnt);
			do{
				save_get(&choice);		/*选择插入的位置*/
			}while(choice>cnt && choice<0);
			LNode *p = TraverseList_cnt(L, choice);		/*p存取位置信息*/
			printf("请输入要插入的数据：");
			ElemType data;
			save_get(&data);			/*读取将插入的数据*/
			LNode *q = (LNode*)malloc(sizeof(LNode));	/*q存储录入的数据信息*/
			q->data = data;
			q->next = NULL;
			if(InsertList(p, q))		/*插入链表中*/
				printf("插入完成\n");
			else
				printf("插入失败\n");
			printf("请按回车继续。");	/*回车返回menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 3:			/*删除结点*/
			system("cls");
			printf("数据如下：\n");
			Traverse_List(L);		/*显示现录入数据*/
			printf("请问您要删除哪个节点（1-%d）：",cnt);
			do{
				save_get(&choice);		/*读取删除的结点位置*/
			}while(choice>cnt && choice<0);
			LNode *will_delete = TraverseList_cnt(L, choice-1);	/*记录删除结点位置*/
			ElemType *e = (ElemType*)malloc(sizeof(ElemType));	/*保存值*/
			if(DeleteList(will_delete, e)){		/*删除结点*/
				printf("删除完成\n");
				printf("删除的值e = %d\n",*e);
			}
			else
				printf("删除失败\n");
			printf("请按回车继续。");	/*回车返回menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 4:  		/*查找数据*/
			system("cls");
			printf("您想要查找的数据是：");
				save_get(&data);	/*读取寻找的数据*/
			if(SearchList(*L, data))	/*查找数据*/
				printf("您查找的数据在链表中\n");
			else
				printf("您查找的数据不在链表中\n");
			printf("请按回车继续。");		/*回车返回menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 5:			/*反转链表*/
			system("cls");
			printf("您确定要反转链表吗？（1：同意  0：取消）：");
			save_get(&choice);
			switch (choice){
				case 1:			/*同意反转*/
					if(ReverseList(L))		/*反转链表*/
						printf("反转成功\n");
					else
						printf("反转失败\n");
					printf("请按回车继续。");	/*回车返回menu*/
					while(getchar() !='\n');
				default:		/*不同意反转，回到menu*/
					system("cls");
					goto DataPrint;
			}

		case 6:		/*判断循环*/
			system("cls");
			if(IsLoopList(*L))	/*判断循环*/
				printf("该链表是循环链表\n");
			else
				printf("该链表不是循环链表\n");
			printf("请按回车继续。");		/*回车返回menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 7:					/*反转偶数结点，未完成*/
			system("cls");
			printf("您确定要偶数节点反转链表吗？（1：同意  0：取消）：");
			save_get(&choice);		/*判断是否同意*/
			switch (choice){
				case 1:		/*同意*/
//					ReverseEvenList(L);			/*反转偶数结点*/
					printf("反转失败\n请按回车继续。");
					while(getchar() !='\n');
				default:	/*不同意，回到menu*/
					system("cls");
					goto DataPrint;
			}

		case 8:			/*寻找正中间数据*/
			system("cls");
//			LNode *middle;
//			middle = FindMidNode(L);		/*传回中间结点的指针*/
//			printf("正中间的这个数为：%d",middle->data);	/*打印中间结点数据*/
			printf("查找失败，请按回车继续。");		/*回车返回menu*/
			while(getchar() !='\n');
			system("cls");
			goto DataPrint;

		case 9:		/*销毁链表*/
			system("cls");
			printf("您确定要销毁链表吗？（1：同意  0：取消）：");
			save_get(&choice);
			switch (choice){
				case 1:		/*同意销毁*/
//					DestroyList(L);			/*调用销毁函数*/
					printf("销毁失败\n请按回车继续。");
					while(getchar() !='\n');
				default:		/*不同意，回到menu*/
					system("cls");
					goto DataPrint;
			}

		case 10:	/*是否退出程序*/
			system("cls");
			printf("您确定要退出程序吗？（1：同意  0：取消）：");
			save_get(&choice);
			switch (choice){
				case 1:			/*退出*/
					printf("再见\n按结束退出程序\n");
					exit(0);
				default:		/*返回menu*/
					system("cls");
					goto DataPrint;
			}
		default:			/*处理无效输入*/
			printf("输入有误，请再输入您的选择（1 or 2）：");
			continue;
		}
		break;
	}

}

/*一个处理录入数据的函数*/
void init_process(LinkedList *L){
	ElemType data, cnt = 0;
	LNode *pre;
	printf("请输入您想要储存的数据(输入886结束录入)：");
	InitList(L);			/*初始化一个链表头*/
	while (1){
		while(save_get(&data)!=1);
		if (data == 886)		/*输入886结束录入*/
			break;
		else{
			if((*L)->data == NULL){		/*第一次录入存在*L指的位置*/
				(*L)->data = data;
				pre = *L;
			}
			else{					/*使用插入的方法录入其他数据*/
				LNode *q;
				q = (LNode*)malloc(sizeof(LNode));
				InsertList(pre, q);		/*插入到链表中*/
				q->data = data;
				pre = q;
			}
			cnt++;		/*记录录入的个数*/
		}
		printf("请再输入其它您想要储存的数据(输入886结束录入)：");
	}
	system("cls");
	data_process(L, cnt);		/*进入处理数据menu*/

}








