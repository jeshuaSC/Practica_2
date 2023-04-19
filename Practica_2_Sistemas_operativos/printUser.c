#include <stdio.h>
#include <unistd.h>

int main() {
    printf("El pid del usuario es: %d\n", getuid());
    return 0;
}
