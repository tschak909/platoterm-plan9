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
 * touch.h - Touch (mouse) functions
 */

#ifndef TOUCH_H
#define TOUCH_H

#include "protocol.h"

void touch_init(void);
void touch_main(int x,int y);
void touch_allow(padBool allow);
void handle_mouse(void);
void touch_hide(void);
void touch_done(void);

#endif /* TOUCH_H */
