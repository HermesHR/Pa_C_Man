#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou()
{
    return 0;
}

void move(char direcao)
{
    m.matriz[heroi.x][heroi.y] = '.';

    switch (direcao)
    {
    case 'a':
        m.matriz[heroi.x][heroi.y - 1] = '@';
        heroi.y--;
        break;
    case 'w':
        m.matriz[heroi.x - 1][heroi.y] = '@';
        heroi.x--;
        break;
    case 's':
        m.matriz[heroi.x + 1][heroi.y] = '@';
        heroi.x++;
        break;
    case 'd':
        m.matriz[heroi.x][heroi.y + 1] = '@';
        heroi.y++;
        break;
    }
}

void encontramapa(MAPA *m, POSICAO *p, char c)
{

    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            if (m->matriz[i][j] == c)
            {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

int main()
{

    lemapa(&m);
    encontramapa(&m, &heroi, '@');

    do
    {

        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());

    liberamapa(&m);
}
