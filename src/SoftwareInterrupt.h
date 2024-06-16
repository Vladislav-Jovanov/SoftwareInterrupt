#ifndef SOFTWAREINTERRUPT_H
#define SOFTWAREINTERRUPT_H

#include <Arduino.h>

class Software_Interrupt
{
    public:
        Software_Interrupt(int Pin);
        virtual ~Software_Interrupt();
        void setup_SI(int Mode=INPUT);
        void attach_SI(void (*interrupt_func)()=NULL,int Status=CHANGE);
        void detach_SI();
        void main();
    protected:
        
        
    private:
        void (*interrupt_handle)();
        int STATUS;
        bool setup=false;
        bool attach=false;
        bool PIN_state;
        bool PIN_old_state;        
        int PIN;
        //static void pass(){};

};

#endif // OPTICINTERRUPT_H
