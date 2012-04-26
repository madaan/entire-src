# include<array>
# include<iostream>

using namespace std;

class sample : public object
{ 
 private:
  int data;
 public:
  sample(const int d)
  {data=d;}
  sample()
  {}
  sample(const sample& sourcesample)
  {data=sourcesample.data;}
  classType isA() const
  {return "sampleclass";}
  char* nameof() const
  {return "sample";}
  void printon(ostream& outputstream) const
  {outputstream<<"**"<<data<<"**";}
  hashvaluetype hashvalue() const
  {hashvaluetype value=data; return value;}
  int isequal(const object& testsample) const
  {return(data==((sample&)testsample).data);}
};


int main (int argc, char *argv[])
{
 array arr(3);
 sample* s1=newsample(99);
 sample* s2=newsample(101);
 sample* s3=newsample(111);
 sample* s4=newsample(113);

 arr.add(*s1);
 arr.add(*s2);
 arr.add(*s3);
 arr.add(*s4);

 cout<<"\narray contents:\n';
 arr.printcontentson(cout);
 cout<<endl;
 cout<<"elements:\n";
 for(int j=0;j<arr.arraysize();j++)
 {
  arr[j].printon(cout);
  cout<<endl;
 }
 arr.detach(1);
 arr.detach(2);
 cout<<"\narray contents:\n";
 arr.printcontentson(cout);
}
