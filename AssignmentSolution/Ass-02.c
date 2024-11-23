/*
        Practice Problems

    Note: Do not submit.

    1. What are the elements of b after the call reverse(b + 1, lenb - 1),
    where b, reverse, and lenb are as in 09-rev.c? Is it wrong to call reverse(b + 1, lenb)?

    2. A student observes that most functions that process arrays are passed both an array and
    the array length, as in

        void g(int a[], size_t n)
        {
        // some code
        }

    However, the array length is known to the compiler, so that we may instead compute the
    array length in the body of the function, as in
        void g(int a[])
        {
        size_t n = sizeof(a) / sizeof(int);
        // some code
        }
    Is the student correct? Explain.

    3. What is size t, and what guarantees does the C standard make about it?

    4. In class, we mentioned that in almost all cases, the name of an array in an expression is
    converted to a pointer to the first element of the array. What are the exceptions to this
    rule?

*********************************************************************************************************************

        Programming

    1. King: Chap. 11: Exercises: #8: Write a function, declared as below, which is passed an
    array of length n, and returns a pointer to the array’s largest element.
    int *find_largest(int a[], size_t n);

    Use it in main as follows: define a test array (as in 07-ptr-maxmin.c) and, using find largest,
    increment the value of the largest element of the array. Finally, print all the elements of
    the array.



*/

/*
 * largest.c:
 *
 * write a function having prototype
 *   int *find_largest(int a[], size_t n);
 * which returns pointer to the array's largest element
 * and, use the return value in main() as instructed.
 */

#include <stdio.h>

int *find_largest(int a[], size_t n);
void print_arr(int a[], size_t n);

int main(void)
{

    int a[] = {10, -1, 20, -2, 15};
    int *p = find_largest(a, sizeof(a) / sizeof(int));

    ++*p;
    print_arr(a, sizeof(a) / sizeof(int));

    return 0;
}

int *find_largest(int a[], size_t n)
{
    size_t imax = 0; // index containing largest element

    for (size_t i = 1; i < n; ++i)
        if (a[i] > a[imax])
            imax = i;

    return &a[imax];
}

void print_arr(int a[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
    putchar('\n');
}
