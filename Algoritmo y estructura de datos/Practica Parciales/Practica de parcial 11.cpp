
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
float facturacionTotal(float &a, float &b, float &p, float &q);
void masPedida(float &p, float &q);
main()
{
	int n=1,i,r; float a,b,p,q;
	
	printf("Ingrese el precio de la comida rapida (Codigo 1): ");
	scanf("%f", &a);
	printf("Ingrese el precio de la comida saludable (Codigo 2): ");
	scanf("%f", &b);
	for(i=0;i<n;)
	{
		printf("Ingrese la cantidad de pedidos: \n");
		printf("Comida rapida: 1\n");
		printf("Comida saludable: 2\n");
		printf("Salir: 0\n");
		scanf("%d", &r);
		if(r==1)
		{
			printf("Ingrese la cantidad de unidades solicitadas de comida rapida: ");
			scanf("%f", &p);
		}
		else if(r==2)
		{
			printf("Ingrese la cantidad de unidades solicitadas de comida saludables: ");
			scanf("%f", &q);
		}
		else if(r==0)
		{
			printf("Carga de pedidos finalizada.\n");
			i++;
		}
		else
		{
			printf("Ingrese una opcion valida.\n");
		}
	}
	
	float total = facturacionTotal(a,b,p,q);
	printf("La facturacion total fue de [%.2f] \n", total);
	masPedida(p,q);
}

float facturacionTotal(float &a, float &b, float &p, float &q)
{
	return (a*p)+(b*q);
}

void masPedida(float &p, float &q)
{
	if(p>q)
	{
		printf("La comida rapida fue mas pedida\n");
	}
	else if(p<q)
		{
		printf("La comida saludable fue mas pedida\n");
	}
	else if (p==q)
	{
		printf("Fueron pedidas por igual.\n");
	}
}