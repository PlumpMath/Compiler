#include "ast.hpp"
#include "symtab.hpp"
#include "primitive.hpp"
#include "assert.h"
#include <typeinfo>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#define WORDSIZE 4

class Codegen : public Visitor
{
	private:

	FILE * m_outputfile;
	SymTab *m_st;

	// basic size of a word (integers and booleans) in bytes
	static const int wordsize = 1;

	int label_count; //access with new_label

	// ********** Helper functions ********************************

	// this is used to get new unique labels (cleverly named label1, label2, ...)
	int new_label() { return label_count++; }

	// this mode is used for the code
	void set_text_mode() { fprintf( m_outputfile, ".text\n\n"); }
	
	// PART 1:
	// 1) get arithmetic expressions on integers working:
	//	  you wont really be able to run your code,
	//	  but you can visually inspect it to see that the correct
	//<F2><F2><F2>    chains of opcodes are being generated.
	// 2) get function calls working:
	//    if you want to see at least a very simple program compile
	//    and link successfully against gcc-produced code, you
	//    need to get at least this far
	// 3) get boolean operation working
	//    before we can implement any of the conditional control flow 
	//    stuff, we need to have booleans worked out.  
	// 4) control flow:
	//    we need a way to have if-elses and for loops in our language. 
	//
	// Hint: Symbols have an associated member variable called m_offset
	//    That offset can be used to figure out where in the activation 
	//    record you should look for a particuar variable

	///////////////////////////////////////////////////////////////////////////////
	//
	//  function_prologue
	//  function_epilogue
	//
	//  Together these two functions implement the callee-side of the calling
	//  convention.  A stack frame has the following layout:
	//
	//                          <- SP (before pre-call / after post-ret)
	//  high -----------------
	//       | actual arg n  |
	//       | ...           |
	//       | actual arg 1  |  <- SP (just before call / just after ret)
	//       -----------------
	//       |  Return Addr  |  <- SP (just after call / just before ret)
	//       =================
	//       | previous %ebp |
	//       -----------------
	//       | temporary 1   |
	//       | ...           |
	//       | temporary n   |  <- SP (after prologue / before epilogue)
	//  low  -----------------
	//
	//
	//			  ||		
	//			  ||
	//			 \  /
	//			  \/
	//
	//
	//  The caller is responsible for placing the actual arguments
	//  and the return address on the stack. Actually, the return address
	//  is put automatically on the stack as part of the x86 call instruction.
	//
	//  On function entry, the callee
	//
	//  (1) allocates space for the callee's temporaries on the stack
	//  
	//  (2) saves callee-saved registers (see below) - including the previous activation record pointer (%ebp)
	//
	//  (3) makes the activation record pointer (frame pointer - %ebp) point to the start of the temporary region
	//
	//  (4) possibly copies the actual arguments into the temporary variables to allow easier access
	//
	//  On function exit, the callee:
	//
	//  (1) pops the callee's activation record (temporary area) off the stack
	//  
	//  (2) restores the callee-saved registers, including the activation record of the caller (%ebp)	 
	//
	//  (3) jumps to the return address (using the x86 "ret" instruction, this automatically pops the 
	//	  return address of the stack. After the ret, remove the arguments from the stack
	//
	//	For more info on this convention, see http://unixwiz.net/techtips/win32-callconv-asm.html
	//
	//	This convention is called __cdecl
	//
	//////////////////////////////////////////////////////////////////////////////
  
  void emit_prologue(SymName *name, unsigned int size_locals, unsigned int num_args)
  {
      int total_size = (size_locals +num_args+1)*WORDSIZE;
      stringstream ss;
      ss
          <<"_"<<name->spelling()<<":"<<endl
          <<"\t"<<"pushl \%ebp"<<" #Save Original EBP"<<endl
          <<"\t"<<"movl \%esp,\%ebp"<<" #Point EBP to top of stack"<<endl
          <<"\t"<<"subl $"<<total_size<<",\%esp"<<" #make room for local variables"<<endl;
      
      int param_off=0;
      int local_off=0;
      for (int i =0; i< num_args;i++)
      {
#if 1
          param_off = (1+num_args-i)*WORDSIZE;
          local_off = -(4*i+4); 
          ss
              <<"\t"<<"movl "<<param_off<<"(\%ebp),\%ebx"<<endl
              <<"\t"<<"movl \%ebx,"<<local_off<<"(\%ebp)"<<endl;
#endif 

      }
      fprintf( m_outputfile, "%s", ss.str().c_str());

  }

