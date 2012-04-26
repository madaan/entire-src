//sg
package p2;
import p1.MyClass;
class Demo extends MyClass
{
public static void main(String args[])
{

Demo my=new Demo();
MySamePClass same=new MySamePClass();

System.out.println("\nProtected ="+my.pro+"\nPublic ="+my.pu);
System.out.println("Default ="+same.d+"\nProtected ="+same.pro+"\nPublic ="+same.pu);


}}
