#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int main() {
    char input[100];
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int frequencies[5] = {440, 460, 480, 500, 520};
    int melody[100];
    int melodyLength = 0;

    printf("Ingrese una cadena: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        for (int j = 0; j < 5; j++) {
            if (input[i] == vowels[j]) {
                printf("Vocal detectada: %c\n", input[i]);

                #ifdef _WIN32
                    Beep(frequencies[j], 500);
                #else
                    // Código para Linux
                    usleep(500000); // Espera en microsegundos
                    printf("Frecuencia: %d\n", frequencies[j]);
                #endif

                melody[melodyLength] = frequencies[j];
                melodyLength++;
            }
        }
    }

    printf("Melodía generada: ");
    for (int i = 0; i < melodyLength; i++) {
        printf("%d ", melody[i]);
    }
    printf("\n");

    return 0;
}