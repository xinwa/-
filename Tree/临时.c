#include<stdio.h>

int main()
{
	int a,b;
	int atag[30];
	int btag[30];
	int acount = 0;
	int bcount = 0;
	int i = 0;
	int j = 0;
	int h = 0;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		acount = 0;
		bcount = 0;
		i = a;
		j = b;

		btag[bcount++] = j % 10;
		while(j = j/10)
			btag[bcount++] = j%10;

		
		while(1)
		{
			j = 0;
			acount = 0;
			atag[acount++] = i%10;
			while(i = i/10)
				atag[acount++] = i%10;

			for(h = 0; h < acount; h++)
			{
				if(atag[h] == btag[j])
				{
					j++;
					if(j == bcount)
						break;
				}
			}
			if(j == bcount)
				break;
			i = ++a;
		}
		printf("%d\n", a);
	}

      return 0;
}