/**********************************************************************

    F I L E   I N F O R M A T I O N

***********************************************************************/
/*
 Author:  Ryan Rozanski
 Created: 1/15/17
 Edited:  1/31/17
*/

#ifndef TREES_STRUCT_DEFS
#define TREES_STRUCT_DEFS

/**********************************************************************

    E N U M E R A T I O N S

***********************************************************************/
typedef enum { REG, ADDRS, INTACT_CHECK } traversal_t;

/**********************************************************************

    F U N C T I O N   P R O T O T Y P E S

***********************************************************************/
void build_tr(void **root, int cells, int cycles);
void traverse_tr(void *tr, traversal_t walk);

#endif