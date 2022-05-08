#ifndef CHROMOSOME_H_INCLUDED
#define CHROMOSOME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <iostream>
using namespace std;

class Chromosome{
    public:
    int gen,chromosome_lenght;
    int target[4]={0,1,0,1};
    int value[4];
    int mutated;
    float fitness=0;
    //FUNKCIJA ZA KREIRANJE HROMOZOMA I DODELU VREDNOSTI
    void forge_chromosome(int gen, int chromosome_lenght, int target[]){
        srand(time(NULL));
        this->gen=gen;
        this->chromosome_lenght=chromosome_lenght;
        for(int i=0;i<4;i++){
            this->target[i]=target[i];
            this->value[i]=rand()%2;
        }
    }

    //treba testirati -- OVU FUNKCIJU NISAM KORISTIO, OSTALA JE SAMO KAO IDEJA
    void mate_value(int value[]){
        for(int i=0;i<4;i++)
            this->value[i]=value[i];
    }

    //ISPIS INFORMACIJA O TRENUTNOM HROMOZOMU
    void chromosome_info(){
        cout<<" Chromosome value: ";
        for(int i=0;i<4;i++)
            cout<<value[i];
        cout<<" Chromosome fitness: "<<fitness;
        if(fitness==100){
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //MENJANJE TEKSTA U ZELENU BOJU U KOLIKO JE META PRONADJENA
            SetConsoleTextAttribute(hConsole, 10);
            cout<<" FOUND TARGET!";
            SetConsoleTextAttribute(hConsole, 7);
        }
        if(mutated==1){
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //MENJANJE TEKSTA U CRVENU BOJU U KOLIKO JE GEN HROMOZOMA MUTIRAO
            SetConsoleTextAttribute(hConsole, 4);
            cout<<" MUTATED!";
            SetConsoleTextAttribute(hConsole, 7);
        }

    }

    //PRORACUN FITNESA HROMOZOMA
    void chromosome_fitness(){
        for(int i=0;i<4;i++)
            if(target[i]==value[i])
                fitness+=25;
    }
    //POKRETANJE PROCESA/SANSE ZA MUTACIJU
    void mutation(){
        srand(time(NULL));
        int randomMutationChance=rand()%10;
        int randomGeneMutation;
        int randomMutatedGen;
            if(randomMutationChance==1){
                randomGeneMutation=rand()%4;
                randomMutatedGen=rand()%2;
                this->value[randomGeneMutation]=randomMutatedGen;
                mutated=1;
            }
    }


};

#endif // CHROMOSOME_H_INCLUDED
