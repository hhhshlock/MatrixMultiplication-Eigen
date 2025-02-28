#include <iostream>
#include <cmath>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

// 计算平面杆单元的全局刚度矩阵
Matrix4d computeTrussStiffness(
    const Vector2d& node_i,  // 节点i坐标 [x, y]
    const Vector2d& node_j,  // 节点j坐标 [x, y]
    double E,                // 弹性模量
    double A                  // 截面积
) {
    // 计算杆件几何参数
    Vector2d delta = node_j - node_i;
    double L = delta.norm();  // 杆长

    if (L <= 1e-12) {
        cerr << "错误：节点重合！" << endl;
        return Matrix4d::Zero();
    }

    double cos_theta = delta.x() / L;  // 方向余弦
    double sin_theta = delta.y() / L;

    // 局部坐标系刚度矩阵（4x4）
    Matrix4d Klocal = Matrix4d::Zero();
    double k = E * A / L;
    Klocal << k, 0, -k, 0,
        0, 0, 0, 0,
        -k, 0, k, 0,
        0, 0, 0, 0;

    // 坐标变换矩阵（4x4）
    Matrix4d T = Matrix4d::Zero();
    T << cos_theta, sin_theta, 0, 0,
        -sin_theta, cos_theta, 0, 0,
        0, 0, cos_theta, sin_theta,
        0, 0, -sin_theta, cos_theta;

    // 全局坐标系刚度矩阵
    return T.transpose() * Klocal * T;
}

// 示例用法
int main() {
    // 定义两个节点坐标
    Vector2d n1(0.0, 0.0);   // 节点1 (x, y)
    Vector2d n2(3.0, 4.0);   // 节点2 (x, y)

    // 材料参数
    double E = 200e9;  // 钢的弹性模量 (Pa)
    double A = 0.01;    // 截面积 (m²)

    // 计算全局刚度矩阵
    Matrix4d K_global = computeTrussStiffness(n1, n2, E, A);

    // 输出结果
    cout << "全局坐标系下的杆单元刚度矩阵 (4x4):\n"
        << K_global << endl;

    // 验证特性
    cout << "\n矩阵特性验证:"
        << "\n对称性误差: " << (K_global - K_global.transpose()).norm()
        << "\n行列式值: " << K_global.determinant()
        << endl;

    return 0;
}