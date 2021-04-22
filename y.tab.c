/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.c"
#include "quadruples.c"

int g_addr = 100;
int i=1;				// latest SCOPE
int lnum1=0;
int stack[100];
int index1=0;				// index of SCOPE ARRAY
int end[100];
int arr[10];
int ct;
int c;
int b;
int fl;
int top=0;				// index of ST1 STACK 
int label[20];
int label_num=0;			// the label suffix i.e L's suffix
int ltop=0;
char st1[100][10];			// - it is the stack used for generating 3AC in terms of STACK OPERATIONS - holds the different values and operands in expressions
char temp_count[2]="0";		// holds the latest TEMPORARY SUFFIX i.e t's suffix	
int plist[100],flist[100];
int k=-1;
int errc=0;
int j=0;
char temp[2]="t";
char null[2]=" ";
char switch_variable[100];
int next_num = 1;
int is_default = 0;
int is_break = 3;
int prev_case = 3;
char prev_case_break[20];
char buffer[20];
int is_array=0;
char dummy_concat[10];

char op_1[100];
char arg1_1[100];
char arg2_1[100];
char result_1[100];

int is_cond_while = 0;
int is_body_while = 0;
int while_scope = 0; 
char loop_variant_id[10][10];
int id_indicator=1; 
int num_loop_variant_ids=0;
int is_return = 0;
int is_not_lambda = 1;

int return_deadcode_statements_count=0;
char expr_eval_res[20];

void yyerror(char *s);
int printline();

int is_void=0;
int is_print=0;

extern int yylineno;




void dummy_quad(char *op,char *arg1,char *arg2,char *result)
{
	strcpy(op_1,op);
	strcpy(arg1_1,arg1);
	strcpy(arg2_1,arg2);
	strcpy(result_1,result);
}



void check_after_return()
{
	if(is_return>0)
	{	
		++return_deadcode_statements_count;
	}
}
		


char *my_itoa(float num, char *str)
{
        if(str == NULL)
        {
                return NULL;
        }
        sprintf(str, "%f", num);
        
        return str;
}


void my_concat(char num,char *str)
{
	char dummy[20];
	strcpy(dummy_concat,str);
	//my_itoa(num,dummy);
	sprintf(dummy, "%d", num);
	strcat(dummy_concat,dummy);
}

// when new scope seen - add to scope stack
void scope_start()
{
	stack[index1]=i;
	i++;
	index1++;
	return;
}

// when scope ends - mark it as '1' in END and '0' in STACK
void scope_end()
{
	index1--;
	end[stack[index1]]=1;
	stack[index1]=0;
	return;
}



void while1()
{
	label_num++;
	label[++ltop]=label_num;
	printf("\nL%d:\n",label_num);
	
	my_concat(label_num,"L");
	enter_in_quad("Label","NULL","NULL",dummy_concat);
}

void while2()
{
	label_num++;						// increment the label's suffix
	printf("iffalse %s goto L%d",st1[top],label_num);
	
	
	char dummy[20];
	strcpy(dummy,"L");
	//my_itoa(label_num,buffer);
	sprintf(buffer, "%d", label_num);
	strcat(dummy,buffer);
	enter_in_quad("iffalse",st1[top],"NULL",dummy);
	
	--top;
 	label[++ltop]=label_num;				
}

void while3()
{
	int y=label[ltop];
	--ltop;
	printf("\ngoto L%d\n",label[ltop]);

	my_concat(label[ltop],"L");
	--ltop;
	
	enter_in_quad("goto","NULL","NULL",dummy_concat);
	printf("\nL%d:\n",y);
}

// push a string into ST1 STACK
void push(char *a)
{
	strcpy(st1[++top],a);
}

void array1()
{
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("\n%s = %s\n",temp,st1[top]);		// temporary = index	
	strcpy(st1[top],temp);
	temp_count[0]++;
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("%s = %s [ %s ] \n",temp,st1[top-1],st1[top]);		
	top--;
	strcpy(st1[top],temp);
	temp_count[0]++;
}


// // generate 3AC for expressions in terms of STACK OPERATIONS
void codegen()
{
	strcpy(temp,"t");
	strcat(temp,temp_count);
	printf("\n%s = %s %s %s\n",temp,st1[top-2],st1[top-1],st1[top]);	// print the instruction in 3AC as stack operations	
	
	enter_in_quad(st1[top-1],st1[top-2],st1[top],temp);
	
	top-=2;
	strcpy(st1[top],temp);							// make the TOP element of the ST1 stack the most recent temp i.e t0 etc
	temp_count[0]++;							// increment the latest temp suffix
}



void codegen_assign()
{
	printf("\n%s = %s\n",st1[top-2],st1[top]);			// print id = value i.e assignment
	
	enter_in_quad("=",st1[top],"NULL",st1[top-2]);
	
	top-=2;							// decrement top of ST1..
}


void switch1(char *switch_var)
{
	strcpy(switch_variable,switch_var);
}

// display label AND condition for the case 
void case1(char *case_value)
{	
	if(is_break==0)
	{
		case2(case_value);
	}
	
	else{
		
		++label_num;
		printf("\n\nL%d:",label_num);
		strcpy(temp,"t");
		strcat(temp,temp_count);
		temp_count[0]++;
		printf("\n%s = %s == %s",temp,switch_variable,case_value);
		printf("\niffalse %s goto L%d",temp,label_num+1);
		
		char dummy[20];
		strcpy(dummy,"L");
		//my_itoa(label_num+1,buffer);
		
		sprintf(buffer, "%d", label_num+1);
		strcat(dummy,buffer);
		enter_in_quad("iffalse",temp,"NULL",dummy);
		
	}
		
}


