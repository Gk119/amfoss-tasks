#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n , m, psum = 0;
    vector<int> devs;
    vector<pair<int,bool>> psolvs;
    cin >> n >> m;
    if( n > m)
    {
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        devs.push_back(temp);
        //cout << devs[i] << endl;
    } 
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        psolvs.push_back(make_pair(temp,false));
        //cout << psolvs[i] << endl;
    }
    sort(psolvs.begin(), psolvs.end());
    for(int i = 0; i < n; i++)
    {
        bool defeated = false;
        for(int j = 0; j < m; j++)
        {
            if(devs[i] < psolvs[j].first && psolvs[j].second == false)
            {
                psum += psolvs[j].first;
                psolvs[j].second = true;
                defeated = true;
                break;
            }
        }
        if(!defeated)
        {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES" << endl << psum;
    return 0;
}
