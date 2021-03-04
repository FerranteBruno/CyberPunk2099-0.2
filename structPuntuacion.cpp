#include "structPuntuacion.H"

#include <iostream>

structPuntuacion prasePuntuacion(char _SKN[3], int _puntos, int _secElapsed, int _minElapsed) {
	structPuntuacion score;



	/*for (int i = 0; i < 3; i++) {
		score.SKN[_SKN[i]];
	}*/
	///strcpy_s(score.SKN,strlen(_SKN)+1, _SKN);
	for (int x = 0; x < 3; x++) {
		score.SKN[x] = _SKN[x];
	}
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


structPuntuacion leerDeDiscoOrdenado(int pos) {
	structPuntuacion scr;
	FILE* p;

	fopen_s(&p, "IMG/scoreboard/puntuacionOrdenada.dat", "rb");
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

void grabarPuntuacionOrdenada(structPuntuacion score) {
	FILE* p;
	///p = fopen("IMG/scoreboard/puntuacionesTemp.dat", "ab");
	fopen_s(&p, "IMG/scoreboard/puntuacionOrdenada.dat", "ab");
	if (p == NULL) return;
	fwrite(&score, sizeof(structPuntuacion), 1, p);
	fclose(p);
}

structPuntuacion leerTop5(int pos) {

	structPuntuacion scr;
///	int pos = 0;



	while (pos++) {
		scr = leerDeDiscoOrdenado(pos);

		/*vPuntos[pos] = scr.puntos;
		vSec[pos] = scr.secElapsed;
		vMin[pos] = scr.minElapsed;
		for (int x = 0; x < 3; x++) {
			vSKN[pos][x] = scr.SKN[x];
		}*/

	}

	return scr;


}

void top5Score(/*char* _SKN[3], int _puntos, int _secElapsed, int _minElapsed*/) {
	structPuntuacion scr;


	bool leyo = true;
	int cant;
	cant = cantidadDePuntuaciones();

	int* vPuntos;
	vPuntos = new int[cant];

	int* vSec;
	vSec = new int[cant];

	int* vMin;
	vMin = new int[cant];

	char(*vSKN)[3];

	vSKN = new char[cant][3];


	int pos = 0;

	int tempSecElapsed = 0;
	int tempMinElapsed = 0;
	char tempSKN[3] = { 0 };
	int tempPuntos = 0;

	for (int i = 0; i < cant; i++) {
		scr = leerDeDisco(pos++);
		vPuntos[i] = scr.puntos;
		vSec[i] = scr.secElapsed;
		vMin[i] = scr.minElapsed;
		for (int x = 0; x < 3; x++) {
			vSKN[i][x] = scr.SKN[x];
		}
	}

	pos = 0;

	/*remove("puntuacionOrdenada.dat");*/
	remove("IMG/scoreboard/puntuacionOrdenada.dat");
	std::cout << "puntuacion borrada" << std::endl;

	while (leerDeDisco(pos++, leyo)) {		

		for (int i = 0; i < cant - 1; i++) {
			for (int j = i + 1; j < cant; j++) {
				if (vPuntos[i] < vPuntos[j]) {

					//guardo temporales auxiliares
					tempPuntos = vPuntos[i];
					tempSecElapsed = vSec[i];
					tempMinElapsed = vMin[i];
					for (int x = 0; x < 3; x++) {
						tempSKN[x] = vSKN[i][x];
					}
					
					//intercambio valores mayores por menores
					vPuntos[i] = vPuntos[j];
					vSec[i] = vSec[j];
					vMin[i] = vMin[j];
					for (int x = 0; x < 3; x++) {
						vSKN[i][x] = vSKN[j][x];
					}

					///pongo los menores en pos+1
					vPuntos[j] = tempPuntos;
					vSec[j] = tempSecElapsed;
					vMin[j] = tempMinElapsed;
					for (int x = 0; x < 3; x++) {
						vSKN[j][x] = tempSKN[x];
					}
					
				}
			}
		}
	}

	pos = 0;

	for (int i = 0; i < 5; i++) {
		scr.puntos = vPuntos[i];
		scr.secElapsed = vSec[i];
		scr.minElapsed = vMin[i];
		for (int x = 0; x < 3; x++) {
			scr.SKN[x] = vSKN[i][x];
		}
		grabarPuntuacionOrdenada(scr);
	}

	delete vPuntos;
	delete vSec;
	delete vMin;
	delete vSKN;
}