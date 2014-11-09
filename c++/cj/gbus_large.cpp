//sg
#include<bits/stdc++.h>
using namespace std;


#define N  5009
#define MAX (1+(1<<22))
#define inf 0x7fffffff

/*SEGMENT TREE IMPLEMENTATION TAKEN FROM :
 *http://se7so.blogspot.in/2012/12/segment-trees-and-lazy-propagation.html
 */
int arr[N];
int tree[MAX];
int lazy[MAX];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range

    if(a == b) { // Leaf node
        tree[node] = arr[a]; // Init value
        return;
    }

    build_tree(node*2, a, (a+b)/2); // Init left child
    build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

    tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

    if(lazy[node] != 0) { // This node needs to be updated
        tree[node] += lazy[node]; // Update it

        if(a != b) {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    }

    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;

    if(a >= i && b <= j) { // Segment is fully within range
        tree[node] += value;

        if(a != b) { // Not leaf node
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }

        return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

    tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

    if(a > b || a > j || b < i) return -inf; // Out of range

    if(lazy[node] != 0) { // This node needs to be updated
        tree[node] += lazy[node]; // Update it

        if(a != b) {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    }

    if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return tree[node];

    int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    int res = max(q1, q2); // Return final result

    return res;
}

int main() {
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        int sa, sb;
        printf("Case #%d: ", tt);
        build_tree(1, 0, N-1);
        memset(lazy, 0, sizeof lazy);
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
             cin >> sa >> sb;
             update_tree(1, 0, N-1, sa, sb, 1); // Increment range [0, 6] by 5
        }
         int p;
         cin >> p;
         for(int k = 0; k < p; k++) {
             cin >> sa;
             //cout << sa << "\n";
            cout << query_tree(1, 0, N-1, sa, sa) << " "; // Get max element in range [0, N-1]
         }
         cout << "\n";
    }
    return 0;
}
