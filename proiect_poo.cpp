#include <iostream>
#include <cstring>
using namespace std;


class Rezervor {
    private:
        float capacitate;
        float nivel_combustibil;

    public:
        Rezervor() {
            capacitate = 0.0;
            nivel_combustibil = 0.0;
        }
        Rezervor(float c, float nvl) {
            capacitate = c;
            nivel_combustibil = nvl;
        }
        ///constructorul de copiere explicit
        Rezervor(const Rezervor& r) {
            capacitate = r.capacitate;
            nivel_combustibil = r.nivel_combustibil;
        }
        ////supraincarcarea operatorului =
        Rezervor& operator=(const Rezervor& r) {
            capacitate = r.capacitate;
            nivel_combustibil = r.nivel_combustibil;
            return *this;
        }

        float getCapacitate() const {
            return capacitate;
        }

        float getNivelCombustibil() const {
            return nivel_combustibil;
        }

        void setCapacitate(float c){
            capacitate=c;
        }
        void setNivelCombustibil(float nvl_c){
            nivel_combustibil=nvl_c;
        }

        void addCombustibil(float cantitate) {
            if (nivel_combustibil + cantitate > capacitate) {
                nivel_combustibil = capacitate;
            } else {
                nivel_combustibil += cantitate;
            }
        }
        ///supraincarcarea operatorilor << si >>
        friend ostream& operator<<(ostream& out, const Rezervor& r);
        friend istream& operator>>(istream& in, Rezervor& r);
};
ostream& operator<<(ostream& out, const Rezervor & r) {
    out << "Capacitate: " << r.getCapacitate() << endl;
    out << "Nivelul combustibilului: " << r.getNivelCombustibil() << endl;

    return out;
}
istream& operator>>(istream& in, Rezervor& r){
    in>>r.capacitate>>r.nivel_combustibil;
    return in;
}

class Motor {
    private:
        int putere;
        float consum_combustibil;
        bool este_pornit;

    public:
        Motor() {
            putere = 0;
            consum_combustibil = 0.0;
            este_pornit=false;
        }
        Motor(int p, float cc, bool ep) {
            putere = p;
            consum_combustibil = cc;
            este_pornit = ep;
        }

        ///constructorul de copiere explicit
        Motor(const Motor& m) {
            putere = m.putere;
            consum_combustibil = m.consum_combustibil;
            este_pornit = m.este_pornit;
        }

        ////supraincarcarea operatorului =
        Motor& operator=(const Motor& m) {
            putere = m.putere;
            consum_combustibil = m.consum_combustibil;
            este_pornit = m.este_pornit;
            return *this;
        }

        int getPutere() {
            return putere;
        }

        float getConsumCombustibil() {
            return consum_combustibil;
        }

        bool getEstePornit() const{
            return este_pornit;
        }
        void setPutere(int p){
            putere=p;
        }
        void setConsumCombustibil(float cc){
            consum_combustibil=cc;
        }
        void setEstePornit(bool ep){
            este_pornit=ep;
        }

        void start() {
            este_pornit = true;
        }

        void stop() {
            este_pornit = false;
        }
        /// supraincarcarea operatorilor << si >>
        friend ostream& operator<<(ostream& out, const Motor& m);
        friend istream& operator>>(istream& in, Motor& m);
};

ostream& operator<<(ostream& out, const Motor& m){
    out<<"Puterea motorului: "<<m.putere<<"\n";
    out<<"Consumul: "<<m.consum_combustibil<<"\n";
    out<<"Motorul "<<(m.este_pornit ? "este " : "nu este ")<<"pornit";
    out<<"\n";
    return out;
}
istream& operator>>(istream& in, Motor& m){
    in>>m.putere>>m.consum_combustibil>>m.este_pornit;
    return in;
}

class Motocicleta {
    private:
        float kilometraj;
        char numar_inmatriculare[50];
        char marca[50];
        char model[50];
        char stare[50];
        int an;
        Rezervor rezervor;
        Motor motor;

