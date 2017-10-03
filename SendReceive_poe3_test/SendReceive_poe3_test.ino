/*

I intentionally use the const byte construct here
instead of #define. It's less dangerous (no name collision possible)
and safer since variables have scope.
*/
const byte IR = A0;
long prev_t = 0;
int ir_value = 100;
byte cmd_id = 0; 

String result="";

void setup() {
  Serial.begin(9600);
}

void loop() {

 for (int i=0; i <= 255; i++){
  if i <= 254;{
    ir_value = analogRead(IR);
    cmd_id = Serial.read();
    result = result + "IR reads: " + pot_value + "," + 1;
    Serial.println(result);
    result = "";
    delay(50);
  }
   else:{
    ir_value = analogRead(IR);
    cmd_id = Serial.read();
    result = result + "IR reads: " + pot_value + "," + 2;
    Serial.println(result);
    result = "";
    delay(50);
   }
   }
   
 }

