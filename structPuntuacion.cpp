#include "structPuntuacion.H"

#include <iostream>

structPuntuacion prasePuntuacion(char* _SKN, int _puntos, int _secElapsed, int _minElapsed) {
	structPuntuacion score;



	/*for (int i = 0; i < 3; i++) {
		score.SKN[_SKN[i]];
	}*/
	strcpy_s(score.SKN,strlen(_SKN)+1, _SKN);
	score.secElapsed = _secElapsed;
	score.minElapsed = _minElapsed;
	score.puntos = _puntos;

	return score;
}

bool leerDeDisco( int pos, bool &leyo) {
	structPuntuacion scr;
	FILE* p;

	fopen_s(&p,"IMG/scoreboard/puntuacionesTemp.dat","rb");
	///p = fopen("IMG/scoreboard/puntuacionesTemp.dat", "rb");
	if (p == NULL) return false;
	fseek(p, sizeof(structPuntuacion) * pos, 0);
	leyo = fread(&scr, sizeof scr, 1, p);
	fclose(p);
	return leyo;
}

structPuntuacion leerDeDisco(int pos) {
	structPuntuacion scr;
	FILE* p;

	fopen_s(&p,"IMG/scoreboard/puntuacionesTemp.dat","rb");
	///p = fopen("IMG/scoreboard/puntuacionesTemp.dat", "rb");
	if (p == NULL)exit;//scr.minElapsed = 0; scr.puntos = 0; scr.secElapsed = 0;scr.minElapsed=0; scr.SKN[0] = '\0'; return scr;
	fseek(p, sizeof(structPuntuacion) * pos, 0);
	fread(&scr, sizeof scr, 1, p);
	fclose(p);
	return scr;
}

int cantidadDePuntuaciones() {
	FILE* p /*= fopen("IMG/scorebiard/puntuacionesTemp.dat", "rb")*/;
	fopen_s(&p, "IMG/scoreboard/puntuacionesTemp.dat", "rb");
	if (p == NULL) {
		return 0;
	}
	int bytes, cant;
	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant = bytes / sizeof(structPuntuacion);
	return cant;
}

void grabarPuntuacion(structPuntuacion score) {
	FILE* p;
	///p = fopen("IMG/scoreboard/puntuacionesTemp.dat", "ab");
	fopen_s(&p,"IMG/scoreboard/puntuacionesTemp.dat","ab");
	if (p == NULL) return;
	fwrite(&score, sizeof(structPuntuacion), 1, p);
	fclose(p);
}

void top5Score(/*char* _SKN[3], int _puntos, int _secElapsed, int _minElapsed*/) {
	structPuntuacion *scr;
	//FILE* p;
	///structPuntuacion acs;

	bool leyo = true;
	int cant;
	cant = cantidadDePuntuaciones();
	scr = new structPuntuacion [cant];

	///*scr = prasePuntuacion(_SKN[3], _puntos, _secElapsed, _minElapsed);
	/// 
	
	if (scr == NULL) {
		return;
	}

	int pos = 0;

	int tempSecElapsed = 0;
	int tempMinElapsed = 0;
	char tempSKN[3] = { 0 };
	int tempPuntos = 0;

	/*int puntosFinal[5] = { 0 };
	int __secElapsed[5] = { 0 };
	int __minElapsed[5] = { 0 };
	char __SKN[5][3] = { 0 };*/



	while (leerDeDisco(pos++, leyo)) {

		*scr = leerDeDisco(pos-1);
		
		///std::cout << scr[3].puntos<< std:: endl;

		for (int i = 0; i < cant - 1; i++) {
			for (int j = i + 1; j < cant; j++) {
				if (scr[i].puntos < scr[j].puntos) {

					//guardo temporales auxiliares
					tempPuntos = scr[i].puntos;
					tempSecElapsed = scr[i].secElapsed;
					tempMinElapsed = scr[i].minElapsed;
					strcpy_s(tempSKN,strlen(tempSKN)+5, scr[i].SKN);

					//intercambio valores mayores por menores
					scr[i].puntos = scr[j].puntos;
					scr[i].secElapsed = scr[j].secElapsed;
					scr[i].minElapsed = scr[j].minElapsed;
					strcpy_s(scr[i].SKN, strlen(tempSKN) + 5, scr[j].SKN);

					///pongo los menores en pos+1
					scr[j].puntos = tempPuntos;
					scr[j].secElapsed = tempSecElapsed;
					scr[j].minElapsed = tempMinElapsed;
					strcpy_s(scr[j].SKN, strlen(tempSKN) + 5, tempSKN);
					
					std::cout << scr->puntos << std::endl;

					
					grabarPuntuacion(*scr);

					
				}
			}
		}





			/*if (maxPuntos == 0) {
				maxPuntos = scr->puntos;
			}
			else if (scr->puntos > maxPuntos) {
				maxPuntos = scr->puntos;

				for (int i = 0; i < 5; i++) {


					puntosFinal[i] = scr->puntos;
					__secElapsed[i] = scr->secElapsed;
					__minElapsed[i] = scr->minElapsed;
					///strcpy(_SKNTEMP, scr->SKN);
					_SKN[i][0];
				}
			}*/

			

			/*for (int x = 0; x < 4; x++)
			{
				for (int i = x+1; i < 5; i++) {

					if (puntosFinal[x] < puntosFinal[i]) {
						tempPuntos = puntosFinal[x];
						puntosFinal[x] = puntosFinal[i];
						puntosFinal[i] = tempPuntos;


					}

				}
			}*/

	}
	pos = 0;
	delete scr;
}

