#include <preloader.h>
#include <soc.h>
#include <plr_pll_gen1.h>
#include <cpu_utils.h>

/* From soc.h, PLL_DEV_CPU == 0, PLL_DEV_LX == 1,
   PLL_DEV_MEM == 2, and PLL_DEV_DSP == 3 */
static u32_t _pll_freq[4]={PLL_MHZ_UNKNOWN, PLL_MHZ_UNKNOWN,
                           PLL_MHZ_UNKNOWN, PLL_MHZ_UNKNOWN};
#if defined(CMU_DIVISOR)
static u32_t cmu_div = 1;
#endif

void pll_gen1_setup(void) {
    if(PLLI.set_by == 1) { /* 1-software or 0-pin */
        otto_pll_gen1_set(PLLI.sysclk_control_reg_25mhz,
                          PLLI.sysclk_control_reg_40mhz,
                          PLLI.mckg_phs_sel_reg,
                          PLLI.mckg_freq_div_reg,
                          PLLI.lx_pll_sel_reg_25mhz,
                          PLLI.lx_pll_sel_reg_40mhz,
                          (OTTO_PLL_CPU_SET | OTTO_PLL_DSP_SET | OTTO_PLL_MEM_SET | OTTO_PLL_LX_SET));
    }

    pll_query_freq(PLL_DEV_CPU);
}

u32_t pll_gen1_is_CKSEL_25MHz(void)
{
	if(REG32(SYSREG_PIN_STATUS_REG_A) & SYSREG_PIN_STATUS_CLSEL_MASK)
		return 0;
	else
		return 1;
}

/* Function implementation */
/* Function Name:
 *      otto_pll_gen1_set
 * Descripton:
 *      Setting CPU/DSP/LX/DRAM PLL clock.
 * Input:
 *      sys_pll_ctl_oc25   : sys_pll_ctl using 25MHz OC.
 *      sys_pll_ctl_oc40   : sys_pll_ctl using 40MHz OC.
 *  sys_mckg_ph_sel    : MCKG phase deley value.
 *  sys_mckg_freq_div  : MCKG frequency division value.
 *  sys_lx_pll_sel_oc25: LX bus PLL selection value using 25MHz OC.
 *  sys_lx_pll_sel_oc40: LX bus PLL selection value using 40MHz OC.
 *  flag           : PLL_CPU_SET/PLL_DSP_SET/PLL_MEM_SET/PLL_LX_SET
 * Output:
 *      NONE
 * Return:
 *      NONE
 */

