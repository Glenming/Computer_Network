#include"TreeNode.h"
#include<vector>
#include<unordered_map>


class Solution {
public:
	/*01 前序遍历构造二叉树*/
	TreeNode* bfsFromPreorder(vector<int>& preorder) {
		TreeNode* root = nullptr;
		for (int i = 0; i < preorder.size(); ++i) {
			createTree(root, preorder[i]);
		}
		return root;
	}
	void createTree(TreeNode* root, int val) {
		if (root == nullptr) {
			root = new TreeNode(val);
			return;
		}
		if (root->value > val) {
			createTree(root->left, val);
		}
		else {
			createTree(root->right, val);
		}
	}

	/*02 构造最大二叉树*/
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return traverse(nums, 0, nums.size() - 1);
	}
	TreeNode* traverse(vector<int>& nums, int low, int hight) {
		//01 找终止条件 low<hight 返回nullptr
		if (low > hight) return nullptr;

		//02 每一级递归 返回构造好的最大二叉树root节点
		//03 每次递归，找到[lo,hig]内的最大值，然后将数组划分为[lo,bond-1]和[bound+1,high] 然后分别构造最大二叉树
		int max_num = INT_MIN;
		int index = -1;
		for (int i = low; i <= hight; ++i) {
			if (max_num < nums[i]) {
				max_num = nums[i];
				index = i;     //记录当前最大值索引
			}
		}
		TreeNode* root = new TreeNode(max_num);    //构造二叉树根节点

		root->left = traverse(nums, low, index - 1);
		root->right = traverse(nums, index + 1, hight);
		return root;
	}

	/*
	使用分解问题思路：
		构造整棵树 = 根节点 + 构造左子树 + 构造右子树
	*/
	/*03 先序遍历和中序遍历构造二叉树*/
	TreeNode* buildtree(vector<int>& preorder, vector<int>& inorder) {
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* build(vector<int>& preorder, int pre_low, int pre_high ,vector<int>& inorder,int in_low,int in_high) {
		if (pre_low > pre_high) return nullptr;

		int root_val = preorder[pre_low];                 //根节点的值
		int index = 0;                                    //中序遍历根节点值的索引
		for (int i = in_low; i <= in_high; ++i) {
			if (inorder[i] == root_val)
				index = i;
		}
		int left_size = index - in_low;

		TreeNode* root = new TreeNode(root_val);           //创建根节点+左子树+右子树
		root->left = build(preorder, pre_low + 1, pre_low + left_size, inorder, in_low, index - 1);
		root->right = build(preorder, pre_low + left_size + 1, pre_high, inorder, index + 1, in_high);
		return root;
	}

	/*04 后序遍历和中序遍历构造二叉树*/
	unordered_map<int, int> mp;
	TreeNode* buildtree2(vector<int>& postorder, vector<int>& inorder) {
		for (int i = 0; i < inorder.size(); ++i) {
			mp[inorder[i]] = i;
		}
		return build2(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* build2(vector<int>& postorder, int post_low, int post_high, vector<int>& inorder, int in_low, int in_high) {
		if (post_low > post_high) return nullptr;

		int root_val = postorder[post_high];
		int indxe = mp[root_val];
		int left_size = indxe - in_low;
		
		TreeNode* root = new TreeNode(root_val);
		root->left = build2(postorder, post_low, post_low + left_size - 1, inorder, in_low, indxe - 1);
		root->right = build2(postorder, post_low + left_size , post_high - 1, inorder, indxe + 1, in_high);
		return root;
	}

	/*05 先序遍历和后序遍历构造二叉树*/
	TreeNode* buildtree3(vector<int>& prevorder, vector<int>& postorder) {
		return build3(prevorder, 0, prevorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
	TreeNode* build3(vector<int>& prevorder, int prev_low, int prev_high, vector<int>& postorder, int post_low, int post_high) {
		if (prev_low > prev_high) return nullptr;
		if (prev_low == prev_high) return new TreeNode(prevorder[prev_low]);
		int root_val = prevorder[prev_low];

		//在后序遍历中寻找左子树的右边界 (即为后序遍历中左子树根节点的索引)
		int index = -1;
		for (int i = 0; i < post_high; ++i) {
			if (prevorder[prev_low + 1] == postorder[i])
				index = i;
		}
		int left_size = index - post_low + 1;
		TreeNode* root = new TreeNode(root_val);
		root->left = build3(prevorder, prev_low + 1, prev_low + left_size, postorder, post_low, index);
		root->right = build3(prevorder, prev_low + left_size + 1,prev_high , postorder, index+1, post_high - 1);
		return root;
	}

};