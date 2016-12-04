/*
 * navigation.h
 *
 *  Created on: Nov 15, 2016
 *      Author: Shaurya Jain & Harsha Gorantla
 */

#ifndef L5_APPLICATION_NAVIGATION_H_
#define L5_APPLICATION_NAVIGATION_H_

#include <uart2.hpp>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include "i2c2.hpp"
#include "i2c_base.hpp"
#include "i2c2_device.hpp"


/*
 * Configuration of GPS Module
 * Adafruit Ultimate GPS breakout board
 *
 */
/*
#define SET_OUTPUT_RMC      "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29<CR><LF>"
#define SET_OUTPUT_RMC_GGA  "$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28<CR><LF>"
#define SET_OUTPUT_ALLDATA  "$PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0*28<CR><LF>"
#define SET_OUTPUT_OFF      "$PMTK314,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28<CR><LF>"

#define UPDATE_RATE_10HZ    "$PMTK220,100*2F<CR><LF>"

#define BAUD_RATE_38400     "$PMTK251,38400*27<CR><LF>"
*/

#define GPS_BAUDRATE    115200
#define GPS_DATA_SIZE   255
#define RX_Q_SIZE       100
#define TX_Q_SIZE       1

#define STATIC_LAT      37
#define STATIC_LONG     121
#define RADIUS          20902231.64

#define MIN_ANGLE       0
#define MAX_ANGLE       360
#define DISTANCE_OFFSET 10
#define STEER_OFFSET    25

typedef struct {
        float latitude;
        float longitude;
}gps_data,app_data;

enum direction {
	straight,
	half_left,
	full_left,
	half_right,
	full_right
};

class Navigation
{
    public:
        void gps_init();
        void compass_init();
        bool geo();
        gps_data coordinates;
        app_data checkpoints;
        uint16_t compass_angle;
        bool destination_reached;
        direction steer;
        bool last_checkpoint_received;

        Navigation(){
            coordinates = {0};
            checkpoints = {0};
            gps_raw_data = new char[GPS_DATA_SIZE];
            gps_bearing_angle = -1;
            gps_distance = -1;
            compass_angle = -1;
            destination_reached = false;
            steer = straight;
            last_checkpoint_received = false;
            pop_next_checkpoint = true;
            next_checkpoint_reached = false;
        }

        ~Navigation(){
            delete [] gps_raw_data;
        }

    private:
        bool gps_get_raw_data();
        bool is_gpgga();
        bool gps_raw_data_checkSum(); //To check integrity of the raw gps data received upon uart
        bool parse_gps_raw_data();
        void gps_calculate_bearing_angle();
        void gps_calculate_distance();
        void compass_direction();
        void steer_command();
        void compass_calibrate();

        char* gps_raw_data;
        uint16_t gps_bearing_angle;
        float gps_distance;
        bool pop_next_checkpoint;
        bool next_checkpoint_reached;

};


#endif /* L5_APPLICATION_NAVIGATION_H_ */