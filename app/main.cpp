#include <fstream>
#include <iostream>


#include "MyAVLTree.hpp"

int main()
{

    MyAVLTree<int, std::string> tree;
//	tree.insert(20, "foo");
//	tree.insert(15, "sna");
//	tree.insert(25, "bar");
//	tree.insert(10, "twelve");
//	tree.insert(16, "twelve");
//	tree.insert(5, "fifteen");
//  tree.insert(111, "foo");
//  tree.insert(112, "sna");
//	tree.insert(100, "twelve");
//	tree.insert(110, "twelve");
	//tree.insert(50, "fifteen");


    //this is right-right test case
//  tree.insert(15, "foo");
//  tree.insert(25, "foo");
//  tree.insert(35, "foo");

    //this is left-left test case
//  tree.insert(15, "foo");
//  tree.insert(10, "foo");
//  tree.insert(5, "foo");

    //this is left-right test case
//  tree.insert(15, "foo");
//  tree.insert(25, "foo");
//  tree.insert(10, "foo");
//  tree.insert(5, "foo");
//  tree.insert(12, "foo");
//  tree.insert(11, "foo");

    //this is right-left test case
    tree.insert(15, "foo");
    tree.insert(25, "foo");
    tree.insert(10, "foo");
    tree.insert(35, "foo");
    tree.insert(20, "foo");
    tree.insert(19, "foo");
    tree.insert(45, "foo");

    std::vector<int> result = tree.inOrder();
    std::cout<<"inorder"<<std::endl;
    for (auto &&i : result)
    {
        std::cout<<i<<std::endl;
    }
    result = tree.postOrder();
    std::cout<<"post"<<std::endl;
    for (auto &&i : result)
    {
        std::cout<<i<<std::endl;
    }
    result = tree.preOrder();
    std::cout<<"pre"<<std::endl;
    for (auto &&i : result)
    {
        std::cout<<i<<std::endl;
    }
    

    return 0;
}