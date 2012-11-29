
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class FibonnaciServer  implements Runnable 
{
	ServerSocket ss;
	Socket cs;
	int fibo[];
	public static void main(String arg[])
    {
    	new FibonnaciServer("Fibonnaci Server");
    }
    
    public FibonnaciServer(String m) 
    {
    	try
    	{
    	fibo =new int[30];
    	fillFibo();
    	ss=new ServerSocket(1234);
    	startListening();
    	}
    	catch(Exception e)
    	{
    		
    		System.out.println(e.toString());
    	}
    }
    void startListening()
    {
   try
   {
	   while(true)
	   {
		   System.out.println("Hello");
	   cs=ss.accept();
	   Thread th=new Thread(this);
	   th.start();
	   }
	   
   }catch(Exception e){
	   System.out.println(e.toString());
   }
    	
    }
    public void run()
    { 
    	BufferedReader br;
    	BufferedWriter bw;
    	System.out.println("Creating a new connection\n");
    try
    {
    br=new BufferedReader(new InputStreamReader(cs.getInputStream()));
    bw=new BufferedWriter(new OutputStreamWriter(cs.getOutputStream()));  
    Integer n;
    	while(true)
    	{
    	n=Integer.parseInt(br.readLine());
    	if(n==0)
    	{
    		break;
    	}
    	System.out.println("Serving : "+fibo[n]);
    	bw.write("Fibonnaci ("+n+") = "+Integer.toString(new Integer(fibo[n]))+"\n");
    	bw.flush();
    	} //keep listening
    }
    catch(Exception e)
    {
    	System.out.println(e.toString());	
    	System.exit(0);
    }   
    }

    
    void fillFibo()
    {
    int i=3;
    fibo[0]=1;
    	fibo[1]=1;
    	fibo[2]=2;
    	
    	while(i<20)
    	{
    		fibo[i]=fibo[i-1]+fibo[i-2];
    		i++;
    	}
    }
    
   
    
}

 /* 
 
Server : 
 
[aman@aman src]$ java FibonnaciServer
Hello
Hello
Creating a new connection

Serving : 233


Client : 

[aman@aman src]$ telnet localhost 1234
Trying ::1...
Connected to localhost.
Escape character is '^]'.
12
Fibonnaci (12) = 233
5
Fibonnaci (5) = 8

*/
