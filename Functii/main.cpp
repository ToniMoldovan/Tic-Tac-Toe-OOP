#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct Jucator {
	string nume = "";
	int scor = 0;
	bool tura = false;
	char semn = ' '; // X sau 0
};

typedef struct Joc
{
	char tabla[5][5] = {
		{'1', '|', '2', '|', '3'},
		{'_', '_', '_', '_', '_'},
		{'4', '|', '5', '|', '6'},
		{'_', '_', '_', '_', '_'},
		{'7', '|', '8', '|', '9'}
	};

	Jucator j1, j2;
};

/*Operatiuni tabla*/
void afisareTabla(Joc obJoc) {
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << obJoc.tabla[i][j];

		cout << endl;
	}

	cout << endl;
}
void afisareJucatori(Joc obJoc) {
	cout << "Jucatorul 1: " << obJoc.j1.nume << " | scor: " << obJoc.j1.scor << endl;
	cout << "Jucatorul 2: " << obJoc.j2.nume << " | scor: " << obJoc.j2.scor << endl;
}
Joc initializareJocNou() {
	Joc jocNou;

	cout << "Introdu numele primului jucator: "; cin >> jocNou.j1.nume;
	cout << "Introdu numele celui de-al doilea jucator: "; cin >> jocNou.j2.nume;

	cout << "\n[INFO]: Noul joc a fost initializat cu succes." << endl << endl;

	return jocNou;
}


/*Operatuni administrative*/
Joc alegereJucatorRandom(Joc obJoc) {
	/* initialize random seed: */
	srand(time(NULL));

	int numarGenerat = rand() % 2 + 1;

	if (numarGenerat == 1) {
		obJoc.j1.semn = 'X';
		obJoc.j1.tura = true;

		obJoc.j2.semn = '0';
		obJoc.j2.tura = false;

		cout << obJoc.j1.nume << " va juca cu X." << endl;
		cout << obJoc.j2.nume << " va juca cu 0." << endl;

	}
	else {
		obJoc.j2.semn = 'X';
		obJoc.j2.tura = true;

		obJoc.j1.semn = '0';
		obJoc.j1.tura = false;

		cout << obJoc.j2.nume << " va juca cu X." << endl;
		cout << obJoc.j1.nume << " va juca cu 0." << endl;
	}

	return obJoc;
}

//Returneaza TRUE daca este tura lui j1
bool verificareTuraJucator(Joc obJoc) {
	if (obJoc.j1.tura)
		return true;
	else
		return false;
}

Joc schimbareTuraJucator(Joc obJoc) {
	if (obJoc.j1.tura)
	{
		obJoc.j2.tura = true;
		obJoc.j1.tura = false;
	}
	else
	{
		obJoc.j1.tura = true;
		obJoc.j2.tura = false;
	}

	return obJoc;
}

bool verificarePozitieDisponibila(Joc obJoc, unsigned int poz) {
	switch (poz)
	{
	case 1:
		if (obJoc.tabla[0][0] == '1')
			return true;
		else
			return false;

	case 2:
		if (obJoc.tabla[0][2] == '2')
			return true;
		else
			return false;

	case 3:
		if (obJoc.tabla[0][4] == '3')
			return true;
		else
			return false;

	case 4:
		if (obJoc.tabla[2][0] == '4')
			return true;
		else
			return false;

	case 5:
		if (obJoc.tabla[2][2] == '5')
			return true;
		else
			return false;

	case 6:
		if (obJoc.tabla[2][4] == '6')
			return true;
		else
			return false;

	case 7:
		if (obJoc.tabla[4][0] == '7')
			return true;
		else
			return false;

	case 8:
		if (obJoc.tabla[4][2] == '8')
			return true;
		else
			return false;

	case 9:
		if (obJoc.tabla[4][4] == '9')
			return true;
		else
			return false;

	default:
		return false;
		break;
	}
}

