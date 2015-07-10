#include<stdio.h>
typedef struct stack stack;
struct stack //defined a structure which accounts for a node.
{
    int value;
    stack *previous;
};
stack *top=NULL;
stack *copy;

void push(int);
int main()
{
    int n,flag=0,out,value,errorCode=0;
    while(flag==0)
    {
        printf("\n\n\n--------------------------STACK--------------------------");
        printf("\n\n1.------------->Push in stack.");
        printf("\n\n2.------------->Pop out of stock.");
        printf("\n\n3.------------->Display stack.");
        printf("\n\n0.------------->Exit.");
        printf("\n\n-----------------------------------------------------------");
        printf("\n\n                      Input:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("\n\nPlease enter the value to be pushed:");
            scanf("%d",&value);
            push(value);
            printf("\n\tpushed successfully");
            break;
        case 2:
            pop(&errorCode);
            if(errorCode==-1)
            {
                errorCode=0;
                printf("\n\nSorry! stack is already empty,first insert some elements in stack.");
            }
            else
            {
                printf("\n\n\t is the Poped out element");
            }
            break;
        case 3:
            display(&errorCode);
            if(errorCode==-1)
            {
                errorCode=0;
                printf("\n\nSorry! stack is already empty,first insert some elements in stack.");
            }
            break;
        case 0:
            flag=1;
            break;
        default:
            printf("\n\n\tWrong input!Try again.");
        }
        getch();
    }
    printf("\n\n\n\n\t\t\t\tThanks!");

    return 0;
}
void push(int value)
{

    if(top==NULL)
    {
        top=(stack *)malloc(sizeof(stack));
        top->value=value;
        top->previous=NULL;
    }
    else
    {
        stack *another;
        copy=top;
        another=(stack *)malloc(sizeof(stack));
        another->value=value;
        another->previous=copy;
        top=another;
    }

}
void pop(int *error)
{
    int ele;
    if(top==NULL)
    {
        error -1;
    }
    else
    {
        ele=top->value;
        top=top->previous;
        printf("%d",ele);
    }
}
void display(int *error)
{
    int flag=0;
    while(top!=NULL)
    {
        flag=1;
        printf("\n\n%d",top->value);
        top=top->previous;
    }
    if(flag==0)
    {
        error= -1;
    }
}

