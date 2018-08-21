#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "iostream"
#include <fstream>
using namespace std;
#include <time.h>
#include <vector>

class Arquivo
{
private:
    string data;
    string horario;
    string container;
    string origem;
    string destino;
    string carga;
    string descarga;
    float valor;

public:
    Arquivo();
    void cadastrar();
    void salvar ();
    void ler (vector<float> &valores);
    void mostrar (Arquivo x);
    string getContainer() const;
    void setContainer(const string &value);
    string getOrigem() const;
    void setOrigem(const string &value);
    string getDestino() const;
    void setDestino(const string &value);
    float getValor() const;
    void setValor(float value);
    string getCarga() const;
    void setCarga(const string &value);
    string getDescarga() const;
    void setDescarga(const string &value);
    string getData() const;
    void setData(const string &value);
    string getHorario() const;
    void setHorario(const string &value);
};

#endif // ARQUIVO_H
