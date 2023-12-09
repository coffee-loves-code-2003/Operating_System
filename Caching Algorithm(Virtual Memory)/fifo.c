#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *list;
list allocate_page(int value,list changing_temp,list head,int count);
void memory_allocation(list head,int frame);
    int frame;
int page_fault=0;
int main()
{
    int limit;
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
              for(int i=0;i<limit;i++) //starting from the page sequence 1 upto limit-1
              {
                t=head;
                while(t->next!=NULL)
                {
                    t=t->next;
                    if(arr[i]==t->data)   //Initially all the nodes are initialized with -1(It is used avoiding duplicate insertion of pages into the frames)
                    {
                        ++flag;
                        break;
                    }
                    
                }
                if(flag==1) //If there is any element already in the frame which is to be insert(duplicate)
                {
                    flag=0;   //reset the flag
                    continue; //Comtinue the loop(terminate the loop for index of that particular existing element in the frame)
                }
                ++count;
              changing_temp=allocate_page(arr[i],changing_temp,head,count);
                if(count>=frame)//For initialization of first node when count reaches the maximum number of frames
                 {
                    
                    count=0; //reset count=0
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
void memory_allocation(list head,int frames) //allocate number of frames with the help of linked list
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
list allocate_page(int value,list changing_temp,list head,int count)
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
    
    if(count>=frame) //if count result greater than or equal to frame change the changing_node to head->next node
    {
      changing_temp=head->next;
      return changing_temp;
    }
    else
    {
        if(changing_temp->next!=NULL) // if not proceed with next node
        {
        return changing_temp->next;
        }
    }
    
}
