#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<char, int>> counted_letters;

bool counted(char x)
{
    for(int i = 0; i < counted_letters.size(); i++)
    {
        if(x == counted_letters[i].first)
        {
            return true;
        }
    }
    return false;
}

void add1(char x)
{
    for(int i = 0; i < counted_letters.size(); i++)
    {
        if(x == counted_letters[i].first)
        {
            counted_letters[i].second += 1;
        }
    }
}

int main() {
    int len, newlen = 0;
    string str;
    cin >> len;
    cin >> str;
    char sl = 0, cl = 0;
    int cl_count = 0;
    
    for(int i = 0; i < str.size(); i++)
    {
        if(!counted(str[i]))
        {
            counted_letters.push_back(make_pair(str[i], 1));
        }
        else
        {
            add1(str[i]);
        }
    }
    for(int i = 0; i < counted_letters.size(); i++)
    {
        if(sl == 0 && counted_letters[i].second % 2 == 1)
        {
            sl = counted_letters[i].first;
        }
        else if( sl != 0 && counted_letters[i].second % 2 == 1)
        {
            counted_letters[i].second -= 1;
        }
        
        newlen += counted_letters[i].second;

    }
    
    string newstr, newstrrev;
    for(int i = 0; i < counted_letters.size(); i++)
    {
        int l = counted_letters[i].second / 2;
        for(int j = 0; j < l; j++)
        {
            newstr.push_back(counted_letters[i].first);
        }
    }
    newstrrev = newstr;
    reverse(newstrrev.begin(),newstrrev.end());
    if(sl != 0)
    {
        newstr = newstr + sl + newstrrev; 
    }
    else
    {
        newstr = newstr + newstrrev; 
    }
    cout << newlen << endl;

    cout << newstr;
    
    return 0;
}
