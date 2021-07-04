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

#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>
#include "screen.h"
#include "protocol.h"
#include "font.h"
#include "keyboard.h"
#include "touch.h"
#include "beep.h"
#include "splash.h"

unsigned char CharHigh=16;
unsigned char CharWide=8;
padPt TTYLoc;

extern int done;

unsigned char fontm23[2048];
padRGB backgroundPLATO={0,0,0};
padRGB foregroundPLATO={255,255,255};

#define TRUE 1
#define FALSE 0

short max(short a, short b) { return ( a > b ) ? a : b; }
short min(short a, short b) { return ( a < b ) ? a : b; }

extern padBool FastText;

Image *view;

unsigned long backgroundColor, foregroundColor;

void screen_setup(void)
{
	Point size = subpt(screen->r.max, screen->r.min);
	Rectangle frame = (Rectangle){Pt(0,0),size};
	
	if (view != nil)
		freeimage(view);

	view = allocimage(display,frame,screen->chan,1,backgroundColor);
}

void eresized(int new)
{
	if (new && getwindow(display, Refnone) < 0)
		sysfatal("can't reattach to window");
	screen_setup();
}

/**
 * screen_init() - Set up the screen
 */
void screen_init(void)
{
	int fd;

	backgroundColor = 0x000000FF;
	foregroundColor = 0xFFFFFFFF;

	if (initdraw(nil, nil, "platoterm") < 0)
		sysfatal("initdraw failed: %r");

	einit(Emouse|Ekeyboard);

	fd = open("/dev/wctl",OWRITE);

	if (fd >= 0)
	{
		fprint(fd,"resize -dx 520 -dy 520"); // gives 512x512 client area.
		close(fd);
	}

	eresized(0);
	ShowPLATO(splash,sizeof(splash));
	screen_update_view();
}

/**
 * screen_update_view() Update vioew
 */
void screen_update_view(void)
{
	draw(screen,screen->r,view,nil,ZP);
	flushimage(display,1);
}

/**
 * screen_main() - render/preserve screen
 */
void screen_main(void)
{
}

/**
 * screen_wait() - Sleep for approx 16.67ms
 */
void screen_wait(void)
{
}

/**
 * screen_beep() - Beep the terminal
 */
void screen_beep(void)
{
	int fd;

	fd = open("/dev/audio", OWRITE);
	if (fd >= 0)
	{
		write(fd,beep_raw,beep_raw_len);
		close(fd);
	}
}

/**
 * screen_clear - Clear the screen
 */
void screen_clear(void)
{
	Image *bkg = allocimagemix(display, backgroundColor, backgroundColor);
	draw(view,view->r,bkg,nil,ZP);
	freeimage(bkg);
}

/**
 * screen_block_draw(Coord1, Coord2) - Perform a block fill from Coord1 to Coord2
 */
void screen_block_draw(padPt *Coord1, padPt *Coord2)
{
	Rectangle r;
	Image *c;

	r.min.x = min(Coord1->x,Coord2->x);
	r.max.x = max(Coord1->x,Coord2->x);
	r.min.y = min(Coord1->y^0x1FF,Coord2->y^0x1FF);
	r.max.y = max(Coord1->y^0x1FF,Coord2->y^0x1FF);

	if (CurMode == ModeErase || CurMode == ModeInverse)
	{
		c = allocimagemix(display,backgroundColor,backgroundColor);
	}
	else
	{
		c = allocimagemix(display,foregroundColor,foregroundColor);
	}

	draw(view,r,c,nil,ZP);

	freeimage(c);
}

/**
 * screen_dot_draw(Coord) - Plot a mode 0 pixel
 */
void screen_dot_draw(padPt *Coord)
{
	Rectangle r;
	Image *c;

	r.min.x=r.max.x=Coord->x;
	r.min.y=r.max.y=Coord->y^0x1FF;
	r.max.x++;
	r.max.y++;

	if (CurMode == ModeErase || CurMode == ModeInverse)
	{
		c = allocimagemix(display,backgroundColor,backgroundColor);
	}
	else
	{	
		c = allocimagemix(display,foregroundColor,foregroundColor);
	}

	draw(view,r,c,nil,ZP);
	freeimage(c);
}

/**
 * screen_line_draw(Coord1, Coord2) - Draw a mode 1 line
 */
