#include <iostream>
#include "pthread.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>//#include <unistd.h>//Sleep(WINDOWS) vs sleep(LINUX)
using namespace std;
#define MAX 20
/* LINUX C�� jash_thread ��WINDOWS */
pthread_t thread[4];
pthread_mutex_t mut;
int number;
int i;
void *thread1(void *p)
{
	printf ("thread1 : I'm thread 1\n");
	for (i = 0; i < MAX; i++)
	{
		printf("thread1 : %d\n",i);
		pthread_mutex_lock(&mut);
			if(i<MAX)
			{
				number++;
				printf("thread1 : number = %d\n",number);
			}
		pthread_mutex_unlock(&mut);
		Sleep( 30 );//sleep(1);
	}
	printf("thread1 :�D��Ʀb���ڧ������ȶܡH\n");
	pthread_exit(NULL);
}
void *thread2(void *p)
{
	printf("thread2 : I'm thread 2\n");
	for (i = 0; i < MAX; i++)
	{
		printf("thread2 : %d\n",i);
		pthread_mutex_lock(&mut);
			if(i<MAX)
			{
				number++;
				printf("thread2 : number = %d\n",number);
			}
		pthread_mutex_unlock(&mut);
		Sleep( 30 );//sleep(1);
	}
	printf("thread2 :�D��Ʀb���ڧ������ȶܡH\n");
	pthread_exit(NULL);
}
void *thread3(void *p)
{
	printf("thread3 : I'm thread 3\n");
	for (i = 0; i < MAX; i++)
	{
		printf("thread3 : %d\n",i);
		pthread_mutex_lock(&mut);
			if(i<MAX)
			{
				number++;
				printf("thread3 : number = %d\n",number);
			}
		pthread_mutex_unlock(&mut);
		Sleep( 30 );//sleep(1);
	}
	printf("thread3 :�D��Ʀb���ڧ������ȶܡH\n");
	pthread_exit(NULL);
}
void *thread4(void *p)
{
	printf("thread4 : I'm thread 4\n");
	for (i = 0; i < MAX; i++)
	{
		printf("thread4 : %d\n",i);
		pthread_mutex_lock(&mut);
			if(i<MAX)
			{
				number++;
				printf("thread4 : number = %d\n",number);
			}
		pthread_mutex_unlock(&mut);
		Sleep( 30 );//sleep(1);
	}
	printf("thread4 :�D��Ʀb���ڧ������ȶܡH\n");
	pthread_exit(NULL);
}
void thread_create(void)
{
	int temp;
	memset(&thread, 0, sizeof(thread));          //comment1
	/*�Ыؽu�{*/
	if((temp = pthread_create(&thread[0], NULL, thread1, NULL)) != 0)       //comment2
	{
		printf("�u�{1�Ыإ���!\n");
	}
	else
	{
		printf("�u�{1�Q�Ы�\n");
	}
	if((temp = pthread_create(&thread[1], NULL, thread2, NULL)) != 0)  //comment3
	{
		printf("�u�{2�Ыإ���");
	}
	else
	{
		printf("�u�{2�Q�Ы�\n");
	}

	if((temp = pthread_create(&thread[2], NULL, thread3, NULL)) != 0)  //comment3
	{
		printf("�u�{3�Ыإ���");
	}
	else
	{
		printf("�u�{3�Q�Ы�\n");
	}
	if((temp = pthread_create(&thread[3], NULL, thread4, NULL)) != 0)  //comment3
	{
		printf("�u�{4�Ыإ���");
	}
	else
	{
		printf("�u�{4�Q�Ы�\n");
	}
}
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
void thread_wait(void)
{
	/*���ݽu�{����*/
	for(int i=0;i<4;i++)
	{
        pthread_join(thread[i],NULL);
        printf("�u�{%d�w�g����\n",i);
	}
}
int main()
{
		number=0;
		setlocale(LC_ALL,"Chinese_Taiwan.950");
        /*���q�{�ݩʪ�l�Ƥ�����*/
        pthread_mutex_init(&mut,NULL);
        printf("�ڬO�D��Ʈ@�A�ڥ��b�Ыؽu�{�A����\n");
        thread_create();
        printf("�ڬO�D��Ʈ@�A�ڥ��b���ݽu�{�������Ȫ��A����\n");
        thread_wait();
        Pause();
    return 0;
}
