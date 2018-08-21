#ifndef START_H
#define START_H

#include <windows.h>
#include <conio.h>

#define BLACK        0
#define BLUE         1
#define GREEN        2
#define AQUA         3
#define RED          4
#define PURPLE       5
#define YELLOW       6
#define WHITE        7
#define GRAY         8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTAQUA    11
#define LIGHTRED     12
#define LIGHTPURPLE  13
#define LIGHTYELLOW  14
#define BRIGHTWHITE  15

using namespace std;


/* ******************************************
 *
 *  Andriy Fuji, George Nardes, Teddy ONu
 *
 * *****************************************/

void hidecursor(void)   //esconde o cursor
{
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void clear()
{
    system("cls");
}

void gotoxy(int column, int line)
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int forecolor, int backcolor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (forecolor | backcolor<<4));
}

void borda()
{
    int x, y;
    textcolor(BLACK, WHITE);
    //Eixo X
    for(x = 4; x < 75; x++)
    {
        gotoxy(x, 0);
        cout << " ";
        gotoxy(x, 24);
        cout << " ";
    }
    //Eixo Y
    for(y = 1; y < 24; y++)
    {
        gotoxy(4, y);
        cout << "  ";
        gotoxy(73, y);
        cout << "  ";
    }
    textcolor(WHITE, BLACK);
}

void printa_menu()
{
    gotoxy(0, 0);
    textcolor(LIGHTYELLOW, BLACK);
    cout << "CONTROLE DE FRETE";

    textcolor(WHITE, BLACK);
    gotoxy(0, 7);
    cout << "Opcoes:";
    gotoxy(0, 16);
    cout << "Utilize as setas para cima/baixo para selecionar uma opcao";
    gotoxy(0, 17);
    cout << "Pressione Enter para selecionar";
}

int menu()
{
    int tecla, aux = 0;
    printa_menu();
    do
    {
        textcolor(BRIGHTWHITE, BLACK);
        gotoxy(18, 7);
        cout << "Cadastrar frete";

        gotoxy(18, 8);
        cout << "Ver fretes cadastrados";

        gotoxy(18, 9);
        cout << "Sair";

        textcolor(BLACK, WHITE);
        if ( aux == 0 )
        {
            gotoxy(18, 7);
            cout << "Cadastrar frete";
        }
        else if ( aux == 1 )
        {
            gotoxy(18, 8);
            cout << "Ver fretes cadastrados";
        }
        else if ( aux == 2 )
        {
            gotoxy(18, 9);
            cout << "Sair";
        }

        textcolor(WHITE, BLACK);

        tecla = getch();

        if ( tecla == 72 && aux != 0 )
            aux--;
        else if ( tecla == 80 && aux != 2 )
            aux++;
        else if ( tecla == 13 )
            return aux;
    }
    while ( tecla != 13 );
    return -1;
}

#endif // START_H
