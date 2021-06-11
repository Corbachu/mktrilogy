#
# Makefile for battlefield
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make battle.o:
######################################################################

TARGETS =		$(PATH_MAK)/battletxt.o $(PATH_MAK)/battlecod.o $(PATH_MAK)/battleflr.o 

OBJECTS_TXT =	artbatt.o
OBJECTS_COD	=	mkbattle.o bkgdbatt.o
OBJECTS_FLR	=	flrbattle.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make battle_*.o:
######################################################################
$(PATH_MAK)/battletxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/battlecod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/battleflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



