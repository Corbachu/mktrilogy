#
# Makefile for steel
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make steel.o:
######################################################################

TARGETS =		$(PATH_MAK)/steelcod.o $(PATH_MAK)/steeltxt.o

OBJECTS_TXT =	artsteel.o
OBJECTS_COD	=	mksteel.o bkgdstel.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make steel_*.o:
######################################################################
$(PATH_MAK)/steeltxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/steelcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



