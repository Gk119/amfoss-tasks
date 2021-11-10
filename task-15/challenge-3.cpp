#include <iostream>

using namespace std;

long next_prime(long primeno)
{
    long x = primeno + 1;
    bool prime = true;
    
    while(true)
    {
        for(long i = 2; i < x; i++)
        {
            if(x % i == 0)
            {
                prime = false;
                break;
            }
        }
        if(prime == false)
        {
            x++;
            prime = true;
        }
        else
        {
            return x;   
        }
    }
    
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long maxp = 0L;
        if(n%2 == 0L) 
        {
            maxp = 2;
            n = n/2L;
            while(true)
            {
                if(n%2 == 0L)
                {
                    n = n/2;
                }
                else
                {
                    break;
                }
            }          
        }
        for(long i = 3L; i <= n; i += 2)
        {
            if(n%i == 0L)
            {
                maxp = i;
                n = n/i;
                i -= 2L;
            }
            //else i =next_prime(i);
        }
        cout << maxp << endl;
    }
    return 0;
}
