/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "src/Javalette.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "Absyn.H"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *str);
void yy_delete_buffer(YY_BUFFER_STATE buf);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  extern char *yytext;
  fprintf(stderr,"error: line %d: %s at %s\n",
    yy_mylinenumber, str, yytext);
}



static Prog* YY_RESULT_Prog_ = 0;

Prog* pProg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Prog_;
  }
}
Prog* pProg(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Prog_;
  }
}




#line 135 "src/Parser.C"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _ERROR_ = 258,                 /* _ERROR_  */
    _SYMB_0 = 259,                 /* _SYMB_0  */
    _SYMB_1 = 260,                 /* _SYMB_1  */
    _SYMB_2 = 261,                 /* _SYMB_2  */
    _SYMB_3 = 262,                 /* _SYMB_3  */
    _SYMB_4 = 263,                 /* _SYMB_4  */
    _SYMB_5 = 264,                 /* _SYMB_5  */
    _SYMB_6 = 265,                 /* _SYMB_6  */
    _SYMB_7 = 266,                 /* _SYMB_7  */
    _SYMB_8 = 267,                 /* _SYMB_8  */
    _SYMB_9 = 268,                 /* _SYMB_9  */
    _SYMB_10 = 269,                /* _SYMB_10  */
    _SYMB_11 = 270,                /* _SYMB_11  */
    _SYMB_12 = 271,                /* _SYMB_12  */
    _SYMB_13 = 272,                /* _SYMB_13  */
    _SYMB_14 = 273,                /* _SYMB_14  */
    _SYMB_15 = 274,                /* _SYMB_15  */
    _SYMB_16 = 275,                /* _SYMB_16  */
    _SYMB_17 = 276,                /* _SYMB_17  */
    _SYMB_18 = 277,                /* _SYMB_18  */
    _SYMB_19 = 278,                /* _SYMB_19  */
    _SYMB_20 = 279,                /* _SYMB_20  */
    _SYMB_21 = 280,                /* _SYMB_21  */
    _SYMB_22 = 281,                /* _SYMB_22  */
    _SYMB_23 = 282,                /* _SYMB_23  */
    _SYMB_24 = 283,                /* _SYMB_24  */
    _SYMB_25 = 284,                /* _SYMB_25  */
    _SYMB_26 = 285,                /* _SYMB_26  */
    _SYMB_27 = 286,                /* _SYMB_27  */
    _SYMB_28 = 287,                /* _SYMB_28  */
    _SYMB_29 = 288,                /* _SYMB_29  */
    _SYMB_30 = 289,                /* _SYMB_30  */
    _SYMB_31 = 290,                /* _SYMB_31  */
    _SYMB_32 = 291,                /* _SYMB_32  */
    _SYMB_33 = 292,                /* _SYMB_33  */
    _SYMB_34 = 293,                /* _SYMB_34  */
    _SYMB_35 = 294,                /* _SYMB_35  */
    _SYMB_36 = 295,                /* _SYMB_36  */
    _SYMB_37 = 296,                /* _SYMB_37  */
    _SYMB_38 = 297,                /* _SYMB_38  */
    _SYMB_39 = 298,                /* _SYMB_39  */
    _STRING_ = 299,                /* _STRING_  */
    _INTEGER_ = 300,               /* _INTEGER_  */
    _DOUBLE_ = 301,                /* _DOUBLE_  */
    _IDENT_ = 302                  /* _IDENT_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "src/Javalette.y"

  int int_;
  char char_;
  double double_;
  char* string_;
  Prog* prog_;
  TopDef* topdef_;
  ListTopDef* listtopdef_;
  Arg* arg_;
  ListArg* listarg_;
  Blk* blk_;
  ListStmt* liststmt_;
  Stmt* stmt_;
  Item* item_;
  ListItem* listitem_;
  Type* type_;
  ListType* listtype_;
  Expr* expr_;
  ListExpr* listexpr_;
  AddOp* addop_;
  MulOp* mulop_;
  RelOp* relop_;

#line 253 "src/Parser.C"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__ERROR_ = 3,                    /* _ERROR_  */
  YYSYMBOL__SYMB_0 = 4,                    /* _SYMB_0  */
  YYSYMBOL__SYMB_1 = 5,                    /* _SYMB_1  */
  YYSYMBOL__SYMB_2 = 6,                    /* _SYMB_2  */
  YYSYMBOL__SYMB_3 = 7,                    /* _SYMB_3  */
  YYSYMBOL__SYMB_4 = 8,                    /* _SYMB_4  */
  YYSYMBOL__SYMB_5 = 9,                    /* _SYMB_5  */
  YYSYMBOL__SYMB_6 = 10,                   /* _SYMB_6  */
  YYSYMBOL__SYMB_7 = 11,                   /* _SYMB_7  */
  YYSYMBOL__SYMB_8 = 12,                   /* _SYMB_8  */
  YYSYMBOL__SYMB_9 = 13,                   /* _SYMB_9  */
  YYSYMBOL__SYMB_10 = 14,                  /* _SYMB_10  */
  YYSYMBOL__SYMB_11 = 15,                  /* _SYMB_11  */
  YYSYMBOL__SYMB_12 = 16,                  /* _SYMB_12  */
  YYSYMBOL__SYMB_13 = 17,                  /* _SYMB_13  */
  YYSYMBOL__SYMB_14 = 18,                  /* _SYMB_14  */
  YYSYMBOL__SYMB_15 = 19,                  /* _SYMB_15  */
  YYSYMBOL__SYMB_16 = 20,                  /* _SYMB_16  */
  YYSYMBOL__SYMB_17 = 21,                  /* _SYMB_17  */
  YYSYMBOL__SYMB_18 = 22,                  /* _SYMB_18  */
  YYSYMBOL__SYMB_19 = 23,                  /* _SYMB_19  */
  YYSYMBOL__SYMB_20 = 24,                  /* _SYMB_20  */
  YYSYMBOL__SYMB_21 = 25,                  /* _SYMB_21  */
  YYSYMBOL__SYMB_22 = 26,                  /* _SYMB_22  */
  YYSYMBOL__SYMB_23 = 27,                  /* _SYMB_23  */
  YYSYMBOL__SYMB_24 = 28,                  /* _SYMB_24  */
  YYSYMBOL__SYMB_25 = 29,                  /* _SYMB_25  */
  YYSYMBOL__SYMB_26 = 30,                  /* _SYMB_26  */
  YYSYMBOL__SYMB_27 = 31,                  /* _SYMB_27  */
  YYSYMBOL__SYMB_28 = 32,                  /* _SYMB_28  */
  YYSYMBOL__SYMB_29 = 33,                  /* _SYMB_29  */
  YYSYMBOL__SYMB_30 = 34,                  /* _SYMB_30  */
  YYSYMBOL__SYMB_31 = 35,                  /* _SYMB_31  */
  YYSYMBOL__SYMB_32 = 36,                  /* _SYMB_32  */
  YYSYMBOL__SYMB_33 = 37,                  /* _SYMB_33  */
  YYSYMBOL__SYMB_34 = 38,                  /* _SYMB_34  */
  YYSYMBOL__SYMB_35 = 39,                  /* _SYMB_35  */
  YYSYMBOL__SYMB_36 = 40,                  /* _SYMB_36  */
  YYSYMBOL__SYMB_37 = 41,                  /* _SYMB_37  */
  YYSYMBOL__SYMB_38 = 42,                  /* _SYMB_38  */
  YYSYMBOL__SYMB_39 = 43,                  /* _SYMB_39  */
  YYSYMBOL__STRING_ = 44,                  /* _STRING_  */
  YYSYMBOL__INTEGER_ = 45,                 /* _INTEGER_  */
  YYSYMBOL__DOUBLE_ = 46,                  /* _DOUBLE_  */
  YYSYMBOL__IDENT_ = 47,                   /* _IDENT_  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Prog = 49,                      /* Prog  */
  YYSYMBOL_TopDef = 50,                    /* TopDef  */
  YYSYMBOL_ListTopDef = 51,                /* ListTopDef  */
  YYSYMBOL_Arg = 52,                       /* Arg  */
  YYSYMBOL_ListArg = 53,                   /* ListArg  */
  YYSYMBOL_Blk = 54,                       /* Blk  */
  YYSYMBOL_ListStmt = 55,                  /* ListStmt  */
  YYSYMBOL_Stmt = 56,                      /* Stmt  */
  YYSYMBOL_Item = 57,                      /* Item  */
  YYSYMBOL_ListItem = 58,                  /* ListItem  */
  YYSYMBOL_Type = 59,                      /* Type  */
  YYSYMBOL_Expr8 = 60,                     /* Expr8  */
  YYSYMBOL_Expr7 = 61,                     /* Expr7  */
  YYSYMBOL_Expr6 = 62,                     /* Expr6  */
  YYSYMBOL_Expr5 = 63,                     /* Expr5  */
  YYSYMBOL_Expr4 = 64,                     /* Expr4  */
  YYSYMBOL_Expr3 = 65,                     /* Expr3  */
  YYSYMBOL_Expr2 = 66,                     /* Expr2  */
  YYSYMBOL_Expr1 = 67,                     /* Expr1  */
  YYSYMBOL_Expr = 68,                      /* Expr  */
  YYSYMBOL_ListExpr = 69,                  /* ListExpr  */
  YYSYMBOL_AddOp = 70,                     /* AddOp  */
  YYSYMBOL_MulOp = 71,                     /* MulOp  */
  YYSYMBOL_RelOp = 72                      /* RelOp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   166,   166,   168,   170,   171,   173,   175,   176,   177,
     179,   181,   182,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   201,
     202,   204,   205,   207,   208,   209,   210,   211,   212,   218,
     219,   221,   222,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   235,   236,   237,   239,   240,   242,   243,
     245,   246,   248,   249,   251,   252,   254,   255,   256,   258,
     259,   261,   262,   263,   265,   266,   267,   268,   269,   270
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_ERROR_", "_SYMB_0",
  "_SYMB_1", "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6",
  "_SYMB_7", "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12",
  "_SYMB_13", "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18",
  "_SYMB_19", "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24",
  "_SYMB_25", "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30",
  "_SYMB_31", "_SYMB_32", "_SYMB_33", "_SYMB_34", "_SYMB_35", "_SYMB_36",
  "_SYMB_37", "_SYMB_38", "_SYMB_39", "_STRING_", "_INTEGER_", "_DOUBLE_",
  "_IDENT_", "$accept", "Prog", "TopDef", "ListTopDef", "Arg", "ListArg",
  "Blk", "ListStmt", "Stmt", "Item", "ListItem", "Type", "Expr8", "Expr7",
  "Expr6", "Expr5", "Expr4", "Expr3", "Expr2", "Expr1", "Expr", "ListExpr",
  "AddOp", "MulOp", "RelOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,  -109,  -109,  -109,  -109,  -109,    48,    94,  -109,   -11,
    -109,  -109,     3,    15,  -109,    94,    43,    23,    -1,    94,
      54,  -109,  -109,  -109,  -109,    76,   179,  -109,  -109,    22,
      22,  -109,    61,    68,    94,     6,  -109,    69,  -109,  -109,
    -109,    66,  -109,  -109,     7,  -109,  -109,    18,  -109,    19,
      10,    62,    55,    -5,    70,    12,    18,    18,    94,   179,
      72,  -109,    73,   179,   179,   179,    87,    89,    90,    93,
      92,   179,    56,  -109,  -109,  -109,   179,  -109,  -109,   179,
     179,  -109,  -109,  -109,  -109,  -109,  -109,   179,   179,  -109,
     179,    95,    97,  -109,    94,     8,   104,   164,  -109,   123,
      96,   125,   124,  -109,  -109,   179,    85,  -109,   126,  -109,
    -109,    19,  -109,    10,  -109,   130,  -109,  -109,    -3,   122,
     120,   127,   120,   179,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,   179,   107,  -109,  -109,  -109,   138,   120,   120,  -109,
    -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    35,    34,    33,    37,    36,     0,     4,     2,     0,
       1,     5,     0,     0,    38,     7,     8,     0,     0,     7,
       0,     6,     9,    11,     3,     0,     0,    10,    13,     0,
       0,    47,     0,     0,     0,     0,    46,     0,    49,    44,
      45,    43,    14,    12,     0,    42,    52,    55,    57,    59,
      61,    63,    65,     0,    43,     0,    53,    54,     0,     0,
       0,    23,     0,     0,    66,     0,     0,     0,    29,    31,
       0,     0,     0,    71,    72,    73,     0,    70,    69,     0,
       0,    74,    75,    76,    77,    78,    79,     0,     0,    28,
       0,     0,     0,    40,     0,     0,     0,     0,    22,     0,
      67,     0,     0,    18,    19,     0,     0,    15,     0,    41,
      56,    58,    62,    60,    64,     0,    20,    21,     0,     0,
       0,     0,     0,    66,    48,    16,    30,    32,    51,    17,
      39,     0,    24,    50,    26,    68,     0,     0,     0,    25,
      27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,   137,  -109,   128,   129,  -109,  -108,  -109,
      39,     1,  -109,  -109,    28,    74,    67,    82,  -109,    91,
     -26,    25,  -109,  -109,  -109
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,    16,    17,    42,    25,    43,    69,
      70,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   101,    79,    76,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,     9,   130,    12,    89,    90,    91,    92,     9,    62,
      26,    12,   132,    12,   134,    61,    18,    93,    14,    15,
      18,    12,    12,    29,    30,    94,    26,    77,    20,   139,
     140,    78,    71,    96,    72,    60,    13,    99,   100,   102,
      31,    73,    74,    75,    34,   108,    21,    36,    10,    19,
      38,    39,    40,    54,    68,   119,    31,    56,    57,    95,
      34,    23,   114,    36,   115,    58,    38,    39,    40,    54,
      64,   121,    59,    63,    64,    88,    65,    66,    67,   126,
      26,    80,    98,    23,    27,    28,    97,    81,    82,    83,
      84,    85,    86,    29,    30,   118,   103,   100,   104,   106,
     105,   107,   123,   109,   116,   136,   117,     1,     2,   120,
      31,    32,    33,     3,    34,    35,     4,    36,     5,    37,
      38,    39,    40,    41,    26,     1,     2,    23,   122,    28,
     124,     3,    68,   125,     4,   131,     5,    29,    30,   129,
     137,   128,   133,   138,    11,   127,   111,    22,   135,    24,
     110,     1,     2,     0,    31,    32,    33,     3,    34,    35,
       4,    36,     5,    37,    38,    39,    40,    41,    26,   113,
       0,   112,     0,     0,     0,     0,     0,     0,     0,    14,
       0,    29,    30,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    30,    31,     0,
       0,     0,    34,     0,     0,    36,     0,     0,    38,    39,
      40,    54,     0,    31,     0,     0,     0,    34,     0,     0,
      36,     0,     0,    38,    39,    40,    54
};

static const yytype_int16 yycheck[] =
{
      26,     0,     5,    14,     9,    10,    11,    12,     7,    35,
       4,    14,   120,    14,   122,     9,    15,     5,    15,     4,
      19,    14,    14,    17,    18,    13,     4,    17,     5,   137,
     138,    21,    14,    59,    16,    34,    47,    63,    64,    65,
      34,    22,    23,    24,    38,    71,    47,    41,     0,     6,
      44,    45,    46,    47,    47,    47,    34,    29,    30,    58,
      38,     7,    88,    41,    90,     4,    44,    45,    46,    47,
       4,    97,     4,     4,     4,    20,    10,    11,    12,   105,
       4,    19,     9,     7,     8,     9,    14,    25,    26,    27,
      28,    29,    30,    17,    18,    94,     9,   123,     9,     6,
      10,     9,     6,    47,     9,   131,     9,    31,    32,     5,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     4,    31,    32,     7,     5,     9,
       5,    37,    47,     9,    40,    13,    42,    17,    18,     9,
      33,    15,    15,     5,     7,   106,    79,    19,   123,    20,
      76,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     4,    87,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    17,    18,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    34,    -1,
      -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    44,    45,
      46,    47,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    32,    37,    40,    42,    49,    50,    51,    59,
       0,    51,    14,    47,    15,     4,    52,    53,    59,     6,
       5,    47,    53,     7,    54,    55,     4,     8,     9,    17,
      18,    34,    35,    36,    38,    39,    41,    43,    44,    45,
      46,    47,    54,    56,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    47,    68,    62,    62,     4,     4,
      59,     9,    68,     4,     4,    10,    11,    12,    47,    57,
      58,    14,    16,    22,    23,    24,    71,    17,    21,    70,
      19,    25,    26,    27,    28,    29,    30,    72,    20,     9,
      10,    11,    12,     5,    13,    59,    68,    14,     9,    68,
      68,    69,    68,     9,     9,    10,     6,     9,    68,    47,
      63,    64,    67,    65,    68,    68,     9,     9,    59,    47,
       5,    68,     5,     6,     5,     9,    68,    58,    15,     9,
       5,    13,    56,    15,    56,    69,    68,    33,     5,    56,
      56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    53,    53,    53,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    60,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    71,    71,    71,    72,    72,    72,    72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     6,     1,     2,     2,     0,     1,     3,
       3,     0,     2,     1,     1,     3,     4,     4,     3,     3,
       3,     3,     3,     2,     5,     7,     5,     8,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     3,     5,
       3,     3,     1,     1,     1,     1,     1,     1,     4,     1,
       5,     4,     1,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Prog: ListTopDef  */
