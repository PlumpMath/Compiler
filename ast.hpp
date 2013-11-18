#ifndef AST_HEADER
#define AST_HEADER

//Automatically Generated C++ Abstract Syntax Tree Interface

using namespace std;
#include <list>
#include <map>
#include "attribute.hpp"


/********** Forward Declarations **********/

class Program;
class Func;
class Function_block;
class Nested_block;
class Param;
class Decl;
class Assignment;
class Stat;
class ArrayAssignment;
class Call;
class ArrayCall;
class IfNoElse;
class IfWithElse;
class ForLoop;
class None;
class Return;
class TInteger;
class Type;
class TBoolean;
class TIntArray;
class And;
class Expr;
class Div;
class Compare;
class Gt;
class Gteq;
class Lt;
class Lteq;
class Minus;
class Noteq;
class Or;
class Plus;
class Times;
class Not;
class Uminus;
class Magnitude;
class Ident;
class ArrayAccess;
class IntLit;
class BoolLit;
class SymName;
class Primitive;


/********** Pointer Typedefs **********/

typedef Program* Program_ptr;

typedef Func* Func_ptr;
typedef Param* Param_ptr;
typedef Decl* Decl_ptr;
typedef Stat* Stat_ptr;
typedef SymName* SymName_ptr;
typedef Expr* Expr_ptr;


/********** Union Type (from parse) **********/

#ifdef YYSTYPE_IS_TRIVIAL
#error Make sure to include this file _before_ parser.hpp
#endif
typedef union
{
list<Func_ptr>* u_func_list;
Program* u_program;
list<Param_ptr>* u_param_list;
Func* u_func;
list<Decl_ptr>* u_decl_list;
list<Stat_ptr>* u_stat_list;
Function_block* u_function_block;
Nested_block* u_nested_block;
Param* u_param;
list<SymName_ptr>* u_symname_list;
Decl* u_decl;
Stat* u_stat;
list<Expr_ptr>* u_expr_list;
Return* u_return;
Type* u_type;
Expr* u_expr;
SymName* u_symname;
Primitive* u_primitive;

// a couple of hardcoded types
char* u_base_charptr;
int u_base_int;
} classunion_stype;
#define YYSTYPE classunion_stype


class Visitor;

class CFVisitor;



class Visitable
{
 public:
  Attribute m_attribute;

  Attribute* m_parent_attribute;

  virtual ~Visitable() {}
  virtual void visit_children(Visitor *v) = 0;
  virtual void accept(Visitor *v) = 0;
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in) = 0;
};


/********** Visitor Interfaces **********/

class Visitor {
 public:
  virtual ~Visitor() {}
  virtual void visitProgram(Program *p) = 0;
  virtual void visitFunc(Func *p) = 0;
  virtual void visitFunction_block(Function_block *p) = 0;
  virtual void visitNested_block(Nested_block *p) = 0;
  virtual void visitParam(Param *p) = 0;
  virtual void visitDecl(Decl *p) = 0;
  virtual void visitAssignment(Assignment *p) = 0;
  virtual void visitArrayAssignment(ArrayAssignment *p) = 0;
  virtual void visitCall(Call *p) = 0;
  virtual void visitArrayCall(ArrayCall *p) = 0;
  virtual void visitIfNoElse(IfNoElse *p) = 0;
  virtual void visitIfWithElse(IfWithElse *p) = 0;
  virtual void visitForLoop(ForLoop *p) = 0;
  virtual void visitNone(None *p) = 0;
  virtual void visitReturn(Return *p) = 0;
  virtual void visitTInteger(TInteger *p) = 0;
  virtual void visitTBoolean(TBoolean *p) = 0;
  virtual void visitTIntArray(TIntArray *p) = 0;
  virtual void visitAnd(And *p) = 0;
  virtual void visitDiv(Div *p) = 0;
  virtual void visitCompare(Compare *p) = 0;
  virtual void visitGt(Gt *p) = 0;
  virtual void visitGteq(Gteq *p) = 0;
  virtual void visitLt(Lt *p) = 0;
  virtual void visitLteq(Lteq *p) = 0;
  virtual void visitMinus(Minus *p) = 0;
  virtual void visitNoteq(Noteq *p) = 0;
  virtual void visitOr(Or *p) = 0;
  virtual void visitPlus(Plus *p) = 0;
  virtual void visitTimes(Times *p) = 0;
  virtual void visitNot(Not *p) = 0;
  virtual void visitUminus(Uminus *p) = 0;
  virtual void visitMagnitude(Magnitude *p) = 0;
  virtual void visitIdent(Ident *p) = 0;
  virtual void visitArrayAccess(ArrayAccess *p) = 0;
  virtual void visitIntLit(IntLit *p) = 0;
  virtual void visitBoolLit(BoolLit *p) = 0;
  virtual void visitSymName(SymName *p) = 0;
  virtual void visitPrimitive(Primitive *p) = 0;

