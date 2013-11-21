#include "ast.hpp"
#include "primitive.hpp"
#include "attribute.hpp"
#include "symtab.hpp"
#include <iostream>

using namespace std;

/*
 * The only methods that are implemented for you are the For statement and a Not expression.
 * Use those two as a template. At the end of this analysis, each expression node should have a
 * valid LatticeElem associated with it.
 *
 * Overview of the code below:
 *
 *
 * LatticeElem:
 *   To see how to work with LatticeElem and LatticeElemMaps, open "attribute.hpp"
 *
 *   In short, LatticeElem is a class that stores a number, a value of a particular
 *   variable or stored in a node. You can just assign a number to it, or TOP or BOTTOM.
 *
 *   For example, to make an expression's value constant, you go:
 *     p -> m_attribute.m_lattice_elem = 5; -// or TOP or BOTTOM
 *
 *   LatticeElems can be compared to each other or to integers using the == operator. If you
 *   specifically need to access a LatticeElem's constant value, use it's public "value" field:
 *     int value = p -> m_attribute.m_lattice_elem.value;
 *
 *
 * LatticeElemMap:
 *   It is nothing but a map of type std::map<const char*, LatticeElem>
 *   http://en.cppreference.com/w/cpp/container/map
 *
 *   In short, you can just lookup a value using the [] operator with a char* as the
 *   argument representing the name of a variable. That will return the corresponding
 *   LatticeElem for a variable name; and if that variable was not stored in the map,
 *   its entry will be automatically added with value BOTTOM.
 *
 *   So, to lookup a LatticeElem in a LatticeElemMap *map, under a Symname "symname":
 *     LatticeElem &le = (*in)[symname->spelling()];
 *
 *   To store a value in the map you similarily go:
 *     (*in)[p->m_symname->spelling()] = TOP;
 *
 *   To clone a LatticeElemMap use a copy constructor. Look at the For statement for
 *   an example.
 *
 *   To JOIN one LatticeElemMap with another, call the join_lattice_maps() function. Example
 *   in the For statement implementation. Note that this function alters the 1st argument
 *   map to contain the join! 
 *
 * 
 * This visitor pattern is not as simple as the typecheck visitor.
 *
 * Each visit method receives an "in" LatticeElemMap, containing the information about variable states
 * from before the visit. You're supposed to edit this LatticeElemMap according to the rules of our constant
 * propagation and return it in the end.
 *
 * In addition, all Expression type nodes have a LatticeElem associated with them. This is the value of the
 * expression as determined by the analysis; by default, it's BOTTOM. You should set all these to either
 * constants, if the analysis can guarantee that an expression will be constant, or to TOP if the analysis 
 * cannot guarantee that an expression will be a constant. This LatticeElem can be accessed, for an expression node *p:
 *   p->m_attribute.m_lattice_elem
 *
 * To recursivelly do the analysis on all the children of a node, use "out = visit_children_of(node, in);"
 * Each child's "out" LatticeElemMap is propagated to the next child as it "in"; the last "out" is returned.
 *  
 * To visit a single child, use "out = visit(child_node, in);". To visit a child that is a list of nodes, use
 * "out = visit_list(list, in);" and the in/out sets are propagated between the individual elements.
 *
 *
 * The rules of our constant folding are:
 *   * All variables are uninitialized at the beginning of a function (TOP by default)
 *   * All assignments force the left hand side variable to the value of the right hand side
 *   * We are doing an intraprocedural analysis. This means that we do our analysis for each function
 *     separately, not minding other functions. As a consequence:
 *       + We assume each function always returns TOP. We will not assume anything more precise.
 *       + We don't assume anything about global variables; therefore they're (initially) TOP, and nothing one function
*         does to a global affects the same global in other functions.
*       + We assume that any function may alter any visible var's state. To simplify the analysis ALL variables should 
*         be set to TOP after each call statement.
*   * We are not keeping track of IntArrays. Any array element is assumed to be TOP at all times.
* Also:
*   * Anything multiplied by 0 is 0
*   * Dividing 0 by anything is always 0, and dividing anything by 0 makes the result TOP for the purposes of the analysis
*   * false AND anything is false, true OR anything is true
*
* While it is possible to do a more detailed analysis, that is not allowed in order to keep the grading fair. If you have 
* a good idea about doing a more precise analysis, great, talk to us about it, but for this assignment do exactly the 
* analysis posted here; no more and no less.
*/

class ConstantFolding : public CFVisitor {
    private:
        FILE* m_errorfile;
        SymTab* m_st;

