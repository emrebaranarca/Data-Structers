#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* createNode(int data)
{
    struct node* nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->next=NULL;
}
void pushStack(struct node** stack,int data)
{
    if((*stack)==NULL)
    {
        *stack=createNode(data);
    }
    else
    {
        struct node* temp=*stack;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        struct node* node=createNode(data);
        temp->next=node;
    }
    
}
void popStack(struct node** stack)
{
    if(*stack==NULL) return;
    struct node* temp=*stack;
    if(temp->next==NULL)
    {
        free(*stack);
        return;
    }
    while (temp->next->next!=NULL)
    {
        
        temp=temp->next;
    }
    struct node* garbage=temp->next;
    temp->next=NULL;
    free(garbage);
    
    

}
void printStack(struct node* stack)
{
    struct node* temp=stack;
    if(stack==NULL) return;
    if(temp->next==NULL){
        printf("|%d|",temp->data);
        return;
    }
    
    while(temp!=NULL)
    {
        printf("|%d|",temp->data);
        temp=temp->next;
    }
}


int main(int argc, char const *argv[])
{
    struct node* stack1=NULL;
    printf("test\n");
    pushStack(&stack1,10);
    printf("test\n");
    pushStack(&stack1,20);
    
    printf("test\n");
    printStack(stack1);
     printf("\ntest\n");
    popStack(&stack1);
     printf("testtt\n");
     printStack(stack1);
     printf("aa\n");
     popStack(&stack1);
      printf("\ntest\n");
      //printStack(stack1);
     
    
    return 0;
}
