#define max 20
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
	  { b[k][0]=i;	   /*将非0元素的行列存入三元组中--> 行-列-非0值*/
	    b[k][1]=j;
	    b[k][2]=a.data[i][j];
	    k++;
	  }
   b[0][0]=a.m;
   b[0][1]=a.n;
   b[0][2]=k-1;
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


 void transposition(spmatrix b) /*三元组快速转置*/
 { 
   spmatrix a={0},c={0};
   int i=1,j=2;
   while(i<=b[0][2])  /*统计原三元组某列值得个数存放到转置后行内元素个数*/
   {
	 c[(b[i][1])+1][0]++;
	 i++;
      }
   c[1][1]=1;  /*第一列放在第一行*/
   while(j<=b[0][1])	  /*求出每行的起始位置*/
      {
	 c[j][1]=c[j-1][0]+c[j-1][1];
	 j++;
      }
   for(i=1;i<=b[0][2];i++) 
      {
	 a[c[(b[i][1])+1][1]][0]=b[i][1]; /*从原三元组第二行开始扫描，+1是为了列在原表是0开始  转换成行后得从1 开始 */
	 a[c[(b[i][1])+1][1]][1]=b[i][0];
	 a[c[(b[i][1])+1][1]][2]=b[i][2];
	 c[(b[i][1]+1)][1]++; /*扫描出一个元素+1得到这行的下一个元素开始地址 */
      }
   a[0][0]=b[0][1]; /*第一行的值行列互换*/
   a[0][1]=b[0][0];
   a[0][2]=b[0][2];
   printf("转置后");
   show(a);

   
 }

 void display(matrix *l) /*输出稀疏矩阵*/
 {
   int i,j;
   printf("创建的稀疏矩阵为\n");
   for(i=0;i<l->m;i++)
    {  for(j=0;j<l->n;j++)
	 printf("%d  ",l->data[i][j]);
      putchar('\n');
     } 
 }
 

void show(spmatrix b)  /*输出三元组*/
{
   int i,j;
   printf("产生的三元组为\n");
   for(i=0;i<=b[0][2];i++)
   {  for(j=0;j<3;j++)
	 printf("%d  ",b[i][j]);
      putchar('\n');
   }
}


void main()
{  matrix l;
   spmatrix b;
   cmatrix(&l);
   display(&l);
   compressmatrix(l,b);
   show(b);
   transposition(b);

}
