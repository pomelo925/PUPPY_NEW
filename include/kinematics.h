#ifndef _KINEMATICS_H_
#define _KINEMEAICS_H_

#include <vector>

//return the value in degree
inline double Cos(double angle);
inline double Sin(double angle);

namespace KINE{
  /**
   * assign Ix, Iy, Iz corresponding to given initial Q 
   */
  void get_init(void);

  /**
   * @brief FORWARD kinemetics
   * @param xyz is relative to its Q1
   * @note this contains tranformation and movement
   *       only used in get_init()
   */
  void Q2pos(double Q1, double Q2, double Q3);
  
  /**
   * @brief BACKWARD kinemetics
   * @param xyz is relative to its Q1
   * @note this contains tranformation and movement
   */
  void pos2Q(int idx, double x, double y, double z);

  /**
   * @brief generate the homogeneous transformation by given parameters
   * @param DH_param the parameters matrix which arguments shall be in the order listed below
   */
  std::vector<std::vector<double>> generate_homo_matrix(std::vector<double> DH_param);

  /**
   * @brief the homogeneous transformation in Denavit_Hartenberg Convention
   * @param parent_frame is the XYZ position of the frame
   * @param homo_tf the 4x4 homogeneuous transformation matrix
   * */
  std::vector<double> homo_transformation(std::vector<double> parent_frame, std::vector<std::vector<double>> homo_tf);

}


#endif