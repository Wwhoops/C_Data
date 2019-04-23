#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct{
   char ok[MAXSIZE];
   int top;
}base;


//栈的初始化
void init(base * stack)
{
   stack->top=0;
   printf("初始化完成\n");
}

//进制转换
void covert(base *l)
{
   int x,i,flag=2;
   while(1)
 { if(flag==1)break;
   printf("\n请输入十进制正整数:");
   scanf("%d",&x);
   printf("\n你需要转换成几进制:");
   scanf("%d",&i);
   if(i>9) appends(l, i, x);
    else  append(l,i,x);
   display(l);
   printf("任意数值继续，输入1结束:");
   scanf("%d",&flag);
  }
}

//进栈
void append(base *l,int i, int x)
{  int j=0,y;
   y=x;
   while(y)
   {
     l->ok[j++] =y%i+48;
    l->top++;
      y=y/i ;
   }
}

//大于10进制进栈
void appends(base *l,int i, int x)
{
   int j=0,y,k;
   y=x;
   while(y)
   {  k=y%i;
     if(k>9)
      l->ok[j++]=k-10+'A';
     else l->ok[j++]=k+48;
     l->top++;
      y=y/i;
   }
}

//出栈
void display(base *l)
{  
   while(l->top>0)
  {
  
  printf("%c",l->ok[l->top-1]);
  l->top=l->top-1;
  }
  putchar('\n');
}

//主函数
void main()
{
base *s;
int cse;
s=(base *)malloc(sizeof(base));
init(s);
covert(s);
}



 
