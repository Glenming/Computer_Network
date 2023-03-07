#include"TreeNode.h"
#include<vector>

class Solution {
public:
	/*01 二叉树与双向链表*/
	TreeNode* head = nullptr;
	TreeNode* prev = nullptr;
	TreeNode* treeToDoublyList(TreeNode* root) {
		if (root == nullptr) return nullptr;
		traverse(root);
		head->left= prev;
		prev->right = head;

		return head;
	}
	//遍历过程中，将当前节点指向上一个被遍历的节点，上一个节点指向自己
	void traverse(TreeNode* root) {
		if (root == nullptr)
			return;

		traverse(root->left);

		//head为空，head作为第一个节点
		if (head == nullptr) {
			head = root;
			prev = head;
		}
		else {
			prev->right = root;
			root->left = prev;
			prev = root;
		}
		traverse(root->right);
	}

	/*02 二叉搜索树和为某一个值*/
	//回溯+DFS
	vector<vector<int>> ans;
	vector<int> track;
	int sum = 0;
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		if (root == nullptr)
			return { };
		traverse2(root, target);
		return ans;
	}
	void traverse2(TreeNode* root, int target) {
		if (root == nullptr || sum > target)
			return;

		sum += root->value;
		track.emplace_back(root->value);

		if (sum == target && !root->left && !root->right) {
			ans.emplace_back(track);
		}	
		else {
			traverse2(root->left, target);
			traverse2(root->right, target);
		}
		sum -= root->value;
		track.pop_back();
	}
};