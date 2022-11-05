#include <fstream>
#include <iostream>
#include <string>
#include "MyAVLTree.hpp"

int main()
{
    MyAVLTree<char, char> tree;
    tree.insert('a', 'a');
    tree.insert('b', 'b');
    tree.insert('c', 'c');
    tree.insert('d', 'd');
    tree.insert('e', 'e');
    tree.insert('f', 'f');
    std::vector<char> trav = tree.inOrder();
    for(auto &i : trav)
        std::cout << i << " ";
    return 0;
}

