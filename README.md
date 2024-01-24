A simple [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) interpreter.

To get started, clone the repository and compile it (for example with `gcc`) to an executable.

```sh
$ git clone https://github.com/ergraff/brainfuck.git ~/brainfuck
$ cd ~/brainfuck
$ gcc main.c -o brainfuck
```

To run the executable, give it the path to a file to interpret as a Brainfuck program.
This is also given by `brainfuck --help`:

```sh
$ ./brainfuck --help
use: brainfuck <path>

Example:
brainfuck examples/helloworld1.bf
$ ./brainfuck /path/to/file.bf
```

For example, run the `helloworld1.bf` included from the [wikipedia examples](https://en.wikipedia.org/wiki/Brainfuck#Examples) with the following:

```sh
$ ./brainfuck examples/helloworld1.bf
Hello World!
```
