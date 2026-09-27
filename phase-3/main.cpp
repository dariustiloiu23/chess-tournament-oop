#include <iostream>
#include <algorithm>
#include "Exceptii.h"
#include "Patterns.h"
#include "Domeniu.h"
#include "Generic.h"
using namespace std;

// Clasa folosita pur pt a demonstra stack unwinding la o exceptie (vedem mesajul din destructor)
class ResursaTest {
public:
    ResursaTest() { cout<<"[ResursaTest] Alocata pe stiva locala\n"; }
    ~ResursaTest() noexcept { cout<<"[ResursaTest] Dealocata automat prin stack unwinding.\n"; }
};

void meniu() {
    cout<<"\n========== MENIU ==========\n";
    cout<<"1. Adauga persoana (Jucator/PRO/Arbitru)\n";
    cout<<"2. Afiseaza doar Jucatori \n";
    cout<<"3. Modifica persoana\n";
    cout<<"4. Sterge persoana\n";
    cout<<"5. Afiseaza doar Arbitri \n";
    cout<<"6. Adauga partida\n";
    cout<<"7. Afiseaza partide\n";
    cout<<"8. Modifica partida\n";
    cout<<"9. Sterge partida\n";
    cout<<"10. Adauga turneu\n";
    cout<<"11. Afiseaza turnee\n";
    cout<<"12. Modifica turneu\n";
    cout<<"13. Sterge turneu\n";
    cout<<"14. Acorda Bonus Rating \n";
    cout<<"15. Filtrare Jucatori \n";
    cout<<"16. Premiere Jucator \n";
    cout<<"17. Afisare Jurnal\n";
    cout<<"18. Testare Exceptie fatala \n";
    cout<<"19. Statistici \n";
    cout<<"0. Iesire\n";
    cout<<"Optiune: ";
}

