#include<stdio.h>
#include<math.h>
#define N 3
 // omega
#define O 10
 //beta
#define B 8./3.

typedef double (*equacoes) ();

double f0(int m, double x, double y[m], double R) //dx/dt
{
	return O*(y[1]-y[0]);
}

double f1(int m, double x, double y[m], double R) // dy/dt
{
	return R*y[0]-y[0]*y[2]-y[1];
}

double f2(int m, double x, double y[m], double R) // dz/dt
{
	return y[0]*y[1]-B*y[2];
}

void metodoEuler(int m, double x, double y[m], double h, double R)
{
	double k1[m], k2[m], k3[m], k4[m], yp[m], ypp[m];
	equacoes f[]={f0, f1, f2};
	int i;
	
	for(i=0; i<m; i++)
	{
		k1[i]=f[i](m, x, y, R);
		y[i]=y[i]+h/2*k1[i];
	}
}

int main(int argc, char** argv)
{	double r, a, b, h, m, x, y[N]={1.0,1.0,0.0}; // consiçoes inicias
	
	m=N;
	h=0.001;// "dt"
	a=10.; // inicio
	b=80.; // fim
	
	for(r=5;r<=100;r+=5)
	{
		for(x=a; x<=b; x+=h)
		{	printf("%g", x);
			for(i=0;i<=m;i++)
			{
				printf("\t%g", y[i]);
			}
			metodoEuler(m, x, y, h, r);
			printf("\n");
		}
		printf("\n\n");		
	}
}
	
	
	
	
	
	
	
	
	
