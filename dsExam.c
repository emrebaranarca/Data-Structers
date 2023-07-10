#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
int Hash(char *key,int mul,int size)
{
    int i=0;
    int pos=0;
    while(key[i])
    {
        pos=(key[i]+mul*pos)%size;
        i++;
    }
    return pos;
}

struct node
{
    char* key;
    struct node* next;
};
struct hashnode
{
    int count;
    struct node* header;
};
struct hashtable
{
    int tablesize;
    int multiplier;
    struct hashnode* headtable;

};

void createHashTable(int size,int mul,struct hashtable** table)
{
    *table=(struct hashtable*)malloc(sizeof(struct hashtable));
    (*table)->multiplier=mul;
    (*table)->tablesize=size;
    (*table)->headtable=(struct hashnode*)malloc(size*sizeof(struct hashnode));
    for(int i=0;i<size;i++)
    {
        (*table)->headtable[i].count=0;
        (*table)->headtable[i].header=NULL;
    }
}
int insertionList(struct node** nd,char* key)
{
    if(*nd==NULL)
    {
        *nd=(struct node*)malloc(sizeof(struct node));
        (*nd)->key=(char*)malloc((strlen(key)+1)*sizeof(char));
        strcpy((*nd)->key,key);
        (*nd)->next=NULL;
        return 1;
    }
     else if(strcmp(key,(*nd)->key)) 
    {
        return insertionList(&((*nd)->next),key);
    }
    else return 0;
}
void insertionKeyHashTable(struct hashtable* tab,char* key)
{       
     int position=Hash(key,tab->multiplier,tab->tablesize);
    if(insertionList(&((tab->headtable +position)->header),key))
    {
        (tab->headtable +position)->count++;
    }


}
void printList(struct node* nd)
{   
    if(nd!=NULL)
    {
        printf("%s ",nd->key);
        printList(nd->next);
    }

}
void printHashTable(struct hashtable* tab)
{
    if(tab)
    {
        printf("*****HASH TABLE*****\n");
        for(int i=0;i<tab->tablesize;i++)
        {
            printf("pos : %d (%d)",i,tab->headtable[i].count);
            printList((tab->headtable+i)->header);
            printf("\n");
        }
    }
    else
       printf("empty");
}

int searchingHashTable(struct hashtable* tab,char* key)
{
    int pos=Hash(key,tab->multiplier,tab->tablesize);

    struct node* current=tab->headtable[pos].header;

    while (current!=NULL)
    {
        if(!strcmp(current->key,key)) 
            return 1;
        else
            current=current->next;
    }
    return 0;
}

int isEqual(struct hashtable* tab1,struct hashtable* tab2)
{

}

*/
struct node
{
    int key;
    struct node *right;
    struct node *left;
};
struct BST
{
    struct node *root;
};
void createBST(struct BST** tree)
{
    *tree=(struct BST*)malloc(sizeof(struct BST));
    (*tree)->root=NULL;
}
struct node* createNode(int key)
{
    struct node* nd=NULL;
    nd=(struct node*)malloc(sizeof(struct node));
    nd->key=key;
    nd->left=nd->right=NULL;
    return nd;

}

void insertionBST(struct BST* tree,int key)
{
    struct node* nd=createNode(key);
    struct node* temp=NULL;
    struct node* prev=NULL;

    temp=tree->root;
    while (temp!= NULL)
    {
        prev=temp;
        if (nd->key < temp->key)
        {
            temp=temp->left;
        }
        else if(nd->key > temp->key)
        {
            temp=temp->right;
        }

        else return;     //if there is equalition exit the method
        
    }
    if(tree->root==NULL) 
    {
        tree->root=nd;
        return;
    }

    if(nd->key < prev->key)
    {
        prev->left=nd;
    }
    if(nd->key > prev->key)
    {
        prev->right=nd;
    }
    


}
void preOrder(struct node* root )
{
    if (root==NULL)
    {
        return;
    }
    printf("%d-",root->key);
    preOrder(root->left);
    preOrder(root->right);
    
}
void preOrderStart(struct BST *tree)
{
    if(tree->root==NULL) return;
    preOrder(tree->root);
}

// ikili ağaçta tek çocuğa sahip olan yani (only one child ) node sayısını bulan algoritmayı yazınız

int numberOfOnlyOneChild(struct node* root)
{
    if(root==NULL) return 0;
    if(root->left!=NULL && root->right==NULL || root->left==NULL && root->right!=NULL) return 1;
    else return numberOfOnlyOneChild(root->left)+numberOfOnlyOneChild(root->right);
    

    
}


int main(int argc, char const *argv[])
{  
    /* final sınavından 60 ALINACAK */

    // LinkedList

    // Stack Queque  ?

    // Binary Search Tree  !!

    // Heap   !

    // AVL Tree  !!! 

    // Hash table with chaining  !!!

    // GRAPHS !!!



    /* HASH DATA STRUCTURE */


    // struct hashtable* tab1=NULL;
    // createHashTable(7,5,&tab1);
    // insertionKeyHashTable(tab1,"emre");
    // //insertionKeyHashTable(tab1,"yasin");
    // printHashTable(tab1);
    // printf("\ntest\n");
    // printf("is there : %d ",searchingHashTable(tab1,"yasin"));
    // printf("\ntest9\n");

    

   /* BST */

   struct BST* tree=NULL;
   createBST(&tree);
   insertionBST(tree,3);
    insertionBST(tree,1);
    insertionBST(tree,2);
    insertionBST(tree,5);
    preOrderStart(tree);
    printf("\ntest\n");
    printf("%d",numberOfOnlyOneChild(tree));
    printf("\ntest9");


    








   /* HEAP */













    
    return 0;
}


