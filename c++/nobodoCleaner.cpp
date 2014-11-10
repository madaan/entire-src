//sg
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
long long ph1[200000],ph2[200000];
int labelledph1[200000],labelledph2[200000];
fstream fnc,fc;
void layDataInMemory(int numRec);
void assignLabels(int numRec);
void assignLabelsToPh2(long long item,int label,int numRec);
void assignLabelsToUnlabelledPh2(int numRec,int label);
void displayLabelledData(int numRec);
main(int argc,char * argv[])
{
    if(argc!=3)
    {
        cout<<argc;
        cout<<"Usage : Unclean file <space> number of records\nOutput file : UncleanFileNameCleaned.pairs\nThe Program will now exit\n";
        exit(0);
    }
    int numRec=atoi(argv[2]);
    fnc.open(argv[1],ios::in);
    char * fileOutName=strcat(argv[1],"Cleaned.pairs");
    fc.open(fileOutName,ios::out);
    layDataInMemory(numRec);
    assignLabels(numRec);
    displayLabelledData(numRec);
//Records Prepared
}
void layDataInMemory(int numRec)
{
    int i=0;
    while(i<numRec)
    {
        fnc>>ph1[i]>>ph2[i];
//cout<<"\nReading record "<<i<<" :"<<ph1[i]<<"  "<<ph2[i];
        i++;
    }
    cout<<"Read "<<i<<" records";
}
void assignLabels(int numRec)
{
    long label=1;
    long j=0;
    long long prevNum;
    prevNum=ph1[0];
    cout<<prevNum<<endl;
    while(j<numRec)
    {
//   cout<<"\nComparing "<<prevNum<<" with "<<ph1[j];
        while(prevNum==ph1[j])
        {
            labelledph1[j++]=label;

//     cout<<"\nAssigning "<<label<<" to "<<ph1[j-1]<<endl;
        }
        assignLabelsToPh2(prevNum,label,numRec); //now label ph2

        prevNum=ph1[j];
        label++;
    }
    assignLabelsToUnlabelledPh2(numRec,label);
}
//assign the given label to all the items in ph2
void assignLabelsToPh2(long long item,int label,int numRec) //pass 1
{
    for(int i=0; i<numRec; i++)
    {
        if(ph2[i]==item)
        {
            labelledph2[i]=label;
        }
    }
}
void assignLabelsToUnlabelledPh2(int numRec,int label)  //pass 2
{
    int totalRecs=0;
    for(int i=0; i<numRec; i++)
    {
        if(labelledph2[i]==0)
        {
            assignLabelsToPh2(ph2[i],label++,numRec);

        }

    }
    cout<<"\nDONE\n";
}
void displayLabelledData(int numRec)
{
    for(int i=0; i<numRec; i++)
    {
        fc<<labelledph1[i]<<"\t"<<labelledph2[i]<<"\n";
    }
}
