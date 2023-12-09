#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
    int data;
    bool state;
    struct node *next;
};
typedef struct node *list;
void insert(int number,list head);
void fcfs(list head);
int current_cylinder_number;
int main()
{
    list head=(list)malloc(sizeof(struct node));
    head->next=NULL;
    int limit;
    printf("Enter the number of cylinders to be get triggered:\n");
    scanf("%d",&limit);
    int number;
    printf("Enter the Cylinder numbers:\n");
    for(int i=0;i<limit;i++)
    {
        scanf("%d",&number);
        insert(number,head);
    }
    printf("Enter the currently holding cylinder number:\n");
    scanf("%d",&current_cylinder_number);
    fcfs(head);
}
void fcfs(list head)
{
    list temp=head;
    int sum=0;
    printf("Travelled path:\n");
    list temp1=head;
    while(temp->next!=NULL)
    {
        
        temp=temp->next;
        printf("%d->",temp->data);
        sum=sum+abs(current_cylinder_number-temp->data);
        current_cylinder_number=temp->data;
        temp1->next=temp->next;
        free(temp);
        
        
    }
    printf("Total:%d\n",sum);
}
void insert(int number,list head)
{
    list temp=head;
    list new=(list)malloc(sizeof(struct node));
    new->data=number;
    new->state=false;
    new->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        new->next=temp->next;
        temp->next=new;
    }
}
