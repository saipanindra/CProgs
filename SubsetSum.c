#include<stdio.h>
#include<stdlib.h>
void allocate2DArray(int ***p, int a, int b);
int subsetHasSum(int *set, int n, int sum);
int main()
{

  int *set = (int *) malloc(4 * sizeof(int));
  set[0] = 1; set [1] = 2; set[2] = 4; set[3] = 6;
  int i;
  printf("Elements of Set : {"); 
  for(i = 0 ; i < 4 ; i++)
    printf("%d ",set[i]);
  printf("}\n");
  int sum = 25;
  printf("The set has sum %d ? %s", sum, subsetHasSum(set, 4, sum)==1 ? "true":"false");

}


void allocate2DArray(int ***p, int a, int b)
{ 
 *p = (int **)malloc(a *  sizeof(int *));
 int i ,j;
 for(i = 0 ; i < a ; i++)
  (*p)[i] = (int *)malloc( b * sizeof(int));

}

int subsetHasSum(int *set, int n, int sum)
{
  int **subset;
  allocate2DArray(&subset, sum + 1, n + 1);
  int i, j ;
  for(i = 0 ; i < sum + 1; i++)
  { 
    for(j = 0 ; j < n + 1; j++)
    {
      printf("%d ",subset[i][j]);
    }
    printf("\n");
  }
  for(i = 0 ; i < n + 1; i++)
  {
    subset[0][i] = 1;
  } 
  for(j = 1 ; j < sum + 1; j++)
  {
    subset[j][0] = 0;
  }

 printf("\n~~~!~!!\n");
 
  for(i = 0 ; i < sum + 1; i++)
  { 
    for(j = 0 ; j < n + 1; j++)
    {
      printf("%d ",subset[i][j]);
    }
    printf("\n");
  }
 for(i = 1 ; i < sum+1 ; i++)
  { 
    for(j = 1 ; j < n+1; j++)
    {
      subset[i][j] = subset[i][j-1];
      if( i - set[j] >= 0)
        subset[i][j] = subset[i][j] || subset[i - set[j]][j-1];
    }
  }
 return subset[sum][n]; 
 }
    
