//Automatically Generated C++ Abstract Syntax Tree Class Hierarchy

#include <algorithm>
#include "ast.hpp"
extern int yylineno;
#include "symtab.hpp"
#include "primitive.hpp"



/********* Program ************/
 Program::Program(list<Func_ptr> *p1)  {
	m_func_list = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		(*m_func_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 Program::Program(const Program & other) {
	m_func_list = new list<Func_ptr>;
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = other.m_func_list->begin();
	  m_func_list_iter != other.m_func_list->end();
	  ++m_func_list_iter){
		m_func_list->push_back( (*m_func_list_iter)->clone() );
	}
 }
 Program &Program::operator=(const Program & other) { Program tmp(other); swap(tmp); return *this; }
 void Program::swap(Program & other) {
	std::swap(m_func_list, other.m_func_list);
 }
 Program::~Program() {
 	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		delete( *m_func_list_iter );
	}
 }
 void Program::visit_children( Visitor* v ) {
 	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		(*m_func_list_iter)->accept( v );
	}
 }
 LatticeElemMap* Program::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		in = (*m_func_list_iter)->accept( v, in );
	}
	return in;
 }
 void Program::accept(Visitor *v) { v->visitProgram(this); }
 LatticeElemMap* Program::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitProgram(this, in); }
 Program *Program::clone() const { return new Program(*this); }
 
 
/********* Func ************/
 Func::Func(Type *p1, SymName *p2, list<Param_ptr> *p3, Function_block *p4)  {
	m_type = p1;
	m_symname = p2;
	m_param_list = p3;
	m_function_block = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_type->m_parent_attribute = &m_attribute;
 	m_symname->m_parent_attribute = &m_attribute;
 	list<Param_ptr>::iterator m_param_list_iter;
	for(m_param_list_iter = m_param_list->begin();
	  m_param_list_iter != m_param_list->end();
	  ++m_param_list_iter){
		(*m_param_list_iter)->m_parent_attribute = &m_attribute;
	}
	m_function_block->m_parent_attribute = &m_attribute;
  }
 Func::Func(const Func & other) {
	m_type = other.m_type->clone();
	m_symname = other.m_symname->clone();
	m_param_list = new list<Param_ptr>;
	list<Param_ptr>::iterator m_param_list_iter;
	for(m_param_list_iter = other.m_param_list->begin();
	  m_param_list_iter != other.m_param_list->end();
	  ++m_param_list_iter){
		m_param_list->push_back( (*m_param_list_iter)->clone() );
	}
	m_function_block = other.m_function_block->clone();
 }
 Func &Func::operator=(const Func & other) { Func tmp(other); swap(tmp); return *this; }
 void Func::swap(Func & other) {
	std::swap(m_type, other.m_type);
	std::swap(m_symname, other.m_symname);
	std::swap(m_param_list, other.m_param_list);
	std::swap(m_function_block, other.m_function_block);
 }
 Func::~Func() {
 	delete(m_type);
 	delete(m_symname);
 	list<Param_ptr>::iterator m_param_list_iter;
	for(m_param_list_iter = m_param_list->begin();
	  m_param_list_iter != m_param_list->end();
	  ++m_param_list_iter){
		delete( *m_param_list_iter );
	}
	delete(m_function_block);
  }
 void Func::visit_children( Visitor* v ) {
 	m_type->accept( v );
 	m_symname->accept( v );
 	list<Param_ptr>::iterator m_param_list_iter;
	for(m_param_list_iter = m_param_list->begin();
	  m_param_list_iter != m_param_list->end();
	  ++m_param_list_iter){
		(*m_param_list_iter)->accept( v );
	}
	m_function_block->accept( v );
  }
 LatticeElemMap* Func::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_type->accept( v, in );
 	in = m_symname->accept( v, in );
 	list<Param_ptr>::iterator m_param_list_iter;
	for(m_param_list_iter = m_param_list->begin();
	  m_param_list_iter != m_param_list->end();
	  ++m_param_list_iter){
		in = (*m_param_list_iter)->accept( v, in );
	}
	in = m_function_block->accept( v, in );
 	return in;
 }
 void Func::accept(Visitor *v) { v->visitFunc(this); }
 LatticeElemMap* Func::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitFunc(this, in); }
 Func *Func::clone() const { return new Func(*this); }
 
 
