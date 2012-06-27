//sg
class StandardizeSolution
{
private static String squeezer(String solution)
{
String moves[]=solution.split(";");
String squeezedSolution="";
Integer numberInT=0;
Integer len=moves.length;
System.out.println( len.toString());
int left=0,right=0,i=0;
while(i<len)
{
left=i;
right=left-1;
while((i<len)&&(moves[i].charAt(0)=='t')) 
{
right=i;
i++;
}
if(right>=left)
{
for(int j=left;j<=right;j++)
{
numberInT+=Integer.parseInt(moves[j].split(":")[1]);
}
squeezedSolution+="t:"+numberInT+";";
numberInT=0;
}

else
{
squeezedSolution+=moves[i]+";";
i++;
}
}
return squeezedSolution;
}
public static void main(String args[])
{
String userSolution=args[0];
System.out.println("User Solution ->"+userSolution);
System.out.println("Solution after squeezing -> "+squeezer(userSolution));
}
}
