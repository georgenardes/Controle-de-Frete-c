#include <iostream>
#include <fstream>
#include "arquivo.h"

using namespace std;
#include <time.h>
#include <conio.h>
#include "menu.h"
#include <vector>
/*
 * Bug encontrado no seguinte procedimento:
 * Efetuar Cadastro -> Ver fretes -> Efetuar Cadastro
 */

int main()
{
    bool sair = false;
    Arquivo controle;
    vector <float> valores_fretes;
    float total = 0;
    do
    {
        clear();
        switch ( menu() )
        {
        case 0:
            clear();
            controle.cadastrar();
            break;

        case 1:
            clear();
            controle.ler( valores_fretes );
            getch();
            clear();
            cout << "Valores de fretes:\n";
            for (float i: valores_fretes)
            {
                cout << i << endl;
                total += i;
            }
            cout << "Lucro bruto: R$" << total;
            getch();
            break;

        case 2:
            sair = true;
            clear();
            break;

        }
    }while (!sair);

    return 0;
}
