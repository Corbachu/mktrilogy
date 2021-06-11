#
# Makefile for bell tower
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make bell.o:
######################################################################

TARGETS =		$(PATH_MAK)/belltxt.o $(PATH_MAK)/bellcod.o $(PATH_MAK)/bellflr.o 

OBJECTS_TXT =	artbell.o
OBJECTS_COD	=	mkbell.o bkgdbell.o
OBJECTS_FLR	=	flrbell.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make bell_*.o:
######################################################################
$(PATH_MAK)/belltxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/bellcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/bellflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



