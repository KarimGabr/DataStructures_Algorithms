#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

void InitializeComponent()
{
    struct Node1* root1 = NULL; // make the root = null at the first time
    struct Node2* root2 = NULL;
}
//creat New node in the first tree
struct Node1* CNewNode(char id[], char name[])
{
    int i;
    struct Node1 * NewNode =malloc(sizeof(struct Node1)); // take place from memory to the new node ( in the heap ) in c we use malloc
    strcpy(NewNode->id, id); // put id of the student in the node ( NewNode->id =id; )
    strcpy(NewNode->name, name); // put name of the student in the node
    NewNode->left = NewNode->right = NULL; //set left and right pointers Null
    return NewNode; // return from the heap to the stack in the memory
}

//creat New node in the second tree
struct Node2* CNewNode2(char id[], char name[])
{
    int i;
    struct Node2 * NewNode2 = malloc(sizeof(struct Node2)); // take place from memory to the new node ( in the heap )
    strcpy(NewNode2->id, id); // put id of the student in the node ( NewNode->id =id; )
    strcpy(NewNode2->name, name);// put name of the student in the node
    NewNode2->left = NewNode2->right = NULL;//set left and right pointers Null
    return NewNode2; // return from the heap to the stack in the memory
}

// isert with id in the first tree
struct Node1* insert1(struct Node1* root1, char id[], char name[])
{
    if (root1 == NULL) //check if root is empty
    {
        root1 = CNewNode(id, name); //isert data
        return root1;
    }
    else if (strcmp(id, root1->id)<0) // isert left if the id smaller than the id in the prev node
    {
        root1->left = insert1(root1->left, id, name); //recursev insert ( the left pointer will point on the new adress of the new node)
    }
    else // id is greater
    {
        root1->right = insert1(root1->right, id, name);
    }
    return root1; // return the adress of root
}

// isert with name in the second tree
struct Node2* insert2(struct Node2* root2, char id[], char name[])
{
    if (root2 == NULL) //check if root is empty
    {
        root2 = CNewNode2(id, name); //isert data
        return root2;
    }
    else if (strcmp(name, root2->name) < 0) // isert left if the name smaller than the name in the prev node
    {
        root2->left = insert2(root2->left, id, name);//recursev insert ( the left pointer will point on the new adress of the new node)
    }
    else // name is greater
    {
        root2->right = insert2(root2->right, id, name);
    }
    return root2; // return the adress of root
}
//edit
struct Node1* edit1(struct Node1* root1, char id[],char name[])
{
    printf("What do u want to edit ? \n N:name \t I:id \t B:both\n");
    char u;
    scanf("%c",&u);
    getchar();
    if((u=='i')||(u=='I'))
    {
        printf("Enter the new id \n");
        char o[10];
        gets(o);
        strcpy(o,root1->id);
        return root1;    }
    else if((u=='n')||(u=='N'))
    {

    }
    else if((u=='b')||(u=='B'))
    {

    }

}
//search by id
struct Node1* search1(struct Node1* root1, char id[])
{
    if (root1 == NULL)
        return NULL;
    else if (strcmpi(id, root1->id) == 0)
        return root1;

    else if (strcmpi(id, root1->id) < 0)
        return search1(root1->left, id); //search in the left node
    else return search1(root1->right, id); //search in the right node
}

// search by name
struct Node2* search2(struct Node2* root2, char name[])
{
    if (root2 == NULL)
        return NULL;
    else if (strcmpi(name, root2->name) == 0)
        return root2;
    else if (strcmpi(name, root2->name) < 0)
        return search2(root2->left, name); //search in the left node
    else return search2(root2->right, name); //search in the right node
}

// find minmum id
struct Node1* findmin1(struct Node1* root1)
{
    if (root1 == NULL) //check if the root = null
    {
        return NULL;
    }
    struct 	Node1* currnt = root1; // make new struct to not effect the orign struct ( we can usr root1 as it def local )
    while (currnt->left != NULL) //get the last node at the left
    {
        currnt = currnt->left;
    }
    return currnt;
}

// find minmum name
struct Node2* findmin2(struct Node2* root2)
{
    if (root2 == NULL) //check if the root = null
    {
        return NULL;
    }
    struct Node2* currnt = root2; // make new struct to not effect the orign struct ( we can usr root1 as it def local )
    while (currnt->left != NULL) //get the last node at the left
    {
        currnt = currnt->left;
    }
    return currnt;
}

