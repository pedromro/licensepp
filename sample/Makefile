#license-manager-sample: main.cc
#	g++ main.cc -I../include -I../build/Release -llicensepp -std=c++11 -O3 -o license-manager-sample


# Sample makefile

#!include <win32.mak>

all: license-manager-sample.exe  license-manager-sample2.exe

.c.obj:
  $(cc) $(cdebug) $(cflags) $(cvars) $*.c

license-manager-sample.exe: license-manager-sample.obj
  $(link) $(ldebug) $(conflags) -I../include -I../build/Release -llicensepp -out:license-manager-sample.exe license-manager-sample.obj $(conlibs) lsapi32.lib

license-manager-sample2.exe: license-manager-sample2.obj md4c.obj
  $(link) $(ldebug) $(conflags) -out:license-manager-sample2.exe $** $(conlibs) lsapi32.lib