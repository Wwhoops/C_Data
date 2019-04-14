#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int datatype;
typedef struct{
   datatype a[MAXSIZE];
   int size;
}sequence_list;

//初始化顺序表---置空
void init(sequence_list *slt)
{
   slt->size=0;
   printf("---初始化完成\n");
}

//顺序表后部进行插入操作
void append(sequence_list *slt)
{  datatype x;
   while(1)
   {
      if(slt->size==MAXSIZE)
	{ printf("顺序表是满的！\n"); exit(1); }
      printf("请输入数据:(输入886结束)\n");
      scanf("%d",&x);
      if(x==886)break;
      slt->a[slt->size]=x;   
      slt->size=slt->size+1;
   }
}

//查找循序值X在节点的位置
void find(sequence_list *slt)
{  int i=0;
   datatype x;
   printf("请输入数值:");
   scanf("%d",&x);
   while(i<slt->size&&slt->a[i]!=x)i++;
   if(i>=slt->size){printf("no find!\n");exit(1);}
   printf("%d 是表的第 %d 个元素\n",x,i+1);
}

//取得顺序表第i个位置的值
void get(sequence_list *slt)
{
   int i;
   printf("请输入查询位置(从1开始):");
   scanf("%d",&i);
   if(i<=0||i>slt->size)
      {printf("节点不存在！\n"); exit(1);}
   printf("%d 位置的值为 %d \n",i,slt->a[i-1]);
}

//从特定位置插入数据
void insert(sequence_list *slt)
{  int i;
   int j;
   datatype x;
   printf("请输入要插入的位置和值");
   scanf("%d%d",&i,&x);
   if(slt->size==MAXSIZE){printf("表是满的\n！");}
   else if(i<=0||i>slt->size+1)
      {
	 printf("插入位置错误\n"); 
      }
      else 
	 {
	    for(j=slt->size;j>=i-1;j--)slt->a[j]=slt->a[j-1];
	    slt->a[i-1]=x;
	    slt->size++;
	 }
   
}

//从特定位置
void del(sequence_list *slt)
{  int i;
   printf("请输入要删除的位置");
   scanf("%d",&i);
   if(i<=0||i>slt->size)
      {
	 printf("删除位置错误\n"); 
      }
      else 
	 {
	    for(i=i-1;i<slt->size;i++)slt->a[i]=slt->a[i+1];
	    slt->size--;
	 }
}

//打印循序表的值
void display(sequence_list *slt)
{  int i;
   if(slt->size==0)
      {printf("顺序表是空的！\n");free(slt); exit(1);}
   for(i=0;i<slt->size;i++)
      {
	 printf("%d  ",slt->a[i]);
      }
   printf("\n");
   
}

//主函数部分
void main()
{  datatype x;
   int cse ;
   sequence_list *l;
   l=(sequence_list *)malloc(sizeof(sequence_list));
   init(l);
   while(1)
   {
      printf("\n你需要做什么:\n0.初始化顺序表 \n1.从尾部插入数据 \n2.打印数据\n3.查找值在表的位置\n4.查找某位置的值\n5.从特定位置插入值\n6.删除特定位置\n(输入886结束):");
      scanf("%d",&cse);
      if(cse==886){free(l); exit(1);}
      switch(cse)
      {	 case 0: init(l);  break;
	 case 1: append(l);  break;
	 case 2: display(l);   break;
	 case 3: find(l);  break;
	 case 4: get(l);   break;
	 case 5: insert(l);   break;
	 case 6: del(l);   break;
	 default : printf("输入错误"); exit(1);
      }
   }
}
