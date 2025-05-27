CC=g++
CCFLAGS=-g -W -Wall -Isrc
SRC_DIR = src

FLEX=flex
FLEX_OPTS=-PJavalettea

BISON=bison
BISON_OPTS=-t -pJavalette

OBJS=${SRC_DIR}/Absyn.o ${SRC_DIR}/Lexer.o ${SRC_DIR}/Parser.o ${SRC_DIR}/Printer.o ${SRC_DIR}/Typechecker.o

.PHONY : clean distclean

all : jlc

clean :
	rm -f ${SRC_DIR}/*.o j ${SRC_DIR}/Javalette.aux ${SRC_DIR}/Javalette.log ${SRC_DIR}/Javalette.pdf ${SRC_DIR}/Javalette.dvi ${SRC_DIR}/Javalette.ps ${SRC_DIR}/Javalette jlc

distclean : clean
	rm -f ${SRC_DIR}/Absyn.C ${SRC_DIR}/Absyn.H ${SRC_DIR}/Test.C ${SRC_DIR}/Parser.C ${SRC_DIR}/Parser.H ${SRC_DIR}/Lexer.C ${SRC_DIR}/Typechecker.C ${SRC_DIR}/Typechecker.H ${SRC_DIR}/Printer.C ${SRC_DIR}/Printer.H Makefile ${SRC_DIR}/Javalette.l ${SRC_DIR}/Javalette.y ${SRC_DIR}/Javalette.tex

jlc : ${OBJS} ${SRC_DIR}/Test.o
	@echo "Linking jlc..."
	${CC} ${CCFLAGS} ${OBJS} ${SRC_DIR}/Test.o -o jlc

${SRC_DIR}/Absyn.o : ${SRC_DIR}/Absyn.C ${SRC_DIR}/Absyn.H
	${CC} ${CCFLAGS} -c ${SRC_DIR}/Absyn.C -o ${SRC_DIR}/Absyn.o

${SRC_DIR}/Lexer.C : ${SRC_DIR}/Javalette.l
	${FLEX} -o ${SRC_DIR}/Lexer.C ${SRC_DIR}/Javalette.l

${SRC_DIR}/Parser.C : ${SRC_DIR}/Javalette.y
	${BISON} ${SRC_DIR}/Javalette.y -o ${SRC_DIR}/Parser.C

${SRC_DIR}/Lexer.o : ${SRC_DIR}/Lexer.C ${SRC_DIR}/Parser.H
	${CC} ${CCFLAGS} -c ${SRC_DIR}/Lexer.C -o ${SRC_DIR}/Lexer.o

${SRC_DIR}/Parser.o : ${SRC_DIR}/Parser.C ${SRC_DIR}/Absyn.H
	${CC} ${CCFLAGS} -c ${SRC_DIR}/Parser.C -o ${SRC_DIR}/Parser.o

${SRC_DIR}/Printer.o : ${SRC_DIR}/Printer.C ${SRC_DIR}/Printer.H ${SRC_DIR}/Absyn.H
	${CC} ${CCFLAGS} -c ${SRC_DIR}/Printer.C -o ${SRC_DIR}/Printer.o


${SRC_DIR}/Test.o : ${SRC_DIR}/Test.C ${SRC_DIR}/Parser.H ${SRC_DIR}/Printer.H ${SRC_DIR}/Absyn.H ${SRC_DIR}/Typechecker.H
	${CC} ${CCFLAGS} -c ${SRC_DIR}/Test.C -o ${SRC_DIR}/Test.o