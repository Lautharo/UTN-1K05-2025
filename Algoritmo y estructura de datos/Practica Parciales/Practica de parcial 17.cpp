#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void notas(int n, float v[100]);
main()
{
	int n,i,pibot2=0;float v[100],pibot=0,promedio, porcentaje;
	
	printf("Ingrese la cantidad de estudiantes: ");
	scanf("%d", &n);
	notas(n,v);
	for(i=0;i<n;i++)
	{
		if(v[i]<8)
		{
			pibot+=v[i];
			pibot2++;
			promedio=pibot/n;
			porcentaje=(pibot2*100)/n;
		}
	}
	printf("El promedio de las notas menores a 8 es de [%.2f]\n",promedio);
	printf("El porcentaje de las notas menores a 8 es de [%.2f%%]\n",porcentaje);
}

void notas(int n, float v[100])
{
	for(int i=0;i<n;i++)
	{
		printf("Ingrese la nota del estudiante [%d]: ", i+1);
		scanf("%f", &v[i]);
	}
}