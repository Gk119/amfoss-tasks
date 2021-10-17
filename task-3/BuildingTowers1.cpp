#include <vector>
#include <iostream>
using namespace std;


int main() 
{
    int rodno;
    vector<pair<int,int>> tower;    //weight = first height = second
    cin >> rodno;
    for(int i = 0; i < rodno; i++)
    {
        bool exist = false;
        int temp;
        cin >> temp;
        for(int j = 0; j < tower.size(); j++)
        {
            if(temp == tower[j].first)
            {
                tower[j].second += 1;
                exist = true;
                break;
            }
        }
        
        if(!exist)
        {
            tower.push_back(make_pair(temp, 1));
        }
    }
    
    int max_height;
    for(int i = 0; i < tower.size(); i++)
    {
        if(tower[i].second > max_height)
        {
            max_height = tower[i].second;
        }
    }
    
    cout << max_height << " " << tower.size();
    
    return 0;
}
