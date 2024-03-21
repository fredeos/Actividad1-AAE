.POSIX:
CC = g++
CFLAGS = -W -O -std=c++11 -Wno-undefined
LIBS = -L/usr/lib -lz -lexpat -pthread -lid3 -ltk86 -ltcl86 -lcrossguid
INCS = -I/usr/include
TKINCS = -I/usr/include/tk86 -I/usr/include/tcl8.6

.ifdef OPENBSD
X11INC = -I/usr/X11R6/include
X11LIB = -L/usr/X11R6/lib -lX11 -lxcb -lXau -lXdmcp -lXft -lXss -lfontconfig -lXext -lfreetype -lXrender -lz -lexpat
.endif

main:
	${CC} ${CFLAGS} -g src/modules/**.cpp src/main.cpp -o main
	./main