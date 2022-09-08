#include <string>
#include <time.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

class randomFile
{
    private:
        string data;
        string pattern;
    public:
        randomFile(string data, string pattern);
        
        void generate(string filename);
};