#line 166 "src/Javalette.y"
                  {  std::reverse((yyvsp[0].listtopdef_)->begin(),(yyvsp[0].listtopdef_)->end()) ;(yyval.prog_) = new Program((yyvsp[0].listtopdef_)); YY_RESULT_Prog_= (yyval.prog_); }
#line 1416 "src/Parser.C"
    break;

  case 3: /* TopDef: Type _IDENT_ _SYMB_0 ListArg _SYMB_1 Blk  */
#line 168 "src/Javalette.y"
                                                  {  std::reverse((yyvsp[-2].listarg_)->begin(),(yyvsp[-2].listarg_)->end()) ;(yyval.topdef_) = new FnDef((yyvsp[-5].type_), (yyvsp[-4].string_), (yyvsp[-2].listarg_), (yyvsp[0].blk_));  }
#line 1422 "src/Parser.C"
    break;

  case 4: /* ListTopDef: TopDef  */
#line 170 "src/Javalette.y"
                    {  (yyval.listtopdef_) = new ListTopDef() ; (yyval.listtopdef_)->push_back((yyvsp[0].topdef_));  }
#line 1428 "src/Parser.C"
    break;

  case 5: /* ListTopDef: TopDef ListTopDef  */
#line 171 "src/Javalette.y"
                      {  (yyvsp[0].listtopdef_)->push_back((yyvsp[-1].topdef_)) ; (yyval.listtopdef_) = (yyvsp[0].listtopdef_) ;  }
