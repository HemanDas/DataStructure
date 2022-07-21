#include<stdio.h>
#define maxQueue 5
struct queue
{
    int rear;
    int front;
    int item[maxQueue];
};typedef struct queue qt;
void createEmptyQueue(qt q[])
{
    q->rear=q->front=0;
}
void enqueue(qt q[],int x)
{
    if((q->front)==((q->rear+1)%maxQueue))
    {
        printf("The queue is full\n");
    }
    else
    {
        q->rear=(q->rear+1)%maxQueue;
        q->item[q->rear]=x;
    }
}
void dequeue(qt q[])
{
    int y=0;
    if(q->front==q->rear)
    {
        printf("The stack is empty\n");   
    }
    else
    {
        q->front=(q->front +1)%maxQueue;
        y=q->item[q->front];
    }
}
void traverse(qt q[])
{
    if(q->front==q->rear)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The element in the queue are:\n");
        int i=(q->front+1);
        do
       {    
            printf("%d\n",q->item[i]);
            i=(i+1)%maxQueue;
        }while(i!=((q->rear+1)%maxQueue));
    }
}
int main()
{
    int choice,x1,choose;
    qt q[maxQueue];
    createEmptyQueue(q);
    do
    {
        printf("Choose the operation to be performed:");
        printf("\n1)Insert\n2)Delete\n3)Display\n4)exit\n:");
        scanf("%d",&choice);
        switch(choice)
      {
        case 1: 
        printf("Enter the item to be pushed into the queue:");
        scanf("%d",&x1);
        enqueue(q,x1);
        break;
        case 2:
        dequeue(q);
        break;
        case 3:
        traverse(q);
        break;
        case 4:
        break;
        default:
        printf("Enter the valid option");
        break;
      }
      
    } while (choice!=4 );
    
}