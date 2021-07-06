# platoterm-plan9

PLATOTERM is a PLATO terminal emulator that has been ported to many platforms, as part of the [IRATA.ONLINE](https://irata.online/) project.

## Features

* Native Plan 9 application.
* 24-bit color terminal support
* PLATO touch panel mapped as mouse device
* Uses the [ASCII PLATO](https://irata.online/assets/s0ascers-045c83081e9ada2008378c3ae6aa62564b213a71decf9fe04608909b91d20ad1.html) protocol

## Missing features

* The paint/fill function is currently stubbed, because it needs a flood fill function. (anyone want to help?)

## Compiling / Installation

```
% mk
% mk install
```

## Invoking platoterm

```
% platoterm -h <hostname> [-p <port>]
```

If -p is not specified, then the port is assumed to be the default ASCII port of 8005.

Upon starting, platoterm will resize the parent window to 520,520 (to accommodate the client area of 512,512), and immediately attempt the connection. 

### PLATO hosts

* [irata.online](https://irata.online/)
* [cyberserv.org](http://cyber1.org/)

## Quitting platoterm

The program stops whenever the connection is hung up, or the Quit option is selected from the right click menu.

## Touch screen

The left mouse button will 

## PLATO Keys

The PLATO keyboard has a lot of special keys. These can be accessed via the middle and right click menus:

| Right click menu keys
|---
| ANS
| BACK
| COPY
| DATA
| EDIT
| FONT
| HELP
| LAB
| MICRO
| NEXT
| □ (access)
| STOP
| SUB
| SUPER
| TERM
| ×
| ÷
| Σ
| Δ
| Quit

| Middle click menu keys
|---
| SHIFT-BACK (BACK1)
| SHIFT-COPY (COPY1)
| SHIFT-DATA (DATA1)
| SHIFT-EDIT (EDIT1)
| SHIFT-HELP (HELP1)
| SHIFT-LAB (LAB1)
| SHIFT-NEXT (NEXT1)
| SHIFT-STOP (STOP1)
| SHIFT-SUB (SUB1)
| SHIFT-SUPER (SUPER1)

## Authors

* Thomas Cherryhomes <thom.cherryhomes at gmail.com>
* Steve Peltz, who wrote the original pad.c state machine which became protocol.c in platoterm.


