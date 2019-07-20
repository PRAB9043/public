#include <stdio.h>
#include <math.h>

int main()
{
    int sq,i,it,value,count1 = 0, flag = 0  ;
    printf("Enter the value...\n");
    scanf("%d",&value);
    sq = (int)sqrt(value);
    for(i = 1;i <= sq ;i++)
      {
         count1 =0;
           for(it = 2;it <= i/2; it++)
               {
                    if(i%it == 0)
                    {
                        count1++;
                        break;
                    }
                }
          if(count1 == 0 & i != 1)
              {
                 if(value%i == 0)
                    flag++;
              }
      }
 if(flag == 0)
    printf("Prime no...\n");
 else
    printf("Not prime no..\n");
}
