#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"

typedef struct{
  void (* Init)	(void);
}Key_t;


extern Key_t Key;
#endif