  void emit_arith(string op){
      stringstream ss;
      string div = "idivl";
       if(op==div){
       ss
          <<"\t"<<"popl \%ebx"<<endl
          <<"\t"<<"popl \%eax"<<endl
          <<"\t"<<"mov \%eax,\%edx"<<endl
          <<"\t"<<"sar "<<"$0x1f,\%edx"<<endl
          <<"\t"<<op<< " \%ebx"<<endl
          <<"\t"<<"pushl \%eax"<<endl;


      }
      else{
      ss
          <<"\t"<<"popl \%ebx"<<endl
          <<"\t"<<"popl \%eax"<<endl
          <<"\t"<<op<< " \%ebx,\%eax"<<endl
          <<"\t"<<"pushl \%eax"<<endl;
      }
      fprintf( m_outputfile, "%s", ss.str().c_str());


  }
 
  void emit_epilogue()
  {
      stringstream ss;
      ss
          <<"\t"<<"movl \%ebp,\%esp"<<endl
          <<"\t"<<"popl \%ebp"<<endl
          <<"\t"<<"ret"<<endl;
      fprintf( m_outputfile, "%s", ss.str().c_str());
  }
  
  // HERE: more functions to emit code

////////////////////////////////////////////////////////////////////////////////

public:
  
  Codegen(FILE * outputfile, SymTab * st)
  {
	m_outputfile = outputfile;
	m_st = st;
	
	label_count = 0;
  }
  
