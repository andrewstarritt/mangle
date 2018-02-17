# mangle

mangle mangles a file or standard input to a file or standard output.

Note: mangle *is not* cyrptographically secure - that's not its purpose.
mangle is the binary equivilent of ROT13 - it does just enough to fool
those pesky e-mail filters.

mangle an involutory program, i.e. it also de-mangles as mangle is its
own inverse:

    mangle  foo bar
    mangle  bar recovered_foo

foo and recovered_foo are identical, bar is a "mess".

### Usage

    mangle [input_file [output_file]]
    mangle -h | --help

### Options
--help, -h   print this help information and exit.

### Parameters
input_file   the file to be mangled/demangled. When no input file specified, or
             just '-' specified, the input is taken from standard input.

output_file  target demangled/mangled file. When no output file specified, or
             just '-' specified, the output is sent to standard output.

