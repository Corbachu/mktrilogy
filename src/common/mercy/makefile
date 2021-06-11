#
# Makefile for mercyality
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make arena.o:
######################################################################

TARGETS =		$(PATH_MAK)/mercytxt.o 

OBJECTS_TXT =	artmercy.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make mercyal_*.o:
######################################################################
$(PATH_MAK)/mercytxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



