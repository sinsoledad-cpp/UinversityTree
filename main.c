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
			printf("�����ļ��ж�ȡ������...\n");
			tree = CreateTreeByFile();
			//visit(root);
			printf("��ȡ�ɹ�\n");
		}
			break;
		case 2:
		{
			printf("�����뱻���ҵ�Ԫ��x��");
			ElemType target;
			scanf("%c", &target);
			if(!tree)
			{
				printf("�����ǿ�����\n");
				break;
			}
			Node* result = SearchNode(tree, target);
			if (result != NULL)
			{
				printf("�ҵ���Ԫ��: ");
				Visit(result);
				printf("\n");
			}
			else printf("�Ҳ�����Ԫ��\n");		
		}
			break;
		case 3:
		{
			//system("cls");
			printf("�ð��뷢��ӡ������: \n");
			InvaginatPrint(tree, 0);
		}
			break;
		case 4:
		{
			//system("cls");
			printf("�÷ǵݹ鷽ʽ���������ʽ�����T�Ľ��: \n");
			PrintTreeNodeByStack(tree);
			printf("\n");
		}
			break;
		case 5:
		{		
			printf("�������������������ʽ������Ľ�㣺\n");
			int model;
			printf("����������1 ��������0\n model: ");
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
			printf("��α�����ʽ������Ľ��: \n");
			PrintTreeNodeByQueue(tree);
			printf("\n");
		}
			break;
		case 7:
		{
			printf("����������: \n");
			int deepth = GetTreeDeepth(tree);
			printf("deepth = %d\n", deepth);
		}
			break;
		case 8:
		{
			//system("cls");
			printf("�������Ҷ�ӽ����Ҷ�ӽ��\n");
			printf("1.��ӡҶ�ӽ��\t");
			printf("2.��ӡ��Ҷ�ӽ��\n");
			int selects;
			scanf("%d", &selects);
			if (selects == 1) {
				printf("Ҷ�ӽ�㣺");
				LeafNodePrint(tree);
				printf("\n");
				break;
			}
			else if (selects == 2) {
				printf("��Ҷ�ӽ�㣺");
				NoLeafNodePrint(tree);
				printf("\n");
				break;
			}
			else {
				printf("�������\n");
				break;
			}
		}
		case 0:
			exit(0);
			break;
		default:
			printf("������󣡰˸£�����\n");
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
//	printf("Ҷ�ӽ��: ");
//	LeafNodePrint(tree);
//	printf("\n");
//
//	printf("��Ҷ�ӽ��: ");
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