#
# Makefile for babyality
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make arena.o:
######################################################################

TARGETS =		$(PATH_MAK)/babytxt.o 

OBJECTS_TXT =	artbaby.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make babyal_*.o:
######################################################################
$(PATH_MAK)/babytxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



