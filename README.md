# Vektoriu-klase  
Sukurta vektoriu klasė (konteineris), kuris veikia kaip std::vector.  
5 vector funkcijos:
1. Assign.  
2. Pop_back.  
3. Push_back.  
4. Reserve.  

## Spartos Analizė  
Buvo atlikta spartos analizė tarp vector klasės ir std::vector.  
Tušti vektoriai buvo užpildomi 10000, 100000, 1000000, 10000000, 100000000 int elemtų su push_back() funkcija.   
Buvo paimtas vektorių klasės ir std::vector veikimo vidurkis:   
![image](https://user-images.githubusercontent.com/79039786/119893330-e4f66880-bf43-11eb-9350-50c116414c42.png)  
### Išvada  
Vector klasė veikia sparčiau nei std::vector, taip turbūt yra, nes vector klasėje nėra daugybės apribojimų, catch'ų, apsaugojimų, kurie taip pat užima laiko.  
## Atminties perskirstimo analizė  
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

