#ifndef SOFTWAREINTERRUPT_H
#define SOFTWAREINTERRUPT_H

#include <Arduino.h>

class Software_Interrupt
{
    public:
        Software_Interrupt(int Pin);
        virtual ~Software_Interrupt();
        void setup(int Mode=INPUT);
        void attachInterrupt(void (*interrupt_func)()=NULL,int Status=CHANGE);
        void detachInterrupt();
        void main();
    protected:
        
        
    private:
        void (*interrupt_handler)()=NULL;
        int STATUS;
        bool setup_finished=false;
        bool attach_finished=false;
        bool PIN_state;
        bool PIN_old_state;        
        int PIN;
        //static void pass(){};

};

#endif // OPTICINTERRUPT_H
