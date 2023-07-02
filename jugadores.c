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
    struct jugador aux; // jugador auxiliar que se utiliza para realizar el intercambio en el ordenamiento.
    int cant_jugadores = 0;
    int cant_goles = 0; // cantidad de goles que se realizaron en el torneo
    int cant_arqueros = 0; // Cantidad de arquerso que hay en el torneo
    int cant_goles_def = 0; // Cantidad de goles realizados por defensores (camisetas 2,3,4 y 6)

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
    printf("|   Nro   |   Nombre y apellido   |   Camiseta    |   Goles   |   Pases OK   |    Pases Totales    |   Minutos Totales    |    Posision   |\n");
    for (int i = 0; i < cant_jugadores; i++) {
        
        char posicion[10];
        if(jugadores[i].posicion == 'a'){
            strcpy(posicion, "Arquero");
        }
        else{
            strcpy(posicion, "Jugador");
        }
        printf("|   %d   |   %s   |   %d   |   %d   |   %d   |   %d   |   %d   |   %s   |\n", i + 1, jugadores[i].NyA, jugadores[i].nro, jugadores[i].goles, jugadores[i].pasesOk, jugadores[i].pasesTot, jugadores[i].minutosTotales, posicion);
    }
    
    // a. Ordenar por la cantidad de goles
    //Se crea una copia de los jugadores en ordenGoles
    
    for(int i = 0; i < cant_jugadores; i++){
        ordenGoles[i] = jugadores[i];
    }
    
    //Se ordena utilizando burbuja
    for(int j = 0; j < cant_jugadores - 1; j++){
        for(int k = j + 1; k < cant_jugadores; k++){
            if(ordenGoles[j].goles < ordenGoles[k].goles)
            {
                aux = ordenGoles[j];
                ordenGoles[j] = ordenGoles[k];
                ordenGoles[k] = aux;
            }
        }
    }
    
    //Se muestra los jugadores ordenados por goles
    printf("\nTabla de Goleadores\n");
    printf("|   Nro   |   Nombre y apellido   |   Goles   |\n");
    
    for (int i = 0; i < cant_jugadores && i < 5; i++) {
        printf("|   %d   |   %s   |   %d   |\n", i + 1, ordenGoles[i].NyA, ordenGoles[i].goles);
    }
    
    // b. Ordenar por la efectividad
    //Se crea una copia de los jugadores en ordenGoles
    
    for(int i = 0; i < cant_jugadores; i++){
        ordenEfectividad[i] = jugadores[i];
    }
    
    //Se ordena utilizando burbuja
    for(int j = 0; j < cant_jugadores - 1; j++){
        for(int k = j + 1; k < cant_jugadores; k++){
            if(ordenEfectividad[j].pasesOk / (ordenEfectividad[j].pasesTot * 100) < ordenEfectividad[k].pasesOk / (ordenEfectividad[k].pasesTot * 100))
            {
                aux = ordenEfectividad[j];
                ordenEfectividad[j] = ordenEfectividad[k];
                ordenEfectividad[k] = aux;
            }
        }
    }
    
    //Se muestra los jugadores ordenados por efectividad de pases
    printf("\nTabla de Goleadores\n");
    printf("|   Nro   |   Nombre y apellido   |   Pases Ok   |    pases Totales    |\n");
    
    for (int i = 0; i < cant_jugadores && i < 5; i++) {
        printf("|   %d   |   %s   |   %d   |    %d     |\n", i + 1, ordenEfectividad[i].NyA, ordenEfectividad[i].pasesOk, ordenEfectividad[i].pasesTot);
    }
    
    // Punto C, D y E
    //C => cant de goles; D => cant de arqueros; E => cant de goles por defensores (camisetas 2,3,4 y 6)
    for(int i = 0; i < cant_jugadores; i++){
        cant_goles += jugadores[i].goles;
        
        if(jugadores[i].posicion == 'a'){
            cant_arqueros ++;
        }
        
        //Se pregunta si es defensor y ademas si hizo goles
        if((jugadores[i].nro == 2 || jugadores[i].nro == 3 || jugadores[i].nro == 4 || jugadores[i].nro == 6) && jugadores[i].goles > 0){
            cant_goles_def += jugadores[i].goles; 
        }
    }
    
    printf("|   Goles Totales   |   Cantidad de arqueros   |   Goles cometidos por defensores   |\n");
    printf("|        %d         |      %d       |       %d        |\n", cant_goles, cant_arqueros, cant_goles_def);
    printf("¡Fin del programa!\n");

    return 0;
}