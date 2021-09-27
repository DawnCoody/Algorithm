#include<iostream>

using namespace std;

void Divinteger(int, int);
int main() {
	int n;
	cin >> n;
	if (n < 1)	printf("输入参数错误，必须大于等于1");
	printf("有 %d 种整数划分",Divinteger(n, n));
	
	return 0;
}

// 使用递归方式将整数划分 n 表示要划分的整数，m 表示划分后整数中最大的数
int Divinteger(int n, int m) {	
	if (n == 1 || m == 1) return 1;		// 如果 n or m 等于 1 只有一种划分方式
	else if (n < m) return Divinteger(n, n);	// 如果 n < m 如：6 < 8， 显然把 6 划分后最大整数只有 6
	else if (n == m ) return (1 + Divinteger(n, n - 1));	// 将大问题划分为小问题
	else return (Divinteger(n, m - 1) + Divinteger(n -m, m));	// 将大问题划分为小问题
}