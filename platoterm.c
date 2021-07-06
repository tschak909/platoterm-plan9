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
 * platoterm.c - Main/initialization functions.
 */

#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>
#include "protocol.h"
#include "screen.h"
#include "io.h"
#include "terminal.h"
#include "keyboard.h"
#include "touch.h"
#include "menu.h"

#define TRUE 1
#define FALSE 0

char* options1[] = {"ANS","BACK","COPY","DATA","EDIT","FONT","HELP","LAB","MICRO","NEXT","□","STOP","SUB","SUPER","TERM","×","÷","Σ","Δ","Quit",0};
char* options2[] = {"SHIFT-BACK (BACK1)","SHIFT-COPY (COPY1)","SHIFT-DATA (DATA1)", "SHIFT-EDIT (EDIT)", "SHIFT-HELP (HELP1)", "SHIFT-LAB (LAB1)", "SHIFT-NEXT (NEXT1)", "SHIFT-STOP (STOP1)", "SHIFT-SUB (SUB1)", "SHIFT-SUPER (SUPER1)",0};

char* h;
char* p="8005";

Menu rightmenu = {options1};
Menu midmenu = {options2};

unsigned char already_started=FALSE;
int done = FALSE;

Event ev;
Mouse m;
int key;
int netev;

extern int net;

void usage(void)
{
	print("platoterm -h <hostname> [-p <port>]\n");
	exits("invalid args");
}

void main(int argc, char *argv[])
{
	unsigned char err=TRUE;

	ARGBEGIN
	{
		case 'h':
			h = ARGF();
			err=FALSE;
			break;
		case 'p':
			p = ARGF();
			break;
		default:
			usage();	
	} 
	ARGEND;

	if (argc == 1 || err == TRUE)
		usage();

	screen_init();
	terminal_init();
	touch_init();
	io_init(h, p);

	netev = estart(0,net,EMAXMSG);

	while (done == FALSE)
	{
		key = event(&ev);

		if (key == Ekeyboard)
				keyboard_main(ev.kbdc);
		else if (key == Emouse)
		{
			if (ev.mouse.buttons & 1)
				touch_main(ev.mouse.xy.x - screen->r.min.x, ev.mouse.xy.y - screen->r.min.y);
			else if (ev.mouse.buttons & 2)
				menu_middle(emenuhit(2,&ev.mouse,&midmenu));
			else if (ev.mouse.buttons & 4)
				menu_right(emenuhit(3,&ev.mouse,&rightmenu));
		}
		else if (key == netev)
		{
			io_main(ev.data,ev.n);
			screen_update_view();
		}
	}

	touch_done();
	io_done();
	screen_done();
}
