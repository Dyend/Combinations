#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int suma(int *permutaciones,int *marcas,int largo);
void mostrar(int *posibilidades,int largo,char *palabra);
long long posibilidadesNoRepetidas(int largo);


int main(){

    fflush(stdin);
    printf("Ingrese palabra\n");
    char palabra[100];
    int *posibilidades,largo,numero=0,posicion=0,i,*marcados,j;
    long long posibilidadesTotales;
    gets(palabra);
    largo=strlen(palabra);
    posibilidades=(int*)calloc(largo,sizeof(int));
    marcados=(int*)calloc(largo,sizeof(int));
    posibilidadesTotales=posibilidadesNoRepetidas(largo);

    i=0;

    while ((i)!=posibilidadesTotales){
        // posicion donde se efectuo la suma
        posicion=suma(posibilidades,marcados,largo);
        //si solo estan ocupadas 1 vez las letras, imprimo porque no hay repetidas
        numero=1;
        for(j=0;j<largo;j++){
            if(marcados[j]>1){
                numero=0;
                break;
            }
        }
        if(numero==1){
            i++;
            printf("Permutacion %d de %llu [",i,posibilidadesTotales);
            mostrar(posibilidades,largo,palabra);
        }
    }

    printf("\n\nSe han generado %llu combinaciones con la palabra %s\n",posibilidadesTotales,palabra);

    system("PAUSE");
    return 0;
}



int suma(int *permutaciones,int *marcas,int largo){
    int posicion=largo-1;

    while(1){

        if(permutaciones[posicion]<largo){
            // anoto que deje de usarla
            if(permutaciones[posicion]!=0){
                marcas[permutaciones[posicion]-1]--;
            }
            permutaciones[posicion]++;
            // anoto que estoy usando esta nueva letra
            marcas[permutaciones[posicion]-1]++;
            break;
        }
        else{
            // anoto que deje de usarla
            marcas[permutaciones[posicion]-1]--;
            // lo hago partir en 1 en vez de 0 porque sino me mostrara denuevo las permutaciones con de 1 caracter
            permutaciones[posicion]=1;
            marcas[permutaciones[posicion]-1]++;
            posicion=posicion-1;
        }
    }


    return posicion;
}

void mostrar(int *posibilidades,int largo,char *palabra){
    int posicion;
    for(posicion=0;posicion<largo;posicion++){
        if(posibilidades[posicion]!=0){
            printf("%c",palabra[posibilidades[posicion]-1]);
        }
    }
    printf("]\n");
}

long long posibilidadesNoRepetidas(int largo){
    int i,numero=1,j;
    long long totalPosibilidades=0;
    for(j=0;j<largo;j++){
        numero=1;
        for(i=largo;i>j;i--){
            numero=i*numero;
        }
        totalPosibilidades=totalPosibilidades+numero;
    }
    printf("total de combinaciones -> %llu\n",totalPosibilidades);
    system("PAUSE");
    return totalPosibilidades;

}


