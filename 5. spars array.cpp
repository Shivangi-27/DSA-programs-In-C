#include<stdio.h>
#include<conio.h>
int main()
{
// create sparse matrix
	int row,col,i,j,nz=0,k=0;
	int spr[30][30], mat[30][3];
	printf("enter no. of row and col- \n");
	scanf("%d %d",&row,&col);
	printf("enter %d elements- \n",(row*col));
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&spr[i][j]);
		}
		printf("\n");
	}
// display sparse matrix
	printf("elements are- \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",spr[i][j]);
		}
		printf("\n");
	}
// count no. of non zero element
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(spr[i][j]!=0)
			{
				nz++;
			}
		}
	}
// checking sparse matrix or not
	if(nz>(row*col)/2)
		{
			printf("sparse matrix is not possible");
			exit(0);
		}
// convert spr[i][j] to mat[k][3]
	mat[0][0]=row;		
	mat[0][1]=col;
	mat[0][2]=nz;	
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(spr[i][j]!=0)
				{
					k++;
					mat[k][0]=i;		
					mat[k][1]=j;
					mat[k][2]=spr[i][j];
				}
			}
		}
// display mat[k][3]
		printf("elements are \n");
		for(i=0;i<=nz;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d\t",mat[i][j]);
			}
			printf("\n");
		}
		return 0;
}
