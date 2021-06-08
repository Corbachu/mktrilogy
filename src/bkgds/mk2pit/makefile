#
# Makefile for mk2pit
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make mk2pit.o:
######################################################################

TARGETS =		$(PATH_MAK)/mk2pittxt.o $(PATH_MAK)/mk2pitcod.o 

OBJECTS_TXT =	artmk2pit.o
OBJECTS_COD	=	mkmk2pit.o bkgdmk2p.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make mk2pit_*.o:
######################################################################
$(PATH_MAK)/mk2pittxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/mk2pitcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

