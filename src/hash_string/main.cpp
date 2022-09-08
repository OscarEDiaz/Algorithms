#include<iostream>
#include<fstream>
#include<limits>
#include<vector>

/*  Polyalphabetic cypher algorithm
    September 04, 2022

    @ Oscar Emiliano Ramírez Díaz
    @ Ángel Rubén Vázquez Rivera
    @ José Israel Pérez Ontiveros
*/

using namespace std;

// O(n) complexity
void hashString(int n, fstream &file)
{
    vector<int> arr(n, 0);
    int j = 0;

    string line;
    string result;

    while(getline(file, line))
    {
        result += line;
        if (!file.eof())
            result.append(1, 10);
    }

    int rest = n - result.length() % n;
    string restData(rest, n);

    result += restData;

    for (int i = 0; i < result.size(); i++)
    {
        if (i % n == 0)
            j = 0;
        
        arr[j] += int(result[i]);
        j++;
    }

    for (int i = 0; i < n; i++)
        arr[i] %= 256;

    for (int x: arr)
    {
        x < 16 ? cout << uppercase << hex << '0' << x : cout << uppercase << hex << x;
    }

    file.close();
}

// O(n) complexity
bool validate(int &n, string &filename, fstream &file)
{
    
    while (n > 64 || n < 16 || n % 4 != 0)
    {
        cout << "Please input a valid n:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> n;
    }

    cin.ignore();

    getline(cin, filename);

    filename = "./data/" + filename + ".txt";

    file.open(filename);
    
    return file.is_open() ? true : false;    
} 

// O(1) complexity
int main()
{
    int n;

    cin >> n;

    fstream file;
    string filename;
    
    if (validate(n, filename, file))
        hashString(n, file);
    else
        cout << "Invalid input data.";

    return 0;
}