    public:
        Motocicleta() :
            an(0),
            kilometraj(0.0) {
            strcpy(numar_inmatriculare, "");
            strcpy(marca, "");
            strcpy(model, "");
            strcpy(stare, "");
            Rezervor();
            Motor();
        }
        Motocicleta(float k, const char* nr, const char* m, const char* md, const char* st, int a, Rezervor r, Motor mot) :
            an(a),
            kilometraj(k) {
            motor=mot;
            rezervor=r;
            strcpy(numar_inmatriculare, nr);
            strcpy(marca, m);
            strcpy(model, md);
            strcpy(stare, st);
        }

        ///constructor de copiere explicit
        Motocicleta(const Motocicleta& m) :
            an(m.an),
            rezervor(m.rezervor),
            motor(m.motor),
            kilometraj(m.kilometraj) {
            strcpy(numar_inmatriculare, m.numar_inmatriculare);
            strcpy(marca, m.marca);
            strcpy(model, m.model);
            strcpy(stare, m.stare);
        }
        ///supraincarcarea operatorului =
        Motocicleta& operator=(const Motocicleta& m);

        float getKilometraj() const {
            return kilometraj;
        }
        const char* getNumarInmatriculare() const{
            return numar_inmatriculare;
        }
        const char* getModel() const{
            return model;
        }
        const char* getMarca() const{
            return marca;
        }

        bool getStare() const{
            return motor.getEstePornit();
        }

        int getAn() const {
            return an;
        }


        void setKilometraj(float km){
            kilometraj=km;
        }
        void setNumarInmatriculare(char nr[50]){
            strcpy(numar_inmatriculare,nr);
        }
        void setModel(char md[50]){
            strcpy(model,md);
        }
        void setMarca(char mc[50]){
            strcpy(marca,mc);
        }
        void setAn(int a){
            an=a;
        }
        void setMotor(int p, float cc, bool ep){
            motor.setPutere(p);
            motor.setConsumCombustibil(cc);
            motor.setEstePornit(ep);
        }
        void setRezervor(float c, float nvl_c){
            rezervor.setCapacitate(c);
            rezervor.setNivelCombustibil(nvl_c);
        }

        void pornire() {
            motor.start();
        }

        void oprire() {
            motor.stop();
        }

        void alimenteaza(float cantitate){
            rezervor.addCombustibil(cantitate);
        }
        void drive(float distanta) {
            if (motor.getEstePornit()) {
                if (rezervor.getNivelCombustibil()>= distanta/50.0) {
                    kilometraj += distanta;
                    rezervor.addCombustibil(-distanta/50.0);
                }
                    else {
                        cout << "Nu exista suficient combustibil pentru a efectua deplasarea!" <<"\n";
                    }
            }
        }
        ///supraincarcarea operatorilor << si >>
        friend ostream& operator<<(ostream& out, const Motocicleta& m);
        friend istream& operator>>(istream& in, Motocicleta& m);
};
Motocicleta& Motocicleta::operator=(const Motocicleta& m) {
    if (this != &m) {
        kilometraj = m.kilometraj;
        strcpy(numar_inmatriculare, m.numar_inmatriculare);
        strcpy(marca, m.marca);
        strcpy(model, m.model);
        strcpy(stare, m.stare);
        motor = m.motor;
        rezervor = m.rezervor;
    }
    return *this;
}
ostream& operator<<(ostream& out, const Motocicleta& m) {
    out << "Numar de inmatriculare: " << m.getNumarInmatriculare() <<"\n";
    out << "Marca: " << m.getMarca() <<"\n";
    out << "Model: " << m.getModel() <<"\n";
    out << "An: " << m.getAn() << "\n";
    out << "Stare: " << m.getStare() << "\n";
    out << "Kilometraj: " << m.getKilometraj() << "\n";
    out << "\nInformatii rezervor:\n";
    out << m.rezervor << "\n";
    out<<"Informtii motor:\n";
    out<<m.motor<<"\n";

    return out;
}

