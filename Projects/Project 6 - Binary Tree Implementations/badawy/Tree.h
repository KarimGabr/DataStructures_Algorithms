// File Tree.h
#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED


// the first tree
struct Node1 //bst node
{
	char id[10];
	char name[100];
	struct Node1 *left;
	struct Node1 *right;
};
struct Node1* root1; // pointer of the root

// the second tree
struct Node2 //bst node
{
	char id[10];
	char name[100];
	struct Node2 *left;
	struct Node2 *right;
};
struct Node2* root2; // pointer of the root

//define struct

typedef struct
{
    char Name[100];
    char Id[100];
} student;

student dataa[100]; // array of struct
student ser[100]; // array of struct


//prototypes
void InitializeComponent();
struct Node1* CNewNode(char id[], char name[]);
struct Node2* CNewNode2(char id[], char name[]);
struct Node1* insert1(struct Node1* root1, char id[], char name[]);
struct Node2* insert2(struct Node2* root2, char id[], char name[]);
struct Node1* search1(struct Node1* root1, char id[]);
struct Node2* search2(struct Node2* root2, char name[]);
struct Node1* findmin1(struct Node1* root1);
struct Node2* findmin2(struct Node2* root2);
struct Node1* findmax1(struct Node1* root1);
struct Node2* findmax2(struct Node2* root2);
int findhight(struct Node1* root1);
void LevelOrder1(struct Node1 *root1);
void LevelOrder2(struct Node2 *root2) ;
void preorder1(struct Node1* root1);
void preorder2(struct Node2* root2);
void inorder1(struct Node1* root1);
void inorder2(struct Node2* root2);
void postorder1(struct Node1* root1);
void postorder2(struct Node2* root2);
struct Node1* deleten(struct Node1* root1, char data[]);
struct Node2* deleten2(struct Node2* root2, char data[]);
struct Node1* FindMin(struct Node1* root1);
struct Node2* FindMin2(struct Node2* root2);
void LOAD (char path [],FILE *pfk,struct Node1* root1,struct Node2* root2);
void SAVE (char path [],FILE *pfk);
struct Node1* edit1(struct Node1* root1, char id[],char name[]);
//bool isBST(struct Node1* root1, int minValue, int maxvalue);
//bool isBSTree(struct Node1* root1);
/*
// Counting number of nodes you have in the binary tree
int countNodes()
{
return countNodes(root1);
}

int countNodes(Node1 *root1)
{
if (root1 == NULL)
return 0;
else
return 1 + countNodes(root1->left) + countNodes(root1->right);
}
// Counting number of leavies nodes in the binary tree
int countleavies()
{
return countleavies(root1);
}

int countleavies(Node1 *root1)
{
if (root1 == NULL)
return 0;
else
{
if (root1->left == NULL && root1->right == NULL)
return 1;
else
return countleavies(root1->left) + countleavies(root1->right);
}
}


// Ciynting the nodes that have the same values in the binary tree
int countDup(int x)
{
return countDup(x, root1);
}

int countDup(int x, Node1 *root1)
{
if (root1 == NULL)
return 0;
else if (root1->id == x)
return 1 + countDup(x, root1->left) + countDup(x, root1->right);
else
return countDup(x, root1->left) + countDup(x, root1->right);
}


// Ciynting the nodes that have the same values in the binary tree
int countDup2(int x)
{
return countDup2(x, root2);
}

int countDup2(int x, Node2 *root2)
{
if (root2 == NULL)
return 0;
else if (root2->id == x)
return 1 + countDup2(x, root2->left) + countDup2(x, root2->right);
else
return countDup2(x, root2->left) + countDup2(x, root2->right);
}
*/


#endif // TREE_H_INCLUDED
