
################################
# configure here
SRCS = sdio.cpp
LIBNAME = libsdio.a
################################

DEPFILE = .depend
OBJS = $(SRCS:.cpp=.o)

CPP = avr-g++
AR  = avr-ar
CFLAGS =  -I/usr/share/arduino/hardware/arduino/cores/arduino -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega1280 -DF_CPU=16000000UL

CFLAGS += -O2

$(LIBNAME): $(OBJS)
	@echo [AR] $@
	$(AR) -r $@ $^

%.o: %.cpp dep
	@echo [CC] $@
	$(CPP) $(CFLAGS) -c -o $@ $<

dep: $(DEPFILE)
$(DEPFILE): $(SRCS)
	$(CPP) -MM $^ >$@

.PHONY: clean install
clean:
	rm -rf $(LIBNAME) $(OBJS) $(DEPFILE)

install: $(LIBNAME)
	@test -n '$(DESTDIR)' || (echo DESTDIR not set, exiting!; exit 1)
	install $< $(DESTDIR)

-include $(DEPFILE)
