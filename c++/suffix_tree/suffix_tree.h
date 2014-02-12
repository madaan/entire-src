#ifndef STREE
#define STREE
//sg
#include <string.h>
#include <queue>
#include <stdio.h>
#define MAX_CHILDREN 100
using namespace std;
struct Node;
struct Node
{
    char nodeVal;
    int numChildren;
    Node **child;
    Node()
    {
        numChildren = 0;
        nodeVal = ' ';
        child = new Node*[MAX_CHILDREN];
        for(int i = 0; i < MAX_CHILDREN; i++) {
            child[i] = NULL;
        }
    }
};


class SuffixTree
{
    public :
        Node *parent;

        //take a string and create a tree
        SuffixTree(char *str) ;
        
        //prints the suffix tree in bfs
        void print_stree(Node *parent);
        
        //checks whether the substring appears in a string
        //returns number of matches if yes or -1 if no
        bool search_stree(char *str);

 
    private:
        //attaches a given suffix to the node
        void attachSuffix(Node *parent, char * str);
        
        //attaches a child with the given value to the parent
        //and returns the child
        Node *attachNode(Node *parent, char childVal);
};
#endif
