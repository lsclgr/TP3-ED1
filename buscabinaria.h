#ifndef BUSCABINARIA_H
#define BUSCABINARIA_H

typedef struct {
    int rapaziada;
    double litrao;
    double piraioMenor;
    double piraioMaior;
    double piraiodabusca;
    double agazao;
    double agazinho;
    double volume;
} Copo;

void calculaVolumedoCopo(Copo *coquinhaGelada);
void fazABuscaAi(Copo *coquinhaGelada);

#endif