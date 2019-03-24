#include <stdio.h>
#include "../head/linkedList.h"
#include <stdlib.h>

Status *save_get(ElemType *choice);
void init_print();

int main()
{
	ElemType choice;
	init_print();		/*判断用户是否输入数据的menu*/
	while (1){
		save_get(&choice);
		switch(choice){
		case 1:			/*要输入数据*/
			system("cls");
			LinkedList *L;		/*初始化一个指向头结点的指针*/
			L = (LinkedList*)malloc(sizeof(LinkedList));
			init_process(L);	/*操作程序*/
			break;
		case 2:			/*要退出程序*/
			printf("\n\n\t再见！\n\t按回车结束程序\n");
			exit(0);
			break;
		default:		/*无效输入*/
			printf("输入有误，请再输入您的选择（1 or 2）：");
			continue;
		}
		break;
	}

}
