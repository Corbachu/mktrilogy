#
# Makefile for desert
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make desert.o:
######################################################################

TARGETS =		$(PATH_MAK)/deserttxt.o $(PATH_MAK)/desertcod.o $(PATH_MAK)/desertflr.o

OBJECTS_TXT =	artdesrt.o
OBJECTS_COD	=	mkdesert.o bkgdesrt.o
OBJECTS_FLR =	flrdesrt.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make desert_*.o:
######################################################################
$(PATH_MAK)/deserttxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/desertcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/desertflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

