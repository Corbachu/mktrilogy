#
# Makefile for hport
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make hport.o:
######################################################################

TARGETS =		$(PATH_MAK)/hporttxt.o $(PATH_MAK)/hportcod.o 

OBJECTS_TXT =	artporta.o
OBJECTS_COD	=	mkportal.o bkgdport.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make hport_*.o:
######################################################################
$(PATH_MAK)/hporttxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/hportcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

