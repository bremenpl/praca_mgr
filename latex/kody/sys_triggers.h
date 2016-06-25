/*
 * @brief	enum representing possible triggers occuring in the driver
 */
typedef enum
{
	e_sysTrig_None				= 0,
	e_sysTrig_EXTI				= 1,
	e_sysTrig_PosError			= 2,
	e_sysTrig_DistReached			= 3,
	e_sysTrig_Go				= 4,
	e_sysTrig_Delay_ms			= 5,
	e_sysTrig_SetPwm1			= 6,
	e_sysTrig_SetPwm2			= 7,
	e_sysTrig_CompAdc1			= 8,
	e_sysTrig_CompAdc2			= 9,
} sysTrigg_t;