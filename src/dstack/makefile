#
# Makefile for Dram Stack
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make select.o:
######################################################################

TARGETS =		$(PATH_MAK)/dstack.o

OBJECTS_COD	=	dstack.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make select_*.o:
######################################################################
$(PATH_MAK)/dstack.o: $(OBJECTS_COD)
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_COD) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)
