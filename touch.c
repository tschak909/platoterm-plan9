/**
 * PLATOTERM for Plan 9
 *
 * A PLATO terminal for services such as 
 *     CYBER1.ORG and IRATA.ONLINE
 *
 * Author: Thomas Cherryhomes
 *   <thom.cherryhomes@gmail.com>
 * 
 * License: GPL 3.0
 *
 * touch.c - Touch screen (mouse) functions
 */
#include <u.h>
#include <libc.h>
#include "touch.h"
#include "protocol.h"

/**
 * void touch_init() - Set up touch screen
 */
void touch_init(void)
{
}

void touch_allow(padBool allow)
{
	USED(allow);
}

/**
 * void touch_main() - Main loop for touch screen
 */
void touch_main(int x,int y)
{
	padPt Coord = {x, y^0x1FF};
	Touch(&Coord);
}

/**
 * void touch_done() - Stop the mouse driver
 */
void touch_done(void)
{
}

