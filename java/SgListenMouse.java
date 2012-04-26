//sg
import java.io.*;
import java.net.*;
class SgListenMouse
{
public void startListening()
{
boolean flag=true;
Integer x,y;
try{
ServerSocket ss=new ServerSocket(1112);
Socket s=ss.accept();
InputStream i=s.getInputStream();

BufferedReader br=new BufferedReader(new InputStreamReader(i));
while(flag)
{
String a=br.readLine();
String coords[]=a.split(" ");
x=Integer.parseInt(coords[0]);

y=Integer.parseInt(coords[1]);
if((x==0)&&(y==0))
{
flag=false;
}
            Runtime rt = Runtime.getRuntime();
		FileWriter fop=new FileWriter ("mdata");
		fop.write(a);	
	fop.close();
            Process proc = rt.exec("./a.out "+x+" "+y);
            int exitVal = proc.waitFor();
            System.out.println("Process exitvalue: " + exitVal);

}
}
catch(Exception e)
{
System.out.println( e);
}
}
public static void main(String args[])
{
new SgListenMouse().startListening();
}
}

