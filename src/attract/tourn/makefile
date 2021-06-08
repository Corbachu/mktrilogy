#
# Makefile for tourn
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make tourn.o:
######################################################################

TARGETS =		$(PATH_MAK)/tourncod.o $(PATH_MAK)/tourntxt.o

OBJECTS_TXT =	arttourn.o
OBJECTS_COD	=	mktourn.o bkgdtorn.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make tourn_*.o:
######################################################################
$(PATH_MAK)/tourntxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/tourncod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



