//sg
/*<applet code="Jform.class" height=600 width=600></applet>*/
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class Jform extends JApplet
{

Label ln,ladd,lph;
JTextField tn,tph;
TextArea tadd;
JButton jb;
public void init() 
{
try
{

SwingUtilities.invokeAndWait(new Runnable()
{
public void run()
{

makeGUI();
}
});

}

catch(Exception e)
{}}
void makeGUI()
{

ln=new Label("NAME: ");
ladd=new Label("ADDRESS : ");
lph=new Label("PHONE NO: ");
tn=new JTextField(30);
tph=new JTextField(10);
jb=new JButton("OK!");
tadd=new TextArea(10,20);
Panel p=new Panel();
JTabbedPane jt=new JTabbedPane();
p.setLayout(new GridLayout(4,3));
p.add(ln);
p.add(tn);
p.add(lph);
p.add(tph);
p.add(ladd);
p.add(tadd);
p.add(jb);
setLayout(new BorderLayout(200,200));


JScrollPane jsp=new JScrollPane(jt,ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
jt.addTab("SG!",p);
add(jsp);
}

public  Insets getInsets()
{
return new Insets(100,100,100,100);

}}
