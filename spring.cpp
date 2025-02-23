#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
//直接刚度法（叠加法）来计算一维弹簧的刚度矩阵


//一维弹簧单元刚度矩阵生成函数
Matrix2d springStiffnessMatrix(double k) {
	Matrix2d ke;
	ke << k, -k,
		-k, k;
	return ke;
}
int main() {
	double k;
	cout << "输入弹簧的刚度系数（N/m）";
	cin >> k;
	Matrix2d ke = springStiffnessMatrix(k);
	cout << "一维弹簧单元刚度矩阵（2×2）：\n" << ke << endl;
	cout << "\n矩阵特征验证：" << "\n行列式值：" << ke.determinant() << "\n迹：" << ke.trace() << endl;
}