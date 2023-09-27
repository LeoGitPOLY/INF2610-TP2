/*
 * processlab - part2.c
 *
 * Ecole polytechnique de Montreal, GIGL, Automne  2022
 * vos noms, prénoms et matricules
 */

// TODO
// Si besoin, ajouter ici les directives d'inclusion
// -------------------------------------------------

// -------------------------------------------------

#include "./libprocesslab/libprocesslab.h"

#define m 1000000
// question2 calcule la somme des m premiers nombres naturels 1+2+...+m

// nb est le nombre de threads qui vont contribuer au calcul
#define nb 4

// tableau somme est utilisé pour le calcul des sommes patielles par les threads
long somme[nb];

// fonction exécutée par chaque thread créé
void *contribution(void *p)
{
  printf("Thread %d de tid=%lu \n", *((int *)p), pthread_self());
  int indexThread = *((int *)p);
  long startingValue = indexThread * m / nb + 1;
  long endingValue = (indexThread + 1) * m / nb;
  long result = 0;

  for (long i = startingValue; i <= endingValue; i++)
  {
    result += i;
  }

  somme[indexThread] = result;
  return NULL;
}

void question2()
{
  pthread_t *tid = malloc(nb * sizeof(pthread_t));
  int num[4] = {0, 1, 2, 3};

  for (int i = 0; i < nb; i++)
  {
    pthread_create(&tid[i], NULL, contribution, (void *)&num[i]);
  }

  long sommeTot = 0;
  long wantedResult = m * (long)(m + 1) / 2;

  for (int i = 0; i < nb; i++)
  {
    pthread_join(tid[i], NULL);
    sommeTot += somme[i];
  }

  printf("somme[0] + ... + somme[nb − 1] = %ld \n", sommeTot);
  printf("m ∗ (m + 1)/2 = %ld \n", wantedResult);
}
