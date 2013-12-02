/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_PARSER_HPP
# define YY_PARSER_HPP
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SEMI = 258,
     COLON = 259,
     COMMA = 260,
     CURLY_O = 261,
     CURLY_C = 262,
     PAREN_O = 263,
     PAREN_C = 264,
     ANGLE_O = 265,
     ANGLE_C = 266,
     BAR = 267,
     KEY_BOOL = 268,
     KEY_ELSE = 269,
     KEY_IF = 270,
     KEY_INT = 271,
     KEY_FOR = 272,
     KEY_VAR = 273,
     KEY_FUNC = 274,
     KEY_INTARRAY = 275,
     KEY_RET = 276,
     INT = 277,
     OCT = 278,
     HEX = 279,
     BIN = 280,
     IDENT = 281,
     ILLEGAL = 282,
     TRUE = 283,
     FALSE = 284,
     ASSIGN = 285,
     OP_LE = 286,
     OP_LT = 287,
     OP_GE = 288,
     OP_GT = 289,
     OP_EQ = 290,
     OP_NE = 291,
     OP_AND = 292,
     OP_OR = 293,
     MINUS = 294,
     PLUS = 295,
     DIV = 296,
     MULT = 297,
     OP_NOT = 298
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_PARSER_HPP  */
