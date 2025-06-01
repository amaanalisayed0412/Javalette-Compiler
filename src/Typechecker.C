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
void Skeleton::visitStructItem(StructItem *t) {} //abstract class
void Skeleton::visitItem(Item *t) {} //abstract class
void Skeleton::visitType(Type *t) {} //abstract class
void Skeleton::visitExpr(Expr *t) {} //abstract class
void Skeleton::visitAddOp(AddOp *t) {} //abstract class
void Skeleton::visitMulOp(MulOp *t) {} //abstract class
void Skeleton::visitRelOp(RelOp *t) {} //abstract class


enum InferredType { TINT, TDOUBLE, TBOOL, TSTR, TVOID, TINTA, TDOUBLEA, TBOOLA, TPTR, TUNKNOWN };


std::string last_type1 = "";


int num_passes = 0;

Type* inferredtotype(std::string type1){
  Type* t;
  if (type1 == "int"){
    t = new Int;
  }
  else if (type1 == "double"){
    t = new Doub;
  }
  else if (type1 == "str"){
    t = new Str;
  }
  else if (type1 == "bool"){
    t = new Bool;
  }
  else if (type1 == "void"){
    t = new Void;
  }
  else if (type1 == "inta"){
    t = new Array(new Int);
  }
  else if (type1 == "doublea"){
    t = new Array(new Doub);
  }
  else if (type1 == "boola"){
    t = new Array(new Bool);
  }
  else if (type1 == "void"){
    t = new Void;
  }
  else if (type1 != "unknown"){
    t = new Ptr(type1); //default type
  }
  return t;
}


struct FunctionInfo {
    Type* returnType;
    std::vector<std::string> paramTypes;
};

struct StructInfo {
    std::string name;
    std::map <std::string, std::string> memb; 
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
  else if (t == TINTA){
    return "int[]";
  }
  else if (t == TDOUBLEA){
    return "double[]";
  }
  else if (t == TBOOLA){
    return "bool[]";
  }
  else if (t == TPTR)
  {
    return "ptr";
  }
  
