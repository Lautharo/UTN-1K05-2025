#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cargaDelVector(float v[100],int &x,float &total, int &n, int &porc)
{
	int porcentaje1=0;
	total=0;
	
	for(int i=0;i<n;i++)
	{
		printf("Ingrese el peso de la pieza [%d] en KG: ", i);
		scanf("%f", &v[i]);
		
		total+=v[i];
		
		if(v[i]<9.8)
		{
			porcentaje1++;
		}
	}
	porc=(porcentaje1*100)/n;
}

main()
{
	int n,porc=0, x; float v[100], total=0;
	
	printf("Cuantas piezas desea registrar: ");
	scanf("%d", &n);

	cargaDelVector(v,x,total,n,porc);

	printf("El porcentaje de las piezas menores a 9.8kg es [%d%%]\n", porc);
	printf("El peso total es [%.2f]\n", total);
	
}

