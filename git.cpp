#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main() {
	//两个矩阵的乘法
	//初始化两个矩阵
	Matrix3d A;
	A << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;
	Matrix3d B;
	B << 9, 8, 7,
		6, 5, 4,
		3, 2, 1;

	//计算矩阵乘积
	Matrix3d C = A * B;
	cout << "矩阵A：" << A << "\n\n";
	cout << "矩阵B:" << B << "\n\n";
	cout << "结果C:\n" << C << endl;
	return 0;

}