void case2(char *case_value)
{	
	
	++label_num;
	printf("\n\nL%d:",label_num);
	strcpy(temp,"t");
	strcat(temp,temp_count);
	temp_count[0]++;
	printf("\n%s = %s == %s",temp,switch_variable,case_value);
	printf("\niffalse %s goto L%d",temp,label_num+2);
	
	char dummy[20];
	strcpy(dummy,"L");
	//my_itoa(label_num+2,buffer);
	sprintf(buffer, "%d", label_num+2);
	strcat(dummy,buffer);
	enter_in_quad("iffalse",temp,"NULL",dummy);
	
	printf("\nL%d:",label_num+1);
	++label_num;
}


void break1()
{
	
	if(is_default==0)
	{
		//printf("goto next%d\n",next_num);
		strcpy(prev_case_break,"goto next");
		
		//my_itoa(next_num,buffer);
		sprintf(buffer, "%d", next_num);
		
		
		char dummy[20];
		strcpy(dummy,"next");
		strcat(dummy,buffer);
		dummy_quad("goto","NULL","NULL",dummy);
		
		strcat(prev_case_break,buffer);
		
		
		
		
	}
}

void break2()
{
	if(is_default==0)
	{
		//printf("goto L%d\n",label_num+2);
		strcpy(prev_case_break,"goto L");
		//my_itoa((label_num+2),buffer);
		sprintf(buffer, "%d", label_num+2);
		
		char dummy[20];
		strcpy(dummy,"L");
		strcat(dummy,buffer);
		
		dummy_quad("goto","NULL","NULL",dummy);
		
		strcat(prev_case_break,buffer);
	}
}
	

void print_prev_break()
{
	//printf("\nIS BREAK:%d",is_break);
	//printf("PREV BREAK%s",prev_case_break);
	if(prev_case == 1)
	{
	
		if(is_default==1)
		{
			//printf("\nIN DEFAULT");
			printf("goto L%d",label_num+1);
			
			//my_itoa(label_num+1,buffer);
			sprintf(buffer, "%d", label_num+1);
			char dummy[20];
			strcpy(dummy,"L");
			strcat(dummy,buffer);
			enter_in_quad("goto","NULL","NULL",dummy);
		}
		
		else
		{	
			//printf("\nIN ELSE");
			printf("%s",prev_case_break);
			
			enter_in_quad(op_1,arg1_1,arg2_1,result_1);
		}
	}
}


void end_switch()
{
	printf("\nnext%d:\n",next_num);
	++next_num;
}


void default1()
{
	++label_num;
	printf("\n\nL%d:",label_num);
}

void loop_variant_ids(char id[10])
{
	if(is_cond_while)
	{
		strcpy(loop_variant_id[num_loop_variant_ids],id);
		//printf("loop variant identifier - %s \n", loop_variant_id[num_loop_variant_ids]);
		num_loop_variant_ids++;
		
	}
}

int check_invariant(char id[10])
{
				 
				int i =0; 
				while(i < num_loop_variant_ids) 
				{ 
					if(strcmp(id,loop_variant_id[i]) != 0)
					{
				 		//printf("\n\nINVARIANT: %d \n\n",yylineno);
						
					}
					else if(strcmp(id,loop_variant_id[i]) == 0)
						return 0;
					++i; 
					
				}
				return 1; 

				
				
				
}

void myprint(int result)
{
	if(result==1) printf("\nLOOP INVARIANT: %d",yylineno);
	
		
}



void expression_evaluation(char *a,char op,char *b)
{
	float a_val = atof(a);
	float b_val = atof(b);
	
	float res;
	
	switch(op)
	{
		case '+': res=a_val+b_val;
			break;
			
		case '-': res=a_val-b_val;
			  break;
			  
		case '*': res = a_val*b_val;
				break;
		case '/': res = a_val/b_val;
			break;
			
	}
	
	
	my_itoa(res,expr_eval_res);
	
	//printf("\nEXPR EVAL RESULT %s a %f b %f res %f",expr_eval_res,a_val,b_val,res);
	
	
}



#line 511 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    ID = 261,
    NUM = 262,
    REAL = 263,
    WHILE = 264,
    RETURN = 265,
    PREPROC = 266,
    LE = 267,
    STRING = 268,
    PRINT = 269,
    FUNCTION = 270,
    ARRAY = 271,
    FOR = 272,
    GE = 273,
    EQ = 274,
    NE = 275,
    INC = 276,
    DEC = 277,
    SWITCH = 278,
    CASE = 279,
    DEFAULT = 280,
    BREAK = 281,
    NEQ = 282,
    AND = 283,
    OR = 284
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define ID 261
#define NUM 262
#define REAL 263
#define WHILE 264
#define RETURN 265
#define PREPROC 266
#define LE 267
#define STRING 268
#define PRINT 269
#define FUNCTION 270
#define ARRAY 271
#define FOR 272
#define GE 273
#define EQ 274
#define NE 275
#define INC 276
#define DEC 277
#define SWITCH 278
#define CASE 279
#define DEFAULT 280
#define BREAK 281
#define NEQ 282
#define AND 283
#define OR 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 452 "parser.y"

		int ival;
		char *str;
	