void screen_line_draw(padPt *Coord1, padPt *Coord2)
{
	Point beg,end;
	Image *c;

	beg.x = Coord1->x;
	end.x = Coord2->x;
	
	beg.y = Coord1->y^0x1FF;
	end.y = Coord2->y^0x1FF;

	if ((CurMode == ModeErase) || (CurMode == ModeInverse))
	{
		c = allocimagemix(display,backgroundColor,backgroundColor);
	}
	else
	{
		c = allocimagemix(display,backgroundColor,foregroundColor);
	}

	line(view,beg,end,Endsquare,Endsquare,0,c,ZP);

	freeimage(c);
}

/**
 * screen_char_draw(Coord, ch, count) - Output buffer from ch* of length count as PLATO characters
 */
void screen_char_draw(padPt *Coord, unsigned char *ch, unsigned char count)
{
  short offset; /* due to negative offsets */
  unsigned short x;      /* Current X and Y coordinates */
  unsigned short y;
  unsigned short* px;   /* Pointers to X and Y coordinates used for actual plotting */
  unsigned short* py;
  unsigned char i; /* current character counter */
  unsigned char a; /* current character byte */
  unsigned char j,k; /* loop counters */
  char b; /* current character row bit signed */
  char width=8;
  char height=16;
  short deltaX=1;
  short deltaY=1;
  unsigned char *p;
  unsigned char* curfont;
  Image *mainColor;
  Image *altColor;

	curfont = plato_font;
	offset = 0;

  if (CurMode==ModeInverse)
    {
		altColor = allocimagemix(display,foregroundColor,foregroundColor);
    }
  else
	{
		altColor = allocimagemix(display,backgroundColor,backgroundColor);
	}

  if (CurMode==ModeErase || CurMode==ModeInverse)
    {
		mainColor = allocimagemix(display,backgroundColor,backgroundColor);
    }
  else
    {
		mainColor = allocimagemix(display,foregroundColor,foregroundColor);
	}

  switch(CurMem)
    {
    case M0:
      curfont=plato_font;
      offset=-32;
      break;
    case M1:
      curfont=plato_font;
      offset=64;
      break;
    case M2:
      curfont=fontm23;
      offset=-32;
      break;
    case M3:
      curfont=fontm23;
      offset=32;
      break;
    }

  x=Coord->x;

  if (ModeBold)
    y=((Coord->y+30)^0x1FF)&0x1FF;
  else
    y=((Coord->y+15)^0x1FF)&0x1FF;

  if (FastText==padF)
    {
      goto chardraw_with_fries;
    }

  px=&x;
  py=&y;

	USED(px);
	USED(py);

  /* the diet chardraw routine - fast text output. */

  for (i=0;i<count;++i)
    {
      a=*ch;
      ++ch;
      a+=offset;
      p=&curfont[FONTPTR(a)];

      for (j=0;j<16;++j)
        {
          b=*p;

          for (k=0;k<8;++k)
            {
              if (b&0x80) /* check sign bit. */
				draw(view,Rect(x,y,x+1,y+1),mainColor,nil,ZP);

              ++x;
              b<<=1;
            }

          ++y;
          x-=width;
          ++p;
        }

      x+=width;
      y-=height;
    }

  return;

 chardraw_with_fries:
  if (Rotate)
    {
      deltaX=-abs(deltaX);
      width=-abs(width);
      px=&y;
      py=&x;
	  USED(px);
	  USED(py);
    }

  if (ModeBold)
    {
      deltaX = deltaY = 2;
      width<<=1;
      height<<=1;
    }

  for (i=0;i<count;++i)
    {
      a=*ch;
      ++ch;
      a+=offset;
      p=&curfont[FONTPTR(a)];
      for (j=0;j<16;++j)
        {
          b=*p;

			px=&x;
			py=&y;

          if (Rotate)
            {
              px=&y;
              py=&x;
            }

          for (k=0;k<8;++k)
            {
              if (b&0x80) /* check sign bit. */
                {
                  if (ModeBold)
                    {
						draw(view,Rect((*px)+1,*py,(*px)+2,(*py)+1),mainColor,nil,ZP);
						draw(view,Rect((*px),(*py)+1,(*px)+1,(*py)+2),mainColor,nil,ZP);
						draw(view,Rect((*px)+1,(*py)+1,(*px)+2,(*py)+2),mainColor,nil,ZP);		
                    }
					draw(view,Rect((*px),(*py),(*px)+1,(*py)+1),mainColor,nil,ZP);
                }
              else
                {
                  if (CurMode==ModeInverse || CurMode==ModeRewrite)
                    {
                      if (ModeBold)
                        {
 							draw(view,Rect((*px)+1,(*py),(*px)+2,(*py)+1),altColor,nil,ZP);
							draw(view,Rect((*px),(*py)+1,(*px)+1,(*py)+2),altColor,nil,ZP);
							draw(view,Rect((*px)+1,(*py)+1,(*px)+2,(*py)+2),altColor,nil,ZP);	
                        }
						draw(view,Rect((*px),(*py),(*px)+1,(*py)+1),altColor,nil,ZP);
                    }
                }

              x += deltaX;
              b<<=1;
            }

          y+=deltaY;
          x-=width;
          ++p;
        }

      Coord->x+=width;
      x+=width;
      y-=height;
    }

	freeimage(mainColor);
	freeimage(altColor);
	
  return;
}

