/**********************************************************************

    F I L E   I N F O R M A T I O N

***********************************************************************/
/*
 Author:  Ryan Rozanski
 Created: 1/15/17
 Edited:  2/19/17
*/

/**********************************************************************

      I N C L U D E S

***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cheney.h>
#include <trees.h>
#include <bits.h>
#include <math.h>

/**********************************************************************

      F U N C T I O N S

***********************************************************************/
void build_tr(void **r, int cells, int cycles) {
  int size_stk[(int)ceil(log(cells + 1) / log(2))];
  void **tr_stk[(int)ceil(log(cells + 1) / log(2))];
  cell_t *ancestor = NULL;
  int stk_ptr, leaf, *i;

  for(leaf = stk_ptr = 0; r != tr_stk[0];) {
    if(!cells) { 
      if(cycles && rand() % 2) { 
        *r = ancestor;
      } else {
        *(i = malloc(sizeof(int))) = leaf++;
        setBit((void **)&i, 0);
        *r = i;
      }
      cells = size_stk[stk_ptr];
      r = tr_stk[stk_ptr--];
    } else {
      *r = cons(NULL, NULL);
      cells--;
      if(rand() % 2 || !ancestor) { ancestor = *r; }
      size_stk[++stk_ptr] = cells / 2;
      cells -= cells / 2;
      tr_stk[stk_ptr] = &(((cell_t *)(*r))->cdr);
      r = &(((cell_t *)(*r))->car);
    }
  }
}

typedef struct hash_t {
  unsigned long size;
  cell_t **tbl;
} hash_t;

hash_t *hash(unsigned long size) {
  hash_t *hash = malloc(sizeof(hash_t));
  hash->size = size;
  hash->tbl = calloc(size, sizeof(cell_t *));
  return hash;
}

void hash_insert(hash_t *h, cell_t *cell, int cell_pos) {
  int loc = (*(int *)cell * 53) % h->size;
  cell_t *bucket = *(h->tbl + loc);
  for(; bucket; bucket = cdr(bucket)) {
    if(car(car(bucket)) == cell) { return; } // already exists
  }
  cell_t *elem = malloc(sizeof(cell_t));
  set_car(elem, cell);
  int *i = malloc(sizeof(int));
  *i = cell_pos;
  set_cdr(elem, i);
  cell_t *link = malloc(sizeof(cell_t));
  set_car(link, elem);
  set_cdr(link, *(h->tbl + loc));
  *(h->tbl + loc) = link;
}

int hash_ref(hash_t *h, cell_t *cell) {
  int loc = (*(int *)cell * 53) % h->size;
  cell_t *bucket = *(h->tbl + loc);
  for(; bucket && car(car(bucket)) != cell; bucket = cdr(bucket));
  if(!bucket) { return 0; } // not found
  return *(int *)cdr(car(bucket));
}

void traverse_tr_intact(void *tr, int cells) { 
  hash_t *seen = hash(1000);
  void *stk[(int)ceil(log(cells + 1) / log(2))];

  for(cells = 0; tr != stk[0];) { // cells as stk_ptr
    if(isAtomic(&tr) || hash_ref(seen, tr)) {
      tr = stk[cells--];
    } else if(isPtr(&tr)) {
      hash_insert(seen, tr, 1);
      stk[++cells] = cdr(tr);
      tr = car(tr);
    } else {
      fprintf(stderr, "error: unrecognized type in generated tree\n");
      exit(EXIT_FAILURE);
    }
  }
}

void traverse_tr_addrs(void *tr, int cells) { 
  int loc, stk_ptr;
  hash_t *seen = hash(1000);
  void *stk[(int)ceil(log(cells + 1) / log(2))];

  for(cells = 1, stk_ptr = loc = 0; tr != stk[0];) {
    if(isAtomic(&tr) || (loc = hash_ref(seen, tr))) {
      if(!loc) { clrBit(&tr, 0); }
      loc ? printf("\t\tleaf #cycle %d#: %p\n", loc, tr) : printf("\t\tleaf %d: %p\n", *(int *)tr, tr);
      tr = stk[stk_ptr--];
    } else if(isPtr(&tr)) {
      printf("cell: %p\n", tr);
      hash_insert(seen, tr, cells++);
      stk[++stk_ptr] = cdr(tr);
      tr = car(tr);
    } else {
      fprintf(stderr, "error: unrecognized type in generated tree\n");
      exit(EXIT_FAILURE);
    }
  }
  printf("\n");
}

void traverse_tr(void *tr, int cells) {
  int loc, stk_ptr;
  hash_t *seen = hash(1000);
  void *stk[(int)ceil(log(cells + 1) / log(2))];

  for(cells = 1, stk_ptr = loc = 0; tr != stk[0];) {
    if(isAtomic(&tr) || (loc = hash_ref(seen, tr))) {
      if(!loc) { clrBit(&tr, 0); }
      loc ? printf("#cycle: %d#", loc) : printf("%d", *(int *)tr); 
      for(; 0;) { printf(")"); } // FIXME: print correct number of right parens
      if(stk_ptr) { printf(" . "); }
      tr = stk[stk_ptr--];
    } else if(isPtr(&tr)) {
      printf("(");
      hash_insert(seen, tr, cells++);
      stk[++stk_ptr] = cdr(tr);
      tr = car(tr);
    } else {
      fprintf(stderr, "error: unrecognized type in generated tree\n");
      exit(EXIT_FAILURE);
    }
  }
  printf("\n");
}
