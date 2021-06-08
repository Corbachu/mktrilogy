#
# Makefile for Finish Her
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make finher.o:
######################################################################

TARGETS =		$(PATH_MAK)/finhertxt.o 

OBJECTS_TXT =	artfinher.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make finher_*.o:
######################################################################
$(PATH_MAK)/finhertxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



