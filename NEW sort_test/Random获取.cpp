#include"myhead.h"
#include<random>
#include<time.h>

class Random {
public:
	/*α���������*/
	void randnum1() {
		cout << "����Ϊ�������" << endl;
		for (int i = 0; i < 20; ++i) {
			int a = rand() % 100;    //����0~99�����
			cout << a << " ";
		}
		cout << endl;
	}

	/*�������*/
	void randnum2() {
		cout << "�������������" << endl;
		srand((unsigned)time(NULL));   //���������
		for (int i = 0; i < 20; ++i) {
			int a = rand() % 100;    //����0~99�����
			cout << a << " ";
		}
		cout << endl;
	}

	/*random_device�������*/
	void randnum3() {
		cout << "����Ϊ�������" << endl;
		random_device rd;
		for (int i = 0; i < 20; ++i) {
			int a = rd() % 100;    //����0~99�����
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