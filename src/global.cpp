#include <global.h>
#include <Arduino.h>
#include <string.h>
#include <constant.h>

namespace GLOB{
// initial EE(end effector) position
  double Ix, Iy, Iz;

// current EE(end effector) pos
  double RF_pos[3];
  double RH_pos[3];
  double LF_pos[3];
  double LH_pos[3];

// current Q(motor) pos
  double RF_Q[3];
  double RH_Q[3];
  double LF_Q[3];
  double LH_Q[3];

// DH param table
  std::vector<std::vector<double>> RF_param;
  std::vector<std::vector<double>> RH_param;
  std::vector<std::vector<double>> LF_param;
  std::vector<std::vector<double>> LH_param;
}

void GLOB::init(void){
  GLOB::update_Q_pos(init_Q1, init_Q2, init_Q3);
}

void GLOB::update_Ixyz(double Ix, double Iy, double Iz){
  GLOB::Ix = Ix;
  GLOB::Iy = Iy;
  GLOB::Iz = Iz;
  return;
}

void GLOB::update_Q_pos(GL index, double Q1, double Q2, double Q3){
  switch(index){
    case(GL::RF):
      GLOB::RF_Q[0]=Q1; GLOB::RF_Q[1]=Q2; GLOB::RF_Q[2]=Q3;
      break;

    case(GL::RH):
      GLOB::RH_Q[0]=Q1; GLOB::RH_Q[1]=Q2; GLOB::RH_Q[2]=Q3;
      break;

    case(GL::LF):
      GLOB::LF_Q[0]=Q1; GLOB::LF_Q[1]=Q2; GLOB::LF_Q[2]=Q3;
      break;

    case(GL::LH):
      GLOB::LH_Q[0]=Q1; GLOB::LH_Q[1]=Q2; GLOB::LH_Q[2]=Q3;
      break;
  }

  GLOB::update_DH_param();
}

void GLOB::update_EE_pos(GL index, double x, double y, double z){
  switch(index){
    case(GL::RF):
      GLOB::RF_pos[0]=x; GLOB::RF_pos[1]=y; GLOB::RF_pos[2]=z;
      break;

    case(GL::RH):
      GLOB::RH_pos[0]=x; GLOB::RH_pos[1]=y; GLOB::RH_pos[2]=z;
      break;

    case(GL::LF):
      GLOB::LF_pos[0]=x; GLOB::LF_pos[1]=y; GLOB::LF_pos[2]=z;
      break;

    case(GL::LH):
      GLOB::LH_pos[0]=x; GLOB::LH_pos[1]=y; GLOB::LH_pos[2]=z;
      break;
  }
}

void GLOB::update_Q_pos(double Q1, double Q2, double Q3){
  GLOB::RF_Q[0]=Q1; GLOB::RF_Q[1]=Q2; GLOB::RF_Q[2]=Q3;
  GLOB::RH_Q[0]=Q1; GLOB::RH_Q[1]=Q2; GLOB::RH_Q[2]=Q3;
  GLOB::LF_Q[0]=Q1; GLOB::LF_Q[1]=Q2; GLOB::LF_Q[2]=Q3;
  GLOB::LH_Q[0]=Q1; GLOB::LH_Q[1]=Q2; GLOB::LH_Q[2]=Q3;

  GLOB::update_DH_param();
}

void GLOB::update_EE_pos(double x, double y, double z){
  GLOB::RF_pos[0]=x; GLOB::RF_pos[1]=y; GLOB::RF_pos[2]=z;
  GLOB::RH_pos[0]=x; GLOB::RH_pos[1]=y; GLOB::RH_pos[2]=z;
  GLOB::LF_pos[0]=x; GLOB::LF_pos[1]=y; GLOB::LF_pos[2]=z;
  GLOB::LH_pos[0]=x; GLOB::LH_pos[1]=y; GLOB::LH_pos[2]=z;
}


void GLOB::update_DH_param(void){

}

void GLOB::show_EE(void){
  Serial.println("=== EE INFO ===");
  Serial.println((String)"RF_EE: "+GLOB::RF_pos[0]+"\t"+GLOB::RF_pos[1]+"\t"+GLOB::RF_pos[2]+"\t");
  Serial.println((String)"RH_EE: "+GLOB::RH_pos[0]+"\t"+GLOB::RH_pos[1]+"\t"+GLOB::RH_pos[2]+"\t");
  Serial.println((String)"LF_EE: "+GLOB::LF_pos[0]+"\t"+GLOB::LF_pos[1]+"\t"+GLOB::LF_pos[2]+"\t");
  Serial.println((String)"LH_EE: "+GLOB::LH_pos[0]+"\t"+GLOB::LH_pos[1]+"\t"+GLOB::LH_pos[2]+"\t");
}

void GLOB::show_Q(void){
  Serial.println("=== Q INFO ===");
  Serial.println((String)"RF_Q: "+GLOB::RF_Q[0]+"\t"+GLOB::RF_Q[1]+"\t"+GLOB::RF_Q[2]+"\t");
  Serial.println((String)"RH_Q: "+GLOB::RH_Q[0]+"\t"+GLOB::RH_Q[1]+"\t"+GLOB::RH_Q[2]+"\t");
  Serial.println((String)"LF_Q: "+GLOB::LF_Q[0]+"\t"+GLOB::LF_Q[1]+"\t"+GLOB::LF_Q[2]+"\t");
  Serial.println((String)"LH_Q: "+GLOB::LH_Q[0]+"\t"+GLOB::LH_Q[1]+"\t"+GLOB::LH_Q[2]+"\t");
}

void GLOB::show_Ixyz(void){
  Serial.println("=== Ixyz INFO ===");
  Serial.println((String)"Ix: "+GLOB::Ix);
  Serial.println((String)"Iy: "+GLOB::Iy);
  Serial.println((String)"Iz: "+GLOB::Iz);
}