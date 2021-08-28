# <span style='color:#ff8000'>mangle</span>

## <span style='color:#c06000'>Overview</span>

mangle accepts input from a file or standard input, mangles the data, and
outputs to a file or standard output.

Note: mangle __is not__ cyrptographically secure - that's not its purpose.
mangle is the binary equivalent of ROT13 - it does just enough to fool
those pesky e-mail filters.

mangle an involutory program, i.e. it also de-mangles as mangle is its
own inverse:

    mangle --key 'peter pan' foo bar
    mangle --key 'peter pan' bar recovered_foo

foo and recovered_foo are identical, bar is a "mess".

### <span style='color:#c06000'>Usage</span>

    mangle [[-k,--key] phrase] [input_file [output_file]]
    mangle -h | --help

### <span style='color:#c06000'>Options</span>
--key, -k    Provides a mangling key phrase for a little bit more privacy.
             The same key phrase must be used for mangling and de-mangling.
             If/when no key phrase is provided, then mangle is compatible
             with the mangle version 1.1.n.

--help, -h   print this help information and exit.

### <span style='color:#c06000'>Parameters</span>
input_file   the file to be mangled/de-mangled. When no input file specified,
             or just '-' specified, the input is taken from standard input.

output_file  target de-mangled/mangled file. When no output file specified,
             or just '-' specified, the output is sent to standard output.


## <span style='color:#c06000'>Release Notes</span>

### <span style='color:#c06000'>1.2.1</span>
mangle now takes an optional --key option.

This does make mangle cyrptographically secure, however is does add a little
bit of privacy.
