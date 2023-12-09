#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *previous;
    struct node *next;
};
typedef struct node *list;
void insert(int number,list head);
void low_scan(list head,int limit);
int current_cylinder_number;
int current_cylinder_number1;

int max;
int main()
{
    int limit;
    list head=(list)malloc(sizeof(struct node));
    head->next=NULL;
    printf("Enter the maximum limit of the cylinder number:\n");
    scanf("%d",&max);
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
    current_cylinder_number1=current_cylinder_number;
    printf("Low to High:\n");
    low_scan(head,limit);

}

void insert(int number,list head)
{
    list temp=head;
    list new=(list)malloc(sizeof(struct node));
    new->data=number;
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
void low_scan(list head,int limit)
{
list temp1=head;
int count=0;
int lower=0;
int temp2;
int sum=0;
list temp3;
while(temp1->next!=NULL)
{
    temp1=temp1->next;
    if(temp1->data<current_cylinder_number)
    {
     ++lower;
    }
}
int lowest_number=9999;
list small_diff_node;

while(count<lower)
{
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
        
        if(temp1->data<current_cylinder_number)
        {
            temp2=abs(current_cylinder_number-temp1->data);

            if(lowest_number>temp2)
            {
             lowest_number=temp2;
             small_diff_node=temp1;
            }
        }
    
    }
    printf("%d->",small_diff_node->data);
    temp3=small_diff_node->previous;  
           temp3->next=small_diff_node->next; 
        if(small_diff_node->next!=NULL)
        {
        small_diff_node->next->previous=temp3;
        }
    current_cylinder_number=small_diff_node->data;
    sum=sum+lowest_number;
    lowest_number=9999;
    ++count;
}
sum=sum+current_cylinder_number;
count=0;
lowest_number=9999;
limit=limit-lower;
current_cylinder_number=0;
while(count<limit)
{
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    
            if(current_cylinder_number<temp1->data)
            {
                            temp2=abs(current_cylinder_number-temp1->data);

                if(lowest_number>temp2)
                {
                    lowest_number=temp2;
                    small_diff_node=temp1;
                }
            }
        
    }
        printf("%d->",small_diff_node->data);
        temp3=small_diff_node->previous;  
           temp3->next=small_diff_node->next; 
        if(small_diff_node->next!=NULL)
        {
        small_diff_node->next->previous=temp3;
        }
        current_cylinder_number=small_diff_node->data;
        sum=sum+lowest_number;
        lowest_number=9999;
        ++count;
                free(small_diff_node);

    
}
printf("\nTotal:%d",sum);

}
