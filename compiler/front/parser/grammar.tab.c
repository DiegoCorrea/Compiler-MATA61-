/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compiler/front/parser/grammar.y" /* yacc.c:339  */

  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "./tree.h"

  int yylex(void);
  void yyerror(char const *);
  FILE *yyin;
  FILE *fl_output;
  extern int yylineno;

  struct ast *ROOT;
  struct ast *ROOT_CHILDS = NULL;
  int START_OK = 0;

  struct symbol symtab[NHASH];

#line 86 "grammar.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    DEC = 259,
    LET_T = 260,
    DEF_T = 261,
    IF_T = 262,
    ELSE_T = 263,
    WHILE_T = 264,
    BREAK_T = 265,
    CONTINUE_T = 266,
    RETURN_T = 267,
    LPARENT = 268,
    RPARENT = 269,
    LBRACE = 270,
    RBRACE = 271,
    LBRACKETS = 272,
    RBRACKETS = 273,
    COMMA = 274,
    SEMICOLON = 275,
    PLUS = 276,
    MINUS = 277,
    MULTIPLY = 278,
    DIVIDER = 279,
    LESSTHAN = 280,
    BIGGERTHAN = 281,
    LESSOREQUAL = 282,
    BIGGEROREQUAL = 283,
    EQUAL = 284,
    ASSIGN = 285,
    NOTEQUAL = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    ERROR = 290,
    UMINUS = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "compiler/front/parser/grammar.y" /* yacc.c:355  */

  int itype;
  struct ast *astNode;

  struct symbol *symbolValue;
  struct symlist *symbolList;

#line 171 "grammar.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 188 "grammar.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,   100,   104,   110,   115,   132,   135,   140,
     145,   156,   168,   178,   181,   184,   189,   192,   199,   202,
     205,   208,   211,   212,   213,   214,   219,   231,   236,   247,
     250,   255,   263,   269,   275,   282,   286,   289,   292,   295,
     298,   304,   310,   316,   322,   328,   334,   340,   346,   352,
     358,   364,   372,   375,   380,   389,   403,   406
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "DEC", "LET_T", "DEF_T", "IF_T",
  "ELSE_T", "WHILE_T", "BREAK_T", "CONTINUE_T", "RETURN_T", "LPARENT",
  "RPARENT", "LBRACE", "RBRACE", "LBRACKETS", "RBRACKETS", "COMMA",
  "SEMICOLON", "PLUS", "MINUS", "MULTIPLY", "DIVIDER", "LESSTHAN",
  "BIGGERTHAN", "LESSOREQUAL", "BIGGEROREQUAL", "EQUAL", "ASSIGN",
  "NOTEQUAL", "AND", "OR", "NOT", "ERROR", "UMINUS", "$accept", "start",
  "program", "decvar", "decvarassign", "decfunc", "decfuncids", "block",
  "blockstatements", "paramlist", "statement", "assigner", "conditional",
  "elseconditional", "loop", "break", "continue", "return", "expr", "unop",
  "funccall", "arglist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -44

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define YYTABLE_NINF -28

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -44,     6,     2,   -44,    -1,     9,   -44,   -44,   -16,     3,
     -44,    56,    29,     1,    39,   -44,    56,   -44,   -44,   168,
      56,   -44,   -44,    36,    52,    54,    32,    60,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
     -44,    70,   127,   -44,    52,   -44,   141,    61,   -44,   -13,
     -13,   -44,   -44,    41,    41,    41,    41,    16,    41,   181,
     181,   -44,     0,    63,    64,    59,    75,    56,   127,    81,
     -44,    76,   139,   139,   -44,   -44,   -44,    78,   -44,    56,
     -44,    56,    56,    56,   -44,   -44,   155,   -44,   -44,   139,
     -44,   -44,   139,   -44,   168,    80,    96,   -44,   -44,   -44,
      52,    52,    72,   -44,    52,   -44,   -44
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     2,     1,     0,     0,     3,     4,     7,     0,
       9,     0,     0,     0,    39,    38,     0,    52,    53,     8,
       0,    37,     6,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,     0,    15,    11,     0,    54,    56,     0,    36,    40,
      41,    42,    43,    44,    46,    45,    47,    48,    49,    50,
      51,    17,     0,     0,     0,     0,     0,     0,    15,     0,
      14,     0,    25,    25,    23,    24,    22,     0,    10,     0,
      55,     0,     0,     0,    32,    33,     0,    13,    12,    25,
      20,    21,    25,    57,    26,     0,     0,    34,    18,    19,
       0,     0,    29,    31,     0,    28,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,   -44,    97,   -44,   -44,   -44,   -43,    46,    74,
     -41,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -11,   -44,
     -39,    21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    68,    12,     7,    10,    43,    69,    25,
      70,    71,    72,   105,    73,    74,    75,    76,    46,    20,
      21,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,    78,     8,    77,    23,    27,     3,     4,     5,    40,
      30,    31,     9,    26,    11,    24,    13,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    77,
      81,    90,    91,    77,    77,    14,    15,    28,    29,    30,
      31,    32,    33,    34,    35,    16,    45,    37,    98,    22,
      77,    99,    26,    77,    17,    41,    86,   102,   103,    14,
      15,   106,    28,    29,    30,    31,    18,    42,    44,    16,
      94,    95,    96,    23,    48,    80,    82,    83,    17,    84,
     104,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      18,    37,    38,    39,   100,    85,    89,    88,    92,     6,
      93,    28,    29,    30,    31,    32,    33,    34,    35,    36,
     101,    37,    38,    39,    87,    61,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,    37,    38,    39,
      62,     0,     4,     0,    63,     0,    64,    65,    66,    67,
       0,     0,    62,     0,     0,     0,    63,   -27,    64,    65,
      66,    67,     0,     0,     0,     0,     0,     0,     0,   -27,
      79,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,    37,    38,    39,    97,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,    37,    38,    39,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,    37,
      38,    39,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,    37
};

