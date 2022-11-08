#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include "nrc2-master/include/nrc2.h"
//#include "nrc2-master/include/nrutil.h"
#include "nrc2.h"
#include "mouvement.h"
//#include "nrutil.h"

#define VMIN 1
#define VMAX 254

//COMMANDE COMPIL gcc main.c -Inrc2-master/include/ -Lnrc2-master/build/lib/ -lnrc



int main(){

	int nrl, nrh, ncl, nch;
	uint8** image = LoadPGM_ui8matrix("/home/fredecontre/Bureau/HPC/Projet/HPC/car3/car_3000.pgm", &nrl, &nrh, &ncl, &nch);
	//uint8**image = ui8matrix(0, 10, 0, 10);

	//Etape 1 : Estimation Mt
	for(uint16_t i = nrl; i < nrh; i++){
		for(uint16_t j = ncl; j < nch; j++){
			printf("%d ",image[i][j] );
		}
		printf("\n");
	}
	return 0;
}