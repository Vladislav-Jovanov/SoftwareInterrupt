#include <SoftwareInterrupt.h>

Software_Interrupt myInterrupt(5);


void Interrupt_Action(){
     Serial.println("Interrupt happened");
 }

void setup() {
  // put your setup code here, to run once:
  myInterrupt.setup_SI();
  myInterrupt.attach_SI(&Interrupt_Action, CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
  myInterrupt.main();
}
