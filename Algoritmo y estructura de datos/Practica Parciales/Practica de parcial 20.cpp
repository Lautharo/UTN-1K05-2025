#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void carga(float v[100],int n);

main()
{
	int n,c=0,n1=0; float v[100],suma=0,prom,porcentaje;
	
	printf("Ingresar la cantidad de espectadores: ");
	scanf("%d", &n);
	carga(v,n);
	for(int i=0;i<n;i++)
	{
		if(v[i] <= 5)
		{
			c++;		
		}
		if(v[i] >= 6)
		{
			n1++;
			suma+=v[i];
		}
	}
	prom=suma/n1;
	porcentaje=(c*100)/n;
	
	printf("El promedio de satisfaccion es de: [%.2f].\n", prom);
	printf("El porcentaje de insatisfaccion es de [%.2f%%].\n", porcentaje);
}

void carga(float v[100],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Persona [%d] calificacion: ", i+1);
		scanf("%f", &v[i]);
		if(v[i] < 0 || v[i] > 10)
		{
			printf("Valor invalido.\n");
			i--;
		}
	}
}