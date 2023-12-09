#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *list;
list allocate_page(int value,list changing_temp,list head,int count,int l,int arr[]);
void memory_allocation(list head,int frame);
    int frame;
int page_fault=0;
int limit;

int main()
{
    
    int count=0;
    printf("Enter the Page sequence limit:\n");
    scanf("%d",&limit);
    int arr[limit];
    printf("Enter the page sequence:\n");
    for(int i=0;i<limit;i++)
    {
        scanf("%d",&arr[i]);
    }
    int choice;
    
list head=(list)malloc(sizeof(struct node));
head->next=NULL;
list changing_temp;
    do
    {
        printf("1.Page replacement:\n");
        printf("2.Exit:\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
              printf("Enter the number of frames:\n");
              scanf("%d",&frame);
              memory_allocation(head,frame);
              changing_temp=head->next;
              list t;
              int flag=0;
              for(int i=0;i<limit;i++)
              {
                t=head;
                while(t->next!=NULL)
                {
                    t=t->next;
                    if(arr[i]==t->data)
                    {
                        ++flag;
                        break;
                    }
                    
                }
                if(flag==1)
                {
                    flag=0;
                    continue;
                }
                ++count;
              changing_temp=allocate_page(arr[i],changing_temp,head,count,i,arr);
                               if(count>=frame)
                 {
                    
                    count=0;
                 }

              }
            printf("Page faults:%d\n",page_fault);
        
            break;
            }
            case 2:
            {
                exit(0);
            }

    }
}while(choice!=0);
}
void memory_allocation(list head,int frames)
{
list temp;
while(frames>0)
{
    list new=(list)malloc(sizeof(struct node));
    new->next=NULL;
    new->data=-1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        new->next=temp->next;
        temp->next=new;
    }
    --frames;
}
}
list allocate_page(int value,list changing_temp,list head,int count,int l,int arr[])
{
    int index=0;
    int arr2[frame];
    int temp_v;
    for(int i=0;i<frame;i++)
    {
        arr2[i]=-1;
    }
    int sample=0;
    list temp2=head;
    if(l<frame)
    {
    changing_temp->data=value;
    list temp2=head;        
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
        if(temp2->data!=-1)
        {
           printf("%d ",temp2->data);

        }
    }
    ++page_fault;
    printf("\n");
    
        if(changing_temp->next!=NULL)
        {
        return changing_temp->next;
        }
    
    }
    else
    {

        list temp3=head;
        int large=0;
        int flag=0;

        int flag1=0;
        while(temp3->next!=NULL)
        {
            temp3=temp3->next;
            for(int i=l+1;i<limit;i++)
            {
               if(temp3->data==arr[i])
               {
                arr2[index]=i;
                ++flag1;
                break;//Here break statement is used to avoid taking the elements which are present later in the page sequence
               }
            }
            if(flag1==0)//replace when the frame element is not present in any of the upcoming sequence of pages
            {
               temp3->data=value;
                goto print;

            }
            ++index;
            flag1=0;
            
        }
        temp3=head;
        for(int i=0;i<frame;i++)
        {
            for(int j=i+1;j<frame;j++)
            {
                if(arr2[i]<arr2[j])
                {
                  temp_v=arr2[i];
                  arr2[i]=arr2[j];
                  arr2[j]=temp_v;
                }
            }
        }
        while(temp3->next!=NULL)
        {
            temp3=temp3->next;
            if(temp3->data==arr[arr2[0]])
            {
                temp3->data=value;
                goto print;
            }
        }


    
   print: if(sample==0)
            
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
        if(temp2->data!=-1)
        {
           printf("%d ",temp2->data);

        }
    }
    ++page_fault;
    printf("\n");
    
}
}
