//sg
#include"Node.h"
#include<stdlib.h>
Node::Node(int valueForNode):data(valueForNode)
{
//initialize next value to be null
next=NULL;
}
Node::Node():data(0)
{
}
inline void Node::updateNode(int newValue)
{
data=newValue;
}
int  Node::getValue()
{
return data;
}