#line 1434 "src/Parser.C"
    break;

  case 6: /* Arg: Type _IDENT_  */
#line 173 "src/Javalette.y"
                   {  (yyval.arg_) = new Argument((yyvsp[-1].type_), (yyvsp[0].string_));  }
#line 1440 "src/Parser.C"
    break;

  case 7: /* ListArg: %empty  */
#line 175 "src/Javalette.y"
                      {  (yyval.listarg_) = new ListArg();  }
#line 1446 "src/Parser.C"
    break;

  case 8: /* ListArg: Arg  */
#line 176 "src/Javalette.y"
        {  (yyval.listarg_) = new ListArg() ; (yyval.listarg_)->push_back((yyvsp[0].arg_));  }
#line 1452 "src/Parser.C"
    break;

  case 9: /* ListArg: Arg _SYMB_2 ListArg  */
#line 177 "src/Javalette.y"
                        {  (yyvsp[0].listarg_)->push_back((yyvsp[-2].arg_)) ; (yyval.listarg_) = (yyvsp[0].listarg_) ;  }
#line 1458 "src/Parser.C"
    break;

  case 10: /* Blk: _SYMB_3 ListStmt _SYMB_4  */
#line 179 "src/Javalette.y"
                               {  (yyval.blk_) = new Block((yyvsp[-1].liststmt_));  }