static const yytype_int8 yycheck[] =
{
      11,    44,     3,    42,     3,    16,     0,     5,     6,    20,
      23,    24,     3,    13,    30,    14,    13,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    68,
      30,    72,    73,    72,    73,     3,     4,    21,    22,    23,
      24,    25,    26,    27,    28,    13,    14,    31,    89,    20,
      89,    92,    13,    92,    22,    19,    67,   100,   101,     3,
       4,   104,    21,    22,    23,    24,    34,    15,    14,    13,
      81,    82,    83,     3,    14,    14,    13,    13,    22,    20,
       8,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      34,    31,    32,    33,    14,    20,    20,    16,    20,     2,
      79,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      14,    31,    32,    33,    68,    41,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
       3,    -1,     5,    -1,     7,    -1,     9,    10,    11,    12,
      -1,    -1,     3,    -1,    -1,    -1,     7,    20,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,     0,     5,     6,    40,    42,     3,     3,
      43,    30,    41,    13,     3,     4,    13,    22,    34,    55,
      56,    57,    20,     3,    14,    46,    13,    55,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    31,    32,    33,
      55,    19,    15,    44,    14,    14,    55,    58,    14,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    46,     3,     7,     9,    10,    11,    12,    40,    45,
      47,    48,    49,    51,    52,    53,    54,    57,    44,    19,
      14,    30,    13,    13,    20,    20,    55,    45,    16,    20,
      47,    47,    20,    58,    55,    55,    55,    20,    47,    47,
      14,    14,    44,    44,     8,    50,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    40,    41,    41,    42,
      43,    43,    44,    45,    45,    45,    46,    46,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    48,    49,    50,
      50,    51,    52,    53,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     4,     0,     2,     2,
       5,     4,     3,     2,     1,     0,     1,     3,     3,     3,
       2,     2,     1,     1,     1,     0,     3,     0,     6,     0,
       2,     5,     2,     2,     3,     2,     3,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     4,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 91 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    ROOT = newast("program");
    astAddChild(ROOT, (yyvsp[0].astNode));

    semanticCheck(ROOT, 0, NULL, NULL);
    astPrint(ROOT, 0);
  }
#line 1365 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 100 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    astAddChildrens(&ROOT_CHILDS, (yyvsp[0].astNode));
    (yyval.astNode) = ROOT_CHILDS;
  }
#line 1374 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 104 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *instantFather = newast("decfunc");
    astAddChild(instantFather, (yyvsp[0].astNode));
    astAddChildrens(&ROOT_CHILDS, instantFather);
    (yyval.astNode) = ROOT_CHILDS;
  }
#line 1385 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 110 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    (yyval.astNode) = NULL;
  }
#line 1393 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *decvar_node = newast("decvar");

    struct ast *id_node = newref("ID", (yyvsp[-2].symbolValue));
    astAddChild(decvar_node, id_node);

    if((yyvsp[-1].astNode) != NULL){
      astAddChild(decvar_node, (yyvsp[-1].astNode));

      (yyval.astNode) = decvar_node;
    }
    else{
      (yyval.astNode) = decvar_node;
    }
  }
#line 1413 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
      (yyval.astNode) = NULL;
    }
