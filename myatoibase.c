//
// Created by Gianni GIUDICE on 15/02/2021.
//

#include <string.h>

int convert(char letter)
{
    if (letter == '!') {
        return 36;
    }
    if (letter >= '0' && letter <= '9') {
        return (int)letter - '0';
    }
    return (int)letter - 'a' + 10;
}

int checkPointerValidity(const char *ptr, const int base)
{
    int i;

    // Cas particulier : un - suivi d'un 0 => mauvaise entrée
    if (ptr[0] == '-' && strlen(ptr) > 1 && ptr[1] == '0') {
        return 0;
    }
    if (base <= 10) {
        for (i = 0; i < strlen(ptr); i++) {
            // On vérifie que chaque caractère est cohérent avec la base donnée
            if (!(ptr[i] >= '0' && ptr[i] < ('0' + base))) {
                // On fait une exception si c'est le premier caractère => - à la place d'un caractère de la base
                if (i != 0 && ptr[i] == '-') {
                    return 0;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < strlen(ptr); i++) {
            // On vérifie que chaque caractère est cohérent avec la base donnée
            if (!((ptr[i] >= '0' && ptr[i] < ('0' + base)) || (ptr[i] >= 'A' && ptr[i] < ('A' + base - 10)))) {
                // On fait une exception si c'est le premier caractère => - à la place d'un caractère de la base
                if (i != 0 && ptr[i] == '-') {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int myatoibase(const char *ptr, const int base)
{
    if (!ptr) {
        return 0;
    }

    if (!checkPointerValidity(ptr, base)) {
        return -1;
    }

    if (base < 2 || base > 37) {
        return -2;
    }

    int power = 1;
    int num = 0;
    int i;


    for (i = strlen(ptr) - 1; i >= 0; i--) {
        if (ptr[i] != '-') {
            if (convert(ptr[i]) >= base) {
                return -1;
            }
            num += convert(ptr[i]) * power;
            power = power * base;
        }
    }

    num = (ptr[0] == '-') ? (num * (-1)) : num;
    return num;
}

