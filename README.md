# Vektoriu-klase  
Sukurta vektoriu klasė (konteineris), kuris veikia kaip std::vector.  
5 vector funkcijos:
1. Assign.  
![image](https://user-images.githubusercontent.com/79039786/119896229-6f8c9700-bf47-11eb-930a-dbdb899a2c70.png)  
2. Pop_back.  
![image](https://user-images.githubusercontent.com/79039786/119896255-76b3a500-bf47-11eb-9cab-b4f700d65a7e.png)


3. Push_back.  
![image](https://user-images.githubusercontent.com/79039786/119896289-7fa47680-bf47-11eb-9707-9fe99377fe4f.png)

4. Reserve.  
![image](https://user-images.githubusercontent.com/79039786/119896316-87641b00-bf47-11eb-8a7c-489e7748d3a6.png)

5. At.
![image](https://user-images.githubusercontent.com/79039786/119896348-91861980-bf47-11eb-959d-c44662f6f4a9.png)

## Spartos Analizė  
Buvo atlikta spartos analizė tarp vector klasės ir std::vector.  
Tušti vektoriai buvo užpildomi 10000, 100000, 1000000, 10000000, 100000000 int elemtų su push_back() funkcija.   
Buvo paimtas vektorių klasės ir std::vector veikimo vidurkis:   
![image](https://user-images.githubusercontent.com/79039786/119893330-e4f66880-bf43-11eb-9350-50c116414c42.png)  
### Išvada  
Vector klasė veikia sparčiau nei std::vector, taip turbūt yra, nes vector klasėje nėra daugybės apribojimų, catch'ų, apsaugojimų, kurie taip pat užima laiko.  
## Atminties perskirstymo analizė  
Perskirstymas įvyksta tada kai patenkinama sąlyga: capacity() == size();  
Buvo lyginamas Versijos-2.0 veikimas su vector klase ir std::vector.   
Vector klasė - įvyko 20 persidengimų programai veikiant su 1000000 studentų duomenų failu.  
Std::vector - taip pat 20 persidengimų. 
## Spartos Analizė 2  
Buvo lyginamas Versijos-2.0 veikimas su vector klase ir std::vector.  
Buvo lyginama veikimo sparta su 1000000 duomenimis bei ar vector klasė veikia teisingai.  
Vector klasė - 209s.  
Std::vector = 237s.  
Vector klasė veikia teisingai, nes išvesti duomenys yra identiški. 

