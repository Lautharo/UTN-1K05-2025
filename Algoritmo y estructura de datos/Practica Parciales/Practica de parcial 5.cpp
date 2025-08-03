#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
void montoTotal(float &din1,int &boletos, int &porc,float porcpart1);
main()
{
	int n,x, paso2, boletos=0,porc=0; float v[100], din1=0, dinerototal=0, porcpart1=0;
	
	printf("Ingrese cuantas ventanillas desea analizar: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		printf("Ingrese la cantidad de boletos vendidos de la ventanilla [%d]: ", i);
		scanf("%f", &v[i]);
		for(paso2=0;paso2<v[i];paso2++)
		{
			printf("Ingrese el monto del boleto [%d]: ", paso2);
			scanf("%f", &din1);
			dinerototal+=din1;
			boletos++;
			if(din1>=10000)
			{
				porcpart1++;
			}
		}
	}
	montoTotal(din1,boletos,porc,porcpart1);
	printf("El Dinero total recaudado de la empresa es [%.2f] \n", dinerototal);
	printf("El porcentaje vendido superior a 10000$ fueron [%d%%]", porc);
}

void montoTotal(float &din1,int &boletos, int &porc,float porcpart1)
{
	if(din1>=10000)
	{
		porc=(porcpart1*100)/boletos;
	}
}