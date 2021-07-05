< /$objtype/mkfile

TARG=platoterm
OFILES=\
	io.$O \
	keyboard.$O \
	menu.$O \
	platoterm.$O \
	protocol.$O \
	screen.$O \
	terminal.$O \
	touch.$O

HFILES=\
	font.h \
	io.h \
	key.h \
	keyboard.h \
	menu.h \
	plato_key.h \
	protocol.h \
	screen.h \
	splash.h \
	terminal.h \
	touch.h

BIN=/$objtype/bin
</sys/src/cmd/mkone

run: 
	cp $O.out /$cputype/platoterm
	platoterm