// find maxmum id
struct Node1* findmax1(struct Node1* root1)
{
    if (root1 == NULL) //check if the root = null
    {
        return NULL;
    }
    struct Node1* currnt = root1; // make new struct to not effect the orign struct ( we can usr root1 as it def local )
    while (currnt->right != NULL) //get the last node at the right
    {
        currnt = currnt->right;
    }
    return currnt;
}

// find maxmum name
struct Node2* findmax2(struct Node2* root2)
{
    if (root2 == NULL) //check if the root = null
    {
        return NULL;
    }
    struct Node2* currnt = root2; // make new struct to not effect the orign struct ( we can usr root1 as it def local )
    while (currnt->right != NULL) //get the last node at the right
    {
        currnt = currnt->right;
    }
    return currnt;
}

//find hieght of the tree
int findhight(struct Node1* root1)//hirght of the tree = # of edges in the longest path from root to leaf (hieght of root)
{
    if (root1 == NULL)
        return -1;
//	return (max(findhight(root1->left), findhight(root1->right)) + 1);
}
/*
//print level order id ( Breadth-first )
void LevelOrder1(Node1 *root1) {
if (root1 == NULL) return;
queue<Node*> Q;
Q.push(root1);
//while there is at least one discovered node
while (!Q.empty()) {
Node1* current = Q.front();
Q.pop(); // removing the element at front
//cout << current->data << " ";
if (current->left != NULL) Q.push(current->left);
if (current->right != NULL) Q.push(current->right);
}
}

//print level order names ( Breadth-first )
void LevelOrder2(Node2 *root2) {
if (root2 == NULL) return;
queue<Node2*> Q;
Q.push(root2);
//while there is at least one discovered node
while (!Q.empty()) {
Node2* current = Q.front();
Q.pop(); // removing the element at front
//cout << current->data << " ";
if (current->left != NULL) Q.push(current->left);
if (current->right != NULL) Q.push(current->right);
}
}
*/
// print preorder id( depth first)
void preorder1(struct Node1* root1)
{
    if (root1 == NULL) return;
    printf("name :%s \t id:%s \n",root1->name,root1->id);
    preorder1(root1->left);
    preorder1(root1->right);
}

// print preorder name( depth first)
void preorder2(struct Node2* root2)
{
    if (root2 == NULL) return;
    printf("name :%s \t id:%s \n",root2->name,root2->id);
    preorder2(root2->left);
    preorder2(root2->right);
}

// print inorder id( depth first)
void inorder1(struct Node1* root1)
{
    if (root1 == NULL) return;
    inorder1(root1->left);
    printf("name :%s \t id:%s \n",root1->name,root1->id);
    inorder1(root1->right);
}

// print inorder name( depth first)
void inorder2(struct Node2* root2)
{
    if (root2 == NULL) return;
    inorder2(root2->left);
    printf("name :%s \t id:%s \n",root2->name,root2->id);
    inorder2(root2->right);
}

// print postorder id( depth first)
void postorder1(struct Node1* root1)
{
    if (root1 == NULL) return;
    postorder1(root1->left);
    postorder1(root1->right);
    printf("name :%s \t id:%s \n",root1->name,root1->id);

}

// print postorder name ( depth first)
void postorder2(struct Node2* root2)
{
    if (root2 == NULL) return;
    postorder2(root2->left);
    postorder2(root2->right);
    printf("name :%s \t id:%s \n",root2->name,root2->id);
}

struct Node1* deleten(struct Node1* root1, char data[]) //return pointer to root node becase it may change after delete
{
    if (root1 == NULL)
        return root1;

    else if (strcmpi(data, root1->id) < 0)
        root1->left = deleten(root1->left, data);
    else if (strcmpi(data, root1->id) > 0)
        root1->right = deleten(root1->right, data);
    else
    {
// Case 1:  No child
        if (root1->left == NULL && root1->right == NULL)
        {
            free(root1);
            root1 = NULL;
        }
//Case 2: One child
        else if (root1->left == NULL)
        {
            struct Node1 *temp = root1;
            root1 = root1->right;
            free(temp);
        }
        else if (root1->right == NULL)
        {
            struct Node1 *temp = root1;
            root1 = root1->left;
            free(temp);
        }
// case 3: 2 children
        else
        {
            struct Node1 *temp = FindMin(root1->right);
            strcpy(root1->id,temp->id);
            root1->right = deleten(root1->right, temp->id);
        }

    }
    return root1;
}

