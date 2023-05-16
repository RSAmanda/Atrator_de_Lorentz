#include<stdio.h>
#include<math.h>
#define N 3
 // omega
#define O 10
 //beta
#define B 8./3.
 //rho
#define R 28


typedef double (*equacoes) ();

double f0(int m, double x, double y[m]) //dx/dt
{
	return O*(y[1]-y[0]);
}

double f1(int m, double x, double y[m]) // dy/dt
{
	return R*y[0]-y[0]*y[2]-y[1];
}

double f2(int m, double x, double y[m]) // dz/dt
{
	return y[0]*y[1]-B*y[2];
}

void metodoEuler(int m, double x, double y[m], double h)
{
	double k1[m], k2[m], k3[m], k4[m], yp[m], ypp[m];
	equacoes f[]={f0, f1, f2};
	int i;
	
	for(i=0; i<m; i++)
	{
		k1[i]=f[i](m, x, y);
		y[i]=y[i]+h/2*k1[i];
	}
}

int main(int argc, char** argv)
{	double r, a, b, h, m, x, y[N]={0.0,0.0,0.0};
	double j;
	int i;
	m=N;
	h=0.001;// "dt"
	a=10.; // inicio
	b=80.; // fim
	
	for(j=0.;j<=1.;j+=0.2)
	{
		y[0]+=j;
		for(x=a; x<=b; x+=h)
		{	printf("%g", x);
			for(i=0;i<m;i++)
			{
				printf("\t%g", y[i]);
			}
			metodoEuler(m, x, y, h);
			printf("\n");
		}
		printf("\n\n");		
	}
}
	
	
	
	
	
	
	
	
	
