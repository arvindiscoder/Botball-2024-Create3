// Title:   Pick_Up_Object_Code
// Files:   main.c
// Semester:   Ranch Botball Spring 2024

// Author:   Neel Arora
// Email:    na92085@student.musd.org
// Coach:     Mr. Tran
#include <kipr/wombat.h>
// We then have a new void function called pick_up_object with parameters
// The parameters are speed which is how fast we want it to go, then we have a distance which is saying
// how close do we want the range finder to be before we close the claw, and servo_position is defined to write
// how high we want the arm to be before moving forward
void pick_up_object(int speed, int distance, int servo_position){
    // We are then moving are first arm, up then we are putting our second arm at servo_position, then we have
    // the claw that open all the way before it stops moving
    set_servo_position(0,2040);
    set_servo_position(1,servo_position);
    set_servo_position(3,100);
    // then we are checking analog(0) or the range finder to see how much farther it needs to go
    // before closing the claw
    while (analog(0) < distance){
        // then it is using the line_follow function as defined above, with the speed going at the parameter
        // speed, and it is moving forward at the parameter speed
        //line_follow(100,speed,650); 
        mav(0,speed);
        mav(3,speed);
    }
    // We are waiting a second before starting.
    msleep(1000);
    // Then we are also closing the claw.
    set_servo_position(3,2000);
    // We are waiting a second before moving the arm up
    msleep(1000);
    set_servo_position(1,0);
    msleep(1000);
}
// Then we have slow servo.
// With parameters that hav a port, then the position of the servo, and the speed we want it to go at.
void servo(int port, int position, float speed){
    // We are defining a function that is getting the servo_position so we can see how far it is before it finishes
	int servo_position = get_servo_position(port);
    // Then we are checking the servo position and if it is equal to the position we want it to go to
	while (servo_position != position){
        // then if the servo position is greater then we are subtracting one from the position.
		if(servo_position > position){
			servo_position -= 1;
		}
        // if it is less then the servo position then we are adding one
		if (servo_position < position){
			servo_position += 1;
		}
        // Then we are assing the port with servo_position 
        // and we are sleeping for a speed.
		set_servo_position(port, servo_position);
		msleep(speed);
	}
    // then we are waiting a little bit before running it again.
	msleep(50);
}
int main()
{
    enable_servos();
    int position = 1100;
    pick_up_object(750,2700,position);
    
}
