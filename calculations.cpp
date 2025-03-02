#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

Vector4d Stress_calculation_factor(double E, const Vector2d& node_1, const Vector2d& node_2) {
	Vector2d delta = node_2 - node_1;
	double L = delta.norm();  //计算杠长

	if (L <= 1e-12) {
		cerr << "错误：节点重合！" << endl;
		return Vector4d::Zero();
	}

	double cos_theta = delta.x() / L;
	double sin_theta = delta.y() / L;

	Vector4d c;
	c << -cos_theta, -sin_theta, cos_theta, sin_theta;
	double k = E / L;
	Vector4d C = k * c;
	return C;
}

int main() {
	Vector2d n1(0.0, 0.0);//节点1
	Vector2d n2(3.0, 4.0);//节点2
	double E = 200e9; //弹性模量
	Vector4d C_1 = Stress_calculation_factor(E, n1, n2);
	cout << "应力计算系数向量为：\n" << C_1 << endl;
	return 0;
}