  void visitProgram(Program * p)
  {
    set_text_mode();
    // WRITEME
    stringstream ss;
      ss
          <<".globl _Main"<<endl;
      fprintf( m_outputfile, "%s", ss.str().c_str());
      visit_children_of(p);


  }
  void visitFunc(Func * p)
  {
     emit_prologue(p->m_symname, p->m_function_block->m_decl_list->size(),
             p->m_param_list->size());
     visit_children_of(p);


    // WRITEME
  }
  void visitFunction_block(Function_block * p)
  {

      stringstream ss;
#if 1
      int i = 0;
	list<Decl_ptr>::iterator m_decl_list_iter;
	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_decl_list_iter = p->m_decl_list->begin();
	  m_decl_list_iter != p->m_decl_list->end();
	  ++m_decl_list_iter){
        /*
       for(m_symname_list_iter= (*m_decl_list_iter)->m_symname_list->begin();
               m_symname_list_iter != (*m_decl_list_iter)->m_symname_list->end(); ++m_symname_list_iter){
           Symbol *s = new Symbol();

           char * name= strdup((*m_symname_list_iter)->spelling());
           m_st -> insert(name, s);
           */
       // add_decl_symbol((*m_decl_list_iter));
        
      fprintf( m_outputfile, "%s", ss.str().c_str());

	}
	
#endif
      visit_children_of(p);

     
  }
  void visitNested_block(Nested_block * p)
  {
    // WRITEME
  }
  void visitAssignment(Assignment * p)
  {
      stringstream ss;

      p->visit_children(this);
#if 1
      const char * name = p->m_symname->spelling();
      int off= m_st->lookup( p->m_attribute.m_scope,name)->get_offset();
      off = -(off+4);
      p->m_symname->m_attribute.m_place = off;
      ss
          <<"\t"<<"popl \%ebx"<<endl
          <<"\t"<<"movl \%ebx,"<<off<<"(\%ebp)"<<endl;

      fprintf( m_outputfile, "%s", ss.str().c_str());
#endif
      // WRITEME
  }
  void visitArrayAssignment(ArrayAssignment * p)
  {
      // WRITEME
  }
  void visitCall(Call * p)
  {
     // p->visit_children(this);
     //visit(p->m_symname_1);
     //visit(p->m_symname_2);
      stringstream ss;
      list<Expr_ptr>::iterator m_expr_list_iter;
      int param_size = p->m_expr_list->size();
      int i =0;
#if 1
    
     // for(m_expr_list_iter = p->m_expr_list->end() - 1;
     //         m_expr_list_iter != p->m_expr_list->begin();
     //         --m_expr_list_iter){
      list<Expr_ptr> * ab  =  new list<Expr_ptr>(*p->m_expr_list);
     for(int i=0;i<param_size;i++){
        visit(ab->back());
        ab->pop_back();
    
         ss
              <<"\t"<<"popl \%ebx"<<"#start visit call"<<endl
              //<<"\t"<<"movl \%ebx,"<<(param_size-i-1)*WORDSIZE<<"(\%esp)"
              <<"\t"<<"pushl \%ebx"<<endl;
    //      (*m_expr_list_iter)->m_attribute.m_place = (param_size-i-1)*WORDSIZE;
          i++;
      }
#endif


#if 0
      int param_size = p->m_expr_list->size();
      for (int i=0;i<param_size;i++)
      {
         ss
              <<"\t"<<"popl \%ebx"<<"#start visit call"<<endl
              <<"\t"<<"movl \%ebx,"<<(param_size-i-1)*WORDSIZE<<"(\%esp)"
              <<endl;
         *(p->m_expr_list[i])m_place=(param_size-i-1)*WORDSIZE;

       }

#endif
      ss
          <<"\t"<<"call _"<< p->m_symname_2->spelling()<<endl;
#if 1
           int off = -(m_st->lookup(p->m_attribute.m_scope,p->m_symname_1->spelling())->get_offset())-4; 
      ss
          <<"\tmovl "<<"\%eax,"<<off<<"(\%ebp)"<<"#end visit call"<<endl;
      for(m_expr_list_iter = p->m_expr_list->begin();
              m_expr_list_iter != p->m_expr_list->end();
              ++m_expr_list_iter){
         ss
              <<"\t"<<"popl \%ebx"<<endl;
      }
      //   cout<<p->m_symname->spelling()<<endl;

#endif





      fprintf( m_outputfile, "%s", ss.str().c_str());

      // WRITEME
  }
  void visitArrayCall(ArrayCall *p)
  {
      // WRITEME
  }
  void visitReturn(Return * p)
  {
      visit_children_of(p);
      stringstream ss;
      ss
          <<"\t"<<"popl "<<"\%eax"<<endl;
      fprintf( m_outputfile, "%s", ss.str().c_str());
      emit_epilogue();

  }

  // control flow
  void visitIfNoElse(IfNoElse * p)
  {// WRITEME

  }
  void visitIfWithElse(IfWithElse * p)
  {
      // WRITEME
  }
  void visitForLoop(ForLoop * p)
  {
      // WRITEME
  }


  void visitNone(None *p)
  {
      // Nothing is emitted
  }

  // variable declarations (no code generation needed)
  void visitDecl(Decl * p)
  {
  }
  void visitParam(Param *p)
  {
  }

  // types (no code generation needed)
  void visitTInteger(TInteger * p)
  {
  }
  void visitTBoolean(TBoolean * p)
  {
  }
  void visitTIntArray(TIntArray * p)
  {
  }

  // comparison operations
  void visitCompare(Compare * p)
  {
      // WRITEME
  }
  void visitNoteq(Noteq * p)
  {
      // WRITEME
  }
  void visitGt(Gt * p)
  {
      // WRITEME
  }
  void visitGteq(Gteq * p)
  {
      // WRITEME
  }
  void visitLt(Lt * p)
  {
      // WRITEME
  }
  void visitLteq(Lteq * p)
  {
      // WRITEME
  }

  // arithmetic and logic operations
  void visitAnd(And * p)
  {
      // WRITEME
  }
  void visitOr(Or * p)
  {
      // WRITEME
  }
  void visitMinus(Minus * p)
  {
      // WRITEME
      p->visit_children(this);
      emit_arith("subl");
  }
  void visitPlus(Plus * p)
  {
      p->visit_children(this);
      emit_arith("addl");
      // WRITEME
  }
  void visitTimes(Times * p)
  {
      p->visit_children(this);
      emit_arith("imull");
      // WRITEME
  }
  void visitDiv(Div * p)
  {
      p->visit_children(this);
      emit_arith("idivl");

      // WRITEME
  }
  void visitNot(Not * p)
  {
      // WRITEME
  }
  void visitUminus(Uminus * p)
  {
      // WRITEME
  }
  void visitMagnitude(Magnitude * p)
  {
      // WRITEME
  }

  // variable and constant access
  void visitIdent(Ident * p)
  {
      stringstream ss;
      p->visit_children(this);
#if 1
   //   cout<<p->m_symname->spelling()<<endl;
      int off = -(m_st->lookup( p->m_attribute.m_scope,p->m_symname->spelling())->get_offset())-4;
      ss
          <<"\tmovl "<<off<<"(\%ebp),"<<"\%ebx"<<endl
          <<"\t"<<"pushl \%ebx"<<endl;

      fprintf( m_outputfile, "%s", ss.str().c_str());
#endif

      // WRITEME
  }
  void visitIntLit(IntLit * p)
  {
      p->visit_children(this);
      stringstream ss;
      ss  <<"\t"<<"pushl $"<<p->m_primitive->m_data<<endl;
      fprintf( m_outputfile, "%s", ss.str().c_str());
  }
  void visitBoolLit(BoolLit * p)
  {
      // WRITEME
  }
  void visitArrayAccess(ArrayAccess * p)
  {
      // WRITEME
  }

  // special cases
  void visitSymName(SymName * p)
  {
  }
  void visitPrimitive(Primitive * p)
  {
  }
};

