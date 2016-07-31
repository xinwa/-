#include<stdio.h>
#include<stdlib.h>

int swapnum(int swap[],int n);
int main()
{
      int num;
      int a_num;
      int b_num;
      int a[1000];
      int b[1000];
      int i;
      while(num >= 1000  || num <=0)
      {
            scanf("%d",&num);
            
      }
      while(a_num > 1000 || a_num < 0)
      {
            scanf("%d",&a_num);
      }
      for(i = 0;i < a_num;i++)
      {
            scanf("%d",&a[i]);
      }
      while(b_num > 1000 || b_num < 0)
      {
            scanf("%d",&b_num);
      }
      for(i = 0;i<b_num;i++)
      {
            scanf("%d",&b[i]);
      }
      printf("%d\n",swapnum(a,a_num));
      printf("%d\n",swapnum(b,b_num));
}

int swapnum(int swap[],int n)
{
      int i,j,temp,count = 0;
      for(i = 0; i< n;i++)
      {
            for(j = i +1 ;j < n;j++)
            {
                  if(swap[i] > swap[j])
                  {
                        temp = swap[i];
                        swap[i] = swap[j];
                        swap[j] = temp;
                        count++;
                  }
            }
      }
      return count;
}    