#line 1464 "src/Parser.C"
    break;

  case 11: /* ListStmt: %empty  */
#line 181 "src/Javalette.y"
                       {  (yyval.liststmt_) = new ListStmt();  }
#line 1470 "src/Parser.C"
    break;

  case 12: /* ListStmt: ListStmt Stmt  */
#line 182 "src/Javalette.y"
                  {  (yyvsp[-1].liststmt_)->push_back((yyvsp[0].stmt_)) ; (yyval.liststmt_) = (yyvsp[-1].liststmt_) ;  }
#line 1476 "src/Parser.C"
    break;

  case 13: /* Stmt: _SYMB_5  */
#line 184 "src/Javalette.y"
               {  (yyval.stmt_) = new Empty();  }
#line 1482 "src/Parser.C"
    break;

  case 14: /* Stmt: Blk  */
#line 185 "src/Javalette.y"
        {  (yyval.stmt_) = new BStmt((yyvsp[0].blk_));  }
#line 1488 "src/Parser.C"
    break;

  case 15: /* Stmt: Type ListItem _SYMB_5  */
#line 186 "src/Javalette.y"
                          {  std::reverse((yyvsp[-1].listitem_)->begin(),(yyvsp[-1].listitem_)->end()) ;(yyval.stmt_) = new Decl((yyvsp[-2].type_), (yyvsp[-1].listitem_));  }
