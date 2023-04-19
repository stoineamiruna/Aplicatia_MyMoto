# Numele proiectului: MyMoto

## Tema proiectului

  Tema acestui proiect este o aplicație mobilă denumită "MyMoto", care are scopul de a monitoriza motocicletele personale ale utilizatorilor și de a retine detalii esențiale despre acestea.

  Cu ajutorul acestei aplicații, utilizatorii vor putea să își urmărească motocicletele în timp real, să primească notificări și avertizări legate de rezervorul de combustibil, viteza, nivelul de consum și alte informații importante.

  Printre informațiile de bază despre motocicletă care vor fi stocate în aplicație se numără detalii precum modelul, anul de lansare, producătorul și firma. De asemenea, utilizatorii vor putea adăuga și alte informații relevante, precum numărul de înmatriculare sau imaginea motocicletei.

  Aplicația va monitoriza și starea motocicletei, inclusiv rezervorul, luminile, semnalizatoarele și motorul, precum și starea generală a vehiculului, inclusiv dacă este pornit sau oprit.

  În plus, aplicația va fi echipată cu un sistem GPS care va permite utilizatorilor să își localizeze motocicleta în timp real și să primească notificări de alertă dacă aceasta este mutată sau dacă este depășită o anumită viteză.

  Așadar, "MyMoto" este o aplicație utilă și eficientă pentru cei pasionați de motociclete care doresc să își monitorizeze vehiculele personale și să primească notificări importante legate de acestea.

## Clasele utlizate

### Utilizator

  Clasa Utilizator reprezintă un element cheie în cadrul aplicației MyMoto, având rolul de a monitoriza motocicleta/motocicletele unui utilizator. Această clasă conține informații despre utilizator, cum ar fi numele, prenumele, vârsta, data nașterii, precum și informații despre motocicletele deținute și întreținerile efectuate asupra acestora.

### Motocicleta

  Clasa "Motocicleta" este esențială în implementarea "MyMoto" deoarece este responsabilă pentru definirea și stocarea informațiilor despre motocicletă, precum nivelul de combustibil, kilometrajul, modelul, starea și altele. Aceste informații sunt cruciale pentru a monitoriza și a gestiona motocicleta într-un mod eficient și precis.

  De asemenea, clasa "Motocicleta" oferă metode pentru a accesa și actualiza aceste informații, ceea ce permite utilizatorilor să efectueze acțiuni precum pornirea și oprirea motorului, adăugarea de combustibil și conducerea motocicletei. În plus, aceste metode sunt importante pentru a asigura o experiență de utilizare sigură și confortabilă.

  Astfel, clasa "Motocicleta" este un element cheie al implementării "MyMoto", deoarece permite aplicației să colecteze, să stocheze și să gestioneze informațiile despre motocicletă într-un mod precis și eficient, oferind utilizatorilor un control mai bun asupra motocicletei și o experiență mai bună în general.

### Rezervor

  Clasa Rezervor este importantă în cadrul aplicației MyMoto deoarece oferă o modalitate de monitorizare a nivelului de combustibil al motocicletelor. Prin intermediul acestei clase, utilizatorii pot vedea capacitatea totală a rezervorului și nivelul actual al combustibilului, iar prin metoda addCombustibil(), pot adăuga combustibil în mod corespunzător. Aceste informații sunt esențiale pentru planificarea călătoriilor și pentru prevenirea opririi inopinate a motocicletei din cauza lipsei de combustibil.

### Intretinere

  Clasa "Intretinere" este utilizată în aplicația "MyMoto" pentru a urmări ultima dată când motocicleta a fost întreținută și tipul de service efectuat. Această clasă permite utilizatorilor să țină evidența asupra întreținerii motocicletei și să o îngrijească adecvat pentru a menține performanța și siguranța acesteia. Metodele din această clasă permit actualizarea informațiilor de întreținere a motocicletei și obținerea datelor existente despre ultimul service efectuat și tipul de service necesar.

