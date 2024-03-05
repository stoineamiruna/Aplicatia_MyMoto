#include <iostream>
#include <cstring>
using namespace std;

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
        void setEsteApasata(bool e_a){
            este_apasata=e_a;
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
class Rezervor {
    private:
        static float capacitate;
        float nivel_combustibil;

    public:
        Rezervor() {
            nivel_combustibil = 0.0;
        }
        Rezervor(float c, float nvl) {
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

        static float getCapacitate() {
            return capacitate;
        }

        float getNivelCombustibil() const {
            return nivel_combustibil;
        }

        static void setCapacitate(float c){
            capacitate=c;
        }
        void setNivelCombustibil(float nvl_c){
            nivel_combustibil=nvl_c;
        }
        void addCombustibil(float cantitate) {
            if (nivel_combustibil + cantitate > capacitate) {
                nivel_combustibil=capacitate;
                throw runtime_error("\nCapacitatea rezervorului a fost depasita!\n");
            } else {
                nivel_combustibil += cantitate;
            }
        }
        static void TripleazaCapacitatea() {
            float valoare = capacitate*3;
            cout << "Capacitatea rezervorului este acum: " << valoare <<"\n";
        }

        static void DubleazaCapacitatea() {
            float valoare = capacitate * 2;
            cout << "Capacitatea rezervorului este acum: " << valoare <<"\n";
        }
        ///supraincarcarea operatorilor << si >>
        friend ostream& operator<<(ostream& out, const Rezervor& r);
        friend istream& operator>>(istream& in, Rezervor& r);
};
float Rezervor::capacitate = 0.0f;
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
    protected:
        int putere;
        float consum_combustibil;
        bool este_pornit;

        void start() {
            este_pornit = true;
        }

        void stop() {
            este_pornit = false;
        }

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
        virtual void accelerare(float viteza) {
            if (este_pornit) {
                cout << "Motor accelereaza cu " << viteza << " km/h\n";
            } else {
                throw runtime_error("\nMotorul nu poate accelera deoarece este oprit.\n");
            }
        }

        virtual void AfiseazaDescriere() {
            cout << "Acesta este un motor generic.\n";
        }

        /// supraincarcarea operatorilor << si >>
        friend ostream& operator<<(ostream& out, const Motor& m);
        friend istream& operator>>(istream& in, Motor& m);
};

ostream& operator<<(ostream& out, const Motor& m){
    out<<"\nInformatii despre motor\n";
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

class Motor2T : public Motor {
    protected:
        int numar_cilindri;
        float raport_aer_combustibil;

    public:
        Motor2T() : Motor() {
            numar_cilindri = 2;
            raport_aer_combustibil=0;
        }
        Motor2T(int p, float cc, bool ep, int nc, float rap) : Motor(p, cc, ep) {
            numar_cilindri = nc;
            raport_aer_combustibil=rap;
        }
        int getNumarCilindri() {
            return numar_cilindri;
        }
        void setNumarCilindri(int nc) {
            numar_cilindri = nc;
        }
        float getRaportAerCombustibil() {
            return raport_aer_combustibil;
        }
        void setRaportAerCombustibil(float rap) {
            raport_aer_combustibil = rap;
        }
        void accelerare(float viteza) {
            if (este_pornit && raport_aer_combustibil > 0) {
                float consum = 0.1 * putere * viteza / raport_aer_combustibil / numar_cilindri;
                consum_combustibil += consum;
                cout<<"Motorul2T are acum consumul de "<<consum_combustibil<<"\n";
            }
            else
                throw runtime_error("\nMotorul4T nu poate fi accelerat deoarece este oprit!\n");
        }
        void AfiseazaDescriere() override {
            cout << "Acesta este un motor cu 2 timpi.\n";
        }
        friend ostream& operator<<(ostream& out, const Motor2T& m);
        friend istream& operator>>(istream& in, Motor2T& m);
};
istream& operator>>(istream& in, Motor2T& m) {
    in >> static_cast<Motor&>(m); // citeste din Motor
    cout << "Numar de cilindri: ";
    in >> m.numar_cilindri;
    cout << "Raport aer-combustibil: ";
    in >> m.raport_aer_combustibil;
    return in;
}

ostream& operator<<(ostream& out, const Motor2T& m) {
    out << static_cast<const Motor&>(m); // afiseaza din Motor
    out << "Numar de cilindri: " << m.numar_cilindri <<"\n";
    out << "Raport aer-combustibil: " << m.raport_aer_combustibil <<"\n";
    return out;
}
class Motor4T : public Motor {
    protected:
        int numar_cilindri;
        int viteza_maxima;
        float raport_transmisie_final;
    public:
        Motor4T() : Motor() {
            numar_cilindri = 4;
            viteza_maxima=0;
        }
        Motor4T(int p, float cc, bool ep, int nc, int vmax, float rap) : Motor(p, cc, ep) {
            numar_cilindri = nc;
            viteza_maxima=vmax;
            raport_transmisie_final=rap;
        }
        int getNumarCilindri() {
            return numar_cilindri;
        }
        void setNumarCilindri(int nc) {
            numar_cilindri = nc;
        }
        int getVitezaMaxima() {
            return viteza_maxima;
        }
        void setVitezaMaxima(int vmax) {
            viteza_maxima = vmax;
        }
        float getRaportTransmisieFinal() {
            return raport_transmisie_final;
        }
        void setRaportTransmisieFinal(float rap) {
            raport_transmisie_final = rap;
        }
        void accelerare(float viteza) {
            if (este_pornit && raport_transmisie_final > 0) {
                float consum = 0.05 * putere * viteza / raport_transmisie_final / numar_cilindri;
                consum_combustibil += consum;
                cout<<"Motorul4T are acum consumul de "<<consum_combustibil<<"\n";
            }
            else
                throw runtime_error("\nMotorul4T nu poate fi accelerat deoarece este oprit!\n");
        }
        void AfiseazaDescriere() override {
            cout << "Acesta este un motor cu 4 timpi.\n";
        }
        friend ostream& operator<<(ostream& out, const Motor4T& m);
        friend istream& operator>>(istream& in, Motor4T& m);
};
istream& operator>>(istream& in, Motor4T& m) {
    in >> static_cast<Motor&>(m); // citeste din Motor
    cout << "Numar de cilindri: ";
    in >> m.numar_cilindri;
    cout << "Viteza maxima: ";
    in >> m.viteza_maxima;
    cout << "Raport transmisie-final: ";
    in >> m.raport_transmisie_final;
    return in;
}

ostream& operator<<(ostream& out, const Motor4T& m) {
    out << static_cast<const Motor&>(m); // afiseaza din Motor
    out << "Numar de cilindri: " << m.numar_cilindri <<"\n";
    out << "Viteza maxima: " << m.viteza_maxima <<"\n";
    out << "Raport transmisie-final: " << m.raport_transmisie_final <<"\n";
    return out;
}
class Vehicul{
public:
    virtual void AfiseazaIndicatie()=0;
    virtual void AfiseazaDescriere()=0;

    virtual ~Vehicul(){}
};
class Motocicleta: public Vehicul {
    protected:
        float kilometraj;
        char numar_inmatriculare[50];
        char marca[50];
        char model[50];
        char stare[50];
        int an;
        Rezervor rezervor;
        Frana frana;

    public:
        Motocicleta() :
            an(0),
            kilometraj(0.0){
            strcpy(numar_inmatriculare, "");
            strcpy(marca, "");
            strcpy(model, "");
            strcpy(stare, "");
            Rezervor();
            Frana();
        }
        Motocicleta(float k, const char* nr, const char* m, const char* md, const char* st, int a, Rezervor r, Frana fr) :
            an(a),
            kilometraj(k) {
            rezervor=r;
            frana=fr;
            strcpy(numar_inmatriculare, nr);
            strcpy(marca, m);
            strcpy(model, md);
            strcpy(stare, st);
        }

        ///constructor de copiere explicit
        Motocicleta(const Motocicleta& m) :
            an(m.an),
            rezervor(m.rezervor),
            frana(m.frana),
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
        void setRezervor(float c, float nvl_c){
            rezervor.setCapacitate(c);
            rezervor.setNivelCombustibil(nvl_c);
        }
        void setFrana(bool este_apasata){
            frana.setEsteApasata(este_apasata);
        }

        void alimenteaza(float cantitate){
            rezervor.addCombustibil(cantitate);
        }

        virtual void AfiseazaIndicatie()=0;
        virtual void AfiseazaDescriere()=0;
        ///supraincarcarea operatorilor << si >>
        friend ostream& operator<<(ostream& out, const Motocicleta& m);
        friend istream& operator>>(istream& in, Motocicleta& m);
        ~Motocicleta(){}
};
Motocicleta& Motocicleta::operator=(const Motocicleta& m) {
    if (this != &m) {
        kilometraj = m.kilometraj;
        strcpy(numar_inmatriculare, m.numar_inmatriculare);
        strcpy(marca, m.marca);
        strcpy(model, m.model);
        strcpy(stare, m.stare);
        rezervor = m.rezervor;
        frana=m.frana;
    }
    return *this;
}
ostream& operator<<(ostream& out, const Motocicleta& m) {
    out << "Numar de inmatriculare: " << m.getNumarInmatriculare() <<"\n";
    out << "Marca: " << m.getMarca() <<"\n";
    out << "Model: " << m.getModel() <<"\n";
    out << "An: " << m.getAn() << "\n";
    out << "Kilometraj: " << m.getKilometraj() << "\n";
    out << "\nInformatii rezervor:\n";
    out << m.rezervor << "\n";
    out<<m.frana<<"\n";

    return out;
}

istream& operator>>(istream& in, Motocicleta& m)
{
    float km; int a; char nr[50],mc[50],st[50],md[50];
    ///variabile pt rezervor
    float c,nvl_c;
    ///variabile pt frana
    bool e_a;
    cout<<"Dati kilometrajul: "; in >>km;
    cout<<"Dati modelul: "; in>>md;
    cout<<"Dati numarul de inmatriculare: "; in>>nr;
    cout<<"Dati marca: "; in>>mc;
    cout<<"Dati anul: "; in>>a;
    cout<<"Dati informatiile rezervorului\n";
    cout<<"Dati capacitatea: "; in>>c;
    cout<<"Dati nivelul combustiblului: "; in>>nvl_c;
    cout<<"Spuneti daca frana este sa nu apasata: "; in>>e_a;
    m.setKilometraj(km);
    m.setModel(md);
    m.setNumarInmatriculare(nr);
    m.setMarca(mc);
    m.setAn(a);
    m.setRezervor(c,nvl_c);
    m.setFrana(e_a);
    return in;
}

class MotocicletaStrada: public Motocicleta, public Motor2T {

  public:
        MotocicletaStrada() : Motor2T(), Motocicleta() {}
        MotocicletaStrada(int p, float cc, bool ep, int nc,float rap,float k, const char* nr, const char* m, const char* md, const char* st, int a, Rezervor r, Frana fr) :
            Motor2T(p,cc,ep,nc,rap),
            Motocicleta(k,nr,m,md,st,a,r,fr) {}
        void pornire() {
            start();
        }
        void oprire() {
            stop();
        }
        void drive(float distanta) {
            if (getEstePornit()) {
                if (rezervor.getNivelCombustibil()>= distanta/50.0) {
                    kilometraj += distanta;
                    rezervor.addCombustibil(-distanta/50.0);
                }
                    else {
                        cout << "Nu exista suficient combustibil pentru a efectua deplasarea!" <<"\n";
                    }
            }
        }
        virtual void AfiseazaIndicatie() override{
            cout << "Atentie! Viteza maxima admisa pe strazi este de 50 km/h.\n";
        }
        virtual void AfiseazaDescriere() override{
            cout<<"Motocicleta utilizata, in general, pe drumurile publice.\n";
        }
        friend istream& operator>>(istream& in, MotocicletaStrada& m);
        friend ostream& operator<<(ostream& out, const MotocicletaStrada& m);
        virtual ~MotocicletaStrada() {}
};
istream& operator>>(istream& in, MotocicletaStrada& m) {
    in >> static_cast<Motocicleta&>(m);
    in >> static_cast<Motor2T&>(m);
    return in;
}

ostream& operator<<(ostream& out, const MotocicletaStrada& m) {
    out << static_cast<const Motocicleta&>(m);
    out << static_cast<const Motor2T&>(m);
    return out;
}

class MotocicletaSport : public Motocicleta, public Motor4T {

  public:
        MotocicletaSport() : Motor4T(), Motocicleta() {}
        MotocicletaSport(int p, float cc, bool ep, int nc, int vmax, float rap,float k, const char* nr, const char* m, const char* md, const char* st, int a, Rezervor r, Frana fr) :
            Motor4T(p,cc,ep,nc,vmax,rap),
            Motocicleta(k,nr,m,md,st,a,r,fr) {}
        void pornire() {
            start();
        }
        void oprire() {
            stop();
        }
        void drive(float distanta) {
            try {
                if (getEstePornit()) {
                    if (rezervor.getNivelCombustibil()>= distanta/50.0) {
                        kilometraj += distanta;
                        rezervor.addCombustibil(-distanta/50.0);
                    }
                        else {
                            throw logic_error("Nu exista suficient combustibil pentru a efectua deplasarea!\n");
                        }
                }
                else
                    {throw logic_error("Motocicleta nu este pornita!\n");}
            } catch (const logic_error& e) {
                cout << "Eroare: " << e.what() <<"\n";
                throw; // re-aruncăm excepția
            }

        }
        virtual void AfiseazaIndicatie()override{
             cout << "Atentie! Aceasta motocicleta este foarte rapida si necesita o atentie sporita la viteza.\n";
        }
        virtual void AfiseazaDescriere() override{
            cout<<"Motocicleta utilizata, in general, in afara drumurilor publice.\n";
        }

        friend istream& operator>>(istream& in, MotocicletaSport& m);
        friend ostream& operator<<(ostream& out, const MotocicletaSport& m);

        virtual ~MotocicletaSport() {}
};

istream& operator>>(istream& in, MotocicletaSport& m) {
    in >> static_cast<Motocicleta&>(m);
    in >> static_cast<Motor4T&>(m);
    return in;
}

ostream& operator<<(ostream& out, const MotocicletaSport& m) {
    out << static_cast<const Motocicleta&>(m);
    out << static_cast<const Motor4T&>(m);
    return out;
}
//Functii care realizeaza Upcasting-ul

void exempluUpcasting1() {
    Motor4T motor4T;
    Motor* motorPtr = &motor4T; // Upcasting prin atribuirea obiectului de tip Motor4T la pointerul de tip Motor
    motorPtr->AfiseazaDescriere(); // Apelăm metoda AfiseazaDescriere() a obiectului prin intermediul pointerului
}

void exempluUpcasting2() {
    MotocicletaSport motocicletaSport;
    Motocicleta* motocicletaPtr = &motocicletaSport; // Upcasting prin atribuirea obiectului de tip MotocicletaSport la pointerul de tip Motocicleta
    motocicletaPtr->AfiseazaDescriere(); // Apelăm metoda AfiseazaDescriere() a obiectului prin intermediul pointerului
}

//Functia care realizeaza polimorfismul
void testPolimorfism(Motocicleta* motocicleta) {
    motocicleta->AfiseazaDescriere();
}

//Totodata, tip de exceptie personalizat

class MyCustomException : public exception {
public:
    const char* what() const throw() {
        return "Aceasta este o exceptie personalizata!";
    }
};

//Functie care realizeaza downcasting-ul+exceptie
void exempluDowncasting() {
    // Creăm un obiect de tip MotocicletaSport
    MotocicletaSport motocicletaSport;

    // Convertim pointerul de tip MotocicletaSport la un pointer de tip Motocicleta
    Motocicleta* motocicleta = &motocicletaSport;

    // Realizăm downcasting-ul folosind dynamic_cast
    MotocicletaSport* motocicletaSportPtr = dynamic_cast<MotocicletaSport*>(motocicleta);

    // Verificăm dacă downcasting-ul a reușit
    try {
        if (motocicletaSportPtr != nullptr) {
            // Apelăm metoda specifică clasei MotocicletaSport
            motocicletaSportPtr->AfiseazaDescriere();
        } else {
            throw MyCustomException();
        }
    } catch (const MyCustomException& e) {
        cout << "A aparut o exceptie personalizata: " << e.what() <<"\n";
        }
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
            if(numar_inmatriculare!=NULL) delete[] numar_inmatriculare;
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

class Utilizator{
    private:
        char user[50];
        char nume[50];
        char prenume[50];
        int varsta;
        char data_nasterii[50];
        int nr_motociclete_strada;
        int nr_motociclete_sport;
        int nr_intretineri;
        MotocicletaSport* motociclete_sport;
        MotocicletaStrada* motociclete_strada;
        Intretinere* intretineri;
    public:
        Utilizator(){
            strcpy(user,"");
            strcpy(nume,"");
            strcpy(prenume,"");
            varsta=0;
            strcpy(data_nasterii,"");
            nr_motociclete_sport=nr_motociclete_strada=nr_intretineri=0;
            motociclete_strada=NULL;
            motociclete_sport=NULL;
            intretineri=NULL;
        }
        Utilizator(char u[], char n[], char p[], int v, char dn[], int nr_m_st, int nr_m_sp, int nr_intr, MotocicletaSport* moto_sp,MotocicletaStrada* moto_st, Intretinere* intr){
            strcpy(user,u);
            strcpy(nume, n);
            strcpy(prenume, p);
            varsta=v;
            strcpy(data_nasterii,dn);
            nr_motociclete_strada=nr_m_st;
            nr_motociclete_sport=nr_m_sp;
            nr_intretineri=nr_intr;
            motociclete_strada=new MotocicletaStrada[nr_motociclete_strada];
            for(int i=0; i<nr_motociclete_strada; i++)
                motociclete_strada[i]=moto_st[i];
            motociclete_sport=new MotocicletaSport[nr_motociclete_sport];
            for(int i=0; i<nr_motociclete_sport; i++)
                motociclete_sport[i]=moto_sp[i];
            intretineri=new Intretinere[nr_intretineri];
            for(int i=0; i<nr_intretineri; i++)
                intretineri[i]=intr[i];
        }
        void AfiseazaMotociclete(){
            cout<<"Motociclete de strada: \n";
            for(int i=0; i<nr_motociclete_strada; i++)
                cout<<motociclete_strada[i]<<"\n\n";
            cout<<"\nMotociclete sport: \n";
            for(int i=0; i<nr_motociclete_sport; i++)
                cout<<motociclete_sport[i]<<"\n\n";
        }
        void AfiseazaIntretineri(){
            for(int i=0; i<nr_intretineri; i++)
                cout<<intretineri[i]<<"\n\n";
        }
        void AdaugaMotocicletaStrada_Citita(){
            MotocicletaStrada moto_st;
            cin>>moto_st;
            nr_motociclete_strada++;
            MotocicletaStrada* motociclete_strada_nou;
            motociclete_strada_nou= new MotocicletaStrada[nr_motociclete_strada];
            for(int i=0; i<nr_motociclete_strada-1; i++)
                motociclete_strada_nou[i]=motociclete_strada[i];
            motociclete_strada_nou[nr_motociclete_strada-1]=moto_st;
            if(motociclete_strada!=NULL)
                delete[] motociclete_strada;
            motociclete_strada=motociclete_strada_nou;
        }
        void AdaugaMotocicletaSport_Citita(){
            MotocicletaSport moto_sp;
            cin>>moto_sp;
            nr_motociclete_sport++;
            MotocicletaSport* motociclete_sport_nou;
            motociclete_sport_nou= new MotocicletaSport[nr_motociclete_sport];
            for(int i=0; i<nr_motociclete_sport-1; i++)
                motociclete_sport_nou[i]=motociclete_sport[i];
            motociclete_sport_nou[nr_motociclete_sport-1]=moto_sp;
            if(motociclete_sport!=NULL)
                delete[] motociclete_sport;
            motociclete_sport=motociclete_sport_nou;
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
        void AdaugaMotocicletaStrada(MotocicletaStrada moto){
            nr_motociclete_strada++;
            MotocicletaStrada* motociclete_strada_nou;
            motociclete_strada_nou= new MotocicletaStrada[nr_motociclete_strada];
            for(int i=0; i<nr_motociclete_strada-1; i++)
                motociclete_strada_nou[i]=motociclete_strada[i];
            motociclete_strada_nou[nr_motociclete_strada-1]=moto;
            if(motociclete_strada!=NULL)
                delete[] motociclete_strada;
            motociclete_strada=motociclete_strada_nou;
        }
        void AdaugaMotocicletaSport(MotocicletaSport moto){
            nr_motociclete_sport++;
            MotocicletaSport* motociclete_sport_nou;
            motociclete_sport_nou= new MotocicletaSport[nr_motociclete_sport];
            for(int i=0; i<nr_motociclete_sport-1; i++)
                motociclete_sport_nou[i]=motociclete_sport[i];
            motociclete_sport_nou[nr_motociclete_sport-1]=moto;
            if(motociclete_sport!=NULL)
                delete[] motociclete_sport;
            motociclete_sport=motociclete_sport_nou;
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
            for(int i=0; i<nr_motociclete_strada; i++)
                if(strcmp(marca, motociclete_strada[i].getMarca())==0) ct++;
            for(int i=0; i<nr_motociclete_sport; i++)
                if(strcmp(marca, motociclete_sport[i].getMarca())==0) ct++;
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
    out<<"\nNumar motociclete strada personale: "<<u.nr_motociclete_strada;
    out<<"\nNumar motociclete sport personale: "<<u.nr_motociclete_sport;
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
    /*
    ///Pentru etapa 1

    Rezervor rezervor;
    Motor motor;
    Utilizator u;
    Intretinere i;

    //Introducerea utilizatorului in aplicatie
    cin>>u;
    //Exemplu input: Utilizator u("ionpopescu07", "Popescu", "Ion", 35, "17.02.1988");

    //Introducem doua
    Motocicleta m1(0, "B-123-ABC", "BMW", "S1000RR", "noua", 2022, Rezervor(15, 7.5), Motor(100, 6, false), Frana(1));
    Motocicleta m2(25000, "CJ-01-YYY", "Yamaha", "YZF-R125", "utilizata", 2015, Rezervor(10, 10), Motor(50, 5, true), Frana(0));

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
    */


    /*
    //Pentru etapa 2
    Rezervor r(20,200);
    Frana fr(1);
    MotocicletaStrada m(30, 20, 0, 2,30,100, "30bc","marca", "model", "stare",2000,r,fr);
    cout<<m;
    m.pornire();
    cout<<m;
    Vehicul* v = new MotocicletaStrada();
    delete v;


    //Pentru reprezentarea polimorfismului la executie
    MotocicletaStrada motocicletaStrada;
    MotocicletaSport motocicletaSport;

    cout<<"Polimorfism: \n";
    testPolimorfism(&motocicletaStrada);
    testPolimorfism(&motocicletaSport);

    //Pentru reprezentarea instantelor de upcasting

    cout<<"\nUpcasting: \n";
    exempluUpcasting1();
    exempluUpcasting2();

    //Pentru reprezentarea downcasting-ului

    cout<<"\nDowncasting: \n";
    exempluDowncasting();

    //tratarea exceptiilor
    cout<<"\nTratarea exceptiilor: \n";

    //Pentru exceptia personalizata (extinde clasa exception)
    cout<<"\nExceptie personalizata:\n";
    try {
        exempluDowncasting();
    } catch (const MyCustomException& e) {
        cout << "Exceptie prinsa in main: " << e.what() <<"\n";
    }

    MotocicletaSport motocicleta;
    motocicleta.setEstePornit(true);

    //pentru primul bloc de try + exceptia 2 din metoda
    cout<<"\nPentru primul bloc try si pentru a doua exceptie dintr-o metoda:\n";
    try {
        motocicleta.drive(100.0);
    } catch (const logic_error& e) {
        cout << "Eroare in timpul deplasarii: " << e.what() <<"\n";
    }

    motocicleta.setEstePornit(false);
    //pentru al doilea bloc de try
    cout<<"\Pentru al doilea bloc try:\n";
    try {
        motocicleta.drive(50.0);
    } catch (const logic_error& e) {
        cout << "Eroare in timpul deplasarii: " << e.what() <<"\n";
    }

    //alt bloc try...catch cu tratarea exceptiei

    cout<<"\nAlt bloc try..catch:\n";
    Motor2T motor;
    try {
    motor.accelerare(100); // Apel al metodei care poate arunca excepția
} catch (const runtime_error& e) {
    // Tratarea excepției
    cout << "A aparut o exceptie de tip runtime_error: " << e.what() << "\n";
}

    //exceptia 1 din metode/functii
    cout<<"\nPentru prima exceptie dintr-o metoda:\n";

    try {
        MotocicletaStrada moto_strada;
        moto_strada.setRezervor(200, 130);
        moto_strada.alimenteaza(80);
    } catch (const std::runtime_error& ex) {
        cout << "A fost prinsa o exceptie: " << ex.what() <<"\n";
    }

    //Metodele statice
    cout<<"\nCele doua metode statice: \n";
    Rezervor rezervor(150,30);
    rezervor.setCapacitate(150);
    rezervor.DubleazaCapacitatea();
    rezervor.TripleazaCapacitatea();
    */

    return 0;
}




