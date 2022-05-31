#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bil.h"
#define max 3 // limite de cadastro
int main()
{

    int opc, loop = 0, resultImport;
    resultImport = importPlayers("jogadores.txt");
    if (resultImport<=0) {
        printf("There is no players saved in external file jogadores.txt...\n");
    } else {
        loop = resultImport;
    }
    sleep(6);

    do
    {
        system("clear");
        printf("-The Escapist Game-\n1-jogar\n2-Ranking\n3-Creditos\n0-Sair\nescolha uma das opcoes=");
        scanf("%d", &opc);
        getchar();
        system("clear");
        switch (opc)
        {
        case 1:
            if (registro(loop) == 0 && loop<max) // caso o resgistro retorne como 0 ele add um loop
            {
                loop++;
            }
            printf("---Em construcao---\n");
            break;
        case 2:
            rank(loop); // mostrara o ranking do jogo ordenado
            break;
        case 3:
            criadores();
            break;
        case 0:
            continue;
            opc = 2;
        }
        printf("voltar=");
        scanf("%d", &opc);
    } while (opc == 1);
}
