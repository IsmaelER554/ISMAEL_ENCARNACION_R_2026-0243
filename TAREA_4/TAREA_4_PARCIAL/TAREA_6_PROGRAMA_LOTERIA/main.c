#include <stdio.h>
#include <stdlib.h> /* Para poder usar la función rand() */

int main(void)
{
    int opcion = 0;
    int cantidad_jugadas = 1;
    int numero_jugado, dinero_jugado;
    int numero_ganador;
    int i;

    while (opcion != 3)
    {
        printf("\n========== LOTERIA ==========");
        printf("\n1. Jugar");
        printf("\n2. Cuantas veces deseas jugar? (Actual: %d)", cantidad_jugadas);
        printf("\n3. Salir");
        printf("\n=============================");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            /* Bucle para ejecutar la cantidad de jugadas seleccionadas */
            for (i = 0; i < cantidad_jugadas; i++)
            {
                printf("\n--- JUGADA %d DE %d ---", i + 1, cantidad_jugadas);

                /* Aqui especifico el rango de numeros en el que se puede jugar */
                printf("\nIngresa tu numero de la suerte (1 a 45): ");
                scanf("%d", &numero_jugado);

                while (numero_jugado < 1 || numero_jugado > 45)
                {
                    printf("Numero invalido. Recuerda que debe ser entre 1 y 45: ");
                    scanf("%d", &numero_jugado);
                }

                /* Entrada de la cantidad de dinero a jugar*/
                printf("Que cantidad de dinero deseas jugar?: ");
                scanf("%d", &dinero_jugado);

                while (dinero_jugado <= 0)
                {
                    printf("La cantidad debe ser mayor a 0. Ingresa el dinero: ");
                    scanf("%d", &dinero_jugado);
                }

                numero_ganador = (rand() % 45) + 1;
                printf("\nEl numero ganador de la loteria es: [%d]", numero_ganador);

                if (numero_jugado == numero_ganador)
                {
                    printf("\n¡Felicidades! Has ganado.");
                    printf("\nTu premio es: $%d\n", dinero_jugado * 1500);
                }
                else
                {
                    printf("\n¡Sigue intentando! Casi lo tienes\n");
                }
            }
        }
        else if (opcion == 2)
        {
            /* Con esto especifico la cantidad de jugadas */
            printf("\nIngresa la cantidad de jugadas que deseas realizar: ");
            scanf("%d", &cantidad_jugadas);

            while (cantidad_jugadas <= 0)
            {
                printf("Cantidad invalida. Debe ser por lo menos 1 jugada: ");
                scanf("%d", &cantidad_jugadas);
            }
            printf("¡Configurado! Ahora realizaras %d jugadas por turno.\n", cantidad_jugadas);
        }
        else if (opcion == 3)
        {
            printf("\nGracias por jugar Espero un 90 en la nota ;) Gracias y ¡Vuelva pronto!\n");
        }
        else
        {
            printf("\nOpcion no valida. Selecciona una opcion del 1 al 3.\n");
        }
    }

    return 0;
}
