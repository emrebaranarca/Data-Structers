#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int multiplier;
    int tablesize;
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

void insertionKeyHashTable(struct hashtable* tab,char* key)
{       
     int position=Hash(key,tab->multiplier,tab->tablesize);
    if(insertionList(&((tab->headtable +position)->header),key))
    {
        (tab->headtable +position)->count++;
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

// int isEqual(struct hashtable* tab1,struct hashtable* tab2)
// {
//     for(int i=0;i<tab1->tablesize;i++)
//     {
//         if(strcmp(tab1->headtable[i].header->key,tab2->headtable[i].header->key))
//         {

//         }
        
        
//     }
// }





int main(int argc, char const *argv[])
{
    struct hashtable* table=NULL;
    printf("test\n");
    createHashTable(7,5,&table);
    printf("test\n");
    printHashTable(table);
    printf("test\n");
     insertionKeyHashTable(table,"anil");
     insertionKeyHashTable(table,"emre");
     printHashTable(table);
    
    struct hashtable* table2=NULL;
    createHashTable(7,5,&table2);
    insertionKeyHashTable(table2,"anil");
    insertionKeyHashTable(table2,"emre");

    printf("\nhashtable 2\n");
    printHashTable(table2);


    //int same=isEqual();

    
    return 0;
}