#line 624 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

#define YYUNDEFTOK  2
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,    35,    33,    43,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    41,
      30,    32,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   459,   459,   460,   461,   462,   466,   487,   488,   489,
     492,   495,   496,   497,   497,   510,   510,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   530,   530,   534,   534,
     535,   539,   540,   543,   543,   544,   556,   556,   556,   568,
     568,   568,   568,   598,   610,   611,   622,   627,   628,   631,
     631,   631,   631,   672,   684,   711,   743,   744,   747,   747,
     750,   750,   750,   751,   751,   751,   752,   753,   753,   753,
     754,   754,   754,   755,   755,   755,   756,   756,   756,   757,
     757,   757,   758,   758,   758,   759,   759,   759,   760,   760,
     760,   761,   761,   761,   762,   764,   764,   764,   765,   765,
     765,   766,   768,   769,   795
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "ID", "NUM",
  "REAL", "WHILE", "RETURN", "PREPROC", "LE", "STRING", "PRINT",
  "FUNCTION", "ARRAY", "FOR", "GE", "EQ", "NE", "INC", "DEC", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "NEQ", "AND", "OR", "'<'", "'>'", "'='",
  "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "':'",
  "','", "'['", "']'", "$accept", "start", "Function", "Type",
  "compound_statement", "stmt", "$@1", "$@2", "switch", "$@3", "case",
  "$@4", "break", "default", "$@5", "while", "$@6", "$@7", "assignment1",
  "$@8", "$@9", "$@10", "consttype", "Declaration", "$@11", "$@12", "$@13",
  "array", "$@14", "E", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28", "$@29",
  "$@30", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "T", "$@37",
  "$@38", "$@39", "$@40", "F", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      60,    62,    61,    43,    45,    42,    47,    40,    41,   123,
     125,    59,    58,    44,    91,    93
};
# endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     190,   -63,   -63,   -63,   -63,    92,   -63,   -63,   190,     5,
     190,    15,   -10,    33,   190,   162,   162,    23,   -63,   -63,
     -63,    12,   -63,   162,   -63,    50,   -63,    49,   -63,    75,
     -63,    73,    71,   -63,    91,     0,   101,   117,   -63,   -63,
     145,     0,   -63,   -63,    65,    83,   -63,   144,   -63,   103,
       0,   127,   169,   164,   168,   172,   174,   171,   173,   175,
     176,    45,   -63,   -63,   -63,   -63,   -63,    -9,   -63,    -5,
     167,   199,   201,   177,   -63,   203,    19,   170,    19,    19,
      19,   -63,    65,     0,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,    40,    40,    40,    40,   179,   180,
     181,   -63,   182,   198,   183,   184,   206,    13,   -63,   -63,
     -63,   -63,   -63,   185,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -63,    83,    83,   -63,   -63,    19,
      19,     0,    19,   -63,   189,    19,    19,   191,   -63,   -63,
      65,    65,    65,    65,    65,    65,    65,    65,    65,   -63,
     -63,   -63,   -63,   -63,   -63,    63,   -63,    19,   187,   -63,
     -63,   -63,   -63,   -63,    19,   192,   101,   -63,   113,   -63,
      73,   -63,   193,   -63,   188,   194,   -63,   -63,   120,    19,
     196,   196,   197,   -63,   113,   -63,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    57,     7,     8,     9,    39,    47,    48,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     3,     1,
       2,    49,    53,     0,     4,    45,    43,     0,    40,     0,
      54,     0,     0,    44,     0,     0,     0,     0,    50,    56,
     103,     0,   104,    94,    41,    66,   101,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    63,    42,    95,    98,    39,    36,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,     0,
       0,    55,    51,     0,    68,    71,    74,    77,    80,    83,
      86,    89,    92,   102,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,    49,    24,    10,
      23,    12,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,    61,    64,    96,    99,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    52,    59,
      69,    72,    75,    78,    81,    84,    87,    90,    93,    62,
      65,    97,   100,    19,    20,     0,    16,     0,     0,    21,
      22,    26,    37,    14,     0,     0,     0,    18,    35,    38,
       0,    33,     0,    30,     0,     0,    27,    28,     0,     0,
      32,    32,     0,    34,    35,    31,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,     1,   -63,    61,   -35,   -62,   -63,   -63,   -63,   -63,
      29,   -63,    34,   -63,   -63,   -63,   -63,   -63,    99,   -63,
     -63,   -63,   -31,   178,   -63,   -63,   -63,   -63,   -63,   -11,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,    85,   -63,   -63,   -63,   -63,    59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    75,    76,    77,   157,   132,    78,   165,
     172,   179,   183,   173,   175,    79,   100,   166,    12,    17,
      35,    64,    13,    80,    32,    50,   113,    43,    51,    44,
      94,   149,    95,   150,    52,   115,    53,   116,    54,   117,
      55,   118,    56,   119,    57,   120,    58,   121,    59,   122,
      60,   123,    45,    96,   151,    97,   152,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    48,     6,     7,    42,    19,    40,     6,     7,    18,
      42,    20,    98,    99,   108,    24,   110,   111,   112,    42,
       1,    21,     2,     3,     4,    67,     6,     7,    68,    69,
      61,    22,   -45,    70,    15,    16,   101,    41,   102,    82,
      71,    72,    73,   -25,   -25,   -25,   124,     6,     7,    29,
      62,    63,    42,    30,    30,    28,    31,    31,    47,   -25,
      74,    11,   139,    42,    42,    42,    42,   153,   154,    11,
     156,    11,   114,   159,   160,    11,    23,    41,    62,    63,
       6,     7,   -39,    93,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    15,    34,   163,    62,    63,    62,    63,
      42,   162,   167,    38,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    36,    26,    27,   180,   181,    65,    66,
     155,     1,    33,     2,     3,     4,    67,     6,     7,    68,
      69,   169,    39,   -45,    70,    15,    16,   170,   171,   174,
      47,    71,    72,    73,    81,     1,   -25,     2,     3,     4,
      67,     6,     7,    68,    69,   127,   128,   -67,    70,    47,
     -25,    74,    49,   -70,   -73,    71,    72,    73,    25,     6,
       7,    83,   -76,   -79,   -82,   -85,   -88,   -91,    14,   125,
     126,    84,    85,    47,   -25,    74,    14,    86,    14,   -58,
      -5,     1,    14,     2,     3,     4,     5,     6,     7,    87,
      89,     8,    88,    90,   103,   104,    91,   105,    92,   107,
     109,   134,   137,   186,   106,   184,     0,     0,   131,     0,
     129,   130,   182,   133,   135,   136,   138,   158,   164,   161,
     177,   168,     0,   176,     0,     0,   178,     0,   185
};

