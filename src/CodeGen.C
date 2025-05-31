/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "CodeGen.H"
#include <iostream>
#include <map>



void CodeGen::visitProg(Prog *t) {} //abstract class
void CodeGen::visitTopDef(TopDef *t) {} //abstract class
void CodeGen::visitArg(Arg *t) {} //abstract class
void CodeGen::visitBlk(Blk *t) {} //abstract class
void CodeGen::visitStmt(Stmt *t) {} //abstract class
void CodeGen::visitItem(Item *t) {} //abstract class
void CodeGen::visitType(Type *t) {} //abstract class
void CodeGen::visitExpr(Expr *t) {} //abstract class
void CodeGen::visitAddOp(AddOp *t) {} //abstract class
void CodeGen::visitMulOp(MulOp *t) {} //abstract class
void CodeGen::visitRelOp(RelOp *t) {} //abstract class

enum InferredType1 { TINT, TDOUBLE, TBOOL, TSTR, TVOID, TINTA, TDOUBLEA, TBOOLA, TUNKNOWN };

InferredType1 infer1(Type *t) {
    if (dynamic_cast<Int*>(t)) return TINT;
    if (dynamic_cast<Doub*>(t)) return TDOUBLE;
    if (dynamic_cast<Bool*>(t)) return TBOOL;
    if (dynamic_cast<Str*>(t)) return TSTR;
    if (dynamic_cast<Void*>(t)) return TVOID;
    if (dynamic_cast<Array*>(t)) {
        Array* arr = dynamic_cast<Array*>(t);
        if (dynamic_cast<Int*>(arr->type_)) return TINTA;
        if (dynamic_cast<Doub*>(arr->type_)) return TDOUBLEA;
        if (dynamic_cast<Bool*>(arr->type_)) return TBOOLA;
        return TUNKNOWN; // Unknown array type
    }
    return TUNKNOWN;
}

InferredType1 last_type1 = TUNKNOWN;
InferredType1 decl_type1 = TUNKNOWN;
InferredType1 ret_type1 = TUNKNOWN;

std::map<std::string, std::string> globalStrings;
int stringCounter = 0;

std::string lastLabel;

std::string escapeString(const std::string& str) {
    std::ostringstream escaped;
    escaped << str << "\\00";

    return escaped.str();
}

std::string getOrAddGlobalString(const std::string& raw) {
    if (globalStrings.count(raw))
        return globalStrings[raw];

    std::string label = "@.str." + std::to_string(stringCounter++);
    globalStrings[raw] = label;
    return label;
}


int num_passes1 = 0;

std::vector<std::unordered_map<std::string, std::string>> symbolTableStack;

std::vector<std::string> liststmt;

int numpass = 1;

std::string declared_type = "";

std::string last__type = "";


std::string llvmtype(InferredType1 t){
  if (t == TINT){
    return "i32";
  }
  else if (t == TDOUBLE){
    return "double";
  }
  else if (t == TBOOL){
    return "i1";
  }
  else if (t == TVOID){
    return "void";
  }
  else if (t == TSTR){
    return "i8*";
  }
  else if (t == TINTA){
    return "i32*";
  }
  else if (t == TDOUBLEA){
    return "double*";
  }
  else if (t == TBOOLA){
    return "i1*";
  }
  else{
    return "i32";
  }
}


std::vector<std::unordered_map<std::string, std::string>> contextStack_llvm;

std::vector<std::string> argstrings;

std::string lastPtr;

std::vector<std::vector<std::string>> funcargsreg;

std::string join(const std::vector<std::string>& parts, const std::string& sep) {
    std::ostringstream os;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) os << sep;
        os << parts[i];
    }
    return os.str();
}

std::string lookupvar(Ident var){
  for (auto it = contextStack_llvm.rbegin(); it != contextStack_llvm.rend(); ++it) {
        if (it->count(var)) {
            return it->at(var);
        }
    }
  return "";
}

void CodeGen::emit(std::vector<std::string> lines) {
	std::string st;
	for (auto line: lines){
		if (line[2] == 'r' and line[3] == 'e' and line[4] == 't'){
			st = line;
		}
	}
	if (lines.size() > 1) {
	    std::string sd = lines[lines.size() - 2];
	
		if (sd[0] != ' '){
			lines.pop_back();
			lines.push_back(st);
			lines.push_back("}");
		}
	}
        for (auto line : lines){
            out << line << "\n";
        }
        std::cout << out.str();
        out.clear();
        out.str("");
        liststmt.clear();
}

void emitGlobalStrings() {
    for (const auto& [raw, label] : globalStrings) {
    	std::string raw1 = escapeString(raw);
        int len = raw1.length() - 2;  // Include null terminator

        std :: cout << label << " = private unnamed_addr constant [" << len
            << " x i8] c\"" << raw1 << "\"\n";
    }
}


