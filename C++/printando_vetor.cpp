#include <iostream>

int main()
{
    int tamanho, opcao {1};

    do
    {
        std::cout << "digite o tamanho do vetor que voce quer imprimir\n";
        std::cin >> tamanho;
        int *vetor = new int[tamanho];

        std::cout << "agora digite os elementos desse vetor\n";
        for (int i {0}; i<tamanho; ++i)
        {
            std::cin >> vetor[i];
        }


        std::cout << "o seu vetor é: ";
        for (int i {0}; i<tamanho; ++i)
        {
            std::cout << vetor[i] << " ";
        }
        std::cout << '\n';
        
        std::cout << "voce deseja imprimir outro vetor?(0 - nao / 1 - sim)\n";
        std::cin >> opcao;

        delete [] vetor;
    } while (opcao!=0);
    
    return 0;
}