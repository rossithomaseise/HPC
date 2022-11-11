#include "morpho.h"
int flag_break;

uint8** erosion(uint8**E_t, int nrl, int nrh, int ncl, int nch){
	
	uint8**E_t_bis=ui8matrix(nrl, nrh, ncl, nch);
	zero_ui8matrix(E_t_bis, nrl, nrh, ncl, nch);

	//Coin haut gauche
	for(uint16_t i_temp = nrl; i_temp <= nrl + 1; i_temp++){
		for(uint16_t j_temp = ncl; j_temp <= ncl + 1; j_temp++){
			if(E_t[i_temp][j_temp] == 0 && j_temp != ncl && i_temp != nrl){
				E_t_bis[nrl][ncl] = 0;				
				flag_break = 1;
				break;
			}
			else{
				E_t_bis[nrl][ncl] = E_t[nrl][ncl];
			}
		}
		if(flag_break){
			flag_break = 0;
			break;
		}
	}
	//Coin haut droite
	for(uint16_t i_temp = nrl; i_temp <= nrl + 1; i_temp++){
		for(uint16_t j_temp = nch - 1; j_temp <= nch; j_temp++){
			if(E_t[i_temp][j_temp] == 0 && j_temp != nch && i_temp != nrl){
				E_t_bis[nrl][nch] = 0;				
				flag_break = 1;
				break;
			}
			else{
				E_t_bis[nrl][nch] = E_t[nrl][nch];
			}
		}
		if(flag_break){
			flag_break = 0;
			break;
		}
	}
	//Coin bas droite
	for(uint16_t i_temp = nrh-1 ; i_temp <= nrh; i_temp++){
		for(uint16_t j_temp = nch-1 ; j_temp <= nch; j_temp++){
			if(E_t[i_temp][j_temp] == 0 && j_temp != nch && i_temp != nrh){
				E_t_bis[nrh][nch] = 0;				
				flag_break = 1;
				break;
			}
			else{
				E_t_bis[nrh][nch] = E_t[nrh][nch];
			}
		}
		if(flag_break){
			flag_break = 0;
			break;
		}
	}
	//Coin bas gauche
	for(uint16_t i_temp = nrh - 1; i_temp <= nrh; i_temp++){
		for(uint16_t j_temp = ncl; j_temp <= ncl + 1; j_temp++){
			if(E_t[i_temp][j_temp] == 0 && j_temp != ncl && i_temp != nrh){
				E_t_bis[nrh][ncl] = 0;				
				flag_break = 1;
				break;
			}
			else{
				E_t_bis[nrh][ncl] = E_t[nrh][ncl];
			}
		}
		if(flag_break){
			flag_break = 0;
			break;
		}
	}
	//Bord gauche
	for(uint16_t i = nrl + 1; i < nrh; i++){
		for(uint16_t i_temp = i - 1; i_temp <= i + 1; i_temp++){
			for(uint16_t j_temp = ncl; j_temp <= ncl + 1; j_temp++){
				if(E_t[i_temp][j_temp] == 0 && j_temp != ncl && i_temp != i){
					E_t_bis[i][ncl] = 0;				
					flag_break = 1;
					break;
				}
				else{
					E_t_bis[i][ncl] = E_t[i][ncl];
				}
			}
			if(flag_break){
				flag_break = 0;
				break;
			}
		}
	}
	//Bord haut
	for(uint16_t j = ncl + 1; j < nch; j++){
		for(uint16_t j_temp = j - 1; j_temp <= j + 1; j_temp++){
			for(uint16_t i_temp = nrl; i_temp <= nrl + 1; i_temp++){
				if(E_t[i_temp][j_temp] == 0 && j_temp != j && i_temp != nrl){
					E_t_bis[nrl][j] = 0;				
					flag_break = 1;
					break;
				}
				else{
					E_t_bis[nrl][j] = E_t[nrl][j];
				}
			}
			if(flag_break){
				flag_break = 0;
				break;
			}
		}
	}
	//Bord droit
	for(uint16_t i = nrl + 1; i < nrh; i++){
		for(uint16_t i_temp = i - 1; i_temp <= i + 1; i_temp++){
			for(uint16_t j_temp = nch - 1; j_temp <= nch; j_temp++){
				if(E_t[i_temp][j_temp] == 0 && j_temp != nch && i_temp != i){
					E_t_bis[i][nch] = 0;				
					flag_break = 1;
					break;
				}
				else{
					E_t_bis[i][nch] = E_t[i][nch];
				}
			}
			if(flag_break){
				flag_break = 0;
				break;
			}
		}
	}
	//Bord bas
	for(uint16_t j = ncl + 1; j < nch; j++){
		for(uint16_t j_temp = j - 1; j_temp <= j + 1; j_temp++){
			for(uint16_t i_temp = nrh - 1; i_temp <= nrh; i_temp++){
				if(E_t[i_temp][j_temp] == 0 && j_temp != j && i_temp != nrh){
					E_t_bis[nrh][j] = 0;				
					flag_break = 1;
					break;
				}
				else{
					E_t_bis[nrh][j] = E_t[nrh][j];
				}
			}
			if(flag_break){
				flag_break = 0;
				break;
			}
		}
	}
	for(uint16_t i = nrl + 1; i < nrh; i++){
		for(uint16_t j = ncl + 1; j < nch; j++){
			for(uint16_t i_temp = i - 1; i_temp <= i + 1; i_temp++){
				for(uint16_t j_temp = j - 1; j_temp <= j + 1; j_temp++){
					if(E_t[i_temp][j_temp] == 0 && j_temp != j && i_temp != i){
						flag_break = 1;
						E_t_bis[i][j] = 0;
						break;
					}
					else{
						E_t_bis[i][j] = E_t[i][j];
					}
				}
				if(flag_break){
					flag_break = 0;
					break;
				}
			}
		}
	}
	return E_t_bis;
}