/********* Function_block ************/
 Function_block::Function_block(list<Decl_ptr> *p1, list<Func_ptr> *p2, list<Stat_ptr> *p3, Return *p4)  {
	m_decl_list = p1;
	m_func_list = p2;
	m_stat_list = p3;
	m_return = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->m_parent_attribute = &m_attribute;
	}
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		(*m_func_list_iter)->m_parent_attribute = &m_attribute;
	}
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->m_parent_attribute = &m_attribute;
	}
	m_return->m_parent_attribute = &m_attribute;
  }
 Function_block::Function_block(const Function_block & other) {
	m_decl_list = new list<Decl_ptr>;
	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = other.m_decl_list->begin();
	  m_decl_list_iter != other.m_decl_list->end();
	  ++m_decl_list_iter){
		m_decl_list->push_back( (*m_decl_list_iter)->clone() );
	}
	m_func_list = new list<Func_ptr>;
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = other.m_func_list->begin();
	  m_func_list_iter != other.m_func_list->end();
	  ++m_func_list_iter){
		m_func_list->push_back( (*m_func_list_iter)->clone() );
	}
	m_stat_list = new list<Stat_ptr>;
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = other.m_stat_list->begin();
	  m_stat_list_iter != other.m_stat_list->end();
	  ++m_stat_list_iter){
		m_stat_list->push_back( (*m_stat_list_iter)->clone() );
	}
	m_return = other.m_return->clone();
 }
 Function_block &Function_block::operator=(const Function_block & other) { Function_block tmp(other); swap(tmp); return *this; }
 void Function_block::swap(Function_block & other) {
	std::swap(m_decl_list, other.m_decl_list);
	std::swap(m_func_list, other.m_func_list);
	std::swap(m_stat_list, other.m_stat_list);
	std::swap(m_return, other.m_return);
 }
 Function_block::~Function_block() {
 	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		delete( *m_decl_list_iter );
	}
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		delete( *m_func_list_iter );
	}
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		delete( *m_stat_list_iter );
	}
	delete(m_return);
  }
 void Function_block::visit_children( Visitor* v ) {
 	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->accept( v );
	}
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		(*m_func_list_iter)->accept( v );
	}
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->accept( v );
	}
	m_return->accept( v );
  }
 LatticeElemMap* Function_block::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		in = (*m_decl_list_iter)->accept( v, in );
	}
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		in = (*m_func_list_iter)->accept( v, in );
	}
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		in = (*m_stat_list_iter)->accept( v, in );
	}
	in = m_return->accept( v, in );
 	return in;
 }
 void Function_block::accept(Visitor *v) { v->visitFunction_block(this); }
 LatticeElemMap* Function_block::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitFunction_block(this, in); }
 Function_block *Function_block::clone() const { return new Function_block(*this); }
 
 
/********* Nested_block ************/
 Nested_block::Nested_block(list<Stat_ptr> *p1)  {
	m_stat_list = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 Nested_block::Nested_block(const Nested_block & other) {
	m_stat_list = new list<Stat_ptr>;
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = other.m_stat_list->begin();
	  m_stat_list_iter != other.m_stat_list->end();
	  ++m_stat_list_iter){
		m_stat_list->push_back( (*m_stat_list_iter)->clone() );
	}
 }
 Nested_block &Nested_block::operator=(const Nested_block & other) { Nested_block tmp(other); swap(tmp); return *this; }
 void Nested_block::swap(Nested_block & other) {
	std::swap(m_stat_list, other.m_stat_list);
 }
 Nested_block::~Nested_block() {
 	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		delete( *m_stat_list_iter );
	}
 }
 void Nested_block::visit_children( Visitor* v ) {
 	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->accept( v );
	}
 }
 LatticeElemMap* Nested_block::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		in = (*m_stat_list_iter)->accept( v, in );
	}
	return in;
 }
 void Nested_block::accept(Visitor *v) { v->visitNested_block(this); }
 LatticeElemMap* Nested_block::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitNested_block(this, in); }
 Nested_block *Nested_block::clone() const { return new Nested_block(*this); }
 
 
/********* Param ************/
 Param::Param(Type *p1, SymName *p2)  {
	m_type = p1;
	m_symname = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_type->m_parent_attribute = &m_attribute;
 	m_symname->m_parent_attribute = &m_attribute;
  }
 Param::Param(const Param & other) {
	m_type = other.m_type->clone();
	m_symname = other.m_symname->clone();
 }
 Param &Param::operator=(const Param & other) { Param tmp(other); swap(tmp); return *this; }
 void Param::swap(Param & other) {
	std::swap(m_type, other.m_type);
	std::swap(m_symname, other.m_symname);
 }
 Param::~Param() {
 	delete(m_type);
 	delete(m_symname);
  }
 void Param::visit_children( Visitor* v ) {
 	m_type->accept( v );
 	m_symname->accept( v );
  }
 LatticeElemMap* Param::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_type->accept( v, in );
 	in = m_symname->accept( v, in );
 	return in;
 }
 void Param::accept(Visitor *v) { v->visitParam(this); }
 LatticeElemMap* Param::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitParam(this, in); }
 Param *Param::clone() const { return new Param(*this); }
 
 
