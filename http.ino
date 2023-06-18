#include<WiFi.h>
#include <HTTPClient.h>
const char ssid[]="WiFi網路名稱"; //WiFi網路名稱
const char pwd[]="WiFi密碼"; //WiFi密碼

//#define pumpPin 21    //水泵腳位
//#define SensorPin A0  //土壤濕度感測器腳位

//int sensorValue; 
//int watering; 

String url = "https://script.google.com/macros/s/AKfycbxjDUzod3eEpf8Rzy09FN5ec-RmPss68hHid6G6yawbi9mjZM1QIwkOC4UxaWoaBYbx/exec"; //Google sheet API


//讀取土壤濕度感測器
//void ReadSensor(){
//  sensorValue=analogRead(SensorPin); //讀取感測器回傳值
//  Serial.print("value:");
//  Serial.println(sensorValue);
//}


//將資料上傳ThinkSpeak
void UploadData(){ 
  
  //建立一個網頁
  HTTPClient http;  

  //把土壤濕度數值寫入網址
  String url1= url+"?humidity="+(int)sensorValue+"& watering="+(int)watering;

  //提交網址
  http.begin(url1);

  //讀取網頁內容
  int httpCode = http.GET();
  if(httpCode == HTTP_CODE_OK){
    String payload = http.getString();
    Serial.print("網頁內容=");
    Serial.println(payload);
  } 
  else{
     Serial.println("網路傳送失敗");
  }

  //關閉網頁
  http.end(); 
  
}

void wifi_setup() {
  
  //pinMode(SensorPin,INPUT);
  //pinMode(pumpPin,OUTPUT);
  //digitalWrite(pumpPin,HIGH);
  
  //Serial.begin(115200);
  
  WiFi.mode(WIFI_STA); //設置WiFi模式
  WiFi.begin(ssid,pwd); 

  Serial.print("WiFi connecting");

  //當WiFi連線時會回傳WL_CONNECTED，因此跳出迴圈時代表已成功連線
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);   
  }

  Serial.println("");
  Serial.print("IP位址:");
  Serial.println(WiFi.localIP()); //讀取IP位址
  Serial.print("WiFi RSSI:");
  Serial.println(WiFi.RSSI()); //讀取WiFi強度

}

//void loop() {

  //讀取土壤濕度
//  ReadSensor();

  //判斷是否需要澆水
//  if(sensorValue<900){
//    Serial.println("water");
//    digitalWrite(pumpPin,LOW);
//    delay(500);
//    digitalWrite(pumpPin,HIGH);
//    delay(500);
//    watering=1; //用來記錄澆水
//  }
//  UploadData(); //上傳資料
//  watering=0; //將澆水紀錄歸零
  
//  delay(60000);
//}
