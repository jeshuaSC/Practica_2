#include <stdio.h>
#include <unistd.h>

int main() {
    printf("El pid del grupo es: %d\n", getpgrp());
    return 0;
}