void CodeGen::visitProgram(Program *program)
{
  /* Code For Program Goes Here */
  num_passes1 = 0;
  program->listtopdef_->accept(this);
  emitGlobalStrings();
  emit({"declare i8* @malloc(i32)"});
  emit({"declare void @printInt(i32)"});
  emit({"declare void @printDouble(double)"});  
  emit({"declare void @printString(i8*)"});
  emit({"declare i32 @readInt()"});
  emit({"declare double @readDouble()"});
  num_passes1 += 1;

  program->listtopdef_->accept(this);

}

void CodeGen::visitFnDef(FnDef *fn_def)
{
  if (num_passes1 == 1){
  std::string stmt;

  stmt = "define ";
  stmt += llvmtype(infer1(fn_def->type_));
  stmt += " @";
  stmt += fn_def->ident_;
  stmt += "(";
  argstrings.clear();
  contextStack_llvm.push_back({});
  fn_def->listarg_->accept(this);
  numpass += 1;
  stmt += join(argstrings, ", ");
  stmt += ") {";

  liststmt.push_back(stmt);
  liststmt.push_back("entry:");
  lastLabel = "entry";

  fn_def->listarg_->accept(this);
  
  numpass -=1;


  fn_def->blk_->accept(this);


  if (llvmtype(infer1(fn_def->type_)) == "void"){
    liststmt.push_back("  ret void");
  }
  liststmt.push_back("}");
  emit(liststmt);
  contextStack_llvm.pop_back();
  }
  else{

    fn_def->blk_->accept(this);
  }
  

  /* if (num_passes1 == 0){
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
    
  } */
  /* Code For FnDef Goes Here */
  /* else if (num_passes1 == 1){
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
  } */ 
}

void CodeGen::visitArgument(Argument *argument)
{
  /* Code For Argument Goes Here */
  if (num_passes1 == 1){
  if (numpass == 1){
    argstrings.push_back(llvmtype(infer1(argument->type_)) + " " + "%" + argument->ident_);
  }
  else if (numpass == 2){
    std::string llvmType = llvmtype(infer1(argument->type_));
    std::string varName = argument->ident_;

    std::string allocName = new_reg();

    liststmt.push_back("  " + allocName + " = alloca " + llvmType);
    liststmt.push_back("  store " + llvmType + " %" + varName + ", " + llvmType + "* " + allocName);

    contextStack_llvm.back()[varName] = allocName;
  }
  }
  

  
/*   if (num_passes1 == 0){
    last_type = infer(argument -> type_);
  }
  else if (num_passes1 == 1){
  argument->type_->accept(this);
  visitIdent(argument->ident_);

  contextStack.back()[argument->ident_] = infer(argument->type_);
  }
  else{

  } */
}

void CodeGen::visitBlock(Block *block)
{
  /* Code For Block Goes Here */
  if (num_passes1 == 1){
  contextStack_llvm.push_back({});
  block->liststmt_->accept(this);
  contextStack_llvm.pop_back();
  }
  else{


    block->liststmt_->accept(this);
  }
}

void CodeGen::visitEmpty(Empty *empty)
{
  /* Code For Empty Goes Here */


}

void CodeGen::visitBStmt(BStmt *b_stmt)
{
  /* Code For BStmt Goes Here */
  if (num_passes1 == 1){
  contextStack_llvm.push_back({});
  b_stmt->blk_->accept(this);
  contextStack_llvm.pop_back();
  }
  else{
  b_stmt->blk_->accept(this);
  }
}

void CodeGen::visitDecl(Decl *decl)
{
  /* Code For Decl Goes Here */
  if (num_passes1 == 1){
  declared_type = llvmtype(infer1(decl->type_));
  decl->listitem_->accept(this);
  }
}

void CodeGen::visitAss(Ass *ass)
{
  /* Code For Ass Goes Here */
  if (num_passes1 == 1){
  std::string ptr = lookupvar(ass->ident_);
  ass->expr_->accept(this);
  std::string rhs = lastValue;
  std::string t = last__type;

  liststmt.push_back("  store " + t + " " + rhs + ", " + t + "* " + ptr);
  }
  /* if (num_passes1 == 1){
    visitIdent(ass->ident_);
    InferredType1 type1 = last_type;
    ass->expr_->accept(this);
    InferredType1 type2 = last_type;

    if (type1 != type2){
      throw TypeError("Incorrect literal type assigned to " + ass->ident_);

    }
  
  } */
  
}

void CodeGen::visitAss1(Ass1 *ass)
{
  /* Code For Ass1 Goes Here */

  
  ass->expr_1->accept(this);
  std::string gep = lastPtr;
  std::string llvmType1 = last__type;
  ass->expr_2->accept(this);
  std::string valueReg = lastValue;

  std::string llvmType = last__type;

  // Store the value into the computed address
  liststmt.push_back("  store " + llvmType + " " + valueReg + ", " + llvmType1 + "* " + gep + "");

}

void CodeGen::visitIncr(Incr *incr)
{
  /* Code For Incr Goes Here */
  if (num_passes1 == 1){
  std::string regName = lookupvar(incr->ident_);
  std::string type_str = llvmtype(TINT);

  std::string temp1 = new_reg();
  liststmt.push_back("  " + temp1 + " = load " + type_str + ", " + type_str + "* " + regName);

  std::string temp2 = new_reg();
  liststmt.push_back("  " + temp2 + " = add " + type_str + " " + temp1 + ", 1");

  liststmt.push_back("  store " + type_str + " " + temp2 + ", " + type_str + "* " + regName);  
  }
}

