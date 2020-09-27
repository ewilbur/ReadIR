The `ReadIR` class
==================

`ir_remote_button_t`: An enumerated type representing a possible button press on the remote. 
The order is mostly from left to right top to bottom, however, `ZERO` was placed next to the rest
of the numbers because it allows for easier checks of whether the user entered a number or not.
The order doesn't really matter and you are free to change it without breaking anything. 

`decode_ir_signal()`: Translates the raw IR signal to `ir_remote_button_t`.

`ir_signal_t`: An `unsigned long` meant to represent the data received.

`receive_ir_signal()`: Reads an input from the IR sensor. If none are present, it will wait
until one is detected. If the signal read results in `results.overflow` being set, will try
again. Basically, call this and it will return the first valid button press possible.

`ReadIR()`: Constructor using the default IR pin defined at the top of the file.
`ReadIR(int)`: Same as `ReadIR()` but allows you to set your own receive pin.
`ReadIR(int, int)`: Again, this is the same as the others but lets you define the blink pin as
well.

`get_button_press()`: Receive an IR signla and returns the decoded value.

This class is inherited from the `IRrecv` class which means you still need to enable it using `enableIRIn()`. It's just meant to provide some extra functionality for CSCI 2021.
