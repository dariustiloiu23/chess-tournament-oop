#include "Patterns.h"

// Implementare Singleton
Logger& Logger::getInstance() { static Logger instanta; return instanta; }
void Logger::log(const string& msg) { loguri.push_back(msg); }
void Logger::afiseazaLoguri() const {
    cout<<"\n--- Jurnal Sistem (Singleton Logger) ---\n";
    for(const auto& l : loguri) cout<<l<<"\n";
    cout<<"----------------------------------------\n";
}

// Implementare Factory
string PremiuStandard::descriere() const { return "Medalie Standard"; }
string DiplomaStandard::text() const { return "Diploma Participare"; }
string PremiuVIP::descriere() const { return "Trofeu Aur VIP"; }
string DiplomaVIP::text() const { return "Diploma Excelenta VIP"; }

IPremiu* FabricaStandard::crearePremiu() const { return new PremiuStandard(); }
IDiploma* FabricaStandard::creareDiploma() const { return new DiplomaStandard(); }
IPremiu* FabricaVIP::crearePremiu() const { return new PremiuVIP(); }
IDiploma* FabricaVIP::creareDiploma() const { return new DiplomaVIP(); }

Festivitate::Festivitate(IFabricaFestivitate* f):fabrica(f) {}
void Festivitate::setFabrica(IFabricaFestivitate* f) { fabrica=f; }
void Festivitate::premiazaJucator(const string& nume) {
    IPremiu* p = fabrica->crearePremiu();
    IDiploma* d = fabrica->creareDiploma();
    istoricPremii[nume]++; // map-ul aloca si incrementeaza automat
    cout<<"\n*** PREMIERE "<<nume<<" (Premiul nr. "<<istoricPremii[nume]<<") ***\n"<<p->descriere()<<"\n"<<d->text()<<"\n*******************\n";
    delete p; delete d;
}