struct Node2* deleten2(struct Node2* root2, char data[]) //return pointer to root node becase it may change after delete
{
    if (root2 == NULL)
        return root2;
    else if (strcmpi(data, root2->id) < 0)
        root2->left = deleten2(root2->left, data);
    else if (strcmpi(data, root2->id) > 0)
        root2->right = deleten2(root2->right, data);
    else
    {
// Case 1:  No child
        if (root2->left == NULL && root2->right == NULL)
        {
            free(root2);
            root2 = NULL;
        }
//Case 2: One child
        else if (root2->left == NULL)
        {
            struct Node2 *temp = root2;
            root2 = root2->right;
            free(temp);
        }
        else if (root2->right == NULL)
        {
            struct Node2 *temp = root2;
            root2 = root2->left;
            free(temp);
        }
// case 3: 2 children
        else
        {
            struct Node2 *temp = FindMin2(root2->right);
            strcpy(root2->id,temp->id);
            root2->right = deleten2(root2->right, temp->id);
        }
        return root2;
    }
}

struct Node1* FindMin(struct Node1* root1)
{
    while (root1->left != NULL) root1 = root1->left;
    return root1;
}

struct Node2* FindMin2(struct Node2* root2)
{
    while (root2->left != NULL) root2 = root2->left;
    return root2;
}

/*
bool isubtless(Node1* root1, int value)
{
if (root1 == NULL)
return true;
if (root1->id <= value && isubtless(root1->left, value) && isubtless(root1->right, value))
return true;
else
return false;
}
bool isubtgreat(Node1* root1, int value)
{
if (root1 == NULL)
return true;
if (root1->id > value && isubtgreat(root1->left, value) && isubtgreat(root1->right, value))
return true;
else
return false;
}
*/
//is binary s t
/*
bool isBST(struct Node1* root1, int minValue, int maxvalue)
{
	if (root1 == NULL)
		return true;
	if (root1->id > minValue  && root1->id < maxvalue && isBST(root1->left, minValue, root1->id) && isBST(root1->right, root1->id, maxvalue))
		return true;
	else
		return false;

}

bool isBSTree(struct Node1* root1)
{
	return isBST(root1, INT_MAX, INT_MIN);
}
*/
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



int i=0,k=0;// index max # of contacts

// load file
void LOAD (char path [],FILE *pfk,struct Node1* root1,struct Node2* root2)
{

    char s;
    strcat(path,".txt");
    pfk = fopen(path,"r");
    if(pfk!=NULL)
    {
        while (!(feof(pfk)))
         {
             char v[1100];
             char x[1000];
             char y[100];
             int s=0;
             int i=0;
             fgets (v,10000,pfk);
             for(i=0;v[s]!=',';i++)
             {
                   x[i] = v[s];
                   s++;
             }
                x[i]='\0';
                s++;
             for(i=0;v[s]!='\n';i++,s++)
                {
                    y[i]=v[s];
                }
                y[i]='\0';
               insert1(root1,y,x);
               insert2(root2,y,x);

         }
        /*while(!(feof(pfk)))
        {
            fscanf(pfk,"%[^,],%[^\n]",dataa[i].Name,dataa[i].Id);

            char so[100],si[100];
            strcpy(so,dataa[i].Name);
            strcpy(si,dataa[i].Id);
            root1=insert1(root1,si,so);
            root2=insert2(root2,si,so);
            fscanf(pfk,"\n");
            i++;
        }*/
    }
    else
    {
        printf("file does not exist do u want to creat new file with this name ?\n");
        scanf("%s",&s);
        getchar();
        if(s=='y')
        {
            pfk = fopen(path,"w");

        }
        // system("cls");
    }
    fclose(pfk);

}

//save changes
void SAVE (char path [],FILE *pfk)
{
    int j;
    pfk = fopen(path,"w");
    int c=0;
    if(pfk!=NULL)
    {
        Loadid(root1);
        for(j=0; j<i; j++)
        {
            //struct Node2* ;

            fprintf(pfk,"%s,%s\n",dataa[c].Name,dataa[c].Id);
            c++;
        }
    }
    else
        printf("file does not exist \n");
    fclose(pfk);
}
// print preorder id( depth first)
void Loadid(struct Node1* root1)
{
    //if (root1 == NULL) return;
    char so[100],si[100];
    strcpy(so,dataa[k].Name);
    strcpy(si,dataa[k].Id);
    k++;
    preorder1(root1->left);
    preorder1(root1->right);
}
