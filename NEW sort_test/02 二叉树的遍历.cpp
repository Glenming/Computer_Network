#include"TreeNode.h"
#include<vector>
#include<list>
#include<stack>
#include<queue>

class Sloution {
public:
	/*二叉树的框架*/
	void traverse(TreeNode* root) {
		if (root == nullptr) return;
		//前序位置
		traverse(root->left);
		//中序位置
		traverse(root->right);
		//后序位置
	}

	/*前序遍历*/
	vector<int> ans;
	void pre_traverse(TreeNode* root) {
		if (root == nullptr) return;
		ans.emplace_back(root->value);
		pre_traverse(root->left);
		pre_traverse(root->right);
	}
	vector<int> preorder_Traverse(TreeNode* root) {
		pre_traverse(root);
		return ans;
	}

	//BFS实现前序遍历(栈+遍历)
	vector<int> preorder_Traverse01(TreeNode* root) {
		if (root == nullptr) return{ };
		vector<int> ans;
		stack<TreeNode*> sk;
		sk.emplace(root);
		while (!sk.empty()) {
			TreeNode* cur = sk.top();
			sk.pop();
			ans.emplace_back(cur->value);
			if (cur->right != nullptr) sk.emplace(cur->right);
			if (cur->left != nullptr) sk.emplace(cur->left);
		}
		return ans;
	}

	/*二叉树后序遍历*/
	vector<int> post_ans;
	vector<int> postorder_Traverse(TreeNode* root) {
		post_traverse(root);
		return post_ans;
	}
	void post_traverse(TreeNode* root) {
		if (root == nullptr) return;
		post_traverse(root->left);
		post_traverse(root->right);
		post_ans.emplace_back(root->value);
	}

	/*二叉树层序遍历——类似于BFS*/
	vector<int> levelTraverse(TreeNode* root) {
		if (root == nullptr) return {};
		queue<TreeNode*> q;
		vector<int> ans;
		q.emplace(root);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			ans.emplace_back(cur->value);
			if (cur->left ) 
				q.emplace(cur->left);
			if(cur->right)
				q.emplace(cur->right);
		}
		return ans;
	}
};