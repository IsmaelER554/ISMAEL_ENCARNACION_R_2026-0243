#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    char apellido[50];
    float promedio;
    char materia[50];
} Alumno;

int leerCantidad(FILE *archivo) {
    char linea[200];
    int cantidad = 0;

    while (fgets(linea, sizeof(linea), archivo)) {
        if (strstr(linea, "<cantidad>")) {
            sscanf(linea, " <cantidad>%d</cantidad>", &cantidad);
            break;
        }
    }
    return cantidad;
}

void leerXML() {
    FILE *archivo = fopen("alumnos.xml", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo XML\n");
        return;
    }

    int cantidad = leerCantidad(archivo);
    if (cantidad <= 0) {
        printf("No se encontro una cantidad valida en el XML\n");
        fclose(archivo);
        return;
    }
    printf("Cantidad de alumnos declarada en el XML: %d\n", cantidad);

    Alumno *alumnos = (Alumno *) malloc(cantidad * sizeof(Alumno));
    if (alumnos == NULL) {
        printf("Error al reservar memoria\n");
        fclose(archivo);
        return;
    }

    int i = -1;
    char linea[200];
    while (fgets(linea, sizeof(linea), archivo) && i < cantidad) {
        if (strstr(linea, "<Alumno>")) {
            i++;
            if (i >= cantidad) break;
        } else if (i >= 0 && strstr(linea, "<Nombre>")) {
            sscanf(linea, " <Nombre>%49[^<]", alumnos[i].nombre);
        } else if (i >= 0 && strstr(linea, "<Apellido>")) {
            sscanf(linea, " <Apellido>%49[^<]", alumnos[i].apellido);
        } else if (i >= 0 && strstr(linea, "<Promedio>")) {
            sscanf(linea, " <Promedio>%f", &alumnos[i].promedio);
        } else if (i >= 0 && strstr(linea, "<Materia>")) {
            sscanf(linea, " <Materia>%49[^<]", alumnos[i].materia);
        }
    }

    fclose(archivo);

    printf("\n--- Alumnos (XML) ---\n");
    for (int j = 0; j < cantidad; j++) {
        printf("Alumno %d: %s %s - Promedio: %.2f - Materia: %s\n",
               j + 1, alumnos[j].nombre, alumnos[j].apellido,
               alumnos[j].promedio, alumnos[j].materia);
    }

    free(alumnos);
}

int main() {
    leerXML();

    printf("\nPresione Enter para salir...");
    getchar();
    return 0;
}
