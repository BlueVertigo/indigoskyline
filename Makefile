# Unix makefile for Unix-like operating systems like GNU/Linux
# original by hjri
# rewrite by me, lolwellun the teapot
NAME=TSP-Git
SRC=pk3/acs
OBJ=pk3/acs
.PHONY: help pk3 pk7 clean

help:
	@echo "Available options:"
	@echo "  help    - prints this dialog and exits"
	@echo "  pk3     - builds a pk3 archive of the target sources"
	@echo "  pk7     - builds a pk7 archive of the target sources"
	@echo "  clean   - removes archives"

pk3:
	@echo -n "Building ${NAME}.pk3 ......"
	@cd "tsp pk3" && 7z a -tzip ../${NAME}.pk3 *
	@echo "done"

pk7:
	@echo -n "Building ${NAME}.pk7 ......"
	@cd "tsp pk3" && 7z a ../${NAME}.pk7 *
	@echo "done"

clean:
	@echo -n "Removing archives....."
	@rm -f ${NAME}.pk7 ${NAME}.pk3
	@echo "done"
