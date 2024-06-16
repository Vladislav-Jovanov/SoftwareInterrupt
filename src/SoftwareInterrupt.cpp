#include "SoftwareInterrupt.h"
#include "Arduino.h"

Software_Interrupt::Software_Interrupt(int Pin){
    PIN=Pin;
}


Software_Interrupt::~Software_Interrupt(){
    //dtor
}

void Software_Interrupt::setup_SI(int Mode){
    if (Mode!=OUTPUT){    
        pinMode(PIN, Mode);
        setup=true;
    }else{
        setup=false;    
    }                              
}

void Software_Interrupt::attach_SI(void (*interrupt_func)(),int Status){
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
       if ((STATUS==RISING & PIN_old_state==LOW & PIN_state==HIGH)|| (STATUS==FALLING & PIN_old_state==HIGH & PIN_state==LOW) || (STATUS==CHANGE & PIN_old_state!=PIN_state)){
            PIN_old_state=PIN_state;             
            interrupt_handle();             
       }
    }                               
}

