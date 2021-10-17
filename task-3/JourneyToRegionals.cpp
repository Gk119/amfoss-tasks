#include <vector>
#include <iostream>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    int * amount;
    int cityno, qno;

    cin >> cityno;
    amount = new int[cityno];

    for(int i = 0; i < cityno; i++)
    {
        int temp;
        cin >> temp;
        amount[i] = temp;
    }
    
    cin >> qno;
    int * sum = new int[qno];
    for(int i =0; i < qno; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        sum[i] = 0;
        for(int j = c1 -1; j <= c2 -1; j++)
        {
            sum[i] = sum[i] + amount[j];
        }
    }
    for(int i =0; i < qno; i++)
    {
        cout << sum[i] << endl;
    }
     
    return 0;
}
