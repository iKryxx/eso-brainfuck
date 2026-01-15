# Brainfuck
___

### Prerequisites
You need a C compiler, CMake and Git.
```shell
apt install build-essential cmake git
```
___
### How to use
Clone the repository and build it:
```shell
git clone https://github.com/iKryxx/eso-brainfuck.git
cd eso-brainfuck
mkdir build && cd build
cmake ..
make
```
___
### Example
```shell
touch test.bf
echo "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." >> test.bf
./ikbf test.bf
# Hello World!
```

___
### Notes
- You can output the memory by using the `-d` flag. This won't print stdout.