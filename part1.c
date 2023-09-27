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

int CountAllChild()
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
    // Level 0
    registerProc(getpid(), getppid(), 0, 0);

    if (fork() == 0)
    {
        // Level 1.1
        registerProc(getpid(), getppid(), 1, 1);

        if (fork() == 0)
        {
            // Level 2.1
            registerProc(getpid(), getppid(), 2, 1);
            _exit(0);
        }
        CountAllChild();
        _exit(0);
    }
    wait(NULL);

    if (fork() == 0)
    {
        // Level 1.2
        registerProc(getpid(), getppid(), 1, 2);

        if (fork() == 0)
        {
            // Level 2.2
            registerProc(getpid(), getppid(), 2, 2);
            _exit(0);
        }
        if (fork() == 0)
        {
            // Level 2.3
            registerProc(getpid(), getppid(), 2, 3);
            _exit(0);
        }
        CountAllChild();
        _exit(0);
    }
    wait(NULL);

    if (fork() == 0)
    {
        // Level 1.3
        registerProc(getpid(), getppid(), 1, 3);

        if (fork() == 0)
        {
            // Level 2.4
            registerProc(getpid(), getppid(), 2, 4);
            _exit(0);
        }
        if (fork() == 0)
        {
            // Level 2.5
            registerProc(getpid(), getppid(), 2, 5);
            _exit(0);
        }
        if (fork() == 0)
        {
            // Level 2.6
            registerProc(getpid(), getppid(), 2, 6);
            _exit(0);
        }
        CountAllChild();
        _exit(0);
    }

    printf("Number of children: %d\n", CountAllChild());
    printProcRegistrations();
    execl("/usr/bin/ls", "ls", "-l", NULL);
}
