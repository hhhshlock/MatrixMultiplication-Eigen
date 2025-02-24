//两个单元杠的组装
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

//函数生成单位刚度矩阵
Matrix2d barsStiffnessMatrix(double k) {
	Matrix2d ke;
	ke << k, -k,
		-k, k;
	return ke;
}
int main() {
	double k1, k2;
	MatrixXd ke = MatrixXd::Zero(3, 3);
	cout << "输入刚度系数(两个单元一维杠)";
	cin >> k1 >> k2;
	Matrix2d ke1 = barsStiffnessMatrix(k1);
	ke.block<2, 2>(0, 0) += ke1;
	Matrix2d ke2 = barsStiffnessMatrix(k2);
	ke.block<2, 2>(1, 1) += ke2;
	cout << "全局刚度矩阵（3×3）：\n" << ke << endl;
	return 0;
}