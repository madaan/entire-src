/*
 * Crypt.cpp
 *
 * Copyright 2012 madaan <aman@aman>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
//sg
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
void createCryptKey(char * seed,char * key)
{
    char init[26][2];
    int l=strlen(seed),keyOff;
    for(int j=0; j<26; j++)
    {
        init[j][0]=static_cast<char>(j+65);
        init[j][1]='0';
    }
    //initially fill the key with seed
    for( keyOff=0; keyOff<l; keyOff++)
    {
        key[keyOff]=seed[keyOff];
        init[seed[keyOff]-65][1]='1';
    }
    for(int i=0; i<26; i++)
    {
        if(init[i][1]=='0')
        {
            key[keyOff++]=init[i][0];
            init[i][1]='1';
        }
    }
}
char * encrypt(char  * message,char * key)
{
    int l=strlen(message);
    char * crypted=new char[l+1];
    int index,i;
    for( i=0; i<l; i++)
    {
        index=message[i]-65;
        crypted[i]=key[index];
    }
    crypted[i]='\0';
    return crypted;
}
int search(char a,char * str)
{
    int i=0;
    while(str[i])
    {
        if(str[i]==a)
        {
            return i;
        }
        i++;
    }
    return -1;
}
char * decrypt(char  * encMessage,char * key)
{
    int l=strlen(encMessage);
    char * deCrypted=new char[l+1];
    int index,i;
    for( i=0; i<l; i++)
    {
        if(encMessage[i]==' ')
        {
            deCrypted[i]=' ';
            continue;
        }
        index=search(encMessage[i],key);
        deCrypted[i]=static_cast<char>(index+65);
    }
    deCrypted[i]='\0';
    return deCrypted;
}
int main()
{
    char key[27],seed[26],message[100];
    key[26]='\0';
    cout<<"Enter the seed : ";
    cin>>seed;
    cin.ignore();
    cout<<"\nEnter the message : ";
    cin.getline(message,100);
    createCryptKey(seed,key);
    cout<<"\nKEY :" <<key<<endl;
    cout<<"\nEncrypted Message : "<<encrypt(message,key)<<endl;
    return 0;
}
