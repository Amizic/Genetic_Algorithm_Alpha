#include <iostream>
#include <stdio.h>
using namespace std;

#include <time.h>
#include <windows.h>
#include "Chromosome.h"
#include "Population.h"

// STUDENT: VUK AMIZIC IT 14/18 EVOLUCIJA HROMOZOMA, MUTACIJA, GENERISANJE NOVIH GENERACIJA - DOMACI MEKO RACUNARSTVO
// PREDMETNI PROFESOR: VLADIMIR BRTKA
// PREDMETNI ASISTENT: IGOR VECSTEJN
int main()
{   BEGIN: //LABELA ZA VRACANJE NA POCETAK, U KOLIKO KORISNIK ZELI PONOVO DA GENERISE HROMOZOME-MOZE SE KORISTITI GOTO JER JE MALA APLIKACIJA, BEZ POTREBE ZA PRACENJEM TOKA MEMORIJSKIH ADRESA
    char handle;
    int target[]={0,1,0,1}; //META JE ZADATA I UNUTAR KLASE HROMOZOMA, MOZE SE ZANEMARITI ZA OSTALE GENERACIJE OSIM ZA PRVU (TREBA REFAKTORISATI KOD)
    int value[4];
    Population population;
    Chromosome chromosome[3][4];
    cout<<"GENERATING CHROMOSOMES...\n";
    for(int i=0;i<1;i++){
            for(int j=0;j<4;j++){
            chromosome[i][j].forge_chromosome(0,4,target);
            population.add_chromosome(chromosome[i][j],i,j);
            //population.chromosome[i][j].chromosome_info();
            Sleep(1000);
        }
    }

        //population.evolve(0);
        cout<<"\n CHROMOSOMES GENERATED! \n";
        cout<<"\n \n ...Calculating mutation chances...\n";
        //population.chromosome[1][0].chromosome_info();
        //population.evolve_gen(0);
       // population.evolve_gen(1);
        //population.evolve_all(2);
        for(int i=0;i<10;i++){
            population.evolve_gen(i);
        }
       // population.chromosome[1][0].chromosome_info();

        //RACUNANJE FITNESA HROMOZOMA
        for(int i=0;i<10;i++)
            for(int j=0;j<4;j++)
            population.chromosome[i][j].chromosome_fitness();
        //PRIKAZ PODATAKA HROMOZOMA
        for(int i=0;i<10;i++)
            for(int j=0;j<4;j++){
            cout<<"Chromosome["<<i<<"]"<<"["<<j<<"]: ";
            population.chromosome[i][j].chromosome_info();
            cout<<"\n";
            }
        ASK_AGAIN://LABELA ZA PONOVNO PITANJE
        cout<<"\n Generate again? (Y/N)";
        cin>>handle;
        if(handle=='Y' || handle=='y'){
            cout<<"\n";
            goto BEGIN;//POVRATAK NA LABELU ZA POCETAK PROGRAMA
        }else if(handle!='N' && handle!='n')
                goto ASK_AGAIN; //POVRATAK NA LABELU ZA PONOVNO PITANJE


    return 0;
}
