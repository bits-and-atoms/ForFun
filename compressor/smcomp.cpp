#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void freqCalc(const string &filename){
    ifstream file(filename,ios::binary);
    if (!file)
    {
        cerr << "Error opening " << filename << "\n";
        exit(EXIT_FAILURE);
    }

}
int main(){

    return 0;
}