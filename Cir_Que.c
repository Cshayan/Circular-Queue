#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;
void insert(int val)
{
    if((front==0&&rear==MAX-1)&&(front==rear+1))
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=rear=0;
    }
    else if(rear==MAX-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=val;
    printf("\nValue Inserted\n");

}
int del()
{
    if(front==-1)
    {
        printf("\nQueue Underflow\n");
        return (-1);
    }
    int val=queue[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==MAX-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
    return val;
}
void display()
{
    if(front==-1&&rear==-1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    if(front<rear)
    {
        int i;
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    else
    {
        int i;
        for(i=front;i<=MAX-1;i++)
        {
            printf("%d\t",queue[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}
int main()
{
    int val,ch;
    while(1)
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the value to insert:- ");
            scanf("%d",&val);
            insert(val);
            break;
        case 2:
            val=del();
            if(val!=-1)
            {
                printf("The deleted value is:- %d",val);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}
