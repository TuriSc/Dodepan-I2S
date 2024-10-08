/* MPR121 functions */

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "mpr121.h"         // https://github.com/antgon/pico-mpr121
#include <config.h>
#include "touch.h"

struct mpr121_sensor mpr121;

void mpr121_i2c_init(){
    i2c_init(MPR121_I2C_PORT, MPR121_I2C_FREQ);
    gpio_set_function(MPR121_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(MPR121_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(MPR121_SDA_PIN);
    gpio_pull_up(MPR121_SCL_PIN);

    mpr121_init(MPR121_I2C_PORT, MPR121_ADDRESS, &mpr121);
    mpr121_set_thresholds(MPR121_TOUCH_THRESHOLD,
                          MPR121_RELEASE_THRESHOLD, &mpr121);
    
    mpr121_enable_electrodes(12, &mpr121);
}


// Perform a second pass of debouncing to better deal with long presses
static bool debounced_states[12] = {false};
static int debounce_counters[12] = {0};
static inline bool mpr121_debounce(uint8_t i, bool is_touched) {
    if (is_touched) { // Do not filter positive readings
            debounced_states[i] = true;
            debounce_counters[i] = 0;
        } else if (!is_touched && debounced_states[i]) {
            debounce_counters[i]++;
            if (debounce_counters[i] >= MPR121_DEBOUNCE_THRESHOLD) {
                debounced_states[i] = false;
                debounce_counters[i] = 0;
            }
        }

    return debounced_states[i];
}

void mpr121_task(){
    bool is_touched;
    static bool was_touched[12];
    for(uint8_t i=0; i<12; i++) {
        mpr121_is_touched(i, &is_touched, &mpr121);
        is_touched = mpr121_debounce(i, is_touched);
        if (is_touched != was_touched[i]){
            if(time_us_32() < 500000) return;  // Ignore readings for half a second,
                                               // allowing the MPR121 to calibrate.
            if (is_touched){
                touch_on(i);
            } else {
                touch_off(i);
            }
            was_touched[i] = is_touched;
        }
    }
}