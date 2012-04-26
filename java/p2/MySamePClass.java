
//sg
package p2;
class MySamePClass
{
private int pr;
protected int pro;
public int pu;
int d;
MySamePClass()
{
pr=pro=pu=d=0;
}
public void show()
{
System.out.println("Class In Same Package-->\nDefault ="+d+"\nProtected ="+pro+"\nPublic ="+pu+"\nPrivate ="+pr);
}
}

