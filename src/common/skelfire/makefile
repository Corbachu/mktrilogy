#
# Makefile for FIGHT
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make fight.o:
######################################################################

TARGETS =		$(PATH_MAK)/skeltxt.o

OBJECTS_TXT =	artskel.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make fight_*.o:
######################################################################
$(PATH_MAK)/skeltxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



