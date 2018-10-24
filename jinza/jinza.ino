//#define DEBUG
unsigned long t1=0, t2=0, t0=0, i=0;
unsigned long l=420;
double g, g_avg;
const double pi=3.1415926535897932384626;
void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  Serial.begin(9600);
  while(digitalRead(3));
  while(!digitalRead(3));
  t0=millis();
  delayMicroseconds(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(3));
  while(!digitalRead(3));
  t1=millis();
  delayMicroseconds(10000);
  i++;
  g=l*pi*pi/(t1-t2)/(t1-t2)*1000;
  g_avg=l*pi*pi/((t1-t0)/i)/((t1-t0)/i)*1000;
  Serial.println(g);
  Serial.println(g_avg);
  while(digitalRead(3));
  while(!digitalRead(3));
  t2=millis();
  delayMicroseconds(10000);
  g=l*pi*pi/(t2-t1)/(t2-t1)*1000;
  i++;
  g_avg=l*pi*pi/((t2-t0)/i)/((t2-t0)/i)*1000;
  Serial.println(g);Serial.println(g_avg);
  #ifdef DEBUG
    Serial.println(t0);
    Serial.println(t1);
    Serial.println(t2);
    Serial.println(i);
    Serial.println(pi);
  #endif
}