istream& operator>>(istream& in, Motocicleta& m)
{
    float km; int a; char nr[50],mc[50],st[50],md[50];
    ///variabile pt motor
    int p; float cc; bool ep;
    ///variabile pt rezervor
    float c,nvl_c;
    cout<<"Dati kilometrajul: "; in >>km;
    cout<<"Dati modelul: "; in>>md;
    cout<<"Dati numarul de inmatriculare: "; in>>nr;
    cout<<"Dati marca: "; in>>mc;
    cout<<"Dati anul: "; in>>a;
    cout<<"Dati informatiile motorului\n";
    cout<<"Dati puterea motorului: "; in>>p;
    cout<<"Dati consumul: "; in>>cc;
    cout<<"Precizati daca este pornit sau nu: "; in>>ep;
    cout<<"Dati informatiile rezervorului\n";
    cout<<"Dati capacitatea: "; in>>c;
    cout<<"Dati nivelul combustiblului: "; in>>nvl_c;
    m.setKilometraj(km);
    m.setModel(md);
    m.setNumarInmatriculare(nr);
    m.setMarca(mc);
    m.setAn(a);
    m.setMotor(p,cc,ep);
    m.setRezervor(c,nvl_c);
    return in;
}



class Intretinere {
    private:
        int id;
        float cost;
        char* nume;
        char* numar_inmatriculare;
        char* data;

    public:
        Intretinere() : id(0), cost(0), nume(nullptr), numar_inmatriculare(nullptr), data(nullptr){}

        Intretinere(int i, float ct, char* n, char *nr_inm, char *dt): nume(n), numar_inmatriculare(nr_inm), data(dt){
            id=i;
            cost=ct;
        }
        void setID(int i_d){
            id=i_d;
        }
        void setCost(float c){
            cost=c;
        }
        void setNume(char n[50]){
            nume = new char[strlen(n) + 1];
            strcpy_s(nume, strlen(n) + 1, n);
        }
        void setNumarInmatriculare(char nr_inm[50]){
            numar_inmatriculare = new char[strlen(nr_inm) + 1];
            strcpy_s(numar_inmatriculare, strlen(nr_inm) + 1, nr_inm);
        }
        void setData(char dt[50]){
            data = new char[strlen(dt) + 1];
            strcpy_s(data, strlen(dt) + 1, dt);
        }
        int getID(){
            return id;
        }
        float getCost(){
            return cost;
        }
        char* getNumarInmatriculare(){
            return numar_inmatriculare;
        }
        char* getData(){
            return data;
        }

        //constructorul de mutare
        Intretinere(Intretinere&& i){
            id=i.id;
            cost=i.cost;
            nume=i.nume;
            i.nume=NULL;
            i.cost=i.id=0;
            numar_inmatriculare=i.numar_inmatriculare;
            i.numar_inmatriculare=NULL;
            data=i.data;
            i.data=NULL;
        }

        // constructorul explicit de copiere
        Intretinere(const Intretinere& i){
            id=i.id;
            cost=i.cost;
            nume = new char[strlen(i.nume) + 1];
            strcpy_s(nume, strlen(i.nume) + 1, i.nume);
            numar_inmatriculare = new char[strlen(i.numar_inmatriculare) + 1];
            strcpy_s(numar_inmatriculare, strlen(i.numar_inmatriculare) + 1, i.numar_inmatriculare);
            data = new char[strlen(i.data) + 1];
            strcpy_s(data, strlen(i.data) + 1, i.data);
        }

