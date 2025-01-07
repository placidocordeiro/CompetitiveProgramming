#include <iostream>

int main()
{
    int ordem;
    std::cout << "digite a ordem das matrizes\n";
    std::cin >> ordem;

    int matriz1[ordem][ordem];
    int matriz2[ordem][ordem];

    std::cout << "digite o conteudo da matriz 1\n";
    for (int i = 0; i<ordem; ++i)
    {
        for (int j = 0; j<ordem; ++j)
        {
            std::cin >> matriz1[i][j];
        }
    }
    
    std::cout << "digite o conteudo da matriz 2\n";
    for (int i = 0; i<ordem; ++i)
    {
        for (int j = 0; j<ordem; ++j)
        {
            std::cin >> matriz2[i][j];
        }
    }

    std::cout << "a matriz resultante da soma é: \n";
    for (int i = 0; i < ordem; ++i)
    {
        for (int j = 0; j < ordem; ++j)
        {
            std::cout << matriz1[i][j] + matriz2[i][j] << "  ";
        }
        std::cout << '\n';
    }
    

    return 0;
}