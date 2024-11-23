#include<stdio.h>
int *find_largest(int a[], size_t n) {
   int *largest= &a[0];
    for(size_t i=1; i<n; i++)
    {
        if(a[i]> *largest)
        largest = &a[i];
    }
    return largest;
}
    
int main(void)
{
    
    int a[] = { 10, -1, 20, 0, 5};
    
    size_t n = sizeof(a)/sizeof(a[0]);
    int *big= find_largest(a, n);
      

    printf("The largest is: %d\n", *big);
    
    (*big) += 1 ;
    printf ("%d\n" , *big);

    for (int i = 0 ; i < 5 ; i++){
      printf ("%d ", a[i]);

    }

    


    return 0;
}