#line 1421 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 135 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
      (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1429 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 140 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    (yyval.astNode) = (yyvsp[0].astNode);
  }
#line 1437 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 145 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *id_node = newref("ID", (yyvsp[-4].symbolValue));

    struct ast *paramlist_node = newast("paramlist");
    astAddChild(paramlist_node, (yyvsp[-2].astNode));

    astNodeBrothers(id_node, paramlist_node);
    astNodeBrothers(id_node, (yyvsp[0].astNode));

    (yyval.astNode) = id_node;
  }
#line 1453 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 156 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *id_node = newref("ID", (yyvsp[-3].symbolValue));

    struct ast *paramlist_node = newast("paramlist");
    astNodeBrothers(id_node, paramlist_node);

    astNodeBrothers(id_node, (yyvsp[0].astNode));

    (yyval.astNode) = id_node;
  }
#line 1468 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 168 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *instantFather = newast("block");

    if((yyvsp[-1].astNode) != NULL)
        astAddChild(instantFather, (yyvsp[-1].astNode));

    (yyval.astNode) = instantFather;
  }
#line 1481 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 178 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        astNodeBrothers((yyvsp[-1].astNode), (yyvsp[0].astNode));
     }
#line 1489 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 181 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {

     }
#line 1497 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 184 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        (yyval.astNode) = NULL;
    }
#line 1505 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 189 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    (yyval.astNode) = newref("ID", (yyvsp[0].symbolValue));
  }
#line 1513 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 192 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *brother = newref("ID", (yyvsp[-2].symbolValue));
    astNodeBrothers(brother,(yyvsp[0].astNode));
    (yyval.astNode) = brother;
  }
#line 1523 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 199 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    astNodeBrothers((yyvsp[-2].astNode), (yyvsp[0].astNode));
  }
#line 1531 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 202 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    astNodeBrothers((yyvsp[-2].astNode), (yyvsp[0].astNode));
  }
#line 1539 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 205 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    astNodeBrothers((yyvsp[-1].astNode), (yyvsp[0].astNode));
  }
#line 1547 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 208 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    astNodeBrothers((yyvsp[-1].astNode), (yyvsp[0].astNode));
  }
#line 1555 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 214 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    (yyval.astNode) = NULL;
  }
#line 1563 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 219 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *id = newref("ID", (yyvsp[-2].symbolValue));
    if((yyvsp[0].astNode) != NULL){
      struct ast *assign = newast("assign");
      astAddChild(assign,id);
      astAddChild(assign,(yyvsp[0].astNode));
      (yyval.astNode) = assign;
    }
    else{
      (yyval.astNode) = id;
    }
  }
#line 1580 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 231 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    (yyval.astNode) = NULL;
  }
#line 1588 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 236 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *instantFather = newast("if");
    astAddChild(instantFather,(yyvsp[-3].astNode));
    astAddChild(instantFather,(yyvsp[-1].astNode));
    if((yyvsp[0].astNode) != NULL){
      astAddChild(instantFather,(yyvsp[0].astNode));
    }
    (yyval.astNode) = instantFather;
  }
#line 1602 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 247 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    (yyval.astNode) = NULL;
  }
#line 1610 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 250 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    (yyval.astNode) = (yyvsp[0].astNode);
  }
#line 1618 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 255 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *instantFather = newast("while");
    astAddChild(instantFather,(yyvsp[-2].astNode));
    astAddChild(instantFather,(yyvsp[0].astNode));
    (yyval.astNode) = instantFather;
  }
#line 1629 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 263 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
    struct ast *instantFather = newast("break");
    (yyval.astNode) = instantFather;
  }
#line 1638 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 269 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("continue");
        (yyval.astNode) = instantFather;
    }
#line 1647 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 275 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("return");
        astAddChild(instantFather,(yyvsp[-1].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1657 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 282 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        astAddChild((yyvsp[-1].astNode),(yyvsp[0].astNode));
        (yyval.astNode) = (yyvsp[-1].astNode);
    }
#line 1666 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 286 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        (yyval.astNode) = (yyvsp[-1].astNode);
    }
#line 1674 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 289 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        (yyval.astNode) = (yyvsp[0].astNode);
    }
#line 1682 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 292 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        (yyval.astNode) = newnum("DEC", (yyvsp[0].itype));
    }
#line 1690 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 295 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        (yyval.astNode) = newref("ID", (yyvsp[0].symbolValue));
    }