void CodeGen::visitDecr(Decr *decr)
{
  /* Code For Decr Goes Here */
  if (num_passes1 == 1){
  std::string regName = lookupvar(decr->ident_);
  std::string type_str = llvmtype(TINT);

  std::string temp1 = new_reg();
  liststmt.push_back("  " + temp1 + " = load " + type_str + ", " + type_str + "* " + regName);

  std::string temp2 = new_reg();
  liststmt.push_back("  " + temp2 + " = sub " + type_str + " " + temp1 + ", 1");

  liststmt.push_back("  store " + type_str + " " + temp2 + ", " + type_str + "* " + regName);  
  }
}


void CodeGen::visitIncr1(Incr1 *incr)
{
  /* Code For Incr1 Goes Here */
  if (num_passes1 == 1){
    last__type = llvmtype(TINT);
    incr->expr_->accept(this);
  std::string elemPtr = lastPtr;  // Pointer to a[i] produced by EIndex
  std::string val = lastValue;   // Value of a[i]

  std::string one = new_reg();
  liststmt.push_back("  " + one + " = add i32 " + val + ", 1");

  liststmt.push_back("  store i32 " + one + ", i32* " + elemPtr);
  }
  
}

void CodeGen::visitDecr1(Decr1 *decr)
{
  /* Code For Decr1 Goes Here */
  last__type = llvmtype(TINT);
  if (num_passes1 == 1){
  decr->expr_->accept(this);
  std::string elemPtr = lastPtr;  // Pointer to a[i] produced by EIndex
  std::string val = lastValue;   // Value of a[i]
  std::string one = new_reg();
  liststmt.push_back("  " + one + " = sub i32 " + val + ", 1");
  liststmt.push_back("  store i32 " + one + ", i32* " + elemPtr);
  }

}



void CodeGen::visitRet(Ret *ret)
{
  /* Code For Ret Goes Here */
  if (num_passes1 == 1){
  ret->expr_->accept(this);
  std::string typ = last__type;
  liststmt.push_back("  ret " + typ + " " + lastValue);
  }
}

void CodeGen::visitVRet(VRet *v_ret)
{
  /* Code For VRet Goes Here */
  if (num_passes1 == 1){
  liststmt.push_back("  ret void");
  }
}

void CodeGen::visitCond(Cond *cond)
{
  /* Code For Cond Goes Here */
  if (num_passes1 == 1){
  std::string then_label = new_label();
  std::string end_label = new_label();

  cond->expr_->accept(this);

  liststmt.push_back("  br i1 " + lastValue + ", label %" + then_label + ", label %" + end_label);

  liststmt.push_back(then_label + ":");
  lastLabel = then_label;
  cond->stmt_->accept(this);
  liststmt.push_back("  br label %" + end_label);

  liststmt.push_back(end_label + ":");
  lastLabel = end_label;
  }
  else{
  cond->stmt_->accept(this);
  }
}

void CodeGen::visitCondElse(CondElse *cond_else)
{
  /* Code For CondElse Goes Here */
  if (num_passes1 == 1){
  std::string then_label = new_label();
  std::string else_label = new_label();
  std::string end_label = new_label();

  cond_else->expr_->accept(this);

  liststmt.push_back("  br i1 " + lastValue + ", label %" + then_label + ", label %" + else_label);

  liststmt.push_back(then_label + ":");
    lastLabel = then_label;
  cond_else->stmt_1->accept(this);
  liststmt.push_back("  br label %" + end_label);

  liststmt.push_back(else_label + ":");
    lastLabel = else_label;
  cond_else->stmt_2->accept(this);
  liststmt.push_back("  br label %" + end_label);


  liststmt.push_back(end_label + ":");
    lastLabel = end_label;
  }
  else{
  cond_else->stmt_1->accept(this);
  cond_else->stmt_2->accept(this);
  }
}

void CodeGen::visitWhile(While *while_)
{
  /* Code For While Goes Here */
  if (num_passes1 == 1){
  std::string cond_label = new_label();
  std::string body_label = new_label();
  std::string end_label = new_label();

  liststmt.push_back("  br label %" + cond_label);

  liststmt.push_back(cond_label + ": ");
    lastLabel = cond_label;
  while_->expr_->accept(this);
  liststmt.push_back("  br i1 " + lastValue + ", label %" + body_label + ", label %" + end_label);

  liststmt.push_back(body_label + ":");
    lastLabel = body_label;
  while_->stmt_->accept(this);
  liststmt.push_back("  br label %" + cond_label);

  liststmt.push_back(end_label + ":");
    lastLabel = end_label;
  }
  else{
  
  while_->stmt_->accept(this);
  }
}

