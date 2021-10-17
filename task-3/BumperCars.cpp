#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int carno, blen;
vector<pair<int,int>> cars; //pos = first, dir = second;
int secs = 0, ffall_count = 0, bfall_count = 0, fall_count = 0;

int main()
{
    cin >> carno >> blen;
    for (int i = 0; i < carno; i++)
    {
        pair<int,int> temp;
        cin >> temp.first;
        temp.second = 0;
        cars.push_back(temp);
    }
    for (int i = 0; i < carno; i++)
    {
        int temp;
        cin >> temp;
        cars[i].second = temp;
    }
    
    sort(cars.begin(), cars.end());
    cars.push_back(make_pair(blen + 1, 0));

    while(fall_count != carno)
    {
        for(int i = bfall_count; i < carno - ffall_count; i++)
        {
            if(cars[i].first == cars[i + 1].first) //if car collided with the one in front of it
            {
                cars[i].second = -1;                //change both of their velocities        
                cars[i + 1].second = 1;
            }
        }
        for(int i = bfall_count; i < carno - ffall_count; )
        {
            if(cars[i].second == 1)             //moving forward
            {
                if(cars[i + 1].first<= blen)    //has a car ahead of it
                {
                    if(cars[i].first + 1 == cars[i + 1].first && cars[i + 1].second == -1)  //the car ahead is one position in front and moving back
                    {
                        cars[i].second = -1;    //change direction of velocities for both cars
                        cars[i + 1].second = 1;
                        i += 2;
                    }
                    else                        //car ahead is farther than one position ahead or moving forward
                    {
                        cars[i].first += 1;
                        if(cars[i].first > blen)
                        {
                            ffall_count += 1;
                            fall_count += 1;
                        }
                        i++;
                    }
                }
                else                            //has no car ahead of it
                {
                    cars[i].first += 1;
                    if(cars[i].first > blen)
                    {
                        ffall_count += 1;
                        fall_count += 1;
                    }
                    i++;

                }
            }
            else if(cars[i].second == -1)       //moving backwards
            {                                   //condition with a car just behind moving forward is already considered
                cars[i].first -= 1;
                if(cars[i].first == 0)
                {
                    bfall_count += 1;
                    fall_count += 1;
                }
                i++;         
            }
        }
        secs++;
        
    }
    cout << secs;
    return 0;
}
