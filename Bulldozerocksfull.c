#include <kipr/wombat.h>
// Title:   Bulldozing_Rock_Working Running
// Files:   main.c
// Semester:   Rancho Botball Spring 2024

// Author:   Neel Arora, Nimish Nijhawan 
// Email:    na92085@student.musd.org, nn102597@student.musd.org
// Coach:     Mr. Tran




// First we create function called onewheelturnleft this a function we create
//so that the wombat stops one wheel and turns left because
// the left function would cause the wombat to hit the pvc pipe and ruin our code
void onewheelturnleft(){
    // We are using mav to move forward in one direction and stay still in the other direction for a certain distance with an msleep function so that it turns
    mav(0,950);
    mav(3,0);
    msleep(2500);
}
// We create the same thing as above but instead made it turnright because of the same problem, which is it breaks the code and turns wrong and hits pvx pipes
void onewheelturnright(){
    // We are using the mav function to make move forward in one direction and stay still in the other direction, for a certian amount of time
    mav(0,0);
    mav(3,950);
    msleep(2500);
}
// Then we have our square up code so that it can correct itself using the color sensors so that it straightens up
void squareup_working(){
    // We have a grey value which is the average of white value and black so that we can tell that when it is greater then the value it is on black and when it is lower then the value it is on right
    int grey = (3500+3900)/2;
    int right = 4; // The sensor on the right
    int left = 5; // sensors on left 
    int mright = 0; // right motor
    int mleft = 3; // left motor
    while (analog(4)<grey || analog(5)<grey){ // makes robot move until it reaches the black line.
        if (analog(right)<grey){ // if right sensor is not on the balck line we want it to move forward
            mav(mright, 500);
        }else{
            mav(mright,-250); //when it is on the line we want it to turn so that the other one can come in the line to.
        }
        if (analog(left)<grey){ // if left sensor is not on  line it moves forward
            mav(mleft,500);
        }else{
            mav(mleft,-250); // if left sensor is on the black line we want it to turn
        }
        msleep(1);     // wait a millisecond before looping again

    }
    mav(mleft,0);           //to lock motors
    mav(mright,0);
    msleep(5);        
}
// then we have a drive function, we have it because it makes reaching a certian distance more exact, we have the two parameters needed like distance we want it to go and speed at we want it to go at.
void drive(int distance,int speed){
    // We first clear the motor position so it is 0 so that it does not give false readings
    clear_motor_position_counter (0);
    clear_motor_position_counter (3); 
    // then we are checking if the absoulte value of the motor position is less then distance then we want it to move forward.
    while (abs(gmpc(0)) < distance || abs(gmpc(3)) < distance){
        mav(0,speed);
        mav(3,speed);
        msleep(1);
    }
    // else it will break out of the function.
}
// Then we have a right function, we are working on making it use parameters, but for now we have this amount of turn.
void right(){
    // it is going at a specific speed and is going to wait for a specific amount of time, to get the perfect turn
    mav(3,950);
    mav(0,-950);
    msleep(1250);
}
// Then we have a left function which is simmilar to the right function, everything is the same except it turns left instead of right
void left(){
    mav(0,950);
    mav(3,-950);
    msleep(1250);
}
// Then we have the is black function, we are working in incorparating more parameters in so that it is more easier to use but right now the main idea is that it first checks if the analog number is greater then the white value, if it it returns 1, else it will return 0 because it is on white.
int isblack(int pint){
    if (analog(pint) > 3700){

        return 1;
    }else{

        return 0;
    }
}
// Now we have our line follow code, which is neccesary for the run. We created three parameters to ask how far we want it to go, how fast we want to go, and how drastice of a turn do we want to take.
void line_follow(int distance, int speed, int subtraction){
    // It first clears the motor position so that it gives us a correct reading
    clear_motor_position_counter (0);
    clear_motor_position_counter (3);
    // then we state that if the right motor is not equal to the distance we want it to use the isblack function.
    while(gmpc(3)<distance){
        // The way the isblack function helps is it first need a parameter call pint to see what port we arch checking then we look at the return values, so like for an example if it returns 0 it is on white and we want it to move forward.
        if(isblack(4) == 0 && isblack(5) == 0){
            // The speed we want it to move forward is the parameter speed and will be defined below
            mav(0,speed);
            mav(3,speed);
        }// If it is equal to one whcih means it is on black we want the motor that is not on black to move forward and the motor that is on black to backward so that we get a turn and the other can get in the black line
        if(isblack(4) == 0 && isblack(5) == 1){
            mav(0,speed); // Again we are going at speed
            mav(3,speed-subtraction);// Then we are subtracting a speed, with a number that is defined when we call the function
        }
        // Simmilar here except now the other on is black so the left motor has to move forward
        if(isblack(4) == 1 && isblack(5) == 0){
            mav(0,speed-subtraction);
            mav(3,speed);
        }

        msleep(1); // Now we are waiting a millisecond everytime it runs the loop.
    }
}
// Since we do not have parameters in the right function yet we created a new one called extra right so that we can turn right much longer then the other one
void extra_right(){
    mav(0,-950);// the right motor is going negative so that it turns right
    mav(3,950);// the left motor is going positive so that it can turn right
    msleep(1550);// this is how long we want it to turn
}
// Simmilar here except it is a smaller right so that we can turn a small right
void small_right(){
    mav(0,-950);// same thing in order turntright the right motor is going backwards
    mav(3,950);// and the left sensor is going forward which causes the turn
    msleep(850);
}
void small_left(){
    mav(0,950);
    mav(3,-950);
    msleep(850);
}
int main()
{

    onewheelturnleft(); // first we turn left in the small rover bay
    drive(1000,-950);// then we square up by ramming into the pvc pipe behind us
    drive(2000,950); // then we move forward for 2000 ticks at a speed of 950
    right(); // then we turn right
    squareup_working();// then we square up so that it is straight
    drive(2500,950);// we move forward for a little distance to get out of the small rover bay area
    right();// then we turn right and go toward the poms
    squareup_working(); // then we square up to get straight
    drive(3400,950);// then we push the poms with the robot into area three
    drive(5000,-950);// then we go back a little bit
    left();
    drive(1500,500);
    right();
    squareup_working();
    drive(3500,950);// we push the poms into area 3
    drive(5000,-950); // then we move back
    squareup_working(); // we square up and get straight
    onewheelturnleft();// then we turn left
    drive(1750,950);// then we move forward for a little bit and pick up the rock in the intersection
    left();// we turn left
    line_follow(1800,500,400);// we line follow and pick up the other rock in the other intersection
    small_right();// we do a small right turn so that it can get on the line near the rock bay
    line_follow(8000,950,400);// then we line follow and pick up the orange poms and the rock at the end
    left();// we push all of and turn left
    drive(1000,500);// we move forward drop it in rock bay
    drive(3000,-500);// and then we move back and the wombat stops running
    left();
    drive(3000,-950);
    drive(2500,950);
    left();
    squareup_working();
    drive(500,500);
    right();
    line_follow(8000,950,300);
    drive(2000,-950);








}

