#
# Makefile for arena
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make arena.o:
######################################################################

TARGETS =		$(PATH_MAK)/arenatxt.o $(PATH_MAK)/arenacod.o $(PATH_MAK)/arenaflr.o 

OBJECTS_TXT =	artarena.o
OBJECTS_COD	=	mkarena.o bkgdaren.o
OBJECTS_FLR	=	flrarena.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make arena_*.o:
######################################################################
$(PATH_MAK)/arenatxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/arenacod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/arenaflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



