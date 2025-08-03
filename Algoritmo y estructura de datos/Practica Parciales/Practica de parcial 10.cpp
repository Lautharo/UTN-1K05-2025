#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void calificaciones(float v[100], int &i, float &s);
float promedio(float &p, float &s, int &n, float v[100], int &des, float &porcen);

main()
{
	int n,i,des=0; float v[100], p=0,s=0,porcen=0;
	
	printf("Ingrese la cantidad de estudiantes: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		calificaciones(v,i,s);
	}
	promedio(p,s,n,v,des,porcen);
	printf("El promedio de las notas es [%.2f] \n",p);
	printf("El porcentaje de desaprobados es de [%.2f%%]\n", porcen);
}

void calificaciones(float v[100], int &i, float &s)
{
	printf("Ingrese la nota del alumno [%d]: ",i+1);
	scanf("%f", &v[i]);
	s+=v[i];
}

float promedio(float &p, float &s, int &n, float v[100], int &des, float &porcen)
{

	p=s/n;
	
	for(int i=0; i<n;i++)
	{
		if(v[i]<7)
		{
			des++;
			porcen=(des*100)/n;
		}
	}
	
	return p, porcen;
}
