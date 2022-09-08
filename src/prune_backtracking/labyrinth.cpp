#include<algorithm>
#include<iostream>
#include<vector>
#include<cctype>
#include<stack>

using namespace std;

void validate()
{

}

bool backtrackingSolution(vector<vector<int>> &solution, vector<vector<int>> &matrix, int x, int y)
{
    if (x == matrix.size() - 1 && y == matrix[x].size() - 1)
        solution[x][y] = 1;

    if (y + 1 < matrix[x].size() && matrix[x][y] == 1)
        if (backtrackingSolution(solution, matrix, x, y+1))
            solution[x][y] = 1; 

    if (x + 1 < matrix.size() && matrix[x][y] == 1)
        if (backtrackingSolution(solution, matrix, x+1, y))
            solution[x][y] = 1; 

    return true;
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
        x.erase(std::remove_if(x.begin(), x.end(), ::isspace), x.end()); // Removes white spaces

        matrix.push_back(temp);

        for (int j = 0; j < n; j++)
            matrix[i].push_back((int)x[j] - 48);

        cin.clear();
    }
}

int main()
{
    int m, n;
    bool cond = true;
    int counter = 0;
    vector<vector<int>> matrix;

    cin >> m;
    cin >> n;

    inputData(m, n, matrix);

    vector<int> zeros(n, 0);
    vector<vector<int>> solution(m, zeros);

    backtrackingSolution(solution, matrix, 0, 0);

    cout << endl;

    for (auto i: solution)
    {
        for (auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
    
