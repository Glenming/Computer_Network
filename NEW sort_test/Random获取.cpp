#include"myhead.h"
#include<random>
#include<time.h>

class Random {
public:
	/*伪随机数生成*/
	void randnum1() {
		cout << "我是为随机数！" << endl;
		for (int i = 0; i < 20; ++i) {
			int a = rand() % 100;    //生成0~99随机数
			cout << a << " ";
		}
		cout << endl;
	}

	/*真随机数*/
	void randnum2() {
		cout << "我是真随机数！" << endl;
		srand((unsigned)time(NULL));   //随机数种子
		for (int i = 0; i < 20; ++i) {
			int a = rand() % 100;    //生成0~99随机数
			cout << a << " ";
		}
		cout << endl;
	}

	/*random_device真随机数*/
	void randnum3() {
		cout << "我是为随机数！" << endl;
		random_device rd;
		for (int i = 0; i < 20; ++i) {
			int a = rd() % 100;    //生成0~99随机数
			cout << a << " ";
		}
		cout << endl;
	}
};

int main810() {

	Random s1;
	s1.randnum1();
	s1.randnum2();
	s1.randnum3();

	system("pause");
	return 0;
}