#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    Tree tree1;
    tree1.add_word("first");
    tree1.add_word("second");
    tree1.add_word("third");
    tree1.add_word("first_a");
    tree1.add_word("first_a_b");
    tree1.add_word("fir_st");

    tree1.show_all();

    cout << "search \"first\"\t=\t"; tree1.search("first");
    cout << "search \"fir\"\t=\t"; tree1.search("fir");
    cout << "search \"third_\"\t=\t"; tree1.search("third_");
    cout << "search \"second\"\t=\t"; tree1.search("second");

    return 0;
}