#line 1494 "src/Parser.C"
    break;

  case 16: /* Stmt: _IDENT_ _SYMB_6 Expr _SYMB_5  */
#line 187 "src/Javalette.y"
                                 {  (yyval.stmt_) = new Ass((yyvsp[-3].string_), (yyvsp[-1].expr_));  }
#line 1500 "src/Parser.C"
    break;

  case 17: /* Stmt: Expr _SYMB_6 Expr _SYMB_5  */
#line 188 "src/Javalette.y"
                              {  (yyval.stmt_) = new Ass1((yyvsp[-3].expr_), (yyvsp[-1].expr_));  }
#line 1506 "src/Parser.C"
    break;

  case 18: /* Stmt: _IDENT_ _SYMB_7 _SYMB_5  */
#line 189 "src/Javalette.y"
                            {  (yyval.stmt_) = new Incr((yyvsp[-2].string_));  }
#line 1512 "src/Parser.C"
    break;

  case 19: /* Stmt: _IDENT_ _SYMB_8 _SYMB_5  */
#line 190 "src/Javalette.y"
                            {  (yyval.stmt_) = new Decr((yyvsp[-2].string_));  }
#line 1518 "src/Parser.C"
    break;

  case 20: /* Stmt: Expr _SYMB_7 _SYMB_5  */
#line 191 "src/Javalette.y"
                         {  (yyval.stmt_) = new Incr1((yyvsp[-2].expr_));  }
#line 1524 "src/Parser.C"
    break;

  case 21: /* Stmt: Expr _SYMB_8 _SYMB_5  */
