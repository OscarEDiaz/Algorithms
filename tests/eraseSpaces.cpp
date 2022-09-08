#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    string x;

    getline(cin, x);

    x.erase(std::remove_if(x.begin(), x.end(), ::isspace), x.end());

    cout << endl; 
    cout << x; 

    return 0;
}