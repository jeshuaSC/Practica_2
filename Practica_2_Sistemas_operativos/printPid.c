#include <stdio.h>
#include <unistd.h>

int main() {
    printf("El pid del proceso es: %d\n", getpid());
    return 0;
}
