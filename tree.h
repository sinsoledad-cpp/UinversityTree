#ifndef TREE_H
#define TREE_H
#include "common.h"
//#include "stack.h"
//#include "queue.h"
//#include "queue.h"
typedef char ElemType;
typedef struct TreeNode
{
	ElemType value;
	struct Node* left;
	struct Node* right;
}Node;

//typedef struct BinaryTree
//{
//	Node* head;
//}BinaryTree;
//Node* CreateAndInitNode();

Node* CreateAndInitNode();
Node* CreateTreeByOrder(char* string);
Node* CreateTreeByFile();
void Visit(Node* node);
void PreOrderByRecursion(Node* root);
void InOrderByRecursion(Node* root);
void PostOrderByRecursion(Node* root);

Node* SearchNode(Node* root, ElemType value);
void InvaginatPrint(Node* root, int deep);

int GetTreeDeepth(Node* root);
int GetTreeNodeNumber(Node* root);
void LeafNodePrint(Node* root);
void NoLeafNodePrint(Node* root);

void PrintTreeNodeByStack(Node* root);
void PrintTreeNodeByQueue(Node* head);

bool IsCompleteTree(Node* root);
//void PrintTreeNodeByQueuesss(Queue* queue);
#endif 