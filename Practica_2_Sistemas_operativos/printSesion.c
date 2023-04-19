#include <stdio.h>
#include <unistd.h>

int main() {
    printf("El pid de la sesion es: %d\n", getsid());
    return 0;
}
