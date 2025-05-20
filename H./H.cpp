#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    while (n != 0 && d != 0)
    {
        string numeroEmTexto;
        cin >> numeroEmTexto;

        vector<char> resposta;
        int deletados = 0;

        for (char c : numeroEmTexto)
        {
            while (!resposta.empty() && deletados < d && resposta.back() < c)
            {
                resposta.pop_back();
                deletados++;
            }
            resposta.push_back(c);
        }
        while (deletados < d)
        {
            resposta.pop_back();
            deletados++;
        }
        for (int i = 0; i < n - d; i++)
        {
            cout << resposta[i];
        }
        cout << endl;
        cin >> n >> d;
    }

    return 0;
}
