#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    //Declaracion de variables
    char input[100];//varibale para guardar los argumentos
    int pid;//vairbale para el comando fork
    int status;//variable para la informacion del proceso secunadario
    int exit_status;//variable para almacenar el estado de salida el proceso hijo

    do{
	fflush(stdin);//Limpiamos el buffer de posbible basura 
        printf("Terminal2:~$ ");//Prompt a imprimir
	fflush(stdin);
        fgets(input, sizeof(input), stdin);//Guardamos el comando que quiere ejecutar el usuario
        input[strcspn(input, "\n")] = 0;//Limpiamos o quitamos de la candena el salto de linea
	//Con este if verificamos si el usuario quiere salir de la terminal2 por lo que ponemos un break 
        if ((strcmp(input, "exit") == 0) || (strcmp(input, "EXIT") == 0) || (strcmp(input, "Exit") == 0)){
           break;
        }

        pid = fork();//Cremaos un procecso nuevo
	//Posibles casos del fork

	switch(pid){
		case -1:
			printf("Error creando el proceso fork\n");
			exit(1);//El return 1 para reportar un problema
			break;
		case  0:
			//Funcion para remplazar la imagen del proceso acutual con una nueva para pasar los argumentos
			//de linea al archivo ejecutable
			if (execlp(input, input, NULL) < 0) {//En caso de que no se pueda ejecutar el comando devuelve -1
                		printf("Error en la ejecucion del comando, no se ha encontrado\n");
                		exit(1);
            		}
			break;
		default:
			//llamda al sistema para dejar que el proceso secundario sea ejecuado del archivo principal
			//deja que se haga el proceso secunadario primero si es 0 es correcto
			wait(&status);
			if (WIFEXITED(status)) {//determina si un proceso secundario termino normalmente se evalua distinto a 0 si es c
		                exit_status = WEXITSTATUS(status);//extrae el estado del proceso secundario
                		if (exit_status != 0) {
                    			printf("Error al ejectutar: %s , esta devuelto  %d\n", input, exit_status);
                		}
            		}
			break;
	}

    }while(1);

    return 0;
}