void CodeGen::visitFor(For *for_) {
  if (num_passes1 != 1) for_->stmt_->accept(this);

  std::string cond_label = new_label();
  std::string body_label = new_label();
  std::string step_label = new_label();
  std::string end_label = new_label();

  // Evaluate array expression
  for_->expr_->accept(this);
  std::string arrReg = lastValue;
  std::string arrType = last__type; // e.g., i32*

  // Allocate loop index (i = 0)
  std::string idx = new_reg();
  liststmt.push_back("  " + idx + " = alloca i32");
  liststmt.push_back("  store i32 0, i32* " + idx);

  // Allocate and bind loop variable (e.g., int x;)
  std::string varType = llvmtype(infer1(for_->type_));
  std::string varAlloc = new_reg();
  liststmt.push_back("  " + varAlloc + " = alloca " + varType);
  contextStack_llvm.push_back({});
  contextStack_llvm.back()[for_->ident_] = varAlloc;

  // Branch to condition
  liststmt.push_back("  br label %" + cond_label);

  // Condition block
  liststmt.push_back(cond_label + ":");
  std::string idxVal = new_reg();
  liststmt.push_back("  " + idxVal + " = load i32, i32* " + idx);

  std::string lenPtr = new_reg();
  liststmt.push_back("  " + lenPtr + " = getelementptr i32, i32* " + arrReg + ", i32 0");
  std::string lenVal = new_reg();
  liststmt.push_back("  " + lenVal + " = load i32, i32* " + lenPtr);
  std::string temp = new_reg();
  liststmt.push_back("  " + temp + " = getelementptr i32, i32* " + arrReg + ", i32 1");
  std::string temp2 = new_reg();
  liststmt.push_back("  " + temp2 + " = bitcast i32* " + temp + " to " + arrType);

  std::string cmp = new_reg();
  liststmt.push_back("  " + cmp + " = icmp slt i32 " + idxVal + ", " + lenVal);
  liststmt.push_back("  br i1 " + cmp + ", label %" + body_label + ", label %" + end_label);

  // Body block
  liststmt.push_back(body_label + ":");
  std::string adjIdx = new_reg();
  liststmt.push_back("  " + adjIdx + " = add i32 " + idxVal + ", 0");  // Skip length at offset 0

  std::string elemPtr = new_reg();
  std::string elemType(llvmtype(infer1(for_->type_)));
  liststmt.push_back("  " + elemPtr + " = getelementptr " + elemType + ", " + arrType + " " + temp2 + ", i32 " + adjIdx);

  std::string elemVal = new_reg();
  liststmt.push_back("  " + elemVal + " = load " + varType + ", " + varType + "* " + elemPtr);

  liststmt.push_back("  store " + varType + " " + elemVal + ", " + varType + "* " + varAlloc);

  // Visit loop body
  for_->stmt_->accept(this);

  liststmt.push_back("  br label %" + step_label);

  // Step block: increment index
  liststmt.push_back(step_label + ":");
  std::string nextIdx = new_reg();
  liststmt.push_back("  " + nextIdx + " = add i32 " + idxVal + ", 1");
  liststmt.push_back("  store i32 " + nextIdx + ", i32* " + idx);
  liststmt.push_back("  br label %" + cond_label);

  // End block
  liststmt.push_back(end_label + ":");

  contextStack_llvm.pop_back();
}


void CodeGen::visitSExp(SExp *s_exp)
{
  /* Code For SExp Goes Here */
  if (num_passes1 == 1){
  s_exp->expr_->accept(this);
  }
  else{
  s_exp->expr_->accept(this);
  }
}

void CodeGen::visitNoInit(NoInit *no_init)
{
  /* Code For NoInit Goes Here */
  if (num_passes1 == 1){
  std::string varName = no_init->ident_;
  std::string allocName = new_reg();

  

  std::string zero_value;
  if (declared_type == "i32") {
    zero_value = "0";
  } else if (declared_type == "double") {
    zero_value = "0.0";
  } else if (declared_type == "i1") {
    zero_value = "false";
  } 
  else if (declared_type == "i32*") {
    visitENewArr(new ENewArr(new Int, new ELitInt(0)));
    zero_value = lastValue;
  } 
  else if (declared_type == "double*") {
    visitENewArr(new ENewArr(new Doub, new ELitInt(0)));
    zero_value = lastValue;
  } 
  else if (declared_type == "i1*") {
    visitENewArr(new ENewArr(new Bool, new ELitInt(0)));
    zero_value = lastValue;
  }
  else {
    zero_value = "zeroinitializer"; // fallback (for structs/arrays etc.)
  }
  if (declared_type == "i32*" || declared_type == "double*" || declared_type == "i1*") {
    liststmt.push_back("  " + allocName + " = alloca " + "i32*");
    liststmt.push_back("  store i32* " + zero_value + ", " + "i32** " + allocName);
  }
  else{
    liststmt.push_back("  " + allocName + " = alloca " + declared_type);
    liststmt.push_back("  store " + declared_type+ " " + zero_value + ", " + declared_type + "* " + allocName);
  }
  contextStack_llvm.back()[varName] = allocName;
  }
  /* if (num_passes1 == 1){
    visitIdent(no_init->ident_);
    contextStack.back()[no_init->ident_] = decl_type;
    std::cout<<"Symbol Table:\n";
    for (auto t: contextStack.back()){
      std::cout<<t.first<<"\n";
      std::cout<<typetostring(t.second) << "\n\n";
    }
  } */
  
}

