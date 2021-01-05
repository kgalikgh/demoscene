#include <copper.h>

CopInsT *CopWait(CopListT *list, u_short vp, u_short hp) {
  CopInsT *ins = list->curr;

  *((u_char *)ins)++ = vp;
  *((u_char *)ins)++ = hp | 1; 
  *((u_short *)ins)++ = 0xfffe;

  list->curr = ins;
  return ins - 1;
}