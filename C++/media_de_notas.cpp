#include <iostream>

using namespace std;

double media_notas(double n1, double n2, double n3)
{
    return (n1+n2+n3)/3;
}

int main()
{
    double nota1, nota2, nota3, media;

    cout << "digite suas 3 notas e em seguida a media necessaria\n";
    cin >> nota1 >> nota2 >> nota3 >> media;

    if (media_notas(nota1,nota2,nota3) < media)
    {
        cout <<  "você está abaixo da média" << endl;
    }
    else if (media_notas(nota1,nota2,nota3) == media)
    {
        cout << "você está exatamente na média" << endl;
    }
    else
    {
        cout << "você está acima da média" << endl;
    }


    return 0;
}