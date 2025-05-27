/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Typechecker.H"

void Skeleton::visitProg(Prog *t) {} //abstract class
void Skeleton::visitTopDef(TopDef *t) {} //abstract class
void Skeleton::visitArg(Arg *t) {} //abstract class
void Skeleton::visitBlk(Blk *t) {} //abstract class
void Skeleton::visitStmt(Stmt *t) {} //abstract class
void Skeleton::visitItem(Item *t) {} //abstract class
void Skeleton::visitType(Type *t) {} //abstract class
void Skeleton::visitExpr(Expr *t) {} //abstract class
void Skeleton::visitAddOp(AddOp *t) {} //abstract class
void Skeleton::visitMulOp(MulOp *t) {} //abstract class
void Skeleton::visitRelOp(RelOp *t) {} //abstract class

void checkMainExists(){
  auto it = funcEnv.find("main");
  if (it == funcEnv.end()){
    throw TypeError("Main function missing");
  }
  else if (infer((*it).second->returnType) != TINT || !(*it).second->paramTypes.empty()){
    throw TypeError("Main function should be of the type int main().");
  }
  else{
    return;
  }
}

void Skeleton::visitProgram(Program *program)
{
  /* Code For Program Goes Here */
  FunctionInfo* f = new FunctionInfo();
  f->returnType = new Void;
  f->paramTypes.push_back(TINT);
  funcEnv["printInt"] = f;

  FunctionInfo* f1 = new FunctionInfo();
  f1->returnType = new Void;
  f1->paramTypes.push_back(TDOUBLE);
  funcEnv["printDouble"] = f1;

  FunctionInfo* f2 = new FunctionInfo();
  f2->returnType = new Void;
  f2->paramTypes.push_back(TSTR);
  funcEnv["printString"] = f2;

  FunctionInfo* f3 = new FunctionInfo();
  f3->returnType = new Int;
  funcEnv["readInt"] = f3;

  FunctionInfo* f4 = new FunctionInfo();
  f4->returnType = new Doub;
  funcEnv["readDouble"] = f4;
  
  program->listtopdef_->accept(this);

  checkMainExists();
  num_passes += 1;
  program->listtopdef_->accept(this);
  num_passes += 1;
  program->listtopdef_->accept(this);
}

void Skeleton::visitFnDef(FnDef *fn_def)
{
  if (num_passes == 0){
    if (lookupFunc(fn_def->ident_) != nullptr){
      throw TypeError(fn_def->ident_ + ": Duplicate function names.");
      return;
    }
    else{
      FunctionInfo* f = new FunctionInfo();
      f->returnType = fn_def->type_;
      fn_def->listarg_->accept(this);
      for (auto p: currargvec){
        (f->paramTypes).push_back(infer(p));
      }
      for (auto p: currargvec){

        delete p;
      }
      currargvec.clear();
      funcEnv[fn_def->ident_] = f; 
    }
    
  }
  /* Code For FnDef Goes Here */
  else if (num_passes == 1){
    ret_type = infer(fn_def->type_);
    contextStack.push_back({});

    fn_def->type_->accept(this);
    visitIdent(fn_def->ident_);
    fn_def->listarg_->accept(this);
    fn_def->blk_->accept(this);

    contextStack.pop_back();
  }
  else{
    ret_type = infer(fn_def->type_);
    if (ret_type != TVOID){
      fn_def->blk_->accept(this);
    }

    if (AlwaysReturns == false){
      throw TypeError(fn_def->ident_ + " may not return a value on all paths.");
    }
    AlwaysReturns = false;
  }
}

void Skeleton::visitArgument(Argument *argument)
{
  /* Code For Argument Goes Here */
  if (num_passes == 0){
    last_type = infer(argument -> type_);
  }
  else if (num_passes == 1){
  argument->type_->accept(this);
  visitIdent(argument->ident_);

  contextStack.back()[argument->ident_] = infer(argument->type_);
  }
  else{

  }
}