/********* Decl ************/
 Decl::Decl(Type *p1, list<SymName_ptr> *p2)  {
	m_type = p1;
	m_symname_list = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_type->m_parent_attribute = &m_attribute;
 	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		(*m_symname_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 Decl::Decl(const Decl & other) {
	m_type = other.m_type->clone();
	m_symname_list = new list<SymName_ptr>;
	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = other.m_symname_list->begin();
	  m_symname_list_iter != other.m_symname_list->end();
	  ++m_symname_list_iter){
		m_symname_list->push_back( (*m_symname_list_iter)->clone() );
	}
 }
 Decl &Decl::operator=(const Decl & other) { Decl tmp(other); swap(tmp); return *this; }
 void Decl::swap(Decl & other) {
	std::swap(m_type, other.m_type);
	std::swap(m_symname_list, other.m_symname_list);
 }
 Decl::~Decl() {
 	delete(m_type);
 	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		delete( *m_symname_list_iter );
	}
 }
 void Decl::visit_children( Visitor* v ) {
 	m_type->accept( v );
 	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		(*m_symname_list_iter)->accept( v );
	}
 }
 LatticeElemMap* Decl::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_type->accept( v, in );
 	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		in = (*m_symname_list_iter)->accept( v, in );
	}
	return in;
 }
 void Decl::accept(Visitor *v) { v->visitDecl(this); }
 LatticeElemMap* Decl::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitDecl(this, in); }
 Decl *Decl::clone() const { return new Decl(*this); }
 
 
/********* Assignment ************/
 Assignment::Assignment(SymName *p1, Expr *p2)  {
	m_symname = p1;
	m_expr = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
 	m_expr->m_parent_attribute = &m_attribute;
  }
 Assignment::Assignment(const Assignment & other) {
	m_symname = other.m_symname->clone();
	m_expr = other.m_expr->clone();
 }
 Assignment &Assignment::operator=(const Assignment & other) { Assignment tmp(other); swap(tmp); return *this; }
 void Assignment::swap(Assignment & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr, other.m_expr);
 }
 Assignment::~Assignment() {
 	delete(m_symname);
 	delete(m_expr);
  }
 void Assignment::visit_children( Visitor* v ) {
 	m_symname->accept( v );
 	m_expr->accept( v );
  }
 LatticeElemMap* Assignment::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_symname->accept( v, in );
 	in = m_expr->accept( v, in );
 	return in;
 }
 void Assignment::accept(Visitor *v) { v->visitAssignment(this); }
 LatticeElemMap* Assignment::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitAssignment(this, in); }
 Assignment *Assignment::clone() const { return new Assignment(*this); }
 
 
/********* ArrayAssignment ************/
 ArrayAssignment::ArrayAssignment(SymName *p1, Expr *p2, Expr *p3)  {
	m_symname = p1;
	m_expr_1 = p2;
	m_expr_2 = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
 	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 ArrayAssignment::ArrayAssignment(const ArrayAssignment & other) {
	m_symname = other.m_symname->clone();
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 ArrayAssignment &ArrayAssignment::operator=(const ArrayAssignment & other) { ArrayAssignment tmp(other); swap(tmp); return *this; }
 void ArrayAssignment::swap(ArrayAssignment & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 ArrayAssignment::~ArrayAssignment() {
 	delete(m_symname);
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void ArrayAssignment::visit_children( Visitor* v ) {
 	m_symname->accept( v );
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* ArrayAssignment::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_symname->accept( v, in );
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void ArrayAssignment::accept(Visitor *v) { v->visitArrayAssignment(this); }
 LatticeElemMap* ArrayAssignment::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitArrayAssignment(this, in); }
 ArrayAssignment *ArrayAssignment::clone() const { return new ArrayAssignment(*this); }
 
 
/********* Call ************/
 Call::Call(SymName *p1, SymName *p2, list<Expr_ptr> *p3)  {
	m_symname_1 = p1;
	m_symname_2 = p2;
	m_expr_list = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname_1->m_parent_attribute = &m_attribute;
 	m_symname_2->m_parent_attribute = &m_attribute;
 	list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		(*m_expr_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 Call::Call(const Call & other) {
	m_symname_1 = other.m_symname_1->clone();
	m_symname_2 = other.m_symname_2->clone();
	m_expr_list = new list<Expr_ptr>;
	list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = other.m_expr_list->begin();
	  m_expr_list_iter != other.m_expr_list->end();
	  ++m_expr_list_iter){
		m_expr_list->push_back( (*m_expr_list_iter)->clone() );
	}
 }
 Call &Call::operator=(const Call & other) { Call tmp(other); swap(tmp); return *this; }
 void Call::swap(Call & other) {
	std::swap(m_symname_1, other.m_symname_1);
	std::swap(m_symname_2, other.m_symname_2);
	std::swap(m_expr_list, other.m_expr_list);
 }
 Call::~Call() {
 	delete(m_symname_1);
 	delete(m_symname_2);
 	list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		delete( *m_expr_list_iter );
	}
 }
 void Call::visit_children( Visitor* v ) {
 	m_symname_1->accept( v );
 	m_symname_2->accept( v );
 	list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		(*m_expr_list_iter)->accept( v );
	}
 }
 LatticeElemMap* Call::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_symname_1->accept( v, in );
 	in = m_symname_2->accept( v, in );
 	list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		in = (*m_expr_list_iter)->accept( v, in );
	}
	return in;
 }
 void Call::accept(Visitor *v) { v->visitCall(this); }
 LatticeElemMap* Call::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitCall(this, in); }
 Call *Call::clone() const { return new Call(*this); }
 
 
