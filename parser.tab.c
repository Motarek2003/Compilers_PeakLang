
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 9 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "SymbolTable.h"
#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>

extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);
// void ErrorToFile(string);
int sym[26];

SymbolTable *symbolTable = new SymbolTable();

// Helper function to allocate memory for a Value's content
void* allocateValueFromExpression(const Value& exprValue) {
    void* allocated_ptr = nullptr;
    switch(exprValue.type) {
        case INT_TYPE:    allocated_ptr = (void*)new int(exprValue.intVal); break;
        case FLOAT_TYPE:  allocated_ptr = (void*)new float(exprValue.floatVal); break;
        case BOOL_TYPE:   allocated_ptr = (void*)new bool(exprValue.boolVal); break;
        case CHAR_TYPE:   allocated_ptr = (void*)new char(exprValue.charVal); break;
        case STRING_TYPE: 
            if (exprValue.stringVal) allocated_ptr = (void*)strdup(exprValue.stringVal); 
            break;
        default:
            fprintf(stderr, "Warning: Cannot allocate value for unhandled expression type %d\n", exprValue.type);
            break;
    }
    return allocated_ptr;
}

string enumToString (dataType enumType) {
    switch (enumType) {
        case dataType::INT_TYPE:
            return "INT";
        case dataType::FLOAT_TYPE:
            return "FLOAT";
        case dataType::BOOL_TYPE:
            return "BOOL";
        case dataType::STRING_TYPE:
            return "STRING";
        case dataType::CHAR_TYPE:
            return "CHAR";
        case dataType::FUNC_TYPE:
            return "FUNC";
        case dataType::VOID_TYPE:
            return "VOID";
        case dataType::UNKNOWN_TYPE:
            return "UNKNOWN";
        default:
            return "UNKNOWN";
    }
}



/* Line 189 of yacc.c  */
#line 137 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 3 "parser.y"

    #include "value_helpers.h"



/* Line 209 of yacc.c  */
#line 167 "parser.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     INT = 260,
     FLOAT = 261,
     CHAR = 262,
     VOID = 263,
     BOOL = 264,
     TRUE = 265,
     FALSE = 266,
     CASE = 267,
     DEFAULT = 268,
     IF = 269,
     ELSE = 270,
     SWITCH = 271,
     WHILE = 272,
     DO = 273,
     FOR = 274,
     GOTO = 275,
     CONTINUE = 276,
     BREAK = 277,
     RETURN = 278,
     THABET = 279,
     ASSIGNMENT = 280,
     AND_OP = 281,
     OR_OP = 282,
     EQ_OP = 283,
     NE_OP = 284,
     LE_OP = 285,
     GE_OP = 286,
     LEFT_OP = 287,
     RIGHT_OP = 288,
     UPLUS = 289,
     UMINUS = 290,
     LOWER_THAN_ELSE = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 73 "parser.y"

    int intVal;
    float floatVal;
    char * stringVal;
    char charVal;
    char * variable;
    bool boolVal;
    Value val;