void Skeleton::visitBlock(Block *block)
{
  /* Code For Block Goes Here */

  block->liststmt_->accept(this);

}

void Skeleton::visitEmpty(Empty *empty)
{
  /* Code For Empty Goes Here */


}

void Skeleton::visitBStmt(BStmt *b_stmt)
{
  /* Code For BStmt Goes Here */

  b_stmt->blk_->accept(this);

}

void Skeleton::visitDecl(Decl *decl)
{
  /* Code For Decl Goes Here */
  if (num_passes == 1){
    decl->type_->accept(this);
    decl_type = infer(decl->type_);
    decl->listitem_->accept(this);
  }
}

void Skeleton::visitAss(Ass *ass)
{
  /* Code For Ass Goes Here */
  if (num_passes == 1){
    visitIdent(ass->ident_);
    InferredType type1 = last_type;
    ass->expr_->accept(this);
    InferredType type2 = last_type;

    if (type1 == TUNKNOWN){
      throw TypeError("Undeclared variable used: " + ass->ident_);
    }
    if (type1 != type2){
      throw TypeError("Incorrect literal type assigned to " + ass->ident_);

    }
  
    ass->expr_ = new ETypeAnn(ass->expr_, inferredtotype(type1));
  }
  
}

void Skeleton::visitIncr(Incr *incr)
{
  /* Code For Incr Goes Here */
  if (num_passes == 1){
    visitIdent(incr->ident_);
    if (last_type != TINT){
      throw TypeError("Wrong variable type used with the increment (++) operator.");
    }
  }
  
}

void Skeleton::visitDecr(Decr *decr)
{
  /* Code For Decr Goes Here */
  if (num_passes == 1){
    visitIdent(decr->ident_);
    if (last_type != TINT){
      throw TypeError("Wrong variable type used with the decrement (--) operator.");
    }
  }
  
}

void Skeleton::visitRet(Ret *ret)
{
  /* Code For Ret Goes Here */
  if (num_passes == 1){
    ret->expr_->accept(this);
    if (last_type != ret_type){
      throw TypeError("Wrong expression type returned by function.");
    }
    ret->expr_ = new ETypeAnn(ret->expr_, inferredtotype(last_type));
  }
  else if (num_passes == 2){
    AlwaysReturns = true;
  }
}

void Skeleton::visitVRet(VRet *v_ret)
{
  /* Code For VRet Goes Here */
  if (ret_type != TVOID){
    throw TypeError("Expected an expression of type " + typetostring(ret_type) + "to be returned.");
  }

}

void Skeleton::visitCond(Cond *cond)
{
  /* Code For Cond Goes Here */
  if (num_passes == 1){
    cond->expr_->accept(this);
    if (last_type != TBOOL){
      throw TypeError("Boolean expression expected in if condition.");
    }
    cond->expr_ = new ETypeAnn(cond->expr_, new Bool);
    cond->stmt_->accept(this);
  }
  else if (num_passes == 2){
    cond->stmt_->accept(this);
  }
}

void Skeleton::visitCondElse(CondElse *cond_else)
{
  /* Code For CondElse Goes Here */
  if (num_passes == 1){
    cond_else->expr_->accept(this);
    if (last_type != TBOOL){
      throw TypeError("Boolean expression expected in if-else condition.");
    }
    cond_else->expr_ = new ETypeAnn(cond_else->expr_, new Bool);
    cond_else->stmt_1->accept(this);
    cond_else->stmt_2->accept(this);
  }
  else if (num_passes == 2){
    if (AlwaysReturns != true){
      cond_else->stmt_1->accept(this);
      if (AlwaysReturns == true){
        AlwaysReturns = false;
        cond_else->stmt_2->accept(this);
      }
    }
  }
}