/********* ArrayCall ************/
 ArrayCall::ArrayCall(SymName *p1, Expr *p2, SymName *p3, list<Expr_ptr> *p4)  {
	m_symname_1 = p1;
	m_expr_1 = p2;
	m_symname_2 = p3;
	m_expr_list_2 = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname_1->m_parent_attribute = &m_attribute;
 	m_expr_1->m_parent_attribute = &m_attribute;
 	m_symname_2->m_parent_attribute = &m_attribute;
 	list<Expr_ptr>::iterator m_expr_list_2_iter;
	for(m_expr_list_2_iter = m_expr_list_2->begin();
	  m_expr_list_2_iter != m_expr_list_2->end();
	  ++m_expr_list_2_iter){
		(*m_expr_list_2_iter)->m_parent_attribute = &m_attribute;
	}
 }
 ArrayCall::ArrayCall(const ArrayCall & other) {
	m_symname_1 = other.m_symname_1->clone();
	m_expr_1 = other.m_expr_1->clone();
	m_symname_2 = other.m_symname_2->clone();
	m_expr_list_2 = new list<Expr_ptr>;
	list<Expr_ptr>::iterator m_expr_list_2_iter;
	for(m_expr_list_2_iter = other.m_expr_list_2->begin();
	  m_expr_list_2_iter != other.m_expr_list_2->end();
	  ++m_expr_list_2_iter){
		m_expr_list_2->push_back( (*m_expr_list_2_iter)->clone() );
	}
 }
 ArrayCall &ArrayCall::operator=(const ArrayCall & other) { ArrayCall tmp(other); swap(tmp); return *this; }
 void ArrayCall::swap(ArrayCall & other) {
	std::swap(m_symname_1, other.m_symname_1);
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_symname_2, other.m_symname_2);
	std::swap(m_expr_list_2, other.m_expr_list_2);
 }
 ArrayCall::~ArrayCall() {
 	delete(m_symname_1);
 	delete(m_expr_1);
 	delete(m_symname_2);
 	list<Expr_ptr>::iterator m_expr_list_2_iter;
	for(m_expr_list_2_iter = m_expr_list_2->begin();
	  m_expr_list_2_iter != m_expr_list_2->end();
	  ++m_expr_list_2_iter){
		delete( *m_expr_list_2_iter );
	}
 }
 void ArrayCall::visit_children( Visitor* v ) {
 	m_symname_1->accept( v );
 	m_expr_1->accept( v );
 	m_symname_2->accept( v );
 	list<Expr_ptr>::iterator m_expr_list_2_iter;
	for(m_expr_list_2_iter = m_expr_list_2->begin();
	  m_expr_list_2_iter != m_expr_list_2->end();
	  ++m_expr_list_2_iter){
		(*m_expr_list_2_iter)->accept( v );
	}
 }
 LatticeElemMap* ArrayCall::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_symname_1->accept( v, in );
 	in = m_expr_1->accept( v, in );
 	in = m_symname_2->accept( v, in );
 	list<Expr_ptr>::iterator m_expr_list_2_iter;
	for(m_expr_list_2_iter = m_expr_list_2->begin();
	  m_expr_list_2_iter != m_expr_list_2->end();
	  ++m_expr_list_2_iter){
		in = (*m_expr_list_2_iter)->accept( v, in );
	}
	return in;
 }
 void ArrayCall::accept(Visitor *v) { v->visitArrayCall(this); }
 LatticeElemMap* ArrayCall::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitArrayCall(this, in); }
 ArrayCall *ArrayCall::clone() const { return new ArrayCall(*this); }
 
 
/********* IfNoElse ************/
 IfNoElse::IfNoElse(Expr *p1, Nested_block *p2)  {
	m_expr = p1;
	m_nested_block = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
 	m_nested_block->m_parent_attribute = &m_attribute;
  }
 IfNoElse::IfNoElse(const IfNoElse & other) {
	m_expr = other.m_expr->clone();
	m_nested_block = other.m_nested_block->clone();
 }
 IfNoElse &IfNoElse::operator=(const IfNoElse & other) { IfNoElse tmp(other); swap(tmp); return *this; }
 void IfNoElse::swap(IfNoElse & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_nested_block, other.m_nested_block);
 }
 IfNoElse::~IfNoElse() {
 	delete(m_expr);
 	delete(m_nested_block);
  }
 void IfNoElse::visit_children( Visitor* v ) {
 	m_expr->accept( v );
 	m_nested_block->accept( v );
  }
 LatticeElemMap* IfNoElse::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr->accept( v, in );
 	in = m_nested_block->accept( v, in );
 	return in;
 }
 void IfNoElse::accept(Visitor *v) { v->visitIfNoElse(this); }
 LatticeElemMap* IfNoElse::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitIfNoElse(this, in); }
 IfNoElse *IfNoElse::clone() const { return new IfNoElse(*this); }
 
 
