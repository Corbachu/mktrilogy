#
# Makefile for seggamecode.o
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs

######################################################################
# Make seggamecode.o:
######################################################################

TARGETS =		$(PATH_MAK)/seggamecode.o 
PONGGAME = mkpong.o
MARKGAME = mkmark.o

OBJECTS =	mkobj.o mkfade.o mkpal.o mkscore.o \
	mktext.o mksound.o mkdma.o 	mksel.o mkbkgd.o mkani.o \
	mkguys.o mkbonus.o mkopt.o mkladder.o mkinit.o mkanimal.o mkfatal.o mkfriend.o mkfx.o \
	mkbuyin.o mkmode.o mkvs.o mkend.o mkmain.o mkglobal.o mkjoy.o mkslam.o \
	mkblood.o mkprop.o moves.o mkreact.o mkos.o mkhstd.o mkbug.o \
	mkcanned.o mkdiag.o mkcombo.o mkdrone.o mkboss.o \
	mkutil.o mkr1.o mkrepell.o mkbio.o mkamode.o mkstat.o mkzap.o vcache.o \
	context.o mkbt.o mkscombo.o mkstk.o mktextdt.o imgpal.o mkbkpal.o u64main.o  \
	mkmisc.o romcopy.o gamepad.o queue.o int_s.o callback.o gutil.o stopwatch.o bench.o inflate.o \
	wesslib.o gfxbuf.o

LIBRARIES =		$(U64LIBFULL)

default:		$(TARGETS) $(PONGGAME) $(MARKGAME)

include $(COMMONRULES)

$(PATH_MAK)/seggamecode.o: $(OBJECTS) 
	$(LD)  -o $@ $(LDFLAGS) $(OBJECTS) \
		-L$(PATH_LIB) -L$(PATH_PRLIB) -l$(U64LIBNAME)