/* Line 214 of yacc.c  */
#line 232 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 244 "parser.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,    51,    38,     2,
      54,    55,    49,    47,    53,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    52,
      39,    46,    40,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,    36,    57,    42,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    43,
      44,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    14,    16,    18,
      22,    28,    35,    37,    41,    43,    45,    47,    49,    51,
      53,    57,    64,    66,    70,    73,    76,    80,    82,    85,
      87,    89,    91,    94,    96,    98,   100,   102,   104,   110,
     118,   126,   128,   131,   136,   140,   146,   154,   162,   166,
     169,   172,   175,   179,   181,   185,   187,   191,   193,   197,
     199,   203,   205,   209,   211,   215,   217,   221,   225,   227,
     231,   235,   239,   243,   245,   249,   253,   255,   259,   263,
     265,   269,   273,   277,   279,   282,   285,   288,   291,   293,
     295,   297,   299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,     1,    -1,    61,    -1,    60,
      61,    -1,    66,    -1,    62,    -1,    72,    -1,    64,    63,
      52,    -1,    64,    63,    25,    65,    52,    -1,    24,    64,
      63,    25,    65,    52,    -1,     3,    -1,    63,    53,     3,
      -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,     9,
      -1,    79,    -1,    65,    53,    79,    -1,    64,     3,    54,
      67,    55,    69,    -1,    68,    -1,    67,    53,    68,    -1,
      64,     3,    -1,    56,    57,    -1,    56,    70,    57,    -1,
      71,    -1,    70,    71,    -1,    62,    -1,    73,    -1,    52,
      -1,    65,    52,    -1,    72,    -1,    69,    -1,    74,    -1,
      77,    -1,    78,    -1,    14,    54,    65,    55,    73,    -1,
      14,    54,    65,    55,    73,    15,    73,    -1,    16,    54,
      65,    55,    56,    75,    57,    -1,    76,    -1,    75,    76,
      -1,    12,     4,    35,    73,    -1,    13,    35,    73,    -1,
      17,    54,    65,    55,    73,    -1,    18,    73,    17,    54,
      65,    55,    52,    -1,    19,    54,    72,    72,    65,    55,
      73,    -1,    20,     3,    52,    -1,    21,    52,    -1,    22,
      52,    -1,    23,    52,    -1,    23,    65,    52,    -1,    80,
      -1,     3,    25,    79,    -1,    81,    -1,    80,    27,    81,
      -1,    82,    -1,    81,    26,    82,    -1,    83,    -1,    82,
      36,    83,    -1,    84,    -1,    83,    37,    84,    -1,    85,
      -1,    84,    38,    85,    -1,    86,    -1,    85,    28,    86,
      -1,    85,    29,    86,    -1,    87,    -1,    86,    39,    87,
      -1,    86,    40,    87,    -1,    86,    30,    87,    -1,    86,
      31,    87,    -1,    88,    -1,    87,    32,    88,    -1,    87,
      33,    88,    -1,    89,    -1,    88,    47,    89,    -1,    88,
      48,    89,    -1,    90,    -1,    89,    49,    90,    -1,    89,
      50,    90,    -1,    89,    51,    90,    -1,    91,    -1,    48,
      90,    -1,    47,    90,    -1,    41,    90,    -1,    42,    90,
      -1,     3,    -1,     4,    -1,    10,    -1,    11,    -1,    54,
      65,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   154,   154,   158,   165,   169,   181,   185,   189,   200,
     210,   227,   252,   260,   271,   272,   273,   274,   275,   279,
     282,   292,   301,   302,   309,   313,   314,   318,   319,   323,
     324,   330,   331,   339,   340,   341,   342,   343,   352,   357,
     364,   368,   369,   373,   374,   383,   388,   394,   401,   402,
     403,   407,   426,   445,   446,   463,   464,   468,   469,   473,
     474,   478,   479,   483,   484,   488,   489,   490,   494,   495,
     496,   497,   498,   502,   503,   504,   508,   509,   510,   514,
     515,   516,   517,   529,   530,   535,   538,   542,   550,   551,
     552,   553,   554
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "INT", "FLOAT",
  "CHAR", "VOID", "BOOL", "TRUE", "FALSE", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "THABET", "ASSIGNMENT", "AND_OP", "OR_OP", "EQ_OP", "NE_OP", "LE_OP",
  "GE_OP", "LEFT_OP", "RIGHT_OP", "'?'", "':'", "'|'", "'^'", "'&'", "'<'",
  "'>'", "'!'", "'~'", "UPLUS", "UMINUS", "LOWER_THAN_ELSE", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "';'", "','", "'('", "')'", "'{'", "'}'",
  "$accept", "mainProgram", "program", "external_declaration",
  "variable_definition", "identifier_list", "type_specifier", "expression",
  "function_definition", "parameter_list", "parameter_declaration",
  "compound_statement", "scope", "scope_item", "expression_statement",
  "statement", "selection_statement", "case_list", "case_item",
  "loop_statement", "jump_statement", "assignment_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "primary_expression", 0
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
     285,   286,   287,   288,    63,    58,   124,    94,    38,    60,
      62,    33,   126,   289,   290,   291,    61,    43,    45,    42,
      47,    37,    59,    44,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    61,    61,    62,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    65,
      65,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      78,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    85,    86,    86,
      86,    86,    86,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     1,     1,     3,
       5,     6,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     6,     1,     3,     2,     2,     3,     1,     2,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     5,     7,
       7,     1,     2,     4,     3,     5,     7,     7,     3,     2,
       2,     2,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,    88,    89,    14,    15,    16,    17,    18,    90,
      91,     0,     0,     0,     0,     0,    31,     0,     0,     2,
       4,     7,     0,     0,     6,     8,    19,    53,    55,    57,
      59,    61,    63,    65,    68,    73,    76,    79,    83,     0,
       0,    88,    86,    87,    85,    84,     0,     1,     5,    12,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    12,     0,    92,     0,     0,     9,     0,    20,
      56,    58,    60,    62,    64,    66,    67,    71,    72,    69,
      70,    74,    75,    77,    78,    80,    81,    82,     0,     0,
       0,    22,     0,    13,     0,    24,     0,     0,    10,    11,
      23,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    29,     0,    34,     0,    27,    33,    30,
      35,    36,    37,     0,     0,     0,     0,     0,     0,    49,
      50,    51,     0,    26,    28,     0,     0,     0,     0,     0,
      48,    52,     0,     0,     0,     0,     0,    38,     0,    45,
       0,     0,     0,     0,     0,     0,    41,     0,     0,    39,
       0,     0,    40,    42,    46,    47,     0,    44,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,    21,    50,    22,    23,    24,   100,
     101,   125,   126,   127,   128,   129,   130,   165,   166,   131,
     132,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -115
