#include "PID.h"
#include <iostream>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */

	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;

	p_error = 0;
	i_error = 0;
	d_error = 0;



	std::cout << "Kp : " << Kp << "\t";
	std::cout << "Ki : " << Ki << "\t";
	std::cout << "Kd : " << Kd << std::endl;


}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
	
	if (cte != p_error) {
	
		d_error = cte - p_error;

	}

	p_error = cte;
	i_error = cte + i_error;

	if (i_error > 100.0) {
		
		i_error = 100.0;
	
	}
	else if (i_error < -100.0) {
	
		i_error = -100.0;
	
	}
	
	
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */

	/*std::cout << "p_error : " << -p_error * Kp << "\t";
	std::cout << "i_error : " << -i_error * Ki << "\t";
	std::cout << "d_error : " << -d_error * Kd << std::endl;*/

  return -p_error * Kp - i_error * Ki - d_error * Kd;  // TODO: Add your total error calc here!
}