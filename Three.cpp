#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
MatrixXd Three_dimensional(const Vector3d& node_1, const Vector3d& node_2, double A, double E){
	Vector3d node_V = node_2 - node_1;
	double L = node_V.norm();//杠长
	if (L <= 1e-12) {
		cerr << "错误：节点重合！" << endl;
		return MatrixXd::Zero(6, 6);
	}
	if (A <= 0 || E <= 0) {
		cerr << "错误：面积或弹性模量非正！返回 6x6 零矩阵" << endl;
		return MatrixXd::Zero(6, 6);
	}
	double Cx = node_V.x() / L;
	double Cy = node_V.y() / L;
	double Cz = node_V.z() / L;
	MatrixXd T_t(6, 2);
	T_t << Cx, 0,
		Cy, 0,
		Cz, 0,
		0, Cx,
		0, Cy,
		0, Cz;
	Matrix2d K;
	K << 1, -1,
		-1, 1;
	MatrixXd K_theta(6, 6);
	K_theta = T_t * K * T_t.transpose();
	double k = (A * E) / L;
	return k * K_theta;
}
int main() {
	Vector3d node_one (0.0, 0.0, 0.0);
	Vector3d node_tow(3.0, 4.0, 5.0);
	double A = 100; 
	double E = 200e9; //弹性模量
	MatrixXd Ei(6, 6);
	Ei = Three_dimensional(node_one, node_tow, A, E);
	if (Ei.rows() != 6 || Ei.cols() != 6) {
		cerr << "错误：返回矩阵维度应为 6x6，实际为 "
			<< Ei.rows() << "x" << Ei.cols() << endl;
		return 1;
	}
	cout << "任意方向的刚度矩阵为：\n" << Ei << endl;
	return 0;
}