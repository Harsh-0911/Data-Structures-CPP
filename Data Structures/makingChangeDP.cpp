#include <stdio.h>
#include <stdlib.h>

int main()
{
    int coin,s;
    printf("Target Money : ");
    scanf("%d",&s);
    printf("Number of denominator coins : ");
    scanf("%d",&coin);
    int a[coin];
    int ans1,ans2;
    printf("Enter Denominator Coins : \n");
    for(int i=0;i<coin;i++){
        scanf("%d",&a[i]);
    }

    int final[s+1][coin];
    for(int i=0;i<coin;i++){
        final[0][i]=1;
    }

    for(int i=1;i<s+1;i++){
        for(int j=0;j<coin;j++){
            if(i-a[j]>=0)
                ans1 = final[i-a[j]][j];
            else
                ans1 = 0;
            if (j>=1)
                ans2 = final[i][j-1];
            else
                ans2 = 0;
            final[i][j] = ans1+ans2;
        }
    }
    printf("Total ways :: %d",final[s][coin-1]);
    return 0;
}
