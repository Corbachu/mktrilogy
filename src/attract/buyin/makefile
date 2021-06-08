#
# Makefile for buyin
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make buyin.o:
######################################################################

TARGETS =		$(PATH_MAK)/buyintxt.o $(PATH_MAK)/buyincod.o 

OBJECTS_TXT =	artbuyin.o
OBJECTS_COD	=	mkbuyin.o bkgdbuy.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make buyin_*.o:
######################################################################
$(PATH_MAK)/buyintxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/buyincod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



