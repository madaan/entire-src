#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct store
{
    struct list * inventory;
};

struct list
{
    struct node * start; 
    int length;
};

struct node 
{
    struct fruit * data;
    struct node * next;
};

struct fruit 
{
    char name[20];
};

/* set inventory to default vals */
void store_init(struct store * store)
{
    store -> inventory = malloc(sizeof(struct list)); 
    store -> inventory -> start = NULL;
    store -> inventory -> length = 0;   
}

void open_store(struct store * store)
{
    struct node * current;
    struct node * traversal_node;
    int i;
    struct fruit *fruits[3];  
    char * fruit_names[] = {"Apple", "Mango", "Orange"};
    for(i=0; i < 3; i++) {
        fruits[i] = malloc(sizeof(struct fruit));
        strcpy(fruits[i]->name, fruit_names[i]);
    }

    for(i=0; i < 3; i++) 
    {
        current = malloc(sizeof(struct node));

        current -> data = fruits[i];
        current -> next = NULL;

        if(store -> inventory -> start == NULL) { /* check if no other nodes have been inserted, if so, insert at start */
            //store -> inventory -> start = malloc(sizeof(struct node));
            store -> inventory -> start = current;
            store -> inventory -> length++;
        } else  {
            traversal_node = store -> inventory -> start;    /* start at header */

            while(traversal_node->next != NULL) {  /* move to end of list */
                traversal_node = traversal_node -> next;
            }
            traversal_node -> next = current;           /* add node */
            store -> inventory -> length++;
        }       

    }

    //printf("%s\n", store -> inventory -> start -> data -> name);

}

void print_inventory(struct store * store)
{
    struct node *item = store -> inventory->start;
    int i;
    for(i = 0 ; i < store -> inventory -> length; i++)  {
        printf("%s\n", item -> data -> name);
        item = item -> next;
    }
}

int main()
{
    struct store store;

    /* intiatlize store */
    store_init(&store);

    open_store(&store);

    print_inventory(&store);

}
