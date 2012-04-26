//sg
import java.io.*;
class j1
{
public static void main(String args[])
{
try{
FileWriter f1=new FileWriter("a1.txt");
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
String str="BEGIN";
while(str.length()!=1)
{
str=br.readLine()+"\n";
f1.write(str);
f1.flush();
}

FileInputStream fi=new FileInputStream("a1.txt");
int i;
while((i=fi.read())!=-1)
{
System.out.print((char)i);
}
}
catch(Exception e){
System.out.println( e);}
}
}
