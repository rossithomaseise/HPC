#include "morpho.h"


uint8** dilatation(uint8**E_t,int nrl, int nrh, int ncl, int nch){

	for(uint16_t i = nrl; i <=nrh; i++){
		for(uint16_t j = ncl; j <=nch; j++){
			//Coin haut gauche
			if(i == nrl && j == ncl){
				//OPTIMISATION : REGARDER DIRECTEMENT SANS BOUCLE (IF ET OR)
				for(uint16_t i_temp = i ; i_temp <= i + 1; i_temp++){
					for(uint16_t j_temp = j ; j_temp <= i + 1; j_temp++){
						//METTRE UN FLAG APRES POUR OPTIMISER
						if(E_t[i_temp][j_temp] == 0 && j_temp != j && i_temp != i)
							E_t[i][j] = 0;
					}
				}
			}
			//Coin haut droite
			else if(i == nrl && j == nch){
				
			}
			//Coin bas droite
			else if(i == nrh && j == nch){
				
			}
			//Coin bas gauche
			else if(i == nrh && j == ncl){
				
			}
			//Bord gauche
			else if(i > nrl && i < nrh && j == ncl){
				
			}
			//Bord haut
			else if(i == nrl && j > ncl && j < nch){
				
			}
			//Bord droit
			else if(i > nrl && i < nrh && j == nch){
				
			}

			//Bord bas
			else if(i == nrh && j > ncl && j < nrh){
				
			}

			//On n'est pas sur les bords
			else{
				for(uint16_t i_temp = i - 1 ; i_temp <= i + 1; i_temp++){
					for(uint16_t j_temp = j - 1 ; j_temp <= i + 1; j_temp++){
						//METTRE UN FLAG APRES POUR OPTIMISER
						if(E_t[i_temp][j_temp] == 0 && j_temp != j && i_temp != i)
							E_t[i][j] = 0;
					}
				}
			}

		}
	}
}