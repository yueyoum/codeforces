// http://codeforces.com/problemset/problem/260/A

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>

using namespace std;

// c++0x

bool check_ok(const int&, const int&, const int&);

int main(void)
{
    int a, b, n, ori_a;
    int result[500000];

    cin >> a >> b >> n;
    ori_a = a;
    int length = 0;
    do
    {
        int _x = a % 10;
        result[length++] = _x;
        a /= 10;
    }while(a>0);

    for(int i=0; i<length/2; i++)
    {
        result[i] = result[i] ^ result[length-1-i];
        result[length-1-i] = result[i] ^ result[length-1-i];
        result[i] = result[i] ^ result[length-1-i];
    }


    map< int, vector<int> > candidates;
    vector<int> c;
    c.reserve(10);
    c = {0};
    candidates[0] = c;
    c = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    candidates[1] = c;
    c = {0, 2, 4, 6, 8};
    candidates[2] = c;
    c = {0, 3, 6, 9, 2, 5, 8, 1, 4, 7};
    candidates[3] = c;
    c = {0, 4, 8, 2, 6};
    candidates[4] = c;
    c = {0, 5};
    candidates[5] = c;
    c = {0, 6, 2, 8, 4};
    candidates[6] = c;
    c = {0, 7, 4, 1, 8, 5, 2, 9, 6, 3};
    candidates[7] = c;
    c = {0, 8, 6, 4, 2};
    candidates[8] = c;
    c = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    candidates[9] = c;


    int b_base = b % 10;
    bool ok;
    for(int i=0; i<n; i++)
    {
        ok = false;
        for(int &can: candidates[b_base])
        {
            result[length] = can;
            if(check_ok(ori_a, can, b))
            {
                ok = true;
                break;
            }
        }
        if(!ok)
        {
            cout << -1;
            exit(0);
        }
        length++;
    }

    for(int i=0; i<length; i++)
        cout << result[i];
    return 0;
}


bool check_ok(const int &a, const int &new_value, const int &b)
{
    static int remainer = a % b;
    int _r = remainer * 10 + new_value;

    if(_r%b == 0)
    {
        remainer = 0;
        return true;
    }
    return false;
}
