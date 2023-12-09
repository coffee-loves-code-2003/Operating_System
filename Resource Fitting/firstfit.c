#include<stdio.h>
#include<stdlib.h>
struct fit
{
    int mem_allocated;
    int mem_segment;
    float diagram;
    struct fit *next;
};
typedef struct fit *list;
void segment_allot(list head,int segment_allocation);
void firstfit(list head,int memory_allocation);
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
        printf("Enter the memory segment size for partition:%d:",i+1);
        scanf("%d",&segment_allocation);
        segment_allot(head,segment_allocation);
    }

    for(int i=0;i<limit1;i++)
    {
        printf("Enter the memory allocation for jobs :%d\n",i+1);
        scanf("%d",&memory_allocation);
        firstfit(head,memory_allocation);
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
temp=head;
int i,j;
while(temp->next!=NULL)
{
    for(i=0,j=0;i<temp->diagram,j<temp->mem_allocated;i++,j++)
    {
        printf("|---------|\n");
    }
    temp=temp->next;
}

}
void firstfit(list head,int memory_allocation)
{
list temp=head;
while(temp->next!=NULL)
{
    temp=temp->next;
    if(temp->mem_segment>=memory_allocation && temp->mem_allocated==0)
    {
        temp->mem_allocated=memory_allocation;
        break;
    }
}
}
void segment_allot(list head,int segment_allocation)
{
    list temp=head;
    list new=(list)malloc(sizeof(struct fit));
    new->next=NULL;
    new->mem_segment=segment_allocation;
    new->diagram=new->mem_segment%100;
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
