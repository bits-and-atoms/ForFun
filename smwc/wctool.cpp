#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printUsage()
{
    cerr << "Invalid input\nUsage:\nsmwc -c <filename> for byte count\nsmwc -l <filename> for line count\nsmwc -w <filename> for word count\nsmwc <filename> for all\n";
    exit(EXIT_FAILURE);
}

int bytesofFile(ifstream &file)
{
    file.seekg(0, ios::end);
    return file.tellg();
}

int linesofFile(ifstream &file)
{
    int linecount = 0;
    string line;
    while (getline(file, line))
    {
        linecount++;
    }
    return linecount;
}

int wordsofFile(ifstream &file)
{
    int wordCount = 0;
    string line;
    while (getline(file, line))
    {
        int n = line.length();
        for (int i = 0; i < n; i++)
        {
            while (i < n and isspace(line[i]))
                i++;
            if (i < n)
                wordCount++;
            while (i < n and !isspace(line[i]))
                i++;
        }
    }
    return wordCount;
}

void handleOption(const string &option, const string &filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Error opening " << filename << "\n";
        printUsage();
        exit(EXIT_FAILURE);
    }
    if (option == "-c")
    {
        cout << filename << " " << bytesofFile(file) << " bytes\n";
    }
    else if (option == "-l")
    {
        cout << filename << " " << linesofFile(file) << " lines\n";
    }
    else if (option == "-w")
    {
        cout << filename << " " << wordsofFile(file) << " words\n";
    }
    else
    {
        cerr << "invalid options\n";
        printUsage();
        exit(EXIT_FAILURE);
    }
    file.close();
}

void handleAll(const string &filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Error opening " << filename << "\n";
        printUsage();
        exit(EXIT_FAILURE);
    }
    cout << filename << " " << bytesofFile(file) << " bytes\n";
    file.clear();
    file.seekg(0);
    cout << filename << " " << linesofFile(file) << " lines\n";
    file.clear();
    file.seekg(0);
    cout << filename << " " << wordsofFile(file) << " words\n";
    file.clear();
    file.seekg(0);
    file.close();
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        handleOption(argv[1], argv[2]);
    }
    else if (argc == 2)
    {
        handleAll(argv[1]);
    }
    else
    {
        printUsage();
    }
    return 0;
}