        // supraincarcarea operatorului =
        Intretinere& operator=(const Intretinere& i) {
            if (this != &i) {
                id = i.id;
                cost = i.cost;
                if(nume!=NULL) delete[] nume;
                nume = nullptr;
                if (i.nume != nullptr) {
                    nume = new char[strlen(i.nume) + 1];
                    strcpy_s(nume, strlen(i.nume) + 1, i.nume);
                    }

                if(numar_inmatriculare!=NULL) delete[] numar_inmatriculare;
                numar_inmatriculare = nullptr;
                if (i.numar_inmatriculare != nullptr) {
                    numar_inmatriculare = new char[strlen(i.numar_inmatriculare) + 1];
                    strcpy_s(numar_inmatriculare, strlen(i.numar_inmatriculare) + 1, i.numar_inmatriculare);
                    }

                if(data!=NULL) delete[] data;
                data = nullptr;
                if (i.data != nullptr) {
                    data = new char[strlen(i.data) + 1];
                    strcpy_s(data, strlen(i.data) + 1, i.data);
                    }
            }
            return *this;
        }
        // supraincarcarea operatorului de mutare
        Intretinere& operator=(const Intretinere&& i) {
            if (this != &i) {
                id = i.id;
                cost = i.cost;
                if(nume!=NULL) delete[] nume;
                nume = nullptr;
                if (i.nume != nullptr) {
                    nume = new char[strlen(i.nume) + 1];
                    strcpy_s(nume, strlen(i.nume) + 1, i.nume);
                    }

                if(numar_inmatriculare!=NULL) delete[] numar_inmatriculare;
                numar_inmatriculare = nullptr;
                if (i.numar_inmatriculare != nullptr) {
                    numar_inmatriculare = new char[strlen(i.numar_inmatriculare) + 1];
                    strcpy_s(numar_inmatriculare, strlen(i.numar_inmatriculare) + 1, i.numar_inmatriculare);
                    }

                if(data!=NULL) delete[] data;
                data = nullptr;
                if (i.data != nullptr) {
                    data = new char[strlen(i.data) + 1];
                    strcpy_s(data, strlen(i.data) + 1, i.data);
                    }
            }
            if(i.nume!=NULL) delete[] i.nume;
            if(i.numar_inmatriculare!=NULL) delete[] i.numar_inmatriculare;
            if(i.data!=NULL) delete[] i.data;
            return *this;
        }

        ~Intretinere() {
            if(nume!=NULL)delete[] nume;
            if(numar_inmatriculare!=NULL)delete[] numar_inmatriculare;
            if(data!=NULL) delete[] data;

        }

        ///supraincarcare operatorilor << si >>
        friend ostream& operator<<(ostream& out, const Intretinere& i);
        friend istream& operator>>(istream& in, Intretinere& i);

};

ostream& operator<<(ostream& out, const Intretinere& i){
    out<<"Detalii intretinere:\n";
    out<<"Are id-ul: "<<i.id;
    out<<"\nA costat: "<<i.cost;
    out<<"\nAre numele: "<<i.nume;
    out<<"\nApartine motocicletei cu numarul de inmatriculare: "<<i.numar_inmatriculare;
    out<<"\nA fost facuta la data de: "<<i.data;
    return out;
}
istream& operator>>(istream& in, Intretinere& i){
    int i_d; float c; char n[50];  char nr_inm[50]; char dt[50];
    cout<<"Dati id-ul: "; in>>i_d;
    cout<<"Dati costul: "; in>>c;
    cout<<"Dati numele: "; in>>n;
    cout<<"Dati numarul de inmatriculare al motocicletei pentru care se face intretinerea: "; in>>nr_inm;
    cout<<"Dati data la care se face intretinerea: "; in>>n;
    i.setID(i_d);
    i.setCost(c);
    i.setNume(n);
    i.setNumarInmatriculare(nr_inm);
    i.setData(dt);
}

class GPS {
    private:
        float longitudine;
        float latitudine;

    public:
        GPS(float lo, float la) {
            longitudine = lo;
            latitudine = la;
        }

