#include <csignal>
#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>//rand()
#include <ctime>
#include <cerrno>
#include <unistd.h>
#include <vector>
#include <string>

using namespace std;

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/* You can change these values */
#define MAX_TRE 200
#define NUM_PIR 2
#define NUM_MER 3
#define NUM_EXP 3
#define NUM_REP 2
#define NUM_JP 1
#define NUM_VOL 1
int const map_size = 10;
/* End of changing values */

class Ship {
    private:
        int max_dur;            // Max durability
        int current_dur;        // Current durability
        int speed;              // Ship speed
        int res_tres;           // Treasure supply
        int x;                  // x coord
        int y;                  // y coord
        int id;                 // 0:pirate 1:merchant 2:repairer 3:explorer
        int overall_dist;       // Overall distance covered by a ship 
        int overall_damage;     // Overall damaged suffered (or made) by a ship
        string msg;             // Message for successful operation by a ship
        string ms;
    public:
        Ship();//constructor
        ~Ship();//destructor
        void informations(int);
        int get_speed();
        int get_res_tres();
        void set_speed(int);
        void set_max_dur();
        int get_max_dur();
        void set_res_tres(int);
        void move(int);                 // Movement method
        virtual void operation();       // Operation method without args
        virtual void operation(int,int);// Operation method with args
        virtual void set_damage(int);
        int get_x();
        int get_y();
        void set_x(int);
        void set_y(int);
        int get_current_dur();
        void set_current_dur(int);
        int get_id();
        void set_id(int);
        int get_overall_dist();
        int get_overall_damage();
        void set_overall_dist(int);
        void set_overall_damage(int);
        void set_msg(string);
        string get_msg();
};
 
class Pirate : public Ship {
    private:
        int damage;
    public:
        Pirate();
        ~Pirate();
        void operation();
        void set_damage(int);
        void get_damage();
        void attack(int,int);
};
 
class Merchant : public Ship {
    public:
        Merchant();
        ~Merchant();
        void operation();
};
 
class Repairer : public Ship {
    public:
        Repairer();
        ~Repairer();
        void operation();
        void repair(int,int);
};
 
class Explorer : public Ship {
    public:
        Explorer();
        ~Explorer();
        void operation(int,int);
};

class Jack_sparrow : public Pirate {
    public:
        Jack_sparrow();
        ~Jack_sparrow();
};

class Volunteer : public Repairer {
    public:
        Volunteer();
        ~Volunteer();
};
 
class Point_map {
    private:
        int weather;
        bool treasure;
        bool port;
        int x,y;    // Coordinates
    public:
        Ship *ship_here;            // Pointer to ship that exists there
        Point_map();
        int get_weather();
        int get_treasure();
        int get_port();
        void set_weather (int);
        void set_treasure(bool);
        void set_port(bool);
        void check_weather();       // Check if weather > 7
        void check_treasure();      // Check for treasure in the bottom of the sea and obtain it
        void check_port();          // Check for adjacent port and act accordingly
        void do_ship(int,int);      // Port gives treasure to ships and damage pirates
        int get_x();
        int get_y();
        void set_x(int);
        void set_y(int);
        void weather_renewal();     // Rearrange the weather
};

int kbhit(void);    // Get instant characters from keyboard
class keyboard      // Source: http://www.linux-sxs.org/programming/kbhit.html
{
    public:
        keyboard();
        ~keyboard();
        int kbhit();
        int getch();
    private:
        struct termios initial_settings, new_settings;
        int peek_character;
};

#endif // HEADER_H_INCLUDED
