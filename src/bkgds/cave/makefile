#
# Makefile for cave
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make cave.o:
######################################################################

TARGETS =		$(PATH_MAK)/cavetxt.o $(PATH_MAK)/cavecod.o $(PATH_MAK)/caveflr.o $(PATH_MAK)/hellflr.o

OBJECTS_TXT =	artcave.o
OBJECTS_COD	=	mkcave.o bkgdcave.o
OBJECTS_FLR	=	flrcave.o
OBJECTS_FLR1	=	flrhell.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make cave_*.o:
######################################################################
$(PATH_MAK)/cavetxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/cavecod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/caveflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/hellflr.o: $(OBJECTS_FLR1)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR1) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)


