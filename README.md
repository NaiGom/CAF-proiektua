# CAF-proiektua

Egileak: Eneko Sanz, Iker Sarasola eta Unai Gomez

# SARRERA

Don Boscoko ikasle-talde bat gara, eta proiektu bat egin dugu CAF enpresarentzat. Trenen abiaduraren simulazioan oinarritzen da gure proiektua. Gure proiektuaren helburua maiztasun desberdinak sartuz gero, trenak abiadura desberdinak detektatzea da. Hortaz aparte, trenaren norantza aldatzea lortu behar dugu.

# ARAZOAREN KONTEXTUALIZAZIOA

CAF-eko langileek kontaktatu ziguten trenean abiadurarekin frogak egiteko erabiltzen zuten  modua oso deserosoa zelako eta bi pertsonen beharra zutelako, bakoitza trenaren alde batean, bat frekuentziak bidaltzeko eta bestea gidariaren lekutik frogaketak egiteko. 
Arazo hau konpontzeko BUENA ONDA enpresakoak produktu bat sortu dugu eta produktu honekin lortzen da langile bakar batek frogaketak egiten ahal izatea modu oso berritzaile eta erosoan. Hainbesteko hobekuntza da mobila edo ordenagailu baten beharra besterik ez dutela behar beraiek nahi dituzten frogaketak egiteko. 


# MATERIAL ZERRENDA

Dokumentu honetan erakutsiko dizugu CAF enpresarentzat egin genuen proiektua egiteko behar duzun materiala eta egin beharreko pausuak.

-  RaspberryPI  1B +  honen elikatze iturria.

