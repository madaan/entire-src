//sg
#include "suffix_tree.h"
int main()
{
    SuffixTree s("abcab$");
    s.print_stree(s.parent);
    printf("search(z) = %d\n", s.search_stree("a"));
    return 0;
}

