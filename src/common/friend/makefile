#
# Makefile for friendality
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make arena.o:
######################################################################

TARGETS =		$(PATH_MAK)/friendtxt.o 

OBJECTS_TXT =	artfriend.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make friendal_*.o:
######################################################################
$(PATH_MAK)/friendtxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



