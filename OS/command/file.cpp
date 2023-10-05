#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    // Check if filename was provided
    if (argc < 2)
    {
        cerr << "Error: filename not provided." << endl;
        return 1;
    }

    // Open file
    ifstream file(argv[1]);

    // Check if file was successfully opened
    if (!file)
    {
        cerr << "Error: file not found." << endl;
        return 1;
    }

    // Read file and print contents
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    // Close file
    file.close();

    return 0;
}
