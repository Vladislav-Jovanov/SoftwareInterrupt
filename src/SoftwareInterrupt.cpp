#include "SoftwareInterrupt.h"
#include "Arduino.h"

Software_Interrupt::Software_Interrupt(int Pin){
    PIN=Pin;
}


Software_Interrupt::~Software_Interrupt(){
    //dtor
}

void Software_Interrupt::setup(int Mode){
    if (Mode!=OUTPUT){    
        pinMode(PIN, Mode);
        setup_finished=true;
    }else{
        setup_finished=false;    
    }                              
}

void Software_Interrupt::attachInterrupt(void (*interrupt_func)(),int Status){
  if (interrupt_func==NULL){
    attach_finished=false;
  }else{
    interrupt_handler=interrupt_func;
    STATUS=Status;
    attach_finished=true;
    PIN_old_state=digitalRead(PIN);
  }
}
void Software_Interrupt::detachInterrupt(){
  attach_finished=false;
  interrupt_handler=NULL;
}

void Software_Interrupt::main(){
    if(setup_finished && attach_finished){
       PIN_state=digitalRead(PIN);
       if ((STATUS==RISING & PIN_old_state==LOW & PIN_state==HIGH)|| (STATUS==FALLING & PIN_old_state==HIGH & PIN_state==LOW) || (STATUS==CHANGE & PIN_old_state!=PIN_state)){
            PIN_old_state=PIN_state;             
            interrupt_handler();             
       }
    }                               
}

