#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void porcentaje(float &x, int &c,int &porcen, int &p1)
{
	float medio;
	if(x>=236 && x<=319)
	{
		p1++;
	}
	medio=(p1*100)/c;
	porcen=medio;
}

main()
{
	int n, c=0, porcen=0, p1=0; float s=0,p=0, x;
	
	printf("Ingrese la cantidad de numeros de 3 digitos a calcular: ");
	scanf("%d", &n);
	printf("Ingrese los numeros de 3 digitos: \n");
	while(c<n)
	{
		printf("x: ");
		scanf("%f", &x);
		if(x>=100 && x<=999)
		{
			c++;    
			porcentaje(x,c,porcen,p1);
			s+=x;
			p=s/n;   
		}
		else
		{
			printf("ERROR unicamente numeros de 3 cifras\n");
		}
   
	}
	printf("El porcentaje es [%d%%]\n", porcen);
	printf("El promedio es [%.2f]\n", p);
}