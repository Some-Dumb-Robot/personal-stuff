
implementation for 4 to 1 mux using fpga
M = S1'S0'I0 + S1'S0I1 + S1S0'I2 + S1S0I3
X = M1 = S0'I0 + S0I1
Y = M2 = S0'I2 + S0I3
M = S1'M1 + S1M2

"a 4 to 1 mux is equivalent to three 2 to 1 mux's"

Shannon decomposition
abccd'ef' + a'b'c'def' + b'cde'f
a( bcd'ef' + b'cde'f)
a'(b'c'def' + b'cde'f)


**carry chains in FPGAS**
* adder circuit
	* one LUT4 can generate teh sum, and another LUT4 will be required for carry
* Very commonly used
	* some FPGAs provide built in carry chain
