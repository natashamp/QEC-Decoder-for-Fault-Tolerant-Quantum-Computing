# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f VDecoderGrid.mk

default: VDecoderGrid

### Constants...
# Perl executable (from $PERL, defaults to 'perl' if not set)
PERL = perl
# Python3 executable (from $PYTHON3, defaults to 'python3' if not set)
PYTHON3 = python3
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/Cellar/verilator/5.046/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?=
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?=

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = VDecoderGrid
# Module prefix (from --prefix)
VM_MODPREFIX = VDecoderGrid
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
  -dynamiclib \
  -I/usr/local/Cellar/openjdk/25.0.2/libexec/openjdk.jdk/Contents/Home/include \
  -I/usr/local/Cellar/openjdk/25.0.2/libexec/openjdk.jdk/Contents/Home/include/darwin \
  -fvisibility=hidden \
  -DVL_USER_FINISH=1 \
  -O0 \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
  -dynamiclib \
  -fvisibility=hidden \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
  VDecoderGrid__spinalWrapper \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
  . \
  .. \

### Default rules...
# Include list of all generated classes
include VDecoderGrid_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

VDecoderGrid__spinalWrapper.o: verilator/VDecoderGrid__spinalWrapper.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<

### Link rules... (from --exe)
VDecoderGrid: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@

# Verilated -*- Makefile -*-
