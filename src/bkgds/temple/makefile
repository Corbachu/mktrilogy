#
# Makefile for temp
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make temp.o:
######################################################################

TARGETS =		$(PATH_MAK)/temptxt.o $(PATH_MAK)/tempcod.o $(PATH_MAK)/tempflr.o 

OBJECTS_TXT =	arttemp.o
OBJECTS_COD	=	mktemp.o bkgdtemp.o
OBJECTS_FLR	=	flrtemp.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make temp_*.o:
######################################################################
$(PATH_MAK)/temptxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/tempcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/tempflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



