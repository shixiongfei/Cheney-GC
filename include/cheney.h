/**********************************************************************

    F I L E   I N F O R M A T I O N

***********************************************************************/
/*
 Author:  Ryan Rozanski
 Created: 1/14/17
 Edited:  1/29/17
*/

#ifndef CHENEY_GC_STRUCT_DEFS
#define CHENEY_GC_STRUCT_DEFS

/**********************************************************************

      D A T A   S T R U C T U R E

***********************************************************************/
typedef struct cell {
  void *car, *cdr; 
} cell_t;

/**********************************************************************

    G L O B A L S

***********************************************************************/
extern void *root;

/**********************************************************************

    F U N C T I O N   P R O T O T Y P E S

***********************************************************************/
int isAtomic(void **p);
int isPtr(void **p);
cell_t *cons(void *car, void *cdr);
void *car(cell_t *cell);
void *cdr(cell_t *cell);
void set_car(cell_t *cell, void *v);
void set_cdr(cell_t *cell, void *v);
void hinit(unsigned long cells);
cell_t *halloc();
void collect();

#endif