/*
void top52() {
	structPuntuacion scr;
	FILE* p;
	///structPuntuacion acs;


	int cant = cantidadDePuntuaciones();
	int* vPuntos;
	vPuntos = new int[cant];

	int* vSec;
	vSec = new int[cant];

	int* vMin;
	vMin = new int[cant];

	char (*vSKN)[3];

	vSKN = new char[cant][3];


	///int cant = cantidadDePuntuaciones();
	//scr = new structPuntuacion[cant];

	/*if (scr == NULL) {
		return;
	}

	

	//p = fopen("IMG/scoreboard/puntuacionesTemp.dat", "rb");
	*/

	/*if (vPuntos == NULL) {
	std::cout << "puntos no" << std::endl;
	}

	if (vSec == NULL) {
		std::cout << "sec no" << std::endl;
	}

	if (vMin == NULL) {
		std::cout << "min no" << std::endl;
	}

	if (vSKN == NULL) {
		std::cout << "char no" << std::endl;
	}





	fopen_s(&p, "IMG/scoreboard/puntuacionesTemp.dat", "rb");

	if (p == NULL) {
		return;
	}

	int pos = 0;

	int tempSecElapsed = 0;
	int tempMinElapsed = 0;
	char tempSKN[3] = { 0 };
	int tempPuntos = 0;

	while (fread(&scr, sizeof(scr)*pos, 1, p) == 1) {

		/*vPuntos[pos+1] = scr.puntos;
		vSec[pos+1] = scr.secElapsed;
		vMin[pos+1] = scr.minElapsed;
		strcpy_s(vSKN[pos], strlen(vSKN[pos])+1, scr.SKN);*/
/*
		for (int i = 0; i < cant - 1; i++) {
			for (int j = i + 1; j < cant; j++) {
				if (scr.puntos < vPuntos[j]) {

					//guardo temporales auxiliares
					tempPuntos = scr[i].puntos;
					tempSecElapsed = scr[i].secElapsed;
					tempMinElapsed = scr[i].minElapsed;
					strcpy_s(tempSKN, strlen(tempSKN) + 1, scr[i].SKN);

					//intercambio valores mayores por menores
					scr[i].puntos = scr[j].puntos;
					scr[i].secElapsed = scr[j].secElapsed;
					scr[i].minElapsed = scr[j].minElapsed;
					strcpy_s(scr[i].SKN, strlen(tempSKN) + 1, scr[j].SKN);

					///pongo los menores en pos+1
					scr[j].puntos = tempPuntos;
					scr[j].secElapsed = tempSecElapsed;
					scr[j].minElapsed = tempMinElapsed;
					strcpy_s(scr[j].SKN, strlen(tempSKN) + 1, tempSKN);

					std::cout << "exito";
					grabarPuntuacion(*scr);


				}

				
			}
		}
		pos++;
	}
	pos = 0;
	fclose(p);

	delete scr;
}*/