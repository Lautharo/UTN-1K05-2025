#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

float buscador(float v[100], float &busqueda, float &guardar,float &guardarf);
main()
{
	int n,i,cant=0;float v[100],pibot=0,busqueda=0,guardar=0,guardarf=0;
	
	printf("Ingrese la cantidad de personas: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("Ingrese los documentos de la persona [%d] (sin puntos): ", i+1);
		scanf("%f", &v[i]);
		
		pibot=v[i];
		if(pibot>=40000000)
		{
			cant++;		
		}		
	}
	printf("\nLa cantidad de personas con DNI mayor a 40.000.000 es [%d] ",cant);
	printf("\n\n===============================\n\n");
	printf("Programa de busqueda:\nIngrese el numero de DNI a buscar en la base de datos: ");
	scanf("%f",&busqueda);
	buscador(v,busqueda,guardar,guardarf);
	
}

float buscador(float v[100], float &busqueda, float &guardar, float &guardarf)
{
	float pibot1=0;
	for(int i=0;i<busqueda;i++)
	{
		pibot1=v[i];
		if(pibot1==busqueda)
		{
			guardar=busqueda;
			printf("\nEl DNI [%.0f] se encuentra en la base de datos", guardar);
			return guardar;
			break;
		}
		else
		{
			guardarf=busqueda;
			printf("\nEl DNI [%.0f] NO se encuentra en la base de datos", guardarf);
			return guardarf;
		}		
	}
}