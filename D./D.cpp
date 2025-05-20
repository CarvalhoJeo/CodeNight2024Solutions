#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 1;
    cin >> n;

    deque<int> fila;
    queue<int> sanduiches;

    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> f;
        fila.push_front(f);
    }

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        sanduiches.push(s);
    }
    int c = 0;
    while (n > 0 && c < n)
    {
        int sanduicheDesejado = fila.front();
        int sanduicheAtual = sanduiches.front();
        if (sanduicheAtual == sanduicheDesejado)
        {
            sanduiches.pop();
            fila.pop_front();
            if (c > 0)
            {
                c--;
            }
        }
        else
        {
            c++;
            fila.pop_front();
            fila.push_back(sanduicheDesejado);
        }
    }
    cout << fila.size();
    return 0;
}