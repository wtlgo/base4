# base4

Base64 has too many characters... It has to be fixed!

## Requirements

- CMake >= 3.12
- C++11 compatible compiler
- git

## How to build

```bash
$ git clone https://github.com/wtlgo/base4.git
$ mkdir base4/build && cd base4/build
$ cmake ..
$ cmake --build .
$ cmake --install .
```

## How to use

```bash
# Encoding string
$ base4 encode "foo"
-*-*-*%%-*%%

# Decoding string
$ base4 decode "-*-*-*%%-*%%"
foo

# Encoding string with different charset
$ base4 encode --charset ABCD "foo"
BCBCBCDDBCDD

# Decoding string with different charset
$ base4 decode --charset ABCD "BCBCBCDDBCDD"
foo
```
