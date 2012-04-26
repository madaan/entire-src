//sg
class outer{
   void show1(){
     System.out.println( "outer show");
   }
void show()
{
new inner().show();
}
  class inner{
     void show(){
        System.out.println("inner show");
outer.this.show1();     
}
  }
public static void main(String args[])
{
outer o=new outer();

//inner i=new inner();

//i.show();
o.show();
}
}
