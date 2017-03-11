//**************************** Kodikas sinagermou gia SG ****************************//
//***********************************************************************************//
//********* Erotiseis sto mail yfantis@ceid.upatras.gr ROTATE ELEUTHERA!! ***********// 
//O kodikas den einai veltistos, alla einai mia arxi gia na katalavete kapoai pio vasika pragmata
//Osoi eiste pio advanced isos na varetheite, opote mporeitai na parete oti sas xreiazetai kai na proxorisete

//Define ta vasika pin mou gia na ta thimamai pou programmatizo, voleuoun giati thimasai ti exeis kanei, 
//se periptosi pou exeis mia allagi den xreiazetai na psaxneis pou thes na tin kaneis kai tin kaneis pio amesa episis einai kaliteri programmatistiki texniki
#define pirPin    9
#define buzzer    7
#define analogPin 0
#define piezoTTL  13 
//I sosti xrisi tha itan na eixame valei tetragoniko palmo, eks'ou kai to TTL 
//alla epeidi tha itan enoxlitikos o thorivos xirismopoiisa stathero reuma
//I sosti xrisi einai gia output na valete na grafei me tin sinartisi tone pou paragei tetragoniko palmo 
//kai na eisagetai interrupt gia to diavasma apo to arduino.

//Einai oi metavlites gia tin metrisi tou xronou me miliseconds
unsigned long current = millis();
unsigned long previous_pir = millis();
unsigned long diff;

//Kaneis setup ta pin kai mas dixnei oti o sensoras einai etoimos 
void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(piezoTTL, OUTPUT);

  Serial.begin(9600);
  Serial.println("PIR ready");
}

//To kaloume opote entopizoume kinisi me ton PIR
void motion()
{
  Serial.println("KLEFTIS!!!!");
}

//I sinartisi tou buzzer kai tin kaloume opote theloume na kanoume thorivo
void buzz()
{
  tone(buzzer, 1000); //I sinartisi tou Arduino prokalei mia sixnotita sto sigkekrimeno PIN 
  delay(1000);        
  noTone(buzzer);     
  delay(1000);        
  Serial.println("IOUIOUIOU!!");
}

//I sinartisi tou piezoelektrikou
void piezo()
{
  if (analogRead(analogPin) > 500)
  {
    Serial.println("Eksoporta!!");
    buzz();
  }
digitalWrite(piezoTTL, LOW); //Katevazoume tin tasi tou PIn gia na diasfalisome kaliteri leitourgia
}
  
void loop()
{
  digitalWrite(piezoTTL, HIGH); //Grafoume high sto pin tou piezoelektrikou
  piezo();

  int pirVal = digitalRead(pirPin); //Diavazoume tin metrisi tou PIR 
  current = millis(); //Apothikeuoume tin metrisi tou epeksergasti
  diff =  current - previous_pir; //Ipologizoume tin diafora
  if(pirVal == HIGH && diff >= 14000) //An i diafora einai einai megaliteri apo 14s(14.000ms) tote einai egkiri mias kai exei 14s recharge time
  {
    previous_pir = millis();
    motion();//kalo tis sinartiseis gia ton sinagermo
    buzz();
  }
  current = millis();//apothikeuo tin torini xroniki stigmi
}
