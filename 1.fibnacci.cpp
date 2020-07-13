long long Fibonacci(unsigned n)
{
    int result[2] = [0,1];
    if(n<2)
        return result[n];

    long long fibNMunisOne = 1;
    long long fibNMunisTwo = 0;

    long long fibN = 0;

    for(unsigned int i=2;i<=n;++i)
    {
        fibN = fibNMunisOne + fibNMunisTwo;
        fibNMunisTwo = fibMunusOne;
        fibNMunisOne = fibN;
    }
    return fibN;
}