void otto_pll_gen1_set(
    unsigned int sys_pll_ctl_oc25,
    unsigned int sys_pll_ctl_oc40,
    unsigned int sys_mckg_ph_sel,
    unsigned int sys_mckg_freq_div,
    unsigned int sys_lx_pll_sel_oc25,
    unsigned int sys_lx_pll_sel_oc40,
    unsigned int flag
    )
{
    //volatile unsigned int wait_loop_cnt;
    unsigned int target_sys_pll_ctl;
    u32_t is_25MHz;

    /*
     * Note: We assume it's running in the SRAM on OCP0 bus now.
     */
    is_25MHz = pll_gen1_is_CKSEL_25MHz();

    /*
     * 1. LX clock flag checking
     */
    if(OTTO_PLL_LX_SET & flag){
        if(is_25MHz){
            if(REG32(SYSREG_LX_PLL_SEL_REG_A) != sys_lx_pll_sel_oc25){
                REG32(SYSREG_LX_PLL_SEL_REG_A) = sys_lx_pll_sel_oc25;
            }
        }else{
            if(REG32(SYSREG_LX_PLL_SEL_REG_A) != sys_lx_pll_sel_oc40){
                REG32(SYSREG_LX_PLL_SEL_REG_A) = sys_lx_pll_sel_oc40;
            }
        }

        /* Wait a little bit time (10ms) for the stability of PLL. */
        //wait_loop_cnt = 700 * 10000;
        //while(wait_loop_cnt--);
        udelay(10*1000);/* 10ms */
    }

    /*
     * 2. CPU/DSP/MEM clock flag checking
     */
    if( flag & (OTTO_PLL_CPU_SET | OTTO_PLL_DSP_SET| OTTO_PLL_MEM_SET) ){

    }else{
        /* No PLL change */
        return;
    }

    if(is_25MHz){
        target_sys_pll_ctl = sys_pll_ctl_oc25;
    }else{
        target_sys_pll_ctl = sys_pll_ctl_oc40;
    }

    if(OTTO_PLL_CPU_SET & flag){

    }else{
        target_sys_pll_ctl = (target_sys_pll_ctl & (~SYSREG_SYSCLK_CONTROL_OCP0PLL_MASK))
                           | (REG32(SYSREG_SYSCLK_CONTROL_REG_A) & SYSREG_SYSCLK_CONTROL_OCP0PLL_MASK);
    }

    if(OTTO_PLL_DSP_SET & flag){

    }else{
        target_sys_pll_ctl = (target_sys_pll_ctl & (~SYSREG_SYSCLK_CONTROL_OCP1PLL_MASK))
                           | (REG32(SYSREG_SYSCLK_CONTROL_REG_A) & SYSREG_SYSCLK_CONTROL_OCP1PLL_MASK);
    }

    if(OTTO_PLL_MEM_SET & flag){

    }else{
        target_sys_pll_ctl = (target_sys_pll_ctl & (~SYSREG_SYSCLK_CONTROL_SDPLL_MASK))
                           | (REG32(SYSREG_SYSCLK_CONTROL_REG_A) & SYSREG_SYSCLK_CONTROL_SDPLL_MASK);
    }


    /* (1) CPU CLOCK select LX PLL clock */
    //wait_loop_cnt = 700 * 10000;
    //while(wait_loop_cnt--){
    //    if(wait_loop_cnt == 3500000){
    //        REG32(SYSREG_SYSTEM_STATUS_REG_A) =
    //            REG32(SYSREG_SYSTEM_STATUS_REG_A) & (~SYSREG_SYSTEM_STATUS_CF_CKSE_OCP0_MASK);
    //    }
    //}
    udelay(5*1000);/* 5ms */
            REG32(SYSREG_SYSTEM_STATUS_REG_A) = \
                REG32(SYSREG_SYSTEM_STATUS_REG_A) & (~SYSREG_SYSTEM_STATUS_CF_CKSE_OCP0_MASK);
    udelay(5*1000);/* 5ms */

    /* (2) Invoke the PLL change. */
    //wait_loop_cnt = 700 * 10000;
    //while(wait_loop_cnt--){
    //    if(wait_loop_cnt == 3500000){
    //        REG32(SYSREG_SYSCLK_CONTROL_REG_A) = target_sys_pll_ctl;
    //    }
    //}
    udelay(5*1000);/* 5ms */
            REG32(SYSREG_SYSCLK_CONTROL_REG_A) = target_sys_pll_ctl;
    udelay(5*1000);/* 5ms */

    if(OTTO_PLL_MEM_SET & flag){
        /* (3) Set MEMCLK Phase 90 to 90 */
        REG32(SYSREG_MCKG_PHS_SEL_REG_A) = sys_mckg_ph_sel;
        /* (4) Set MEMCLK Clock divison */
        REG32(SYSREG_MCKG_FREQ_DIV_REG_A) = sys_mckg_freq_div;
    }


    /* (5) CPU CLOCK select OCP0 PLL clock */
    //wait_loop_cnt = 700 * 10000;
    //while(wait_loop_cnt--){
    //    if(wait_loop_cnt == 3500000){
    //        REG32(SYSREG_SYSTEM_STATUS_REG_A) =
    //            REG32(SYSREG_SYSTEM_STATUS_REG_A) | SYSREG_SYSTEM_STATUS_CF_CKSE_OCP0_MASK;
    //    }
    //}
    udelay(5*1000);/* 5ms */
            REG32(SYSREG_SYSTEM_STATUS_REG_A) = \
                REG32(SYSREG_SYSTEM_STATUS_REG_A) | SYSREG_SYSTEM_STATUS_CF_CKSE_OCP0_MASK;
    udelay(5*1000);/* 5ms */

    _pll_freq[PLL_DEV_CPU] = PLL_MHZ_UNKNOWN;
    _pll_freq[PLL_DEV_LX]  = PLL_MHZ_UNKNOWN;
    _pll_freq[PLL_DEV_MEM] = PLL_MHZ_UNKNOWN;
    _pll_freq[PLL_DEV_DSP] = PLL_MHZ_UNKNOWN;

    return;
}

