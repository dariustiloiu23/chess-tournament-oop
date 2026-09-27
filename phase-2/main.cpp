#include <iostream>
#include <cstring>
#include "Data.h"
#include "Persoana.h"
#include "Jucator.h"
#include "JucatorPro.h"
#include "Arbitru.h"
#include "Partida.h"
#include "Turneu.h"
using namespace std;

int cautaPersoana(Persoana* v[],int n,int id) {
    for(int i=0;i<n;i++)
        if(v[i]->getId()==id)
            return i;
    return -1;
}
int cautaPartida(Partida v[],int n,int id) {
    for(int i=0;i<n;i++)
        if(v[i].getId()==id)
            return i;
    return -1;
}

int cautaTurneu(Turneu v[],int n,int id) {
    for(int i=0;i<n;i++)
        if(v[i].getId()==id)
            return i;
    return -1;
}

void meniu() {
    cout<<"\n========== MENIU ==========\n";
    cout<<"1.Adauga persoana (Jucator/Arbitru/Profesionist)\n";
    cout<<"2.Afiseaza doar Jucatori\n";
    cout<<"3.Modifica persoana\n";
    cout<<"4.Sterge persoana\n";
    cout<<"5.Afiseaza doar Arbitri\n";
    cout<<"6.Adauga partida\n";
    cout<<"7.Afiseaza partide\n";
    cout<<"8.Modifica partida\n";
    cout<<"9.Sterge partida\n";
    cout<<"10.Adauga turneu\n";
    cout<<"11.Afiseaza turnee\n";
    cout<<"12.Modifica turneu\n";
    cout<<"13.Sterge turneu\n";
    cout<<"14.Acorda Rating bonus Jucatori\n";
    cout<<"15.Demo\n";
    cout<<"0.Iesire\n";
    cout<<"Optiune: ";
}

