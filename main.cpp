#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 100;

class Brinquedo {
private:
    int codigo, quantidade;
    string nome, categoria;
    double preco;

public:
    void ler();
    int getCodigo();
    int getQuantidade();
    string getNome();
    string getCategoria();
    double getPreco();
};

class Estoque {
private:
    Brinquedo vetor[MAX];
    int quantidade = 0;

public:
    Estoque();
    void inserir(Brinquedo brinquedo);
    void listar();
    void pesquisarBrinquedo();
};

void Brinquedo::ler() {
    cin >> codigo;
    if(codigo == 0) {
        return;
    }
    cin.ignore();
    getline(cin, nome);
    getline(cin, categoria);
    cin >> preco >> quantidade;
}

int Brinquedo::getCodigo() {
    return codigo;
}

int Brinquedo::getQuantidade() {
    return quantidade;
}

string Brinquedo::getNome() {
    return nome;
}

string Brinquedo::getCategoria() {
    return categoria;
}

double Brinquedo::getPreco() {
    return preco;
}

Estoque::Estoque() {
    quantidade = 0;
}

void Estoque::inserir(Brinquedo brinquedo) {
    vetor[quantidade] = brinquedo;
    quantidade++;
}

void Estoque::listar() {
    cout << "---- + -------------------------------------------------- + ------------------------------ + ------------ + ----------" << endl;
    cout << "Cod. ! Nome                                               ! Categoria                      !        Preco ! Quantidade" << endl;
    cout << "---- + -------------------------------------------------- + ------------------------------ + ------------ + ----------" << endl;
    cout << setprecision(2) << fixed;
    for(int i = 0; i < quantidade; i++) {
        if(vetor[i].getCodigo() != 0) {
            cout << setw(4) << setfill('0') << vetor[i].getCodigo() << " ! " << left << setw(50) << setfill(' ') << vetor[i].getNome() << " ! " << setw(30) << setfill(' ') << vetor[i].getCategoria() << " ! " << right << setw(12) << setfill(' ') << vetor[i].getPreco() << " ! " << setw(10) << setfill(' ') << vetor[i].getQuantidade() << endl;
        }
    }
    cout << "---- + -------------------------------------------------- + ------------------------------ + ------------ + ----------" << endl;
}

void Estoque::pesquisarBrinquedo() {
    int codigo;
    bool encontrou = false;

    do {
        cin >> codigo;

        if(codigo < 0) {
            codigo = codigo * (-1);
            cout << "Erro na leitura - codigo [-" << right << setw(3) << setfill('0') << codigo << "]!" << endl;
            codigo = codigo * (-1);
        } else {
            encontrou = false;
            for(int i = 0; i < quantidade; i++) {
                if(codigo == vetor[i].getCodigo() && vetor[i].getCodigo() != 0) {
                    cout << "Codigo     : " << right << setw(4) << setfill('0') << vetor[i].getCodigo() << endl;
                    cout << "Nome       : " << vetor[i].getNome() << endl;
                    cout << "Categoria  : " << vetor[i].getCategoria() << endl;
                    cout << "Preco      : R$ " << vetor[i].getPreco() << endl;
                    cout << "Quantidade : " << vetor[i].getQuantidade() << endl;
                    encontrou = true;
                }
            }
        }

        if(!encontrou && codigo > 0) {
            cout << "Produto com codigo [" << right << setw(4) << setfill('0') << codigo << "] nao encontrado!" << endl;
        }
    } while(codigo != 0);
}

int main() {
    Brinquedo brinquedo;
    Estoque estoque;

    do {
        brinquedo.ler();
        estoque.inserir(brinquedo);
    } while(brinquedo.getCodigo() != 0);

    estoque.listar();
    estoque.pesquisarBrinquedo();

    return 0;
}