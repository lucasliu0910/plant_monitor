#define pumpPin 7    //水泵腳位
#define SensorPin A0  //土壤濕度感測器腳位

int sensorValue; 
int watering; 

//讀取土壤濕度感測器
void ReadSensor(){
  sensorValue=analogRead(SensorPin); //讀取感測器回傳值
  Serial.print("value:");
  Serial.println(sensorValue);
}

void setup() {
  
  pinMode(SensorPin,INPUT);
  pinMode(pumpPin,OUTPUT);
  digitalWrite(pumpPin,HIGH);
  
  Serial.begin(115200);
}

void loop() {

  //讀取土壤濕度
  ReadSensor();

  //判斷是否需要澆水
  if(sensorValue<900){
    Serial.println("water");
    digitalWrite(pumpPin,LOW);
    delay(500);
    digitalWrite(pumpPin,HIGH);
    delay(500);
    watering=1; //用來記錄澆水
  }
  watering=0; //將澆水紀錄歸零
  
  //delay(60000);

  for (int i = 0; i<60; i++)
  {
    Serial.print(".");
    delay(1000); //1 sec
    if (( i % 10) == 9) Serial.println();
  }
}