#line 192 "src/Javalette.y"
                         {  (yyval.stmt_) = new Decr1((yyvsp[-2].expr_));  }
#line 1530 "src/Parser.C"
    break;

  case 22: /* Stmt: _SYMB_35 Expr _SYMB_5  */
#line 193 "src/Javalette.y"
                          {  (yyval.stmt_) = new Ret((yyvsp[-1].expr_));  }
#line 1536 "src/Parser.C"
    break;

  case 23: /* Stmt: _SYMB_35 _SYMB_5  */
#line 194 "src/Javalette.y"
                     {  (yyval.stmt_) = new VRet();  }
#line 1542 "src/Parser.C"
    break;

  case 24: /* Stmt: _SYMB_32 _SYMB_0 Expr _SYMB_1 Stmt  */
#line 195 "src/Javalette.y"
                                       {  (yyval.stmt_) = new Cond((yyvsp[-2].expr_), (yyvsp[0].stmt_));  }
#line 1548 "src/Parser.C"
    break;

  case 25: /* Stmt: _SYMB_32 _SYMB_0 Expr _SYMB_1 Stmt _SYMB_29 Stmt  */
#line 196 "src/Javalette.y"
                                                     {  (yyval.stmt_) = new CondElse((yyvsp[-4].expr_), (yyvsp[-2].stmt_), (yyvsp[0].stmt_));  }
#line 1554 "src/Parser.C"
    break;

  case 26: /* Stmt: _SYMB_39 _SYMB_0 Expr _SYMB_1 Stmt  */
#line 197 "src/Javalette.y"
                                       {  (yyval.stmt_) = new While((yyvsp[-2].expr_), (yyvsp[0].stmt_));  }
#line 1560 "src/Parser.C"
    break;

  case 27: /* Stmt: _SYMB_31 _SYMB_0 Type _IDENT_ _SYMB_9 Expr _SYMB_1 Stmt  */
#line 198 "src/Javalette.y"
                                                            {  (yyval.stmt_) = new For((yyvsp[-5].type_), (yyvsp[-4].string_), (yyvsp[-2].expr_), (yyvsp[0].stmt_));  }
#line 1566 "src/Parser.C"
    break;

  case 28: /* Stmt: Expr _SYMB_5  */
#line 199 "src/Javalette.y"
                 {  (yyval.stmt_) = new SExp((yyvsp[-1].expr_));  }
#line 1572 "src/Parser.C"
    break;

  case 29: /* Item: _IDENT_  */
#line 201 "src/Javalette.y"
               {  (yyval.item_) = new NoInit((yyvsp[0].string_));  }
#line 1578 "src/Parser.C"
    break;

  case 30: /* Item: _IDENT_ _SYMB_6 Expr  */
#line 202 "src/Javalette.y"
                         {  (yyval.item_) = new Init((yyvsp[-2].string_), (yyvsp[0].expr_));  }
#line 1584 "src/Parser.C"
    break;

  case 31: /* ListItem: Item  */
#line 204 "src/Javalette.y"
                {  (yyval.listitem_) = new ListItem() ; (yyval.listitem_)->push_back((yyvsp[0].item_));  }
#line 1590 "src/Parser.C"
    break;

  case 32: /* ListItem: Item _SYMB_2 ListItem  */
#line 205 "src/Javalette.y"
                          {  (yyvsp[0].listitem_)->push_back((yyvsp[-2].item_)) ; (yyval.listitem_) = (yyvsp[0].listitem_) ;  }
#line 1596 "src/Parser.C"
    break;

  case 33: /* Type: _SYMB_33  */
#line 207 "src/Javalette.y"
                {  (yyval.type_) = new Int();  }
#line 1602 "src/Parser.C"
    break;

  case 34: /* Type: _SYMB_28  */
#line 208 "src/Javalette.y"
             {  (yyval.type_) = new Doub();  }
#line 1608 "src/Parser.C"
    break;

  case 35: /* Type: _SYMB_27  */
#line 209 "src/Javalette.y"
             {  (yyval.type_) = new Bool();  }
#line 1614 "src/Parser.C"
    break;

  case 36: /* Type: _SYMB_38  */
#line 210 "src/Javalette.y"
             {  (yyval.type_) = new Void();  }
#line 1620 "src/Parser.C"
    break;

  case 37: /* Type: _SYMB_36  */
#line 211 "src/Javalette.y"
             {  (yyval.type_) = new Str();  }
#line 1626 "src/Parser.C"
    break;

  case 38: /* Type: Type _SYMB_10 _SYMB_11  */
#line 212 "src/Javalette.y"
                           {  (yyval.type_) = new Array((yyvsp[-2].type_));  }
#line 1632 "src/Parser.C"
    break;

  case 39: /* Expr8: _SYMB_0 Expr _SYMB_9 Type _SYMB_1  */
