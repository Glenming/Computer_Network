#pragma once
#include<iostream>
using namespace std;
struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode():value(0),left(nullptr),right(nullptr){ }
	TreeNode(int x):value(x), left(nullptr), right(nullptr) { }
	TreeNode(int x,TreeNode* left,TreeNode* right):value(x),left(left),right(right){ }
};