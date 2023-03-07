#include"myhead.h"
#include<sstream>

class solution {

public:
	/*01 反转字符串*/
	string reverseWords(string s) {
		//法1：利用输入输出流运算
		/*stringstream sst(s);
		string ans = "", temp;
		while (sst >> temp) {
			ans = temp + " " + ans;
		}
		ans.pop_back();
		return ans;*/

		//法2：利用双指针
		reverse(s.begin(), s.end());
		int index = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != ' ') {
				int j = i;
				if (index != 0) s[index++] = ' ';
				while (j < s.size() && s[j] != ' ') 
					s[index++] = s[j++];
				reverse(s.begin() + index - j + i, s.begin() + index);
				i = j;
			}
		}
		s.erase(s.begin() + index, s.end());
		return s;
	}
};

//int main() {
//	solution s1;
//	string str = "the sky is blue";
//	cout << s1.reverseWords(str) << endl;
//
//	cout << endl;
//	system("pause");
//	return 0;
//}