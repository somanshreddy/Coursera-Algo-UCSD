#include <iostream>
using namespace std;

long long Pisano_period(long long m){
    long long a = 0;
    long long b = 1;
    long long c;

    for (long long i = 0; i < m * m; ++i)     /* since c depends on the previous two numbers which ranges
                                                from 0 to m - 1 (as we did mod), there are m*m possibilities */
    {
        c = (a + b) % m;
        a = b;
        b = c;

        if(a == 0 && b == 1)                  // Pisano period always starts with 0 1
            return i + 1;
    }
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    long long p = Pisano_period(m);

    

    n = n % p;                          // For Fib(2015), we need to find 2015 % period

    if(n <=1)
        return n;


    long long a = 0, b = 1, c;
    
    for (int i = 1; i < n; ++i)
    {
        c = (a + b) % m;
        a = b;
        b = c;
    } 

     return c;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