void CodeGen::visitInit(Init *init)
{
  /* Code For Init Goes Here */
  if (num_passes1 == 1){
  std::string varName = init->ident_;
  std::string allocName = new_reg();
  std::string resultReg;
  init->expr_->accept(this);
  resultReg = lastValue;

  if (declared_type == "i32*" || declared_type == "double*" || declared_type == "i1*") {
    liststmt.push_back("  " + allocName + " = alloca " + "i32*");
    liststmt.push_back("  store i32* " + resultReg + ", " + "i32** " + allocName);
  }
  else{
    liststmt.push_back("  " + allocName + " = alloca " + declared_type);
    liststmt.push_back("  store " + declared_type+ " " + resultReg + ", " + declared_type + "* " + allocName);
  }


  contextStack_llvm.back()[varName] = allocName;
  }
  /* if (num_passes1 == 1){
    visitIdent(init->ident_);
    init->expr_->accept(this);
    if (last_type != decl_type){
      throw TypeError("Wrong literal type initialised.");
    }
    else{
      init->expr_ = new ETypeAnn(init->expr_, inferredtotype(last_type));
    }
    contextStack.back()[init->ident_] = last_type;
    std::cout<<"Symbol Table:\n";
    for (auto t: contextStack.back()){
      std::cout<<t.first<<"\n";
      std::cout<<typetostring(t.second) << "\n\n";
    }
  } */
  
}

void CodeGen::visitInt(Int *int_)
{
  /* Code For Int Goes Here */
  if (num_passes1 == 1){
  last_type1 = TINT;
  }
}

void CodeGen::visitDoub(Doub *doub)
{
  /* Code For Doub Goes Here */
  if (num_passes1 == 1){
  last_type1 = TDOUBLE;
  }
}

void CodeGen::visitBool(Bool *bool_)
{
  /* Code For Bool Goes Here */
  if (num_passes1 == 1){
  last_type1 = TBOOL;
  }
}


void CodeGen::visitVoid(Void *void_)
{
  /* Code For Void Goes Here */
  if (num_passes1 == 1){
  last_type1 = TVOID;
  }
}

void CodeGen::visitStr(Str *str)
{
  /* Code For Str Goes Here */
  last_type1 = TSTR;
}

void CodeGen::visitArray(Array *array)
{
  /* Code For Array Goes Here */

}

void CodeGen::visitFun(Fun *fun)
{
  /* Code For Fun Goes Here */
  if (num_passes1 == 1){
  fun->type_->accept(this);
  fun->listtype_->accept(this);
  }
}

void CodeGen::visitETypeAnn(ETypeAnn *e_type_ann)
{
  /* Code For ETypeAnn Goes Here */
  if (num_passes1 == 1){
  last__type = llvmtype(infer1(e_type_ann->type_));
  e_type_ann->expr_->accept(this);
  e_type_ann->type_->accept(this);
  last__type = llvmtype(infer1(e_type_ann->type_));
  }
  else{
    e_type_ann->expr_->accept(this);
  }
}

void CodeGen::visitEVar(EVar *e_var)
{
  /* Code For EVar Goes Here */
  if (num_passes1 == 1){
  
  std::string ptr = lookupvar(e_var->ident_);  // get alloca'd pointer from symbol table
  std::string temp = new_reg();
  if (last__type == "i32*" || last__type == "double*" || last__type == "i1*") {
    liststmt.push_back("  " + temp + " = load i32*, i32** " + ptr);
  } else {
  liststmt.push_back("  " + temp + " = load " + last__type + ", " + last__type + "* " + ptr);
  }
  lastValue = temp;  
  }
}

void CodeGen::visitELitInt(ELitInt *e_lit_int)
{
  /* Code For ELitInt Goes Here */
  if (num_passes1 == 1){
  lastValue = std::to_string(e_lit_int->integer_);
  }
}

void CodeGen::visitELitDoub(ELitDoub *e_lit_doub)
{
  /* Code For ELitDoub Goes Here */
  if (num_passes1 == 1){
  lastValue = std::to_string(e_lit_doub->double_);
  }
}

void CodeGen::visitELitTrue(ELitTrue *e_lit_true)
{
  /* Code For ELitTrue Goes Here */
  if (num_passes1 == 1){
  lastValue = "1";
  }

}

void CodeGen::visitELitFalse(ELitFalse *e_lit_false)
{
  /* Code For ELitFalse Goes Here */
  if (num_passes1 == 1){
  lastValue = "0";
  }
}

