CC=g++
CCFLAGS=-g -W -Wall

FLEX=flex
FLEX_OPTS=-PJavalette

BISON=bison
BISON_OPTS=-t -pJavalette

OBJS=Absyn.o Lexer.o Parser.o Printer.o

.PHONY : clean distclean

all : TestJavalette

clean :
	rm -f *.o TestJavalette Javalette.aux Javalette.log Javalette.pdf Javalette.dvi Javalette.ps Javalette

distclean : clean
	rm -f Absyn.C Absyn.H Test.C Parser.C Parser.H Lexer.C Skeleton.C Skeleton.H Printer.C Printer.H Makefile Javalette.l Javalette.y Javalette.tex

TestJavalette : ${OBJS} Test.o
	@echo "Linking TestJavalette..."
	${CC} ${CCFLAGS} ${OBJS} Test.o -o TestJavalette

Absyn.o : Absyn.C Absyn.H
	${CC} ${CCFLAGS} -c Absyn.C

Lexer.C : Javalette.l
	${FLEX} -oLexer.C Javalette.l

Parser.C : Javalette.y
	${BISON} Javalette.y -o Parser.C

Lexer.o : Lexer.C Parser.H
	${CC} ${CCFLAGS} -c Lexer.C

Parser.o : Parser.C Absyn.H
	${CC} ${CCFLAGS} -c Parser.C

Printer.o : Printer.C Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Printer.C

Skeleton.o : Skeleton.C Skeleton.H Absyn.H
	${CC} ${CCFLAGS} -Wno-unused-parameter -c Skeleton.C

CodeGen.o : CodeGen.C CodeGen.H Absyn.H
	${CC} ${CCFLAGS} -Who-unused-parameter -c CodeGen.C

Test.o : Test.C Parser.H Printer.H Absyn.H 
	${CC} ${CCFLAGS} -c Test.C
