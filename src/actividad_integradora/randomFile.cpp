#include "randomFile.h"

randomFile::randomFile(string data, string pattern)
{
    this->data = data;
    this->pattern = pattern;
}

void randomFile::generate(string filename)
{
    ofstream file;
    srand(time(NULL));
    
    file.open(filename);

    int randFill;
    int randPattern;

    for (int i = 0; i < 50; i++)
    {
        randFill = (rand() % this->data.length()) + 0;
        randPattern = (rand() % 10) + 0;
        
        if (randPattern == 5)
            file << this->pattern;

        file << this->data[randFill];
    }

    file.close();
}