#include <stdio.h>
#include <stdlib.h>
#define MAX_V	20
int	Real_V;
int COST[MAX_V][MAX_V];
int A[MAX_V][MAX_V];
int P[MAX_V][MAX_V];

void Floyd(void);
void SearchPath();
void ReadWeightedAM(void); // Read Weighted Adjacency Matrix from file Floyd.dat
void showDMatrix();

int main(void)
{
    ReadWeightedAM();
	Floyd();
    SearchPath();
    return 0;
}

void ReadWeightedAM(void)
{	int	i,j;
	FILE	*fin;
	if ((fin=fopen("Floyd.dat","r")) == NULL)
	{
		printf("Floyd.dat Not Found !");
		exit(1);
	}
	fscanf(fin,"%d",&Real_V);
	for (i=0; i<Real_V; i++)
		for (j=0; j<Real_V;j++)
			fscanf(fin,"%d",&COST[i][j]);
	fclose(fin);
}

void Floyd(void)
{
    int i,j,k;
    for(i=0;i <Real_V;i++)
		for(j=0;j < Real_V;j++)
		{
			A[i][j]=COST[i][j];
			P[i][j]=j;
		}
    for(k=0;k < Real_V;k++){
    	for(i=0;i < Real_V;i++)
			for(j=0;j < Real_V;j++)
				if(A[i][j] > A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					P[i][j]=P[i][k];
				}
		showDMatrix();
	}		
}
void showDMatrix(){
	int i,j;
	printf("\n");
	for(i=0;i < Real_V;i++){
		for(j=0;j < Real_V;j++){
			printf("%4d",A[i][j]);
		}
		printf("\n");
	}		
	return ;
}
void SearchPath()
{
    int i,j,row;
    for(i=0;i < Real_V;i++)
		for(j=0;j < Real_V;j++)
		{
			printf("Shortest Path from V%d to V%d cost is:%d\n",i+1,j+1,A[i][j]);
			printf("Shortest path is:\n from v%d",i+1);
			row=P[i][j];
			while(row != j)
			{
				printf(" to V%d",row+1);
				row=P[row][j];
			}
			printf(" to V%d\n",row+1);
		}
}


