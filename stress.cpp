#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;
//函数处理求解三元一次方程
const double M_PI = 3.14149265358979323846;
vector<double> solveCubic(double I1, double I2, double I3) {
    vector<double> roots;
    const double epsilon = 1e-12;
    double a = -I1;
    double b = I2;
    double c = -I3;

    double p = b - a * a / 3.0;
    double q = c - a * b / 3.0 + 2 * pow(a, 3) / 27.0;
    double delta = pow(q / 2.0, 2) + pow(p / 3.0, 3);

    if (abs(delta) < epsilon) delta = 0;

    if (delta > epsilon) {
        // 一个实根，两个复根
        double sqrt_delta = sqrt(delta);
        double u = cbrt(-q / 2.0 + sqrt_delta);
        double v = cbrt(-q / 2.0 - sqrt_delta);
        roots.push_back(u + v - a / 3.0);
    }
    else if (delta < -epsilon) {
        // 三个不同实根（三角函数解）
        double theta = acos(-q / (2.0 * sqrt(-pow(p, 3) / 27.0)));
        double sqrt_term = 2.0 * sqrt(-p / 3.0);
        roots.push_back(sqrt_term * cos(theta / 3.0) - a / 3.0);
        roots.push_back(sqrt_term * cos((theta + 2 * M_PI) / 3.0) - a / 3.0);
        roots.push_back(sqrt_term * cos((theta + 4 * M_PI) / 3.0) - a / 3.0);
    }
    else {
        // delta=0，至少两个实根相同
        double u = cbrt(-q / 2.0);
        if (abs(u) < epsilon) { // 三重根
            roots.push_back(-a / 3.0);
        }
        else {
            roots.push_back(2 * u - a / 3.0);
            roots.push_back(-u - a / 3.0);
        }
    }

    // 去重（考虑浮点误差）
    sort(roots.begin(), roots.end());
    auto last = unique(roots.begin(), roots.end(), [epsilon](double x, double y) {
        return abs(x - y) < epsilon;
        });
    roots.erase(last, roots.end());

    return roots;
}

int main() {
    vector<vector<int>>matrix;
    int rows, cols;
    cout << "输入行数和列数(行和列数只能是相同的)：";
    cin >> rows >> cols;
    cout << "逐行输入元素：" << endl;
    for (int i = 0; i < rows; ++i) {
        vector<int>row;
        for (int j = 0; j < cols; ++j) {
            int val;
            cin >> val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }
    MatrixXi eigen_mat1(matrix.size(), matrix[0].size());
    for (int i = 0; i < eigen_mat1.rows(); ++i)
        for (int j = 0; j < eigen_mat1.cols(); ++j)
            eigen_mat1(i, j) = matrix[i][j];

    double I1, I2, I3;
    I1 = eigen_mat1.trace();
    I2 = eigen_mat1(0, 0) * eigen_mat1(1, 1) + eigen_mat1(1, 1) * eigen_mat1(2, 2) + eigen_mat1(2, 2) * eigen_mat1(0, 0) - eigen_mat1(0, 1) * eigen_mat1(0, 1) - eigen_mat1(0, 2) * eigen_mat1(0, 2) - eigen_mat1(2, 1) * eigen_mat1(2, 1);
    I3 = eigen_mat1.determinant();
    vector<double> roots = solveCubic(I1, I2, I3);

    if (roots.empty()) {
        cout << "无实根" << endl;
    }
    else {
        cout << " 主应力：";
        for (double root : roots) {
            cout << root << " ";
        }
        cout << endl;
    }

    return 0;
}