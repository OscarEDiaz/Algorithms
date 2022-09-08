#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Dinero
{
    int cantidad = 0;
    int valor;
};

void monedasCambio(int N, vector<int> &array, vector<Dinero> &dinero)
{
    int num;
    struct Dinero actual;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        array.push_back(num);

        actual.valor = num;

        dinero.push_back(actual);        
    }
}

vector<Dinero> cambioDinamico(int P, int Q, vector<int> monedas, vector<Dinero> dinero)
{
    int cambio = Q - P;
    int j = 0;
    int k = dinero.size() - 1;

    vector<int> suma = {0};

    // ordenar el arreglo de monedas
    sort(monedas.begin(), monedas.end(), greater<>());

    if (monedas[j] <= cambio)
    {
        suma.push_back(monedas[j]);
        dinero[k].cantidad++;
    }
    else
    {
        j++;
        k--;
        suma.push_back(monedas[j]);
        dinero[k].cantidad++;
    }
    
    for (int i = 2; suma[i-1] < cambio; i++)
    {
        if (monedas[j] + suma[i-1] > cambio)
        {
            j++;
            k--;
            if (j < monedas.size())
            {
                suma.push_back(monedas[j] + suma[i-1]);
                dinero[k].cantidad++;
            }
        }
        else
        {
            suma.push_back(monedas[j] + suma[i-1]);
            dinero[k].cantidad++;
        }
    }
    
    return dinero;
}

