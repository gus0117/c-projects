#include <stdio.h>
#include <string.h>

#define MAX_JUGADORES 35

struct jugador {
    char NyA[50]; //Nombre y Apellido
    int nro; //Numero de Camiseta
    int goles; //Goles totales
    int pasesOk; //Pases acertados
    int pasesTot; // Pases totales
    int minutosTotales; //cantidad de minutos jugados
    char posicion; //'a' arquero - 'j' jugador
};

int main() {
    struct jugador jugadores[MAX_JUGADORES];
    struct jugador ordenGoles[MAX_JUGADORES];
    struct jugador ordenEfectividad[MAX_JUGADORES];
    
    int cant_jugadores = 0;

    while (cant_jugadores < MAX_JUGADORES) {
        printf("Ingrese nombre y apellido (o 'fin' para salir): ");
        fgets(jugadores[cant_jugadores].NyA, sizeof(jugadores[cant_jugadores].NyA), stdin);
        jugadores[cant_jugadores].NyA[strcspn(jugadores[cant_jugadores].NyA, "\n")] = '\0';  // Eliminar el carácter de nueva línea

        if (strcmp(jugadores[cant_jugadores].NyA, "fin") == 0) {
            break;  // Salir del bucle si se ingresa "fin"
        }

        printf("Ingrese el numero de camiseta: ");
        scanf("%d", &jugadores[cant_jugadores].nro);
        getchar();
        
        printf("Ingrese goles totales: ");
        scanf("%d", &jugadores[cant_jugadores].goles);
        getchar();
        
        printf("Ingrese cantidad de pases acertados: ");
        scanf("%d", &jugadores[cant_jugadores].pasesOk);
        getchar();
        
        printf("Ingrese cantidad de pases totales: ");
        scanf("%d", &jugadores[cant_jugadores].pasesTot);
        getchar();
        
        printf("Ingrese minutos totales: ");
        scanf("%d", &jugadores[cant_jugadores].minutosTotales);
        getchar();
        
        printf("Ingrese la posicion del jugador: ");
        scanf("%c", &jugadores[cant_jugadores].posicion);
        getchar();

        cant_jugadores++;
    }

    printf("\nJugadores ingresados:\n");

    for (int i = 0; i < cant_jugadores; i++) {
        printf("Nombre y apellido: %s\n", jugadores[i].NyA);
        printf("Número de camiseta: %d\n", jugadores[i].nro);
        printf("Goles totales: %d\n", jugadores[i].goles);
        printf("Pases acertados: %d\n", jugadores[i].pasesOk);
        printf("Pases totales: %d\n", jugadores[i].pasesTot);
        printf("Minutos totales: %d\n", jugadores[i].minutosTotales);
        if(jugadores[i].posicion == 'a'){
            printf("Posicion: %s\n\n", "arquero");
        }
        if(jugadores[i].posicion == 'j'){
            printf("Posicion: %s\n\n", "jugador");
        }
        
    }
    
    // a. Ordenar por la cantidad de goles
    // Se crea una copia ordenada por goles de los jugadores
    int cant_goleadores = 0;
    for(int i = 0; i < cant_jugadores; i++){
        int posAgregar = 0; // Posicion del arreglo donde se guardara el jugador
        for(int j = 0; j < cant_goleadores; j++){ // se compara el nuevo jugador con los que ya estan guardados y ordenados
            if(jugadores[i].goles > ordenGoles[j].goles){
                posAgregar = j; // Guardo esta posicion para guardar el jugador
                for(int k = cant_goleadores; k > j; k--){ //Se mueven todos los elementos hacia fondo del arreglo
                    ordenGoles[k] = ordenGoles[k - 1];
                }
            }
        }
        ordenGoles[posAgregar] = jugadores[i]; //Se guarda el jugador
    }
    
    //Se muestra los jugadores ordenados por goles
    for (int i = 0; i < cant_jugadores; i++) {
        printf()
        printf("Nombre y apellido: %s\n", jugadores[i].NyA);
        printf("Número de camiseta: %d\n", jugadores[i].nro);
        printf("Goles totales: %d\n", jugadores[i].goles);
        printf("Pases acertados: %d\n", jugadores[i].pasesOk);
        printf("Pases totales: %d\n", jugadores[i].pasesTot);
        printf("Minutos totales: %d\n", jugadores[i].minutosTotales);
        if(jugadores[i].posicion == 'a'){
            printf("Posicion: %s\n\n", "arquero");
        }
        if(jugadores[i].posicion == 'j'){
            printf("Posicion: %s\n\n", "jugador");
        }
        
    }
    printf("¡Fin del programa!\n");

    return 0;
}