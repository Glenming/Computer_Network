#include"TreeNode.h"
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>

class Solition00 {
public:
	string serialize(TreeNode* root) {
		//��һ��
		if (root == nullptr) return "# ";

		string ans = to_string(root->value)+' ';
		ans += serialize(root->left);
		ans += serialize(root->right);

		//������
		/*if (root == nullptr) return "#";
		return to_string(root->value) + ' ' + serialize(root->left) + ' ' + serialize(root->right);*/
	}

	TreeNode* deserialize(string date) {
		stringstream ss(date);  
		return mydeserialize(ss);
	}

	TreeNode* mydeserialize(stringstream& ss) {
		string temp;
		ss >> temp;
		if (temp == "#")
			return nullptr;
		TreeNode* node = new TreeNode(stoi(temp));  //stoi ���ַ�������int��
		node->left = mydeserialize(ss);
		node->right = mydeserialize(ss);
		return node;
	}

	/*Ѱ���ظ�����*/   
	//�������ظ����⣬ת��Ϊ�����ظ�����
	vector<TreeNode*> ans;            //�������
	unordered_map<string, TreeNode*> mp;    //��������
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		traverse(root);
		return { ans.begin(),ans.end() };
	}
	string traverse(TreeNode* root) {
		if (root == nullptr) return "#";
		string subtree = to_string(root->value) + ' ' + traverse(root->left) + ' ' + traverse(root->right);

		//��һ
		auto it = mp.find(subtree);
		if (it != mp.end())       //��ʱ�������Ѿ����ڸ������ˣ��ظ�������������
			ans.emplace_back(root);
		else
			mp[subtree] = root;

		//����
		/*if (mp[subtree] == 1) ans.emplace_back(root);
		++mp[subtree];*/

		return subtree;
	}



};
