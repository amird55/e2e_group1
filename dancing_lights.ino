#define btnPin_R 2
#define btnPin_G 3
#define btnPin_B 4
#define btnPin_Y 12

#define ledPin_R 6
#define ledPin_B 9
#define ledPin_L 10
#define ledPin_U 11

#define BTN_NUM 4

int btns[BTN_NUM]={btnPin_R,btnPin_G,btnPin_B,btnPin_Y};
int leds[BTN_NUM]={ledPin_R,ledPin_B,ledPin_L,ledPin_U};


int toShow[8]={0,1,2,3,0,3,0,2};
/*
 * כל חצי שניה נורה אחרת נדלקת (והקודמת נכבית)
 * 
 * קל לשנות את סדר ההדלקה, אם רוצים
 */

void setup() {
  for(int k=0;k<BTN_NUM;k++){
//    pinMode(btns[k],INPUT_PULLUP);
    pinMode(leds[k],OUTPUT);
    digitalWrite(leds[k],LOW);
  }
}

int LedIndex=0;
int currentLed=0;
void loop() {
    currentLed=toShow[LedIndex];
    digitalWrite(leds[currentLed],HIGH);
    delay(300);
    digitalWrite(leds[toShow[LedIndex]],LOW);
    LedIndex=(LedIndex+1) % 8;
}
