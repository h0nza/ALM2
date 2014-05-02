Zápočtová úloha 
===============

Sestavte aplikaci obsahující 3 hašovací tabulky pro ukládání řetězců s vlastnostmi: 

Velikost všech tabulek je stejná. Počet přihrádek v tabulkách je 5003 (prvočíslo). 

Řešení kolizí je u všech tabulek otevřeným adresováním. 

* V první tabulce je použito lineární hledání prázdné přihrádky. 
* V druhé tabulce je použito kvadratické hledání prázdné přihrádky. 
* Ve třetí tabulce je použito dvojí hašování pro hledání prázdné přihrádky. 

Do tabulek jsou ukládány náhodně vygenerované řetězce. Pro každý řetězec je nejprve 
vygenerována jeho délka jako náhodné číslo v rozsahu 1..10. Řetězec je sestaven z malých 
písmen, která jsou rovněž generována pomocí generátoru náhodných čísel. Do všech tabulek 
jsou ukládány stejné řetězce (a ve stejném pořadí). Při ukládání řetězce do tabulky zároveň 
ověřte, zda stejný řetězec již v tabulce není. Pokud daný řetězec je již v tabulce, do tabulky ho 
znovu neukládejte. 


Tabulky postupně zaplňte na přibližně 50%, 75%, 90% a 95%. 
Pro každé uvedené zaplnění vypočítejte, kolik bylo průměrně zapotřebí pokusů k nalezení 
prázdné přihrádky pro uložení řetězce (mimo případy, kdy řetězec nebyl uložen, protože už 
v tabulce je). Výsledky zobrazte ve tvaru: 

zaplnění | Linear. | Kvadrat. | Dvoji has. 
---------|---------|----------|-----------
     50% | x.xx    | x.xx     | x.xx 
     75% | x.xx    | x.xx     | x.xx 
     90% | x.xx    | x.xx     | x.xx 
     95% | x.xx    | x.xx     | x.xx 


Základní část hašovací funkce může například být: 

c(z) = p^{k-1} z_1 + p^{k-2} z_2 + ... +p^2 z_{k-2} + p z_{k-1} + z_k 

kde p je konstanta, nejlépe prvočíslo, třeba p=37.

Výpočet: p(p(… p(pz_1 + z_2)+…+z_{k-2}) + z_{k-1}) + z_k.

Při výpočtu uvedené funkce c(z) dochází k přetečení, proto pro výpočet je zapotřebí použít 
datový typ čísla bez znaménka -unsigned ! 

Soubor se zdrojovým kódem nebo celý projekt pošlete 
* nejpozději v pondělí 12. května pro středeční cvičení 
* nejpozději v úterý 13. května pro čtvrteční cvičení 

Při zasílání do předmětu dopisu uveďte zkratku kurzu ALM2 a přiložený soubor se zdrojovým kódem 
nebo projektem bude mít jméno sestavené z prefixu, který je uveden v následující tabulce, příjmení a křestního 
jména (příjmení bude před křestním jménem). 

den cvičení | začátek cvičení | prefix 
------------|-----------------|-------
středa      | 9:45            | ALM2S 
čtvrtek     | 8:00            | ALM2C 

Příklad: ALM2SMalýPavel.c, ALM2SMalýPavel.cpp, ALM2SMalýPavel.rar, 