static const yytype_int16 yycheck[] =
{
      31,    36,     7,     8,    35,     0,     6,     7,     8,     8,
      41,    10,    21,    22,    76,    14,    78,    79,    80,    50,
       1,     6,     3,     4,     5,     6,     7,     8,     9,    10,
      41,    41,    41,    14,    43,    44,    41,    37,    69,    50,
      21,    22,    23,    24,    25,    26,     6,     7,     8,    37,
      33,    34,    83,    41,    41,    32,    44,    44,    39,    40,
      41,     0,    45,    94,    95,    96,    97,   129,   130,     8,
     132,    10,    83,   135,   136,    14,    43,    37,    33,    34,
       7,     8,    32,    38,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    43,    45,   157,    33,    34,    33,    34,
     131,    38,   164,    32,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    38,    15,    16,   178,   179,    35,    36,
     131,     1,    23,     3,     4,     5,     6,     7,     8,     9,
      10,   166,    41,    41,    14,    43,    44,    24,    25,   170,
      39,    21,    22,    23,    41,     1,    26,     3,     4,     5,
       6,     7,     8,     9,    10,    96,    97,    12,    14,    39,
      40,    41,    45,    18,    19,    21,    22,    23,     6,     7,
       8,    44,    27,    28,    29,    30,    31,    32,     0,    94,
      95,    12,    18,    39,    40,    41,     8,    19,    10,    44,
       0,     1,    14,     3,     4,     5,     6,     7,     8,    27,
      29,    11,    28,    30,    37,     6,    31,     6,    32,     6,
      40,    13,     6,   184,    37,   181,    -1,    -1,    37,    -1,
      41,    41,    26,    41,    41,    41,    41,    38,    41,    38,
      42,    39,    -1,    40,    -1,    -1,    42,    -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    11,    47,
      48,    49,    64,    68,    69,    43,    44,    65,    47,     0,
      47,     6,    41,    43,    47,     6,    64,    64,    32,    37,
      41,    44,    70,    64,    45,    66,    38,    68,    32,    41,
       6,    37,    68,    73,    75,    98,   103,    39,    50,    45,
      71,    74,    80,    82,    84,    86,    88,    90,    92,    94,
      96,    75,    33,    34,    67,    35,    36,     6,     9,    10,
      14,    21,    22,    23,    41,    49,    50,    51,    54,    61,
      69,    41,    75,    44,    12,    18,    19,    27,    28,    29,
      30,    31,    32,    38,    76,    78,    99,   101,    21,    22,
      62,    41,    68,    37,     6,     6,    37,     6,    51,    40,
      51,    51,    51,    72,    75,    81,    83,    85,    87,    89,
      91,    93,    95,    97,     6,    98,    98,   103,   103,    41,
      41,    37,    53,    41,    13,    41,    41,     6,    41,    45,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    77,
      79,   100,   102,    51,    51,    75,    51,    52,    38,    51,
      51,    38,    38,    51,    41,    55,    63,    51,    39,    50,
      24,    25,    56,    59,    68,    60,    40,    42,    42,    57,
      51,    51,    26,    58,    58,    41,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    48,    49,    49,    49,
      50,    51,    51,    52,    51,    53,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    55,    54,    57,    56,
      56,    58,    58,    60,    59,    59,    62,    63,    61,    65,
      66,    67,    64,    64,    64,    64,    64,    68,    68,    70,
      71,    72,    69,    69,    69,    69,    69,    69,    74,    73,
      76,    77,    75,    78,    79,    75,    75,    80,    81,    75,
      82,    83,    75,    84,    85,    75,    86,    87,    75,    88,
      89,    75,    90,    91,    75,    92,    93,    75,    94,    95,
      75,    96,    97,    75,    75,    99,   100,    98,   101,   102,
      98,    98,   103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     1,     1,     1,
       3,     2,     2,     0,     5,     0,     4,     1,     6,     4,
       4,     4,     4,     2,     2,     0,     0,     8,     0,     7,
       1,     2,     0,     0,     5,     0,     0,     0,     7,     0,
       0,     0,     6,     3,     3,     1,     1,     1,     1,     0,
       0,     0,     8,     2,     3,     6,     5,     1,     0,     5,
       0,     0,     5,     0,     0,     5,     1,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     1,     0,     0,     5,     0,     0,
       5,     1,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 6:
#line 466 "parser.y"
                                             {
	// if return type value is not matched with type specified
	if ((yyvsp[-4].ival)!=returntype_func())
	{
		printf("\nError : Return Type mismatch : Line %d\n",printline()); errc++;
	}
	
	// check if MAIN function is named 'main'	
	if(strcmp((yyvsp[-3].str),"main")!=0)
		{printf("Error : Cannot name main function this! %s : Line %d\n",(yyvsp[-3].str),printline()); errc++;}
	
	else
	{
		insert((yyvsp[-3].str),FUNCTION);				// create entry in symbol table
		insert((yyvsp[-3].str),(yyvsp[-4].ival));
		g_addr+=4;
	}
	}
#line 1961 "y.tab.c"
    break;

  case 11:
#line 495 "parser.y"
                        {check_after_return();}
#line 1967 "y.tab.c"
    break;

  case 12:
#line 496 "parser.y"
                        {check_after_return();}
#line 1973 "y.tab.c"
    break;

  case 13:
#line 497 "parser.y"
                               {is_return = yylineno;}
#line 1979 "y.tab.c"
    break;

  case 14:
#line 497 "parser.y"
                                                            {	

						if(!(strspn((yyvsp[-3].str),"0123456789")==strlen((yyvsp[-3].str))))		// check if the return value is float or int 
							storereturn(FLOAT);				// store the function return type
						else
							storereturn(INT);
							
					// check for statements after RETURN
						if(return_deadcode_statements_count>0)
						{
							printf("\nStatements after line number %d is DEAD CODE\n",is_return);
						}	
				}
#line 1997 "y.tab.c"
    break;

  case 15:
#line 510 "parser.y"
                     {is_return = yylineno; is_void=1;}
#line 2003 "y.tab.c"
    break;

  case 16:
#line 511 "parser.y"
                                        {storereturn(VOID);
						if(return_deadcode_statements_count>0)
						{
							printf("\nStatements after line number %d is DEAD CODE\n",is_return);
						} 
					}
#line 2014 "y.tab.c"
    break;

  case 18:
#line 519 "parser.y"
                                        { is_print=1; check_after_return();}
#line 2020 "y.tab.c"
    break;

  case 19:
#line 520 "parser.y"
                         {push((yyvsp[-3].str)); loop_variant_ids((yyvsp[-3].str)); if(is_body_while) myprint(check_invariant((yyvsp[-3].str))); 	check_after_return();}
#line 2026 "y.tab.c"
    break;

  case 20:
#line 521 "parser.y"
                         {push((yyvsp[-3].str)); loop_variant_ids((yyvsp[-3].str)); if(is_body_while) myprint(check_invariant((yyvsp[-3].str)));	check_after_return();}
#line 2032 "y.tab.c"
    break;

  case 21:
#line 522 "parser.y"
                         {push((yyvsp[-2].str)); loop_variant_ids((yyvsp[-2].str)); if(is_body_while) myprint(check_invariant((yyvsp[-2].str)));	check_after_return();}
#line 2038 "y.tab.c"
    break;

  case 22:
#line 523 "parser.y"
                         {push((yyvsp[-2].str)); loop_variant_ids((yyvsp[-2].str)); if(is_body_while) myprint(check_invariant((yyvsp[-2].str)));	check_after_return();}
#line 2044 "y.tab.c"
    break;

  case 23:
#line 524 "parser.y"
                                                                                                                {check_after_return();}
#line 2050 "y.tab.c"
    break;

  case 24:
#line 525 "parser.y"
                                                                                                                {check_after_return();}
#line 2056 "y.tab.c"
    break;

  case 26:
#line 530 "parser.y"
                       {switch1((yyvsp[-1].str));}
#line 2062 "y.tab.c"
    break;

  case 27:
#line 530 "parser.y"
                                                 {end_switch(); is_break=3; is_default=0; prev_case=3;}
#line 2068 "y.tab.c"
    break;

  case 28:
#line 534 "parser.y"
                         { print_prev_break(); prev_case=1; case1((yyvsp[-1].str)); }
#line 2074 "y.tab.c"
    break;

  case 31:
#line 539 "parser.y"
                 {is_break=1; break1();}
#line 2080 "y.tab.c"
    break;

  case 32:
#line 540 "parser.y"
        {is_break=0; break2();}
#line 2086 "y.tab.c"
    break;

  case 33:
#line 543 "parser.y"
                  {is_default=1;print_prev_break(); default1();}
#line 2092 "y.tab.c"
    break;

  case 35:
#line 544 "parser.y"
          {	default1(); 
		printf("goto next%d\n",next_num); 		
		char dummy[20];
		strcpy(dummy,"next");
		my_itoa(next_num,buffer);
		strcat(dummy,buffer);
		enter_in_quad("goto","-","-",dummy);
	}
#line 2105 "y.tab.c"
    break;

  case 36:
#line 556 "parser.y"
              {while1();is_cond_while = 1;}
#line 2111 "y.tab.c"
    break;

  case 37:
#line 556 "parser.y"
                                                     {while2();is_cond_while = 0; is_body_while = 1;}
#line 2117 "y.tab.c"
    break;

  case 38:
#line 556 "parser.y"
                                                                                                                         {while3(); is_body_while = 0;}
#line 2123 "y.tab.c"
    break;

  case 39:
#line 568 "parser.y"
                 {push((yyvsp[0].str));}
#line 2129 "y.tab.c"
    break;

  case 40:
#line 568 "parser.y"
                                 {strcpy(st1[++top],"=");}
#line 2135 "y.tab.c"
    break;

  case 41:
#line 568 "parser.y"
                                                             {codegen_assign();}
#line 2141 "y.tab.c"
    break;

  case 42:
#line 569 "parser.y"
        {
		
		int sct=returnscope((yyvsp[-5].str),stack[index1-1]);
		int type=returntype((yyvsp[-5].str),sct);
		if((!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && type==258 && fl==0 && strlen((yyvsp[-1].str))==1)
			printf("\nError: Type Mismatch : Line %d\n",printline());
		
		if(!lookup((yyvsp[-5].str)))
		{
			int currscope=stack[index1-1];
			int scope=returnscope((yyvsp[-5].str),currscope);
			if((scope<=currscope && end[scope]==0) && !(scope==0))
			{
				check_scope_update((yyvsp[-5].str),(yyvsp[-1].str),currscope);
			}
		}
		
		if(is_body_while == 1)
	
		{
			
			int check = check_invariant((yyvsp[-5].str)); 
			if(check && id_indicator) printf("\nLOOP INVARIANT: %d", yylineno);
			id_indicator = 1;
				
		
		} 
	}
#line 2174 "y.tab.c"
    break;

  case 43:
#line 599 "parser.y"
        {
			if(is_body_while) 
			{
				push((yyvsp[-2].str));
				myprint(check_invariant((yyvsp[-2].str)));
				id_indicator = 1;
			}

			if(lookup((yyvsp[-2].str)))
				printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());
	}
#line 2190 "y.tab.c"
    break;

  case 45:
#line 612 "parser.y"
        {
		if(is_body_while) 
			{
				push((yyvsp[0].str));
				myprint(check_invariant((yyvsp[0].str)));
			}
		if(lookup((yyvsp[0].str)))
			printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
	}
#line 2204 "y.tab.c"
    break;

  case 49:
#line 631 "parser.y"
                      {push((yyvsp[0].str));}
#line 2210 "y.tab.c"
    break;

  case 50:
#line 631 "parser.y"
                                      {strcpy(st1[++top],"=");}
#line 2216 "y.tab.c"
    break;

  case 51:
#line 631 "parser.y"
                                                                  {codegen_assign();}
#line 2222 "y.tab.c"
    break;

  case 52:
#line 632 "parser.y"
        {
		if( (!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) && (yyvsp[-7].ival)==258 && (fl==0) && strlen((yyvsp[-2].str))==1)
		{
			printf("\nError : Type Mismatch : Line %d\n",printline());
			//fl=1;
		}
		if(!lookup((yyvsp[-6].str)))
		{
			int currscope=stack[index1-1];
			int previous_scope=returnscope((yyvsp[-6].str),currscope);
			if(currscope==previous_scope)
				printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-6].str),printline());
			else
			{
				insert_dup((yyvsp[-6].str),(yyvsp[-7].ival),currscope);
				check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
				int sg=returnscope((yyvsp[-6].str),stack[index1-1]);
				g_addr+=4;
			}
		}
		else
		{
			int scope=stack[index1-1];
			insert((yyvsp[-6].str),(yyvsp[-7].ival));
			insertscope((yyvsp[-6].str),scope);
			check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
			g_addr+=4;
		}
		if(is_body_while == 1)
	
		{
			
			int check = check_invariant((yyvsp[-6].str)); 
			if(check && id_indicator) printf("\nLOOP INVARIANT: %d", yylineno);
			id_indicator = 1;
				
		
		} 
	}
