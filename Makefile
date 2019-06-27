# CHOCOVIRUS MAKEFILE TIME
DEBUG=0
MINGW = i686-w64-mingw32-

ifeq ($(MINGW), i686-w64-mingw32-)
ARCH = x86
else
# assume x64
ARCH = x64
endif

RC = $(MINGW)windres -O coff
CXX = $(MINGW)g++

# To make sure I don't use STL at all, I'm
# going to use gcc to link so I end up forgetting
# to ever link in stdc++.
#
# So basically, less painful torture. Thank you for coming to my TED talk.
LD = $(MINGW)gcc

ifeq ($(DEBUG), 0)
BD=Release
CXXFLAGS = -fno-exceptions -fno-ident -fno-stack-protector -funroll-loops -fomit-frame-pointer -fno-unwind-tables -fno-asynchronous-unwind-tables -msse -Wall -Wno-write-strings -Werror -Iinclude
else
BD=Debug
CXXFLAGS = -fno-exceptions -fno-ident -fno-stack-protector -funroll-loops -fomit-frame-pointer -fno-unwind-tables -fno-asynchronous-unwind-tables -msse -Wall -Wno-write-strings -g -Iinclude -DDEBUG
endif

BDIR = bin/$(ARCH)/$(BD)
ODIR = obj/$(ARCH)/$(BD)

OBJS = $(ODIR)/main.o $(ODIR)/choco.res

.PHONY: all clean

all: $(BDIR)/chocovirus.exe

clean:
	@-rm -rf obj/
	@-rm -rf bin/

$(ODIR)/:
	mkdir -p $@

$(BDIR)/:
	mkdir -p $@

$(ODIR)/%.res: src/%.rc
	$(RC) $< -o $@

$(ODIR)/%.o: src/%.cc
	$(CXX) -c $(CXXFLAGS) -MT $@ -MD -MP -MF $(ODIR)/$*.d $< -o $@

$(BDIR)/chocovirus.exe: $(BDIR)/ $(ODIR)/ $(OBJS)
	$(LD) $(CXXFLAGS) -mwindows $(OBJS) -o $@

-include $(wildcard $(ODIR)/*.d)
