#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    int count = 0, twopow = 0;
    vector<int> nums;
    while(N % 2 == 0)
    {
        twopow++;
        N /= 2;
    }
    for(int i = 1; i <= M; i++)
    {
        int tp = 0;
        int i2 = i;
        while(i2 % 2 == 0)
        {
            tp++;
            i2 /= 2;
        }
        if(tp < twopow) nums.push_back(i);
    }
    cout << nums.size() << endl;
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
