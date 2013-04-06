//sg
#include<iostream>
#include<string.h>
using namespace std;
const int MAX = 199;
void inc(char number[], int len)
{
    int carry = 1;
    int index = 0, dig;
    do {
        dig = number[index] - 48; //take out the decimal eqn
        dig = (dig + carry) % 10; //add 1 to it
        number[index] = dig + 48; //update the string
        if (dig == 0) { //check carry
            carry = 1;
            if (index == len - 1) { //number has to expanded
                number[index + 1] = '1';
                number[index + 2] = '\0';
                return; //you never have to go over this here
            }
        } else {
            carry = 0;
        }
        index++;
    } while (carry);
}
void printS(char num[], int len)
{
    for (int i = len - 1; i >= 0; i--)
        cout << num[i];
}
void strrev(char num[])
{
    int l = strlen(num);
    for (int i = 0; i < l / 2; i++) {
        num[i] ^= num[l - i - 1];
        num[l - i - 1] ^= num[i];
        num[i] ^= num[l - i - 1];
    }
}
bool isPali(char num[])
{
    int l = strlen(num);
    for (int i = 0; i < l / 2; i++) {
        if (num[i] != num[l - i - 1]) {
            return false;
        }
    }
    return true;

}
int main()
{
    char num[200];
    cin >> num;
    strrev(num);
    int rem = 10, j = 0;
    while (rem) {
        inc(num, strlen(num));
        if (isPali(num)) {
            printS(num, strlen(num));
            cout << "\n";
            rem--;
        }

    }
    return 0;
}


