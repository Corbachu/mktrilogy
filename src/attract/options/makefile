#
# Makefile for option
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make option.o:
######################################################################

TARGETS =		$(PATH_MAK)/optiontxt.o $(PATH_MAK)/optioncod.o 

OBJECTS_TXT =	artnuopt.o
OBJECTS_COD	=	mknuopt.o bkgdopts.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make option_*.o:
######################################################################
$(PATH_MAK)/optiontxt.o: $(OBJECTS_TXT)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/optioncod.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)



