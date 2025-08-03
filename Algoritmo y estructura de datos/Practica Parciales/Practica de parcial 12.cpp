#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void notas(float v[100], int n);

main()
{
	int n, s=0; float v[100], prom=0,porcen,a=0;
	
	printf("Ingrese la cantidad de estudiantes: ");
	scanf("%d", &n);
	notas(v,n);
	for(int i=0 ; i<n; i++)
	{
		if(v[i]<8)
		{
			s++;
			a+=v[i];
			prom=a/n;
			porcen=s/n*100;
		}
	}
	printf("El promedio de las notas menor a 8 es [%.2f] \n", prom);
	printf("El porcentaje de estudiantes con nota menor a 8 es [%.2f%%]\n", porcen);
}

void notas(float v[100], int n)
{
	int i;
	for(i=0; i<n ; i++)
	{
		printf("Ingrese la nota del estudiante [%d]: ", i+1);
		scanf("%f", &v[i]);
	}
}