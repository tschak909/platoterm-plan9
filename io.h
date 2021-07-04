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
 * io.h - I/O functions
 */

#ifndef IO_H
#define IO_H

#define XON  0x11
#define XOFF 0x13

/**
 * io_init() - Set-up the I/O
 */
void io_init(char* hostname, char* port);

/**
 * io_send_byte(b) - Send specified byte out
 */
void io_send_byte(unsigned char b);

/**
 * io_main() - The IO main loop
 */
void io_main(unsigned char *data, int n);

/**
 * io_done() - Called to close I/O
 */
void io_done(void);

#endif /* IO_H */
