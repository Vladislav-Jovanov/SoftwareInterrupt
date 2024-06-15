#include "SoftwareInterrupt.h"
#include "Arduino.h"

Software_Interrupt::Software_Interrupt(int Pin){
    PIN=Pin;
}


Software_Interrupt::~Software_Interrupt(){
    //dtor
}

void Software_Interrupt::setup_OI(PinMode Mode){
    if (Mode!=OUTPUT){    
        pinMode(PIN, Mode);
        setup=(setup & true);
    }else{
        setup=false;    
    }                              
}

void Software_Interrupt::attach_SI(void (*interrupt_func)(),PinStatus Status){
  if (interrupt_func==NULL){
    attach=false;
  }else{
    interrupt_handle=interrupt_func;
    STATUS=Status;
    attach=true;
    PIN_old_state=digitalRead(PIN);
  }
}
void Software_Interrupt::detach_SI(){
  attach=false;
}

void Software_Interrupt::main(){
    if(setup & attach){
       PIN_state=digitalRead(PIN);
       if ((STATUS==RISING & PIN_old_state==LOW & PIN_State==HIGH)|| (STATUS==FALLING & PIN_old_state==HIGH & PIN_State==LOW) || (STATUS==CHANGE & PIN_old_state!=PIN_State)){
            PIN_old_state=PIN_State;             
            interrupt_handle();             
       }
    }                               
}

