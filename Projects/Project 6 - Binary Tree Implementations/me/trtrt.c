#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{int Data;struct Node *left_child , *right_child;} *Bubble;

void inorder_traverse(struct Node *Tree)
{
	if (Tree)
	{
		inorder_traverse(Tree -> left_child);
		printf("%d\t", Tree -> Data);
		inorder_traverse(Tree -> right_child);
	}
}
struct node * CreateBubble(int Data)
{
	struct node * Bubble = (struct node *) malloc(sizeof(struct node));
	Bubble->Data = Data;
	Bubble->right_child = NULL;
	Bubble->left_child = NULL;
	return Bubble;
}
void insert (struct node * Tree,int Data)
{

	if (!Tree)
	{
		Tree = CreateBubble(Data);
	}
	else if (Data<Tree->Data)
	{
		insert (Tree->left_child,Data);
	}
	else if (Data>Tree->Data)
	{

		insert (Tree->right_child,Data);
	}
}
void preorder_traverse(struct Node *Tree)
{
	if (Tree)
	{
		printf("%d\t", Tree -> Data);
		preorder_traverse(Tree -> left_child);
		preorder_traverse(Tree -> right_child);
	}
}

void postorder_traverse(struct Node *Tree)
{
	if (Tree)
	{
		postorder_traverse(Tree -> left_child);
		postorder_traverse(Tree -> right_child);
		printf("%d\t", Tree -> Data);
	}
}

struct Node* insert(int number,struct Node *Tree)
{
	if (Tree == NULL)
	{
		Bubble = (struct Node*)malloc(sizeof(struct Node));
		Bubble -> Data = number;
		Bubble -> right_child = Bubble -> left_child = NULL;
	}

	else if (number < Tree -> Data)    Tree -> left_child = insert(number , Tree -> left_child);

	else if (number > Tree -> Data)    Tree -> right_child = insert(number , Tree -> right_child);

	else if (number == Tree -> Data)
	{
		puts("ERROR DATA already EXISTS!");
		return;
	}

	return Bubble;
}

int main()
{
	struct Node *Tree = NULL;
	Tree =  insert(5 , Tree);
	insert(7 , Tree);
	insert(13 , Tree);
	insert(1 , Tree);
	insert(6 , Tree);
	insert(2 , Tree);
	inorder_traverse(Tree);
	puts("");
	preorder_traverse(Tree);
	puts("");
	postorder_traverse(Tree);
}
