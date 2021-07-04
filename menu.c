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
 * menu.c - Menu functions
 */

#include <u.h>
#include <libc.h>
#include "menu.h"
#include "protocol.h"
#include "plato_key.h"

extern int done;
extern void keyboard_out(unsigned char platoKey);

#define TRUE 1
#define FALSE 0

void menu_right(int item)
{
	switch (item)
	{
		case 0: // ANS
			keyboard_out(PKEY_ANS);
			break;
		case 1: // BACK
			keyboard_out(PKEY_BACK);
			break;
		case 2: // COPY
			keyboard_out(PKEY_COPY);
			break;
		case 3: // DATA
			keyboard_out(PKEY_DATA);
			break;
		case 4: // EDIT
			keyboard_out(PKEY_EDIT);
			break;
		case 5: // FONT
			keyboard_out(PKEY_FONT);
			break;
		case 6: // HELP
			keyboard_out(PKEY_HELP);
			break;
		case 7: // LAB
			keyboard_out(PKEY_LAB);
			break;
		case 8: // MICRO
			keyboard_out(PKEY_MICRO);
			break;
		case 9: // NEXT
			keyboard_out(PKEY_NEXT);
			break;
		case 10: // SQUARE
			keyboard_out(PKEY_SQUARE);
			break;
		case 11: // STOP
			keyboard_out(PKEY_STOP);
			break;
		case 12: // SUB
			keyboard_out(PKEY_SUB);
			break;
		case 13: // SUPER
			keyboard_out(PKEY_SUPER);
			break;
		case 14: // TERM
			keyboard_out(PKEY_TERM);
			break;
		case 15: // Multiply
			keyboard_out(PKEY_MULTIPLY);
			break;
		case 16: // Divide
			keyboard_out(PKEY_DIVIDE);
			break;
		case 17: // Sigma
			keyboard_out(PKEY_SIGMA);
			break;
		case 18: // Delta
			keyboard_out(PKEY_DELTA);
			break;
		case 19: // Quit
			done=TRUE;
			break;

	}
}

void menu_middle(int item)
{
	switch (item)
	{
		case 0:
			keyboard_out(PKEY_BACK1);
			break;
		case 1:
			keyboard_out(PKEY_COPY1);
			break;
		case 2:
			keyboard_out(PKEY_DATA1);
			break;
		case 3:
			keyboard_out(PKEY_EDIT1);
			break;
		case 4:
			keyboard_out(PKEY_HELP1);
			break;
		case 5:
			keyboard_out(PKEY_LAB1);
			break;
		case 6:
			keyboard_out(PKEY_NEXT1);
			break;
		case 7:
			keyboard_out(PKEY_STOP1);
			break;
		case 8:
			keyboard_out(PKEY_SUB1);
			break;
		case 9:
			keyboard_out(PKEY_SUPER1);
			break;
	}
}