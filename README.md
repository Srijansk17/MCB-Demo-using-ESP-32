This Project is to mimic the house system for showing the working of an MCB.
the microcontroler simulates random light blinks that shall stop if the MCB is tripped which is read by the microntroller as a signal
- Note that MCB itself isn't cutting any supply here, it is just an input signal to the Microcontroller
This mini circuit is to demonstrate the internals of the mcb and how its disconneting the lines when its mechanical parts are triggered to move

follow the connections from the connections.txt file for the GPIO pins of ESP32 to leds and the MCB
preferably use ArduinoIDE with your ESP32 to sktech the code and the prop for MCB working is ready

