#include <iostream>
#include "Eigen/Dense"

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
 
int main(void){
  MatrixXd A = MatrixXd::Random(3, 3);
  MatrixXd B = MatrixXd::Constant(3, 3, 1.2);
  A = (A + B) * 5;
  cout << "A =" << endl << A << endl;

  VectorXd v(3);
  v << 1, 2, 3;
  cout << "A * v =" << endl << A * v << endl;

  double vAv = v.transpose() * A * v;
  cout << "v' * A * v = " << vAv << endl;

  VectorXd x = A.lu().solve(v);
  cout << "residual = " << (A * x - v).norm();
  cout << endl;
}
