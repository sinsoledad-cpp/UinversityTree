#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include "common.h"
#include "tree.h"
#include "stack.h"
#include "queue.h"

int main()
{
	Node* tree = NULL;

	while (true)
	{
		MainMenu();
		int select;
		printf("your select: ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
		case 1:
		{
			printf("正在文件中读取二叉树...\n");
			tree = CreateTreeByFile();
			//visit(root);
			printf("读取成功\n");
		}
			break;
		case 2:
		{
			printf("请输入被查找的元素x：");
			ElemType target;
			scanf("%c", &target);
			if(!tree)
			{
				printf("该树是空树！\n");
				break;
			}
			Node* result = SearchNode(tree, target);
			if (result != NULL)
			{
				printf("找到了元素: ");
				Visit(result);
				printf("\n");
			}
			else printf("找不到该元素\n");		
		}
			break;
		case 3:
		{
			//system("cls");
			printf("用凹入发打印二叉树: \n");
			InvaginatPrint(tree, 0);
		}
			break;
		case 4:
		{
			//system("cls");
			printf("用非递归方式先序遍历方式输出树T的结点: \n");
			PrintTreeNodeByStack(tree);
			printf("\n");
		}
			break;
		case 5:
		{		
			printf("用中序遍历或后序遍历方式输出树的结点：\n");
			int model;
			printf("中序请输入1 后序情入0\n model: ");
			scanf("%d", &model);
			if (model == 1)
			{
				InOrderByRecursion(tree);
				printf("\n");
				break;
			}
			else
			{
				PostOrderByRecursion(tree);
				printf("\n");
				break;
			}
		}	
			break;
		case 6:
		{
			printf("层次遍历方式输出树的结点: \n");
			PrintTreeNodeByQueue(tree);
			printf("\n");
		}
			break;
		case 7:
		{
			printf("输出树的深度: \n");
			int deepth = GetTreeDeepth(tree);
			printf("deepth = %d\n", deepth);
		}
			break;
		case 8:
		{
			//system("cls");
			printf("输出树的叶子结点或非叶子结点\n");
			printf("1.打印叶子结点\t");
			printf("2.打印非叶子结点\n");
			int selects;
			scanf("%d", &selects);
			if (selects == 1) {
				printf("叶子结点：");
				LeafNodePrint(tree);
				printf("\n");
				break;
			}
			else if (selects == 2) {
				printf("非叶子结点：");
				NoLeafNodePrint(tree);
				printf("\n");
				break;
			}
			else {
				printf("输入错误！\n");
				break;
			}
		}
		case 0:
			exit(0);
			break;
		default:
			printf("输入错误！八嘎！！！\n");
			break;
		}
	}
	return 0;
}




//int main()
//{
//	Node* tree = CreateTreeByFile();
//	if (tree == NULL)printf("NULL\n");
//	PreOrderByRecursion(tree);
//	printf("\n");
//	InOrderByRecursion(tree);
//	printf("\n");
//	PostOrderByRecursion(tree);
//	printf("\n");
//	Node* result = SearchNode(tree, 'e');
//	Visit(result);
//	printf("\n");
//	InvaginatPrint(tree, 0);
//	int deepth = GetTreeDeepth(tree);
//	printf("deepth = %d\n", deepth);
//	int number = GetTreeNodeNumber(tree);
//	printf("node number = %d\n", number);
//
//	printf("叶子结点: ");
//	LeafNodePrint(tree);
//	printf("\n");
//
//	printf("非叶子结点: ");
//	NoLeafNodePrint(tree);
//	printf("\n");
//
//	PreOrderByRecursion(tree);
//	printf("\n");
//	PrintTreeNodeByStack(tree);
//	printf("\n");
//	PrintTreeNodeByQueue(tree);
//	printf("\n");
//
//	bool flag = IsCompleteTree(tree);
//	printf("Is it a complete tree ?\t %s \n", flag ? "Yes" : "No");
//
//	printf("-------------\n");
//	Stack* stack = NULL;
//	stack = InititateStack();
//	PushStack(stack, tree);
//	printf("size = %d\n", GetStackSize(stack));
//	Node* res = TopStack(stack);
//	Visit(res);
//
//	printf("-------------\n");
//	Queue queue;
//	InitiateQueue(&queue);
//	printf("%d\n", GetQueueSize(queue.front));
//	PushQueue(&queue, tree);
//	printf("%d\n", GetQueueSize(queue.front));
//	Node* results = TopQueue(&queue);
//	Visit(results);
//
//	return 0;
//}