#define DEBUG

const int ir1 = 3;
const int ir2 = 5;
const int ir3 = 9;
const long l1=400000, l2=400000;
unsigned long t1, t2, t3;
double v1, v2;
double g; //(mm/us/us)
void setup() {
  // put your setup code here, to run once:
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:x
  retry:
  Serial.println("start");
  while(digitalRead(ir1));
  t1=millis();
  while(digitalRead(ir2));
  t2=millis();
  while(digitalRead(ir3))if(!digitalRead(ir1))goto retry;
  t3=millis();
  v1=l1/(double)(t2-t1);
  v2=l2/(double)(t3-t2);
  g=2*(v2-v1)/(t3-t1);
  #ifdef DEBUG
  Serial.println(t1);
  Serial.println(t2);
  Serial.println(t3);
  Serial.println(v1);
  Serial.println(v2);
  Serial.println(g);
  #endif
  Serial.print("g = ");
  Serial.println(g);
}
