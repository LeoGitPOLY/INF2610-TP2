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

int counter()
{
    int status;
    int childCount = 0;
    while (wait(&status) > 0)
    {
        childCount++;
    }
    return childCount;
}
void question1()
{
    printf("Level 0\n");
    registerProc(getpid(), getppid(), 0, 0);

    if (fork() == 0)
    {
        printf("Level 1.1\n");
        registerProc(getpid(), getppid(), 1, 1);

        if (fork() == 0)
        {
            printf("Level 2.1\n");
            registerProc(getpid(), getppid(), 2, 1);
            _exit(0);
        }
        counter();
        wait(NULL);
        _exit(0);
    }
    wait(NULL);

    if (fork() == 0)
    {
        printf("Level 1.2\n");
        registerProc(getpid(), getppid(), 1, 2);

        if (fork() == 0)
        {
            printf("Level 2.2\n");
            registerProc(getpid(), getppid(), 2, 2);
            _exit(0);
        }
        if (fork() == 0)
        {
            printf("Level 2.3\n");
            registerProc(getpid(), getppid(), 2, 3);
            _exit(0);
        }
        counter();
        wait(NULL);
        _exit(0);
    }
    wait(NULL);

    if (fork() == 0)
    {
        printf("Level 1.3\n");
        registerProc(getpid(), getppid(), 1, 3);

        if (fork() == 0)
        {
            printf("Level 2.4\n");
            registerProc(getpid(), getppid(), 2, 4);
            _exit(0);
        }
        if (fork() == 0)
        {
            printf("Level 2.5\n");
            registerProc(getpid(), getppid(), 2, 5);
            _exit(0);
        }
        if (fork() == 0)
        {
            printf("Level 2.6\n");
            registerProc(getpid(), getppid(), 2, 6);
            _exit(0);
        }
        counter();
        wait(NULL);
        _exit(0);
    }
    
    printf("Number of children: %d\n", counter());
    printProcRegistrations();
}
