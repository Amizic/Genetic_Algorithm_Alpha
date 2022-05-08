#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED
#include "Chromosome.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

// STUDENT: VUK AMIZIC IT 14/18 EVOLUCIJA HROMOZOMA, MUTACIJA, GENERISANJE NOVIH GENERACIJA - DOMACI MEKO RACUNARSTVO
// PREDMETNI PROFESOR: VLADIMIR BRTKA
// PREDMETNI ASISTENT: IGOR VECSTEJN

//KLASA POPULACIJA KOJA SADRZI NIZOVE HROMOZOMA, HROMOZOME mate1,mate2,child NISAM USPEO DA IMPLEMENTIRAM JOS, TREBA PROSIRITI ALGORITAM
class Population{
    public:
    Chromosome chromosome[10][4];
    Chromosome mate1,mate2,child;
    int max_v=4;
    int min_v=0;
    int j=0;
    int val_indx=0;
    void add_chromosome(Chromosome new_chromosome,int generation,int number){
        this->chromosome[generation][number]=new_chromosome;
    }

    //PROBNA FUNKCIJA ZA NOVI HROMOZOM SLEDECE GENERACIJE, KORISTENO KAO TEST VARIJANTA, MOZE SE IGNORISATI
    void evolve(int generation){
            int evolve_value[4];
            evolve_value[0]=chromosome[generation][0].value[0];
            cout<<"\n"<<evolve_value[0]<<"\n";
            evolve_value[1]=chromosome[generation][0].value[1];
            cout<<evolve_value[1]<<"\n";
            evolve_value[2]=chromosome[generation][1].value[2];
            cout<<evolve_value[2]<<"\n";
            evolve_value[3]=chromosome[generation][1].value[3];
            cout<<evolve_value[3]<<"\n";
            for(int i=0;i<4;i++)
                this->chromosome[1][0].value[i]=evolve_value[i];
    }

        //FUNKCIJA GDE SE PO ORDEDJENOM REDU UKRSTAJU DELOVI HROMOZOMA, I STVARAJU NOVI. SVAKI ODSECAK KODA PREDSTAVLJA JEDAN NOVI HROMOZOM
        void evolve_gen(int generation){

            int evolve_value[4];
            evolve_value[0]=chromosome[generation][0].value[0];
            //cout<<"\n"<<evolve_value[0]<<"\n";
            evolve_value[1]=chromosome[generation][0].value[1];
            //cout<<evolve_value[1]<<"\n";
            evolve_value[2]=chromosome[generation][1].value[2];
            //cout<<evolve_value[2]<<"\n";
            evolve_value[3]=chromosome[generation][1].value[3];
            //cout<<evolve_value[3]<<"\n";
            for(int i=0;i<4;i++)
                this->chromosome[generation+1][0].value[i]=evolve_value[i];


            evolve_value[0]=chromosome[generation][1].value[0];
            //cout<<"\n"<<evolve_value[0]<<"\n";
            evolve_value[1]=chromosome[generation][1].value[1];
            //cout<<evolve_value[1]<<"\n";
            evolve_value[2]=chromosome[generation][2].value[2];
            //cout<<evolve_value[2]<<"\n";
            evolve_value[3]=chromosome[generation][2].value[3];
            //cout<<evolve_value[3]<<"\n";
            for(int i=0;i<4;i++)
                this->chromosome[generation+1][1].value[i]=evolve_value[i];


            evolve_value[0]=chromosome[generation][3].value[0];
           // cout<<"\n"<<evolve_value[0]<<"\n";
            evolve_value[1]=chromosome[generation][3].value[1];
            //cout<<evolve_value[1]<<"\n";
            evolve_value[2]=chromosome[generation][0].value[2];
            //cout<<evolve_value[2]<<"\n";
            evolve_value[3]=chromosome[generation][0].value[3];
            //cout<<evolve_value[3]<<"\n";
            for(int i=0;i<4;i++)
                this->chromosome[generation+1][2].value[i]=evolve_value[i];


            evolve_value[0]=chromosome[generation][2].value[0];
            //cout<<"\n"<<evolve_value[0]<<"\n";
            evolve_value[1]=chromosome[generation][2].value[1];
            //cout<<evolve_value[1]<<"\n";
            evolve_value[2]=chromosome[generation][3].value[2];
            //cout<<evolve_value[2]<<"\n";
            evolve_value[3]=chromosome[generation][3].value[3];
            //cout<<evolve_value[3]<<"\n";
            for(int i=0;i<4;i++)
                this->chromosome[generation+1][3].value[i]=evolve_value[i];
            srand(time(NULL));
            chromosome[generation+1][0].mutation();
            Sleep(500);
            srand(time(NULL));
            Sleep(500);
            Sleep(500);
            chromosome[generation+1][1].mutation();
            chromosome[generation+1][2].mutation();
            Sleep(500);
            chromosome[generation+1][3].mutation();

    }

};

#endif // POPULATION_H_INCLUDED
