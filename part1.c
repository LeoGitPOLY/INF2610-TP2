/*
 * processlab - part1.c
 *
 * Ecole polytechnique de Montreal, GIGL, Automne  2022
 * vos noms, prénoms et matricules
 * Aurelie Nichols -2142404
 */

#include "libprocesslab/libprocesslab.h"

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------

// -------------------------------------------------

void question1()
{
    printf("Level 0\n");

    if (fork() == 0)
    {
        printf("Level 1.1\n");

        if (fork() == 0)
        {
            printf("Level 2.1\n");
            _exit(0);
        }

        wait(NULL);
        _exit(0);
    }
    wait(NULL);
    
    if (fork() == 0)
    {
        printf("Level 1.2\n");

        if (fork() == 0)
        {
            printf("Level 2.2\n");
            _exit(0);
        }
        wait(NULL);
        if (fork() == 0)
        {
            printf("Level 2.3\n");
            _exit(0);
        }
        wait(NULL);
        _exit(0);
    }
    wait(NULL);

    if (fork() == 0)
    {
        printf("Level 1.3\n");

        if (fork() == 0)
        {
            printf("Level 2.4\n");
            _exit(0);
        }
        wait(NULL);
        if (fork() == 0)
        {
            printf("Level 2.5\n");
            _exit(0);
        }
        wait(NULL);
        if (fork() == 0)
        {
            printf("Level 2.6\n");
            _exit(0);
        }

        wait(NULL);
        _exit(0);
    }

    wait(NULL);
}
