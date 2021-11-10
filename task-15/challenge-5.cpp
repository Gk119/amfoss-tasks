#include <vector>
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
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;
        vector<int> nums;
        long ans = 1;
        for(int i = 1; i <= n; i++) nums.push_back(i);
        for(int prime = 2; prime <= n;)
        {
            bool div = false;            
            for(int i = 0; i < n; i++)
            {
                if(nums[i]%prime == 0)
                {
                    nums[i] /= prime;
                    div = true; 
                }
            }
            if(div == false)
            {
                prime = next_prime(prime);
            }
            else
            {
                //factors.push_back(prime);
                ans *= prime;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
