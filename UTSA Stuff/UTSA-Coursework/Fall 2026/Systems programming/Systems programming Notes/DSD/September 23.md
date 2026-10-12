

representation of number literals:
~

<size>'<signed><radix>value ("<>") indicates optional part)
	**size** the number of binary bits the number is comprised of. not the number of hex or decimal digits. default is 32 bits
	' A separator, single quote not backtick



format - prefix - number rep
binary - 'b - 01xXzZ_?
octal - 'o - 0-7xXzZ_?
decimal - 'd - 0-9_
hexadeciaml - 'h - 0-9-fA-F

left most bit - extension
0 - 0 extension
1 - 0 extension
X - x_X extension
Z - z_Z extension

example:
reg [7:0] v = 8'b1011; initial $displayb ("v signed =\t", v);

