
#include "mouvement.h"

void initialisation(uint8**I, uint8**V, uint8**M,int nrh,int nch,int nrl,int ncl){
	for(uint16_t i = nrl; i < nrh; i++){
		for(uint16_t j = ncl; j < nch; j++){
			M[i][j] = I[i][j];
			V[i][j] = VMIN;
		}

	}

}

void sigma_delta(uint8**It, uint8**Vt, uint8**M_t,uint8**V_t_1, uint8**M_t_1, int nrh,int nch,int nrl,int ncl){

	//initialisation(I, V_t_1, M_t_1);

	uint8** Ot;
	//Etape 1 : Estimation Mt
	for(uint16_t i = nrl; i < nrh; i++){
		for(uint16_t j = ncl; j < nch; j++){
			if(M_t_1[i][j] < It[i][j])
				M_t[i][j] = M_t_1[i][j] + 1;
			else if(M_t_1[i][j] > It[i][j])
				M_t[i][j] = M_t_1[i][j] - 1;
			else
				M_t[i][j] = M_t_1[i][j];
		}
	}

	//Etape 2 Traitement des différences
	for(uint16_t i = nrl; i < nrh; i++){
		for(uint16_t j = ncl; j < nch; j++){
			Ot[i][j] = abs(M_t[i][j] - It[i][j]);
		}
	}

	


}