#line 2266 "y.tab.c"
    break;

  case 53:
#line 672 "parser.y"
                           {
				if(!lookup((yyvsp[-1].str)))
				{
					int currscope=stack[index1-1];
					int scope=returnscope((yyvsp[-1].str),currscope);
					if(!(scope<=currscope && end[scope]==0) || scope==0)
						printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline());
				}
#line 2282 "y.tab.c"
    break;

  case 54:
#line 685 "parser.y"
        {
        	if(!lookup((yyvsp[-1].str)))		// if identifier is in in symbol table
		{
			int currscope=stack[index1-1];
			int previous_scope=returnscope((yyvsp[-1].str),currscope);
			if(currscope==previous_scope)				// check if redeclaration of identifier
				{printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-1].str),printline());errc++;}
			else							// if no redeclaration..create entry according to scope
			{
				insert_dup((yyvsp[-1].str),(yyvsp[-2].ival),currscope);
			
			}
			

		}
		else		// if identifier is NOT in symbol table
		{
			int scope=stack[index1-1];
			
			insert((yyvsp[-1].str),(yyvsp[-2].ival));				// create entry - incl scope
			insertscope((yyvsp[-1].str),scope);
			
		}
		if(is_body_while) myprint(check_invariant((yyvsp[-1].str)));
	}
