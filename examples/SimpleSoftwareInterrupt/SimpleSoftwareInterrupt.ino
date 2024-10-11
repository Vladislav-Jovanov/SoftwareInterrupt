#include <SoftwareInterrupt.h>

Software_Interrupt myInterrupt(5);


void Interrupt_Action(){
     Serial.println("Interrupt happened");
 }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myInterrupt.setup(INPUT);
  myInterrupt.attachInterrupt(&Interrupt_Action, CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
  myInterrupt.main();
}