/********* IfWithElse ************/
 IfWithElse::IfWithElse(Expr *p1, Nested_block *p2, Nested_block *p3)  {
	m_expr = p1;
	m_nested_block_1 = p2;
	m_nested_block_2 = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
 	m_nested_block_1->m_parent_attribute = &m_attribute;
 	m_nested_block_2->m_parent_attribute = &m_attribute;
  }
 IfWithElse::IfWithElse(const IfWithElse & other) {
	m_expr = other.m_expr->clone();
	m_nested_block_1 = other.m_nested_block_1->clone();
	m_nested_block_2 = other.m_nested_block_2->clone();
 }
 IfWithElse &IfWithElse::operator=(const IfWithElse & other) { IfWithElse tmp(other); swap(tmp); return *this; }
 void IfWithElse::swap(IfWithElse & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_nested_block_1, other.m_nested_block_1);
	std::swap(m_nested_block_2, other.m_nested_block_2);
 }
 IfWithElse::~IfWithElse() {
 	delete(m_expr);
 	delete(m_nested_block_1);
 	delete(m_nested_block_2);
  }
 void IfWithElse::visit_children( Visitor* v ) {
 	m_expr->accept( v );
 	m_nested_block_1->accept( v );
 	m_nested_block_2->accept( v );
  }
 LatticeElemMap* IfWithElse::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr->accept( v, in );
 	in = m_nested_block_1->accept( v, in );
 	in = m_nested_block_2->accept( v, in );
 	return in;
 }
 void IfWithElse::accept(Visitor *v) { v->visitIfWithElse(this); }
 LatticeElemMap* IfWithElse::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitIfWithElse(this, in); }
 IfWithElse *IfWithElse::clone() const { return new IfWithElse(*this); }
 
 
/********* ForLoop ************/
 ForLoop::ForLoop(Stat *p1, Expr *p2, Stat *p3, Nested_block *p4)  {
	m_stat_1 = p1;
	m_expr = p2;
	m_stat_2 = p3;
	m_nested_block = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_stat_1->m_parent_attribute = &m_attribute;
 	m_expr->m_parent_attribute = &m_attribute;
 	m_stat_2->m_parent_attribute = &m_attribute;
 	m_nested_block->m_parent_attribute = &m_attribute;
  }
 ForLoop::ForLoop(const ForLoop & other) {
	m_stat_1 = other.m_stat_1->clone();
	m_expr = other.m_expr->clone();
	m_stat_2 = other.m_stat_2->clone();
	m_nested_block = other.m_nested_block->clone();
 }
 ForLoop &ForLoop::operator=(const ForLoop & other) { ForLoop tmp(other); swap(tmp); return *this; }
 void ForLoop::swap(ForLoop & other) {
	std::swap(m_stat_1, other.m_stat_1);
	std::swap(m_expr, other.m_expr);
	std::swap(m_stat_2, other.m_stat_2);
	std::swap(m_nested_block, other.m_nested_block);
 }
 ForLoop::~ForLoop() {
 	delete(m_stat_1);
 	delete(m_expr);
 	delete(m_stat_2);
 	delete(m_nested_block);
  }
 void ForLoop::visit_children( Visitor* v ) {
 	m_stat_1->accept( v );
 	m_expr->accept( v );
 	m_stat_2->accept( v );
 	m_nested_block->accept( v );
  }
 LatticeElemMap* ForLoop::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_stat_1->accept( v, in );
 	in = m_expr->accept( v, in );
 	in = m_stat_2->accept( v, in );
 	in = m_nested_block->accept( v, in );
 	return in;
 }
 void ForLoop::accept(Visitor *v) { v->visitForLoop(this); }
 LatticeElemMap* ForLoop::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitForLoop(this, in); }
 ForLoop *ForLoop::clone() const { return new ForLoop(*this); }
 
 
/********* None ************/
 None::None()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 None::None(const None & other) {
 }
 None &None::operator=(const None & other) { None tmp(other); swap(tmp); return *this; }
 void None::swap(None & other) {
 }
 None::~None() {
  }
 void None::visit_children( Visitor* v ) {
  }
 LatticeElemMap* None::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	return in;
 }
 void None::accept(Visitor *v) { v->visitNone(this); }
 LatticeElemMap* None::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitNone(this, in); }
 None *None::clone() const { return new None(*this); }
 
 
