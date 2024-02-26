#include <stdio.h>
int a[10][10],d[10][10];
int i,j,k,n;
int min(int a, int b) 
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
 //return (a<b)?a:b;

void path()
{
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main()
{
	printf("\nEnter the number of vertices:");
	scanf("%d", &n);
	printf("\nEnter the cost Matrix:\n");
	for (i = 0; i < n; i++) 
	{
        		for (j = 1; j < n; j++) 
		{
			scanf("%d", &a[i][j]);
			d[i][j]=a[i][j];
		}
	}
	path();
	printf("\nEnter the Final Distance Matrix:\n");
	for (i = 0; i < n; i++) 
	{
        		for (j = 1; j < n; j++) 
		{
			printf("%d", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}

	