void Skeleton::visitWhile(While *while_)
{
  /* Code For While Goes Here */
  if (num_passes == 1){
    while_->expr_->accept(this);
    if (last_type != TBOOL){
      throw TypeError("Boolean expression expected in if condition.");
    }
    while_->expr_ = new ETypeAnn(while_->expr_, new Bool);
    while_->stmt_->accept(this);
  }
  else if (num_passes == 2){
    while_->stmt_->accept(this);
  }
}

void Skeleton::visitSExp(SExp *s_exp)
{
  /* Code For SExp Goes Here */

  s_exp->expr_->accept(this);
  s_exp->expr_ = new ETypeAnn(s_exp->expr_, inferredtotype(last_type));
}

void Skeleton::visitNoInit(NoInit *no_init)
{
  /* Code For NoInit Goes Here */
  if (num_passes == 1){
    visitIdent(no_init->ident_);
    contextStack.back()[no_init->ident_] = decl_type;

  }
  
}

void Skeleton::visitInit(Init *init)
{
  /* Code For Init Goes Here */
  if (num_passes == 1){
    visitIdent(init->ident_);
    init->expr_->accept(this);
    if (last_type != decl_type){
      throw TypeError("Wrong literal type initialised.");
    }
    else{
      init->expr_ = new ETypeAnn(init->expr_, inferredtotype(last_type));
    }
    contextStack.back()[init->ident_] = last_type;

  }
  
}

void Skeleton::visitInt(Int *int_)
{
  /* Code For Int Goes Here */

  last_type = TINT;
}

void Skeleton::visitDoub(Doub *doub)
{
  /* Code For Doub Goes Here */

  last_type = TDOUBLE;
}

void Skeleton::visitBool(Bool *bool_)
{
  /* Code For Bool Goes Here */

  last_type = TBOOL;
}

void Skeleton::visitVoid(Void *void_)
{
  /* Code For Void Goes Here */
  last_type = TVOID;

}

void Skeleton::visitStr(Str *str)
{
  /* Code For Str Goes Here */

  last_type = TSTR;
}

void Skeleton::visitFun(Fun *fun)
{
  /* Code For Fun Goes Here */

  fun->type_->accept(this);
  fun->listtype_->accept(this);

}

void Skeleton::visitETypeAnn(ETypeAnn *e_type_ann)
{
  /* Code For ETypeAnn Goes Here */

  e_type_ann->expr_->accept(this);
  e_type_ann->type_->accept(this);
  last_type = infer(e_type_ann->type_);

}

void Skeleton::visitEVar(EVar *e_var)
{
  /* Code For EVar Goes Here */
  if (num_passes == 1){
    visitIdent(e_var->ident_);
    if (last_type == TUNKNOWN){
      throw TypeError("Undeclared variable: "+ e_var->ident_);
    }
  }
  
}

void Skeleton::visitELitInt(ELitInt *e_lit_int)
{
  /* Code For ELitInt Goes Here */

  visitInteger(e_lit_int->integer_);

}

void Skeleton::visitELitDoub(ELitDoub *e_lit_doub)
{
  /* Code For ELitDoub Goes Here */

  visitDouble(e_lit_doub->double_);

}

void Skeleton::visitELitTrue(ELitTrue *e_lit_true)
{
  /* Code For ELitTrue Goes Here */
  last_type = TBOOL;

}

void Skeleton::visitELitFalse(ELitFalse *e_lit_false)
{
  /* Code For ELitFalse Goes Here */

  last_type = TBOOL;
}