static const yytype_int16 yypact[] =
{
      26,  -115,    14,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,    91,   242,   242,   242,   242,  -115,   282,    45,    84,
    -115,  -115,    25,   -36,  -115,  -115,  -115,    20,    29,    27,
      35,    38,    74,   -18,    77,    64,     2,  -115,  -115,   282,
      76,  -115,  -115,  -115,  -115,  -115,    -9,  -115,  -115,    50,
     -11,  -115,   282,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,  -115,  -115,   -10,  -115,    91,   282,  -115,    82,  -115,
      29,    27,    35,    38,    74,   -18,   -18,    77,    77,    77,
      77,    64,    64,     2,     2,  -115,  -115,  -115,   282,   104,
       3,  -115,    61,  -115,    63,  -115,    91,    68,  -115,  -115,
    -115,   147,  -115,    66,    94,   105,   257,   106,   130,    93,
     110,   131,  -115,  -115,    76,  -115,   202,  -115,  -115,  -115,
    -115,  -115,  -115,   282,   282,   282,   157,   187,   123,  -115,
    -115,  -115,    70,  -115,  -115,     6,    16,    22,   122,   187,
    -115,  -115,   257,   121,   257,   282,   282,   165,   115,  -115,
      28,    31,   257,   177,   149,    -8,  -115,   134,   257,  -115,
     152,   257,  -115,  -115,  -115,  -115,   257,  -115,  -115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,   163,  -108,   153,    -5,   -16,  -115,  -115,
      86,    89,  -115,    88,     0,  -114,  -115,  -115,    37,  -115,
    -115,   -32,  -115,   162,   146,   172,   161,   173,    71,   -37,
      79,    80,    -4,  -115
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      25,    46,   136,   123,   163,   164,    40,    71,    42,    43,
      44,    45,    60,    61,    76,    98,    51,    52,   123,    25,
      79,    62,    63,    87,    88,    89,    90,     1,    49,     2,
       3,     4,     5,     6,     7,     8,     9,    10,   157,    39,
     159,    77,    78,    78,    52,    47,    74,    53,   169,   172,
      11,    68,    69,    70,   175,    54,   106,   177,   107,    52,
     102,   152,   178,    55,    95,    96,    97,    12,    13,    52,
      99,   153,    56,    14,    15,    52,    57,   154,    16,    72,
      17,    52,   104,   167,    52,   103,   168,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     4,     5,     6,     7,
       8,    99,    58,    59,    75,   142,   124,   105,    11,    64,
      65,    66,    67,   108,    52,   109,    52,   145,   146,   147,
     133,   124,   151,    52,   111,    12,    13,   163,   164,    85,
      86,    14,    15,   138,     2,     3,    16,   149,    17,   160,
     161,     9,    10,    91,    92,   139,    93,    94,   134,   156,
       2,     3,     4,     5,     6,     7,     8,     9,    10,   135,
     137,   113,   140,   114,   115,   116,   117,   118,   119,   120,
     121,    11,    12,    13,   148,   150,   155,   158,    14,    15,
     162,   170,    48,   141,   171,    17,   174,   176,    12,    13,
       2,     3,   110,    73,    14,    15,   112,     9,    10,    16,
      81,    17,   173,   111,   122,     2,     3,     4,     5,     6,
       7,     8,     9,    10,   144,    80,   113,    83,   114,   115,
     116,   117,   118,   119,   120,   121,    11,    82,    12,    13,
      84,     0,     0,     0,    14,    15,     0,     0,     0,    16,
       0,    17,     0,    12,    13,    41,     3,     0,     0,    14,
      15,     0,     9,    10,    16,     0,    17,     0,   111,   143,
       2,     3,     0,     0,     0,     0,     0,     9,    10,     0,
       0,   113,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,     0,    12,    13,     2,     3,     0,     0,    14,
      15,     0,     9,    10,     0,     0,    17,     0,    12,    13,
       0,     0,     0,     0,    14,    15,     0,     0,     0,    16,
       0,    17,     0,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,     0,    17
};

