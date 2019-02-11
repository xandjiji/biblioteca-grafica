# biblioteca-grafica

A basic graphic library using X Window System.

<p align="center">
  <img src="https://i.imgur.com/fn6Hdv3.png">
</p>

### Usage

Compile with GCC using both ```cg2d.c``` and ```cg3d.c``` (math library and X Window required)
```
gcc -c cg2d.c
gcc -c cg3d.c
gcc atividade1.c -o atividade1 ./cg2d.o ./cg3d.o -lm -lX11
```
  
Samples included: ```atividade1.c```, ```atividade2.c```, ```atividade3.c``` and ```atividade4.c```
