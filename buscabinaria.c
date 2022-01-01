#include "buscabinaria.h"

#include <math.h>
#include <stdio.h>
#define PI 3.14159265

void calculaVolumedoCopo(Copo *coquinhaGelada) {
    coquinhaGelada->volume =
        ((PI * coquinhaGelada->agazinho) / 3) *
        ((coquinhaGelada->piraiodabusca * coquinhaGelada->piraioMenor) +
         (coquinhaGelada->piraiodabusca * coquinhaGelada->piraiodabusca) +
         (coquinhaGelada->piraioMenor * coquinhaGelada->piraioMenor));
}

void fazABuscaAi(Copo *coquinhaGelada) {
    double volumeArredondado;
    do {
        calculaVolumedoCopo(coquinhaGelada);
        volumeArredondado =
            round(coquinhaGelada->volume * coquinhaGelada->rapaziada);
        // printf("volume: %lf\n", coquinhaGelada->litrao);
        printf("volume calculado: %lf\n", volumeArredondado);

        if (volumeArredondado > coquinhaGelada->litrao) {
            coquinhaGelada->agazao = coquinhaGelada->agazinho;
            coquinhaGelada->piraioMaior = coquinhaGelada->piraiodabusca;
            coquinhaGelada->agazinho = (coquinhaGelada->agazinho / 2.0);
            // round((coquinhaGelada->agazinho / 2.0) * 100) / 100;
            // arredondar
            printf("agazinho 1: %lf\n", coquinhaGelada->agazinho);
            coquinhaGelada->piraiodabusca =
                (coquinhaGelada->piraiodabusca + coquinhaGelada->piraioMenor) /
                2.0;
            // coquinhaGelada->piraiodabusca =  
            //     round(coquinhaGelada->piraiodabusca * 100) / 100;
            printf("piraio busca 1: %lf\n", coquinhaGelada->piraiodabusca);
        } else if (volumeArredondado < coquinhaGelada->litrao) {
            coquinhaGelada->agazinho =
                (coquinhaGelada->agazao + coquinhaGelada->agazinho) / 2.0;
            // coquinhaGelada->agazinho =
            //     round(coquinhaGelada->agazinho * 100) / 100;
            printf("agazinho 2: %lf\n", coquinhaGelada->agazinho);
            coquinhaGelada->piraiodabusca =
                (coquinhaGelada->piraiodabusca + coquinhaGelada->piraioMaior) /
                2.0;
            // coquinhaGelada->piraiodabusca =
            //     round(coquinhaGelada->piraiodabusca * 100) / 100;
            printf("piraio busca 2: %lf\n", coquinhaGelada->piraiodabusca);
        }
        printf("piraio menor: %lf\n", coquinhaGelada->piraioMenor);

    } while (volumeArredondado != coquinhaGelada->litrao);
}