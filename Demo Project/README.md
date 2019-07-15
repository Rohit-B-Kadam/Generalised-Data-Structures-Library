# Shared Object

## commad of gcc

How to run Program

I First Technique

1. Create object file ( .o )

```bash
g++ -g  -c -fPIC -Wall Server.cpp
```

2. Create Shared Object file ( .so )

```bash
g++ -g -shared -o SharedObject.so Server.o
```

3. Compiling client Program

```bash
g++ -g -Wall -o Client Clients.cpp SharedObject.so -ldl
```

4. Specifing path of Shared Object File
	- if we give SharedObject complete path in dlopen then we can direct run
		```bash
		./Client
		```
	- if we have given only name of Shared object file then we must specify the path
		```bash
		LD_LIBRARY_PATH=. ./Client
		```

II

III
