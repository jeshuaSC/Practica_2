#include <stdio.h>
#include <unistd.h>

int main() {
    printf("El pid del proceso padre es: %d\n", getppid());
    return 0;
}
