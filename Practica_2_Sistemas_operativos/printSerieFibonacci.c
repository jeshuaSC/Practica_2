#include <stdio.h>
#include <stdlib.h>
/*Este programa imprime la serie de FIbonacci 
1 1 2 3 5 8 13 ...*/
int FIbonacci(int n);

int main(int argc, char *argv[]) {
	int i,num;
	printf("Ingresa hasta el elemento que desea conocer\n");
	scanf("%d", &num);
	//printf("0 ");
	for(i = 1; i<=num; i++){
		printf("%d ", FIbonacci(i));
	}
	printf("\n\n");
	return 0;
}

int FIbonacci(int n){
	if(n == 0 || n==1){
		return n;
	}
	else{
		return (FIbonacci(n-1) + FIbonacci(n-2));
		//Lo que hace basicamente esto es sumar las 2 posiciones anteriores como en la serie de FIbonacci
	}
}
