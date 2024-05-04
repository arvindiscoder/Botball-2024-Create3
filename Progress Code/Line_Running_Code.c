#include <kipr/wombat.h>
// Title:   Line Running
// Files:   main.c
// Semester:   Ranch Botball Spring 2024

// Author:   Neel Arora
// Email:    na92085@student.musd.org
// Coach:     Mr. Tran



// We are creating an int function with a parameter pint.
int isblack(int pint){
    // Then we are using pint which like 0 in motor(0,100); and we are checking if it black which is when it 
    // is greater then 3700 and then it will return 1.
    if (analog(pint) > 3700){
        return 1;
        // else if it is on white then it will return 0
    }else{
        return 0;
    }
}
void line_follow(int distance, int speed, int subtraction){
    // We are clearing the position counter so that we can go to an almost exact place.
    clear_motor_position_counter (0);
    clear_motor_position_counter (3);
    // Then we are getting the motor position counter to see if it is at distance yet, if it is not it goes in the
    // while loop
    while(gmpc(3)<distance){
        // We are using the isBlack function as definied above to check if it is on black or other color.
        // if it is on white it will move forward at a speed that will be given in the call of function.
        if(isblack(4) == 0 && isblack(5) == 0){
            mav(0,speed);
            mav(3,speed);
        }
        // 0 is right 3 is left motor
        // if it is on black then it will turn towards the black.
        if(isblack(4) == 0 && isblack(5) == 1){
            mav(0,speed);
            mav(3,speed-subtraction);
        }
        // If the other one is black then it will also turn toward the line.
         if(isblack(4) == 1 && isblack(5) == 0){
            mav(0,speed-subtraction);
            mav(3,speed);
        }
        // Then we are waiting one second
        
        msleep(1); 
    }
}
int main(){
    // makes three integers and gives them values
    int distance = 17000;
    int speed = 950;
    int subtraction = 400;
    //sets all of those values in the line_follow function that was set before.
    line_follow(distance, speed, subtraction);
}
