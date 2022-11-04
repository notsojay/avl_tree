#include <fstream>
#include <iostream>
#include <string>
#include "MyAVLTree.hpp"

int main()
{
    MyAVLTree<std::string, std::string> tree;
    std::vector<std::string> vec;
    tree.insert("aaaaaa", "aaaaaa");
    tree.insert("bbbbbb", "bbbbbb");
    tree.insert("cccccc", "cccccc");
    vec = tree.inOrder();
    
    return 0;
}

