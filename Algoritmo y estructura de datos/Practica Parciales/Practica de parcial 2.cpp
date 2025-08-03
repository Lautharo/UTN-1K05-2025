#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

void pacientes(float v[100], int &c1)
{
	float n=0; int  i=0;
	do
	{
		printf("Ingrese el estado del paciente: ");
		scanf("%f", &n);
		if(n!=0)
			{
				if(n>0 && n<1)
				{
					v[i]=n;
					i++;
				}
				else if(n<0 || n>1)
				{
					printf("ERROR ingresar un valor valido\n");
				}
			}
	}while(n!=0);
	c1=i;

}

main()
{
	int c1=0, xmenos=0, xhosp=0, xop=0, porc=0; 
	float v[100];
	
	
	pacientes(v,c1);
	
	for(int i=0;i<c1;i++)
	{
		if(v[i]>=0.6)
		{
			xhosp++;
		}
		
		if(v[i]>0.89)
		{
			xop++;
		}
		porc=(xop*100)/c1;

	}
	printf("Cantidad de pacientes hospitalizados [%d]\n", xhosp);
	printf("El porcentaje de los pacientes operados es de un [%d%%] \n", porc);
}