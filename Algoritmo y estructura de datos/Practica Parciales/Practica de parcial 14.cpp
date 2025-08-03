#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void cargaDelVector(float v[100], int &n);
main()
{
	int n,c=0,i=0; float v[100],sumador=0,prom,menor;
	
	printf("Ingresa la cantidad de dias: ");
	scanf("%d", &n);
	cargaDelVector(v,n);
	menor=v[i];
	for(i=0;i<n;i++)
	{
		sumador+=v[i];
		prom=sumador/n;
		if(v[i]<menor)
		{
			menor=v[i];
		}
		if(v[i]>=20 && v[i]<=25)
		{
			c++;
		}
	}
	printf("El promedio de la temperatura es [%.2f] \n",prom);
	printf("La temperatura menor dada fue [%.2f]\n", menor);
	printf("Hubo un/unos [%d] dias de temperaturas entre 20 y 25\n", c);
}

void cargaDelVector(float v[100], int &n)
{
	for(int i=0; i<n; i++)
	{
		printf("Ingrese el valor de la temperatura [%d]: ", i+1);
		scanf("%f", &v[i]);
	}
}