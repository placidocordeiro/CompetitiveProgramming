#include <iostream>

using namespace std;

int fatorial(int n)
{
    int resultado = 1;
    for (int i = 1; i<=n; i++)
    {
        resultado *= i;
    }
    return resultado;
}

int main()
{
    int n;

    cout << "digite um numero\n";
    cin >> n;
    cout << "o fatorial de " << n << " é " << fatorial(n) << endl;


    return 0;
}