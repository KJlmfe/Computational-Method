#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 1000
int main()
{
    int n;
    double tmp,l,x[N],f[N]; 
	
	printf("请输入n: ");
    scanf("%d",&n);
    
    for(int i=0;i<=n;i++)
    {
        printf("请输入x[%d]：",i);
		scanf("%lf",&x[i]);
		printf("请输入y[%d]：",i);
   		scanf("%lf",&f[i]);
	}
    
	printf("请输入x：");
    scanf("%lf",&tmp);

	//以下是拉格朗日差值核心算法
    double y = 0.0;
    int k = 0;
    
    while(k <= n)
    {
        l = 1.0;
        for(int j=0; j<=n; j++)
	        if(j != k)
		        l = l*(tmp-x[j])/(x[k]-x[j]);
	    y = y+l*f[k];
	    k++;
    }

    printf("当x=%lf时 y=%lf\n",tmp,y);
    system("pause");
    return 0;
}
