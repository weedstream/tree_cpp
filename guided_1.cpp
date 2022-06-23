#include <iostream>

using namespace std;

struct pohon
{
	pohon * kanan;
	char data;
	pohon * kiri;
};

pohon * simpul;
pohon * root;
pohon * saatIni;
pohon * helperA;
pohon * helperB;
pohon * alamat[256];

void insialisasi()
{
	root = NULL;
}

void simpulBaru(char dataMasukkan)
{
	simpul = new pohon;
	simpul->data = dataMasukkan;	//A
	simpul->kanan = NULL;
	simpul->kiri = NULL;
}

void simpulAkar()
{
	if (root == NULL)
	{
		char dataAnda;
		cout << "Silahkan masukkan data : ";
		cin >> dataAnda;	//B
		simpulBaru(dataAnda);
		root = simpul;
		cout << "Root terbentuk..." << endl;
	}
	else
	{
		cout << "Root sudah ada..." << endl;
	}
}

void tambahSimpul()
{
	if (root != NULL)
	{
		int i, j, penanda;
		char dataUser;
		i = 1;
		j = 1;
		penanda = 0;
		alamat[i] = root;
		while (penanda == 0 && j < 256)
		{
			cout << "Masukkan data kiri : ";
			cin >> dataUser;	//B
			if (dataUser != '0')
			{
				simpulBaru(dataUser);
				saatIni = alamat[i];
				saatIni->kiri = simpul;
				j++;	// j = 2
				alamat[j] = simpul;	// alamat simpul B
			}
			else
			{
				penanda = 1;
				j++;
				alamat[j] = NULL;
			}
			if (penanda == 0)
			{
				cout << "Masukkan data kanan : ";
				cin >> dataUser;	// C
				if (dataUser != '0')
				{
					simpulBaru(dataUser);
					saatIni = alamat[i];
					saatIni->kanan = simpul;
					j++;	//3
					alamat[j] = simpul;	// alamat simpul C
				}
				else
				{
					penanda = 1;
					j++;
					alamat[j] = NULL;
				}
			}
			i++;
		}
	}
}

void bacaPohon()
{
	if (root != NULL)
	{
		int i, n, pencacah;
		i = 1;
		n = 1;
		pencacah = 0;
		cout << endl;
		while (alamat[i] != NULL)
		{
			saatIni = alamat[i];
			cout << saatIni->data << " ";
			pencacah++;	//1
			if (pencacah == n)
			{
				cout << endl;
				pencacah = 0;
				n = n * 2;
			}
			i++;
		}
	}
}

int main()
{
	simpulAkar();
	tambahSimpul();
	bacaPohon();

	return 0;
}