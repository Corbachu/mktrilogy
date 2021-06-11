#
# Makefile for grave
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make grave.o:
######################################################################

TARGETS =		$(PATH_MAK)/kung5txt.o $(PATH_MAK)/kung5cod.o 

OBJECTS_TXT =	artkung5.o
OBJECTS_COD	=	mkkung5.o bkgdkung5.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make grave_*.o:
######################################################################
$(PATH_MAK)/kung5txt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/kung5cod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

