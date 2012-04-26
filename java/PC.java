//sg
import java.util.Random;
class MemoryArea
{
int data;
boolean sf;
synchronized void producer(int num)
{
notify();
System.out.println("PRODUCING : "+num);
data=num;
}
synchronized void consumer()
{

try
{
if(!sf)
{
wait();
}
}

catch(Exception e){}
sf=false;
notify();
System.out.println("CONSUMING : "+data);
}

}
class Producer implements Runnable
{
MemoryArea m1;
Producer(MemoryArea m1)
{
this.m1=m1;
}
public void run()
{
Random r=new Random();

for(int i=0;i<100;i++)
{
try
{
if(m1.sf)
{
synchronized(m1)
{
m1.wait();
}
}
}
catch(Exception e){System.out.println(e);}
try
{
m1.producer(r.nextInt());
m1.sf=true;
System.out.println("PRODUCER");

synchronized(m1)
{
m1.notify();
}

Thread.sleep(500);
}
catch(Exception e)
{
System.out.println(e);
}
}
}
}
class Consumer implements Runnable
{

MemoryArea m1;
Consumer(MemoryArea m1)
{
this.m1=m1;
}
public void run()
{
for(int i=0;i<100;i++)
{

try
{
if(!m1.sf)
{
synchronized(m1)
{
m1.wait();
}
}
}

catch(Exception e){System.out.println(e);}
try
{
m1.consumer();
m1.sf=false;
System.out.println("CONSUMER");

synchronized(m1)
{
m1.notify();
}
Thread.sleep(500);
}
catch(Exception e)
{
}

}
}
}
class PC
{
public static void main(String args[])
{
MemoryArea m1=new MemoryArea();
Thread t1,t2;
Producer p=new Producer(m1);
Consumer c=new Consumer(m1);
t1=new Thread(c);
t2=new Thread(p);
t1.start();
t2.start();
try
{
t1.join();
t2.join();
}
catch(Exception e)
{
}
}
}