#line 2312 "y.tab.c"
    break;

  case 55:
#line 711 "parser.y"
                                        {
			int itype;
			if(!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) { itype=259; } else itype = 258;
			if(itype!=258)
			{ printf("\nError : Array index must be of type int : Line %d\n",printline());errc++;}
			if(atoi((yyvsp[-2].str))<=0)
			{ printf("\nError : Array index must be of type int > 0 : Line %d\n",printline());errc++;}
			if(!lookup((yyvsp[-4].str)))
			{
				int currscope=stack[top-1];
				int previous_scope=returnscope((yyvsp[-4].str),currscope);
				if(currscope==previous_scope)
				{printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-4].str),printline());errc++;}
				else
				{
					insert_dup((yyvsp[-4].str),ARRAY,currscope);
					insert_by_scope((yyvsp[-4].str),(yyvsp[-5].ival),currscope);	//to insert type to the correct identifier in case of multiple entries of the identifier by using scope
					if (itype==258) {insert_index((yyvsp[-4].str),(yyvsp[-2].str));}
					update_array_size((yyvsp[-4].str),currscope,atoi((yyvsp[-2].str)));
				}
			}
			else
			{
				int scope=stack[top-1];
				insert((yyvsp[-4].str),ARRAY);
				insert((yyvsp[-4].str),(yyvsp[-5].ival));
				insertscope((yyvsp[-4].str),scope);
				if (itype==258) {insert_index((yyvsp[-4].str),(yyvsp[-2].str));}
				update_array_size((yyvsp[-4].str),scope,atoi((yyvsp[-2].str)));
			}
		}
