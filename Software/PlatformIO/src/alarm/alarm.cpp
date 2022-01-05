
#include "alarm/alarm.h"
#include "lights/Lights.h"
#include "co2/co2.h"
//#include "buzzer.h"



//Hysterese 20ppm, um schwingen zu verhindern

ALARM :: ALARM(int low_red_value, int hysterese, int tone, int pin_buzzer)  : BUZZER(pin_buzzer ,tone)
    {
        clearBuzzer();
        alarm_value = low_red_value;
    }

void ALARM::checkAlarm (int co2_val)
    {
        if ( ((co2_val) > alarm_value + 20) && alarm == false )
        {
            {
                alarm = true;
                setBuzzer();
            }
           /* if ( ((co2_val) > alarm_value + 20) && alarm == true )
            {
                setBuzzer();
            }*/
        }
        else 
        {
            
                if ( ((co2_val) < alarm_value - 20) && alarm == true )
                {               
                clearBuzzer();
                alarm = false;
                }
                /*
                if ( ((co2_val ) < alarm_value -20 ) && alarm == false )
                {
                    clearBuzzer();
                }*/
                
        }   

       
    }    

