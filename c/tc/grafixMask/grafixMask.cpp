//sg
#include<stdio.h>
#include<iostream>
#include<stack>
#include<stdlib.h>
#include<string>
#include<string.h>
#define HEIGHT 10
#define WIDTH 7

void getCoordinates(char * str, int * corr) {
char temp[20];
int l = strlen(str);
int i = 0, j = 0;
int pos = 0; // 0->top, 1->left, 2->bottom, 3->right
while(i < l ) {
    j = 0;
while(str[i] != ' ' && i < l) {
temp[j++] = str[i++];
}
i++;
temp[j] = '\0';
corr[pos++] = atoi(temp);

}

}
struct node {
    int x, y;
    node(int x, int y) {
        this-> x = x;
        this->y = y;
    }
    node() {
        x = y = 0;
    }
};
bool fill[HEIGHT][WIDTH];

int dfs(node);

void dumpGrid() {
printf("\n\n");
for(int x = 0; x < HEIGHT; x++) {
    for(int y = 0; y < WIDTH; y++) {
    if(fill[x][y]) {
        printf("X ");
    }
    else {
        printf(". ");
    }
    }
    printf("\n");
}
}
void sortedAreas(char * rectangles[],int n) {
//set up fill
int top, left, bottom, right;

for(int x = 0; x < HEIGHT; x++) {
    for(int y = 0; y < WIDTH; y++) {
    fill[x][y] = false;

    }
}
int pos[4];
for(int i = 0; i < n; i++) { //process each rectangle
        getCoordinates(rectangles[i], pos);
        top = pos[0];
        left = pos[1];
        bottom = pos[2];
        right = pos[3];
        for(int x = top; x <= bottom; x++) {
            for(int y = left; y <= right; y++) {
                fill[x][y] = true;
            }
        }
}
for(int x = 0; x < HEIGHT; x++) {
    for(int y = 0; y < WIDTH; y++) {
        //printf("(%d, %d) = ", x, y);
        //std::cout<<fill[x][y]<<"\n";
        if(fill[x][y] == false) {
            dumpGrid();
            printf("%d\n", dfs(node(x,y)));
            dumpGrid();
        }
    }
}
}

int dfs(node start) {
static int run = 0;
std::stack<node> dfss;
node top;
int area  = 0;
dfss.push(start);

while(!dfss.empty()) {
top = dfss.top();
dfss.pop();
if(top.x < 0 || top.x >= WIDTH) {
    continue;
}
if(top.y < 0 || top.y >= HEIGHT) {
    continue;
}
if(fill[top.x][top.y]) {
    continue;
}
//printf("run = %d => (%d, %d) = %d\n", run, top.x, top.y, fill[top.x][top.y]);
fill[top.x][top.y] = true;
//else push the neighbors
area++;
dfss.push(node(top.x + 1, top.y));
dfss.push(node(top.x - 1, top.y));
dfss.push(node(top.x, top.y + 1));
dfss.push(node(top.x, top.y - 1));
}
run++;
return area;
}

int main() {
char * arr [] = {"0 3 5 4","2 6 4 7"};
sortedAreas(arr, 2);
return 0;
}
