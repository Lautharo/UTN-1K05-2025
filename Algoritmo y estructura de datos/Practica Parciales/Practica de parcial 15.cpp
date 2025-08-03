#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void proporcionoMas(float &p, float &q);
float recaudacionTotal(float a, float b, float p, float q, float &total);

main()
{
	int n,i,r;float a,b,p,q,cantidad,total;
	
	printf("Ingrese el precio de KWh: \n");
	printf("Estacion Rapida (code 1): ");
	scanf("%f", &a);
	printf("Estacion Rapida (code 2): ");
	scanf("%f", &b);
	printf("Ingrese la cantidad de registros: ");
	scanf("%d", &r);
	for(i=0;i<r;i++)
	{
		printf("Cargue el registro [%d] (ingrese la estacion): ", i+1);
		scanf("%d", &n);
		if(n == 1)
		{
			printf("Ingrese la cantidad de KWh cargados de la estacion rapida: ");
			scanf("%f", &cantidad);
			p+=cantidad;
		}
		else if(n == 2)
		{
			printf("Ingrese la cantidad de KWh cargados de la estacion lenta: ");
			scanf("%f", &cantidad);
			q+=cantidad;	
		}
		else
		{
			printf("Ingrese un valor valido.\n");
			i--;
		}
	}
	recaudacionTotal(a,b,p,q,total);
	printf("La recaudacion total sumistrada es de [%.2f]\n", total);
	proporcionoMas(p,q);
}

float recaudacionTotal(float a, float b, float p, float q, float &total)
{
	return total = (a*p)+(b*q);
}

void proporcionoMas(float &p, float &q)
{
	if(p>q)
	{
		printf("Proporciono mas la estacion rapida.\n");
	}
	else if(q>p)
	{
		printf("Proporciono mas la estacion lenta.\n");
	}
	else
	{
		printf("Propocionaron lo mismo.\n");
	}
}