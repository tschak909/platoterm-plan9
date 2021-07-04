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
 * screen.c - Screen drawing functions
 */

#ifndef SCREEN_H
#define SCREEN_H

#include "protocol.h"

void screen_init(void);
void screen_update_view(void);
void screen_main(void);
void screen_wait(void);
void screen_beep(void);
void screen_clear(void);
void screen_set_pen_mode(void);
void screen_block_draw(padPt *Coord1, padPt *Coord2);
void screen_dot_draw(padPt* Coord);
void screen_line_draw(padPt *Coord1, padPt *Coord2);
void screen_char_draw(padPt *Coord, unsigned char *ch, unsigned char count);
void screen_tty_char(padByte theChar);
unsigned long screen_color_match(padRGB *platocolor);
void screen_foreground(padRGB* theColor);
void screen_background(padRGB* theColor);
void screen_paint(padPt *Coord);
void screen_done(void);

#endif /* SCREEN_H */
