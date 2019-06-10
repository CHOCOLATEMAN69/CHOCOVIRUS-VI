########################################################
# This is the VSMinGW master Makefile.
# (c) 2019 Modeco80
#
# Modified for Blitz/CVVI.
########################################################

MINGW = $(subst \,/,$(SOLDIR))mingw
RM = $(MINGW)/common/rm.exe

INTDIR = obj/$(MSBPLATFORM)/$(MSBCONFIG)/
OUTDIR = $(MSBPLATFORM)/$(MSBCONFIG)/
OUTPUT = $(MSBPROJECTNAME)

SRCS = $(wildcard *.c)
RCSRCS = $(wildcard *.rc)
OBJS = $(SRCS:%.c=$(INTDIR)%.o) $(RCSRCS:%.rc=$(INTDIR)%.o)

# Selecting compilers for different targets.
ifeq ($(MSBPLATFORM),x64)
CC = $(MINGW)/amd64/bin/gcc
#CXX =  $(MINGW)/amd64/bin/g++
# ???
WINDRES = $(subst /,\,$(MINGW))\amd64\bin\windres -O coff
else
CC = $(MINGW)/x86/bin/gcc
#CXX =  $(MINGW)/x86/bin/g++
# ???
WINDRES = $(subst /,\,$(MINGW))\x86\bin\windres -O coff
endif

# Build configuration selection.
ifeq ($(MSBCONFIG),Debug)
CCFLAGS = -fno-ident -fno-stack-protector -funroll-loops -fomit-frame-pointer -fno-unwind-tables -fno-asynchronous-unwind-tables -DDEBUG -msse -masm=intel -Wall -Werror -g
else
CCFLAGS = -fno-ident -fno-stack-protector -funroll-loops -fomit-frame-pointer -fno-unwind-tables -fno-asynchronous-unwind-tables -msse -masm=intel -Wall -Os
endif

LD = $(CC) -mwindows -s -lmingw32 -lmingwex -lgcc -lmsvcrt
USERLIBS = -lkernel32 -luser32

.PHONY: all clean

all: $(OUTDIR)$(OUTPUT).exe

$(INTDIR)%.o: %.c
	@echo $(notdir $<)
	@$(CC) -c $(CCFLAGS) -MT $@ -MD -MP -MF $(INTDIR)$*.d $< -o $@

#$(INTDIR)%.o: %.cpp
#	$(CXX) -c $(CCFLAGS) -MT $@ -MD -MP -MF $(INTDIR)$*.d $< -o $@
	
$(INTDIR)%.o: %.rc
	@echo $(notdir $<)
	@$(WINDRES) $< -o $@

$(OUTDIR)$(OUTPUT).exe: $(OBJS)
	@echo Linking $@
	@$(LD) $(OBJS) $(USERLIBS) -o $@
	
clean:
	@-$(RM) -f obj/$(MSBPLATFORM)/$(MSBCONFIG)/*.o
	@-$(RM) -f $(MSBPLATFORM)/$(MSBCONFIG)/$(OUTPUT).exe

# Allow make to see the dependencies
-include $(wildcard $(INTDIR)*.d)