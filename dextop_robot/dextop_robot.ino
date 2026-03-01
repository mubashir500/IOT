int n1 = 8;
int n2 = 9;
int n3 = 10;
int n4 = 11;

int irf = 3;
int ird = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(N4, OUTPUT);
  pinMode(irf, INTPUT);
  pinMode(ird, INTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int front_ir = digitalRead(irf);
  int down_ir = digitalRead(ird);

  if(front_ir == 0){
    pinMode(n1, HIGH);
    pinMode(n2, LOW);
    pinMode(n3, HIGH);
    pinMode(n4, LOW);
  }
  else if(front_if == 1){
    pinMode(n1, HIGH);
    pinMode(n2, LOW);
    pinMode(n3, LOW);
    pinMode(n4, HIGH);
  }
  if(down_ir == 0){
    while(down_ir == 0){
      pinMode(n1, LOW);
      pinMode(n2, HIGH);
      pinMode(n3, LOW);
      pinMode(n4, HIGH);
    }
    delay(500);
    pinMode(n1, HIGH);
    pinMode(n2, LOW);
    pinMode(n3, LOW);
    pinMode(n4, HIGH);
  )



}