        ///constructorul de copiere explicit
        GPS(const GPS& g) {
            longitudine = g.longitudine;
            latitudine = g.latitudine;
        }
        ////supraincarcarea operatorului =
        GPS& operator=(const GPS& g) {
            longitudine = g.longitudine;
            latitudine = g.latitudine;
            return *this;
        }

        float getLongitudine() {
            return longitudine;
        }

        float getLatitudine() {
            return latitudine;
        }

        void actualizareLocatie(float lo, float la) {
            longitudine = lo;
            latitudine = la;
        }
};


class Odometru {
    private:
        float distanta;

    public:
        Odometru(float d) {
            distanta = d;
        }

        float getDistanta() {
            return distanta;
        }

        void actualizeazaDistanta(float d) {
            distanta += d;
        }
};

class Vitezometru {
    private:
        float viteza;

    public:
        Vitezometru(float v) {
            viteza = v;
        }

        float getViteza() {
            return viteza;
        }

        void actualizeazaViteza(float v) {
            viteza = v;
        }
};
class Faruri {
    private:
        int numar_faruri;
        char tip_faruri[50];
        bool stanga;
        bool dreapta;
    public:
        Faruri(){
            numar_faruri=0;
            strcpy(tip_faruri,"");
            stanga=dreapta=false;
        }
        Faruri(int nr, char* tip, bool st, bool dr) {
            numar_faruri=nr;
            strcpy(tip_faruri, tip);
            stanga=st;
            dreapta=dr;
        }
        int getNumarFaruri() const{
            return numar_faruri;
        }
        char* getTipFaruri(){
            return tip_faruri;
        }
        bool getStanga() {
            return stanga;
        }
        bool getDreapta() {
            return dreapta;
        }

        void aprinde() {
            stanga=dreapta = true;
        }

        void stinge() {
            stanga=dreapta = false;
        }


        //supraincarea operatorilor << si >>
        friend ostream& operator<<(ostream& out, const Faruri& f);
        friend istream& operator>>(istream& in, Faruri& f);
};

ostream& operator<<(ostream& out, const Faruri& f){
    out<<"Detalii despre faruri\n";
    out<<"Numar: "<<f.numar_faruri;
    out<<"\nTipul farurilor: "<<f.tip_faruri;
    out<<"\nFarul din stanga este: "<<(f.stanga ? "deschis " : "inchis ");
    out<<"\nFarul din dreapta este: "<<(f.dreapta ? "deschis " : "inchis ");
}
istream& operator>>(istream& in, Faruri& f){
    cout<<"Dati numarul de faruri: "; in>>f.numar_faruri;
    cout<<"Dati tipul farurilor: "; in>>f.tip_faruri;
    cout<<"Dati starea farului din stanga(0-inchis,1-deschis): "; in>>f.stanga;
    cout<<"Dati starea farului din dreapta(0-inchis,1-deschis): "; in>>f.dreapta;
}
class Frana {
    private:
        bool este_apasata;
    public:
        Frana(){
            este_apasata=false;
        }
        Frana(bool ea) {
            este_apasata = ea;
        }
        bool esteApasata() {
            return este_apasata;
        }
        void apasa() {
            este_apasata = true;
        }
        void elibereaza() {
            este_apasata = false;
        }