pll_result_t
pll_gen1_get_to_mhz(const pll_info_t *pll_reg,
                    pll_gen1_mhz_t *pll_mhz) {
	u32_t osc_mhz;
	pll_result_t res;

	if (pll_gen1_is_CKSEL_25MHz()) {
		osc_mhz = 25;
	} else {
		osc_mhz = 40;
	}

	if (pll_reg == NULL) {
		pll_info_t tmp;

		/* Set sysclk_control_reg_40mhz to equal
		   sysclk_control_reg_25mhz, since _pll_gen1_get_to_mhz()
		   wil choose the correct one according to osc_mhz. */
		tmp.sysclk_control_reg_25mhz = REG32(SYSREG_SYSCLK_CONTROL_REG_A);
		tmp.sysclk_control_reg_40mhz = tmp.sysclk_control_reg_25mhz;
		tmp.mckg_freq_div_reg = REG32(SYSREG_MCKG_FREQ_DIV_REG_A);
		tmp.mckg_phs_sel_reg  = REG32(SYSREG_MCKG_PHS_SEL_REG_A);

		if (REG32(SYSREG_LX_PLL_SEL_REG_A) == 0) {
			if (osc_mhz == 25) {
				tmp.lx_pll_sel_reg_25mhz = 8;
			} else {
				tmp.lx_pll_sel_reg_25mhz = 10;
			}
		} else {
			tmp.lx_pll_sel_reg_25mhz = REG32(SYSREG_LX_PLL_SEL_REG_A);
		}
		tmp.lx_pll_sel_reg_40mhz = tmp.lx_pll_sel_reg_25mhz;

		res = _pll_gen1_get_to_mhz(&tmp, pll_mhz, osc_mhz);
	} else {
		res = _pll_gen1_get_to_mhz(pll_reg, pll_mhz, osc_mhz);
	}

	return res;
}

u32_t
pll_query_freq(u32_t dev) {
	if (_pll_freq[dev] == PLL_MHZ_UNKNOWN) {
		pll_gen1_mhz_t pll_mhz;
		pll_result_t res;

		res = pll_gen1_get_to_mhz(NULL, &pll_mhz);
		if (res == PLL_RES_OK) {
#if defined(CMU_DIVISOR)
			_pll_freq[PLL_DEV_CPU] = pll_mhz.cpu / cmu_div;
			_pll_freq[PLL_DEV_LX]  = pll_mhz.lx  / cmu_div;
			_pll_freq[PLL_DEV_DSP] = pll_mhz.dsp / cmu_div;
#else
			_pll_freq[PLL_DEV_CPU] = pll_mhz.cpu;
			_pll_freq[PLL_DEV_LX]  = pll_mhz.lx;
			_pll_freq[PLL_DEV_DSP] = pll_mhz.dsp;
#endif
			_pll_freq[PLL_DEV_MEM] = pll_mhz.mem;
		}
	}

	return _pll_freq[dev];
}

#if defined(CMU_DIVISOR)
#define CMUCTRL      (*((volatile u32_t *)0xB8000308))
#define CMU_OC0_DIVo 23
#define CMU_OC1_DIVo 20
#define CMU_LX0_DIVo 17
#define CMU_LX1_DIVo 14
#define CMU_LX2_DIVo 11
#define CMU_LXP_DIVo 8
#define CMU_MODEo    6
#define CMU_MODE_DIS    (0 << CMU_MODEo)
#define CMU_MODE_EN_FIX (1 << CMU_MODEo)
#define CMU_MODE_EN_DYN (2 << CMU_MODEo)
#define CMU_OC0_SLOWo 4
#define CMU_OC1_SLOWo 3
#define CMU_LX0_SLOWo 2
#define CMU_LX1_SLOWo 1
#define CMU_LX2_SLOWo 0

