// http://codeforces.com/problemset/problem/259/B
// c++0x
//


#include <iostream>

using namespace std;

int main(void)
{
    int square[3][3];
    for(int i=0; i<3; i++)
    {
        cin >> square[i][0] >> square[i][1] >> square[i][2];
    }

    int corner_sum = square[1][0] + square[1][2];
    int tl = square[0][1] + square[0][2];
    int rb = square[2][0] + square[2][1];

    //a + b = sum;
    //a - b = rb - tl;

    square[0][0] = (corner_sum + rb - tl) / 2;
    square[2][2] = corner_sum - square[0][0];
    square[1][1] = tl + square[0][0] - corner_sum;

    for(auto &line: square)
    {
        for(auto &i: line)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
