# theremin
Basic theremin made with a photoresistor, a passive buzzer and an led.

The frequency of sound by the buzzer changes with respect to the position of your hand!



Execution procedure:
1. The code goes into calibration mode and senses the range of values that will be possible and defines a range accordingly
2. The led will turn off and the theremin is ready to be used (along with the pitch of the buzzer, the brightness of led changes too) 

NOTE- Do NOT use the pin #3 and #11 for analogWrite() (ie the led) because the PWM interferes with the timer of the tone() function!