int main() {
    const int MAX_PERSOANE=100;
    const int MAX_PARTIDE=100;
    const int MAX_TURNEE=50;

    //Vector de pointeri la baza
    Persoana* persoane[MAX_PERSOANE];
    Partida partide[MAX_PARTIDE];
    Turneu turnee[MAX_TURNEE];

    int nrPersoane=0;
    int nrPartide=0;
    int nrTurnee=0;
    int op;

    do {
        meniu();
        cin>>op;
        if(op==1) {
            if(nrPersoane<MAX_PERSOANE) {
                int tip;
                cout<<"Alege tipul (1.Amator 2.Profesionist 3.Arbitru): ";
                cin>>tip;
                if(tip==1) {
                    persoane[nrPersoane]=new Jucator();
                }
                else if(tip==2) {
                    persoane[nrPersoane]=new JucatorPro();
                }
                else {
                    persoane[nrPersoane]=new Arbitru();
                }
                cin>>*persoane[nrPersoane];
                nrPersoane++;
            } else {
                cout<<"Nu mai este loc pentru persoane\n";
            }
        }
        else if(op==2) {
            if(nrPersoane==0)
                cout<<"Nu exista persoane in sistem\n";
            for(int i=0;i<nrPersoane;i++) {
                Jucator* j = dynamic_cast<Jucator*>(persoane[i]);
                if(j!=nullptr) {
                    cout<<"\n--- Jucator "<<i+1<<" ---\n";
                    persoane[i]->afiseazaTip();
                    cout<<*persoane[i];
                }
            }
        }
        else if(op==3) {
            int id,p;
            cout<<"ID persoana: ";
            cin>>id;
            p=cautaPersoana(persoane,nrPersoane,id);
            if(p!=-1)
                cin>>*persoane[p];
            else
                cout<<"Nu exista\n";
        }
        else if(op==4) {
            int id,p;
            cout<<"ID persoana: ";
            cin>>id;
            p=cautaPersoana(persoane,nrPersoane,id);
            if(p!=-1) {
                delete persoane[p];
                for(int i=p;i<nrPersoane-1;i++)
                    persoane[i]=persoane[i+1];
                nrPersoane--;
                cout<<"Persoana stearsa cu succes.\n";
            } else {
                cout<<"Nu exista\n";
            }
        }
        else if(op==5) {
            if(nrPersoane==0)
                cout<<"Nu exista persoane in sistem\n";
            for(int i=0;i<nrPersoane;i++) {
                Arbitru* a = dynamic_cast<Arbitru*>(persoane[i]);
                if(a!=nullptr) {
                    cout<<"\n--- Arbitru "<<i+1<<" ---\n";
                    persoane[i]->afiseazaTip();
                    cout<<*persoane[i];
                }
            }
        }
        else if(op==6) {
            if(nrPartide<MAX_PARTIDE) {
                cin>>partide[nrPartide];
                nrPartide++;
            } else {
                cout<<"Nu mai este loc pentru partide\n";
            }
        }
        else if(op==7) {
            if(nrPartide==0)
                cout<<"Nu exista partide.\n";
            for(int i=0;i<nrPartide;i++) {
                cout<<"\nPartida "<<i+1<<":\n";
                cout<<partide[i];
            }
        }
        else if(op==8) {
            int id,p;
            cout<<"ID partida: ";
            cin>>id;
            p=cautaPartida(partide,nrPartide,id);
            if(p!=-1)
                cin>>partide[p];
            else
                cout<<"Nu exista\n";
        }
        else if(op==9) {
            int id,p;
            cout<<"ID partida: ";
            cin>>id;
            p=cautaPartida(partide,nrPartide,id);
            if(p!=-1) {
                for(int i=p;i<nrPartide-1;i++)
                    partide[i]=partide[i+1];
                nrPartide--;
            } else {
                cout<<"Nu exista.\n";
            }
        }
        else if(op==10) {
            if(nrTurnee<MAX_TURNEE) {
                cin>>turnee[nrTurnee];
                nrTurnee++;
            } else {
                cout<<"Nu mai este loc pentru turnee.\n";
            }
        }
        else if(op==11) {
            if(nrTurnee==0)
                cout<<"Nu exista turnee\n";
            for(int i=0;i<nrTurnee;i++) {
                cout<<"\nTurneul "<<i+1<<":\n";
                cout<<turnee[i];
            }
        }
        else if(op==12) {
            int id,p;
            cout<<"ID turneu: ";
            cin>>id;
            p=cautaTurneu(turnee,nrTurnee,id);
            if(p!=-1)
                cin>>turnee[p];
            else
                cout<<"Nu exista.\n";
        }
        else if(op==13) {
            int id,p;
            cout<<"ID turneu: ";
            cin>>id;
            p=cautaTurneu(turnee,nrTurnee,id);
            if(p!=-1) {
                for(int i=p;i<nrTurnee-1;i++)
                    turnee[i]=turnee[i+1];
                nrTurnee--;
            } else {
                cout<<"Nu exista.\n";
            }
        }
        else if(op==14) {
            /* Folosesc dynamic_cast, deoarece vectorul 'persoane' contine Jucatori, JucatoriPro si Arbitri.
               Daca as folosi static_cast pentru a forta conversia unui Arbitru in Jucator, compilatorul m ar lasa,
               dar as primi Undefined Behavior la rulare cnd as apela metode din Jucator pe el.
               dynamic_cast verifica tipul la runtime (RTTI) si returneaza nullptr daca obiectul nu este Jucator */
            int count=0;
            cout<<"\nSe adauga 50 pct bonus doar la jucatorii din sistem..\n";
            for(int i=0;i<nrPersoane;i++) {
                Jucator* j = dynamic_cast<Jucator*>(persoane[i]);
                if(j!=nullptr) {
                    *j = *j + 50.0f;
                    cout<<"Bonus adaugat pentru: "<<j->getNume()<<"\n";
                    count++;
                }
            }
            if(count==0) {
                cout<<"Nu a fost gasit niciun jucator in sistem.\n";
            }
        }
        else if(op==15) {
            Jucator j1(1,"Darius",1700,true,'X',2006);
            Jucator j2("Magnus",2800);
            Jucator j3=j1+50;
            Arbitru a1(1,"Ionescu",5,true,'A',2018);
            Partida p1(1,10,20,"1/2-1/2",4.5,true,'C',200);
            Turneu t1;
            t1.setId(1);
            t1.setNume("Open Bucuresti");
            t1.adaugaParticipant(10);
            t1.adaugaParticipant(20);
            cout<<"\n=== DEMO ===\n";
            cout<<"j1:\n"<<j1;
            cout<<"j2:\n"<<j2;
            cout<<"j3=j1+50:\n"<<j3;
            ++j1;
            cout<<"Dupa ++j1:\n"<<j1;
            cout<<"j1[0]="<<j1[0]<<"\n";
            cout<<"(j1==j2)="<<(j1==j2)<<"\n";
            cout<<"(j2>j1)="<<(j2>j1)<<"\n\n";
            cout<<"Arbitru demo:\n"<<a1;
            cout<<"Partida demo:\n"<<p1;
            cout<<"Turneu demo:\n"<<t1;
        }
        else if(op!=0) {
            cout<<"Optiune invalida.\n";
        }
    } while(op!=0);

    // dezalocare memorie si verificare pt nullptr
    for(int i=0;i<nrPersoane;i++) {
        if(persoane[i]!=nullptr) {
            delete persoane[i];
            persoane[i]=nullptr;
        }
    }
    return 0;
}