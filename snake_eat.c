//main.c
//snake
//
//Created by Shaosen Hou on 2018/12/5
//Copyright(c) year 2018 Sun Yat-sen University.All rights reserved.
//


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define SNAKE_SPACE '-'
#define SNAKE_FOOD '*'

typedef struct{ //定义蛇头、蛇身的坐标
	int x;      
	int y;      
}elemtype;
typedef struct node_tag{    //节点及节点指针的初始化
	elemtype data;
	struct node_tag *next;
}NODE,*NODEPTR;
typedef struct{
	NODEPTR front,rear,current;     //队列的模型
}LKQUEUE;


void init(LKQUEUE *Q);      //队列的初始化
void destroy(LKQUEUE *Q);       //销毁队列
int ENQUEUE(LKQUEUE *Q,elemtype e);     //入队
int DEQUEUE(LKQUEUE *Q,elemtype * e);   //出队
int printmap(char map[10][10]);         //打印地图
int returnmap(char map[10][10],elemtype *m);  //恢复地图
int gameover(LKQUEUE *Q,elemtype q);        //游戏结束
void randomfood(char map[10][10],elemtype *m,LKQUEUE *Q);   //随机食物出现
int eatfood(LKQUEUE *Q,elemtype m,elemtype *q,char map[10][10]);    //吃食物(变长)

int main()
{	
	LKQUEUE Q;
    init(&Q);
	elemtype a,b,c,d,e,p,q,m;
	a.x=0;a.y=0;
	b.x=1;b.y=0;
	c.x=2;c.y=0;
	d.x=3;d.y=0;
	e.x=4;e.y=0;
	q.x=1;q.y=1;
	ENQUEUE(&Q,a);
	ENQUEUE(&Q,b);
	ENQUEUE(&Q,c);
	ENQUEUE(&Q,d);
	ENQUEUE(&Q,e);
	char map[10][10];
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			map[i][j]='-';
	map[a.y][a.x]='X';
	map[b.y][b.x]='X';
	map[c.y][c.x]='X';
	map[d.y][d.x]='X';
	map[e.y][e.x]='H';
	randomfood(map,&m,&Q);
	printmap(map);
	returnmap(map,&m);
	while(gameover(&Q,q))
	{
		char ch=getch();
		switch(ch)
		{	
			case 'w':
			case 'W':q.x=Q.rear->data.x;q.y=Q.rear->data.y-1;
					 break;
			case 's':
			case 'S':q.x=Q.rear->data.x;q.y=Q.rear->data.y+1;
					 break;
			case 'a':
			case 'A':q.x=Q.rear->data.x-1;q.y=Q.rear->data.y;
					 break;	
			case 'd':
			case 'D':q.x=Q.rear->data.x+1;q.y=Q.rear->data.y;
					 break;
		}
		if(eatfood(&Q,m,&q,map))
		{
			randomfood(map,&m,&Q);
			ENQUEUE(&Q,q);
		}
		else 
		{	DEQUEUE(&Q,&p);
			free(&p);
			ENQUEUE(&Q,q);
		}
		Q.current=Q.front;
		while(Q.current!=Q.rear)
		{
			map[Q.current->data.y][Q.current->data.x]='X';
			Q.current=Q.current->next;
		}
		map[Q.rear->data.y][Q.rear->data.x]='H';
		system("cls");
		printmap(map);
		returnmap(map,&m);
	}
	destroy(&Q);
	return 0;
}

void init(LKQUEUE *Q){
	Q->front=Q->rear=NULL;
	Q->current=Q->front;
}
void destroy(LKQUEUE *Q){
	NODEPTR p;
	while(Q->front!=NULL)
	{
		p=Q->front;
		Q->front=p->next;
		free(p);
	}
	Q->rear=NULL;
}
int ENQUEUE(LKQUEUE *Q,elemtype e){
	NODEPTR p;
	p=(NODEPTR)malloc(sizeof(NODE));
	if(p==NULL) return 0;
	p->data=e;
	p->next=NULL;
	if(Q->front==NULL) Q->front=Q->rear=p;
	else {
		Q->rear->next=p;
		Q->rear=p;
	}
	Q->current=Q->front;
	return 1;
}
int DEQUEUE(LKQUEUE *Q,elemtype * e){
	NODEPTR p;
	if(Q->front==NULL) return 0;
	p=Q->front;
	Q->front=p->next;
	if(Q->front==NULL) Q->rear=NULL;
	*e=p->data;
	free(p);
	Q->current=Q->front;
	return 1;
}
int printmap(char map[10][10]){
	for(int i=0;i<=9;i++)
		{for(int j=0;j<=9;j++)
			{printf("%c",map[i][j]);}
			printf("\n");}
}
int returnmap(char map[10][10],elemtype *m){
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			map[i][j]='-';
	map[(*m).y][(*m).x]='*';
}
int gameover(LKQUEUE *Q,elemtype q){
	if(q.x<0||q.x>9||q.y<0||q.y>9)
	{
		system("cls");
		printf("gameover");
		return 0;
	}
	Q->current=Q->front;
	while(Q->current->next!=Q->rear)
	{	
		if(Q->current->data.x==Q->rear->data.x&&Q->current->data.y==Q->rear->data.y)
		{
			system("cls");
			printf("gameover");
			return 0;
		}
		Q->current=Q->current->next;
	}
		return 1;
}
void randomfood(char map[10][10],elemtype *m,LKQUEUE *Q){
	(*m).x=rand()%10;
	(*m).y=rand()%10;
	int flag=2;
	while(flag)
	{
		Q->current=Q->front;
		while(Q->current!=Q->rear)
		{
			if(Q->current->data.x==(*m).x&&Q->current->data.y==(*m).y) 
			{
				flag=1;
				(*m).x=rand()%10;
				(*m).y=rand()%10;
				break;
			}
			Q->current=Q->current->next;
		}
		if(flag==2) break;
	}
	map[(*m).y][(*m).x]='*';
}
int eatfood(LKQUEUE *Q,elemtype m,elemtype *q,char map[10][10]){
	if((*q).x==m.x&&(*q).y==m.y)
	{	
		map[m.y][m.x]='-';
		return 1;
	}
	return 0;
}