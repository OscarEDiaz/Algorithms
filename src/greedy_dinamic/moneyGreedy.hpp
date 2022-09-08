#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Tomar monedas de cambio existentes
void monedasCambio(int N, vector<int> &array)
{
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        array.push_back(num);
    }
}

// Definir el cambio - Algoritmo dinámico
vector<int> cambioGreedy(int P, int Q, vector<int> monedas)
{
    vector<int> suma;
    int cambio = Q - P, i = 0;
    int tam = monedas.size();

    // ordenar el arreglo de monedas
    sort(monedas.begin(), monedas.end(), greater<>());

    while (cambio > 0 && i < tam)
    {
        while (monedas[i] <= cambio)
        {
            cambio -= monedas[i];
            suma.push_back(monedas[i]);
        }
        i++;
    }
    return suma;
}