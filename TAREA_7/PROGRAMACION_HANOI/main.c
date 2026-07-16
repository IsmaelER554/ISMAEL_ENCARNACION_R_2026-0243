#include <stdio.h>
#include <stdlib.h>

int contadorMovimientos = 0;

void moverTorres(int n, char origen, char destino, char auxiliar, FILE *archivo) {

    if (n == 1) {

        contadorMovimientos++;
        printf("Movimiento %d: mover disco 1 de %c a %c\n", contadorMovimientos, origen, destino);
        fprintf(archivo, "Movimiento %d: mover disco 1 de %c a %c\n", contadorMovimientos, origen, destino);
        return;
    }

    moverTorres(n - 1, origen, auxiliar, destino, archivo);

    contadorMovimientos++;
    printf("Movimiento %d: mover disco %d de %c a %c\n", contadorMovimientos, n, origen, destino);
    fprintf(archivo, "Movimiento %d: mover disco %d de %c a %c\n", contadorMovimientos, n, origen, destino);

    moverTorres(n - 1, auxiliar, destino, origen, archivo);
}

int main() {
    int discos;

    printf("===== Torres de Hanoi =====\n");
    printf("Ingrese la cantidad de discos: ");
    scanf("%d", &discos);

    if (discos < 1) {
        printf("La cantidad de discos debe ser mayor a 0\n");
        return 1;
    }

    FILE *archivo = fopen("movimientos.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo movimientos.txt\n");
        return 1;
    }

    printf("\nVarilla A = origen, Varilla B = destino, Varilla C = auxiliar\n\n");

    moverTorres(discos, 'A', 'B', 'C', archivo);

    fclose(archivo);

    printf("\nSe completo la Torre de Hanoi con %d discos\n", discos);
    printf("Total de movimientos: %d\n", contadorMovimientos);
    printf("Los movimientos se guardaron en movimientos.txt\n");

    return 0;
}
