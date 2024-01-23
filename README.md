A simple [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) interpreter.

To get started, clone the repository and compile it (for example with `gcc`) to a binary.

```sh
$ git clone https://github.com/ergraff/brainfuck.git ~/brainfuck
$ cd ~/brainfuck
$ gcc main.c instructions.c -o brainfuck
```

To run the interpreter, give it the path to a file to run as a Brainfuck program. For example, run the `helloworld1.bf` included from the [wikipedia examples](https://en.wikipedia.org/wiki/Brainfuck#Examples) with the following:

```sh
$ ./brainfuck examples/helloworld1.bf
Hello World!
```
