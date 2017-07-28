/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 24 "compiler/front/parser/grammar.y" /* yacc.c:1909  */

    #include "tree.h"

#line 48 "grammar.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    DEC = 259,
    LET_T = 260,
    DEF_T = 261,
    MAIN_T = 262,
    IF_T = 263,
    ELSE_T = 264,
    WHILE_T = 265,
    BREAK_T = 266,
    CONTINUE_T = 267,
    RETURN_T = 268,
    LPARENT = 269,
    RPARENT = 270,
    LBRACE = 271,
    RBRACE = 272,
    LBRACKETS = 273,
    RBRACKETS = 274,
    COMMA = 275,
    SEMICOLON = 276,
    PLUS = 277,
    MINUS = 278,
    MULTIPLY = 279,
    DIVIDER = 280,
    LESSTHAN = 281,
    BIGGERTHAN = 282,
    LESSOREQUAL = 283,
    BIGGEROREQUAL = 284,
    EQUAL = 285,
    ASSIGN = 286,
    NOTEQUAL = 287,
    AND = 288,
    OR = 289,
    NOT = 290,
    ERROR = 291,
    UMINUS = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "compiler/front/parser/grammar.y" /* yacc.c:1909  */

    int itype;
    struct ast *astNode;

    struct symbol *symbolValue;
    struct symlist *symbolList;

#line 106 "grammar.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