#line 218 "src/Javalette.y"
                                          {  (yyval.expr_) = new ETypeAnn((yyvsp[-3].expr_), (yyvsp[-1].type_));  }
#line 1638 "src/Parser.C"
    break;

  case 40: /* Expr8: _SYMB_0 Expr _SYMB_1  */
#line 219 "src/Javalette.y"
                         {  (yyval.expr_) = (yyvsp[-1].expr_);  }
#line 1644 "src/Parser.C"
    break;

  case 41: /* Expr7: Expr6 _SYMB_12 _IDENT_  */
#line 221 "src/Javalette.y"
                               {  (yyval.expr_) = new ELen((yyvsp[-2].expr_), (yyvsp[0].string_));  }
#line 1650 "src/Parser.C"
    break;

  case 42: /* Expr7: Expr8  */
#line 222 "src/Javalette.y"
          {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 1656 "src/Parser.C"
    break;

  case 43: /* Expr6: _IDENT_  */
#line 224 "src/Javalette.y"
                {  (yyval.expr_) = new EVar((yyvsp[0].string_));  }
#line 1662 "src/Parser.C"
    break;

  case 44: /* Expr6: _INTEGER_  */
#line 225 "src/Javalette.y"
              {  (yyval.expr_) = new ELitInt((yyvsp[0].int_));  }
#line 1668 "src/Parser.C"
    break;

  case 45: /* Expr6: _DOUBLE_  */
#line 226 "src/Javalette.y"
             {  (yyval.expr_) = new ELitDoub((yyvsp[0].double_));  }
#line 1674 "src/Parser.C"
    break;

  case 46: /* Expr6: _SYMB_37  */
#line 227 "src/Javalette.y"
             {  (yyval.expr_) = new ELitTrue();  }
#line 1680 "src/Parser.C"
    break;

  case 47: /* Expr6: _SYMB_30  */
#line 228 "src/Javalette.y"
             {  (yyval.expr_) = new ELitFalse();  }
#line 1686 "src/Parser.C"
    break;

  case 48: /* Expr6: _IDENT_ _SYMB_0 ListExpr _SYMB_1  */
#line 229 "src/Javalette.y"
                                     {  std::reverse((yyvsp[-1].listexpr_)->begin(),(yyvsp[-1].listexpr_)->end()) ;(yyval.expr_) = new EApp((yyvsp[-3].string_), (yyvsp[-1].listexpr_));  }
#line 1692 "src/Parser.C"
    break;

  case 49: /* Expr6: _STRING_  */
#line 230 "src/Javalette.y"
             {  (yyval.expr_) = new EString((yyvsp[0].string_));  }
#line 1698 "src/Parser.C"
    break;

  case 50: /* Expr6: _SYMB_34 Type _SYMB_10 Expr _SYMB_11  */
#line 231 "src/Javalette.y"
                                         {  (yyval.expr_) = new ENewArr((yyvsp[-3].type_), (yyvsp[-1].expr_));  }
#line 1704 "src/Parser.C"
    break;

  case 51: /* Expr6: Expr6 _SYMB_10 Expr _SYMB_11  */
#line 232 "src/Javalette.y"
                                 {  (yyval.expr_) = new EIndex((yyvsp[-3].expr_), (yyvsp[-1].expr_));  }
#line 1710 "src/Parser.C"
    break;

  case 52: /* Expr6: Expr7  */
#line 233 "src/Javalette.y"
          {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 1716 "src/Parser.C"
    break;

  case 53: /* Expr5: _SYMB_13 Expr6  */
#line 235 "src/Javalette.y"
                       {  (yyval.expr_) = new Neg((yyvsp[0].expr_));  }
#line 1722 "src/Parser.C"
    break;

  case 54: /* Expr5: _SYMB_14 Expr6  */
#line 236 "src/Javalette.y"
                   {  (yyval.expr_) = new Not((yyvsp[0].expr_));  }
#line 1728 "src/Parser.C"
    break;

  case 55: /* Expr5: Expr6  */
#line 237 "src/Javalette.y"
          {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 1734 "src/Parser.C"
    break;

  case 56: /* Expr4: Expr4 MulOp Expr5  */
#line 239 "src/Javalette.y"
                          {  (yyval.expr_) = new EMul((yyvsp[-2].expr_), (yyvsp[-1].mulop_), (yyvsp[0].expr_));  }
#line 1740 "src/Parser.C"
    break;

  case 57: /* Expr4: Expr5  */
#line 240 "src/Javalette.y"
          {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 1746 "src/Parser.C"
    break;

  case 58: /* Expr3: Expr3 AddOp Expr4  */
#line 242 "src/Javalette.y"
                          {  (yyval.expr_) = new EAdd((yyvsp[-2].expr_), (yyvsp[-1].addop_), (yyvsp[0].expr_));  }
#line 1752 "src/Parser.C"
    break;

  case 59: /* Expr3: Expr4  */
#line 243 "src/Javalette.y"
          {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 1758 "src/Parser.C"
    break;

  case 60: /* Expr2: Expr2 RelOp Expr3  */
#line 245 "src/Javalette.y"
                          {  (yyval.expr_) = new ERel((yyvsp[-2].expr_), (yyvsp[-1].relop_), (yyvsp[0].expr_));  }
#line 1764 "src/Parser.C"
    break;

  case 61: /* Expr2: Expr3  */
#line 246 "src/Javalette.y"
          {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 1770 "src/Parser.C"
    break;

  case 62: /* Expr1: Expr2 _SYMB_15 Expr1  */
#line 248 "src/Javalette.y"
                             {  (yyval.expr_) = new EAnd((yyvsp[-2].expr_), (yyvsp[0].expr_));  }
#line 1776 "src/Parser.C"
    break;

  case 63: /* Expr1: Expr2  */
#line 249 "src/Javalette.y"
          {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 1782 "src/Parser.C"
    break;

  case 64: /* Expr: Expr1 _SYMB_16 Expr  */
#line 251 "src/Javalette.y"
                           {  (yyval.expr_) = new EOr((yyvsp[-2].expr_), (yyvsp[0].expr_));  }
#line 1788 "src/Parser.C"
    break;

  case 65: /* Expr: Expr1  */
#line 252 "src/Javalette.y"
          {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 1794 "src/Parser.C"
    break;

  case 66: /* ListExpr: %empty  */
#line 254 "src/Javalette.y"
                       {  (yyval.listexpr_) = new ListExpr();  }
#line 1800 "src/Parser.C"
    break;

  case 67: /* ListExpr: Expr  */
#line 255 "src/Javalette.y"
         {  (yyval.listexpr_) = new ListExpr() ; (yyval.listexpr_)->push_back((yyvsp[0].expr_));  }
#line 1806 "src/Parser.C"
    break;

  case 68: /* ListExpr: Expr _SYMB_2 ListExpr  */
#line 256 "src/Javalette.y"
                          {  (yyvsp[0].listexpr_)->push_back((yyvsp[-2].expr_)) ; (yyval.listexpr_) = (yyvsp[0].listexpr_) ;  }
#line 1812 "src/Parser.C"
    break;

  case 69: /* AddOp: _SYMB_17  */
#line 258 "src/Javalette.y"
                 {  (yyval.addop_) = new Plus();  }
#line 1818 "src/Parser.C"
    break;

  case 70: /* AddOp: _SYMB_13  */
#line 259 "src/Javalette.y"
             {  (yyval.addop_) = new Minus();  }
#line 1824 "src/Parser.C"
    break;

  case 71: /* MulOp: _SYMB_18  */
#line 261 "src/Javalette.y"
                 {  (yyval.mulop_) = new Times();  }
#line 1830 "src/Parser.C"
    break;

  case 72: /* MulOp: _SYMB_19  */
#line 262 "src/Javalette.y"
             {  (yyval.mulop_) = new Div();  }
#line 1836 "src/Parser.C"
    break;

  case 73: /* MulOp: _SYMB_20  */
#line 263 "src/Javalette.y"
             {  (yyval.mulop_) = new Mod();  }
#line 1842 "src/Parser.C"
    break;

  case 74: /* RelOp: _SYMB_21  */
#line 265 "src/Javalette.y"
                 {  (yyval.relop_) = new LTH();  }
#line 1848 "src/Parser.C"
    break;

  case 75: /* RelOp: _SYMB_22  */
#line 266 "src/Javalette.y"
             {  (yyval.relop_) = new LE();  }
#line 1854 "src/Parser.C"
    break;

  case 76: /* RelOp: _SYMB_23  */
#line 267 "src/Javalette.y"
             {  (yyval.relop_) = new GTH();  }
#line 1860 "src/Parser.C"
    break;

  case 77: /* RelOp: _SYMB_24  */
#line 268 "src/Javalette.y"
             {  (yyval.relop_) = new GE();  }
#line 1866 "src/Parser.C"
    break;

  case 78: /* RelOp: _SYMB_25  */
#line 269 "src/Javalette.y"
             {  (yyval.relop_) = new EQU();  }
#line 1872 "src/Parser.C"
    break;

  case 79: /* RelOp: _SYMB_26  */
#line 270 "src/Javalette.y"
             {  (yyval.relop_) = new NE();  }
#line 1878 "src/Parser.C"
    break;


#line 1882 "src/Parser.C"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