void Skeleton::visitEApp(EApp *e_app)
{
  /* Code For EApp Goes Here */
  if (num_passes == 1){
    visitIdent(e_app->ident_);
    if (lookupFunc(e_app->ident_) == nullptr){
      throw TypeError(e_app->ident_ + ": Invoked function has not been defined.");
    }
    e_app->listexpr_->accept(this);
    FunctionInfo* res = lookupFunc(e_app->ident_);
    if ((res->paramTypes).size() != currargvec.size()){
      throw TypeError("Function call to " + e_app->ident_ + " does not match the definition (insufficient arguments).");
    }

    for (size_t i = 0; i < res->paramTypes.size(); ++i) {
      if (!(infer(currargvec[i]) == res->paramTypes[i])) {
        throw TypeError("Function " + e_app->ident_ + ": Argument " + std::to_string(i + 1) +
                        " has incorrect type.");
      }
    }

    for (auto p: currargvec){
      delete p;
    }
    currargvec.clear();

    last_type = infer(res->returnType);
  }
}

void Skeleton::visitEString(EString *e_string)
{
  /* Code For EString Goes Here */

  visitString(e_string->string_);

}

void Skeleton::visitNeg(Neg *neg)
{
  /* Code For Neg Goes Here */

  neg->expr_->accept(this);

}

void Skeleton::visitNot(Not *not_)
{
  /* Code For Not Goes Here */

  not_->expr_->accept(this);

}

void Skeleton::visitEMul(EMul *e_mul)
{
  /* Code For EMul Goes Here */
  if (num_passes == 1){
    e_mul->expr_1->accept(this);
    InferredType type1 = last_type;
    e_mul->mulop_->accept(this);
    e_mul->expr_2->accept(this);
    InferredType type2 = last_type;
    if (((type1 != TINT) && (type2 != TINT)) || ((type1 != TDOUBLE) && (type2 != TDOUBLE))) {
      throw TypeError("Incorrect operand type for multiplication");
    }
    Type *t;
    t = inferredtotype(type1);
    e_mul->expr_1 = new ETypeAnn(e_mul->expr_1, t);
    e_mul->expr_2 = new ETypeAnn(e_mul->expr_2, t);
    last_type = type1;
  }
  

}

void Skeleton::visitEAdd(EAdd *e_add)
{
  /* Code For EAdd Goes Here */
  if (num_passes == 1){
    e_add->expr_1->accept(this);
    InferredType type1 = last_type;
    e_add->addop_->accept(this);
    e_add->expr_2->accept(this);
    InferredType type2 = last_type;
    if (((type1 != TINT) || (type2 != TINT)) && ((type1 != TDOUBLE) || (type2 != TDOUBLE))) {
      throw TypeError("Incorrect operand type for addition");
      
    }
    Type *t = inferredtotype(type1);
    e_add->expr_1 = new ETypeAnn(e_add->expr_1, t);
    e_add->expr_2 = new ETypeAnn(e_add->expr_2, t);
    last_type = type1;
  }
  
}

void Skeleton::visitERel(ERel *e_rel)
{
  /* Code For ERel Goes Here */
  if (num_passes == 1){
    e_rel->expr_1->accept(this);
    InferredType type1 = last_type;
    e_rel->relop_->accept(this);
    e_rel->expr_2->accept(this);
    InferredType type2 = last_type;
    if (type1 != type2){
      throw TypeError("Incorrect operand type for ERel");
      
    }
    e_rel-> expr_1 = new ETypeAnn(e_rel->expr_1, inferredtotype(type1));
    e_rel-> expr_2 = new ETypeAnn(e_rel->expr_2, inferredtotype(type2));
    last_type = TBOOL;
  }


}

void Skeleton::visitEAnd(EAnd *e_and)
{
  /* Code For EAnd Goes Here */

  if (num_passes == 1){
    e_and->expr_1->accept(this);
    InferredType type1 = last_type;
    e_and->expr_2->accept(this);
    InferredType type2 = last_type;
    if (((type1 != TBOOL) || (type2 != TBOOL))) {
      throw TypeError("Incorrect operand type for && operator.");
      
    }
    Type *t = inferredtotype(type1);
    e_and->expr_1 = new ETypeAnn(e_and->expr_1, t);
    e_and->expr_2 = new ETypeAnn(e_and->expr_2, t);
    last_type = TBOOL;
  }

}

