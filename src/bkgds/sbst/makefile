#
# Makefile for sbst
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make sbst.o:
######################################################################

TARGETS =		$(PATH_MAK)/sbsttxt.o $(PATH_MAK)/sbstcod.o $(PATH_MAK)/subflr.o $(PATH_MAK)/streetflr.o

OBJECTS_TXT =	artsbst.o
OBJECTS_COD	=	mksbst.o bkgdsbst.o
OBJECTS_FLR	=	flrsub.o
OBJECTS_FLR1	=	flrstreet.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make sbst_*.o:
######################################################################
$(PATH_MAK)/sbsttxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/sbstcod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/subflr.o: $(OBJECTS_FLR)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/streetflr.o: $(OBJECTS_FLR1)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_FLR1) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