int main() {
    // Alocare folosind clasa Template
    Depozitar<Persoana, 100> persoane;
    Depozitar<Partida, 100> partide;
    Depozitar<Turneu, 50> turnee;

    // Setare componente Abstract Factory
    FabricaStandard fStandard;
    FabricaVIP fVIP;
    Festivitate festivitate(&fStandard);

    int opt;
    do {
        meniu();
        if(!(cin>>opt)) break;

        // Toate erorile prinse prin blocuri try/catch inlănțuite (nu exista coduri de eroare manuale)
        try {
            if(opt==1) {
                int tip; cout<<"1.Amator 2.Profesionist 3.Arbitru: "; cin>>tip;
                Persoana* p = nullptr;
                if(tip==1) p = new Jucator();
                else if(tip==2) p = new JucatorPro();
                else p = new Arbitru();
                cin>>*p;
                persoane.adauga(p);
            }
            else if(opt==2) {
                for(auto e : persoane.getElemente()) {
                    Jucator* j = dynamic_cast<Jucator*>(e);
                    if(j) {
                        j->afiseazaTip();
                        cout<<*j<<"\n";
                    }
                }
            }
            else if(opt==3) {
                int id; cout<<"ID persoana: "; cin>>id;
                Persoana* p = persoane.gaseste(id);
                cin>>*p;
            }
            else if(opt==4) {
                int id; cout<<"ID persoana de sters: "; cin>>id;
                persoane.sterge(id);
                cout<<"Sters.\n";
            }
            else if(opt==5) {
                for(auto e : persoane.getElemente()) {
                    Arbitru* a = dynamic_cast<Arbitru*>(e);
                    if(a) {
                        a->afiseazaTip();
                        cout<<*a<<"\n";
                    }
                }
            }
            else if(opt==6) {
                Partida* p = new Partida(); cin>>*p; partide.adauga(p);
            }
            else if(opt==7) {
                auto els = partide.getElemente();
                // for_each cu lambda
                for_each(els.begin(), els.end(), [](Partida* p){ cout<<*p<<"\n"; });
            }
            else if(opt==8) {
                int id; cout<<"ID partida: "; cin>>id;
                Partida* p = partide.gaseste(id); cin>>*p;
            }
            else if(opt==9) {
                int id; cout<<"ID partida de sters: "; cin>>id;
                partide.sterge(id); cout<<"Sters.\n";
            }
            else if(opt==10) {
                Turneu* t = new Turneu(); cin>>*t; turnee.adauga(t);
            }
            else if(opt==11) {
                for(auto t : turnee.getElemente()) cout<<*t<<"\n";
            }
            else if(opt==12) {
                int id; cout<<"ID turneu: "; cin>>id;
                Turneu* t = turnee.gaseste(id); cin>>*t;
            }
            else if(opt==13) {
                int id; cout<<"ID turneu de sters: "; cin>>id;
                turnee.sterge(id); cout<<"Sters.\n";
            }
            else if(opt==14) {
                //  dynamic_cast: Vectorul polimorfic retine pointeri de baza (Persoana).
                // Un static_cast ar da Undefined Behavior daca persoana e Arbitru. dynamic_cast verifica la runtime si da nullptr.
                int count=0;
                for(auto p : persoane.getElemente()) {
                    Jucator* j = dynamic_cast<Jucator*>(p);
                    if(j) {
                        float ratingCurent = j->getRating();
                        j->setRating(ratingCurent + 50.0f);
                        count++;
                    }
                }
                cout<<"Bonus acordat pentru "<<count<<" jucatori.\n";
            }
            else if(opt==15) {
                cout<<"Rating minim jucator = "; float minR; cin>>minR;
                persoane.sorteaza();
                // Apel functia template libera
                printeazaFiltrat(persoane.getElemente(), [minR](Persoana* p){
                    Jucator* j = dynamic_cast<Jucator*>(p);
                    return (j && j->getRating() >= minR);
                });
            }
            else if(opt==16) {
                string nume; int tipF;
                cout<<"Nume jucator de premiat: "; cin>>ws; getline(cin, nume);
                cout<<"Tip festivitate (1.Standard / 2.VIP): "; cin>>tipF;
                if(tipF==2) festivitate.setFabrica(&fVIP);
                else festivitate.setFabrica(&fStandard);
                // Apel Abstract Factory
                festivitate.premiazaJucator(nume);
            }
            else if(opt==17) {
                Logger::getInstance().afiseazaLoguri();
            }
            else if(opt==18) {
                cout<<"Introducem un rating -5 ca sa fortam prabusirea in try-catch:\n";
                //  Demonstrare de Stack Unwinding
                ResursaTest rt;
                Jucator test("Gigel", -5);
            }
            else if(opt==19) {
                auto& pers = persoane.getElemente();
                //  count_if cu lambda
                int nrJucatoriBuni = count_if(pers.begin(), pers.end(), [](Persoana* p){
                    Jucator* j = dynamic_cast<Jucator*>(p);
                    return j && j->getRating() > 1500;
                });
                //  any_of cu lambda
                bool existaVIP = any_of(pers.begin(), pers.end(), [](Persoana* p){
                    JucatorPro* jp = dynamic_cast<JucatorPro*>(p);
                    return jp != nullptr;
                });
                cout<<"Statistici:\n- Jucatori cu rating > 1500: "<<nrJucatoriBuni<<"\n- Exista profesionisti in sistem? "<<(existaVIP?"Da":"Nu")<<"\n";
            }
            else if(opt!=0) {
                cout<<"Optiune invalida!\n";
            }
        }
        // Catch-uri multiple prinzand de la specific la general
        catch(const ValidareException& e) {
            cout<<"[EROARE VALIDARE] "<<e.what()<<" | Valoare refuzata: "<<e.getValoare()<<"\n";
        }
        catch(const NotFoundException& e) {
            cout<<"[EROARE CAUTARE] "<<e.what()<<" | ID-ul cautat: "<<e.getId()<<"\n";
        }
        catch(const SahException& e) {
            cout<<"[EROARE SAH] "<<e.what()<<"\n";
        }
        catch(const exception& e) {
            cout<<"[EROARE FATALA] "<<e.what()<<"\n";
        }

    } while(opt!=0);

    return 0;
}