/********* Return ************/
 Return::Return(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Return::Return(const Return & other) {
	m_expr = other.m_expr->clone();
 }
 Return &Return::operator=(const Return & other) { Return tmp(other); swap(tmp); return *this; }
 void Return::swap(Return & other) {
	std::swap(m_expr, other.m_expr);
 }
 Return::~Return() {
 	delete(m_expr);
  }
 void Return::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 LatticeElemMap* Return::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr->accept( v, in );
 	return in;
 }
 void Return::accept(Visitor *v) { v->visitReturn(this); }
 LatticeElemMap* Return::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitReturn(this, in); }
 Return *Return::clone() const { return new Return(*this); }
 
 
/********* TInteger ************/
 TInteger::TInteger()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TInteger::TInteger(const TInteger & other) {
 }
 TInteger &TInteger::operator=(const TInteger & other) { TInteger tmp(other); swap(tmp); return *this; }
 void TInteger::swap(TInteger & other) {
 }
 TInteger::~TInteger() {
  }
 void TInteger::visit_children( Visitor* v ) {
  }
 LatticeElemMap* TInteger::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	return in;
 }
 void TInteger::accept(Visitor *v) { v->visitTInteger(this); }
 LatticeElemMap* TInteger::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitTInteger(this, in); }
 TInteger *TInteger::clone() const { return new TInteger(*this); }
 
 
/********* TBoolean ************/
 TBoolean::TBoolean()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TBoolean::TBoolean(const TBoolean & other) {
 }
 TBoolean &TBoolean::operator=(const TBoolean & other) { TBoolean tmp(other); swap(tmp); return *this; }
 void TBoolean::swap(TBoolean & other) {
 }
 TBoolean::~TBoolean() {
  }
 void TBoolean::visit_children( Visitor* v ) {
  }
 LatticeElemMap* TBoolean::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	return in;
 }
 void TBoolean::accept(Visitor *v) { v->visitTBoolean(this); }
 LatticeElemMap* TBoolean::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitTBoolean(this, in); }
 TBoolean *TBoolean::clone() const { return new TBoolean(*this); }
 
 
/********* TIntArray ************/
 TIntArray::TIntArray(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 TIntArray::TIntArray(const TIntArray & other) {
	m_primitive = other.m_primitive->clone();
 }
 TIntArray &TIntArray::operator=(const TIntArray & other) { TIntArray tmp(other); swap(tmp); return *this; }
 void TIntArray::swap(TIntArray & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 TIntArray::~TIntArray() {
 	delete(m_primitive);
  }
 void TIntArray::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 LatticeElemMap* TIntArray::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_primitive->accept( v, in );
 	return in;
 }
 void TIntArray::accept(Visitor *v) { v->visitTIntArray(this); }
 LatticeElemMap* TIntArray::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitTIntArray(this, in); }
 TIntArray *TIntArray::clone() const { return new TIntArray(*this); }
 
 
