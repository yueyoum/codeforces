// http://codeforces.com/problemset/problem/259/A

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;



bool check_line(vector<string>::iterator &it)
{
    int length = it->size();
    for(int i=0; i<length-1; i++)
    {
        if((*it)[i] == (*it)[i+1]) return false;
    }
    return true;
}


int main(void)
{
    string s;
    vector<string> input;
    while(getline(cin, s))
        input.push_back(s);


    if(input[0][0] != 'W')
        input[0] = input[0].substr(7,1) + input[0].substr(0,7);

    for(vector<string>::iterator it=input.begin(); it!=input.end(); it++)
    {
        if(!check_line(it))
        {
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES";
    return 0;
}
