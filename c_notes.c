//////////////////////////////////////////////////////////////////////////////
Data Types
char : 1 byte : -128 to 127 or 0 to 255
unsigned char : 1 byte : 0 to 255
signed char...
int : 2/4 bytes : ...
unsigned int : ...
short : 2 bytes : ...
long : 4 bytes : ...
sizeof(type) : returns storage size in bytes
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Printf formatting
%d: signed int
%u: unsigned int
%o: octal
%x: hexadecimal
%f: floating point (%f4.2 = number of chars to output)
%e: floating point exponent form
%c: character
%s: string
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
GCC options
-E: preprocessing only
-S: assembly only
-c: compilation only
-D<DEFNAME>: passes definition to preprocessor
-o: define output name (instead of a.out)
-Wall: display all warnings
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Preprocessor functions
#include <>: system header files
#include "": user header files (-I to add path)
#define A_NAME 18: replaces A_NAME with 18
#ifdef A_NAME
#else
#endif: checks if A_NAME has been defined
#ifndef
#else
#endif: check if A_NAME has not been defined
e.g
#define DEBUG
#ifdef DEBUG
//code
#endif: inclusion of debugging only code
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Macro Definitions
+faster
+generic (accept any type)
-not type checked
-ALWAYS USE BRACKETS AS MUCH AS POSSIBLE
#define MAX(x,y) ((x)>(y)?(x):(y))
i = MAX(j+k, m-n);
#define IS_EVEN(n) ((n)%2==0)
if (IS_EVEN(i)) i++;
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
True/False
0: false
1: true
Comparisons return 0/1
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Loops
while: tested before loop
do..while: tested after loop
for (expr1;expr2;expr3)
===
expr1;
while(expr2)
    expr3;
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Enumerations
variables that have small num of possible values
enum {CLUBS, DIAMONDS, HEARTS, SPADES} s1, s2;
conforms to scope unlike #define
by default assigns values 0..n to constants
can specify
enum suit {CLUBS = 1, DIAMONDS = 2,...};
Can even have same value/no order
enum EGA_colours {BLACK, LT_GRAY=7, DK_GRAY,WHITE=15};
BLACK=0, LT_GRAY=7,DK_GRAY=8,WHITE=15
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Structures
struct point {
    int x;
    int y;
}; (members are x,y)
struct point a_point;
struct point a_point = {5,6};
a_point.x = 4;
a_point.y = 3;
Dot operator takes precedence over pretty much everything
Any names defined wont conflict, (separate namespace for members)
Can copy point1 to point2 using =
typedef struct points {
    int x;
    int y;
} point;
point p1 = {5, 4};
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Unions
compiler allocates enough space for only largest of members
assigning value to one overwrites/corrupts data of others
Only first member can have an initial value
union {
    int i;
    double d;
} u = {0};
Unless using designated initializer
union {
    int i;
    double d;
} u = {.d = 10.0};
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Pointers
int *p; //Pointer variable
p = &i; //p stores memory address of integer i
int *p = &i; //Equiv
*p = 7; //i = 7
*p = *p + 1; //i = i + 1
q = p; //q now also points to i and *q can change it
&: address of
*: value of
Applying *var to uninitialized pointer is a VERY BAD IDEA
int a[10];
int *pa;
//Following pairs of statements are equal
pa = &a[0];
pa = a;
pa = a[1];
pa = *(a+1);
a[-4];
*(a+4);
Safety:
assert(pointer != NULL)// #include <assert.h>
once done: pointer = NULL

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Arrays/Strings
int a[10]; //fixed array holding 10 ints
char a[] = "Hello worlds";
char b[13]; //12+1 for /0
b =a; //Set pointer b to address a
Array to array assignment not supported
strcpy(dest, source); //#include <string.h>
char a[] = "hello";
strlen(a): 5
sizeof(a): 6
Use of a on its own = memory address of start of string
Can also do char *a = "hello";
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Dynamic memory management
Malloc
void *malloc(size_t size);
Allocates contigous block of memory size bytes long
Return type is generic pointer void*
Returns NULL pointer if if cant allocate requested memory (TEST)
char *line = (char *)malloc(size);
Free
void free(void *ptr);
returns memory for re-use
forgetting to free() gives memory leak
Calloc
void *calloc(size_t n, size_t size);
Allocates block of memory of n elements size bytes long initialised to 0
Ensures old data is not used inappropriately
Realloc
void *realloc(void *ptr, size_t size);
Allows dynamic change in size of block of memory pointed to by ptr
ptr must point to a block previously allocated
can move/copy contents if necessary
Still returns NULL pointer on failure
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Conversions
String -> int: atoi() (also atol() and atof())
int -> String: sprintf(char *s, char *format, <value list>)
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Selection operator: ->
Used to access struct/union members on a pointer
Usually when malloc has been used
ptr -> color = 1;
(*ptr).color = 1;//Are equiv
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
Scope
static foo(): accessible only by code in file
Lifetime
static int i; //life of program
int i; //automatic/end of current block
i = (int*)malloc(400); //dynamic (our control)
Scope vs Visibility
Scope: largest program region which a name can be used without qualification to entity
Visibility: region of program which object associated w/ identifier can be accessed
