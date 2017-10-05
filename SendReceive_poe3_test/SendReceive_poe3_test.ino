/*

I intentionally use the const byte construct here
instead of #define. It's less dangerous (no name collision possible)
and safer since variables have scope.
*/
const byte IR = A0;
long prev_t = 0;
int ir_value = 100;
byte cmd_id = 0; 

void setup() {
  Serial.begin(9600);
}

void loop() {

 for (int i=0; i <= 255; i++){
  if(i <= 254) {
    delay(50);
    ir_value = analogRead(IR);
    cmd_id = Serial.read();
    Serial.print(ir_value);
    Serial.print(" , ");
    Serial.print("1\n");
    delay(50);
  } else {
    ir_value = analogRead(IR);
    cmd_id = Serial.read();
    Serial.print(ir_value);
    Serial.print(" , ");
    Serial.print("2\n");
    delay(50);
   }
  } 
}

