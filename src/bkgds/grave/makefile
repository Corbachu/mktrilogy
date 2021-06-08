#
# Makefile for grave
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make grave.o:
######################################################################

TARGETS =		$(PATH_MAK)/gravetxt.o $(PATH_MAK)/gravecod.o $(PATH_MAK)/graveflr.o

OBJECTS_TXT =	artgrav.o
OBJECTS_COD	=	mkgrav.o bkgdgrav.o
OBJECTS_FLR =	flrgrave.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make grave_*.o:
######################################################################
$(PATH_MAK)/gravetxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/gravecod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/graveflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