  else if (t == TUNKNOWN){
    return "unknown";
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

std::vector<std::map<std::string, std::string>> contextStack;

std::map<std::string, FunctionInfo*> funcEnv;

std::map<std::string, StructInfo*> structEnv;

std::map<std::string, std::string> ptrEnv;

std::vector<Type*> currargvec1;

std::vector<std::string> currargvec2;

std::vector<std::string> currargvec3;

std::vector<std::vector<Type*>> currargvec;

std::string infer(Type *t) {
    if (dynamic_cast<Int*>(t)) return "int";
    if (dynamic_cast<Doub*>(t)) return "double";
    if (dynamic_cast<Bool*>(t)) return "bool";
    if (dynamic_cast<Str*>(t)) return "str";
    if (dynamic_cast<Ptr*>(t)) return dynamic_cast<Ptr*>(t)->ident_;
    if (dynamic_cast<Array*>(t)) {
        Array* arr = dynamic_cast<Array*>(t);
        if (dynamic_cast<Int*>(arr->type_)) return "inta";
        if (dynamic_cast<Doub*>(arr->type_)) return "doublea";
        if (dynamic_cast<Bool*>(arr->type_)) return "boola";
        return "unknown"; // Unknown array type
    }
    if (dynamic_cast<Void*>(t)) return "void";
    return "unknown";
}

std::string typeextract(Type *t) {

    return dynamic_cast<Ptr*>(t)->ident_;

}

std::string lookupVariable(Ident var){
  for (auto it = contextStack.rbegin(); it != contextStack.rend(); ++it) {
        if (it->count(var)) {
            return it->at(var);
        }
    }
  return "unknown";
}

std::string lookupVariableshall(Ident var){
  bool b = false;
  for (auto it = contextStack.rbegin(); it != contextStack.rend(); ++it) {
  	if (b) return "unknown";
        if (it->count(var)) {
            return it->at(var);
        }
        b = true;
    }
  return "unknown";
}



FunctionInfo* lookupFunc(Ident func){
  for (auto p : funcEnv){
    if (p.first == func){
      return p.second;
    }
  }
  return nullptr;
}

StructInfo* lookupStruct(Ident struc){
  for (auto& p : structEnv) {
    if (p.first == struc) {
      return p.second;
    }
  }
  
  
  return nullptr;
}

std::string last_type = "unknown";
std::string decl_type = "unknown";
std::string ret_type = "unknown";
std::string ret_type1 = "";
std::string decl_type1 = "";
std::string last_type2 = "";



bool AlwaysReturns = false;

void checkMainExists(){
  auto it = funcEnv.find("main");
  if (it == funcEnv.end()){
    throw TypeError("Main function missing");
  }
  else if (infer((*it).second->returnType) != "int" || !(*it).second->paramTypes.empty()){
    throw TypeError("Main function should be of the type int main().");
  }
  else{
    return;
  }
}

void checkStructPtr(){
  for (auto p : ptrEnv){
    if (structEnv.find(p.second) == structEnv.end()){
      throw TypeError("typedef for struct declared which doesn't exist.");
    }
  }

  for (auto p : structEnv){
    StructInfo* s = p.second;
    for (auto t : s->memb){
      if (ptrEnv.find(t.second) == ptrEnv.end() and (t.second != "int" and t.second != "bool" and t.second != "double")){
        throw TypeError("Type in struct doesn't exist." + t.second);
      }
    }
  }

}

void Skeleton::visitProgram(Program *program)
{
  /* Code For Program Goes Here */
  FunctionInfo* f = new FunctionInfo();
  f->returnType = new Void;
  f->paramTypes.push_back("int");
  funcEnv["printInt"] = f;

  FunctionInfo* f1 = new FunctionInfo();
  f1->returnType = new Void;
  f1->paramTypes.push_back("double");
  funcEnv["printDouble"] = f1;

  FunctionInfo* f2 = new FunctionInfo();
  f2->returnType = new Void;
  f2->paramTypes.push_back("str");
  funcEnv["printString"] = f2;

  FunctionInfo* f3 = new FunctionInfo();
  f3->returnType = new Int;
  f3->paramTypes = {};
  funcEnv["readInt"] = f3;

  FunctionInfo* f4 = new FunctionInfo();
  f4->returnType = new Doub;
  f4->paramTypes = {};
  funcEnv["readDouble"] = f4;
  
  program->listtopdef_->accept(this);

  checkMainExists();
  checkStructPtr();
  num_passes += 1;
  program->listtopdef_->accept(this);
  num_passes += 1;
  program->listtopdef_->accept(this);
}

void Skeleton::visitStructDef(StructDef *struct_def)
{
  /* Code For StructDef Goes Here */
  if (num_passes == 0){
    std::string structName = typeextract(struct_def->type_);
    if (structEnv.find(structName) != structEnv.end()) {
      throw TypeError("Struct " + structName + " already defined");
      return;
    }
    
    StructInfo* s = new StructInfo();
    s->name = structName;
    
    struct_def->liststructitem_->accept(this);

    int siz = currargvec2.size(); 

    std::set<std::string> st (currargvec3.begin(), currargvec3.end());
    if (siz != st.size()){
      throw TypeError("Duplicate members in struct " + structName);
      return;
    }
    if (siz == 0){
      throw TypeError("Struct " + structName + " cannot be empty.");
      return;
    }
    
    for (int i = 0; i < siz; i++){
      s->memb[currargvec3[i]] = currargvec2[i];
    }

    currargvec2.clear();
    currargvec3.clear();

    structEnv[structName] = s;
    return;
  }
}

void Skeleton::visitPtrDef(PtrDef *ptr_def)
{
  /* Code For PtrDef Goes Here */
  if (num_passes == 0){
    std::string ptr_typ = typeextract(ptr_def->type_);
    if (ptrEnv.find(ptr_typ) != ptrEnv.end()){
      throw TypeError("typedef " + ptr_typ +  " already defined.");
    }

    ptrEnv[ptr_def->ident_] = ptr_typ;
  }
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
      for (auto p: currargvec1){
        (f->paramTypes).push_back(infer(p));
      }
      for (auto p: currargvec1){

        delete p;
      }
      currargvec1.clear();
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
    if (ret_type != "void"){
      fn_def->blk_->accept(this);
    }

    if (AlwaysReturns == false and ret_type != "void"){
      throw TypeError(fn_def->ident_ + " may not return a value on all paths.");
    }
    AlwaysReturns = false;
  }
}

void Skeleton::visitFnDef1(FnDef1 *fn_def)
{
  /* Code For FnDef1 Goes Here */
  if (num_passes == 0){
    if (lookupFunc(fn_def->ident_2) != nullptr){
      throw TypeError(fn_def->ident_2 + ": Duplicate function names.");
      return;
    }
    else{
      FunctionInfo* f = new FunctionInfo();
      f->returnType = inferredtotype(fn_def->ident_1);
      fn_def->listarg_->accept(this);
      for (auto p: currargvec1){
        (f->paramTypes).push_back(infer(p));
      }
      for (auto p: currargvec1){

        delete p;
      }
      currargvec1.clear();
      funcEnv[fn_def->ident_2] = f; 
    }
    
  }
  /* Code For FnDef Goes Here */
  else if (num_passes == 1){
    ret_type = fn_def->ident_1;
    contextStack.push_back({});
    visitIdent(fn_def->ident_1);
    fn_def->listarg_->accept(this);
    fn_def->blk_->accept(this);

    contextStack.pop_back();
  }
  else{
    ret_type = fn_def->ident_1;
    if (ret_type != "void"){
      fn_def->blk_->accept(this);
    }

    if (AlwaysReturns == false and ret_type != "void"){
      throw TypeError(fn_def->ident_2 + " may not return a value on all paths.");
    }
    AlwaysReturns = false;
  }

}

void Skeleton::visitArgument(Argument *argument)
{
  /* Code For Argument Goes Here */
  if (num_passes == 0){
    last_type = infer(argument -> type_);
    if (last_type == "void"){
    	throw TypeError("Argument cannot be of void type");
    }
  }
  else if (num_passes == 1){
  argument->type_->accept(this);
  visitIdent(argument->ident_);
  if (last_type != "unknown"){
    throw TypeError("Duplicate parameters in function definition.");
  }
  contextStack.back()[argument->ident_] = infer(argument->type_);
  }
  else{

  }
}

void Skeleton::visitArgument1(Argument1 *argument)
{
  /* Code For Argument1 Goes Here */
  if (num_passes == 0){
    last_type = argument->ident_1;
  }
  else if (num_passes == 1){
    visitIdent(argument->ident_1);
    visitIdent(argument->ident_2);
    if (last_type != "unknown"){
      throw TypeError("Duplicate parameters in function definition.");
    }
    contextStack.back()[argument->ident_2] = argument->ident_1 ;
  }
}

void Skeleton::visitBlock(Block *block)
{
  /* Code For Block Goes Here */
  contextStack.push_back({});
  block->liststmt_->accept(this);
  contextStack.pop_back();

}

void Skeleton::visitEmpty(Empty *empty)
{
  /* Code For Empty Goes Here */


}

void Skeleton::visitBStmt(BStmt *b_stmt)
{
  /* Code For BStmt Goes Here */
  contextStack.push_back({});
  b_stmt->blk_->accept(this);
  contextStack.pop_back();

}

void Skeleton::visitDecl(Decl *decl)
{
  /* Code For Decl Goes Here */
  if (num_passes == 1){
    decl->type_->accept(this);
    decl_type = infer(decl->type_);
    if (decl_type == "void"){
    	throw TypeError("Cannot declare void variable");
    }

    decl->listitem_->accept(this);
  }
}

void Skeleton::visitDecl1(Decl1 *decl)
{
  /* Code For Decl1 Goes Here */
  if (num_passes == 1){
    decl_type = decl->ident_;
    if (ptrEnv.find(decl_type) == ptrEnv.end()){
      throw TypeError("Pointer type " + decl_type + " not defined.");
    }
    decl->listitem_->accept(this);
  }

}



void Skeleton::visitAss1(Ass1 *ass)
{
  /* Code For Ass1 Goes Here */
  if (num_passes == 1){
    if (!dynamic_cast<EIndex*>(ass->expr_1) and !dynamic_cast<EVar*>(ass->expr_1) and ! dynamic_cast<EDeref*>(ass->expr_1)) throw TypeError("Assignment statement cannot have expression on the left.");
    ass->expr_1->accept(this);
    std::string type1 = last_type;
    
  
    ass->expr_2->accept(this);
    std::string type2 = last_type;

    if (type1 == "unknown"){
      throw TypeError("Undeclared list indexed. ");
    }
    if (type1 != type2){
      throw TypeError("Incorrect literal type assigned.");

    }
    last_type = type1;
    ass->expr_1 = new ETypeAnn(ass->expr_1, inferredtotype(type1));
    last_type = type2;
    ass->expr_2 = new ETypeAnn(ass->expr_2, inferredtotype(type2));
  }

}

void Skeleton::visitIncr1(Incr1 *incr)
{
  /* Code For Incr1 Goes Here */
  
  if (num_passes == 1){
    if (! dynamic_cast<EIndex*> (incr->expr_)and !dynamic_cast<EVar*>(incr->expr_)and ! dynamic_cast<EDeref*>(incr->expr_)) throw TypeError("Cannot use an expression with the ++ operator");
    incr->expr_->accept(this);
    if (last_type != "int"){
      throw TypeError("Wrong variable type used with the increment (++) operator.");
    }
    incr->expr_ = new ETypeAnn(incr->expr_, new Int);
  }
}

void Skeleton::visitDecr1(Decr1 *decr)
{
  /* Code For Decr1 Goes Here */

  if (num_passes == 1){
    if (! dynamic_cast<EIndex*> (decr->expr_)and !dynamic_cast<EVar*>(decr->expr_)and ! dynamic_cast<EDeref*>(decr->expr_)) throw TypeError("Cannot use an expression with the -- operator");
    decr->expr_->accept(this);
    if (last_type != "int"){
      throw TypeError("Wrong variable type used with the decrement (--) operator.");
    }
    decr->expr_ = new ETypeAnn(decr->expr_, new Int);
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
  if (ret_type != "void"){
    throw TypeError("Expected an expression of type " + ret_type + "to be returned.");
  }

}

void Skeleton::visitCond(Cond *cond)
{
  /* Code For Cond Goes Here */
  if (num_passes == 1){
    cond->expr_->accept(this);
    if (last_type != "bool"){
      throw TypeError("Boolean expression expected in if condition.");
    }
    cond->expr_ = new ETypeAnn(cond->expr_, new Bool);
    cond->stmt_->accept(this);
  }
  else if (num_passes == 2){
  }
}

void Skeleton::visitCondElse(CondElse *cond_else)
{
  /* Code For CondElse Goes Here */
  if (num_passes == 1){
    cond_else->expr_->accept(this);
    if (last_type != "bool"){
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
    if (last_type != "bool"){
      throw TypeError("Boolean expression expected in if condition.");
    }
    while_->expr_ = new ETypeAnn(while_->expr_, new Bool);
    while_->stmt_->accept(this);
  }
  else if (num_passes == 2){
    
  }
}

void Skeleton::visitFor(For *for_)
{
  /* Code For For Goes Here */
  if (num_passes == 1){
    for_->expr_->accept(this);
    if (last_type != "inta" && last_type != "doublea" && last_type != "boola"){

      throw TypeError("List expected in for loop.");
    }

    for_->expr_ = new ETypeAnn(for_->expr_, inferredtotype(last_type));


    std::string elementType;
    if (last_type == "inta") elementType = "int";
    else if (last_type == "doublea") elementType = "double";
    else if (last_type == "boola") elementType = "bool";
    else{
      throw TypeError("Unknown type in for loop.");
    }

    for_->type_->accept(this);
    if (last_type != elementType){
      throw TypeError("For loop variable type does not match the list type.");
    }
  visitIdent(for_->ident_);
  
    if (lookupVariableshall(for_->ident_) != "unknown"){
      throw TypeError("Multiple declaration in same scope");
    }
    else{
      contextStack.push_back({});
    }
    decl_type = infer(for_->type_);
    contextStack.back()[for_->ident_] = decl_type;

    for_->stmt_->accept(this);
    contextStack.pop_back();
  }
  else if (num_passes == 2){
    if (AlwaysReturns != true){
      for_->stmt_->accept(this);
    }
}
}
void Skeleton::visitSExp(SExp *s_exp)
{
  /* Code For SExp Goes Here */
  if (num_passes == 1){
  s_exp->expr_->accept(this);
  if (last_type != "void"){
  	throw TypeError("Non-void expression statement.");
  }
  s_exp->expr_ = new ETypeAnn(s_exp->expr_, new Void);
  }
  
  
}

void Skeleton::visitStructItemT(StructItemT *struct_item_t)
{
  /* Code For StructItemT Goes Here */
  if (num_passes == 0){
    struct_item_t->type_->accept(this);
    if (last_type == "void"){
      throw TypeError("Cannot have void type member of struct");
    }
    last_type2 = struct_item_t->ident_;
  }

}

void Skeleton::visitStructItemP(StructItemP *struct_item_p)
{
  /* Code For StructItemP Goes Here */
  if (num_passes == 0){
    last_type = struct_item_p->ident_1;
    last_type2 = struct_item_p->ident_2;
  }
  

}

void Skeleton::visitNoInit(NoInit *no_init)
{
  /* Code For NoInit Goes Here */
  if (num_passes == 1){
    visitIdent(no_init->ident_);
    if (lookupVariableshall(no_init->ident_) != "unknown"){
    	throw TypeError("Multiple declaration in same scope");
    }
    contextStack.back()[no_init->ident_] = decl_type;

  }
  
}

void Skeleton::visitInit(Init *init)
{
  /* Code For Init Goes Here */
  if (num_passes == 1){
    visitIdent(init->ident_);
    if (lookupVariableshall(init->ident_) != "unknown"){
    	throw TypeError("Multiple declaration in same scope");
    }
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

  last_type = "int";
}

void Skeleton::visitDoub(Doub *doub)
{
  /* Code For Doub Goes Here */

  last_type = "double";
}

void Skeleton::visitBool(Bool *bool_)
{
  /* Code For Bool Goes Here */

  last_type = "bool";
}

void Skeleton::visitVoid(Void *void_)
{
  /* Code For Void Goes Here */
  last_type = "void";

}

void Skeleton::visitStr(Str *str)
{
  /* Code For Str Goes Here */

  last_type = "str";
}

void Skeleton::visitArray(Array *array)
{
  /* Code For Array Goes Here */
  if (num_passes == 1){
    array->type_->accept(this);
    std::string type = last_type;
    if (type != "int" && type != "double" && type != "bool"){
      throw TypeError("Invalid array type in array declaration.");
    }
    last_type = (type == "int") ? "inta" : (type == "double") ? "doublea" : "boola";
  }

}

void Skeleton::visitPtr(Ptr *ptr)
{
  /* Code For Ptr Goes Here */
  if (num_passes == 0){
    last_type = ptr->ident_;
  }
  else if (num_passes == 1){
    if (ptrEnv.find(ptr->ident_) == ptrEnv.end()){
      throw TypeError("Pointer type " + ptr->ident_ + " not defined.");
    }
    last_type = ptr->ident_;
  }
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
    if (last_type == "unknown"){
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
  last_type = "bool";

}

void Skeleton::visitELitFalse(ELitFalse *e_lit_false)
{
  /* Code For ELitFalse Goes Here */

  last_type = "bool";
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
    if ((res->paramTypes).size() != currargvec.back().size()){
      throw TypeError("Function call to " + e_app->ident_ + " does not match the definition (insufficient arguments).");
    }

    for (size_t i = 0; i < res->paramTypes.size(); ++i) {
      if (!(infer(currargvec.back()[i]) == res->paramTypes[i])) {
        throw TypeError("Function " + e_app->ident_ + ": Argument " + std::to_string(i + 1) +
                        " has incorrect type.");
      }
    }


    currargvec.pop_back();

    last_type = infer(res->returnType);


  }
}

void Skeleton::visitEString(EString *e_string)
{
  /* Code For EString Goes Here */

  visitString(e_string->string_);

}

void Skeleton::visitEIndex(EIndex *e_index)
{
  /* Code For EIndex Goes Here */
  if (num_passes == 1){
    e_index->expr_1->accept(this);
    std::string type1 = last_type;
    e_index->expr_2->accept(this);
    std::string type2 = last_type;
    if (type1 != "inta" && type1 != "doublea" && type1 != "boola"){
      throw TypeError("Invalid array type in index expression.");
    }
    if (type2 != "int"){
      throw TypeError("Array index must be of type int.");
    }
    if (type1 == "inta"){
      last_type = "int";
    }
    else if (type1 == "doublea"){
      last_type = "double";
    }
    else if (type1 == "boola"){
      last_type = "bool";
    }
      
    e_index->expr_1 = new ETypeAnn(e_index->expr_1, inferredtotype(type1));
    e_index->expr_2 = new ETypeAnn(e_index->expr_2, inferredtotype(type2));
  }

}

void Skeleton::visitENewArr(ENewArr *e_new_arr)
{
  /* Code For ENewArr Goes Here */
  if (num_passes == 1){
    e_new_arr->type_->accept(this);
    std::string type = last_type;
    if (type != "int" && type != "double" && type != "bool"){
      throw TypeError("Invalid array type in array declaration.");
    }
    e_new_arr->expr_->accept(this);
    std::string expr_type = last_type;
    if (expr_type != "int"){
      throw TypeError("Array size must be of type int.");
    }
    e_new_arr->expr_ = new ETypeAnn(e_new_arr->expr_, new Int);
    last_type = (type == "int") ? "inta" : (type == "double") ? "doublea" : "boola";
  }

}

void Skeleton::visitENewStruct(ENewStruct *e_new_struct)
{
  /* Code For ENewStruct Goes Here */
  if (e_new_struct->ident_ == "int" || e_new_struct->ident_ == "double" || e_new_struct->ident_ == "bool"){
    throw TypeError("Cannot create a new struct of primitive type.");
  }
  if (num_passes == 1){
    bool b = false;
    for (auto& p : ptrEnv){
      if (p.second == e_new_struct->ident_){
        last_type = p.first;
        b = true;
        break;
      }
    }
    if (!b){
      throw TypeError("No typedef defined for " + e_new_struct->ident_);
    }
    StructInfo* s = lookupStruct(e_new_struct->ident_);
    if (s == nullptr){
      throw TypeError("Struct " + e_new_struct->ident_ + " not defined.");
    }
    
    }

}

void Skeleton::visitENullPtr(ENullPtr *e_null_ptr)
{
  /* Code For ENullPtr Goes Here */
  if (num_passes == 1){
    if (e_null_ptr->ident_ == "int" || e_null_ptr->ident_ == "double" || e_null_ptr->ident_ == "bool"){
      throw TypeError("Cannot create a null pointer of primitive type.");
    }
    if (ptrEnv.find(e_null_ptr->ident_) == ptrEnv.end()){
      throw TypeError("Pointer type " + e_null_ptr->ident_ + " not defined.");
    }
    last_type = e_null_ptr->ident_;
  }
}

void Skeleton::visitEDeref(EDeref *e_deref)
{
  /* Code For EDeref Goes Here */
  if (num_passes == 1){
    e_deref->expr_->accept(this);
    e_deref->expr_ = new ETypeAnn(e_deref->expr_, new Ptr(last_type));

    bool b = false;
    for (auto& p : ptrEnv){
      if (p.first == last_type){
        last_type = p.second;
        b = true;
        break;
      }
    }
    if (!b){
      throw TypeError("Pointer type for " + last_type + " not defined.");
    }
    StructInfo* s = lookupStruct(last_type);
    if (s == nullptr){
      throw TypeError("Pointer type " + last_type + " not defined.");
    }
    if (s->memb.find(e_deref->ident_) == s->memb.end()){
      throw TypeError("Member " + e_deref->ident_ + " not found in struct " + ptrEnv[last_type] + ".");
    }
    else{
      if (s->memb[e_deref->ident_] == "int"){
        last_type = "int";
      }
      else if (s->memb[e_deref->ident_] == "double"){
        last_type = "double";
      }
      else if (s->memb[e_deref->ident_] == "bool"){
        last_type = "bool";
      }
      else{
        last_type = s->memb[e_deref->ident_];
      }
    }
  }

}

void Skeleton::visitELen(ELen *e_len)
{
  /* Code For ELen Goes Here */
  if (num_passes == 1){
    visitIdent(e_len->ident_);
    if (e_len->ident_ != "length"){
      throw TypeError("Method does not exist.");
    }
    e_len->expr_->accept(this);
    if (last_type != "inta" && last_type != "doublea" && last_type != "boola"){
      throw TypeError("Invalid array type in length expression.");
    }
    e_len->expr_ = new ETypeAnn(e_len->expr_, inferredtotype(last_type));
    last_type = "int";
  }

}

void Skeleton::visitNeg(Neg *neg)
{
  /* Code For Neg Goes Here */

  neg->expr_->accept(this);
  if (last_type == "void"){
  	throw TypeError("Invalid operand for neg");
  }

}

void Skeleton::visitNot(Not *not_)
{
  /* Code For Not Goes Here */

  not_->expr_->accept(this);
  if (last_type == "void"){
  	throw TypeError("Invalid operand for not");
  }
}

void Skeleton::visitEMul(EMul *e_mul)
{
  /* Code For EMul Goes Here */
  if (num_passes == 1){
    e_mul->expr_1->accept(this);
    std::string type1 = last_type;
    e_mul->mulop_->accept(this);
    e_mul->expr_2->accept(this);
    std::string type2 = last_type;
    if (((type1 != "int") || (type2 != "int")) && ((type1 != "double") || (type2 != "double"))) {
      throw TypeError("Incorrect operand type for multiplication");
    }

    if (dynamic_cast<Mod*>(e_mul->mulop_)){
      if (type1 != "int" || type2 != "int"){
        throw TypeError("Incorrect operand type for modulus");
      }
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
    std::string type1 = last_type;
    e_add->addop_->accept(this);
    e_add->expr_2->accept(this);
    std::string type2 = last_type;
    if (((type1 != "int") || (type2 != "int")) && ((type1 != "double") || (type2 != "double"))) {
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
    std::string type1 = last_type;
    e_rel->relop_->accept(this);
    e_rel->expr_2->accept(this);
    std::string type2 = last_type;
    if (type1 != type2 || (type1 == "bool" && !dynamic_cast<EQU*>(e_rel->relop_))){
      std :: cout << type1 << " " << type2 << std::endl;

       throw TypeError("Incorrect operand type for ERel");
      
    }
    e_rel-> expr_1 = new ETypeAnn(e_rel->expr_1, inferredtotype(type1));
    e_rel-> expr_2 = new ETypeAnn(e_rel->expr_2, inferredtotype(type2));
    last_type = "bool";
  }


}

void Skeleton::visitEAnd(EAnd *e_and)
{
  /* Code For EAnd Goes Here */

  if (num_passes == 1){
    e_and->expr_1->accept(this);
    std::string type1 = last_type;
    e_and->expr_2->accept(this);
    std::string type2 = last_type;
    if (((type1 != "bool") || (type2 != "bool"))) {
      throw TypeError("Incorrect operand type for && operator.");
      
    }
    Type *t = inferredtotype(type1);
    e_and->expr_1 = new ETypeAnn(e_and->expr_1, t);
    e_and->expr_2 = new ETypeAnn(e_and->expr_2, t);
    last_type = "bool";
  }

}

void Skeleton::visitEOr(EOr *e_or)
{
  /* Code For EOr Goes Here */

  if (num_passes == 1){
    e_or->expr_1->accept(this);
    std::string type1 = last_type;
    e_or->expr_2->accept(this);
    std::string type2 = last_type;
    if (((type1 != "bool") || (type2 != "bool"))) {
      throw TypeError("Incorrect operand type for || operator.");
      
    }
    Type *t = inferredtotype(type1);
    e_or->expr_1 = new ETypeAnn(e_or->expr_1, t);
    e_or->expr_2 = new ETypeAnn(e_or->expr_2, t);
    last_type = "bool";
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
      currargvec1.push_back(inferredtotype(last_type));
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

void Skeleton::visitListStructItem(ListStructItem *list_struct_item)
{
  if (num_passes == 0){
    for (ListStructItem::iterator i = list_struct_item->begin() ; i != list_struct_item->end() ; ++i)
  {
    (*i)->accept(this);
      currargvec2.push_back(last_type);

    currargvec3.push_back(last_type2);
  }
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
    currargvec.push_back({});
    for (ListExpr::iterator i = list_expr->begin() ; i != list_expr->end() ; ++i)
    {
      (*i)->accept(this);
      (*i) = new ETypeAnn((*i), inferredtotype(last_type));
      currargvec.back().push_back(inferredtotype(last_type));
    }
  }
  
}


void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
  last_type = "int";
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */

}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
  last_type = "double";
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
  last_type = "str";
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
  last_type = lookupVariable(x);
}