static const yytype_int16 yycheck[] =
{
       0,    17,   116,   111,    12,    13,    11,    39,    12,    13,
      14,    15,    30,    31,    25,    25,    52,    53,   126,    19,
      52,    39,    40,    60,    61,    62,    63,     1,     3,     3,
       4,     5,     6,     7,     8,     9,    10,    11,   152,    25,
     154,    52,    53,    53,    53,     0,    55,    27,   162,    57,
      24,    49,    50,    51,   168,    26,    53,   171,    55,    53,
      76,    55,   176,    36,    68,    69,    70,    41,    42,    53,
      75,    55,    37,    47,    48,    53,    38,    55,    52,     3,
      54,    53,    98,    55,    53,     3,    55,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     5,     6,     7,     8,
       9,   106,    28,    29,    54,   121,   111,     3,    24,    32,
      33,    47,    48,    52,    53,    52,    53,   133,   134,   135,
      54,   126,    52,    53,    56,    41,    42,    12,    13,    58,
      59,    47,    48,     3,     3,     4,    52,   137,    54,   155,
     156,    10,    11,    64,    65,    52,    66,    67,    54,   149,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    54,
      54,    14,    52,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    41,    42,    17,    52,    54,    56,    47,    48,
      15,     4,    19,    52,    35,    54,    52,    35,    41,    42,
       3,     4,   106,    40,    47,    48,   107,    10,    11,    52,
      54,    54,   165,    56,    57,     3,     4,     5,     6,     7,
       8,     9,    10,    11,   126,    53,    14,    56,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    55,    41,    42,
      57,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    52,
      -1,    54,    -1,    41,    42,     3,     4,    -1,    -1,    47,
      48,    -1,    10,    11,    52,    -1,    54,    -1,    56,    57,
       3,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,
      -1,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    41,    42,     3,     4,    -1,    -1,    47,
      48,    -1,    10,    11,    -1,    -1,    54,    -1,    41,    42,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    52,
      -1,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    24,    41,    42,    47,    48,    52,    54,    59,    60,
      61,    62,    64,    65,    66,    72,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    25,
      64,     3,    90,    90,    90,    90,    65,     0,    61,     3,
      63,    52,    53,    27,    26,    36,    37,    38,    28,    29,
      30,    31,    39,    40,    32,    33,    47,    48,    49,    50,
      51,    79,     3,    63,    55,    54,    25,    52,    53,    79,
      81,    82,    83,    84,    85,    86,    86,    87,    87,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    25,    64,
      67,    68,    65,     3,    65,     3,    53,    55,    52,    52,
      68,    56,    69,    14,    16,    17,    18,    19,    20,    21,
      22,    23,    57,    62,    64,    69,    70,    71,    72,    73,
      74,    77,    78,    54,    54,    54,    73,    54,     3,    52,
      52,    52,    65,    57,    71,    65,    65,    65,    17,    72,
      52,    52,    55,    55,    55,    54,    72,    73,    56,    73,
      65,    65,    15,    12,    13,    75,    76,    55,    55,    73,
       4,    35,    57,    76,    52,    73,    35,    73,    73
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { 
        printf("Main program\n"); 
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { 
        // ErrorToFile("Syntax Error"); YYABORT; 
        printf("Feh errors ya man\n");  YYABORT; 
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {
        printf("Program\n");
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {
        printf("Program with external declarations\n");
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {
        printf("Function definition\n");
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {
        printf("Variable definition\n");
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {
        printf("Expression statement\n");
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {
        printf("variable_declaration Rule 2\n");
        symbolTable->insert((yyvsp[(2) - (3)].val), (yyvsp[(1) - (3)].val), NULL);
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {
        // $1 is type_specifier (Value), $2 is identifier_list (Value), $4 is expression (Value)
        
        void* allocated_val_ptr = allocateValueFromExpression((yyvsp[(4) - (5)].val)); 

        if (allocated_val_ptr != nullptr) { 
            symbolTable->insert((yyvsp[(2) - (5)].val), (yyvsp[(1) - (5)].val), allocated_val_ptr); 
        } else {
             yyerror(("Failed to create value for assignment to variable " + getValueName((yyvsp[(2) - (5)].val))).c_str());
             symbolTable->insert((yyvsp[(2) - (5)].val), (yyvsp[(1) - (5)].val), nullptr); 
        }
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    {
        printf("variable_declaration Rule 3\n");

         // $2 is type_specifier (Value), $3 is identifier_list (Value), $5 is expression (Value)
        
        void* allocated_val_ptr = allocateValueFromExpression((yyvsp[(5) - (6)].val)); 

        if (allocated_val_ptr != nullptr) { 
            symbolTable->insert((yyvsp[(3) - (6)].val), (yyvsp[(2) - (6)].val), allocated_val_ptr,true); 
        } else {
             yyerror(("Failed to create value for assignment to variable " + getValueName((yyvsp[(2) - (6)].val))).c_str());
             symbolTable->insert((yyvsp[(2) - (6)].val), (yyvsp[(1) - (6)].val), nullptr); 
        }

        // symbolTable->update_Func($3);
        // symbolTable->printTable();   
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    {
        (yyval.val) = (yyvsp[(1) - (1)].val);
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    {
        // $$ = (char*)malloc(strlen($1) + strlen($3) + 2);
        // sprintf($$, "%s,%s", $1, $3);
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {
        printf("Assignment Expression\n");
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 301 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 408 "parser.y"
    {
       // check if the function is returning a value with same type
        // TODO: string functionName = (active functions) I would like to get the function name from the symbol table
        // TODO: we can have a vector of strings that contain all active functions (or stack)
        string functionName = "dummy"; // change later
        // SingleEntry * functionEntry = symbolTable->get_SingleEntry(functionName);
        
        // Im not sure that NULL de haga sah walla la
        // if (functionEntry->returnType != NULL) 
        // {
        //     printf("[ERROR] Type mismatch in return statement\n");
        //     ErrorToFile("Type mismatch in return statement");
        // }

    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 427 "parser.y"
    {
        // check if the function is returning a value with same type
        // TODO: string functionName = (active functions) I would like to get the function name from the symbol table
        // TODO: we can have a vector of strings that contain all active functions (or stack)
        string functionName = "dummy"; // change later
        // SingleEntry * functionEntry = symbolTable->get_SingleEntry(functionName);
        
        // if (functionEntry->returnType != $2[0]->type) 
        // {
        //     printf("[ERROR] Type mismatch in return statement\n");
        //     ErrorToFile("Type mismatch in return statement");
        // }
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 446 "parser.y"
    {
        printf("Assignment expression\n");
        // $1 is IDENTIFIER, $3 is assignment_expression (Value)

        void* allocated_val_ptr = allocateValueFromExpression((yyvsp[(3) - (3)].val));
        if (allocated_val_ptr != nullptr) {
            symbolTable->update_Value(getValueName((yyvsp[(1) - (3)].val)), allocated_val_ptr , (yyvsp[(3) - (3)].val).type);
        } else {
            yyerror(("Failed to create value for assignment to variable " + getValueName((yyvsp[(1) - (3)].val))).c_str());
        }
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 529 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 530 "parser.y"
    {
          // Create a new Value and apply negation
          (yyval.val) = (yyvsp[(2) - (2)].val);
          (yyval.val).intVal = -(yyval.val).intVal;
      ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 535 "parser.y"
    {
          (yyval.val) = (yyvsp[(2) - (2)].val);
      ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 538 "parser.y"
    {
          (yyval.val) = (yyvsp[(2) - (2)].val);
          (yyval.val).boolVal = !(yyval.val).boolVal;
      ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 542 "parser.y"
    {
          (yyval.val) = (yyvsp[(2) - (2)].val);
          (yyval.val).intVal = ~(yyval.val).intVal;
      ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 550 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 551 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 552 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 553 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 554 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1966 "parser.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 557 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "[ERROR] %s\n", s);
}

// Function to merge parameters from parameter_list
/* Value merge(Value param1, Value param2) {
    // Simple implementation - in a real compiler this would 
    // properly merge parameter information
    return param2; // Just return the second parameter for now
} */

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Error opening file: %s\n", argv[1]);
            return 1;
        }
    } else {
        fprintf(stderr, "No input file provided.\n");
        return 1;
    }
       if (yyparse() == 0) {
        printf("Parsing completed successfully.\n");
        if (symbolTable->getParent() == NULL) {
            symbolTable->printTableToFile();
        }
        return 0;
    } else {
        printf("Parsing failed.\n");
        return 1;
       }

}

