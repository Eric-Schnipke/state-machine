#include "stdafx.h"
#include <stdio.h>
//#include <string.h>

typedef unsigned char ubyte;
typedef unsigned char boolean;
typedef unsigned int uword;
typedef signed int sword;
typedef signed long    slong;    // 4 byte signed;   prefix: sl
typedef   long    _iq19;
#define FALSE (0)
#define TRUE  (!FALSE)

static void state_init(void)
{
	/* do stuff here */
	printf("This is the init state.");
}

static void state_a(void)
{
	/* do stuff here */
	printf("This is state a.");
}

static void state_b(void)
{
	/* do stuff here */
	printf("This is state b.");
}

static void state_c(void)
{
	/* do stuff here */
	printf("This is state c.");
}

static void run_state_machine()
{
	static void(*fpState)(void) = state_init;

	/*
	* Execute current state
	*/
	fpState();

	/*
	* Find next state
	*/
	fpState =
	   /* ============================================================================================================= *
		* ( ORIGIN STATE          )    ( TRANSITION LOGIC                                     )   ( DESTINATION STATE ) *
		* ============================================================================================================= */
		  ( fpState == state_init ) && ( TRUE  /* insert state-specific trans logic here   */ ) ? ( state_a           )
	   /* ------------------------------------------------------------------------------------------------------------- */
		: ( fpState == state_a    ) && ( FALSE /* insert state-specific trans logic here   */ ) ? ( state_b           )
	   /* ------------------------------------------------------------------------------------------------------------- */
		: ( fpState == state_a    ) && (  (  TRUE  )
			                           && ( !FALSE )  /* example of multi-line conditional */
			                           )                                                        ? ( state_c           )
	   /* ------------------------------------------------------------------------------------------------------------- */
		: ( fpState == state_b    ) && ( TRUE  /* insert state-specific trans logic here   */ ) ? ( state_c           )
	   /* ------------------------------------------------------------------------------------------------------------- */
		: ( fpState == state_c    ) && ( TRUE  /* insert state-specific trans logic here   */ ) ? ( state_a           )
	   /* ------------------------------------------------------------------------------------------------------------- */
		: /* else */ fpState;
}

void main(void)
{
	while (1)
	{
		run_state_machine();
		getchar(); /* pause execution on each cycle of state machine */
	}
}
