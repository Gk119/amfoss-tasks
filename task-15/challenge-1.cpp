#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        n--;
        long n3 = n/3, n5 = n/5, n15 = n/15;       
        long sum = 0;
        sum += n3*(2*3 + (n3 - 1)*3)/2;
        sum += n5*(2*5 + (n5 - 1)*5)/2;
        sum -= n15*(2*15 + (n15 - 1)*15)/2;                                           
        cout << sum << endl;   
    }
    return 0;
}
