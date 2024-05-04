//    Title:                Main code
//    Files:                main.c
//    Semester:           	Rancho Botball Spring 2024
//
//    Author:               Arvind Sainathan
//    Pair Partner(s)   	Krishnaa Rajesh
//    Email:               	as91657@student.musd.org
//    Coach:                Mr. Tran
//    Credits:              Mr. Tim, Neel Arora, Nimish Nijawan
//
//


#include <kipr/wombat.h>

void black_line(){
    create3_connect(); 
    double velocity = 0.15;//sets the velocity
    while (velocity != 0){
        if (create3_sensor_cliff(2)<2204){//sets a condition is it dtectes black
            create3_drive_straight(0.09,0.39);
            printf("found Black\n");
            velocity = 0;
        }
        create3_velocity_set_components(velocity, 0);//uses velocity variable as linear x
    }

    create3_wait();
    // return 0;

}

void line_follow(){
    enable_servos();
    set_servo_position(3,877);
    msleep(500);
    int mid = 1000;//sets variable as integer
    create3_connect();
    while(analog(0) < 2800){//this isn't true
        if (analog(2)>= mid){// If this is true
            create3_velocity_set_components(0.1,0.3);
        }
        else{
            create3_velocity_set_components(0.1,-0.3); 
        }
    }
    create3_velocity_set_components(0,0);

    set_servo_position(3,1500);
    msleep(500);
}



void follow_towards(int farness, float speed){
    while(analog(0) < farness){
        create3_drive_straight(0.1,speed);
    }
}
void rotate(){
    create3_rotate_degrees(45,45);
}

void pick_up_object_code(){
    set_servo_position(0,1290);
    set_servo_position(1,1559);
    set_servo_position(3,2000);
    msleep(1000);
}
void turn_value(){
    int v = 0;
    printf("V is %d", v);
}
int main()
{  
    wait_for_light(5);
    shut_down_in(119);
    //printf("ITTTS PAARRTYY TIIMMEE!!");
    msleep(70000);
    enable_servos();
    set_servo_position(0,1122);
    msleep(500);
    create3_connect();

    //set_servo_position(0,1810);
    //set_servo_position(1,0);
    //set_servo_position(2,100);
    create3_drive_straight(0.4,0.49);
    black_line();
    create3_rotate_degrees(95,90);
    line_follow();
   // create3_drive_straight(0.05,0.49);
    //pick_up_object_code();

    //part 2
    create3_drive_straight(-0.03,0.49);
    create3_rotate_degrees(90,90);
    create3_drive_straight(0.3,0.49);
    create3_rotate_degrees(90,90);
    create3_drive_straight(-0.1,0.49);

    while(analog(2)<1500){
        create3_velocity_set_components(0.1,0);

    }
    create3_drive_straight(0,0.49);
    set_servo_position(0,2047);
    msleep(500);
    set_servo_position(3,279);
    msleep(500);
    //create3_drive_straight(-0.1,0.49);
    // black_line();
    //create3_rotate_degrees(90,90);
    // create3_drive_straight(0.2,0.49);
    // black_line();
    //set_servo_position(3,1000);
    //msleep(400);
    //create3_rotate_degrees(180,90);
    //black_line();
    //create3_rotate_degrees(-90,90);
    printf("Partayyyy...! ._.");
    return 0;
}
//port 0 870
//port 1 1670
//port 2 1000

// pick up location
// port 0 1170
// port 1 1560