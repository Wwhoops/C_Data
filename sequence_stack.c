#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int datatype;
typedef struct{
   datatype a[MAXSIZE];
   int top;
}sequence_stack;

//初始化顺序表---置空
void init(sequence_stack *st)
{
   st->top=0;
   printf("---初始化完成\n");
}

//栈（顺序存储）的插入操作
void push(sequence_stack *st)
{  datatype x;                                                                                 
   while(1)
   {
      if(st->top==MAXSIZE)
	{ printf("栈是满的！\n"); exit(1); }
      printf("请输入数据:(输入886结束)\n");
      scanf("%d",&x);
      if(x==886)break;
      st->a[st->top]=x;   
      st->top++;
   }
}


//删除操作
void pop(sequence_stack *st)
{
    if(st->top==0)
	{printf("栈是空的empty\n！"); exit(1);}
    st->top--;

}

//取得栈顶元素
void read(sequence_stack *st)
 { if(st->top==0)
      {printf("栈是空的empty！\n"); exit(1);}
     printf("%d  \n",st->a[st->top-1]);
 }
   


//主函数部分
void main()
{  datatype x;
   int cse ;
   sequence_stack *l;
   l=(sequence_stack *)malloc(sizeof(sequence_stack));
   init(l);
   while(1)
   {
      printf("\n你需要做什么:\n0.初始化栈 \n1.插入操作\n2.取出栈顶元素\n3.删除操作\n(输入886结束):");
      scanf("%d",&cse);
      if(cse==886){free(l); exit(1);}
      switch(cse)
      {	 case 0: init(l);  break;
	 case 1: push(l);  break;
	 case 2: read(l);   break;
	 case 3: pop(l);  break;
	 default : printf("输入错误"); exit(1);
      }
   }
}
