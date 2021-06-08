#
# Master makefile for the Ultra-64 version of MK TRILOGY
#

# NOTE: PRdefs includes commondefs:
include $(ROOT)/usr/include/make/PRdefs
include makedefs


######################################################################
# Make mktrilogy & rom:
######################################################################

ROMFILE =	rom
EMFILE =	mktrilogy
SPECFILE =	spec

TARGETS =	$(ROMFILE) $(EMFILE)

OBJECTS =	seggamecode.o 

default:	$(TARGETS) 

include	$(COMMONRULES)

$(TARGETS): $(SPECFILE) $(MAKEROM) $(OBJECTS)
	makeit $(PATH_SEG)/cfb
	makeit $(PATH_SEG)/dstack
	makeit $(PATH_SEG)/pheap
	makeit $(PATH_BKGD)/armory
	makeit $(PATH_BKGD)/battle
	makeit $(PATH_BKGD)/bell
	makeit $(PATH_BKGD)/bridge
	makeit $(PATH_BKGD)/cave
	makeit $(PATH_BKGD)/dead
	makeit $(PATH_BKGD)/desert
	makeit $(PATH_BKGD)/grave
	makeit $(PATH_BKGD)/hport
	makeit $(PATH_BKGD)/lost
	makeit $(PATH_BKGD)/mk2pit
	makeit $(PATH_BKGD)/monks
	makeit $(PATH_BKGD)/pit
	makeit $(PATH_BKGD)/sbst
	makeit $(PATH_BKGD)/soul
	makeit $(PATH_BKGD)/temple
	makeit $(PATH_BKGD)/tower
	makeit $(PATH_BKGD)/city
	makeit $(PATH_BKGD)/tree
	makeit $(PATH_BKGD)/water
	makeit $(PATH_BKGD)/kungfu2
	makeit $(PATH_BKGD)/kungfu5
	makeit $(PATH_CHARS)/sonya
	makeit $(PATH_CHARS)/robo
	makeit $(PATH_CHARS)/tusk
	makeit $(PATH_CHARS)/jcage
	makeit $(PATH_CHARS)/swat
	makeit $(PATH_CHARS)/sheeva
	makeit $(PATH_CHARS)/baraka
	makeit $(PATH_CHARS)/rayden
	makeit $(PATH_CHARS)/sk
	makeit $(PATH_CHARS)/shang
	makeit $(PATH_CHARS)/motaro
	makeit $(PATH_CHARS)/lk
	makeit $(PATH_CHARS)/fninja
	makeit $(PATH_CHARS)/mninja
	makeit $(PATH_CHARS)/lia
	makeit $(PATH_CHARS)/lao
	makeit $(PATH_CHARS)/kano
	makeit $(PATH_CHARS)/jax
	makeit $(PATH_CHARS)/indian
	makeit $(PATH_ATTRACT)/buyin
	makeit $(PATH_ATTRACT)/gradient
	makeit $(PATH_ATTRACT)/options
	makeit $(PATH_ATTRACT)/select
	makeit $(PATH_ATTRACT)/steelvs
	makeit $(PATH_ATTRACT)/tourn
	makeit $(PATH_ATTRACT)/kronicle
	makeit $(PATH_ATTRACT)/vs
	makeit $(PATH_COMMON)/animal
	makeit $(PATH_COMMON)/baby
	makeit $(PATH_COMMON)/friend
	makeit $(PATH_COMMON)/fatal
	makeit $(PATH_COMMON)/fight
	makeit $(PATH_COMMON)/brutal
	makeit $(PATH_COMMON)/finher
	makeit $(PATH_COMMON)/finhim
	makeit $(PATH_COMMON)/mercy
	makeit $(PATH_COMMON)/mugs
	makeit $(PATH_COMMON)/storm
	makeit $(PATH_COMMON)/skelfire
	makeit $(PATH_COMMON)/ripskel
	makeit $(PATH_COMMON)/top
	makeit $(PATH_COMMON)/logo

	$(MAKEROM) $(MRFLAGS) -r $(ROMFILE) $(SPECFILE) >mapfile

######################################################################
# Make seg_*.o:
######################################################################
seggamecode.o:
	makeit $(PATH_SEG)/gamecode

