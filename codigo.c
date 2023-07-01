#include <stdio.h>

int main(void) {
	int cantVacaciones = 0, cantBasico = 0, cantSueldoBono = 0;
	int sueldo = 1; // se inicializa en 1 para entrar al bucle
	
	while(sueldo > 0){
		printf("Ingrese el sueldo basico (Ingrese 0 para salir): ");
    	scanf("%d", &sueldo);
    	if(sueldo > 0){ 
    		if(sueldo >= 100000){
    			cantBasico++;
    		}
    		int bono;
			printf("Ingrese el bono (Ingrese 0 si no recibe bono): ");
	    	scanf("%d", &bono);
    		int bonoSueldo = bono + sueldo;
    		if(bono != 0 && bonoSueldo >= 120000 && bonoSueldo <= 150000){
    			cantSueldoBono++;
    		}
    		int vacaciones;
			printf("Ingrese dias de vacaciones (Ingrese 0 si no tomo vacaciones): ");
	    	scanf("%d", &vacaciones);
	    	if(vacaciones >= 0){
	    		cantVacaciones++;
	    	}
    	}
    	
	}
	
	printf("Cantidad de empleados que tomaron vacaciones: %d\n", cantVacaciones);
	printf("Cantidad de empleados con sueldo mayor a 100000: %d\n", cantBasico);
	printf("Cantidad de empleados con sueldo + bono entre 120000 y 150000: %d\n", cantSueldoBono);
	
	return 0;
}