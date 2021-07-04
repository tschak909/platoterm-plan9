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
 * io.c - I/O functions
 */

#include <u.h>
#include <libc.h>
#include "io.h"
#include "protocol.h"

#define TRUE 1
#define FALSE 0

int buflen;

int net;

extern int done;

/**
 * io_init() - Set-up the I/O
 */
void io_init(char* hostname, char* port)
{
	net = dial(netmkaddr(hostname,"tcp",port),0,0,0);

	if (net < 0)
		done=TRUE;
}

/**
 * io_send_byte(b) - Send specified byte out
 */
void io_send_byte(unsigned char b)
{
	write(net, &b, 1);
}

/**
 * io_main() - The IO event
 */
void io_main(uchar *data, int n)
{
	ShowPLATO((padByte *)data,n);
}

/**
 * io_done() - Called to close I/O
 */
void io_done()
{
	close(net);
}
