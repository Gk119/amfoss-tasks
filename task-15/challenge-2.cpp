#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long sum = 2;
        long p2 = 1, p1 = 2;
        for(long i = p1 + p2; i < n; )
        {
            if(i%2 == 0) sum += i;
            p2 = p1;
            p1 = i;
            i = p1 + p2;
        }
        cout << sum << endl;
    }
    return 0;
}
