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
 * keyboard.c - Keyboard functions
 */

#include <u.h>
#include <libc.h>
#include "keyboard.h"
#include "protocol.h"
#include "key.h"

#define TRUE 1
#define FALSE 0

unsigned char ch;

/* ACCESS Key combinations. */
unsigned char ACCESS_KEYS[] = {
  PKEY_a, /* 0x80 a ɑ alpha */ 
  PKEY_B, /* 0x81 b ß beta */
  PKEY_c, /* 0x82 c cedilla */
  PKEY_d, /* 0x83 d δ delta */
  PKEY_e, /* 0x84 e ' acute accent */
  PKEY_g, /* 0x85 g æ ae */
  PKEY_h, /* 0x86 h oe oe */
  PKEY_j, /* 0x87 j å a with ring */
  PKEY_k, /* 0x88 k ä a with diaeresis */
  PKEY_l, /* 0x89 l ƛ lambda */
  PKEY_m, /* 0x8A m μ mu */
  PKEY_n, /* 0x8B n ~ tilde */
  PKEY_o, /* 0x8C o ° degree */
  PKEY_p, /* 0x8D p π pi */
  0x51, /* 0x8E q ` grave */
  PKEY_r, /* 0x8F r ρ rho */
  PKEY_s, /* 0x90 s σ sigma */
  PKEY_t, /* 0x91 t θ theta */
  PKEY_u, /* 0x92 u ¨ diaeresis */
  PKEY_v, /* 0x93 v hacek (upside down circumflex) */
  PKEY_w, /* 0x94 w ϖ capital pi */
  PKEY_x, /* 0x95 x ^ circumflex */
  PKEY_0, /* 0x96 0 l-embed */
  PKEY_1, /* 0x97 1 r-embed */
  PKEY_5, /* 0x98 5 @ */
  PKEY_6, /* 0x99 6 arrow */
  PKEY_PLUS, /* 0x9a + & */
  0x26, /* 0x9b & interpunct */
  PKEY_COLON, /* 0x9c : ~ lower tilde */
  0x5f, /* 0x9d , delimiter */
  PKEY_SLASH, /* 0x9e / \ */
  PKEY_EQUALS, /* 0x9f = not equal */
  PKEY_y, /* 0xA0 y ö */
  0x61, /* 0xA1 A left arrow */
  0x78, /* 0xA2 X down arrow */
  0x64, /* 0xA3 D right arrow */
  0x77, /* 0xA4 W up arrow */
  0x63, /* 0xA5 C © */
  0x66, /* 0xA6 F ♦ */
  0x67, /* 0xA7 G Æ */
  0x68, /* 0xA8 H OE */
  0x69, /* 0xA9 I | */
  0x6A, /* 0xAA J Å */
  0x6B, /* 0xAB K Ä */
  0x6F, /* 0xAC O SQUARE */
  0x79, /* 0xAD Y Ö */
  0x20, /* 0xAE < ≤ */
  0x21, /* 0xAF > ≥ */
  0x5B, /* 0xB0 [ { */
  PKEY_SLASH, /* 0xB1 ] } */
  0x24, /* 0xB2 $ # */
  0x9a, /* 0xB3 & big cross */
  0x7B  /* 0xB4 EQUIVALENT */
};

void keyboard_out(unsigned char platoKey)
{
  if (platoKey==0xff)
    return;
  
  if (platoKey>0x7F)
    {
      Key(ACCESS);
      Key(ACCESS_KEYS[platoKey-0x80]);
      return;
    }
  Key(platoKey);
}

