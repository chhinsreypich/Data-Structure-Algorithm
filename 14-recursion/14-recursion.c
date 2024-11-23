/* 
 * add squares of integers in range [m:n]
 *  iterative version
 */
long sum_squares(int m, int n)
{
    long sum = 0;

    for (int i = m; i <=n; ++i)
        sum += i*i;

    return sum;
}

/* 
 * recursive version ("going up")
 *   assume m <= n
 */
long sum_squares_up(int m, int n)
{
    if (m == n)
        return m*m;     /* base step */
    return m*m + sum_squares_up(m+1, n);
}

/* 
 * recursive version ("going down")
 *   assume m <= n
 */
long sum_squares_down(int m, int n)
{
    if (m == n)
        return n*n;     /* base step */
    return sum_squares_down(m, n-1) + n*n;
}

/*
 * recursive version ("partition strategy")
 *   assume m <= n
 */
long sum_squares_middle(int m, int n)
{
    int middle = (m + n) / 2;

    if (m == n)
        return m*m;
    
    return sum_squares_middle(m, middle) + sum_squares_middle(middle+1, n);
}