LINUX_BUILD="build_linux"
WIN_BUILD="build_mingw"

all:

linux:
	mkdir -p ${LINUX_BUILD}
	gcc -c sqlite/*.c -fPIC -o ${LINUX_BUILD}/sqlite.o -lpthread -ldl
	g++ *.cpp ${LINUX_BUILD}/sqlite.o `pkg-config gtkmm-3.0 --libs --cflags` -ldl -o ${LINUX_BUILD}/DinnerPlanner

win_once:
	ldd ${WIN_BUILD}/DinnerPlanner.exe | grep '\/mingw.*\.dll' -o | xargs -I{} cp "{}" ${WIN_BUILD}/

windows:
	mkdir -p ${WIN_BUILD}
	gcc -c sqlite/*.c -fPIC -o ${WIN_BUILD}/sqlite.o -lpthread -ldl
	g++ *.cpp ${WIN_BUILD}/sqlite.o `pkg-config gtkmm-3.0 --libs --cflags` -o ${WIN_BUILD}/DinnerPlanner.exe