CC = arm-linux-gnueabi-g++ -std=c++11
a.out: main.o point.o rect.o screen.o bitmap.o color.o  game.o map.o snake.o ts.o food.o
	$(CC) $^  -o $@  -pthread
	
%.o: %.cpp
	$(CC) $< -c 

clean:
	rm *.o -f

# # $@ 目标文件的完整名称
# # $^ 所有的不重复的依赖文件的文件名，以空格分开
# # $< 第一个依赖文件的名字
# # $(变量名)引用变量的值

# #定义变量
# TARGET:=main	                    #可执行文件
# SRC:=			                    #指定所有的源文件.c
# OBJS:=			                    #指定所有的目标文件.o
# CC:=arm-linux-gnueabi-g++ -std=c++11#指定编译器 如果需要在开发板上运行 arm-linux-gnueabi-gcc
# INCS:=-I ./		                    #指定头文件的搜索路径
# LIBS:=-L ./		                    #指定库文件的搜索路径
# LIBNAME:=		                    #指定库的名字

# SRC+=$(wildcard *.cpp)	            #展开所有的.c文件 赋值给SRC
# OBJS+=$(patsubst %.cpp,%.o,$(SRC))	#把SRC中所有的.c文件 转成.o 赋值给OBJS


# $(TARGET):$(OBJS)
# 	$(CC) $^ $(INCS) $(LIBS) $(LIBNAME) -o $@
	
# %.o:%.cpp
# 	$(CC) -c $< $(INCS) $(LIBS) $(LIBNAME) -o $@

# clean:
# 	rm *.o -f