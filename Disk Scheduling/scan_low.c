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
void high_scan(list head,int limit);
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
    
    printf("\n\nHigh to low:\n");
    high_scan(head,limit);
}
void high_scan(list head,int limit)
{
   list temp=head;
int count=0;
int higher=0;
int temp1;
list temp2;
int sum=0;
while(temp->next!=NULL)
{
    temp=temp->next;
    if(temp->data>current_cylinder_number1)
    {
     ++higher;
    }
}
int lowest_number=9999;
list small_diff_node;

while(count<higher)
{
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        
        if(temp->data>current_cylinder_number1)
        {
            temp1=abs(current_cylinder_number1-temp->data);

            if(lowest_number>temp1)
            {
             lowest_number=temp1;
             small_diff_node=temp;
            }
        }
    
    }
    printf("%d->",small_diff_node->data);
    temp2=small_diff_node->previous;  
           temp2->next=small_diff_node->next; 
        if(small_diff_node->next!=NULL)
        {
        small_diff_node->next->previous=temp2;
        }
    current_cylinder_number1=small_diff_node->data;
    sum=sum+lowest_number;
    lowest_number=9999;
            free(small_diff_node);

    ++count;
}
sum=sum+((max-1)-current_cylinder_number1);
current_cylinder_number1=max-1;
count=0;
lowest_number=9999;
limit=limit-higher;
while(count<limit)
{
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

            if(current_cylinder_number1>temp->data)
            {
                            temp1=abs(current_cylinder_number1-temp->data);

                if(lowest_number>temp1)
                {
                    lowest_number=temp1;
                    small_diff_node=temp;
                }
            }
        
    }
        printf("%d->",small_diff_node->data);
        temp2=small_diff_node->previous;  
           temp2->next=small_diff_node->next; 
        if(small_diff_node->next!=NULL)
        {
        small_diff_node->next->previous=temp2;
        }

        current_cylinder_number1=small_diff_node->data;
        sum=sum+lowest_number;
        lowest_number=9999;
                free(small_diff_node);

        ++count;
    
}
printf("\nTotal:%d",sum);

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

