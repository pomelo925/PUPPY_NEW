#include <cassert>

#include <kinematics.h>
#include <pwm_server.h>
#include <constant.h>
#include <global.h>

inline double Cos(double angle){
  return cos(angle*PI/180);
}

inline double Sin(double angle){
  return sin(angle*PI/180);
}


void KINE::get_init(void){
  Q2pos(init_Q1, init_Q2, init_Q3);
}

void KINE::Q2pos(double Q1, double Q2, double Q3){
  // original coordination
  const double EE_x = (fabs(Q2) >= fabs(Q3))? L2*Sin(Q2) + L3*Sin(Q2-Q3) : L2*Sin(Q2) - L3*sin(Q3-Q2);
  const double EE_y = -(L2*Cos(Q2) + L3*Cos(Q2-Q3));
  const double EE_z = L1*Cos(Q1);

  // update global
  GLOB::update_Ixyz(EE_x, EE_y, EE_z);
  GLOB::update_EE_pos(EE_x, EE_y, EE_z);
}

std::vector<std::vector<double>> KINE::generate_homo_matrix(std::vector<double> DH_param){
  if(DH_param.size()!=4) Serial.println("== ERROR: Invalid Parameters Matrix!");

  const double the = DH_param[0], alp = DH_param[1];
  const double d = DH_param[2], r = DH_param[3];

  const std::vector<std::vector<double>> homo{
    {Cos(the) , -Sin(the)*Cos(alp) , sin(the)*sin(alp)  , r*cos(the)},
    {sin(the) , cos(the)*cos(alp)  , -cos(the)*sin(alp) , r*sin(the)},
    {0        , sin(alp)           , cos(alp)           , d         },
    {0        , 0                  , 0                  , 1         }
  };

  return homo;
}

// std::vector<double> KINE::homo_transformation(std::vector<double> parent_frame, std::vector<std::vector<double>> homo_tf){
//   // if (parent_frame.size() != 3) Serial.println("== ERROR : Invalid parent frame position ==");
//   // if (homo_tf.size() != 4) Serial.println("== ERROR : Invalid params matrix ==");
  
//   // const std::vector<double> parent{
//   //   parent_frame[0], parent_frame[1], parent_frame[2], 1
//   // };

//   // return KINE::multiply(homo_tf, parent);
// }