/********* And ************/
 And::And(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 And::And(const And & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 And &And::operator=(const And & other) { And tmp(other); swap(tmp); return *this; }
 void And::swap(And & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 And::~And() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void And::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* And::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void And::accept(Visitor *v) { v->visitAnd(this); }
 LatticeElemMap* And::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitAnd(this, in); }
 And *And::clone() const { return new And(*this); }
 
 
/********* Div ************/
 Div::Div(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Div::Div(const Div & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Div &Div::operator=(const Div & other) { Div tmp(other); swap(tmp); return *this; }
 void Div::swap(Div & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Div::~Div() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Div::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Div::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Div::accept(Visitor *v) { v->visitDiv(this); }
 LatticeElemMap* Div::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitDiv(this, in); }
 Div *Div::clone() const { return new Div(*this); }
 
 
/********* Compare ************/
 Compare::Compare(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Compare::Compare(const Compare & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Compare &Compare::operator=(const Compare & other) { Compare tmp(other); swap(tmp); return *this; }
 void Compare::swap(Compare & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Compare::~Compare() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Compare::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Compare::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Compare::accept(Visitor *v) { v->visitCompare(this); }
 LatticeElemMap* Compare::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitCompare(this, in); }
 Compare *Compare::clone() const { return new Compare(*this); }
 
 
/********* Gt ************/
 Gt::Gt(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Gt::Gt(const Gt & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Gt &Gt::operator=(const Gt & other) { Gt tmp(other); swap(tmp); return *this; }
 void Gt::swap(Gt & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Gt::~Gt() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Gt::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Gt::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Gt::accept(Visitor *v) { v->visitGt(this); }
 LatticeElemMap* Gt::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitGt(this, in); }
 Gt *Gt::clone() const { return new Gt(*this); }
 
 
/********* Gteq ************/
 Gteq::Gteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Gteq::Gteq(const Gteq & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Gteq &Gteq::operator=(const Gteq & other) { Gteq tmp(other); swap(tmp); return *this; }
 void Gteq::swap(Gteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Gteq::~Gteq() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Gteq::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Gteq::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Gteq::accept(Visitor *v) { v->visitGteq(this); }
 LatticeElemMap* Gteq::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitGteq(this, in); }
 Gteq *Gteq::clone() const { return new Gteq(*this); }
 
 
/********* Lt ************/
 Lt::Lt(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Lt::Lt(const Lt & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Lt &Lt::operator=(const Lt & other) { Lt tmp(other); swap(tmp); return *this; }
 void Lt::swap(Lt & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Lt::~Lt() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Lt::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Lt::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Lt::accept(Visitor *v) { v->visitLt(this); }
 LatticeElemMap* Lt::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitLt(this, in); }
 Lt *Lt::clone() const { return new Lt(*this); }
 
 
/********* Lteq ************/
 Lteq::Lteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Lteq::Lteq(const Lteq & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Lteq &Lteq::operator=(const Lteq & other) { Lteq tmp(other); swap(tmp); return *this; }
 void Lteq::swap(Lteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Lteq::~Lteq() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Lteq::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Lteq::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Lteq::accept(Visitor *v) { v->visitLteq(this); }
 LatticeElemMap* Lteq::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitLteq(this, in); }
 Lteq *Lteq::clone() const { return new Lteq(*this); }
 
 
/********* Minus ************/
 Minus::Minus(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Minus::Minus(const Minus & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Minus &Minus::operator=(const Minus & other) { Minus tmp(other); swap(tmp); return *this; }
 void Minus::swap(Minus & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Minus::~Minus() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Minus::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Minus::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Minus::accept(Visitor *v) { v->visitMinus(this); }
 LatticeElemMap* Minus::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitMinus(this, in); }
 Minus *Minus::clone() const { return new Minus(*this); }
 
 
/********* Noteq ************/
 Noteq::Noteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Noteq::Noteq(const Noteq & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Noteq &Noteq::operator=(const Noteq & other) { Noteq tmp(other); swap(tmp); return *this; }
 void Noteq::swap(Noteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Noteq::~Noteq() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Noteq::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Noteq::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Noteq::accept(Visitor *v) { v->visitNoteq(this); }
 LatticeElemMap* Noteq::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitNoteq(this, in); }
 Noteq *Noteq::clone() const { return new Noteq(*this); }
 
 
/********* Or ************/
 Or::Or(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Or::Or(const Or & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Or &Or::operator=(const Or & other) { Or tmp(other); swap(tmp); return *this; }
 void Or::swap(Or & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Or::~Or() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Or::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Or::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Or::accept(Visitor *v) { v->visitOr(this); }
 LatticeElemMap* Or::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitOr(this, in); }
 Or *Or::clone() const { return new Or(*this); }
 
 
/********* Plus ************/
 Plus::Plus(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Plus::Plus(const Plus & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Plus &Plus::operator=(const Plus & other) { Plus tmp(other); swap(tmp); return *this; }
 void Plus::swap(Plus & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Plus::~Plus() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Plus::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Plus::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Plus::accept(Visitor *v) { v->visitPlus(this); }
 LatticeElemMap* Plus::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitPlus(this, in); }
 Plus *Plus::clone() const { return new Plus(*this); }
 
 
/********* Times ************/
 Times::Times(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Times::Times(const Times & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Times &Times::operator=(const Times & other) { Times tmp(other); swap(tmp); return *this; }
 void Times::swap(Times & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Times::~Times() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Times::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 LatticeElemMap* Times::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr_1->accept( v, in );
 	in = m_expr_2->accept( v, in );
 	return in;
 }
 void Times::accept(Visitor *v) { v->visitTimes(this); }
 LatticeElemMap* Times::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitTimes(this, in); }
 Times *Times::clone() const { return new Times(*this); }
 
 
/********* Not ************/
 Not::Not(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Not::Not(const Not & other) {
	m_expr = other.m_expr->clone();
 }
 Not &Not::operator=(const Not & other) { Not tmp(other); swap(tmp); return *this; }
 void Not::swap(Not & other) {
	std::swap(m_expr, other.m_expr);
 }
 Not::~Not() {
 	delete(m_expr);
  }
 void Not::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 LatticeElemMap* Not::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr->accept( v, in );
 	return in;
 }
 void Not::accept(Visitor *v) { v->visitNot(this); }
 LatticeElemMap* Not::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitNot(this, in); }
 Not *Not::clone() const { return new Not(*this); }
 
 
/********* Uminus ************/
 Uminus::Uminus(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Uminus::Uminus(const Uminus & other) {
	m_expr = other.m_expr->clone();
 }
 Uminus &Uminus::operator=(const Uminus & other) { Uminus tmp(other); swap(tmp); return *this; }
 void Uminus::swap(Uminus & other) {
	std::swap(m_expr, other.m_expr);
 }
 Uminus::~Uminus() {
 	delete(m_expr);
  }
 void Uminus::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 LatticeElemMap* Uminus::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr->accept( v, in );
 	return in;
 }
 void Uminus::accept(Visitor *v) { v->visitUminus(this); }
 LatticeElemMap* Uminus::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitUminus(this, in); }
 Uminus *Uminus::clone() const { return new Uminus(*this); }
 
 
/********* Magnitude ************/
 Magnitude::Magnitude(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Magnitude::Magnitude(const Magnitude & other) {
	m_expr = other.m_expr->clone();
 }
 Magnitude &Magnitude::operator=(const Magnitude & other) { Magnitude tmp(other); swap(tmp); return *this; }
 void Magnitude::swap(Magnitude & other) {
	std::swap(m_expr, other.m_expr);
 }
 Magnitude::~Magnitude() {
 	delete(m_expr);
  }
 void Magnitude::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 LatticeElemMap* Magnitude::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_expr->accept( v, in );
 	return in;
 }
 void Magnitude::accept(Visitor *v) { v->visitMagnitude(this); }
 LatticeElemMap* Magnitude::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitMagnitude(this, in); }
 Magnitude *Magnitude::clone() const { return new Magnitude(*this); }
 
 
/********* Ident ************/
 Ident::Ident(SymName *p1)  {
	m_symname = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
  }
 Ident::Ident(const Ident & other) {
	m_symname = other.m_symname->clone();
 }
 Ident &Ident::operator=(const Ident & other) { Ident tmp(other); swap(tmp); return *this; }
 void Ident::swap(Ident & other) {
	std::swap(m_symname, other.m_symname);
 }
 Ident::~Ident() {
 	delete(m_symname);
  }
 void Ident::visit_children( Visitor* v ) {
 	m_symname->accept( v );
  }
 LatticeElemMap* Ident::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_symname->accept( v, in );
 	return in;
 }
 void Ident::accept(Visitor *v) { v->visitIdent(this); }
 LatticeElemMap* Ident::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitIdent(this, in); }
 Ident *Ident::clone() const { return new Ident(*this); }
 
 
/********* ArrayAccess ************/
 ArrayAccess::ArrayAccess(SymName *p1, Expr *p2)  {
	m_symname = p1;
	m_expr = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
 	m_expr->m_parent_attribute = &m_attribute;
  }
 ArrayAccess::ArrayAccess(const ArrayAccess & other) {
	m_symname = other.m_symname->clone();
	m_expr = other.m_expr->clone();
 }
 ArrayAccess &ArrayAccess::operator=(const ArrayAccess & other) { ArrayAccess tmp(other); swap(tmp); return *this; }
 void ArrayAccess::swap(ArrayAccess & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr, other.m_expr);
 }
 ArrayAccess::~ArrayAccess() {
 	delete(m_symname);
 	delete(m_expr);
  }
 void ArrayAccess::visit_children( Visitor* v ) {
 	m_symname->accept( v );
 	m_expr->accept( v );
  }
 LatticeElemMap* ArrayAccess::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_symname->accept( v, in );
 	in = m_expr->accept( v, in );
 	return in;
 }
 void ArrayAccess::accept(Visitor *v) { v->visitArrayAccess(this); }
 LatticeElemMap* ArrayAccess::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitArrayAccess(this, in); }
 ArrayAccess *ArrayAccess::clone() const { return new ArrayAccess(*this); }
 
 
/********* IntLit ************/
 IntLit::IntLit(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 IntLit::IntLit(const IntLit & other) {
	m_primitive = other.m_primitive->clone();
 }
 IntLit &IntLit::operator=(const IntLit & other) { IntLit tmp(other); swap(tmp); return *this; }
 void IntLit::swap(IntLit & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 IntLit::~IntLit() {
 	delete(m_primitive);
  }
 void IntLit::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 LatticeElemMap* IntLit::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_primitive->accept( v, in );
 	return in;
 }
 void IntLit::accept(Visitor *v) { v->visitIntLit(this); }
 LatticeElemMap* IntLit::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitIntLit(this, in); }
 IntLit *IntLit::clone() const { return new IntLit(*this); }
 
 
/********* BoolLit ************/
 BoolLit::BoolLit(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 BoolLit::BoolLit(const BoolLit & other) {
	m_primitive = other.m_primitive->clone();
 }
 BoolLit &BoolLit::operator=(const BoolLit & other) { BoolLit tmp(other); swap(tmp); return *this; }
 void BoolLit::swap(BoolLit & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 BoolLit::~BoolLit() {
 	delete(m_primitive);
  }
 void BoolLit::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 LatticeElemMap* BoolLit::visit_children( CFVisitor* v, LatticeElemMap *in ) {
 	in = m_primitive->accept( v, in );
 	return in;
 }
 void BoolLit::accept(Visitor *v) { v->visitBoolLit(this); }
 LatticeElemMap* BoolLit::accept(CFVisitor *v, LatticeElemMap *in) { return v->visitBoolLit(this, in); }
 BoolLit *BoolLit::clone() const { return new BoolLit(*this); }
 
 



