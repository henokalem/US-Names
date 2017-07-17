
#include <fstream>

using namespace std;

int main()
{
        int begin = 1880;
        int end = 2014;
        ofstream myfile;
        myfile.open("inputFile.txt");
        while(begin <=end)
        {
                myfile <<"namesData/yob" << begin << ".txt\n";
                ++begin;
        }
        myfile.close();


        return 0;
}
