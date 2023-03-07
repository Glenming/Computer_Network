#include"TreeNode.h"
#include<vector>
#include<list>
#include<stack>
#include<queue>

class Sloution {
public:
	/*�������Ŀ��*/
	void traverse(TreeNode* root) {
		if (root == nullptr) return;
		//ǰ��λ��
		traverse(root->left);
		//����λ��
		traverse(root->right);
		//����λ��
	}

	/*ǰ�����*/
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

	//BFSʵ��ǰ�����(ջ+����)
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

	/*�������������*/
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

	/*�����������������������BFS*/
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