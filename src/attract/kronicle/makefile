#
# Makefile for title
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make title.o:
######################################################################

TARGETS =		$(PATH_MAK)/titlecod.o $(PATH_MAK)/titletxt.o

OBJECTS_TXT =	arttitle.o
OBJECTS_COD	=	mktitle.o bkgdtitl.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make title_*.o:
######################################################################
$(PATH_MAK)/titletxt.o: $(OBJECTS_TXT) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/titlecod.o: $(OBJECTS_COD) 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



