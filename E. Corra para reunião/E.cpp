#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 1;
    cin >> t;
    vector<int> escadas(t);
    for (int i = 0; i < escadas.size(); i++)
    {
        cin >> escadas[i];
    }
    vector<int> cansacoMinimoEscadas(t);
    cansacoMinimoEscadas[0] = escadas[0];
    cansacoMinimoEscadas[1] = escadas[1];
    for (int i = 2; i < cansacoMinimoEscadas.size(); i++)
    {
        cansacoMinimoEscadas[i] = min(cansacoMinimoEscadas[i - 1], cansacoMinimoEscadas[i - 2]) + escadas[i];
    }
    cout << min(cansacoMinimoEscadas[t - 1], cansacoMinimoEscadas[t - 2]) << endl;
    return 0;
}