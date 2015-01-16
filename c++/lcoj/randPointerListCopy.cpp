/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) {
            return head;
        }
        map<int, RandomListNode*> nodeMap;
        RandomListNode *tmp = new RandomListNode(head->label);
      
        RandomListNode *res = tmp;
        RandomListNode *ptr = head;
        while(ptr) {
            if(ptr->next) {
                
            
            map<int, RandomListNode*>::iterator i = nodeMap.find(ptr->next->label);
            if(i == nodeMap.end()) {
                RandomListNode *nxt = new RandomListNode(ptr->next->label);
                nodeMap[ptr->next->label] = nxt;
                tmp->next = nxt;
            } else {
                tmp->next = (*i).second;
            }
            } else {
                tmp->next = NULL;
            }
            if(ptr->random) {
                
            
            map<int, RandomListNode*>::iterator i = nodeMap.find(ptr->random->label);
            
            if(i == nodeMap.end()) {
                RandomListNode *rnd = new RandomListNode(ptr->random->label);
                nodeMap[ptr->random->label] = rnd;
                tmp->random = rnd;
            } else {
                tmp->random = (*i).second;
            }
            } else {
                ptr->random = NULL;
            }
            tmp = tmp->next;
            ptr = ptr->next;
        }
        return res;
    }
};