![rasberry Pi 1B](https://user-images.githubusercontent.com/98529068/154254936-fa040963-2bd5-4787-af55-68eb37bb5bb6.jpg)

![Rasberry Pi elikatze iturria](https://user-images.githubusercontent.com/98529068/154255028-2c7a8f42-36ed-4f33-8595-8bfd65c25953.jpg)

RaspberryPI-a  Node-Red instalatzeko  eta WiFi sarea sortzeko erabili dugu.
Elikatze iturria RaspberryPI-a elikatzeko.

- MicroSD txartela

![MicroSD](https://user-images.githubusercontent.com/98529068/154263610-81146313-2e14-4e58-b6af-fd639c224e4d.jpg)

Raspberry Pi batek micro SD txartel bat erabiltzen du disko gogor gisa eta edozein informazio gordetzeko.

- WiFi egokitzailea.

![Wifi adaptadorea](https://user-images.githubusercontent.com/98529068/154264082-ebc42ccc-f5ba-4549-8943-bc583af4821e.jpg)

WiFi sarearentzako erabili beharko duzu .

- Elikatze iturria

![Elikatze iturria](https://user-images.githubusercontent.com/98529068/154264595-50a81ad8-21b3-4333-a89b-4aefba5bc885.jpg)

Saretik 230V hartzen ditu eta 5 pinetan banatzen da (5V, GND, -15V eta 15V). Bere funtzioa, PCB plakaren konponenteak elikatzea da.

- AD9833 TXIPA

![ad9833](https://user-images.githubusercontent.com/98529068/154265437-8c7ac05a-d526-4afa-a6f5-c48bfb1cd1b8.jpg)

Uhin sinusoidalak, karratuak edo triangeluarrak sortzen dituen txipa da.

- ESP8266

![esp8266](https://user-images.githubusercontent.com/98529068/154266413-6cf8d5e4-c382-42ca-9f1c-6111e0489eaf.jpg)

Arduinoren antzeko garapen-plataforma da, bereziki gauzen Internetera bideratua. AD9833 txiparekin bateratu dugu.

- 2 errele

![rele 5v](https://user-images.githubusercontent.com/98529068/154269593-ec46f5e9-4ca5-4766-8370-a7afacfd7685.jpg)

Trenaren norantza aldatzeko erabili dugu.

- Kaxa

![Caja RS PRO de Aluminio Presofundido Gris, 125 x 80 x 57mm, IP66](https://user-images.githubusercontent.com/98529068/154273826-e4f98575-cc76-4c9b-b829-b4e8fd0789db.jpg)

Osagai guztiak sartzeko (Raspberry, PCB plaka...) erabili dugu.

- ...
 
# Erronkaren zatiak 

- WIFI SAREA

 Lehen urratsa, Raspberry Pi-aren sistema eragilea SD txartelera instalatzea izan da. Gero, WiFi sare pribatu bat sortzen hasi gara komandu batzuen bitartez. WiFi sare hori sortu dugu, CAF-eko langileek bakarrik erabil dezaten.
 Hona hemen wifia sortzeko pausuak: https://learn.pi-supply.com/make/how-to-setup-a-wireless-access-point-on-the-raspberry-pi/

![micro sd +raspberry](https://user-images.githubusercontent.com/98529068/154331566-b8e9e13b-ecae-4901-88dd-c0db344f4cce.jpg)
![red wifi](https://user-images.githubusercontent.com/98529068/154333900-24a9c113-6050-4f6f-bd6f-ba7cc01e4186.png)

- INTERFAZ ERABILTZAILEA

Proiektukoaren zati garrantzitsua da, CAF-eko langileek honekin frekuentzia eta norabidea aldatu dezaketelako. Hau egiteko Raspberryan Node Red eta Node Red Dashboard instalatu behar dituzu.
Honetaz aparte ere, MQTT protokoloa instalatu behar duzu Dashboard-etik ESP8266-ra informazioa bidaltzeko. Enlaze hontan sartu deskargatzeko: https://www.luisllamas.es/como-instalar-mosquitto-el-broker-mqtt/.

![image](https://user-images.githubusercontent.com/96518844/154533880-6dac939a-9b4b-4e4b-950d-050008bc9168.png)


# NOLA BIDALI FREKUENTZIAK AD9833 txipera?

![image](https://user-images.githubusercontent.com/96518844/154534203-f6a3d59a-d37a-459e-aa68-7e4d10d3bb24.png)


Node Red Dashboardetik trenari frekuentzia edo norabidearen informazioa bidaltzeko, MQTT protokoloa eta ESP8266 txipa erabili behar dira (Badaude pausu hau egiteko beste hainbat modu baina guk horrela egitea gomendatzen dugu). Kontuan izan txip hau WiFi bidez doala eta ESP8266-a WiFI ra konektatu ahal izateko Arduino programan libreriak sartu eta sortutako access pointeko datuak sartu behar direla (SSID, Pasahitza eta Raspberry Pi-aren IP estatikoa).


![image](https://user-images.githubusercontent.com/96518844/154539431-b9baa7c8-2d1f-4645-96bf-9c5e2230dec0.png)                       ![image](https://user-images.githubusercontent.com/96518844/154539735-9f5c4d49-3eed-418e-b2af-9d08b99cedc4.png)




Dashboardean frekuentzia edo norabidearen botoia sakatzean, MQTT irteeraren bidez dagokion TOPIC-a publikatu egiten da. Arduinoko callback funtzioarekin, ESP8266 txipa subskribitu egiten da TOPIC-era eta aldi berean topicaren barruko PAYLOAD edo MEZUA jasotzen du bytetan. Hau String modura pasatzeko honako for funtzioa erabiltzen dugu: 

![image](https://user-images.githubusercontent.com/96518844/154540684-2d904043-2bef-42a4-a093-82635df3ec1f.png)

(Noski, payload string bezala deklaratuta lehenago)

Dagoeneko, payload-a String moduan dugu baina frekuentziaren kasuan Float modura pasatu behar da komando hau erabiliz (freqF lehenago deklaratu):

![image](https://user-images.githubusercontent.com/96518844/154541396-1b888e1b-3557-4f1c-a3bc-62d567364bad.png)


Beheko argazki honetan ikusten da nola programatu TOPIC-etara subskribitzeko (Kontuan izan Void reconnect funtzioan deklaratu behar dituzula MQTT irteerako topicak):

![image](https://user-images.githubusercontent.com/96518844/154534766-449f8332-7b4b-4f22-bfb1-8c2420bae349.png)

![image](https://user-images.githubusercontent.com/96518844/154542746-8c77c28e-3ca6-4035-a816-a07881ea50be.png)


- PULTSU SORTZAILEA

Pultsuak sortzeko AD9833 txipa erabili genuen. ESP8266-tik etortzen den frekuentzia AD9833 txipara bidaltzen dio, pultsu hoiek desfasatzen ditugu eta gero anplifikatzen ditugu. Ondoren, pultsu hoiek erreletara joango dira eta errele hoiek trenaren norabidea aldatuko dute. Azkenik, irteeran bi seinale izango ditugu 90 gradutara desfasatuta. 

![pcb](https://user-images.githubusercontent.com/98529068/154375899-683e6553-bf27-47da-b571-0c5b25836328.PNG)

Hortaz aparte, elikatze iturri bat daukagu 230V-tara elikatuta. Honek, hainbat pin ditu boltai desbedinarekin. Pin hoiek, erreleak, ad9833-a, Raspberry-a, ESP8266-a eta txipak elikatzeko erabiltzen dira.

Hurrengo pausoa, PCB plaka diseinatzea da. Horretarako, proteusaren konexioak hartzen ditugu eta PCB plaka diseinatzen dugu. 

![image](https://user-images.githubusercontent.com/98529068/154376587-ba6952da-8f41-4791-952c-212b02bd5442.png)

Ikusten den bezala, konexio gorriak eta urdinak daude. Horrek esan nahi du, bi aldetatik soldatuta dagoela. Gorriak plakarean goiko aldean soldatzen dela esan nahi du. Eta urdina berriz, behekaldean. Bestalde, ESP8266 eta AD9833-en package-ak sortu ditugu. Kontuan izan behar da, PCB plaka egiterakoan konponente hauen neurriak hartzea eta zuloak aldatzea.

![download](https://user-images.githubusercontent.com/98529068/154375749-ff506a88-9464-46df-948a-976cf8cb3a05.jpg)

- MUNTAKETA

Bukatzeko, Pcb-a, raspberry-a eta elikatze iturria bateratu behar dira kaxa batean. Horretarako, muntaketa egiteko zerrendako kaxa beharko duzu. Honi zuloak egin behar dizkiozu brokarekin eta ondoren lijatu behar bada (Metrica 3 ko zuloak egiteko 3,25mm-ko broka gomendatzen dizugu). Kokapena, noski, hoberen iruditzen zaizun bezela. 

![IMG20220216202026](https://user-images.githubusercontent.com/96518844/154363062-49a24bb2-a8ce-4e14-9180-f6db8bbae1b5.jpg)

