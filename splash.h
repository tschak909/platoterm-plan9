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
 * splash.h - PLATOTERM splash data
 */

#ifndef SPLASH_H
#define SPLASH_H

#include "protocol.h"
padByte splash[] = 
{
0x1b,
0x02,
0x1b,
0x0c,
0x1b,
0x12,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xe2,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0x0c,
0x1b,
0x12,
0x1d,
0xaf,
0xf0,
0xc0,
0x1b,
0x5a,
0x1b,
0xd1,
0xc0,
0x44,
0x41,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0x0c,
0x1b,
0x12,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0x5a,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xe2,
0xeb,
0x44,
0x59,
0x41,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0x0c,
0x1b,
0x12,
0x1d,
0x28,
0x7e,
0xa5,
0xc0,
0x1b,
0x5a,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1d,
0xa6,
0x6c,
0x24,
0xcc,
0x2b,
0xfa,
0xcc,
0xfa,
0xa5,
0x50,
0xa6,
0x6c,
0x50,
0x6c,
0x24,
0xcc,
0x1d,
0x6c,
0x28,
0x4e,
0xee,
0x27,
0x5a,
0xf0,
0x50,
0x74,
0x48,
0xfc,
0xa6,
0xde,
0x27,
0xe2,
0xd8,
0x6c,
0x50,
0x74,
0xca,
0xfa,
0x48,
0x28,
0xe2,
0x44,
0xf0,
0xc0,
0xa9,
0x60,
0xa5,
0x5c,
0x66,
0x5c,
0xee,
0x5c,
0x78,
0xde,
0xaa,
0x60,
0xa6,
0xc0,
0xe8,
0x44,
0xf0,
0x48,
0x78,
0x4e,
0x7e,
0xd2,
0x2b,
0xe2,
0x56,
0xe8,
0x5c,
0x6c,
0x27,
0x42,
0xf0,
0x48,
0x74,
0x4e,
0x78,
0xd8,
0xfc,
0x28,
0xc6,
0x7e,
0x56,
0x5c,
0xfc,
0xa9,
0x48,
0xfa,
0xd4,
0xf6,
0xaa,
0xc0,
0x72,
0xc6,
0xee,
0xca,
0x6a,
0x50,
0xe4,
0x56,
0xaa,
0x7e,
0x5c,
0x74,
0x2b,
0x42,
0x6a,
0x48,
0x60,
0xcc,
0xa9,
0x74,
0x50,
0xf0,
0x50,
0x66,
0x50,
0x28,
0xfc,
0x50,
0xf0,
0x4e,
0xe8,
0xcc,
0x27,
0x7e,
0x48,
0xf6,
0x44,
0xee,
0xaa,
0xde,
0x66,
0xd8,
0xa6,
0x7e,
0x50,
0x78,
0xca,
0x72,
0xc0,
0xee,
0xa9,
0xd8,
0x6c,
0x4e,
0x6c,
0x28,
0x4e,
0x1d,
0xaa,
0x78,
0x4e,
0x5a,
0xf6,
0xa9,
0x44,
0x74,
0xcc,
0xee,
0x56,
0xe8,
0x5c,
0x60,
0xaa,
0x42,
0xa9,
0x78,
0xc6,
0xf0,
0x48,
0xe8,
0xca,
0x28,
0x7e,
0xca,
0x72,
0x48,
0x6a,
0x44,
0xe4,
0xc0,
0x27,
0x7e,
0xa9,
0x5c,
0xfa,
0x56,
0xf6,
0xd2,
0x72,
0x48,
0xf0,
0xc0,
0xee,
0x28,
0xd8,
0x50,
0xf0,
0xc6,
0x74,
0x27,
0xde,
0x78,
0xd8,
0xfc,
0xd2,
0x28,
0xe2,
0xcc,
0xe8,
0x48,
0x6c,
0xc6,
0xf0,
0x44,
0x78,
0x42,
0xa9,
0x60,
0x42,
0x6c,
0x42,
0x78,
0xc6,
0xaa,
0x60,
0xca,
0x66,
0x50,
0x6a,
0xd4,
0xee,
0xd8,
0xf0,
0x5a,
0x72,
0x5c,
0x74,
0x28,
0xc0,
0xf6,
0xc6,
0x78,
0x4e,
0x1d,
0x28,
0x7e,
0xac,
0x50,
0x1d,
0xa5,
0xee,
0xa3,
0x50,
0xee,
0xac,
0x41,
0xac,
0x41,
0xee,
0xa3,
0x50,
0xa5,
0x50,
0x1d,
0xed,
0xcf,
0xed,
0xac,
0x42,
0xac,
0x6f,
0x42,
0x6f,
0xa3,
0xcf,
0xa5,
0xed,
0xcf,
0x1d,
0x6c,
0x4e,
0x6c,
0xac,
0xc3,
0xac,
0xf0,
0xc3,
0xf0,
0xa3,
0x4e,
0xa5,
0x6c,
0x4e,
0x1d,
0xeb,
0x4d,
0xeb,
0xac,
0x44,
0xac,
0x71,
0x44,
0x71,
0xa3,
0x4d,
0xa5,
0xeb,
0x4d,
0x1d,
0x6a,
0xcc,
0x6a,
0xac,
0xc5,
0xac,
0x72,
0xc5,
0x72,
0xa3,
0xcc,
0xa5,
0x6a,
0xcc,
0x1d,
0x69,
0x4b,
0x69,
0xac,
0xc6,
0xac,
0xf3,
0xc6,
0xf3,
0xa3,
0x4b,
0xa5,
0x69,
0x4b,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xe2,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1d,
0x28,
0xe4,
0x24,
0xde,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x65,
0xa6,
0x4d,
0x1b,
0x63,
0xc0,
0xc0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xe2,
0xeb,
0x44,
0x59,
0x41,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1d,
0xa3,
0x7e,
0xa3,
0x50,
0x1b,
0x5a,
0x1b,
0x12,
0x1d,
0x6f,
0xcc,
0x24,
0xf6,
0xcc,
0x53,
0xa3,
0x6f,
0x53,
0xcc,
0x1d,
0x5a,
0x24,
0x71,
0x5a,
0xf3,
0x5a,
0x5a,
0x74,
0xdb,
0xdb,
0xf5,
0x5c,
0x5c,
0xf6,
0xdd,
0xf6,
0x24,
0x47,
0x48,
0xf5,
0xca,
0x4b,
0x74,
0xcc,
0x4d,
0xf3,
0x4e,
0x4e,
0x72,
0xcf,
0x71,
0x50,
0x50,
0xf0,
0x50,
0x6f,
0xd1,
0xee,
0xd1,
0xed,
0xd2,
0x6c,
0xd2,
0xeb,
0xd2,
0x69,
0xd2,
0xe7,
0xd1,
0x66,
0xd1,
0x65,
0x50,
0xe4,
0x50,
0x63,
0xcf,
0xe2,
0x4e,
0x4d,
0x4b,
0xe1,
0x4b,
0xca,
0xa3,
0x6f,
0x55,
0xca,
0x24,
0x60,
0xc3,
0xe1,
0x42,
0xe2,
0x42,
0x63,
0xc3,
0xe4,
0x44,
0x65,
0xc5,
0xc5,
0x66,
0xc5,
0xc6,
0xe7,
0x48,
0xe8,
0xc9,
0x69,
0xc9,
0xeb,
0xc9,
0xed,
0x48,
0x47,
0xee,
0xc6,
0x42,
0xa3,
0x6f,
0x42,
0x6f,
0xa3,
0x5a,
0x1d,
0x6f,
0x24,
0x55,
0x24,
0xf3,
0xa5,
0xc0,
0xc0,
0x74,
0x41,
0xf5,
0x42,
0xf6,
0x42,
0x44,
0x77,
0xc5,
0xc5,
0xf6,
0x47,
0xf5,
0x48,
0x74,
0xc9,
0xf3,
0xca,
0xa3,
0x6f,
0x55,
0xcc,
0x77,
0xca,
0xc0,
0x6f,
0x24,
0xdd,
0x55,
0x1d,
0x7e,
0xa5,
0x42,
0x24,
0xee,
0xc5,
0xa3,
0x7e,
0x48,
0x42,
0x1d,
0x6f,
0x59,
0x24,
0xee,
0x59,
0xd2,
0xf6,
0xd2,
0xf6,
0xa6,
0x48,
0xee,
0x48,
0x41,
0xa3,
0x6f,
0x41,
0x6f,
0xa5,
0x59,
0x1d,
0x7e,
0xa6,
0xd1,
0x1d,
0x6f,
0x44,
0x24,
0xf3,
0xcf,
0xcf,
0x74,
0x50,
0xf5,
0xd1,
0xf6,
0xd1,
0x53,
0x77,
0xd4,
0xd4,
0xf6,
0x56,
0xf5,
0xd7,
0x74,
0xd8,
0xf3,
0x59,
0xa3,
0x6f,
0x27,
0x44,
0x6f,
0xa6,
0xdb,
0x77,
0x59,
0xcf,
0x6f,
0xcc,
0x44,
0x1d,
0x7e,
0xd1,
0x24,
0xee,
0xd4,
0xa3,
0x7e,
0xd7,
0xd1,
0x1d,
0x6f,
0x27,
0x5c,
0xd8,
0xf0,
0x55,
0x71,
0x53,
0x72,
0xd1,
0x74,
0x50,
0xf6,
0x4e,
0x78,
0x4d,
0xf9,
0xcc,
0x7b,
0x4b,
0x7e,
0xca,
0x24,
0xe2,
0xc9,
0xc9,
0xe4,
0xc9,
0xe7,
0xca,
0xe8,
0xca,
0x6a,
0x4b,
0x6c,
0xcc,
0xee,
0x4d,
0x6f,
0x4e,
0xf0,
0xcf,
0x72,
0xd1,
0xf3,
0xd2,
0x53,
0x74,
0x55,
0xf5,
0xd7,
0xf6,
0x5a,
0x77,
0xde,
0xde,
0xf6,
0x28,
0x41,
0x44,
0xf5,
0x47,
0x74,
0x48,
0xf3,
0xc9,
0x72,
0xca,
0x71,
0xcc,
0x6f,
0x4d,
0xed,
0xcf,
0xeb,
0x50,
0xe8,
0xd1,
0x66,
0xd2,
0x65,
0xd2,
0xe2,
0xd2,
0xe1,
0xd2,
0xa3,
0x7e,
0xd1,
0x7d,
0xd1,
0xfa,
0x50,
0x78,
0xcf,
0x77,
0x4e,
0xf5,
0xcc,
0xf3,
0xca,
0x71,
0xc9,
0xf0,
0x47,
0x6f,
0xc5,
0xc3,
0x6f,
0x27,
0x5c,
0x1d,
0x24,
0xee,
0x5c,
0xde,
0xed,
0x28,
0xc0,
0x42,
0x6c,
0x44,
0x6a,
0xc6,
0xe8,
0x47,
0xe7,
0x48,
0x65,
0xc9,
0x63,
0xc9,
0xe2,
0xc9,
0xa3,
0xff,
0xff,
0xc9,
0x7d,
0x48,
0xfc,
0x47,
0xfa,
0xc6,
0xf9,
0x44,
0x78,
0xc3,
0x77,
0x41,
0x77,
0x27,
0x5f,
0xde,
0xdd,
0x5a,
0x78,
0x59,
0xf9,
0xd7,
0xfa,
0x56,
0x7b,
0xd4,
0x7d,
0x53,
0x53,
0x7e,
0x53,
0x24,
0x60,
0xd2,
0xe2,
0xd2,
0xe4,
0xd2,
0xe7,
0x53,
0xe8,
0xd4,
0x6a,
0x55,
0xeb,
0x56,
0x6c,
0xd7,
0xd8,
0xed,
0xd8,
0x59,
0x5a,
0xee,
0x5c,
0x1d,
0xa3,
0x7e,
0x28,
0x5c,
0x1b,
0x59,
0x50,
0x41,
0xc0,
0x1d,
0x6f,
0x55,
0x24,
0xf3,
0x55,
0x74,
0x55,
0x56,
0xf5,
0x56,
0xf6,
0xd7,
0xd8,
0x77,
0x5a,
0xdb,
0xf6,
0x5c,
0xdd,
0xf5,
0xde,
0x74,
0xde,
0xa3,
0x7b,
0xa9,
0x48,
0xc9,
0x24,
0xf6,
0xc9,
0xd1,
0xa3,
0xf3,
0xd1,
0x72,
0x50,
0x71,
0x50,
0xf0,
0xcf,
0x6f,
0x4e,
0x4d,
0x48,
0xf0,
0x47,
0x71,
0xc6,
0x24,
0x69,
0x28,
0xdd,
0x5c,
0xa3,
0x6f,
0x5c,
0x55,
0x1d,
0xf3,
0xa9,
0x53,
0x24,
0xf5,
0x53,
0xdb,
0xa3,
0xf6,
0xdb,
0xf6,
0xaa,
0xc6,
0x6f,
0xc6,
0x6f,
0xa9,
0xd8,
0x56,
0xf0,
0x55,
0x71,
0xd4,
0xf3,
0x53,
0x1d,
0x6f,
0xaa,
0x4b,
0x24,
0xf6,
0x4b,
0xd2,
0xa3,
0x6f,
0xd2,
0x4b,
0x1d,
0xd4,
0x24,
0xf3,
0xd4,
0x74,
0xd4,
0x55,
0xf5,
0x55,
0xf6,
0x56,
0xd7,
0x77,
0x59,
0x5a,
0xf6,
0xdb,
0x5c,
0xf5,
0xdd,
0x74,
0xdd,
0xa3,
0x7b,
0x2b,
0x47,
0x48,
0x24,
0xf6,
0x48,
0x50,
0xa3,
0xf3,
0x50,
0x72,
0xcf,
0x71,
0xcf,
0xf0,
0x4e,
0x6f,
0x4d,
0xcc,
0x47,
0xf0,
0xc6,
0x71,
0xc5,
0x24,
0x69,
0xaa,
0x5c,
0xdb,
0xa3,
0x6f,
0xdb,
0xd4,
0x1d,
0x7e,
0x2b,
0xd8,
0x1d,
0xf6,
0x53,
0x24,
0x71,
0x53,
0x72,
0x53,
0xf3,
0xd4,
0x74,
0xd4,
0xf5,
0x55,
0x55,
0xf6,
0x56,
0xd8,
0xf6,
0xac,
0xc6,
0xee,
0xc6,
0xee,
0x2b,
0x5a,
0xe7,
0x5a,
0xe7,
0xac,
0xc6,
0x60,
0xc6,
0x60,
0x2b,
0x5a,
0xa3,
0x77,
0x5a,
0x77,
0xac,
0xc6,
0x6f,
0xc6,
0x6f,
0x2b,
0xd8,
0xd7,
0xf0,
0x56,
0x55,
0x71,
0xd4,
0x72,
0x53,
0xf3,
0x53,
0xf6,
0x53,
0x1d,
0x7e,
0xac,
0x53,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xe2,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1d,
0x7d,
0xa3,
0x50,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x77,
0x24,
0xcc,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x7b,
0xde,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x78,
0xa5,
0xdd,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xfa,
0xa6,
0x4d,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x72,
0x27,
0xde,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xf5,
0xa9,
0xcc,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xf3,
0xd8,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x7b,
0xaa,
0xcf,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0xf3,
0x2b,
0x4b,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x24,
0x63,
0xd8,
0x1b,
0x63,
0xc0,
0xc0,
0x1d,
0x22,
0xf0,
0xa6,
0xd8,
0x1b,
0x5a,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xe2,
0xeb,
0x44,
0x59,
0x41,
0x9f,
0x1b,
0x12,
0x41,
0xee,
0xa0,
0x6f,
0xee,
0x2d,
0x6c,
0x69,
0xee,
0x65,
0xa0,
0xf3,
0x65,
0x72,
0xf6,
0x69,
0x63,
0x65,
0xa0,
0x66,
0x6f,
0x72,
0x8d,
0xd2,
0x65,
0x74,
0x72,
0x6f,
0x2d,
0xc3,
0x6f,
0xed,
0xf0,
0xf5,
0x74,
0x69,
0xee,
0xe7,
0xa0,
0xc5,
0xee,
0x74,
0xe8,
0xf5,
0xf3,
0x69,
0xe1,
0xf3,
0x74,
0xf3,
0x1d,
0xaf,
0xf0,
0xa0,
0xc0,
0x1b,
0x5a,
0x1b,
0x59,
0x50,
0x41,
0xc0,
0x1b,
0x03
};

#endif /* SPLASH_H*/
