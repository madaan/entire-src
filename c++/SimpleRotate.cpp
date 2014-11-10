//sg
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    srand(time(NULL));
    char message[100],figletString[100];
    int key=rand()%26,l;

    sprintf(figletString," figlet -c KEY = %d",key);
    cout<<"Enter the message : ";
    cin.getline(message,100);

    l=strlen(message);
    system(figletString);
    for(int i=0; i<l; i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
                message[i]=static_cast<char>((message[i]-65+key)%26+65);
            else
                message[i]=static_cast<char>((message[i]+key-97)%26+97);
        }

    }
    cout<<"\nAFTER ROTATION : "<<message;

    return 0;
}

