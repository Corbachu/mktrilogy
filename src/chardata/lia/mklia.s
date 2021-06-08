#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

	.extern LPRP_P
	.extern SHOCK_P
	.extern LIFLASH_P
	.extern LIASPIT_P
	.extern LIXPLOD_P
	.extern FLESH_P
	.extern SMDRIP_P
	.extern LBLU_P
	.extern   SKELRIP_P
	.extern   LAOFLA_P
	.extern   KUFLB_P
	.extern   OBFLA_P
	.extern   OBFLB_P
	.extern   LIAFLA_P
	.extern   SBFLA_P
	.extern   KANOFLA_P
	.extern   KANOFLB_P
	.extern   SGFLA_P
	.extern   SGFLB_P
	.extern   JAXFLA_P
	.extern   JAXFLB_P
	.extern   LUFLA_P
	.extern   TSFLA_P
	.extern   TSFLB_P
	.extern   TRFLA_P
	.extern   TRFLB_P
	.extern   INFLA_P
	.extern   INDFLB_P
	.extern   SUBFL_P
	.extern   SUBFLB_P
	.extern   RBRDFLA_P
	.extern   RBRDFLB_P


	.align 2
#include "mklia.atd"
#include "mklia.att1" 
