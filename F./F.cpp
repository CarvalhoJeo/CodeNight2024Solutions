#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numeroDePessoas = 1;
    cin >> numeroDePessoas;
    int numeroDeCoffeCorners = 1;
    cin >> numeroDeCoffeCorners;
    vector<pair<int, int>> coordenadasPessoas(numeroDePessoas);
    vector<pair<int, int>> coordenadasCoffeCorners(numeroDeCoffeCorners);
    for (int i = 0; i < numeroDePessoas; i++)
    {
        cin >> coordenadasPessoas[i].first;
        cin >> coordenadasPessoas[i].second;
    }
    for (int i = 0; i < numeroDeCoffeCorners; i++)
    {
        cin >> coordenadasCoffeCorners[i].first;
        cin >> coordenadasCoffeCorners[i].second;
    }
    pair<int, int> pessoaMenorDistancia;
    for (int i = 0; i < coordenadasPessoas.size(); i++)
    {
        pair<int, int> coordenadasP = coordenadasPessoas[i];
        for (int x = 0; x < coordenadasCoffeCorners.size(); x++)
        {
            pair<int, int> coordenadasCC = coordenadasCoffeCorners[x];
            int distance = abs(coordenadasCC.first - coordenadasP.first) + abs(coordenadasCC.second - coordenadasP.second);
            if (i == 0 && x == 0)
            {
                pessoaMenorDistancia.first = i + 1;
                pessoaMenorDistancia.second = distance;
                continue;
            }
            if (pessoaMenorDistancia.second > distance)
            {
                pessoaMenorDistancia.first = i + 1;
                pessoaMenorDistancia.second = distance;
            }
        }
    }
    cout << pessoaMenorDistancia.first << endl;
    return 0;
}