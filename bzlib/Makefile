# Blitz library makefile

DEBUG=0
MINGW = i686-w64-mingw32-

ifeq ($(MINGW), i686-w64-mingw32-)
ARCH = x86
else
# assume x64
ARCH = x64
endif

CXX = $(MINGW)g++
AR = $(MINGW)ar r

ifeq ($(DEBUG), 0)
BD=Release
CXXFLAGS = -fno-exceptions -fno-ident -fno-stack-protector -funroll-loops -fomit-frame-pointer -fno-unwind-tables -fno-asynchronous-unwind-tables -msse -Wall -Wno-write-strings -Werror -I../include
else
BD=Debug
CXXFLAGS = -fno-exceptions -fno-ident -fno-stack-protector -funroll-loops -fomit-frame-pointer -fno-unwind-tables -fno-asynchronous-unwind-tables -msse -Wall -Wno-write-strings -g -I../include -DDEBUG
endif

LDIR = lib/$(ARCH)/$(BD)
ODIR = obj/$(ARCH)/$(BD)

OBJS = $(ODIR)/PayloadMan.o $(ODIR)/RegUtil.o

.PHONY: all clean

all: $(LDIR)/libBlitz.a

clean:
	@-rm -rf obj/
	@-rm -rf bin/

$(ODIR)/:
	mkdir -p $@

$(LDIR)/:
	mkdir -p $@

$(ODIR)/%.o: src/%.cc
	$(CXX) -c $(CXXFLAGS) -MT $@ -MD -MP -MF $(ODIR)/$*.d $< -o $@

$(LDIR)/libBlitz.a: $(LDIR)/ $(ODIR)/ $(OBJS)
	$(AR) $@ $(OBJS)

-include $(wildcard $(ODIR)/*.d)
