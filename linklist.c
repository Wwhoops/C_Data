#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100
typedef int elemtype;
typedef struct node
{
 elemtype data;
 struct node *next;
}snode;

//初始化线性表
void init(snode *head)
{
 head->next=NULL;
 printf("³õÊ¼»¯Íê³É£¡\n");

}

//倒序创建线性表
void fcreat(snode *head)
{snode *p;
 int n,i;
 printf("ÇëÊäÈëÔªËØ¸öÊý£º");
 scanf("%d",&n);
 for (i=1;i<=n;i++)
 {
	  printf("ÇëÊäÈëµÚ%d¸öÔªËØµÄÖµ£º",i);
	 p=(snode*)malloc(sizeof(snode));
  scanf("%d",&p->data);
  p->next=head->next;
  head->next=p;
 }
}

//顺序创建线性表
void creat(snode *head)
{snode *p,*q;
 int n,i;
 q=head;
printf("ÇëÊäÈëÔªËØ¸öÊý£º");
 scanf("%d",&n);
 for (i=1;i<=n;i++)
 {p=(snode*)malloc(sizeof(snode));
  printf("ÇëÊäÈëµÚ%d¸öÔªËØµÄÖµ£º",i);
  scanf("%d",&p->data);
  p->next=NULL;
  q->next=p;
  q=p;
 }
}

//输出线性表
void output(snode *head)
{snode *p;
 printf("线性表的值为 :\n");
 p=head->next;
 while (p!=NULL)
 {printf("%d,",p->data);
  p=p->next;
 }
printf("\n");
}

//指定位置插入线性表
insert(snode *head,int i,elemtype x)
{snode *p,*s;
 int j=0;
 p=head;
 while (p!=NULL && j<i-1)
 { p=p->next;
   j++;
 }
printf("i=%d,j=%d\n",i,j);
if (p==NULL)
 {printf("²åÈëÎ»ÖÃ´íÎó£¬²åÈëÊ§°Ü£¡");
  return 0;
	}
 s=(snode*)malloc(sizeof(snode));
 s->data=x;
 s->next=p->next;
 p->next=s;
}

//删除指定位置
 del(snode *head ,int weizhi)
{snode *p,*q;
 int j=0;
 q=head;
 p=head->next;
 while(p!=NULL&&j<weizhi-1)
 {	 q=p;
	 p=p->next;
	 j=j+1;

 }
 printf("weizhi is %d xiabiao is  %d\n",weizhi,j);
if (p==NULL)
 {printf("É¾³ýÎ»ÖÃ´íÎó£¬É¾³ýÊ§°Ü£¡");
  return 0;
}
 q->next=p->next;
 free(p);

}

//获取指定位置的值
getnum(snode *head ,int i)
{
 snode *p;
 int j=0;
 p=head->next;
 while(p!=NULL&&j<i-1)
 {
  p=p->next;
  j++;
 }
  if(p==NULL||i<=0)
  {printf("\nÎ»ÖÃ´íÎó£¡£¡");
   return 0;
  }
  printf("\n%d Î»ÖÃµÄÖµÊÇ %d \n",i,p->data);
}

//获取值所在的位置
num(snode *head ,elemtype x)
{ int k=0,j[MAXSIZE]={0},flag=0,i=0;
  snode *p;
  p=head->next;
  while(p!=NULL)
  {  
	 if(p->data==x)
	 {j[i]=i+1; flag=1;}
	 i++;
	 p=p->next;
  }
  if(flag==0){printf("Ã»ÓÐ¸ÃÖµ\n"); return 0;}
  printf("Î»ÖÃÎª£º ");
  for(;k<i;k++)
  {  if(j[k]!=0)printf("  %d  ",j[k]);
  
 }
}

//主函数部分
void main()
{  elemtype x;
    int i,cse;
   snode *l;
   l=(snode*)malloc(sizeof(snode));
   init(l);
   while(1)
   {
      printf("\n你需要做什么:   0.顺序创建线性表  \n1. 倒序创建线性表 \n2.输出线性表 \n3.查找值在线性表的位置\n4.查找某位置的值\n5.从特定位置插入值\n6.删除特定位置\n7.初始化线性表(输入886结束):");
      scanf("%d",&cse);
      if(cse==886){free(l); exit(1);}
      switch(cse)
      {	 case 0: creat(l);  break;
	 case 1: fcreat(l);  break;
	 case 2: output(l);   break;
	 case 3:
		printf("请输入值:");
		scanf("%d",&x);
		num(l,x);  break;
	 case 4:
		printf("请输入位置:");
		scanf("%d",&i);
		getnum(l,i);   break;
	 case 5: 
		printf("请输入位置和值:");
		scanf("%d%d",&i,&x);
		insert(l,i,x);   break;
	 case 6:
		printf("请输入位置:");
		scanf("%d",&i);
		del(l,i);   break;
	case 7:
		free(l);
		l=(snode*)malloc(sizeof(snode));
		init(l);
		break;
	 default : printf("输入错误"); exit(1);
      }
   }
}
