
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
#line 1 "syntax.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "TS_fct.h"
    
    extern int nb_ligne;
    extern int col;
    extern int yylex();
    extern char* yytext;
    int yyerror(const char *s);
    
    
    int nb_erreurs = 0;

    
    typedef struct {
        int value;
        char *name;  
        int is_var;  
        char *type;  
    } ExprInfo;



/* Line 189 of yacc.c  */
#line 99 "syntax.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAINPRGM = 258,
     VAR = 259,
     BEGINPG = 260,
     ENDPG = 261,
     LET = 262,
     DEFINE = 263,
     CONST = 264,
     INT = 265,
     FLOAT = 266,
     IDF = 267,
     CST_INT = 268,
     CST_FLOAT = 269,
     IF = 270,
     THEN = 271,
     ELSE = 272,
     DO = 273,
     WHILE = 274,
     FOR = 275,
     FROM = 276,
     TO = 277,
     STEP = 278,
     INPUT = 279,
     OUTPUT = 280,
     ASSIGN = 281,
     AND = 282,
     OR = 283,
     GT = 284,
     LT = 285,
     GE = 286,
     LE = 287,
     EQ = 288,
     NE = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "syntax.y"

    int entier;
    float reel;
    char* str;
    char* type;  
    struct {
        int value;
        char *name; 
        int is_var;  
        char *type;  
    } expr_info;




