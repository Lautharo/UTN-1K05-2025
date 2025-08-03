/*REALICE LA CODIFICACIÓN EN LENGUAJE C
Se requiere llevar el registro de las alturas de N personas. Para ello, se almacenarán las alturas en un
vector, donde el subindice del vector indica el número de persona.
Se pide:
EJERCICIO No 2-No usar variables globales
a) Ingresar las alturas de las personas en el vector.
b) A través de una función con tipo lIlamada ""calcularEstadisticas", encuentre la altura promedio, la
altura más alta y la más baja registradas. Muestre los resultados en main().*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int calcularEstadisticas(float v[100], float &max, float &min, float &altpr, int &c1,int &condicional, float &n);
main()
{
	float v[100],n, max=0, min=0, altpr=0; int  c1=0, condicional=0;
	do
	{
		printf("Ingrese las alturas de las personas en m: ");
		scanf("%f", &n);
		if(n!=0)
		{
			v[c1]=n;
			c1++;
		}
	}while(n!=0);	
	calcularEstadisticas(v,max,min,altpr,c1,condicional,n);
	if(condicional==1)
	{
		printf("La altura mas baja es [%.2f]\n", min);
		printf("La altura mas alta es [%.2f]\n", max);
		printf("La altura promedio es [%.2f]\n", altpr);
	}	
}
int calcularEstadisticas(float v[100], float &max, float &min, float &altpr, int &c1,int &condicional, float &n)
{
	int i=0;float pr=0;
	min = v[i];
	max = v[i];
	for(i=0;i<c1;i++)
	{
		if(v[i] > max) 
		{
			max=v[i];
		}
		if(v[i] <= min) 
		{
			min=v[i];
		}
		pr+=v[i];
	}
	altpr=pr/c1;		
	return condicional = 1;
}