void CodeGen::visitEApp(EApp *e_app)
{
  /* Code For EApp Goes Here */
  if (num_passes1 == 1){
  std::string s = last__type;
  e_app->listexpr_->accept(this);
  if (s == "void"){
  	if (e_app->ident_ == "printString"){
  		
	liststmt.push_back("  call " + s + " @" + e_app->ident_ + "(" + "i8* " + lastValue + ")");
	funcargsreg.pop_back();
	}
	else{
	  liststmt.push_back("  call " + s + " @" + e_app->ident_ + "(" + join(funcargsreg.back(), ", ") + ")");
	  funcargsreg.pop_back();
	}
  }
  else{
	  std::string temp = new_reg();
	  liststmt.push_back("  " + temp + " = call " + s + " @" + e_app->ident_ + "(" + join(funcargsreg.back(), ", ") + ")");
	  funcargsreg.pop_back();
	  lastValue = temp;
  }
  }
  else{
  e_app->listexpr_->accept(this);
  }
}
void CodeGen::visitEString(EString *e_string)
{
  /* Code For EString Goes Here */
  if(num_passes1 == 0){
  std::string temp = getOrAddGlobalString(e_string->string_);
  }
  if (num_passes1 == 1){
  std::string str = e_string->string_; // raw string from the AST
    std::string label = getOrAddGlobalString(str);
    int len = str.length() + 1;

    std::string tmpName = "%str" + std::to_string(reg_count++);
    liststmt.push_back("  " + tmpName + " = getelementptr [" + std::to_string(len) + " x i8], ["
        + std::to_string(len) + " x i8]* " + label + ", i32 0, i32 0");

  lastValue = tmpName;
  }
}

void CodeGen::visitENewArr(ENewArr *e_new_arr)
{
  /* Code For ENewArr Goes Here */
  if (num_passes1 == 1){
    e_new_arr->expr_->accept(this);
    std::string sizeReg = lastValue;

    std::string llvmType = llvmtype(infer1(e_new_arr->type_));
    int sizeBytes = 0;
    if (llvmType == "i32") {
        sizeBytes = 4;  // Size of int in bytes
    } else if (llvmType == "double") {
        sizeBytes = 8;  // Size of double in bytes
    } else if (llvmType == "i1") {
        sizeBytes = 4;  // Size of boolean in bytes
    } 

    std::string oneReg = new_reg();
    liststmt.push_back("  " + oneReg + " = add i32 " + sizeReg + ", 1");

    std::string fourReg = new_reg();
    liststmt.push_back("  " + fourReg + " = mul i32 " + "1, 4");

    std::string allocSize = new_reg();
    liststmt.push_back("  " + allocSize + " = mul i32 " + sizeReg + ", " + std::to_string(sizeBytes));

    std::string allocSizePlusFour = new_reg();

    liststmt.push_back("  " + allocSizePlusFour + " = add i32 " + allocSize + ", " + fourReg);

    std::string rawPtr = new_reg();
    liststmt.push_back("  " + rawPtr + " = call i8* @malloc(i32 " + allocSizePlusFour + ")");

    std::string arrPtr = new_reg();
    liststmt.push_back("  " + arrPtr + " = bitcast i8* " + rawPtr + " to " + "i32*");

    liststmt.push_back("  store i32 " + sizeReg + ", i32* " + arrPtr);

    std::string dataPtr = new_reg();
    liststmt.push_back("  " + dataPtr + " = getelementptr i8, i8* " + rawPtr + ", i32 " + std::to_string(4));

    std::string finalPtr = new_reg();
    liststmt.push_back("  " + finalPtr + " = bitcast i8* " + dataPtr + " to " + llvmType + "*");

    lastValue = arrPtr;
    if (infer1(e_new_arr->type_) == TINT){
      last__type = TINTA;
    }
    else if (infer1(e_new_arr->type_) == TDOUBLE){
      last__type = TDOUBLEA;
    }
    else if (infer1(e_new_arr->type_) == TBOOL){
      last__type = TBOOLA;
    }
  }
}

void CodeGen::visitEIndex(EIndex *e_index)
{
  /* Code For EIndex Goes Here */
  if (num_passes1 == 1){
    std::string type_str = last__type;
    e_index->expr_1->accept(this);
    std::string arrPtr = lastValue;
    e_index->expr_2->accept(this);
    std::string index = lastValue;
    std::string adjIdx = new_reg();
    liststmt.push_back("  " + adjIdx + " = add i32 " + index + ", 0");
    std::string temp = new_reg();
    liststmt.push_back("  " + temp + " = getelementptr i32, i32* " + arrPtr + ", i32 1");
    std::string temp1 = new_reg();
    liststmt.push_back("  " + temp1 + " = bitcast i32* " + temp + " to " + type_str + "*");
    std::string temp2 = new_reg();
    liststmt.push_back("  " + temp2 + " = getelementptr " + type_str + ", " + type_str + "* " + temp1 + ", i32 " + adjIdx);
    std::string temp3 = new_reg();
    liststmt.push_back("  " + temp3 + " = load " + type_str + ", " + type_str + "* " + temp2);

    lastValue = temp3;
    lastPtr = temp2;
    last__type = type_str;
  }
}

