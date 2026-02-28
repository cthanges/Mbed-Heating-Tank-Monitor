#include "mbed.h"

#define LED p5
#define TEMP p15
#define LEVEL p16
#define SPEAKER p21

AnalogIn temp(TEMP);
AnalogIn level(LEVEL);

DigitalOut led(LED);
PwmOut speaker(SPEAKER);

float lowValue;
float highValue;
float tempVal;
float levelVal;
float i;

int main(){
    speaker.write(0.5); // 50% duty cycle for audible tone

    while (1){
        // Read the temperature and level sensor values
        levelVal = level.read();
        tempVal = temp.read();

        // --- LOW TANK LEVEL ---
        while(levelVal < 0.75) { // Tank less than 3/4 full
            led = !led; // Flash LED

            // One cycle of warble (~1 sec)
            for(i = 0.0; i < 1.0; i += 0.05) {
                float period = 0.010 - (0.008 * i);
                if(period < 0.002){
                    period = 0.002; // Clamp to safe min
                }
                speaker.period(period);
                wait_ms(50);
            }

            levelVal = level.read(); // Re-read tank level
        }

        // Tank is full, check temperature
        led = 0; // LED off

        tempVal = temp.read(); // Re-read temperature
        
        if(tempVal > 0.66){ // High temp
            highValue = 0.001; // ~1000 Hz
            lowValue = 0.005; // ~200 Hz
        }
        else if(tempVal >= 0.33){ // Good/mid temp
            highValue = 0.002; // ~500 Hz
            lowValue = 0.002; // ~500 Hz
        }
        else{ // Low temp
            highValue = 0.005; // ~200 Hz
            lowValue = 1.0; // inaudible
        }

        // Play the tone based on temperature
        speaker.period(highValue);
        wait_ms(500);
        speaker.period(lowValue);
        wait_ms(500);
    }
}