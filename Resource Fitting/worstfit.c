#include<stdio.h>
#include<stdlib.h>
struct fit
{
    int mem_allocated;
    int mem_segment;
    struct fit *next;
};
typedef struct fit *list;
void segment_allot(list head,int segment_allocation);
void worstfit(list head,int memory_allocation);
void print_memory_allocated(list head);
int main()
{
    int limit,limit1;
    printf("Enter the number of memory partitions:\n");
    scanf("%d",&limit);
    printf("Enter the number of jobs:\n");
    scanf("%d",&limit1);
    int segment_allocation;
    int memory_allocation;
    list head=(list)malloc(sizeof(struct fit));
    head->next=NULL;
    int free[3];
    for(int i=0;i<limit;i++)
    {
        printf("Enter the memory segment size for partition:%d",i+1);
        scanf("%d",&segment_allocation);
        segment_allot(head,segment_allocation);
    }

    for(int i=0;i<limit1;i++)
    {
        printf("Enter the memory allocation for jobs :%d\n",i+1);
        scanf("%d",&memory_allocation);
        worstfit(head,memory_allocation);
    }
     print_memory_allocated(head);

    }
void print_memory_allocated(list head)
{
list temp=head;
int wastage=0;
int free=0;
int total_free;
while(temp->next!=NULL)
{
    temp=temp->next;
    printf("Memory partitioned Size:%d",temp->mem_segment);
    printf("       Memory allocated:%d\n",temp->mem_allocated);
    if(temp->mem_allocated!=0)
    {
wastage=wastage+(temp->mem_segment-temp->mem_allocated);
    }
    
    if(temp->mem_allocated==0)
    {
        free=free+temp->mem_segment;
    }

}
total_free=wastage+free;
printf("Wastage:%d\n",wastage);
printf("Free:%d\n",free);
printf("Total Free:%d\n",total_free);
}
void worstfit(list head,int memory_allocation)
{
list temp=head;
int large=0;
list temp1;
while(temp->next!=NULL)
{
    temp=temp->next;
    if(temp->mem_segment-memory_allocation>=0 && temp->mem_allocated==0)
    {
       if(large<=temp->mem_segment-memory_allocation)
       {
        large=temp->mem_segment-memory_allocation;
       }
    }
}
temp1=head;
while(temp1->next!=NULL)
{
    temp1=temp1->next;
    if(large==temp1->mem_segment-memory_allocation)
    {
        temp1->mem_allocated=memory_allocation;
    }
}
}
void segment_allot(list head,int segment_allocation)
{
    list temp=head;
    list new=(list)malloc(sizeof(struct fit));
    new->next=NULL;
    new->mem_segment=segment_allocation;
    new->mem_allocated=0;
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
