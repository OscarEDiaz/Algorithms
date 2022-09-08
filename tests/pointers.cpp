#include <iostream>
#include <List>

using namespace std;

int main()
{
    string s = "123456783";
    int rows = 4;

    char **matrix;

    // Allocating memory for each "array"
    matrix = (char **)malloc(rows * sizeof(char*));
    
    int columns = s.length() / rows;

    if (s.length() % rows > 0)
        columns++;

    // Allocating memory
    for (int i = 0; i < rows; i++)
        matrix[i] = (char*)malloc(columns*sizeof(char));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = 97;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    free(matrix);

    return 0;
}