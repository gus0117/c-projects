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
    int cant_jugadores = 0;

    while (cant_jugadores < MAX_JUGADORES) {
        printf("Ingrese un NyA (o 'fin' para salir): ");
        fgets(jugadores[cant_jugadores].NyA, sizeof(jugadores[cant_jugadores].NyA), stdin);
        jugadores[cant_jugadores].NyA[strcspn(jugadores[cant_jugadores].NyA, "\n")] = '\0';  // Eliminar el carácter de nueva línea

        if (strcmp(jugadores[cant_jugadores].NyA, "fin") == 0) {
            break;  // Salir del bucle si se ingresa "fin"
        }

        printf("Ingrese el numero de camiseta: ");
        scanf("%d", &jugadores[cant_jugadores].nro);
        getchar();  // Capturar el carácter de nueva línea después de scanf

        cant_jugadores++;
    }

    printf("\nJugadores ingresados:\n");

    for (int i = 0; i < cant_jugadores; i++) {
        printf("Nombre y apellido: %s\n", jugadores[i].NyA);
        printf("Número de camiseta: %d\n\n", jugadores[i].nro);
    }

    printf("¡Fin del programa!\n");

    return 0;
}
