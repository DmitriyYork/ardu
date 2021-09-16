/* US AQL LEVEL 
 * Arduino DUE 
 * PM 1.0 "ОТЛ" 0-50,   "ХОР" 51-100,     "УДОВЛ" 101-150,      "НЕУДОВЛ" 151-200       "ПЛОХО"               "ОПАСНО"
 * РМ 2.5 "ОТЛ" 0-12.0, "ХОР" 12,1-35,4,  "УДОВЛ" 35,5-55.4,    "НЕУДОВЛ" 55.5-150.4,   "ПЛОХО" 150,5-250,4   "ОПАСНО" >250,5
 * РМ 10  "ОТЛ" 0-50,   "ХОР" 51-100,     "УДОВЛ" 101-150,      "НЕУДОВЛ" 151-200,      "ПЛОХО" 201-300.      "ОПАСНО" >301
 */
byte Seril[23]; //Массив данных

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial1.begin(9600); //Serial1 RX D19 TX D18
pinMode(13, OUTPUT); //LED мигалка, для подсветки циклов
digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial1.available()>0) {
    digitalWrite(13, HIGH);
    int i = 0;
    for(i=0; i<24; i++){
    Seril[i] = Serial1.read(); 
    }
    /* Debag
    Serial.print(Seril[i]); //Сбойный один из 10 кадров, причина не понятна
    Serial.print(", ");
    Serial.println("Stop arroy!");
    */
  
  int PM1_0 = ((Seril[10]<<8)+Seril[11]);
  int PM2_5 = ((Seril[12]<<8)+Seril[13]);
  int PM10_ = ((Seril[14]<<8)+Seril[15]); 
  Serial.print("PM_1.0: ");
  Serial.print(PM1_0);
  Serial.println(" ug/m3");
  Serial.print("PM_2.5: ");
  Serial.print(PM2_5);
  Serial.println(" ug/m3");
  Serial.print("PM_10: ");
  Serial.print(PM10_);
  Serial.println(" ug/m3");
      //}
  Serial.println("     End String!!!");
  digitalWrite(13, LOW);
}
else{
  Serial.println("Not Date");
  digitalWrite(13,LOW);
}
delay(1400);
}