### GPS

  Clasa GPS este utila in aplicatia "MyMoto" pentru a permite utilizatorului sa cunoasca pozitia actuala a motocicletei sale. Aceasta clasa stocheaza coordonatele geografice ale locatiei si ofera metode pentru a obtine si actualiza aceste informatii.

### Motor

  Clasa "Motor" reprezinta o componenta esentiala a aplicatiei "MyMoto", fiind responsabila pentru functionarea motocicletei. Aceasta clasa contine informatii despre puterea motorului, consumul de combustibil si starea motorului (pornit/oprit). Metodele clasei permit pornirea sau oprirea motorului, precum si accesul la informatiile despre puterea motorului si consumul de combustibil. Clasa "Motor" este importanta in cadrul aplicatiei "MyMoto" deoarece permite controlul functionarii motocicletei.

### Odometru

  Clasa Odometru permite măsurarea distanței parcurse. Ea este utilizată în aplicația "MyMoto" pentru a monitoriza și afișa distanța parcursă de utilizator în timpul călătoriilor cu motocicleta. Clasa conține o singură variabilă de tip float - distanța - și două metode: getDistanta() pentru a obține valoarea distanței parcurse și actualizeazaDistanta() pentru a actualiza valoarea distanței cu o valoare nouă.

### Vitezometru

  Clasa Vitezometru este utilizată în aplicația "MyMoto" pentru a măsura și afișa viteza curentă a motocicletei. Ea conține o variabilă privată "viteza" și două metode publice: "getViteza()" pentru a obține viteza curentă și "actualizeazaViteza()" pentru a actualiza viteza curentă cu o nouă valoare.

## Funcționalități


- Înregistrarea motocicletei - utilizatorul poate introduce informații despre motocicletă, inclusiv marca, modelul, anul de fabricație, starea curenta, numărul de înmatriculare,kilometraj, dar si informatii legate de componentele acesteia, cum ar fi rezervorul si motorul.

- Înregistrarea unui utilizator-utilizatorul isi poate stoca informatii precum: username-ul, numele, prenumele, varsta, data nasterii; dar și informații despre motocicletele personale si intretinerile platite pana la momentul actual.

- Citirea si initializarea informațiilor, dar și actualizarea acestora, pentru fiecare clasa în parte.

- Istoricul de întreținere - aplicația poate să stocheze informații despre întreținerea și reparațiile anterioare ale motocicletei. 

- Pornirea motocicletei- utilizatorul poate porni o motocicleta personală și totodată să verifice dacă motocicleta sa este sau nu în funcțiune(pornire).

- Alimentarea unei motociclete- utilizatorul își poate alimenta oricând motocicleta cu un număr de litri dat (alimenteaza).

- Simularea conducereii motocicletei- utilizatorul poate porni una dintre motocicletele personale pe un traseu a cărui distanță este cunoscută (drive).

- Adăgarea unei noi motociclete, fie prin stocarea directă a datelor, fie prin adăugarea datelor deja existente (AdaugaMotocicleta_citita si AdaugaMotocicleta).

- Adăgarea unei noi întrețineri, fie prin stocarea directă a datelor, fie prin adăugarea datelor deja existente(AdaugaIntretinere_citita si AdaugaIntretinere).

- Calculul costului mediu- aplicația oferă utilizatorului valoarea costului mediu alocat reparațiilor efectuate până la momentul actual (CostMediu_pentru_Reparatii).

- Cost total- aplicația oferă utilizatorului valoarea totală a costurilor alocate reparațiilor și altor cheltuieli efectuate asupra tuturor motocicletelor până la momentul actual (CostTotal_pentru_reparatii).

- Afișarea tuturor motocicletelor deținute de un utilizator (AfiseazaMotociclete).

- Afișarea informațiilor tuturor cheltuielilor efectuate de utilizator asupra motocicletelor personale (AfiseazaIntretineri). 

- Numarul de motocicle de o anumita marca- aplicația oferă utilizatorului numărul total de motociclete deținute de acesta care aparțin unei anumite mărci (NrMotociclete_din_Marca).

- Localizarea motocicletei - aplicația poate să ofere utilizatorului informații despre locația motocicletei în timp real sau să stocheze informații despre locația anterioară a acesteia.
