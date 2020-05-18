#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 8
#define TAMNOT 3

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;

} eNootBook;

float aplicarDescuento(float precio);
int contarCaracteres(char caracter1[], char caracter2, int tam);
void ordenarNootbooks(eNootBook x[], int tamnot);

int main()
{

    float precio;
    float descuento;
    char caracterABuscar;
    char caracter1[TAM] = {'a','b','a','c', 'a', 'a'};
    int vecesCaracter;
    eNootBook notebooks[TAMNOT]= {{1000, "QQCC", "Sony", 20000}, {1000, "QQCC", "ASUS", 10000}, {1000, "QQCC", "ASUS", 40000}};

    printf("----Ejercicio de Descuento----\n\n");

    printf("Ingrese precio: ");
    scanf("%f", &precio);

    descuento = aplicarDescuento(precio);

    printf("Precio con descuento: %.2f\n\n", descuento);

     printf("----Ejercicio de Caracteres----\n\n");

    printf("Ingrese caracter a buscar: ");
    fflush(stdin);
    scanf("%c", &caracterABuscar);

    vecesCaracter = contarCaracteres(caracter1, caracterABuscar, TAM);

    printf("Aparece %d veces el caracter buscado\n\n", vecesCaracter);

     printf("----Ejercicio de NoteBooks----\n\n");

    printf("---------Notebooks----------\n\n");
    printf("ID      Procesador    Marca     Precio\n");
    for(int i=0; i<TAMNOT; i++)
    {

        printf("%d       %s       %s     %.2f\n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);

    }

    ordenarNootbooks(notebooks, TAMNOT);

    printf("---------Notebooks----------\n\n");
    printf("ID      Procesador    Marca     Precio\n");
    for(int i=0; i<TAMNOT; i++)
    {

        printf("%d       %s       %s     %.2f\n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);

    }
}

float aplicarDescuento(float precio)
{

    float precioDescuento;

    precioDescuento =  precio * 5 / 100;

    precioDescuento = precio - precioDescuento;

    return precioDescuento;

}

int contarCaracteres(char caracter1[], char caracter2, int tam)
{

    int veces;

    for(int i = 0; i < tam; i++)
    {

        if(caracter2 == caracter1[i])
        {

            veces++;

        }

    }

    return veces;

}

void ordenarNootbooks(eNootBook x[], int tamnot)
{

    eNootBook aux;

    printf("\n\n----Ordenar-----\n\n");

    for(int i = 0; i < tamnot - 1; i++)
    {

        for(int j = i + 1; j < tamnot; j++)
        {

            if(strcmp(x[i].marca, x[j].marca)>0)
            {

                aux = x[j];
                x[j] = x[i];
                x[i] = aux;


            }

            if( x[i].precio < x[j].precio && strcmp(x[i].marca, x[j].marca)==0)
            {

                aux = x[j];
                x[j] = x[i];
                x[i] = aux;


            }
        }
    }

}
