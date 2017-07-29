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
#line 25 "compiler/front/parser/grammar.y" /* yacc.c:1909  */

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
#line 17 "compiler/front/parser/grammar.y" /* yacc.c:1909  */

    int itype;
    struct ast *astNode;

    struct symbol *symbolValue;
    struct symlist *symbolList;

#line 105 "grammar.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
