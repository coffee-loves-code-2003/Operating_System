#include<stdio.h>
#include<stdlib.h>
struct node
{
    char P_name[20];
    int arrival;
    int burst;
    int temp_burst;
    struct node *previous;
    struct node *next;
};
typedef struct node *list;
void insert(list head);
void calculate(list temp);
int main()
{
    list head=(list)malloc(sizeof(struct node));
    head->previous=NULL;
    head->next=NULL;
    int limit;
    printf("Enter the number of processes to be proceed:\n");
    scanf("%d",&limit);
    int i;
    for(i=0;i<limit;i++)
    {
        insert(head);
    }
    for(i=0;i<limit;i++)
    {
        calculate(head);
    }
}
void insert(list head)
{
    list t=head;
    list temp=(list)malloc(sizeof(struct node));
    printf("Enter the process name:\n");
    scanf("%s",temp->P_name);
    printf("Enter the arrival time:\n");
    scanf("%d",&temp->arrival);
    printf("Enter the burst time:\n");
    scanf("%d",&temp->burst);
    while(t->next!=NULL)
    {
       t=t->next;
    }
    if(t->next==NULL)
    {
        temp->next=t->next;
        t->next=temp;
    }
    

}
void calculate(list head)
{
    list t=head;
    int temp1;
    temp1=temp->arrival-temp->previous->arrival;
    if(temp->arrival!=0 && temp1<temp->previous->burst)
    {
        
        temp->previous->temp_burst=temp->previous->burst-temp1;
        printf("%d\n",&temp->previous->burst);
        return;
    }
    else
    {
        temp->previous->temp_burst=0;
        return;
    }

}