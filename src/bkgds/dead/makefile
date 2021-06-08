#
# Makefile for dead
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make dead.o:
######################################################################

TARGETS =		$(PATH_MAK)/deadtxt.o $(PATH_MAK)/deadcod.o 

OBJECTS_TXT =	artdead.o
OBJECTS_COD	=	mkdead.o bkgddead.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make dead_*.o:
######################################################################
$(PATH_MAK)/deadtxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/deadcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)


