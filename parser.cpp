/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.6.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 336 of yacc.c  */
#line 1 "parser.ypp"

	#include <stdio.h>
	#include <stdlib.h>

    	#include "ast.hpp"
    	#include "primitive.hpp"
    	#include "symtab.hpp"

	#define YYDEBUG 1

    	extern Program_ptr ast;
	int yylex(void);
	void yyerror(const char *);
	

/* Line 336 of yacc.c  */
#line 84 "parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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

/* Copy the second part of user declarations.  */

/* Line 353 of yacc.c  */
#line 193 "parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    20,    25,    27,    29,
      30,    34,    36,    40,    43,    44,    50,    54,    56,    58,
      60,    62,    67,    70,    71,    74,    75,    77,    79,    87,
      99,   111,   113,   114,   118,   123,   131,   139,   150,   153,
     154,   158,   159,   163,   167,   171,   175,   179,   183,   187,
     191,   195,   199,   203,   207,   210,   213,   215,   217,   222,
     226,   230,   232,   234,   236,   238,   240,   242
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    46,    47,    -1,    -1,    19,
      26,     8,    50,     9,     4,    56,     6,    48,     7,    -1,
      53,    58,    59,    62,    -1,    59,    -1,    51,    -1,    -1,
      51,     5,    52,    -1,    52,    -1,    26,     4,    56,    -1,
      53,    54,    -1,    -1,    18,    55,     4,    57,     3,    -1,
      55,     5,    26,    -1,    26,    -1,    13,    -1,    16,    -1,
      56,    -1,    20,    10,    69,    11,    -1,    58,    47,    -1,
      -1,    59,    60,    -1,    -1,    63,    -1,    64,    -1,    15,
       8,    67,     9,     6,    49,     7,    -1,    15,     8,    67,
       9,     6,    49,     7,    14,     6,    49,     7,    -1,    17,
       8,    61,     8,    67,     9,    61,     9,     6,    49,     7,
      -1,    63,    -1,    -1,    21,    67,     3,    -1,    26,    30,
      67,     3,    -1,    26,    10,    67,    11,    30,    67,     3,
      -1,    26,    30,    26,     8,    65,     9,     3,    -1,    26,
      10,    67,    11,    30,    26,     8,    65,     9,     3,    -1,
      66,    67,    -1,    -1,    66,    67,     5,    -1,    -1,    67,
      40,    67,    -1,    67,    39,    67,    -1,    67,    42,    67,
      -1,    67,    41,    67,    -1,    67,    37,    67,    -1,    67,
      38,    67,    -1,    67,    36,    67,    -1,    67,    35,    67,
      -1,    67,    34,    67,    -1,    67,    33,    67,    -1,    67,
      32,    67,    -1,    67,    31,    67,    -1,    43,    67,    -1,
      39,    67,    -1,    68,    -1,    26,    -1,    26,    10,    67,
      11,    -1,     8,    67,     9,    -1,    12,    67,    12,    -1,
      69,    -1,    28,    -1,    29,    -1,    22,    -1,    24,    -1,
      25,    -1,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    32,    32,    35,    36,    39,    43,    47,    50,    51,
      54,    55,    58,    61,    62,    65,    68,    69,    72,    73,
      76,    77,    80,    81,    84,    85,    88,    89,    90,    91,
      93,    96,    97,   100,   103,   104,   107,   109,   113,   114,
     117,   118,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   142,   143,   144,   147,   148,   149,   150
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMI", "COLON", "COMMA", "CURLY_O",
  "CURLY_C", "PAREN_O", "PAREN_C", "ANGLE_O", "ANGLE_C", "BAR", "KEY_BOOL",
  "KEY_ELSE", "KEY_IF", "KEY_INT", "KEY_FOR", "KEY_VAR", "KEY_FUNC",
  "KEY_INTARRAY", "KEY_RET", "INT", "OCT", "HEX", "BIN", "IDENT",
  "ILLEGAL", "TRUE", "FALSE", "ASSIGN", "OP_LE", "OP_LT", "OP_GE", "OP_GT",
  "OP_EQ", "OP_NE", "OP_AND", "OP_OR", "MINUS", "PLUS", "DIV", "MULT",
  "OP_NOT", "$accept", "program", "functions", "function", "body",
  "nest_block", "f_params", "f_params_", "param", "var_decls", "var_decl",
  "var_list", "type", "atype", "func_decls", "stmts", "stmt", "opt_assign",
  "ret_stmt", "assignment", "fct_call", "expr_list", "expr_list_", "expr",
  "literal", "integer", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    48,    49,    50,    50,
      51,    51,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    61,    61,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    69,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,    10,     4,     1,     1,     0,
       3,     1,     3,     2,     0,     5,     3,     1,     1,     1,
       1,     4,     2,     0,     2,     0,     1,     1,     7,    11,
      11,     1,     0,     3,     4,     7,     7,    10,     2,     0,
       3,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     4,     3,
       3,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     3,     0,     9,     0,     0,
       8,    11,     0,     0,     0,    18,    19,    12,     0,    10,
       0,    14,     0,    23,     5,     0,    13,    25,    17,     0,
      22,     0,     0,     0,     0,     0,     0,     0,    24,     6,
      26,    27,     0,    20,     0,    16,     0,    32,     0,     0,
      64,    67,    65,    66,    57,    62,    63,     0,     0,     0,
      56,    61,     0,     0,     0,    15,     0,     0,     0,    31,
       0,     0,     0,    55,    54,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,    59,    60,     0,    53,
      52,    51,    50,    49,    48,    46,    47,    43,    42,    45,
      44,     0,    41,    34,    21,    25,     0,     0,    58,     0,
       0,     0,     0,     7,     0,    32,    57,     0,     0,    38,
      28,     0,     0,    41,    35,    36,    40,     0,     0,     0,
      25,    25,     0,     0,     0,    37,    29,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,    22,   122,     9,    10,    11,    23,
      26,    29,    17,    44,    27,   123,    38,    68,    39,    40,
      41,   120,   121,    90,    60,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -61
