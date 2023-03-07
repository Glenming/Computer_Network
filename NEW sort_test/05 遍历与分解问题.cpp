#include"TreeNode.h"
#include<vector>
#include<queue>

class Solution {

public:
	/*
		01 通过分解问题，递归解决问题
	*/

	/*树的子结构*/
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr) return false;
		return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
	bool dfs(TreeNode* A, TreeNode* B) {
		if (B == nullptr) return true;     // B树最后可以为空时，A树不一定为空
		if (A == nullptr) return false;
		return A->value == B->value && dfs(A->left, B->left) && dfs(A->right, B->right);
	}

	/*对称二叉树*/
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;
		return dfs2(root->left, root->right);
	}
	bool dfs2(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr && t2 == nullptr) return true;
		if (t1 == nullptr || t2 == nullptr) return false;
		return t1->value == t2->value && dfs2(t1->left, t2->right) && dfs2(t1->right, t2->left);
	}

	/*
		02  BST(二叉搜索树) 
			中序遍历结果是有序的（升序）若先遍历右子树 在左子树就是降序
	*/

	/*寻找BST第k小的元素*/
	int ans = 0;
	int index = 0;
	int kthSmallest(TreeNode* root, int k) {
		traverse(root, k);
		return ans;
	}
	void traverse(TreeNode* root, int k) {
		if (root == nullptr) return;
		traverse(root->left,k);
		++index;
		if (index == k) {
			ans = root->value;
			return;
		}	
		traverse(root->right,k);
	}

	/*BST转化为累加树*/
	int sum = 0;
	TreeNode* convertBST(TreeNode* root) {
		traverse2(root);
		return root;
	}
	TreeNode* traverse2(TreeNode* root) {
		if (root == nullptr) return nullptr;
		traverse2(root->right);
		sum += root->value;     //从最大元素开始累加
		root->value = sum;		//给root节点赋累加后的值
		traverse2(root->left);
		return root;
	}

	/*
		03 BST的合法性、增、删、查找
	*/

	/*BST查找一个值*/
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr || root->value == val)
			return root;
		if (root->value < val)
			return searchBST(root->right, val);
		else
			return searchBST(root->left, val);
	}

	/*BST插入一个值*/
	TreeNode* insertBST(TreeNode* root, int val) {
		if (root == nullptr)
			return new TreeNode(val);
		if (root->value < val)
			root->right = insertBST(root->right, val);
		else
			root->left = insertBST(root->left, val);
		return root;
	}

	/*判断BST的合法性*/
	bool isValidBST(TreeNode* root) {
		return isvalid(root, nullptr, nullptr);
	}
	bool isvalid(TreeNode* root, TreeNode* min, TreeNode* max) {
		if (root == nullptr) return true;
		if (min != nullptr && root->value <= min->value) return false;
		if (max != nullptr && root->value >= max->value) return false;
		return isvalid(root->left, min, root) && isvalid(root->right, root, max);
	}


	/*vector<int> levelTraverse(TreeNode* root) {
		if (root == nullptr) return {};
		queue<TreeNode*> q;
		vector<int> ans;
		q.emplace(root);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			ans.emplace_back(cur->value);
			if (cur->left)
				q.emplace(cur->left);
			if (cur->right)
				q.emplace(cur->right);
		}
		return ans;
	}*/
};

//int main50() {
//	TreeNode* t1 = new TreeNode(3);
//	TreeNode* t2 = new TreeNode(9);
//	TreeNode* t3 = new TreeNode(20);
//	TreeNode* t4 = new TreeNode(15);
//	TreeNode* t5 = new TreeNode(7);
//
//	t1->left = t2;
//	t1->right = t3;
//	t2->left = t5;
//	t2->right = t4;
//
//	Solution* st = new Solution();
//	t1 = st->convertBST(t1);
//	vector<int> nums = st->levelTraverse(t1);
//
//	for (auto elem : nums) {
//		cout << elem << " ";
//	}
//	cout << endl;
//
//	return 0;
//}