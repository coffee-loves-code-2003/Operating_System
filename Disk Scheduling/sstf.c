#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
typedef struct node *list;
void insert(int number,list head);
void sstf(list head);
int current_cylinder_number;
int limit;
int main()
{
    list head=(list)malloc(sizeof(struct node));
    head->next=NULL;
    head->previous=NULL;
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
    sstf(head);
}
void sstf(list head)
{
    list temp;
    
    int sum=0;
    int count=0;
    int small=9999;
    int temp1;
    printf("Travelled path:\n");
    list small_diff_node;
    list temp2;
    while(count<limit)
    {
        temp=head;
        
        while(temp->next!=NULL)
        {
            
            temp=temp->next;
            temp1=abs(current_cylinder_number-temp->data);
            if(small>temp1)
            {
                
                small_diff_node=temp;
                small=temp1;
            }
                

        }
        printf("%d->",small_diff_node->data);
            temp2=small_diff_node->previous;  
           temp2->next=small_diff_node->next; 
        if(small_diff_node->next!=NULL)
        {
        small_diff_node->next->previous=temp2;
        }
        current_cylinder_number=small_diff_node->data;
        sum=sum+small;
        small=9999;
        ++count;
        free(small_diff_node);
    }
    printf("\nTotal:%d\n",sum);
}
void insert(int number,list head)
{
    list temp=head;
    list new=(list)malloc(sizeof(struct node));
    new->data=number;
    new->previous=NULL;
    new->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        new->next=temp->next;
        temp->next=new;
        new->previous=temp;
    }
}