static const yytype_int16 yypact[] =
{
     -61,     9,    -4,   -61,    -1,   -61,    22,     8,    35,    47,
      53,   -61,    15,    78,     8,   -61,   -61,   -61,    15,   -61,
      80,   -61,    82,    70,   -61,    61,   -61,    -4,   -61,    73,
     -61,    12,    -2,    64,    83,    84,   128,    -7,   -61,   -61,
     -61,   -61,    86,   -61,    90,   -61,   128,    68,   128,   128,
     -61,   -61,   -61,   -61,    87,   -61,   -61,   128,   128,    29,
     -61,   -61,   128,   136,    30,   -61,   176,    -6,    91,   -61,
     189,   297,   128,   -61,   -61,   -61,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   222,    -3,
      69,   126,   132,   128,   128,   128,   -61,   -61,   254,    34,
      34,    34,    34,    34,    34,    34,    34,   -22,   -22,   -61,
     -61,   109,   133,   -61,   -61,   -61,   266,   210,   -61,   158,
     134,   128,   138,    -9,   111,    68,    27,    81,   143,    93,
     135,   128,   146,   133,   -61,   -61,   -61,   141,   157,   159,
     -61,   -61,   166,   165,   167,   -61,   -61,   -61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   -61,   149,   -61,   -60,   -61,   -61,   163,   -61,
     -61,   -61,   -16,   -61,   -61,   151,   -61,    48,   -61,   -46,
     -61,    55,   -61,   -36,   -61,   125
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int16 yytable[] =
{
      59,    69,    20,    62,    93,   112,    34,    72,    35,     3,
      66,    15,    70,    71,    16,     4,    43,    37,    42,    86,
      87,    73,    74,    63,    94,     6,    88,    34,    15,    35,
       7,    16,    75,    36,     8,   133,    98,    72,    37,    12,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    50,    51,    52,    53,    13,   116,    14,   117,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   113,    84,    85,    86,    87,    32,    33,    69,
     143,   144,    18,   127,   134,   129,    21,    28,    25,    24,
      45,    46,    47,    65,    67,   127,    64,    72,   136,    95,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    48,   114,   115,   119,
      49,   131,   -39,   128,    48,   130,   135,   140,    49,   137,
      50,    51,    52,    53,    54,   138,    55,    56,    50,    51,
      52,    53,    89,   141,    55,    56,    48,    57,   142,   145,
      49,    58,   146,   132,   147,    57,    30,    19,    31,    58,
      50,    51,    52,    53,   126,    92,    55,    56,   139,    91,
       0,     0,     0,     0,     0,     0,     0,    57,    96,     0,
       0,    58,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   125,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,   111,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-61))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      36,    47,    18,    10,    10,     8,    15,    10,    17,     0,
      46,    13,    48,    49,    16,    19,    32,    26,    20,    41,
      42,    57,    58,    30,    30,    26,    62,    15,    13,    17,
       8,    16,     3,    21,    26,     8,    72,    10,    26,     4,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    22,    23,    24,    25,     9,    93,     5,    95,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     3,    39,    40,    41,    42,     4,     5,   125,
     140,   141,     4,   119,     3,   121,     6,    26,    18,     7,
      26,     8,     8,     3,    26,   131,    10,    10,     5,     8,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     8,    11,     6,    30,
      12,    30,     9,     9,     8,     7,     3,     6,    12,    14,
      22,    23,    24,    25,    26,     9,    28,    29,    22,    23,
      24,    25,    26,     6,    28,    29,     8,    39,     9,     3,
      12,    43,     7,   125,     7,    39,    27,    14,    27,    43,
      22,    23,    24,    25,    26,     9,    28,    29,   133,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,     9,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     9,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,    19,    47,    26,     8,    26,    50,
      51,    52,     4,     9,     5,    13,    16,    56,     4,    52,
      56,     6,    48,    53,     7,    18,    54,    58,    26,    55,
      47,    59,     4,     5,    15,    17,    21,    26,    60,    62,
      63,    64,    20,    56,    57,    26,     8,     8,     8,    12,
      22,    23,    24,    25,    26,    28,    29,    39,    43,    67,
      68,    69,    10,    30,    10,     3,    67,    26,    61,    63,
      67,    67,    10,    67,    67,     3,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    67,    26,
      67,    69,     9,    10,    30,     8,     9,    12,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    11,     8,     3,    11,     6,    67,    67,    11,    30,
      65,    66,    49,    59,    11,     9,    26,    67,     9,    67,
       7,    30,    61,     8,     3,     3,     5,    14,     9,    65,
       6,     6,     9,    49,    49,     3,     7,     7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 32 "parser.ypp"
    {ast = new Program((yyvsp[(1) - (1)]).u_func_list);}
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 35 "parser.ypp"
    {(yyvsp[(1) - (2)]).u_func_list -> push_back((yyvsp[(2) - (2)]).u_func); (yyval) = (yyvsp[(1) - (2)]);}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 36 "parser.ypp"
    {(yyval).u_func_list = new list<Func_ptr>();}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 40 "parser.ypp"
    {(yyval).u_func = new Func((yyvsp[(7) - (10)]).u_type, new SymName((yyvsp[(2) - (10)]).u_base_charptr), (yyvsp[(4) - (10)]).u_param_list, (yyvsp[(9) - (10)]).u_function_block);}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 44 "parser.ypp"
    {(yyval).u_function_block = new Function_block((yyvsp[(1) - (4)]).u_decl_list, (yyvsp[(2) - (4)]).u_func_list, (yyvsp[(3) - (4)]).u_stat_list, (yyvsp[(4) - (4)]).u_return);}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 47 "parser.ypp"
    {(yyval).u_nested_block = new Nested_block((yyvsp[(1) - (1)]).u_stat_list);}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 50 "parser.ypp"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 51 "parser.ypp"
    { (yyval).u_param_list = new list<Param_ptr>(); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 54 "parser.ypp"
    { (yyvsp[(1) - (3)]).u_param_list -> push_back((yyvsp[(3) - (3)]).u_param); (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 55 "parser.ypp"
    { (yyval).u_param_list = new list<Param_ptr>(); (yyval).u_param_list -> push_back((yyvsp[(1) - (1)]).u_param); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 58 "parser.ypp"
    { (yyval).u_param = new Param((yyvsp[(3) - (3)]).u_type, new SymName((yyvsp[(1) - (3)]).u_base_charptr)); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 61 "parser.ypp"
    {(yyvsp[(1) - (2)]).u_decl_list -> push_back((yyvsp[(2) - (2)]).u_decl); (yyval) = (yyvsp[(1) - (2)]);}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 62 "parser.ypp"
    {(yyval).u_decl_list = new list<Decl_ptr>();}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 65 "parser.ypp"
    {(yyval).u_decl = new Decl((yyvsp[(4) - (5)]).u_type, (yyvsp[(2) - (5)]).u_symname_list);}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 68 "parser.ypp"
    {(yyvsp[(1) - (3)]).u_symname_list -> push_back(new SymName((yyvsp[(3) - (3)]).u_base_charptr)); (yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 69 "parser.ypp"
    {(yyval).u_symname_list = new list<SymName_ptr>(); (yyval).u_symname_list -> push_back(new SymName((yyvsp[(1) - (1)]).u_base_charptr));}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 72 "parser.ypp"
    {(yyval).u_type = new TBoolean();}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 73 "parser.ypp"
    {(yyval).u_type = new TInteger();}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 76 "parser.ypp"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 77 "parser.ypp"
    {(yyval).u_type = new TIntArray((yyvsp[(3) - (4)]).u_primitive);}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 80 "parser.ypp"
    {(yyvsp[(1) - (2)]).u_func_list -> push_back((yyvsp[(2) - (2)]).u_func); (yyval) = (yyvsp[(1) - (2)]);}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 81 "parser.ypp"
    {(yyval).u_func_list = new list<Func_ptr>();}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 84 "parser.ypp"
    {(yyvsp[(1) - (2)]).u_stat_list -> push_back((yyvsp[(2) - (2)]).u_stat); (yyval) = (yyvsp[(1) - (2)]);}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 85 "parser.ypp"
    {(yyval).u_stat_list = new list<Stat_ptr>();}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 88 "parser.ypp"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 89 "parser.ypp"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 90 "parser.ypp"
    {(yyval).u_stat = new IfNoElse((yyvsp[(3) - (7)]).u_expr, (yyvsp[(6) - (7)]).u_nested_block);}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 92 "parser.ypp"
    {(yyval).u_stat = new IfWithElse((yyvsp[(3) - (11)]).u_expr, (yyvsp[(6) - (11)]).u_nested_block, (yyvsp[(10) - (11)]).u_nested_block);}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 93 "parser.ypp"
    {(yyval).u_stat = new ForLoop((yyvsp[(3) - (11)]).u_stat, (yyvsp[(5) - (11)]).u_expr, (yyvsp[(7) - (11)]).u_stat, (yyvsp[(10) - (11)]).u_nested_block);}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 96 "parser.ypp"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 97 "parser.ypp"
    {(yyval).u_stat = new None();}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 100 "parser.ypp"
    {(yyval).u_return = new Return((yyvsp[(2) - (3)]).u_expr); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 103 "parser.ypp"
    {(yyval).u_stat = new Assignment(new SymName((yyvsp[(1) - (4)]).u_base_charptr), (yyvsp[(3) - (4)]).u_expr);}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 104 "parser.ypp"
    {(yyval).u_stat = new ArrayAssignment(new SymName((yyvsp[(1) - (7)]).u_base_charptr), (yyvsp[(3) - (7)]).u_expr, (yyvsp[(6) - (7)]).u_expr);}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 108 "parser.ypp"
    {(yyval).u_stat = new Call(new SymName((yyvsp[(1) - (7)]).u_base_charptr), new SymName((yyvsp[(3) - (7)]).u_base_charptr), (yyvsp[(5) - (7)]).u_expr_list);}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 110 "parser.ypp"
    {(yyval).u_stat = new ArrayCall(new SymName((yyvsp[(1) - (10)]).u_base_charptr), (yyvsp[(3) - (10)]).u_expr, new SymName((yyvsp[(6) - (10)]).u_base_charptr), (yyvsp[(8) - (10)]).u_expr_list);}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 113 "parser.ypp"
    { (yyvsp[(1) - (2)]).u_expr_list -> push_back((yyvsp[(2) - (2)]).u_expr); (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 114 "parser.ypp"
    { (yyval).u_expr_list = new list<Expr_ptr>(); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 117 "parser.ypp"
    { (yyvsp[(1) - (3)]).u_expr_list -> push_back((yyvsp[(2) - (3)]).u_expr); (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 118 "parser.ypp"
    { (yyval).u_expr_list = new list<Expr_ptr>(); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 121 "parser.ypp"
    {(yyval).u_expr = new Plus((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 122 "parser.ypp"
    {(yyval).u_expr = new Minus((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 123 "parser.ypp"
    {(yyval).u_expr = new Times((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 124 "parser.ypp"
    {(yyval).u_expr = new Div((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 125 "parser.ypp"
    {(yyval).u_expr = new And((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 126 "parser.ypp"
    {(yyval).u_expr = new Or((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 127 "parser.ypp"
    {(yyval).u_expr = new Noteq((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 128 "parser.ypp"
    {(yyval).u_expr = new Compare((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 129 "parser.ypp"
    {(yyval).u_expr = new Gt((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 130 "parser.ypp"
    {(yyval).u_expr = new Gteq((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 131 "parser.ypp"
    {(yyval).u_expr = new Lt((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 132 "parser.ypp"
    {(yyval).u_expr = new Lteq((yyvsp[(1) - (3)]).u_expr, (yyvsp[(3) - (3)]).u_expr);}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 133 "parser.ypp"
    {(yyval).u_expr = new Not((yyvsp[(2) - (2)]).u_expr);}
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 134 "parser.ypp"
    {(yyval).u_expr = new Uminus((yyvsp[(2) - (2)]).u_expr);}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 135 "parser.ypp"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 136 "parser.ypp"
    {(yyval).u_expr = new Ident(new SymName((yyvsp[(1) - (1)]).u_base_charptr));}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 137 "parser.ypp"
    {(yyval).u_expr = new ArrayAccess(new SymName((yyvsp[(1) - (4)]).u_base_charptr), (yyvsp[(3) - (4)]).u_expr);}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 138 "parser.ypp"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 139 "parser.ypp"
    { (yyval).u_expr = new Magnitude((yyvsp[(2) - (3)]).u_expr); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 142 "parser.ypp"
    {(yyval).u_expr = new IntLit((yyvsp[(1) - (1)]).u_primitive);}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 143 "parser.ypp"
    {(yyval).u_expr = new BoolLit(new Primitive(1));}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 144 "parser.ypp"
    {(yyval).u_expr = new BoolLit(new Primitive(0));}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 147 "parser.ypp"
    {(yyval).u_primitive = new Primitive((yyvsp[(1) - (1)]).u_base_int);}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 148 "parser.ypp"
    {(yyval).u_primitive = new Primitive((yyvsp[(1) - (1)]).u_base_int);}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 149 "parser.ypp"
    {(yyval).u_primitive = new Primitive((yyvsp[(1) - (1)]).u_base_int);}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 150 "parser.ypp"
    {(yyval).u_primitive = new Primitive((yyvsp[(1) - (1)]).u_base_int);}
    break;


/* Line 1787 of yacc.c  */
#line 1964 "parser.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2048 of yacc.c  */
#line 153 "parser.ypp"




extern int yylineno;

void yyerror(const char *s) {
	fprintf(stderr, "%s at line %d\n", s, yylineno);
	exit(1);
	return;
}


