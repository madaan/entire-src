
//sg
class LoopExpander
{
private static String loopExpander(String solution)
{
String moves[]=solution.split(";");
String expandedSolution="";
Integer loopVar=0,noStatements;
Integer len=moves.length;
System.out.println( len.toString());
int left=0,right=0,i=0,j=0;
while(i<len)
{
if(moves[i].charAt(0)=='r')
{

loopVar=Integer.parseInt(moves[i].split(":")[2]);
noStatements=Integer.parseInt(moves[i].split(":")[1]);
while((i<len)&&(moves[i+1].charAt(0)=='r')) // checks nesting
{

loopVar*=Integer.parseInt(moves[i+1].split(":")[2]);
i++;
}
loopVar=loopVar-1; //the instruction itself is not to be added
while(loopVar!=0)
{
j=1;
while(j<=noStatements)
{
expandedSolution+=moves[i+j]+";";
j++;
}
loopVar--;
}
}
else
{
expandedSolution+=moves[i]+";";
}
i++;
}
return expandedSolution;
}

public static void main(String args[])
{
System.out.println( "Your Input : "+args[0]);
System.out.println( "Expanded Output : " +loopExpander(args[0]));

}
}