#line 2348 "y.tab.c"
    break;

  case 58:
#line 747 "parser.y"
           {push((yyvsp[0].str));}
#line 2354 "y.tab.c"
    break;

  case 60:
#line 750 "parser.y"
         {strcpy(st1[++top],"+");}
#line 2360 "y.tab.c"
    break;

  case 61:
#line 750 "parser.y"
                                    {codegen();}
#line 2366 "y.tab.c"
    break;

  case 62:
#line 750 "parser.y"
                                                                        {expression_evaluation((yyvsp[-4].str),'+',(yyvsp[-1].str)); strcpy((yyval.str),expr_eval_res);}
#line 2372 "y.tab.c"
    break;

  case 63:
#line 751 "parser.y"
          {strcpy(st1[++top],"-");}
#line 2378 "y.tab.c"
    break;

  case 64:
#line 751 "parser.y"
                                     {codegen();}
#line 2384 "y.tab.c"
    break;

  case 65:
#line 751 "parser.y"
                                                                        {expression_evaluation((yyvsp[-4].str),'-',(yyvsp[-1].str)); strcpy((yyval.str),expr_eval_res);}
#line 2390 "y.tab.c"
    break;

  case 67:
#line 753 "parser.y"
        {push((yyvsp[0].str));loop_variant_ids(st1[top]);if(is_body_while) myprint(check_invariant((yyvsp[0].str)));}
#line 2396 "y.tab.c"
    break;

  case 68:
#line 753 "parser.y"
                                                                                                 {strcpy(st1[++top],"<=");}
#line 2402 "y.tab.c"
    break;

  case 69:
#line 753 "parser.y"
                                                                                                                              {codegen();}
#line 2408 "y.tab.c"
    break;

  case 70:
#line 754 "parser.y"
        {push((yyvsp[0].str));loop_variant_ids(st1[top]);if(is_body_while) myprint(check_invariant((yyvsp[0].str)));}
#line 2414 "y.tab.c"
    break;

  case 71:
#line 754 "parser.y"
                                                                                                 {strcpy(st1[++top],">=");}
#line 2420 "y.tab.c"
    break;

  case 72:
#line 754 "parser.y"
                                                                                                                              {codegen();}
#line 2426 "y.tab.c"
    break;

  case 73:
#line 755 "parser.y"
        {push((yyvsp[0].str));loop_variant_ids(st1[top]);if(is_body_while) myprint(check_invariant((yyvsp[0].str)));}
#line 2432 "y.tab.c"
    break;

  case 74:
#line 755 "parser.y"
                                                                                                 {strcpy(st1[++top],"==");}
#line 2438 "y.tab.c"
    break;

  case 75:
#line 755 "parser.y"
                                                                                                                              {codegen();}
#line 2444 "y.tab.c"
    break;

  case 76:
#line 756 "parser.y"
        {push((yyvsp[0].str));loop_variant_ids(st1[top]);if(is_body_while) myprint(check_invariant((yyvsp[0].str)));}
#line 2450 "y.tab.c"
    break;

  case 77:
#line 756 "parser.y"
                                                                                                  {strcpy(st1[++top],"!=");}
#line 2456 "y.tab.c"
    break;

  case 78:
#line 756 "parser.y"
                                                                                                                               {codegen();}
#line 2462 "y.tab.c"
    break;

  case 79:
#line 757 "parser.y"
        {push((yyvsp[0].str));loop_variant_ids(st1[top]);if(is_body_while) myprint(check_invariant((yyvsp[0].str)));}
