#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include<sys/shm.h>
int *buf;
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void sem_wait(int sem_id) {
    struct sembuf obj;
    obj.sem_num = 0;
    obj.sem_op = -1;
    obj.sem_flg = 0;
    semop(sem_id, &obj, 1);
 *(buf+0)=0;
}

void sem_signal(int sem_id) {
    struct sembuf obj;
    obj.sem_num = 0;
    obj.sem_op = 1;
    obj.sem_flg = 0;
    semop(sem_id, &obj, 1);
*(buf+0)=1;
}

int main() {
    int sem_id;
    union semun sem_union;
    int sem_number=shmget(70,1024,IPC_CREAT|0666);
     buf=(int*)shmat(sem_number,NULL,0);
    sem_id = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    sem_union.val = 1;
    semctl(sem_id, 0, SETVAL, sem_union);
*(buf+0)=1;
    int i;
        int a = fork();
        if(a>0)
        {
         printf("Train 1 waiting in station...\n");
         sem_wait(sem_id);
         printf("Train 1 acquired track.....\n");
         sem_signal(sem_id);
         printf("Train 1 released track....\n");
         wait();
         printf("Train 1 exits the station....\n");
        }
        else if(a==0)
        {
            printf("Train 2 waiting in station...\n");
         sem_wait(sem_id);
         printf("Train 2 acquired track.....\n");
         sem_signal(sem_id);
         printf("Train 2 released track....\n");
         
         printf("Train 2 exits the station....\n");
        }
         else if (a < 0) {
            printf("fork creation error");
            exit(1);
        }
    


    return 0;
}