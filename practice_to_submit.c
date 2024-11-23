#include <stdio.h>

int *find_largest(int a[], size_t n )
{
    int *large = &a[0];

    for ( int i = 0 ; i < n ; i++){
        if (a[i] > *large ){
            large = &a[i];
        }
    }
    
    return large;
}

int main(void)
{
    int big, small;
    int a[] = {10, -1, 20, 0, 5}; 

    int *p = find_largest(a, 5);

    printf("\nThe largest one in array is: %d\n\n", *p);

    //(*p)++;
    (*p) += 1;

    printf("After increment: %d\n\n", *p);

    printf("The element of array after using function: ");

    for (size_t i = 0 ; i < sizeof(a) / sizeof(int) ; i++){
        printf("%d ", a[i]);
    }

    // easy to see the output
    printf("\n\n");

    return 0;
}
