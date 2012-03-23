#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 1.0e-6	// 精度
#define MAX 10		// 最大迭代次数

double f(double);
double Romberg(double a, double b);

int main() {
	double a, b;
	printf("请输入积分上下限！\n   下限a = ");
	scanf ("%lf", &a);
	getchar();
	printf("   上限b = ");
	scanf ("%lf", &b);
	getchar();

	printf("\n龙贝格法求积分结果为: %lf\n", Romberg(a, b));
	system("pause");
	return 0;
}

double Romberg(double a, double b) {
	double  h = b - a, buf, y[4];			// y[4]依次存储Tn, Sn, Cn, Rn. 

	y[0] = h * (f(b) + f(a)) / 2.0;			// 求第一个Tn,用y[0]存储

	int m = 1, n = 1,k;						// m为迭代次数, n为
	do {
		buf = 0.0;
		for (int i=0; i<n; i++)				// 求Hn, 用buf存储
			buf += f(a + (i + 0.5) * h);
		buf = (y[0] + h * buf) / 2.0;		// 求T2n = (Tn+Hn)/2, 用buf冲掉T2n以节省存储空间
		
		double tmp, s = 1.0;				// buf和tmp临时存储Sn,Cn,Rn s控制迭代公式的变化
		for (k=1; k<=m && k<=3; k++) {
			s *= 4.0;
			tmp = (s * buf - y[k-1]) / (s - 1.0);
			y[k-1] = buf;					// y[k-1]保存
			buf = tmp;
		}
		buf = (k == 4) ? fabs(tmp - y[k-1]) : EPS+1;
		y[k-1] = tmp;						// |R2n - Rn|计算后存储R2n
		n *= 2;	h /= 2;	
	} while ((m++ <= MAX) && (buf > EPS));	// |R2n - Rn|精度控制与迭代次数控制

	return y[0];
}

double f(double x) {    //这里返回f(x)
    return x*x*exp(x);          //问题1(1)
    //return exp(x)*sin(x);    //问题1(2)
    //return 4/(1+x*x);      //问题1(3)
    //return 1/(1+x);       //问题1(4)
    //return x==0 ? 1 : sin(x)/x;  //问题2(1)
    //return x==1 ? 1 : cos(x)/sqrt(1-x);  //问题2(2)
    //return x==0 ? 0 : cos(x)/sqrt(x);   //问题2(3)
    //return x*x==1 ? 1 : x*sin(x)/(sqrt(1-x*x));   //问题2(4)
}

