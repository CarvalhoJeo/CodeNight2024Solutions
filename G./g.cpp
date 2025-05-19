#include <bits/stdc++.h>
using namespace std;

int main()
{
    int compromissos, massagensDisponiveis;
    cin >> compromissos >> massagensDisponiveis;

    string diasSemana[] = {"segunda", "terca", "quarta", "quinta", "sexta"};
    vector<vector<pair<int, int>>> diasComCompromisso(5);
    vector<vector<pair<int, int>>> diasComMassagem(5);

    for (int i = 0; i < compromissos; i++)
    {
        int dia, horas, minutos, duracao;
        cin >> dia;
        scanf("%d:%d", &horas, &minutos);
        cin >> duracao;

        int inicio = horas * 60 + minutos;
        int fim = inicio + duracao;
        diasComCompromisso[dia - 2].emplace_back(inicio, fim);
    }

    for (int i = 0; i < massagensDisponiveis; i++)
    {
        int dia, horas, minutos;
        cin >> dia;
        scanf("%d:%d", &horas, &minutos);

        int inicio = horas * 60 + minutos;
        int fim = inicio + 10;
        diasComMassagem[dia - 2].emplace_back(inicio, fim);
    }

    for (int dia = 0; dia < 5; dia++)
    {
        for (auto massagem : diasComMassagem[dia])
        {
            bool conflito = false;
            for (auto compromisso : diasComCompromisso[dia])
            {
                if (!(massagem.second <= compromisso.first || massagem.first >= compromisso.second))
                {
                    conflito = true;
                    break;
                }
            }
            if (!conflito)
            {
                printf("%02d:%02d na %s\n", massagem.first / 60, massagem.first % 60, diasSemana[dia].c_str());
                return 0;
            }
        }
    }

    cout << "Sem massagem essa semana :(" << endl;
    return 0;
}
