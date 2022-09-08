#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool validate(vector<vector<int>> matrix, int x, int y)
{
    int counter = 0;

    // Derecha
    if (y + 1 < matrix[x].size())
    {
        if (matrix[x][y + 1] == 1)
            counter++;
    }

    // Arriba
    if (x - 1 >= 0)
    {
        if (matrix[x - 1][y] == 1)
            counter++;
    }

    // Izquierda
    if (y - 1 >= 0)
    {
        if (matrix[x][y - 1] == 1)
            counter++;
    }
    // Abajo
    if (x + 1 < matrix.size())
    {
        if (matrix[x + 1][y] == 1)
            counter++;
    }

    if (counter >= 2)
        return true;

    return false;
}

void branchBound(vector<vector<int>> &matrix, int i, int j, queue<vector<int>> &queue, vector<vector<bool>> &visited, vector<vector<int>> &solution, vector<vector<vector<int>>> &master)
{
    if (matrix[i][j] == 0)
    {
        cout << "Sin solucion" << endl;
        return;
    }

    // Push actual
    queue.push({matrix[i][j], i, j});

    // Marcar como visitado
    visited[i].push_back(true);
    while (!queue.empty())
    {
        i = queue.front()[1];
        j = queue.front()[2];

        if (queue.front()[0] == 1 && validate(matrix, i, j))
        {
            solution[queue.front()[1]][queue.front()[2]] = queue.front()[0];
        }
        queue.pop();

        // Arriba
        if (i - 1 >= 0)
        {
            if (!visited[i - 1][j] && matrix[i - 1][j] != 0)
            {
                visited[i - 1][j] = true;

                if (i - 1 >= 0)
                {
                    queue.push({matrix[i - 1][j], i - 1, j});
                    branchBound(matrix, i, j, copy, visited, solution, master);
                }
            }
        }

        // izquierda
        if (j - 1 >= 0)
        {
            if (!visited[i][j - 1] && matrix[i][j - 1] != 0)
            {
                visited[i][j - 1] = true;

                if (j - 1 >= 0)
                { // notita = uwu
                    queue.push({matrix[i][j - 1], i, j - 1});
                    branchBound(matrix, i, j, copy, visited, solution, master);
                }
            }
        }

        // Derecha
        if (j + 1 < matrix[i].size())
        {
            if (!visited[i][j + 1] && matrix[i][j + 1] != 0)
            {
                visited[i][j + 1] = true;

                if (j + 1 < matrix[i].size())
                { // notita = uwu
                    queue.push({matrix[i][j + 1], i, j + 1});
                }
                branchBound(matrix, i, j, copy, visited, solution);
            }
        }

        // Abajo
        if (i + 1 < matrix.size())
        {
            if (!visited[i + 1][j] && matrix[i + 1][j] != 0)
            {
                visited[i + 1][j] = true;

                if (i + 1 < matrix.size())
                {
                    queue.push({matrix[i + 1][j], i + 1, j});
                    branchBound(matrix, i, j, copy, visited, solution);
                }
            }
        }
    }
}

void inputData(int m, int n, vector<vector<int>> &matrix)
{
    string x;
    cin.ignore();

    // Filling the matrix
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        getline(cin, x);
        x.erase(std::remove_if(x.begin(), x.end(), ::isspace),
                x.end()); // Removes white spaces

        matrix.push_back(temp);

        for (int j = 0; j < n; j++)
        {
            matrix[i].push_back((int)x[j] - 48);
        }

        cin.clear();
    }
}

int main()
{
    int m, n;
    vector<vector<int>> matrix;
    queue<vector<int>> queue;

    cin >> m;
    cin >> n;

    vector<bool> falses(n, false);
    vector<vector<bool>> visited(m, falses);

    inputData(m, n, matrix);

    vector<int> zeros(n, 0);
    vector<vector<int>> solution(m, zeros);

    branchBound(matrix, 0, 0, queue, visited, solution);

    cout << "\n";
    for (auto i : solution)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}