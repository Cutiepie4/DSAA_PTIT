bool isprime(int x)
{
    if (x < 2) return 0;
    if (x == 2) return 1;
    if (x % 2 == 0) return 0;
    if (x == 3) return 1;
    if (x % 3 == 0) return 0;
    int t = 1;
    double sqr = sqrt(x);
    for (int i = 5; i <= sqr; i += (1 + t) << 1)
    {
        if (x % i == 0) return 0;
        t = 1 - t;
    }
    return 1;
}