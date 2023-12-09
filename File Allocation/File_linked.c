#include<stdio.h>
#include<stdlib.h>
struct file
{
char block;
struct node *next;
};
typedef struct file *list;
void display(list head);
void insert(char block,list head);
int main()
{
    list head=(list)malloc(sizeof(struct file));
    head->next=NULL;
    char block;
    int choice;
    do
    {
        printf("1.Insert blocks:\n");
    printf("2.Display:\n");
    printf("3.Exit:\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter the block name:");
            scanf(" %c",&block);
            insert(block,head);
            break;
        }
        case 2:
        {
            display(head);
            break;
        }
    }
    } while (choice!=3);
    
    
}
void insert(char block,list head)
{
    list temp=head;
    list new=(list)malloc(sizeof(struct file));
    new->block=block;
    new->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        temp->next=new;
    }
}
void display(list head)
{
    list temp=head;
    printf("Allocated blocks:\n");
    int flag=0;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        if(flag==0)
        {
        printf("|%c|",temp->block);
        }
        else
        {
                    printf(" <-|%c|",temp->block);

        }
        ++flag;

    }
    printf("\n");
}