void CodeGen::visitELen(ELen *e_len)
{
  /* Code For ELen Goes Here */
  e_len->expr_->accept(this);
  std::string arrPtr = lastValue;

  std::string length = new_reg();
  liststmt.push_back("  " + length + " = load i32, i32* " + arrPtr);

  lastValue = length;

}

void CodeGen::visitNeg(Neg *neg)
{
  /* Code For Neg Goes Here */
  if (num_passes1 == 1){
  neg->expr_->accept(this);
  std::string temp = new_reg();
  if (last__type == "double"){
  	liststmt.push_back("  " + temp + " = fsub double 0.0, " + lastValue);
  }
  else{
  	liststmt.push_back("  " + temp + " = sub i32 0, " + lastValue);  
  }
  lastValue = temp;
  }
}

void CodeGen::visitNot(Not *not_)
{
  /* Code For Not Goes Here */
  if (num_passes1 == 1){
  not_->expr_->accept(this);
  std::string temp = new_reg();
  liststmt.push_back("  " + temp + " = xor i1 " + lastValue + ", true");
  lastValue = temp;
  }
}

void CodeGen::visitEMul(EMul *e_mul)
{
  /* Code For EMul Goes Here */
  if (num_passes1 == 1){
  e_mul->expr_1->accept(this);
  std::string t = last__type;
  std::string lhs = lastValue;
  e_mul->expr_2->accept(this);
  std::string rhs = lastValue;
  
  std::string temp = new_reg();
  std::string op;

  if (dynamic_cast<Times*>(e_mul->mulop_)){
    if (t == "double"){
    	op = "fmul";
    }
    else{
        op = "mul";
    }
  }
  else if (dynamic_cast<Div*>(e_mul->mulop_)){
    if (t == "double"){
    	op = "fdiv";
    }
    else{
        op = "sdiv";
    }
  }
  else if (dynamic_cast<Mod*>(e_mul->mulop_)){
    if (t == "double"){
    	op = "frem";
    }
    else{
        op = "srem";
    }
  }

  liststmt.push_back("  " + temp + " = " + op + " " + last__type + " " + lhs + ", " + rhs);
  lastValue = temp;
  }

}

void CodeGen::visitEAdd(EAdd *e_add)
{
  /* Code For EAdd Goes Here */
  if (num_passes1 == 1){
  e_add->expr_1->accept(this);
  std::string t = last__type;
  std::string lhs = lastValue;
  e_add->expr_2->accept(this);
  std::string rhs = lastValue;
  
  std::string temp = new_reg();
  std::string op;

  if (dynamic_cast<Plus*>(e_add->addop_)){
    if (t == "double"){
    	op = "fadd";
    }
    else{
        op = "add";
    }
  }
  else if (dynamic_cast<Minus*>(e_add->addop_)){
    if (t == "double"){
    	op = "fsub";
    }
    else{
        op = "sub";
    }
  }

  liststmt.push_back("  " + temp + " = " + op + " " + last__type + " " + lhs + ", " + rhs);
  lastValue = temp;
  }
  
}

void CodeGen::visitERel(ERel *e_rel)
{
  /* Code For ERel Goes Here */
  if (num_passes1 == 1){
  e_rel->expr_1->accept(this);
  std::string t = last__type;
  std::string lhs = lastValue;
  e_rel->expr_2->accept(this);
  std::string rhs = lastValue;
  
  std::string temp = new_reg();
  std::string op;

  if (dynamic_cast<LTH*>(e_rel->relop_)){
    if (t == "double"){
    	op = "fcmp olt";
    }
    else{
    	op = "icmp slt";
    }
  }
  else if (dynamic_cast<LE*>(e_rel->relop_)){
    if (t == "double"){
    	op = "fcmp ole";
    }
    else{
    	op = "icmp sle";
    }
  }
  else if (dynamic_cast<GTH*>(e_rel->relop_)){
    if (t == "double"){
    	op = "fcmp ogt";
    }
    else{
    	op = "icmp sgt";
    }
  }
  else if (dynamic_cast<GE*>(e_rel->relop_)){
    if (t == "double"){
    	op = "fcmp oge";
    }
    else{
    	op = "icmp sge";
    }
  }
  else if (dynamic_cast<EQU*>(e_rel->relop_)){
    if (t == "double"){
    	op = "fcmp oeq";
    }
    else{
    	op = "icmp eq";
    }
  }
  else if (dynamic_cast<NE*>(e_rel->relop_)){
    if (t == "double"){
    	op = "fcmp one";
    }
    else{
    	op = "icmp ne";
    }
  }

  liststmt.push_back("  " + temp + " = " + op + " " + last__type + " " + lhs + ", " + rhs);
  lastValue = temp;
  }

}

