#
# Makefile for soul
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make soul.o:
######################################################################

TARGETS =		$(PATH_MAK)/soultxt.o $(PATH_MAK)/soulcod.o $(PATH_MAK)/soulflr.o $(PATH_MAK)/balcflr.o

OBJECTS_TXT =	artsoul.o
OBJECTS_COD	=	mksoul.o bkgdsoul.o
OBJECTS_FLR	=	flrsoul.o
OBJECTS_FLR1	=	flrbalc.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make soul_*.o:
######################################################################
$(PATH_MAK)/soultxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/soulcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/soulflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/balcflr.o: $(OBJECTS_FLR1)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR1) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)




