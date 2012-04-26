//sg
class A implements Runnable 
{
B b;
A()
{}
public void setB(B b)
{
this.b=b;

}
public void run()
{
fooA();
}
synchronized public void fooA()
{
System.out.println( "INSIDE FOO A ,GOING TO FOO B");
b.fooB();
}
synchronized public void A1()
{
System.out.println( "here in a1");
}
}

class B implements Runnable 
{
A a;
B()
{}
public void setA(A a)
{
this.a=a;
}
public void run()
{
fooB();
}
synchronized public void fooB() 
{
System.out.println( "INSIDE FOO B,GOING TO FOO A");
try{
Thread.sleep(4000);}
catch( InterruptedException ie){}
a.fooA();
}
synchronized public void B1(){
System.out.println( "here in b1");
}
}
class j1
{
public static void main(String args[])
{
Thread t1,t2;
A a1=new A();
B b1=new B();
a1.setB(b1);
b1.setA(a1);
t1=new Thread(a1);
t2=new Thread(b1);
t1.start();
t2.start();
}
}
