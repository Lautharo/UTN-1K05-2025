/*
EJERCICIO 01: Realice la codificación en lenguaje C
Una empresa de venta de electrodomésticos registra en un array bidimensional de MxN las unidades vendidas (número entero) de cada uno de los M 
(filas) electrodomésticos en cada una de las N (columnas) sucursales que posee.
Se pide:

a) A través de una función sin tipo, cargar el arreglo y determinar cuál es la sucursal con mayor cantidad 
de unidades vendidas, mostrar el resultado en main ().
b) Ingresar el indice correspondiente a alguno de los M electrodomésticos. Por medio de una función con tipo 
determinar la venta promedio de ese electrodoméstico en particular. Mostrar el resultado en la función main.

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void CargaMatriz(int Ma[100][100], int m, int n);
void SucursalMay(int Ma[100][100], int m, int n, int &sucursalmay);
float ElectroProm(int Ma[100][100], int m, int n, int indice, float prom);

main()
{ 
	int m,n,Ma[100][100], sucursalmay, indice;
	float prom=0;

	printf("Ingrese la cantidad de electrodomesticos: ");
	scanf("%d", &m);
	printf("Ingrese la cantidad de sucursales: ");
	scanf("%d", &n);
	
	printf("\n----------------------------------------------------------\n\n");
	CargaMatriz(Ma,m,n);
	printf("\n----------------------------------------------------------\n\n");
	
	SucursalMay(Ma,m,n,sucursalmay);
	
	printf("Ingrese que electrodomestico desea analizar su promedio con respeto a su venta dentro de las sucursales: ");
	scanf("%d", &indice);
	float PromElec = ElectroProm(Ma,m,n,indice-1,prom);
	
	printf("\n----------------------------------------------------------\n\n");
	printf("La sucursal que mas electrodomesticos vendio fue la [%d]. \n", sucursalmay);
	printf("El promedio del electrodomestico [%d] es de [%.2f] . \n", indice, PromElec);
	
}

void CargaMatriz(int Ma[100][100], int m, int n)
{
	for(int j=0; j<n; j++)
	{
		for(int i=0; i<m; i++)
		{
			printf("Ingrese las unidades vendidas del electrodomestico [%d] en la sucursal [%d]: ", i+1, j+1 );
			scanf("%d", &Ma[i][j]);
		}
	}
}

void SucursalMay(int Ma[100][100], int m, int n, int &sucursalmay)
{
	int a=0, mayor=0;
	
	for(int j=0; j<n; j++)
	{
		a=0;
		for(int i=0; i<m; i++)
		{
			a+=Ma[i][j]; 
			
			if(a > mayor)  
			{
				mayor = a;
				sucursalmay = j+1;
			}
		}
	}
}

float ElectroProm(int Ma[100][100], int m, int n, int indice, float prom)
{
	int a=0;
	for(int i=0; i<m; i++)
	{
		if(i==indice)
		{
			for(int j=0; j<n; j++)
			{
			a+=Ma[i][j];
			}
		}	
	}
	return prom=a/n;
}
