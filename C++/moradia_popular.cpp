#include <iostream>

using namespace std;

struct Usuario
{
    int idade;
    double renda;
};


int main()
{
    Usuario usuario;

    cout << "informe a idade e a renda do usuario respectivamente: \n";
    cin >> usuario.idade >> usuario.renda;

    if (usuario.idade >= 21 && usuario.renda <= 1200) cout << "o usuario em questao pode participar do programa\n";
    else cout << "o usuario em questao nao pode participar do programa\n";

    return 0;
}