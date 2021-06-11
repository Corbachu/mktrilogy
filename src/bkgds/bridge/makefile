#
# Makefile for bridge
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make bridge.o:
######################################################################

TARGETS =		$(PATH_MAK)/bridgetxt.o $(PATH_MAK)/bridgecod.o $(PATH_MAK)/bridgeflr.o 

OBJECTS_TXT =	artbrig.o
OBJECTS_COD	=	mkbrig.o bkgdbrig.o
OBJECTS_FLR	=	flrbridge.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make bridge_*.o:
######################################################################
$(PATH_MAK)/bridgetxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/bridgecod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/bridgeflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



