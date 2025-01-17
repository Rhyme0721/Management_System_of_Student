CC=gcc#编译器名称
CFLAGS=-c -g -Wall#编译器选项
OBJS=stu_sys.o function.o#生成的二进制文件，依赖文件

stu_sys: $(OBJS)
	$(CC) $^ -o $@
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

