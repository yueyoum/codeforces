// http://codeforces.com/contest/259/problem/C

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string::size_type pos = s.find('0');
    if(pos!=string::npos)
        s = s.erase(pos, 1);
    else
        s = s.erase(0, 1);
    cout << s << endl;
}
