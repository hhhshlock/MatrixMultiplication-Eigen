#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

//函数生成在xy平面任意反向的显示刚度矩阵
Matrix4d Orientation_matrix(double ang) {
	double M_PI = 3.14159265358979323846;
	double angle = (ang / 180) * M_PI;
	Matrix4d T, k, count;
	T << cos(angle), sin(angle), 0, 0,
		-sin(angle), cos(angle), 0, 0,
		0, 0, cos(angle), sin(angle),
		0, 0, -sin(angle), cos(angle);
	Matrix4d Tt = T.transpose();
	k << 1, 0, -1, 0,
		0, 0, 0, 0,
		-1, 0, 1, 0,
		0, 0, 0, 0;
	count = Tt * k * T;
	return count;
}
int main() {
	double ang;
	cout << "输入以水平为x正轴逆时针转过的角度（ang）：";
	cin >> ang;
	Matrix4d direction = Orientation_matrix(ang);
	cout << "该角度的显示刚度矩阵为：\n" << direction << endl;
}