#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char brind[10];
	char ime[10];
	char prezime[10];
	int ocena;
}TStud;

int meni()
{
	int odg;

	do
	{
		system("cls");
		printf("\n\n\n");
		printf("\nProgram za rad sa studentima.");
		printf("\n1. Unos novog studenta.");
		printf("\n2. Ispis unetih studenata.");
		printf("\n3. Pretraga studenata.");
		printf("\n4. Izmena podataka.");
		printf("\n5. Brisanje studenta.");
		printf("\n6. Prosecna ocena.");
		printf("\n7. Sortiranje studenata po broju indeksa (rastuci redosled).");
		printf("\n8. Sortiranje studenata po oceni (opadajuci redosled).");
		printf("\n0. Kraj.");
		printf("\n\nUnesite opciju:");
		scanf("%d",&odg);
	} while(odg<0 || odg >8);
	return odg;
}

int pretragastudenta(TStud* niz,int n, char* bri)
{
	int poz,i;
	poz=-1;
	for(i=0; i<n; i++)
	{
		if(strcmp(bri,niz[i].brind)==0)
		{
			poz=i;
		}
	}
	return poz;
}

void ispissapozicije(TStud* niz,int poz)
{
	system("cls");
	printf("\nPodaci studenta:");
	if(poz>-1)
	{	
		printf("\n\nIndeks\tIme\tPreizme\tOcena");
		printf("\n%s",niz[poz].brind);
		printf("\t%s",niz[poz].ime);
		printf("\t%s",niz[poz].prezime);
		printf("\t%d",niz[poz].ocena);
	}
	else
	{
		printf("\n\nStudent nije nadjen!");
	}
	printf("\n");
	system("pause");
}

void unosstudenta(TStud* niz,int* n)
{
	TStud temp;
	if(*n<50)
	{
		system("cls");
		printf("\n\nUnesite broj indeksa studenta:");
		fflush(stdin);
		scanf("%s",temp.brind);
		printf("\n\nUnesite ime studenta:");
		fflush(stdin);
		scanf("%s",temp.ime);
		printf("\n\nUnesite prezime studenta:");
		fflush(stdin);
		scanf("%s",temp.prezime);
		printf("\n\nUnesite ocenu studenta:");
		fflush(stdin);
		scanf("%d",&temp.ocena);
		if(pretragastudenta(niz,*n,temp.brind)==-1)
		{
			niz[*n]=temp;
			(*n)++;
		}
		else
		{
			printf("\nStudent sa unetim brojem indeksa vec postoji!\n");
			system("pause");
		}
	}
}

void ispisstudenata(TStud* niz,int n)
{
	int i;
	system("cls");
	printf("\nSpisak unetih studenata:");
	printf("\n\nIndeks\tIme\tPreizme\tOcena");

	for(i=0; i<n; i++)
	{
		printf("\n%s",niz[i].brind);
		printf("\t%s",niz[i].ime);
		printf("\t%s",niz[i].prezime);
		printf("\t%d",niz[i].ocena);
	}
	printf("\n");
	system("pause");
}

void prosekstudenata(TStud* niz,int n)
{
	int i;
	float suma;
	system("cls");
	suma=0;
	for(i=0; i<n; i++)
	{
		suma+=(float)(niz[i].ocena);
	}

	printf("\nProsecna ocena studenata je: %f",suma/n);
	printf("\n");
	system("pause");
}

void sortindeks(TStud* niz,int n)
{
	int i,j;
	TStud temp;
	system("cls");
	printf("\nStudenti sortirani po broju indeksa.");
	if(n>0)
	{
		for(i=0; i<n-1; i++)
		{
			for(j=i+1; j<n; j++)
			{
				if(strcmp(niz[i].brind,niz[j].brind)>0)
				{
					temp=niz[i];
					niz[i]=niz[j];
					niz[j]=temp;
				}
			}
		}
	}
	printf("\n");
	system("pause");
}

void sortocena(TStud* niz,int n)
{
	int i,j;
	TStud temp;
	system("cls");
	printf("\nStudenti sortirani po oceni.");
	if(n>0)
	{
		for(i=0; i<n-1; i++)
		{
			for(j=i+1; j<n; j++)
			{
				if(niz[i].ocena<niz[j].ocena)
				{
					temp=niz[i];
					niz[i]=niz[j];
					niz[j]=temp;
				}
			}
		}
	}
	printf("\n");
	system("pause");
}

void izmenastudenta(TStud* niz, int n)
{
	int odg=1;
	printf("\nIzabrani student je:\n");
	ispissapozicije(niz,n);
	while(odg)
	{
		printf("Izaberite polje koje zelite menjati:\n\t[1] Ime\n\t[2] Prezime\n\t[3] Ocenu\n\n\t[0] Za kraj izmene\n\n?: ");
		fflush(stdin);
		scanf("%d", &odg);
		switch(odg)
		{
		case 1: printf("\nUnesite novo ime: ");
			scanf("%s",&niz[n].ime);
			break;
		case 2: printf("\nUnesite novo prezime: ");
			scanf("%s",&niz[n].prezime);
			break;
		case 3: printf("\nUnesite novu ocenu: ");
			scanf("%d",&niz[n].ocena);
			break;
		}
	}
}

void brisistud(TStud* niz, int* n, int p)
{	
	char odg;
	printf("\nStudent za brisanje:");
	ispissapozicije(niz,p);
	printf("\n\nDa li zelite da obrisete studenta: d-DA, n-NE");
	fflush(stdin);
	scanf("%c",&odg);
	if (odg=='d')
	{
		niz[p]=niz[*n-1];
		(*n)--;
		printf("\n\nStudent je obrisan!\n");
		system("pause");
	}

}

void main()
{
	TStud studenti[50];
	int brel,opcija,poz;
	char bri[10];

	brel=0;

	do{
		opcija = meni();
		switch(opcija)
		{
			case 1:
			{
				unosstudenta(studenti,&brel);
			}break;
			case 2:
			{
				ispisstudenata(studenti,brel);
			}break;
			case 3:
			{
				system("cls");
				printf("\nUnesite broj indeksa studenta kojeg trazite:");
				fflush(stdin);
				scanf("%s",bri);
				poz = pretragastudenta(studenti,brel,bri);
				ispissapozicije(studenti,poz);
			}break;

			case 4:
			{
				system("cls");
				printf("\nUnesite broj indeksa studenta za izmenu podataka:");
				fflush(stdin);
				scanf("%s",bri);
				poz = pretragastudenta(studenti,brel,bri);
				if (poz!=-1)
					izmenastudenta(studenti,poz);
				else
					printf("Student pod unetim brojem indeksa (%s) ne postoji.",bri);

			}break;
			
			case 5:
			{
				system("cls");
				printf("\nUnesite broj indeksa studenta kojeg zelite obrisati:");
				fflush(stdin);
				scanf("%s",bri);
				poz = pretragastudenta(studenti,brel,bri);
				if (poz!=-1)
					brisistud(studenti,&brel,poz);
				else
					printf("Student pod unetim brojem indeksa (%s) ne postoji.",bri);
			}break;

			case 6:
			{
				prosekstudenata(studenti,brel);
			}break;
			case 7:
			{
				sortindeks(studenti,brel);
			}break;
			case 8:
			{
				sortocena(studenti,brel);
			}break;
		}
	}while(opcija!=0);
	


}
