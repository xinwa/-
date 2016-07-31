#include<stdio.h>

int main(void)
{
	int m , n;
	int k;

	int a[1000] = {0};
	int l = 0;
	int i , j;
	int temp;
	scanf("%d%d%d",&n,&m,&k);
	for(i = 1;i<=n ; i++)
		for( j = 1 ; j<=m ; j++)
			a[l++] = i*j;


		 for (i = 0; i < l; i++)
                for (j = i; j < l; j++)
                {
                    if (a[i] > a[j])
                    {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                }
printf("%d\n",a[k-1]);
	return 0;
}