/* Line 214 of yacc.c  */
#line 185 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 197 "syntax.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   612

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,     2,     2,     2,     2,     2,
      40,    41,    38,    36,    48,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    42,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    15,    17,    20,    22,    23,    25,    27,
      30,    36,    46,    54,    60,    66,    76,    85,    89,    91,
      93,   102,   111,   120,   127,   134,   138,   140,   142,   144,
     147,   149,   150,   152,   154,   156,   158,   160,   162,   165,
     170,   175,   183,   191,   195,   203,   208,   213,   221,   230,
     243,   252,   260,   268,   275,   287,   299,   301,   311,   319,
     322,   334,   346,   349,   355,   361,   364,   370,   375,   380,
     384,   388,   390,   392,   396,   400,   404,   408,   412,   416,
     420,   423,   427,   431,   435,   439,   443,   447,   451,   453,
     458,   460,   462
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,     3,    12,    42,     4,    52,     5,    43,
      58,    44,     6,    42,    -1,     1,    -1,    53,    52,    -1,
      53,    -1,    -1,    54,    -1,    56,    -1,     1,    42,    -1,
       7,    55,    45,    57,    42,    -1,     7,    55,    45,    46,
      57,    42,    13,    47,    42,    -1,     7,    55,    45,    46,
      57,     1,    42,    -1,     7,    55,    45,     1,    42,    -1,
       7,     1,    45,    57,    42,    -1,     7,     1,    45,    46,
      57,    42,    13,    47,    42,    -1,     7,    55,    45,    46,
      57,     1,    47,    42,    -1,    12,    48,    55,    -1,    12,
      -1,     1,    -1,     8,     9,    12,    45,    57,    49,    13,
      42,    -1,     8,     9,    12,    45,    57,    49,    14,    42,
      -1,     8,     9,    12,    45,    57,    49,     1,    42,    -1,
       8,     9,    12,    49,    13,    42,    -1,     8,     9,    12,
      49,    14,    42,    -1,     8,     1,    42,    -1,    10,    -1,
      11,    -1,     1,    -1,    59,    58,    -1,    59,    -1,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,     1,    42,    -1,    12,    26,    67,    42,    -1,
      12,    49,    67,    42,    -1,    12,    46,    13,    47,    26,
      67,    42,    -1,    12,    46,    13,    47,    49,    67,    42,
      -1,    12,    26,    67,    -1,    12,    46,    13,    47,    26,
      67,     1,    -1,     1,    26,    13,    42,    -1,    12,    26,
       1,    42,    -1,    12,    46,    13,    47,    26,     1,    42,
      -1,    15,    40,    67,    41,    16,    43,    58,    44,    -1,
      15,    40,    67,    41,    16,    43,    58,    44,    17,    43,
      58,    44,    -1,    15,    40,     1,    41,    16,    43,    58,
      44,    -1,    15,    40,    67,    41,    16,    43,    58,    -1,
      15,    40,    67,    41,    16,    58,    44,    -1,    15,    67,
      16,    43,    58,    44,    -1,    15,    40,    67,    41,    16,
      43,    58,    44,    17,    43,    58,    -1,    15,    40,    67,
      41,    16,    43,    58,    44,    17,    58,    44,    -1,     1,
      -1,    18,    43,    58,    44,    19,    40,    67,    41,    42,
      -1,    18,    43,    58,    44,    19,     1,    42,    -1,    18,
       1,    -1,    20,    12,    21,    67,    22,    67,    23,    67,
      43,    58,    44,    -1,    20,     1,    21,    67,    22,    67,
      23,    67,    43,    59,    44,    -1,    20,     1,    -1,    24,
      40,    12,    41,    42,    -1,    24,    40,     1,    41,    42,
      -1,    24,     1,    -1,    25,    40,    66,    41,    42,    -1,
      25,    40,    66,    42,    -1,    25,    66,    41,    42,    -1,
      25,     1,    42,    -1,    67,    48,    66,    -1,    67,    -1,
       1,    -1,    67,    36,    67,    -1,    67,    37,    67,    -1,
      67,    38,    67,    -1,    67,    39,    67,    -1,    40,    67,
      41,    -1,    67,    27,    67,    -1,    67,    28,    67,    -1,
      35,    67,    -1,    67,    29,    67,    -1,    67,    30,    67,
      -1,    67,    31,    67,    -1,    67,    32,    67,    -1,    67,
      33,    67,    -1,    67,    49,    67,    -1,    67,    34,    67,
      -1,    12,    -1,    12,    46,    13,    47,    -1,    13,    -1,
      14,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    76,    84,    85,    86,    89,    90,    91,
      99,   119,   151,   156,   161,   166,   171,   179,   184,   187,
     194,   221,   249,   254,   259,   264,   272,   275,   278,   286,
     287,   288,   291,   292,   293,   294,   295,   296,   297,   304,
     350,   356,   394,   400,   405,   410,   415,   420,   427,   429,
     431,   436,   441,   447,   452,   457,   462,   469,   471,   476,
     483,   500,   505,   512,   529,   534,   541,   545,   550,   555,
     562,   563,   564,   571,   589,   603,   617,   658,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   676,   677,   702,
     741,   747,   753
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAINPRGM", "VAR", "BEGINPG", "ENDPG",
  "LET", "DEFINE", "CONST", "INT", "FLOAT", "IDF", "CST_INT", "CST_FLOAT",
  "IF", "THEN", "ELSE", "DO", "WHILE", "FOR", "FROM", "TO", "STEP",
  "INPUT", "OUTPUT", "ASSIGN", "AND", "OR", "GT", "LT", "GE", "LE", "EQ",
  "NE", "'!'", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "';'", "'{'",
  "'}'", "':'", "'['", "']'", "','", "'='", "$accept", "programme",
  "declarations", "declaration", "var_decl", "var_list", "const_decl",
  "type", "instructions", "instruction", "affectation", "condition",
  "boucle_do", "boucle_for", "lecture", "ecriture", "expression_liste",
  "expression", 0
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
     285,   286,   287,   288,   289,    33,    43,    45,    42,    47,
      40,    41,    59,   123,   125,    58,    91,    93,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    57,    57,    57,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    65,    65,    65,    65,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,     1,     2,     1,     0,     1,     1,     2,
       5,     9,     7,     5,     5,     9,     8,     3,     1,     1,
       8,     8,     8,     6,     6,     3,     1,     1,     1,     2,
       1,     0,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     7,     7,     3,     7,     4,     4,     7,     8,    12,
       8,     7,     7,     6,    11,    11,     1,     9,     7,     2,
      11,    11,     2,     5,     5,     2,     5,     4,     4,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     1,     4,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,    18,     0,     0,
       0,     0,     4,     0,     0,     0,    25,     0,     0,    28,
      26,    27,     0,     0,    19,    17,     0,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,    34,    35,    36,    37,     0,    14,    13,     0,
      10,     0,     0,     0,     0,    38,     0,     0,     0,    92,
      88,    90,    91,     0,     0,     0,    59,     0,    62,     0,
      65,     0,    92,     0,     0,    71,     0,    29,     0,     0,
       0,     0,    23,    24,     0,    92,     0,    43,     0,     0,
       0,    80,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    92,     0,    71,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,    45,    46,     0,
      39,     0,    40,     0,     0,    77,     0,    78,    79,    81,
      82,    83,    84,    85,    87,    73,    74,    75,    76,    86,
       0,     0,     0,     0,     0,     0,    67,    77,    68,    70,
       2,     0,    16,     0,    22,    20,    21,     0,     0,    89,
       0,     0,     0,     0,     0,     0,    64,    63,    66,    15,
      11,    92,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,    47,    44,    41,    42,     0,    51,    52,    58,
       0,     0,     0,    50,    48,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,    54,    55,    61,    60,
      49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    11,    12,    13,    18,    14,    33,    48,    49,
      50,    51,    52,    53,    54,    55,    84,    85
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
     124,   -78,    -8,    29,    41,   -78,    95,   238,    97,     8,
      10,    58,   261,   -78,   -78,   -78,    88,    80,   103,   112,
     144,   133,   -78,     2,    83,     4,   -78,   102,   106,   -78,
     -78,   -78,    79,   140,   -78,   -78,   142,    79,   149,    79,
      40,   -25,    56,    46,     9,    86,    21,   128,   160,   137,
     -78,   -78,   -78,   -78,   -78,   -78,   167,   -78,   -78,    15,
     -78,   159,   170,   171,   197,   -78,   152,   201,   166,   -78,
     172,   -78,   -78,   166,   176,   199,   -78,   106,   198,   200,
     -78,    92,    72,   182,   183,   328,   217,   -78,   221,    70,
     227,   109,   -78,   -78,   205,   215,   166,   351,   194,   374,
     229,   563,   223,   397,   220,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   226,   166,
     166,   224,   239,   -78,   118,   161,   305,   243,   182,   244,
     240,   -78,   246,   242,   248,   250,   251,   -78,   -78,   420,
     -78,    59,   -78,   256,   292,   293,   106,   563,   549,   360,
     360,   360,   360,   360,   360,   136,   136,   262,   262,   535,
     294,   222,   245,   270,   273,   274,   -78,   -78,   -78,   -78,
     -78,   284,   -78,   289,   -78,   -78,   -78,   185,   166,   -78,
     267,    76,   301,    22,   166,   166,   -78,   -78,   -78,   -78,
     -78,   306,     7,   443,   106,   106,   303,   -78,   307,   166,
     268,   291,   -78,   -78,   -78,   -78,   308,   319,   -78,   -78,
     466,   166,   166,   -78,   333,   309,   489,   512,    91,   -78,
       6,   106,   106,   324,   325,   326,   327,   -78,   -78,   -78,
     -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   361,   -78,   -78,   348,   -78,   168,   -49,   154,
     -78,   -78,   -78,   -78,   -78,   -78,   -77,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -73
