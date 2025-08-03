#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

float desaprobados(int n, float v[100],int &c);
void carga(float v[100],int n);

main()
{
	int n,i,c=0;float v[100], promedio=0,suma=0,porcentaje=0;
	
	printf("Ingrese la cantidad de alumnos: ");
	scanf("%d", &n);
	carga(v,n);
	
	for(i=0;i<n;i++)
	{
		suma+=v[i];
		promedio=suma/n;	
	}
	desaprobados(n,v,c);
	porcentaje=(c*100)/n;
	
	printf("El promedio de las calificaciones es de [%.2f]\n", promedio);
	printf("El porcentaje de las calificaciones <6 es de [%.2f%%]\n", porcentaje);
	
}

void carga(float v[100],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Ingrese las calificaciones de los estudiantes: ");
		scanf("%f", &v[i]);
	}
}

float desaprobados(int n, float v[100],int &c)
{
	for(int i=0;i<n;i++)
	{
		if(v[i] < 6)
		{
			c++;
		}
	}
	return c;
}