void keyboard_main(int k)
{
	unsigned char outk=0xff;

	switch(k)
	{
		case 0x01: // ctrl-A
			outk=PKEY_ANS;
			break;
		case 0x02: // ctrl-B
			outk=PKEY_BACK;
			break;
		case 0x03: // ctrl-C
			outk=PKEY_COPY;
			break;
		case 0x04: // ctrl-D
			outk=PKEY_DATA;
			break;
		case 0x05: // ctrl-E
			outk=PKEY_EDIT;
			break;
		case 0x06: // ctrl-F
			outk=PKEY_FONT;
			break;
		case 0x07: // ctrl-G
			outk=PKEY_DIVIDE;
			break;
		case 0x08: // ctrl-H
			outk=PKEY_ERASE;
			break;
		case 0x09: // ctrl-I
			break;
		case 0x0a: // ctrl
			outk=PKEY_NEXT;
			break;
		case 0x0b: // ctrl-K
			break;
		case 0x0c: // ctrl-L
			outk=PKEY_LAB;
			break;
		case 0x0d: // ctrl-M
			outk=PKEY_NEXT;
			break;
		case 0x0e: // ctrl-N
			outk=PKEY_NEXT1;
			break;
		case 0x0f: // ctrl-O
			break;
		case 0x10: // ctrl-P
			outk=PKEY_SUPER;
			break;
		case 0x11: // ctrl-Q
			outk=PKEY_SQUARE;
			break;
		case 0x12: // ctrl-R
			outk=PKEY_ERASE;
			break;
		case 0x13: // ctrl-S
			outk=PKEY_STOP;
			break;
		case 0x14: // ctrl-T
			outk=PKEY_TERM;
			break;
		case 0x15: // ctrl-U
			break;
		case 0x16: // ctrl-V
			break;
		case 0x17: // ctrl-W
			break;
		case 0x18: // ctrl-X
			outk=PKEY_MULTIPLY;
			break;
		case 0x19: // ctrl-Y
			outk=PKEY_SUB;
			break;
		case 0x1a: // ctrl-Z
			break;
		case 0x1b: // ESC
			outk=PKEY_ASSIGN;
			break;
		case 0x1c:
			break;
		case 0x1d:
			break;
		case 0x1e:
			break;
		case 0x1f:
			break;
		case 0x20:
			outk=PKEY_SPACE;
			break;
		case 0x21: // !
			outk=PKEY_EXCLAMATION;
			break;
		case 0x22: // "
			outk=PKEY_QUOTE;
			break;
		case 0x23: // #
			outk=PKEY_POUND;
			break;
		case 0x24: // $
			outk=PKEY_DOLLAR;
			break;
		case 0x25: // %
			outk=PKEY_PERCENT;
			break;
		case 0x26: // &
			outk=PKEY_AMPERSAND;
			break;
		case 0x27: // '
			outk=PKEY_APOSTROPHE;
			break;
		case 0x28: // (
			outk=PKEY_PARENTHESIS_LEFT;
			break;
		case 0x29: // )
			outk=PKEY_PARENTHESIS_RIGHT;
			break;
		case 0x2A: // *
			outk=PKEY_ASTERISK;
			break;
		case 0x2B: // +
			outk=PKEY_PLUS;
			break;
		case 0x2C: // ,
			outk=PKEY_COMMA;
			break;
		case 0x2D: // -
			outk=PKEY_MINUS;
			break;
		case 0x2E: // .
			outk=PKEY_PERIOD;
			break;
		case 0x2F: // /
			outk=PKEY_SLASH;
			break;
		case 0x30: // 0
			outk=PKEY_0;
			break;
		case 0x31: // 1
			outk=PKEY_1;
			break;
		case 0x32: // 2
			outk=PKEY_2;
			break;
		case 0x33: // 3
			outk=PKEY_3;
			break;
		case 0x34: // 4
			outk=PKEY_4;
			break;
		case 0x35: // 5
			outk=PKEY_5;
			break;
		case 0x36: // 6
			outk=PKEY_6;
			break;
		case 0x37: // 7
			outk=PKEY_7;
			break;
		case 0x38: // 8
			outk=PKEY_8;
			break;
		case 0x39: // 9
			outk=PKEY_9;
			break;
		case 0x3A: // :
			outk=PKEY_COLON;
			break;
		case 0x3B: // ;
			outk=PKEY_SEMICOLON;
			break;
		case 0x3C: // <
			outk=PKEY_LESS_THAN;
			break;
		case 0x3D: // =
			outk=PKEY_EQUALS;
			break;
		case 0x3E: // >
			outk=PKEY_GREATER_THAN;
			break;
		case 0x3F: // ?
			outk=PKEY_QUESTION_MARK;
			break;
		case 0x40: // @
			outk=PKEY_AT;
			break;
		case 'A': // A
			outk=PKEY_A;
			break;
		case 'B': // B
			outk=PKEY_B;
			break;
		case 'C': // C
			outk=PKEY_C;
			break;
		case 'D': // D
			outk=PKEY_D;
			break;
		case 'E': // E
			outk=PKEY_E;
			break;
		case 'F': // F
			outk=PKEY_F;
			break;
		case 'G': // G
			outk=PKEY_G;
			break;
		case 'H': // H
			outk=PKEY_H;
			break;
		case 'I': // I
			outk=PKEY_I;
			break;
		case 'J': // J
			outk=PKEY_J;
			break;
		case 'K': // K
			outk=PKEY_K;
			break;
		case 'L': // L
			outk=PKEY_L;
			break;
		case 'M': // M
			outk=PKEY_M;
			break;
		case 'N': // N
			outk=PKEY_N;
			break;
		case 'O': // O
			outk=PKEY_O;
			break;
		case 'P': // P
			outk=PKEY_P;
			break;
		case 'Q': // Q
			outk=PKEY_Q;
			break;
		case 'R': // R
			outk=PKEY_R;
			break;
		case 'S': // S
			outk=PKEY_S;
			break;
		case 'T': // T
			outk=PKEY_T;
			break;
		case 'U': // U
			outk=PKEY_U;
			break;
		case 'V': // V
			outk=PKEY_V;
			break;
		case 'W': // W
			outk=PKEY_W;
			break;
		case 'X': // X
			outk=PKEY_X;
			break;
		case 'Y': // Y
			outk=PKEY_Y;
			break;
		case 'Z': // Z
			outk=PKEY_Z;
			break;
		case '[': // [
			outk=PKEY_BRACKET_LEFT;
			break;
		case 0x5C: // backslash
			outk=PKEY_BACKSLASH;
			break;
		case ']': // ]
			outk=PKEY_BRACKET_RIGHT;
			break;
		case '^': // ^
			outk=PKEY_CIRCUMFLEX;
			break;
		case '_': // _
			outk=PKEY_UNDERSCORE;
			break;
		case '`': // `
			outk=PKEY_GRAVE;
			break;
		case 'a':
			outk=PKEY_a;
			break;
		case 'b':
			outk=PKEY_b;
			break;
		case 'c':
			outk=PKEY_c;
			break;
		case 'd':
			outk=PKEY_d;
			break;
		case 'e':
			outk=PKEY_e;
			break;
		case 'f':
			outk=PKEY_f;
			break;
		case 'g':
			outk=PKEY_g;
			break;
		case 'h':
			outk=PKEY_h;
			break;
		case 'i':
			outk=PKEY_i;
			break;
		case 'j':
			outk=PKEY_j;
			break;
		case 'k':
			outk=PKEY_k;
			break;
		case 'l':
			outk=PKEY_l;
			break;
		case 'm':
			outk=PKEY_m;
			break;
		case 'n':
			outk=PKEY_n;
			break;
		case 'o':
			outk=PKEY_o;
			break;
		case 'p':
			outk=PKEY_p;
			break;
		case 'q':
			outk=PKEY_q;
			break;
		case 'r':
			outk=PKEY_r;
			break;
		case 's':
			outk=PKEY_s;
			break;
		case 't':
			outk=PKEY_t;
			break;
		case 'u':
			outk=PKEY_u;
			break;
		case 'v':
			outk=PKEY_v;
			break;
		case 'w':
			outk=PKEY_w;
			break;
		case 'x':
			outk=PKEY_x;
			break;
		case 'y':
			outk=PKEY_y;
			break;
		case 'z':
			outk=PKEY_z;
			break;
		case 0x7B:
			outk=PKEY_LEFT_CURLY_BRACE;
			break;
		case 0x7C:
			outk=PKEY_BAR;
			break;
		case 0x7D:
			outk=PKEY_RIGHT_CURLY_BRACE;
			break;
		case 0x7E:
			outk=PKEY_TILDE;
			break;
		case 0x7F:
			outk=PKEY_ERASE1;
			break;

	}

	keyboard_out(outk);
}