  void visit(Visitable *p) {
    p -> accept(this);
  }


  template<class T>
  void visit_list(list<T*> *v) {
    typename list<T*>::iterator iter;
    for (iter = v->begin(); iter != v->end(); iter++)
      visit((*iter));
  }


  void visit_children_of(Visitable* p) {
    p -> visit_children(this);
  }
};


/********** CFVisitor Interfaces **********/

class CFVisitor {
 public:
  virtual ~CFVisitor() {}
  virtual LatticeElemMap* visitProgram(Program *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitFunc(Func *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitFunction_block(Function_block *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitNested_block(Nested_block *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitParam(Param *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitDecl(Decl *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitAssignment(Assignment *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitArrayAssignment(ArrayAssignment *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitCall(Call *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitArrayCall(ArrayCall *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitIfNoElse(IfNoElse *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitIfWithElse(IfWithElse *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitForLoop(ForLoop *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitNone(None *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitReturn(Return *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitTInteger(TInteger *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitTBoolean(TBoolean *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitTIntArray(TIntArray *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitAnd(And *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitDiv(Div *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitCompare(Compare *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitGt(Gt *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitGteq(Gteq *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitLt(Lt *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitLteq(Lteq *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitMinus(Minus *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitNoteq(Noteq *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitOr(Or *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitPlus(Plus *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitTimes(Times *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitNot(Not *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitUminus(Uminus *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitMagnitude(Magnitude *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitIdent(Ident *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitArrayAccess(ArrayAccess *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitIntLit(IntLit *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitBoolLit(BoolLit *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitSymName(SymName *p, LatticeElemMap *in) = 0;
  virtual LatticeElemMap* visitPrimitive(Primitive *p, LatticeElemMap *in) = 0;

  LatticeElemMap* visit(Visitable *p, LatticeElemMap *in) {
    return p -> accept(this, in);
  }


  template<class T>
  LatticeElemMap* visit_list(list<T*> *v, LatticeElemMap *in) {
    typename list<T*>::iterator iter;
    for (iter = v->begin(); iter != v->end(); iter++)
      in = visit(*iter, in);
    return in;
  }


  LatticeElemMap* visit_children_of(Visitable* p, LatticeElemMap *in) {
    return p -> visit_children(this, in);
  }
};


/********** Abstract Syntax Classes **********/

class Stat : public Visitable {
public:
  virtual Stat *clone() const = 0;
};

class Type : public Visitable {
public:
  virtual Type *clone() const = 0;
};

class Expr : public Visitable {
public:
  virtual Expr *clone() const = 0;
};


// Program ==> *Func
class Program : public Visitable
{
  public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
  list<Func_ptr> *m_func_list;

  Program(const Program &);
  Program &operator=(const Program &);
  Program(list<Func_ptr> *p1);
  ~Program();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Program  *clone() const;
  void swap(Program &);
};

// Func ==> Type SymName *Param Function_block
class Func : public Visitable
{
  public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
  Type *m_type;
  SymName *m_symname;
  list<Param_ptr> *m_param_list;
  Function_block *m_function_block;

  Func(const Func &);
  Func &operator=(const Func &);
  Func(Type *p1, SymName *p2, list<Param_ptr> *p3, Function_block *p4);
  ~Func();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Func  *clone() const;
  void swap(Func &);
};

// Function_block ==> *Decl *Func *Stat Return
class Function_block : public Visitable
{
  public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
  list<Decl_ptr> *m_decl_list;
  list<Func_ptr> *m_func_list;
  list<Stat_ptr> *m_stat_list;
  Return *m_return;

  Function_block(const Function_block &);
  Function_block &operator=(const Function_block &);
  Function_block(list<Decl_ptr> *p1, list<Func_ptr> *p2, list<Stat_ptr> *p3, Return *p4);
  ~Function_block();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Function_block  *clone() const;
  void swap(Function_block &);
};

// Nested_block ==> *Stat
class Nested_block : public Visitable
{
  public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
  list<Stat_ptr> *m_stat_list;

  Nested_block(const Nested_block &);
  Nested_block &operator=(const Nested_block &);
  Nested_block(list<Stat_ptr> *p1);
  ~Nested_block();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Nested_block  *clone() const;
  void swap(Nested_block &);
};

// Param ==> Type SymName
class Param : public Visitable
{
  public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
  Type *m_type;
  SymName *m_symname;

  Param(const Param &);
  Param &operator=(const Param &);
  Param(Type *p1, SymName *p2);
  ~Param();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Param  *clone() const;
  void swap(Param &);
};

// Decl ==> Type *SymName
class Decl : public Visitable
{
  public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
  Type *m_type;
  list<SymName_ptr> *m_symname_list;

  Decl(const Decl &);
  Decl &operator=(const Decl &);
  Decl(Type *p1, list<SymName_ptr> *p2);
  ~Decl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Decl  *clone() const;
  void swap(Decl &);
};

// Stat:Assignment ==> SymName Expr
class Assignment : public Stat
{
  public:
  SymName *m_symname;
  Expr *m_expr;

  Assignment(const Assignment &);
  Assignment &operator=(const Assignment &);
  Assignment(SymName *p1, Expr *p2);
  ~Assignment();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Assignment  *clone() const;
  void swap(Assignment &);
};

// Stat:ArrayAssignment ==> SymName Expr Expr
class ArrayAssignment : public Stat
{
  public:
  SymName *m_symname;
  Expr *m_expr_1;
  Expr *m_expr_2;

  ArrayAssignment(const ArrayAssignment &);
  ArrayAssignment &operator=(const ArrayAssignment &);
  ArrayAssignment(SymName *p1, Expr *p2, Expr *p3);
  ~ArrayAssignment();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  ArrayAssignment  *clone() const;
  void swap(ArrayAssignment &);
};

// Stat:Call ==> SymName SymName *Expr 
class Call : public Stat
{
  public:
  SymName *m_symname_1;
  SymName *m_symname_2;
  list<Expr_ptr> *m_expr_list;

  Call(const Call &);
  Call &operator=(const Call &);
  Call(SymName *p1, SymName *p2, list<Expr_ptr> *p3);
  ~Call();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Call  *clone() const;
  void swap(Call &);
};

// Stat:ArrayCall ==> SymName Expr SymName *Expr
class ArrayCall : public Stat
{
  public:
  SymName *m_symname_1;
  Expr *m_expr_1;
  SymName *m_symname_2;
  list<Expr_ptr> *m_expr_list_2;

  ArrayCall(const ArrayCall &);
  ArrayCall &operator=(const ArrayCall &);
  ArrayCall(SymName *p1, Expr *p2, SymName *p3, list<Expr_ptr> *p4);
  ~ArrayCall();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  ArrayCall  *clone() const;
  void swap(ArrayCall &);
};

// Stat:IfNoElse ==> Expr Nested_block 
class IfNoElse : public Stat
{
  public:
  Expr *m_expr;
  Nested_block *m_nested_block;

  IfNoElse(const IfNoElse &);
  IfNoElse &operator=(const IfNoElse &);
  IfNoElse(Expr *p1, Nested_block *p2);
  ~IfNoElse();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  IfNoElse  *clone() const;
  void swap(IfNoElse &);
};

// Stat:IfWithElse ==> Expr Nested_block Nested_block 
class IfWithElse : public Stat
{
  public:
  Expr *m_expr;
  Nested_block *m_nested_block_1;
  Nested_block *m_nested_block_2;

  IfWithElse(const IfWithElse &);
  IfWithElse &operator=(const IfWithElse &);
  IfWithElse(Expr *p1, Nested_block *p2, Nested_block *p3);
  ~IfWithElse();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  IfWithElse  *clone() const;
  void swap(IfWithElse &);
};

// Stat:ForLoop ==> Stat Expr Stat Nested_block
class ForLoop : public Stat
{
  public:
  Stat *m_stat_1;
  Expr *m_expr;
  Stat *m_stat_2;
  Nested_block *m_nested_block;

  ForLoop(const ForLoop &);
  ForLoop &operator=(const ForLoop &);
  ForLoop(Stat *p1, Expr *p2, Stat *p3, Nested_block *p4);
  ~ForLoop();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  ForLoop  *clone() const;
  void swap(ForLoop &);
};

// Stat:None ==> 
class None : public Stat
{
  public:

  None(const None &);
  None &operator=(const None &);
  None();
  ~None();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  None  *clone() const;
  void swap(None &);
};

// Return ==> Expr
class Return : public Visitable
{
  public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
  Expr *m_expr;

  Return(const Return &);
  Return &operator=(const Return &);
  Return(Expr *p1);
  ~Return();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Return  *clone() const;
  void swap(Return &);
};

// Type:TInteger ==> 
class TInteger : public Type
{
  public:

  TInteger(const TInteger &);
  TInteger &operator=(const TInteger &);
  TInteger();
  ~TInteger();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  TInteger  *clone() const;
  void swap(TInteger &);
};

// Type:TBoolean ==> 
class TBoolean : public Type
{
  public:

  TBoolean(const TBoolean &);
  TBoolean &operator=(const TBoolean &);
  TBoolean();
  ~TBoolean();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  TBoolean  *clone() const;
  void swap(TBoolean &);
};

// Type:TIntArray ==> Primitive
class TIntArray : public Type
{
  public:
  Primitive *m_primitive;

  TIntArray(const TIntArray &);
  TIntArray &operator=(const TIntArray &);
  TIntArray(Primitive *p1);
  ~TIntArray();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  TIntArray  *clone() const;
  void swap(TIntArray &);
};

// Expr:And ==> Expr Expr
class And : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  And(const And &);
  And &operator=(const And &);
  And(Expr *p1, Expr *p2);
  ~And();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  And  *clone() const;
  void swap(And &);
};

// Expr:Div ==> Expr Expr
class Div : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Div(const Div &);
  Div &operator=(const Div &);
  Div(Expr *p1, Expr *p2);
  ~Div();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Div  *clone() const;
  void swap(Div &);
};

// Expr:Compare ==> Expr Expr
class Compare : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Compare(const Compare &);
  Compare &operator=(const Compare &);
  Compare(Expr *p1, Expr *p2);
  ~Compare();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Compare  *clone() const;
  void swap(Compare &);
};

// Expr:Gt ==> Expr Expr
class Gt : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Gt(const Gt &);
  Gt &operator=(const Gt &);
  Gt(Expr *p1, Expr *p2);
  ~Gt();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Gt  *clone() const;
  void swap(Gt &);
};

// Expr:Gteq ==> Expr Expr
class Gteq : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Gteq(const Gteq &);
  Gteq &operator=(const Gteq &);
  Gteq(Expr *p1, Expr *p2);
  ~Gteq();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Gteq  *clone() const;
  void swap(Gteq &);
};

// Expr:Lt ==> Expr Expr
class Lt : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Lt(const Lt &);
  Lt &operator=(const Lt &);
  Lt(Expr *p1, Expr *p2);
  ~Lt();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Lt  *clone() const;
  void swap(Lt &);
};

// Expr:Lteq ==> Expr Expr
class Lteq : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Lteq(const Lteq &);
  Lteq &operator=(const Lteq &);
  Lteq(Expr *p1, Expr *p2);
  ~Lteq();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Lteq  *clone() const;
  void swap(Lteq &);
};

// Expr:Minus ==> Expr Expr
class Minus : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Minus(const Minus &);
  Minus &operator=(const Minus &);
  Minus(Expr *p1, Expr *p2);
  ~Minus();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Minus  *clone() const;
  void swap(Minus &);
};

// Expr:Noteq ==> Expr Expr
class Noteq : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Noteq(const Noteq &);
  Noteq &operator=(const Noteq &);
  Noteq(Expr *p1, Expr *p2);
  ~Noteq();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Noteq  *clone() const;
  void swap(Noteq &);
};

// Expr:Or ==> Expr Expr
class Or : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Or(const Or &);
  Or &operator=(const Or &);
  Or(Expr *p1, Expr *p2);
  ~Or();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Or  *clone() const;
  void swap(Or &);
};

// Expr:Plus ==> Expr Expr
class Plus : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Plus(const Plus &);
  Plus &operator=(const Plus &);
  Plus(Expr *p1, Expr *p2);
  ~Plus();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Plus  *clone() const;
  void swap(Plus &);
};

// Expr:Times ==> Expr Expr
class Times : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Times(const Times &);
  Times &operator=(const Times &);
  Times(Expr *p1, Expr *p2);
  ~Times();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Times  *clone() const;
  void swap(Times &);
};

// Expr:Not ==> Expr
class Not : public Expr
{
  public:
  Expr *m_expr;

  Not(const Not &);
  Not &operator=(const Not &);
  Not(Expr *p1);
  ~Not();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Not  *clone() const;
  void swap(Not &);
};

// Expr:Uminus ==> Expr
class Uminus : public Expr
{
  public:
  Expr *m_expr;

  Uminus(const Uminus &);
  Uminus &operator=(const Uminus &);
  Uminus(Expr *p1);
  ~Uminus();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Uminus  *clone() const;
  void swap(Uminus &);
};

// Expr:Magnitude ==> Expr
class Magnitude : public Expr
{
  public:
  Expr *m_expr;

  Magnitude(const Magnitude &);
  Magnitude &operator=(const Magnitude &);
  Magnitude(Expr *p1);
  ~Magnitude();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Magnitude  *clone() const;
  void swap(Magnitude &);
};

// Expr:Ident ==> SymName
class Ident : public Expr
{
  public:
  SymName *m_symname;

  Ident(const Ident &);
  Ident &operator=(const Ident &);
  Ident(SymName *p1);
  ~Ident();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  Ident  *clone() const;
  void swap(Ident &);
};

// Expr:ArrayAccess ==> SymName Expr
class ArrayAccess : public Expr
{
  public:
  SymName *m_symname;
  Expr *m_expr;

  ArrayAccess(const ArrayAccess &);
  ArrayAccess &operator=(const ArrayAccess &);
  ArrayAccess(SymName *p1, Expr *p2);
  ~ArrayAccess();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  ArrayAccess  *clone() const;
  void swap(ArrayAccess &);
};

// Expr:IntLit ==> Primitive
class IntLit : public Expr
{
  public:
  Primitive *m_primitive;

  IntLit(const IntLit &);
  IntLit &operator=(const IntLit &);
  IntLit(Primitive *p1);
  ~IntLit();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  IntLit  *clone() const;
  void swap(IntLit &);
};

// Expr:BoolLit ==> Primitive
class BoolLit : public Expr
{
  public:
  Primitive *m_primitive;

  BoolLit(const BoolLit &);
  BoolLit &operator=(const BoolLit &);
  BoolLit(Primitive *p1);
  ~BoolLit();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual LatticeElemMap* visit_children(CFVisitor *v, LatticeElemMap *in);
  virtual LatticeElemMap* accept(CFVisitor *v, LatticeElemMap *in);
  virtual  BoolLit  *clone() const;
  void swap(BoolLit &);
};




#endif //AST_HEADER

