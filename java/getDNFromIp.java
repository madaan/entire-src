//sg
import java.net.*;
import static java.lang.System.out;
class j1
{
public static void main(String args[])
{
try{
byte b[]={(byte)209,(byte)85,(byte)148,(byte)106};
out.println("sf");
InetAddress sw=InetAddress.getByAddress(b);
out.println(sw.getHostName());
InetAddress addr = InetAddress.getByName("209.85.148.106");
  String host = addr.getHostName();
  System.out.println(host);
}
catch(UnknownHostException e)
{
System.out.println(e);
}
}
}
