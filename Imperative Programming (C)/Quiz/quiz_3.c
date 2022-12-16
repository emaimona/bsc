#include <stdio.h>


void pnz(int numbers[], int size, int* ppos, int* pneg, int* pzero)
{
    for (int i=0; i<size; i++) {
        if (numbers[i]>0)
            (*ppos)++;
        else if (numbers[i]<0)
            (*pneg)++;
        else
            (*pzero)++;
    }
}
int main()
{
    int numbers[] = {56, 78, 34, -56, 0, 1, -1, 54, 7, 89, -2, 100, 566, 321523, -3, 87,
    0, 36, -1, -45, -25231285, 6, 14, -69, 123, 46747, 234, 7, -235, 346, 1325, -4436, 7457};
    int pos = 0;
    int neg = 0;
    int zero = 0;
    
    int size = sizeof(numbers)/ sizeof(numbers[0]);
    
    pnz(numbers, size, &pos, &neg, &zero);
    
    printf("pos = %i\n", pos);
    printf("neg = %i\n", neg);
    printf("zero = %i\n", zero);
    
    return 0;    
}