//sg
import java.net.DatagramPacket;
import java.net.DatagramSocket;
public class FileServer {

int SERVER_PORT=1235;
int CLIENT_PORT=1234;

DatagramSocket ss;
DatagramPacket requestPacket;
DatagramPacket replyPacket;
byte[] choice;
int INT_SIZE=4;		

FileServer()
	{
		try {
	choice=new byte[1000];			
			ss=new DatagramSocket(SERVER_PORT);
			requestPacket=new DatagramPacket(choice,1000);
			serveFile();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

void serveFile()
	{
try{		
		while(true)
		{			
			ss.receive(requestPacket);
			System.out.println("Got : "+new String(requestPacket.getData(),0,requestPacket.getLength()));
		}		
	
} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		 
		
	}
	public static void main(String[] args)
	{	
		
		new FileServer();
	}

}
/* Server Side 
 
 
[aman@aman src]$ java FileServer
Got : Hello UDP
Got : Quick Web Access
Got : 
[aman@aman src]$ java FileClient
Hello UDP
Sending Hello UDP
Quick Web Access
Sending Quick Web Access

Sending 

*/
