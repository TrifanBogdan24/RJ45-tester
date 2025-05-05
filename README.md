# RJ45 Tester


## Introducere


<!-- Care a fost ideea de la care ati pornit? -->
Va amintiti primul lab de RL?

In cadrul acestui laborator, am invatat sa fac propriul cablu UTP de Ethernet,
pentru a conecta 2 dispozitive.
Dupa acest proces (cunoscut sub numele de "sertizare"), trebuie sa testam
ca conectivitatea cablului.

<!-- Ce face? -->
In cadrul proiectului de PM, eu imi propun sa realizez acest intrument de testare,
[Tester Continuitate RJ45](https://www.optimusdigital.ro/ro/aparate-de-masura/4962-tester-rj45-rj11.html?search_query=rj45&results=22).
Astfel deci, dispozivitul pe care l-am proiectat isi propune sa verifice.

## Descriere Generala




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
- 16x [LED Verde](https://www.optimusdigital.ro/ro/optoelectronice-led-uri/697-led-verde-de-3-mm-cu-lentile-difuze.html?search_query=0104210000006209&results=1)
- [Modul Buzzer Pasiv](https://www.optimusdigital.ro/ro/componente-electronice/12598-modul-buzzer-pasiv.html?search_query=0104110000082985&results=1)
- Rezistente
- 3 breadboard-uri 400 puncte