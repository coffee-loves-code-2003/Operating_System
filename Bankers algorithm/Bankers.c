#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int allocation[10];
    int maximum[10];
    int need[10];
    bool status;
    char name;
    struct node *next;
};
struct node *listarray[10];
typedef struct node *list;
int total_resources[10];
int num;
int num_1;
int flag=0;
void insert();
void display();
void need_matrix();
void deadlock_prevention();
void need_matrix_display();
void available();
int available_matrix[10];
int main()
{
    printf("Enter the number of process:\n");
scanf("%d",&num);
printf("Enter the number of instances:\n");
scanf("%d",&num_1);
for(int i=0;i<num_1;i++)
{
    printf("Enter the total resources:%d",i+1);
    scanf("%d",&total_resources[i]);
}
for(int i=0;i<num;i++)
{
    listarray[i]=NULL;
}
insert();
display();
need_matrix();
need_matrix_display();
available();
deadlock_prevention();
}
void insert()
{
for(int i=0;i<num;i++)
{
    list new=(list)malloc(sizeof(struct node));
    printf("Enter the process name:\n");
    scanf(" %c",&new->name);
    printf("For process:%d\n",i+1);
    for(int j=0;j<num_1;j++)  //for every single process I need to give input for Allocation and maximum for every single instances
    {
        printf("Enter the Allocation for instance:%d\n",j+1);
        scanf("%d",&new->allocation[j]);
        printf("Enter the Maximum for instance:%d\n",j+1);
        scanf("%d",&new->maximum[j]);
    }
    new->status=false; //Initially state is termed as false
    new->next=NULL;
    
    listarray[i]=new; //inserting into hash table
}
}
void display()
{
    printf("Allocation   Maximum\n");
            char n='A';
    for(int i=0;i<num_1;i++)
    {
        printf("%c  ",n++);
    }
        n='A';
    for(int i=0;i<num_1;i++)
    {
        printf("%c  ",n++);
    }
    printf("\n");
for(int i=0;i<num;i++)
{
    list temp=listarray[i];
    

    for(int j=0;j<num_1;j++)
    {
     printf("%d  ",temp->allocation[j]);
     
    }

       for(int j=0;j<num_1;j++)
    {
     
     printf("%d  ",temp->maximum[j]);
    }
    printf("\n");
}
}
void need_matrix()
{
    for(int i=0;i<num;i++)
    {
        list temp=listarray[i];
        for(int j=0;j<num_1;j++)
        {
            temp->need[j]=temp->maximum[j]-temp->allocation[j];  //For every single process Subtract Maximum with allocation
        }
    }
}
void need_matrix_display()
{
    printf("Need Matrix\n");
    char n='A';
    for(int i=0;i<num_1;i++)
    {
        printf("%c  ",n++);
    }
    printf("\n");
    for(int i=0;i<num;i++)
{
    list temp=listarray[i];
    for(int j=0;j<num_1;j++)
    {
     printf("%d  ",temp->need[j]);
     
    }

    printf("\n");
}
}
void available()
{
    int add;
    for(int i=0;i<num_1;i++)
    {
        add=0;
        for(int j=0;j<num;j++)
        {
           list temp=listarray[j];
           add=add+temp->allocation[i];
        }
        available_matrix[i]=total_resources[i]-add;
        printf("%d  ",available_matrix[i]);
    }
}
void deadlock_prevention()
{
    int i=0;
    int count=0;
    int status_value=0;
     printf("\nSafest Sequence:\n");
    while(status_value<num)  //Checking with every other process
    {
        if(i>=num)
        {
            i=0; //reseting the i if exceeds number of processes
        }
        list temp=listarray[i];
       
        if(temp->status==false)
        {
            
        for(int j=0;j<num_1;j++)
        {
    
          if(temp->need[j]<=available_matrix[j])
          {
            ++count;         //check when the available matrix is greater than or equal to need matrix of the particular process in every instances

          }
        }
        if(count==num_1) //if the count equals to number of instances it satisfies the available matrix
        {
        for(int j=0;j<num_1;j++)
        {
          available_matrix[j]=available_matrix[j]+temp->allocation[j]; //add the available matrix
        }
 
        temp->status=true; //change the state of process to true
        ++status_value;
        printf("%c  ",temp->name);

        }
        }
        count=0; ///reset the count
        ++i;
        
       
    }
    printf("\nAvailable Resources after Forming Safest Sequence:\n");
    for(int i=0;i<num_1;i++)
    {
        printf("%d  ",available_matrix[i]);
    }
}
