#include<stdio.h>

int sum(int *arr, int size) {
    int s=0;

    for (int i=0; i<size; i++) {
        s += *(arr+i);
    }

    return s;
}

int sum2(int* begin, int* end) {
    int s=0;

    while (begin != end) {
        s += *begin++;
        //++begin;
    }

    return s;
}

double avg(int *begin, int* end) {
    int size = end - begin;
    return (double)sum2(begin, end) / size;
}

int* local() {
    int i = 42;
    
    return 
}

int main() {
    int x = 0;
    int *pi = &x;
    
    (*pi)++;
    printf("%d %p\n", x, pi);

    int **p2 = &pi;

    **p2 = 4;
    printf("%d\n", *pi);

    // Passing as pointer arrays;
    int arr[] = {3,4,2};
    int size = (sizeof(arr)/sizeof(arr[0]));

    int s = sum(arr, size);
    printf("The sum is: %d \n", s);

    printf("The sum2 is: %d \n", sum2(arr, arr+size));

    printf("\nThe average is %lf\n", avg(arr, arr+size));
    
    printf("\nThe size %lu: \n", (arr+size) - arr);
    return 0;
}