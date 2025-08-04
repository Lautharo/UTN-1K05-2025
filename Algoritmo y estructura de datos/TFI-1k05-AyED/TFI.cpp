///TFI UTN 2025
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
/*Funcion para elegir entre modos de cargar y los metodos a usar*/
void mostrar(int vec[], int n);
int maximo(int vec[],int n);
void cargaman(int vec[],int &n);
void cargaaut(int vec[], int &n);
void ejecutarMetodo(int vec[], int n, int metodo);
void insercion(int vec[], int n, int &comp, int &inter, int orden);
void quicksort(int vec[], int ini, int fin, int &comp, int &inter, int orden);
void mergesort(int vec[], int ini, int fin, int &comp, int &inter, int orden);
void merge(int vec[], int ini, int medio, int fin, int &comp, int &inter, int orden);
void radixsort(int vec[], int n, int &comp, int &inter, int orden);
void countingsort(int vec[],int n,int exp, int &comp, int &inter);
int Menu();
int main()
{
	float b=1;int op=0,vec[500000],n,comp,inter;
	do 
	{
        op = Menu();  /*Mostrar menu*/
        switch(op)
        {        	
            case 1:
			{
				cargaman(vec, n);
				break;
			}    
            case 2:
			{
				cargaaut(vec, n);
				break;
			}     
            case 3:
			{
				/*metodo insercion */
				ejecutarMetodo(vec, n, 3);
				break;
			}
            case 4:
			{
				/*metodo QuickSort*/
				ejecutarMetodo(vec, n, 4);
				break;
			}   
            case 5:
			{
				/*metodo MergeSort*/
				ejecutarMetodo(vec, n, 5);
				break;
			}                                
            case 6:
			{
				/*metodo RadixSort*/
				ejecutarMetodo(vec, n, 6);
				break;
			}            	
            case 0:
			{
				printf("\nSaliendo del programa...\n");
				break;
			}                
            default:
                printf("\nOpcion invalida.\n");
        }
        printf("\nPresione cualquier tecla para continuar...");
        getch();
        system("cls");
    } while (op != 0);
    return 0;
}
int Menu()
{
	int opc;
	do {
        printf("=============MENU===============\n");
		printf("OPCION 1: Carga manual del vector\n");
        printf("OPCION 2: Carga automatica del vector\n");
        printf("OPCION 3: Insercion \n");
        printf("OPCION 4: QuickSort\n");
        printf("OPCION 5: MergeSort\n");
        printf("OPCION 6: RadixSort\n");
        printf("OPCION 0: Salir\n");
        printf("Elija una opcion: ");
        if (scanf("%d", &opc) != 1) 
		{
            /*Por si el usuario ingresa texto*/
            while (getchar() != '\n');
            opc = -1;
            system("cls");
            printf("\nNo puede ingresar caracteres. Aprete cualquier tecla para continuar");
            getch();
            system("cls");   
        }
    } while (opc < 0 || opc > 6);
    system("cls");
	return opc; //La variable "opc" valdra op dentro de main
}
void cargaman(int vec[],int &n) //Carga manual del vector
{
	printf("\nIngrese el numero de elementos del vector: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nIngrese el valor del elemento [%d]: ",i+1);
		scanf("%d",&vec[i]);
	}
}
void cargaaut(int vec[], int &n) //Carga automatica del vector
{
	int min,max;
	printf("Ingrese el numero de elementos del vector: ");
    scanf("%d", &n);
    printf("Ingrese el valor minimo: ");
    scanf("%d", &min);
    printf("Ingrese el valor maximo: ");
    scanf("%d", &max);
    if (max < min) 
	{
	    int temp = min; //Variable temporal si el valor max recibe un valor < a min
	    min = max;
	    max = temp;
	}
    srand((unsigned)time(NULL)); //Funcion random de stdlib.h con time.h 
    for (int i = 0; i < n; i++) 
	{
        vec[i] = rand() % (max - min + 1) + min;
        printf("Elemento [%d]: [%d]\n", i + 1, vec[i]);
    }
    printf("\nCarga completa entre [%d] y [%d].\n", min, max);
}
void mostrar(int vec[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Pos [%3d]:\tValor [%5d]\n", i + 1, vec[i]);
	}
}
void ejecutarMetodo(int vec[], int n, int metodo)
 {
    int orden, comp = 0, inter = 0;
    printf("Orden:");
    printf("\n1 - Ascendente\n2 - Descendente\n");
    printf("Seleccione el orden: ");
    scanf("%d", &orden);

    printf("El vector desordenado es:\n");
    mostrar(vec, n);
    clock_t inicio = clock();

    switch(metodo) {
        case 3: insercion(vec, n, comp, inter, orden); break;
        case 4: quicksort(vec, 0, n - 1, comp, inter, orden); break;
        case 5: mergesort(vec, 0, n - 1, comp, inter, orden); break;
        case 6: radixsort(vec, n, comp, inter, orden); break;
    }

    clock_t fin = clock();
    printf("----------------------\n");
    printf("El vector ordenado es:\n");
    mostrar(vec, n);
    printf("\nComparaciones: %d\nIntercambios: %d\n", comp, inter);
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.6f segundos\n", tiempo);
}
void insercion(int vec[], int n, int &comp, int &inter,int orden)
{
    comp = 0; inter = 0;
    for (int i = 1; i < n; i++) 
	{
        int actual = vec[i];
        int j = i - 1;
        while (j >= 0 && ((orden == 1 && vec[j] > actual) || (orden == 2 && vec[j] < actual))) 
		{
            vec[j + 1] = vec[j];
            j--; comp++; inter++;
        }
        vec[j + 1] = actual;
        if (j >= 0) comp++;
    }
}
void quicksort(int vec[], int ini, int fin, int &comp, int &inter,int orden) {
    if (ini < fin) {
        int pivote = vec[fin];
        int i = ini - 1;
        for (int j = ini; j < fin; j++) {
            comp++;
            if ((orden == 1 && vec[j] <= pivote) || (orden == 2 && vec[j] >= pivote)) {
                i++;
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
                inter++;
            }
        }
        int temp = vec[i + 1];
        vec[i + 1] = vec[fin];
        vec[fin] = temp;
        inter++;
        int posPivote = i + 1;
        quicksort(vec, ini, posPivote - 1, comp, inter, orden);
        quicksort(vec, posPivote + 1, fin, comp, inter, orden);
    }
}
void mergesort(int vec[], int ini, int fin, int &comp, int &inter,int orden) {
    if (ini < fin) { 
        int medio = (ini + fin) / 2; //Dividimos en 2 el vector
        mergesort(vec, ini, medio, comp, inter, orden);
        mergesort(vec, medio + 1, fin, comp, inter, orden); //Utilizamos la recursividad para que se vuelva a repetir este medio hasta q ya no pueda completarse
        merge(vec, ini, medio, fin, comp, inter,orden); //Funcionamiento atraves de otra funcion para que pueda separarlos indipendientemente
    }
}
void merge(int vec[], int ini, int medio, int fin, int &comp, int &inter,int orden) {
    int n1 = medio - ini + 1; //Creamos 2 variables las cuales obtendran el tamano posteriormente los vectores
    int n2 = fin - medio;
    int izq[n1], der[n2]; // Le asignamos el tamano a los vectores
    for (int i = 0; i < n1; i++)
	izq[i] = vec[ini + i]; // Copia los valores de la izq
    for (int j = 0; j < n2; j++)
	der[j] = vec[medio + 1 + j]; // Copia los valores de la der
    int i = 0, j = 0, k = ini;
    while (i < n1 && j < n2) { //mientras q haya elementos va a funcionar
        comp++;
        if ((orden == 1 && izq[i] <= der[j]) || (orden == 2 && izq[i] >= der[j])) 
		{ 
            vec[k++] = izq[i++]; //inserta los valores de la izq
        } else 
		{
            vec[k++] = der[j++]; //inserta los valores de la der   
        }
        inter++;
    }
    while (i < n1) //copia lo q quedo en la izq
	{ 
        vec[k++] = izq[i++], inter++;
    }
    while (j < n2) //copia lo q quedo en la der
	{ 
        vec[k++] = der[j++], inter++;
    }
}
void radixsort(int vec[],int n, int &comp,int &inter,int orden)
{
	comp=0; inter=0;
	int max = maximo(vec,n);
	for (int exp = 1; max / exp > 0; exp *= 10) 
	{
        countingsort(vec, n, exp, comp, inter);
    }
    /*Si se eligio orden descendente, invertimos el vector luego del ordenamiento para mantener estabilidad*/
    if (orden == 2) {
        for (int i = 0; i < n / 2; i++) {
            int temp = vec[i];
            vec[i] = vec[n - i - 1];
            vec[n - i - 1] = temp;
            inter++;
        }
    }
}
int maximo(int vec[],int n)
{
	if (n <= 0) return 0; /*verificacion de que haya n*/
    int maxi = vec[0];
    for (int i = 1; i < n; i++) 
	{
        if (vec[i] > maxi) maxi = vec[i];
    }
    return maxi;
}
void countingsort(int vec[],int n,int exp, int &comp, int &inter)
{
	int resul[n],cuenta[10] = {0};/*creamos un vector auxiliar y uno contador para cada digito(0-9)*/
	
	for(int i=0;i<n;i++)/*se cuenta cuantos elementos tienen cada digito en la posicion actual*/
	{
		cuenta[(vec[i]/exp) % 10]++; /*(vec[i]/exp)%10 da el digito relevante y se aumenta su frecuencia en el vector de cuenta*/
		comp++; /*contamos la deteccion del digito*/
	}
	
	for(int i=1;i<10;i++)/*se convierte el vector de frecuencias en acumalado de posiciones*/
	{
		cuenta[i]+= cuenta[i-1];
	}
	
	for (int i = n - 1; i >= 0; i--) /*reubicamos los elementos en el vector resultante, recorriendo de derecha a izquierda*/
	{
        resul[cuenta[(vec[i] / exp) % 10] - 1] = vec[i];
        cuenta[(vec[i] / exp) % 10]--;
        inter++;  // Movimiento de elemento
    }

    for (int i = 0; i < n; i++)/*Copiamos el vector ordenado en esta etapa de dígito*/
	{
        vec[i] = resul[i];
	}
}


