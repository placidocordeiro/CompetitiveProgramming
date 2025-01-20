#include <iostream>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int a = 1, b = 2;
    int *ptr_a = &a, *prt_b = &b;

    printf("%p // %p\n",ptr_a,prt_b);
    printf("%d // %d\n",*ptr_a,*prt_b);

    swap(ptr_a,prt_b);

    printf("%p // %p\n",ptr_a,prt_b);
    printf("%d // %d\n",*ptr_a,*prt_b);

    return 0;
}