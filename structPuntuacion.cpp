#include "structPuntuacion.H"

structPuntuacion prasePuntuacion(char _SKN[3], int _puntos, int _secElapsed, int _minElapsed) {
	structPuntuacion score;



	for (int i = 0; i < 3; i++) {
		score.SKN[_SKN[i]];
	}
	score.secElapsed = _secElapsed;
	score.minElapsed = _minElapsed;
	score.puntos = _puntos;

	return score;
}

bool leerDeDisco(int pos) {
	structPuntuacion* scr;
	FILE* p;
	bool leyo;
	p = fopen("IMG/scoreboard/puntuacionesTemp.dat", "rb");
	if (p == NULL) return false;
	fseek(p, sizeof(scr) * pos, 0);
	leyo = fread(scr, sizeof * scr, 1, p);
	fclose(p);
	return leyo;
}

void grabarPuntuacion(structPuntuacion* score) {
	FILE* p;
	p = fopen("IMG/scoreboard/puntuacionesTemp.dat", "ab");
	if (p == NULL) return;
	fwrite(score, sizeof(structPuntuacion), 1, p);
	fclose(p);
}

void top5Score(char* _SKN[3], int _puntos, int _secElapsed, int _minElapsed) {
	structPuntuacion scr;

	//scr = new structPuntuacion;

	scr = prasePuntuacion(_SKN[3], _puntos, _secElapsed, _minElapsed);

	int pos = 0;
	int maxPuntos = 0;

	int puntosFinal[5] = { 0 };
	int __secElapsed[5] = { 0 };
	int __minElapsed[5] = { 0 };
	char _SKN[5][3] = { 0 };
	char _SKNTEMP[3];

	while (leerDeDisco(pos++)) {


			if (maxPuntos == 0) {
				maxPuntos = scr.puntos;
			}
			else if (scr.puntos > maxPuntos) {
				maxPuntos = scr.puntos;

				for (int i = 0; i < 4; i++) {
				
					if (maxPuntos > puntosFinal[i]) {
						puntosFinal [i]= scr.puntos;
						__secElapsed[i] = scr.secElapsed;
						__minElapsed[i] = scr.minElapsed;
						strcpy(_SKNTEMP, scr.SKN);
						_SKN[i][0];
					}
					
				}


			}
	}

}