uint8** dilatation(uint8**E_t, int nrl, int nrh, int ncl, int nch){

	uint8**E_t_bis=ui8matrix(nrl, nrh, ncl, nch);
	zero_ui8matrix(E_t_bis, nrl, nrh, ncl, nch);

	//Coin haut gauche
	for(uint16_t i_temp = nrl; i_temp <= nrl + 1; i_temp++){
		for(uint16_t j_temp = ncl; j_temp <= ncl + 1; j_temp++){
			if(E_t[i_temp][j_temp] == 255 && j_temp != ncl && i_temp != nrl){
				E_t_bis[nrl][ncl] = 255;				
				flag_break = 1;
				break;
			}
		}
		if(flag_break){
			flag_break = 0;
			break;
		}
	}
	//Coin haut droite
	for(uint16_t i_temp = nrl; i_temp <= nrl + 1; i_temp++){
		for(uint16_t j_temp = nch - 1; j_temp <= nch; j_temp++){
			if(E_t[i_temp][j_temp] == 255 && j_temp != nch && i_temp != nrl){
				E_t_bis[nrl][nch] = 255;				
				flag_break = 1;
				break;
			}
		}
		if(flag_break){
			flag_break = 0;
			break;
		}
	}
	//Coin bas droite
	for(uint16_t i_temp = nrh - 1 ; i_temp <= nrh; i_temp++){
		for(uint16_t j_temp = nch - 1; j_temp <= nch; j_temp++){
			if(E_t[i_temp][j_temp] == 255 && j_temp != nch && i_temp != nrh){
				E_t_bis[nrh][nch] = 255;				
				flag_break = 1;
				break;
			}
		}
		if(flag_break){
			flag_break = 0;
			break;
		}
	}
	//Coin bas gauche
	for(uint16_t i_temp = nrh - 1; i_temp <= nrh; i_temp++){
		for(uint16_t j_temp = ncl; j_temp <= ncl + 1; j_temp++){
			if(E_t[i_temp][j_temp] == 255 && j_temp != ncl && i_temp != nrh){
				E_t_bis[nrh][ncl] = 255;				
				flag_break = 1;
				break;
			}
		}
		if(flag_break){
			flag_break = 0;
			break;
		}
	}
	//Bord gauche
	for(uint16_t i = nrl + 1; i < nrh; i++){
		for(uint16_t i_temp = i - 1; i_temp <= i + 1; i_temp++){
			for(uint16_t j_temp = ncl; j_temp <= ncl + 1; j_temp++){
				if(E_t[i_temp][j_temp] == 255 && j_temp != ncl && i_temp != i){
					E_t[i][ncl] = 255;				
					flag_break = 1;
					break;
				}
			}
			if(flag_break){
				flag_break = 0;
				break;
			}
		}
	}
	//Bord haut
	for(uint16_t j = ncl + 1; j < nch; j++){
		for(uint16_t j_temp = j - 1; j_temp <= j + 1; j_temp++){
			for(uint16_t i_temp = nrl; i_temp <= nrl + 1; i_temp++){
				if(E_t[i_temp][j_temp] == 255 && j_temp != j && i_temp != nrl){
					E_t_bis[nrl][j] = 255;				
					flag_break = 1;
					break;
				}
			}
			if(flag_break){
				flag_break = 0;
				break;
			}
		}
	}
	//Bord droit
	for(uint16_t i = nrl + 1; i < nrh; i++){
		for(uint16_t i_temp = i - 1; i_temp <= i + 1; i_temp++){
			for(uint16_t j_temp = nch - 1; j_temp <= nch; j_temp++){
				if(E_t[i_temp][j_temp] == 255 && j_temp != nch && i_temp != i){
					E_t_bis[i][nch] = 255;				
					flag_break = 1;
					break;
				}
			}
			if(flag_break){
				flag_break = 0;
				break;
			}
		}
	}
	//Bord bas
	for(uint16_t j = ncl + 1; j < nch; j++){
		for(uint16_t j_temp = j - 1; j_temp <= j + 1; j_temp++){
			for(uint16_t i_temp = nrh - 1; i_temp <= nrh; i_temp++){
				if(E_t[i_temp][j_temp] == 255 && j_temp != j && i_temp != nrh){
					E_t_bis[nrh][j] = 255;				
					flag_break = 1;
					break;
				}
			}
			if(flag_break){
				flag_break = 0;
				break;
			}
		}
	}
	for(uint16_t i = nrl +1; i < nrh; i++){
		for(uint16_t j = ncl + 1; j < nch; j++){
			for(uint16_t i_temp = i - 1; i_temp <= i + 1; i_temp++){
				for(uint16_t j_temp = j - 1; j_temp <= j + 1; j_temp++){
					if(E_t[i_temp][j_temp] == 255 && j_temp != j && i_temp != i){
						flag_break = 1;
						E_t_bis[i][j] = 255;
						break;
					}
				}
				if(flag_break){
					flag_break = 0;
					break;
				}
			}
		}
	}
	return E_t_bis;
}