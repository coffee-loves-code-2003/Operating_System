#include<stdio.h>
#include<stdlib.h>
int limit;
void insert(char c,int start,int length,char *a);
void display(char *a);
int main()
{
    int choice;
    int start,length;
    printf("Enter the size of the container:\n");
    scanf("%d",&limit);
    char c;
    char *a=(char*)calloc(limit+1,sizeof(char));
    for(int i=0;i<limit+1;i++)
    {
        a[i]=-1;
    }
    do
    {
        printf("1.Insert block:\n");
        printf("2.Display:\n");
        printf("3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the block name:\n");
                scanf(" %c",&c);
                printf("Enter the starting and ending of allocating size\n");
                scanf("%d %d",&start,&length);
                insert(c,start,length,a);
                break;
            }
            case 2:
            {
                display(a);
                break;
            }
        }
    }while(choice!=3);

}
void insert(char c,int start,int length,char *a)
{
    if(length<limit)
    {
    int flag=0;
for(int i=start;i<=length;i++)
{
    if(a[i]!=-1)
    {
      ++flag;
    }
    if(flag==abs(length-start))
    {
        printf("Allocation failed\n");
        return;
    }
}
    }
    else{
        printf("Insufficient Space\n");
        return;
    }
for(int i=start;i<length;i++)
        {
            a[i]=c;
        }
}
void display(char *a)
{
    printf("(------------------)\n");
    for(int i=0;i<=limit;i++)
    {
        printf("%c ",a[i]);
        if((i+1)%10==0)
        {
            printf("\n");
        }

    }
    printf("\n(-----------------)");
    printf("\n");
}