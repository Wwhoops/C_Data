#define max 100
#include<stdio.h>
typedef struct{
   int data[max][max];
   int m,n;
   }matrix;

typedef int spmatrix[max][3];

void init(matrix *l) /*初始化稀疏矩阵全置0 */
   {  
      int i,j;
      for(i=0;i<l->m;i++)
	 for(j=0;j<l->n;j++)
	    l->data[i][j]=0;
      printf("初始化完成\n");
   }

void compressmatrix(matrix a,spmatrix b) /* 将稀疏矩阵转换成其三元组表示*/
{
   int i,j,k=1;
   for(i=0;i<a.m;i++)
      for(j=0;j<a.n;j++)
	 if(a.data[i][j]!=0)
	  { b[k][0]=i;	   /*spmarix第一行第一列存稀疏矩阵有多少行，第二行存有多少列，第三行存有多少非0数 */
	    b[k][1]=j;
	    b[k][2]=a.data[i][j];
	    k++;
	  }
   b[0][0]=k-1;  
}

 void cmatrix(matrix *l) /*创建一个稀疏矩阵 */
 {
   int i,j,k,v,m,n;
   printf("\n非0元素和行列数--->行-列-非0数：  ");
   scanf("%d%d%d",&l->m,&l->n,&k);  
   init(l);
   for(i=0;i<k;i++)
   {
      printf("请输入第%d个元素--->行-列-值: ",i+1);
      scanf("%d%d%d",&m,&n,&v);
      l->data[m-1][n-1]=v;	 /*将行列对应的值存入矩阵中*/



   }
}

 void display(matrix *l)
 {
   int i,j;
   for(i=0;i<l->m;i++)
    {  for(j=0;j<l->n;j++)
	 printf("%d  ",l->data[i][j]);
      putchar('\n');
     } 
 }
 

void main()
{  matrix l;
   cmatrix(&l);
   display(&l);
   

}
