#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node* next;
};
struct node* createNode(int data)
{
    struct node* nd;
    nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->next=NULL;

    return nd;
}
void insertionHeadList(int data,struct node** head)
{
    struct node* nd=createNode(data);
    nd->next=*head;
    *head=nd;

}
void insertionMiddleListMinMax(int data,struct node** head)
{
    struct node* nd=createNode(data);
    struct node* temp=*head;
    struct node* temp2;

    while(temp != NULL && temp->data <= data) 
    {
        if(temp->data == data) return ;
        temp2=temp;
        temp=temp->next;
    }
    if(temp==*head) 
    {
        nd->next=*head;
        *head=nd;
    }

    else    
    {
        temp2->next=nd;
        nd->next=temp;
    }

}
void insertionMiddleListMaxMin(int data,struct node** head)
{
    struct node* nd=createNode(data);
    struct node* temp=*head;
    struct node* temp2;
    

    while(temp != NULL && temp->data >= data) 
    {
        if(temp->data == data) return ;
        temp2=temp;
        temp=temp->next;
    }
    if(temp==*head) 
    {
        nd->next=*head;
        *head=nd;
    }

    else    
    {
        temp2->next=nd;
        nd->next=temp;
    }

}
void insertionMiddleListPosition(int position,int data,struct node** head)
{
    
    struct node* nd=createNode(data);
    struct node* temp=*head;
    struct node* temp2;



    for (int i =2; i < position; i++)
    {
        if(temp->data==data) return;
        if(temp != NULL)
        {
            temp2=temp;
            temp=temp->next;
        }

    }
    if(temp==*head) 
    {
        nd->next=*head;
        *head=nd;
    }
    temp2->next=nd;
    nd->next=temp;
}
void insertionEndList(int data,struct node** head)
{
    struct node* nd=createNode(data);
    if(*head==NULL)
    {
        nd->next=*head;
        *head=nd;
    }

    else
    {
        struct node* temp;
        temp=*head;
        while(temp ->next!= NULL)
        {
            temp=temp->next;
        }
        temp->next=nd;
    }
    
}
void deleteData(int data,struct node **head)
{

    struct node *temp=*head;
    struct node *temp2;
    
    while (temp != NULL && temp->data!=data)
    {
        temp2=temp;
        temp=temp->next;
    }
    
    if (temp==*head)
    {
        *head=(*head)->next;
        
    }
    else
    {
        temp2->next=temp->next;
        free(temp);

    }
}
void printLinkedList(struct node* nd)
{
    while (nd != NULL)
    {
        printf("%d --> ",nd->data);
        nd=nd->next;

    }
}


int main(int argc, char const *argv[])
{
    struct node *head=NULL;
    insertionHeadList(10,&head);
    insertionHeadList(20,&head);
    insertionEndList(30,&head);

    deleteData(20,&head);

    printLinkedList(head);

    
    return 0;
}
