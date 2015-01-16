//sg
/* Number Generator to create data sets for testing sorting
 * algorithms
 * Author : Aman Madaan <madaan.amanmadaan@gmail.com>
 */
#include<fstream>
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
class NumberGenerator
{
    fstream f;
    const char * filename;
    int N; //how many numbers to be generated
    int rangeL,rangeU; // numbers will be generated from rangeL to rangeU
public:
    NumberGenerator(const char * filename,int N,int rangeL,int rangeU)
    {
        f.open(filename,ios::out);
        this->rangeL=rangeL;
        this->rangeU=rangeU;
        this->N=N;
        this->filename=filename;
    }
    /*
     * Writes the numbers to the file specified
     *
     */
    void setFileName(const char * ptr)
    {
        filename=ptr;
        f.close();
        f.open(filename,ios::out);
    }
    void setRange(int rangeL,int rangeU)
    {
        this->rangeL=rangeL;
        this->rangeU=rangeU;
    }
    void setN(int N)
    {
        this->N=N;
    }
    void writeRandom()
    {
        srand(time(NULL));// initialize random number generator
        int randNum;
        f<<N<<"\n";
        for(int i=0; i<N; i++)
        {
            randNum=rand()%(rangeU-rangeL)+rangeL;
            f<<randNum<<"\n";
        }
    }
    /*
     * deletes the file
     */
    void deleteFile()
    {
        remove(filename);
    }
    void writeAscending()
    {
        f<<N<<"\n";
        for(int i=1; i<=N; i++)
        {
            f<<i<<"\n";
        }
    }
    void writeDescending()
    {
        f<<N<<"\n";
        for(int i=N; i>=1; i--)
        {
            f<<i<<"\n";
        }
    }
    void writeSame()
    {
        f<<N<<"\n";
        int randNum=rand()%(rangeU-rangeL)+rangeL;
        for(int i=0; i<N; i++)
        {
            f<<randNum<<"\n";
        }
    }
};
int main()
{
    NumberGenerator rg("tmp.txt",1000,50,6230);
    rg.writeRandom();
    //now write to a different file with different name
    rg.setRange(35,40);
    rg.setFileName("tmp2.txt");
    rg.writeAscending();
    //write the numbers with new config
    //rg.deleteFile(); uncomment if you want to delete the file
    return 0;
}
