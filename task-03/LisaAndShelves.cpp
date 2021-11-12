#include <iostream>
#include <cmath>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long int num, factors = 0;
    cin >> num;
    long int root = sqrt(num);
    for(long int i = 1; i <= root; i++)
    {
        if(num % i != 0)
        {
            continue;
        }

        if(i*i != num)
        {
            factors += 2;
        }
        else
        {
            factors++;   
        }
    }
    cout << factors;
    return 0;
}
