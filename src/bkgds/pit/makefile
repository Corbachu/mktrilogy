#
# Makefile for pit
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make pit.o:
######################################################################

TARGETS =		$(PATH_MAK)/pittxt.o $(PATH_MAK)/pitcod.o 

OBJECTS_TXT =	artpit.o
OBJECTS_COD	=	mkpit.o bkgdpit.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make pit_*.o:
######################################################################
$(PATH_MAK)/pittxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/pitcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



