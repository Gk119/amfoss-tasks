#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int  i = 0; i < T; ++i)
    {
        long p , q , r;
        long a, b, c, d;
        long long N;
        
        cin >> a >> b >> c >> d >> N;
        p = a;
        q = b;
        if(N == 1)
        {
            r = a;
        }
        if(N == 2)
        {
            r = b;
        }
        for(long long j = 2; j < N; ++j)
        {
            r = c*p + d*q;
            if(r > 1000000006L)
            {
                r = r % 1000000007L;
            }
            p = q;
            q = r;
        }
        cout << r<< "\n";
    }
    return 0;
}