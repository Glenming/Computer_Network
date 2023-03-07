#include"TreeNode.h"
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>

class Solition00 {
public:
	string serialize(TreeNode* root) {
		//法一：
		if (root == nullptr) return "# ";

		string ans = to_string(root->value)+' ';
		ans += serialize(root->left);
		ans += serialize(root->right);

		//法二：
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
		TreeNode* node = new TreeNode(stoi(temp));  //stoi 将字符串传化int数
		node->left = mydeserialize(ss);
		node->right = mydeserialize(ss);
		return node;
	}

	/*寻找重复子树*/   
	//将子树重复问题，转化为序列重复问题
	vector<TreeNode*> ans;            //结果集合
	unordered_map<string, TreeNode*> mp;    //子树集合
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		traverse(root);
		return { ans.begin(),ans.end() };
	}
	string traverse(TreeNode* root) {
		if (root == nullptr) return "#";
		string subtree = to_string(root->value) + ' ' + traverse(root->left) + ' ' + traverse(root->right);

		//法一
		auto it = mp.find(subtree);
		if (it != mp.end())       //此时集合中已经存在该子树了，重复子树放入结果中
			ans.emplace_back(root);
		else
			mp[subtree] = root;

		//法二
		/*if (mp[subtree] == 1) ans.emplace_back(root);
		++mp[subtree];*/

		return subtree;
	}



};
