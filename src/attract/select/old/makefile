#
# Makefile for Player Select/Ladder/Fire Background
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make select.o:
######################################################################

TARGETS =		$(PATH_MAK)/selectcod.o $(PATH_MAK)/selecttxt.o

OBJECTS_TXT =	artpsel.o 
OBJECTS_COD	=	mkpsel.o bkgdsel.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make select_*.o:
######################################################################
$(PATH_MAK)/selecttxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/selectcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



