#ifndef __MORPHO_H__
#define __MORPHO_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "nrc2.h"

uint8** dilatation(uint8**E_t, int nrl, int nrh, int ncl, int nch);
uint8** erosion(uint8**E_t, int nrl, int nrh, int ncl, int nch);

#endif