static const yytype_int16 yytable[] =
{
      87,    64,    75,    29,     4,    36,   125,    41,   203,    16,
      76,    19,    30,    31,    30,    31,    89,    65,    42,    20,
      17,    43,    80,   198,    44,    97,    45,    99,   118,     5,
      46,    47,   101,   103,   105,   106,   107,   108,   109,   110,
     111,   112,   126,   113,   114,   115,   116,    69,    32,   204,
      37,   169,    77,    62,    63,   139,   117,    90,    70,    71,
      72,    81,   199,    21,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    41,   161,   162,
      29,    73,    66,     6,    34,   177,    74,    78,    42,    30,
      31,    43,    41,   121,    44,    17,    45,   182,    79,     7,
      46,    47,    67,    42,   122,    68,    43,    41,   178,    44,
     134,    45,   131,   -72,   123,    46,    47,   132,    42,   195,
     -31,    43,   135,   136,    44,     1,    45,     2,    24,    82,
      46,    47,   196,    23,   222,   -31,   192,   193,    41,    15,
      70,    71,    72,   200,   201,   206,   207,    39,    25,    42,
     -31,    40,    43,    95,    26,    44,    27,    45,   210,   -72,
     -72,    46,    47,    73,    70,    71,    72,    69,    83,   223,
     216,   217,   225,   226,   115,   116,    28,   102,    70,    71,
      72,   -30,    57,   124,    58,   117,   191,    73,    70,    71,
      72,    60,    96,    38,    70,    71,    72,    70,    71,    72,
      56,    73,   165,   166,    86,    59,    96,    61,    91,    88,
      94,    73,    92,    93,    98,   104,    96,    73,   100,   119,
      73,   120,    96,   129,   127,    96,   105,   106,   107,   108,
     109,   110,   111,   112,   130,   113,   114,   115,   116,     8,
     133,   141,   143,    -6,   184,     9,    10,   137,   117,   105,
     106,   107,   108,   109,   110,   111,   112,   138,   113,   114,
     115,   116,     8,   146,   144,   163,    -5,   185,     9,    10,
     160,   117,   105,   106,   107,   108,   109,   110,   111,   112,
     164,   113,   114,   115,   116,   168,   170,   171,   172,   173,
     174,   211,   175,   176,   117,   105,   106,   107,   108,   109,
     110,   111,   112,   179,   113,   114,   115,   116,   180,   181,
     194,   117,   186,   183,   212,   187,   188,   117,   105,   106,
     107,   108,   109,   110,   111,   112,   189,   113,   114,   115,
     116,   190,   105,   106,   107,   108,   109,   110,   111,   112,
     117,   113,   114,   115,   116,   197,   167,   208,   202,   209,
     218,   219,   213,   128,   117,   105,   106,   107,   108,   109,
     110,   111,   112,   214,   113,   114,   115,   116,   227,   228,
     229,   230,    35,    22,   224,     0,   128,   117,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,     0,     0,   140,     0,     0,   113,   114,   115,   116,
     117,   105,   106,   107,   108,   109,   110,   111,   112,   117,
     113,   114,   115,   116,     0,     0,   142,     0,     0,     0,
       0,     0,     0,   117,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,     0,   145,     0,
       0,     0,     0,     0,     0,     0,   117,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
       0,   167,     0,     0,     0,     0,     0,     0,     0,   117,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,     0,     0,   205,     0,     0,     0,     0,
       0,     0,   117,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,     0,   215,     0,     0,
       0,     0,     0,     0,     0,   117,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,     0,
       0,     0,   220,     0,     0,     0,     0,     0,   117,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,     0,     0,     0,   221,     0,     0,     0,     0,
       0,   117,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,     0,   105,     0,   107,   108,
     109,   110,   111,   112,   117,   113,   114,   115,   116,     0,
       0,     0,   107,   108,   109,   110,   111,   112,   117,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117
};

