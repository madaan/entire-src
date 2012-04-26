//sg

import java.awt.*;
import java.awt.event.*;
class Db extends Frame implements ActionListener
{
int r,b,g;
Db()
{
setSize(new Dimension(500,500));
addComponents();
setVisible(true);
addWindowListener(new WindowAdapter()
{
public void windowClosing(WindowEvent we)
{
setVisible(false);
System.exit(0);
}});
}
public void addComponents()
{
MenuBar mbar=new MenuBar();
Menu m=new Menu("File");
MenuItem ex,sp;
m.add(ex=new MenuItem("Exit"));
m.add(sp=new MenuItem("Pick Color"));
setMenuBar(mbar);
mbar.add(m);
ex.addActionListener(this);
sp.addActionListener(this);
}
public void actionPerformed(ActionEvent ae)
{
String st=ae.getActionCommand();
if(st.equals("Exit"))
{
System.exit(0);

}
else
{
new Myd(this,"Sgd1",true).setVisible(true);
setBackground(new Color(r,b,g));
}
}
public static void main(String args[])
{
new Db();
}
}

class Myd extends Dialog implements ActionListener
{
final Db f1;
TextField t1,t2,t3;
Button b1;
Myd(Db f1,String t,boolean m)
{
super(f1,t,m);
this.f1=f1;
setSize(300,300);
setLayout(new FlowLayout());
t1=new TextField(20);

t2=new TextField(20);
t3=new TextField(20);
b1=new Button("OK");

add(t1);
add(t2);
add(t3);
add(b1);
b1.addActionListener(this);
}
public void actionPerformed(ActionEvent ae)
{
 Db db1=f1;
db1.r=Integer.parseInt(t1.getText());
db1.b=Integer.parseInt(t2.getText());
db1.g=Integer.parseInt(t3.getText());

dispose();
}
}