bool verificareSfarsitJoc(Joc obJoc) {
	if ((obJoc.tabla[0][0] == 'X' && obJoc.tabla[0][2] == 'X' && obJoc.tabla[0][4] == 'X') || 
		(obJoc.tabla[0][0] == '0' && obJoc.tabla[0][2] == '0' && obJoc.tabla[0][4] == '0'))
	{
		return true;
	}
	else if ((obJoc.tabla[2][0] == 'X' && obJoc.tabla[2][2] == 'X' && obJoc.tabla[2][4] == 'X') ||
		(obJoc.tabla[2][0] == '0' && obJoc.tabla[2][2] == '0' && obJoc.tabla[2][4] == '0'))
	{
		return true;
	}
	else if ((obJoc.tabla[4][0] == 'X' && obJoc.tabla[4][2] == 'X' && obJoc.tabla[4][4] == 'X') ||
		(obJoc.tabla[4][0] == '0' && obJoc.tabla[4][2] == '0' && obJoc.tabla[4][4] == '0'))
	{
		return true;
	}
	else if ((obJoc.tabla[0][0] == 'X' && obJoc.tabla[2][2] == 'X' && obJoc.tabla[4][4] == 'X') ||
		(obJoc.tabla[0][0] == '0' && obJoc.tabla[2][2] == '0' && obJoc.tabla[4][4] == '0'))
	{
		return true;
	}
	else if ((obJoc.tabla[0][4] == 'X' && obJoc.tabla[2][2] == 'X' && obJoc.tabla[4][0] == 'X') ||
		(obJoc.tabla[0][4] == '0' && obJoc.tabla[2][2] == '0' && obJoc.tabla[4][0] == '0'))
	{
		return true;
	}
	else if ((obJoc.tabla[0][0] == 'X' && obJoc.tabla[2][0] == 'X' && obJoc.tabla[4][0] == 'X') ||
		(obJoc.tabla[0][0] == '0' && obJoc.tabla[2][0] == '0' && obJoc.tabla[4][0] == '0'))
	{
		return true;
	}
	else if ((obJoc.tabla[0][2] == 'X' && obJoc.tabla[2][2] == 'X' && obJoc.tabla[4][2] == 'X') ||
		(obJoc.tabla[0][2] == '0' && obJoc.tabla[2][2] == '0' && obJoc.tabla[4][2] == '0'))
	{
		return true;
	}
	else if ((obJoc.tabla[0][4] == 'X' && obJoc.tabla[2][4] == 'X' && obJoc.tabla[4][4] == 'X') ||
		(obJoc.tabla[0][4] == '0' && obJoc.tabla[2][4] == '0' && obJoc.tabla[4][4] == '0'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Joc plasareMutare(Joc obJoc) {
	afisareTabla(obJoc);

	unsigned int pozitieAleasa;
	if (verificareTuraJucator(obJoc))
	{
		cout << obJoc.j1.nume << ", alege o pozitie disponibila: "; cin >> pozitieAleasa;
	}
	else
	{
		cout << obJoc.j2.nume << ", alege o pozitie disponibila: "; cin >> pozitieAleasa;
	}

	cout << "Se verifica pozitia..." << endl;

	// Pozitia aleasa este disponibila (TRUE)
	if (verificarePozitieDisponibila(obJoc, pozitieAleasa))
	{
		//Este tura lui j1
		if (verificareTuraJucator(obJoc))
		{
			switch (pozitieAleasa)
			{
			case 1:
				obJoc.tabla[0][0] = obJoc.j1.semn;
				break;

			case 2:
				obJoc.tabla[0][2] = obJoc.j1.semn;
				break;

			case 3:
				obJoc.tabla[0][4] = obJoc.j1.semn;
				break;

			case 4:
				obJoc.tabla[2][0] = obJoc.j1.semn;
				break;

			case 5:
				obJoc.tabla[2][2] = obJoc.j1.semn;
				break;

			case 6:
				obJoc.tabla[2][4] = obJoc.j1.semn;
				break;

			case 7:
				obJoc.tabla[4][0] = obJoc.j1.semn;
				break;

			case 8:
				obJoc.tabla[4][2] = obJoc.j1.semn;
				break;

			case 9:
				obJoc.tabla[4][4] = obJoc.j1.semn;
				break;
			
			default:
				break;
			}

			obJoc = schimbareTuraJucator(obJoc);
		}
		else //Este tura lui j2
		{
			switch (pozitieAleasa)
			{
			case 1:
				obJoc.tabla[0][0] = obJoc.j2.semn;
				break;

			case 2:
				obJoc.tabla[0][2] = obJoc.j2.semn;
				break;

			case 3:
				obJoc.tabla[0][4] = obJoc.j2.semn;
				break;

			case 4:
				obJoc.tabla[2][0] = obJoc.j2.semn;
				break;

			case 5:
				obJoc.tabla[2][2] = obJoc.j2.semn;
				break;

			case 6:
				obJoc.tabla[2][4] = obJoc.j2.semn;
				break;

			case 7:
				obJoc.tabla[4][0] = obJoc.j2.semn;
				break;

			case 8:
				obJoc.tabla[4][2] = obJoc.j2.semn;
				break;

			case 9:
				obJoc.tabla[4][4] = obJoc.j2.semn;
				break;

			default:
				break;
			}

			obJoc = schimbareTuraJucator(obJoc);
		}
	}
	else
	{
		cout << "Pozitia aleasa nu este disponibila. Alege alta.\n";
	}

	return obJoc;
}


void startJoc(Joc obJoc) {
	obJoc = initializareJocNou();

	obJoc = alegereJucatorRandom(obJoc);

	bool jocTerminat = verificareSfarsitJoc(obJoc);

	while (!jocTerminat)
	{
		obJoc = plasareMutare(obJoc);

		jocTerminat = verificareSfarsitJoc(obJoc);
	}

	afisareTabla(obJoc);

	cout << "Sfarsit joc.\n";

}

int main() {
	Joc meciNou;
	startJoc(meciNou);

	return 0;
}