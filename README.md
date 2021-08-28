# mangle

mangle mangles a file or standard input to a file or standard output.

Note: mangle *is not* cyrptographically secure - that's not its purpose.
mangle is the binary equivalent of ROT13 - it does just enough to fool
those pesky e-mail filters.

mangle an involutory program, i.e. it also de-mangles as mangle is its
own inverse:

    mangle --key 'peter pan' foo bar
    mangle --key 'peter pan' bar recovered_foo

foo and recovered_foo are identical, bar is a "mess".

### Usage

    mangle [[-k,--key] phrase] [input_file [output_file]]
    mangle -h | --help

### Options
--key, -k    Provides a mangling key phrase for a little bit more privacy.
             The same key phrase must be used for mangling and de-mangling.
             If/when no key phrase is provided, then mangle is compatible
             with the mangle version 1.1.n versions.

--help, -h   print this help information and exit.

### Parameters
input_file   the file to be mangled/demangled. When no input file specified, or
             just '-' specified, the input is taken from standard input.

output_file  target demangled/mangled file. When no output file specified, or
             just '-' specified, the output is sent to standard output.
