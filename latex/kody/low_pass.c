/*
 * @brief	This function should be called each \ref dt.
 * @param	input: Filter input.
 *
 * return	Filter output.
 */
float lowpass_Tick(lowpass_t* filter, float input)
{
	assert_param(filter);
	assert_param(filter->order);

	if (filter->order > MAX_ORDER_NR)
		filter->order = MAX_ORDER_NR;
	else if (filter->order < 1)
		filter->order = 1;

	uint32_t i;
	for (i = 0; i < filter->order; i++)
	{
		input = input * filter->a0 + 
			filter->prevOutput[i] * filter->b1;
		filter->prevOutput[i] = input;
	}

	return input;
}