    public:
        LatticeElemMap* visitProgram(Program *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitFunc(Func *p, LatticeElemMap *in)
        {
            // Intraprocedural; so let's start a new analysis for each function with a blank LatticeElemMap
            LatticeElemMap* newMap = new LatticeElemMap();
            newMap = visit_children_of(p, newMap);
            delete newMap;
            return in;
        }

        LatticeElemMap* visitFunction_block(Function_block *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            //p->m_attribute.m_lattice_elem = TOP;
#if 0
            list<Func_ptr>::iterator m_func_list_iter;
            for(m_func_list_iter = p->m_func_list->begin();
                    m_func_list_iter != p->m_func_list->end();
                    ++m_func_list_iter)
            {
                visit(*(m_func_list_iter), in);

            }

            list<Decl_ptr>::iterator m_decl_list_iter;
            for(m_decl_list_iter = p->m_decl_list->begin();
                    m_decl_list_iter != p->m_decl_list->end();
                    ++m_decl_list_iter)
            {
                visit(*(m_decl_list_iter), in);

            }
             visit(p->m_func_list, in);
             visit(p->m_return, in);
#endif

            return in;
        }

        LatticeElemMap* visitNested_block(Nested_block *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitParam(Param *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitDecl(Decl *p, LatticeElemMap *in)
        {
            //1m_type = p1;
            //1m_symname_list = p2;

            in = visit_children_of(p, in);
            LatticeElemMap* clone = new LatticeElemMap(*in);
            list<SymName_ptr>::iterator m_symname_list_iter;
            for(m_symname_list_iter = p->m_symname_list->begin();
                    m_symname_list_iter != p->m_symname_list->end();
                    ++m_symname_list_iter)
            {
               (*in)[ (*m_symname_list_iter)->spelling()]=TOP;

            }

            
            
            return in;
        }

        LatticeElemMap* visitReturn(Return *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitAssignment(Assignment *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);

            (*in)[p->m_symname->spelling()]=p->m_expr->m_attribute.m_lattice_elem;
            return in;
        }

        LatticeElemMap* visitArrayAssignment(ArrayAssignment *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitCall(Call *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
           LatticeElemMap::iterator iter;
           for (iter = in->begin(); iter != in->end(); iter++){
                   (*in)[iter->first]=TOP;

               }

            return in;
        }

        LatticeElemMap* visitArrayCall(ArrayCall *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitIfNoElse(IfNoElse *p, LatticeElemMap *in)
        {
	//m_expr = p1;
	//m_nested_block = p2;

            in = visit(p->m_expr, in);
            LatticeElemMap* clone = new LatticeElemMap(*in);
            clone = visit(p->m_nested_block, clone);
            join_lattice_elem_maps(clone, in);
            delete in;
            in = clone;
            return in;





        }

        LatticeElemMap* visitIfWithElse(IfWithElse *p, LatticeElemMap *in)
        {
#if 0
            m_expr = p1;
	m_nested_block_1 = p2;
	m_nested_block_2 = p3;
#endif
#if 0
            LatticeElemMap* clone1 = new LatticeElemMap(*in);
            clone1 = visit(p->m_nested_block_1, clone1);
            LatticeElemMap* clone2 = new LatticeElemMap(*in);
            clone2 = visit(p->m_nested_block_2, clone2);
            join_lattice_elem_maps(clone2, clone1);
            join_lattice_elem_maps(in, clone2);
            in = visit(p->m_expr, in);

            //Iterate through map if not TOP assign blank to map

            //loop through map if NOT top add to vector of char
            
#if 1

           LatticeElemMap::iterator iter;
           for (iter = clone2->begin(); iter != clone2->end(); iter++){
               if(iter->second.value!=TOP){
                   (*in)[iter->first]=iter->second.value;

               }
    }
#endif







           //join_lattice_elem_maps(in, clone2);
#endif

#if 1
            LatticeElemMap* clone = new LatticeElemMap(*in);
            in = visit(p->m_expr, in);
            clone = visit(p->m_nested_block_1, clone);
            in = visit(p->m_nested_block_2, in);

            join_lattice_elem_maps(clone, in);
            delete in;
            in = clone;
            return in;
#endif

        }

        LatticeElemMap* visitForLoop(ForLoop *p, LatticeElemMap *in)
        {
            // NOTE: this here is implemented for you. Use it as a template

            // For loops happen in this order: the initialization statement is executed,
            // the condition (expression) is evaluated, then the body is evaluated any
            // number of times, each time followed the by increment statement and the
            // condition again.
            //
            // Therefore, our expression receives input from either the statement
            // before the for, or from the block itself! But the block also receives
            // information from the expression. It goes in circles.
            //
            // Therefore, we're going to loop our LatticeElemMap through the for block
            // as long as there are changes to the LatticeElemMap. Once the LatticeElemMap
            // stops being changed by iterating through the block, we've reached a fix-point
            // and only then can we continue.


            // First, visit the initialization statement
            in = visit(p->m_stat_1, in);

            // Then visit the expression.
            in = visit(p->m_expr, in);

            // And then, as many times as needed,
            while(true) {
                // Copy this lattice elem map into another
                LatticeElemMap* clone = new LatticeElemMap(*in);

                // Visit the block using this clone
                clone = visit(p->m_nested_block, clone);
                // Visit the incrementer statement using this clone
                clone = visit(p->m_stat_2, clone);

                // Join the original "in" lattice_elem_map with the clone,
                // storing the result in the clone
                join_lattice_elem_maps(clone, in);

                // now visit the expression
                clone = visit(p->m_expr, clone);

                // Compare them
                bool equal = lattice_maps_equal(in, clone);

                // Make "in" point to the clone, deleting in
                delete in;
                in = clone;

                // If the clone was the same as "in", meaning that we've reached a fix-point,
                // we're done!
                if (equal)
                    return in;
            }
        }

        LatticeElemMap* visitNone(None *p, LatticeElemMap *in)
        {
            return in;
        }

        LatticeElemMap* visitTInteger(TInteger *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitTBoolean(TBoolean *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitTIntArray(TIntArray *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitAnd(And *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if(e1==0||e2==0)
                p->m_attribute.m_lattice_elem = 0;
            else if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value && e2.value;
            return in;


        }

        LatticeElemMap* visitOr(Or *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if(e1==1||e2==1)
                p->m_attribute.m_lattice_elem = 1;
            else if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value || e2.value;
            in = visit_children_of(p, in);
            return in;



        }

        LatticeElemMap* visitCompare(Compare *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value== e2.value;
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitNoteq(Noteq *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value!= e2.value;
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitGt(Gt *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value> e2.value;
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitGteq(Gteq *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value>= e2.value;
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitLt(Lt *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value< e2.value;
            in = visit_children_of(p, in);
            return in;

        }

        LatticeElemMap* visitLteq(Lteq *p, LatticeElemMap *in)
        {

            in = visit_children_of(p, in);
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value>= e2.value;
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitUminus(Uminus *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitMagnitude(Magnitude *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitPlus(Plus *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);

            //m_expr_1 = p1;
            //m_expr_2 = p2;
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well
            if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value + e2.value;






            return in;
        }

        LatticeElemMap* visitMinus(Minus *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);

            //m_expr_1 = p1;
            //m_expr_2 = p2;
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well
            if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value - e2.value;






            return in;

        }

        LatticeElemMap* visitTimes(Times *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);

            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if(e1 == 0|| e2==0)
                p->m_attribute.m_lattice_elem = 0;
            else if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value * e2.value;



            return in;
        }

        LatticeElemMap* visitDiv(Div *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            // Read that lattice element
            LatticeElem &e1 = p->m_expr_1->m_attribute.m_lattice_elem;
            LatticeElem &e2 = p->m_expr_2->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well

            if(e1 == 0)
                p->m_attribute.m_lattice_elem = 0;
            if(e2 == 0)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==TOP||e2 == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else if (e1==BOTTOM||e2 == BOTTOM)
                p->m_attribute.m_lattice_elem = BOTTOM;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = e1.value / e2.value;
            return in;

        }

        LatticeElemMap* visitNot(Not *p, LatticeElemMap *in)
        {
            // First visit the child expression. After this line of code, the child
            // expression should have a valid LatticeElem stored inside it
            in = visit_children_of(p, in);

            // Read that lattice element
            LatticeElem &e = p->m_expr->m_attribute.m_lattice_elem;

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well
            if (e == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = !(e.value);

            // And now we return the LatticeElemMap. We didn't modify it, we didn't need to.
            return in;
        }

        LatticeElemMap* visitIdent(Ident *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            LatticeElem &le = (*in)[p->m_symname->spelling()];

            // If it's TOP, then we cannot know anything about this expression; it should be TOP as well
            if (le == TOP)
                p->m_attribute.m_lattice_elem = TOP;
            else
                // Otherwise, it contains the boolean opposite of the child's LatticeElem
                p->m_attribute.m_lattice_elem = (le.value);




            return in;
        }

        LatticeElemMap* visitArrayAccess(ArrayAccess *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitIntLit(IntLit *p, LatticeElemMap *in)
        {
            // store the constant's value in this expression's LatticeElem
            p->m_attribute.m_lattice_elem = p -> m_primitive -> m_data;
            return in;
        }

        LatticeElemMap* visitBoolLit(BoolLit *p, LatticeElemMap *in)
        {
            // store the constant's value in this expression's LatticeElem
            p->m_attribute.m_lattice_elem = p -> m_primitive -> m_data;
            return in;
        }

        LatticeElemMap* visitSymName(SymName *p, LatticeElemMap *in)
        {
            in = visit_children_of(p, in);
            return in;
        }

        LatticeElemMap* visitPrimitive(Primitive *p, LatticeElemMap *in)
        {
            return in;
        }

        ConstantFolding(FILE* errorfile, SymTab* st) 
        {
            m_errorfile = errorfile;
            m_st = st; 
        }

        ~ConstantFolding() {}
};


