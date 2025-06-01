CC=g++
CCFLAGS=-g -W -Wall -Isrc
SRC_DIR = src
BNFC = bnfc
BNFC_GRAMMAR = ${SRC_DIR}/Javalette.cf

FLEX=flex
FLEX_OPTS=-PJavalettea

BISON=bison
BISON_OPTS=-t -pJavalette

OBJS=${SRC_DIR}/Absyn.o ${SRC_DIR}/Lexer.o ${SRC_DIR}/Parser.o ${SRC_DIR}/Printer.o ${SRC_DIR}/Typechecker.o ${SRC_DIR}/CodeGen.o

.PHONY : generate_bnfc clean

all : generate_bnfc jlc

clean :
	rm -f ${SRC_DIR}/*.o j ${SRC_DIR}/Javalette.aux ${SRC_DIR}/Javalette.log ${SRC_DIR}/Javalette.pdf ${SRC_DIR}/Javalette.dvi ${SRC_DIR}/Javalette.ps ${SRC_DIR}/Javalette jlc
	rm -f ${SRC_DIR}/Absyn.C ${SRC_DIR}/Absyn.H ${SRC_DIR}/Test.C ${SRC_DIR}/Parser.C ${SRC_DIR}/Parser.H ${SRC_DIR}/Lexer.C ${SRC_DIR}/Printer.C ${SRC_DIR}/Printer.H ${SRC_DIR}/Javalette.l ${SRC_DIR}/Javalette.y ${SRC_DIR}/Javalette.tex
	

generate_bnfc:
	@echo "Generating BNFC files..."
	${BNFC} -cpp -o ${SRC_DIR} ${BNFC_GRAMMAR}
	@echo "BNFC files generated."

jlc : ${OBJS} ${SRC_DIR}/Main.o
	@echo "Linking jlc..."
	${CC} ${CCFLAGS} ${OBJS} ${SRC_DIR}/Main.o -o jlc

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


${SRC_DIR}/Main.o : ${SRC_DIR}/Main.C ${SRC_DIR}/Parser.H ${SRC_DIR}/Printer.H ${SRC_DIR}/Absyn.H ${SRC_DIR}/Typechecker.H ${SRC_DIR}/CodeGen.H
	${CC} ${CCFLAGS} -c ${SRC_DIR}/Main.C -o ${SRC_DIR}/Main.o