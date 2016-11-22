/*
 *     SocialLedge.com - Copyright (C) 2013
 *
 *     This file is part of free software framework for embedded processors.
 *     You can use it and/or distribute it as long as this copyright header
 *     remains unmodified.  The code is free for personal use and requires
 *     permission to use in a commercial product.
 *
 *      THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *      OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *      MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *      I SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *      CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *     You can reach the author of this software at :
 *          p r e e t . w i k i @ g m a i l . c o m
 */

/**
 * @file
 * This contains the period callback functions for the periodic scheduler
 *
 * @warning
 * These callbacks should be used for hard real-time system, and the priority of these
 * tasks are above everything else in the system (above the PRIORITY_CRITICAL).
 * The period functions SHOULD NEVER block and SHOULD NEVER run over their time slot.
 * For example, the 1000Hz take slot runs periodically every 1ms, and whatever you
 * do must be completed within 1ms.  Running over the time slot will reset the system.
 */

#include <sensor_sonar.hpp>
#include <stdint.h>
#include "io.hpp"
#include "periodic_callback.h"
#include "io.hpp"
#include "stdio.h"
#include "timers.h"
#include "utilities.h"
#include "file_logger.h"
#include "can.h"
#include "_can_dbc/generated_can.h"
#include "lpc_timers.h"
#include "string.h"
#include "eint.h"



//SYSTEM_CMD_t master_cmd = {0};

const uint32_t            MASTER_CMD__MIA_MS = 3000;
//const SYSTEM_CMD_t      MASTER_CMD__MIA_MSG = { 25 };


/// This is the stack size used for each of the period tasks (1Hz, 10Hz, 100Hz, and 1000Hz)
const uint32_t PERIOD_TASKS_STACK_SIZE_BYTES = (512 * 4);

/**
 * This is the stack size of the dispatcher task that triggers the period tasks to run.
 * Minimum 1500 bytes are needed in order to write a debug file if the period tasks overrun.
 * This stack size is also used while calling the period_init() and period_reg_tlm(), and if you use
 * printf inside these functions, you need about 1500 bytes minimum
 */
const uint32_t PERIOD_DISPATCHER_TASK_STACK_SIZE_BYTES = (512 * 3);

/// Called once before the RTOS is started, this is a good place to initialize things once


bool period_init(void)
{
	sensor_init();
	can_init_sensor();
	return true; // Must return true upon success
}

/// Register any telemetry variables
bool period_reg_tlm(void)
{
	// Make sure "SYS_CFG_ENABLE_TLM" is enabled at sys_config.h to use Telemetry
	return true; // Must return true upon success
}


/**
 * Below are your periodic functions.
 * The argument 'count' is the number of times each periodic task is called.
 */

void period_1Hz(uint32_t count)
{

    ultrasonic_sensor_heartbeat_message();

	//LE.toggle(1);
}

void period_10Hz(uint32_t count)
{
    static bool start=false;
	/*sensor_heartbeat_message.SENSOR_HEARTBEAT_tx_bytes = 12;
	sensor_heartbeat_message.SENSOR_HEARTBEAT_rx_bytes = 54;
	dbc_encode_and_send_SENSOR_HEARTBEAT(&sensor_heartbeat_message);*/

	//puts("sent");
    /**
     * todo what is the point of this if/else statement? You set start = true in both cases.
     */
    if(received_sensor_can_msg()==1){
        start=true;
    }
    else{
        start=true;
    }
    if(start){
        sensor_measure();
    }

    //decoded_can_sensor_message(1,0,0);
	//LE.toggle(2);
}

void period_100Hz(uint32_t count)
{
	//LE.toggle(3);
}

// 1Khz (1ms) is only run if Periodic Dispatcher was configured to run it at main():
// scheduler_add_task(new periodicSchedulerTask(run_1Khz = true));
void period_1000Hz(uint32_t count)
{
	//LE.toggle(4);
}

