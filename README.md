# Proiect-ASC

# Team VS Team

Echipa noastra: yoyoboyss <br/>
Echipa adversa: [HMM](https://github.com/ImCataG/xor-cypher) <br/>
Parola echipei adverse: despacito30AB <br/>

# input + output

&emsp;Am luat manual primele 30 de caractere din fisierul input si din output si am aplicat operatia XOR intre caractere, dupa care cu un convertor online, am transformat numarul din binar intr-un caracter. Deoarece cheia folosita trebuia sa fie intre 10-15 caractere, daca luam primele 30 de caractere, cheia s-ar fi regasit de cel putin 2 ori in decodare noastra, astfel am putut sa obvservam ca ce s-a repetat a fost sirul de caractere "despacito30AB".

# output

&emsp;Pentru aflarea cheii doar pe baza de output am folosit un script codat in C++, numit main.cpp, ce este gasit pe pagina de github, ce realiza o metoda bruteforce de aflare a cheii. Am ales sa folosim C++ deoarece metoda noastra bruteforce necesita foarte multe operatii de executat, iar C++ s-a potrivit perfect pentru ceea ce voiam sa facem. <br/>
&emsp;Pentru aflarea cheii incercam sa folosim o cheie partiala de lungime X, care sa decodifice caracterele cuprinse intre indixii [i, i+X), pentru o cheie ce ar fi avut lungimea L. <br/>
&emsp;Plecand de la aceasta idee, noi generam toate aranjamentele de caractere valide pentru o cheie partiala de lungime X, dupa care aplicam algoritmul prezentat mai sus, si incercam sa vedem in care dintre acele decodificari gaseam cuvantul "este". <br/>
&emsp;Deoarece cuvantul "este" este foarte raspandit in limba romana, exista foarte mare probabilitate ca in momentul cand folosim o parte din cheia corecta, cuvantul "este" sa se gaseasca la un moment dat pe un interval de caractere [i, i+X) din cheia de lungime L. <br/>
&emsp;Deoarece doar gasirea cuvantului "este" in decodificare ne adunea un numar foarte mare de chei partiale posibile, am mai adaugat o conditie de existenta, si anume atunci cand este decodificat un caracter, decodificarea acestuia sa nu fie un caracter al carui ASCII este mai mic decat 32 si diferit de 10 sau mai mare decat 126. Daca pe intreaga decodificare a fisierul erau respectate aceste reguli, atunci consideram ca aceasta cheie partiala folosind este posibil corect. <br/>
&emsp;Exista posibilitatea ca la un moment dat pe intervalul [i, i+X) sa ne genereze mai multe chei posibil corecte, iar care sa vedem care este cea corecta, generam si pentru intervalul [i+1, i+X] cheile posibile corecte, si alegem doar cheile care respecta proprietatea ca ultimele X-1 caractere din generarea pe intervalul [i, i+X) sa fie aceleasi cu primele X-1 caractere din generarea pe intervalul [i+1, i+X]. <br/>
&emsp;Un exemplu a modului in care functioneaza acest algoritm ar fi: daca pe intervalul [0, 4) din lumgimea cheii de 11 caractere, am gasit cheile posibile "alba", "best", "desp", iar pe intervalul [1,4] din lungimea cheii de 11 caractere gaseam cheile posibile "lbba", "espa", "mica", "ripa", atunci am fi ales doar "desp" si "espa" deoarece respecta proprietatea prezentata mai sus, si am fi obtinut o partea din cheia de 11 caractere care este "despa". <br/>
&emsp;Pentru a alege lungimea corecta a cheii folosite, am generat pentru fiecare valoarea dintre intervalul [10, 15]. Daca lungimea aleasa era gresita, atunci la un moment dat intersectia respectand proprietatea de mai sus, a cheilor gasite pe intervalul [i, i+X) si a cheilor gasite pe intervalul [i+1, i+X] ar fi fost multimea vida. <br/>
&emsp;Cand am ajuns la lungimea 13, script-ul creat ne-a generat urmatoarea chestie: <br/>
&emsp;&emsp; cheie folosita - interval  <br/>
&emsp;&emsp; desp - [0, 4)  <br/>
&emsp;&emsp; espa - [1, 5)  <br/>
&emsp;&emsp; spac - [2, 6)  <br/>
&emsp;&emsp; paci - [3, 7)  <br/>
&emsp;&emsp; acit - [4, 8)  <br/>
&emsp;&emsp; cito - [5, 9)  <br/>
&emsp;&emsp; ito3 - [6, 10)  <br/>
&emsp;&emsp; to30 - [7, 11)  <br/>
&emsp;&emsp; o30A - [8, 12)  <br/>
&emsp;&emsp; 30AB - [9, 13)  <br/>
&emsp;Privind ce ne-a fost generat mai sus, am reusit sa gasit cu usurinta cheia folosita, si anume: "despacito30AB", iar dupa ce am folosit cheia aceasta pentru a decoda output-ul, am reusit sa vedem ca iese un text in limba romana, corect gramatical, ceea ce inseamna ca aceasta este cheia corecta.
