#include <iostream>
#include "arquivo.h"
#include <fstream>
#include <string>
#include <conio.h>
#include <ctime>

#define LINHAS 8
string Arquivo::getContainer() const
{
    return container;
}

void Arquivo::setContainer(const string &value)
{
    container = value;
}

string Arquivo::getOrigem() const
{
    return origem;
}

void Arquivo::setOrigem(const string &value)
{
    origem = value;
}

string Arquivo::getDestino() const
{
    return destino;
}

void Arquivo::setDestino(const string &value)
{
    destino = value;
}

float Arquivo::getValor() const
{
    return valor;
}

void Arquivo::setValor(float value)
{
    valor = value;
}


string Arquivo::getCarga() const
{
    return carga;
}

void Arquivo::setCarga(const string &value)
{
    carga = value;
}

string Arquivo::getDescarga() const
{
    return descarga;
}

void Arquivo::setDescarga(const string &value)
{
    descarga = value;
}

string Arquivo::getData() const
{
    return data;
}

void Arquivo::setData(const string &value)
{
    data = value;
}

string Arquivo::getHorario() const
{
    return horario;
}

void Arquivo::setHorario(const string &value)
{
    horario = value;
}

Arquivo::Arquivo()
{

}

void Arquivo::cadastrar()
{
    fflush(stdin);
    string Saux = "";
    float Iaux = 0.0;
    cout << "Digite o nome do container: ";
    cin.ignore();
    getline(cin, Saux);
    this->container = Saux;
    //setContainer(Saux);

    cout << "Cidade de origem: ";
    getline(cin, Saux);
    this->origem = Saux;
    //setOrigem(Saux);

    cout << "Cidade de destino: ";
    getline (cin, Saux);
    this->destino = Saux;
    //setDestino(Saux);

    cout << "Valor do Frete: ";
    cin >> Iaux;
    this->valor = Iaux;
    //setValor(Iaux);

    cout << "O container esta cheio ou vazio: ";
    cin >> Saux;
    this->carga = Saux;
    //setCarga(Saux);

    cout << "O container sera entregue cheio ou vazio: ";
    cin >> Saux;
    this->descarga = Saux;
    //setDescarga(Saux);

    cout << "Deseja salvar os dados?(S/N) ";
    char aux = getch();
    if(aux == 's' || aux == 'S')
        this->salvar();

}

void Arquivo::salvar()
{
    ofstream dados;
    dados.open("data.txt", ios_base::app);

    if(!dados.is_open())
    {
        cout << "Erro ao abrir o arquivo! " << endl;
    }
    else
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        dados << "Data: "<<
                 now->tm_mday  << '/' <<
                 (now->tm_mon + 1) << '/' <<
                 (now->tm_year + 1900);
        dados << "\nHorario: " << now->tm_hour <<":" << now->tm_min;
        dados << "\nNome do container: " << getContainer();
        dados << "\nOrigem: " << getOrigem();
        dados << "\nDestino: " << getDestino();
        dados << "\nValor: R$ " << getValor();
        dados << "\nContainer pego " << getCarga();
        dados << "\nContainer entregue " << getDescarga();
        dados << "\n------------------------------------\n";
    }
    dados.close();
}

void Arquivo::ler( vector<float> &valores )
{
    ifstream dados;
    dados.open("data.txt");
    
    if( !dados.is_open() )
    {
        cout << "Erro ao abrir o arquivo! " << endl;
        getch();
    }
    else
    {
        Arquivo aux;
        vector<string> linhas;
        string linha;
        string valor_str = "";
        int l = 0;
        while ( getline(dados, linha) )
        {
            if ( linha.at(1) != '-' )
            {
                linhas.insert(linhas.begin()+l, linha);
                l++;
            }
            else
            {
                l = 0;
                aux.setData(linhas[0]);
                aux.setHorario(linhas[1]);
                aux.setContainer(linhas[2]);
                aux.setOrigem(linhas[3]);
                aux.setDestino(linhas[4]);
                linha = linhas[5];
                for (unsigned int i = 0; i < linha.size();  i++  )
                {
                    if ( linha[i] == '$' )
                    {
                        i += 2;
                        while ( i < linha.size() )
                        {
                            valor_str += linha[i];
                            i++;
                        }
                    }
                }
                float valor = stof(valor_str);
                valores.push_back(valor);
                aux.setValor(valor);
                aux.setCarga(linhas[6]);
                aux.setDescarga(linhas[7]);
                mostrar (aux);
                /*
                 * A ideia seria passar cada frete, através do auxiliar, para um
                 * vector de arquivos chamado fretes.
                 * ex:  fretes.push_back(aux);
                 *
                 * Acho que será necessario usar os procedimentos que usamos no RPG.
                */
            }
            linha = "";
            valor_str = "";
        }
    }
    dados.close();
}

void Arquivo::mostrar(Arquivo x)
{
        cout << x.getData() << endl;
        cout << x.getHorario() << endl;
        cout << x.getContainer() << endl;
        cout << x.getOrigem() << endl;
        cout << x.getDestino() << endl;
        cout <<"Valor: R$ " << x.getValor() << endl;
        cout << x.getCarga() << endl;
        cout << x.getDescarga() << endl;
        cout <<"----------------------------------\n";
}
