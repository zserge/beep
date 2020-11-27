OS:=$(shell uname)
ifeq ($(OS),Darwin)
	LDFLAGS=-framework AudioUnit
endif

ifeq ($(OS),Linux)
	LDFLAGS=-lasound
endif

beep: beep.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f beep beep.exe beep.o
