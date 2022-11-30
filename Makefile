OBJS = build/main.o build/crc.o build/uart_wp.o
CFLAGS = -g -Wall

all: app

app: $(OBJS)
	mkdir -p build
	gcc -o $@ $?

build/%.o: crc/%.c crc/%.h
	gcc $(CFLAGS) -c $< -o $@

build/%.o: uart_wp/%.c uart_wp/%.h
	gcc $(CFLAGS) -c $< -o $@

build/main.o: main.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f app build/*.o 