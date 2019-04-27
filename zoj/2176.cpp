#include <iostream>
using namespace std;
int main()
{
    int n, s[10], t[10], dis = 0;
    cin >> n;
    while (n != -1)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> s[i] >> t[i];
            if (i == 0)
                dis = s[i] * t[i];
            else
                dis += s[i] * (t[i] - t[i - 1]);
        }
        cout << dis << " miles" << endl;
        cin >> n;
    }
    return 0;
}