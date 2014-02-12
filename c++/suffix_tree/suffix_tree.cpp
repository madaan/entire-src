//sg
#include "suffix_tree.h"
//the constructor
SuffixTree::SuffixTree(char *str) 
{
    int len = strlen(str);
    parent = new Node();
    //generate all suffixes and attach them
    for(int i = len - 1; i >= 0; i--) {
        attachSuffix(parent, str + i);
    }
}

//attaches a child with the given value to the parent
//and returns the child
Node *SuffixTree::attachNode(Node *parent, char childVal)
{
    Node * child = new Node();
    child -> nodeVal = childVal;
    parent->child[parent->numChildren] = child;
    parent->numChildren += 1;
    return child;
}

//attaches a given suffix to the node
//Poor implementation, O(n^2)
void SuffixTree::attachSuffix(Node *parent, char * str)
{
    Node * curr = parent;
    bool placeFound = false; 
    int level = 0;
    int len = strlen(str);
    while(!placeFound) 
    {
        placeFound = true;
        for(int i = 0; i < curr -> numChildren; i++) {
            if((curr -> child[i]) -> nodeVal == str[level]) {
                curr = curr -> child[i];
                level += 1;
                placeFound = false;
                break;
            }
        }
    }
    //create a chain now starting from the curr node
    for(int i = level; i < len; i++) {
        curr = attachNode(curr, str[i]);
    }
}
        

//prints the suffix tree in bfs
void SuffixTree::print_stree(Node *parent)
{
    queue<Node *> q;
    q.push(parent);
    printf("\n");
    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();
        printf("%c ", curr -> nodeVal);
        for(int i = 0; i < curr -> numChildren; i++) {
            q.push(curr -> child[i]);
        }
    }
        printf("\n");
}

//checks whether the substring appears in a string
bool SuffixTree::search_stree(char *str)
{
    Node * curr = parent;
    bool strFound = false; 
    int level = 0;
    int len = strlen(str);
    int currChildren = 0;
    while(!strFound && level <= len) 
    {
        strFound = true;
        for(int i = 0; i < curr -> numChildren; i++) {
            if((curr -> child[i]) -> nodeVal == str[level]) {
                level += 1;
                strFound = false;
                curr = curr -> child[i];
                if(level == len) {
                    return true;
                }
                break;
            }
        }
    }
    return false;
}
