# Náplň cvičenia
- zadanie so 7-segmentovým displejom
- organizácia k distribúcii HW

# Zadanie

### Úvod k zadaniu
- pre zadanie sa bude využívať 4 miestny 7-segmentový displej LFD028BUE-103A

<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_8/blob/zadanie_cv8/pics/20201124_111845.jpg" width="350">
</p>

- dokumentácia k displeju: 
    - https://www.tme.eu/Document/afe40de6cbe93d7d978749835d83cb6c/LFD028BUE-103A.pdf
    - https://www.tme.eu/Document/dbdd01c960330b1fd5fd83f8ac44a1e1/LFD036BUE-101B.pdf

- zobrazovanie znakov pomocou segmentov:

<p align="center">
    <img src="https://github.com/VRS-Predmet/vrs_cvicenie_8/blob/zadanie_cv8/pics/Segment_Display_with_Labeled_Segments.png" width="250">
</p>

- abeceda pre sedem segmentový displej: https://en.wikichip.org/wiki/seven-segment_display/representing_letters

### Úlohy:
1a. Nakonfigurovať GPIO tak, aby dokázali ovládať segmenty: 
   - segment A  -> PA1           
   - segment B  -> PA0             
   - segment C  -> PA8             
   - segment D  -> PB5             
   - segment E  -> PA11            
   - segment F  -> PA3
   - segment G  -> PB4
   - segment DP -> PB1

1b. Nakonfigurovať GPIO tak, aby sa dokázali ovládať digity: 
   - digit 0 ->    PA5
   - digit 1 ->    PA4
   - digit 2 ->    PA6
   - digit 3 ->    PA2
   - digit time -> PA7
   
2. Vytvoriť sadu znakov (písmená a číslice). Pri abecede sa riadte podľa výššie uvedenej stránky. 
3. Implementujte aj znaky "K", "M", "V", "W", "X", "Z" .
4. Vytvorte aplikáciu, ktorá na displeji zobrazí vaše meno, priezvysko a ID. Kedže sa všetky znaky na displaj nezmestia naraz v jednom čase, je potrebné, aby sa text posúval. Výsledná animácia bude vyzerať tak, že na začiatku sa zobrazia prvé štyri znaky krstného mena. Potom sa zobrazí 2. až 5. znak krstného mena a tak ďalej ... . Krstné meno, priezvysko a ID budú navzájom oddelené podčiarkovníkom - "_". Do vašej sady znakov teda zahrnte aj tento znak.
5. Znak sa posunie každých 500ms.
6. Reťazec s menom, priezvyskom a ID môže byť napevno definovaný.
7. Ak sa zobrazovaný text dostane na koniec, začne sa text po znakoch posúvať opačným smerom až kým nedojde na začiatok. 

Príklad: 
- meno, priezvysko a ID budú vo výsledku tvoriť pre zobrazenie reťazec: Janko_Bukvička_123
- na začiatku animácie sa zobrazia znaky: "Jank"
- v ďalšej iterácii, teda sa zobrazovanie posunie o jeden znak: "anko"
- v ďalšej iterácii a tak ďalej: "anko"
