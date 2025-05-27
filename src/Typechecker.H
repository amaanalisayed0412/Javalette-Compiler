#ifndef TYPECHECKER_HEADER
#define TYPECHECKER_HEADER
/* You might want to change the above name. */

#include "Absyn.H"
#include <iostream>
#include <map>

enum InferredType { TINT, TDOUBLE, TBOOL, TSTR, TVOID, TUNKNOWN };

Type* inferredtotype(InferredType type1);

int num_passes = 0;

Type* inferredtotype(InferredType type1){
  Type* t;
  if (type1 == TINT){
    t = new Int;
  }
  else if (type1 == TDOUBLE){
    t = new Doub;
  }
  else if (type1 == TSTR){
    t = new Str;
  }
  else if (type1 == TBOOL){
    t = new Bool;
  }
  else if (type1 == TVOID){
    t = new Void;
  }
  return t;
}


struct FunctionInfo {
    Type* returnType;
    std::vector<InferredType> paramTypes;
};


std::string typetostring(InferredType t){
  if (t == TINT){
    return "int";
  }
  else if (t == TDOUBLE){
    return "double";
  }
  else if (t == TBOOL){
    return "bool";
  }
  else if (t == TSTR){
    return "string";
  }
  else if (t == TVOID){
    return "void";
  }
  else {
    return "unknown";
  }
}



class TypeError : public std::runtime_error {
public:
    explicit TypeError(const std::string& msg)
        : std::runtime_error("Error: " + msg) {}
};

std::vector<std::map<std::string, InferredType>> contextStack;

std::map<std::string, FunctionInfo*> funcEnv;

std::vector<Type*> currargvec;

InferredType infer(Type *t) {
    if (dynamic_cast<Int*>(t)) return TINT;
    if (dynamic_cast<Doub*>(t)) return TDOUBLE;
    if (dynamic_cast<Bool*>(t)) return TBOOL;
    if (dynamic_cast<Str*>(t)) return TSTR;
    if (dynamic_cast<Void*>(t)) return TVOID;
    return TUNKNOWN;
}

InferredType lookupVariable(Ident var){
  for (auto it = contextStack.rbegin(); it != contextStack.rend(); ++it) {
        if (it->count(var)) {
            return it->at(var);
        }
    }
  return TUNKNOWN;
}

FunctionInfo* lookupFunc(Ident func){
  for (auto p : funcEnv){
    if (p.first == func){
      return p.second;
    }
  }
  return nullptr;
}

InferredType last_type = TUNKNOWN;
InferredType decl_type = TUNKNOWN;
InferredType ret_type = TUNKNOWN;

bool AlwaysReturns = false;
class Skeleton : public Visitor
{
public:
  void visitProg(Prog *p);
  void visitTopDef(TopDef *p);
  void visitArg(Arg *p);
  void visitBlk(Blk *p);
  void visitStmt(Stmt *p);
  void visitItem(Item *p);
  void visitType(Type *p);
  void visitExpr(Expr *p);
  void visitAddOp(AddOp *p);
  void visitMulOp(MulOp *p);
  void visitRelOp(RelOp *p);
  void visitProgram(Program *p);
  void visitFnDef(FnDef *p);
  void visitArgument(Argument *p);
  void visitBlock(Block *p);
  void visitEmpty(Empty *p);
  void visitBStmt(BStmt *p);
  void visitDecl(Decl *p);
  void visitNoInit(NoInit *p);
  void visitInit(Init *p);
  void visitAss(Ass *p);
  void visitIncr(Incr *p);
  void visitDecr(Decr *p);
  void visitRet(Ret *p);
  void visitVRet(VRet *p);
  void visitCond(Cond *p);
  void visitCondElse(CondElse *p);
  void visitWhile(While *p);
  void visitSExp(SExp *p);
  void visitInt(Int *p);
  void visitDoub(Doub *p);
  void visitBool(Bool *p);
  void visitVoid(Void *p);
  void visitStr(Str *p);
  void visitFun(Fun *p);
  void visitETypeAnn(ETypeAnn *p);
  void visitEVar(EVar *p);
  void visitELitInt(ELitInt *p);
  void visitELitDoub(ELitDoub *p);
  void visitELitTrue(ELitTrue *p);
  void visitELitFalse(ELitFalse *p);
  void visitEApp(EApp *p);
  void visitEString(EString *p);
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
  void visitListType(ListType *p);
  void visitListExpr(ListExpr *p);

  void visitInteger(Integer x);
  void visitChar(Char x);
  void visitDouble(Double x);
  void visitString(String x);
  void visitIdent(Ident x);
};


#endif