void Skeleton::visitEOr(EOr *e_or)
{
  /* Code For EOr Goes Here */

  if (num_passes == 1){
    e_or->expr_1->accept(this);
    InferredType type1 = last_type;
    e_or->expr_2->accept(this);
    InferredType type2 = last_type;
    if (((type1 != TBOOL) || (type2 != TBOOL))) {
      throw TypeError("Incorrect operand type for && operator.");
      
    }
    Type *t = inferredtotype(type1);
    e_or->expr_1 = new ETypeAnn(e_or->expr_1, t);
    e_or->expr_2 = new ETypeAnn(e_or->expr_2, t);
    last_type = TBOOL;
  }

}

void Skeleton::visitPlus(Plus *plus)
{
  /* Code For Plus Goes Here */


}

void Skeleton::visitMinus(Minus *minus)
{
  /* Code For Minus Goes Here */


}

void Skeleton::visitTimes(Times *times)
{
  /* Code For Times Goes Here */


}

void Skeleton::visitDiv(Div *div)
{
  /* Code For Div Goes Here */


}

void Skeleton::visitMod(Mod *mod)
{
  /* Code For Mod Goes Here */


}

void Skeleton::visitLTH(LTH *lth)
{
  /* Code For LTH Goes Here */


}

void Skeleton::visitLE(LE *le)
{
  /* Code For LE Goes Here */


}

void Skeleton::visitGTH(GTH *gth)
{
  /* Code For GTH Goes Here */


}

void Skeleton::visitGE(GE *ge)
{
  /* Code For GE Goes Here */


}

void Skeleton::visitEQU(EQU *equ)
{
  /* Code For EQU Goes Here */


}

void Skeleton::visitNE(NE *ne)
{
  /* Code For NE Goes Here */


}


void Skeleton::visitListTopDef(ListTopDef *list_top_def)
{
  for (ListTopDef::iterator i = list_top_def->begin() ; i != list_top_def->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListArg(ListArg *list_arg)
{
  if (num_passes == 0){
    for (ListArg::iterator i = list_arg->begin() ; i != list_arg->end() ; ++i)
    {
      (*i)->accept(this);
      currargvec.push_back(inferredtotype(last_type));
    }

  }
  else if (num_passes == 1){
    for (ListArg::iterator i = list_arg->begin() ; i != list_arg->end() ; ++i)
    {
      (*i)->accept(this);
    }
  }
  
}

void Skeleton::visitListStmt(ListStmt *list_stmt)
{
  if (num_passes == 0){
    for (ListStmt::iterator i = list_stmt->begin() ; i != list_stmt->end() ; ++i)
    {
      
      (*i)->accept(this);
    }
  }
  else if (num_passes == 1){
    for (ListStmt::iterator i = list_stmt->begin() ; i != list_stmt->end() ; ++i)
    {
      (*i)->accept(this);
    }
  }
  else{
    for (ListStmt::iterator i = list_stmt->begin() ; i != list_stmt->end() ; ++i)
    {
      (*i)->accept(this);
    }
  }
}

void Skeleton::visitListItem(ListItem *list_item)
{
  for (ListItem::iterator i = list_item->begin() ; i != list_item->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListType(ListType *list_type)
{
  for (ListType::iterator i = list_type->begin() ; i != list_type->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListExpr(ListExpr *list_expr)
{
  if (num_passes == 1){
    for (ListExpr::iterator i = list_expr->begin() ; i != list_expr->end() ; ++i)
    {
      (*i)->accept(this);
      (*i) = new ETypeAnn((*i), inferredtotype(last_type));
      currargvec.push_back(inferredtotype(last_type));
    }
  }
  
}


void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
  last_type = TINT;
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */

}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
  last_type = TDOUBLE;
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
  last_type = TSTR;
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
  last_type = lookupVariable(x);
}



