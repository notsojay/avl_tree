#include "gtest/gtest.h"
#include "MyAVLTree.hpp"
#include <string>
#include <sstream>
#include <vector>

namespace{


// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.

// The four tests marked "CheckPoint" are going to be run
// on your submission for the checkpoint code.
// This is worth one-fifth of your grade on the assignment
// and is due at the time marked "checkpoint"


// None of the "checkpoint" tests require you to have
// AVL functionality OR the counting of words.
// Implementing your tree as a plain binary search
// tree is more than enough to pass these tests.

// Of course, you are expected to implement AVL functionality
// for the full project.

// BE SURE TO FULLY TEST YOUR CODE.
// This means making sure your templating is not hard-coding for 
// a specific type, that every function is called somewhere in 
// your test cases, etc. 
//  If your code does not compile, your score will be a zero. 


TEST(CheckPoint, CheckPoint_FindTheRoot)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");

	EXPECT_TRUE( tree.contains(5) );
}

TEST(CheckPoint, CheckPoint_FindOneHop)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(10, "bar");

	EXPECT_TRUE( tree.contains(10) );
}

TEST(CheckPoint, CheckPoint_FindTwoHops)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");

	EXPECT_TRUE( tree.contains(12) );
}



TEST(CheckPoint, CheckPoint_Add5)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	EXPECT_TRUE( tree.size() == 5 );
}

TEST(CheckPoint, StringCheck)
{
	MyAVLTree<std::string, std::string> tree;
	tree.insert("c", "foo");
	tree.insert("b", "sna");
	tree.insert("a", "bar");
	tree.insert("e", "twelve");
	tree.insert("d", "fifteen");
		
	std::vector<std::string> trav = tree.inOrder();
	std::vector<std::string> expected = {"a", "b", "c", "d", "e"};
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, InOrderTraversal)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	std::vector<int> trav = tree.inOrder();
	std::vector<int> expected = {3, 5, 10, 12, 15};
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, PreOrderTraversal)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");
		
	std::vector<int> trav = tree.preOrder();
	std::vector<int> expected = {5, 3, 10, 12, 15};
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, PostOrderTraversal)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");
		
	std::vector<int> trav = tree.postOrder();
	std::vector<int> expected = {3, 15, 12, 10, 5};
	EXPECT_TRUE( trav == expected );
}

}