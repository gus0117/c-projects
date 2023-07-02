#include <stdio.h>
#include <math.h>
/*
 en replit usar __fpurge en lugar de fflush
 y ademas incluir el siguiente header
#include <stdio_ext.h>
__fpurge(stdin);
*/
#define N 100

struct registro{
    int id, edad;
    char nombre[30], apellido[30];
    char sexo;
    float disp1, disp2, disp3, mejorDisp, promDisp;
};

int main(void)
{
    struct registro dato[N], aux;
    int i=0, j=0, k=0, idPart, contH=0, contM=0, edadHombreMx=0, edadMujeresMin=999;
    float auxDx, auxDy, auxMej, acumPromedio=0, promedioGeneral;

    printf("Nro de participante: ");
    scanf("%d", &idPart);

    //bucle de carga
    while(idPart != 999){
        dato[i].id = idPart;

        printf("Nombre: ");
        fflush(stdin);
        fgets(dato[i].nombre, 30, stdin);
        printf("Apellido: ");
        fflush(stdin);
        fgets(dato[i].apellido, 30, stdin);
        printf("Edad: ");
        scanf("%d", &dato[i].edad);
        printf("Sexo: ");
        fflush(stdin);
        scanf("%c", &dato[i].sexo);

        if(dato[i].sexo == 'm'){
            contH ++;

            if (dato[i].edad > edadHombreMx){
                edadHombreMx = dato[i].edad;
            }
        }else{
            contM ++;

            if (dato[i].edad < edadMujeresMin){
                edadMujeresMin = dato[i].edad;
            }
        }

        //ingreso de disparos
        printf("Disparo 1\n: ");
        printf("X: ");
        scanf("%f", &auxDx);
        printf("Y: ");
        scanf("%f", &auxDy);

        dato[i].disp1 = sqrt(pow(auxDx, 2)+pow(auxDy, 2));
        auxMej = dato[i].disp1;

        //ingreso de disparos
        printf("Disparo 2\n: ");
        printf("X: ");
        scanf("%f", &auxDx);
        printf("Y: ");
        scanf("%f", &auxDy);

        dato[i].disp2 = sqrt(pow(auxDx, 2)+pow(auxDy, 2));

        if (dato[i].disp2 < auxMej){
            auxMej = dato[i].disp2;
        }

        //ingreso de disparos
        printf("Disparo 3\n: ");
        printf("X: ");
        scanf("%f", &auxDx);
        printf("Y: ");
        scanf("%f", &auxDy);

        dato[i].disp3 = sqrt(pow(auxDx, 2)+pow(auxDy, 2));

        if (dato[i].disp3 < auxMej){
            auxMej = dato[i].disp3;
        }

        dato[i].mejorDisp = auxMej;
        dato[i].promDisp = (dato[i].disp1 + dato[i].disp2 + dato[i].disp3) / 3;

        acumPromedio = acumPromedio + dato[i].promDisp;


        i++;

        printf("Ingrese otro Nro de participante: ");
        scanf("%d", &idPart);

    }


    //punto a)
    for(j=0; j<i-1; j++)
        for(k=j+1; k<i; k++)
            if(dato[j].mejorDisp > dato[k].mejorDisp)
            {
                aux = dato[j];
                dato[j] = dato[k];
                dato[k] = aux;
            }

    for(j=0; j<3; j++){
        printf("%s %s %d %.2f %.2f %.2f\n", dato[j].apellido, dato[j].nombre, dato[j].edad,
               dato[j].disp1, dato[j].disp2, dato[j].disp3);
    }

    //punto b)
    printf("%s %s %d %.2f %.2f %.2f\n", dato[i-1].apellido, dato[i-1].nombre, dato[i-1].edad,
           dato[i-1].disp1, dato[i-1].disp2, dato[i-1].disp3);

    //punto c)
    printf("Cantidad de participantes: %d", i);

    //punto d)
    printf("Hombres: %d - Mujeres: %d", contH, contM);

    //punto e)
    printf("Hombre mas grande: %d", edadHombreMx);
    printf("Mujer mas joven: %d", edadMujeresMin);


    //punto f)
    for(j=0; j<i-1; j++)
        for(k=j+1; k<i; k++)
            if(dato[j].edad > dato[k].edad)
            {
                aux = dato[j];
                dato[j] = dato[k];
                dato[k] = aux;
            }
    
    for(j=0; j<i; j++){
        printf("%s %s %d %.2f %.2f %.2f\n", dato[j].apellido, dato[j].nombre, dato[j].edad,
               dato[j].disp1, dato[j].disp2, dato[j].disp3);
    }
    
    
    //punto g)
    promedioGeneral = acumPromedio/i;
    printf("Promedio de todos los disparos: %.2f", promedioGeneral);
    
    //punto h)
    for(j=0; j<i; j++)
    {
        if(dato[j].promDisp > promedioGeneral)
            printf("%s %s %d %.2f %.2f %.2f\n", dato[j].apellido, dato[j].nombre, dato[j].edad,
               dato[j].disp1, dato[j].disp2, dato[j].disp3);
    }

    //calculos
    for(j=0; j<i; j++){
        printf("%s %s %d %.2f %.2f %.2f\n", dato[j].apellido, dato[j].nombre, dato[j].edad,
               dato[j].disp1, dato[j].disp2, dato[j].disp3);
    }


    printf("\n\n");
    return 0;
}
