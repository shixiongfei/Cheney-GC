/******************************************************************************
 * FILE:    main.c                                                            *
 * AUTHOR:  Ryan Rozanski                                                     *
 * CREATED: 10/31/17                                                          *
 * EDITED:  10/31/17                                                          *
 * INFO:    ...                                                               *   
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *                                                                            *
 *   I N C L U D E S                                                          *
 *                                                                            *
 ******************************************************************************/
#include <cheney.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

/******************************************************************************
 *                                                                            *
 *   G L O B A L S                                                            *
 *                                                                            *
 ******************************************************************************/
void *root; // define root for the garbage collector

/******************************************************************************
 *                                                                            *
 *   F U N C T I O N S                                                        *
 *                                                                            *
 ******************************************************************************/
int main(int argc, char *argv[]) {
  fprintf(stdout, "Interactive Cheney Garbage Collector\nv1.0\nRyan Rozanski\n\n");

  srand(time(NULL)); // seed random

  // FIXME: the fun part -> visual garbage collection (old test stuff)

  exit(EXIT_SUCCESS);
}


/******************************************************************************
 * FILE:    trees.c                                                           *
 * AUTHOR:  Ryan Rozanski                                                     *
 * CREATED: 1/15/17                                                           *
 * EDITED:  10/31/17                                                          *
 * INFO:    A library to randomly build arbitrary binary trees using cons     *
 *          cells, along with several different ways of walking over the      *
 *          given generated tree(s). The generator as well as all tree        *
 *          traversals are also capable of handling cycles.                   *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *                                                                            *
 *   I N C L U D E S                                                          *
 *                                                                            *
 ******************************************************************************/
//#include <stdio.h>
//#include <stdlib.h>
//#include <cheney.h>
//#include <math.h>

/******************************************************************************
 *                                                                            *
 *   F U N C T I O N S                                                        *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *                                                                            *
 * PURPOSE: To set a specific bit in an arbitrary pointer.                    *
 *                                                                            *
 * ARGUMENT DESCRIPTION                                                       *
 * -------- -----------                                                       *
 * ptr      the pointer to modify                                             *
 * bit      the specific bit to set                                           *
 *                                                                            *
 * RETURNS: N/A                                                               *
 *                                                                            *
 ******************************************************************************/
//void setBit(void **ptr, int bit) { *(int *)ptr |= 1 << bit; }

/******************************************************************************
 *                                                                            *
 * PURPOSE: To clear a specific bit in an arbitrary pointer.                  *
 *                                                                            *
 * ARGUMENT DESCRIPTION                                                       *
 * -------- -----------                                                       *
 * ptr      the pointer to modify                                             *
 * bit      the specific bit to clear                                         *
 *                                                                            *
 * RETURNS: N/A                                                               *
 *                                                                            *
 ******************************************************************************/
//void clrBit(void **ptr, int bit) { *(int *)ptr &= ~(1 << bit); }

/******************************************************************************
 *                                                                            *
 * PURPOSE: To flip a specific bit in an arbitrary pointer.                   *
 *                                                                            *
 * ARGUMENT DESCRIPTION                                                       *
 * -------- -----------                                                       *
 * ptr      the pointer to modify                                             *
 * bit      the specific bit to flip                                          *
 *                                                                            *
 * RETURNS: N/A                                                               *
 *                                                                            *
 ******************************************************************************/
//void flpBit(void **ptr, int bit) { *(int *)ptr ^= 1 << bit; }

/******************************************************************************
 *                                                                            *
 * PURPOSE: To determine if a specific bit is set in an arbitrary pointer.    *
 *                                                                            *
 * ARGUMENT DESCRIPTION                                                       *
 * -------- -----------                                                       *
 * ptr      the pointer to modify                                             *
 * bit      the specific bit in question                                      *
 *                                                                            *
 * RETURNS: 1 if the specified bit is set, 0 otherwise.                       *
 *                                                                            *
 ******************************************************************************/
//int  getBit(void **ptr, int bit) { return (*(int *)ptr & 1 << bit) ? 1 : 0; }

/******************************************************************************
 *                                                                            *
 * PURPOSE: To display an integer in its binary representation.               *
 *                                                                            *
 * ARGUMENT DESCRIPTION                                                       *
 * -------- -----------                                                       *
 * n        the integer to display in binary                                  *
 *                                                                            *
 * RETURNS: N/A                                                               *
 *                                                                            *
 ******************************************************************************/
