void setup(){
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  Serial.begin(9600);
}
String stringPi = "";
byte vectorIn[10];
String stringUser = "0123456789";
String stringComputer = "0123456789";
String UserComp = "0123456789";
String analogic0 = "x";
String uno1 = "1";
String cer0 = "0";

void loop(){

///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// Bloque 1
  for(int i=0;i<=10;i++)
    { vectorIn[i]=digitalRead(i+2); }
  int j = 0;
  for(int i=9;i>=0;i--){
    if(vectorIn[i]==1)
      { stringUser[j]=uno1[0]; }
    else
      { stringUser[j]=cer0[0]; }
    j++;
   }

///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// Bloque 2
  if(Serial.available())
    { stringPi = Serial.readStringUntil('\n'); }  else { stringPi = "0000000000"; }
  for(int i=0; i<=10; i++)
    { stringComputer[i] = stringPi[i]; }

///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// Bloque 3
  for(int i=0; i<10; i++){
    if(stringUser[i]==uno1[0] || stringComputer[i]==uno1[0])
      { UserComp[i] = uno1[0]; }
    else
      { UserComp[i]=cer0[0]; }
  }
 
///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// Bloque 4
  int dato = analogRead(A0); delay(40);
         if (dato > 691 && dato < 711) //1
    { analogic0="A"; }
  else if (dato > 521 && dato < 541) //2
    { analogic0="B"; }
  else if (dato > 417 && dato < 437) //3
    { analogic0="C"; }
  else if (dato > 347 && dato < 367) //4
    { analogic0="D"; }
  else if (dato > 296 && dato < 316) //5
    { analogic0="E"; }
  else if (dato > 259 && dato < 279) //6
    { analogic0="F"; }
  else if (dato > 229 && dato < 249) //7
    { analogic0="G"; }
  else if (dato > 205 && dato < 225) //8
    { analogic0="H"; }
  else if (dato > 186 && dato < 206) //9
    { analogic0="I"; }
  else if (dato > 173 && dato < 193) //10
    { analogic0="J"; }
  else                               //x
    { analogic0="x"; }

///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// Bloque 5
  int Dec=0;
  int peso;
  int jj=9;
  for(int i=0;i<10;i++){
      int prePeso=pow(2,jj);
      if (prePeso>2){ peso = prePeso+1; } else { peso = prePeso; }
      if(UserComp[i]==uno1[0])
        { Dec=Dec+peso; }
      else
        { Dec=Dec+0; }
      jj--;
  }

  char valorAnalogico=analogic0[0];
  Serial.write(valorAnalogico);
  Serial.print(Dec); //Verificar si no hay problemas en standalone
  Serial.write(" zzzzz\n");

}
