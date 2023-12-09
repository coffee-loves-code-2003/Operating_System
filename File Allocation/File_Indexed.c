#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *listarray1[100];
struct node *listarray[100];
typedef struct node *list;
int index1=0;
    int size_of_the_table;
    int size_of_the_cylinder;
void insert(int num);
void display();
int main()
{
    int num;
    int choice;
    int overhead;
    printf("Enter the size of the cylinder:\n");
    scanf("%d",&size_of_the_cylinder);
    for(int i=0;i<size_of_the_cylinder;i++)
    {
        listarray1[i]=NULL;
    }
    printf("Enter the Index-Overhead Block\n");
    scanf("%d",&overhead);
    listarray1[overhead]=100;
    for(int i=0;i<size_of_the_cylinder;i++)
    {
        if(listarray1[i]==NULL)
        {
            printf("%d\n",listarray1[i]);
            printf("-------NULL------\n");
        }
        else
        {            printf("%d\n",listarray1[i]);

            printf("-----Occupied----\n");

        }
    }
    printf("Enter the size of the Index-Containing Block:\n");
    scanf("%d",&size_of_the_table);
    int i;
    for(i=0;i<size_of_the_table;i++)
    {
        listarray[i]=NULL;
    }
    
    do
    {
        printf("1.Insert a block\n");
        printf("2.Display\n");
        printf("3.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the block number:\n");
                scanf("%d",&num);
                insert(num);
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                exit(0);
            }
        }
    }while(choice!=0);
}
void insert(int num)
{
    list new=(list)malloc(sizeof(struct node));

    new->data=num;
    new->next=NULL;
    if(listarray[index1]==NULL)
    {
      listarray[index1]=new;
      ++index1;
    }
    
}
void display()
{
    int i;
    printf("%d\n",listarray);
    printf("Block numbers:\n");
    printf("--------------------\n");
    for(i=0;i<size_of_the_table;i++)
    {

        list temp=listarray[i];
        if(temp==NULL)
        {
            printf("|--------NULL--------|");
        }
        else{
        printf("|---------%d---------|",temp->data);
        }
        printf("\n");
    }
}