#include <stdio.h>
#include <stdlib.h>
struct stack{
    int* array;
    int top;
    int capasity;
};

struct stack* createStack(int capasity)
{
    struct stack* stck=(struct stack*)malloc(sizeof(struct stack));
    stck->capasity=capasity;
    stck->top=-1;
    stck->array=(int*)malloc(capasity*sizeof(int));
    
    return stck;
}
void destroyStack(struct stack** stack)
{
    free((*stack)->array);
    free(*stack);
    *stack=NULL;
    
    
    
}
void increasingCapasity(struct stack** stack,int newcapasity)
{
    (*stack)->capasity=newcapasity;
}
void pushStack(struct stack** stack,int data)
{
    if(stack==NULL || (*stack)->top == ((*stack)->capasity)-1) return ;  //overflow

    (*stack)->array[(++(*stack)->top)]=data;
    
}

void popStack(struct stack** stack)
{
    if(stack==NULL || (*stack)->top==-1) return;  //underflow

    (*stack)->array[(*stack)->top--];

}

int topStack(struct stack* stack)
{
    return stack->array[stack->top];
}

char isEmpty(struct stack* stack)
{
    if(stack->top==-1) return '1';
    else if(stack==NULL) return '1';
    else return '0';
}

char isFull(struct stack* stack)
{
    if(stack->top+1==stack->capasity) return '1';
    else if(stack==NULL) return '0';
    else return '0';

}

void printStack(struct stack* stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("|%d|- ",stack->array[i]);
    }
    
    
}

int main(int argc, char const *argv[])
{
    struct stack* stack_1=NULL;
    stack_1=createStack(4);
    pushStack(&stack_1,10);
    pushStack(&stack_1,20);
    pushStack(&stack_1,30);
    pushStack(&stack_1,40);
    increasingCapasity(&stack_1,8);

    pushStack(&stack_1,140);
    pushStack(&stack_1,220);
    pushStack(&stack_1,310);
    pushStack(&stack_1,420);

    
    //destroyStack(&stack_1);
    printStack(stack_1);
    printf("top element of stack :%d\n",topStack(stack_1));
    printf("is full:%c",isFull(stack_1));
   
    popStack(&stack_1);
    popStack(&stack_1);
    popStack(&stack_1);

    printf("\n");
    
    
    
    printStack(stack_1);
    printf("top element of stack :%d\n",topStack(stack_1));
    
    printf("is empty:%c",isEmpty(stack_1));
    printf("\nis full:%c",isFull(stack_1));
    printf("\n""");



    

    






    

    
    



    



    return 0;
}
