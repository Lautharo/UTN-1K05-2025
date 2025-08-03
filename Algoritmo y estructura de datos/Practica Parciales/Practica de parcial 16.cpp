#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void cargaDelVector(int n, float v[100]);

main()
{
	int n,i,dias=0;float v[100],promedio,menor;
	
	printf("Ingrese la cantidad de las temperaturas diarias:");
	scanf("%d", &n);
	cargaDelVector(n,v);
	menor=v[i];
	for(i=0;i<n;i++)
	{
		promedio=v[i]/n;
		
		if(v[i]<menor)
		{
			menor=v[i];
		}
		
		if(v[i] >= 20 && v[i] <= 25)
		{
			dias++;
		}
	}
	printf("La temperatura promedio fue de [%.2f]\n", promedio);
	printf("La temperatura mas baja fue de [%.2f]\n", menor);
	printf("Hubo unos [%d] dias entre la temperatura 20 y 25\n", dias);
}

void cargaDelVector(int n, float v[100])
{
	for(int i=0;i<n;i++)
	{
		printf("Ingrese la temperatura del dia [%d]:",i+1);
		scanf("%f", &v[i]);
	}
}