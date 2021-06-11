#
# Makefile for jax
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make jax.o:
######################################################################

TARGETS =		$(PATH_MAK)/jaxtxt.o $(PATH_MAK)/jaxdct.o

OBJECTS_TXT	=	mkjax.o mkjax1.o 
OBJECTS_DCT	=	mkjaxdct.o 

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) 

include $(COMMONRULES)

######################################################################
# Make jaxtxt*.o:
######################################################################
$(PATH_MAK)/jaxtxt.o: $(OBJECTS_TXT) mkjax.atd 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_TXT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

$(PATH_MAK)/jaxdct.o: $(OBJECTS_DCT) mkjax.dct 
	$(LD) -o $@ $(LDFLAGS) $(OBJECTS_DCT) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

mkjax.o: mkjax.atd
mkjax1.o: mkjax.att2
mkjax2.o: mkjax.att3
mkjaxdct.o: mkjax.dct