#line 1698 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 298 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("+");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1709 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 304 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("-");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1720 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 310 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("*");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1731 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 316 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("/");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1742 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 322 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("<");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1753 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 328 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("<=");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1764 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 334 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast(">");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1775 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 340 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast(">=");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1786 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 346 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("==");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1797 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 352 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("!=");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1808 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 358 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("&&");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1819 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 364 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("||");
        astAddChild(instantFather,(yyvsp[-2].astNode));
        astAddChild(instantFather,(yyvsp[0].astNode));
        (yyval.astNode) = instantFather;
    }
#line 1830 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 372 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        (yyval.astNode) = newast("-");
    }
#line 1838 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 375 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        (yyval.astNode) = newast("!");
    }
#line 1846 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 380 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("funccall");
        astAddChild(instantFather, newref("ID", (yyvsp[-2].symbolValue)));

        struct ast *argument_list = newast("arglist");
        astAddChild(instantFather, argument_list);

        (yyval.astNode) = instantFather;
    }
#line 1860 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 389 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        struct ast *instantFather = newast("funccall");

        astAddChild(instantFather, newref("ID", (yyvsp[-3].symbolValue)));

        struct ast *argument_list = newast("arglist");
        astAddChild(argument_list, (yyvsp[-1].astNode));

        astAddChild(instantFather, argument_list);
        //astAddChild(instantFather, $3);
        (yyval.astNode) = instantFather;
    }
#line 1877 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 403 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        //$$ = $1;
    }
#line 1885 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 406 "compiler/front/parser/grammar.y" /* yacc.c:1646  */
    {
        astNodeBrothers((yyvsp[-2].astNode), (yyvsp[0].astNode));
        //$$ = $1;
    }
#line 1894 "grammar.tab.c" /* yacc.c:1646  */
    break;


#line 1898 "grammar.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 411 "compiler/front/parser/grammar.y" /* yacc.c:1906  */


void yyerror(char const *err){
  printf("[PARSER] Error na linha %d.\nMensagem: %s\n", yylineno, err);
  exit(1);
}
void readFromFile( argc, argv )
	int argc;
	char **argv;
{
	++argv, --argc;	/* skip over program name */
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
}
struct ast *newast(char nodetype[MAX_NODE_TYPE]) {
  struct ast *no = (struct ast *)malloc(sizeof(struct ast));
  if(!no) {
    exit(0);
  }

  strcpy(no->nodetype,nodetype);
  no->childrens = NULL;
  no->nextBrother = NULL;
  no->previousBrother = NULL;

  return (struct ast *)no;
}
void astAddChild(struct ast *father, struct ast *child){
  struct ast *walkNode;
  if(father->childrens == NULL){
    father->childrens = child;
  }else{
    for(walkNode = father->childrens; walkNode->nextBrother != NULL; walkNode = walkNode->nextBrother);

    walkNode->nextBrother = child;
    child->previousBrother = walkNode;
  }
}
void astNumAddChild(struct ast *father, struct ast *child){
  struct ast *walkNode;
  if(father->childrens == NULL){
    father->childrens = child;
  }else{
    for(walkNode = father->childrens; walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);

    walkNode->nextBrother = child;
    child->previousBrother = walkNode;
  }
}
struct ast *newnum(char nodetype[MAX_NODE_TYPE], int number){
  struct ast *no = (struct ast *)malloc(sizeof(struct ast));
  if(!no) {
    //yyerror("out of space");
    exit(0);
  }

  strcpy(no->nodetype,nodetype);
  no->dec.number = number;

  no->childrens = NULL;
  no->nextBrother = NULL;
  no->previousBrother = NULL;

  return (struct ast *)no;
}
struct ast *newref(char nodetype[MAX_NODE_TYPE], struct symbol *name){
  struct ast *no = (struct ast *)malloc(sizeof(struct ast));
  if(!no) {
    yyerror("out of space");
    exit(0);
  }

  strcpy(no->nodetype,nodetype);
  no->identification = name;
  no->childrens = NULL;
  no->nextBrother = NULL;
  no->previousBrother = NULL;

