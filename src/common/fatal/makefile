#
# Makefile for fatalality
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make arena.o:
######################################################################

TARGETS =		$(PATH_MAK)/fataltxt.o 

OBJECTS_TXT =	artfatal.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make fatalal_*.o:
######################################################################
$(PATH_MAK)/fataltxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



