#include <stdio.h>
#include <string.h>

struct Jugador{
    char NyA[51]; //Nombre y Apellido
    int nro; // Numero de camiseta
    int goles; // Goles totales
    int pasesOk; //Pases acertados
    int pasesTot; // pases totales
    int minutosTotales; // Cantidad de minutos Jugados
    char posicion; // 'a' aquero - 'j' jugador
};


int main()
{
    struct Jugador jugadores[35];
    int i = 0;
    int continuar = 0;
    while(i < 35 && continuar == 0){
        char nombreAux[51];
        printf("Ingresa tu nombre y apellido: ");
        fgets(nombreAux, sizeof(nombreAux), stdin);
        
        // Elimina el carácter de nueva línea del final de la cadena ingresada
        nombreAux[strcspn(nombreAux, "\n")] = '\0';
        
        if(strcmp(nombreAux, "fin") != 0){
            strcpy(jugadores[i].NyA, nombreAux);
            
            printf("Ingresa el numero de camiseta: ");
            scanf("%d", &jugadores[i].nro);
        }
        else{
            continuar = 1; // Se termina el bucle
        }
        
        i++;
    }
    
    //Mostrar los jugadores
    for(int i = 0; i < 35; i++){
        printf("Datos del jugador:\n", i);
        printf("Nombre y Apellido: %s\n", jugadores[i].NyA);
        printf("Numero de camiseta: %d\n", jugadores[i].nro);
    }
    
    return 0;
}
