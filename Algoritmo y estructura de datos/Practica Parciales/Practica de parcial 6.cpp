#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int carPorcentaje(float v[100],int &c1,int &n,int &porcentaje, int &minx);

main()
{
	int n,menor300=0, minx,i,porcentaje=0,c1=0;float v[100];
	
	printf("Ingrese la cantidad de autos a competir: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("Ingrese los minutos que llego el auto [%d]: ", i);
		scanf("%f", &v[i]);
		if(v[i]<=300)
		{
			menor300++;
		}
	}
	printf("La cantidad de autos que terminaron en menos de 300 minutos fueron [%d]\n\n", menor300);
	printf("=================================================================\n\n");

	carPorcentaje(v,c1,n,porcentaje,minx);	
	printf("El porcentaje de los autos antes de %d minutos es [%d%%]\n",minx,porcentaje);
	
}

int carPorcentaje(float v[100],int &c1,int &n,int &porcentaje, int &minx)
{
	printf("Ingrese los minutos a saber quienes terminaron antes de X tiempo: ");	
	scanf("%d",&minx);
	for(int i=0;i<n;i++)
	{
		if(v[i]<minx)
		{
			c1++;
		}
	}
	porcentaje=(c1*100)/n;
	return porcentaje, minx;
}

