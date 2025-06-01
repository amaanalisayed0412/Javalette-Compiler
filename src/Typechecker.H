#ifndef TYPECHECKER_HEADER
#define TYPECHECKER_HEADER
/* You might want to change the above name. */

#include "Absyn.H"
#include <iostream>
#include <map>
#include <set>


class Skeleton : public Visitor
{
public:
  void visitProg(Prog *p);
  void visitTopDef(TopDef *p);
  void visitArg(Arg *p);
  void visitBlk(Blk *p);
  void visitStmt(Stmt *p);
  void visitStructItem(StructItem *p);
  void visitItem(Item *p);
  void visitType(Type *p);
  void visitExpr(Expr *p);
  void visitAddOp(AddOp *p);
  void visitMulOp(MulOp *p);
  void visitRelOp(RelOp *p);
  void visitProgram(Program *p);
  void visitStructDef(StructDef *p);
  void visitPtrDef(PtrDef *p);
  void visitFnDef(FnDef *p);
  void visitFnDef1(FnDef1 *p);
  void visitArgument(Argument *p);
  void visitArgument1(Argument1 *p);
  void visitBlock(Block *p);
  void visitEmpty(Empty *p);
  void visitBStmt(BStmt *p);
  void visitDecl(Decl *p);
  void visitDecl1(Decl1 *p);
  void visitStructItemT(StructItemT *p);
  void visitStructItemP(StructItemP *p);
  void visitNoInit(NoInit *p);
  void visitInit(Init *p);
  void visitAss1(Ass1 *p);
  void visitIncr1(Incr1 *p);
  void visitDecr1(Decr1 *p);
  void visitRet(Ret *p);
  void visitVRet(VRet *p);
  void visitCond(Cond *p);
  void visitCondElse(CondElse *p);
  void visitWhile(While *p);
  void visitFor(For *p);
  void visitSExp(SExp *p);
  void visitPtr(Ptr *p);
  void visitInt(Int *p);
  void visitDoub(Doub *p);
  void visitBool(Bool *p);
  void visitVoid(Void *p);
  void visitStr(Str *p);
  void visitArray(Array *p);
  void visitFun(Fun *p);
  void visitETypeAnn(ETypeAnn *p);
  void visitELen(ELen *p);
  void visitEVar(EVar *p);
  void visitELitInt(ELitInt *p);
  void visitELitDoub(ELitDoub *p);
  void visitELitTrue(ELitTrue *p);
  void visitELitFalse(ELitFalse *p);
  void visitEApp(EApp *p);
  void visitEString(EString *p);
  void visitENewArr(ENewArr *p);
  void visitENewStruct(ENewStruct *p);
  void visitENullPtr(ENullPtr *p);
  void visitEDeref(EDeref *p);
  void visitEIndex(EIndex *p);
  void visitNeg(Neg *p);
  void visitNot(Not *p);
  void visitEMul(EMul *p);
  void visitEAdd(EAdd *p);
  void visitERel(ERel *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitPlus(Plus *p);
  void visitMinus(Minus *p);
  void visitTimes(Times *p);
  void visitDiv(Div *p);
  void visitMod(Mod *p);
  void visitLTH(LTH *p);
  void visitLE(LE *p);
  void visitGTH(GTH *p);
  void visitGE(GE *p);
  void visitEQU(EQU *p);
  void visitNE(NE *p);
  void visitListTopDef(ListTopDef *p);
  void visitListArg(ListArg *p);
  void visitListStmt(ListStmt *p);
  void visitListItem(ListItem *p);
  void visitListStructItem(ListStructItem *p);
  void visitListType(ListType *p);
  void visitListExpr(ListExpr *p);

  void visitInteger(Integer x);
  void visitChar(Char x);
  void visitDouble(Double x);
  void visitString(String x);
  void visitIdent(Ident x);
};


#endif
