#include <math.h>
#include <stdio.h>

#include "buscabinaria.h"

int main() {
    int nCasos;
    Copo coquinhaGelada;
    scanf("%d", &nCasos);
    for (int i = 0; i < nCasos; i++) {
        scanf("%d%lf", &coquinhaGelada.rapaziada, &coquinhaGelada.litrao);
        scanf("%lf%lf%lf", &coquinhaGelada.piraioMenor,
              &coquinhaGelada.piraioMaior, &coquinhaGelada.agazao);
        coquinhaGelada.piraiodabusca = coquinhaGelada.piraioMaior;
        coquinhaGelada.agazinho = coquinhaGelada.agazao;

        fazABuscaAi(&coquinhaGelada);
        // coquinhaGelada.agazinho = round(coquinhaGelada.agazinho * 100) / 100;
        printf("%.2lf\n", coquinhaGelada.agazinho);
    }
    return 0;
}