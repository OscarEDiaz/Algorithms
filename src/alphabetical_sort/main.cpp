#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void conquer(vector<string> &words, int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    vector<string> aux;

    while(i <= middle && j <= right)
    {
        if (words[i] <= words[j])
        {
            aux.push_back(words[i]);
            i++;
        }
        else
        {
            aux.push_back(words[j]);
            j++;
        }
    }


    // Filling the rest
    while (i <= middle)
    {
        aux.push_back(words[i]);
        i++;
    }

    while (j <= right)
    {
        aux.push_back(words[j]);
        j++;
    }

    for (auto x: aux)
    {
        words[left] = x;
        left++;
    }
}

void divide(vector<string> &words, int left, int right)
{
    if (left >= right)
        return;

    int middle = left + (right - left)/2;

    divide(words, left, middle);
    divide(words, middle + 1, right);
    conquer(words, left, middle, right); 
}

vector<string> vectorSuffix(string word)
{
    vector<string> x;

    for (int i = word.length() - 1; i >= 0; i--)
        x.push_back(word.substr(i, i + word.length()));

    return x;
}

int main()
{
    vector<string> words;
    
    string word = "";
    cin >> word;
    
    words = vectorSuffix(word);
    
    divide(words, 0, words.size() - 1);

    for (auto x: words)
        cout << x << " "; 

    return 0;
}