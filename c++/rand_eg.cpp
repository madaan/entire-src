//sg
#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
using namespace std;
class RandomDistro
{
private :
    static string names [];
    const int LENGHT;
public :
    RandomDistro(): LENGHT(5) {
    }
    string getRandomDistro() {
        srand(time(NULL));
        int index = rand() % LENGHT;
        return names[index];
    }
};
string RandomDistro::names[5] = {"Fedora", "Mint", "Ubuntu", "SlackWare", "OpenSUSE"};
int main()
{
    RandomDistro rd;
    cout << rd.getRandomDistro();
    return 0;
}