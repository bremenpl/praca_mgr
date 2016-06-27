/*
 * @brief	Regulates the output position, 
 *		taking under consideration current pos and desired pos. 
 *		This function is universal for all type of motors.
 *
 * @param	motor: pointer to a motor structure.
 * @param	currentPos: Current position expressed as angle or position.
 * @param	desiredPos: Desired position expressed as angle or position.
 */
float pid_PosController(motor_t* motor, float currentPos, float desiredPos)
{
	assert_param(motor);

	float error = desiredPos - currentPos;
	motor->posPid.integral += (error * motor->posPid.dt);

	if (motor->posPid.integral >= motor->posPid.antiWindUp)
		motor->posPid.integral = motor->posPid.antiWindUp;
	else if (motor->posPid.integral < (motor->posPid.antiWindUp * -1))
		motor->posPid.integral = motor->posPid.antiWindUp * -1;

	float derivative = (error - motor->posPid.prevErr) / motor->posPid.dt;
	float output = 	motor->posPid.kp * error +
			motor->posPid.ki * motor->posPid.integral +
			motor->posPid.kd * derivative;

	motor->posPid.prevErr = error;
	return output;
}