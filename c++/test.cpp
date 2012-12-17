//sg
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char* argv[]) {

    long f;

    fstream myFile("data.txt", fstream::in|fstream::out);
    cout << "f before: " << f << endl;
    myFile >> f;
    cout << "f after: " << f << endl;
    f++;
    cout << "f after increment: " << f << endl;
    myFile.seekp(ios::beg);
    myFile << f<<"\n";
    myFile.close();

    return 0;
}
