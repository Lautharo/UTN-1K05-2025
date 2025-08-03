#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

float totalFacturado(float preB, float preP, float mesB, float mesP);
void mayorCantidadDeMeses(float mesB, float mesP);

main()
{
	int n,code;float cant,preB,preP,mesB=0,mesP=0;
	
	printf("Ingrese el precio del plan basico (code 1): ");
	scanf("%f", &preB);
	printf("Ingrese el precio del plan premium (code 2): ");
	scanf("%f", &preP);
	printf("Ingrese el numero de contrataciones: ");
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		printf("Ingrese el plan correspondiste: ");
		scanf("%d", &code);
		
		if(code == 1)
		{
			printf("Ingrese la cantidad de meses pagadas del Plan basico: ");
			scanf("%f", &cant);
			mesB+=cant;
		}
		else if(code == 2)
		{
			printf("Ingrese la cantidad de meses pagadas del Plan premium: ");
			scanf("%f", &cant);
			mesP+=cant;
		}
		else
		{
			printf("Ingrese un valor valido.\n");
			i--;
		}
	}
	float total = totalFacturado(preB,preP,mesB,mesP);
	mayorCantidadDeMeses(mesB,mesP);
	printf("La facturacion total fue de [%.2f].\n", total);
}
float totalFacturado(float preB, float preP, float mesB, float mesP)
{
	return (preB*mesB)+(preP*mesP);
}
void mayorCantidadDeMeses(float mesB, float mesP)
{
	if(mesB > mesP)
	{
		printf("El plan basico fue mayor que el premium.\n");
	}
	else if(mesP > mesB)
	{
		printf("El plan premium fue mayor que el basico.\n");
	}
	else
	{
		printf("Fueron contrados iguales.\n");
	}
}