        ///supraincarcarea opearatorilor << si >>
        friend ostream& operator<<(ostream& out, const Frana& f);
        friend istream& operator>>(istream& in, Frana& f);
};
ostream& operator<<(ostream& out, const Frana& f){
    out<<"Frana "<<(f.este_apasata ? "este " : "nu este ")<<"apasata!";
    return out;
}
istream& operator>>(istream& in, Frana& f){
    in>>f.este_apasata;
    return in;
}
class Utilizator{
    private:
        char user[50];
        char nume[50];
        char prenume[50];
        int varsta;
        char data_nasterii[50];
        int nr_motociclete;
        int nr_intretineri;
        Motocicleta* motociclete;
        Intretinere* intretineri;
    public:
        Utilizator(){
            strcpy(user,"");
            strcpy(nume,"");
            strcpy(prenume,"");
            varsta=0;
            strcpy(data_nasterii,"");
            nr_motociclete=nr_intretineri=0;
            motociclete=NULL;
            intretineri=NULL;
        }
        Utilizator(char u[], char n[], char p[], int v, char dn[], int nr_m, int nr_intr, Motocicleta* moto, Intretinere* intr){
            strcpy(user,u);
            strcpy(nume, n);
            strcpy(prenume, p);
            varsta=v;
            strcpy(data_nasterii,dn);
            nr_motociclete=nr_m;
            nr_intretineri=nr_intr;
            motociclete=new Motocicleta[nr_motociclete];
            for(int i=0; i<nr_motociclete; i++)
                motociclete[i]=moto[i];
            intretineri=new Intretinere[nr_intretineri];
            for(int i=0; i<nr_intretineri; i++)
                intretineri[i]=intr[i];
        }
        void AfiseazaMotociclete(){
            for(int i=0; i<nr_motociclete; i++)
                cout<<motociclete[i]<<"\n\n";
        }
        void AfiseazaIntretineri(){
            for(int i=0; i<nr_intretineri; i++)
                cout<<intretineri[i]<<"\n\n";
        }
        void AdaugaMotocicleta_Citita(){
            Motocicleta moto;
            cin>>moto;
            nr_motociclete++;
            Motocicleta* motociclete_nou;
            motociclete_nou= new Motocicleta[nr_motociclete];
            for(int i=0; i<nr_motociclete-1; i++)
                motociclete_nou[i]=motociclete[i];
            motociclete_nou[nr_motociclete-1]=moto;
            if(motociclete!=NULL)
                delete[] motociclete;
            motociclete=motociclete_nou;
        }
        void AdaugaIntretinere(Intretinere intr){
            nr_intretineri++;
            Intretinere* intretineri_nou;
            intretineri_nou= new Intretinere[nr_intretineri];
            for(int i=0; i<nr_intretineri-1; i++)
                intretineri_nou[i]=intretineri[i];
            intretineri_nou[nr_intretineri-1]=intr;
            if(intretineri!=NULL)
                delete[] intretineri;
            intretineri=intretineri_nou;
        }
        void AdaugaMotocicleta(Motocicleta moto){
            nr_motociclete++;
            Motocicleta* motociclete_nou;
            motociclete_nou= new Motocicleta[nr_motociclete];
            for(int i=0; i<nr_motociclete-1; i++)
                motociclete_nou[i]=motociclete[i];
            motociclete_nou[nr_motociclete-1]=moto;
            if(motociclete!=NULL)
                delete[] motociclete;
            motociclete=motociclete_nou;
        }
        void AdaugaIntretinere_Citita(){
            Intretinere intr;
            cin>>intr;
            nr_intretineri++;
            Intretinere* intretineri_nou;
            intretineri_nou= new Intretinere[nr_intretineri];
            for(int i=0; i<nr_intretineri-1; i++)
                intretineri_nou[i]=intretineri[i];
            intretineri_nou[nr_intretineri-1]=intr;
            if(intretineri!=NULL)
                delete[] intretineri;
            intretineri=intretineri_nou;
        }

        int NrMotociclete_din_Marca(char marca[50]){
            int ct=0;
            for(int i=0; i<nr_motociclete; i++)
                if(strcmp(marca, motociclete[i].getMarca())==0) ct++;
            return ct;
        }
        float CostMediu_pentru_Reparatii(){
            float medie=0;
            for(int i=0; i<nr_intretineri; i++)
                medie=medie+intretineri[i].getCost();
            medie=(float)medie/nr_intretineri;
            return medie;
        }
        float CostTotal_pentru_reparatii(){
            float cost=0;
            for(int i=0; i<nr_intretineri; i++)
                cost=cost+intretineri[i].getCost();
            return cost;
        }

