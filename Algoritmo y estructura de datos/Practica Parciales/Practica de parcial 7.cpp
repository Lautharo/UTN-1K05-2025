#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

float combus(float v[100],float &p,float &s,int &n, float &porcen);
main()
{
	int n,i,obj=0; float v[100],p=0,s=0,may=0,comparacion=0,porcen=0;
	
	printf("Ingrese la cantidad de camiones a analizar: ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++)
	{
		printf("Ingrese el consumo de combustible del camion [%d] : ", i);
		scanf("%f", &v[i]);
		s+=v[i];
		comparacion=v[i];
		if(comparacion > may)
		{
			obj=i;
			may=comparacion;
		} 
		combus(v,p,s,n,porcen);
	}	        
	printf("\n=====================================================\n\n");	
	
	printf("El camion [%d] fue que consumio mas combustible con [%.2f]", obj,may);
	
	printf("\n\n=====================================================\n\n");
	
	printf("El promedio de consumo del combustible fue [%.2f]\n", p);
	printf("El porcentaje superior al promedio es de un [%.2f%%]\n",porcen);
	
	
}

float combus(float v[100],float &p,float &s,int &n,float &porcen)
{
	float p1=0;
	for(int i=0;i<n;i++)
	{
		p=s/n;
		if(p>v[i])
		{
			p1++;
			porcen=(p1*100)/n;
		}
	}
	
	return porcen , p;
}