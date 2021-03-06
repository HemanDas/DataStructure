#include<stdio.h>
#include<conio.h>
#include<malloc.h> 
#include<process.h> 
struct node
{
int info; 
struct node *prev;
struct node *next;
};
typedef struct node NodeType;
NodeType *head; 
struct node *head = NULL;
void insert_atfirst(int); 
void insert_givenposition(int); 
void insert_atend(int); 
void delet_first(); 
void delet_last(); 
void delet_nthnode(); 
void info_sum(); 
void count_nodes(); 
void main()
{
int choice; int item;
do {
    printf("\nmenu for program:\n");
    printf("1)insert first \n2)insert at given position \n3)insert at last \n4)Delete first node\n5)delete last node\n6)delete nth node\n7)count nodes\n8)Display items\n9:exit\n");
    printf("enter your choice\n"); 
    scanf("%d",&choice); 
    switch(choice)
    {
    case 1:
    printf("Enter item to be inserted:");
    scanf("%d", &item);
    insert_atfirst(item);
    break;
    case 2:
    printf("Enter item to be inserted:");
    scanf("%d", &item);
    insert_givenposition(item); 
    break;
    case 3:
    printf("Enter item to be inserted:");
    scanf("%d", &item);
    insert_atend(item); 
    break;
    case 4:
    delet_first(); 
    break;
    case 5:
    delet_last(); 
    break;
    case 6:
    delet_nthnode(); 
    break;
    case 7:
    count_nodes(); 
    break;
    case 8:
    info_sum(); 
    break; 
    case 9:
    break;
    default:
    printf("invalid choice\n");
    break;
    }
}while(choice!=9);
 getch();
}

void insert_atfirst(int item)
{
    NodeType *newnode;
    newnode=(NodeType*)malloc(sizeof(NodeType));
    if (head == NULL)
    {
        newnode -> next = NULL;
        newnode -> prev = NULL;
        newnode -> info = item;
        head = newnode;
        return;

    }
    newnode->info=item;
    newnode->prev=newnode->next=NULL;
    newnode->next=head; 
    head->prev=newnode; 
    head=newnode;

}
void insert_givenposition(int item)
{
    NodeType *nnode; 
    NodeType *temp; 
    temp=head;
    int p,i;
    nnode=(NodeType*)malloc(sizeof(NodeType)); 
    nnode->info=item; 
    if (head==NULL)
    { 
    nnode->next=NULL;
    head=nnode;
    }
    else
    {
    printf("Enter Position of a node at which you want to insert an new node\n");
    scanf("%d",&p);
    for(i=1;i<p-1;i++)
    {
        temp=temp->next;
    }
    nnode->next=temp->next; 
    temp->next=nnode;
    nnode->prev=temp;
    }
}
void insert_atend(int item)
 {
    NodeType *nnode; 
    NodeType *temp; 
    temp=head;
    nnode=( NodeType *)malloc(sizeof(NodeType)); 
    nnode->info=item;
    if(head==NULL) 
    { 
    nnode->next=NULL; 
    head=nnode; 
    }
    else {
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    nnode->next=NULL; 
    temp->next=nnode;
    nnode->prev=temp;
    }
}
void delet_first()
{
    NodeType *temp; 
    if(head==NULL)
    {
    printf("Void deletion\n"); 
    return;
    }
    else { 
    temp=head; 
    head=head->next; 
    head->prev=NULL;
    free(temp);
    }
}
void delet_last()
{
    NodeType *hold,*temp; 
    if(head==NULL)
    {
    printf("Void deletion\n"); 
    return;
    } 
    else if(head->next==NULL) 
    {
    hold=head; head=NULL;
    free(hold);
    }
    else 
    { 
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    hold=temp->next; 
    temp->next=NULL;
    free(hold);
    }
}
void delet_nthnode()
{
    NodeType *hold,*temp;
    int pos, i;
    if(head==NULL)
    {
        printf("Void deletion\n");
        return;
    }
    else 
    { 
    temp=head;
    printf("Enter position of node which node is to be deleted\n");
    scanf("%d",&pos); 
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    hold=temp->next; 
    temp->next=hold->next;
    free(hold);
    }
}
void info_sum()
{
    NodeType *temp; 
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->info); 
        temp=temp->next;
    }
}
void count_nodes()
{ 
    int cnt=0;
    NodeType *temp;
    temp=head; 
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
 printf("total nodes=%d",cnt);
}