        ///supraincarcarea operatorilor << si >>
        friend ostream& operator<<(ostream& out, const Utilizator& u);
        friend istream& operator>>(istream& in, Utilizator& u);

};
ostream& operator<<(ostream& out, const Utilizator& u){
    out<<"Informatii utilizator\n";
    out<<"Userul tau este "<<u.user;
    out<<"\nNumele: "<<u.nume;
    out<<"\nPrenumele: "<<u.prenume;
    out<<"\nVarsta: "<<u.varsta;
    out<<"\nData nasterii: "<<u.data_nasterii;
    out<<"\nNumar motociclete personale: "<<u.nr_motociclete;
    out<<"\nNumar total intretineri parcurse: "<<u.nr_intretineri;
    return out;
}
istream& operator>>(istream& in, Utilizator& u){
    cout<< "Introduceti userul: "; in>>u.user;
    cout<<"Dati numele utilizatorului: "; in>>u.nume;
    cout<<"Dati prenumele utilizatorului: "; in>>u.prenume;
    cout<<"Dati varsta: "; in>>u.varsta;
    cout<<"Introduceti data nasterii: "; in>>u.data_nasterii;
    return in;
}
int main()
{
    Rezervor rezervor;
    Motor motor;
    Utilizator u;
    Intretinere i;

    //Introducerea utilizatorului in aplicatie
    cin>>u;
    //Exemplu input: Utilizator u("ionpopescu07", "Popescu", "Ion", 35, "17.02.1988");

    //Introducem doua
    Motocicleta m1(0, "B-123-ABC", "BMW", "S1000RR", "noua", 2022, Rezervor(15, 7.5), Motor(100, 6, false));
    Motocicleta m2(25000, "CJ-01-YYY", "Yamaha", "YZF-R125", "utilizata", 2015, Rezervor(10, 10), Motor(50, 5, true));

    //Actiuni pentru motocicleta m1
    m1.alimenteaza(5);
    m1.pornire();
    m1.drive(20.0);

    //Adauga cele doua motociclete in lista utilizatorului u
    u.AdaugaMotocicleta(m1);
    u.AdaugaMotocicleta(m2);

    Intretinere i1(1, 120.50, "Schimb_ulei_si_filtre","B-123-ABC", "30.01.2022");
    Intretinere i2(2, 50.00, "Reglaj_carburator","CJ-01-YYY", "12.12.2022");

    //Adauga cele doua intretineri in lista utilizatorului u
    u.AdaugaIntretinere(i1);
    u.AdaugaIntretinere(i2);

    //u.AdaugaMotocicleta_Citita();
    ///exemplu de input: Motocicleta m(40000, "AG-02-HON", "Honda", "CBR600RR", "utilizata", 2013, Rezervor(12, 3), Motor(70, 4.5, true));
    //u.AdaugaIntretinere_Citita();
    ///exemplu de input: Intretinere i(3, 300.00, "Inlocuire_kit_distributie", "AG-02-HON", "13.03.2023");

    ///Afisarea utilizatorului
    cout<<u<<"\n";

    ///Afisarea motocicletelor detinute
    u.AfiseazaMotociclete();
    cout<<"\n";

    ///Afisare intretinerilor parcurse
    u.AfiseazaIntretineri();

    ///Afisarea detaliilor legate de costuri cum ar fi:

    //1. costul mediu pentru reparatii platit de utilizatorul u
    cout<<"\nCostul mediu alocat reparatiilor este "<<u.CostMediu_pentru_Reparatii();

    //2. costul total pentru reparatii platit de utilizatorul u
    cout<<"\nCostul total alocat reparatiilor este "<<u.CostTotal_pentru_reparatii();

    //3. numarul de motociclete din marca "BMW" ale utilizatorului u
    cout<<"\nNumarul de motociclete din marca BMW este "<<u.NrMotociclete_din_Marca("BMW");

    return 0;
}




