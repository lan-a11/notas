#include <stdio.h>
#include <string.h>

int main() {
    int opcion, cont = 0;
    char nombre[5][30], asignaturas[3][30];
    int notas[5][3];
    float promedioEstudiante[5];
    float promedioAsignatura[3];
    int nota_max[3], nota_min[3];
    char estudiante_max[3][30], estudiante_min[3][30];
    int i, j;

    do {
        printf("\n\t===== MENU DE OPCIONES =====\n");
        printf("\t1. Ingresar materias\n");
        printf("\t2. Ingresar nombres y notas de estudiantes\n");
        printf("\t3. Mostrar resultados por asignatura\n");
        printf("\t4. Mostrar resultados por estudiante\n");
        printf("\t5. Salir\n");
        printf("\tSeleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("\n\tError: Ingrese un numero valido.\n");
            while (getchar() != '\n');
            continue;
        }

        switch(opcion) {
            case 1:
                printf("\nIngrese los nombres de las 3 asignaturas:\n");
                for (j = 0; j < 3; j++) {
                    printf("Asignatura %d: ", j + 1);
                    fflush(stdin);
                    fgets(asignaturas[j], 30, stdin);
                    asignaturas[j][strlen(asignaturas[j]) - 1] = '\0';
                }
                break;

            case 2:
                for(i = 0; i < 5; i++) {
                    printf("\nIngrese el nombre del estudiante %d: ", i + 1);
                    fflush(stdin);
                    fgets(nombre[i], 30, stdin);
                    nombre[i][strlen(nombre[i]) - 1] = '\0';

                    for(j = 0; j < 3; j++) {
                        do {
                            printf("Ingrese la nota de %s en %s (0 a 10): ", nombre[i], asignaturas[j]);
                            if (scanf("%d", &notas[i][j]) != 1 || notas[i][j] < 0 || notas[i][j] > 10) {
                                printf("\tError: La nota debe estar entre 0 y 10.\n");
                                while (getchar() != '\n');
                            } else {
                                break;
                            }
                        } while(1);
                    }
                }
                break;

            case 3:
                printf("\nResultados por asignatura:\n");
                printf("#\tAsignatura\tPromedio\tNota Maxima\tEstudiante Max\tNota Minima\tEstudiante Min\n");
                for(j = 0; j < 3; j++) {
                    int suma = 0;
                    nota_max[j] = notas[0][j];
                    nota_min[j] = notas[0][j];
                    strcpy(estudiante_max[j], nombre[0]);
                    strcpy(estudiante_min[j], nombre[0]);
                    for(i = 0; i < 5; i++) {
                        suma += notas[i][j];
                        if(notas[i][j] > nota_max[j]) {
                            nota_max[j] = notas[i][j];
                            strcpy(estudiante_max[j], nombre[i]);
                        }
                        if(notas[i][j] < nota_min[j]) {
                            nota_min[j] = notas[i][j];
                            strcpy(estudiante_min[j], nombre[i]);
                        }
                    }
                    promedioAsignatura[j] = (float)suma / 5;
                    printf("%d\t%s\t%.2f\t\t%d\t\t%s\t\t%d\t\t%s\n", j + 1, asignaturas[j], promedioAsignatura[j], 
                        nota_max[j], estudiante_max[j], nota_min[j], estudiante_min[j]);
                }
                break;

            case 4:
                printf("\nResultados por estudiante:\n");
                printf("#\tNombre\t\tPromedio\tEstado\n");
                for(i = 0; i < 5; i++) {
                    int suma = 0;
                    for(j = 0; j < 3; j++) {
                        suma += notas[i][j];
                    }
                    promedioEstudiante[i] = (float)suma / 3;
                    printf("%d\t%s\t\t%.2f\t\t", i + 1, nombre[i], promedioEstudiante[i]);
                    if(promedioEstudiante[i] >= 6) {
                        printf("Aprobado\n");
                    } else {
                        printf("Reprobado\n");
                    }
                }
                break;

            case 5:
                printf("\n\tfin de programa.\n");
                break;

            default:
                printf("\n\tOpcion no valida.\n");
        }

    } while(opcion != 5);

    return 0;
}