//void printBin(unsigned int n) {
//  int i;
//  for(i = (sizeof(int) * 8) - 1; i >= 0; i--) {
//    (n & 1 << i) ? putchar('1') : putchar('0'); 
//  }
//  printf("\n");
//}

/******************************************************************************
 *                                                                            *
 * PURPOSE: To randomly build an arbitrary binary tree using cons cells.      *
 *                                                                            *
 * ARGUMENT DESCRIPTION                                                       *
 * -------- -----------                                                       *
 * root     the address of the location at which to store the resulting tree  *
 * cells    how many cons cells to be used in building this tree              *
 * cycles   if we should include cycles or not when building the tree (1/0)   *
 *                                                                            *
 * RETURNS: N/A                                                               *
 *                                                                            *
 ******************************************************************************/
//void build_tr(void **r, int cells, int cycles) {
//  int size_stk[(int)ceil(log(cells + 1) / log(2))+1];
//  void **tr_stk[(int)ceil(log(cells + 1) / log(2))+1];
//  cell_t *ancestor = NULL;
//  int stk_ptr, leaf, *i;
//
//  for(leaf = stk_ptr = 0; r != tr_stk[0];) {
//    if(!cells) { 
//      if(cycles && rand() % 2 && ancestor) {
//        *r = ancestor;
//      } else {
//        *(i = malloc(sizeof(int))) = leaf++;
//        setBit((void **)&i, 0);
//        *r = i;
//      }
//      cells = size_stk[stk_ptr];
//      r = tr_stk[stk_ptr--];
//    } else {
//      *r = cons(NULL, NULL);
//      cells--;
//      if(rand() % 2 || !ancestor) { ancestor = *r; }
//      size_stk[++stk_ptr] = cells / 2;
//      cells -= cells / 2;
//      tr_stk[stk_ptr] = &(((cell_t *)(*r))->cdr);
//      r = &(((cell_t *)(*r))->car);
//    }
//  }
//}
//
//typedef struct hash_t {
//  //unsigned long size; // problem with comparison >= 0 in hash_free
//  long size;
//  cell_t **tbl;
//} hash_t;
//
//hash_t *hash(unsigned long size) {
//  hash_t *hash = malloc(sizeof(hash_t));
//  hash->size = size;
//  hash->tbl = calloc(size, sizeof(cell_t *));
//  return hash;
//}
//
//void hash_insert(hash_t *h, cell_t *cell, int cell_pos) {
//  int loc = (*(unsigned int *)cell * 53) % h->size;
//  cell_t *bucket = *(h->tbl + loc);
//  for(; bucket; bucket = cdr(bucket)) {
//    if(car(car(bucket)) == cell) { return; } // already exists
//  }
//  cell_t *elem = malloc(sizeof(cell_t));
//  set_car(elem, cell);
//  int *i = malloc(sizeof(int));
//  *i = cell_pos;
//  set_cdr(elem, i);
//  cell_t *link = malloc(sizeof(cell_t));
//  set_car(link, elem);
//  set_cdr(link, *(h->tbl + loc));
//  *(h->tbl + loc) = link;
//}
//
//int hash_ref(hash_t *h, cell_t *cell) {
//  int loc = (*(unsigned int *)cell * 53) % h->size; // int was giving negatives sometimes
//  cell_t *bucket = *(h->tbl + loc);
//  for(; bucket && car(car(bucket)) != cell; bucket = cdr(bucket));
//  if(!bucket) { return 0; } // not found
//  return *(int *)cdr(car(bucket));
//}
//
//void hash_free(hash_t *h) {
//  cell_t *buckets, *bucket, *link;
//  for(h->size -= 1, buckets = *(h->tbl + h->size); h->size >= 0; h->size -= 1) {
//    for(; buckets;) {
//      bucket = car(buckets);
//      link = buckets;
//      buckets = cdr(buckets);
//      free(link);
//      free(cdr(bucket));
//      free(bucket);
//    }
//  }
//  free(h->tbl);
//  free(h);
//}

/******************************************************************************
 *                                                                            *
 * PURPOSE: To ensure the tree, possibly cyclical, is intact by walking it    *
 *          all (following all the pointers).                                 *
 *                                                                            *
 * ARGUMENT DESCRIPTION                                                       *
 * -------- -----------                                                       *
 * tr        the tree to traverse                                             *
 * cells     the number of cells used to construct the tree                   *
 *                                                                            *
 * RETURNS: N/A                                                               *
 *                                                                            *
 ******************************************************************************/
