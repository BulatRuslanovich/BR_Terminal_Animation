all: Console3D clean

Console3D : 
	@g++ Console3D.cpp Funcs.h vec2.h vec3.h -o Console3D
	@./Console3D

clean : 
	@rm -rf Console3D