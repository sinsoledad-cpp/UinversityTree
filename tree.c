#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include "stack.h"
#include "queue.h"
const char* filename = "tree.txt";
static int fileindex = 0;
Node* CreateAndInitNode()
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (!newnode)
	{
		printf("CreateAndInitNode defeat\n");
		return NULL;
	}
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
Node* CreateTreeByOrder(char* string)
{
	Node* node = NULL;
	char ch = string[fileindex++];
	if (ch != '#')
	{
		node = CreateAndInitNode();
		node->value = ch;
	}
	else
	{
		return node;
	}
	node->left = CreateTreeByOrder(string);
	node->right = CreateTreeByOrder(string);
	return node;
}
Node* CreateTreeByFile()
{
	FILE* file = fopen("tree.txt", "r");
	if (!file)
	{
		printf("CreateTreeByFile 文件打开失败\n");
		return NULL;
	}
	//char filestring[1000];
	//fscanf(filename, "%s", filestring);

	char* filestring = (char*)malloc(sizeof(char) * 100);
	if (!filestring)return NULL;
	memset(filestring, 0, 100);
	fgets(filestring, 100, file);
	//printf("%s\n", filestring);
	fclose(file);
	//char* filestring = "-+a##*b##-c##d##/e##f##";
	Node* tree = CreateTreeByOrder(filestring);
	return tree;
}

void Visit(Node* node)
{
	printf("%c", node->value);
	return;
}
void PreOrderByRecursion(Node* root)
{
	//printf("pre\n");
	if (root == NULL)return;
	Visit(root);
	PreOrderByRecursion(root->left);
	PreOrderByRecursion(root->right);
}
void InOrderByRecursion(Node* root)
{
	if (root == NULL)return;
	InOrderByRecursion(root->left);
	Visit(root);
	InOrderByRecursion(root->right);
}
void PostOrderByRecursion(Node* root)
{
	if (root == NULL)return;
	PostOrderByRecursion(root->left);
	PostOrderByRecursion(root->right);
	Visit(root);
}

Node* SearchNode(Node* root, ElemType value)
{
	if (root == NULL)return NULL;
	if (root->value == value)
	{
		return root;
	}
	Node* findresult = SearchNode(root->left, value);
	if (findresult != NULL)return findresult;
	findresult = SearchNode(root->right, value);
	if (findresult != NULL)return findresult;
	return NULL;
}
void InvaginatPrint(Node* root, int deep)//凹入表示法打印,逆时针旋转90°
{
	if (root == NULL)return;
	InvaginatPrint(root->right, deep + 1);
	for (int i = 0; i < deep ; i++)printf("    ");

	printf("---");
	printf("%c\n", root->value);

	InvaginatPrint(root->left, deep + 1);
}

int GetTreeDeepth(Node* root)
{
	if (root == NULL)return NULL;
	int left = GetTreeDeepth(root->left);
	int right = GetTreeDeepth(root->right);
	return left > right ? left + 1 : right + 1;
}
void LeafNodePrint(Node* root)
{
	if (root == NULL)return NULL;
	if (root->left == NULL && root->right == NULL)Visit(root);
	LeafNodePrint(root->left);
	LeafNodePrint(root->right);
}
void NoLeafNodePrint(Node* root)
{
	if (root == NULL)return NULL;
	if (root->left != NULL || root->right != NULL)Visit(root);
	NoLeafNodePrint(root->left);
	NoLeafNodePrint(root->right);
}

void PrintTreeNodeByStack(Node* root)
{
	if (!root)return;
	Stack* stack = InititateStack();
	PushStack(stack, root);
	while (!EmptyStack(stack))
	{
		int size = GetStackSize(stack);
		for (int i = 0; i < size; i++)
		{
			Node* temp = TopStack(stack);
			PushStack(stack, temp->right);
			PushStack(stack, temp->left);
			Visit(temp);
		}
	}
}
void PrintTreeNodeByQueue(Node* root)
{
	if (!root)return;
	Queue queue;
	InitiateQueue(&queue);
	PushQueue(&queue, root);
	while (!EmptyQueue(&queue))
	{
		int size = GetQueueSize(queue.front);
		for (int i = 0; i < size; i++)
		{
			Node* temp = TopQueue(&queue);
			PushQueue(&queue, temp->left);
			PushQueue(&queue, temp->right);
			Visit(temp);
		}
	}

}
int GetTreeNodeNumber(Node* root)
{
	if (root == NULL)return 0;
	return GetTreeNodeNumber(root->left) + GetTreeNodeNumber(root->right) + 1;
}
bool IsCompleteTree(Node* root)
{
	int deepth = GetTreeDeepth(root);
	int nodenumber = GetTreeNodeNumber(root);
	int temp = pow(2, deepth) - 1;
	return temp == nodenumber ? true : false;
}