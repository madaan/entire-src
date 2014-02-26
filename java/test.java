import java.util.Scanner;
import java.io.*;

public class test{
public static void main(String[] args) {
int a = 0;
String str = "";
String str2 = " ";
System.out.println("hello");

//System.out.println(a);

BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
try {
str = br.readLine();
str2 = br.readLine();
System.out.println(str + str2);

} catch(IOException ex) {
 System.out.println("exception: " + ex);
}
Scanner sc = new Scanner(System.in);

 for (int i = 0; i < 2; i++) {
  System.out.println(sc.nextInt());
 }

 }
}
