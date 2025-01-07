#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    char loop = 's';

    do
    {
        cout << "digite um numero e sua potencia: \n";
        double numero;
        int potencia;
        cin >> numero >> potencia;
        cout << "o resultado de " << numero << " elevado a " << potencia << " é: " << pow(numero,potencia) << endl;

        cout << "você deseja fazer mais um conta? (s/n)\n";
        cin >> loop;
        while (loop != 's' && loop != 'n')
        {
            cout << "resposta inválida, digite novamente: \n";
            cin >> loop;
        }
        
    } while (loop != 'n');

    return 0;
}