#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 3 // limite de cadastro
#include "bil.h"
typedef struct
{
    int pontos;
    char nome[10];
} reg_jogador;        // guardar os dados do jogador
reg_jogador reg[max]; // vetor principal usado
int findUser(char name[10], int untilPos);
void ordenacao(int l);
int exportPlayers(char *path, int playersCount);
int importPlayers(char *path);
void insertionSort(reg_jogador player);
void moveToRight(int pos);
void moveToLeft(int pos);

////////////////////////
int registro(int l)
{
    char nomeaux[10];            // nome auxiliar
    int pontosaux, userRepeated; // ponto auxiliar e variavel para confirmar o return
    printf("nome e pontuacao\nnome=");
    fgets(nomeaux, 10, stdin); // guarda o nome no nme aux
    printf("pontos=");
    scanf("%d", &pontosaux); // guarda os pontos no
    getchar();
    system("clear");
    userRepeated = findUser(nomeaux, l);
    if (userRepeated > -1)
    {
        moveToLeft(userRepeated);
    }
    // novo V
    reg_jogador novUser;
    novUser.pontos = pontosaux;
    strcpy(novUser.nome, nomeaux);
    insertionSort(novUser);
    if (exportPlayers("jogadores.txt", l+1) == -1) {
        printf("Panic ERROR...");
        exit(1);
    }
    return userRepeated+1;
}
//////////////////////////////////////////////////////////////////
void rank(int l)
{
    int opc;
    for (int i = 0; i < l; i++)
    {
        printf("%d\t%d\t\t%s\n", i + 1, reg[i].pontos, reg[i].nome);
    }
    //
    printf("deseja jogar com algum save ou criar novo jogo=");
    scanf("%d", &opc);
    getchar();
    if (opc == 1)
    {
        registro(l);
    }
    else
    {
        registro(l);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void criadores()
{
    printf("criadores do jogo\n-Lay's\n-Pablo\n-Hassan\n-Lucas\n");
}

int findUser(char name[10], int untilPos) // procura no vetor se ja existe um registro com o mesmo nome
{
    for (int i = 0; i < untilPos; i++)
    {
        if (strcmp(reg[i].nome, name) == 0)
        {

            return i;
        }
    }
    return -1;
}

void ordenacao(int l)
{

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l - 1; j++)
        {
            if (reg[j].pontos < reg[j + 1].pontos)
            {
                char tnome[10];
                strcpy(tnome, reg[j].nome);
                strcpy(reg[j].nome, reg[j + 1].nome);
                strcpy(reg[j + 1].nome, tnome);
                int aux = reg[j].pontos;
                reg[j].pontos = reg[j + 1].pontos;
                reg[j + 1].pontos = aux;
            }
        }
    }
}

int exportPlayers(char *path, int playersCount)
{
    FILE *pointerFile;
    int result;
    pointerFile = fopen(path,"w");
    if (pointerFile == NULL) {
        printf("error opening the file in path %s\n", path);
        return -1;
    }
    result = fprintf(pointerFile, "%d %s %d %s %d %s %d",playersCount, reg[0].nome, reg[0].pontos, reg[1].nome, reg[1].pontos,reg[2].nome, reg[2].pontos);
    if (result<0) {
        printf("error writting in the file %s\n", path);
        fclose(pointerFile);
        return -1;
    }
    fclose(pointerFile);
    return 1;
}

int importPlayers(char *path)
{
    FILE *pointerFile;
    int playersCount;
    pointerFile = fopen(path,"r");
    if (pointerFile == NULL) {
        printf("Error opening the file in path %s\n", path);
        return -1;
    }
    fscanf(pointerFile, "%d %s %d %s %d %s %d",&playersCount, &reg[0].nome, &reg[0].pontos, &reg[1].nome, &reg[1].pontos,&reg[2].nome, &reg[2].pontos);
    if (playersCount > max) {
        return 0;
    }
    fclose(pointerFile);

    return playersCount;
}

void insertionSort(reg_jogador player)
{
    for (int i = 0; i < max; i++)
    {
        if (player.pontos > reg[i].pontos)
        {
            moveToRight(i);
            reg[i].pontos = player.pontos;
            strcpy(reg[i].nome, player.nome);
            return;
        }
    }
}

void moveToRight(int pos)
{
    for (int i = max - 1; i > pos; i--)
    {
        reg[i].pontos = reg[i - 1].pontos;
        strcpy(reg[i].nome, reg[i - 1].nome);
    }
}

void moveToLeft(int pos)
{
    for (int i = pos; i < max-1; i++)
    {
        reg[i].pontos = reg[i + 1].pontos;
        strcpy(reg[i].nome, reg[i + 1].nome);
    }
}

