#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <vector>

enum class GL{
  RF,
  RH,
  LF,
  LH
};

namespace GLOB{
/**
  @brief EE(end effector) position as initialization
  @note vital as being the initial point of trajectory
  @note reference frame: Q1
  @note unit: cm
  @warning only changes iff initialization changes
**/
  extern double Ix, Iy, Iz;


/**
  @brief current EE(end effector) pos
  @note reference frame: Q1
  @note unit: cm
**/
  extern double RF_pos[3];
  extern double RH_pos[3];
  extern double LF_pos[3];
  extern double LH_pos[3];


/**
  @brief current Q(motor) angle
  @note reference frame: Q1
  @note unit: degree
**/
  extern double RF_Q[3];
  extern double RH_Q[3];
  extern double LF_Q[3];
  extern double LH_Q[3];


/** Denavit_hartenberg Convention Parameters 
  ** param in the vector listed below in order
  * @param theta the rotation about Z axis
  * @param alpha the rotation about X axis
  * @param d the displacement of two frmaes in Z direction
  * @param r the displacement of two frames in X-direction
  */
  extern std::vector<std::vector<double>> RF_param;
  extern std::vector<std::vector<double>> RH_param;
  extern std::vector<std::vector<double>> LF_param;
  extern std::vector<std::vector<double>> LH_param;


/*----------------------------------------------------------------*/
  void init(void);

  void update_Ixyz(double Ix, double Iy, double Iz);
  
  void update_Q_pos(GL index, double Q1, double Q2, double Q3);
  void update_Q_pos(double Q1, double Q2, double Q3);
  void update_EE_pos(GL index, double x, double y, double z);
  void update_EE_pos(double x, double y, double z);
  void update_DH_param(void);

  void show_Ixyz(void);
  void show_EE(void);
  void show_Q(void);
}

#endif