#include <Eigen/Dense>
  #include <iostream>
  #include <cmath>

  // 固定轴 RPY（绕固定 X-Y-Z 依次转）→ 旋转矩阵
  Eigen::Matrix3d rpyToR(double roll, double pitch, double yaw) {
    Eigen::Matrix3d Rx, Ry, Rz;
    Rx << 1, 0, 0,  0, cos(roll), -sin(roll),  0, sin(roll), cos(roll);
    Ry << cos(pitch), 0, sin(pitch),  0, 1, 0,  -sin(pitch), 0, cos(pitch);
    Rz << cos(yaw), -sin(yaw), 0,  sin(yaw), cos(yaw), 0,  0, 0, 1;
    return Rz * Ry * Rx;
  }

  int main() {
    const double roll = 0.3, pitch = -0.5, yaw = 1.1;

    Eigen::Matrix3d R_hand = rpyToR(roll, pitch, yaw);

    Eigen::Matrix3d R_eigen =
        (Eigen::AngleAxisd(yaw,   Eigen::Vector3d::UnitZ()) *
         Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitY()) *
         Eigen::AngleAxisd(roll,  Eigen::Vector3d::UnitX())).toRotationMatrix();

    std::cout << "||R_hand - R_eigen|| = " << (R_hand - R_eigen).norm() << "\n";
    std::cout << "det = " << R_hand.determinant() << "\n";
    std::cout << "||R^T R - I|| = "
              << (R_hand.transpose() * R_hand - Eigen::Matrix3d::Identity()).norm() << "\n";
  }
