#include <stdio.h>
#include <string.h>

void reverse_string(char nombre[])
{
    int length = 0;
    while (nombre[length] != '\0') {
        length = length + 1;
    }

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = nombre[i];
        nombre[i] = nombre[j];
        nombre[j] = temp;
    }
}

int main()
{
    char nombre[] = "DANIEL"; /// {'D','A','N','I','E','L','\0'}
    printf("%s\n", nombre);
    /// Aqui haces tu demadre o tu codigo -> {'L','E','I','N','A','D','\0'}
    /// al final se imprime LEINAD
    reverse_string(nombre);
    printf("%s\n", nombre);
}
