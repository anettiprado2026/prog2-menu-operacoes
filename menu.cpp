#include <iostream>
using namespace std;

// Funções que recebem PONTEIROS (passar ponteiros para funções)
double soma(double *a, double *b) {
    return (*a + *b);
}

double subtracao(double *a, double *b) {
    return (*a - *b);
}

double multiplicacao(double *a, double *b) {
    return (*a * *b);
}

double divisao(double *a, double *b) {
    return (*a / *b);
}

// Potência com expoente inteiro (aceita negativo)
double potencia(double *base, int *expoente) {
    int n = (*expoente < 0) ? -(*expoente) : *expoente;
    double res = 1;

    for (int i = 0; i < n; i++) {
        res = res * (*base);
    }
    if (*expoente < 0) {
        res = 1 / res;
    }
    return (res);
}

int main() {
    int opcao;

    // Alocação dinâmica com new 
    double *n1 = new double;
    double *n2 = new double;
    int *expo = new int;

    do {
        cout << "\n===== MENU DE OPERACOES =====" << endl;
        cout << "1. Soma" << endl;
        cout << "2. Subtracao" << endl;
        cout << "3. Multiplicacao" << endl;
        cout << "4. Divisao" << endl;
        cout << "5. Potencia" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite dois numeros: ";
                cin >> *n1 >> *n2;
                cout << "Resultado: " << *n1 << " + " << *n2
                     << " = " << soma(n1, n2) << endl;
                break;

            case 2:
                cout << "Digite dois numeros: ";
                cin >> *n1 >> *n2;
                cout << "Resultado: " << *n1 << " - " << *n2
                     << " = " << subtracao(n1, n2) << endl;
                break;

            case 3:
                cout << "Digite dois numeros: ";
                cin >> *n1 >> *n2;
                cout << "Resultado: " << *n1 << " * " << *n2
                     << " = " << multiplicacao(n1, n2) << endl;
                break;

            case 4:
                cout << "Digite dois numeros: ";
                cin >> *n1 >> *n2;
                if (*n2 == 0) {
                    cout << "Erro: divisao por zero!" << endl;
                } else {
                    cout << "Resultado: " << *n1 << " / " << *n2
                         << " = " << divisao(n1, n2) << endl;
                }
                break;

            case 5:
                cout << "Digite a base: ";
                cin >> *n1;
                cout << "Digite o expoente (inteiro): ";
                cin >> *expo;
                if (*n1 == 0 && *expo < 0) {
                    cout << "Erro: zero elevado a expoente negativo!" << endl;
                } else {
                    cout << "Resultado: " << *n1 << " ^ " << *expo
                         << " = " << potencia(n1, expo) << endl;
                }
                break;

            case 6:
                cout << "Encerrando o programa..." << endl;
                break;

            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 6);

    // Liberta a memória alocada 
    delete n1;
    delete n2;
    delete expo;

    return 0;
}