/**
 * screen_tty_char - Called to plot chars when in tty mode
 */
void screen_tty_char(padByte theChar)
{
  if ((theChar >= 0x20) && (theChar < 0x7F)) {
    screen_char_draw(&TTYLoc, &theChar, 1);
    TTYLoc.x += CharWide;
  }  
  else if (theChar == 0x0b) /* Vertical Tab */
    {
      TTYLoc.y += CharHigh;
    }
  else if ((theChar == 0x08) && (TTYLoc.x > 7))/* backspace */
    {
      TTYLoc.x -= CharWide;
    }
  else if (theChar == 0x0A)/* line feed */
    TTYLoc.y -= CharHigh;
  else if (theChar == 0x0D)/* carriage return */
    TTYLoc.x = 0;
     
  if (TTYLoc.x + CharWide > 511) {/* wrap at right side */
    TTYLoc.x = 0;
    TTYLoc.y -= CharHigh;
  }  
     
  if (TTYLoc.y < 0) {
    TTYLoc.y=495;
  }
}

/**
 * screen_foreground - Called to set foreground color.
 */
void screen_foreground(padRGB* theColor)
{
	foregroundColor = ((theColor->red & 0xff) << 24) + ((theColor->green & 0xff) << 16) + ((theColor->blue & 0xff) << 8) + 0xFF;
}

/**
 * screen_background - Called to set foreground color.
 */
void screen_background(padRGB* theColor)
{
	backgroundColor = ((theColor->red & 0xff) << 24) + ((theColor->green & 0xff) << 16) + ((theColor->blue & 0xff) << 8) + 0xFF;
}

/**
 * screen_get_pixel - Get pixel from view.
 * This routine assumes an image type of RGB24. The alpha channel doesn't get stored,
 * but is premultiplied in the color components. Since PLATOTERM does not use any alpha except 0xFF,
 * we can simply shift everything over by 8, and OR in the alpha value of 0xFF, so that colors will match.
 */
unsigned long screen_get_pixel(int x, int y)
{
    /* Union to make manipulation easier. */
	union
	{
		unsigned char data[4];
		unsigned long color;
	} _px;

	/* Retrieve color data for single pixel from image */
	unloadimage(view,Rect(x,y,x+1,y+1),_px.data,sizeof(_px.data));

    /* correct for missing alpha value. */
	_px.color <<= 8;
	_px.color |= 0xFF;

	return _px.color;
}

/**
 * Recursive flood fill
 */
void _screen_paint(int x,int y,unsigned long oldpixel,unsigned long newpixel)
{
        unsigned long p = screen_get_pixel(x,y);
		Image* c = allocimagemix(display, newpixel, newpixel);
		Rectangle r;

		r.min.x=r.max.x=x;
		r.min.y=r.max.y=y;
		r.max.x++;
		r.max.y++;

        if (p != oldpixel)
                return;
        if (p == newpixel)
                return;
        if (p == oldpixel)
			draw(view,r,c,nil,ZP);

		freeimage(c);
		screen_update_view();

        _screen_paint(x-1,y,oldpixel,newpixel);
        _screen_paint(x+1,y,oldpixel,newpixel);
        _screen_paint(x,y-1,oldpixel,newpixel);
        _screen_paint(x,y+1,oldpixel,newpixel);
}

void screen_paint(padPt *Coord)
{
        int x = Coord->x;
        int y = Coord->y^0x1FF;
        unsigned long oldpixel;

		USED(x,y,oldpixel);
        /* oldpixel = screen_get_pixel(x,y);
        _screen_paint(x,y,oldpixel,foregroundColor); */
}

/**
 * screen_done()
 * Close down TGI
 */
void screen_done(void)
{
	if (view != nil)
		freeimage(view);

	closedisplay(display);
}
