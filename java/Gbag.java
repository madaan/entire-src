//sg
import java.awt.*;
import java.awt.event.*;
class Gbag extends Frame
{
TextArea t1;
Button b1,b2;
GridBagLayout gbl;
GridBagConstraints gbc;
Gbag(String str)
{
super(str);
gbl=new GridBagLayout();
gbc=new GridBagConstraints();
t1=new TextArea("TEXT HERE",20,20,TextArea.SCROLLBARS_NONE);
b1=new Button("sg1");
b2=new Button("sg2");
arrange();
setSize(600,600);
setVisible(true);
addWindowListener(new WindowAdapter()
{
public void windowClosing(WindowEvent we)
{
setVisible(false);
System.exit(0);
}
}
);
}
public void arrange()
{
setLayout(gbl);
gbc.anchor=GridBagConstraints.NORTHWEST;
gbc.gridwidth=GridBagConstraints.REMAINDER;
gbl.setConstraints(t1,gbc);
add(t1);
gbc.gridy=1;
gbc.gridwidth=GridBagConstraints.REMAINDER;
gbl.setConstraints(b1,gbc);
add(b1);

gbc.gridwidth=GridBagConstraints.RELATIVE;
gbl.setConstraints(b2,gbc);
add(b2);
}
public static void main(String args[])
{
new Gbag("sg1");

}
}
