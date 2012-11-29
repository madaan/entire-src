//sg
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
public class FileClient {
int SERVER_PORT=1235;
int CLIENT_PORT=1234;
int INT_SIZE=4;
int MAX_SIZE=1000;
String file_choice;
DatagramPacket reqestPacket;
DatagramPacket replyPacket;
DatagramSocket cs;
byte [] fileContents;
FileClient(String file_choice)
{
	fileContents=new byte[MAX_SIZE];
	this.file_choice=file_choice;
	try {
		cs=new DatagramSocket(CLIENT_PORT);
		requestPacket();
	} catch (SocketException e) {
		e.printStackTrace();
	}
}
void requestPacket()
{
	
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	byte request[]=new byte[INT_SIZE]; //4 bytes is 1 int
	request=file_choice.getBytes();
	String temp;
	try {
		//send request
		for(int i=0;i<1000;i++)
		{
		Thread.sleep(1000);		
		temp=br.readLine();
		System.out.println("Sending "+temp );
		cs.send(new DatagramPacket(temp.getBytes(),temp.length(),InetAddress.getLocalHost(),SERVER_PORT ));
		}		
		cs.send(new DatagramPacket(request,0,InetAddress.getLocalHost(),SERVER_PORT ));
		replyPacket=new DatagramPacket(fileContents,MAX_SIZE);
		cs.receive(replyPacket);
		System.out.println(replyPacket.getData().toString());
	} 
	catch( Exception e) 
	{
		e.printStackTrace();
	}
}
public static void main(String args[])
{
	new FileClient("ALPHA");
}
}
