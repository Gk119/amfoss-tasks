#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    //ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++)
    {
        long N, M, v, k;
        cin >> N >> M >> v >> k; // N = length M = drops v = velocity k = time
        long d = v * k;
        long ans = N;
        
        if(N == 0)
        {
            cout << N << endl;
            continue;
        }
        
        vector<long> drops;
        vector<pair<long,long>> ranges;
        for(long j = 0; j < M; j++)
        {
            long temp;
            cin >> temp;
            if(temp >= 0 && temp <= N) drops.push_back(temp);
        }
        sort(drops.begin(), drops.end());
        drops.erase( unique( drops.begin(), drops.end() ), drops.end() );
        
        if( d != 0)// && drops.size() != N)
        {
            long start, end;
            if(drops[0] - d > 0) start = drops[0] - d;
            else start = 1;
            if(drops[0] + d < N) end = drops[0] + d;
            else end = N;
            ranges.push_back(make_pair(start,end));

            for(long j = 1; j < drops.size(); j++)
            {
                if(drops[j] - d > 0) start = drops[j] - d;
                else start = 1;
                if(drops[j] + d < N) end = drops[j] + d;
                else end = N;

                if(ranges.back().second >= start) ranges.back().second = end;
                else ranges.push_back(make_pair(start,end));
            }
            for(long j = 0; j < ranges.size(); j++)
            {
                //cout << "Ranges:" << ranges[j].first << " " << ranges[j].second << endl;
                ans -= (ranges[j].second - ranges[j].first + 1);
            }
        }
        else 
        {
            ans -= drops.size();
        }

        cout << ans << endl;

    }
    return 0;
}