static const yytype_int16 yycheck[] =
{
      49,    26,    43,     1,    12,     1,    83,     1,     1,     1,
       1,     1,    10,    11,    10,    11,     1,    42,    12,     9,
      12,    15,     1,     1,    18,    66,    20,    68,    77,     0,
      24,    25,    73,    74,    27,    28,    29,    30,    31,    32,
      33,    34,    83,    36,    37,    38,    39,     1,    46,    42,
      46,   128,    43,    13,    14,    96,    49,    42,    12,    13,
      14,    40,    40,     5,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     1,   119,   120,
       1,    35,    26,    42,     1,    26,    40,     1,    12,    10,
      11,    15,     1,     1,    18,    12,    20,   146,    12,     4,
      24,    25,    46,    12,    12,    49,    15,     1,    49,    18,
       1,    20,    42,    41,    42,    24,    25,    47,    12,    43,
      44,    15,    13,    14,    18,     1,    20,     3,    48,     1,
      24,    25,   181,    45,    43,    44,   177,   178,     1,    42,
      12,    13,    14,   184,   185,   194,   195,    45,    45,    12,
      44,    49,    15,     1,    42,    18,    12,    20,   199,    41,
      42,    24,    25,    35,    12,    13,    14,     1,    40,   218,
     211,   212,   221,   222,    38,    39,    43,     1,    12,    13,
      14,    44,    42,     1,    42,    49,     1,    35,    12,    13,
      14,    42,    40,    25,    12,    13,    14,    12,    13,    14,
      32,    35,    41,    42,    44,    37,    40,    39,    49,    42,
      13,    35,    42,    42,    13,    16,    40,    35,    46,    21,
      35,    21,    40,     6,    41,    40,    27,    28,    29,    30,
      31,    32,    33,    34,    13,    36,    37,    38,    39,     1,
      13,    47,    13,     5,    22,     7,     8,    42,    49,    27,
      28,    29,    30,    31,    32,    33,    34,    42,    36,    37,
      38,    39,     1,    43,    41,    41,     5,    22,     7,     8,
      44,    49,    27,    28,    29,    30,    31,    32,    33,    34,
      41,    36,    37,    38,    39,    42,    42,    47,    42,    47,
      42,    23,    42,    42,    49,    27,    28,    29,    30,    31,
      32,    33,    34,    47,    36,    37,    38,    39,    16,    16,
      43,    49,    42,    19,    23,    42,    42,    49,    27,    28,
      29,    30,    31,    32,    33,    34,    42,    36,    37,    38,
      39,    42,    27,    28,    29,    30,    31,    32,    33,    34,
      49,    36,    37,    38,    39,    44,    41,    44,    42,    42,
      17,    42,    44,    48,    49,    27,    28,    29,    30,    31,
      32,    33,    34,    44,    36,    37,    38,    39,    44,    44,
      44,    44,    24,    12,   220,    -1,    48,    49,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    36,    37,    38,    39,
      49,    27,    28,    29,    30,    31,    32,    33,    34,    49,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    49,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    -1,    27,    -1,    29,    30,
      31,    32,    33,    34,    49,    36,    37,    38,    39,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    49,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    51,    12,     0,    42,     4,     1,     7,
       8,    52,    53,    54,    56,    42,     1,    12,    55,     1,
       9,     5,    52,    45,    48,    45,    42,    12,    43,     1,
      10,    11,    46,    57,     1,    55,     1,    46,    57,    45,
      49,     1,    12,    15,    18,    20,    24,    25,    58,    59,
      60,    61,    62,    63,    64,    65,    57,    42,    42,    57,
      42,    57,    13,    14,    26,    42,    26,    46,    49,     1,
      12,    13,    14,    35,    40,    67,     1,    43,     1,    12,
       1,    40,     1,    40,    66,    67,    44,    58,    42,     1,
      42,    49,    42,    42,    13,     1,    40,    67,    13,    67,
      46,    67,     1,    67,    16,    27,    28,    29,    30,    31,
      32,    33,    34,    36,    37,    38,    39,    49,    58,    21,
      21,     1,    12,    42,     1,    66,    67,    41,    48,     6,
      13,    42,    47,    13,     1,    13,    14,    42,    42,    67,
      42,    47,    42,    13,    41,    41,    43,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      44,    67,    67,    41,    41,    41,    42,    41,    42,    66,
      42,    47,    42,    47,    42,    42,    42,    26,    49,    47,
      16,    16,    58,    19,    22,    22,    42,    42,    42,    42,
      42,     1,    67,    67,    43,    43,    58,    44,     1,    40,
      67,    67,    42,     1,    42,    42,    58,    58,    44,    42,
      67,    23,    23,    44,    44,    41,    67,    67,    17,    42,
      43,    43,    43,    58,    59,    58,    58,    44,    44,    44,
      44
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
#line 68 "syntax.y"
    {  
              inserer((yyvsp[(2) - (11)].str),"motCle","null", "false");
              if (nb_erreurs == 0) {
                  printf("\nProgramme valide !\n");
              } else {
                  printf("\nProgramme invalide. %d erreur(s) detectee(s).\n", nb_erreurs);
              }
          ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 77 "syntax.y"
    {
              yyerror("Erreur dans la structure globale du programme");
              yyerrok;
          ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 92 "syntax.y"
    {
                yyerror("Erreur dans la declaration");
                yyerrok;
            ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 100 "syntax.y"
    {
            int i = 0;
            char *token = strtok(strdup((yyvsp[(2) - (5)].str)), ",");  
            char buffer[100];
            while (token != NULL) {
                int i = recherche(token);
                if (i != -1) {
                    // Variable déjà déclarée
                    snprintf(buffer, sizeof(buffer), "Double declaration de la variable %s", token);
                    yyerrorSemantique(buffer);
                    yyerrok;
                } else {
                    int inserted = inserer(token, "Idf", "null", "false");
                    i = update(token, (yyvsp[(4) - (5)].str), "false", "null", 1);
                    printf("\nDeclaration de variables %s de type %s\n", token, (yyvsp[(4) - (5)].str));
                }
                token = strtok(NULL, ",");
            }
         ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 120 "syntax.y"
    {         char buffer[100];
                   char *token = strtok((yyvsp[(2) - (9)].str),",");
                   while (token != NULL) {
                      int inserted = inserer(token,"Idf","null","false");
                      if(inserted == -1){
                           
                          snprintf(buffer, sizeof(buffer), "Erreur: double delaration de l'entite %s\n", token);
                          yyerrorSemantique(buffer);
                          yyerrok;
                      }else if(inserted != 0){
                       if((yyvsp[(7) - (9)].entier) <= 0){
                         snprintf(buffer, sizeof(buffer), "Erreur: La taille du tableau %s doit etre positive\n", token);
                         yyerror(buffer);
                         yyerrok;
                        }else{
                            int i= update(token, (yyvsp[(5) - (9)].str), "false","null",(yyvsp[(7) - (9)].entier));   
                              switch (i) {
                         case -1: 
                             snprintf(buffer, sizeof(buffer), "Erreur: Le tableau %s n'est pas declare\n", token);
                             yyerror(buffer);
                             yyerrok;
                             break;
                         default:
                             printf("\nDeclaration de tableau %s de type %s [%d]\n", (yyvsp[(2) - (9)].str), (yyvsp[(5) - (9)].str), (yyvsp[(7) - (9)].entier));
                             break;
                                          } 
                              }}
                     token = strtok(NULL, ",");
                    } 
            ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 152 "syntax.y"
    { 
             yyerror("Erreur: Mauvaise declaration du tableau. Syntaxe attendue: [type;taille] \n");
             yyerrok;
         ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 157 "syntax.y"
    { 
             yyerror("Erreur: Type invalide dans la declaration de variable \n");
             yyerrok;
         ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 162 "syntax.y"
    {
             yyerror("l'une des varialbles est mal declares\n");
             yyerrok;
         ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 167 "syntax.y"
    {
             yyerror("l'un des array est mal declares est mal declares\n");
             yyerrok;
         ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 172 "syntax.y"
    {
            yyerror("Erreur: Mauvaise declaration du tableau. Syntaxe attendue: [type;taille] \n");
             yyerrok;
              
         ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 179 "syntax.y"
    {
        char* buffer = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 2);
        sprintf(buffer, "%s,%s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = buffer;
        ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 184 "syntax.y"
    {
            (yyval.str) = strdup((yyvsp[(1) - (1)].str));  // Copie du nom
        ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 187 "syntax.y"
    {
            yyerror("Erreur dans la liste des variables\n");
            yyerrok;
            (yyval.str) = strdup("???");
        ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 195 "syntax.y"
    { 
               char value_str[12], buffer[100];
                int inserted = inserer((yyvsp[(3) - (8)].str), "Idf", "null", "false");
                if(inserted == -1) {
                    snprintf(buffer, sizeof(buffer), "Double declaration de l'entite %s", (yyvsp[(3) - (8)].str));
                    yyerrorSemantique(buffer);
                    yyerrok;
                } else {
                    // Vérification de la compatibilité de type
                    if (strcmp((yyvsp[(5) - (8)].str), "Int") != 0 && strcmp((yyvsp[(5) - (8)].str), "Float") != 0) {
                        snprintf(buffer, sizeof(buffer), "Type %s incompatible pour la constante %s", (yyvsp[(5) - (8)].str), (yyvsp[(3) - (8)].str));
                        yyerrorSemantique(buffer);
                        yyerrok;
                    } else {
                        snprintf(value_str, sizeof(value_str), "%d", (yyvsp[(7) - (8)].entier));
                        int i = update((yyvsp[(3) - (8)].str), (yyvsp[(5) - (8)].str), "true", value_str, 1);
                        if(i == -1) {
                            snprintf(buffer, sizeof(buffer), "Erreur dans la declaration de constante %s", (yyvsp[(3) - (8)].str));
                            yyerror(buffer);
                            yyerrok;
                        } else {
                            printf("\nDeclaration de constante entiere %s = %d\n", (yyvsp[(3) - (8)].str), (yyvsp[(7) - (8)].entier));
                        }
                    }
                }
            ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 222 "syntax.y"
    { 

                char value_str[12], buffer[100];
                int inserted = inserer((yyvsp[(3) - (8)].str), "Idf", "null", "false");
                if(inserted == -1) {
                    snprintf(buffer, sizeof(buffer), "Double declaration de l'entite %s", (yyvsp[(3) - (8)].str));
                    yyerrorSemantique(buffer);
                    yyerrok;
                } else {
                    // Vérification de la compatibilité de type
                    if (strcmp((yyvsp[(5) - (8)].str), "Float") != 0) {
                        snprintf(buffer, sizeof(buffer), "Type %s incompatible pour la constante flottante %s", (yyvsp[(5) - (8)].str), (yyvsp[(3) - (8)].str));
                        yyerrorSemantique(buffer);
                        yyerrok;
                    } else {
                        snprintf(value_str, sizeof(value_str), "%f", (yyvsp[(7) - (8)].reel));
                        int i = update((yyvsp[(3) - (8)].str), "Float", "true", value_str, 1);
                        if(i == -1) {
                            snprintf(buffer, sizeof(buffer), "Erreur dans la declaration de constante %s", (yyvsp[(3) - (8)].str));
                            yyerror(buffer);
                            yyerrok;
                        } else {
                            printf("\nDeclaration de constante flottante %s = %f\n", (yyvsp[(3) - (8)].str), (yyvsp[(7) - (8)].reel));
                        }
                    }
                }
            ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 250 "syntax.y"
    { 
               yyerror("Erreur: Valeur de constante doit etre un iniger ou float");
               yyerrok;
           ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 255 "syntax.y"
    { 
               yyerror("Erreur: constante sans type");
               yyerrok;
           ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 260 "syntax.y"
    { 
               yyerror("Erreur: constante sans type");
               yyerrok;
           ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 265 "syntax.y"
    {
               yyerror("Erreur dans la declaration de constante");
               yyerrok;
           ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 272 "syntax.y"
    {
    (yyval.str) = strdup("Int");
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 275 "syntax.y"
    {
        (yyval.str) = strdup("Float");
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 278 "syntax.y"
    {
        yyerror("Type non reconnu");
        yyerrok;
        (yyval.str) = strdup("Unknown");
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 298 "syntax.y"
    {
                yyerror("Erreur dans l'instruction");
                yyerrok;
            ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 305 "syntax.y"
    { 
                char buffer[100];
                int i = recherche((yyvsp[(1) - (4)].str));

                // undeclared variable
                if(i == -1) {
                    snprintf(buffer,sizeof(buffer),"Erreur: La variable %s n'est pas declaree\n", (yyvsp[(1) - (4)].str));
                    yyerrorSemantique(buffer);
                    yyerrok;

                    // appedend a value to a const
                } else if(isConst((yyvsp[(1) - (4)].str)) == 1) {
                    
                        snprintf(buffer,sizeof(buffer),"Erreur: La constante %s ne peut pas etre modifiee\n", (yyvsp[(1) - (4)].str));
                        yyerrorSemantique(buffer);
                        yyerrok;
                        // no problem
                } else {
                       // Type compatibility check
                    int type_error = 0;
                    if (strcmp(ts[i].TypeEntite, "Int") == 0) {
                        if ((yyvsp[(3) - (4)].expr_info).is_var) {
                            int expr_idx = recherche((yyvsp[(3) - (4)].expr_info).name);
                            if (expr_idx != -1 && strcmp(ts[expr_idx].TypeEntite, "Float") == 0) {
                                snprintf(buffer, sizeof(buffer), "Erreur: Impossible d'assigner un Float a un Int pour %s\n", (yyvsp[(1) - (4)].str));
                                yyerrorSemantique(buffer);
                                type_error = 1;
                            }
                        }
                    }

                    if (!type_error) {
                        printf("\nAffectation pour entite %s \n", (yyvsp[(1) - (4)].str));
                        if ((yyvsp[(3) - (4)].expr_info).is_var) {
                            int expr_idx = recherche((yyvsp[(3) - (4)].expr_info).name);
                            if (expr_idx != -1) {
                                update((yyvsp[(1) - (4)].str), ts[i].TypeEntite, ts[i].isConst ? "true" : "false", ts[expr_idx].Value, 1);
                            }
                        } else {
                            snprintf(buffer, sizeof(buffer), "%d", (yyvsp[(3) - (4)].expr_info).value);
                            update((yyvsp[(1) - (4)].str), ts[i].TypeEntite, ts[i].isConst ? "true" : "false", buffer, 1);
                        }                
                    }
                }
            ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 350 "syntax.y"
    {
                  char buffer[100];
                  snprintf(buffer,sizeof(buffer),"Erreur: L'operateur '=' est une affectation, pas une comparaison\n");
                  yyerror(buffer);
                  yyerrok;
            ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 357 "syntax.y"
    { 
               char buffer[100];
               int i = recherche((yyvsp[(1) - (7)].str));
               int erreur = 0;

               if (i == -1) {
                   snprintf(buffer, sizeof(buffer), "Erreur: La variable %s n'est pas declaree\n", (yyvsp[(1) - (7)].str));
                   yyerrorSemantique(buffer);
                   erreur = 1;
               } else if (ts[i].Length == 1) {
                   snprintf(buffer, sizeof(buffer), "Erreur: La variable %s n'est pas un tableau\n", (yyvsp[(1) - (7)].str));
                   yyerrorSemantique(buffer);
                   erreur = 1;
               } else {
                   int index = (yyvsp[(3) - (7)].entier);
                   if (index < 0 || index >= ts[i].Length) {
                       snprintf(buffer, sizeof(buffer), "Erreur: L'indice %d est hors limites pour le tableau %s\n", index, (yyvsp[(1) - (7)].str));
                       yyerrorSemantique(buffer);
                       erreur = 1;
                   }
               }

               if (!erreur) {
                printf("\nAffectation pour tableau %s[%d] \n", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].entier));
                if ((yyvsp[(6) - (7)].expr_info).is_var) {
                     // Si c'est une variable, on récupère sa valeur de la table des symboles
                     int expr_idx = recherche((yyvsp[(6) - (7)].expr_info).name);
                     if (expr_idx != -1) {
                         update((yyvsp[(1) - (7)].str), ts[i].TypeEntite, ts[i].isConst ? "true" : "false", ts[expr_idx].Value, ts[i].Length);
                     }
                 } else {
                     // Sinon c'est une valeur constante
                     snprintf(buffer, sizeof(buffer), "%d", (yyvsp[(6) - (7)].expr_info).value);
                     update((yyvsp[(1) - (7)].str), ts[i].TypeEntite, ts[i].isConst ? "true" : "false", buffer, ts[i].Length);
                 }
               }
            ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 394 "syntax.y"
    {
                char buffer[100];
                snprintf(buffer,sizeof(buffer),"Erreur: L'operateur '=' est une affectation, pas une comparaison\n");
                yyerror(buffer);
                yyerrok;
            ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 401 "syntax.y"
    { 
                yyerror("Erreur: Point-virgule manquant apres l'affectation");
                yyerrok;
            ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 406 "syntax.y"
    {
                yyerror("Erreur: Point-virgule manquant apres l'affectation de tableau");
                yyerrok;
            ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 411 "syntax.y"
    {
                yyerror("Erreur: Identificateur invalide dans l'affectation");
                yyerrok;
            ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 416 "syntax.y"
    {
                yyerror("Erreur: vous affectez une valeur invalide");
                yyerrok;
            ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 421 "syntax.y"
    {
                yyerror("Erreur: vous affectez une valeur invalide au tableau");
                yyerrok;
            ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 428 "syntax.y"
    { printf("\nCondition if sans else\n"); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 430 "syntax.y"
    { printf("\nCondition if-else\n"); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 432 "syntax.y"
    {
              yyerror("Erreur dans la condition du if");
              yyerrok;
          ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 437 "syntax.y"
    {
            yyerror("Erreur: syntaxe du else incorrect");
             yyerrok;
           ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 442 "syntax.y"
    {
            yyerror("Erreur: syntaxe du else incorrect");
             yyerrok;
           ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 448 "syntax.y"
    {
              yyerror("Erreur: parenthese du exprssion manquant");
              yyerrok;
           ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 453 "syntax.y"
    {
            yyerror("Erreur:erreur dans le else ");
             yyerrok;
           ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 458 "syntax.y"
    {
            yyerror("Erreur:erreur dans le else ");
             yyerrok;
           ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 463 "syntax.y"
    {
              yyerror("Erreur: Syntaxe incorrecte pour la condition if -error");
              yyerrok;
          ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 470 "syntax.y"
    { printf("\nBoucle do-while\n"); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 472 "syntax.y"
    {
              yyerror("Erreur: Parentheses manquantes autour de la condition while");
              yyerrok;
          ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 477 "syntax.y"
    {
              yyerror("Erreur: Syntaxe incorrecte pour la boucle do-while");
              yyerrok;
          ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 484 "syntax.y"
    { 
                char buffer[100];
                int i = recherche((yyvsp[(2) - (11)].str));

                // undeclared variable
                if(i == -1) {
                    snprintf(buffer,sizeof(buffer),"Erreur: La variable %s n'est pas declaree\n", (yyvsp[(2) - (11)].str));
                    yyerrorSemantique(buffer);
                    yyerrok;

                    // no problem
                } else  {
                        printf("\nboucle for bien forme \n");
                } 

            ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 501 "syntax.y"
    {
                yyerror("Erreur: Syntaxe incorrecte pour la boucle for");
                yyerrok;    
            ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 506 "syntax.y"
    {
               yyerror("Erreur: Syntaxe incorrecte pour la boucle for");
               yyerrok;
           ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 513 "syntax.y"
    { 
                char buffer[100];
                int i = recherche((yyvsp[(3) - (5)].str));

                // undeclared variable
                if(i == -1) {
                    snprintf(buffer,sizeof(buffer),"Erreur: entite %s n'est pas declaree\n", (yyvsp[(3) - (5)].str));
                    yyerrorSemantique(buffer);
                    yyerrok;

                    // appedend a value to a const
                } else  {
                    printf("\nInstruction input pour entite %s \n",(yyvsp[(3) - (5)].str));
                } 

         ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 530 "syntax.y"
    {
            yyerror("Erreur: expression invalide dans l'instruction input");
            yyerrok;
        ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 535 "syntax.y"
    {
            yyerror("Erreur: Syntaxe incorrecte pour l'instruction input");
            yyerrok;
        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 542 "syntax.y"
    { 
                printf("\nInstruction output appele \n");
         ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 546 "syntax.y"
    {
            yyerror("Erreur: parenthese fermant manquant pour le output");
             yyerrok;
         ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 551 "syntax.y"
    {
            yyerror("Erreur: parenthese ouvrant manquant pour le output");
             yyerrok;
         ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 556 "syntax.y"
    {
             yyerror("Erreur: Syntaxe incorrecte pour l'instruction output");
             yyerrok;
         ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 565 "syntax.y"
    {
                     yyerror("Erreur dans la liste d'expressions");
                     yyerrok;
                 ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 572 "syntax.y"
    {
            // Pour les opérations simples, on calcule la valeur si on a des constantes
            if (!(yyvsp[(1) - (3)].expr_info).is_var && !(yyvsp[(3) - (3)].expr_info).is_var) {
                (yyval.expr_info).value = (yyvsp[(1) - (3)].expr_info).value + (yyvsp[(3) - (3)].expr_info).value;
                (yyval.expr_info).is_var = 0;
                (yyval.expr_info).name = NULL;

                char buffer[20];
                snprintf(buffer, sizeof(buffer), "%d", (yyval.expr_info).value);
                update("expr", "Int", "false", buffer, 1);
            } else {
                // Sinon, on doit garder l'info que c'est une expression avec variables
                (yyval.expr_info).is_var = 1;
                (yyval.expr_info).name = strdup("expr");  // Nom fictif
                (yyval.expr_info).value = 0;  // Valeur par défaut
            }
        ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 590 "syntax.y"
    {
            // Pour les opérations simples, on calcule la valeur si on a des constantes
            if (!(yyvsp[(1) - (3)].expr_info).is_var && !(yyvsp[(3) - (3)].expr_info).is_var) {
                (yyval.expr_info).value = (yyvsp[(1) - (3)].expr_info).value - (yyvsp[(3) - (3)].expr_info).value;
                (yyval.expr_info).is_var = 0;
                (yyval.expr_info).name = NULL;
            } else {
                // Sinon, on doit garder l'info que c'est une expression avec variables
                (yyval.expr_info).is_var = 1;
                (yyval.expr_info).name = strdup("expr");  // Nom fictif
                (yyval.expr_info).value = 0;  // Valeur par défaut
            }
        ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 604 "syntax.y"
    {
            // Pour les opérations simples, on calcule la valeur si on a des constantes
            if (!(yyvsp[(1) - (3)].expr_info).is_var && !(yyvsp[(3) - (3)].expr_info).is_var) {
                (yyval.expr_info).value = (yyvsp[(1) - (3)].expr_info).value * (yyvsp[(3) - (3)].expr_info).value;
                (yyval.expr_info).is_var = 0;
                (yyval.expr_info).name = NULL;
            } else {
                // Sinon, on doit garder l'info que c'est une expression avec variables
                (yyval.expr_info).is_var = 1;
                (yyval.expr_info).name = strdup("expr");  // Nom fictif
                (yyval.expr_info).value = 0;  // Valeur par défaut
            }
        ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 618 "syntax.y"
    {
            // Vérifier division par zéro pour les constantes
            if (!(yyvsp[(3) - (3)].expr_info).is_var && (yyvsp[(3) - (3)].expr_info).value == 0) {
                char buffer[100];
                snprintf(buffer, sizeof(buffer), "Erreur: Division par zero detectee");
                yyerrorSemantique(buffer);
                yyerrok;
                (yyval.expr_info).value = 0; // Valeur par défaut
                (yyval.expr_info).is_var = 0;
                (yyval.expr_info).name = NULL;
            }
            // Vérifier division par zéro pour les variables
            else if ((yyvsp[(3) - (3)].expr_info).is_var) {
                int divisor_idx = recherche((yyvsp[(3) - (3)].expr_info).name);
                if (divisor_idx != -1) {
                    // Vérifier si la valeur est "0" ou équivalent à 0
                    if (strcmp(ts[divisor_idx].Value, "0") == 0 || 
                        (strcmp(ts[divisor_idx].Value, "null") != 0 && atoi(ts[divisor_idx].Value) == 0)) {
                        char buffer[100];
                        snprintf(buffer, sizeof(buffer), "Erreur: Division par zero detectee avec la variable %s", (yyvsp[(3) - (3)].expr_info).name);
                        yyerrorSemantique(buffer);
                        yyerrok;
                    }
                }
                (yyval.expr_info).is_var = 1;
                (yyval.expr_info).name = strdup("expr");
                (yyval.expr_info).value = 0;
            }
            // Cas normal, division de constantes
            else if (!(yyvsp[(1) - (3)].expr_info).is_var && !(yyvsp[(3) - (3)].expr_info).is_var) {
                (yyval.expr_info).value = (yyvsp[(1) - (3)].expr_info).value / (yyvsp[(3) - (3)].expr_info).value;
                (yyval.expr_info).is_var = 0;
                (yyval.expr_info).name = NULL;
            }
            else {
                (yyval.expr_info).is_var = 1;
                (yyval.expr_info).name = strdup("expr");
                (yyval.expr_info).value = 0;
            }
        ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 659 "syntax.y"
    {
            (yyval.expr_info) = (yyvsp[(2) - (3)].expr_info);
        ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 670 "syntax.y"
    {
        char buffer[100];
        snprintf(buffer,sizeof(buffer),"Erreur: L'operateur '=' est une affectation, pas une comparaison\n");
        yyerror(buffer);
        yyerrok;
        ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 677 "syntax.y"
    {
            char buffer[100];
            int i = recherche((yyvsp[(1) - (1)].str));

            // undeclared variable
            if(i == -1) {
                snprintf(buffer,sizeof(buffer),"Erreur: La variable %s n'est pas declaree\n", (yyvsp[(1) - (1)].str));
                yyerrorSemantique(buffer);
                yyerrok;
                (yyval.expr_info).is_var = 0;
                (yyval.expr_info).value = 0;
                (yyval.expr_info).name = NULL;
            } else {
                
                (yyval.expr_info).is_var = 1;
                (yyval.expr_info).name = strdup((yyvsp[(1) - (1)].str));
                
                // Try to convert value to int if available
                if (strcmp(ts[i].Value, "null") != 0) {
                    (yyval.expr_info).value = atoi(ts[i].Value);
                } else {
                    (yyval.expr_info).value = 0;  // Default value
                }
            }
        ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 703 "syntax.y"
    {
            char buffer[100];
            int i = recherche((yyvsp[(1) - (4)].str));
            int erreur = 0;

            if (i == -1) {
                snprintf(buffer, sizeof(buffer), "Erreur: La variable %s n'est pas declaree\n", (yyvsp[(1) - (4)].str));
                yyerrorSemantique(buffer);
                erreur = 1;
                (yyval.expr_info).is_var = 0;
                (yyval.expr_info).value = 0;
                (yyval.expr_info).name = NULL;
            } else if (ts[i].Length == 1) {
                snprintf(buffer, sizeof(buffer), "Erreur: La variable %s n'est pas un tableau\n", (yyvsp[(1) - (4)].str));
                yyerrorSemantique(buffer);
                erreur = 1;
                (yyval.expr_info).is_var = 0;
                (yyval.expr_info).value = 0;
                (yyval.expr_info).name = NULL;
            } else {
                int index = (yyvsp[(3) - (4)].entier);
                if (index < 0 || index >= ts[i].Length) {
                    snprintf(buffer, sizeof(buffer), "Erreur: L'indice %d est hors limites pour le tableau %s\n", index, (yyvsp[(1) - (4)].str));
                    yyerrorSemantique(buffer);
                    erreur = 1;
                    (yyval.expr_info).is_var = 0;
                    (yyval.expr_info).value = 0;
                    (yyval.expr_info).name = NULL;
                }
            }

            if (!erreur) {
                printf("\nUtilisation du tableau %s[%d] dans une expression\n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].entier));
                (yyval.expr_info).is_var = 1;
                (yyval.expr_info).name = strdup((yyvsp[(1) - (4)].str));  
                (yyval.expr_info).value = 0;  
            }
        ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 742 "syntax.y"
    {
            (yyval.expr_info).value = (yyvsp[(1) - (1)].entier);
            (yyval.expr_info).is_var = 0;
            (yyval.expr_info).name = NULL;
        ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 748 "syntax.y"
    {
            (yyval.expr_info).value = (int)(yyvsp[(1) - (1)].reel); 
            (yyval.expr_info).is_var = 0;
            (yyval.expr_info).name = NULL;
        ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 754 "syntax.y"
    {
        yyerror("Erreur dans l'expression");
        yyerrok;
        (yyval.expr_info).is_var = 0;
        (yyval.expr_info).value = 0;
        (yyval.expr_info).name = NULL;
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2635 "syntax.tab.c"
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
#line 763 "syntax.y"


int yyerror(const char *s) {
    printf("\nErreur Syntaxique a la ligne %d, colonne %d: %s\n", nb_ligne, col, s);
    nb_erreurs++;
    return 0;
}

int yyerrorSemantique(const char *s) {
    printf("\nErreur semantique a la ligne %d, colonne %d: %s\n", nb_ligne, col, s);
    nb_erreurs++;
    return 0;
}


int main() {
    printf("\nAnalyse du programme...\n");
    yyparse();  
    afficher();
    return 0;
}
