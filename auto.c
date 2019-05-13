#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAX 100

typedef struct tn{   //二叉树的结构
char data;    //数据
struct tn *lchild;   //左孩子
struct tn *rchild;   //右孩子
}TreeNode;


TreeNode*  create_bitree(TreeNode *r) //创建二叉树返回根节点

{
   TreeNode *p[MAX+1],*s;
   int j,i,k;
   char ch='A';
   printf("请输入深度:  ");
   scanf("%d",&i);   
  for(j=1;j<=(1<<i)-1;j++)
  {
  s=(TreeNode*)malloc(sizeof(TreeNode));
  s->data=ch;
  s->lchild=s->rchild=NULL;
  ch=ch+1;
  if(ch=='Z'+1)ch='A';
  p[j]=s;      //存放树的节点为后面存放左右孩子能找到父节点
  if(j==1)r=s; //第一个为根节点
  else
   {  k=j/2;
      if(j%2==0)p[k]->lchild=s;  //偶数则是左孩子
      else p[k]->rchild=s;	 //奇数为右孩子
   }
  
  }
  return r;

}


int deep(TreeNode *r) //层次遍历法求二叉树的深度
{
   TreeNode *s[MAX],*t[MAX],*p;//创建2个栈
   int top=0,deep=0,count=0,next=1,i=0; 
   if(r==NULL) return;
   p=r;
   s[0]= t[0]=p;

  while(next)
   {
   count++;
   if(t[top]->lchild!=NULL){s[i]=t[top]->lchild; i++;}
   if(t[top]->rchild!=NULL){s[i]=t[top]->rchild; i++;}
   if(count==next)
   {
   cover(t,s,i);
   next=i;
   top=i=count=0;
   deep++;
   }
   else top++;
   }
   return deep;
}


void show(TreeNode *r ,int deep)//输出完整2叉树
{
   TreeNode *s[MAX],*t[MAX],*p;//创建2个栈,和一个指向根节点的指针
   int top=0,i=0,j,k,d,v=0; //top用来出栈,i用来记录当前在第几层，j存放j层有多少个结点， K用来控制空格输出,d保存树的深度,v用来寄存将要入栈的结点位置
   p=r;	 
   d=deep;
   if(r==NULL) return;
   s[0]= t[0]=p; //开始第一个位置存放根
   for(i=0;i<deep;i++)
   {   top=v=0;
      for(j=0;j<1<<i;j++)
      {
	 for(k=0;k<(1<<d)-1;k++)
	    printf(" ");   
	 if(t[top]==NULL) printf("#");
	 else printf("%c",t[top]->data);

	 for(k=0;k<(1<<d)-1;k++)
	    printf(" ");

	 printf(" ");
        if(t[top]==NULL){s[v++]=NULL;s[v++]=NULL;}
	else{
	if(t[top]->lchild!=NULL){s[v]=t[top]->lchild; v++;} else {s[v]=NULL;v++;}
        if(t[top]->rchild!=NULL){s[v]=t[top]->rchild; v++;} else {s[v]=NULL;v++;}
	}
        top++;
      }
   cover(t,s,v); 
   printf("\n");
   d--;
   }
   
  putchar('\n');
}

void cover(TreeNode *a,TreeNode *b,int k) //覆盖栈
{
 int i;
 for(i=0;i<k;i++)
   {
   a[i]=b[i];
   }
}



void first(TreeNode *r) //先序遍历
{
   TreeNode *p,*s[MAX];
   int top=0;
   p=r;
   printf("\n先序遍历: ");
   if(r==NULL) return;
   while(top>0||p!=NULL)
   {  if(p!=NULL)
      {	 
	 printf(" %c",p->data);
	 s[top]=p;
	 p=p->lchild;
	 top++;
      }
      else { top--; p=s[top]->rchild;}

   } 

  putchar('\n');
}


void inorder(TreeNode *r) //中序遍历
{
   TreeNode *p,*s[MAX];
   int top=0;
   p=r;
   printf("\n中序遍历: ");
   if(r==NULL) return;
   while(top>0||p!=NULL)
   {
      if(p!=NULL)
      {
      s[top]=p;
      p=p->lchild;
      top++;
      }
      else 
      {
      top--;
      p=s[top];
      printf(" %c",p->data);
      p=p->rchild;
      }
   
   }

  putchar('\n');
}



void last(TreeNode *r)  //后序遍历
{
   TreeNode *p,*s[MAX]={NULL};
   int top=1;
   p=r;
   s[top++]=p;
   s[top]=p;
   printf("\n后序遍历: ");
   if(r==NULL) return;
   while(top>0)
   {
    p=s[top];
    top--;
    if(p==s[top])
    { 
      if(p->rchild){top++;s[top++]=p->rchild;s[top]=p->rchild;}
      if(p->lchild){top++;s[top++]=p->lchild;s[top]=p->lchild;}
    }
    else printf(" %c",p->data);
    }
  putchar('\n');
}



void layer(TreeNode *r)  //层次遍历
{
 TreeNode *p,*s[MAX]={NULL},*t[MAX];
 int top=0,v=0,next=1,c=0;
 t[top]=r;
 printf("\n层次遍历: ");
 if(r==NULL) return;
 while(next)
 {
    c++;
    p=t[top];
    printf(" %c",p->data);
    if(p->lchild)s[v++]=p->lchild;
    if(p->rchild)s[v++]=p->rchild;
    if(c==next)
       {
       next=v;
       cover(t,s,v);
       top=c=v=0;
	 
       }
    else top++;
 }

  putchar('\n');

}

void delete(TreeNode **r)
{
   TreeNode **p,**t[MAX]={NULL};
   int top=1;
   p=r;
   t[top++]=p;
   t[top]=p;
   while(top>0)
   {
    p=t[top--];
    if(p==t[top])
    {
      if((*p)->rchild){top++;t[top++]=&((*p)->rchild);t[top]=&((*p)->rchild);}
      if((*p)->lchild){top++;t[top++]=&((*p)->lchild);t[top]=&((*p)->lchild);}
    }
    else {free(*p); *p=NULL;}
   }
   printf("\n二叉树已摧毁！\n\n");
}

void main()
{  int d;
   TreeNode *root;
  root=create_bitree(root); //创建二叉树
  d=deep(root);  //求深度
  printf("--------------------------------------------------------------------------------------------------------------------------------\n");
  show(root,d);  //展示二叉树
  printf("--------------------------------------------------------------------------------------------------------------------------------");
  printf("\n生成二叉树的深度为:  %d\n",d);
  first(root);  //先序遍历
  inorder(root);     //中序遍历
  last(root);	  //后续遍历
  layer(root);	  //层次遍历
  delete(&root);  //摧毁树
}






