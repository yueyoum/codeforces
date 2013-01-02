// http://codeforces.com/contest/255/problem/A


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    const char *muscles[] = {"chest", "biceps", "back"};
    int n;
    vector<int> a;

    cin >> n;
    a.reserve(n);
    int _tmp;
    while(cin >> _tmp) a.push_back(_tmp);

    int count[] = {0, 0, 0};
    for(int i=0; i<n; i++)
        count[i%3] += a[i];


    int max_index = 0;
    int max_num = count[max_index];
    if(max_num < count[1])
    {
        max_num = count[1];
        max_index = 1;
    }
    if(max_num < count[2])
    {
        max_num = count[2];
        max_index = 2;
    }

    cout << *(muscles + max_index);
    return 0;

}
