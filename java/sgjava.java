//sg
import java.util.*;
import java.io.*;
public class sgjava
{
    public static void main(String args[])
    {
        try
        {
int i=0;            
            Runtime rt = Runtime.getRuntime();
while(i<5)
{
            Process proc = rt.exec("./a.out");
            int exitVal = proc.waitFor();
            System.out.println("Process exitValue: " + exitVal);
i++;
        }
} catch (Throwable t)
          {
            t.printStackTrace();
          }
    }
}
