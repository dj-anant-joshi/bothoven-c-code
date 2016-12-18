#ifndef LINE_FOLLOWING_HEADER
#define LINE_FOLLOWING_HEADER 

#include "motor_movement.h"
#include "analog_to_digital.h"
	#ifndef BLACK_THRESHOLD
	#define BLACK_THRESHOLD 0x14
	#endif

char bot_is_on_node(){
	left = ADC_Conversion(3);
	right = ADC_Conversion(2);
	centre = ADC_Conversion(1);
	return (left > BLACK_THRESHOLD && right > BLACK_THRESHOLD && centre > BLACK_THRESHOLD);
}

char bot_is_on_line(){
	left = ADC_Conversion(3);
	right = ADC_Conversion(2);
	centre = ADC_Conversion(1);
	return (left < BLACK_THRESHOLD && centre > BLACK_THRESHOLD && right < BLACK_THRESHOLD);
}

char bot_is_veering_left(){
	left = ADC_Conversion(3);
	right = ADC_Conversion(2);
	centre = ADC_Conversion(1);
	return (left < BLACK_THRESHOLD && right > BLACK_THRESHOLD);
	//(experimental): centre intentionally not specified to improve responsiveness
}

char bot_is_veering_right(){
	left = ADC_Conversion(3);
	right = ADC_Conversion(2);
	centre = ADC_Conversion(1);
	return (left > BLACK_THRESHOLD && right < BLACK_THRESHOLD);
	//(experimental): centre intentionally not specified to improve responsiveness
}

void follow_black_line(){
	while(!bot_is_on_node()){
		if(bot_is_on_line()){
			forward();
			velocity(150,150);
		}else if(bot_is_veering_left()){
			forward()
			velocity(130,50);
		}else if(bot_is_veering_right()){
			forward();
			velocity(50,130);
		}
		_delay_ms(2);	
	}
	velocity(0,0);
}

#endif