#line 2468 "y.tab.c"
    break;

  case 80:
#line 757 "parser.y"
                                                                                                  {strcpy(st1[++top],"&&");}
#line 2474 "y.tab.c"
    break;

  case 81:
#line 757 "parser.y"
                                                                                                                               {codegen();}
#line 2480 "y.tab.c"
    break;

  case 82:
#line 758 "parser.y"
        {push((yyvsp[0].str));loop_variant_ids(st1[top]);if(is_body_while) myprint(check_invariant((yyvsp[0].str)));}
#line 2486 "y.tab.c"
    break;

  case 83:
#line 758 "parser.y"
                                                                                                 {strcpy(st1[++top],"||");}
#line 2492 "y.tab.c"
    break;

  case 84:
#line 758 "parser.y"
                                                                                                                              {codegen();}
#line 2498 "y.tab.c"
    break;

  case 85:
#line 759 "parser.y"
        {push((yyvsp[0].str));loop_variant_ids(st1[top]);if(is_body_while) myprint(check_invariant((yyvsp[0].str)));}
#line 2504 "y.tab.c"
    break;

  case 86:
#line 759 "parser.y"
                                                                                                  {strcpy(st1[++top],"<");}
#line 2510 "y.tab.c"
    break;

  case 87:
#line 759 "parser.y"
                                                                                                                              {codegen();}
#line 2516 "y.tab.c"
    break;

  case 88:
#line 760 "parser.y"
        {push((yyvsp[0].str));loop_variant_ids(st1[top]);if(is_body_while) myprint(check_invariant((yyvsp[0].str)));}
#line 2522 "y.tab.c"
    break;

  case 89:
#line 760 "parser.y"
                                                                                                  {strcpy(st1[++top],">");}
#line 2528 "y.tab.c"
    break;

  case 90:
#line 760 "parser.y"
                                                                                                                              {codegen();}
#line 2534 "y.tab.c"
    break;

  case 91:
#line 761 "parser.y"
        {push((yyvsp[0].str));}
#line 2540 "y.tab.c"
    break;

  case 92:
#line 761 "parser.y"
                        {strcpy(st1[++top],"=");}
#line 2546 "y.tab.c"
    break;

  case 93:
#line 761 "parser.y"
                                                    {codegen_assign();}
#line 2552 "y.tab.c"
    break;

  case 94:
#line 762 "parser.y"
           {array1();fl=1; is_array=1;}
#line 2558 "y.tab.c"
    break;

  case 95:
#line 764 "parser.y"
         {strcpy(st1[++top],"*");}
#line 2564 "y.tab.c"
    break;

  case 96:
#line 764 "parser.y"
                                    {codegen();}
#line 2570 "y.tab.c"
    break;

  case 97:
#line 764 "parser.y"
                                                                        {expression_evaluation((yyvsp[-4].str),'*',(yyvsp[-1].str)); strcpy((yyval.str),expr_eval_res);}
#line 2576 "y.tab.c"
    break;

  case 98:
#line 765 "parser.y"
          {strcpy(st1[++top],"/");}
#line 2582 "y.tab.c"
    break;

  case 99:
#line 765 "parser.y"
                                     {codegen();}
#line 2588 "y.tab.c"
    break;

  case 100:
#line 765 "parser.y"
                                                                        {expression_evaluation((yyvsp[-4].str),'/',(yyvsp[-1].str)); strcpy((yyval.str),expr_eval_res);}
#line 2594 "y.tab.c"
    break;

  case 102:
#line 768 "parser.y"
              {(yyval.str)=(yyvsp[-1].str);}
#line 2600 "y.tab.c"
    break;

  case 103:
#line 769 "parser.y"
        { 
   
   			// for original 3AC code START COMMENT HERE
   		int currscope=stack[index1-1];
   		char id_value[10];
   		
   		int ret_type = returntype((yyvsp[0].str),currscope);
   		
   		float id_res = find_identifier_value((yyvsp[0].str),currscope);
   		
   		if(ret_type==258)
   		{
   			int id_res_1 = (int)id_res;
   			sprintf((yyvsp[0].str), "%d", id_res_1);
   			
   		}
   		
   		else
   		{
   			sprintf((yyvsp[0].str),"%f",id_res);
   		}		// end comment here

   		push((yyvsp[0].str));fl=1;if(is_cond_while) {loop_variant_ids((yyvsp[0].str));} if(is_body_while) {if(!check_invariant((yyvsp[0].str))) id_indicator = 0;}
   		 
   		
   		}
#line 2631 "y.tab.c"
    break;

  case 104:
#line 795 "parser.y"
               { push((yyvsp[0].str)); (yyval.str)=(yyvsp[0].str); fl=0;}
#line 2637 "y.tab.c"
    break;


#line 2641 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 798 "parser.y"


#include "lex.yy.c"
#include<ctype.h>


int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	yyparse();
	if(!yyparse())
	{
		printf("Parsing done\n");
		
		
		/*if(is_print==0 && is_void==1)
		{
			printf("\nThe entire program is dead code!\n");
		}*/
		
		display();
		display_quad();
	}
	else
	{
		printf("Error\n");
	}
	fclose(yyin);
	return 0;
}

void yyerror(char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}
int printline()
{
	return yylineno;
}

