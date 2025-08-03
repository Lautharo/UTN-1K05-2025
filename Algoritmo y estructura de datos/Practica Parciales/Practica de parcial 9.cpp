#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float recaudacion(float &a,float &b,float &total);
void vendioMas(float &a,float &b);

main()
{
	int n,m,o,p,q,c=0,x=1; float a,b,total=0,cansup=0,canprem=0;
	
	printf("Seleccione cual precio del combustible ingresar primero:\n");
	printf("Codigo 1 SUPER\n");
	printf("Codigo 2 PREMIUM\n");
	while(c<x)
	{
		scanf("%d",&n);
		if(n==1)
		{
			c=2;
			printf("Ingrese el precio del combustible SUPER por litro: ");
			scanf("%f", &a);
			printf("Ingrese el precio del combustible PREMIUM por litro: ");
			scanf("%f", &b);
			
		}
		else if(n==2)
		{
			c=2;
			printf("Ingrese el precio del combustible PREMIUM por litro: ");
			scanf("%f", &b);
			printf("Ingrese el precio del combustible SUPER por litro: ");
			scanf("%f", &a);
		}
		else
		{
			printf("Selecciona una opcion valida.\n");
		}
	}
	printf("Ingrese el numero de ventas: ");
	scanf("%d", &x);
	for(int i=o; i<x;i++)
	{
		printf("Venta [%d] del combustible (1 y 2): ",i+1);
		scanf("%d", &m);
		if(m==1)
		{
			printf("Ingrese los litros vendidos del combustible SUPER: ");
			scanf("%d", &p);
			cansup+=(a*p);
		}
		else if(m==2)
		{
			printf("Ingrese los litros vendidos del combustible PREMIUM: ");
			scanf("%d", &q);
			canprem+=(b*q);	
		}
		else
		{
			i--;
			printf("Ingrese un valor valido.\n");
		}
	}
	recaudacion(cansup,canprem,total);
	printf("La recaudacion total de ambos combustibles es de [%.2f]\n", total);
	vendioMas(cansup,canprem);

}

float recaudacion(float &cansup,float &canprem,float &total)
{
	total=cansup+canprem;
	return total;
}

void vendioMas(float &cansup,float &canprem)
{
	if(cansup>canprem)
	{
		printf("Vendio mas combustible SUPER\n");
	}
	else
	{
		printf("Vendio mas combustible PREMIUM\n");
	}
}

/*	printf("Seleccione el combustible a ingresar:\n");
	printf("1 Super \n");
	printf("2 Premium\n");
	while(c<x)
	{
		scanf("%d", &n);
		if(n==1)
		{
			printf("Ingrese el precio por litro del combustible SUPER: ");
			scanf("%d",&m);
			printf("Ingrese el numero de ventas: ");
			scanf("%d",&o);
			a=m*o;
			c=1;
			x=1;
		}
		else if(n==2)
		{
			printf("Ingrese el precio por litro del combustible PREMIUM: ");
			scanf("%d",&p);
			printf("Ingrese el numero de ventas: ");
			scanf("%d",&q);
			b=p*q;
			c=1;
			x=1;
		}
		else
		{
		printf("Seleccione una opcion valida.\n");
		}
	}
	if(n==1)
	{
		printf("Ingrese el precio por litro del combustible PREMIUM: ");
		scanf("%d",&p);
		printf("Ingrese el numero de ventas: ");
		scanf("%d",&q);
		b=p*q;
	}
	if(n==2)
	{
			printf("Ingrese el precio por litro del combustible SUPER: ");
			scanf("%d",&m);
			printf("Ingrese el numero de ventas: ");
			scanf("%d",&o);
			a=m*o;
	}
	recaudacion(a,b,total);
	printf("La recaudacion total de las ventas es de: [%.2f] \n",total);
	vendioMas(a,b);*/