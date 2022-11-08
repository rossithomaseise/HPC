#ifndef __MOUVEMENT_H__
#define __MOUVEMENT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "nrc2.h"

#define VMIN 1
#define VMAX 254

void initialisation(uint8**I, uint8**V, uint8**M,int nrh,int nch,int nrl,int ncl);

void sigma_delta(uint8**It, uint8**Vt, uint8**M_t,uint8**V_t_1, uint8**M_t_1, int nrh,int nch,int nrl,int ncl);














#endif