  return (struct ast *)no;
}
void astPrint(struct ast *father, int tab){
  struct ast *walker;

  for(walker = father; walker != NULL; walker = walker->nextBrother){
    for(int i = 0; i < tab; i++){
      fprintf(fl_output,"\t");
    }
    if(strcmp(walker->nodetype,"DEC") == 0){
      fprintf(fl_output,"[%d \n", walker->dec.number);
    } else if(strcmp(walker->nodetype,"ID") == 0){
      char *name = walker->identification->name;
      fprintf(fl_output,"[%s \n", name);
    } else{
      fprintf(fl_output,"[%s \n", walker->nodetype);
    }
    if(walker->childrens != NULL)
      astPrint(walker->childrens,tab+1);
    for(int i = 0; i < tab; i++){
      fprintf(fl_output,"\t");
    }
    fprintf(fl_output,"]\n");
  }
}
void astAddChildrens(struct ast **head_list, struct ast *newBrother){
  struct ast *walkNode;
  if(*head_list != NULL){
    for(walkNode = *head_list; walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);
    walkNode->nextBrother = newBrother;
    newBrother->previousBrother = walkNode;
  }
  else{
    *head_list = newBrother;
  }
}
void astNodeBrothers(struct ast *leftBrother, struct ast *rightBrother){
  struct ast *walkNode;
  if(rightBrother != NULL){
    for(walkNode = leftBrother; walkNode != NULL && walkNode->nextBrother != NULL;walkNode = walkNode->nextBrother);
    walkNode->nextBrother = rightBrother;
    rightBrother->previousBrother = walkNode;
  }
}
static unsigned symhash(char *sym){
  unsigned int hash = 0;
  unsigned c;
  while(c = *sym++) hash = hash*9 ^ c;

  return hash;
}
struct symbol *lookup(char* sym) {
  struct symbol *sp = &symtab[symhash(sym)%NHASH];
  int scount = NHASH;

  while(--scount >= 0) {
    if(sp->name && !strcmp(sp->name, sym)) { return sp; }
    if(!sp->name) {
      sp->name = strdup(sym);
      sp->value = 0;
      sp->func = NULL;
      sp->syms = NULL;
      return sp;
    }
    if(++sp >= symtab+NHASH) sp = symtab; /* try the next entry */
  }
}
struct vardeclaration *symStackPush(struct vardeclaration *var_stack, struct vardeclaration *var_node){
  var_node->next = var_stack;
  return var_node;
}
int onVarStack(struct vardeclaration *top_stack, struct symbol *sym){
  struct vardeclaration *walkerStack;

  for(walkerStack = top_stack; walkerStack != NULL && (strcmp(walkerStack->sym->name, sym->name) != 0); walkerStack = walkerStack->next);
  if(walkerStack != NULL && (strcmp(walkerStack->sym->name, sym->name) == 0)){
    return 0;
  }
  return 1;
}
void reservedWords(struct symbol *sym){
  if(strcmp("print", sym->name) == 0){
    exit(0);
  }
  if(strcmp("main", sym->name) == 0){
    START_OK = 1;
  }
}
void semanticCheck(struct ast *father, int nivel, struct vardeclaration *var_stack, struct vardeclaration *func_stack){
  struct ast *walkerAST;
  for(walkerAST = father; walkerAST != NULL; walkerAST = walkerAST->nextBrother){
    struct vardeclaration *var_node = (struct vardeclaration *)malloc(sizeof(struct vardeclaration));

    if(strcmp(walkerAST->nodetype,"decvar") == 0){
      if(walkerAST->childrens->nextBrother != NULL){
        semanticCheck(walkerAST->childrens->nextBrother, nivel+1, var_stack, func_stack);
      }
      var_node->sym = walkerAST->childrens->identification;
      var_node->nivel = nivel;

      var_stack = symStackPush(var_stack, var_node);
      //printf("\n[Semantico] add VAR: %s", var_node->sym->name);
    } else if(strcmp(walkerAST->nodetype,"decfunc") == 0){
      struct ast *walkChild = walkerAST->childrens;

      reservedWords(walkChild->identification);
      if(onVarStack(func_stack, walkChild->identification) == 0){
        exit(0);
      }

      var_node->sym = walkChild->identification;
      var_node->nivel = nivel;
      func_stack = symStackPush(func_stack, var_node);

      walkChild = walkChild->nextBrother;

      for(struct ast *params_node = walkChild->childrens; params_node != NULL; params_node = params_node->nextBrother){
        var_node = (struct vardeclaration *)malloc(sizeof(struct vardeclaration));

        var_node->sym = walkChild->identification;
        var_node->nivel = nivel;

        var_stack = symStackPush(var_stack, var_node);
      }
    }else if(strcmp(walkerAST->nodetype,"funccall") == 0){
      if(onVarStack(func_stack, walkerAST->childrens->identification) == 0){
        //printf("\n[Semantico] %s: Na Pilha", walkerAST->identification->name);
      } else {
        exit(0);
      }
    } else if(strcmp(walkerAST->nodetype,"ID") == 0){
      if(onVarStack(var_stack, walkerAST->identification) == 0){
        //printf("\n[Semantico] %s: Na Pilha", walkerAST->identification->name);
      } else {
        exit(0);
      }
    } else{
      semanticCheck(walkerAST->childrens, nivel+1, var_stack, func_stack);
    }
  }
}
