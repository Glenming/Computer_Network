#include"TreeNode.h"
#include<queue>
#include<vector>
class BFS {
public:
	/*最小二叉树深度*/
	int bfs_mindepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> que;
		que.emplace(root);
		int depth = 1;
		
		//while循环逐层遍历 for循环从左到右遍历二叉树
		while(!que.empty()){
			int sz = que.size();      //当前队列节点个数
			TreeNode* cur = que.front();
			que.pop();
			for (int i = 0; i < sz; ++i) {
				if (cur->left == nullptr && cur->right ==nullptr)
					return depth;
			    if (cur->left != nullptr)
					que.emplace(cur->left);
				if (cur->right != nullptr)
					que.emplace(cur->right);
			}
			++depth;
		}
		return depth;
	}

	/*最大二叉树深度*/
	int ans = 0;        //最大二叉树深度
	int depth = 0;      //当前二叉树深度
	void traverse(TreeNode* root) {
		if (root == nullptr) return;
		++depth;
		if (root->left == nullptr && root->right == nullptr) {
			ans = max(ans, depth);
		}
		traverse(root->left);
		traverse(root->right);
		--depth;
	}
	int bfs_maxdepth(TreeNode* root) {
		traverse(root);
		return ans;
	}
};

class DFS {
public:
	/*最小二叉树深度*/
	int dfs_mindepth(TreeNode* root) {
		if (root == nullptr) return 0;
		else if (root->left == nullptr) {
			return dfs_mindepth(root->right) + 1;
		}
		else if (root->right == nullptr) {
			return dfs_mindepth(root->left) + 1;
		}
		else return min(dfs_mindepth(root->left), dfs_mindepth(root->right)) + 1;;
	}

	/*最大二叉树深度*/
	int dfs_maxdepth(TreeNode* root) {
		if (root == nullptr) return 0;
		int left_depth = dfs_maxdepth(root->left);
		int right_depth = dfs_maxdepth(root->right);
		return max(left_depth, right_depth) + 1;
	}

	/*机器人运动范围*/
	int ans = 0;
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> board(m, vector<bool>(n, false));  //标记
		traverse3(board, m, n, 0, 0, k);
		return ans;
	}

	void traverse3(vector<vector<bool>>& board, int m, int n, int x, int y, int k) {
		if (x < 0 || x >= m || y < 0 || y >= n)
			return;
		if (x / 10 + x % 10 + y / 10 + y % 10 > k)
			return;

		if (board[x][y] == false) {
			board[x][y] = true;
			++ans;
			traverse3(board, m, n, x + 1, y, k);
			traverse3(board, m, n, x, y + 1, k);
		}
		return;
	}

	/*矩阵中的路径*/
	int index = 0;
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if(traverse4(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
	bool traverse4(vector<vector<char>>& board, string word, int i, int j, int index) {
		if (word.size() == index) return true;
		if (board[i][j] != word[index])
			return false;
		if (i<0 || i>board.size() || j<0 || j>board[0].size())
			return false;

		board[i][j] = '*';
		if (traverse4(board, word, i - 1, j, index + 1) ||
			traverse4(board, word, i + 1, j, index + 1) ||
			traverse4(board, word, i, j - 1, index + 1) ||
			traverse4(board, word, i, j + 1, index + 1))
			return true;

		else {
			board[i][j] = word[index];
			return false;
		}
	}
};

int main() {
	DFS res;
	cout << "运动范围：" << res.movingCount(2, 3, 1) << endl;

	return 0;
}