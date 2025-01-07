#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array <double, 5> gastos;
    int i {1};
    std::for_each(gastos.begin(),gastos.end(),[&i](double &elemento)
    {
        std::cout << "insira os gastos da familia " << i << '\n';
        std::cin >> elemento;
        ++i;
    });

    double media {0};
    std::for_each(gastos.begin(),gastos.end(),[&media] (double &elemento)
    {
        media += elemento;
    });

    media /= gastos.size();
    std::cout << "\na média dos gastos é: " << media << "\n\n";

    i = 1;
    std::for_each(gastos.begin(),gastos.end(),[media,&i](int elemento)
    {
        if (elemento == media)
        {
            std::cout << "a familia " << i << " está na média\n";
        }
        else if (elemento > media)
        {
            std::cout << "a familia " << i << " está acima da média\n";
        }
        else
        {
            std::cout << "a familia " << i << " está abaixo da média\n";
        }
        ++i;
    });

    return 0;
}