void CodeGen::visitEAnd(EAnd *e_and)
{
  if (num_passes1 == 1) {
    std::string result = new_reg();

    // Evaluate LHS
    e_and->expr_1->accept(this);
    std::string lhs = lastValue;
    std::string lhsLabel = lastLabel;  // capture after lhs is evaluated

    std::string eval_rhs_label = new_label();
    std::string end_label = new_label();

    // Conditional branch after LHS
    liststmt.push_back("  br i1 " + lhs + ", label %" + eval_rhs_label + ", label %" + end_label);

    // RHS block
    liststmt.push_back(eval_rhs_label + ":");
    lastLabel = eval_rhs_label;
    e_and->expr_2->accept(this);
    std::string rhs = lastValue;
    std::string rhsLabel = lastLabel;  // for clarity
    liststmt.push_back("  br label %" + end_label);

    // End block with phi
    liststmt.push_back(end_label + ":");
    lastLabel = end_label;

    std::string phi = new_reg();
    liststmt.push_back("  " + phi + " = phi i1 [" + lhs + ", %" + lhsLabel + "], [" + rhs + ", %" + rhsLabel + "]");
    lastValue = phi;
  }
}


void CodeGen::visitEOr(EOr *e_or)
{
  if (num_passes1 == 1) {
    std::string result = new_reg();
    std::string f = lastLabel; 
    std::string eval_rhs_label = new_label();
    std::string end_label = new_label();

    e_or->expr_1->accept(this);
    std::string lhs = lastValue;

    // Conditional branch
    liststmt.push_back("  br i1 " + lhs + ", label %" + end_label + ", label %" + eval_rhs_label);

    // RHS block
    liststmt.push_back(eval_rhs_label + ":");
        lastLabel = eval_rhs_label;
    e_or->expr_2->accept(this);
    std::string rhs = lastValue;
    liststmt.push_back("  br label %" + end_label);

    // End block with phi
    liststmt.push_back(end_label + ":");
    lastLabel = end_label;
    std::string phi = new_reg();
    liststmt.push_back("  " + phi + " = phi i1 [" + lhs + ", %" + f + "], [" + rhs + ", %" + eval_rhs_label + "]");

    lastValue = phi;
  }
}

void CodeGen::visitPlus(Plus *plus)
{
  /* Code For Plus Goes Here */


}

void CodeGen::visitMinus(Minus *minus)
{
  /* Code For Minus Goes Here */


}

void CodeGen::visitTimes(Times *times)
{
  /* Code For Times Goes Here */


}

void CodeGen::visitDiv(Div *div)
{
  /* Code For Div Goes Here */


}

void CodeGen::visitMod(Mod *mod)
{
  /* Code For Mod Goes Here */


}

void CodeGen::visitLTH(LTH *lth)
{
  /* Code For LTH Goes Here */


}

void CodeGen::visitLE(LE *le)
{
  /* Code For LE Goes Here */


}

void CodeGen::visitGTH(GTH *gth)
{
  /* Code For GTH Goes Here */


}

void CodeGen::visitGE(GE *ge)
{
  /* Code For GE Goes Here */


}

void CodeGen::visitEQU(EQU *equ)
{
  /* Code For EQU Goes Here */


}

void CodeGen::visitNE(NE *ne)
{
  /* Code For NE Goes Here */


}


void CodeGen::visitListTopDef(ListTopDef *list_top_def)
{
  for (ListTopDef::iterator i = list_top_def->begin() ; i != list_top_def->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void CodeGen::visitListArg(ListArg *list_arg)
{
    if (num_passes1 == 1){
    for (ListArg::iterator i = list_arg->begin() ; i != list_arg->end() ; ++i)
    {
      (*i)->accept(this);
    }  
    }
}

void CodeGen::visitListStmt(ListStmt *list_stmt)
{
  if (num_passes1 == 0){
    for (ListStmt::iterator i = list_stmt->begin() ; i != list_stmt->end() ; ++i)
    {
      
      (*i)->accept(this);
    }
  }
  else if (num_passes1 == 1){
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

void CodeGen::visitListItem(ListItem *list_item)
{
  if (num_passes1 == 1){
  for (ListItem::iterator i = list_item->begin() ; i != list_item->end() ; ++i)
  {
    (*i)->accept(this);
  }
  }
}

void CodeGen::visitListType(ListType *list_type)
{
  for (ListType::iterator i = list_type->begin() ; i != list_type->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void CodeGen::visitListExpr(ListExpr *list_expr)
{
  if (num_passes1 == 1){
  funcargsreg.push_back({});
  for (ListExpr::iterator i = list_expr->begin() ; i != list_expr->end() ; ++i)
  {
    (*i)->accept(this);
    funcargsreg.back().push_back(last__type + " " + lastValue);
  }
  }
  else{
  for (ListExpr::iterator i = list_expr->begin() ; i != list_expr->end() ; ++i)
  {
    (*i)->accept(this);
  }
  }
}


void CodeGen::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
  last_type1 = TINT;
}

void CodeGen::visitChar(Char x)
{
  /* Code for Char Goes Here */

}

void CodeGen::visitDouble(Double x)
{
  /* Code for Double Goes Here */
  last_type1 = TDOUBLE;
}

void CodeGen::visitString(String x)
{
  /* Code for String Goes Here */
  last_type1 = TSTR;
}

void CodeGen::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
  
  /* last_type = lookupVariable(x); */
}


