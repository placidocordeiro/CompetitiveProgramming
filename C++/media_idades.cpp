#include <iostream>

int main()
{
    int *idade1 = new int, *idade2 = new int;

    std::cout << "digite as duas idades:\n";
    std::cin >> *idade1 >> *idade2;

    std::cout << "a média das idade é: " << (*idade1+*idade2)/2 << '\n';

    return 0;
}