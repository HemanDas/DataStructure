#include<stdio.h>
#define MAX 5
int cqueue[MAX];
int front=-1,rear=-1,item,i=0;
void emqueue(){
    if ((front==0 && rear== MAX-1)||(front==rear+1)){printf("Queue iverflown");}
    if (front==-1){
        front=0;
        rear=0;
    }
    else{
        if(rear==MAX-1){rear=0;}
        else{rear=rear+1;}
    }
    cqueue[rear]=item;
}
void dequeue(){
    if (front ==  - 1)
    {
        printf("Queue is empty ");
    }
    else if (front == rear)
    {
        printf("\n %d deleted", cqueue[front]);
        front =  - 1;
        rear =  - 1;
    }
    else
    {
        printf("\n %d deleted", cqueue[front]);
        front++;
    }
}
void display(){
    printf("\n");
    if (front > rear)
    {
        for (i = front; i < MAX; i++)
        {
            printf("%d ", cqueue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
}