void cmu_setup_info(void) {
	u32_t cmu_ctrl = CMUCTRL;

	printf("II: Enabled CMU with divisor %d... STM:", cmu_div);

	if (cmu_ctrl & (1 << CMU_OC0_SLOWo)) {
		pblr_puts(" OC0");
	}
	if (cmu_ctrl & (1 << CMU_OC1_SLOWo)) {
		pblr_puts(" OC1");
	}
	if (cmu_ctrl & (1 << CMU_LX0_SLOWo)) {
		pblr_puts(" LX0");
	}
	if (cmu_ctrl & (1 << CMU_LX1_SLOWo)) {
		pblr_puts(" LX1");
	}
	if (cmu_ctrl & (1 << CMU_LX2_SLOWo)) {
		pblr_puts(" LX2");
	}

	pblr_puts("\n");
	return;
}

void cmu_division(u32_t divisor) {
	u32_t div_factor, cmu_ctrl, tmp_divisor;
	u32_t cmu_mode;
	u32_t targ_freq_oc0, targ_freq_oc1, targ_freq_lx;

	divisor &= 0x000000ff; // to cap the max divisor to 128.

	div_factor = 0;
	cmu_ctrl = 0;

	if (divisor <= 1) {
		cmu_mode = CMU_MODE_DIS;
	} else {
		cmu_mode = CMU_MODE_EN_FIX;

		tmp_divisor = divisor;
		while (tmp_divisor >>= 1) {
			div_factor++;
		}
	}

	cmu_ctrl |= ((div_factor << CMU_OC0_DIVo) | (div_factor << CMU_OC1_DIVo) |
	             (div_factor << CMU_LX0_DIVo) | (div_factor << CMU_LX2_DIVo) |
	             (div_factor << CMU_LXP_DIVo) | cmu_mode);

	targ_freq_oc0 = pll_query_freq(PLL_DEV_CPU) * cmu_div / divisor;
	targ_freq_oc1 = pll_query_freq(PLL_DEV_DSP) * cmu_div / divisor;
	targ_freq_lx  = pll_query_freq(PLL_DEV_LX)  * cmu_div / divisor;

	CMUCTRL = cmu_ctrl;
	cmu_div = divisor;

	_pll_freq[PLL_DEV_CPU] = targ_freq_oc0;
	_pll_freq[PLL_DEV_LX]  = targ_freq_lx;
	_pll_freq[PLL_DEV_DSP] = targ_freq_oc1;

	udelay(100);

	return;
}
#endif

#if (defined(PLR_ENABLE_PLL_SET) || \
     defined(CONFIG_STANDALONE_UBOOT))
SECTION_ON_FLASH pll_result_t
pll_gen1_set_from_mhz(pll_info_t *pll_reg,
                      pll_gen1_mhz_t *pll_mhz) {
	pll_result_t res;

	if (pll_reg == NULL) {
		pll_info_t tmp;
		res = _pll_gen1_set_from_mhz(&tmp, pll_mhz);
		otto_pll_gen1_set(tmp.sysclk_control_reg_25mhz,
		                  tmp.sysclk_control_reg_40mhz,
		                  tmp.mckg_phs_sel_reg,
		                  tmp.mckg_freq_div_reg,
		                  tmp.lx_pll_sel_reg_25mhz,
		                  tmp.lx_pll_sel_reg_40mhz,
		                  OTTO_PLL_CPU_SET | OTTO_PLL_DSP_SET | OTTO_PLL_MEM_SET | OTTO_PLL_LX_SET);
	} else {
		res = _pll_gen1_set_from_mhz(pll_reg, pll_mhz);
	}

	return res;
}
#endif /* if (defined(PLR_ENABLE_PLL_SET) || defined(CONFIG_STANDALONE_UBOOT)) */
