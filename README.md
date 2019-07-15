# Generalised Data Structures Library

- In this project we provide almost every functionality required to handle all necessary data structure in library format.
- In case of static library there is a memory issue and to avoid it we developed the library as Shared Object.
- We can use this library in any C/C++ application on Linux Platform.

## Use Following Command

How to run Program

I First Technique

1. Create object file ( .o )

```bash
g++ -g  -c -fPIC -Wall Collection.cpp
```

2. Create Shared Object file ( .so )

```bash
g++ -g -shared -o Collection.so Collection.o
```

3. Compiling client Program

```bash
g++ -g -Wall -o User User.cpp Collection.so -ldl
```

4. Specifing path of Shared Object File
	- if we give SharedObject complete path in dlopen then we can direct run
		```bash
		./User
		```
	- if we have given only name of Shared object file then we must specify the path
		```bash
		LD_LIBRARY_PATH=. ./User
		```

___
