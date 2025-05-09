# RJ45 Tester

## Introducere

### De la idee la prototip

Vă amintiți primul laborator de **RL**?

Acolo am învățat cum să realizăm un **cablu UTP** pentru rețele Ethernet,
Procesul poarta numele de **sertiazare**.
După realizarea cablului, acesta trebuie verificat ca functioneaza corect - adică dacă are continuitate.

Testarea se face folosind un dispozitiv dedicat.

De aici a pornit ideea proiectului meu: realizarea propriului meu [tester RJ45](https://www.optimusdigital.ro/ro/aparate-de-masura/4962-tester-rj45-rj11.html?search_query=rj45&results=22),
caruia i-am adus o serie de îmbunătățiri.

### Ce face dispozitivul?

Dispozitivul proiectat permite testarea cablurilor de rețea de tip **RJ45**,
oferind feedback vizual și auditiv privind corectitudinea conexiunilor dintre pini.

Prin simpla apăsare a unui buton, utilizatorul poate selecta tipul de cablu testat:
1. **Straight-through** - pentru conectarea dispozitivelor aflate pe *layere diferite* (ex: PC – switch)
2. **Crossover** - pentru conectarea dispozitivelor de *același layer* (ex: PC - PC)

După selectare, pe ecranul principal (128x160 SPI) este afișată o imagine cu ordinea corectă a firelor pentru tipul respectiv de cablu.



Rolul hardware-ului in testare:
- Se folosesc 2 socketi: unul dedicat pentru **sender**, iar celalalt pentru **receiver**
-  Fiecare soclu RJ-45 are 8 pini
- Fiecarui pin RJ-45 ii este asociat un LED de culoare verde care se va aprinde
    atunci cand semnalul transmis/primit pe pinul respectiv este de 1 logic.
- In momentul in care socket-ul de **receiver** receptioneaza **1 logic**, buzzer-ul va emite un beep scurt


Testarea efectiva presupune 2 verificari:
1. Se vor trimite semnale, secvential, iterand pinii **sender**-ului unul cate unul, cu mici pauze intre transmisii,
2. urmand un test final in care se vor activa simultan toti pinii **sender**-ului



Testar-ul poate fi oprită forțat, in orice moment,  prin apăsarea unui buton.

In timp ce display-ul pe SPI (de rezolutie mai mare)
afiseaza ordinea firelor in mufa RJ-45,
LCD-ul cu modul I2C va scrie pe ecran tipul de cablu **straight-through**/**crossover**
si indexul pinului de pe **sender** de pe care se trimit semnale
(e.g. *"Testing pin 1...8"*), sau mesajul *"Testing all pins"*.


### De ce este util?

Consider ca folosirea ecranelor face diferenta dintre un tester RJ-45 obisnuit
si device-ul.

Practic, este un instrument **"2 în 1"**: tester + ghid de conectare.

Sper ca dispozivitul pe care il proiectez
(imi propun sa ii fac si un **PCB compact**)
sa ajunga in mainile laborantilor de RL/CCNA1.
Acolo isi va atinge adevaratul potential.






## Descriere Generala


Schema bloc:

![img](./images/rj45-tester-schema-bloc.png)



## Hardware Design


### Lista Componente

- [Arduino Nano V3.0](https://www.emag.ro/placa-de-dezvoltare-nano-v3-0-atmega328p-ch340-cu-cablu-usb-1414dr/pd/DTDC88YBM/?ref=history-shopping_415312802_171246_1)
- 2x [Soclu RJ45](https://ardushop.ro/ro/fire-si-conectori/1000-soclu-rj45-6427854013521.html)
- 3x [74HC595 8-bit Shift Register](https://ardushop.ro/ro/circuite-integrate/1657-ic-shift-register-sn74hc595n-74hc595-6427854024978.html) (fiecare are 8 pini de iesiri)
- [74HC165 8-bit Shift Register](https://ardushop.ro/ro/electronica/683-74hc165-8-bit-shift-register-6427854008602.html) (8 pini de intrare)
- [LCD 16x02 cu interfata I2C](https://www.optimusdigital.ro/ro/optoelectronice-lcd-uri/2894-lcd-cu-interfata-i2c-si-backlight-albastru.html?search_query=0104110000003584&results=1)
- [Modul LCD SPI 128x160 cu adaptor microSD](https://ardushop.ro/ro/electronica/2124-modul-lcd-spi-128x160-6427854032546.html)
- [Card MicroSD 16 GB](https://www.optimusdigital.ro/ro/memorii/8678-card-microsd-original-de-16-gb-cu-noobs-compatibil-cu-raspberry-pi-4-model-b-varianta-bulk.html)
    - Nu am găsit un card mai mic 🙁
- 16x [LED Verde 3mm cu Lentile Difuze](https://www.optimusdigital.ro/ro/optoelectronice-led-uri/697-led-verde-de-3-mm-cu-lentile-difuze.html?search_query=0104210000006209&results=1)
- 16x Rezistente 220 Ω (pt LED-uri)
- [Modul Buzzer Pasiv](https://www.optimusdigital.ro/ro/componente-electronice/12598-modul-buzzer-pasiv.html?search_query=0104110000082985&results=1)
- 3x [Buton cu Capac Rotund](https://www.optimusdigital.ro/ro/butoane-i-comutatoare/1115-buton-cu-capac-rotund-alb.html?search_query=buton+cu+capac&results=29)
- Rezistente
- 3x Rezistente (de PULL-UP) de 220 Ω (pt butoane)
- 3 breadboard-uri 830 puncte