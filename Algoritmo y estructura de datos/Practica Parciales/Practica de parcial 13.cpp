#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void mayorEnergia(float &p, float &q, float &a, float &b);
float recaudacionTotal(float &a, float &b, float &p, float &q);
main()
{
	int codigo; float a,b,p=0,q=0,cantidad;
	
	printf("Ingrese el precio de kWh de la Estacion rapida (codigo 1): ");
	scanf("%f", &a);
	printf("Ingrese el precio de kWh de la Estacion lenta (codigo 2 ): ");
	scanf("%f", &b);
	printf("\n\n");
	while(true)
	{
		printf("Ingrese la estacion a utilizar: ");
		scanf("%d", &codigo);
		if(codigo == 1 )
		{
			printf("Ingrese el kwh cargado: ");
			scanf("%f", &cantidad);
			p+=cantidad;
		}
		else if(codigo == 2)
		{
			printf("Ingrese el kwh cargado: ");
			scanf("%f", &cantidad);
			q+=cantidad;	
		}
		else if(codigo == 0)
		{
			printf("Carga finalizada.\n");
			break;
		}
		else
		{
			printf("Ingrese una opcion valida.\n");
		}
	}
	float total = recaudacionTotal(a,b,p,q);
	mayorEnergia(p,q,a,b);
}

float recaudacionTotal(float &a, float &b, float &p, float &q)
{
	return (a*p)+(b*q);
}

void mayorEnergia(float &p, float &q, float &a, float &b)
{
	
	float rapida,lenta;
	
	rapida=p*a;
	lenta=q*b;
	
	if(rapida>lenta)
	{
		printf("La estacion rapida recaudo mas.\n");
	}
	else if(lenta>rapida)
	{
		printf("La estacion lenta recaudo mas.\n");
	}
	else
	{
		printf("Recadaron lo mismo.\n");
	}
}