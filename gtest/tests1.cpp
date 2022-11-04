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

TEST(PostCheckPoint, RotationCheck1)
{
	MyAVLTree<char, char> tree;
	tree.insert('a', 'a');
	tree.insert('b', 'b');
	tree.insert('c', 'c');
	tree.insert('d', 'd');
	tree.insert('e', 'e');
	tree.insert('f', 'f');
		
	std::vector<char> trav = tree.postOrder();
	std::vector<char> expected = {'a','c','b','f','e','d'};
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, RotationCheck2)
{
	MyAVLTree<int, int> tree;
	for(int i = 1; i < 11; ++i)
	{
		tree.insert(i,i);
	}
	std::vector<int> trav = tree.postOrder();
	std::vector<int> expected1 = {1,3,2,5,7,6,9,10,8,4};
	EXPECT_TRUE( trav == expected1 );
	
	trav = tree.inOrder();
	std::vector<int> expected2 = {1,2,3,4,5,6,7,8,9,10};
	EXPECT_TRUE( trav == expected2 );
	
	trav = tree.preOrder();
	std::vector<int> expected3 = {4,2,1,3,8,6,5,7,9,10};
	EXPECT_TRUE( trav == expected3 );
}

TEST(PostCheckPoint, RotationCheck3)
{
	MyAVLTree<int, int> tree;
	std::vector<int> expected;
	for(int i = -9999; i <= 9999; ++i)
	{
		tree.insert(i,i);
		expected.push_back(i);
	}
	std::vector<int> trav = tree.inOrder();
	EXPECT_TRUE( trav == expected );
}
	
TEST(PostCheckPoint, RotationCheck4)
{
	MyAVLTree<int, int> tree;
	std::vector<int> expected;
	for(int i = 9999; i >= -9999; --i)
	{
		tree.insert(i,i);
		expected.push_back(i);
	}
	std::vector<int> trav = tree.inOrder();
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, RotationCheck5)
{
	MyAVLTree<char, char> tree;
	std::vector<char> expected;
	for(char i = '!'; i <= '~'; ++i)
	{
		tree.insert(i,i);
		expected.push_back(i);
	}
	std::vector<char> trav = tree.inOrder();
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, RotationCheck6)
{
	MyAVLTree<double, double> tree;
	std::vector<double> expected;
	for(double i = 1; i < 9999; i=(i*3.14)/2)
	{
		tree.insert(i, i);
		expected.push_back(i);
	}
	std::vector<double> trav = tree.inOrder();
	EXPECT_TRUE( trav == expected );
	}
}

TEST(PostCheckPoint, RotationCheck7)
{
	MyAVLTree<std::string, std::string> tree;
	tree.insert("aaaaaa", "aaaaaa");
	tree.insert("bbbbbb", "bbbbbb");
	tree.insert("cccccc", "cccccc");
	tree.insert("dddddd", "dddddd");
	tree.insert("eeeeee", "eeeeee");
	tree.insert("ffffff", "ffffff");
	tree.insert("gggggg", "gggggg");
	std::vector<std::string> expected = {"aaaaaa","bbbbbb","cccccc","dddddd","eeeeee","ffffff","gggggg"};
	std::vector<std::string> trav = tree.inOrder();
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, RuntimeErrorTest1)
{
	MyAVLTree<int, int> tree;
	EXPECT_THROW(tree.find(1), RuntimeException);
}

TEST(PostCheckPoint, RuntimeErrorTest2)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");
	EXPECT_THROW(tree.find(1), RuntimeException);
}

TEST(PostCheckPoint, RuntimeErrorTest3)
{
	MyAVLTree<int, int> tree;
	EXPECT_FALSE(tree.isEmpty() == false);
}

TEST(PostCheckPoint, sizeCheck)
{
	MyAVLTree<int, int> tree;
	for(int i = 0; i < 10000; ++i)
	{
		tree.insert(i,i);
	}
	EXPECT_TRUE( tree.size() == 10000 );
}

}