//void traverse_tr_intact(void *tr, int cells) { 
//  hash_t *seen = hash(1000);
//  void *stk[(int)ceil(log(cells + 1) / log(2)) + 1];
//
//  for(cells = 0; tr != stk[0];) { // cells as stk_ptr
//    if(isAtomic(&tr) || hash_ref(seen, tr)) {
//      tr = stk[cells--];
//    } else if(isPtr(&tr)) {
//      hash_insert(seen, tr, 1);
//      stk[++cells] = cdr(tr);
//      tr = car(tr);
//    } else {
//      fprintf(stderr, "error: unrecognized type in generated tree\n");
//      exit(EXIT_FAILURE);
//    }
//  }
//  hash_free(seen);
//}

/******************************************************************************
 *                                                                            *
 * PURPOSE: To print a graphical representation of a binary tree's memory     *
 *          footprint.                                                        *
 *                                                                            *
 * ARGUMENT DESCRIPTION                                                       *
 * -------- -----------                                                       *
 * tr        the tree to traverse                                             *
 * cells     the number of cells used to construct the tree                   *
 *                                                                            *
 * RETURNS: N/A                                                               *
 *                                                                            *
 ******************************************************************************/
//void traverse_tr_addrs(void *tr, int cells) { 
//  int loc, stk_ptr;
//  hash_t *seen = hash(1000);
//  void *stk[(int)ceil(log(cells + 1) / log(2)) + 1];
//
//  for(cells = 1, stk_ptr = loc = 0; tr != stk[0];) {
//    if(isAtomic(&tr) || (loc = hash_ref(seen, tr))) {
//      if(!loc) { clrBit(&tr, 0); }
//      loc ? printf("\t\tleaf #cycle %d#: %p\n", loc, tr) : printf("\t\tleaf %d: %p\n", *(int *)tr, tr);
//      tr = stk[stk_ptr--];
//    } else if(isPtr(&tr)) {
//      printf("cell: %p\n", tr);
//      hash_insert(seen, tr, cells++);
//      stk[++stk_ptr] = cdr(tr);
//      tr = car(tr);
//    } else {
//      fprintf(stderr, "error: unrecognized type in generated tree\n");
//      exit(EXIT_FAILURE);
//    }
//  }
//  printf("\n");
//  hash_free(seen);
//}

/******************************************************************************
 *                                                                            *
 * PURPOSE: To print a graphical representation of a binary tree, possibly    *
 *          cyclic in nature.                                                 *
 *                                                                            *
 * ARGUMENT DESCRIPTION                                                       *
 * -------- -----------                                                       *
 * tr        the tree to traverse                                             *
 * cells     the number of cells used to construct the tree                   *
 *                                                                            *
 * RETURNS: N/A                                                               *
 *                                                                            *
 ******************************************************************************/
//void traverse_tr(void *tr, int cells) {
//  int loc, stk_ptr;
//  hash_t *seen = hash(1000);
//  cells = (int)ceil(log(cells + 1) / log(2)) + 1;
//  void *stk[cells];
//  int parens[cells];
//  for(cells--; cells >= 0; cells--) { parens[cells] = 0; }
//
//  for(cells = 1, stk_ptr = loc = 0; tr != stk[0];) {
//    if(isAtomic(&tr) || (loc = hash_ref(seen, tr))) {
//      if(!loc) { clrBit(&tr, 0); }
//      loc ? printf("#cycle: %d#", loc) : printf("%d", *(int *)tr); 
//      for(; parens[stk_ptr]; parens[stk_ptr]--) { printf(")"); }
//      if(stk_ptr) { printf(" . "); }
//      tr = stk[stk_ptr--];
//    } else if(isPtr(&tr)) {
//      printf("(");
//      hash_insert(seen, tr, cells++);
//      parens[stk_ptr]++;
//      stk[++stk_ptr] = cdr(tr);
//      tr = car(tr);
//    } else {
//      fprintf(stderr, "error: unrecognized type in generated tree\n");
//      exit(EXIT_FAILURE);
//    }
//  }
//  for(; parens[0]; parens[0]--) { printf(")"); }
//  printf("\n");
//  hash_free(seen);
//}