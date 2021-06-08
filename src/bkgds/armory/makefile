#
# Makefile for armory
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make armory.o:
######################################################################

TARGETS =		$(PATH_MAK)/armortxt.o $(PATH_MAK)/armorcod.o $(PATH_MAK)/armorflr.o $(PATH_MAK)/tombflr.o 

OBJECTS_TXT =	artarmor.o
OBJECTS_COD	=	mkarmor.o bkgdarmr.o
OBJECTS_FLR1	=	flrarmor.o
OBJECTS_FLR2	=	flrtomb.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make armor_*.o:
######################################################################
$(PATH_MAK)/armortxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/armorcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/armorflr.o: $(OBJECTS_FLR1)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR1) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/tombflr.o: $(OBJECTS_FLR2)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR2) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



