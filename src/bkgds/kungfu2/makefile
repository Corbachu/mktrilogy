#
# Makefile for grave
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make grave.o:
######################################################################

TARGETS =		$(PATH_MAK)/kung2txt.o $(PATH_MAK)/kung2cod.o 

OBJECTS_TXT =	artkung2.o
OBJECTS_COD	=	mkkung2.o bkgdkung2.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make grave_*.o:
######################################################################
$(PATH_MAK)/kung2txt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/kung2cod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

