/*
 * File: DHP.c
 *
 * Code generated for Simulink model 'DHP_model'.
 *
 * Model version                  : 1.5367
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:33:37 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "DHP.h"

/* Include model header file for global data */
#include "DHP_model.h"
#include "DHP_model_private.h"

/* Output and update for atomic system: '<S4>/AllFaultPriorityCollect' */
void DHP_model_AllFaultPriorityCollect(void)
{
  boolean_T rtb_LogicalOperator1;
  uint8_T rtb_MinMax5;
  uint8_T rtb_MinMax6;
  uint8_T rtb_MinMax1;
  uint8_T rtb_MinMax7;
  uint8_T u0;
  uint8_T u0_0;

  /* MinMax: '<S25>/MinMax5' */
  if (DHP_model_B.Fault_Valid_Time_c.Switch2_i >=
      DHP_model_B.Fault_Valid_Time_k.Switch2_i) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_c.Switch2_i;
  } else {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_k.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_j.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_j.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_o.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_o.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_i.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_i.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Switch2_bk)) {
    rtb_MinMax5 = DHP_model_B.Switch2_bk;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_b.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_b.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_n.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_n.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_d.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_d.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_am.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_am.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Switch2_bf)) {
    rtb_MinMax5 = DHP_model_B.Switch2_bf;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_h.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_h.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_o0.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_o0.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_la.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_la.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_n1.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_n1.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_nvm.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_nvm.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_nw.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_nw.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_is.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_is.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_nm.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_nm.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_ai.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_ai.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Switch2_jd)) {
    rtb_MinMax5 = DHP_model_B.Switch2_jd;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_j5.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_j5.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_lp.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_lp.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_m.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_m.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_g.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_g.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_jy.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_jy.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_eo.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_eo.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_n1v.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_n1v.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_oe.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_oe.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_jj.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_jj.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_e.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_e.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_a.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_a.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Switch2_p3)) {
    rtb_MinMax5 = DHP_model_B.Switch2_p3;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_ch.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_ch.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_jv.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_jv.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_mv.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_mv.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_d.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_d.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_f.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_f.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_l3.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_l3.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_c0.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_c0.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_im.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_im.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_kz.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_kz.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_oa.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_oa.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_n.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_n.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_p.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_p.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_a.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_a.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_j1.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_j1.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_ew.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_ew.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_kv.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_kv.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_ir.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_ir.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_e3.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_e3.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_b1.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_b1.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_an.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_an.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_ho.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_ho.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_ds.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_ds.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_jx.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_jx.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_cg.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_cg.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_kvr.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_kvr.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_bm.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_bm.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_bz.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_bz.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_kb.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_kb.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_ae.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_ae.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_e5.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_e5.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_c5.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_c5.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_m.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_m.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_nv.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_nv.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_f.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_f.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_k.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_k.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_b.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_b.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_c.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_c.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_l.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_l.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_et.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_et.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_cw.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_cw.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_le.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_le.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_ni.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_ni.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_dj.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_dj.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_os.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_os.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_e34.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_e34.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_k1.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_k1.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_i1.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_i1.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_kt.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_kt.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_i.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_i.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_e.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_e.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_cx.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_cx.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_ij.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_ij.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_l.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_l.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_k4.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_k4.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_h.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_h.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_ez.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_ez.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_bn.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_bn.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_g.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_g.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_gf.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_gf.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_mf.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_mf.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_j.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_j.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_og.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_og.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Switch2_nh)) {
    rtb_MinMax5 = DHP_model_B.Switch2_nh;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Switch2_f3)) {
    rtb_MinMax5 = DHP_model_B.Switch2_f3;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Switch2_ph)) {
    rtb_MinMax5 = DHP_model_B.Switch2_ph;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Switch2_lj)) {
    rtb_MinMax5 = DHP_model_B.Switch2_lj;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_os.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_os.Switch2_i;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_o.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_o.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_nq.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_nq.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_RT_jt.Switch2_m)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_RT_jt.Switch2_m;
  }

  if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_p.Switch2_i)) {
    rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_p.Switch2_i;
  }

  /* End of MinMax: '<S25>/MinMax5' */

  /* MinMax: '<S25>/MinMax6' */
  if (DHP_model_B.Fault_Valid_RT_mp.Switch2_m >=
      DHP_model_B.Fault_Valid_RT_bzj.Switch2_m) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_mp.Switch2_m;
  } else {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_bzj.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_Time_im.Switch2_i)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_Time_im.Switch2_i;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_Time_k5.Switch2_i)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_Time_k5.Switch2_i;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_Time_kh.Switch2_i)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_Time_kh.Switch2_i;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_Time_pv.Switch2_i)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_Time_pv.Switch2_i;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_Time_nj.Switch2_i)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_Time_nj.Switch2_i;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_Time_jc.Switch2_i)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_Time_jc.Switch2_i;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_Time_j4.Switch2_i)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_Time_j4.Switch2_i;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Switch2_fl)) {
    rtb_MinMax6 = DHP_model_B.Switch2_fl;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_bf.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_bf.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_hi.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_hi.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_en.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_en.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_a4.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_a4.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_mn.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_mn.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_hm.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_hm.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_ke.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_ke.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_Time_ad.Switch2_i)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_Time_ad.Switch2_i;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_cu.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_cu.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_lt.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_lt.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_jk.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_jk.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_oy.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_oy.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_g1.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_g1.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_fm.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_fm.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_ii.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_ii.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_e1.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_e1.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_etn.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_etn.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_hg.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_hg.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_iw.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_iw.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_c2.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_c2.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_e2.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_e2.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_ax.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_ax.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_ik.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_ik.Switch2_m;
  }

  if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_j0.Switch2_m)) {
    rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_j0.Switch2_m;
  }

  /* End of MinMax: '<S25>/MinMax6' */

  /* MinMax: '<S25>/MinMax1' */
  if (DHP_model_B.Fault_Valid_Time_ak.Switch2_i >=
      DHP_model_B.Fault_Valid_Time_iw.Switch2_i) {
    rtb_MinMax1 = DHP_model_B.Fault_Valid_Time_ak.Switch2_i;
  } else {
    rtb_MinMax1 = DHP_model_B.Fault_Valid_Time_iw.Switch2_i;
  }

  if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_Time_ix.Switch2_i)) {
    rtb_MinMax1 = DHP_model_B.Fault_Valid_Time_ix.Switch2_i;
  }

  if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_Time_a0.Switch2_i)) {
    rtb_MinMax1 = DHP_model_B.Fault_Valid_Time_a0.Switch2_i;
  }

  if (!(rtb_MinMax1 >= DHP_model_B.Switch2_bc)) {
    rtb_MinMax1 = DHP_model_B.Switch2_bc;
  }

  if (!(rtb_MinMax1 >= DHP_model_B.Switch2_gz)) {
    rtb_MinMax1 = DHP_model_B.Switch2_gz;
  }

  if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_kl.Switch2_m)) {
    rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_kl.Switch2_m;
  }

  /* End of MinMax: '<S25>/MinMax1' */

  /* MinMax: '<S25>/MinMax7' */
  if (DHP_model_B.Fault_Valid_Time_as.Switch2_i >=
      DHP_model_B.Fault_Valid_Time_iy.Switch2_i) {
    rtb_MinMax7 = DHP_model_B.Fault_Valid_Time_as.Switch2_i;
  } else {
    rtb_MinMax7 = DHP_model_B.Fault_Valid_Time_iy.Switch2_i;
  }

  if (!(rtb_MinMax7 >= DHP_model_B.Fault_Valid_Time_gy.Switch2_i)) {
    rtb_MinMax7 = DHP_model_B.Fault_Valid_Time_gy.Switch2_i;
  }

  if (!(rtb_MinMax7 >= DHP_model_B.Fault_Valid_Time_fa.Switch2_i)) {
    rtb_MinMax7 = DHP_model_B.Fault_Valid_Time_fa.Switch2_i;
  }

  if (!(rtb_MinMax7 >= DHP_model_B.Fault_Valid_Time_cb.Switch2_i)) {
    rtb_MinMax7 = DHP_model_B.Fault_Valid_Time_cb.Switch2_i;
  }

  if (!(rtb_MinMax7 >= DHP_model_B.Switch2_n)) {
    rtb_MinMax7 = DHP_model_B.Switch2_n;
  }

  if (!(rtb_MinMax7 >= DHP_model_B.Fault_Valid_RT_my.Switch2_m)) {
    rtb_MinMax7 = DHP_model_B.Fault_Valid_RT_my.Switch2_m;
  }

  /* End of MinMax: '<S25>/MinMax7' */

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/Constant1'
   *  Constant: '<S25>/Constant2'
   *  MinMax: '<S25>/MinMax10'
   */
  if (KDHP_AllVehDeviceMaxFaultLever_Ovrdflg) {
    VDHP_MaxFaultLever_Light = KDHP_AllVehDeviceMaxFaultLever_Ovrdval;
  } else {
    if (rtb_MinMax5 >= rtb_MinMax6) {
      /* MinMax: '<S25>/MinMax10' */
      u0 = rtb_MinMax5;
    } else {
      /* MinMax: '<S25>/MinMax10' */
      u0 = rtb_MinMax6;
    }

    /* MinMax: '<S25>/MinMax10' */
    if (!(u0 >= rtb_MinMax1)) {
      u0 = rtb_MinMax1;
    }

    if (u0 >= rtb_MinMax7) {
      VDHP_MaxFaultLever_Light = u0;
    } else {
      VDHP_MaxFaultLever_Light = rtb_MinMax7;
    }
  }

  /* End of Switch: '<S25>/Switch1' */

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   */
  DHP_output.VDHP_VehFaultLight_flg = (VDHP_MaxFaultLever_Light >= 2);

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S29>/Constant37'
   *  MinMax: '<S29>/MinMax'
   */
  if ((int32_T)KDHP_AllVehDeviceDropRpmPct_Ovrdflg > 0) {
    VDHP_Spd_Limit = KDHP_AllVehDeviceDropRpmPct_Ovrdval;
  } else {
    if (DHP_model_B.Fault_Valid_Time_c.Switch3 <=
        DHP_model_B.Fault_Valid_Time_k.Switch3) {
      /* MinMax: '<S29>/MinMax' */
      u0 = DHP_model_B.Fault_Valid_Time_c.Switch3;
    } else {
      /* MinMax: '<S29>/MinMax' */
      u0 = DHP_model_B.Fault_Valid_Time_k.Switch3;
    }

    /* MinMax: '<S29>/MinMax' */
    if (!(u0 <= DHP_model_B.Fault_Valid_Time_j.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_j.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_o.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_o.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_i.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_i.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch4_ft)) {
      u0 = DHP_model_B.Switch4_ft;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_b.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_b.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_n.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_n.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_d.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_d.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_am.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_am.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Action.Switch3)) {
      u0 = DHP_model_B.Fault_Action.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_lp.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_lp.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_m.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_m.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_g.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_g.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_jy.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_jy.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_eo.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_eo.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_n1v.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_n1v.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_oe.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_oe.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_jj.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_jj.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ds.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_ds.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_h.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_h.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_o0.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_o0.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_la.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_la.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_n1.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_n1.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nvm.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_nvm.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nw.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_nw.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch13_f)) {
      u0 = DHP_model_B.Switch13_f;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_is.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_is.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nm.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_nm.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_j5.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_j5.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ai.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_ai.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ch.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ch.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_jv.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_jv.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mv.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_mv.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_d.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_d.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_f.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_f.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_l3.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_l3.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_c0.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_c0.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_im.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_im.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kz.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_kz.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_oa.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_oa.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_n.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_n.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_p.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_p.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_a.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_a.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_j1.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_j1.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ew.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ew.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kv.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_kv.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ir.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ir.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_e3.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_e3.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_b1.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_b1.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_an.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_an.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ho.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ho.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_e.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_e.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_a.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_a.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch3_p)) {
      u0 = DHP_model_B.Switch3_p;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_jx.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_jx.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_cg.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_cg.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kvr.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_kvr.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bm.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_bm.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bz.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_bz.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kb.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_kb.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ae.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ae.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ot.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_ot.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nvb.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_nvb.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_e5.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_e5.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_c5.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_c5.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_m.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_m.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nv.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_nv.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_f.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_f.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_k.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_k.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_b.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_b.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_c.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_c.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_l.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_l.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_et.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_et.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_cw.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_cw.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_le.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_le.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ni.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ni.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_dj.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_dj.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_os.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_os.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_e34.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_e34.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_k1.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_k1.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_i1.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_i1.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kt.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_kt.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_i.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_i.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_e.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_e.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_cx.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_cx.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ij.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ij.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_l.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_l.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_k4.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_k4.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_h.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_h.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ez.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ez.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bn.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_bn.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_g.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_g.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_gf.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_gf.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mf.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_mf.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_j.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_j.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_og.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_og.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch3_e)) {
      u0 = DHP_model_B.Switch3_e;
    }

    if (!(u0 <= DHP_model_B.Switch13_fa)) {
      u0 = DHP_model_B.Switch13_fa;
    }

    if (!(u0 <= DHP_model_B.Switch3_k)) {
      u0 = DHP_model_B.Switch3_k;
    }

    if (!(u0 <= DHP_model_B.Switch3_fp)) {
      u0 = DHP_model_B.Switch3_fp;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_os.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_os.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_o.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_o.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_nq.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_nq.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_jt.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_jt.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_p.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_p.Switch3;
    }

    /* MinMax: '<S29>/MinMax1' */
    if (DHP_model_B.Fault_Valid_RT_b3.Switch3 <=
        DHP_model_B.Fault_Valid_RT_mp.Switch3) {
      u0_0 = DHP_model_B.Fault_Valid_RT_b3.Switch3;
    } else {
      u0_0 = DHP_model_B.Fault_Valid_RT_mp.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_bzj.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_bzj.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_im.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_im.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_k5.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_k5.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_kh.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_kh.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_pv.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_pv.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_nj.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_nj.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_jc.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_jc.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_j4.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_j4.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Switch13_e)) {
      u0_0 = DHP_model_B.Switch13_e;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_j1b.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_j1b.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_hb.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_hb.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_gv.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_gv.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ds.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ds.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_bf.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_bf.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_hi.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_hi.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_en.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_en.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Switch3_n)) {
      u0_0 = DHP_model_B.Switch3_n;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_a4.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_a4.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_mn.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_mn.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_hm.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_hm.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_kf.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_kf.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ke.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ke.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_nk.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_nk.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_cii.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_cii.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ci.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ci.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_ad.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_ad.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_cu.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_cu.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_lt.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_lt.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_jk.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_jk.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_oy.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_oy.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_g1.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_g1.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_fm.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_fm.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ii.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ii.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_e1.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_e1.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_etn.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_etn.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_hg.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_hg.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_iw.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_iw.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_c2.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_c2.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_e2.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_e2.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ax.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ax.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ik.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ik.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_j1y.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_j1y.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_j0.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_j0.Switch3;
    }

    /* End of MinMax: '<S29>/MinMax1' */

    /* MinMax: '<S29>/MinMax4' */
    if (u0 <= u0_0) {
      u0_0 = u0;
    }

    /* MinMax: '<S29>/MinMax2' */
    if (DHP_model_B.Fault_Valid_RT_kj.Switch3 <=
        DHP_model_B.Fault_Valid_RT_du.Switch3) {
      u0 = DHP_model_B.Fault_Valid_RT_kj.Switch3;
    } else {
      u0 = DHP_model_B.Fault_Valid_RT_du.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_jm.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_jm.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ad.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ad.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_pi.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_pi.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_pa.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_pa.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_iq.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_iq.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch3_bz)) {
      u0 = DHP_model_B.Switch3_bz;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_k1s.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_k1s.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch3_m)) {
      u0 = DHP_model_B.Switch3_m;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bt.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_bt.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch13_k)) {
      u0 = DHP_model_B.Switch13_k;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_py.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_py.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mb.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_mb.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_m5.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_m5.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bne.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_bne.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch3_cw)) {
      u0 = DHP_model_B.Switch3_cw;
    }

    if (!(u0 <= DHP_model_B.Switch13)) {
      u0 = DHP_model_B.Switch13;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ag.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ag.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mr.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_mr.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kbz.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_kbz.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ewi.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_ewi.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch3_b)) {
      u0 = DHP_model_B.Switch3_b;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_l4.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_l4.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_if.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_if.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ak.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_ak.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_iw.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_iw.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ix.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_ix.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_a0.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_Time_a0.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch3_o)) {
      u0 = DHP_model_B.Switch3_o;
    }

    if (!(u0 <= DHP_model_B.Switch3_a)) {
      u0 = DHP_model_B.Switch3_a;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_id.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_id.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kl.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_kl.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_h3.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_h3.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_co.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_co.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_at.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_at.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_n0.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_n0.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_gt.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_gt.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_c5o.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_c5o.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_de.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_de.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_gk.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_gk.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_lf.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_lf.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_hj.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_hj.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mz.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_mz.Switch3;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_m4.Switch3)) {
      u0 = DHP_model_B.Fault_Valid_RT_m4.Switch3;
    }

    if (!(u0 <= DHP_model_B.Switch3_d)) {
      u0 = DHP_model_B.Switch3_d;
    }

    /* End of MinMax: '<S29>/MinMax2' */

    /* MinMax: '<S29>/MinMax4' */
    if (u0_0 <= u0) {
      u0 = u0_0;
    }

    /* MinMax: '<S29>/MinMax3' */
    if (DHP_model_B.Switch3_c <= DHP_model_B.Switch3_h) {
      u0_0 = DHP_model_B.Switch3_c;
    } else {
      u0_0 = DHP_model_B.Switch3_h;
    }

    if (!(u0_0 <= DHP_model_B.Switch3_g)) {
      u0_0 = DHP_model_B.Switch3_g;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_as.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_as.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_iy.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_iy.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_gy.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_gy.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_fa.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_fa.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_cb.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_cb.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Switch3)) {
      u0_0 = DHP_model_B.Switch3;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_my.Switch3)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_my.Switch3;
    }

    /* End of MinMax: '<S29>/MinMax3' */

    /* MinMax: '<S29>/MinMax4' */
    if (u0 <= u0_0) {
      VDHP_Spd_Limit = u0;
    } else {
      VDHP_Spd_Limit = u0_0;
    }
  }

  /* End of Switch: '<S29>/Switch' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant37'
   *  MinMax: '<S28>/MinMax'
   */
  if ((int32_T)KDHP_AllVehDeviceDropPwrPct_Ovrdflg > 0) {
    VDHP_Pwr_Limit_Pct = KDHP_AllVehDeviceDropPwrPct_Ovrdval;
  } else {
    if (DHP_model_B.Fault_Valid_Time_c.Switch4 <=
        DHP_model_B.Fault_Valid_Time_k.Switch4) {
      /* MinMax: '<S28>/MinMax' */
      u0 = DHP_model_B.Fault_Valid_Time_c.Switch4;
    } else {
      /* MinMax: '<S28>/MinMax' */
      u0 = DHP_model_B.Fault_Valid_Time_k.Switch4;
    }

    /* MinMax: '<S28>/MinMax' */
    if (!(u0 <= DHP_model_B.Fault_Valid_Time_j.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_j.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_o.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_o.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_i.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_i.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch3_md)) {
      u0 = DHP_model_B.Switch3_md;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_b.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_b.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_n.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_n.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_d.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_d.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_am.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_am.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Action.Switch4)) {
      u0 = DHP_model_B.Fault_Action.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_lp.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_lp.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_m.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_m.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_g.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_g.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_jy.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_jy.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_eo.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_eo.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_n1v.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_n1v.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_oe.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_oe.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_jj.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_jj.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ds.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_ds.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_h.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_h.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_o0.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_o0.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_la.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_la.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_n1.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_n1.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nvm.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_nvm.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nw.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_nw.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch3_oc)) {
      u0 = DHP_model_B.Switch3_oc;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_is.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_is.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nm.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_nm.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_j5.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_j5.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ai.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_ai.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ch.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ch.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_jv.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_jv.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mv.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_mv.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_d.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_d.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_f.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_f.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_l3.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_l3.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_c0.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_c0.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_im.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_im.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kz.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_kz.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_oa.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_oa.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_n.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_n.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_p.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_p.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_a.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_a.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_j1.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_j1.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ew.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ew.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kv.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_kv.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ir.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ir.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_e3.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_e3.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_b1.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_b1.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_an.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_an.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ho.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ho.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_e.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_e.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_a.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_a.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch4_lt)) {
      u0 = DHP_model_B.Switch4_lt;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_jx.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_jx.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_cg.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_cg.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kvr.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_kvr.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bm.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_bm.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bz.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_bz.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kb.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_kb.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ae.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ae.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ot.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_ot.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nvb.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_nvb.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_e5.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_e5.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_c5.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_c5.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_m.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_m.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_nv.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_nv.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_f.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_f.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_k.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_k.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_b.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_b.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_c.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_c.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_l.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_l.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_et.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_et.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_cw.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_cw.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_le.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_le.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ni.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ni.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_dj.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_dj.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_os.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_os.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_e34.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_e34.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_k1.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_k1.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_i1.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_i1.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kt.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_kt.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_i.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_i.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_e.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_e.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_cx.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_cx.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ij.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ij.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_l.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_l.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_k4.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_k4.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_h.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_h.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ez.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ez.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bn.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_bn.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_g.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_g.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_gf.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_gf.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mf.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_mf.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_j.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_j.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_og.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_og.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch4_lp)) {
      u0 = DHP_model_B.Switch4_lp;
    }

    if (!(u0 <= DHP_model_B.Switch3_n4)) {
      u0 = DHP_model_B.Switch3_n4;
    }

    if (!(u0 <= DHP_model_B.Switch4_l)) {
      u0 = DHP_model_B.Switch4_l;
    }

    if (!(u0 <= DHP_model_B.Switch4_m)) {
      u0 = DHP_model_B.Switch4_m;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_os.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_os.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_o.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_o.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_nq.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_nq.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_jt.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_jt.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_p.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_p.Switch4;
    }

    /* MinMax: '<S28>/MinMax1' */
    if (DHP_model_B.Fault_Valid_RT_b3.Switch4 <=
        DHP_model_B.Fault_Valid_RT_mp.Switch4) {
      u0_0 = DHP_model_B.Fault_Valid_RT_b3.Switch4;
    } else {
      u0_0 = DHP_model_B.Fault_Valid_RT_mp.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_bzj.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_bzj.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_im.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_im.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_k5.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_k5.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_kh.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_kh.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_pv.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_pv.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_nj.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_nj.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_jc.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_jc.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_j4.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_j4.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Switch3_f)) {
      u0_0 = DHP_model_B.Switch3_f;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_j1b.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_j1b.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_hb.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_hb.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_gv.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_gv.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ds.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ds.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_bf.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_bf.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_hi.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_hi.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_en.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_en.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Switch4_ot)) {
      u0_0 = DHP_model_B.Switch4_ot;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_a4.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_a4.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_mn.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_mn.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_hm.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_hm.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_kf.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_kf.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ke.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ke.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_nk.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_nk.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_cii.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_cii.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ci.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ci.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_ad.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_ad.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_cu.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_cu.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_lt.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_lt.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_jk.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_jk.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_oy.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_oy.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_g1.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_g1.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_fm.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_fm.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ii.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ii.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_e1.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_e1.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_etn.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_etn.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_hg.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_hg.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_iw.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_iw.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_c2.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_c2.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_e2.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_e2.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ax.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ax.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_ik.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_ik.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_j1y.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_j1y.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_j0.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_j0.Switch4;
    }

    /* End of MinMax: '<S28>/MinMax1' */

    /* MinMax: '<S28>/MinMax4' */
    if (u0 <= u0_0) {
      u0_0 = u0;
    }

    /* MinMax: '<S28>/MinMax2' */
    if (DHP_model_B.Fault_Valid_RT_kj.Switch4 <=
        DHP_model_B.Fault_Valid_RT_du.Switch4) {
      u0 = DHP_model_B.Fault_Valid_RT_kj.Switch4;
    } else {
      u0 = DHP_model_B.Fault_Valid_RT_du.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_jm.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_jm.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ad.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ad.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_pi.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_pi.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_pa.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_pa.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_iq.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_iq.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch4_cf)) {
      u0 = DHP_model_B.Switch4_cf;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_k1s.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_k1s.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch4_n)) {
      u0 = DHP_model_B.Switch4_n;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bt.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_bt.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch9_m)) {
      u0 = DHP_model_B.Switch9_m;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_py.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_py.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mb.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_mb.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_m5.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_m5.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_bne.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_bne.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch4_e)) {
      u0 = DHP_model_B.Switch4_e;
    }

    if (!(u0 <= DHP_model_B.Switch9)) {
      u0 = DHP_model_B.Switch9;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ag.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ag.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mr.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_mr.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kbz.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_kbz.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_ewi.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_ewi.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch4_pt)) {
      u0 = DHP_model_B.Switch4_pt;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_l4.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_l4.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_if.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_if.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ak.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_ak.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_iw.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_iw.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_ix.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_ix.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_Time_a0.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_Time_a0.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch4_o)) {
      u0 = DHP_model_B.Switch4_o;
    }

    if (!(u0 <= DHP_model_B.Switch4_j)) {
      u0 = DHP_model_B.Switch4_j;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_id.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_id.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_kl.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_kl.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_h3.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_h3.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_co.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_co.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_at.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_at.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_n0.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_n0.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_gt.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_gt.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_c5o.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_c5o.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_de.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_de.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_gk.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_gk.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_lf.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_lf.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_hj.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_hj.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_mz.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_mz.Switch4;
    }

    if (!(u0 <= DHP_model_B.Fault_Valid_RT_m4.Switch4)) {
      u0 = DHP_model_B.Fault_Valid_RT_m4.Switch4;
    }

    if (!(u0 <= DHP_model_B.Switch4_b)) {
      u0 = DHP_model_B.Switch4_b;
    }

    /* End of MinMax: '<S28>/MinMax2' */

    /* MinMax: '<S28>/MinMax4' */
    if (u0_0 <= u0) {
      u0 = u0_0;
    }

    /* MinMax: '<S28>/MinMax3' */
    if (DHP_model_B.Switch4_f <= DHP_model_B.Switch4_c) {
      u0_0 = DHP_model_B.Switch4_f;
    } else {
      u0_0 = DHP_model_B.Switch4_c;
    }

    if (!(u0_0 <= DHP_model_B.Switch4_p)) {
      u0_0 = DHP_model_B.Switch4_p;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_as.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_as.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_iy.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_iy.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_gy.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_gy.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_fa.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_fa.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_Time_cb.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_Time_cb.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Switch4)) {
      u0_0 = DHP_model_B.Switch4;
    }

    if (!(u0_0 <= DHP_model_B.Fault_Valid_RT_my.Switch4)) {
      u0_0 = DHP_model_B.Fault_Valid_RT_my.Switch4;
    }

    /* End of MinMax: '<S28>/MinMax3' */

    /* MinMax: '<S28>/MinMax4' */
    if (u0 <= u0_0) {
      VDHP_Pwr_Limit_Pct = u0;
    } else {
      VDHP_Pwr_Limit_Pct = u0_0;
    }
  }

  /* End of Switch: '<S28>/Switch' */

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S25>/Constant37'
   *  MinMax: '<S25>/MinMax2'
   */
  if (KDHP_AllVehDeviceMaxFaultLever_Ovrdflg) {
    VDHP_MaxFaultLever = KDHP_AllVehDeviceMaxFaultLever_Ovrdval;
  } else {
    if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_ot.Switch2_i)) {
      /* MinMax: '<S25>/MinMax2' */
      rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_ot.Switch2_i;
    }

    /* MinMax: '<S25>/MinMax2' */
    if (!(rtb_MinMax5 >= DHP_model_B.Fault_Valid_Time_nvb.Switch2_i)) {
      rtb_MinMax5 = DHP_model_B.Fault_Valid_Time_nvb.Switch2_i;
    }

    /* MinMax: '<S25>/MinMax3' */
    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_b3.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_b3.Switch2_m;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_j1b.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_j1b.Switch2_m;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_gv.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_gv.Switch2_m;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_ds.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_ds.Switch2_m;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_kf.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_kf.Switch2_m;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_hb.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_hb.Switch2_m;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Switch2_fx)) {
      rtb_MinMax6 = DHP_model_B.Switch2_fx;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_nk.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_nk.Switch2_m;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_cii.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_cii.Switch2_m;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_ci.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_ci.Switch2_m;
    }

    if (!(rtb_MinMax6 >= DHP_model_B.Fault_Valid_RT_j1y.Switch2_m)) {
      rtb_MinMax6 = DHP_model_B.Fault_Valid_RT_j1y.Switch2_m;
    }

    /* End of MinMax: '<S25>/MinMax3' */

    /* MinMax: '<S25>/MinMax4' */
    if (rtb_MinMax5 >= rtb_MinMax6) {
      rtb_MinMax6 = rtb_MinMax5;
    }

    /* MinMax: '<S25>/MinMax8' */
    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_kj.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_kj.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_du.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_du.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_jm.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_jm.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_ad.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_ad.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_pi.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_pi.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_pa.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_pa.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_iq.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_iq.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Switch2_ip)) {
      rtb_MinMax1 = DHP_model_B.Switch2_ip;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_k1s.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_k1s.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Switch2_fe)) {
      rtb_MinMax1 = DHP_model_B.Switch2_fe;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_bt.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_bt.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Switch2_dh)) {
      rtb_MinMax1 = DHP_model_B.Switch2_dh;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_py.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_py.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_mb.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_mb.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_m5.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_m5.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_bne.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_bne.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Switch2_mf)) {
      rtb_MinMax1 = DHP_model_B.Switch2_mf;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Switch2_i)) {
      rtb_MinMax1 = DHP_model_B.Switch2_i;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_ag.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_ag.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_mr.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_mr.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_kbz.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_kbz.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_ewi.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_ewi.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Switch2_bh)) {
      rtb_MinMax1 = DHP_model_B.Switch2_bh;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_l4.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_l4.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_if.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_if.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_id.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_id.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_h3.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_h3.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_co.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_co.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_at.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_at.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_n0.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_n0.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_gt.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_gt.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_c5o.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_c5o.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_de.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_de.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_gk.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_gk.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_lf.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_lf.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_hj.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_hj.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_mz.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_mz.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Fault_Valid_RT_m4.Switch2_m)) {
      rtb_MinMax1 = DHP_model_B.Fault_Valid_RT_m4.Switch2_m;
    }

    if (!(rtb_MinMax1 >= DHP_model_B.Switch2_f)) {
      rtb_MinMax1 = DHP_model_B.Switch2_f;
    }

    /* End of MinMax: '<S25>/MinMax8' */

    /* MinMax: '<S25>/MinMax4' */
    if (rtb_MinMax6 >= rtb_MinMax1) {
      rtb_MinMax1 = rtb_MinMax6;
    }

    /* MinMax: '<S25>/MinMax9' */
    if (!(rtb_MinMax7 >= DHP_model_B.Switch2_a)) {
      rtb_MinMax7 = DHP_model_B.Switch2_a;
    }

    if (!(rtb_MinMax7 >= DHP_model_B.Switch2_d5d)) {
      rtb_MinMax7 = DHP_model_B.Switch2_d5d;
    }

    if (!(rtb_MinMax7 >= DHP_model_B.Switch2_bp)) {
      rtb_MinMax7 = DHP_model_B.Switch2_bp;
    }

    /* End of MinMax: '<S25>/MinMax9' */

    /* MinMax: '<S25>/MinMax4' */
    if (rtb_MinMax1 >= rtb_MinMax7) {
      VDHP_MaxFaultLever = rtb_MinMax1;
    } else {
      VDHP_MaxFaultLever = rtb_MinMax7;
    }
  }

  /* End of Switch: '<S25>/Switch' */

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/Constant37'
   *  S-Function (sfix_bitop): '<S26>/Bitwise Operator'
   *  S-Function (sfix_bitop): '<S26>/Bitwise Operator1'
   *  S-Function (sfix_bitop): '<S26>/Bitwise Operator2'
   *  S-Function (sfix_bitop): '<S26>/Bitwise Operator3'
   *  S-Function (sfix_bitop): '<S26>/Bitwise Operator4'
   */
  if (KDHP_AllResponseBits_Ovrdflg) {
    VDHP_AllResponseBits = KDHP_AllResponseBits_Ovrdval;
  } else {
    VDHP_AllResponseBits = (uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)(DHP_model_B.Fault_Valid_Time_c.Switch2 |
      DHP_model_B.Fault_Valid_Time_k.Switch2) |
      DHP_model_B.Fault_Valid_Time_j.Switch2) |
      DHP_model_B.Fault_Valid_Time.Switch2) |
      DHP_model_B.Fault_Valid_Time_o.Switch2) |
      DHP_model_B.Fault_Valid_Time_i.Switch2) | DHP_model_B.Switch2_c) |
      DHP_model_B.Fault_Valid_Time_b.Switch2) |
      DHP_model_B.Fault_Valid_Time_n.Switch2) |
      DHP_model_B.Fault_Valid_Time_d.Switch2) |
      DHP_model_B.Fault_Valid_Time_am.Switch2) |
      DHP_model_B.Fault_Action.Switch2) | DHP_model_B.Fault_Valid_Time_h.Switch2)
      | DHP_model_B.Fault_Valid_Time_o0.Switch2) |
      DHP_model_B.Fault_Valid_Time_la.Switch2) |
      DHP_model_B.Fault_Valid_Time_n1.Switch2) |
      DHP_model_B.Fault_Valid_Time_nvm.Switch2) |
      DHP_model_B.Fault_Valid_Time_nw.Switch2) | DHP_model_B.Switch2_o3) |
      DHP_model_B.Fault_Valid_RT_is.Switch2) |
      DHP_model_B.Fault_Valid_Time_nm.Switch2) |
      DHP_model_B.Fault_Valid_Time_j5.Switch2) |
      DHP_model_B.Fault_Valid_Time_ai.Switch2) |
      DHP_model_B.Fault_Valid_RT_ch.Switch2) |
      DHP_model_B.Fault_Valid_RT_jv.Switch2) |
      DHP_model_B.Fault_Valid_RT_mv.Switch2) |
      DHP_model_B.Fault_Valid_RT_d.Switch2) |
      DHP_model_B.Fault_Valid_RT_f.Switch2) |
      DHP_model_B.Fault_Valid_RT_l3.Switch2) |
      DHP_model_B.Fault_Valid_RT_c0.Switch2) |
      DHP_model_B.Fault_Valid_RT_im.Switch2) |
      DHP_model_B.Fault_Valid_RT_kz.Switch2) |
      DHP_model_B.Fault_Valid_RT_oa.Switch2) |
      DHP_model_B.Fault_Valid_RT_n.Switch2) |
      DHP_model_B.Fault_Valid_RT_p.Switch2) |
      DHP_model_B.Fault_Valid_RT_a.Switch2) |
      DHP_model_B.Fault_Valid_RT_j1.Switch2) |
      DHP_model_B.Fault_Valid_RT_ew.Switch2) |
      DHP_model_B.Fault_Valid_RT_kv.Switch2) |
      DHP_model_B.Fault_Valid_RT_ir.Switch2) |
      DHP_model_B.Fault_Valid_RT_e3.Switch2) |
      DHP_model_B.Fault_Valid_RT_b1.Switch2) |
      DHP_model_B.Fault_Valid_RT_an.Switch2) |
      DHP_model_B.Fault_Valid_RT_ho.Switch2) |
      DHP_model_B.Fault_Valid_Time_e.Switch2) |
      DHP_model_B.Fault_Valid_Time_a.Switch2) |
      DHP_model_B.Fault_Valid_RT.Switch2) | DHP_model_B.Switch2_eb) |
      DHP_model_B.Fault_Valid_Time_lp.Switch2) |
      DHP_model_B.Fault_Valid_Time_m.Switch2) |
      DHP_model_B.Fault_Valid_Time_g.Switch2) |
      DHP_model_B.Fault_Valid_Time_jy.Switch2) |
      DHP_model_B.Fault_Valid_Time_eo.Switch2) |
      DHP_model_B.Fault_Valid_Time_n1v.Switch2) |
      DHP_model_B.Fault_Valid_Time_oe.Switch2) |
      DHP_model_B.Fault_Valid_Time_jj.Switch2) |
      DHP_model_B.Fault_Valid_Time_ds.Switch2) |
      DHP_model_B.Fault_Valid_Time_jx.Switch2) |
      DHP_model_B.Fault_Valid_RT_cg.Switch2) |
      DHP_model_B.Fault_Valid_RT_kvr.Switch2) |
      DHP_model_B.Fault_Valid_RT_bm.Switch2) |
      DHP_model_B.Fault_Valid_RT_bz.Switch2) |
      DHP_model_B.Fault_Valid_RT_kb.Switch2) |
      DHP_model_B.Fault_Valid_RT_ae.Switch2) |
      DHP_model_B.Fault_Valid_Time_ot.Switch2) |
      DHP_model_B.Fault_Valid_Time_nvb.Switch2) |
      DHP_model_B.Fault_Valid_RT_e5.Switch2) |
      DHP_model_B.Fault_Valid_RT_c5.Switch2) |
      DHP_model_B.Fault_Valid_RT_m.Switch2) |
      DHP_model_B.Fault_Valid_Time_nv.Switch2) |
      DHP_model_B.Fault_Valid_Time_f.Switch2) |
      DHP_model_B.Fault_Valid_RT_k.Switch2) |
      DHP_model_B.Fault_Valid_RT_b.Switch2) |
      DHP_model_B.Fault_Valid_RT_c.Switch2) |
      DHP_model_B.Fault_Valid_Time_l.Switch2) |
      DHP_model_B.Fault_Valid_RT_et.Switch2) |
      DHP_model_B.Fault_Valid_RT_cw.Switch2) |
      DHP_model_B.Fault_Valid_Time_le.Switch2) |
      DHP_model_B.Fault_Valid_RT_ni.Switch2) |
      DHP_model_B.Fault_Valid_RT_dj.Switch2) |
      DHP_model_B.Fault_Valid_RT_os.Switch2) |
      DHP_model_B.Fault_Valid_RT_e34.Switch2) |
      DHP_model_B.Fault_Valid_RT_k1.Switch2) |
      DHP_model_B.Fault_Valid_RT_i1.Switch2) |
      DHP_model_B.Fault_Valid_RT_kt.Switch2) |
      DHP_model_B.Fault_Valid_RT_i.Switch2) |
      DHP_model_B.Fault_Valid_RT_e.Switch2) |
      DHP_model_B.Fault_Valid_RT_cx.Switch2) |
      DHP_model_B.Fault_Valid_RT_ij.Switch2) |
      DHP_model_B.Fault_Valid_RT_l.Switch2) |
      DHP_model_B.Fault_Valid_RT_k4.Switch2) |
      DHP_model_B.Fault_Valid_RT_h.Switch2) |
      DHP_model_B.Fault_Valid_RT_ez.Switch2) |
                  DHP_model_B.Fault_Valid_RT_bn.Switch2) |
       DHP_model_B.Fault_Valid_RT_g.Switch2) |
      DHP_model_B.Fault_Valid_RT_gf.Switch2) |
      DHP_model_B.Fault_Valid_RT_mf.Switch2) |
      DHP_model_B.Fault_Valid_RT_j.Switch2) |
      DHP_model_B.Fault_Valid_RT_og.Switch2) | DHP_model_B.Switch2_l) |
       DHP_model_B.Switch2_gk) | DHP_model_B.Switch2_od) | DHP_model_B.Switch2_k)
      | DHP_model_B.Fault_Valid_Time_os.Switch2) |
      DHP_model_B.Fault_Valid_RT_o.Switch2) |
                  DHP_model_B.Fault_Valid_RT_nq.Switch2) |
       DHP_model_B.Fault_Valid_RT_jt.Switch2) |
      DHP_model_B.Fault_Valid_Time_p.Switch2) | (uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      (DHP_model_B.Fault_Valid_RT_b3.Switch2 |
      DHP_model_B.Fault_Valid_RT_mp.Switch2) |
      DHP_model_B.Fault_Valid_RT_bzj.Switch2) |
      DHP_model_B.Fault_Valid_Time_im.Switch2) |
      DHP_model_B.Fault_Valid_Time_k5.Switch2) |
      DHP_model_B.Fault_Valid_Time_kh.Switch2) |
      DHP_model_B.Fault_Valid_Time_pv.Switch2) |
      DHP_model_B.Fault_Valid_Time_nj.Switch2) |
      DHP_model_B.Fault_Valid_Time_jc.Switch2) |
      DHP_model_B.Fault_Valid_Time_j4.Switch2) | DHP_model_B.Switch2_ei) |
      DHP_model_B.Fault_Valid_RT_j1b.Switch2) |
      DHP_model_B.Fault_Valid_RT_hb.Switch2) |
      DHP_model_B.Fault_Valid_RT_gv.Switch2) |
      DHP_model_B.Fault_Valid_RT_ds.Switch2) |
      DHP_model_B.Fault_Valid_RT_bf.Switch2) |
      DHP_model_B.Fault_Valid_RT_hi.Switch2) |
      DHP_model_B.Fault_Valid_RT_en.Switch2) | DHP_model_B.Switch2_gf) |
      DHP_model_B.Fault_Valid_RT_a4.Switch2) |
      DHP_model_B.Fault_Valid_RT_mn.Switch2) |
      DHP_model_B.Fault_Valid_RT_hm.Switch2) |
      DHP_model_B.Fault_Valid_RT_kf.Switch2) |
      DHP_model_B.Fault_Valid_RT_ke.Switch2) |
      DHP_model_B.Fault_Valid_RT_nk.Switch2) |
      DHP_model_B.Fault_Valid_RT_cii.Switch2) |
      DHP_model_B.Fault_Valid_RT_ci.Switch2) |
      DHP_model_B.Fault_Valid_Time_ad.Switch2) |
      DHP_model_B.Fault_Valid_RT_cu.Switch2) |
                  DHP_model_B.Fault_Valid_RT_lt.Switch2) |
       DHP_model_B.Fault_Valid_RT_jk.Switch2) |
      DHP_model_B.Fault_Valid_RT_oy.Switch2) |
      DHP_model_B.Fault_Valid_RT_g1.Switch2) |
      DHP_model_B.Fault_Valid_RT_fm.Switch2) |
      DHP_model_B.Fault_Valid_RT_ii.Switch2) |
                  DHP_model_B.Fault_Valid_RT_e1.Switch2) |
       DHP_model_B.Fault_Valid_RT_etn.Switch2) |
      DHP_model_B.Fault_Valid_RT_hg.Switch2) |
      DHP_model_B.Fault_Valid_RT_iw.Switch2) |
      DHP_model_B.Fault_Valid_RT_c2.Switch2) |
      DHP_model_B.Fault_Valid_RT_e2.Switch2) |
                  DHP_model_B.Fault_Valid_RT_ax.Switch2) |
       DHP_model_B.Fault_Valid_RT_ik.Switch2) |
      DHP_model_B.Fault_Valid_RT_j1y.Switch2) |
      DHP_model_B.Fault_Valid_RT_j0.Switch2)) | (uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      (DHP_model_B.Fault_Valid_RT_kj.Switch2 |
      DHP_model_B.Fault_Valid_RT_du.Switch2) |
      DHP_model_B.Fault_Valid_RT_jm.Switch2) |
      DHP_model_B.Fault_Valid_RT_ad.Switch2) |
      DHP_model_B.Fault_Valid_RT_pi.Switch2) |
      DHP_model_B.Fault_Valid_RT_pa.Switch2) |
      DHP_model_B.Fault_Valid_RT_iq.Switch2) | DHP_model_B.Switch2_d5) |
      DHP_model_B.Fault_Valid_RT_k1s.Switch2) | DHP_model_B.Switch2_or) |
      DHP_model_B.Fault_Valid_RT_bt.Switch2) | DHP_model_B.Switch14_o) |
      DHP_model_B.Fault_Valid_RT_py.Switch2) |
      DHP_model_B.Fault_Valid_RT_mb.Switch2) |
      DHP_model_B.Fault_Valid_RT_m5.Switch2) |
      DHP_model_B.Fault_Valid_RT_bne.Switch2) | DHP_model_B.Switch2_b) |
      DHP_model_B.Switch14) | DHP_model_B.Fault_Valid_RT_ag.Switch2) |
      DHP_model_B.Fault_Valid_RT_mr.Switch2) |
      DHP_model_B.Fault_Valid_RT_kbz.Switch2) |
      DHP_model_B.Fault_Valid_RT_ewi.Switch2) | DHP_model_B.Switch2_j) |
      DHP_model_B.Fault_Valid_RT_l4.Switch2) |
      DHP_model_B.Fault_Valid_RT_if.Switch2) |
      DHP_model_B.Fault_Valid_Time_ak.Switch2) |
      DHP_model_B.Fault_Valid_Time_iw.Switch2) |
      DHP_model_B.Fault_Valid_Time_ix.Switch2) |
      DHP_model_B.Fault_Valid_Time_a0.Switch2) | DHP_model_B.Switch2_d) |
                  DHP_model_B.Switch2_m) | DHP_model_B.Fault_Valid_RT_id.Switch2)
      | DHP_model_B.Fault_Valid_RT_kl.Switch2) |
      DHP_model_B.Fault_Valid_RT_h3.Switch2) |
      DHP_model_B.Fault_Valid_RT_co.Switch2) |
      DHP_model_B.Fault_Valid_RT_at.Switch2) |
                  DHP_model_B.Fault_Valid_RT_n0.Switch2) |
       DHP_model_B.Fault_Valid_RT_gt.Switch2) |
      DHP_model_B.Fault_Valid_RT_c5o.Switch2) |
      DHP_model_B.Fault_Valid_RT_de.Switch2) |
      DHP_model_B.Fault_Valid_RT_gk.Switch2) |
      DHP_model_B.Fault_Valid_RT_lf.Switch2) |
                  DHP_model_B.Fault_Valid_RT_hj.Switch2) |
       DHP_model_B.Fault_Valid_RT_mz.Switch2) |
      DHP_model_B.Fault_Valid_RT_m4.Switch2) | DHP_model_B.Switch2_g)) |
      (uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)((uint16_T)
      ((uint16_T)((uint16_T)((uint16_T)(DHP_model_B.Switch2_e |
      DHP_model_B.Switch2_p) | DHP_model_B.Switch2_o) |
                  DHP_model_B.Fault_Valid_Time_as.Switch2) |
       DHP_model_B.Fault_Valid_Time_iy.Switch2) |
      DHP_model_B.Fault_Valid_Time_gy.Switch2) |
      DHP_model_B.Fault_Valid_Time_fa.Switch2) |
      DHP_model_B.Fault_Valid_Time_cb.Switch2) | DHP_model_B.Switch2) |
                 DHP_model_B.Fault_Valid_RT_my.Switch2));
  }

  /* End of Switch: '<S26>/Switch' */

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant37'
   *  DataTypeConversion: '<S49>/Extract Desired Bits'
   *  RelationalOperator: '<S44>/Compare'
   */
  if (KDHP_AllVehDeviceForbidPTC_Ovrdflg) {
    VDHP_Forbid_PTCFlg = KDHP_AllVehDeviceForbidPTC_Ovrdval;
  } else {
    VDHP_Forbid_PTCFlg = (((uint8_T)((uint32_T)VDHP_AllResponseBits >> 6) & 1) ==
                          1);
  }

  /* End of Switch: '<S27>/Switch' */

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S27>/Constant1'
   *  Constant: '<S27>/Constant2'
   *  DataTypeConversion: '<S47>/Extract Desired Bits'
   *  RelationalOperator: '<S32>/Compare'
   */
  if (KDHP_AllVehDeviceOffMainRelay_Ovrdflg) {
    VDHP_OFFMainRelayFlg = KDHP_AllVehDeviceOffMainRelay_Ovrdval;
  } else {
    VDHP_OFFMainRelayFlg = (((int32_T)((uint32_T)VDHP_AllResponseBits >> 13) & 1)
      == 1);
  }

  /* End of Switch: '<S27>/Switch1' */

  /* Switch: '<S27>/Switch10' incorporates:
   *  Constant: '<S27>/Constant19'
   *  Constant: '<S27>/Constant20'
   *  DataTypeConversion: '<S46>/Extract Desired Bits'
   *  RelationalOperator: '<S34>/Compare'
   */
  if (KDHP_AllVehDeviceForbidDCDC_Ovrdflg) {
    VDHP_Forbid_DCDCFlg = KDHP_AllVehDeviceForbidDCDC_Ovrdval;
  } else {
    VDHP_Forbid_DCDCFlg = (((uint8_T)((uint32_T)VDHP_AllResponseBits >> 3) & 1) ==
      1);
  }

  /* End of Switch: '<S27>/Switch10' */

  /* Switch: '<S27>/Switch11' incorporates:
   *  Constant: '<S27>/Constant21'
   *  Constant: '<S27>/Constant22'
   *  DataTypeConversion: '<S50>/Extract Desired Bits'
   *  RelationalOperator: '<S35>/Compare'
   */
  if (KDHP_AllVehDeviceForbidActiveDischarge_Ovrdflg) {
    VDHP_Forbid_ActiveDischargeFlg =
      KDHP_AllVehDeviceForbidActiveDischarge_Ovrdval;
  } else {
    VDHP_Forbid_ActiveDischargeFlg = (((uint8_T)((uint32_T)VDHP_AllResponseBits >>
      2) & 1) == 1);
  }

  /* End of Switch: '<S27>/Switch11' */

  /* Switch: '<S27>/Switch12' incorporates:
   *  Constant: '<S27>/Constant23'
   *  Constant: '<S27>/Constant24'
   *  DataTypeConversion: '<S56>/Extract Desired Bits'
   *  RelationalOperator: '<S36>/Compare'
   */
  if (KDHP_AllVehDeviceForbidPreCharge_Ovrdflg) {
    VDHP_Forbid_PreChargeFlg = KDHP_AllVehDeviceForbidPreCharge_Ovrdval;
  } else {
    VDHP_Forbid_PreChargeFlg = (((uint8_T)((uint32_T)VDHP_AllResponseBits >> 1)
      & 1) == 1);
  }

  /* End of Switch: '<S27>/Switch12' */

  /* Switch: '<S27>/Switch13' incorporates:
   *  Constant: '<S27>/Constant25'
   *  Constant: '<S27>/Constant26'
   *  DataTypeConversion: '<S53>/Extract Desired Bits'
   *  RelationalOperator: '<S37>/Compare'
   */
  if (KDHP_AllVehDeviceForbidCruise_Ovrdflg) {
    VDHP_Forbid_CruiseFlg = KDHP_AllVehDeviceForbidCruise_Ovrdval;
  } else {
    VDHP_Forbid_CruiseFlg = (((uint8_T)VDHP_AllResponseBits & 1) == 1);
  }

  /* End of Switch: '<S27>/Switch13' */

  /* Switch: '<S27>/Switch2' incorporates:
   *  Constant: '<S27>/Constant3'
   *  Constant: '<S27>/Constant4'
   *  DataTypeConversion: '<S31>/Extract Desired Bits'
   *  RelationalOperator: '<S38>/Compare'
   */
  if (KDHP_AllVehDeviceOffAllRelay_Ovrdflg) {
    VDHP_OFFAllHVRelayFlg = KDHP_AllVehDeviceOffAllRelay_Ovrdval;
  } else {
    VDHP_OFFAllHVRelayFlg = (((int32_T)((uint32_T)VDHP_AllResponseBits >> 12) &
      1) == 1);
  }

  /* End of Switch: '<S27>/Switch2' */

  /* Switch: '<S27>/Switch3' incorporates:
   *  Constant: '<S27>/Constant5'
   *  Constant: '<S27>/Constant6'
   *  DataTypeConversion: '<S30>/Extract Desired Bits'
   *  RelationalOperator: '<S39>/Compare'
   */
  if (KDHP_AllVehDeviceMcuDisEnable_Ovrdflg) {
    VDHP_MCU_DisEnableFlg = KDHP_AllVehDeviceMcuDisEnable_Ovrdval;
  } else {
    VDHP_MCU_DisEnableFlg = (((int32_T)((uint32_T)VDHP_AllResponseBits >> 11) &
      1) == 1);
  }

  /* End of Switch: '<S27>/Switch3' */

  /* Switch: '<S27>/Switch4' incorporates:
   *  Constant: '<S27>/Constant7'
   *  Constant: '<S27>/Constant8'
   *  DataTypeConversion: '<S51>/Extract Desired Bits'
   *  RelationalOperator: '<S40>/Compare'
   */
  if (KDHP_AllVehDeviceForbidCharge_Ovrdflg) {
    VDHP_Forbid_ChargeFlg = KDHP_AllVehDeviceForbidCharge_Ovrdval;
  } else {
    VDHP_Forbid_ChargeFlg = (((int32_T)((uint32_T)VDHP_AllResponseBits >> 10) &
      1) == 1);
  }

  /* End of Switch: '<S27>/Switch4' */

  /* Switch: '<S27>/Switch5' incorporates:
   *  Constant: '<S27>/Constant10'
   *  Constant: '<S27>/Constant9'
   *  DataTypeConversion: '<S55>/Extract Desired Bits'
   *  RelationalOperator: '<S41>/Compare'
   */
  if (KDHP_AllVehDeviceForbidCreep_Ovrdflg) {
    VDHP_Forbid_CreepFlg = KDHP_AllVehDeviceForbidCreep_Ovrdval;
  } else {
    VDHP_Forbid_CreepFlg = (((int32_T)((uint32_T)VDHP_AllResponseBits >> 9) & 1)
      == 1);
  }

  /* End of Switch: '<S27>/Switch5' */

  /* Switch: '<S27>/Switch6' incorporates:
   *  Constant: '<S27>/Constant11'
   *  Constant: '<S27>/Constant12'
   *  DataTypeConversion: '<S52>/Extract Desired Bits'
   *  RelationalOperator: '<S42>/Compare'
   */
  if (KDHP_AllVehDeviceForbidFeedback_Ovrdflg) {
    VDHP_Forbid_FeedbackFlg = KDHP_AllVehDeviceForbidFeedback_Ovrdval;
  } else {
    VDHP_Forbid_FeedbackFlg = (((int32_T)((uint32_T)VDHP_AllResponseBits >> 8) &
      1) == 1);
  }

  /* End of Switch: '<S27>/Switch6' */

  /* Switch: '<S27>/Switch7' incorporates:
   *  Constant: '<S27>/Constant13'
   *  Constant: '<S27>/Constant14'
   *  DataTypeConversion: '<S54>/Extract Desired Bits'
   *  RelationalOperator: '<S43>/Compare'
   */
  if (KDHP_AllVehDeviceForbidCondition_Ovrdflg) {
    VDHP_Forbid_ConditionFlg = KDHP_AllVehDeviceForbidCondition_Ovrdval;
  } else {
    VDHP_Forbid_ConditionFlg = (((uint8_T)((uint32_T)VDHP_AllResponseBits >> 7)
      & 1) == 1);
  }

  /* End of Switch: '<S27>/Switch7' */

  /* Switch: '<S27>/Switch8' incorporates:
   *  Constant: '<S27>/Constant15'
   *  Constant: '<S27>/Constant16'
   *  DataTypeConversion: '<S57>/Extract Desired Bits'
   *  RelationalOperator: '<S45>/Compare'
   */
  if (KDHP_AllVehDeviceNormalPowerDown_Ovrdflg) {
    VDHP_Normal_PowerDownFlg = KDHP_AllVehDeviceNormalPowerDown_Ovrdval;
  } else {
    VDHP_Normal_PowerDownFlg = (((uint8_T)((uint32_T)VDHP_AllResponseBits >> 5)
      & 1) == 1);
  }

  /* End of Switch: '<S27>/Switch8' */

  /* Switch: '<S27>/Switch9' incorporates:
   *  Constant: '<S27>/Constant17'
   *  Constant: '<S27>/Constant18'
   *  DataTypeConversion: '<S48>/Extract Desired Bits'
   *  RelationalOperator: '<S33>/Compare'
   */
  if ((int32_T)KDHP_AllVehDeviceOffDeviceRelay_Ovrdflg > 0) {
    VDHP_Off_DeviceRelayFlg = KDHP_AllVehDeviceOffDeviceRelay_Ovrdval;
  } else {
    VDHP_Off_DeviceRelayFlg = (((uint8_T)((uint32_T)VDHP_AllResponseBits >> 4) &
      1) == 1);
  }

  /* End of Switch: '<S27>/Switch9' */

  /* Logic: '<S5>/Logical Operator1' */
  rtb_LogicalOperator1 = (DHP_model_B.Fault_Valid_Time_c.Fault_Affirm.Switch2 ||
    DHP_model_B.Fault_Valid_Time_k.Fault_Affirm.Switch2 ||
    DHP_model_B.Fault_Valid_Time_j.Fault_Affirm.Switch2 ||
    DHP_model_B.Fault_Valid_Time.Fault_Affirm.Switch2);

  /* Logic: '<S5>/Logical Operator' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  Logic: '<S5>/Logical Operator4'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   */
  DHP_output.VDHP_PwrLimitLight_flg = ((VDHP_Pwr_Limit_Pct < ((uint8_T)
    DHP_PWRLIMITLAMP_PCT)) || (VDHP_Spd_Limit < ((uint8_T)DHP_SPDLIMITLAMP_KPH))
    || rtb_LogicalOperator1 || ((DHP_model_B.Switch2_a == 2) ||
    (DHP_model_B.Fault_Valid_RT_du.Switch2_m == 2)));

  /* Logic: '<S5>/Logical Operator3' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S5>/Constant19'
   *  Logic: '<S5>/Logical Operator2'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S24>/Compare'
   */
  DHP_output.VDHP_PwrLimitbyBMS_flg = ((Vehicle_Type == S11P05_Mark) &&
    (VDHP_MaxFaultLever < 2) && (!rtb_LogicalOperator1) &&
    (DHP_model_B.VINP_BMSMaxDchaPwr_kW < KDHP_PerformancePwr_Kw));
}

/* Output and update for atomic system: '<S4>/DHP_FaultStore_Interface' */
void DHP_model_DHP_FaultStore_Interface(void)
{
  uint8_T rtb_SnapShots[61];
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_Switch1;
  boolean_T rtb_Switch4;
  boolean_T rtb_Switch6;
  boolean_T rtb_Switch3;
  boolean_T rtb_Switch9;
  boolean_T rtb_Switch12;
  boolean_T rtb_Switch14;
  boolean_T rtb_Switch16;
  boolean_T rtb_Switch18;
  boolean_T rtb_Switch20;
  boolean_T rtb_Switch22;
  boolean_T rtb_Switch24;
  boolean_T rtb_Switch26;
  boolean_T rtb_Switch28;
  boolean_T rtb_Switch38;
  boolean_T rtb_Switch40;
  boolean_T rtb_Switch42;
  boolean_T rtb_Switch44;
  boolean_T rtb_Switch46;
  boolean_T rtb_Switch29;
  boolean_T rtb_Switch31;
  boolean_T rtb_Switch33;
  uint8_T rtb_RelationalOperator_0;

  /* DataStoreWrite: '<S59>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S59>/Data Type Conversion'
   */
  DTCStatusRAMTbl[0] = DHP_model_B.Switch2_mf2;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_SnapShots[0] = DHP_model_B.BusCreator.VDHP_VehSts_enum;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_SnapShots[1] = DHP_model_B.BusCreator.VDHP_PEPS_PDU_enum;

  /* DataTypeConversion: '<S58>/Data Type Conversion28' */
  rtb_SnapShots[2] = DHP_model_B.BusCreator.VDHP_GearOut_enum;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn4' */
  rtb_SnapShots[3] = DHP_model_B.BusCreator.VDHP_AccelPedal_per;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn5' */
  rtb_SnapShots[4] = DHP_model_B.BusCreator.VDHP_BrkLightSwitchActive_flg;

  /* DataTypeConversion: '<S58>/Data Type Conversion3' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic15'
   */
  rtb_SnapShots[5] = (uint8_T)(DHP_model_B.BusCreator.VDHP_TotalVehDistance_km >>
    16);

  /* DataTypeConversion: '<S58>/Data Type Conversion4' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic1'
   */
  rtb_SnapShots[6] = (uint8_T)(DHP_model_B.BusCreator.VDHP_TotalVehDistance_km >>
    8);

  /* DataTypeConversion: '<S58>/Data Type Conversion19' */
  rtb_SnapShots[7] = (uint8_T)DHP_model_B.BusCreator.VDHP_TotalVehDistance_km;

  /* DataTypeConversion: '<S58>/Data Type Conversion7' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic4'
   */
  rtb_SnapShots[8] = (uint8_T)((uint32_T)
    DHP_model_B.BusCreator.VDHP_ABS_VehicleSpeed >> 8);

  /* DataTypeConversion: '<S58>/Data Type Conversion8' */
  rtb_SnapShots[9] = (uint8_T)DHP_model_B.BusCreator.VDHP_ABS_VehicleSpeed;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn11' */
  rtb_SnapShots[10] = DHP_model_B.BusCreator.VDHP_LVBattVoltage_V;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn12' */
  rtb_SnapShots[11] = DHP_model_B.BusCreator.VDHP_BMSChrgSts_enum;

  /* DataTypeConversion: '<S58>/Data Type Conversion16' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic5'
   */
  rtb_SnapShots[12] = (uint8_T)((uint32_T)DHP_model_B.BusCreator.VDHP_TMTqReq >>
    8);

  /* DataTypeConversion: '<S58>/Data Type Conversion17' */
  rtb_SnapShots[13] = (uint8_T)DHP_model_B.BusCreator.VDHP_TMTqReq;

  /* DataTypeConversion: '<S58>/Data Type Conversion11' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic9'
   */
  rtb_SnapShots[14] = (uint8_T)((uint32_T)DHP_model_B.BusCreator.VDHP_MotTqReal >>
    8);

  /* DataTypeConversion: '<S58>/Data Type Conversion12' */
  rtb_SnapShots[15] = (uint8_T)DHP_model_B.BusCreator.VDHP_MotTqReal;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn17' */
  rtb_SnapShots[16] = DHP_model_B.BusCreator.VDHP_MCUIGBTT;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn18' */
  rtb_SnapShots[17] = DHP_model_B.BusCreator.VDHP_MCUElecMotT;

  /* DataTypeConversion: '<S58>/Data Type Conversion2' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic7'
   */
  rtb_SnapShots[18] = (uint8_T)((uint32_T)
    DHP_model_B.BusCreator.VDHP_MCUElecMotSpd >> 8);

  /* DataTypeConversion: '<S58>/Data Type Conversion10' */
  rtb_SnapShots[19] = (uint8_T)DHP_model_B.BusCreator.VDHP_MCUElecMotSpd;

  /* DataTypeConversion: '<S58>/Data Type Conversion21' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic6'
   */
  rtb_SnapShots[20] = (uint8_T)((uint32_T)DHP_model_B.BusCreator.VDHP_BMSSOC >>
    8);

  /* DataTypeConversion: '<S58>/Data Type Conversion22' */
  rtb_SnapShots[21] = (uint8_T)DHP_model_B.BusCreator.VDHP_BMSSOC;

  /* DataTypeConversion: '<S58>/Data Type Conversion13' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic11'
   */
  rtb_SnapShots[22] = (uint8_T)((uint32_T)DHP_model_B.BusCreator.VDHP_BMSBattU >>
    8);

  /* DataTypeConversion: '<S58>/Data Type Conversion23' */
  rtb_SnapShots[23] = (uint8_T)DHP_model_B.BusCreator.VDHP_BMSBattU;

  /* DataTypeConversion: '<S58>/Data Type Conversion14' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic12'
   */
  rtb_SnapShots[24] = (uint8_T)((uint32_T)DHP_model_B.BusCreator.VDHP_BMSBattI >>
    8);

  /* DataTypeConversion: '<S58>/Data Type Conversion15' */
  rtb_SnapShots[25] = (uint8_T)DHP_model_B.BusCreator.VDHP_BMSBattI;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn27' */
  rtb_SnapShots[26] = DHP_model_B.BusCreator.VDHP_BMSAvrgBattT;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn28' */
  rtb_SnapShots[27] = DHP_model_B.BusCreator.VDHP_DCDCT;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn29' */
  rtb_SnapShots[28] = DHP_model_B.BusCreator.VDHP_FltTime_Year;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn30' */
  rtb_SnapShots[29] = DHP_model_B.BusCreator.VDHP_FltTime_Month;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn31' */
  rtb_SnapShots[30] = DHP_model_B.BusCreator.VDHP_FltTime_Day;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn32' */
  rtb_SnapShots[31] = DHP_model_B.BusCreator.VDHP_FltTime_Hour;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn33' */
  rtb_SnapShots[32] = DHP_model_B.BusCreator.VDHP_FltTime_Minute;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn34' */
  rtb_SnapShots[33] = DHP_model_B.BusCreator.VDHP_FltTime_Second;

  /* DataTypeConversion: '<S58>/Data Type Conversion36' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic2'
   */
  rtb_SnapShots[34] = (uint8_T)((uint32_T)DHP_model_B.BusCreator.VDHP_BMSErrNum >>
    8);

  /* DataTypeConversion: '<S58>/Data Type Conversion37' */
  rtb_SnapShots[35] = (uint8_T)DHP_model_B.BusCreator.VDHP_BMSErrNum;

  /* DataTypeConversion: '<S58>/Data Type Conversion38' */
  rtb_SnapShots[36] = DHP_model_B.BusCreator.VDHP_MCUErrNum;

  /* DataTypeConversion: '<S58>/Data Type Conversion1' */
  rtb_SnapShots[37] = DHP_model_B.BusCreator.VDHP_BrkLightSwitch;

  /* DataTypeConversion: '<S58>/Data Type Conversion5' */
  rtb_SnapShots[38] = DHP_model_B.BusCreator.VDHP_GearSwitch;

  /* DataTypeConversion: '<S58>/Data Type Conversion6' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic3'
   */
  rtb_SnapShots[39] = (uint8_T)((uint32_T)
    DHP_model_B.BusCreator.VDHP_AccelPedalH_kv >> 8);

  /* DataTypeConversion: '<S58>/Data Type Conversion9' */
  rtb_SnapShots[40] = (uint8_T)DHP_model_B.BusCreator.VDHP_AccelPedalH_kv;

  /* DataTypeConversion: '<S58>/Data Type Conversion18' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic8'
   */
  rtb_SnapShots[41] = (uint8_T)((uint32_T)
    DHP_model_B.BusCreator.VDHP_AccelPedalL_kv >> 8);

  /* DataTypeConversion: '<S58>/Data Type Conversion20' */
  rtb_SnapShots[42] = (uint8_T)DHP_model_B.BusCreator.VDHP_AccelPedalL_kv;

  /* DataTypeConversion: '<S58>/Data Type Conversion24' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic10'
   */
  rtb_SnapShots[43] = (uint8_T)((uint32_T)
    DHP_model_B.BusCreator.VDHP_WaterPWM_Duty >> 8);

  /* DataTypeConversion: '<S58>/Data Type Conversion25' */
  rtb_SnapShots[44] = (uint8_T)DHP_model_B.BusCreator.VDHP_WaterPWM_Duty;

  /* DataTypeConversion: '<S58>/Data Type Conversion26' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic13'
   */
  rtb_SnapShots[45] = (uint8_T)((uint32_T)
    DHP_model_B.BusCreator.VDHP_VacuumPump_HZ >> 8);

  /* DataTypeConversion: '<S58>/Data Type Conversion27' */
  rtb_SnapShots[46] = (uint8_T)DHP_model_B.BusCreator.VDHP_VacuumPump_HZ;

  /* DataTypeConversion: '<S58>/Data Type Conversion29' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic14'
   */
  rtb_SnapShots[47] = (uint8_T)((uint32_T)
    DHP_model_B.BusCreator.VDHP_SRSPWM_Duty >> 8);

  /* DataTypeConversion: '<S58>/Data Type Conversion30' */
  rtb_SnapShots[48] = (uint8_T)DHP_model_B.BusCreator.VDHP_SRSPWM_Duty;

  /* DataTypeConversion: '<S58>/Data Type Conversion31' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic16'
   */
  rtb_SnapShots[49] = (uint8_T)((uint32_T)DHP_model_B.BusCreator.VDHP_SRSPWM_HZ >>
    8);

  /* DataTypeConversion: '<S58>/Data Type Conversion32' */
  rtb_SnapShots[50] = (uint8_T)DHP_model_B.BusCreator.VDHP_SRSPWM_HZ;

  /* DataTypeConversion: '<S58>/Data Type Conversion33' incorporates:
   *  ArithShift: '<S58>/Shift Arithmetic17'
   */
  rtb_SnapShots[51] = (uint8_T)((uint32_T)
    DHP_model_B.BusCreator.VDHP_HVInterlock_HZ >> 8);

  /* DataTypeConversion: '<S58>/Data Type Conversion34' */
  rtb_SnapShots[52] = (uint8_T)DHP_model_B.BusCreator.VDHP_HVInterlock_HZ;

  /* DataTypeConversion: '<S58>/Data Type Conversion35' */
  rtb_SnapShots[53] = DHP_model_B.BusCreator.VDHP_HLspdFan;

  /* DataTypeConversion: '<S58>/Data Type Conversion39' */
  rtb_SnapShots[54] = DHP_model_B.BusCreator.VDHP_WaterPump_flg;

  /* DataTypeConversion: '<S58>/Data Type Conversion40' */
  rtb_SnapShots[55] = DHP_model_B.BusCreator.VDHP_EPB_Status;

  /* DataTypeConversion: '<S58>/Data Type Conversion41' */
  rtb_SnapShots[56] = DHP_model_B.BusCreator.VDHP_EPBAppliedReq;

  /* DataTypeConversion: '<S58>/Data Type Conversion42' */
  rtb_SnapShots[57] = DHP_model_B.BusCreator.VDHP_FastChargeAwake_flg;

  /* DataTypeConversion: '<S58>/Data Type Conversion43' */
  rtb_SnapShots[58] = DHP_model_B.BusCreator.VDHP_SlowChargeAwake_flg;

  /* DataTypeConversion: '<S58>/Data Type Conversion44' */
  rtb_SnapShots[59] = DHP_model_B.BusCreator.VDHP_MainRelay_flg;

  /* DataTypeConversion: '<S58>/Data Type Conversion45' */
  rtb_SnapShots[60] = DHP_model_B.BusCreator.VDHP_gbWhoWriteCalArea;

  /* Chart: '<S59>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S59>/Constant'
   *  Delay: '<S59>/Delay'
   *  Logic: '<S59>/Logical Operator'
   *  Logic: '<S59>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch2_mf2, DHP_model_B.Switch2_bf,
    1U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_ej) &&
    DHP_model_B.Switch2_mf2);

  /* DataStoreWrite: '<S60>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S60>/Data Type Conversion'
   */
  DTCStatusRAMTbl[9] = DHP_model_B.Fault_Valid_RT_cx.Switch9;

  /* Chart: '<S60>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S60>/Constant'
   *  Delay: '<S60>/Delay'
   *  Logic: '<S60>/Logical Operator'
   *  Logic: '<S60>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_cx.Switch9,
    DHP_model_B.Fault_Valid_RT_cx.Switch2_m, 10U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ey) && DHP_model_B.Fault_Valid_RT_cx.Switch9);

  /* DataStoreWrite: '<S61>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S61>/Data Type Conversion'
   */
  DTCStatusRAMTbl[99] = DHP_model_B.Switch3_nn;

  /* Chart: '<S61>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S61>/Constant'
   *  Delay: '<S61>/Delay'
   *  Logic: '<S61>/Logical Operator'
   *  Logic: '<S61>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch3_nn, DHP_model_B.Switch2_n,
    100U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_ke) &&
    DHP_model_B.Switch3_nn);

  /* DataStoreWrite: '<S62>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S62>/Data Type Conversion'
   */
  DTCStatusRAMTbl[100] = DHP_model_B.Fault_Valid_RT_ch.Switch9;

  /* Chart: '<S62>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S62>/Constant'
   *  Delay: '<S62>/Delay'
   *  Logic: '<S62>/Logical Operator'
   *  Logic: '<S62>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ch.Switch9,
    DHP_model_B.Fault_Valid_RT_ch.Switch2_m, 101U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_i5l) && DHP_model_B.Fault_Valid_RT_ch.Switch9);

  /* DataStoreWrite: '<S63>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S63>/Data Type Conversion'
   */
  DTCStatusRAMTbl[101] = DHP_model_B.Fault_Valid_RT_jv.Switch9;

  /* Chart: '<S63>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S63>/Constant'
   *  Delay: '<S63>/Delay'
   *  Logic: '<S63>/Logical Operator'
   *  Logic: '<S63>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_jv.Switch9,
    DHP_model_B.Fault_Valid_RT_jv.Switch2_m, 102U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_h5b) && DHP_model_B.Fault_Valid_RT_jv.Switch9);

  /* DataStoreWrite: '<S64>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S64>/Data Type Conversion'
   */
  DTCStatusRAMTbl[102] = DHP_model_B.Fault_Valid_RT_mv.Switch9;

  /* Chart: '<S64>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S64>/Constant'
   *  Delay: '<S64>/Delay'
   *  Logic: '<S64>/Logical Operator'
   *  Logic: '<S64>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_mv.Switch9,
    DHP_model_B.Fault_Valid_RT_mv.Switch2_m, 103U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ml) && DHP_model_B.Fault_Valid_RT_mv.Switch9);

  /* DataStoreWrite: '<S65>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S65>/Data Type Conversion'
   */
  DTCStatusRAMTbl[103] = DHP_model_B.Fault_Valid_RT_d.Switch9;

  /* Chart: '<S65>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S65>/Constant'
   *  Delay: '<S65>/Delay'
   *  Logic: '<S65>/Logical Operator'
   *  Logic: '<S65>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_d.Switch9,
    DHP_model_B.Fault_Valid_RT_d.Switch2_m, 104U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ks) && DHP_model_B.Fault_Valid_RT_d.Switch9);

  /* DataStoreWrite: '<S66>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S66>/Data Type Conversion'
   */
  DTCStatusRAMTbl[104] = DHP_model_B.Fault_Valid_RT_f.Switch9;

  /* Chart: '<S66>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S66>/Constant'
   *  Delay: '<S66>/Delay'
   *  Logic: '<S66>/Logical Operator'
   *  Logic: '<S66>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_f.Switch9,
    DHP_model_B.Fault_Valid_RT_f.Switch2_m, 105U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_es) && DHP_model_B.Fault_Valid_RT_f.Switch9);

  /* DataStoreWrite: '<S67>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S67>/Data Type Conversion'
   */
  DTCStatusRAMTbl[105] = DHP_model_B.Fault_Valid_RT_l3.Switch9;

  /* Chart: '<S67>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S67>/Constant'
   *  Delay: '<S67>/Delay'
   *  Logic: '<S67>/Logical Operator'
   *  Logic: '<S67>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_l3.Switch9,
    DHP_model_B.Fault_Valid_RT_l3.Switch2_m, 106U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ie) && DHP_model_B.Fault_Valid_RT_l3.Switch9);

  /* DataStoreWrite: '<S68>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S68>/Data Type Conversion'
   */
  DTCStatusRAMTbl[106] = DHP_model_B.Fault_Valid_RT_c0.Switch9;

  /* Chart: '<S68>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S68>/Constant'
   *  Delay: '<S68>/Delay'
   *  Logic: '<S68>/Logical Operator'
   *  Logic: '<S68>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_c0.Switch9,
    DHP_model_B.Fault_Valid_RT_c0.Switch2_m, 107U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_cq) && DHP_model_B.Fault_Valid_RT_c0.Switch9);

  /* DataStoreWrite: '<S69>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S69>/Data Type Conversion'
   */
  DTCStatusRAMTbl[107] = DHP_model_B.Fault_Valid_RT_im.Switch9;

  /* Chart: '<S69>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S69>/Constant'
   *  Delay: '<S69>/Delay'
   *  Logic: '<S69>/Logical Operator'
   *  Logic: '<S69>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_im.Switch9,
    DHP_model_B.Fault_Valid_RT_im.Switch2_m, 108U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_cj) && DHP_model_B.Fault_Valid_RT_im.Switch9);

  /* DataStoreWrite: '<S70>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   */
  DTCStatusRAMTbl[108] = DHP_model_B.Fault_Valid_RT_kz.Switch9;

  /* Chart: '<S70>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S70>/Constant'
   *  Delay: '<S70>/Delay'
   *  Logic: '<S70>/Logical Operator'
   *  Logic: '<S70>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_kz.Switch9,
    DHP_model_B.Fault_Valid_RT_kz.Switch2_m, 109U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ox) && DHP_model_B.Fault_Valid_RT_kz.Switch9);

  /* DataStoreWrite: '<S71>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S71>/Data Type Conversion'
   */
  DTCStatusRAMTbl[10] = DHP_model_B.Fault_Valid_Time_c.Fault_Affirm.Switch2;

  /* Chart: '<S71>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S71>/Constant'
   *  Delay: '<S71>/Delay'
   *  Logic: '<S71>/Logical Operator'
   *  Logic: '<S71>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_c.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_c.Switch2_i, 11U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_pr) &&
     DHP_model_B.Fault_Valid_Time_c.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S72>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S72>/Data Type Conversion'
   */
  DTCStatusRAMTbl[109] = DHP_model_B.Fault_Valid_RT_oa.Switch9;

  /* Chart: '<S72>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S72>/Constant'
   *  Delay: '<S72>/Delay'
   *  Logic: '<S72>/Logical Operator'
   *  Logic: '<S72>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_oa.Switch9,
    DHP_model_B.Fault_Valid_RT_oa.Switch2_m, 110U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_g4) && DHP_model_B.Fault_Valid_RT_oa.Switch9);

  /* DataStoreWrite: '<S73>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S73>/Data Type Conversion'
   */
  DTCStatusRAMTbl[110] = DHP_model_B.Fault_Valid_RT_n.Switch9;

  /* Chart: '<S73>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S73>/Constant'
   *  Delay: '<S73>/Delay'
   *  Logic: '<S73>/Logical Operator'
   *  Logic: '<S73>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_n.Switch9,
    DHP_model_B.Fault_Valid_RT_n.Switch2_m, 111U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_gp) && DHP_model_B.Fault_Valid_RT_n.Switch9);

  /* DataStoreWrite: '<S74>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S74>/Data Type Conversion'
   */
  DTCStatusRAMTbl[111] = DHP_model_B.Fault_Valid_RT_p.Switch9;

  /* Chart: '<S74>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S74>/Constant'
   *  Delay: '<S74>/Delay'
   *  Logic: '<S74>/Logical Operator'
   *  Logic: '<S74>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_p.Switch9,
    DHP_model_B.Fault_Valid_RT_p.Switch2_m, 112U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_b) && DHP_model_B.Fault_Valid_RT_p.Switch9);

  /* DataStoreWrite: '<S75>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S75>/Data Type Conversion'
   */
  DTCStatusRAMTbl[112] = DHP_model_B.Fault_Valid_RT_a.Switch9;

  /* Chart: '<S75>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S75>/Constant'
   *  Delay: '<S75>/Delay'
   *  Logic: '<S75>/Logical Operator'
   *  Logic: '<S75>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_a.Switch9,
    DHP_model_B.Fault_Valid_RT_a.Switch2_m, 113U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_a5) && DHP_model_B.Fault_Valid_RT_a.Switch9);

  /* DataStoreWrite: '<S76>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S76>/Data Type Conversion'
   */
  DTCStatusRAMTbl[113] = DHP_model_B.Fault_Valid_RT_j1.Switch9;

  /* Chart: '<S76>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S76>/Constant'
   *  Delay: '<S76>/Delay'
   *  Logic: '<S76>/Logical Operator'
   *  Logic: '<S76>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_j1.Switch9,
    DHP_model_B.Fault_Valid_RT_j1.Switch2_m, 114U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_oh) && DHP_model_B.Fault_Valid_RT_j1.Switch9);

  /* DataStoreWrite: '<S77>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S77>/Data Type Conversion'
   */
  DTCStatusRAMTbl[114] = DHP_model_B.Fault_Valid_RT_ew.Switch9;

  /* Chart: '<S77>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S77>/Constant'
   *  Delay: '<S77>/Delay'
   *  Logic: '<S77>/Logical Operator'
   *  Logic: '<S77>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ew.Switch9,
    DHP_model_B.Fault_Valid_RT_ew.Switch2_m, 115U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_mz) && DHP_model_B.Fault_Valid_RT_ew.Switch9);

  /* DataStoreWrite: '<S78>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S78>/Data Type Conversion'
   */
  DTCStatusRAMTbl[115] = DHP_model_B.Fault_Valid_RT_kv.Switch9;

  /* Chart: '<S78>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S78>/Constant'
   *  Delay: '<S78>/Delay'
   *  Logic: '<S78>/Logical Operator'
   *  Logic: '<S78>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_kv.Switch9,
    DHP_model_B.Fault_Valid_RT_kv.Switch2_m, 116U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_eo) && DHP_model_B.Fault_Valid_RT_kv.Switch9);

  /* DataStoreWrite: '<S79>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S79>/Data Type Conversion'
   */
  DTCStatusRAMTbl[116] = DHP_model_B.Fault_Valid_RT_ir.Switch9;

  /* Chart: '<S79>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S79>/Constant'
   *  Delay: '<S79>/Delay'
   *  Logic: '<S79>/Logical Operator'
   *  Logic: '<S79>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ir.Switch9,
    DHP_model_B.Fault_Valid_RT_ir.Switch2_m, 117U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_bn) && DHP_model_B.Fault_Valid_RT_ir.Switch9);

  /* DataStoreWrite: '<S80>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S80>/Data Type Conversion'
   */
  DTCStatusRAMTbl[117] = DHP_model_B.Fault_Valid_RT_e3.Switch9;

  /* Chart: '<S80>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S80>/Constant'
   *  Delay: '<S80>/Delay'
   *  Logic: '<S80>/Logical Operator'
   *  Logic: '<S80>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_e3.Switch9,
    DHP_model_B.Fault_Valid_RT_e3.Switch2_m, 118U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_jg) && DHP_model_B.Fault_Valid_RT_e3.Switch9);

  /* DataStoreWrite: '<S81>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S81>/Data Type Conversion'
   */
  DTCStatusRAMTbl[118] = DHP_model_B.Fault_Valid_RT_b1.Switch9;

  /* Chart: '<S81>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S81>/Constant'
   *  Delay: '<S81>/Delay'
   *  Logic: '<S81>/Logical Operator'
   *  Logic: '<S81>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_b1.Switch9,
    DHP_model_B.Fault_Valid_RT_b1.Switch2_m, 119U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_c0) && DHP_model_B.Fault_Valid_RT_b1.Switch9);

  /* DataStoreWrite: '<S82>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S82>/Data Type Conversion'
   */
  DTCStatusRAMTbl[11] = DHP_model_B.Fault_Valid_Time_k.Fault_Affirm.Switch2;

  /* Chart: '<S82>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S82>/Constant'
   *  Delay: '<S82>/Delay'
   *  Logic: '<S82>/Logical Operator'
   *  Logic: '<S82>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_k.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_k.Switch2_i, 12U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_cb) &&
     DHP_model_B.Fault_Valid_Time_k.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S83>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S83>/Data Type Conversion'
   */
  DTCStatusRAMTbl[119] = DHP_model_B.Fault_Valid_RT_an.Switch9;

  /* Chart: '<S83>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S83>/Constant'
   *  Delay: '<S83>/Delay'
   *  Logic: '<S83>/Logical Operator'
   *  Logic: '<S83>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_an.Switch9,
    DHP_model_B.Fault_Valid_RT_an.Switch2_m, 120U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_pe) && DHP_model_B.Fault_Valid_RT_an.Switch9);

  /* DataStoreWrite: '<S84>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S84>/Data Type Conversion'
   */
  DTCStatusRAMTbl[120] = DHP_model_B.Fault_Valid_RT_ho.Switch9;

  /* Chart: '<S84>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S84>/Constant'
   *  Delay: '<S84>/Delay'
   *  Logic: '<S84>/Logical Operator'
   *  Logic: '<S84>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ho.Switch9,
    DHP_model_B.Fault_Valid_RT_ho.Switch2_m, 121U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_fl) && DHP_model_B.Fault_Valid_RT_ho.Switch9);

  /* DataStoreWrite: '<S85>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S85>/Data Type Conversion'
   */
  DTCStatusRAMTbl[121] = DHP_model_B.Fault_Valid_RT_ij.Switch9;

  /* Chart: '<S85>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S85>/Constant'
   *  Delay: '<S85>/Delay'
   *  Logic: '<S85>/Logical Operator'
   *  Logic: '<S85>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ij.Switch9,
    DHP_model_B.Fault_Valid_RT_ij.Switch2_m, 122U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_c04) && DHP_model_B.Fault_Valid_RT_ij.Switch9);

  /* DataStoreWrite: '<S86>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S86>/Data Type Conversion'
   */
  DTCStatusRAMTbl[122] = DHP_model_B.Fault_Valid_RT_l.Switch9;

  /* Chart: '<S86>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S86>/Constant'
   *  Delay: '<S86>/Delay'
   *  Logic: '<S86>/Logical Operator'
   *  Logic: '<S86>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_l.Switch9,
    DHP_model_B.Fault_Valid_RT_l.Switch2_m, 123U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_hr) && DHP_model_B.Fault_Valid_RT_l.Switch9);

  /* DataStoreWrite: '<S87>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S87>/Data Type Conversion'
   */
  DTCStatusRAMTbl[123] = DHP_model_B.Fault_Valid_RT_k4.Switch9;

  /* Chart: '<S87>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S87>/Constant'
   *  Delay: '<S87>/Delay'
   *  Logic: '<S87>/Logical Operator'
   *  Logic: '<S87>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_k4.Switch9,
    DHP_model_B.Fault_Valid_RT_k4.Switch2_m, 124U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_hj) && DHP_model_B.Fault_Valid_RT_k4.Switch9);

  /* DataStoreWrite: '<S88>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S88>/Data Type Conversion'
   */
  DTCStatusRAMTbl[124] = DHP_model_B.Fault_Valid_RT_h.Switch9;

  /* Chart: '<S88>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S88>/Constant'
   *  Delay: '<S88>/Delay'
   *  Logic: '<S88>/Logical Operator'
   *  Logic: '<S88>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_h.Switch9,
    DHP_model_B.Fault_Valid_RT_h.Switch2_m, 125U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_kj) && DHP_model_B.Fault_Valid_RT_h.Switch9);

  /* DataStoreWrite: '<S89>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S89>/Data Type Conversion'
   */
  DTCStatusRAMTbl[125] = DHP_model_B.Fault_Valid_Time_jx.Fault_Affirm.Switch2;

  /* Chart: '<S89>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S89>/Constant'
   *  Delay: '<S89>/Delay'
   *  Logic: '<S89>/Logical Operator'
   *  Logic: '<S89>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_jx.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_jx.Switch2_i, 126U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_ko) &&
     DHP_model_B.Fault_Valid_Time_jx.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S90>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S90>/Data Type Conversion'
   */
  DTCStatusRAMTbl[126] = DHP_model_B.Fault_Valid_RT_gv.Switch9;

  /* Chart: '<S90>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S90>/Constant'
   *  Delay: '<S90>/Delay'
   *  Logic: '<S90>/Logical Operator'
   *  Logic: '<S90>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_gv.Switch9,
    DHP_model_B.Fault_Valid_RT_gv.Switch2_m, 127U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_on) && DHP_model_B.Fault_Valid_RT_gv.Switch9);

  /* DataStoreWrite: '<S91>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S91>/Data Type Conversion'
   */
  DTCStatusRAMTbl[127] = DHP_model_B.Fault_Valid_RT_ds.Switch9;

  /* Chart: '<S91>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S91>/Constant'
   *  Delay: '<S91>/Delay'
   *  Logic: '<S91>/Logical Operator'
   *  Logic: '<S91>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ds.Switch9,
    DHP_model_B.Fault_Valid_RT_ds.Switch2_m, 128U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_aa) && DHP_model_B.Fault_Valid_RT_ds.Switch9);

  /* DataStoreWrite: '<S92>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S92>/Data Type Conversion'
   */
  DTCStatusRAMTbl[128] = DHP_model_B.Fault_Valid_RT_bf.Switch9;

  /* Chart: '<S92>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S92>/Constant'
   *  Delay: '<S92>/Delay'
   *  Logic: '<S92>/Logical Operator'
   *  Logic: '<S92>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_bf.Switch9,
    DHP_model_B.Fault_Valid_RT_bf.Switch2_m, 129U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_eu) && DHP_model_B.Fault_Valid_RT_bf.Switch9);

  /* DataStoreWrite: '<S93>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S93>/Data Type Conversion'
   */
  DTCStatusRAMTbl[12] = DHP_model_B.Fault_Valid_Time_j.Fault_Affirm.Switch2;

  /* Chart: '<S93>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S93>/Constant'
   *  Delay: '<S93>/Delay'
   *  Logic: '<S93>/Logical Operator'
   *  Logic: '<S93>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_j.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_j.Switch2_i, 13U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_gc) &&
     DHP_model_B.Fault_Valid_Time_j.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S94>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S94>/Data Type Conversion'
   */
  DTCStatusRAMTbl[129] = DHP_model_B.Fault_Valid_RT_hi.Switch9;

  /* Chart: '<S94>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S94>/Constant'
   *  Delay: '<S94>/Delay'
   *  Logic: '<S94>/Logical Operator'
   *  Logic: '<S94>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_hi.Switch9,
    DHP_model_B.Fault_Valid_RT_hi.Switch2_m, 130U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_iu) && DHP_model_B.Fault_Valid_RT_hi.Switch9);

  /* DataStoreWrite: '<S95>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S95>/Data Type Conversion'
   */
  DTCStatusRAMTbl[130] = DHP_model_B.Fault_Valid_RT_en.Switch9;

  /* Chart: '<S95>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S95>/Constant'
   *  Delay: '<S95>/Delay'
   *  Logic: '<S95>/Logical Operator'
   *  Logic: '<S95>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_en.Switch9,
    DHP_model_B.Fault_Valid_RT_en.Switch2_m, 131U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_jk) && DHP_model_B.Fault_Valid_RT_en.Switch9);

  /* DataStoreWrite: '<S96>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S96>/Data Type Conversion'
   */
  DTCStatusRAMTbl[131] = DHP_model_B.Switch9_n;

  /* Chart: '<S96>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S96>/Constant'
   *  Delay: '<S96>/Delay'
   *  Logic: '<S96>/Logical Operator'
   *  Logic: '<S96>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch9_n, DHP_model_B.Switch2_fx,
    132U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_kq) &&
    DHP_model_B.Switch9_n);

  /* DataStoreWrite: '<S97>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S97>/Data Type Conversion'
   */
  DTCStatusRAMTbl[132] = DHP_model_B.Fault_Valid_RT_a4.Switch9;

  /* Chart: '<S97>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S97>/Constant'
   *  Delay: '<S97>/Delay'
   *  Logic: '<S97>/Logical Operator'
   *  Logic: '<S97>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_a4.Switch9,
    DHP_model_B.Fault_Valid_RT_a4.Switch2_m, 133U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_bw) && DHP_model_B.Fault_Valid_RT_a4.Switch9);

  /* DataStoreWrite: '<S98>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S98>/Data Type Conversion'
   */
  DTCStatusRAMTbl[133] = DHP_model_B.Fault_Valid_RT_mn.Switch9;

  /* Chart: '<S98>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S98>/Constant'
   *  Delay: '<S98>/Delay'
   *  Logic: '<S98>/Logical Operator'
   *  Logic: '<S98>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_mn.Switch9,
    DHP_model_B.Fault_Valid_RT_mn.Switch2_m, 134U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_mj) && DHP_model_B.Fault_Valid_RT_mn.Switch9);

  /* DataStoreWrite: '<S99>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S99>/Data Type Conversion'
   */
  DTCStatusRAMTbl[134] = DHP_model_B.Fault_Valid_RT_cg.Switch9;

  /* Chart: '<S99>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S99>/Constant'
   *  Delay: '<S99>/Delay'
   *  Logic: '<S99>/Logical Operator'
   *  Logic: '<S99>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_cg.Switch9,
    DHP_model_B.Fault_Valid_RT_cg.Switch2_m, 135U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_eq) && DHP_model_B.Fault_Valid_RT_cg.Switch9);

  /* DataStoreWrite: '<S100>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S100>/Data Type Conversion'
   */
  DTCStatusRAMTbl[135] = DHP_model_B.Fault_Valid_RT_kvr.Switch9;

  /* Chart: '<S100>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S100>/Constant'
   *  Delay: '<S100>/Delay'
   *  Logic: '<S100>/Logical Operator'
   *  Logic: '<S100>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_kvr.Switch9,
    DHP_model_B.Fault_Valid_RT_kvr.Switch2_m, 136U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_gk) && DHP_model_B.Fault_Valid_RT_kvr.Switch9);

  /* DataStoreWrite: '<S101>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S101>/Data Type Conversion'
   */
  DTCStatusRAMTbl[136] = DHP_model_B.Fault_Valid_RT_kf.Switch9;

  /* Chart: '<S101>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S101>/Constant'
   *  Delay: '<S101>/Delay'
   *  Logic: '<S101>/Logical Operator'
   *  Logic: '<S101>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_kf.Switch9,
    DHP_model_B.Fault_Valid_RT_kf.Switch2_m, 137U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_eyh) && DHP_model_B.Fault_Valid_RT_kf.Switch9);

  /* DataStoreWrite: '<S102>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S102>/Data Type Conversion'
   */
  DTCStatusRAMTbl[137] = DHP_model_B.Fault_Valid_RT_id.Switch9;

  /* Chart: '<S102>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S102>/Constant'
   *  Delay: '<S102>/Delay'
   *  Logic: '<S102>/Logical Operator'
   *  Logic: '<S102>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_id.Switch9,
    DHP_model_B.Fault_Valid_RT_id.Switch2_m, 138U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_mc) && DHP_model_B.Fault_Valid_RT_id.Switch9);

  /* DataStoreWrite: '<S103>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S103>/Data Type Conversion'
   */
  DTCStatusRAMTbl[138] = DHP_model_B.Fault_Valid_RT_bm.Switch9;

  /* Chart: '<S103>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S103>/Constant'
   *  Delay: '<S103>/Delay'
   *  Logic: '<S103>/Logical Operator'
   *  Logic: '<S103>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_bm.Switch9,
    DHP_model_B.Fault_Valid_RT_bm.Switch2_m, 139U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_my) && DHP_model_B.Fault_Valid_RT_bm.Switch9);

  /* DataStoreWrite: '<S104>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S104>/Data Type Conversion'
   */
  DTCStatusRAMTbl[13] = DHP_model_B.Fault_Valid_Time.Fault_Affirm.Switch2;

  /* Chart: '<S104>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S104>/Constant'
   *  Delay: '<S104>/Delay'
   *  Logic: '<S104>/Logical Operator'
   *  Logic: '<S104>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time.Switch2_i, 14U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_ew) &&
     DHP_model_B.Fault_Valid_Time.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S105>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S105>/Data Type Conversion'
   */
  DTCStatusRAMTbl[139] = DHP_model_B.Fault_Valid_RT_bz.Switch9;

  /* Chart: '<S105>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S105>/Constant'
   *  Delay: '<S105>/Delay'
   *  Logic: '<S105>/Logical Operator'
   *  Logic: '<S105>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_bz.Switch9,
    DHP_model_B.Fault_Valid_RT_bz.Switch2_m, 140U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_jr) && DHP_model_B.Fault_Valid_RT_bz.Switch9);

  /* DataStoreWrite: '<S106>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S106>/Data Type Conversion'
   */
  DTCStatusRAMTbl[140] = DHP_model_B.Fault_Valid_RT_kl.Switch9;

  /* Chart: '<S106>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S106>/Constant'
   *  Delay: '<S106>/Delay'
   *  Logic: '<S106>/Logical Operator'
   *  Logic: '<S106>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_kl.Switch9,
    DHP_model_B.Fault_Valid_RT_kl.Switch2_m, 141U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_o5) && DHP_model_B.Fault_Valid_RT_kl.Switch9);

  /* DataStoreWrite: '<S107>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S107>/Data Type Conversion'
   */
  DTCStatusRAMTbl[141] = DHP_model_B.Fault_Valid_RT_my.Switch9;

  /* Chart: '<S107>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S107>/Constant'
   *  Delay: '<S107>/Delay'
   *  Logic: '<S107>/Logical Operator'
   *  Logic: '<S107>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_my.Switch9,
    DHP_model_B.Fault_Valid_RT_my.Switch2_m, 142U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_nj) && DHP_model_B.Fault_Valid_RT_my.Switch9);

  /* DataStoreWrite: '<S108>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S108>/Data Type Conversion'
   */
  DTCStatusRAMTbl[142] = DHP_model_B.Fault_Valid_RT_kb.Switch9;

  /* Chart: '<S108>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S108>/Constant'
   *  Delay: '<S108>/Delay'
   *  Logic: '<S108>/Logical Operator'
   *  Logic: '<S108>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_kb.Switch9,
    DHP_model_B.Fault_Valid_RT_kb.Switch2_m, 143U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ewf) && DHP_model_B.Fault_Valid_RT_kb.Switch9);

  /* DataStoreWrite: '<S109>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S109>/Data Type Conversion'
   */
  DTCStatusRAMTbl[143] = DHP_model_B.Fault_Valid_RT_ae.Switch9;

  /* Chart: '<S109>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S109>/Constant'
   *  Delay: '<S109>/Delay'
   *  Logic: '<S109>/Logical Operator'
   *  Logic: '<S109>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ae.Switch9,
    DHP_model_B.Fault_Valid_RT_ae.Switch2_m, 144U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_bnm) && DHP_model_B.Fault_Valid_RT_ae.Switch9);

  /* DataStoreWrite: '<S110>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S110>/Data Type Conversion'
   */
  DTCStatusRAMTbl[144] = DHP_model_B.Fault_Valid_RT_h3.Switch9;

  /* Chart: '<S110>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S110>/Constant'
   *  Delay: '<S110>/Delay'
   *  Logic: '<S110>/Logical Operator'
   *  Logic: '<S110>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_h3.Switch9,
    DHP_model_B.Fault_Valid_RT_h3.Switch2_m, 145U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_dq) && DHP_model_B.Fault_Valid_RT_h3.Switch9);

  /* RelationalOperator: '<S7>/Relational Operator' incorporates:
   *  Constant: '<S7>/Constant8'
   *  DataStoreRead: '<S7>/Data Store Read'
   */
  rtb_RelationalOperator = (VHALI_HWVersion == ((uint8_T)DHP_HW_VCU20));

  /* Switch: '<S7>/Switch1' incorporates:
   *  Switch: '<S7>/Switch2'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch1 = DHP_model_B.Fault_Valid_RT_co.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_co.Switch2_m;
  } else {
    rtb_Switch1 = DHP_model_B.Fault_Valid_RT_e5.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_e5.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* DataStoreWrite: '<S111>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S111>/Data Type Conversion'
   */
  DTCStatusRAMTbl[145] = rtb_Switch1;

  /* Chart: '<S111>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S111>/Constant'
   *  Delay: '<S111>/Delay'
   *  Logic: '<S111>/Logical Operator'
   *  Logic: '<S111>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch1, rtb_RelationalOperator_0, 146U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_dw) && rtb_Switch1);

  /* Switch: '<S7>/Switch4' incorporates:
   *  Switch: '<S7>/Switch5'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch4 = DHP_model_B.Fault_Valid_Time_ot.Fault_Affirm.Switch2;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_Time_ot.Switch2_i;
  } else {
    rtb_Switch4 = DHP_model_B.Fault_Valid_RT_c5.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_c5.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch4' */

  /* DataStoreWrite: '<S112>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S112>/Data Type Conversion'
   */
  DTCStatusRAMTbl[146] = rtb_Switch4;

  /* Chart: '<S112>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S112>/Constant'
   *  Delay: '<S112>/Delay'
   *  Logic: '<S112>/Logical Operator'
   *  Logic: '<S112>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch4, rtb_RelationalOperator_0, 147U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_lq) && rtb_Switch4);

  /* Switch: '<S7>/Switch6' incorporates:
   *  Switch: '<S7>/Switch7'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch6 = DHP_model_B.Fault_Valid_Time_nvb.Fault_Affirm.Switch2;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_Time_nvb.Switch2_i;
  } else {
    rtb_Switch6 = DHP_model_B.Fault_Valid_RT_m.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_m.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch6' */

  /* DataStoreWrite: '<S113>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S113>/Data Type Conversion'
   */
  DTCStatusRAMTbl[147] = rtb_Switch6;

  /* Chart: '<S113>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S113>/Constant'
   *  Delay: '<S113>/Delay'
   *  Logic: '<S113>/Logical Operator'
   *  Logic: '<S113>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch6, rtb_RelationalOperator_0, 148U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_in) && rtb_Switch6);

  /* Switch: '<S7>/Switch3' incorporates:
   *  Switch: '<S7>/Switch8'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch3 = DHP_model_B.Fault_Valid_RT_ke.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_ke.Switch2_m;
  } else {
    rtb_Switch3 = DHP_model_B.Fault_Valid_Time_ad.Fault_Affirm.Switch2;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_Time_ad.Switch2_i;
  }

  /* End of Switch: '<S7>/Switch3' */

  /* DataStoreWrite: '<S114>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S114>/Data Type Conversion'
   */
  DTCStatusRAMTbl[148] = rtb_Switch3;

  /* Chart: '<S114>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S114>/Constant'
   *  Delay: '<S114>/Delay'
   *  Logic: '<S114>/Logical Operator'
   *  Logic: '<S114>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch3, rtb_RelationalOperator_0, 149U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_me) && rtb_Switch3);

  /* DataStoreWrite: '<S115>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S115>/Data Type Conversion'
   */
  DTCStatusRAMTbl[14] = DHP_model_B.Fault_Valid_Time_o.Fault_Affirm.Switch2;

  /* Chart: '<S115>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S115>/Constant'
   *  Delay: '<S115>/Delay'
   *  Logic: '<S115>/Logical Operator'
   *  Logic: '<S115>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_o.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_o.Switch2_i, 15U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_c5) &&
     DHP_model_B.Fault_Valid_Time_o.Fault_Affirm.Switch2);

  /* Switch: '<S7>/Switch9' incorporates:
   *  Switch: '<S7>/Switch10'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch9 = DHP_model_B.Fault_Valid_RT_bn.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_bn.Switch2_m;
  } else {
    rtb_Switch9 = DHP_model_B.Fault_Valid_RT_cw.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_cw.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch9' */

  /* DataStoreWrite: '<S116>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S116>/Data Type Conversion'
   */
  DTCStatusRAMTbl[149] = rtb_Switch9;

  /* Chart: '<S116>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S116>/Constant'
   *  Delay: '<S116>/Delay'
   *  Logic: '<S116>/Logical Operator'
   *  Logic: '<S116>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch9, rtb_RelationalOperator_0, 150U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_f2) && rtb_Switch9);

  /* Switch: '<S7>/Switch12' incorporates:
   *  Switch: '<S7>/Switch11'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch12 = DHP_model_B.Fault_Valid_RT_at.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_at.Switch2_m;
  } else {
    rtb_Switch12 = DHP_model_B.Fault_Valid_RT_j1y.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_j1y.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch12' */

  /* DataStoreWrite: '<S117>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S117>/Data Type Conversion'
   */
  DTCStatusRAMTbl[150] = rtb_Switch12;

  /* Chart: '<S117>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S117>/Constant'
   *  Delay: '<S117>/Delay'
   *  Logic: '<S117>/Logical Operator'
   *  Logic: '<S117>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch12, rtb_RelationalOperator_0, 151U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_oq) && rtb_Switch12);

  /* Switch: '<S7>/Switch14' incorporates:
   *  Switch: '<S7>/Switch13'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch14 = DHP_model_B.Fault_Valid_RT_n0.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_n0.Switch2_m;
  } else {
    rtb_Switch14 = DHP_model_B.Fault_Valid_RT_j0.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_j0.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch14' */

  /* DataStoreWrite: '<S118>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S118>/Data Type Conversion'
   */
  DTCStatusRAMTbl[151] = rtb_Switch14;

  /* Chart: '<S118>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S118>/Constant'
   *  Delay: '<S118>/Delay'
   *  Logic: '<S118>/Logical Operator'
   *  Logic: '<S118>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch14, rtb_RelationalOperator_0, 152U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_da) && rtb_Switch14);

  /* Switch: '<S7>/Switch16' incorporates:
   *  Switch: '<S7>/Switch15'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch16 = DHP_model_B.Fault_Valid_RT_gt.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_gt.Switch2_m;
  } else {
    rtb_Switch16 = DHP_model_B.Fault_Valid_Time_le.Fault_Affirm.Switch2;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_Time_le.Switch2_i;
  }

  /* End of Switch: '<S7>/Switch16' */

  /* DataStoreWrite: '<S119>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S119>/Data Type Conversion'
   */
  DTCStatusRAMTbl[152] = rtb_Switch16;

  /* Chart: '<S119>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S119>/Constant'
   *  Delay: '<S119>/Delay'
   *  Logic: '<S119>/Logical Operator'
   *  Logic: '<S119>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch16, rtb_RelationalOperator_0, 153U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_fir) && rtb_Switch16);

  /* Switch: '<S7>/Switch18' incorporates:
   *  Switch: '<S7>/Switch17'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch18 = DHP_model_B.Fault_Valid_RT_c5o.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_c5o.Switch2_m;
  } else {
    rtb_Switch18 = DHP_model_B.Fault_Valid_RT_ni.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_ni.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch18' */

  /* DataStoreWrite: '<S120>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S120>/Data Type Conversion'
   */
  DTCStatusRAMTbl[153] = rtb_Switch18;

  /* Chart: '<S120>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S120>/Constant'
   *  Delay: '<S120>/Delay'
   *  Logic: '<S120>/Logical Operator'
   *  Logic: '<S120>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch18, rtb_RelationalOperator_0, 154U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_bg) && rtb_Switch18);

  /* Switch: '<S7>/Switch20' incorporates:
   *  Switch: '<S7>/Switch19'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch20 = DHP_model_B.Fault_Valid_RT_de.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_de.Switch2_m;
  } else {
    rtb_Switch20 = DHP_model_B.Fault_Valid_RT_dj.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_dj.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch20' */

  /* DataStoreWrite: '<S121>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S121>/Data Type Conversion'
   */
  DTCStatusRAMTbl[154] = rtb_Switch20;

  /* Chart: '<S121>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S121>/Constant'
   *  Delay: '<S121>/Delay'
   *  Logic: '<S121>/Logical Operator'
   *  Logic: '<S121>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch20, rtb_RelationalOperator_0, 155U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_nr) && rtb_Switch20);

  /* Switch: '<S7>/Switch22' incorporates:
   *  Switch: '<S7>/Switch21'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch22 = DHP_model_B.Fault_Valid_RT_gk.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_gk.Switch2_m;
  } else {
    rtb_Switch22 = DHP_model_B.Fault_Valid_RT_os.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_os.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch22' */

  /* DataStoreWrite: '<S122>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S122>/Data Type Conversion'
   */
  DTCStatusRAMTbl[155] = rtb_Switch22;

  /* Chart: '<S122>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S122>/Constant'
   *  Delay: '<S122>/Delay'
   *  Logic: '<S122>/Logical Operator'
   *  Logic: '<S122>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch22, rtb_RelationalOperator_0, 156U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_i0) && rtb_Switch22);

  /* Switch: '<S7>/Switch24' incorporates:
   *  Switch: '<S7>/Switch23'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch24 = DHP_model_B.Fault_Valid_RT_lf.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_lf.Switch2_m;
  } else {
    rtb_Switch24 = DHP_model_B.Fault_Valid_RT_e34.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_e34.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch24' */

  /* DataStoreWrite: '<S123>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S123>/Data Type Conversion'
   */
  DTCStatusRAMTbl[156] = rtb_Switch24;

  /* Chart: '<S123>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S123>/Constant'
   *  Delay: '<S123>/Delay'
   *  Logic: '<S123>/Logical Operator'
   *  Logic: '<S123>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch24, rtb_RelationalOperator_0, 157U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_g4r) && rtb_Switch24);

  /* Switch: '<S7>/Switch26' incorporates:
   *  Switch: '<S7>/Switch25'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch26 = DHP_model_B.Fault_Valid_RT_hj.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_hj.Switch2_m;
  } else {
    rtb_Switch26 = DHP_model_B.Fault_Valid_RT_k1.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_k1.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch26' */

  /* DataStoreWrite: '<S124>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S124>/Data Type Conversion'
   */
  DTCStatusRAMTbl[157] = rtb_Switch26;

  /* Chart: '<S124>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S124>/Constant'
   *  Delay: '<S124>/Delay'
   *  Logic: '<S124>/Logical Operator'
   *  Logic: '<S124>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch26, rtb_RelationalOperator_0, 158U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_c1) && rtb_Switch26);

  /* Switch: '<S7>/Switch28' incorporates:
   *  Switch: '<S7>/Switch27'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch28 = DHP_model_B.Fault_Valid_RT_mz.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_mz.Switch2_m;
  } else {
    rtb_Switch28 = DHP_model_B.Fault_Valid_RT_i1.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_i1.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch28' */

  /* DataStoreWrite: '<S125>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S125>/Data Type Conversion'
   */
  DTCStatusRAMTbl[158] = rtb_Switch28;

  /* Chart: '<S125>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S125>/Constant'
   *  Delay: '<S125>/Delay'
   *  Logic: '<S125>/Logical Operator'
   *  Logic: '<S125>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch28, rtb_RelationalOperator_0, 159U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_k1) && rtb_Switch28);

  /* DataStoreWrite: '<S126>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S126>/Data Type Conversion'
   */
  DTCStatusRAMTbl[15] = DHP_model_B.Fault_Valid_Time_i.Fault_Affirm.Switch2;

  /* Chart: '<S126>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S126>/Constant'
   *  Delay: '<S126>/Delay'
   *  Logic: '<S126>/Logical Operator'
   *  Logic: '<S126>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_i.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_i.Switch2_i, 16U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_ny) &&
     DHP_model_B.Fault_Valid_Time_i.Fault_Affirm.Switch2);

  /* Switch: '<S7>/Switch38' incorporates:
   *  Switch: '<S7>/Switch39'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch38 = DHP_model_B.Fault_Valid_RT_m4.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_m4.Switch2_m;
  } else {
    rtb_Switch38 = DHP_model_B.Fault_Valid_RT_nq.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_nq.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch38' */

  /* DataStoreWrite: '<S127>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S127>/Data Type Conversion'
   */
  DTCStatusRAMTbl[159] = rtb_Switch38;

  /* Chart: '<S127>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S127>/Constant'
   *  Delay: '<S127>/Delay'
   *  Logic: '<S127>/Logical Operator'
   *  Logic: '<S127>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch38, rtb_RelationalOperator_0, 160U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_gi) && rtb_Switch38);

  /* Switch: '<S7>/Switch40' incorporates:
   *  Switch: '<S7>/Switch41'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch40 = DHP_model_B.Switch9_h;
    rtb_RelationalOperator_0 = DHP_model_B.Switch2_f;
  } else {
    rtb_Switch40 = DHP_model_B.Fault_Valid_RT_jt.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_jt.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch40' */

  /* DataStoreWrite: '<S128>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S128>/Data Type Conversion'
   */
  DTCStatusRAMTbl[160] = rtb_Switch40;

  /* Chart: '<S128>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S128>/Constant'
   *  Delay: '<S128>/Delay'
   *  Logic: '<S128>/Logical Operator'
   *  Logic: '<S128>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch40, rtb_RelationalOperator_0, 161U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_cbq) && rtb_Switch40);

  /* Switch: '<S7>/Switch42' incorporates:
   *  Switch: '<S7>/Switch43'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch42 = DHP_model_B.Fault_Valid_RT_nk.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_nk.Switch2_m;
  } else {
    rtb_Switch42 = DHP_model_B.Switch2_pe;
    rtb_RelationalOperator_0 = DHP_model_B.Switch2_nh;
  }

  /* End of Switch: '<S7>/Switch42' */

  /* DataStoreWrite: '<S129>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S129>/Data Type Conversion'
   */
  DTCStatusRAMTbl[161] = rtb_Switch42;

  /* Chart: '<S129>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S129>/Constant'
   *  Delay: '<S129>/Delay'
   *  Logic: '<S129>/Logical Operator'
   *  Logic: '<S129>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch42, rtb_RelationalOperator_0, 162U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_pj) && rtb_Switch42);

  /* Switch: '<S7>/Switch44' incorporates:
   *  Switch: '<S7>/Switch45'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch44 = DHP_model_B.Fault_Valid_RT_cii.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_cii.Switch2_m;
  } else {
    rtb_Switch44 = DHP_model_B.LogicalOperator3_h;
    rtb_RelationalOperator_0 = DHP_model_B.Switch2_f3;
  }

  /* End of Switch: '<S7>/Switch44' */

  /* DataStoreWrite: '<S130>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S130>/Data Type Conversion'
   */
  DTCStatusRAMTbl[162] = rtb_Switch44;

  /* Chart: '<S130>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S130>/Constant'
   *  Delay: '<S130>/Delay'
   *  Logic: '<S130>/Logical Operator'
   *  Logic: '<S130>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch44, rtb_RelationalOperator_0, 163U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_fp) && rtb_Switch44);

  /* Switch: '<S7>/Switch46' incorporates:
   *  Switch: '<S7>/Switch47'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch46 = DHP_model_B.Fault_Valid_RT_c5.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_c5.Switch2_m;
  } else {
    rtb_Switch46 = DHP_model_B.Switch2_il;
    rtb_RelationalOperator_0 = DHP_model_B.Switch2_ph;
  }

  /* End of Switch: '<S7>/Switch46' */

  /* DataStoreWrite: '<S131>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S131>/Data Type Conversion'
   */
  DTCStatusRAMTbl[163] = rtb_Switch46;

  /* Chart: '<S131>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S131>/Constant'
   *  Delay: '<S131>/Delay'
   *  Logic: '<S131>/Logical Operator'
   *  Logic: '<S131>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch46, rtb_RelationalOperator_0, 164U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_k14) && rtb_Switch46);

  /* Switch: '<S7>/Switch29' incorporates:
   *  Switch: '<S7>/Switch30'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch29 = DHP_model_B.Fault_Valid_RT_m.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_m.Switch2_m;
  } else {
    rtb_Switch29 = DHP_model_B.Switch2_n2;
    rtb_RelationalOperator_0 = DHP_model_B.Switch2_lj;
  }

  /* End of Switch: '<S7>/Switch29' */

  /* DataStoreWrite: '<S132>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S132>/Data Type Conversion'
   */
  DTCStatusRAMTbl[164] = rtb_Switch29;

  /* Chart: '<S132>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S132>/Constant'
   *  Delay: '<S132>/Delay'
   *  Logic: '<S132>/Logical Operator'
   *  Logic: '<S132>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch29, rtb_RelationalOperator_0, 165U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_cr) && rtb_Switch29);

  /* Switch: '<S7>/Switch31' incorporates:
   *  Switch: '<S7>/Switch32'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch31 = DHP_model_B.Fault_Valid_RT_ci.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_ci.Switch2_m;
  } else {
    rtb_Switch31 = DHP_model_B.Fault_Valid_Time_os.Fault_Affirm.Switch2;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_Time_os.Switch2_i;
  }

  /* End of Switch: '<S7>/Switch31' */

  /* DataStoreWrite: '<S133>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S133>/Data Type Conversion'
   */
  DTCStatusRAMTbl[165] = rtb_Switch31;

  /* Chart: '<S133>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S133>/Constant'
   *  Delay: '<S133>/Delay'
   *  Logic: '<S133>/Logical Operator'
   *  Logic: '<S133>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch31, rtb_RelationalOperator_0, 166U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_cj2) && rtb_Switch31);

  /* Switch: '<S7>/Switch33' incorporates:
   *  Switch: '<S7>/Switch34'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch33 = DHP_model_B.Fault_Valid_Time_ad.Fault_Affirm.Switch2;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_Time_ad.Switch2_i;
  } else {
    rtb_Switch33 = DHP_model_B.Fault_Valid_RT_o.Switch9;
    rtb_RelationalOperator_0 = DHP_model_B.Fault_Valid_RT_o.Switch2_m;
  }

  /* End of Switch: '<S7>/Switch33' */

  /* DataStoreWrite: '<S134>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S134>/Data Type Conversion'
   */
  DTCStatusRAMTbl[166] = rtb_Switch33;

  /* Chart: '<S134>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S134>/Constant'
   *  Delay: '<S134>/Delay'
   *  Logic: '<S134>/Logical Operator'
   *  Logic: '<S134>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(rtb_Switch33, rtb_RelationalOperator_0, 167U,
    rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_n0) && rtb_Switch33);

  /* DataStoreWrite: '<S135>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S135>/Data Type Conversion'
   */
  DTCStatusRAMTbl[16] = DHP_model_B.Fault_Affirm.Switch2;

  /* Chart: '<S135>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S135>/Constant'
   *  Delay: '<S135>/Delay'
   *  Logic: '<S135>/Logical Operator'
   *  Logic: '<S135>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Affirm.Switch2,
    DHP_model_B.Switch2_bk, 17U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_cu) &&
    DHP_model_B.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S136>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S136>/Data Type Conversion'
   */
  DTCStatusRAMTbl[17] = DHP_model_B.Fault_Valid_Time_b.Fault_Affirm.Switch2;

  /* Chart: '<S136>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S136>/Constant'
   *  Delay: '<S136>/Delay'
   *  Logic: '<S136>/Logical Operator'
   *  Logic: '<S136>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_b.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_b.Switch2_i, 18U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_pg) &&
     DHP_model_B.Fault_Valid_Time_b.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S137>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S137>/Data Type Conversion'
   */
  DTCStatusRAMTbl[18] = DHP_model_B.Fault_Valid_Time_n.Fault_Affirm.Switch2;

  /* Chart: '<S137>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S137>/Constant'
   *  Delay: '<S137>/Delay'
   *  Logic: '<S137>/Logical Operator'
   *  Logic: '<S137>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_n.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_n.Switch2_i, 19U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_kqz) &&
     DHP_model_B.Fault_Valid_Time_n.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S138>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S138>/Data Type Conversion'
   */
  DTCStatusRAMTbl[1] = DHP_model_B.Fault_Valid_RT_g.Switch9;

  /* Chart: '<S138>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S138>/Constant'
   *  Delay: '<S138>/Delay'
   *  Logic: '<S138>/Logical Operator'
   *  Logic: '<S138>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_g.Switch9,
    DHP_model_B.Fault_Valid_RT_g.Switch2_m, 2U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ee0) && DHP_model_B.Fault_Valid_RT_g.Switch9);

  /* DataStoreWrite: '<S139>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S139>/Data Type Conversion'
   */
  DTCStatusRAMTbl[19] = DHP_model_B.Fault_Valid_Time_d.Fault_Affirm.Switch2;

  /* Chart: '<S139>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S139>/Constant'
   *  Delay: '<S139>/Delay'
   *  Logic: '<S139>/Logical Operator'
   *  Logic: '<S139>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_d.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_d.Switch2_i, 20U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_n4) &&
     DHP_model_B.Fault_Valid_Time_d.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S140>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S140>/Data Type Conversion'
   */
  DTCStatusRAMTbl[20] = DHP_model_B.Fault_Valid_Time_h.Fault_Affirm.Switch2;

  /* Chart: '<S140>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S140>/Constant'
   *  Delay: '<S140>/Delay'
   *  Logic: '<S140>/Logical Operator'
   *  Logic: '<S140>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_h.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_h.Switch2_i, 21U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_ni) &&
     DHP_model_B.Fault_Valid_Time_h.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S141>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S141>/Data Type Conversion'
   */
  DTCStatusRAMTbl[21] = DHP_model_B.Fault_Valid_Time_o0.Fault_Affirm.Switch2;

  /* Chart: '<S141>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S141>/Constant'
   *  Delay: '<S141>/Delay'
   *  Logic: '<S141>/Logical Operator'
   *  Logic: '<S141>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_o0.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_o0.Switch2_i, 22U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_lf) &&
     DHP_model_B.Fault_Valid_Time_o0.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S142>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S142>/Data Type Conversion'
   */
  DTCStatusRAMTbl[22] = DHP_model_B.Fault_Valid_Time_la.Fault_Affirm.Switch2;

  /* Chart: '<S142>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S142>/Constant'
   *  Delay: '<S142>/Delay'
   *  Logic: '<S142>/Logical Operator'
   *  Logic: '<S142>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_la.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_la.Switch2_i, 23U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_fh) &&
     DHP_model_B.Fault_Valid_Time_la.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S143>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S143>/Data Type Conversion'
   */
  DTCStatusRAMTbl[23] = DHP_model_B.Fault_Valid_Time_n1.Fault_Affirm.Switch2;

  /* Chart: '<S143>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S143>/Constant'
   *  Delay: '<S143>/Delay'
   *  Logic: '<S143>/Logical Operator'
   *  Logic: '<S143>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_n1.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_n1.Switch2_i, 24U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_hs) &&
     DHP_model_B.Fault_Valid_Time_n1.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S144>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S144>/Data Type Conversion'
   */
  DTCStatusRAMTbl[24] = DHP_model_B.Fault_Valid_Time_nvm.Fault_Affirm.Switch2;

  /* Chart: '<S144>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S144>/Constant'
   *  Delay: '<S144>/Delay'
   *  Logic: '<S144>/Logical Operator'
   *  Logic: '<S144>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_nvm.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_nvm.Switch2_i, 25U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_md) &&
     DHP_model_B.Fault_Valid_Time_nvm.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S145>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S145>/Data Type Conversion'
   */
  DTCStatusRAMTbl[25] = DHP_model_B.Fault_Valid_Time_nw.Fault_Affirm.Switch2;

  /* Chart: '<S145>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S145>/Constant'
   *  Delay: '<S145>/Delay'
   *  Logic: '<S145>/Logical Operator'
   *  Logic: '<S145>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_nw.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_nw.Switch2_i, 26U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_io) &&
     DHP_model_B.Fault_Valid_Time_nw.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S146>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S146>/Data Type Conversion'
   */
  DTCStatusRAMTbl[26] = DHP_model_B.Fault_Valid_RT_is.Switch9;

  /* Chart: '<S146>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S146>/Constant'
   *  Delay: '<S146>/Delay'
   *  Logic: '<S146>/Logical Operator'
   *  Logic: '<S146>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_is.Switch9,
    DHP_model_B.Fault_Valid_RT_is.Switch2_m, 27U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_kp) && DHP_model_B.Fault_Valid_RT_is.Switch9);

  /* DataStoreWrite: '<S147>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S147>/Data Type Conversion'
   */
  DTCStatusRAMTbl[27] = DHP_model_B.Fault_Valid_Time_ai.Fault_Affirm.Switch2;

  /* Chart: '<S147>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S147>/Constant'
   *  Delay: '<S147>/Delay'
   *  Logic: '<S147>/Logical Operator'
   *  Logic: '<S147>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_ai.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_ai.Switch2_i, 28U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_l5) &&
     DHP_model_B.Fault_Valid_Time_ai.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S148>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S148>/Data Type Conversion'
   */
  DTCStatusRAMTbl[28] = DHP_model_B.Switch3_f5;

  /* Chart: '<S148>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S148>/Constant'
   *  Delay: '<S148>/Delay'
   *  Logic: '<S148>/Logical Operator'
   *  Logic: '<S148>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch3_f5, DHP_model_B.Switch2_jd,
    29U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_nt) &&
    DHP_model_B.Switch3_f5);

  /* DataStoreWrite: '<S149>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S149>/Data Type Conversion'
   */
  DTCStatusRAMTbl[2] = DHP_model_B.Fault_Valid_RT_gf.Switch9;

  /* Chart: '<S149>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S149>/Constant'
   *  Delay: '<S149>/Delay'
   *  Logic: '<S149>/Logical Operator'
   *  Logic: '<S149>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_gf.Switch9,
    DHP_model_B.Fault_Valid_RT_gf.Switch2_m, 3U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_la) && DHP_model_B.Fault_Valid_RT_gf.Switch9);

  /* DataStoreWrite: '<S150>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S150>/Data Type Conversion'
   */
  DTCStatusRAMTbl[29] = DHP_model_B.Fault_Valid_Time_j5.Fault_Affirm.Switch2;

  /* Chart: '<S150>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S150>/Constant'
   *  Delay: '<S150>/Delay'
   *  Logic: '<S150>/Logical Operator'
   *  Logic: '<S150>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_j5.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_j5.Switch2_i, 30U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_p3) &&
     DHP_model_B.Fault_Valid_Time_j5.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S151>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S151>/Data Type Conversion'
   */
  DTCStatusRAMTbl[30] = DHP_model_B.Fault_Valid_Time_nm.Fault_Affirm.Switch2;

  /* Chart: '<S151>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S151>/Constant'
   *  Delay: '<S151>/Delay'
   *  Logic: '<S151>/Logical Operator'
   *  Logic: '<S151>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_nm.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_nm.Switch2_i, 31U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_a1) &&
     DHP_model_B.Fault_Valid_Time_nm.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S152>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S152>/Data Type Conversion'
   */
  DTCStatusRAMTbl[31] = DHP_model_B.Fault_Valid_Time_am.Fault_Affirm.Switch2;

  /* Chart: '<S152>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S152>/Constant'
   *  Delay: '<S152>/Delay'
   *  Logic: '<S152>/Logical Operator'
   *  Logic: '<S152>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_am.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_am.Switch2_i, 32U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_hu) &&
     DHP_model_B.Fault_Valid_Time_am.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S153>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S153>/Data Type Conversion'
   */
  DTCStatusRAMTbl[32] = DHP_model_B.LogicalOperator3;

  /* Chart: '<S153>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S153>/Constant'
   *  Delay: '<S153>/Delay'
   *  Logic: '<S153>/Logical Operator'
   *  Logic: '<S153>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.LogicalOperator3,
    DHP_model_B.Switch2_fl, 33U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_hx) &&
    DHP_model_B.LogicalOperator3);

  /* DataStoreWrite: '<S154>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S154>/Data Type Conversion'
   */
  DTCStatusRAMTbl[33] = DHP_model_B.Fault_Valid_RT_kj.Switch9;

  /* Chart: '<S154>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S154>/Constant'
   *  Delay: '<S154>/Delay'
   *  Logic: '<S154>/Logical Operator'
   *  Logic: '<S154>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_kj.Switch9,
    DHP_model_B.Fault_Valid_RT_kj.Switch2_m, 34U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_pl) && DHP_model_B.Fault_Valid_RT_kj.Switch9);

  /* DataStoreWrite: '<S155>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S155>/Data Type Conversion'
   */
  DTCStatusRAMTbl[34] = DHP_model_B.Fault_Valid_RT_du.Switch9;

  /* Chart: '<S155>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S155>/Constant'
   *  Delay: '<S155>/Delay'
   *  Logic: '<S155>/Logical Operator'
   *  Logic: '<S155>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_du.Switch9,
    DHP_model_B.Fault_Valid_RT_du.Switch2_m, 35U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_lg) && DHP_model_B.Fault_Valid_RT_du.Switch9);

  /* DataStoreWrite: '<S156>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S156>/Data Type Conversion'
   */
  DTCStatusRAMTbl[35] = DHP_model_B.Fault_Valid_RT_jm.Switch9;

  /* Chart: '<S156>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S156>/Constant'
   *  Delay: '<S156>/Delay'
   *  Logic: '<S156>/Logical Operator'
   *  Logic: '<S156>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_jm.Switch9,
    DHP_model_B.Fault_Valid_RT_jm.Switch2_m, 36U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_hc) && DHP_model_B.Fault_Valid_RT_jm.Switch9);

  /* DataStoreWrite: '<S157>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S157>/Data Type Conversion'
   */
  DTCStatusRAMTbl[36] = DHP_model_B.Fault_Valid_Time_ak.Fault_Affirm.Switch2;

  /* Chart: '<S157>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S157>/Constant'
   *  Delay: '<S157>/Delay'
   *  Logic: '<S157>/Logical Operator'
   *  Logic: '<S157>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_ak.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_ak.Switch2_i, 37U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_bx) &&
     DHP_model_B.Fault_Valid_Time_ak.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S158>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S158>/Data Type Conversion'
   */
  DTCStatusRAMTbl[37] = DHP_model_B.Fault_Valid_Time_iw.Fault_Affirm.Switch2;

  /* Chart: '<S158>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S158>/Constant'
   *  Delay: '<S158>/Delay'
   *  Logic: '<S158>/Logical Operator'
   *  Logic: '<S158>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_iw.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_iw.Switch2_i, 38U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_d5) &&
     DHP_model_B.Fault_Valid_Time_iw.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S159>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S159>/Data Type Conversion'
   */
  DTCStatusRAMTbl[38] = DHP_model_B.Fault_Valid_Time_ix.Fault_Affirm.Switch2;

  /* Chart: '<S159>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S159>/Constant'
   *  Delay: '<S159>/Delay'
   *  Logic: '<S159>/Logical Operator'
   *  Logic: '<S159>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_ix.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_ix.Switch2_i, 39U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_eb) &&
     DHP_model_B.Fault_Valid_Time_ix.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S160>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S160>/Data Type Conversion'
   */
  DTCStatusRAMTbl[3] = DHP_model_B.Fault_Valid_RT_mf.Switch9;

  /* Chart: '<S160>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S160>/Constant'
   *  Delay: '<S160>/Delay'
   *  Logic: '<S160>/Logical Operator'
   *  Logic: '<S160>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_mf.Switch9,
    DHP_model_B.Fault_Valid_RT_mf.Switch2_m, 4U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_bwe) && DHP_model_B.Fault_Valid_RT_mf.Switch9);

  /* DataStoreWrite: '<S161>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S161>/Data Type Conversion'
   */
  DTCStatusRAMTbl[39] = DHP_model_B.Fault_Valid_Time_a0.Fault_Affirm.Switch2;

  /* Chart: '<S161>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S161>/Constant'
   *  Delay: '<S161>/Delay'
   *  Logic: '<S161>/Logical Operator'
   *  Logic: '<S161>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_a0.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_a0.Switch2_i, 40U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_bq) &&
     DHP_model_B.Fault_Valid_Time_a0.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S162>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S162>/Data Type Conversion'
   */
  DTCStatusRAMTbl[40] = DHP_model_B.Switch2_h;

  /* Chart: '<S162>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S162>/Constant'
   *  Delay: '<S162>/Delay'
   *  Logic: '<S162>/Logical Operator'
   *  Logic: '<S162>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch2_h, DHP_model_B.Switch2_bc,
    41U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_jo) && DHP_model_B.Switch2_h);

  /* DataStoreWrite: '<S163>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S163>/Data Type Conversion'
   */
  DTCStatusRAMTbl[41] = DHP_model_B.Fault_Valid_RT_ad.Switch9;

  /* Chart: '<S163>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S163>/Constant'
   *  Delay: '<S163>/Delay'
   *  Logic: '<S163>/Logical Operator'
   *  Logic: '<S163>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ad.Switch9,
    DHP_model_B.Fault_Valid_RT_ad.Switch2_m, 42U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ph) && DHP_model_B.Fault_Valid_RT_ad.Switch9);

  /* DataStoreWrite: '<S164>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S164>/Data Type Conversion'
   */
  DTCStatusRAMTbl[42] = DHP_model_B.Fault_Valid_RT_pi.Switch9;

  /* Chart: '<S164>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S164>/Constant'
   *  Delay: '<S164>/Delay'
   *  Logic: '<S164>/Logical Operator'
   *  Logic: '<S164>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_pi.Switch9,
    DHP_model_B.Fault_Valid_RT_pi.Switch2_m, 43U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_dx) && DHP_model_B.Fault_Valid_RT_pi.Switch9);

  /* DataStoreWrite: '<S165>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S165>/Data Type Conversion'
   */
  DTCStatusRAMTbl[43] = DHP_model_B.Fault_Valid_RT_pa.Switch9;

  /* Chart: '<S165>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S165>/Constant'
   *  Delay: '<S165>/Delay'
   *  Logic: '<S165>/Logical Operator'
   *  Logic: '<S165>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_pa.Switch9,
    DHP_model_B.Fault_Valid_RT_pa.Switch2_m, 44U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_pl0) && DHP_model_B.Fault_Valid_RT_pa.Switch9);

  /* DataStoreWrite: '<S166>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S166>/Data Type Conversion'
   */
  DTCStatusRAMTbl[44] = DHP_model_B.Fault_Valid_RT_iq.Switch9;

  /* Chart: '<S166>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S166>/Constant'
   *  Delay: '<S166>/Delay'
   *  Logic: '<S166>/Logical Operator'
   *  Logic: '<S166>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_iq.Switch9,
    DHP_model_B.Fault_Valid_RT_iq.Switch2_m, 45U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_clf) && DHP_model_B.Fault_Valid_RT_iq.Switch9);

  /* DataStoreWrite: '<S167>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S167>/Data Type Conversion'
   */
  DTCStatusRAMTbl[45] = DHP_model_B.Switch9_e;

  /* Chart: '<S167>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S167>/Constant'
   *  Delay: '<S167>/Delay'
   *  Logic: '<S167>/Logical Operator'
   *  Logic: '<S167>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch9_e, DHP_model_B.Switch2_ip,
    46U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_ia) && DHP_model_B.Switch9_e);

  /* DataStoreWrite: '<S168>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S168>/Data Type Conversion'
   */
  DTCStatusRAMTbl[46] = DHP_model_B.Fault_Valid_RT_k1s.Switch9;

  /* Chart: '<S168>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S168>/Constant'
   *  Delay: '<S168>/Delay'
   *  Logic: '<S168>/Logical Operator'
   *  Logic: '<S168>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_k1s.Switch9,
    DHP_model_B.Fault_Valid_RT_k1s.Switch2_m, 47U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_njc) && DHP_model_B.Fault_Valid_RT_k1s.Switch9);

  /* DataStoreWrite: '<S169>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S169>/Data Type Conversion'
   */
  DTCStatusRAMTbl[47] = DHP_model_B.Switch9_i;

  /* Chart: '<S169>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S169>/Constant'
   *  Delay: '<S169>/Delay'
   *  Logic: '<S169>/Logical Operator'
   *  Logic: '<S169>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch9_i, DHP_model_B.Switch2_fe,
    48U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_gkp) &&
    DHP_model_B.Switch9_i);

  /* DataStoreWrite: '<S170>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S170>/Data Type Conversion'
   */
  DTCStatusRAMTbl[48] = DHP_model_B.Fault_Valid_RT_bt.Switch9;

  /* Chart: '<S170>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S170>/Constant'
   *  Delay: '<S170>/Delay'
   *  Logic: '<S170>/Logical Operator'
   *  Logic: '<S170>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_bt.Switch9,
    DHP_model_B.Fault_Valid_RT_bt.Switch2_m, 49U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ah) && DHP_model_B.Fault_Valid_RT_bt.Switch9);

  /* DataStoreWrite: '<S171>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S171>/Data Type Conversion'
   */
  DTCStatusRAMTbl[4] = DHP_model_B.Fault_Valid_RT_j.Switch9;

  /* Chart: '<S171>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S171>/Constant'
   *  Delay: '<S171>/Delay'
   *  Logic: '<S171>/Logical Operator'
   *  Logic: '<S171>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_j.Switch9,
    DHP_model_B.Fault_Valid_RT_j.Switch2_m, 5U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_h5m) && DHP_model_B.Fault_Valid_RT_j.Switch9);

  /* DataStoreWrite: '<S172>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S172>/Data Type Conversion'
   */
  DTCStatusRAMTbl[49] = DHP_model_B.Switch9_ma;

  /* Chart: '<S172>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S172>/Constant'
   *  Delay: '<S172>/Delay'
   *  Logic: '<S172>/Logical Operator'
   *  Logic: '<S172>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch9_ma, DHP_model_B.Switch2_dh,
    50U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_op) &&
    DHP_model_B.Switch9_ma);

  /* DataStoreWrite: '<S173>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S173>/Data Type Conversion'
   */
  DTCStatusRAMTbl[50] = DHP_model_B.Fault_Valid_RT_py.Switch9;

  /* Chart: '<S173>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S173>/Constant'
   *  Delay: '<S173>/Delay'
   *  Logic: '<S173>/Logical Operator'
   *  Logic: '<S173>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_py.Switch9,
    DHP_model_B.Fault_Valid_RT_py.Switch2_m, 51U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_br) && DHP_model_B.Fault_Valid_RT_py.Switch9);

  /* DataStoreWrite: '<S174>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S174>/Data Type Conversion'
   */
  DTCStatusRAMTbl[51] = DHP_model_B.Fault_Valid_RT_mb.Switch9;

  /* Chart: '<S174>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S174>/Constant'
   *  Delay: '<S174>/Delay'
   *  Logic: '<S174>/Logical Operator'
   *  Logic: '<S174>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_mb.Switch9,
    DHP_model_B.Fault_Valid_RT_mb.Switch2_m, 52U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_oy) && DHP_model_B.Fault_Valid_RT_mb.Switch9);

  /* DataStoreWrite: '<S175>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S175>/Data Type Conversion'
   */
  DTCStatusRAMTbl[52] = DHP_model_B.Fault_Valid_RT_m5.Switch9;

  /* Chart: '<S175>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S175>/Constant'
   *  Delay: '<S175>/Delay'
   *  Logic: '<S175>/Logical Operator'
   *  Logic: '<S175>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_m5.Switch9,
    DHP_model_B.Fault_Valid_RT_m5.Switch2_m, 53U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_lu) && DHP_model_B.Fault_Valid_RT_m5.Switch9);

  /* DataStoreWrite: '<S176>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S176>/Data Type Conversion'
   */
  DTCStatusRAMTbl[53] = DHP_model_B.Fault_Valid_RT_bne.Switch9;

  /* Chart: '<S176>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S176>/Constant'
   *  Delay: '<S176>/Delay'
   *  Logic: '<S176>/Logical Operator'
   *  Logic: '<S176>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_bne.Switch9,
    DHP_model_B.Fault_Valid_RT_bne.Switch2_m, 54U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ps) && DHP_model_B.Fault_Valid_RT_bne.Switch9);

  /* DataStoreWrite: '<S177>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S177>/Data Type Conversion'
   */
  DTCStatusRAMTbl[54] = DHP_model_B.Switch9_fr;

  /* Chart: '<S177>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S177>/Constant'
   *  Delay: '<S177>/Delay'
   *  Logic: '<S177>/Logical Operator'
   *  Logic: '<S177>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch9_fr, DHP_model_B.Switch2_mf,
    55U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_ic) &&
    DHP_model_B.Switch9_fr);

  /* DataStoreWrite: '<S178>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S178>/Data Type Conversion'
   */
  DTCStatusRAMTbl[55] = DHP_model_B.Switch9_g;

  /* Chart: '<S178>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S178>/Constant'
   *  Delay: '<S178>/Delay'
   *  Logic: '<S178>/Logical Operator'
   *  Logic: '<S178>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch9_g, DHP_model_B.Switch2_i,
    56U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_cf) && DHP_model_B.Switch9_g);

  /* DataStoreWrite: '<S179>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S179>/Data Type Conversion'
   */
  DTCStatusRAMTbl[56] = DHP_model_B.Fault_Valid_RT_ag.Switch9;

  /* Chart: '<S179>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S179>/Constant'
   *  Delay: '<S179>/Delay'
   *  Logic: '<S179>/Logical Operator'
   *  Logic: '<S179>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ag.Switch9,
    DHP_model_B.Fault_Valid_RT_ag.Switch2_m, 57U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_cd) && DHP_model_B.Fault_Valid_RT_ag.Switch9);

  /* DataStoreWrite: '<S180>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S180>/Data Type Conversion'
   */
  DTCStatusRAMTbl[57] = DHP_model_B.Fault_Valid_RT_mr.Switch9;

  /* Chart: '<S180>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S180>/Constant'
   *  Delay: '<S180>/Delay'
   *  Logic: '<S180>/Logical Operator'
   *  Logic: '<S180>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_mr.Switch9,
    DHP_model_B.Fault_Valid_RT_mr.Switch2_m, 58U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_nm) && DHP_model_B.Fault_Valid_RT_mr.Switch9);

  /* DataStoreWrite: '<S181>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S181>/Data Type Conversion'
   */
  DTCStatusRAMTbl[58] = DHP_model_B.Fault_Valid_RT_kbz.Switch9;

  /* Chart: '<S181>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S181>/Constant'
   *  Delay: '<S181>/Delay'
   *  Logic: '<S181>/Logical Operator'
   *  Logic: '<S181>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_kbz.Switch9,
    DHP_model_B.Fault_Valid_RT_kbz.Switch2_m, 59U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_p1) && DHP_model_B.Fault_Valid_RT_kbz.Switch9);

  /* DataStoreWrite: '<S182>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S182>/Data Type Conversion'
   */
  DTCStatusRAMTbl[5] = DHP_model_B.Fault_Valid_RT_kt.Switch9;

  /* Chart: '<S182>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S182>/Constant'
   *  Delay: '<S182>/Delay'
   *  Logic: '<S182>/Logical Operator'
   *  Logic: '<S182>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_kt.Switch9,
    DHP_model_B.Fault_Valid_RT_kt.Switch2_m, 6U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_h3) && DHP_model_B.Fault_Valid_RT_kt.Switch9);

  /* DataStoreWrite: '<S183>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S183>/Data Type Conversion'
   */
  DTCStatusRAMTbl[59] = DHP_model_B.Fault_Valid_RT_ewi.Switch9;

  /* Chart: '<S183>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S183>/Constant'
   *  Delay: '<S183>/Delay'
   *  Logic: '<S183>/Logical Operator'
   *  Logic: '<S183>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ewi.Switch9,
    DHP_model_B.Fault_Valid_RT_ewi.Switch2_m, 60U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_lo) && DHP_model_B.Fault_Valid_RT_ewi.Switch9);

  /* DataStoreWrite: '<S184>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S184>/Data Type Conversion'
   */
  DTCStatusRAMTbl[60] = DHP_model_B.Switch9_f;

  /* Chart: '<S184>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S184>/Constant'
   *  Delay: '<S184>/Delay'
   *  Logic: '<S184>/Logical Operator'
   *  Logic: '<S184>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch9_f, DHP_model_B.Switch2_bh,
    61U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_eek) &&
    DHP_model_B.Switch9_f);

  /* DataStoreWrite: '<S185>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S185>/Data Type Conversion'
   */
  DTCStatusRAMTbl[61] = DHP_model_B.Fault_Valid_RT_l4.Switch9;

  /* Chart: '<S185>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S185>/Constant'
   *  Delay: '<S185>/Delay'
   *  Logic: '<S185>/Logical Operator'
   *  Logic: '<S185>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_l4.Switch9,
    DHP_model_B.Fault_Valid_RT_l4.Switch2_m, 62U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_bnk) && DHP_model_B.Fault_Valid_RT_l4.Switch9);

  /* DataStoreWrite: '<S186>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S186>/Data Type Conversion'
   */
  DTCStatusRAMTbl[62] = DHP_model_B.Fault_Valid_RT_if.Switch9;

  /* Chart: '<S186>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S186>/Constant'
   *  Delay: '<S186>/Delay'
   *  Logic: '<S186>/Logical Operator'
   *  Logic: '<S186>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_if.Switch9,
    DHP_model_B.Fault_Valid_RT_if.Switch2_m, 63U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ls) && DHP_model_B.Fault_Valid_RT_if.Switch9);

  /* DataStoreWrite: '<S187>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S187>/Data Type Conversion'
   */
  DTCStatusRAMTbl[63] = DHP_model_B.Fault_Valid_Time_im.Fault_Affirm.Switch2;

  /* Chart: '<S187>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S187>/Constant'
   *  Delay: '<S187>/Delay'
   *  Logic: '<S187>/Logical Operator'
   *  Logic: '<S187>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_im.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_im.Switch2_i, 64U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_gv) &&
     DHP_model_B.Fault_Valid_Time_im.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S188>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S188>/Data Type Conversion'
   */
  DTCStatusRAMTbl[64] = DHP_model_B.Fault_Valid_Time_k5.Fault_Affirm.Switch2;

  /* Chart: '<S188>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S188>/Constant'
   *  Delay: '<S188>/Delay'
   *  Logic: '<S188>/Logical Operator'
   *  Logic: '<S188>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_k5.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_k5.Switch2_i, 65U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_iv) &&
     DHP_model_B.Fault_Valid_Time_k5.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S189>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S189>/Data Type Conversion'
   */
  DTCStatusRAMTbl[65] = DHP_model_B.Fault_Valid_Time_kh.Fault_Affirm.Switch2;

  /* Chart: '<S189>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S189>/Constant'
   *  Delay: '<S189>/Delay'
   *  Logic: '<S189>/Logical Operator'
   *  Logic: '<S189>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_kh.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_kh.Switch2_i, 66U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_hz) &&
     DHP_model_B.Fault_Valid_Time_kh.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S190>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S190>/Data Type Conversion'
   */
  DTCStatusRAMTbl[66] = DHP_model_B.Fault_Valid_Time_pv.Fault_Affirm.Switch2;

  /* Chart: '<S190>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S190>/Constant'
   *  Delay: '<S190>/Delay'
   *  Logic: '<S190>/Logical Operator'
   *  Logic: '<S190>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_pv.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_pv.Switch2_i, 67U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_gu) &&
     DHP_model_B.Fault_Valid_Time_pv.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S191>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S191>/Data Type Conversion'
   */
  DTCStatusRAMTbl[67] = DHP_model_B.Fault_Valid_Time_nj.Fault_Affirm.Switch2;

  /* Chart: '<S191>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S191>/Constant'
   *  Delay: '<S191>/Delay'
   *  Logic: '<S191>/Logical Operator'
   *  Logic: '<S191>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_nj.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_nj.Switch2_i, 68U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_iw) &&
     DHP_model_B.Fault_Valid_Time_nj.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S192>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S192>/Data Type Conversion'
   */
  DTCStatusRAMTbl[68] = DHP_model_B.Fault_Valid_Time_jc.Fault_Affirm.Switch2;

  /* Chart: '<S192>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S192>/Constant'
   *  Delay: '<S192>/Delay'
   *  Logic: '<S192>/Logical Operator'
   *  Logic: '<S192>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_jc.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_jc.Switch2_i, 69U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_jy) &&
     DHP_model_B.Fault_Valid_Time_jc.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S193>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S193>/Data Type Conversion'
   */
  DTCStatusRAMTbl[6] = DHP_model_B.Fault_Valid_RT_og.Switch9;

  /* Chart: '<S193>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S193>/Constant'
   *  Delay: '<S193>/Delay'
   *  Logic: '<S193>/Logical Operator'
   *  Logic: '<S193>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_og.Switch9,
    DHP_model_B.Fault_Valid_RT_og.Switch2_m, 7U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_a5e) && DHP_model_B.Fault_Valid_RT_og.Switch9);

  /* DataStoreWrite: '<S194>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S194>/Data Type Conversion'
   */
  DTCStatusRAMTbl[69] = DHP_model_B.Fault_Valid_Time_j4.Fault_Affirm.Switch2;

  /* Chart: '<S194>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S194>/Constant'
   *  Delay: '<S194>/Delay'
   *  Logic: '<S194>/Logical Operator'
   *  Logic: '<S194>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_j4.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_j4.Switch2_i, 70U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_ku) &&
     DHP_model_B.Fault_Valid_Time_j4.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S195>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S195>/Data Type Conversion'
   */
  DTCStatusRAMTbl[70] = DHP_model_B.LogicalOperator1_e;

  /* Chart: '<S195>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S195>/Constant'
   *  Delay: '<S195>/Delay'
   *  Logic: '<S195>/Logical Operator'
   *  Logic: '<S195>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.LogicalOperator1_e,
    DHP_model_B.Switch2_a, 71U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_ch) &&
    DHP_model_B.LogicalOperator1_e);

  /* DataStoreWrite: '<S196>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S196>/Data Type Conversion'
   */
  DTCStatusRAMTbl[71] = DHP_model_B.LogicalOperator1_k;

  /* Chart: '<S196>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S196>/Constant'
   *  Delay: '<S196>/Delay'
   *  Logic: '<S196>/Logical Operator'
   *  Logic: '<S196>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.LogicalOperator1_k,
    DHP_model_B.Switch2_d5d, 72U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_fao)
    && DHP_model_B.LogicalOperator1_k);

  /* DataStoreWrite: '<S197>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S197>/Data Type Conversion'
   */
  DTCStatusRAMTbl[72] = DHP_model_B.LogicalOperator1_h;

  /* Chart: '<S197>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S197>/Constant'
   *  Delay: '<S197>/Delay'
   *  Logic: '<S197>/Logical Operator'
   *  Logic: '<S197>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.LogicalOperator1_h,
    DHP_model_B.Switch2_bp, 73U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_bs) &&
    DHP_model_B.LogicalOperator1_h);

  /* DataStoreWrite: '<S198>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S198>/Data Type Conversion'
   */
  DTCStatusRAMTbl[73] = DHP_model_B.Fault_Valid_Time_as.Fault_Affirm.Switch2;

  /* Chart: '<S198>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S198>/Constant'
   *  Delay: '<S198>/Delay'
   *  Logic: '<S198>/Logical Operator'
   *  Logic: '<S198>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_as.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_as.Switch2_i, 74U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_ll) &&
     DHP_model_B.Fault_Valid_Time_as.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S199>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S199>/Data Type Conversion'
   */
  DTCStatusRAMTbl[74] = DHP_model_B.Fault_Valid_Time_iy.Fault_Affirm.Switch2;

  /* Chart: '<S199>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S199>/Constant'
   *  Delay: '<S199>/Delay'
   *  Logic: '<S199>/Logical Operator'
   *  Logic: '<S199>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_iy.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_iy.Switch2_i, 75U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_ph3) &&
     DHP_model_B.Fault_Valid_Time_iy.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S200>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S200>/Data Type Conversion'
   */
  DTCStatusRAMTbl[75] = DHP_model_B.Fault_Valid_Time_gy.Fault_Affirm.Switch2;

  /* Chart: '<S200>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S200>/Constant'
   *  Delay: '<S200>/Delay'
   *  Logic: '<S200>/Logical Operator'
   *  Logic: '<S200>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_gy.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_gy.Switch2_i, 76U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_nc) &&
     DHP_model_B.Fault_Valid_Time_gy.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S201>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S201>/Data Type Conversion'
   */
  DTCStatusRAMTbl[76] = DHP_model_B.Fault_Valid_Time_fa.Fault_Affirm.Switch2;

  /* Chart: '<S201>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S201>/Constant'
   *  Delay: '<S201>/Delay'
   *  Logic: '<S201>/Logical Operator'
   *  Logic: '<S201>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_fa.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_fa.Switch2_i, 77U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_et) &&
     DHP_model_B.Fault_Valid_Time_fa.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S202>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S202>/Data Type Conversion'
   */
  DTCStatusRAMTbl[77] = DHP_model_B.Fault_Valid_Time_cb.Fault_Affirm.Switch2;

  /* Chart: '<S202>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S202>/Constant'
   *  Delay: '<S202>/Delay'
   *  Logic: '<S202>/Logical Operator'
   *  Logic: '<S202>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_cb.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_cb.Switch2_i, 78U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_p3i) &&
     DHP_model_B.Fault_Valid_Time_cb.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S203>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S203>/Data Type Conversion'
   */
  DTCStatusRAMTbl[78] = DHP_model_B.Fault_Valid_RT_b3.Switch9;

  /* Chart: '<S203>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S203>/Constant'
   *  Delay: '<S203>/Delay'
   *  Logic: '<S203>/Logical Operator'
   *  Logic: '<S203>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_b3.Switch9,
    DHP_model_B.Fault_Valid_RT_b3.Switch2_m, 79U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_da1) && DHP_model_B.Fault_Valid_RT_b3.Switch9);

  /* DataStoreWrite: '<S204>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S204>/Data Type Conversion'
   */
  DTCStatusRAMTbl[7] = DHP_model_B.Fault_Valid_RT_i.Switch9;

  /* Chart: '<S204>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S204>/Constant'
   *  Delay: '<S204>/Delay'
   *  Logic: '<S204>/Logical Operator'
   *  Logic: '<S204>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_i.Switch9,
    DHP_model_B.Fault_Valid_RT_i.Switch2_m, 8U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_fmn) && DHP_model_B.Fault_Valid_RT_i.Switch9);

  /* DataStoreWrite: '<S205>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S205>/Data Type Conversion'
   */
  DTCStatusRAMTbl[79] = DHP_model_B.Fault_Valid_RT_mp.Switch9;

  /* Chart: '<S205>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S205>/Constant'
   *  Delay: '<S205>/Delay'
   *  Logic: '<S205>/Logical Operator'
   *  Logic: '<S205>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_mp.Switch9,
    DHP_model_B.Fault_Valid_RT_mp.Switch2_m, 80U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ahx) && DHP_model_B.Fault_Valid_RT_mp.Switch9);

  /* DataStoreWrite: '<S206>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S206>/Data Type Conversion'
   */
  DTCStatusRAMTbl[80] = DHP_model_B.Fault_Valid_RT_bzj.Switch9;

  /* Chart: '<S206>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S206>/Constant'
   *  Delay: '<S206>/Delay'
   *  Logic: '<S206>/Logical Operator'
   *  Logic: '<S206>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_bzj.Switch9,
    DHP_model_B.Fault_Valid_RT_bzj.Switch2_m, 81U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_cl5) && DHP_model_B.Fault_Valid_RT_bzj.Switch9);

  /* DataStoreWrite: '<S207>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S207>/Data Type Conversion'
   */
  DTCStatusRAMTbl[81] = DHP_model_B.Fault_Valid_RT_j1b.Switch9;

  /* Chart: '<S207>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S207>/Constant'
   *  Delay: '<S207>/Delay'
   *  Logic: '<S207>/Logical Operator'
   *  Logic: '<S207>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_j1b.Switch9,
    DHP_model_B.Fault_Valid_RT_j1b.Switch2_m, 82U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_ky) && DHP_model_B.Fault_Valid_RT_j1b.Switch9);

  /* DataStoreWrite: '<S208>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S208>/Data Type Conversion'
   */
  DTCStatusRAMTbl[82] = DHP_model_B.Fault_Valid_RT_hb.Switch9;

  /* Chart: '<S208>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S208>/Constant'
   *  Delay: '<S208>/Delay'
   *  Logic: '<S208>/Logical Operator'
   *  Logic: '<S208>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_hb.Switch9,
    DHP_model_B.Fault_Valid_RT_hb.Switch2_m, 83U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_mi) && DHP_model_B.Fault_Valid_RT_hb.Switch9);

  /* DataStoreWrite: '<S209>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S209>/Data Type Conversion'
   */
  DTCStatusRAMTbl[83] = DHP_model_B.Fault_Valid_Time_lp.Fault_Affirm.Switch2;

  /* Chart: '<S209>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S209>/Constant'
   *  Delay: '<S209>/Delay'
   *  Logic: '<S209>/Logical Operator'
   *  Logic: '<S209>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_lp.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_lp.Switch2_i, 84U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_iwx) &&
     DHP_model_B.Fault_Valid_Time_lp.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S210>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S210>/Data Type Conversion'
   */
  DTCStatusRAMTbl[84] = DHP_model_B.Fault_Valid_Time_m.Fault_Affirm.Switch2;

  /* Chart: '<S210>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S210>/Constant'
   *  Delay: '<S210>/Delay'
   *  Logic: '<S210>/Logical Operator'
   *  Logic: '<S210>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_m.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_m.Switch2_i, 85U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_hvo) &&
     DHP_model_B.Fault_Valid_Time_m.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S211>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S211>/Data Type Conversion'
   */
  DTCStatusRAMTbl[85] = DHP_model_B.Fault_Valid_Time_g.Fault_Affirm.Switch2;

  /* Chart: '<S211>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S211>/Constant'
   *  Delay: '<S211>/Delay'
   *  Logic: '<S211>/Logical Operator'
   *  Logic: '<S211>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_g.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_g.Switch2_i, 86U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_kpb) &&
     DHP_model_B.Fault_Valid_Time_g.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S212>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S212>/Data Type Conversion'
   */
  DTCStatusRAMTbl[86] = DHP_model_B.Fault_Valid_Time_jy.Fault_Affirm.Switch2;

  /* Chart: '<S212>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S212>/Constant'
   *  Delay: '<S212>/Delay'
   *  Logic: '<S212>/Logical Operator'
   *  Logic: '<S212>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_jy.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_jy.Switch2_i, 87U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_hi) &&
     DHP_model_B.Fault_Valid_Time_jy.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S213>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S213>/Data Type Conversion'
   */
  DTCStatusRAMTbl[87] = DHP_model_B.Fault_Valid_Time_eo.Fault_Affirm.Switch2;

  /* Chart: '<S213>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S213>/Constant'
   *  Delay: '<S213>/Delay'
   *  Logic: '<S213>/Logical Operator'
   *  Logic: '<S213>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_eo.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_eo.Switch2_i, 88U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_ex) &&
     DHP_model_B.Fault_Valid_Time_eo.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S214>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S214>/Data Type Conversion'
   */
  DTCStatusRAMTbl[88] = DHP_model_B.Fault_Valid_Time_n1v.Fault_Affirm.Switch2;

  /* Chart: '<S214>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S214>/Constant'
   *  Delay: '<S214>/Delay'
   *  Logic: '<S214>/Logical Operator'
   *  Logic: '<S214>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_n1v.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_n1v.Switch2_i, 89U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_koq) &&
     DHP_model_B.Fault_Valid_Time_n1v.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S215>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S215>/Data Type Conversion'
   */
  DTCStatusRAMTbl[8] = DHP_model_B.Fault_Valid_RT_e.Switch9;

  /* Chart: '<S215>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S215>/Constant'
   *  Delay: '<S215>/Delay'
   *  Logic: '<S215>/Logical Operator'
   *  Logic: '<S215>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_e.Switch9,
    DHP_model_B.Fault_Valid_RT_e.Switch2_m, 9U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_d5z) && DHP_model_B.Fault_Valid_RT_e.Switch9);

  /* DataStoreWrite: '<S216>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S216>/Data Type Conversion'
   */
  DTCStatusRAMTbl[89] = DHP_model_B.Fault_Valid_Time_oe.Fault_Affirm.Switch2;

  /* Chart: '<S216>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S216>/Constant'
   *  Delay: '<S216>/Delay'
   *  Logic: '<S216>/Logical Operator'
   *  Logic: '<S216>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_oe.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_oe.Switch2_i, 90U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_p3r) &&
     DHP_model_B.Fault_Valid_Time_oe.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S217>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S217>/Data Type Conversion'
   */
  DTCStatusRAMTbl[90] = DHP_model_B.Fault_Valid_Time_jj.Fault_Affirm.Switch2;

  /* Chart: '<S217>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S217>/Constant'
   *  Delay: '<S217>/Delay'
   *  Logic: '<S217>/Logical Operator'
   *  Logic: '<S217>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_jj.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_jj.Switch2_i, 91U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_cc) &&
     DHP_model_B.Fault_Valid_Time_jj.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S218>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S218>/Data Type Conversion'
   */
  DTCStatusRAMTbl[91] = DHP_model_B.Fault_Valid_Time_ds.Fault_Affirm.Switch2;

  /* Chart: '<S218>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S218>/Constant'
   *  Delay: '<S218>/Delay'
   *  Logic: '<S218>/Logical Operator'
   *  Logic: '<S218>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_ds.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_ds.Switch2_i, 92U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_lk) &&
     DHP_model_B.Fault_Valid_Time_ds.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S219>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S219>/Data Type Conversion'
   */
  DTCStatusRAMTbl[92] = DHP_model_B.Fault_Valid_Time_e.Fault_Affirm.Switch2;

  /* Chart: '<S219>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S219>/Constant'
   *  Delay: '<S219>/Delay'
   *  Logic: '<S219>/Logical Operator'
   *  Logic: '<S219>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_e.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_e.Switch2_i, 93U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_ao) &&
     DHP_model_B.Fault_Valid_Time_e.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S220>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S220>/Data Type Conversion'
   */
  DTCStatusRAMTbl[93] = DHP_model_B.Fault_Valid_Time_a.Fault_Affirm.Switch2;

  /* Chart: '<S220>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S220>/Constant'
   *  Delay: '<S220>/Delay'
   *  Logic: '<S220>/Logical Operator'
   *  Logic: '<S220>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart
    (DHP_model_B.Fault_Valid_Time_a.Fault_Affirm.Switch2,
     DHP_model_B.Fault_Valid_Time_a.Switch2_i, 94U, rtb_SnapShots,
     (!DHP_model_DW.Delay_DSTATE_j0) &&
     DHP_model_B.Fault_Valid_Time_a.Fault_Affirm.Switch2);

  /* DataStoreWrite: '<S221>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S221>/Data Type Conversion'
   */
  DTCStatusRAMTbl[94] = DHP_model_B.Fault_Valid_RT.Switch9;

  /* Chart: '<S221>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S221>/Constant'
   *  Delay: '<S221>/Delay'
   *  Logic: '<S221>/Logical Operator'
   *  Logic: '<S221>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT.Switch9,
    DHP_model_B.Fault_Valid_RT.Switch2_m, 95U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_av) && DHP_model_B.Fault_Valid_RT.Switch9);

  /* DataStoreWrite: '<S222>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S222>/Data Type Conversion'
   */
  DTCStatusRAMTbl[95] = DHP_model_B.Fault_Valid_RT_hm.Switch9;

  /* Chart: '<S222>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S222>/Constant'
   *  Delay: '<S222>/Delay'
   *  Logic: '<S222>/Logical Operator'
   *  Logic: '<S222>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_hm.Switch9,
    DHP_model_B.Fault_Valid_RT_hm.Switch2_m, 96U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_nf) && DHP_model_B.Fault_Valid_RT_hm.Switch9);

  /* DataStoreWrite: '<S223>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S223>/Data Type Conversion'
   */
  DTCStatusRAMTbl[96] = DHP_model_B.Switch2_bz;

  /* Chart: '<S223>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S223>/Constant'
   *  Delay: '<S223>/Delay'
   *  Logic: '<S223>/Logical Operator'
   *  Logic: '<S223>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch2_bz, DHP_model_B.Switch2_p3,
    97U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_oc) &&
    DHP_model_B.Switch2_bz);

  /* DataStoreWrite: '<S224>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S224>/Data Type Conversion'
   */
  DTCStatusRAMTbl[97] = DHP_model_B.Fault_Valid_RT_ez.Switch9;

  /* Chart: '<S224>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S224>/Constant'
   *  Delay: '<S224>/Delay'
   *  Logic: '<S224>/Logical Operator'
   *  Logic: '<S224>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ez.Switch9,
    DHP_model_B.Fault_Valid_RT_ez.Switch2_m, 98U, rtb_SnapShots,
    (!DHP_model_DW.Delay_DSTATE_koj) && DHP_model_B.Fault_Valid_RT_ez.Switch9);

  /* DataStoreWrite: '<S225>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S225>/Data Type Conversion'
   */
  DTCStatusRAMTbl[98] = DHP_model_B.Switch3_kd;

  /* Chart: '<S225>/DHP_FaultStore_Chart' incorporates:
   *  Constant: '<S225>/Constant'
   *  Delay: '<S225>/Delay'
   *  Logic: '<S225>/Logical Operator'
   *  Logic: '<S225>/Logical Operator1'
   */
  DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch3_kd, DHP_model_B.Switch2_gz,
    99U, rtb_SnapShots, (!DHP_model_DW.Delay_DSTATE_ca) &&
    DHP_model_B.Switch3_kd);

  /* Outputs for Enabled SubSystem: '<S7>/Subsystem_VCU2HW' incorporates:
   *  EnablePort: '<S226>/Enable'
   */
  if (rtb_RelationalOperator) {
    /* DataStoreWrite: '<S402>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S402>/Data Type Conversion'
     */
    DTCStatusRAMTbl[167] = DHP_model_B.Fault_Valid_RT_et.Switch9;

    /* Chart: '<S402>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S402>/Constant'
     *  Delay: '<S402>/Delay'
     *  Logic: '<S402>/Logical Operator'
     *  Logic: '<S402>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_et.Switch9,
      DHP_model_B.Fault_Valid_RT_et.Switch2_m, 168U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_hm) && DHP_model_B.Fault_Valid_RT_et.Switch9);

    /* DataStoreWrite: '<S403>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S403>/Data Type Conversion'
     */
    DTCStatusRAMTbl[168] = DHP_model_B.Fault_Valid_RT_cw.Switch9;

    /* Chart: '<S403>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S403>/Constant'
     *  Delay: '<S403>/Delay'
     *  Logic: '<S403>/Logical Operator'
     *  Logic: '<S403>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_cw.Switch9,
      DHP_model_B.Fault_Valid_RT_cw.Switch2_m, 169U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_ow) && DHP_model_B.Fault_Valid_RT_cw.Switch9);

    /* DataStoreWrite: '<S404>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S404>/Data Type Conversion'
     */
    DTCStatusRAMTbl[169] = DHP_model_B.Fault_Valid_Time_nv.Fault_Affirm.Switch2;

    /* Chart: '<S404>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S404>/Constant'
     *  Delay: '<S404>/Delay'
     *  Logic: '<S404>/Logical Operator'
     *  Logic: '<S404>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart
      (DHP_model_B.Fault_Valid_Time_nv.Fault_Affirm.Switch2,
       DHP_model_B.Fault_Valid_Time_nv.Switch2_i, 170U, rtb_SnapShots,
       (!DHP_model_DW.Delay_DSTATE_k141) &&
       DHP_model_B.Fault_Valid_Time_nv.Fault_Affirm.Switch2);

    /* DataStoreWrite: '<S405>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S405>/Data Type Conversion'
     */
    DTCStatusRAMTbl[170] = DHP_model_B.Fault_Valid_Time_f.Fault_Affirm.Switch2;

    /* Chart: '<S405>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S405>/Constant'
     *  Delay: '<S405>/Delay'
     *  Logic: '<S405>/Logical Operator'
     *  Logic: '<S405>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart
      (DHP_model_B.Fault_Valid_Time_f.Fault_Affirm.Switch2,
       DHP_model_B.Fault_Valid_Time_f.Switch2_i, 171U, rtb_SnapShots,
       (!DHP_model_DW.Delay_DSTATE_az) &&
       DHP_model_B.Fault_Valid_Time_f.Fault_Affirm.Switch2);

    /* DataStoreWrite: '<S406>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S406>/Data Type Conversion'
     */
    DTCStatusRAMTbl[171] = DHP_model_B.Fault_Valid_RT_k.Switch9;

    /* Chart: '<S406>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S406>/Constant'
     *  Delay: '<S406>/Delay'
     *  Logic: '<S406>/Logical Operator'
     *  Logic: '<S406>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_k.Switch9,
      DHP_model_B.Fault_Valid_RT_k.Switch2_m, 172U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_ds) && DHP_model_B.Fault_Valid_RT_k.Switch9);

    /* DataStoreWrite: '<S407>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S407>/Data Type Conversion'
     */
    DTCStatusRAMTbl[172] = DHP_model_B.Fault_Valid_RT_b.Switch9;

    /* Chart: '<S407>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S407>/Constant'
     *  Delay: '<S407>/Delay'
     *  Logic: '<S407>/Logical Operator'
     *  Logic: '<S407>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_b.Switch9,
      DHP_model_B.Fault_Valid_RT_b.Switch2_m, 173U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_o0) && DHP_model_B.Fault_Valid_RT_b.Switch9);

    /* DataStoreWrite: '<S408>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S408>/Data Type Conversion'
     */
    DTCStatusRAMTbl[173] = DHP_model_B.Fault_Valid_RT_c.Switch9;

    /* Chart: '<S408>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S408>/Constant'
     *  Delay: '<S408>/Delay'
     *  Logic: '<S408>/Logical Operator'
     *  Logic: '<S408>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_c.Switch9,
      DHP_model_B.Fault_Valid_RT_c.Switch2_m, 174U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_crf) && DHP_model_B.Fault_Valid_RT_c.Switch9);

    /* DataStoreWrite: '<S409>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S409>/Data Type Conversion'
     */
    DTCStatusRAMTbl[174] = DHP_model_B.Fault_Valid_Time_l.Fault_Affirm.Switch2;

    /* Chart: '<S409>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S409>/Constant'
     *  Delay: '<S409>/Delay'
     *  Logic: '<S409>/Logical Operator'
     *  Logic: '<S409>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart
      (DHP_model_B.Fault_Valid_Time_l.Fault_Affirm.Switch2,
       DHP_model_B.Fault_Valid_Time_l.Switch2_i, 175U, rtb_SnapShots,
       (!DHP_model_DW.Delay_DSTATE_kn) &&
       DHP_model_B.Fault_Valid_Time_l.Fault_Affirm.Switch2);

    /* DataStoreWrite: '<S410>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S410>/Data Type Conversion'
     */
    DTCStatusRAMTbl[175] = DHP_model_B.Fault_Valid_RT_cu.Switch9;

    /* Chart: '<S410>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S410>/Constant'
     *  Delay: '<S410>/Delay'
     *  Logic: '<S410>/Logical Operator'
     *  Logic: '<S410>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_cu.Switch9,
      DHP_model_B.Fault_Valid_RT_cu.Switch2_m, 176U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_gb) && DHP_model_B.Fault_Valid_RT_cu.Switch9);

    /* DataStoreWrite: '<S411>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S411>/Data Type Conversion'
     */
    DTCStatusRAMTbl[176] = DHP_model_B.Fault_Valid_RT_lt.Switch9;

    /* Chart: '<S411>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S411>/Constant'
     *  Delay: '<S411>/Delay'
     *  Logic: '<S411>/Logical Operator'
     *  Logic: '<S411>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_lt.Switch9,
      DHP_model_B.Fault_Valid_RT_lt.Switch2_m, 177U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_i5d) && DHP_model_B.Fault_Valid_RT_lt.Switch9);

    /* DataStoreWrite: '<S412>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S412>/Data Type Conversion'
     */
    DTCStatusRAMTbl[177] = DHP_model_B.Fault_Valid_RT_jk.Switch9;

    /* Chart: '<S412>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S412>/Constant'
     *  Delay: '<S412>/Delay'
     *  Logic: '<S412>/Logical Operator'
     *  Logic: '<S412>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_jk.Switch9,
      DHP_model_B.Fault_Valid_RT_jk.Switch2_m, 178U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_hw) && DHP_model_B.Fault_Valid_RT_jk.Switch9);

    /* DataStoreWrite: '<S413>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S413>/Data Type Conversion'
     */
    DTCStatusRAMTbl[178] = DHP_model_B.Fault_Valid_RT_oy.Switch9;

    /* Chart: '<S413>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S413>/Constant'
     *  Delay: '<S413>/Delay'
     *  Logic: '<S413>/Logical Operator'
     *  Logic: '<S413>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_oy.Switch9,
      DHP_model_B.Fault_Valid_RT_oy.Switch2_m, 179U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_mw) && DHP_model_B.Fault_Valid_RT_oy.Switch9);

    /* DataStoreWrite: '<S414>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S414>/Data Type Conversion'
     */
    DTCStatusRAMTbl[179] = DHP_model_B.Fault_Valid_RT_g1.Switch9;

    /* Chart: '<S414>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S414>/Constant'
     *  Delay: '<S414>/Delay'
     *  Logic: '<S414>/Logical Operator'
     *  Logic: '<S414>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_g1.Switch9,
      DHP_model_B.Fault_Valid_RT_g1.Switch2_m, 180U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_e2) && DHP_model_B.Fault_Valid_RT_g1.Switch9);

    /* DataStoreWrite: '<S415>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S415>/Data Type Conversion'
     */
    DTCStatusRAMTbl[180] = DHP_model_B.Fault_Valid_RT_fm.Switch9;

    /* Chart: '<S415>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S415>/Constant'
     *  Delay: '<S415>/Delay'
     *  Logic: '<S415>/Logical Operator'
     *  Logic: '<S415>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_fm.Switch9,
      DHP_model_B.Fault_Valid_RT_fm.Switch2_m, 181U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_brq) && DHP_model_B.Fault_Valid_RT_fm.Switch9);

    /* DataStoreWrite: '<S416>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S416>/Data Type Conversion'
     */
    DTCStatusRAMTbl[181] = DHP_model_B.Fault_Valid_RT_ii.Switch9;

    /* Chart: '<S416>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S416>/Constant'
     *  Delay: '<S416>/Delay'
     *  Logic: '<S416>/Logical Operator'
     *  Logic: '<S416>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ii.Switch9,
      DHP_model_B.Fault_Valid_RT_ii.Switch2_m, 182U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_eeg) && DHP_model_B.Fault_Valid_RT_ii.Switch9);

    /* DataStoreWrite: '<S417>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S417>/Data Type Conversion'
     */
    DTCStatusRAMTbl[182] = DHP_model_B.Fault_Valid_RT_e1.Switch9;

    /* Chart: '<S417>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S417>/Constant'
     *  Delay: '<S417>/Delay'
     *  Logic: '<S417>/Logical Operator'
     *  Logic: '<S417>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_e1.Switch9,
      DHP_model_B.Fault_Valid_RT_e1.Switch2_m, 183U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_jki) && DHP_model_B.Fault_Valid_RT_e1.Switch9);

    /* DataStoreWrite: '<S418>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S418>/Data Type Conversion'
     */
    DTCStatusRAMTbl[183] = DHP_model_B.Fault_Valid_RT_etn.Switch9;

    /* Chart: '<S418>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S418>/Constant'
     *  Delay: '<S418>/Delay'
     *  Logic: '<S418>/Logical Operator'
     *  Logic: '<S418>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_etn.Switch9,
      DHP_model_B.Fault_Valid_RT_etn.Switch2_m, 184U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_ai) && DHP_model_B.Fault_Valid_RT_etn.Switch9);

    /* DataStoreWrite: '<S419>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S419>/Data Type Conversion'
     */
    DTCStatusRAMTbl[184] = DHP_model_B.Fault_Valid_RT_hg.Switch9;

    /* Chart: '<S419>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S419>/Constant'
     *  Delay: '<S419>/Delay'
     *  Logic: '<S419>/Logical Operator'
     *  Logic: '<S419>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_hg.Switch9,
      DHP_model_B.Fault_Valid_RT_hg.Switch2_m, 185U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_kv) && DHP_model_B.Fault_Valid_RT_hg.Switch9);

    /* DataStoreWrite: '<S420>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S420>/Data Type Conversion'
     */
    DTCStatusRAMTbl[185] = DHP_model_B.Fault_Valid_RT_iw.Switch9;

    /* Chart: '<S420>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S420>/Constant'
     *  Delay: '<S420>/Delay'
     *  Logic: '<S420>/Logical Operator'
     *  Logic: '<S420>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_iw.Switch9,
      DHP_model_B.Fault_Valid_RT_iw.Switch2_m, 186U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_ohq) && DHP_model_B.Fault_Valid_RT_iw.Switch9);

    /* DataStoreWrite: '<S421>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S421>/Data Type Conversion'
     */
    DTCStatusRAMTbl[186] = DHP_model_B.Fault_Valid_RT_c2.Switch9;

    /* Chart: '<S421>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S421>/Constant'
     *  Delay: '<S421>/Delay'
     *  Logic: '<S421>/Logical Operator'
     *  Logic: '<S421>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_c2.Switch9,
      DHP_model_B.Fault_Valid_RT_c2.Switch2_m, 187U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_fq) && DHP_model_B.Fault_Valid_RT_c2.Switch9);

    /* DataStoreWrite: '<S422>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S422>/Data Type Conversion'
     */
    DTCStatusRAMTbl[187] = DHP_model_B.Fault_Valid_RT_e2.Switch9;

    /* Chart: '<S422>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S422>/Constant'
     *  Delay: '<S422>/Delay'
     *  Logic: '<S422>/Logical Operator'
     *  Logic: '<S422>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_e2.Switch9,
      DHP_model_B.Fault_Valid_RT_e2.Switch2_m, 188U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_nz) && DHP_model_B.Fault_Valid_RT_e2.Switch9);

    /* DataStoreWrite: '<S423>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S423>/Data Type Conversion'
     */
    DTCStatusRAMTbl[188] = DHP_model_B.Fault_Valid_RT_ax.Switch9;

    /* Chart: '<S423>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S423>/Constant'
     *  Delay: '<S423>/Delay'
     *  Logic: '<S423>/Logical Operator'
     *  Logic: '<S423>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ax.Switch9,
      DHP_model_B.Fault_Valid_RT_ax.Switch2_m, 189U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_dy) && DHP_model_B.Fault_Valid_RT_ax.Switch9);

    /* DataStoreWrite: '<S424>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S424>/Data Type Conversion'
     */
    DTCStatusRAMTbl[189] = DHP_model_B.Fault_Valid_RT_ik.Switch9;

    /* Chart: '<S424>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S424>/Constant'
     *  Delay: '<S424>/Delay'
     *  Logic: '<S424>/Logical Operator'
     *  Logic: '<S424>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_ik.Switch9,
      DHP_model_B.Fault_Valid_RT_ik.Switch2_m, 190U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_af) && DHP_model_B.Fault_Valid_RT_ik.Switch9);

    /* DataStoreWrite: '<S425>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S425>/Data Type Conversion'
     */
    DTCStatusRAMTbl[190] = DHP_model_B.Fault_Valid_RT_j1y.Switch9;

    /* Chart: '<S425>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S425>/Constant'
     *  Delay: '<S425>/Delay'
     *  Logic: '<S425>/Logical Operator'
     *  Logic: '<S425>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_j1y.Switch9,
      DHP_model_B.Fault_Valid_RT_j1y.Switch2_m, 191U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_iir) && DHP_model_B.Fault_Valid_RT_j1y.Switch9);

    /* DataStoreWrite: '<S426>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S426>/Data Type Conversion'
     */
    DTCStatusRAMTbl[191] = DHP_model_B.Fault_Valid_RT_j0.Switch9;

    /* Chart: '<S426>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S426>/Constant'
     *  Delay: '<S426>/Delay'
     *  Logic: '<S426>/Logical Operator'
     *  Logic: '<S426>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_j0.Switch9,
      DHP_model_B.Fault_Valid_RT_j0.Switch2_m, 192U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_ei) && DHP_model_B.Fault_Valid_RT_j0.Switch9);

    /* DataStoreWrite: '<S427>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S427>/Data Type Conversion'
     */
    DTCStatusRAMTbl[192] = DHP_model_B.Switch2_pe;

    /* Chart: '<S427>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S427>/Constant'
     *  Delay: '<S427>/Delay'
     *  Logic: '<S427>/Logical Operator'
     *  Logic: '<S427>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch2_pe,
      DHP_model_B.Switch2_nh, 193U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_n0x) && DHP_model_B.Switch2_pe);

    /* DataStoreWrite: '<S428>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S428>/Data Type Conversion'
     */
    DTCStatusRAMTbl[193] = DHP_model_B.LogicalOperator3_h;

    /* Chart: '<S428>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S428>/Constant'
     *  Delay: '<S428>/Delay'
     *  Logic: '<S428>/Logical Operator'
     *  Logic: '<S428>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.LogicalOperator3_h,
      DHP_model_B.Switch2_f3, 194U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_bb) && DHP_model_B.LogicalOperator3_h);

    /* DataStoreWrite: '<S429>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S429>/Data Type Conversion'
     */
    DTCStatusRAMTbl[194] = DHP_model_B.Switch2_il;

    /* Chart: '<S429>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S429>/Constant'
     *  Delay: '<S429>/Delay'
     *  Logic: '<S429>/Logical Operator'
     *  Logic: '<S429>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch2_il,
      DHP_model_B.Switch2_ph, 195U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_fpy) && DHP_model_B.Switch2_il);

    /* DataStoreWrite: '<S430>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S430>/Data Type Conversion'
     */
    DTCStatusRAMTbl[195] = DHP_model_B.Switch2_n2;

    /* Chart: '<S430>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S430>/Constant'
     *  Delay: '<S430>/Delay'
     *  Logic: '<S430>/Logical Operator'
     *  Logic: '<S430>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Switch2_n2,
      DHP_model_B.Switch2_lj, 196U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_hzl) && DHP_model_B.Switch2_n2);

    /* DataStoreWrite: '<S431>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S431>/Data Type Conversion'
     */
    DTCStatusRAMTbl[196] = DHP_model_B.Fault_Valid_Time_os.Fault_Affirm.Switch2;

    /* Chart: '<S431>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S431>/Constant'
     *  Delay: '<S431>/Delay'
     *  Logic: '<S431>/Logical Operator'
     *  Logic: '<S431>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart
      (DHP_model_B.Fault_Valid_Time_os.Fault_Affirm.Switch2,
       DHP_model_B.Fault_Valid_Time_os.Switch2_i, 197U, rtb_SnapShots,
       (!DHP_model_DW.Delay_DSTATE_dp) &&
       DHP_model_B.Fault_Valid_Time_os.Fault_Affirm.Switch2);

    /* DataStoreWrite: '<S432>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S432>/Data Type Conversion'
     */
    DTCStatusRAMTbl[197] = DHP_model_B.Fault_Valid_RT_o.Switch9;

    /* Chart: '<S432>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S432>/Constant'
     *  Delay: '<S432>/Delay'
     *  Logic: '<S432>/Logical Operator'
     *  Logic: '<S432>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart(DHP_model_B.Fault_Valid_RT_o.Switch9,
      DHP_model_B.Fault_Valid_RT_o.Switch2_m, 198U, rtb_SnapShots,
      (!DHP_model_DW.Delay_DSTATE_cqv) && DHP_model_B.Fault_Valid_RT_o.Switch9);

    /* DataStoreWrite: '<S433>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S433>/Data Type Conversion'
     */
    DTCStatusRAMTbl[198] = DHP_model_B.Fault_Valid_Time_p.Fault_Affirm.Switch2;

    /* Chart: '<S433>/DHP_FaultStore_Chart' incorporates:
     *  Constant: '<S433>/Constant'
     *  Delay: '<S433>/Delay'
     *  Logic: '<S433>/Logical Operator'
     *  Logic: '<S433>/Logical Operator1'
     */
    DHP_model_DHP_FaultStore_Chart
      (DHP_model_B.Fault_Valid_Time_p.Fault_Affirm.Switch2,
       DHP_model_B.Fault_Valid_Time_p.Switch2_i, 199U, rtb_SnapShots,
       (!DHP_model_DW.Delay_DSTATE_fpn) &&
       DHP_model_B.Fault_Valid_Time_p.Fault_Affirm.Switch2);

    /* Update for Delay: '<S402>/Delay' */
    DHP_model_DW.Delay_DSTATE_hm = DHP_model_B.Fault_Valid_RT_et.Switch9;

    /* Update for Delay: '<S403>/Delay' */
    DHP_model_DW.Delay_DSTATE_ow = DHP_model_B.Fault_Valid_RT_cw.Switch9;

    /* Update for Delay: '<S404>/Delay' */
    DHP_model_DW.Delay_DSTATE_k141 =
      DHP_model_B.Fault_Valid_Time_nv.Fault_Affirm.Switch2;

    /* Update for Delay: '<S405>/Delay' */
    DHP_model_DW.Delay_DSTATE_az =
      DHP_model_B.Fault_Valid_Time_f.Fault_Affirm.Switch2;

    /* Update for Delay: '<S406>/Delay' */
    DHP_model_DW.Delay_DSTATE_ds = DHP_model_B.Fault_Valid_RT_k.Switch9;

    /* Update for Delay: '<S407>/Delay' */
    DHP_model_DW.Delay_DSTATE_o0 = DHP_model_B.Fault_Valid_RT_b.Switch9;

    /* Update for Delay: '<S408>/Delay' */
    DHP_model_DW.Delay_DSTATE_crf = DHP_model_B.Fault_Valid_RT_c.Switch9;

    /* Update for Delay: '<S409>/Delay' */
    DHP_model_DW.Delay_DSTATE_kn =
      DHP_model_B.Fault_Valid_Time_l.Fault_Affirm.Switch2;

    /* Update for Delay: '<S410>/Delay' */
    DHP_model_DW.Delay_DSTATE_gb = DHP_model_B.Fault_Valid_RT_cu.Switch9;

    /* Update for Delay: '<S411>/Delay' */
    DHP_model_DW.Delay_DSTATE_i5d = DHP_model_B.Fault_Valid_RT_lt.Switch9;

    /* Update for Delay: '<S412>/Delay' */
    DHP_model_DW.Delay_DSTATE_hw = DHP_model_B.Fault_Valid_RT_jk.Switch9;

    /* Update for Delay: '<S413>/Delay' */
    DHP_model_DW.Delay_DSTATE_mw = DHP_model_B.Fault_Valid_RT_oy.Switch9;

    /* Update for Delay: '<S414>/Delay' */
    DHP_model_DW.Delay_DSTATE_e2 = DHP_model_B.Fault_Valid_RT_g1.Switch9;

    /* Update for Delay: '<S415>/Delay' */
    DHP_model_DW.Delay_DSTATE_brq = DHP_model_B.Fault_Valid_RT_fm.Switch9;

    /* Update for Delay: '<S416>/Delay' */
    DHP_model_DW.Delay_DSTATE_eeg = DHP_model_B.Fault_Valid_RT_ii.Switch9;

    /* Update for Delay: '<S417>/Delay' */
    DHP_model_DW.Delay_DSTATE_jki = DHP_model_B.Fault_Valid_RT_e1.Switch9;

    /* Update for Delay: '<S418>/Delay' */
    DHP_model_DW.Delay_DSTATE_ai = DHP_model_B.Fault_Valid_RT_etn.Switch9;

    /* Update for Delay: '<S419>/Delay' */
    DHP_model_DW.Delay_DSTATE_kv = DHP_model_B.Fault_Valid_RT_hg.Switch9;

    /* Update for Delay: '<S420>/Delay' */
    DHP_model_DW.Delay_DSTATE_ohq = DHP_model_B.Fault_Valid_RT_iw.Switch9;

    /* Update for Delay: '<S421>/Delay' */
    DHP_model_DW.Delay_DSTATE_fq = DHP_model_B.Fault_Valid_RT_c2.Switch9;

    /* Update for Delay: '<S422>/Delay' */
    DHP_model_DW.Delay_DSTATE_nz = DHP_model_B.Fault_Valid_RT_e2.Switch9;

    /* Update for Delay: '<S423>/Delay' */
    DHP_model_DW.Delay_DSTATE_dy = DHP_model_B.Fault_Valid_RT_ax.Switch9;

    /* Update for Delay: '<S424>/Delay' */
    DHP_model_DW.Delay_DSTATE_af = DHP_model_B.Fault_Valid_RT_ik.Switch9;

    /* Update for Delay: '<S425>/Delay' */
    DHP_model_DW.Delay_DSTATE_iir = DHP_model_B.Fault_Valid_RT_j1y.Switch9;

    /* Update for Delay: '<S426>/Delay' */
    DHP_model_DW.Delay_DSTATE_ei = DHP_model_B.Fault_Valid_RT_j0.Switch9;

    /* Update for Delay: '<S427>/Delay' */
    DHP_model_DW.Delay_DSTATE_n0x = DHP_model_B.Switch2_pe;

    /* Update for Delay: '<S428>/Delay' */
    DHP_model_DW.Delay_DSTATE_bb = DHP_model_B.LogicalOperator3_h;

    /* Update for Delay: '<S429>/Delay' */
    DHP_model_DW.Delay_DSTATE_fpy = DHP_model_B.Switch2_il;

    /* Update for Delay: '<S430>/Delay' */
    DHP_model_DW.Delay_DSTATE_hzl = DHP_model_B.Switch2_n2;

    /* Update for Delay: '<S431>/Delay' */
    DHP_model_DW.Delay_DSTATE_dp =
      DHP_model_B.Fault_Valid_Time_os.Fault_Affirm.Switch2;

    /* Update for Delay: '<S432>/Delay' */
    DHP_model_DW.Delay_DSTATE_cqv = DHP_model_B.Fault_Valid_RT_o.Switch9;

    /* Update for Delay: '<S433>/Delay' */
    DHP_model_DW.Delay_DSTATE_fpn =
      DHP_model_B.Fault_Valid_Time_p.Fault_Affirm.Switch2;
  }

  /* End of Outputs for SubSystem: '<S7>/Subsystem_VCU2HW' */

  /* Update for Delay: '<S59>/Delay' */
  DHP_model_DW.Delay_DSTATE_ej = DHP_model_B.Switch2_mf2;

  /* Update for Delay: '<S60>/Delay' */
  DHP_model_DW.Delay_DSTATE_ey = DHP_model_B.Fault_Valid_RT_cx.Switch9;

  /* Update for Delay: '<S61>/Delay' */
  DHP_model_DW.Delay_DSTATE_ke = DHP_model_B.Switch3_nn;

  /* Update for Delay: '<S62>/Delay' */
  DHP_model_DW.Delay_DSTATE_i5l = DHP_model_B.Fault_Valid_RT_ch.Switch9;

  /* Update for Delay: '<S63>/Delay' */
  DHP_model_DW.Delay_DSTATE_h5b = DHP_model_B.Fault_Valid_RT_jv.Switch9;

  /* Update for Delay: '<S64>/Delay' */
  DHP_model_DW.Delay_DSTATE_ml = DHP_model_B.Fault_Valid_RT_mv.Switch9;

  /* Update for Delay: '<S65>/Delay' */
  DHP_model_DW.Delay_DSTATE_ks = DHP_model_B.Fault_Valid_RT_d.Switch9;

  /* Update for Delay: '<S66>/Delay' */
  DHP_model_DW.Delay_DSTATE_es = DHP_model_B.Fault_Valid_RT_f.Switch9;

  /* Update for Delay: '<S67>/Delay' */
  DHP_model_DW.Delay_DSTATE_ie = DHP_model_B.Fault_Valid_RT_l3.Switch9;

  /* Update for Delay: '<S68>/Delay' */
  DHP_model_DW.Delay_DSTATE_cq = DHP_model_B.Fault_Valid_RT_c0.Switch9;

  /* Update for Delay: '<S69>/Delay' */
  DHP_model_DW.Delay_DSTATE_cj = DHP_model_B.Fault_Valid_RT_im.Switch9;

  /* Update for Delay: '<S70>/Delay' */
  DHP_model_DW.Delay_DSTATE_ox = DHP_model_B.Fault_Valid_RT_kz.Switch9;

  /* Update for Delay: '<S71>/Delay' */
  DHP_model_DW.Delay_DSTATE_pr =
    DHP_model_B.Fault_Valid_Time_c.Fault_Affirm.Switch2;

  /* Update for Delay: '<S72>/Delay' */
  DHP_model_DW.Delay_DSTATE_g4 = DHP_model_B.Fault_Valid_RT_oa.Switch9;

  /* Update for Delay: '<S73>/Delay' */
  DHP_model_DW.Delay_DSTATE_gp = DHP_model_B.Fault_Valid_RT_n.Switch9;

  /* Update for Delay: '<S74>/Delay' */
  DHP_model_DW.Delay_DSTATE_b = DHP_model_B.Fault_Valid_RT_p.Switch9;

  /* Update for Delay: '<S75>/Delay' */
  DHP_model_DW.Delay_DSTATE_a5 = DHP_model_B.Fault_Valid_RT_a.Switch9;

  /* Update for Delay: '<S76>/Delay' */
  DHP_model_DW.Delay_DSTATE_oh = DHP_model_B.Fault_Valid_RT_j1.Switch9;

  /* Update for Delay: '<S77>/Delay' */
  DHP_model_DW.Delay_DSTATE_mz = DHP_model_B.Fault_Valid_RT_ew.Switch9;

  /* Update for Delay: '<S78>/Delay' */
  DHP_model_DW.Delay_DSTATE_eo = DHP_model_B.Fault_Valid_RT_kv.Switch9;

  /* Update for Delay: '<S79>/Delay' */
  DHP_model_DW.Delay_DSTATE_bn = DHP_model_B.Fault_Valid_RT_ir.Switch9;

  /* Update for Delay: '<S80>/Delay' */
  DHP_model_DW.Delay_DSTATE_jg = DHP_model_B.Fault_Valid_RT_e3.Switch9;

  /* Update for Delay: '<S81>/Delay' */
  DHP_model_DW.Delay_DSTATE_c0 = DHP_model_B.Fault_Valid_RT_b1.Switch9;

  /* Update for Delay: '<S82>/Delay' */
  DHP_model_DW.Delay_DSTATE_cb =
    DHP_model_B.Fault_Valid_Time_k.Fault_Affirm.Switch2;

  /* Update for Delay: '<S83>/Delay' */
  DHP_model_DW.Delay_DSTATE_pe = DHP_model_B.Fault_Valid_RT_an.Switch9;

  /* Update for Delay: '<S84>/Delay' */
  DHP_model_DW.Delay_DSTATE_fl = DHP_model_B.Fault_Valid_RT_ho.Switch9;

  /* Update for Delay: '<S85>/Delay' */
  DHP_model_DW.Delay_DSTATE_c04 = DHP_model_B.Fault_Valid_RT_ij.Switch9;

  /* Update for Delay: '<S86>/Delay' */
  DHP_model_DW.Delay_DSTATE_hr = DHP_model_B.Fault_Valid_RT_l.Switch9;

  /* Update for Delay: '<S87>/Delay' */
  DHP_model_DW.Delay_DSTATE_hj = DHP_model_B.Fault_Valid_RT_k4.Switch9;

  /* Update for Delay: '<S88>/Delay' */
  DHP_model_DW.Delay_DSTATE_kj = DHP_model_B.Fault_Valid_RT_h.Switch9;

  /* Update for Delay: '<S89>/Delay' */
  DHP_model_DW.Delay_DSTATE_ko =
    DHP_model_B.Fault_Valid_Time_jx.Fault_Affirm.Switch2;

  /* Update for Delay: '<S90>/Delay' */
  DHP_model_DW.Delay_DSTATE_on = DHP_model_B.Fault_Valid_RT_gv.Switch9;

  /* Update for Delay: '<S91>/Delay' */
  DHP_model_DW.Delay_DSTATE_aa = DHP_model_B.Fault_Valid_RT_ds.Switch9;

  /* Update for Delay: '<S92>/Delay' */
  DHP_model_DW.Delay_DSTATE_eu = DHP_model_B.Fault_Valid_RT_bf.Switch9;

  /* Update for Delay: '<S93>/Delay' */
  DHP_model_DW.Delay_DSTATE_gc =
    DHP_model_B.Fault_Valid_Time_j.Fault_Affirm.Switch2;

  /* Update for Delay: '<S94>/Delay' */
  DHP_model_DW.Delay_DSTATE_iu = DHP_model_B.Fault_Valid_RT_hi.Switch9;

  /* Update for Delay: '<S95>/Delay' */
  DHP_model_DW.Delay_DSTATE_jk = DHP_model_B.Fault_Valid_RT_en.Switch9;

  /* Update for Delay: '<S96>/Delay' */
  DHP_model_DW.Delay_DSTATE_kq = DHP_model_B.Switch9_n;

  /* Update for Delay: '<S97>/Delay' */
  DHP_model_DW.Delay_DSTATE_bw = DHP_model_B.Fault_Valid_RT_a4.Switch9;

  /* Update for Delay: '<S98>/Delay' */
  DHP_model_DW.Delay_DSTATE_mj = DHP_model_B.Fault_Valid_RT_mn.Switch9;

  /* Update for Delay: '<S99>/Delay' */
  DHP_model_DW.Delay_DSTATE_eq = DHP_model_B.Fault_Valid_RT_cg.Switch9;

  /* Update for Delay: '<S100>/Delay' */
  DHP_model_DW.Delay_DSTATE_gk = DHP_model_B.Fault_Valid_RT_kvr.Switch9;

  /* Update for Delay: '<S101>/Delay' */
  DHP_model_DW.Delay_DSTATE_eyh = DHP_model_B.Fault_Valid_RT_kf.Switch9;

  /* Update for Delay: '<S102>/Delay' */
  DHP_model_DW.Delay_DSTATE_mc = DHP_model_B.Fault_Valid_RT_id.Switch9;

  /* Update for Delay: '<S103>/Delay' */
  DHP_model_DW.Delay_DSTATE_my = DHP_model_B.Fault_Valid_RT_bm.Switch9;

  /* Update for Delay: '<S104>/Delay' */
  DHP_model_DW.Delay_DSTATE_ew =
    DHP_model_B.Fault_Valid_Time.Fault_Affirm.Switch2;

  /* Update for Delay: '<S105>/Delay' */
  DHP_model_DW.Delay_DSTATE_jr = DHP_model_B.Fault_Valid_RT_bz.Switch9;

  /* Update for Delay: '<S106>/Delay' */
  DHP_model_DW.Delay_DSTATE_o5 = DHP_model_B.Fault_Valid_RT_kl.Switch9;

  /* Update for Delay: '<S107>/Delay' */
  DHP_model_DW.Delay_DSTATE_nj = DHP_model_B.Fault_Valid_RT_my.Switch9;

  /* Update for Delay: '<S108>/Delay' */
  DHP_model_DW.Delay_DSTATE_ewf = DHP_model_B.Fault_Valid_RT_kb.Switch9;

  /* Update for Delay: '<S109>/Delay' */
  DHP_model_DW.Delay_DSTATE_bnm = DHP_model_B.Fault_Valid_RT_ae.Switch9;

  /* Update for Delay: '<S110>/Delay' */
  DHP_model_DW.Delay_DSTATE_dq = DHP_model_B.Fault_Valid_RT_h3.Switch9;

  /* Update for Delay: '<S111>/Delay' */
  DHP_model_DW.Delay_DSTATE_dw = rtb_Switch1;

  /* Update for Delay: '<S112>/Delay' */
  DHP_model_DW.Delay_DSTATE_lq = rtb_Switch4;

  /* Update for Delay: '<S113>/Delay' */
  DHP_model_DW.Delay_DSTATE_in = rtb_Switch6;

  /* Update for Delay: '<S114>/Delay' */
  DHP_model_DW.Delay_DSTATE_me = rtb_Switch3;

  /* Update for Delay: '<S115>/Delay' */
  DHP_model_DW.Delay_DSTATE_c5 =
    DHP_model_B.Fault_Valid_Time_o.Fault_Affirm.Switch2;

  /* Update for Delay: '<S116>/Delay' */
  DHP_model_DW.Delay_DSTATE_f2 = rtb_Switch9;

  /* Update for Delay: '<S117>/Delay' */
  DHP_model_DW.Delay_DSTATE_oq = rtb_Switch12;

  /* Update for Delay: '<S118>/Delay' */
  DHP_model_DW.Delay_DSTATE_da = rtb_Switch14;

  /* Update for Delay: '<S119>/Delay' */
  DHP_model_DW.Delay_DSTATE_fir = rtb_Switch16;

  /* Update for Delay: '<S120>/Delay' */
  DHP_model_DW.Delay_DSTATE_bg = rtb_Switch18;

  /* Update for Delay: '<S121>/Delay' */
  DHP_model_DW.Delay_DSTATE_nr = rtb_Switch20;

  /* Update for Delay: '<S122>/Delay' */
  DHP_model_DW.Delay_DSTATE_i0 = rtb_Switch22;

  /* Update for Delay: '<S123>/Delay' */
  DHP_model_DW.Delay_DSTATE_g4r = rtb_Switch24;

  /* Update for Delay: '<S124>/Delay' */
  DHP_model_DW.Delay_DSTATE_c1 = rtb_Switch26;

  /* Update for Delay: '<S125>/Delay' */
  DHP_model_DW.Delay_DSTATE_k1 = rtb_Switch28;

  /* Update for Delay: '<S126>/Delay' */
  DHP_model_DW.Delay_DSTATE_ny =
    DHP_model_B.Fault_Valid_Time_i.Fault_Affirm.Switch2;

  /* Update for Delay: '<S127>/Delay' */
  DHP_model_DW.Delay_DSTATE_gi = rtb_Switch38;

  /* Update for Delay: '<S128>/Delay' */
  DHP_model_DW.Delay_DSTATE_cbq = rtb_Switch40;

  /* Update for Delay: '<S129>/Delay' */
  DHP_model_DW.Delay_DSTATE_pj = rtb_Switch42;

  /* Update for Delay: '<S130>/Delay' */
  DHP_model_DW.Delay_DSTATE_fp = rtb_Switch44;

  /* Update for Delay: '<S131>/Delay' */
  DHP_model_DW.Delay_DSTATE_k14 = rtb_Switch46;

  /* Update for Delay: '<S132>/Delay' */
  DHP_model_DW.Delay_DSTATE_cr = rtb_Switch29;

  /* Update for Delay: '<S133>/Delay' */
  DHP_model_DW.Delay_DSTATE_cj2 = rtb_Switch31;

  /* Update for Delay: '<S134>/Delay' */
  DHP_model_DW.Delay_DSTATE_n0 = rtb_Switch33;

  /* Update for Delay: '<S135>/Delay' */
  DHP_model_DW.Delay_DSTATE_cu = DHP_model_B.Fault_Affirm.Switch2;

  /* Update for Delay: '<S136>/Delay' */
  DHP_model_DW.Delay_DSTATE_pg =
    DHP_model_B.Fault_Valid_Time_b.Fault_Affirm.Switch2;

  /* Update for Delay: '<S137>/Delay' */
  DHP_model_DW.Delay_DSTATE_kqz =
    DHP_model_B.Fault_Valid_Time_n.Fault_Affirm.Switch2;

  /* Update for Delay: '<S138>/Delay' */
  DHP_model_DW.Delay_DSTATE_ee0 = DHP_model_B.Fault_Valid_RT_g.Switch9;

  /* Update for Delay: '<S139>/Delay' */
  DHP_model_DW.Delay_DSTATE_n4 =
    DHP_model_B.Fault_Valid_Time_d.Fault_Affirm.Switch2;

  /* Update for Delay: '<S140>/Delay' */
  DHP_model_DW.Delay_DSTATE_ni =
    DHP_model_B.Fault_Valid_Time_h.Fault_Affirm.Switch2;

  /* Update for Delay: '<S141>/Delay' */
  DHP_model_DW.Delay_DSTATE_lf =
    DHP_model_B.Fault_Valid_Time_o0.Fault_Affirm.Switch2;

  /* Update for Delay: '<S142>/Delay' */
  DHP_model_DW.Delay_DSTATE_fh =
    DHP_model_B.Fault_Valid_Time_la.Fault_Affirm.Switch2;

  /* Update for Delay: '<S143>/Delay' */
  DHP_model_DW.Delay_DSTATE_hs =
    DHP_model_B.Fault_Valid_Time_n1.Fault_Affirm.Switch2;

  /* Update for Delay: '<S144>/Delay' */
  DHP_model_DW.Delay_DSTATE_md =
    DHP_model_B.Fault_Valid_Time_nvm.Fault_Affirm.Switch2;

  /* Update for Delay: '<S145>/Delay' */
  DHP_model_DW.Delay_DSTATE_io =
    DHP_model_B.Fault_Valid_Time_nw.Fault_Affirm.Switch2;

  /* Update for Delay: '<S146>/Delay' */
  DHP_model_DW.Delay_DSTATE_kp = DHP_model_B.Fault_Valid_RT_is.Switch9;

  /* Update for Delay: '<S147>/Delay' */
  DHP_model_DW.Delay_DSTATE_l5 =
    DHP_model_B.Fault_Valid_Time_ai.Fault_Affirm.Switch2;

  /* Update for Delay: '<S148>/Delay' */
  DHP_model_DW.Delay_DSTATE_nt = DHP_model_B.Switch3_f5;

  /* Update for Delay: '<S149>/Delay' */
  DHP_model_DW.Delay_DSTATE_la = DHP_model_B.Fault_Valid_RT_gf.Switch9;

  /* Update for Delay: '<S150>/Delay' */
  DHP_model_DW.Delay_DSTATE_p3 =
    DHP_model_B.Fault_Valid_Time_j5.Fault_Affirm.Switch2;

  /* Update for Delay: '<S151>/Delay' */
  DHP_model_DW.Delay_DSTATE_a1 =
    DHP_model_B.Fault_Valid_Time_nm.Fault_Affirm.Switch2;

  /* Update for Delay: '<S152>/Delay' */
  DHP_model_DW.Delay_DSTATE_hu =
    DHP_model_B.Fault_Valid_Time_am.Fault_Affirm.Switch2;

  /* Update for Delay: '<S153>/Delay' */
  DHP_model_DW.Delay_DSTATE_hx = DHP_model_B.LogicalOperator3;

  /* Update for Delay: '<S154>/Delay' */
  DHP_model_DW.Delay_DSTATE_pl = DHP_model_B.Fault_Valid_RT_kj.Switch9;

  /* Update for Delay: '<S155>/Delay' */
  DHP_model_DW.Delay_DSTATE_lg = DHP_model_B.Fault_Valid_RT_du.Switch9;

  /* Update for Delay: '<S156>/Delay' */
  DHP_model_DW.Delay_DSTATE_hc = DHP_model_B.Fault_Valid_RT_jm.Switch9;

  /* Update for Delay: '<S157>/Delay' */
  DHP_model_DW.Delay_DSTATE_bx =
    DHP_model_B.Fault_Valid_Time_ak.Fault_Affirm.Switch2;

  /* Update for Delay: '<S158>/Delay' */
  DHP_model_DW.Delay_DSTATE_d5 =
    DHP_model_B.Fault_Valid_Time_iw.Fault_Affirm.Switch2;

  /* Update for Delay: '<S159>/Delay' */
  DHP_model_DW.Delay_DSTATE_eb =
    DHP_model_B.Fault_Valid_Time_ix.Fault_Affirm.Switch2;

  /* Update for Delay: '<S160>/Delay' */
  DHP_model_DW.Delay_DSTATE_bwe = DHP_model_B.Fault_Valid_RT_mf.Switch9;

  /* Update for Delay: '<S161>/Delay' */
  DHP_model_DW.Delay_DSTATE_bq =
    DHP_model_B.Fault_Valid_Time_a0.Fault_Affirm.Switch2;

  /* Update for Delay: '<S162>/Delay' */
  DHP_model_DW.Delay_DSTATE_jo = DHP_model_B.Switch2_h;

  /* Update for Delay: '<S163>/Delay' */
  DHP_model_DW.Delay_DSTATE_ph = DHP_model_B.Fault_Valid_RT_ad.Switch9;

  /* Update for Delay: '<S164>/Delay' */
  DHP_model_DW.Delay_DSTATE_dx = DHP_model_B.Fault_Valid_RT_pi.Switch9;

  /* Update for Delay: '<S165>/Delay' */
  DHP_model_DW.Delay_DSTATE_pl0 = DHP_model_B.Fault_Valid_RT_pa.Switch9;

  /* Update for Delay: '<S166>/Delay' */
  DHP_model_DW.Delay_DSTATE_clf = DHP_model_B.Fault_Valid_RT_iq.Switch9;

  /* Update for Delay: '<S167>/Delay' */
  DHP_model_DW.Delay_DSTATE_ia = DHP_model_B.Switch9_e;

  /* Update for Delay: '<S168>/Delay' */
  DHP_model_DW.Delay_DSTATE_njc = DHP_model_B.Fault_Valid_RT_k1s.Switch9;

  /* Update for Delay: '<S169>/Delay' */
  DHP_model_DW.Delay_DSTATE_gkp = DHP_model_B.Switch9_i;

  /* Update for Delay: '<S170>/Delay' */
  DHP_model_DW.Delay_DSTATE_ah = DHP_model_B.Fault_Valid_RT_bt.Switch9;

  /* Update for Delay: '<S171>/Delay' */
  DHP_model_DW.Delay_DSTATE_h5m = DHP_model_B.Fault_Valid_RT_j.Switch9;

  /* Update for Delay: '<S172>/Delay' */
  DHP_model_DW.Delay_DSTATE_op = DHP_model_B.Switch9_ma;

  /* Update for Delay: '<S173>/Delay' */
  DHP_model_DW.Delay_DSTATE_br = DHP_model_B.Fault_Valid_RT_py.Switch9;

  /* Update for Delay: '<S174>/Delay' */
  DHP_model_DW.Delay_DSTATE_oy = DHP_model_B.Fault_Valid_RT_mb.Switch9;

  /* Update for Delay: '<S175>/Delay' */
  DHP_model_DW.Delay_DSTATE_lu = DHP_model_B.Fault_Valid_RT_m5.Switch9;

  /* Update for Delay: '<S176>/Delay' */
  DHP_model_DW.Delay_DSTATE_ps = DHP_model_B.Fault_Valid_RT_bne.Switch9;

  /* Update for Delay: '<S177>/Delay' */
  DHP_model_DW.Delay_DSTATE_ic = DHP_model_B.Switch9_fr;

  /* Update for Delay: '<S178>/Delay' */
  DHP_model_DW.Delay_DSTATE_cf = DHP_model_B.Switch9_g;

  /* Update for Delay: '<S179>/Delay' */
  DHP_model_DW.Delay_DSTATE_cd = DHP_model_B.Fault_Valid_RT_ag.Switch9;

  /* Update for Delay: '<S180>/Delay' */
  DHP_model_DW.Delay_DSTATE_nm = DHP_model_B.Fault_Valid_RT_mr.Switch9;

  /* Update for Delay: '<S181>/Delay' */
  DHP_model_DW.Delay_DSTATE_p1 = DHP_model_B.Fault_Valid_RT_kbz.Switch9;

  /* Update for Delay: '<S182>/Delay' */
  DHP_model_DW.Delay_DSTATE_h3 = DHP_model_B.Fault_Valid_RT_kt.Switch9;

  /* Update for Delay: '<S183>/Delay' */
  DHP_model_DW.Delay_DSTATE_lo = DHP_model_B.Fault_Valid_RT_ewi.Switch9;

  /* Update for Delay: '<S184>/Delay' */
  DHP_model_DW.Delay_DSTATE_eek = DHP_model_B.Switch9_f;

  /* Update for Delay: '<S185>/Delay' */
  DHP_model_DW.Delay_DSTATE_bnk = DHP_model_B.Fault_Valid_RT_l4.Switch9;

  /* Update for Delay: '<S186>/Delay' */
  DHP_model_DW.Delay_DSTATE_ls = DHP_model_B.Fault_Valid_RT_if.Switch9;

  /* Update for Delay: '<S187>/Delay' */
  DHP_model_DW.Delay_DSTATE_gv =
    DHP_model_B.Fault_Valid_Time_im.Fault_Affirm.Switch2;

  /* Update for Delay: '<S188>/Delay' */
  DHP_model_DW.Delay_DSTATE_iv =
    DHP_model_B.Fault_Valid_Time_k5.Fault_Affirm.Switch2;

  /* Update for Delay: '<S189>/Delay' */
  DHP_model_DW.Delay_DSTATE_hz =
    DHP_model_B.Fault_Valid_Time_kh.Fault_Affirm.Switch2;

  /* Update for Delay: '<S190>/Delay' */
  DHP_model_DW.Delay_DSTATE_gu =
    DHP_model_B.Fault_Valid_Time_pv.Fault_Affirm.Switch2;

  /* Update for Delay: '<S191>/Delay' */
  DHP_model_DW.Delay_DSTATE_iw =
    DHP_model_B.Fault_Valid_Time_nj.Fault_Affirm.Switch2;

  /* Update for Delay: '<S192>/Delay' */
  DHP_model_DW.Delay_DSTATE_jy =
    DHP_model_B.Fault_Valid_Time_jc.Fault_Affirm.Switch2;

  /* Update for Delay: '<S193>/Delay' */
  DHP_model_DW.Delay_DSTATE_a5e = DHP_model_B.Fault_Valid_RT_og.Switch9;

  /* Update for Delay: '<S194>/Delay' */
  DHP_model_DW.Delay_DSTATE_ku =
    DHP_model_B.Fault_Valid_Time_j4.Fault_Affirm.Switch2;

  /* Update for Delay: '<S195>/Delay' */
  DHP_model_DW.Delay_DSTATE_ch = DHP_model_B.LogicalOperator1_e;

  /* Update for Delay: '<S196>/Delay' */
  DHP_model_DW.Delay_DSTATE_fao = DHP_model_B.LogicalOperator1_k;

  /* Update for Delay: '<S197>/Delay' */
  DHP_model_DW.Delay_DSTATE_bs = DHP_model_B.LogicalOperator1_h;

  /* Update for Delay: '<S198>/Delay' */
  DHP_model_DW.Delay_DSTATE_ll =
    DHP_model_B.Fault_Valid_Time_as.Fault_Affirm.Switch2;

  /* Update for Delay: '<S199>/Delay' */
  DHP_model_DW.Delay_DSTATE_ph3 =
    DHP_model_B.Fault_Valid_Time_iy.Fault_Affirm.Switch2;

  /* Update for Delay: '<S200>/Delay' */
  DHP_model_DW.Delay_DSTATE_nc =
    DHP_model_B.Fault_Valid_Time_gy.Fault_Affirm.Switch2;

  /* Update for Delay: '<S201>/Delay' */
  DHP_model_DW.Delay_DSTATE_et =
    DHP_model_B.Fault_Valid_Time_fa.Fault_Affirm.Switch2;

  /* Update for Delay: '<S202>/Delay' */
  DHP_model_DW.Delay_DSTATE_p3i =
    DHP_model_B.Fault_Valid_Time_cb.Fault_Affirm.Switch2;

  /* Update for Delay: '<S203>/Delay' */
  DHP_model_DW.Delay_DSTATE_da1 = DHP_model_B.Fault_Valid_RT_b3.Switch9;

  /* Update for Delay: '<S204>/Delay' */
  DHP_model_DW.Delay_DSTATE_fmn = DHP_model_B.Fault_Valid_RT_i.Switch9;

  /* Update for Delay: '<S205>/Delay' */
  DHP_model_DW.Delay_DSTATE_ahx = DHP_model_B.Fault_Valid_RT_mp.Switch9;

  /* Update for Delay: '<S206>/Delay' */
  DHP_model_DW.Delay_DSTATE_cl5 = DHP_model_B.Fault_Valid_RT_bzj.Switch9;

  /* Update for Delay: '<S207>/Delay' */
  DHP_model_DW.Delay_DSTATE_ky = DHP_model_B.Fault_Valid_RT_j1b.Switch9;

  /* Update for Delay: '<S208>/Delay' */
  DHP_model_DW.Delay_DSTATE_mi = DHP_model_B.Fault_Valid_RT_hb.Switch9;

  /* Update for Delay: '<S209>/Delay' */
  DHP_model_DW.Delay_DSTATE_iwx =
    DHP_model_B.Fault_Valid_Time_lp.Fault_Affirm.Switch2;

  /* Update for Delay: '<S210>/Delay' */
  DHP_model_DW.Delay_DSTATE_hvo =
    DHP_model_B.Fault_Valid_Time_m.Fault_Affirm.Switch2;

  /* Update for Delay: '<S211>/Delay' */
  DHP_model_DW.Delay_DSTATE_kpb =
    DHP_model_B.Fault_Valid_Time_g.Fault_Affirm.Switch2;

  /* Update for Delay: '<S212>/Delay' */
  DHP_model_DW.Delay_DSTATE_hi =
    DHP_model_B.Fault_Valid_Time_jy.Fault_Affirm.Switch2;

  /* Update for Delay: '<S213>/Delay' */
  DHP_model_DW.Delay_DSTATE_ex =
    DHP_model_B.Fault_Valid_Time_eo.Fault_Affirm.Switch2;

  /* Update for Delay: '<S214>/Delay' */
  DHP_model_DW.Delay_DSTATE_koq =
    DHP_model_B.Fault_Valid_Time_n1v.Fault_Affirm.Switch2;

  /* Update for Delay: '<S215>/Delay' */
  DHP_model_DW.Delay_DSTATE_d5z = DHP_model_B.Fault_Valid_RT_e.Switch9;

  /* Update for Delay: '<S216>/Delay' */
  DHP_model_DW.Delay_DSTATE_p3r =
    DHP_model_B.Fault_Valid_Time_oe.Fault_Affirm.Switch2;

  /* Update for Delay: '<S217>/Delay' */
  DHP_model_DW.Delay_DSTATE_cc =
    DHP_model_B.Fault_Valid_Time_jj.Fault_Affirm.Switch2;

  /* Update for Delay: '<S218>/Delay' */
  DHP_model_DW.Delay_DSTATE_lk =
    DHP_model_B.Fault_Valid_Time_ds.Fault_Affirm.Switch2;

  /* Update for Delay: '<S219>/Delay' */
  DHP_model_DW.Delay_DSTATE_ao =
    DHP_model_B.Fault_Valid_Time_e.Fault_Affirm.Switch2;

  /* Update for Delay: '<S220>/Delay' */
  DHP_model_DW.Delay_DSTATE_j0 =
    DHP_model_B.Fault_Valid_Time_a.Fault_Affirm.Switch2;

  /* Update for Delay: '<S221>/Delay' */
  DHP_model_DW.Delay_DSTATE_av = DHP_model_B.Fault_Valid_RT.Switch9;

  /* Update for Delay: '<S222>/Delay' */
  DHP_model_DW.Delay_DSTATE_nf = DHP_model_B.Fault_Valid_RT_hm.Switch9;

  /* Update for Delay: '<S223>/Delay' */
  DHP_model_DW.Delay_DSTATE_oc = DHP_model_B.Switch2_bz;

  /* Update for Delay: '<S224>/Delay' */
  DHP_model_DW.Delay_DSTATE_koj = DHP_model_B.Fault_Valid_RT_ez.Switch9;

  /* Update for Delay: '<S225>/Delay' */
  DHP_model_DW.Delay_DSTATE_ca = DHP_model_B.Switch3_kd;
}

/* Output and update for enable system: '<S543>/AccPdlSenRefVoltInstFlt' */
void DHP_model_AccPdlSenRefVoltInstFlt(boolean_T rtu_Enable, uint16_T
  rtu_AccPdlSen1Volt_mv, uint16_T rtu_AccPdlSenVolt2_mv, uint16_T
  rtu_KDHP_AccPdlPowerVoltDownLimValue_mv, uint16_T
  rtu_KDHP_AccPdlPowerVoltUpLimValue_mv, boolean_T
  rtu_Auxiliary_Judgment_Condition, B_AccPdlSenRefVoltInstFlt_DHP_model_T
  *localB)
{
  /* Outputs for Enabled SubSystem: '<S543>/AccPdlSenRefVoltInstFlt' incorporates:
   *  EnablePort: '<S551>/Enable'
   */
  if (rtu_Enable) {
    /* Logic: '<S551>/Logical Operator4' incorporates:
     *  Logic: '<S551>/Logical Operator'
     *  Logic: '<S551>/Logical Operator2'
     *  RelationalOperator: '<S551>/Relational Operator3'
     *  RelationalOperator: '<S551>/Relational Operator4'
     */
    localB->LogicalOperator4 = (((rtu_AccPdlSen1Volt_mv >
      rtu_KDHP_AccPdlPowerVoltUpLimValue_mv) && rtu_Auxiliary_Judgment_Condition)
      || ((rtu_AccPdlSenVolt2_mv > rtu_KDHP_AccPdlPowerVoltUpLimValue_mv) &&
          rtu_Auxiliary_Judgment_Condition));

    /* Logic: '<S551>/Logical Operator5' incorporates:
     *  Logic: '<S551>/Logical Operator1'
     *  Logic: '<S551>/Logical Operator3'
     *  RelationalOperator: '<S551>/Relational Operator1'
     *  RelationalOperator: '<S551>/Relational Operator2'
     */
    localB->LogicalOperator5 = ((rtu_Auxiliary_Judgment_Condition &&
      (rtu_AccPdlSen1Volt_mv < rtu_KDHP_AccPdlPowerVoltDownLimValue_mv)) ||
      (rtu_Auxiliary_Judgment_Condition && (rtu_AccPdlSenVolt2_mv <
      rtu_KDHP_AccPdlPowerVoltDownLimValue_mv)));
  }

  /* End of Outputs for SubSystem: '<S543>/AccPdlSenRefVoltInstFlt' */
}

/* Output and update for enable system: '<S543>/AccPdlSenRefVoltInstFlt_Test' */
void DHP_model_AccPdlSenRefVoltInstFlt_Test(boolean_T rtu_Enable, uint16_T
  rtu_AccPdlSen1Volt_mv, uint16_T rtu_AccPdlSenVolt2_mv, uint16_T
  rtu_KDHP_AccPdlPowerVoltDownLimValue_mv, uint16_T
  rtu_KDHP_AccPdlPowerVoltUpLimValue_mv, boolean_T rtu_TestWorkDelay2s_flg,
  B_AccPdlSenRefVoltInstFlt_Test_DHP_model_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S543>/AccPdlSenRefVoltInstFlt_Test' incorporates:
   *  EnablePort: '<S552>/Enable'
   */
  if (rtu_Enable) {
    /* Logic: '<S552>/Logical Operator4' incorporates:
     *  Logic: '<S552>/Logical Operator'
     *  Logic: '<S552>/Logical Operator1'
     *  RelationalOperator: '<S552>/Relational Operator1'
     *  RelationalOperator: '<S552>/Relational Operator3'
     */
    localB->LogicalOperator4 = ((rtu_TestWorkDelay2s_flg &&
      (rtu_AccPdlSen1Volt_mv > rtu_KDHP_AccPdlPowerVoltUpLimValue_mv)) ||
      (rtu_TestWorkDelay2s_flg && (rtu_AccPdlSen1Volt_mv <
      rtu_KDHP_AccPdlPowerVoltDownLimValue_mv)));

    /* Logic: '<S552>/Logical Operator5' incorporates:
     *  Logic: '<S552>/Logical Operator2'
     *  Logic: '<S552>/Logical Operator3'
     *  RelationalOperator: '<S552>/Relational Operator2'
     *  RelationalOperator: '<S552>/Relational Operator4'
     */
    localB->LogicalOperator5 = ((rtu_TestWorkDelay2s_flg &&
      (rtu_AccPdlSenVolt2_mv > rtu_KDHP_AccPdlPowerVoltUpLimValue_mv)) ||
      (rtu_TestWorkDelay2s_flg && (rtu_AccPdlSenVolt2_mv <
      rtu_KDHP_AccPdlPowerVoltDownLimValue_mv)));
  }

  /* End of Outputs for SubSystem: '<S543>/AccPdlSenRefVoltInstFlt_Test' */
}

/* Output and update for enable system: '<S531>/LowVoltBatErrState_Test' */
void DHP_model_LowVoltBatErrState_Test(boolean_T rtu_Enable, uint16_T
  rtu_Vbatt12_volt_dV, B_LowVoltBatErrState_Test_DHP_model_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S531>/LowVoltBatErrState_Test' incorporates:
   *  EnablePort: '<S554>/Enable'
   */
  if (rtu_Enable) {
    /* RelationalOperator: '<S556>/Relational Operator' incorporates:
     *  Constant: '<S554>/Constant6'
     */
    localB->RelationalOperator = (rtu_Vbatt12_volt_dV <
      KDHP_AuxBattVoltLowInstWarmValue_dV);

    /* RelationalOperator: '<S556>/Relational Operator1' incorporates:
     *  Constant: '<S554>/Constant8'
     */
    localB->RelationalOperator1 = (rtu_Vbatt12_volt_dV >
      KDHP_AuxBattVoltHighInstWarmValue_dV);
  }

  /* End of Outputs for SubSystem: '<S531>/LowVoltBatErrState_Test' */
}

/* Disable for atomic system: '<S12>/VcuControlDevice1InstErrGenerate' */
void DHP_model_VcuControlDevice1InstErrGenerate_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S591>/TestMode' */
  if (DHP_model_DW.TestMode_MODE) {
    /* Disable for Outport: '<S594>/VCUHwHS1ErrInstFlt_flg' */
    DHP_model_B.LogicalOperator7_g = false;
    DHP_model_DW.TestMode_MODE = false;
  }

  /* End of Disable for SubSystem: '<S591>/TestMode' */
}

/* Output and update for atomic system: '<S12>/VcuControlDevice1InstErrGenerate' */
void DHP_model_VcuControlDevice1InstErrGenerate(void)
{
  uint16_T rtb_Switch;
  boolean_T rtb_Switch_o0;
  boolean_T rtb_u;
  boolean_T rtb_RelationalOperator1_hc;
  uint8_T rtb_Add1_m;
  uint8_T tmp;
  uint8_T tmp_0;

  /* Inport: '<S522>/VPMM_DCDCStopworkTimeout_flg' */
  VDHP_DCDCStopworkTOInstFlt_flg = DHP_model_B.VPMM_DCDCStopworkTimeout_flg;

  /* Inport: '<S522>/VPMM_HVActiveTimeout_flg' */
  VDHP_HVActiveTOInstFlt_flg = DHP_model_B.VPMM_HVActiveTimeout_flg;

  /* Inport: '<S522>/VPMM_HVDCDCActiveTimeout_flg' */
  VDHP_HVDCDCActiveTOInstFlt_flg = DHP_model_B.VPMM_HVDCDCActiveTimeout_flg;

  /* Inport: '<S522>/VPMM_HVDownTimeout_flg' */
  VDHP_HVDownTOInstFlt_flg = DHP_model_B.VPMM_HVDownTimeout_flg;

  /* Inport: '<S522>/VPMM_HVUpTimeout_flg' */
  VDHP_HVUpTOInstFlt_flg = DHP_model_B.VPMM_HVUpTimeout_flg;

  /* Inport: '<S522>/VPMM_LVUpBMSPwrUpAllwTimeout_flg' */
  VDHP_LVUpBMSPwrUpAllwTOInstFlt_flg =
    DHP_model_B.VPMM_LVUpBMSPwrUpAllwTimeout_flg;

  /* Inport: '<S522>/VPMM_LVUpBMSTimeout_flg' */
  VDHP_LVUpBMSTOInstFlt_flg = DHP_model_B.VPMM_LVUpBMSTimeout_flg;

  /* Inport: '<S522>/VPMM_LVUpDCDCTimeout_flg' */
  VDHP_LVUpDCDCTOInstFlt_flg = DHP_model_B.VPMM_LVUpDCDCTimeout_flg;

  /* Inport: '<S522>/VPMM_LVUpMCUTimeout_flg' */
  VDHP_LVUpMCUTOInstFlt_flg = DHP_model_B.VPMM_LVUpMCUTimeout_flg;

  /* Inport: '<S522>/VPMM_MCUDischargeTimeout_flg' */
  VDHP_MCUDischargeTOInstFlt_flg = DHP_model_B.VPMM_MCUDischargeTimeout_flg;

  /* Inport: '<S522>/VPMM_MCUExitTorqTimeout_flg' */
  VDHP_MCUExitTorqTOInstFlt_flg = DHP_model_B.VPMM_MCUExitTqlTimeout_flg;

  /* Inport: '<S522>/VPMM_MCUHVActiveTimeout_flg' */
  VDHP_MCUHVActiveTOInstFlt_flg = DHP_model_B.VPMM_MCUHVActiveTimeout_flg;

  /* Switch: '<S547>/Switch' incorporates:
   *  Constant: '<S547>/Constant1'
   */
  if (DHP_model_B.Gain2 != 0) {
    rtb_Switch = DHP_model_B.Gain2;
  } else {
    rtb_Switch = 1U;
  }

  /* End of Switch: '<S547>/Switch' */

  /* Product: '<S547>/Divide1' incorporates:
   *  Product: '<S547>/Product'
   */
  rtb_Switch = (uint16_T)(DHP_model_B.Gain4 * 100U / rtb_Switch);

  /* Outputs for Enabled SubSystem: '<S531>/LowVoltBatErrState_Test' */

  /* SignalConversion: '<S531>/HiddenBuf_InsertedFor_LowVoltBatErrState_Test_at_inport_1' */
  DHP_model_LowVoltBatErrState_Test(VDHP_TestWorkDelay4s_Flg, DHP_model_B.Gain1,
    &DHP_model_B.LowVoltBatErrState_Test);

  /* End of Outputs for SubSystem: '<S531>/LowVoltBatErrState_Test' */

  /* Switch: '<S531>/Switch' incorporates:
   *  Constant: '<S553>/Constant4'
   *  Constant: '<S553>/Constant5'
   *  Constant: '<S553>/Constant6'
   *  Constant: '<S553>/Constant8'
   *  DataStoreRead: '<S531>/Data Store Read1'
   *  Logic: '<S531>/Logical Operator1'
   *  Logic: '<S555>/Logical Operator'
   *  Logic: '<S555>/Logical Operator2'
   *  Logic: '<S555>/Logical Operator7'
   *  Logic: '<S555>/Logical Operator9'
   *  RelationalOperator: '<S555>/Relational Operator'
   *  RelationalOperator: '<S555>/Relational Operator1'
   *  RelationalOperator: '<S555>/Relational Operator2'
   *  RelationalOperator: '<S555>/Relational Operator3'
   *  Switch: '<S531>/Switch1'
   */
  if (!bool_udsAgingTestStart_flag) {
    VDHP_AuxBattVoltHighInstWarm_flg = (VDHP_VCUPowerUpDelay2SWork_Flg &&
      ((KDHP_AuxBattVoltHighInstFltValue_dV > DHP_model_B.Gain1) &&
       (DHP_model_B.Gain1 > KDHP_AuxBattVoltHighInstWarmValue_dV)));
    VDHP_AuxBattVoltLowInstWarm_flg = (VDHP_VCUPowerUpDelay2SWork_Flg &&
      ((KDHP_AuxBattVoltLowInstFltValue_dV < DHP_model_B.Gain1) &&
       (DHP_model_B.Gain1 < KDHP_AuxBattVoltLowInstWarmValue_dV)));
  } else {
    VDHP_AuxBattVoltHighInstWarm_flg =
      DHP_model_B.LowVoltBatErrState_Test.RelationalOperator1;
    VDHP_AuxBattVoltLowInstWarm_flg =
      DHP_model_B.LowVoltBatErrState_Test.RelationalOperator;
  }

  /* End of Switch: '<S531>/Switch' */

  /* Logic: '<S555>/Logical Operator6' incorporates:
   *  Constant: '<S553>/Constant5'
   *  RelationalOperator: '<S555>/Relational Operator4'
   */
  VDHP_AuxBattVoltHighInstFlt_flg = ((DHP_model_B.Gain1 >=
    KDHP_AuxBattVoltHighInstFltValue_dV) && VDHP_VCUPowerUpDelay2SWork_Flg);

  /* Logic: '<S555>/Logical Operator8' incorporates:
   *  Constant: '<S553>/Constant4'
   *  RelationalOperator: '<S555>/Relational Operator5'
   */
  VDHP_AuxBattVoltLowInstFlt_flg = ((DHP_model_B.Gain1 <=
    KDHP_AuxBattVoltLowInstFltValue_dV) && VDHP_VCUPowerUpDelay2SWork_Flg);

  /* Logic: '<S528>/Logical Operator' */
  rtb_Switch_o0 = (VDHP_AuxBattVoltHighInstWarm_flg ||
                   VDHP_AuxBattVoltLowInstWarm_flg ||
                   VDHP_AuxBattVoltHighInstFlt_flg ||
                   VDHP_AuxBattVoltLowInstFlt_flg);

  /* Logic: '<S528>/Logical Operator6' incorporates:
   *  Logic: '<S528>/Logical Operator1'
   *  Logic: '<S528>/Logical Operator5'
   */
  VDHP_AccPdl_Judgment_Condition =
    !((!DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator)
      || rtb_Switch_o0);

  /* Logic: '<S528>/不充电的时候才检测' incorporates:
   *  Constant: '<S529>/Constant'
   *  RelationalOperator: '<S529>/Compare'
   */
  rtb_u = (VDHP_AccPdl_Judgment_Condition && (DHP_model_B.VINP_BMSChrgMod_enum ==
            0));

  /* Logic: '<S543>/Logical Operator' incorporates:
   *  DataStoreRead: '<S543>/Data Store Read'
   */
  rtb_RelationalOperator1_hc = !bool_udsAgingTestStart_flag;

  /* Outputs for Enabled SubSystem: '<S543>/AccPdlSenRefVoltInstFlt' */

  /* SignalConversion: '<S543>/HiddenBuf_InsertedFor_AccPdlSenRefVoltInstFlt_at_inport_5' incorporates:
   *  Constant: '<S543>/Constant5'
   *  Constant: '<S543>/Constant8'
   */
  DHP_model_AccPdlSenRefVoltInstFlt(rtb_RelationalOperator1_hc,
    DHP_model_B.DataTypeConversion10, DHP_model_B.DataTypeConversion11,
    KDHP_AccPdlPowerVoltDownLimValue_mv, KDHP_AccPdlPowerVoltUpLimValue_mv,
    rtb_u, &DHP_model_B.AccPdlSenRefVoltInstFlt);

  /* End of Outputs for SubSystem: '<S543>/AccPdlSenRefVoltInstFlt' */

  /* Outputs for Enabled SubSystem: '<S543>/AccPdlSenRefVoltInstFlt_Test' */

  /* DataStoreRead: '<S543>/Data Store Read1' incorporates:
   *  Constant: '<S543>/Constant1'
   *  Constant: '<S543>/Constant2'
   */
  DHP_model_AccPdlSenRefVoltInstFlt_Test(bool_udsAgingTestStart_flag,
    DHP_model_B.DataTypeConversion10, DHP_model_B.DataTypeConversion11,
    KDHP_AccPdlPowerVoltDownLimValue_mv, KDHP_AccPdlPowerVoltUpLimValue_mv,
    VDHP_TestWorkDelay4s_Flg, &DHP_model_B.AccPdlSenRefVoltInstFlt_Test);

  /* End of Outputs for SubSystem: '<S543>/AccPdlSenRefVoltInstFlt_Test' */

  /* Switch: '<S543>/Switch1' incorporates:
   *  Switch: '<S543>/Switch'
   */
  if (rtb_RelationalOperator1_hc) {
    VDHP_AccPdlSenRefVoltLowInstFlt_flg =
      DHP_model_B.AccPdlSenRefVoltInstFlt.LogicalOperator5;
    VDHP_AccPdlSenRefVoltHighInstFlt_flg =
      DHP_model_B.AccPdlSenRefVoltInstFlt.LogicalOperator4;
  } else {
    VDHP_AccPdlSenRefVoltLowInstFlt_flg =
      DHP_model_B.AccPdlSenRefVoltInstFlt_Test.LogicalOperator5;
    VDHP_AccPdlSenRefVoltHighInstFlt_flg =
      DHP_model_B.AccPdlSenRefVoltInstFlt_Test.LogicalOperator4;
  }

  /* End of Switch: '<S543>/Switch1' */

  /* Logic: '<S544>/Logical Operator1' incorporates:
   *  Logic: '<S544>/Logical Operator'
   *  Logic: '<S544>/Logical Operator6'
   */
  VDHP_AccPdlHLVoltPrecondition = !((!rtb_u) ||
    VDHP_AccPdlSenRefVoltLowInstFlt_flg || VDHP_AccPdlSenRefVoltHighInstFlt_flg);

  /* Logic: '<S544>/Logical Operator2' incorporates:
   *  Constant: '<S542>/Constant18'
   *  Constant: '<S544>/Constant1'
   *  RelationalOperator: '<S544>/Relational Operator1'
   *  Sum: '<S544>/Add1'
   */
  VDHP_AccPdlHVoltLowInstFlt_flg = (((uint16_T)
    (KDHP_AccPdlHDownDeathAreaValue_mv - KDHP_AccPdlHLDeathAreaOffestValue_mv) >=
    DHP_model_B.Gain4) && VDHP_AccPdlHLVoltPrecondition);

  /* Logic: '<S544>/Logical Operator3' incorporates:
   *  Constant: '<S542>/Constant15'
   *  Constant: '<S544>/Constant'
   *  RelationalOperator: '<S544>/Relational Operator'
   *  Sum: '<S544>/Add'
   */
  VDHP_AccPdlHVoltHighInstFlt_flg = ((DHP_model_B.Gain4 >= (uint16_T)((uint32_T)
    KDHP_AccPdlHUpDeathAreaValue_mv + KDHP_AccPdlHLDeathAreaOffestValue_mv)) &&
    VDHP_AccPdlHLVoltPrecondition);

  /* Logic: '<S544>/Logical Operator4' incorporates:
   *  Constant: '<S542>/Constant10'
   *  Constant: '<S544>/Constant3'
   *  RelationalOperator: '<S544>/Relational Operator3'
   *  Sum: '<S544>/Add3'
   */
  VDHP_AccPdlLVoltLowInstFlt_flg = (((uint16_T)
    (KDHP_AccPdlLDownDeathAreaValue_mv - KDHP_AccPdlHLDeathAreaOffestValue_mv) >=
    DHP_model_B.Gain2) && VDHP_AccPdlHLVoltPrecondition);

  /* Logic: '<S544>/Logical Operator5' incorporates:
   *  Constant: '<S542>/Constant5'
   *  Constant: '<S544>/Constant2'
   *  RelationalOperator: '<S544>/Relational Operator2'
   *  Sum: '<S544>/Add2'
   */
  VDHP_AccPdlLVoltHighInstFlt_flg = ((DHP_model_B.Gain2 >= (uint16_T)((uint32_T)
    KDHP_AccPdlLUpDeathAreaValue_mv + KDHP_AccPdlHLDeathAreaOffestValue_mv)) &&
    VDHP_AccPdlHLVoltPrecondition);

  /* Logic: '<S545>/Logical Operator1' incorporates:
   *  Logic: '<S545>/Logical Operator'
   *  Logic: '<S545>/Logical Operator3'
   */
  VDHP_AccelPdlRatPrecondition = !((!VDHP_AccPdlHLVoltPrecondition) ||
    VDHP_AccPdlHVoltLowInstFlt_flg || VDHP_AccPdlHVoltHighInstFlt_flg ||
    VDHP_AccPdlLVoltLowInstFlt_flg || VDHP_AccPdlLVoltHighInstFlt_flg);

  /* Logic: '<S545>/Logical Operator2' incorporates:
   *  Constant: '<S545>/Constant13'
   *  Constant: '<S545>/Constant14'
   *  Logic: '<S547>/Logical Operator2'
   *  Logic: '<S548>/FixPt Logical Operator'
   *  RelationalOperator: '<S548>/Lower Test'
   *  RelationalOperator: '<S548>/Upper Test'
   */
  VDHP_AccelPdlRatInstFlt_flg = ((!((KDHP_AccPdlHLRatDownLimitValue_pct <=
    rtb_Switch) && (rtb_Switch <= KDHP_AccPdlHLRatUpLimitValue_pct))) &&
    VDHP_AccelPdlRatPrecondition);

  /* Switch: '<S549>/Switch' incorporates:
   *  Constant: '<S549>/Constant1'
   */
  if (DHP_model_B.Gain2 != 0) {
    rtb_Switch = DHP_model_B.Gain2;
  } else {
    rtb_Switch = 1U;
  }

  /* End of Switch: '<S549>/Switch' */

  /* Product: '<S549>/Divide1' incorporates:
   *  Product: '<S549>/Product'
   */
  rtb_Switch = (uint16_T)(DHP_model_B.Gain4 * 100U / rtb_Switch);

  /* Logic: '<S546>/Logical Operator2' incorporates:
   *  Constant: '<S546>/Constant13'
   *  Constant: '<S546>/Constant14'
   *  Logic: '<S546>/Logical Operator'
   *  Logic: '<S546>/Logical Operator1'
   *  Logic: '<S549>/Logical Operator2'
   *  Logic: '<S550>/FixPt Logical Operator'
   *  RelationalOperator: '<S550>/Lower Test'
   *  RelationalOperator: '<S550>/Upper Test'
   */
  VDHP_AccelPdlRatDeathInstFlt_flg = ((!((KDHP_AccPdlHLRatDownLimitValue_pct <=
    rtb_Switch) && (rtb_Switch <= KDHP_AccPdlHLRatUpLimitValue_pct))) &&
    (VDHP_AccPdlHLVoltPrecondition && (VDHP_AccPdlHVoltLowInstFlt_flg ||
    VDHP_AccPdlHVoltHighInstFlt_flg || VDHP_AccPdlLVoltLowInstFlt_flg ||
    VDHP_AccPdlLVoltHighInstFlt_flg)));

  /* Logic: '<S544>/Logical Operator11' incorporates:
   *  Logic: '<S544>/Logical Operator10'
   *  Logic: '<S544>/Logical Operator7'
   *  Logic: '<S544>/Logical Operator8'
   *  Logic: '<S544>/Logical Operator9'
   */
  VDHP_AccPdlLHVoltDeathInstFlt_flg = ((VDHP_AccPdlHVoltLowInstFlt_flg &&
    VDHP_AccPdlLVoltLowInstFlt_flg) || (VDHP_AccPdlHVoltLowInstFlt_flg &&
    VDHP_AccPdlLVoltHighInstFlt_flg) || (VDHP_AccPdlHVoltHighInstFlt_flg &&
    VDHP_AccPdlLVoltLowInstFlt_flg) || (VDHP_AccPdlHVoltHighInstFlt_flg &&
    VDHP_AccPdlLVoltHighInstFlt_flg));

  /* Logic: '<S528>/Logical Operator2' incorporates:
   *  Logic: '<S528>/Logical Operator3'
   *  Logic: '<S528>/Logical Operator4'
   */
  VDHP_Basc_Auxiliary_Judgment_Condition = !((!VDHP_VCUPowerUpDelay2SWork_Flg) ||
    rtb_Switch_o0);

  /* Logic: '<S528>/Logical Operator10' */
  rtb_u = (VDHP_Basc_Auxiliary_Judgment_Condition &&
           DHP_model_B.VehPowerOnDelayWorkFlagCollect.VINP_15KeyOn_flg);

  /* Logic: '<S560>/Logical Operator' incorporates:
   *  RelationalOperator: '<S561>/Compare'
   *  RelationalOperator: '<S562>/Compare'
   */
  VDHP_BrkDSCheck0InstFlt_flg = ((!VDSF_BrkSwitch1) && (!VDSF_BrkSwitch2) &&
    rtb_u);

  /* Logic: '<S560>/Logical Operator1' incorporates:
   *  Logic: '<S528>/Logical Operator11'
   *  Logic: '<S560>/Logical Operator2'
   *  RelationalOperator: '<S563>/Compare'
   *  RelationalOperator: '<S564>/Compare'
   */
  VDHP_BrkDSCheck1InstFlt_flg = (VDSF_BrkSwitch1 && VDSF_BrkSwitch2 && (rtb_u &&
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.VINP_15KeyOn_flg &&
     VDHP_HVPowerUpDelay2SWork_Flg)));

  /* Logic: '<S535>/Logical Operator' incorporates:
   *  Logic: '<S535>/Logical Operator2'
   */
  VDHP_CoolSysFlt_Auxiliary_Judgment_Condition = (VDHP_HVPowerUpDelay2SWork_Flg &&
    (!MCU215LossCanNetInstFlt_flg));

  /* Switch: '<S565>/Switch1' incorporates:
   *  Constant: '<S565>/Constant10'
   *  Constant: '<S565>/Constant2'
   *  Constant: '<S565>/Constant8'
   *  Constant: '<S571>/Constant'
   *  RelationalOperator: '<S565>/Relational Operator2'
   *  RelationalOperator: '<S571>/Compare'
   */
  if (Vehicle_Type == A11_Mark) {
    rtb_Switch_o0 = false;
  } else {
    rtb_Switch_o0 = (DHP_model_B.DataTypeConversion1 > KDHP_CoolSysErr_MCUT);
  }

  /* End of Switch: '<S565>/Switch1' */

  /* Switch: '<S565>/Switch' incorporates:
   *  Constant: '<S565>/Constant'
   *  Constant: '<S565>/Constant3'
   *  Constant: '<S565>/Constant5'
   *  Constant: '<S566>/Constant'
   *  Constant: '<S567>/Constant'
   *  Constant: '<S568>/Constant'
   *  Constant: '<S569>/Constant'
   *  Constant: '<S570>/Constant'
   *  Logic: '<S565>/Logical Operator'
   *  RelationalOperator: '<S565>/Relational Operator'
   *  RelationalOperator: '<S566>/Compare'
   *  RelationalOperator: '<S567>/Compare'
   *  RelationalOperator: '<S568>/Compare'
   *  RelationalOperator: '<S569>/Compare'
   *  RelationalOperator: '<S570>/Compare'
   */
  if ((Vehicle_Type != K11_Mark) && (Vehicle_Type != K11P01_Mark) &&
      (Vehicle_Type != K11E01R_Mark) && (Vehicle_Type != K11P06_Mark) &&
      (Vehicle_Type != ((uint8_T)Z18_MARK))) {
    rtb_u = (DHP_model_B.DataTypeConversion45 > KDHP_CoolSysErr_MCUIGBTT);
  } else {
    rtb_u = false;
  }

  /* End of Switch: '<S565>/Switch' */

  /* Logic: '<S565>/Logical Operator7' incorporates:
   *  Constant: '<S565>/Constant1'
   *  Logic: '<S565>/Logical Operator6'
   *  RelationalOperator: '<S565>/Relational Operator1'
   */
  VDHP_CoolSysErrInstFlt_flg = ((rtb_Switch_o0 ||
    (DHP_model_B.DataTypeConversion46 > KDHP_CoolSysErr_MCUElecMotT) || rtb_u) &&
    VDHP_CoolSysFlt_Auxiliary_Judgment_Condition);

  /* DataStoreRead: '<S528>/Data Store Read1' */
  DHP_model_B.DataStoreRead1_f = DIDData_Invalid_DFlash;

  /* DataStoreRead: '<S528>/Data Store Read10' */
  VDHP_ChrgStopLockErrInstFlt_flg = VCHRG_ChrgStopLockError_flg;

  /* DataStoreRead: '<S528>/Data Store Read11' */
  VDHP_OBCWakeupTOInstFlt_flg = VCHRG_OBCWakeupTimeout_flg;

  /* DataStoreRead: '<S528>/Data Store Read13' */
  VDHP_AppDataCheckFaliedInstFlt_flg = AppDataCheckFaliedFlag;

  /* DataStoreRead: '<S528>/Data Store Read14' */
  VDHP_HistDataCheckFaliedInstFlt_flg = HistDataCheckFaliedFlag;

  /* DataStoreRead: '<S528>/Data Store Read17' */
  DHP_model_B.DataStoreRead17_o = DIDData_Invalid_EEPROM;

  /* DataStoreRead: '<S528>/Data Store Read2' */
  VDHP_ChrgFaultInstFlt_flg = VCHRG_ChrgFault_flg;

  /* DataStoreRead: '<S528>/Data Store Read25' */
  DHP_model_B.DataStoreRead25_i = APPData_Invalid_DFlash_1_2;

  /* DataStoreRead: '<S528>/Data Store Read26' */
  DHP_model_B.DataStoreRead26_g = APPData_Invalid_EEPROM_1_2;

  /* DataStoreRead: '<S528>/Data Store Read27' */
  DHP_model_B.DataStoreRead27_k = APPData_Invalid_DFlash_3;

  /* DataStoreRead: '<S528>/Data Store Read28' */
  DHP_model_B.DataStoreRead28_f = APPData_Invalid_EEPROM_3;

  /* DataStoreRead: '<S528>/Data Store Read29' */
  DHP_model_B.DataStoreRead29_f = APPData_Invalid_DFlash_4;

  /* DataStoreRead: '<S528>/Data Store Read3' */
  VDHP_ChrgModeInvalidInstFlt_flg = VCHRG_ChrgModeInvalid_flg;

  /* DataStoreRead: '<S528>/Data Store Read30' */
  DHP_model_B.DataStoreRead30_j = APPData_Invalid_EEPROM_4;

  /* DataStoreRead: '<S528>/Data Store Read4' */
  VDHP_ChrgModeAbnormalInstFlt_flg = VCHRG_ChrgModeAbnormal_flg;

  /* DataStoreRead: '<S528>/Data Store Read5' */
  VDHP_ChrgLockCheckTOInstFlt_flg = VCHRG_ChrgLockCheckTimeout_flg;

  /* DataStoreRead: '<S528>/Data Store Read6' */
  VDHP_ShiftKnobCheckTOInstFlt_flg = VCHRG_ShiftKnobCheckTimeout_flg;

  /* DataStoreRead: '<S528>/Data Store Read7' */
  VDHP_ChrgStopAbnormalInstFlt_flg = VCHRG_ChrgStopAbnormal_flg;

  /* DataStoreRead: '<S528>/Data Store Read8' */
  VDHP_ChrgStopOperTOInstFlt_flg = VCHRG_ChrgStopOperTimeout_flg;

  /* DataStoreRead: '<S528>/Data Store Read9' */
  VDHP_ChrgStopModeInvalidInstFlt_flg = VCHRG_ChrgStopModeInvalid_flg;

  /* Outputs for Enabled SubSystem: '<S536>/GearSignal_CS' incorporates:
   *  EnablePort: '<S572>/Enable'
   */
  /* Logic: '<S536>/Logical Operator' incorporates:
   *  Constant: '<S576>/Constant'
   *  Constant: '<S577>/Constant'
   *  Constant: '<S578>/Constant'
   *  Inport: '<Root>/Config'
   *  Logic: '<S572>/Logical Operator'
   *  RelationalOperator: '<S576>/Compare'
   *  RelationalOperator: '<S577>/Compare'
   *  RelationalOperator: '<S578>/Compare'
   */
  if (!Config_output.C_YK19_En) {
    /* Outputs for Enabled SubSystem: '<S572>/GearSingleNotAeraK11' incorporates:
     *  EnablePort: '<S574>/Enable'
     */
    if (Config_output.C_CS_En == 2) {
      /* Sum: '<S574>/Add' incorporates:
       *  DataTypeConversion: '<S574>/Data Type Conversion'
       *  DataTypeConversion: '<S574>/Data Type Conversion1'
       *  DataTypeConversion: '<S574>/Data Type Conversion2'
       *  Product: '<S574>/Product'
       *  Product: '<S574>/Product1'
       *  Product: '<S574>/Product2'
       */
      rtb_Switch = (uint16_T)(((uint32_T)(VDSF_GearSwitch1Active_flg << 3) +
        (VDSF_GearSwitch2Active_flg << 2)) + (VDSF_GearSwitch3Active_flg << 1));

      /* Logic: '<S574>/Logical Operator4' incorporates:
       *  Constant: '<S574>/Constant4'
       *  Constant: '<S574>/Constant5'
       *  Constant: '<S574>/Constant6'
       *  Logic: '<S574>/Logical Operator2'
       *  Logic: '<S574>/Logical Operator3'
       *  RelationalOperator: '<S574>/Relational Operator'
       *  RelationalOperator: '<S574>/Relational Operator1'
       *  RelationalOperator: '<S574>/Relational Operator2'
       */
      DHP_model_B.Merge = ((!((rtb_Switch == KDHP_KGearNeutral_Single) ||
        (rtb_Switch == KDHP_KGearDrange_Single) || (rtb_Switch ==
        KDHP_KGearReverse_Single))) && VDHP_Basc_Auxiliary_Judgment_Condition);
    }

    /* End of Outputs for SubSystem: '<S572>/GearSingleNotAeraK11' */

    /* Outputs for Enabled SubSystem: '<S572>/GearSingleNotAeraS11' incorporates:
     *  EnablePort: '<S575>/Enable'
     */
    if ((Config_output.C_CS_En == 1) || (Config_output.C_CS_En == 3)) {
      /* Sum: '<S575>/Add' incorporates:
       *  DataTypeConversion: '<S575>/Data Type Conversion'
       *  DataTypeConversion: '<S575>/Data Type Conversion1'
       *  DataTypeConversion: '<S575>/Data Type Conversion2'
       *  Product: '<S575>/Product'
       *  Product: '<S575>/Product1'
       */
      rtb_Switch = (uint16_T)(((uint32_T)(VDSF_GearSwitch1Active_flg << 2) +
        (VDSF_GearSwitch3Active_flg << 1)) + VDSF_GearSwitch2Active_flg);

      /* Logic: '<S575>/Logical Operator4' incorporates:
       *  Constant: '<S575>/Constant3'
       *  Constant: '<S575>/Constant4'
       *  Constant: '<S575>/Constant5'
       *  Constant: '<S575>/Constant6'
       *  Constant: '<S575>/Constant7'
       *  Logic: '<S575>/Logical Operator2'
       *  Logic: '<S575>/Logical Operator3'
       *  RelationalOperator: '<S575>/Relational Operator'
       *  RelationalOperator: '<S575>/Relational Operator1'
       *  RelationalOperator: '<S575>/Relational Operator2'
       *  RelationalOperator: '<S575>/Relational Operator3'
       *  RelationalOperator: '<S575>/Relational Operator4'
       */
      DHP_model_B.Merge = ((!((rtb_Switch == KDHP_SGearReverse_Single) ||
        (rtb_Switch == KDHP_SGearRRelease_Single) || (rtb_Switch ==
        KDHP_SGearNeutral_Single) || (rtb_Switch == KDHP_SGearDRelease_Single) ||
        (rtb_Switch == KDHP_SGearDrange_Single))) &&
                           VDHP_Basc_Auxiliary_Judgment_Condition);
    }

    /* End of Outputs for SubSystem: '<S572>/GearSingleNotAeraS11' */
  }

  /* End of Logic: '<S536>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S536>/GearSignal_CS' */

  /* Outputs for Enabled SubSystem: '<S536>/GearSignal_YK19' incorporates:
   *  EnablePort: '<S573>/Enable'
   */
  /* Switch: '<S536>/Switch' incorporates:
   *  Inport: '<Root>/Config'
   */
  if (Config_output.C_YK19_En) {
    /* Sum: '<S573>/Add1' incorporates:
     *  ArithShift: '<S573>/Shift Arithmetic'
     *  ArithShift: '<S573>/Shift Arithmetic1'
     *  ArithShift: '<S573>/Shift Arithmetic2'
     *  DataTypeConversion: '<S573>/Data Type Conversion4'
     *  DataTypeConversion: '<S573>/Data Type Conversion5'
     *  DataTypeConversion: '<S573>/Data Type Conversion6'
     *  DataTypeConversion: '<S573>/Data Type Conversion7'
     */
    rtb_Add1_m = (uint8_T)((((uint32_T)(VDSF_GearSwitch4Active_flg << 3) +
      (VDSF_GearSwitch1Active_flg << 2)) + (VDSF_GearSwitch3Active_flg << 1)) +
      VDSF_GearSwitch2Active_flg);

    /* Logic: '<S573>/Logical Operator4' incorporates:
     *  Constant: '<S579>/Constant'
     *  Constant: '<S580>/Constant'
     *  Constant: '<S581>/Constant'
     *  Constant: '<S582>/Constant'
     *  Constant: '<S583>/Constant'
     *  Constant: '<S584>/Constant'
     *  Constant: '<S585>/Constant'
     *  Logic: '<S573>/Logical Operator1'
     *  Logic: '<S573>/Logical Operator3'
     *  RelationalOperator: '<S579>/Compare'
     *  RelationalOperator: '<S580>/Compare'
     *  RelationalOperator: '<S581>/Compare'
     *  RelationalOperator: '<S582>/Compare'
     *  RelationalOperator: '<S583>/Compare'
     *  RelationalOperator: '<S584>/Compare'
     *  RelationalOperator: '<S585>/Compare'
     */
    DHP_model_B.LogicalOperator4_m = ((!((rtb_Add1_m == ((uint8_T)
      ENUM_GEARN_YK19)) || (rtb_Add1_m == ((uint8_T)ENUM_GEARR_YK19)) ||
      (rtb_Add1_m == ((uint8_T)ENUM_GEARD1_YK19)) || (rtb_Add1_m == ((uint8_T)
      ENUM_GEARD2_YK19)) || (rtb_Add1_m == ((uint8_T)ENUM_GEARD3_YK19)) ||
      (rtb_Add1_m == ((uint8_T)ENUM_GEARD4_YK19)) || (rtb_Add1_m == ((uint8_T)
      ENUM_GEARD5_YK19)))) && VDHP_Basc_Auxiliary_Judgment_Condition);
    VDHP_GearSingleNotInAeraInstFlt_flg = DHP_model_B.LogicalOperator4_m;
  } else {
    VDHP_GearSingleNotInAeraInstFlt_flg = DHP_model_B.Merge;
  }

  /* End of Switch: '<S536>/Switch' */
  /* End of Outputs for SubSystem: '<S536>/GearSignal_YK19' */

  /* Outputs for Enabled SubSystem: '<S528>/MechanicalKey_Z18' incorporates:
   *  EnablePort: '<S537>/Enable'
   */
  /* RelationalOperator: '<S534>/Compare' incorporates:
   *  Constant: '<S534>/Constant'
   *  Constant: '<S537>/Constant17'
   *  Inport: '<Root>/Config'
   *  Logic: '<S537>/Logical Operator1'
   *  Logic: '<S537>/Logical Operator8'
   */
  if (Config_output.C_PMSC_En == 2) {
    /* Outputs for Atomic SubSystem: '<S537>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer((!DHP_model_B.VHALI_SSB_Switch_1) &&
      DHP_model_B.VHALI_SSB_Switch_2, VDHP_deltaSystemTick_ms,
      KDHP_ACCHWSignalAbnormal_ms, &DHP_model_DW.DHP_systemtick_Timer);

    /* End of Outputs for SubSystem: '<S537>/DHP_systemtick_Timer' */
  }

  /* End of RelationalOperator: '<S534>/Compare' */
  /* End of Outputs for SubSystem: '<S528>/MechanicalKey_Z18' */

  /* Logic: '<S587>/Logical Operator1' */
  VDHP_HVPwrUpTimeoutInstFlt_flg = (DHP_model_B.VPMM_LVUpTimeout_flg ||
    VDHP_HVUpTOInstFlt_flg || VDHP_HVActiveTOInstFlt_flg ||
    VDHP_MCUHVActiveTOInstFlt_flg || VDHP_HVDCDCActiveTOInstFlt_flg);

  /* RelationalOperator: '<S590>/Compare' incorporates:
   *  Constant: '<S590>/Constant'
   */
  VDHP_ChrgReqLimFacInstFlt_flg = (DHP_model_B.TMM_VCUChrgReqLimFac_enum == 3);

  /* Logic: '<S588>/Logical Operator' incorporates:
   *  Constant: '<S588>/Constant13'
   *  Constant: '<S589>/Constant'
   *  DataStoreRead: '<S528>/Data Store Read24'
   *  RelationalOperator: '<S589>/Compare'
   */
  DHP_model_B.LogicalOperator_hq = (VCHRG_OBCSleepTimeout_flg && (Vehicle_Type
    != ((uint8_T)Z18_MARK)));

  /* Logic: '<S591>/Logical Operator' incorporates:
   *  DataStoreRead: '<S591>/Data Store Read'
   */
  rtb_Switch_o0 = !bool_udsAgingTestStart_flag;

  /* Outputs for Enabled SubSystem: '<S591>/TestMode' incorporates:
   *  EnablePort: '<S594>/Enable'
   */
  /* DataStoreRead: '<S591>/Data Store Read1' incorporates:
   *  Constant: '<S594>/Constant4'
   */
  if (bool_udsAgingTestStart_flag) {
    if (!DHP_model_DW.TestMode_MODE) {
      DHP_model_DW.TestMode_MODE = true;
    }

    /* Logic: '<S594>/Logical Operator' incorporates:
     *  DataStoreRead: '<S591>/Data Store Read2'
     *  DataTypeConversion: '<S654>/Extract Desired Bits'
     *  RelationalOperator: '<S643>/Compare'
     */
    DHP_model_B.LogicalOperator_hz = (VDHP_TestWorkDelay4s_Flg && (((int32_T)
      ((uint32_T)LSChip7240BFaultStatus >> 8) & 3) != 0));

    /* Logic: '<S594>/Logical Operator1' incorporates:
     *  DataStoreRead: '<S591>/Data Store Read2'
     *  DataTypeConversion: '<S655>/Extract Desired Bits'
     *  RelationalOperator: '<S647>/Compare'
     */
    DHP_model_B.LogicalOperator1_p = (VDHP_TestWorkDelay4s_Flg && (((int32_T)
      ((uint32_T)LSChip7240BFaultStatus >> 10) & 3) != 0));

    /* Logic: '<S594>/Logical Operator2' incorporates:
     *  DataStoreRead: '<S591>/Data Store Read2'
     *  DataTypeConversion: '<S657>/Extract Desired Bits'
     *  RelationalOperator: '<S648>/Compare'
     */
    DHP_model_B.LogicalOperator2_e = (VDHP_TestWorkDelay4s_Flg && ((int32_T)
      ((uint32_T)LSChip7240BFaultStatus >> 14) != 0));

    /* Logic: '<S594>/Logical Operator3' incorporates:
     *  DataStoreRead: '<S591>/Data Store Read2'
     *  DataTypeConversion: '<S656>/Extract Desired Bits'
     *  RelationalOperator: '<S649>/Compare'
     */
    DHP_model_B.LogicalOperator3_a = (VDHP_TestWorkDelay4s_Flg && (((int32_T)
      ((uint32_T)LSChip7240BFaultStatus >> 12) & 3) != 0));

    /* Logic: '<S594>/Logical Operator4' incorporates:
     *  DataStoreRead: '<S591>/Data Store Read2'
     *  DataTypeConversion: '<S650>/Extract Desired Bits'
     *  RelationalOperator: '<S644>/Compare'
     */
    DHP_model_B.LogicalOperator4_k = (VDHP_TestWorkDelay4s_Flg && (((uint8_T)
      LSChip7240BFaultStatus & 3) != 0));

    /* Logic: '<S594>/Logical Operator5' incorporates:
     *  DataStoreRead: '<S591>/Data Store Read2'
     *  DataTypeConversion: '<S653>/Extract Desired Bits'
     *  RelationalOperator: '<S645>/Compare'
     */
    DHP_model_B.LogicalOperator5_n = (VDHP_TestWorkDelay4s_Flg && (((uint8_T)
      ((uint32_T)LSChip7240BFaultStatus >> 6) & 3) != 0));

    /* Logic: '<S594>/Logical Operator6' incorporates:
     *  DataStoreRead: '<S591>/Data Store Read2'
     *  DataTypeConversion: '<S652>/Extract Desired Bits'
     *  RelationalOperator: '<S646>/Compare'
     */
    DHP_model_B.LogicalOperator6 = (VDHP_TestWorkDelay4s_Flg && (((uint8_T)
      ((uint32_T)LSChip7240BFaultStatus >> 4) & 3) != 0));

    /* Logic: '<S594>/Logical Operator7' incorporates:
     *  DataStoreRead: '<S591>/Data Store Read3'
     *  DataTypeConversion: '<S651>/Extract Desired Bits'
     *  RelationalOperator: '<S642>/Compare'
     */
    DHP_model_B.LogicalOperator7_g = (VDHP_TestWorkDelay4s_Flg &&
      ((HSChip5180BFaultStatus & 3) != 0));
    DHP_model_B.Constant4 = false;
  } else {
    if (DHP_model_DW.TestMode_MODE) {
      /* Disable for Outport: '<S594>/VCUHwHS1ErrInstFlt_flg' */
      DHP_model_B.LogicalOperator7_g = false;
      DHP_model_DW.TestMode_MODE = false;
    }
  }

  /* End of DataStoreRead: '<S591>/Data Store Read1' */
  /* End of Outputs for SubSystem: '<S591>/TestMode' */

  /* Outputs for Enabled SubSystem: '<S591>/NormalMode' incorporates:
   *  EnablePort: '<S593>/Enable'
   */
  /* Switch: '<S591>/Switch' incorporates:
   *  Constant: '<S607>/Constant'
   *  Constant: '<S608>/Constant'
   *  Inport: '<Root>/Config'
   *  Logic: '<S600>/Logical Operator'
   *  RelationalOperator: '<S607>/Compare'
   *  RelationalOperator: '<S608>/Compare'
   *  Switch: '<S591>/Switch1'
   *  Switch: '<S591>/Switch2'
   *  Switch: '<S591>/Switch3'
   *  Switch: '<S591>/Switch4'
   *  Switch: '<S591>/Switch5'
   *  Switch: '<S591>/Switch6'
   *  Switch: '<S591>/Switch7'
   *  Switch: '<S591>/Switch8'
   */
  if (rtb_Switch_o0) {
    /* DataStoreRead: '<S599>/Data Store Read' */
    VDHP_HSFaultCode_PwrOn = hIOP_HSFaultCode_enum_POR;

    /* DataTypeConversion: '<S605>/Extract Desired Bits' */
    rtb_Add1_m = (uint8_T)(DHP_model_B.VHALI_HSFaultCode_enum & 3);

    /* Logic: '<S599>/Logical Operator3' incorporates:
     *  Constant: '<S593>/Constant5'
     *  Constant: '<S595>/Constant'
     *  Constant: '<S596>/Constant'
     *  Constant: '<S597>/Constant'
     *  Constant: '<S598>/Constant'
     *  Logic: '<S593>/Logical Operator3'
     *  RelationalOperator: '<S595>/Compare'
     *  RelationalOperator: '<S596>/Compare'
     *  RelationalOperator: '<S597>/Compare'
     *  RelationalOperator: '<S598>/Compare'
     */
    rtb_RelationalOperator1_hc = ((Vehicle_Type != K11_Mark) && (Vehicle_Type !=
      K11P01_Mark) && (Vehicle_Type != K11E01R_Mark) && (Vehicle_Type !=
      K11P06_Mark) && VDHP_VCUPowerUpDelay2SWork_Flg);

    /* Switch: '<S599>/Switch' incorporates:
     *  Constant: '<S599>/Constant'
     *  Constant: '<S599>/Constant1'
     *  Constant: '<S599>/Constant3'
     *  DataTypeConversion: '<S604>/Extract Desired Bits'
     *  Switch: '<S599>/Switch1'
     */
    if (KDHP_HS1FaultOpenLoad_Valid) {
      tmp = (uint8_T)(VDHP_HSFaultCode_PwrOn & 3);
      tmp_0 = rtb_Add1_m;
    } else {
      tmp = 0U;
      tmp_0 = 0U;
    }

    /* End of Switch: '<S599>/Switch' */

    /* Logic: '<S599>/Logical Operator10' incorporates:
     *  Constant: '<S601>/Constant'
     *  Constant: '<S602>/Constant'
     *  Logic: '<S599>/Logical Operator1'
     *  Logic: '<S599>/Logical Operator2'
     *  Logic: '<S599>/Logical Operator9'
     *  RelationalOperator: '<S601>/Compare'
     *  RelationalOperator: '<S602>/Compare'
     *  RelationalOperator: '<S603>/Compare'
     */
    DHP_model_B.LogicalOperator10_h = (((tmp == 1) && rtb_RelationalOperator1_hc)
      || (rtb_RelationalOperator1_hc && ((rtb_Add1_m == 2) || (tmp_0 == 1))));

    /* DataStoreRead: '<S600>/Data Store Read' */
    VDHP_LS1to10FaultCode_PwrOn = hIOP_LSFaultCode_enum_POR;

    /* DataTypeConversion: '<S627>/Extract Desired Bits' */
    rtb_Add1_m = (uint8_T)((uint8_T)(VDHP_LS1to10FaultCode_PwrOn >> 14) & 3);

    /* RelationalOperator: '<S615>/Compare' incorporates:
     *  Constant: '<S600>/Constant4'
     *  Constant: '<S615>/Constant'
     */
    rtb_RelationalOperator1_hc = (Vehicle_Type != ((uint8_T)Z18_MARK));

    /* Logic: '<S600>/Logical Operator13' incorporates:
     *  DataTypeConversion: '<S620>/Extract Desired Bits'
     *  RelationalOperator: '<S616>/Compare'
     */
    DHP_model_B.LogicalOperator13_l = ((((uint8_T)(VDHP_LS1to10FaultCode >> 2) &
      3) == 3) && VDHP_HVPowerUpDelay2SWork_Flg && rtb_RelationalOperator1_hc);

    /* Logic: '<S600>/Logical Operator16' incorporates:
     *  DataTypeConversion: '<S621>/Extract Desired Bits'
     *  RelationalOperator: '<S617>/Compare'
     */
    DHP_model_B.LogicalOperator16 = ((((uint8_T)(VDHP_LS1to10FaultCode >> 4) & 3)
      == 3) && VDHP_HVPowerUpDelay2SWork_Flg && rtb_RelationalOperator1_hc);

    /* Logic: '<S600>/Logical Operator19' incorporates:
     *  DataTypeConversion: '<S622>/Extract Desired Bits'
     *  RelationalOperator: '<S618>/Compare'
     */
    DHP_model_B.LogicalOperator19 = ((((uint8_T)(VDHP_LS1to10FaultCode >> 6) & 3)
      == 3) && VDHP_HVPowerUpDelay2SWork_Flg && rtb_RelationalOperator1_hc);

    /* Logic: '<S600>/Logical Operator22' incorporates:
     *  DataTypeConversion: '<S623>/Extract Desired Bits'
     *  RelationalOperator: '<S609>/Compare'
     */
    DHP_model_B.LogicalOperator22 = ((((uint8_T)(VDHP_LS1to10FaultCode >> 8) & 3)
      == 3) && VDHP_VCUPowerUpDelay2SWork_Flg && rtb_RelationalOperator1_hc);

    /* Logic: '<S600>/Logical Operator25' incorporates:
     *  DataTypeConversion: '<S624>/Extract Desired Bits'
     *  RelationalOperator: '<S610>/Compare'
     */
    DHP_model_B.LogicalOperator25 = ((((uint8_T)(VDHP_LS1to10FaultCode >> 10) &
      3) == 3) && VDHP_HVPowerUpDelay2SWork_Flg);

    /* Logic: '<S600>/Logical Operator28' incorporates:
     *  DataTypeConversion: '<S625>/Extract Desired Bits'
     *  RelationalOperator: '<S611>/Compare'
     */
    DHP_model_B.LogicalOperator28 = ((((uint8_T)(VDHP_LS1to10FaultCode >> 12) &
      3) == 3) && VDHP_HVPowerUpDelay2SWork_Flg && rtb_RelationalOperator1_hc);

    /* Logic: '<S600>/Logical Operator30' incorporates:
     *  DataTypeConversion: '<S626>/Extract Desired Bits'
     *  Logic: '<S600>/Logical Operator31'
     *  Logic: '<S600>/Logical Operator32'
     *  Logic: '<S600>/Logical Operator8'
     *  RelationalOperator: '<S612>/Compare'
     *  RelationalOperator: '<S613>/Compare'
     *  RelationalOperator: '<S614>/Compare'
     */
    DHP_model_B.LogicalOperator30 = (((((uint8_T)(VDHP_LS1to10FaultCode >> 14) &
      3) == 3) && VDHP_VCUPowerUpDelay2SWork_Flg) ||
      (VDHP_VCUPowerUpDelay2SWork_Flg && ((rtb_Add1_m == 1) || (rtb_Add1_m == 2))));

    /* Logic: '<S600>/Logical Operator9' incorporates:
     *  DataTypeConversion: '<S619>/Extract Desired Bits'
     *  RelationalOperator: '<S606>/Compare'
     */
    DHP_model_B.LogicalOperator9 = ((((uint8_T)VDHP_LS1to10FaultCode & 3) == 3) &&
      VDHP_VCUPowerUpDelay2SWork_Flg && rtb_RelationalOperator1_hc);

    /* Outputs for Enabled SubSystem: '<S600>/Subsystem' incorporates:
     *  EnablePort: '<S628>/Enable'
     */
    if ((Config_output.C_PMS_En == 1) || (Config_output.C_PMS_En == 2)) {
      /* DataTypeConversion: '<S637>/Extract Desired Bits' */
      rtb_Add1_m = (uint8_T)((uint8_T)(VDHP_LS1to10FaultCode_PwrOn >> 16) & 3);

      /* RelationalOperator: '<S632>/Compare' */
      rtb_u = (rtb_Add1_m == 1);

      /* RelationalOperator: '<S633>/Compare' */
      rtb_RelationalOperator1_hc = (rtb_Add1_m == 2);

      /* DataTypeConversion: '<S638>/Extract Desired Bits' */
      rtb_Add1_m = (uint8_T)((uint8_T)(VDHP_LS1to10FaultCode_PwrOn >> 18) & 3);

      /* Logic: '<S628>/Logical Operator1' incorporates:
       *  DataTypeConversion: '<S641>/Extract Desired Bits'
       *  Logic: '<S628>/Logical Operator2'
       *  Logic: '<S628>/Logical Operator3'
       *  Logic: '<S628>/Logical Operator4'
       *  RelationalOperator: '<S629>/Compare'
       */
      VDHP_VCUHwLSIGN1InstFlt_flg = (((((uint8_T)(VDHP_LS1to10FaultCode >> 16) &
        3) == 3) && VDHP_VCUPowerUpDelay2SWork_Flg) ||
        (VDHP_VCUPowerUpDelay2SWork_Flg && (rtb_u || rtb_RelationalOperator1_hc)));

      /* Logic: '<S628>/Logical Operator17' incorporates:
       *  Constant: '<S630>/Constant'
       *  DataTypeConversion: '<S640>/Extract Desired Bits'
       *  Logic: '<S628>/Logical Operator12'
       *  RelationalOperator: '<S630>/Compare'
       *  RelationalOperator: '<S631>/Compare'
       */
      VDHP_VCUHWLSEsclPwrInstFlt_flg = (VDHP_VCUPowerUpDelay2SWork_Flg &&
        (Config_output.C_ESCL_En == 1) && (((uint8_T)(VDHP_LS1to10FaultCode >>
        20) & 3) == 3));

      /* Logic: '<S628>/Logical Operator5' incorporates:
       *  DataTypeConversion: '<S639>/Extract Desired Bits'
       *  Logic: '<S628>/Logical Operator10'
       *  Logic: '<S628>/Logical Operator6'
       *  Logic: '<S628>/Logical Operator7'
       *  RelationalOperator: '<S634>/Compare'
       *  RelationalOperator: '<S635>/Compare'
       *  RelationalOperator: '<S636>/Compare'
       */
      VDHP_VCUHwLSIGN2InstFlt_flg = (((((uint8_T)(VDHP_LS1to10FaultCode >> 18) &
        3) == 3) && VDHP_VCUPowerUpDelay2SWork_Flg) ||
        (VDHP_VCUPowerUpDelay2SWork_Flg && ((rtb_Add1_m == 1) || (rtb_Add1_m ==
        2))));
    }

    /* End of Outputs for SubSystem: '<S600>/Subsystem' */
    VDHP_VCUHwLS1ErrInstFlt_flg = DHP_model_B.LogicalOperator9;
    VDHP_VCUHwLS2ErrInstFlt_flg = DHP_model_B.LogicalOperator13_l;
    VDHP_VCUHwLS3ErrInstFlt_flg = DHP_model_B.LogicalOperator16;
    VDHP_VCUHwLS4ErrInstFlt_flg = DHP_model_B.LogicalOperator19;
    VDHP_VCUHwLS5ErrInstFlt_flg = DHP_model_B.LogicalOperator22;
    VDHP_VCUHwLS6ErrInstFlt_flg = DHP_model_B.LogicalOperator25;
    VDHP_VCUHwLS7ErrInstFlt_flg = DHP_model_B.LogicalOperator28;
    VDHP_VCUHwLS8ErrInstFlt_flg = DHP_model_B.LogicalOperator30;
    VDHP_VCUHwHS1ErrInstFlt_flg = DHP_model_B.LogicalOperator10_h;
  } else {
    VDHP_VCUHwLS1ErrInstFlt_flg = DHP_model_B.LogicalOperator_hz;
    VDHP_VCUHwLS2ErrInstFlt_flg = DHP_model_B.LogicalOperator1_p;
    VDHP_VCUHwLS3ErrInstFlt_flg = DHP_model_B.LogicalOperator2_e;
    VDHP_VCUHwLS4ErrInstFlt_flg = DHP_model_B.LogicalOperator3_a;
    VDHP_VCUHwLS5ErrInstFlt_flg = DHP_model_B.Constant4;
    VDHP_VCUHwLS6ErrInstFlt_flg = DHP_model_B.LogicalOperator4_k;
    VDHP_VCUHwLS7ErrInstFlt_flg = DHP_model_B.LogicalOperator5_n;
    VDHP_VCUHwLS8ErrInstFlt_flg = DHP_model_B.LogicalOperator6;
    VDHP_VCUHwHS1ErrInstFlt_flg = DHP_model_B.LogicalOperator7_g;
  }

  /* End of Switch: '<S591>/Switch' */
  /* End of Outputs for SubSystem: '<S591>/NormalMode' */

  /* RelationalOperator: '<S661>/Compare' incorporates:
   *  Constant: '<S661>/Constant'
   *  DataStoreRead: '<S528>/Data Store Read12'
   */
  VDHP_DidDataCheckFailedInstFlt_flg = (gbDidDataCorrect == 0);

  /* RelationalOperator: '<S662>/Compare' incorporates:
   *  Constant: '<S662>/Constant'
   *  DataStoreRead: '<S528>/Data Store Read15'
   */
  VDHP_CalDataCheckFailedInstFlt_flg = (gbCalDataCorrect == 0);

  /* Outputs for Enabled SubSystem: '<S592>/CruiseKeyFault' incorporates:
   *  EnablePort: '<S663>/Enable'
   */
  /* RelationalOperator: '<S658>/Compare' incorporates:
   *  Constant: '<S658>/Constant'
   *  Constant: '<S663>/Constant1'
   *  Constant: '<S663>/Constant2'
   *  Constant: '<S666>/Constant'
   *  Constant: '<S667>/Constant'
   *  DataStoreRead: '<S592>/Data Store Read'
   *  DataStoreRead: '<S592>/Data Store Read2'
   *  Inport: '<Root>/Config'
   *  RelationalOperator: '<S666>/Compare'
   *  RelationalOperator: '<S667>/Compare'
   */
  if (Config_output.C_CC_En != 0) {
    /* RelationalOperator: '<S664>/Compare' incorporates:
     *  Constant: '<S664>/Constant'
     *  DataStoreRead: '<S528>/Data Store Read16'
     */
    DHP_model_B.Compare_pp = (CruiseKeyFaultCode == 1);

    /* RelationalOperator: '<S665>/Compare' incorporates:
     *  Constant: '<S665>/Constant'
     *  DataStoreRead: '<S528>/Data Store Read16'
     */
    VDHP_CruiseKeyShortedInstFlt_flg = (CruiseKeyFaultCode == 2);

    /* Outputs for Atomic SubSystem: '<S663>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_p(VINP_CruiseKeySet_flg == 1,
      VDHP_deltaSystemTick_ms, KDHP_CruiseKeyJam_ms,
      &DHP_model_DW.DHP_systemtick_Timer_p);

    /* End of Outputs for SubSystem: '<S663>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S663>/DHP_systemtick_Timer1' */
    DHP_model_DHP_systemtick_Timer1(VINP_CruiseKeyRes_flg == 1,
      VDHP_deltaSystemTick_ms, KDHP_CruiseKeyJam_ms,
      &DHP_model_DW.DHP_systemtick_Timer1);

    /* End of Outputs for SubSystem: '<S663>/DHP_systemtick_Timer1' */
  }

  /* End of RelationalOperator: '<S658>/Compare' */
  /* End of Outputs for SubSystem: '<S592>/CruiseKeyFault' */

  /* Switch: '<S592>/Switch' incorporates:
   *  Constant: '<S660>/Constant'
   *  DataStoreRead: '<S528>/Data Store Read16'
   *  DataStoreRead: '<S592>/Data Store Read1'
   *  Logic: '<S592>/Logical Operator'
   *  RelationalOperator: '<S660>/Compare'
   */
  if (bool_udsAgingTestStart_flag) {
    VDHP_CruiseKeyOpenInstFlt_flg = ((CruiseKeyFaultCode == 1) &&
      VDHP_TestWorkDelay4s_Flg);
  } else {
    VDHP_CruiseKeyOpenInstFlt_flg = DHP_model_B.Compare_pp;
  }

  /* End of Switch: '<S592>/Switch' */

  /* RelationalOperator: '<S659>/Compare' incorporates:
   *  Constant: '<S659>/Constant'
   *  DataStoreRead: '<S528>/Data Store Read19'
   */
  VDHP_gbInvalidWriteToCalAreaInstFlt_flg = (gbInvalidWriteToCalArea == 1);

  /* RelationalOperator: '<S557>/Compare' incorporates:
   *  Constant: '<S557>/Constant'
   *  DataStoreRead: '<S528>/Data Store Read21'
   */
  VDHP_IGN1FeedVErrInstFlt_flg = (IGN1_FeedVoltCorrect == 0);

  /* RelationalOperator: '<S558>/Compare' incorporates:
   *  Constant: '<S558>/Constant'
   *  DataStoreRead: '<S528>/Data Store Read22'
   */
  VDHP_IGN2FeedVErrInstFlt_flg = (IGN2_FeedVoltCorrect == 0);

  /* RelationalOperator: '<S559>/Compare' incorporates:
   *  Constant: '<S559>/Constant'
   *  DataStoreRead: '<S528>/Data Store Read23'
   */
  VDHP_SSBSyncErrInstFlt_flg = (SSB_SyncCorrect == 0);

  /* MultiPortSwitch: '<S670>/Multiport Switch1' incorporates:
   *  Constant: '<S670>/Constant4'
   *  Constant: '<S672>/Constant'
   *  Constant: '<S678>/Constant'
   *  Constant: '<S685>/Constant'
   *  Constant: '<S686>/Constant'
   *  Inport: '<Root>/TQM'
   *  Logic: '<S670>/Logical Operator10'
   *  Logic: '<S670>/Logical Operator11'
   *  RelationalOperator: '<S672>/Compare'
   *  RelationalOperator: '<S678>/Compare'
   *  RelationalOperator: '<S685>/Compare'
   *  RelationalOperator: '<S686>/Compare'
   */
  switch (TQM_output.TQM_GearDisp) {
   case 4:
    rtb_Switch_o0 = ((TQM_output.TQM_VehTq < 0.0F) && (TQM_output.TQM_VehTq <
      KDHP_GearDRegenTq_Nm));
    break;

   case 2:
    rtb_Switch_o0 = ((TQM_output.TQM_VehTq > 0.0F) && (TQM_output.TQM_VehTq >
      KDHP_GearRRegenTq_Nm));
    break;

   default:
    rtb_Switch_o0 = false;
    break;
  }

  /* End of MultiPortSwitch: '<S670>/Multiport Switch1' */

  /* Switch: '<S670>/Switch1' incorporates:
   *  Constant: '<S670>/Constant'
   *  Constant: '<S670>/Constant1'
   *  Constant: '<S670>/Constant2'
   *  Constant: '<S670>/Constant3'
   *  Constant: '<S671>/Constant'
   *  Constant: '<S673>/Constant'
   *  Constant: '<S674>/Constant'
   *  Constant: '<S675>/Constant'
   *  Constant: '<S676>/Constant'
   *  Constant: '<S677>/Constant'
   *  Constant: '<S679>/Constant'
   *  Constant: '<S680>/Constant'
   *  Constant: '<S681>/Constant'
   *  Constant: '<S682>/Constant'
   *  Constant: '<S683>/Constant'
   *  Constant: '<S684>/Constant'
   *  Gain: '<S670>/Gain1'
   *  Gain: '<S670>/Gain2'
   *  Gain: '<S670>/Gain3'
   *  Gain: '<S670>/Gain9'
   *  Inport: '<Root>/TQM'
   *  Logic: '<S670>/Logical Operator1'
   *  Logic: '<S670>/Logical Operator2'
   *  Logic: '<S670>/Logical Operator3'
   *  Logic: '<S670>/Logical Operator4'
   *  Logic: '<S670>/Logical Operator5'
   *  Logic: '<S670>/Logical Operator6'
   *  Logic: '<S670>/Logical Operator7'
   *  Logic: '<S670>/Logical Operator8'
   *  Logic: '<S670>/Logical Operator9'
   *  RelationalOperator: '<S670>/Relational Operator'
   *  RelationalOperator: '<S670>/Relational Operator1'
   *  RelationalOperator: '<S670>/Relational Operator2'
   *  RelationalOperator: '<S670>/Relational Operator3'
   *  RelationalOperator: '<S671>/Compare'
   *  RelationalOperator: '<S673>/Compare'
   *  RelationalOperator: '<S674>/Compare'
   *  RelationalOperator: '<S675>/Compare'
   *  RelationalOperator: '<S676>/Compare'
   *  RelationalOperator: '<S677>/Compare'
   *  RelationalOperator: '<S679>/Compare'
   *  RelationalOperator: '<S680>/Compare'
   *  RelationalOperator: '<S681>/Compare'
   *  RelationalOperator: '<S682>/Compare'
   *  RelationalOperator: '<S683>/Compare'
   *  RelationalOperator: '<S684>/Compare'
   */
  if (DHP_model_B.VINP_BrkLightSwitchActive_flg) {
    VDHP_VCURegenAbnormal_flg = (rtb_Switch_o0 && (((DHP_model_B.Gain9 <
      (int32_T)(10U * FDT_Regen_Spd_Off)) && (TQM_output.TQM_WorkMode == 14)) ||
      (TQM_output.TQM_WorkMode != 14)));
  } else {
    VDHP_VCURegenAbnormal_flg = (rtb_Switch_o0 && ((TQM_output.TQM_WorkMode == 0)
      || (TQM_output.TQM_WorkMode == 1) || (TQM_output.TQM_WorkMode == 2) ||
      (TQM_output.TQM_WorkMode == 5) || (TQM_output.TQM_WorkMode == 12) ||
      (TQM_output.TQM_WorkMode == 13) || (TQM_output.TQM_WorkMode == 16) ||
      ((DHP_model_B.Gain9 < (uint16_T)(5U * KCRS_CruiseMinSpd >> 9)) &&
       (TQM_output.TQM_WorkMode == 9)) || ((DHP_model_B.Gain9 < (int32_T)(10U *
      KHDC_GearDSpdLower_KPH)) && (TQM_output.TQM_WorkMode == 10)) ||
      ((DHP_model_B.Gain9 < (int32_T)(10U * FDT_Regen_Spd_Off)) &&
       (TQM_output.TQM_WorkMode == 15))));
  }

  /* End of Switch: '<S670>/Switch1' */
}

/* Output and update for atomic system: '<S12>/VcuControlDevice2InstErrGenerate' */
void DHP_model_VcuControlDevice2InstErrGenerate(void)
{
  boolean_T rtb_LogicalOperator19_po;
  boolean_T rtb_Compare_kvm;
  uint16_T rtb_DataTypeConversion_m;
  boolean_T rtb_TMS3;
  boolean_T rtb_LogicalOperator3_py;
  boolean_T rtb_Switch1;
  boolean_T rtb_LogicalOperator19;
  boolean_T rtb_FixPtLogicalOperator_a;
  boolean_T rtb_LogicalOperator6_bor;
  boolean_T rtb_Switch4;
  uint8_T rtb_LogicalOperator19_0;

  /* Logic: '<S687>/Logical Operator19' incorporates:
   *  Constant: '<S697>/Constant'
   *  Logic: '<S687>/Logical Operator12'
   *  Logic: '<S687>/Logical Operator20'
   *  RelationalOperator: '<S697>/Compare'
   */
  rtb_LogicalOperator19_po =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
     ||
     (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
      && ((DHP_model_B.VINP_BMSChrgMod_enum != 0) ||
          DHP_model_B.VINP_SlowChargeAwakeActive_flg ||
          DHP_model_B.VINP_FastChargeAwakeActiveIn_flg)));

  /* Outputs for Atomic SubSystem: '<S689>/DHP_systemtick_Timer' */

  /* Logic: '<S689>/Logical Operator' incorporates:
   *  Constant: '<S689>/1s'
   *  Delay: '<S689>/Delay2'
   *  RelationalOperator: '<S689>/Relational Operator2'
   */
  DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19_po &&
    (DHP_model_B.DataStoreRead17 == DHP_model_DW.Delay2_DSTATE_p),
    VDHP_deltaSystemTick_ms, 1020U, &DHP_model_B.DHP_systemtick_Timer_c,
    &DHP_model_DW.DHP_systemtick_Timer_c);

  /* End of Outputs for SubSystem: '<S689>/DHP_systemtick_Timer' */

  /* Outputs for Atomic SubSystem: '<S696>/DHP_systemtick_Timer' */

  /* Logic: '<S692>/FixPt Logical Operator' incorporates:
   *  Constant: '<S687>/Constant2'
   *  Constant: '<S687>/Constant3'
   *  Constant: '<S696>/1.5s'
   *  RelationalOperator: '<S692>/Lower Test'
   *  RelationalOperator: '<S692>/Upper Test'
   */
  DHP_model_DHP_systemtick_Timer_c((((uint16_T)DHP_DIAGENABLE_VOLTDOWN) <=
    DHP_model_B.Gain1) && (DHP_model_B.Gain1 <= ((uint16_T)DHP_DIAGENABLE_VOLTUP)),
    VDHP_deltaSystemTick_ms, 1500U, &DHP_model_B.DHP_systemtick_Timer_n,
    &DHP_model_DW.DHP_systemtick_Timer_n);

  /* End of Outputs for SubSystem: '<S696>/DHP_systemtick_Timer' */

  /* Logic: '<S689>/Logical Operator5' */
  VDHP_PTCanLossInstFlt_Flg =
    (DHP_model_B.DHP_systemtick_Timer_n.RelationalOperator &&
     DHP_model_B.DHP_systemtick_Timer_c.RelationalOperator);

  /* Logic: '<S689>/Logical Operator8' */
  DHP_model_B.LogicalOperator8_n =
    !DHP_model_B.DHP_systemtick_Timer_c.RelationalOperator;

  /* RelationalOperator: '<S690>/Compare' incorporates:
   *  Constant: '<S690>/Constant'
   *  DataStoreRead: '<S687>/Data Store Read20'
   */
  rtb_Compare_kvm = (CAN3_BusOffState == 0);

  /* Logic: '<S691>/Logical Operator' incorporates:
   *  Constant: '<S691>/Constant2'
   *  RelationalOperator: '<S691>/Relational Operator1'
   */
  VDHP_OverDiagnVoltInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_n5.RelationalOperator
     && (DHP_model_B.Gain1 > ((uint16_T)DHP_DIAGENABLE_VOLTUP)));

  /* Logic: '<S691>/Logical Operator1' incorporates:
   *  Constant: '<S691>/Constant3'
   *  RelationalOperator: '<S691>/Relational Operator2'
   */
  VDHP_UnderDiagnVoltInstFlt_Flg = ((DHP_model_B.Gain1 < ((uint16_T)
    DHP_DIAGENABLE_VOLTDOWN)) &&
    DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_n5.RelationalOperator);

  /* DataTypeConversion: '<S700>/Data Type Conversion' incorporates:
   *  DataStoreRead: '<S700>/Data Store Read4'
   */
  rtb_DataTypeConversion_m = (uint16_T)hIOP_CollisionSw_Hz;

  /* Outputs for Enabled SubSystem: '<S700>/SRS_InsFlt' incorporates:
   *  EnablePort: '<S703>/Enable'
   */
  /* RelationalOperator: '<S702>/Compare' incorporates:
   *  Constant: '<S702>/Constant'
   *  Constant: '<S703>/300ms*5C'
   *  Constant: '<S703>/Constant'
   *  Constant: '<S703>/Constant2'
   *  Constant: '<S707>/Constant'
   *  Constant: '<S708>/Constant'
   *  Delay: '<S705>/Delay'
   *  Inport: '<Root>/Config'
   *  Logic: '<S703>/Logical Operator26'
   *  Logic: '<S703>/Logical Operator3'
   *  Logic: '<S703>/Logical Operator4'
   *  Logic: '<S705>/Logical Operator1'
   *  RelationalOperator: '<S705>/Relational Operator'
   *  RelationalOperator: '<S707>/Compare'
   *  RelationalOperator: '<S708>/Compare'
   */
  if (Config_output.C_SRS_En == 1) {
    /* Outputs for Enabled SubSystem: '<S703>/CAN_LoseFrame4' incorporates:
     *  EnablePort: '<S705>/Enable'
     */
    if (rtb_Compare_kvm && DHP_model_B.DHP_systemtick_Timer_n.RelationalOperator)
    {
      /* Outputs for Atomic SubSystem: '<S705>/DHP_systemtick_Timer' */
      DHP_model_DHP_systemtick_Timer_c
        (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
         && (DHP_model_B.DataStoreRead55 == DHP_model_DW.Delay_DSTATE_pv),
         VDHP_deltaSystemTick_ms, 1500U, &DHP_model_B.DHP_systemtick_Timer_nm,
         &DHP_model_DW.DHP_systemtick_Timer_nm);

      /* End of Outputs for SubSystem: '<S705>/DHP_systemtick_Timer' */

      /* Update for Delay: '<S705>/Delay' incorporates:
       *  Constant: '<S703>/300ms*5C'
       *  Delay: '<S705>/Delay'
       *  Logic: '<S705>/Logical Operator1'
       *  RelationalOperator: '<S705>/Relational Operator'
       */
      DHP_model_DW.Delay_DSTATE_pv = DHP_model_B.DataStoreRead55;
    }

    /* End of Outputs for SubSystem: '<S703>/CAN_LoseFrame4' */

    /* Logic: '<S711>/FixPt Logical Operator' incorporates:
     *  Constant: '<S703>/300ms*5C'
     *  Constant: '<S703>/'KINP_Debounce_ClutchPdlSwitch_lim'1'
     *  Constant: '<S703>/'KINP_Debounce_ClutchPdlSwitch_lim'2'
     *  Delay: '<S705>/Delay'
     *  Logic: '<S703>/Logical Operator26'
     *  Logic: '<S705>/Logical Operator1'
     *  RelationalOperator: '<S705>/Relational Operator'
     *  RelationalOperator: '<S711>/Lower Test'
     *  RelationalOperator: '<S711>/Upper Test'
     */
    rtb_FixPtLogicalOperator_a = ((6 <= VDSF_CollisionFreIn_Hz) &&
      (VDSF_CollisionFreIn_Hz <= 10));

    /* Logic: '<S712>/FixPt Logical Operator' incorporates:
     *  Constant: '<S703>/'KINP_Debounce_ClutchPdlSwitch_lim'3'
     *  Constant: '<S703>/'KINP_Debounce_ClutchPdlSwitch_lim'4'
     *  RelationalOperator: '<S712>/Lower Test'
     *  RelationalOperator: '<S712>/Upper Test'
     */
    rtb_LogicalOperator6_bor = ((14 <= VDSF_CollisionDutyIn_pct) &&
      (VDSF_CollisionDutyIn_pct <= 18));

    /* Outputs for Atomic SubSystem: '<S703>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_c(rtb_FixPtLogicalOperator_a &&
      rtb_LogicalOperator6_bor, VDHP_deltaSystemTick_ms,
      KDHP_CollisionKeepTime_ms, &DHP_model_B.DHP_systemtick_Timer_j4,
      &DHP_model_DW.DHP_systemtick_Timer_j4);

    /* End of Outputs for SubSystem: '<S703>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S703>/DHP_systemtick_Timer1' */
    DHP_model_DHP_systemtick_Timer_c((VDSF_CollisionFreIn_Hz >= 254) &&
      (VDSF_CollisionDutyIn_pct >= 254), VDHP_deltaSystemTick_ms, 1500U,
      &DHP_model_B.DHP_systemtick_Timer1_c,
      &DHP_model_DW.DHP_systemtick_Timer1_c);

    /* End of Outputs for SubSystem: '<S703>/DHP_systemtick_Timer1' */

    /* Logic: '<S703>/Logical Operator6' incorporates:
     *  Constant: '<S703>/Constant'
     *  Constant: '<S703>/Constant2'
     *  Constant: '<S703>/'KINP_Debounce_ClutchPdlSwitch_lim'5'
     *  Constant: '<S703>/'KINP_Debounce_ClutchPdlSwitch_lim'6'
     *  Constant: '<S707>/Constant'
     *  Constant: '<S708>/Constant'
     *  Logic: '<S703>/Logical Operator3'
     *  Logic: '<S703>/Logical Operator4'
     *  Logic: '<S703>/Logical Operator8'
     *  Logic: '<S703>/Logical Operator9'
     *  Logic: '<S713>/FixPt Logical Operator'
     *  RelationalOperator: '<S707>/Compare'
     *  RelationalOperator: '<S708>/Compare'
     *  RelationalOperator: '<S713>/Lower Test'
     *  RelationalOperator: '<S713>/Upper Test'
     */
    rtb_LogicalOperator6_bor = (((81 <= VDSF_CollisionDutyIn_pct) &&
      (VDSF_CollisionDutyIn_pct <= 85) && rtb_FixPtLogicalOperator_a) ||
      (rtb_FixPtLogicalOperator_a && rtb_LogicalOperator6_bor));

    /* Logic: '<S703>/Logical Operator10' */
    DHP_model_B.LogicalOperator10 =
      (DHP_model_B.DHP_systemtick_Timer1_c.RelationalOperator &&
       DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator);

    /* Logic: '<S703>/Logical Operator11' incorporates:
     *  Logic: '<S703>/Logical Operator1'
     */
    DHP_model_B.LogicalOperator11 = ((!rtb_LogicalOperator6_bor) &&
      DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator);

    /* Logic: '<S703>/Logical Operator12' incorporates:
     *  Constant: '<S706>/Constant'
     *  RelationalOperator: '<S706>/Compare'
     */
    DHP_model_B.LogicalOperator12 = ((DHP_model_B.VHALI_SRS_CrashOutputStatus ==
      1) && VDHP_VCUPowerUpDelay2SWork_Flg);

    /* Logic: '<S703>/Logical Operator13' incorporates:
     *  Logic: '<S703>/Logical Operator14'
     */
    DHP_model_B.LogicalOperator13 =
      ((!DHP_model_B.DHP_systemtick_Timer_nm.RelationalOperator) &&
       DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator);

    /* Logic: '<S703>/Logical Operator2' */
    DHP_model_B.LogicalOperator2_n =
      (DHP_model_B.DHP_systemtick_Timer_j4.RelationalOperator &&
       VDHP_VCUPowerUpDelay2SWork_Flg);

    /* Logic: '<S703>/Logical Operator5' */
    DHP_model_B.LogicalOperator5 =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && rtb_LogicalOperator6_bor);
  }

  /* End of RelationalOperator: '<S702>/Compare' */
  /* End of Outputs for SubSystem: '<S700>/SRS_InsFlt' */

  /* Logic: '<S700>/Logical Operator1' */
  VDHP_VehCrashCanSignalInstFlt_flg =
    (DHP_model_B.DHP_systemtick_Timer_nm.RelationalOperator &&
     DHP_model_B.LogicalOperator5);

  /* Logic: '<S700>/Logical Operator13' */
  VDHP_VehCrashHardwareSignalInstFlt_flg = (DHP_model_B.LogicalOperator13 &&
    DHP_model_B.LogicalOperator11);

  /* Logic: '<S700>/Logical Operator15' */
  VDHP_VehCrashInstFlt_flg = (DHP_model_B.LogicalOperator12 ||
    DHP_model_B.LogicalOperator2_n);

  /* Outputs for Enabled SubSystem: '<S700>/Subsystem' incorporates:
   *  EnablePort: '<S704>/Enable'
   */
  if (VDHP_TestWorkDelay4s_Flg) {
    /* Outputs for Atomic SubSystem: '<S704>/DHP_systemtick_Timer' */

    /* Logic: '<S704>/Logical Operator' incorporates:
     *  Constant: '<S704>/Constant'
     *  Constant: '<S704>/Constant1'
     *  Constant: '<S704>/Constant2'
     *  Constant: '<S704>/Constant3'
     *  Constant: '<S704>/Constant4'
     *  Logic: '<S716>/FixPt Logical Operator'
     *  RelationalOperator: '<S716>/Lower Test'
     *  RelationalOperator: '<S716>/Upper Test'
     *  Sum: '<S704>/Add'
     *  Sum: '<S704>/Add1'
     */
    DHP_model_DHP_systemtick_Timer_c(!(((uint16_T)(KDHP_TestCrashPWM_HZ -
      KDHP_TestPWMHZ_offset) <= rtb_DataTypeConversion_m) &&
      (rtb_DataTypeConversion_m <= (uint16_T)((uint32_T)KDHP_TestCrashPWM_HZ +
      KDHP_TestPWMHZ_offset))), VDHP_deltaSystemTick_ms,
      KDHP_CollisionKeepTime_ms, &DHP_model_B.DHP_systemtick_Timer_o,
      &DHP_model_DW.DHP_systemtick_Timer_o);

    /* End of Outputs for SubSystem: '<S704>/DHP_systemtick_Timer' */
  }

  /* End of Outputs for SubSystem: '<S700>/Subsystem' */

  /* Switch: '<S700>/Switch' incorporates:
   *  DataStoreRead: '<S700>/Data Store Read'
   *  Logic: '<S700>/Logical Operator2'
   *  Logic: '<S700>/Logical Operator7'
   */
  if (!bool_udsAgingTestStart_flag) {
    VDHP_VehCrashHardwareCanSignalInstFlt_flg =
      (DHP_model_B.DHP_systemtick_Timer_nm.RelationalOperator &&
       DHP_model_B.LogicalOperator10);
  } else {
    VDHP_VehCrashHardwareCanSignalInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_o.RelationalOperator;
  }

  /* End of Switch: '<S700>/Switch' */

  /* DataStoreRead: '<S701>/Data Store Read2' */
  VDHP_HVIL_PulseTime_us = hIOP_HVInterlock_PulseTime_us;

  /* DataTypeConversion: '<S701>/Data Type Conversion1' incorporates:
   *  DataStoreRead: '<S701>/Data Store Read5'
   */
  rtb_DataTypeConversion_m = (uint16_T)hIOP_HVInterlock_Hz;

  /* Logic: '<S701>/Logical Operator1' incorporates:
   *  DataStoreRead: '<S701>/Data Store Read'
   */
  rtb_FixPtLogicalOperator_a = !bool_udsAgingTestStart_flag;

  /* Outputs for Enabled SubSystem: '<S701>/NormalMode' incorporates:
   *  EnablePort: '<S717>/Enable'
   */
  if (rtb_FixPtLogicalOperator_a) {
    /* Outputs for Atomic SubSystem: '<S717>/DHP_systemtick_Timer' */

    /* Logic: '<S717>/Logical Operator11' incorporates:
     *  Constant: '<S717>/Constant'
     *  Constant: '<S717>/Constant1'
     *  Constant: '<S717>/Constant2'
     *  Constant: '<S717>/Constant3'
     *  Constant: '<S717>/Constant4'
     *  Constant: '<S717>/Constant5'
     *  Constant: '<S717>/Constant6'
     *  Logic: '<S717>/Logical Operator'
     *  Logic: '<S717>/Logical Operator1'
     *  Logic: '<S720>/FixPt Logical Operator'
     *  Logic: '<S721>/FixPt Logical Operator'
     *  RelationalOperator: '<S720>/Lower Test'
     *  RelationalOperator: '<S720>/Upper Test'
     *  RelationalOperator: '<S721>/Lower Test'
     *  RelationalOperator: '<S721>/Upper Test'
     *  Sum: '<S717>/Add1'
     *  Sum: '<S717>/Add2'
     */
    DHP_model_DHP_systemtick_Timer_c((!(((uint8_T)(KDHP_HVIL_FreHZ -
      KDHP_HVIL_FreOffset) <= VDSF_HVInterlockFreIn_Hz) &&
      (VDSF_HVInterlockFreIn_Hz <= (uint8_T)((uint32_T)KDHP_HVIL_FreHZ +
      KDHP_HVIL_FreOffset)))) && VDHP_VCUPowerUpDelay2SWork_Flg &&
      (!((KDHP_HVILPulseTime_Lower_us <= VDHP_HVIL_PulseTime_us) &&
         (VDHP_HVIL_PulseTime_us <= KDHP_HVILPulseTime_Upper_us))),
      VDHP_deltaSystemTick_ms, 100U, &DHP_model_B.DHP_systemtick_Timer_f,
      &DHP_model_DW.DHP_systemtick_Timer_f);

    /* End of Outputs for SubSystem: '<S717>/DHP_systemtick_Timer' */

    /* Inport: '<S717>/VPMM_UpToHVMode_flg' */
    DHP_model_B.VPMM_UpToHVMode_flg_e = DHP_model_B.LogicalOperator2;

    /* RelationalOperator: '<S717>/Relational Operator2' incorporates:
     *  Constant: '<S717>/Constant7'
     */
    DHP_model_B.RelationalOperator2 = (DHP_model_B.Gain9 >
      KDHP_HVIL_VehicleSpeed);
  }

  /* End of Outputs for SubSystem: '<S701>/NormalMode' */

  /* Outputs for Enabled SubSystem: '<S701>/TestMode' incorporates:
   *  EnablePort: '<S718>/Enable'
   */
  /* DataStoreRead: '<S701>/Data Store Read1' incorporates:
   *  Constant: '<S718>/Constant'
   *  Constant: '<S718>/Constant1'
   *  Constant: '<S718>/Constant2'
   *  Constant: '<S718>/Constant3'
   *  Constant: '<S718>/Constant4'
   *  Constant: '<S718>/Constant5'
   *  Inport: '<S718>/VPMM_UpToHVMode_flg'
   *  Logic: '<S718>/Logical Operator'
   *  Logic: '<S718>/Logical Operator1'
   *  Logic: '<S723>/FixPt Logical Operator'
   *  RelationalOperator: '<S723>/Lower Test'
   *  RelationalOperator: '<S723>/Upper Test'
   *  Sum: '<S718>/Add'
   *  Sum: '<S718>/Add1'
   */
  if (bool_udsAgingTestStart_flag) {
    /* Outputs for Atomic SubSystem: '<S718>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_c(VDHP_TestWorkDelay4s_Flg && (!(((uint16_T)
      (KDHP_TestHVILPWM_HZ - KDHP_TestPWMHZ_offset) <= rtb_DataTypeConversion_m)
      && (rtb_DataTypeConversion_m <= (uint16_T)((uint32_T)KDHP_TestHVILPWM_HZ +
      KDHP_TestPWMHZ_offset)))), VDHP_deltaSystemTick_ms, 100U,
      &DHP_model_B.DHP_systemtick_Timer_c2,
      &DHP_model_DW.DHP_systemtick_Timer_c2);

    /* End of Outputs for SubSystem: '<S718>/DHP_systemtick_Timer' */
    DHP_model_B.VPMM_UpToHVMode_flg = DHP_model_B.LogicalOperator2;
    DHP_model_B.Constant1 = true;
  }

  /* End of DataStoreRead: '<S701>/Data Store Read1' */
  /* End of Outputs for SubSystem: '<S701>/TestMode' */

  /* Switch: '<S701>/Switch' incorporates:
   *  Switch: '<S701>/Switch1'
   *  Switch: '<S701>/Switch2'
   */
  if (rtb_FixPtLogicalOperator_a) {
    VDHP_HVILErrInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_f.RelationalOperator;
    HVIL_UpToHVMode_flg = DHP_model_B.VPMM_UpToHVMode_flg_e;
    HVIL_VehicleSpeed = DHP_model_B.RelationalOperator2;
  } else {
    VDHP_HVILErrInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_c2.RelationalOperator;
    HVIL_UpToHVMode_flg = DHP_model_B.VPMM_UpToHVMode_flg;
    HVIL_VehicleSpeed = DHP_model_B.Constant1;
  }

  /* End of Switch: '<S701>/Switch' */

  /* RelationalOperator: '<S724>/Compare' incorporates:
   *  Constant: '<S724>/Constant'
   */
  DHP_model_B.Compare_ks = (DHP_model_B.VINP_BMSChrgMod_enum != 1);

  /* RelationalOperator: '<S737>/Compare' incorporates:
   *  Constant: '<S694>/Constant1'
   *  Constant: '<S737>/Constant'
   */
  rtb_LogicalOperator6_bor = (Vehicle_Type == S11_Mark);

  /* Logic: '<S694>/外置TMS3' */
  rtb_TMS3 = !rtb_LogicalOperator6_bor;

  /* Logic: '<S694>/Logical Operator3' incorporates:
   *  Constant: '<S694>/Constant19'
   *  Constant: '<S731>/Constant'
   *  Constant: '<S732>/Constant'
   *  Constant: '<S734>/Constant'
   *  Constant: '<S735>/Constant'
   *  Constant: '<S736>/Constant'
   *  RelationalOperator: '<S731>/Compare'
   *  RelationalOperator: '<S732>/Compare'
   *  RelationalOperator: '<S734>/Compare'
   *  RelationalOperator: '<S735>/Compare'
   *  RelationalOperator: '<S736>/Compare'
   */
  rtb_LogicalOperator3_py = ((Vehicle_Type == S11P05_Mark) || (Vehicle_Type ==
    ((uint8_T)S11P04_MARK)) || (Vehicle_Type == S11P03_Mark) || (Vehicle_Type ==
    S11P01_Mark) || (Vehicle_Type == S21_Mark));

  /* Logic: '<S694>/Logical Operator16' incorporates:
   *  Constant: '<S694>/Constant13'
   *  Constant: '<S733>/Constant'
   *  RelationalOperator: '<S733>/Compare'
   */
  rtb_Switch1 = (rtb_LogicalOperator3_py || (Vehicle_Type == A11_Mark));

  /* Outputs for Enabled SubSystem: '<S694>/ABS_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S726>/Enable'
   */
  /* Logic: '<S694>/Logical Operator24' incorporates:
   *  Constant: '<S694>/Constant2'
   *  Constant: '<S726>/Constant1'
   *  Constant: '<S726>/Constant10'
   *  Constant: '<S740>/Constant'
   *  Delay: '<S766>/Delay'
   *  Delay: '<S767>/Delay'
   *  Logic: '<S726>/Logical Operator12'
   *  Logic: '<S766>/Logical Operator1'
   *  Logic: '<S767>/Logical Operator1'
   *  RelationalOperator: '<S740>/Compare'
   *  RelationalOperator: '<S766>/Relational Operator'
   *  RelationalOperator: '<S767>/Relational Operator'
   *  Switch: '<S694>/Switch3'
   */
  if ((rtb_Switch1 || rtb_Compare_kvm) && (Vehicle_Type != X11_Mark) &&
      DHP_model_B.DHP_systemtick_Timer_n.RelationalOperator) {
    /* Outputs for Atomic SubSystem: '<S766>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_n
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && (DHP_model_B.DataStoreRead41 == DHP_model_DW.Delay_DSTATE_fi),
       VDHP_deltaSystemTick_ms, ((uint16_T)DHP_20MSMSG_MISSINGTIME),
       &DHP_model_DW.DHP_systemtick_Timer_nt);

    /* End of Outputs for SubSystem: '<S766>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S767>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_c
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && rtb_TMS3 && (DHP_model_B.DataStoreRead3 ==
                       DHP_model_DW.Delay_DSTATE_h5), VDHP_deltaSystemTick_ms,
       ((uint16_T)DHP_20MSMSG_MISSINGTIME), &DHP_model_B.DHP_systemtick_Timer_cd,
       &DHP_model_DW.DHP_systemtick_Timer_cd);

    /* End of Outputs for SubSystem: '<S767>/DHP_systemtick_Timer' */

    /* Switch: '<S726>/Switch' incorporates:
     *  Constant: '<S726>/Constant1'
     *  Constant: '<S726>/Constant10'
     *  Delay: '<S766>/Delay'
     *  Delay: '<S767>/Delay'
     *  Logic: '<S726>/Logical Operator12'
     *  Logic: '<S766>/Logical Operator1'
     *  Logic: '<S767>/Logical Operator1'
     *  RelationalOperator: '<S766>/Relational Operator'
     *  RelationalOperator: '<S767>/Relational Operator'
     */
    if (rtb_TMS3) {
      VDHP_ABSLossCanNetInstFlt_flg =
        DHP_model_B.DHP_systemtick_Timer_cd.RelationalOperator;
    } else {
      VDHP_ABSLossCanNetInstFlt_flg = VDHP_ABS232MissingInstFlt_flg;
    }

    /* End of Switch: '<S726>/Switch' */

    /* Update for Delay: '<S766>/Delay' */
    DHP_model_DW.Delay_DSTATE_fi = DHP_model_B.DataStoreRead41;

    /* Update for Delay: '<S767>/Delay' */
    DHP_model_DW.Delay_DSTATE_h5 = DHP_model_B.DataStoreRead3;
  }

  /* End of Logic: '<S694>/Logical Operator24' */
  /* End of Outputs for SubSystem: '<S694>/ABS_LossCanNetInsFlt' */

  /* Logic: '<S694>/Logical Operator19' incorporates:
   *  Constant: '<S765>/Constant'
   *  Logic: '<S694>/Logical Operator20'
   *  Logic: '<S694>/Logical Operator21'
   *  RelationalOperator: '<S765>/Compare'
   */
  rtb_LogicalOperator19 =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
     ||
     (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
      && ((DHP_model_B.VINP_BMSChrgMod_enum != 0) ||
          DHP_model_B.VINP_SlowChargeAwakeActive_flg ||
          DHP_model_B.VINP_FastChargeAwakeActiveIn_flg)));

  /* Logic: '<S694>/Logical Operator26' */
  rtb_FixPtLogicalOperator_a = (rtb_Compare_kvm &&
    DHP_model_B.DHP_systemtick_Timer_n.RelationalOperator);

  /* Outputs for Enabled SubSystem: '<S694>/DCDC_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S749>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S694>/BMS_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S727>/Enable'
   */
  if (rtb_FixPtLogicalOperator_a) {
    /* Outputs for Atomic SubSystem: '<S770>/DHP_systemtick_Timer' */

    /* Logic: '<S770>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S770>/Delay'
     *  RelationalOperator: '<S770>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_e(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead23 == DHP_model_DW.Delay_DSTATE_as),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_DW.DHP_systemtick_Timer_e);

    /* End of Outputs for SubSystem: '<S770>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S771>/DHP_systemtick_Timer' */

    /* Logic: '<S771>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S771>/Delay'
     *  RelationalOperator: '<S771>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead4 == DHP_model_DW.Delay_DSTATE_n),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_d, &DHP_model_DW.DHP_systemtick_Timer_d);

    /* End of Outputs for SubSystem: '<S771>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S771>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_304LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_d.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S772>/DHP_systemtick_Timer' */

    /* Logic: '<S772>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S772>/Delay'
     *  RelationalOperator: '<S772>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead5 == DHP_model_DW.Delay_DSTATE_ik),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_h, &DHP_model_DW.DHP_systemtick_Timer_h);

    /* End of Outputs for SubSystem: '<S772>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S772>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_513LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_h.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S773>/DHP_systemtick_Timer' */

    /* Logic: '<S773>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S773>/Delay'
     *  RelationalOperator: '<S773>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead6 == DHP_model_DW.Delay_DSTATE_hv),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_jp,
      &DHP_model_DW.DHP_systemtick_Timer_jp);

    /* End of Outputs for SubSystem: '<S773>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S773>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_603LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_jp.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S774>/DHP_systemtick_Timer' */

    /* Logic: '<S774>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S774>/Delay'
     *  RelationalOperator: '<S774>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead7 == DHP_model_DW.Delay_DSTATE_dl),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_cu,
      &DHP_model_DW.DHP_systemtick_Timer_cu);

    /* End of Outputs for SubSystem: '<S774>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S774>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_613LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_cu.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S775>/DHP_systemtick_Timer' */

    /* Logic: '<S775>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S775>/Delay'
     *  RelationalOperator: '<S775>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead19 == DHP_model_DW.Delay_DSTATE_ee),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_fl,
      &DHP_model_DW.DHP_systemtick_Timer_fl);

    /* End of Outputs for SubSystem: '<S775>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S776>/DHP_systemtick_Timer' */

    /* Logic: '<S776>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S776>/Delay'
     *  RelationalOperator: '<S776>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead22 == DHP_model_DW.Delay_DSTATE_n2),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_ns,
      &DHP_model_DW.DHP_systemtick_Timer_ns);

    /* End of Outputs for SubSystem: '<S776>/DHP_systemtick_Timer' */

    /* RelationalOperator: '<S787>/Compare' incorporates:
     *  Constant: '<S727>/Constant9'
     *  Constant: '<S787>/Constant'
     */
    rtb_Switch4 = (Vehicle_Type != K11_Mark);

    /* Outputs for Atomic SubSystem: '<S777>/DHP_systemtick_Timer' */

    /* Logic: '<S777>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S777>/Delay'
     *  Logic: '<S727>/Logical Operator'
     *  RelationalOperator: '<S777>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_Switch4 && rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead8 == DHP_model_DW.Delay_DSTATE_e4),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_b, &DHP_model_DW.DHP_systemtick_Timer_b);

    /* End of Outputs for SubSystem: '<S777>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S777>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_623LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_b.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S778>/DHP_systemtick_Timer' */

    /* Logic: '<S778>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant1'
     *  Delay: '<S778>/Delay'
     *  RelationalOperator: '<S778>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_k(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead19 == DHP_model_DW.Delay_DSTATE_iy),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_10MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_k);

    /* End of Outputs for SubSystem: '<S778>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S779>/DHP_systemtick_Timer' */

    /* Logic: '<S779>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S779>/Delay'
     *  RelationalOperator: '<S779>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_o(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead19 == DHP_model_DW.Delay_DSTATE_oi),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_DW.DHP_systemtick_Timer_oe);

    /* End of Outputs for SubSystem: '<S779>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S780>/DHP_systemtick_Timer' */

    /* Logic: '<S780>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S780>/Delay'
     *  RelationalOperator: '<S780>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_g(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead26 == DHP_model_DW.Delay_DSTATE_k),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_DW.DHP_systemtick_Timer_g);

    /* End of Outputs for SubSystem: '<S780>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S781>/DHP_systemtick_Timer' */

    /* Logic: '<S781>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S781>/Delay'
     *  RelationalOperator: '<S781>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead20 == DHP_model_DW.Delay_DSTATE_am),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_i, &DHP_model_DW.DHP_systemtick_Timer_i);

    /* End of Outputs for SubSystem: '<S781>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S781>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_213LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_i.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S782>/DHP_systemtick_Timer' */

    /* Logic: '<S782>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S782>/Delay'
     *  RelationalOperator: '<S782>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead25 == DHP_model_DW.Delay_DSTATE_kh),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_ii,
      &DHP_model_DW.DHP_systemtick_Timer_ii);

    /* End of Outputs for SubSystem: '<S782>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S782>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_377LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_ii.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S783>/DHP_systemtick_Timer' */

    /* Logic: '<S783>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S783>/Delay'
     *  RelationalOperator: '<S783>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead21 == DHP_model_DW.Delay_DSTATE_i5),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_gv,
      &DHP_model_DW.DHP_systemtick_Timer_gv);

    /* End of Outputs for SubSystem: '<S783>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S783>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_233LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_gv.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S784>/DHP_systemtick_Timer' */

    /* Logic: '<S784>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S784>/Delay'
     *  RelationalOperator: '<S784>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead22 == DHP_model_DW.Delay_DSTATE_dj),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_bi,
      &DHP_model_DW.DHP_systemtick_Timer_bi);

    /* End of Outputs for SubSystem: '<S784>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S784>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_303LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_bi.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S785>/DHP_systemtick_Timer' */

    /* Logic: '<S785>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S785>/Delay'
     *  RelationalOperator: '<S785>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead27 == DHP_model_DW.Delay_DSTATE_e0),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_bh,
      &DHP_model_DW.DHP_systemtick_Timer_bh);

    /* End of Outputs for SubSystem: '<S785>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S785>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_653LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_bh.RelationalOperator;

    /* Outputs for Atomic SubSystem: '<S786>/DHP_systemtick_Timer' */

    /* Logic: '<S786>/Logical Operator1' incorporates:
     *  Constant: '<S727>/Constant3'
     *  Delay: '<S786>/Delay'
     *  RelationalOperator: '<S786>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead24 == DHP_model_DW.Delay_DSTATE_o4),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_ha,
      &DHP_model_DW.DHP_systemtick_Timer_ha);

    /* End of Outputs for SubSystem: '<S786>/DHP_systemtick_Timer' */

    /* SignalConversion: '<S786>/TmpSignal ConversionAtDHP_systemtick_TimerOutport1' */
    BMS_323LossCanNetInstFlt_flg =
      DHP_model_B.DHP_systemtick_Timer_ha.RelationalOperator;

    /* Switch: '<S727>/Switch4' */
    rtb_Switch4 = ((!rtb_Switch4) || BMS_623LossCanNetInstFlt_flg);

    /* Logic: '<S727>/Logical Operator19' */
    VDHP_BMSMissingInstFlt_flg = (BMS_113LossCanNetInstFlt_flg &&
      BMS_313LossCanNetInstFlt_flg && BMS_633LossCanNetInstFlt_flg &&
      BMS_213LossCanNetInstFlt_flg && BMS_377LossCanNetInstFlt_flg &&
      BMS_233LossCanNetInstFlt_flg && BMS_303LossCanNetInstFlt_flg &&
      BMS_323LossCanNetInstFlt_flg && BMS_653LossCanNetInstFlt_flg &&
      BMS_304LossCanNetInstFlt_flg && BMS_513LossCanNetInstFlt_flg &&
      BMS_603LossCanNetInstFlt_flg && BMS_613LossCanNetInstFlt_flg &&
      rtb_Switch4);

    /* Logic: '<S727>/Logical Operator20' incorporates:
     *  Logic: '<S727>/Logical Operator1'
     *  Logic: '<S727>/Logical Operator10'
     *  Logic: '<S727>/Logical Operator11'
     *  Logic: '<S727>/Logical Operator12'
     *  Logic: '<S727>/Logical Operator13'
     *  Logic: '<S727>/Logical Operator14'
     *  Logic: '<S727>/Logical Operator15'
     *  Logic: '<S727>/Logical Operator16'
     *  Logic: '<S727>/Logical Operator17'
     *  Logic: '<S727>/Logical Operator18'
     *  Logic: '<S727>/Logical Operator24'
     *  Logic: '<S727>/Logical Operator25'
     *  Logic: '<S727>/Logical Operator27'
     *  Logic: '<S727>/Logical Operator29'
     */
    DHP_model_B.LogicalOperator20 = ((!BMS_113LossCanNetInstFlt_flg) &&
      (!BMS_313LossCanNetInstFlt_flg) && (!BMS_633LossCanNetInstFlt_flg) &&
      (!BMS_213LossCanNetInstFlt_flg) && (!BMS_377LossCanNetInstFlt_flg) &&
      (!BMS_233LossCanNetInstFlt_flg) && (!BMS_303LossCanNetInstFlt_flg) &&
      (!BMS_323LossCanNetInstFlt_flg) && (!BMS_653LossCanNetInstFlt_flg) &&
      (!BMS_304LossCanNetInstFlt_flg) && (!BMS_513LossCanNetInstFlt_flg) &&
      (!BMS_603LossCanNetInstFlt_flg) && (!BMS_613LossCanNetInstFlt_flg) &&
      (!BMS_623LossCanNetInstFlt_flg));

    /* Update for Delay: '<S770>/Delay' */
    DHP_model_DW.Delay_DSTATE_as = DHP_model_B.DataStoreRead23;

    /* Update for Delay: '<S771>/Delay' */
    DHP_model_DW.Delay_DSTATE_n = DHP_model_B.DataStoreRead4;

    /* Update for Delay: '<S772>/Delay' */
    DHP_model_DW.Delay_DSTATE_ik = DHP_model_B.DataStoreRead5;

    /* Update for Delay: '<S773>/Delay' */
    DHP_model_DW.Delay_DSTATE_hv = DHP_model_B.DataStoreRead6;

    /* Update for Delay: '<S774>/Delay' */
    DHP_model_DW.Delay_DSTATE_dl = DHP_model_B.DataStoreRead7;

    /* Update for Delay: '<S775>/Delay' */
    DHP_model_DW.Delay_DSTATE_ee = DHP_model_B.DataStoreRead19;

    /* Update for Delay: '<S776>/Delay' */
    DHP_model_DW.Delay_DSTATE_n2 = DHP_model_B.DataStoreRead22;

    /* Update for Delay: '<S777>/Delay' */
    DHP_model_DW.Delay_DSTATE_e4 = DHP_model_B.DataStoreRead8;

    /* Update for Delay: '<S778>/Delay' */
    DHP_model_DW.Delay_DSTATE_iy = DHP_model_B.DataStoreRead19;

    /* Update for Delay: '<S779>/Delay' */
    DHP_model_DW.Delay_DSTATE_oi = DHP_model_B.DataStoreRead19;

    /* Update for Delay: '<S780>/Delay' */
    DHP_model_DW.Delay_DSTATE_k = DHP_model_B.DataStoreRead26;

    /* Update for Delay: '<S781>/Delay' */
    DHP_model_DW.Delay_DSTATE_am = DHP_model_B.DataStoreRead20;

    /* Update for Delay: '<S782>/Delay' */
    DHP_model_DW.Delay_DSTATE_kh = DHP_model_B.DataStoreRead25;

    /* Update for Delay: '<S783>/Delay' */
    DHP_model_DW.Delay_DSTATE_i5 = DHP_model_B.DataStoreRead21;

    /* Update for Delay: '<S784>/Delay' */
    DHP_model_DW.Delay_DSTATE_dj = DHP_model_B.DataStoreRead22;

    /* Update for Delay: '<S785>/Delay' */
    DHP_model_DW.Delay_DSTATE_e0 = DHP_model_B.DataStoreRead27;

    /* Update for Delay: '<S786>/Delay' */
    DHP_model_DW.Delay_DSTATE_o4 = DHP_model_B.DataStoreRead24;

    /* Outputs for Atomic SubSystem: '<S805>/DHP_systemtick_Timer' */

    /* Logic: '<S805>/Logical Operator1' incorporates:
     *  Constant: '<S749>/Constant2'
     *  Delay: '<S805>/Delay'
     *  RelationalOperator: '<S805>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead33 == DHP_model_DW.Delay_DSTATE_o),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_m, &DHP_model_DW.DHP_systemtick_Timer_m);

    /* End of Outputs for SubSystem: '<S805>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S806>/DHP_systemtick_Timer' */

    /* Logic: '<S806>/Logical Operator1' incorporates:
     *  Constant: '<S749>/Constant1'
     *  Delay: '<S806>/Delay'
     *  RelationalOperator: '<S806>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead32 == DHP_model_DW.Delay_DSTATE_cl),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_ci,
      &DHP_model_DW.DHP_systemtick_Timer_ci);

    /* End of Outputs for SubSystem: '<S806>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S807>/DHP_systemtick_Timer' */

    /* Logic: '<S807>/Logical Operator1' incorporates:
     *  Constant: '<S749>/Constant10'
     *  Delay: '<S807>/Delay'
     *  RelationalOperator: '<S807>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_k2(rtb_LogicalOperator19 &&
      (DHP_model_B.DataStoreRead32 == DHP_model_DW.Delay_DSTATE_dr),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_100MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_k2);

    /* End of Outputs for SubSystem: '<S807>/DHP_systemtick_Timer' */

    /* Logic: '<S749>/Logical Operator3' */
    VDHP_DCDCMissingInstFlt_flg =
      (DHP_model_B.DHP_systemtick_Timer_ci.RelationalOperator &&
       DHP_model_B.DHP_systemtick_Timer_m.RelationalOperator);

    /* Logic: '<S749>/Logical Operator4' incorporates:
     *  Logic: '<S749>/Logical Operator2'
     *  Logic: '<S749>/Logical Operator8'
     */
    DHP_model_B.LogicalOperator4 =
      ((!DHP_model_B.DHP_systemtick_Timer_ci.RelationalOperator) &&
       (!DHP_model_B.DHP_systemtick_Timer_m.RelationalOperator));

    /* Update for Delay: '<S805>/Delay' */
    DHP_model_DW.Delay_DSTATE_o = DHP_model_B.DataStoreRead33;

    /* Update for Delay: '<S806>/Delay' */
    DHP_model_DW.Delay_DSTATE_cl = DHP_model_B.DataStoreRead32;

    /* Update for Delay: '<S807>/Delay' */
    DHP_model_DW.Delay_DSTATE_dr = DHP_model_B.DataStoreRead32;
  }

  /* End of Outputs for SubSystem: '<S694>/BMS_LossCanNetInsFlt' */
  /* End of Outputs for SubSystem: '<S694>/DCDC_LossCanNetInsFlt' */

  /* Logic: '<S694>/外置TMS2' incorporates:
   *  Constant: '<S694>/Constant4'
   *  Constant: '<S741>/Constant'
   *  RelationalOperator: '<S741>/Compare'
   */
  rtb_LogicalOperator19 = !(Vehicle_Type == ((uint8_T)Z18_MARK));

  /* Outputs for Enabled SubSystem: '<S694>/EAC_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S750>/Enable'
   */
  /* Logic: '<S694>/Logical Operator4' incorporates:
   *  Constant: '<S729>/Constant'
   *  Constant: '<S750>/Constant5'
   *  Delay: '<S750>/Delay4'
   *  Inport: '<Root>/Config'
   *  Logic: '<S750>/Logical Operator2'
   *  RelationalOperator: '<S729>/Compare'
   *  RelationalOperator: '<S750>/Relational Operator4'
   */
  if (rtb_LogicalOperator19 && (Config_output.C_EAC_En == 1) &&
      rtb_FixPtLogicalOperator_a) {
    /* Outputs for Atomic SubSystem: '<S750>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_m((DHP_model_B.DataStoreRead47 ==
      DHP_model_DW.Delay4_DSTATE_o) &&
      DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator,
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_100MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_mz);

    /* End of Outputs for SubSystem: '<S750>/DHP_systemtick_Timer' */

    /* Update for Delay: '<S750>/Delay4' incorporates:
     *  Constant: '<S750>/Constant5'
     *  Delay: '<S750>/Delay4'
     *  Logic: '<S750>/Logical Operator2'
     *  RelationalOperator: '<S750>/Relational Operator4'
     */
    DHP_model_DW.Delay4_DSTATE_o = DHP_model_B.DataStoreRead47;
  }

  /* End of Logic: '<S694>/Logical Operator4' */
  /* End of Outputs for SubSystem: '<S694>/EAC_LossCanNetInsFlt' */

  /* Outputs for Enabled SubSystem: '<S694>/ECC_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S751>/Enable'
   */
  /* Logic: '<S694>/Logical Operator23' incorporates:
   *  Constant: '<S745>/Constant'
   *  Constant: '<S751>/Constant10'
   *  Delay: '<S812>/Delay'
   *  Inport: '<Root>/Config'
   *  Logic: '<S812>/Logical Operator1'
   *  RelationalOperator: '<S745>/Compare'
   *  RelationalOperator: '<S812>/Relational Operator'
   */
  if ((Config_output.C_ECC_En == 1) && rtb_FixPtLogicalOperator_a &&
      rtb_LogicalOperator19) {
    /* Outputs for Atomic SubSystem: '<S812>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_m3
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && (DHP_model_B.DataStoreRead38 == DHP_model_DW.Delay_DSTATE_m),
       VDHP_deltaSystemTick_ms, ((uint16_T)DHP_100MSMSG_MISSINGTIME),
       &DHP_model_DW.DHP_systemtick_Timer_m3);

    /* End of Outputs for SubSystem: '<S812>/DHP_systemtick_Timer' */

    /* Update for Delay: '<S812>/Delay' incorporates:
     *  Constant: '<S751>/Constant10'
     *  Delay: '<S812>/Delay'
     *  Logic: '<S812>/Logical Operator1'
     *  RelationalOperator: '<S812>/Relational Operator'
     */
    DHP_model_DW.Delay_DSTATE_m = DHP_model_B.DataStoreRead38;
  }

  /* End of Logic: '<S694>/Logical Operator23' */
  /* End of Outputs for SubSystem: '<S694>/ECC_LossCanNetInsFlt' */

  /* Logic: '<S694>/Logical Operator15' incorporates:
   *  Constant: '<S694>/Constant3'
   *  Constant: '<S730>/Constant'
   *  Constant: '<S738>/Constant'
   *  Constant: '<S747>/Constant'
   *  Constant: '<S748>/Constant'
   *  RelationalOperator: '<S730>/Compare'
   *  RelationalOperator: '<S738>/Compare'
   *  RelationalOperator: '<S747>/Compare'
   *  RelationalOperator: '<S748>/Compare'
   */
  rtb_Switch4 = ((Vehicle_Type == K11_Mark) || (Vehicle_Type == K11P01_Mark) ||
                 (Vehicle_Type == K11E01R_Mark) || (Vehicle_Type == K11P06_Mark));

  /* Outputs for Enabled SubSystem: '<S694>/EHU_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S752>/Enable'
   */
  /* Logic: '<S694>/Logical Operator6' incorporates:
   *  Constant: '<S746>/Constant'
   *  Constant: '<S752>/Constant5'
   *  Delay: '<S752>/Delay4'
   *  Inport: '<Root>/Config'
   *  Logic: '<S752>/Logical Operator2'
   *  RelationalOperator: '<S746>/Compare'
   *  RelationalOperator: '<S752>/Relational Operator4'
   */
  if (rtb_Switch4 && (Config_output.C_EHU_En == 1) && rtb_FixPtLogicalOperator_a
      && rtb_LogicalOperator19) {
    /* Outputs for Atomic SubSystem: '<S752>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_l
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && (DHP_model_B.DataStoreRead2 == DHP_model_DW.Delay4_DSTATE_i),
       VDHP_deltaSystemTick_ms, ((uint16_T)DHP_500MSMSG_MISSINGTIME),
       &DHP_model_DW.DHP_systemtick_Timer_lt);

    /* End of Outputs for SubSystem: '<S752>/DHP_systemtick_Timer' */

    /* Update for Delay: '<S752>/Delay4' incorporates:
     *  Constant: '<S752>/Constant5'
     *  Delay: '<S752>/Delay4'
     *  Logic: '<S752>/Logical Operator2'
     *  RelationalOperator: '<S752>/Relational Operator4'
     */
    DHP_model_DW.Delay4_DSTATE_i = DHP_model_B.DataStoreRead2;
  }

  /* End of Logic: '<S694>/Logical Operator6' */
  /* End of Outputs for SubSystem: '<S694>/EHU_LossCanNetInsFlt' */

  /* Switch: '<S694>/Switch1' */
  rtb_Switch1 = (rtb_Switch1 || rtb_Compare_kvm);

  /* Outputs for Enabled SubSystem: '<S694>/EPS_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S753>/Enable'
   */
  /* Logic: '<S694>/Logical Operator' incorporates:
   *  Constant: '<S742>/Constant'
   *  Constant: '<S753>/Constant1'
   *  Delay: '<S815>/Delay'
   *  Inport: '<Root>/Config'
   *  Logic: '<S815>/Logical Operator1'
   *  RelationalOperator: '<S742>/Compare'
   *  RelationalOperator: '<S815>/Relational Operator'
   */
  if (rtb_Switch1 && rtb_TMS3 && (Config_output.C_EPS_En == 1) &&
      DHP_model_B.DHP_systemtick_Timer_n.RelationalOperator) {
    /* Outputs for Atomic SubSystem: '<S815>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_f
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && (DHP_model_B.DataStoreRead46 == DHP_model_DW.Delay_DSTATE_ii),
       VDHP_deltaSystemTick_ms, ((uint16_T)DHP_10MSMSG_MISSINGTIME),
       &DHP_model_DW.DHP_systemtick_Timer_fr);

    /* End of Outputs for SubSystem: '<S815>/DHP_systemtick_Timer' */

    /* Update for Delay: '<S815>/Delay' incorporates:
     *  Constant: '<S753>/Constant1'
     *  Delay: '<S815>/Delay'
     *  Logic: '<S815>/Logical Operator1'
     *  RelationalOperator: '<S815>/Relational Operator'
     */
    DHP_model_DW.Delay_DSTATE_ii = DHP_model_B.DataStoreRead46;
  }

  /* End of Logic: '<S694>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S694>/EPS_LossCanNetInsFlt' */

  /* Outputs for Enabled SubSystem: '<S694>/GW_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S754>/Enable'
   */
  /* Logic: '<S694>/Logical Operator1' incorporates:
   *  Constant: '<S754>/Constant7'
   *  Constant: '<S754>/Constant8'
   *  Delay: '<S817>/Delay'
   *  Delay: '<S818>/Delay'
   *  Logic: '<S694>/外置TMS1'
   *  Logic: '<S754>/Logical Operator4'
   *  Logic: '<S817>/Logical Operator1'
   *  Logic: '<S818>/Logical Operator1'
   *  RelationalOperator: '<S817>/Relational Operator'
   *  RelationalOperator: '<S818>/Relational Operator'
   */
  if ((!rtb_Switch4) && rtb_FixPtLogicalOperator_a && rtb_LogicalOperator19) {
    /* Outputs for Atomic SubSystem: '<S817>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_c
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && rtb_LogicalOperator6_bor && (DHP_model_B.DataStoreRead43 ==
        DHP_model_DW.Delay_DSTATE_c), VDHP_deltaSystemTick_ms, ((uint16_T)
        DHP_20MSMSG_MISSINGTIME), &DHP_model_B.DHP_systemtick_Timer_hv,
       &DHP_model_DW.DHP_systemtick_Timer_hv);

    /* End of Outputs for SubSystem: '<S817>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S818>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_c
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && (DHP_model_B.DataStoreRead44 == DHP_model_DW.Delay_DSTATE_g),
       VDHP_deltaSystemTick_ms, ((uint16_T)DHP_500MSMSG_MISSINGTIME),
       &DHP_model_B.DHP_systemtick_Timer_gt,
       &DHP_model_DW.DHP_systemtick_Timer_gt);

    /* End of Outputs for SubSystem: '<S818>/DHP_systemtick_Timer' */

    /* Switch: '<S754>/Switch' incorporates:
     *  Constant: '<S754>/Constant7'
     *  Constant: '<S754>/Constant8'
     *  Delay: '<S817>/Delay'
     *  Delay: '<S818>/Delay'
     *  Logic: '<S754>/Logical Operator4'
     *  Logic: '<S817>/Logical Operator1'
     *  Logic: '<S818>/Logical Operator1'
     *  RelationalOperator: '<S817>/Relational Operator'
     *  RelationalOperator: '<S818>/Relational Operator'
     */
    if (rtb_LogicalOperator6_bor) {
      VDHP_GWLossCanNetInstFlt_flg =
        DHP_model_B.DHP_systemtick_Timer_hv.RelationalOperator;
    } else {
      VDHP_GWLossCanNetInstFlt_flg =
        DHP_model_B.DHP_systemtick_Timer_gt.RelationalOperator;
    }

    /* End of Switch: '<S754>/Switch' */

    /* Update for Delay: '<S817>/Delay' */
    DHP_model_DW.Delay_DSTATE_c = DHP_model_B.DataStoreRead43;

    /* Update for Delay: '<S818>/Delay' */
    DHP_model_DW.Delay_DSTATE_g = DHP_model_B.DataStoreRead44;
  }

  /* End of Logic: '<S694>/Logical Operator1' */
  /* End of Outputs for SubSystem: '<S694>/GW_LossCanNetInsFlt' */

  /* Outputs for Enabled SubSystem: '<S694>/ICM_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S755>/Enable'
   */
  /* Logic: '<S694>/Logical Operator5' incorporates:
   *  Constant: '<S739>/Constant'
   *  Constant: '<S755>/Constant1'
   *  Constant: '<S755>/Constant5'
   *  DataStoreRead: '<S687>/Data Store Read18'
   *  Delay: '<S755>/Delay1'
   *  Delay: '<S755>/Delay4'
   *  Inport: '<Root>/Config'
   *  Logic: '<S755>/Logical Operator1'
   *  Logic: '<S755>/Logical Operator2'
   *  RelationalOperator: '<S739>/Compare'
   *  RelationalOperator: '<S755>/Relational Operator1'
   *  RelationalOperator: '<S755>/Relational Operator4'
   */
  if (rtb_TMS3 && (Config_output.C_ICM_En == 1) && rtb_FixPtLogicalOperator_a) {
    /* Outputs for Atomic SubSystem: '<S755>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_c
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && (DHP_model_B.DataStoreRead1 == DHP_model_DW.Delay4_DSTATE_f),
       VDHP_deltaSystemTick_ms, ((uint16_T)DHP_500MSMSG_MISSINGTIME),
       &DHP_model_B.DHP_systemtick_Timer_bj,
       &DHP_model_DW.DHP_systemtick_Timer_bj);

    /* End of Outputs for SubSystem: '<S755>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S755>/DHP_systemtick_Timer1' */
    DHP_model_DHP_systemtick_Timer1_k
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && (VHALI_ICM_235_MsgTicks == DHP_model_DW.Delay1_DSTATE_jd),
       VDHP_deltaSystemTick_ms, ((uint16_T)DHP_20MSMSG_MISSINGTIME),
       &DHP_model_DW.DHP_systemtick_Timer1_k);

    /* End of Outputs for SubSystem: '<S755>/DHP_systemtick_Timer1' */

    /* Switch: '<S755>/Switch' incorporates:
     *  Constant: '<S755>/Constant1'
     *  Constant: '<S755>/Constant5'
     *  DataStoreRead: '<S687>/Data Store Read18'
     *  Delay: '<S755>/Delay1'
     *  Delay: '<S755>/Delay4'
     *  Logic: '<S755>/Logical Operator'
     *  Logic: '<S755>/Logical Operator1'
     *  Logic: '<S755>/Logical Operator2'
     *  RelationalOperator: '<S755>/Relational Operator1'
     *  RelationalOperator: '<S755>/Relational Operator4'
     */
    if (!rtb_LogicalOperator3_py) {
      VDHP_ICMLossCanNetInstFlt_flg =
        DHP_model_B.DHP_systemtick_Timer_bj.RelationalOperator;
    } else {
      VDHP_ICMLossCanNetInstFlt_flg = VDHP_ICM235MissingInstFlt_flg;
    }

    /* End of Switch: '<S755>/Switch' */

    /* Update for Delay: '<S755>/Delay4' */
    DHP_model_DW.Delay4_DSTATE_f = DHP_model_B.DataStoreRead1;

    /* Update for Delay: '<S755>/Delay1' incorporates:
     *  DataStoreRead: '<S687>/Data Store Read18'
     */
    DHP_model_DW.Delay1_DSTATE_jd = VHALI_ICM_235_MsgTicks;
  }

  /* End of Logic: '<S694>/Logical Operator5' */
  /* End of Outputs for SubSystem: '<S694>/ICM_LossCanNetInsFlt' */

  /* Logic: '<S694>/Logical Operator17' incorporates:
   *  Constant: '<S728>/Constant'
   *  Inport: '<Root>/Config'
   *  RelationalOperator: '<S728>/Compare'
   */
  rtb_Compare_kvm = ((Config_output.C_Booster_En == 1) &&
                     DHP_model_B.DHP_systemtick_Timer_n.RelationalOperator);

  /* Logic: '<S694>/Logical Operator2' incorporates:
   *  Constant: '<S725>/Constant'
   *  RelationalOperator: '<S725>/Compare'
   */
  VDHP_OBC_CANLoseAuxCondition = (DHP_model_B.VCHRG_ChrgStsLampReq_flg &&
    (DHP_model_B.VINP_BMSChrgMod_enum == 1));

  /* Switch: '<S694>/Switch2' incorporates:
   *  DataStoreRead: '<S694>/Data Store Read'
   *  DataStoreRead: '<S694>/Data Store Read12'
   */
  if (rtb_LogicalOperator19) {
    rtb_LogicalOperator19_0 = VHALO_MCURelayActive_flg;
  } else {
    rtb_LogicalOperator19_0 = hIOP_MainRelay_flg;
  }

  /* End of Switch: '<S694>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S762>/DHP_systemtick_Timer' */

  /* Logic: '<S694>/Logical Operator18' incorporates:
   *  Constant: '<S762>/Constant8'
   *  Constant: '<S764>/Constant'
   *  Logic: '<S694>/Logical Operator8'
   *  Logic: '<S694>/Logical Operator9'
   *  RelationalOperator: '<S764>/Compare'
   */
  DHP_model_DHP_systemtick_Timer_c((rtb_LogicalOperator19_0 != 0) &&
    (!((DHP_model_B.VINP_BMSChrgMod_enum != 0) ||
       DHP_model_B.VCHRG_VCUChrgAllwd_flg ||
       DHP_model_B.VINP_SlowChargeAwakeActive_flg ||
       DHP_model_B.VINP_FastChargeAwakeActiveIn_flg)), VDHP_deltaSystemTick_ms,
    KDHP_ChrgendMCUmissing_ms, &DHP_model_B.DHP_systemtick_Timer_l,
    &DHP_model_DW.DHP_systemtick_Timer_l);

  /* End of Outputs for SubSystem: '<S762>/DHP_systemtick_Timer' */

  /* Logic: '<S694>/Logical Operator7' */
  rtb_LogicalOperator6_bor =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
     && DHP_model_B.DHP_systemtick_Timer_l.RelationalOperator);

  /* Outputs for Enabled SubSystem: '<S694>/TBOX_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S760>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S694>/SRS_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S759>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S694>/OBC_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S758>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S694>/NMLiphome_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S757>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S694>/MCU_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S756>/Enable'
   */
  if (rtb_FixPtLogicalOperator_a) {
    /* Outputs for Atomic SubSystem: '<S823>/DHP_systemtick_Timer' */

    /* Logic: '<S823>/Logical Operator1' incorporates:
     *  Constant: '<S756>/Constant1'
     *  Delay: '<S823>/Delay'
     *  RelationalOperator: '<S823>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_a(rtb_LogicalOperator6_bor &&
      (DHP_model_B.DataStoreRead29 == DHP_model_DW.Delay_DSTATE_ip),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_10MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_a);

    /* End of Outputs for SubSystem: '<S823>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S824>/DHP_systemtick_Timer' */

    /* Logic: '<S824>/Logical Operator1' incorporates:
     *  Constant: '<S756>/Constant10'
     *  Delay: '<S824>/Delay'
     *  RelationalOperator: '<S824>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_b(rtb_LogicalOperator6_bor &&
      (DHP_model_B.DataStoreRead28 == DHP_model_DW.Delay_DSTATE_hp),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_10MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_bn);

    /* End of Outputs for SubSystem: '<S824>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S825>/DHP_systemtick_Timer' */

    /* Logic: '<S825>/Logical Operator1' incorporates:
     *  Constant: '<S756>/Constant2'
     *  Delay: '<S825>/Delay'
     *  RelationalOperator: '<S825>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_j(rtb_LogicalOperator6_bor &&
      (DHP_model_B.DataStoreRead31 == DHP_model_DW.Delay_DSTATE_e),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_1000MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_jg);

    /* End of Outputs for SubSystem: '<S825>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S826>/DHP_systemtick_Timer' */

    /* Logic: '<S826>/Logical Operator1' incorporates:
     *  Constant: '<S756>/Constant3'
     *  Delay: '<S826>/Delay'
     *  RelationalOperator: '<S826>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_h(rtb_LogicalOperator6_bor &&
      (DHP_model_B.DataStoreRead30 == DHP_model_DW.Delay_DSTATE_a),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_1000MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_hr);

    /* End of Outputs for SubSystem: '<S826>/DHP_systemtick_Timer' */

    /* Update for Delay: '<S823>/Delay' */
    DHP_model_DW.Delay_DSTATE_ip = DHP_model_B.DataStoreRead29;

    /* Update for Delay: '<S824>/Delay' */
    DHP_model_DW.Delay_DSTATE_hp = DHP_model_B.DataStoreRead28;

    /* Update for Delay: '<S825>/Delay' */
    DHP_model_DW.Delay_DSTATE_e = DHP_model_B.DataStoreRead31;

    /* Update for Delay: '<S826>/Delay' */
    DHP_model_DW.Delay_DSTATE_a = DHP_model_B.DataStoreRead30;

    /* Logic: '<S757>/Logical Operator5' incorporates:
     *  Constant: '<S831>/Constant'
     *  Inport: '<Root>/NM'
     *  RelationalOperator: '<S831>/Compare'
     */
    VDHP_NMLiphomeInstFlt_flg = (VDHP_VCUPowerUpDelay2SWork_Flg &&
      (NM_output.VNM_TxLiphome_flg == 1));

    /* RelationalOperator: '<S836>/Compare' incorporates:
     *  Constant: '<S758>/Constant17'
     *  Constant: '<S836>/Constant'
     */
    rtb_LogicalOperator6_bor = (Vehicle_Type == K11E01R_Mark);

    /* Outputs for Atomic SubSystem: '<S832>/DHP_systemtick_Timer' */

    /* Logic: '<S832>/Logical Operator1' incorporates:
     *  Constant: '<S758>/Constant2'
     *  Delay: '<S832>/Delay'
     *  Logic: '<S758>/Logical Operator'
     *  Logic: '<S758>/Logical Operator1'
     *  RelationalOperator: '<S832>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c((!rtb_LogicalOperator6_bor) &&
      VDHP_OBC_CANLoseAuxCondition && (DHP_model_B.DataStoreRead35 ==
      DHP_model_DW.Delay_DSTATE_d), VDHP_deltaSystemTick_ms, ((uint16_T)
      DHP_MISSINGECUTIME_MS), &DHP_model_B.DHP_systemtick_Timer_fy,
      &DHP_model_DW.DHP_systemtick_Timer_fy);

    /* End of Outputs for SubSystem: '<S832>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S833>/DHP_systemtick_Timer' */

    /* Logic: '<S833>/Logical Operator1' incorporates:
     *  Constant: '<S758>/Constant6'
     *  Delay: '<S833>/Delay'
     *  RelationalOperator: '<S833>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(VDHP_OBC_CANLoseAuxCondition &&
      (DHP_model_B.DataStoreRead34 == DHP_model_DW.Delay_DSTATE_p),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_oz,
      &DHP_model_DW.DHP_systemtick_Timer_oz);

    /* End of Outputs for SubSystem: '<S833>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S834>/DHP_systemtick_Timer' */

    /* Logic: '<S834>/Logical Operator1' incorporates:
     *  Constant: '<S758>/Constant1'
     *  Delay: '<S834>/Delay'
     *  RelationalOperator: '<S834>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_c(VDHP_OBC_CANLoseAuxCondition &&
      (DHP_model_B.DataStoreRead36 == DHP_model_DW.Delay_DSTATE_f),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_MISSINGECUTIME_MS),
      &DHP_model_B.DHP_systemtick_Timer_nn,
      &DHP_model_DW.DHP_systemtick_Timer_nn);

    /* End of Outputs for SubSystem: '<S834>/DHP_systemtick_Timer' */

    /* Outputs for Atomic SubSystem: '<S835>/DHP_systemtick_Timer' */

    /* Logic: '<S835>/Logical Operator1' incorporates:
     *  Constant: '<S758>/Constant3'
     *  Delay: '<S835>/Delay'
     *  RelationalOperator: '<S835>/Relational Operator'
     */
    DHP_model_DHP_systemtick_Timer_p0(VDHP_OBC_CANLoseAuxCondition &&
      (DHP_model_B.DataStoreRead34 == DHP_model_DW.Delay_DSTATE_h),
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_100MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_p0);

    /* End of Outputs for SubSystem: '<S835>/DHP_systemtick_Timer' */

    /* Switch: '<S758>/Switch3' */
    rtb_LogicalOperator6_bor = (rtb_LogicalOperator6_bor ||
      DHP_model_B.DHP_systemtick_Timer_fy.RelationalOperator);

    /* Logic: '<S758>/Logical Operator6' */
    VDHP_OBCMissingtInstFlt_flg =
      (DHP_model_B.DHP_systemtick_Timer_oz.RelationalOperator &&
       rtb_LogicalOperator6_bor &&
       DHP_model_B.DHP_systemtick_Timer_nn.RelationalOperator);

    /* Logic: '<S758>/Logical Operator7' incorporates:
     *  Logic: '<S758>/Logical Operator2'
     *  Logic: '<S758>/Logical Operator4'
     *  Logic: '<S758>/Logical Operator8'
     */
    DHP_model_B.LogicalOperator7 =
      ((!DHP_model_B.DHP_systemtick_Timer_oz.RelationalOperator) &&
       (!DHP_model_B.DHP_systemtick_Timer_fy.RelationalOperator) &&
       (!DHP_model_B.DHP_systemtick_Timer_nn.RelationalOperator));

    /* Update for Delay: '<S832>/Delay' */
    DHP_model_DW.Delay_DSTATE_d = DHP_model_B.DataStoreRead35;

    /* Update for Delay: '<S833>/Delay' */
    DHP_model_DW.Delay_DSTATE_p = DHP_model_B.DataStoreRead34;

    /* Update for Delay: '<S834>/Delay' */
    DHP_model_DW.Delay_DSTATE_f = DHP_model_B.DataStoreRead36;

    /* Update for Delay: '<S835>/Delay' */
    DHP_model_DW.Delay_DSTATE_h = DHP_model_B.DataStoreRead34;

    /* Outputs for Atomic SubSystem: '<S759>/DHP_systemtick_Timer' */

    /* Logic: '<S759>/Logical Operator2' incorporates:
     *  Constant: '<S759>/Constant5'
     *  Delay: '<S759>/Delay4'
     *  RelationalOperator: '<S759>/Relational Operator4'
     */
    DHP_model_DHP_systemtick_Timer_c
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && (DHP_model_B.DataStoreRead55 == DHP_model_DW.Delay4_DSTATE_k),
       VDHP_deltaSystemTick_ms, ((uint16_T)DHP_300MSMSG_MISSINGTIME),
       &DHP_model_B.DHP_systemtick_Timer_kn,
       &DHP_model_DW.DHP_systemtick_Timer_kn);

    /* End of Outputs for SubSystem: '<S759>/DHP_systemtick_Timer' */

    /* Update for Delay: '<S759>/Delay4' */
    DHP_model_DW.Delay4_DSTATE_k = DHP_model_B.DataStoreRead55;

    /* Outputs for Atomic SubSystem: '<S760>/DHP_systemtick_Timer' */

    /* Logic: '<S760>/Logical Operator2' incorporates:
     *  Constant: '<S760>/Constant5'
     *  Delay: '<S760>/Delay4'
     *  RelationalOperator: '<S760>/Relational Operator4'
     */
    DHP_model_DHP_systemtick_Timer_i((DHP_model_B.DataStoreRead48 ==
      DHP_model_DW.Delay4_DSTATE_a) &&
      DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator,
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_500MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_i3);

    /* End of Outputs for SubSystem: '<S760>/DHP_systemtick_Timer' */

    /* Update for Delay: '<S760>/Delay4' */
    DHP_model_DW.Delay4_DSTATE_a = DHP_model_B.DataStoreRead48;
  }

  /* End of Outputs for SubSystem: '<S694>/MCU_LossCanNetInsFlt' */
  /* End of Outputs for SubSystem: '<S694>/NMLiphome_LossCanNetInsFlt' */
  /* End of Outputs for SubSystem: '<S694>/OBC_LossCanNetInsFlt' */
  /* End of Outputs for SubSystem: '<S694>/SRS_LossCanNetInsFlt' */
  /* End of Outputs for SubSystem: '<S694>/TBOX_LossCanNetInsFlt' */

  /* Outputs for Enabled SubSystem: '<S694>/TMS_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S761>/Enable'
   */
  /* Logic: '<S694>/Logical Operator12' incorporates:
   *  Constant: '<S761>/Constant5'
   *  Delay: '<S843>/Delay'
   *  Inport: '<Root>/Config'
   *  Logic: '<S694>/外置TMS'
   *  Logic: '<S843>/Logical Operator1'
   *  RelationalOperator: '<S843>/Relational Operator'
   */
  if (Config_output.C_TMS_En && (!Config_output.C_TMS_Internal) &&
      rtb_FixPtLogicalOperator_a) {
    /* Outputs for Atomic SubSystem: '<S843>/DHP_systemtick_Timer' */
    DHP_model_DHP_systemtick_Timer_ph
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
       && (DHP_model_B.DataStoreRead51 == DHP_model_DW.Delay_DSTATE_j),
       VDHP_deltaSystemTick_ms, ((uint16_T)DHP_100MSMSG_MISSINGTIME),
       &DHP_model_DW.DHP_systemtick_Timer_ph);

    /* End of Outputs for SubSystem: '<S843>/DHP_systemtick_Timer' */

    /* Update for Delay: '<S843>/Delay' incorporates:
     *  Constant: '<S761>/Constant5'
     *  Delay: '<S843>/Delay'
     *  Logic: '<S843>/Logical Operator1'
     *  RelationalOperator: '<S843>/Relational Operator'
     */
    DHP_model_DW.Delay_DSTATE_j = DHP_model_B.DataStoreRead51;
  }

  /* End of Logic: '<S694>/Logical Operator12' */
  /* End of Outputs for SubSystem: '<S694>/TMS_LossCanNetInsFlt' */

  /* Outputs for Enabled SubSystem: '<S694>/XBS_LossCanNetInsFlt' incorporates:
   *  EnablePort: '<S763>/Enable'
   */
  if (rtb_Compare_kvm) {
    /* Outputs for Atomic SubSystem: '<S763>/DHP_systemtick_Timer' */

    /* Logic: '<S763>/Logical Operator2' incorporates:
     *  Constant: '<S763>/Constant5'
     *  DataStoreRead: '<S687>/Data Store Read17'
     *  Delay: '<S763>/Delay4'
     *  RelationalOperator: '<S763>/Relational Operator4'
     */
    DHP_model_DHP_systemtick_Timer_ho((VHALI_XBS_241_MsgTicks ==
      DHP_model_DW.Delay4_DSTATE) &&
      DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator,
      VDHP_deltaSystemTick_ms, ((uint16_T)DHP_20MSMSG_MISSINGTIME),
      &DHP_model_DW.DHP_systemtick_Timer_ho);

    /* End of Outputs for SubSystem: '<S763>/DHP_systemtick_Timer' */

    /* Update for Delay: '<S763>/Delay4' incorporates:
     *  DataStoreRead: '<S687>/Data Store Read17'
     */
    DHP_model_DW.Delay4_DSTATE = VHALI_XBS_241_MsgTicks;
  }

  /* End of Outputs for SubSystem: '<S694>/XBS_LossCanNetInsFlt' */

  /* Outputs for Atomic SubSystem: '<S695>/DHP_systemtick_Timer' */

  /* Logic: '<S695>/Logical Operator12' incorporates:
   *  Constant: '<S695>/Constant'
   *  Delay: '<S695>/Delay'
   *  RelationalOperator: '<S695>/Relational Operator'
   */
  DHP_model_DHP_systemtick_Timer_c((DHP_model_B.DataStoreRead18 ==
    DHP_model_DW.Delay_DSTATE_i) && rtb_LogicalOperator19_po,
    VDHP_deltaSystemTick_ms, KDHP_VCUCanNetLineOffTime_ms,
    &DHP_model_B.DHP_systemtick_Timer_j, &DHP_model_DW.DHP_systemtick_Timer_j);

  /* End of Outputs for SubSystem: '<S695>/DHP_systemtick_Timer' */

  /* Logic: '<S695>/Logical Operator1' */
  VDHP_VCUHCanNetLineOffInstFlt_flg =
    (DHP_model_B.DHP_systemtick_Timer_n.RelationalOperator &&
     DHP_model_B.DHP_systemtick_Timer_j.RelationalOperator);

  /* Logic: '<S695>/Logical Operator2' */
  DHP_model_B.LogicalOperator2_b =
    !DHP_model_B.DHP_systemtick_Timer_j.RelationalOperator;

  /* RelationalOperator: '<S698>/Compare' incorporates:
   *  Constant: '<S698>/Constant'
   *  DataStoreRead: '<S687>/Data Store Read'
   */
  VDHP_PTBusOffInstFlt_Flg = (PTBusOffConfirmedFlag > 0);

  /* Update for Delay: '<S689>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_p = DHP_model_B.DataStoreRead17;

  /* Update for Delay: '<S695>/Delay' */
  DHP_model_DW.Delay_DSTATE_i = DHP_model_B.DataStoreRead18;
}

/* System initialize for atomic system: '<S12>/VehDriveSysInstErrGenerate' */
void DHP_model_VehDriveSysInstErrGenerate_Init(void)
{
  /* SystemInitialize for Triggered SubSystem: '<S882>/CoolErrMotTempUpRate' */
  /* InitializeConditions for UnitDelay: '<S1004>/UnitDelay2' */
  DHP_model_DW.UnitDelay2_DSTATE = 80;

  /* End of SystemInitialize for SubSystem: '<S882>/CoolErrMotTempUpRate' */
}

/* Output and update for atomic system: '<S12>/VehDriveSysInstErrGenerate' */
void DHP_model_VehDriveSysInstErrGenerate(void)
{
  boolean_T rtb_Compare_m5y;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator_mr;
  boolean_T rtb_LogicalOperator10_gt;
  boolean_T rtb_LogicalOperator3_av3;
  boolean_T rtb_LogicalOperator4_ci;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_LogicalOperator3_f;
  uint32_T rtb_Add1_iw;
  boolean_T rtb_LogicalOperator1_du;
  boolean_T rtb_LogicalOperator1_n5;
  boolean_T rtb_LogicalOperator8_l;
  uint8_T rtb_LogicalOperator_mq;

  /* RelationalOperator: '<S854>/Compare' incorporates:
   *  Constant: '<S849>/Constant5'
   *  Constant: '<S854>/Constant'
   */
  rtb_Compare_m5y = (Vehicle_Type == A11_Mark);

  /* Logic: '<S849>/Logical Operator1' incorporates:
   *  Constant: '<S849>/Constant13'
   *  Constant: '<S851>/Constant'
   *  Constant: '<S852>/Constant'
   *  Constant: '<S856>/Constant'
   *  Constant: '<S857>/Constant'
   *  Constant: '<S859>/Constant'
   *  RelationalOperator: '<S851>/Compare'
   *  RelationalOperator: '<S852>/Compare'
   *  RelationalOperator: '<S856>/Compare'
   *  RelationalOperator: '<S857>/Compare'
   *  RelationalOperator: '<S859>/Compare'
   */
  rtb_LogicalOperator1 = ((Vehicle_Type == K11_Mark) || (Vehicle_Type ==
    K11P01_Mark) || (Vehicle_Type == K11E01R_Mark) || (Vehicle_Type ==
    K11P06_Mark) || (Vehicle_Type == ((uint8_T)Z18_MARK)));

  /* Logic: '<S849>/Logical Operator' */
  rtb_LogicalOperator_mr = !rtb_LogicalOperator1;

  /* Logic: '<S849>/Logical Operator10' incorporates:
   *  Constant: '<S849>/Constant7'
   *  Constant: '<S850>/Constant'
   *  Constant: '<S853>/Constant'
   *  Constant: '<S855>/Constant'
   *  Constant: '<S858>/Constant'
   *  Constant: '<S860>/Constant'
   *  RelationalOperator: '<S850>/Compare'
   *  RelationalOperator: '<S853>/Compare'
   *  RelationalOperator: '<S855>/Compare'
   *  RelationalOperator: '<S858>/Compare'
   *  RelationalOperator: '<S860>/Compare'
   */
  rtb_LogicalOperator10_gt = ((Vehicle_Type == S21_Mark) || (Vehicle_Type ==
    S11P03_Mark) || (Vehicle_Type == S11P01_Mark) || (Vehicle_Type == ((uint8_T)
    S11P04_MARK)) || (Vehicle_Type == S11P05_Mark));

  /* Logic: '<S849>/Logical Operator3' */
  rtb_LogicalOperator3_av3 = !rtb_Compare_m5y;

  /* Logic: '<S849>/Logical Operator4' */
  rtb_LogicalOperator4_ci = !rtb_LogicalOperator10_gt;

  /* RelationalOperator: '<S849>/Relational Operator' incorporates:
   *  Constant: '<S849>/Constant6'
   */
  rtb_RelationalOperator = (DHP_model_B.DataStoreRead1_j == ((uint8_T)
    DHP_HW_VCU20));

  /* Outputs for Enabled SubSystem: '<S849>/MCU_A11_Err' incorporates:
   *  EnablePort: '<S861>/Enable'
   */
  /* Logic: '<S849>/Logical Operator9' */
  if (rtb_Compare_m5y && rtb_RelationalOperator) {
    /* Logic: '<S861>/Logical Operator1' incorporates:
     *  Constant: '<S892>/Constant'
     *  RelationalOperator: '<S892>/Compare'
     */
    rtb_LogicalOperator1_du =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2));

    /* Logic: '<S861>/Logical Operator10' incorporates:
     *  Constant: '<S904>/Constant'
     *  RelationalOperator: '<S904>/Compare'
     */
    VDHP_MCUCANBusOffInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 31));

    /* Logic: '<S861>/Logical Operator11' incorporates:
     *  Constant: '<S894>/Constant'
     *  RelationalOperator: '<S894>/Compare'
     */
    VDHP_MCUDCUOverUHWInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 32));

    /* Logic: '<S861>/Logical Operator12' incorporates:
     *  Constant: '<S895>/Constant'
     *  RelationalOperator: '<S895>/Compare'
     */
    VDHP_MCUHWSamplingInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 33));

    /* Logic: '<S861>/Logical Operator13' incorporates:
     *  Constant: '<S896>/Constant'
     *  RelationalOperator: '<S896>/Compare'
     */
    VDHP_MCUChipPowerInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 34));

    /* Logic: '<S861>/Logical Operator3' incorporates:
     *  Constant: '<S893>/Constant'
     *  RelationalOperator: '<S893>/Compare'
     */
    VDHP_MCUElecMotUnderTInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 27));

    /* Logic: '<S861>/Logical Operator4' incorporates:
     *  Constant: '<S898>/Constant'
     *  RelationalOperator: '<S898>/Compare'
     */
    VDHP_MCUIGBTUnderTInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 35));

    /* Logic: '<S861>/Logical Operator5' incorporates:
     *  Constant: '<S899>/Constant'
     *  RelationalOperator: '<S899>/Compare'
     */
    VDHP_MCUElecMotOverSpdFltInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 20));

    /* Logic: '<S861>/Logical Operator6' incorporates:
     *  Constant: '<S900>/Constant'
     *  RelationalOperator: '<S900>/Compare'
     */
    VDHP_MCUDcUUnderUFltInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 22));

    /* Logic: '<S861>/Logical Operator7' incorporates:
     *  Constant: '<S901>/Constant'
     *  RelationalOperator: '<S901>/Compare'
     */
    VDHP_MCUElecMotOverTFltInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 28));

    /* Logic: '<S861>/Logical Operator8' incorporates:
     *  Constant: '<S902>/Constant'
     *  RelationalOperator: '<S902>/Compare'
     */
    VDHP_MCUIGBTOverTFltInstFlt_Flg = (rtb_LogicalOperator1_du &&
      (DHP_model_B.VINP_MCUErrNum == 29));

    /* Logic: '<S861>/Logical Operator9' incorporates:
     *  Constant: '<S897>/Constant'
     *  Constant: '<S903>/Constant'
     *  Logic: '<S861>/Logical Operator2'
     *  RelationalOperator: '<S897>/Compare'
     *  RelationalOperator: '<S903>/Compare'
     */
    VDHP_MCUVersionMismatchInstFlt_Flg = ((DHP_model_B.VINP_MCUFltRnk_enum == 3)
      &&
      DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
      && (DHP_model_B.VINP_MCUErrNum == 30));
  }

  /* End of Logic: '<S849>/Logical Operator9' */
  /* End of Outputs for SubSystem: '<S849>/MCU_A11_Err' */

  /* Logic: '<S862>/Logical Operator3' incorporates:
   *  Constant: '<S905>/Constant'
   *  Constant: '<S906>/Constant'
   *  RelationalOperator: '<S905>/Compare'
   *  RelationalOperator: '<S906>/Compare'
   */
  VDHP_MCUCANComInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
      6));

  /* Outputs for Enabled SubSystem: '<S849>/MCU_DcCrrt_RedundErr' incorporates:
   *  EnablePort: '<S864>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S849>/MCU_DCUShoCirc_Err' incorporates:
   *  EnablePort: '<S863>/Enable'
   */
  /* Logic: '<S849>/Logical Operator7' */
  if (rtb_LogicalOperator_mr && rtb_LogicalOperator4_ci) {
    /* Logic: '<S863>/Logical Operator3' incorporates:
     *  Constant: '<S907>/Constant'
     *  Constant: '<S908>/Constant'
     *  RelationalOperator: '<S907>/Compare'
     *  RelationalOperator: '<S908>/Compare'
     */
    VDHP_MCUDcUShoCircInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 3) && (DHP_model_B.VINP_MCUErrNum ==
        14));

    /* Logic: '<S864>/Logical Operator3' incorporates:
     *  Constant: '<S864>/Constant13'
     *  Constant: '<S909>/Constant'
     *  RelationalOperator: '<S864>/Relational Operator'
     *  RelationalOperator: '<S909>/Compare'
     */
    VDHP_MCUDcCrrtOverURedundInstFlt_flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
      (DHP_model_B.VINP_MCUFltRnk_enum != 3) && (DHP_model_B.DataTypeConversion6
      > KDHP_MCU_DcCrrtErrValue_A));
  }

  /* End of Logic: '<S849>/Logical Operator7' */
  /* End of Outputs for SubSystem: '<S849>/MCU_DCUShoCirc_Err' */
  /* End of Outputs for SubSystem: '<S849>/MCU_DcCrrt_RedundErr' */

  /* Outputs for Enabled SubSystem: '<S849>/MCU_DcUSnsrRati_Err' incorporates:
   *  EnablePort: '<S865>/Enable'
   */
  /* Logic: '<S849>/Logical Operator12' */
  if (rtb_LogicalOperator3_av3 && rtb_LogicalOperator4_ci) {
    /* Logic: '<S865>/Logical Operator3' incorporates:
     *  Constant: '<S910>/Constant'
     *  Constant: '<S911>/Constant'
     *  RelationalOperator: '<S910>/Compare'
     *  RelationalOperator: '<S911>/Compare'
     */
    VDHP_MCUDcUSnsrRatiInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
        24));
  }

  /* End of Logic: '<S849>/Logical Operator12' */
  /* End of Outputs for SubSystem: '<S849>/MCU_DcUSnsrRati_Err' */

  /* RelationalOperator: '<S912>/Compare' incorporates:
   *  Constant: '<S912>/Constant'
   */
  rtb_LogicalOperator1_du = (DHP_model_B.VINP_MCUFltRnk_enum == 2);

  /* Logic: '<S866>/Logical Operator3' incorporates:
   *  Constant: '<S913>/Constant'
   *  RelationalOperator: '<S913>/Compare'
   */
  rtb_LogicalOperator3_f =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && rtb_LogicalOperator1_du && (DHP_model_B.VINP_MCUErrNum == 3));

  /* Switch: '<S866>/Switch1' incorporates:
   *  Constant: '<S866>/Constant'
   *  Switch: '<S866>/Switch2'
   *  Switch: '<S866>/Switch3'
   *  Switch: '<S866>/Switch4'
   */
  if (rtb_LogicalOperator10_gt) {
    VDHP_MCUDcUOverUWarnInstFlt_Flg = false;
    VDHP_MCUDcUOverUFltInstFlt_Flg = rtb_LogicalOperator3_f;
  } else if (rtb_Compare_m5y) {
    /* Switch: '<S866>/Switch2' */
    VDHP_MCUDcUOverUWarnInstFlt_Flg = rtb_LogicalOperator3_f;

    /* Switch: '<S866>/Switch3' incorporates:
     *  Constant: '<S914>/Constant'
     *  Logic: '<S866>/Logical Operator4'
     *  RelationalOperator: '<S914>/Compare'
     */
    VDHP_MCUDcUOverUFltInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && rtb_LogicalOperator1_du && (DHP_model_B.VINP_MCUErrNum == 23));
  } else {
    /* Switch: '<S866>/Switch2' incorporates:
     *  Constant: '<S866>/Constant1'
     *  Constant: '<S866>/Constant13'
     *  Logic: '<S866>/Logical Operator1'
     *  RelationalOperator: '<S866>/Relational Operator'
     *  RelationalOperator: '<S866>/Relational Operator1'
     */
    VDHP_MCUDcUOverUWarnInstFlt_Flg = (rtb_LogicalOperator3_f &&
      (DHP_model_B.DataTypeConversion5 >= KDHP_MCUErrNum3Value_V1) &&
      (DHP_model_B.DataTypeConversion5 < KDHP_MCUErrNum3Value_V2));

    /* Switch: '<S866>/Switch3' incorporates:
     *  Constant: '<S866>/Constant5'
     *  Logic: '<S866>/Logical Operator2'
     *  RelationalOperator: '<S866>/Relational Operator3'
     */
    VDHP_MCUDcUOverUFltInstFlt_Flg = (rtb_LogicalOperator3_f &&
      (DHP_model_B.DataTypeConversion5 >= KDHP_MCUErrNum3Value_V2));
  }

  /* End of Switch: '<S866>/Switch1' */

  /* Logic: '<S867>/Logical Operator1' incorporates:
   *  Constant: '<S867>/Constant13'
   *  Constant: '<S915>/Constant'
   *  RelationalOperator: '<S867>/Relational Operator'
   *  RelationalOperator: '<S915>/Compare'
   */
  VDHP_MCUDcUOverURedundInstFlt_flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
    (DHP_model_B.VINP_MCUFltRnk_enum != 2) && (DHP_model_B.DataTypeConversion5 >
    KDHP_MCU_DcUErrValue_V));

  /* Logic: '<S868>/Logical Operator3' incorporates:
   *  Constant: '<S916>/Constant'
   *  Constant: '<S917>/Constant'
   *  RelationalOperator: '<S916>/Compare'
   *  RelationalOperator: '<S917>/Compare'
   */
  VDHP_MCUDcUUnderUWarnInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
      2));

  /* Logic: '<S869>/Logical Operator3' incorporates:
   *  Constant: '<S918>/Constant'
   *  Constant: '<S919>/Constant'
   *  RelationalOperator: '<S918>/Compare'
   *  RelationalOperator: '<S919>/Compare'
   */
  VDHP_MCUDischrgInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
      10));

  /* Outputs for Enabled SubSystem: '<S849>/MCU_ElecMotReslv_Err' incorporates:
   *  EnablePort: '<S870>/Enable'
   */
  if (rtb_LogicalOperator3_av3) {
    /* Logic: '<S870>/Logical Operator3' incorporates:
     *  Constant: '<S920>/Constant'
     *  Constant: '<S921>/Constant'
     *  RelationalOperator: '<S920>/Compare'
     *  RelationalOperator: '<S921>/Compare'
     */
    VDHP_MCUElecMotReslvInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
        19));
  }

  /* End of Outputs for SubSystem: '<S849>/MCU_ElecMotReslv_Err' */

  /* Outputs for Enabled SubSystem: '<S849>/MCU_ElecMotStopTurn_Err' incorporates:
   *  EnablePort: '<S871>/Enable'
   */
  if (rtb_LogicalOperator4_ci) {
    /* Logic: '<S871>/Logical Operator3' incorporates:
     *  Constant: '<S922>/Constant'
     *  Constant: '<S923>/Constant'
     *  RelationalOperator: '<S922>/Compare'
     *  RelationalOperator: '<S923>/Compare'
     */
    VDHP_MCUElecMotStopTurnInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
        7));
  }

  /* End of Outputs for SubSystem: '<S849>/MCU_ElecMotStopTurn_Err' */

  /* Switch: '<S872>/Switch' incorporates:
   *  Constant: '<S924>/Constant'
   *  Constant: '<S926>/Constant'
   *  RelationalOperator: '<S924>/Compare'
   *  RelationalOperator: '<S926>/Compare'
   */
  if (rtb_LogicalOperator10_gt) {
    rtb_LogicalOperator1_du = (DHP_model_B.VINP_MCUFltRnk_enum == 1);
  } else {
    rtb_LogicalOperator1_du = (DHP_model_B.VINP_MCUFltRnk_enum == 2);
  }

  /* End of Switch: '<S872>/Switch' */

  /* Logic: '<S872>/Logical Operator3' incorporates:
   *  Constant: '<S925>/Constant'
   *  RelationalOperator: '<S925>/Compare'
   */
  VDHP_MCUElecMotTSnsrRatiInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUErrNum == 26) && rtb_LogicalOperator1_du);

  /* Logic: '<S873>/Logical Operator3' incorporates:
   *  Constant: '<S927>/Constant'
   *  Constant: '<S928>/Constant'
   *  RelationalOperator: '<S927>/Compare'
   *  RelationalOperator: '<S928>/Compare'
   */
  VDHP_MCUElecMotOverCrrtInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
      4));

  /* RelationalOperator: '<S929>/Compare' incorporates:
   *  Constant: '<S929>/Constant'
   */
  DHP_model_B.Compare_hq = (DHP_model_B.VINP_MCUFltRnk_enum < 2);

  /* Outputs for Enabled SubSystem: '<S874>/K_TYPE' incorporates:
   *  EnablePort: '<S930>/Enable'
   */
  if (rtb_LogicalOperator1) {
    /* Logic: '<S930>/Logical Operator3' incorporates:
     *  RelationalOperator: '<S930>/Relational Operator1'
     */
    rtb_LogicalOperator1_du =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2));

    /* DataTypeConversion: '<S930>/Data Type Conversion' */
    VDHP_MCUInstFlt2_flg = rtb_LogicalOperator1_du;

    /* Logic: '<S930>/Logical Operator4' incorporates:
     *  RelationalOperator: '<S930>/Relational Operator2'
     */
    rtb_LogicalOperator3_f =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 3));

    /* DataTypeConversion: '<S930>/Data Type Conversion1' */
    VDHP_MCUInstFlt3_flg = rtb_LogicalOperator3_f;

    /* Logic: '<S930>/Logical Operator1' incorporates:
     *  Constant: '<S934>/Constant'
     *  Constant: '<S937>/Constant'
     *  Constant: '<S938>/Constant'
     *  Constant: '<S939>/Constant'
     *  Constant: '<S940>/Constant'
     *  Constant: '<S941>/Constant'
     *  Constant: '<S942>/Constant'
     *  Constant: '<S943>/Constant'
     *  Constant: '<S944>/Constant'
     *  Constant: '<S945>/Constant'
     *  Logic: '<S930>/Logical Operator33'
     *  Logic: '<S930>/Logical Operator6'
     *  Logic: '<S930>/Logical Operator7'
     *  RelationalOperator: '<S934>/Compare'
     *  RelationalOperator: '<S937>/Compare'
     *  RelationalOperator: '<S938>/Compare'
     *  RelationalOperator: '<S939>/Compare'
     *  RelationalOperator: '<S940>/Compare'
     *  RelationalOperator: '<S941>/Compare'
     *  RelationalOperator: '<S942>/Compare'
     *  RelationalOperator: '<S943>/Compare'
     *  RelationalOperator: '<S944>/Compare'
     *  RelationalOperator: '<S945>/Compare'
     */
    rtb_LogicalOperator1_n5 = (((DHP_model_B.VINP_MCUErrNum >= 1) &&
      (DHP_model_B.VINP_MCUErrNum <= 8)) || ((DHP_model_B.VINP_MCUErrNum >= 12) &&
      (DHP_model_B.VINP_MCUErrNum <= 13)) || (DHP_model_B.VINP_MCUErrNum == 16) ||
      (DHP_model_B.VINP_MCUErrNum == 10) || (DHP_model_B.VINP_MCUErrNum == 19) ||
      ((DHP_model_B.VINP_MCUErrNum >= 24) && (DHP_model_B.VINP_MCUErrNum <= 26))
      || (DHP_model_B.VINP_MCUErrNum == 38));

    /* DataTypeConversion: '<S930>/Data Type Conversion2' */
    DHP_model_B.Merge2 = rtb_LogicalOperator1_n5;

    /* Logic: '<S930>/Logical Operator8' incorporates:
     *  Constant: '<S935>/Constant'
     *  Constant: '<S936>/Constant'
     *  RelationalOperator: '<S935>/Compare'
     *  RelationalOperator: '<S936>/Compare'
     */
    rtb_LogicalOperator8_l = ((DHP_model_B.VINP_MCUErrNum == 9) ||
      (DHP_model_B.VINP_MCUErrNum == 15));

    /* DataTypeConversion: '<S930>/Data Type Conversion3' */
    DHP_model_B.Merge5 = rtb_LogicalOperator8_l;

    /* Logic: '<S930>/Logical Operator5' incorporates:
     *  Logic: '<S930>/Logical Operator11'
     */
    DHP_model_B.Merge1 = (rtb_LogicalOperator1_du && (!rtb_LogicalOperator1_n5));

    /* Logic: '<S930>/Logical Operator9' incorporates:
     *  Logic: '<S930>/Logical Operator10'
     */
    DHP_model_B.Merge4 = (rtb_LogicalOperator3_f && (!rtb_LogicalOperator8_l));
  }

  /* End of Outputs for SubSystem: '<S874>/K_TYPE' */

  /* Outputs for Enabled SubSystem: '<S874>/NOT_K_TYPE' incorporates:
   *  EnablePort: '<S931>/Enable'
   */
  /* Logic: '<S874>/Logical Operator14' incorporates:
   *  Logic: '<S874>/Logical Operator'
   *  Logic: '<S874>/Logical Operator1'
   *  Logic: '<S874>/Logical Operator13'
   */
  if ((!rtb_Compare_m5y) && (!rtb_LogicalOperator1) &&
      (!rtb_LogicalOperator10_gt)) {
    /* Logic: '<S931>/Logical Operator3' incorporates:
     *  RelationalOperator: '<S931>/Relational Operator1'
     */
    rtb_LogicalOperator1_du =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2));

    /* DataTypeConversion: '<S931>/Data Type Conversion' */
    VDHP_MCUInstFlt2_flg = rtb_LogicalOperator1_du;

    /* Logic: '<S931>/Logical Operator4' incorporates:
     *  RelationalOperator: '<S931>/Relational Operator2'
     */
    rtb_LogicalOperator3_f =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 3));

    /* DataTypeConversion: '<S931>/Data Type Conversion1' */
    VDHP_MCUInstFlt3_flg = rtb_LogicalOperator3_f;

    /* Logic: '<S931>/Logical Operator1' incorporates:
     *  Constant: '<S946>/Constant'
     *  Constant: '<S950>/Constant'
     *  Constant: '<S951>/Constant'
     *  Constant: '<S952>/Constant'
     *  Constant: '<S953>/Constant'
     *  Constant: '<S954>/Constant'
     *  Constant: '<S955>/Constant'
     *  Constant: '<S956>/Constant'
     *  Constant: '<S958>/Constant'
     *  Constant: '<S959>/Constant'
     *  Logic: '<S931>/Logical Operator33'
     *  Logic: '<S931>/Logical Operator6'
     *  Logic: '<S931>/Logical Operator7'
     *  RelationalOperator: '<S946>/Compare'
     *  RelationalOperator: '<S950>/Compare'
     *  RelationalOperator: '<S951>/Compare'
     *  RelationalOperator: '<S952>/Compare'
     *  RelationalOperator: '<S953>/Compare'
     *  RelationalOperator: '<S954>/Compare'
     *  RelationalOperator: '<S955>/Compare'
     *  RelationalOperator: '<S956>/Compare'
     *  RelationalOperator: '<S958>/Compare'
     *  RelationalOperator: '<S959>/Compare'
     */
    rtb_LogicalOperator1_n5 = (((DHP_model_B.VINP_MCUErrNum >= 1) &&
      (DHP_model_B.VINP_MCUErrNum <= 7)) || ((DHP_model_B.VINP_MCUErrNum >= 10) &&
      (DHP_model_B.VINP_MCUErrNum <= 13)) || (DHP_model_B.VINP_MCUErrNum == 16) ||
      (DHP_model_B.VINP_MCUErrNum == 18) || (DHP_model_B.VINP_MCUErrNum == 19) ||
      ((DHP_model_B.VINP_MCUErrNum >= 24) && (DHP_model_B.VINP_MCUErrNum <= 27))
      || (DHP_model_B.VINP_MCUErrNum == 35));

    /* DataTypeConversion: '<S931>/Data Type Conversion2' */
    DHP_model_B.Merge2 = rtb_LogicalOperator1_n5;

    /* Logic: '<S931>/Logical Operator8' incorporates:
     *  Constant: '<S947>/Constant'
     *  Constant: '<S948>/Constant'
     *  Constant: '<S949>/Constant'
     *  Constant: '<S957>/Constant'
     *  RelationalOperator: '<S947>/Compare'
     *  RelationalOperator: '<S948>/Compare'
     *  RelationalOperator: '<S949>/Compare'
     *  RelationalOperator: '<S957>/Compare'
     */
    rtb_LogicalOperator8_l = ((DHP_model_B.VINP_MCUErrNum == 8) ||
      (DHP_model_B.VINP_MCUErrNum == 9) || (DHP_model_B.VINP_MCUErrNum == 14) ||
      (DHP_model_B.VINP_MCUErrNum == 15));

    /* DataTypeConversion: '<S931>/Data Type Conversion3' */
    DHP_model_B.Merge5 = rtb_LogicalOperator8_l;

    /* Logic: '<S931>/Logical Operator5' incorporates:
     *  Logic: '<S931>/Logical Operator11'
     */
    DHP_model_B.Merge1 = (rtb_LogicalOperator1_du && (!rtb_LogicalOperator1_n5));

    /* Logic: '<S931>/Logical Operator9' incorporates:
     *  Logic: '<S931>/Logical Operator10'
     */
    DHP_model_B.Merge4 = (rtb_LogicalOperator3_f && (!rtb_LogicalOperator8_l));
  }

  /* End of Logic: '<S874>/Logical Operator14' */
  /* End of Outputs for SubSystem: '<S874>/NOT_K_TYPE' */

  /* Outputs for Enabled SubSystem: '<S874>/S11P01_TYPE' incorporates:
   *  EnablePort: '<S932>/Enable'
   */
  if (rtb_LogicalOperator10_gt) {
    /* RelationalOperator: '<S961>/Compare' incorporates:
     *  Constant: '<S961>/Constant'
     */
    rtb_LogicalOperator1_du = (DHP_model_B.VINP_MCUErrNum == 9);

    /* Logic: '<S932>/Logical Operator3' incorporates:
     *  RelationalOperator: '<S932>/Relational Operator1'
     */
    rtb_LogicalOperator3_f =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2));

    /* DataTypeConversion: '<S932>/Data Type Conversion' */
    VDHP_MCUInstFlt2_flg = rtb_LogicalOperator3_f;

    /* Logic: '<S932>/Logical Operator4' incorporates:
     *  RelationalOperator: '<S932>/Relational Operator2'
     */
    rtb_LogicalOperator1_n5 =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 3));

    /* DataTypeConversion: '<S932>/Data Type Conversion1' */
    VDHP_MCUInstFlt3_flg = rtb_LogicalOperator1_n5;

    /* Logic: '<S932>/Logical Operator1' incorporates:
     *  Constant: '<S960>/Constant'
     *  Constant: '<S962>/Constant'
     *  Constant: '<S963>/Constant'
     *  Constant: '<S964>/Constant'
     *  Constant: '<S965>/Constant'
     *  Constant: '<S966>/Constant'
     *  Constant: '<S967>/Constant'
     *  Constant: '<S968>/Constant'
     *  Constant: '<S969>/Constant'
     *  Constant: '<S970>/Constant'
     *  Logic: '<S932>/Logical Operator33'
     *  Logic: '<S932>/Logical Operator6'
     *  Logic: '<S932>/Logical Operator7'
     *  RelationalOperator: '<S960>/Compare'
     *  RelationalOperator: '<S962>/Compare'
     *  RelationalOperator: '<S963>/Compare'
     *  RelationalOperator: '<S964>/Compare'
     *  RelationalOperator: '<S965>/Compare'
     *  RelationalOperator: '<S966>/Compare'
     *  RelationalOperator: '<S967>/Compare'
     *  RelationalOperator: '<S968>/Compare'
     *  RelationalOperator: '<S969>/Compare'
     *  RelationalOperator: '<S970>/Compare'
     */
    rtb_LogicalOperator8_l = (((DHP_model_B.VINP_MCUErrNum >= 1) &&
      (DHP_model_B.VINP_MCUErrNum <= 6)) || ((DHP_model_B.VINP_MCUErrNum >= 10) &&
      (DHP_model_B.VINP_MCUErrNum <= 12)) || (DHP_model_B.VINP_MCUErrNum == 16) ||
      (DHP_model_B.VINP_MCUErrNum == 19) || ((DHP_model_B.VINP_MCUErrNum >= 37) &&
      (DHP_model_B.VINP_MCUErrNum <= 39)) || (DHP_model_B.VINP_MCUErrNum == 8) ||
      (DHP_model_B.VINP_MCUErrNum == 15));

    /* DataTypeConversion: '<S932>/Data Type Conversion2' */
    DHP_model_B.Merge2 = rtb_LogicalOperator8_l;

    /* DataTypeConversion: '<S932>/Data Type Conversion3' */
    DHP_model_B.Merge5 = rtb_LogicalOperator1_du;

    /* Logic: '<S932>/Logical Operator5' incorporates:
     *  Logic: '<S932>/Logical Operator11'
     */
    DHP_model_B.Merge1 = (rtb_LogicalOperator3_f && (!rtb_LogicalOperator8_l));

    /* Logic: '<S932>/Logical Operator9' incorporates:
     *  Logic: '<S932>/Logical Operator10'
     */
    DHP_model_B.Merge4 = (rtb_LogicalOperator1_n5 && (!rtb_LogicalOperator1_du));
  }

  /* End of Outputs for SubSystem: '<S874>/S11P01_TYPE' */

  /* Outputs for Enabled SubSystem: '<S874>/S11P01_TYPE1' incorporates:
   *  EnablePort: '<S933>/Enable'
   */
  if (rtb_Compare_m5y) {
    /* Logic: '<S933>/Logical Operator3' incorporates:
     *  RelationalOperator: '<S933>/Relational Operator1'
     */
    rtb_LogicalOperator1_du =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2));

    /* DataTypeConversion: '<S933>/Data Type Conversion' */
    VDHP_MCUInstFlt2_flg = rtb_LogicalOperator1_du;

    /* Logic: '<S933>/Logical Operator4' incorporates:
     *  RelationalOperator: '<S933>/Relational Operator2'
     */
    rtb_LogicalOperator3_f =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 3));

    /* DataTypeConversion: '<S933>/Data Type Conversion1' */
    VDHP_MCUInstFlt3_flg = rtb_LogicalOperator3_f;

    /* Logic: '<S933>/Logical Operator1' incorporates:
     *  Constant: '<S971>/Constant'
     *  Constant: '<S976>/Constant'
     *  Constant: '<S977>/Constant'
     *  Constant: '<S978>/Constant'
     *  Constant: '<S979>/Constant'
     *  Constant: '<S980>/Constant'
     *  Constant: '<S981>/Constant'
     *  Constant: '<S982>/Constant'
     *  Constant: '<S983>/Constant'
     *  Constant: '<S984>/Constant'
     *  Constant: '<S985>/Constant'
     *  Constant: '<S986>/Constant'
     *  Constant: '<S988>/Constant'
     *  Constant: '<S989>/Constant'
     *  Logic: '<S933>/Logical Operator2'
     *  Logic: '<S933>/Logical Operator33'
     *  Logic: '<S933>/Logical Operator6'
     *  Logic: '<S933>/Logical Operator7'
     *  RelationalOperator: '<S971>/Compare'
     *  RelationalOperator: '<S976>/Compare'
     *  RelationalOperator: '<S977>/Compare'
     *  RelationalOperator: '<S978>/Compare'
     *  RelationalOperator: '<S979>/Compare'
     *  RelationalOperator: '<S980>/Compare'
     *  RelationalOperator: '<S981>/Compare'
     *  RelationalOperator: '<S982>/Compare'
     *  RelationalOperator: '<S983>/Compare'
     *  RelationalOperator: '<S984>/Compare'
     *  RelationalOperator: '<S985>/Compare'
     *  RelationalOperator: '<S986>/Compare'
     *  RelationalOperator: '<S988>/Compare'
     *  RelationalOperator: '<S989>/Compare'
     */
    rtb_LogicalOperator1_n5 = (((DHP_model_B.VINP_MCUErrNum >= 1) &&
      (DHP_model_B.VINP_MCUErrNum <= 7)) || ((DHP_model_B.VINP_MCUErrNum >= 10) &&
      (DHP_model_B.VINP_MCUErrNum <= 11)) || (DHP_model_B.VINP_MCUErrNum == 16) ||
      (DHP_model_B.VINP_MCUErrNum == 20) || (DHP_model_B.VINP_MCUErrNum == 22) ||
      ((DHP_model_B.VINP_MCUErrNum >= 26) && (DHP_model_B.VINP_MCUErrNum <= 29))
      || (DHP_model_B.VINP_MCUErrNum == 23) || ((DHP_model_B.VINP_MCUErrNum >=
      31) && (DHP_model_B.VINP_MCUErrNum <= 35)) || (DHP_model_B.VINP_MCUErrNum ==
      39) || (DHP_model_B.VINP_MCUErrNum == 40));

    /* DataTypeConversion: '<S933>/Data Type Conversion2' */
    DHP_model_B.Merge2 = rtb_LogicalOperator1_n5;

    /* Logic: '<S933>/Logical Operator8' incorporates:
     *  Constant: '<S972>/Constant'
     *  Constant: '<S973>/Constant'
     *  Constant: '<S974>/Constant'
     *  Constant: '<S975>/Constant'
     *  Constant: '<S987>/Constant'
     *  RelationalOperator: '<S972>/Compare'
     *  RelationalOperator: '<S973>/Compare'
     *  RelationalOperator: '<S974>/Compare'
     *  RelationalOperator: '<S975>/Compare'
     *  RelationalOperator: '<S987>/Compare'
     */
    rtb_LogicalOperator8_l = ((DHP_model_B.VINP_MCUErrNum == 8) ||
      (DHP_model_B.VINP_MCUErrNum == 9) || (DHP_model_B.VINP_MCUErrNum == 14) ||
      (DHP_model_B.VINP_MCUErrNum == 15) || (DHP_model_B.VINP_MCUErrNum == 30));

    /* DataTypeConversion: '<S933>/Data Type Conversion3' */
    DHP_model_B.Merge5 = rtb_LogicalOperator8_l;

    /* Logic: '<S933>/Logical Operator5' incorporates:
     *  Logic: '<S933>/Logical Operator11'
     */
    DHP_model_B.Merge1 = (rtb_LogicalOperator1_du && (!rtb_LogicalOperator1_n5));

    /* Logic: '<S933>/Logical Operator9' incorporates:
     *  Logic: '<S933>/Logical Operator10'
     */
    DHP_model_B.Merge4 = (rtb_LogicalOperator3_f && (!rtb_LogicalOperator8_l));
  }

  /* End of Outputs for SubSystem: '<S874>/S11P01_TYPE1' */

  /* Logic: '<S874>/Logical Operator12' */
  VDHP_MCUFltUnmatchInstFlt_Flg = (DHP_model_B.Merge1 || DHP_model_B.Merge4);

  /* Logic: '<S874>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S874>/Relational Operator'
   */
  VDHP_MCUInstFlt1_flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
    (DHP_model_B.VINP_MCUFltRnk_enum == 1));

  /* Switch: '<S875>/Switch' incorporates:
   *  Constant: '<S990>/Constant'
   *  Constant: '<S992>/Constant'
   *  Logic: '<S849>/Logical Operator11'
   *  RelationalOperator: '<S990>/Compare'
   *  RelationalOperator: '<S992>/Compare'
   */
  if (rtb_LogicalOperator1 || rtb_LogicalOperator10_gt) {
    rtb_LogicalOperator1_du = (DHP_model_B.VINP_MCUFltRnk_enum == 2);
  } else {
    rtb_LogicalOperator1_du = (DHP_model_B.VINP_MCUFltRnk_enum == 3);
  }

  /* End of Switch: '<S875>/Switch' */

  /* Logic: '<S875>/Logical Operator3' incorporates:
   *  Constant: '<S991>/Constant'
   *  RelationalOperator: '<S991>/Compare'
   */
  VDHP_MCUHWCurrOverInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUErrNum == 8) && rtb_LogicalOperator1_du);

  /* Outputs for Enabled SubSystem: '<S849>/MCU_HwCurrOver_RedundErr' incorporates:
   *  EnablePort: '<S876>/Enable'
   */
  /* Logic: '<S849>/Logical Operator14' */
  if (rtb_LogicalOperator_mr && rtb_LogicalOperator4_ci) {
    /* Logic: '<S876>/Logical Operator3' incorporates:
     *  Constant: '<S993>/Constant'
     *  RelationalOperator: '<S993>/Compare'
     */
    VDHP_MCUHwCurrOverRedundInstFlt_flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
      DHP_model_B.MCUHWCurrOverErr && (DHP_model_B.VINP_MCUFltRnk_enum != 3));
  }

  /* End of Logic: '<S849>/Logical Operator14' */
  /* End of Outputs for SubSystem: '<S849>/MCU_HwCurrOver_RedundErr' */

  /* Switch: '<S877>/Switch' incorporates:
   *  Constant: '<S994>/Constant'
   *  Constant: '<S996>/Constant'
   *  RelationalOperator: '<S994>/Compare'
   *  RelationalOperator: '<S996>/Compare'
   */
  if (rtb_LogicalOperator10_gt) {
    rtb_LogicalOperator1_du = (DHP_model_B.VINP_MCUFltRnk_enum == 2);
  } else {
    rtb_LogicalOperator1_du = (DHP_model_B.VINP_MCUFltRnk_enum == 3);
  }

  /* End of Switch: '<S877>/Switch' */

  /* Logic: '<S877>/Logical Operator3' incorporates:
   *  Constant: '<S995>/Constant'
   *  RelationalOperator: '<S995>/Compare'
   */
  VDHP_MCUIGBTHWInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUErrNum == 15) && rtb_LogicalOperator1_du);

  /* Outputs for Enabled SubSystem: '<S849>/MCU_IGBTOverT_Err' incorporates:
   *  EnablePort: '<S878>/Enable'
   */
  if (rtb_LogicalOperator_mr) {
    /* Logic: '<S878>/Logical Operator3' incorporates:
     *  Constant: '<S997>/Constant'
     *  Constant: '<S998>/Constant'
     *  RelationalOperator: '<S997>/Compare'
     *  RelationalOperator: '<S998>/Compare'
     */
    VDHP_MCUIGBTOverTWarnInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
        11));
  }

  /* End of Outputs for SubSystem: '<S849>/MCU_IGBTOverT_Err' */

  /* Outputs for Enabled SubSystem: '<S849>/MCU_IGBTphaseTCheckErr' incorporates:
   *  EnablePort: '<S879>/Enable'
   */
  if (rtb_LogicalOperator10_gt) {
    /* Logic: '<S879>/Logical Operator3' incorporates:
     *  Constant: '<S1000>/Constant'
     *  Constant: '<S999>/Constant'
     *  RelationalOperator: '<S1000>/Compare'
     *  RelationalOperator: '<S999>/Compare'
     */
    VDHP_MCUIGBTphaseTCheckErrInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 1) && (DHP_model_B.VINP_MCUErrNum ==
        36));
  }

  /* End of Outputs for SubSystem: '<S849>/MCU_IGBTphaseTCheckErr' */

  /* Logic: '<S880>/Logical Operator3' incorporates:
   *  Constant: '<S1001>/Constant'
   *  Constant: '<S1002>/Constant'
   *  RelationalOperator: '<S1001>/Compare'
   *  RelationalOperator: '<S1002>/Compare'
   */
  VDHP_MCULowBattUnderUInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUFltRnk_enum == 3) && (DHP_model_B.VINP_MCUErrNum ==
      9));

  /* Logic: '<S881>/Logical Operator3' incorporates:
   *  Constant: '<S1003>/Constant'
   *  RelationalOperator: '<S1003>/Compare'
   */
  VDHP_MCUPwrModRedundInstFlt_flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
    DHP_model_B.VINP_MCUPwrModErr_flg && (DHP_model_B.VINP_MCUFltRnk_enum != 3));

  /* RelationalOperator: '<S882>/Relational Operator' incorporates:
   *  Constant: '<S882>/Constant1'
   */
  rtb_LogicalOperator1_du = (DHP_model_B.DataTypeConversion46 >
    KDHP_CoolErrMotTemp_C);

  /* Logic: '<S882>/Logical Operator' incorporates:
   *  Logic: '<S849>/Logical Operator2'
   *  Logic: '<S849>/Logical Operator5'
   */
  rtb_LogicalOperator_mr = (VDHP_HVPowerUpDelay2SWork_Flg &&
    (!MCU215LossCanNetInstFlt_flg) && rtb_LogicalOperator1_du);

  /* Switch: '<S1006>/Switch3' incorporates:
   *  Constant: '<S1006>/constant2'
   */
  if (rtb_LogicalOperator_mr) {
    rtb_LogicalOperator_mq = VDHP_deltaSystemTick_ms;
  } else {
    rtb_LogicalOperator_mq = 0U;
  }

  /* End of Switch: '<S1006>/Switch3' */

  /* Sum: '<S1006>/Add1' incorporates:
   *  UnitDelay: '<S1006>/UnitDelay'
   */
  rtb_Add1_iw = DHP_model_DW.UnitDelay_DSTATE + rtb_LogicalOperator_mq;

  /* RelationalOperator: '<S1006>/Relational Operator' */
  rtb_LogicalOperator3_f = (rtb_Add1_iw >= 1000U);

  /* Outputs for Triggered SubSystem: '<S882>/CoolErrMotTempUpRate' incorporates:
   *  TriggerPort: '<S1004>/Trigger'
   */
  if (rtb_LogicalOperator3_f && (DHP_model_PrevZCX.CoolErrMotTempUpRate_Trig_ZCE
       != POS_ZCSIG)) {
    /* RelationalOperator: '<S1004>/Relational Operator1' incorporates:
     *  Constant: '<S1004>/Constant4'
     *  Sum: '<S1004>/Add2'
     *  UnitDelay: '<S1004>/UnitDelay2'
     */
    DHP_model_B.RelationalOperator1 = ((int8_T)(DHP_model_B.DataTypeConversion46
      - DHP_model_DW.UnitDelay2_DSTATE) > KDHP_CoolErrMotTempUpRate_pct);

    /* Update for UnitDelay: '<S1004>/UnitDelay2' */
    DHP_model_DW.UnitDelay2_DSTATE = DHP_model_B.DataTypeConversion46;
  }

  DHP_model_PrevZCX.CoolErrMotTempUpRate_Trig_ZCE = rtb_LogicalOperator3_f;

  /* End of Outputs for SubSystem: '<S882>/CoolErrMotTempUpRate' */

  /* Logic: '<S882>/Logical Operator1' */
  VDHP_MCUTUpRateInstFlt_flg = (rtb_LogicalOperator_mr &&
    DHP_model_B.RelationalOperator1);

  /* Logic: '<S882>/Logical Operator2' */
  DHP_model_B.LogicalOperator2_a = !rtb_LogicalOperator1_du;

  /* Outputs for Enabled SubSystem: '<S849>/MCU_OverT_Err' incorporates:
   *  EnablePort: '<S883>/Enable'
   */
  if (rtb_LogicalOperator3_av3) {
    /* Logic: '<S883>/Logical Operator3' incorporates:
     *  Constant: '<S1007>/Constant'
     *  Constant: '<S1008>/Constant'
     *  Constant: '<S1009>/Constant'
     *  Logic: '<S883>/Logical Operator'
     *  RelationalOperator: '<S1007>/Compare'
     *  RelationalOperator: '<S1008>/Compare'
     *  RelationalOperator: '<S1009>/Compare'
     */
    VDHP_MCUOverTInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && ((DHP_model_B.VINP_MCUErrNum
         == 12) || (DHP_model_B.VINP_MCUErrNum == 13)));
  }

  /* End of Outputs for SubSystem: '<S849>/MCU_OverT_Err' */

  /* Logic: '<S884>/Logical Operator3' incorporates:
   *  Constant: '<S1010>/Constant'
   *  Constant: '<S1011>/Constant'
   *  Constant: '<S1012>/Constant'
   *  Logic: '<S884>/Logical Operator'
   *  RelationalOperator: '<S1010>/Compare'
   *  RelationalOperator: '<S1011>/Compare'
   *  RelationalOperator: '<S1012>/Compare'
   */
  VDHP_MCUPhaACCrrtSnsrRatiInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && ((DHP_model_B.VINP_MCUErrNum ==
       16) || (DHP_model_B.VINP_MCUErrNum == 18)));

  /* Outputs for Enabled SubSystem: '<S849>/MCU_PhaseLoss' incorporates:
   *  EnablePort: '<S885>/Enable'
   */
  if (rtb_LogicalOperator10_gt) {
    /* Logic: '<S885>/Logical Operator3' incorporates:
     *  Constant: '<S1013>/Constant'
     *  Constant: '<S1014>/Constant'
     *  RelationalOperator: '<S1013>/Compare'
     *  RelationalOperator: '<S1014>/Compare'
     */
    VDHP_MCUPhaseLossInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
        37));
  }

  /* End of Outputs for SubSystem: '<S849>/MCU_PhaseLoss' */

  /* Outputs for Enabled SubSystem: '<S849>/MCU_TSnsrRati_Err' incorporates:
   *  EnablePort: '<S886>/Enable'
   */
  /* Logic: '<S849>/Logical Operator13' */
  if (rtb_LogicalOperator3_av3 && rtb_LogicalOperator4_ci) {
    /* Logic: '<S886>/Logical Operator3' incorporates:
     *  Constant: '<S1015>/Constant'
     *  Constant: '<S1016>/Constant'
     *  RelationalOperator: '<S1015>/Compare'
     *  RelationalOperator: '<S1016>/Compare'
     */
    VDHP_MCUTSnsrRatiInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
        25));
  }

  /* End of Logic: '<S849>/Logical Operator13' */
  /* End of Outputs for SubSystem: '<S849>/MCU_TSnsrRati_Err' */

  /* Outputs for Enabled SubSystem: '<S849>/MCU_TorqCheckErr' incorporates:
   *  EnablePort: '<S887>/Enable'
   */
  /* Logic: '<S849>/Logical Operator8' */
  if (rtb_LogicalOperator1 || rtb_LogicalOperator10_gt) {
    /* Logic: '<S887>/Logical Operator3' incorporates:
     *  Constant: '<S1017>/Constant'
     *  Constant: '<S1018>/Constant'
     *  RelationalOperator: '<S1017>/Compare'
     *  RelationalOperator: '<S1018>/Compare'
     */
    VDHP_MCUTorqCheckInstFlt_Flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
      (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
      38));
  }

  /* End of Logic: '<S849>/Logical Operator8' */
  /* End of Outputs for SubSystem: '<S849>/MCU_TorqCheckErr' */

  /* Outputs for Enabled SubSystem: '<S849>/MCU_TorqOuterRange' incorporates:
   *  EnablePort: '<S888>/Enable'
   */
  if (rtb_RelationalOperator) {
    /* Logic: '<S888>/Logical Operator3' incorporates:
     *  Constant: '<S1019>/Constant'
     *  Constant: '<S1020>/Constant'
     *  Constant: '<S1021>/Constant'
     *  Constant: '<S1022>/Constant'
     *  Constant: '<S1023>/Constant'
     *  Constant: '<S1024>/Constant'
     *  Inport: '<Root>/TQM'
     *  Logic: '<S888>/Logical Operator1'
     *  Logic: '<S888>/Logical Operator2'
     *  Logic: '<S888>/Logical Operator4'
     *  Logic: '<S888>/Logical Operator5'
     *  Logic: '<S888>/Logical Operator6'
     *  Logic: '<S888>/Logical Operator7'
     *  Logic: '<S888>/Logical Operator8'
     *  RelationalOperator: '<S1019>/Compare'
     *  RelationalOperator: '<S1020>/Compare'
     *  RelationalOperator: '<S1021>/Compare'
     *  RelationalOperator: '<S1022>/Compare'
     *  RelationalOperator: '<S1023>/Compare'
     *  RelationalOperator: '<S1024>/Compare'
     */
    VDHP_MCUTorqOuterRangeInstFlt_Flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
      TQM_output.b1_M_TQM_TqArbitration && ((DHP_model_B.VINP_MCUFltRnk_enum ==
      0) || (DHP_model_B.VINP_MCUErrNum == 0) || ((DHP_model_B.VINP_MCUErrNum !=
      2) && (DHP_model_B.VINP_MCUFltRnk_enum == 1)) ||
      ((DHP_model_B.VINP_MCUFltRnk_enum == 2) && (!DHP_model_B.Merge2)) ||
      ((DHP_model_B.VINP_MCUFltRnk_enum == 3) && (!DHP_model_B.Merge5))));
  }

  /* End of Outputs for SubSystem: '<S849>/MCU_TorqOuterRange' */

  /* Outputs for Enabled SubSystem: '<S849>/MCU_faults' incorporates:
   *  EnablePort: '<S889>/Enable'
   */
  /* Logic: '<S849>/Logical Operator15' */
  if (rtb_Compare_m5y || rtb_LogicalOperator10_gt) {
    /* Switch: '<S889>/Switch' incorporates:
     *  Constant: '<S1026>/Constant'
     *  Constant: '<S1029>/Constant'
     *  RelationalOperator: '<S1026>/Compare'
     *  RelationalOperator: '<S1029>/Compare'
     */
    if (rtb_LogicalOperator10_gt) {
      rtb_LogicalOperator10_gt = (DHP_model_B.VINP_MCUFltRnk_enum == 1);
    } else {
      rtb_LogicalOperator10_gt = (DHP_model_B.VINP_MCUFltRnk_enum == 2);
    }

    /* End of Switch: '<S889>/Switch' */

    /* Logic: '<S889>/Logical Operator1' incorporates:
     *  Constant: '<S1028>/Constant'
     *  RelationalOperator: '<S1028>/Compare'
     */
    VDHP_MCUCoverWarnInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUErrNum == 40) && rtb_LogicalOperator10_gt);

    /* Logic: '<S889>/Logical Operator15' incorporates:
     *  Constant: '<S1025>/Constant'
     *  Constant: '<S1027>/Constant'
     *  RelationalOperator: '<S1025>/Compare'
     *  RelationalOperator: '<S1027>/Compare'
     */
    VDHP_MCUCoverFltInstFlt_Flg =
      (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
       && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
        39));
  }

  /* End of Logic: '<S849>/Logical Operator15' */
  /* End of Outputs for SubSystem: '<S849>/MCU_faults' */

  /* Logic: '<S890>/Logical Operator3' incorporates:
   *  Constant: '<S1030>/Constant'
   *  Constant: '<S1031>/Constant'
   *  RelationalOperator: '<S1030>/Compare'
   *  RelationalOperator: '<S1031>/Compare'
   */
  VDHP_MCUElecMotOverSpdWarnInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
      1));

  /* Logic: '<S891>/Logical Operator3' incorporates:
   *  Constant: '<S1032>/Constant'
   *  Constant: '<S1033>/Constant'
   *  RelationalOperator: '<S1032>/Compare'
   *  RelationalOperator: '<S1033>/Compare'
   */
  VDHP_MCUElecMotOverTWarnInstFlt_Flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && (DHP_model_B.VINP_MCUFltRnk_enum == 2) && (DHP_model_B.VINP_MCUErrNum ==
      5));

  /* Switch: '<S1006>/Switch2' incorporates:
   *  Logic: '<S1006>/Logical Operator'
   *  Logic: '<S1006>/Logical Operator1'
   */
  if (rtb_LogicalOperator_mr && (!rtb_LogicalOperator3_f)) {
    /* Update for UnitDelay: '<S1006>/UnitDelay' */
    DHP_model_DW.UnitDelay_DSTATE = rtb_Add1_iw;
  } else {
    /* Update for UnitDelay: '<S1006>/UnitDelay' incorporates:
     *  Constant: '<S1006>/constant3'
     */
    DHP_model_DW.UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1006>/Switch2' */
}

/* Output and update for atomic system: '<S12>/VehOtherDeviceInstErrGenerate' */
void DHP_model_VehOtherDeviceInstErrGenerate(void)
{
  boolean_T rtb_Compare_pvu;
  boolean_T rtb_LogicalOperator5_bj;
  boolean_T rtb_LogicalOperator6_dl;
  boolean_T rtb_RelationalOperator2_ag;
  boolean_T rtb_Compare_pjf;
  uint16_T rtb_DataTypeConversion_o;
  uint16_T rtb_DataTypeConversion1_m;

  /* Inport: '<S525>/VINP_ICM_VehSpdChkInvalidFlt_flg ' */
  DHP_model_B.VINP_ICM_VehSpdChkInvalidFlt_flg_m =
    DHP_model_B.VINP_ICM_VehSpdChkInvalidFlt_flg;

  /* RelationalOperator: '<S1035>/Compare' incorporates:
   *  Constant: '<S1035>/Constant'
   */
  rtb_Compare_pvu = (DHP_model_B.VINP_BMSChrgMod_enum == 2);

  /* Logic: '<S1037>/Logical Operator5' */
  rtb_LogicalOperator5_bj = (VDHP_HVPowerUpDelay2SWork_Flg &&
    DHP_model_B.VPMM_PTReady_flg);

  /* Logic: '<S1037>/Logical Operator1' */
  VDHP_EPSWorkInstFlt_flg = (rtb_LogicalOperator5_bj &&
    DHP_model_B.VINP_EPS_EpasFailed);

  /* Logic: '<S1037>/Logical Operator6' */
  rtb_LogicalOperator6_dl = !DHP_model_B.VINP_MCUElecMotSpdValid_flg;

  /* Logic: '<S1037>/Logical Operator10' */
  VDHP_MCUSpdInvalid_flg = (rtb_LogicalOperator5_bj && rtb_LogicalOperator6_dl);

  /* Logic: '<S1037>/Logical Operator11' incorporates:
   *  Constant: '<S1034>/Constant1'
   *  Constant: '<S1043>/Constant'
   *  Constant: '<S1044>/Constant'
   *  Constant: '<S1045>/Constant'
   *  Constant: '<S1047>/Constant'
   *  Logic: '<S1034>/Logical Operator'
   *  Logic: '<S1034>/Logical Operator4'
   *  RelationalOperator: '<S1043>/Compare'
   *  RelationalOperator: '<S1044>/Compare'
   *  RelationalOperator: '<S1045>/Compare'
   *  RelationalOperator: '<S1047>/Compare'
   */
  VDHP_ESPWorkErrInstFlt_flg = (rtb_LogicalOperator5_bj &&
    (DHP_model_B.VINP_ESP_ESPFailStatus && ((Vehicle_Type == S11P01_Mark) ||
    (Vehicle_Type == A11_Mark) || (Vehicle_Type == S21_Mark) || (Vehicle_Type ==
    S11P05_Mark))));

  /* Logic: '<S1037>/Logical Operator12' */
  rtb_RelationalOperator2_ag = (DHP_model_B.VPMM_PTReady_flg &&
    DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_d.RelationalOperator);

  /* Logic: '<S1037>/Logical Operator7' */
  rtb_Compare_pjf = !DHP_model_B.VINP_ABS_VehicleSpeedValid_flg;

  /* Logic: '<S1037>/Logical Operator13' */
  VDHP_SpeedInvalidInstFlt_flg = (rtb_Compare_pjf && rtb_LogicalOperator6_dl &&
    rtb_LogicalOperator5_bj);

  /* Logic: '<S1037>/Logical Operator2' */
  VDHP_EBDWorkInstFlt_flg = (rtb_RelationalOperator2_ag &&
    DHP_model_B.VINP_ABS_EbdFlgFlt);

  /* Logic: '<S1037>/Logical Operator3' incorporates:
   *  Constant: '<S1058>/Constant'
   *  RelationalOperator: '<S1058>/Compare'
   */
  VDHP_EPBWorkInstFlt_flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
    (DHP_model_B.VINP_EPB_Status == 4));

  /* Logic: '<S1037>/Logical Operator4' */
  VDHP_ABSWorkInstFlt_flg = (rtb_RelationalOperator2_ag &&
    DHP_model_B.VINP_ABS_AbsFlgFlt);

  /* Logic: '<S1037>/Logical Operator8' */
  VDHP_ABSVehicleSpeedInvalid_flg = (rtb_LogicalOperator5_bj && rtb_Compare_pjf);

  /* Logic: '<S1037>/Logical Operator9' incorporates:
   *  Logic: '<S1037>/Logical Operator'
   */
  VDHP_MCUTrqInvalid_flg = (rtb_LogicalOperator5_bj &&
    (!DHP_model_B.VINP_MotTqRealValid_flg));

  /* RelationalOperator: '<S1041>/Compare' incorporates:
   *  Constant: '<S1041>/Constant'
   */
  rtb_Compare_pjf = (DHP_model_B.VINP_BMSChrgMod_enum == 1);

  /* Outputs for Enabled SubSystem: '<S1034>/DCChrgPortOverT' incorporates:
   *  EnablePort: '<S1048>/Enable'
   */
  /* RelationalOperator: '<S1042>/Compare' incorporates:
   *  Constant: '<S1034>/Constant4'
   *  Constant: '<S1042>/Constant'
   */
  if (Vehicle_Type != ((uint8_T)Z18_MARK)) {
    /* Logic: '<S1048>/Logical Operator1' incorporates:
     *  Constant: '<S1048>/Constant2'
     *  Constant: '<S1048>/Constant6'
     *  Logic: '<S1048>/Logical Operator5'
     *  RelationalOperator: '<S1048>/Relational Operator1'
     *  RelationalOperator: '<S1048>/Relational Operator5'
     */
    VDHP_DCChrgPortOverT2InstFlt_flg = (rtb_Compare_pvu &&
      ((DHP_model_B.DataTypeConversion9 > KDHP_DCChrgPortOverT2_C) ||
       (DHP_model_B.DataTypeConversion8 > KDHP_DCChrgPortOverT2_C)));

    /* Logic: '<S1048>/Logical Operator3' incorporates:
     *  Constant: '<S1048>/Constant3'
     *  Constant: '<S1048>/Constant5'
     *  RelationalOperator: '<S1048>/Relational Operator2'
     *  RelationalOperator: '<S1048>/Relational Operator4'
     */
    DHP_model_B.LogicalOperator3_k = ((DHP_model_B.DataTypeConversion9 <
      KDHP_DCChrgPortNormalT_C) && (DHP_model_B.DataTypeConversion8 <
      KDHP_DCChrgPortNormalT_C));

    /* Logic: '<S1048>/Logical Operator4' incorporates:
     *  Constant: '<S1048>/Constant1'
     *  Constant: '<S1048>/Constant4'
     *  Logic: '<S1048>/Logical Operator2'
     *  RelationalOperator: '<S1048>/Relational Operator'
     *  RelationalOperator: '<S1048>/Relational Operator3'
     */
    VDHP_DCChrgPortOverT1InstFlt_flg = (rtb_Compare_pvu &&
      ((DHP_model_B.DataTypeConversion9 > KDHP_DCChrgPortOverT1_C) ||
       (DHP_model_B.DataTypeConversion8 > KDHP_DCChrgPortOverT1_C)));
  }

  /* End of RelationalOperator: '<S1042>/Compare' */
  /* End of Outputs for SubSystem: '<S1034>/DCChrgPortOverT' */

  /* Logic: '<S1049>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S1049>/Relational Operator1'
   */
  VDHP_DcdcFlt2_flg = (VDHP_VCUPowerUpDelay2SWork_Flg &&
                       (DHP_model_B.VINP_DCDCFltRnk_enum == 2));

  /* Logic: '<S1034>/Logical Operator1' incorporates:
   *  Constant: '<S1036>/Constant'
   *  RelationalOperator: '<S1036>/Compare'
   */
  rtb_Compare_pvu = ((DHP_model_B.VINP_BMSChrgMod_enum == 0) &&
                     DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_nq.RelationalOperator
                     && VDHP_HVPowerUpDelay2SWork_Flg);

  /* Logic: '<S1053>/Logical Operator1' */
  VDHP_MCUModErrInstFlt_flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
    DHP_model_B.VPMM_MCUModError);

  /* Logic: '<S1053>/Logical Operator2' */
  VDHP_DCDCModErrInstFlt_flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
    DHP_model_B.VPMM_DCDCModError);

  /* Logic: '<S1053>/Logical Operator4' */
  VDHP_BMSModErrInstFlt_flg = (VDHP_HVPowerUpDelay2SWork_Flg &&
    DHP_model_B.VPMM_BMSModError);

  /* Logic: '<S1054>/Logical Operator17' incorporates:
   *  RelationalOperator: '<S1054>/Relational Operator1'
   */
  VDHP_ObcFlt2_flg = (rtb_Compare_pjf && (DHP_model_B.VINP_OBCFltRnk_enum == 2));

  /* Logic: '<S1054>/Logical Operator19' incorporates:
   *  RelationalOperator: '<S1054>/Relational Operator2'
   */
  VDHP_ObcFlt3_flg = (rtb_Compare_pjf && (DHP_model_B.VINP_OBCFltRnk_enum == 3));

  /* DataTypeConversion: '<S1056>/Data Type Conversion' incorporates:
   *  DataStoreRead: '<S1056>/Data Store Read2'
   */
  rtb_DataTypeConversion_o = (uint16_T)hIOP_Fin4_Hz;

  /* DataTypeConversion: '<S1056>/Data Type Conversion1' incorporates:
   *  DataStoreRead: '<S1056>/Data Store Read5'
   */
  rtb_DataTypeConversion1_m = (uint16_T)hIOP_WaterPwm_Hz;

  /* Outputs for Enabled SubSystem: '<S1056>/VacPump_InsFlt' incorporates:
   *  EnablePort: '<S1085>/Enable'
   */
  /* RelationalOperator: '<S1081>/Compare' incorporates:
   *  Constant: '<S1081>/Constant'
   *  Inport: '<Root>/Config'
   */
  if (Config_output.C_VacuumPump_En == 1) {
    /* Logic: '<S1085>/Logical Operator4' incorporates:
     *  Constant: '<S1085>/Constant6'
     *  Constant: '<S1085>/Constant7'
     *  Constant: '<S1085>/Constant8'
     *  Constant: '<S1085>/Constant9'
     *  Logic: '<S1085>/Logical Operator6'
     *  RelationalOperator: '<S1085>/Relational Operator3'
     *  RelationalOperator: '<S1085>/Relational Operator4'
     *  Sum: '<S1085>/Add3'
     *  Sum: '<S1085>/Add4'
     */
    VDHP_VacHzInstFlt2_flg = (rtb_Compare_pvu && ((VDSF_VacuumPumpIn_Hz <
      (uint16_T)((uint32_T)KDHP_VacHzFlt2 + KDHP_VacHzFlt2Offset)) &&
      (VDSF_VacuumPumpIn_Hz >= (uint16_T)(KDHP_VacHzFlt2 - KDHP_VacHzFlt2Offset))));

    /* Logic: '<S1085>/Logical Operator5' incorporates:
     *  Constant: '<S1085>/Constant1'
     *  Constant: '<S1085>/Constant2'
     *  Constant: '<S1085>/Constant4'
     *  Constant: '<S1085>/Constant5'
     *  Logic: '<S1085>/Logical Operator1'
     *  RelationalOperator: '<S1085>/Relational Operator1'
     *  RelationalOperator: '<S1085>/Relational Operator2'
     *  Sum: '<S1085>/Add1'
     *  Sum: '<S1085>/Add2'
     */
    VDHP_VacHzInstFlt1_flg = (rtb_Compare_pvu && ((VDSF_VacuumPumpIn_Hz <
      (uint16_T)((uint32_T)KDHP_VacHzFlt1 + KDHP_VacHzFlt1Offset)) &&
      (VDSF_VacuumPumpIn_Hz >= (uint16_T)(KDHP_VacHzFlt1 - KDHP_VacHzFlt1Offset))));

    /* Logic: '<S1085>/Logical Operator8' incorporates:
     *  Constant: '<S1085>/Constant14'
     *  RelationalOperator: '<S1085>/Relational Operator'
     */
    DHP_model_B.LogicalOperator8_e = ((VDSF_VacuumPumpIn_Hz >= 65534) &&
      rtb_Compare_pvu);
  }

  /* End of RelationalOperator: '<S1081>/Compare' */
  /* End of Outputs for SubSystem: '<S1056>/VacPump_InsFlt' */

  /* Outputs for Enabled SubSystem: '<S1056>/TestVacPump_InsFlt' incorporates:
   *  EnablePort: '<S1083>/Enable'
   */
  if (VDHP_TestWorkDelay4s_Flg) {
    /* Logic: '<S1083>/Logical Operator2' incorporates:
     *  Constant: '<S1083>/Constant1'
     *  Constant: '<S1083>/Constant2'
     *  Constant: '<S1083>/Constant3'
     *  Constant: '<S1083>/Constant4'
     *  Logic: '<S1087>/FixPt Logical Operator'
     *  RelationalOperator: '<S1087>/Lower Test'
     *  RelationalOperator: '<S1087>/Upper Test'
     *  Sum: '<S1083>/Add'
     *  Sum: '<S1083>/Add1'
     */
    DHP_model_B.LogicalOperator2_j = !(((uint16_T)(KDHP_TestVacpumpPWM_HZ -
      KDHP_TestPWMHZ_offset) <= rtb_DataTypeConversion_o) &&
      (rtb_DataTypeConversion_o <= (uint16_T)((uint32_T)KDHP_TestVacpumpPWM_HZ +
      KDHP_TestPWMHZ_offset)));
  }

  /* End of Outputs for SubSystem: '<S1056>/TestVacPump_InsFlt' */

  /* Switch: '<S1056>/Switch' incorporates:
   *  DataStoreRead: '<S1056>/Data Store Read1'
   *  Logic: '<S1056>/Logical Operator1'
   */
  if (!bool_udsAgingTestStart_flag) {
    VDHP_VacPumpHardwireInstFlt_flg = DHP_model_B.LogicalOperator8_e;
  } else {
    VDHP_VacPumpHardwireInstFlt_flg = DHP_model_B.LogicalOperator2_j;
  }

  /* End of Switch: '<S1056>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1057>/DHP_systemtick_Timer' */

  /* Constant: '<S1057>/Constant8' */
  DHP_model_DHP_systemtick_Timer_c(DHP_model_B.TMM_WaterPumpEnReq_flg,
    VDHP_deltaSystemTick_ms, 2000U, &DHP_model_B.DHP_systemtick_Timer_n1,
    &DHP_model_DW.DHP_systemtick_Timer_n1);

  /* End of Outputs for SubSystem: '<S1057>/DHP_systemtick_Timer' */

  /* Outputs for Enabled SubSystem: '<S1056>/WaterPump_InsFlt' incorporates:
   *  EnablePort: '<S1086>/Enable'
   */
  /* RelationalOperator: '<S1082>/Compare' incorporates:
   *  Constant: '<S1056>/Constant4'
   *  Constant: '<S1082>/Constant'
   *  Constant: '<S1086>/Constant3'
   *  Constant: '<S1089>/Constant'
   *  Constant: '<S1090>/Constant'
   *  Constant: '<S1091>/Constant'
   *  Constant: '<S1092>/Constant'
   *  Constant: '<S1093>/Constant'
   *  Logic: '<S1086>/Logical Operator'
   *  Logic: '<S1086>/Logical Operator3'
   *  RelationalOperator: '<S1089>/Compare'
   *  RelationalOperator: '<S1090>/Compare'
   *  RelationalOperator: '<S1091>/Compare'
   *  RelationalOperator: '<S1092>/Compare'
   *  RelationalOperator: '<S1093>/Compare'
   */
  if (Vehicle_Type != ((uint8_T)Z18_MARK)) {
    /* Outputs for Enabled SubSystem: '<S1086>/waterpump for s11' incorporates:
     *  EnablePort: '<S1095>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S1086>/waterpump for K11//X11' incorporates:
     *  EnablePort: '<S1094>/Enable'
     */
    if (!((Vehicle_Type == K11_Mark) || (Vehicle_Type == X11_Mark) ||
          (Vehicle_Type == K11P01_Mark) || (Vehicle_Type == K11E01R_Mark) ||
          (Vehicle_Type == K11P06_Mark))) {
      /* Logic: '<S1098>/FixPt Logical Operator' incorporates:
       *  Constant: '<S1095>/Constant2'
       *  Constant: '<S1095>/Constant3'
       *  RelationalOperator: '<S1098>/Lower Test'
       *  RelationalOperator: '<S1098>/Upper Test'
       */
      rtb_Compare_pvu = ((20 <= VDSF_WaterPwmIn_Duty) && (VDSF_WaterPwmIn_Duty <=
        27));

      /* Logic: '<S1095>/Logical Operator' incorporates:
       *  Constant: '<S1095>/Constant4'
       *  Constant: '<S1095>/Constant5'
       *  Constant: '<S1095>/Constant6'
       *  Constant: '<S1095>/Constant7'
       *  Logic: '<S1099>/FixPt Logical Operator'
       *  Logic: '<S1100>/FixPt Logical Operator'
       *  RelationalOperator: '<S1099>/Lower Test'
       *  RelationalOperator: '<S1099>/Upper Test'
       *  RelationalOperator: '<S1100>/Lower Test'
       *  RelationalOperator: '<S1100>/Upper Test'
       */
      rtb_LogicalOperator5_bj = (((3 < VDSF_WaterPwmIn_Duty) &&
        (VDSF_WaterPwmIn_Duty < 5)) || ((18 < VDSF_WaterPwmIn_Duty) &&
        (VDSF_WaterPwmIn_Duty < 20)));

      /* Logic: '<S1101>/FixPt Logical Operator' incorporates:
       *  Constant: '<S1095>/Constant'
       *  Constant: '<S1095>/Constant1'
       *  RelationalOperator: '<S1101>/Lower Test'
       *  RelationalOperator: '<S1101>/Upper Test'
       */
      rtb_Compare_pjf = ((5 <= VDSF_WaterPwmIn_Duty) && (VDSF_WaterPwmIn_Duty <=
        18));
    } else {
      /* Logic: '<S1094>/Logical Operator5' incorporates:
       *  Constant: '<S1094>/Constant1'
       *  Constant: '<S1094>/Constant10'
       *  Constant: '<S1094>/Constant11'
       *  Constant: '<S1094>/Constant12'
       *  Constant: '<S1094>/Constant13'
       *  Constant: '<S1094>/Constant14'
       *  Constant: '<S1094>/Constant15'
       *  Constant: '<S1094>/Constant16'
       *  Constant: '<S1094>/Constant2'
       *  Constant: '<S1094>/Constant3'
       *  Constant: '<S1094>/Constant4'
       *  Constant: '<S1094>/Constant5'
       *  Constant: '<S1094>/Constant6'
       *  Constant: '<S1094>/Constant7'
       *  Constant: '<S1094>/Constant8'
       *  Constant: '<S1094>/Constant9'
       *  Logic: '<S1094>/Logical Operator1'
       *  Logic: '<S1094>/Logical Operator2'
       *  Logic: '<S1094>/Logical Operator3'
       *  Logic: '<S1094>/Logical Operator4'
       *  RelationalOperator: '<S1094>/Relational Operator1'
       *  RelationalOperator: '<S1094>/Relational Operator2'
       *  RelationalOperator: '<S1094>/Relational Operator3'
       *  RelationalOperator: '<S1094>/Relational Operator4'
       *  RelationalOperator: '<S1094>/Relational Operator5'
       *  RelationalOperator: '<S1094>/Relational Operator6'
       *  RelationalOperator: '<S1094>/Relational Operator7'
       *  RelationalOperator: '<S1094>/Relational Operator8'
       *  Sum: '<S1094>/Add1'
       *  Sum: '<S1094>/Add2'
       *  Sum: '<S1094>/Add3'
       *  Sum: '<S1094>/Add4'
       *  Sum: '<S1094>/Add5'
       *  Sum: '<S1094>/Add6'
       *  Sum: '<S1094>/Add7'
       *  Sum: '<S1094>/Add8'
       */
      rtb_Compare_pjf = (((VDSF_WaterPwmIn_Duty <= (uint8_T)(80U +
        KDHP_WaterPumpFlt1_PCTOffset)) && (VDSF_WaterPwmIn_Duty >= (uint8_T)(80
        - KDHP_WaterPumpFlt1_PCTOffset))) || ((VDSF_WaterPwmIn_Duty <= (uint8_T)
        (60U + KDHP_WaterPumpFlt1_PCTOffset)) && (VDSF_WaterPwmIn_Duty >=
        (uint8_T)(60 - KDHP_WaterPumpFlt1_PCTOffset))) || ((VDSF_WaterPwmIn_Duty
        <= (uint8_T)(30U + KDHP_WaterPumpFlt1_PCTOffset)) &&
        (VDSF_WaterPwmIn_Duty >= (uint8_T)(30 - KDHP_WaterPumpFlt1_PCTOffset))) ||
                         ((VDSF_WaterPwmIn_Duty <= (uint8_T)(20U +
        KDHP_WaterPumpFlt1_PCTOffset)) && (VDSF_WaterPwmIn_Duty >= (uint8_T)(20
        - KDHP_WaterPumpFlt1_PCTOffset))));

      /* Logic: '<S1094>/Logical Operator8' incorporates:
       *  Constant: '<S1094>/Constant17'
       *  Constant: '<S1094>/Constant18'
       *  Constant: '<S1094>/Constant19'
       *  Constant: '<S1094>/Constant20'
       *  Constant: '<S1094>/Constant21'
       *  Constant: '<S1094>/Constant22'
       *  Constant: '<S1094>/Constant23'
       *  Constant: '<S1094>/Constant24'
       *  Logic: '<S1094>/Logical Operator6'
       *  Logic: '<S1094>/Logical Operator7'
       *  RelationalOperator: '<S1094>/Relational Operator10'
       *  RelationalOperator: '<S1094>/Relational Operator11'
       *  RelationalOperator: '<S1094>/Relational Operator12'
       *  RelationalOperator: '<S1094>/Relational Operator9'
       *  Sum: '<S1094>/Add10'
       *  Sum: '<S1094>/Add11'
       *  Sum: '<S1094>/Add12'
       *  Sum: '<S1094>/Add9'
       */
      rtb_Compare_pvu = (((VDSF_WaterPwmIn_Duty <= (uint8_T)(70U +
        KDHP_WaterPumpFlt2_PCTOffset)) && (VDSF_WaterPwmIn_Duty >= (uint8_T)(70
        - KDHP_WaterPumpFlt2_PCTOffset))) || ((VDSF_WaterPwmIn_Duty <= (uint8_T)
        (40U + KDHP_WaterPumpFlt2_PCTOffset)) && (VDSF_WaterPwmIn_Duty >=
        (uint8_T)(40 - KDHP_WaterPumpFlt2_PCTOffset))));

      /* Logic: '<S1094>/Logical Operator12' incorporates:
       *  Constant: '<S1094>/Constant25'
       *  Constant: '<S1094>/Constant26'
       *  Constant: '<S1094>/Constant27'
       *  Constant: '<S1094>/Constant28'
       *  Constant: '<S1094>/Constant29'
       *  Constant: '<S1094>/Constant30'
       *  Constant: '<S1094>/Constant31'
       *  Constant: '<S1094>/Constant32'
       *  Constant: '<S1096>/Constant'
       *  Constant: '<S1097>/Constant'
       *  Logic: '<S1094>/Logical Operator10'
       *  Logic: '<S1094>/Logical Operator11'
       *  Logic: '<S1094>/Logical Operator13'
       *  Logic: '<S1094>/Logical Operator14'
       *  Logic: '<S1094>/Logical Operator15'
       *  Logic: '<S1094>/Logical Operator9'
       *  RelationalOperator: '<S1094>/Relational Operator13'
       *  RelationalOperator: '<S1094>/Relational Operator14'
       *  RelationalOperator: '<S1094>/Relational Operator15'
       *  RelationalOperator: '<S1094>/Relational Operator16'
       *  RelationalOperator: '<S1096>/Compare'
       *  RelationalOperator: '<S1097>/Compare'
       *  Sum: '<S1094>/Add13'
       *  Sum: '<S1094>/Add14'
       *  Sum: '<S1094>/Add15'
       *  Sum: '<S1094>/Add16'
       */
      rtb_LogicalOperator5_bj = ((!rtb_Compare_pjf) && (!rtb_Compare_pvu) &&
        (!(((VDSF_WaterPwmIn_Duty <= (uint8_T)(50U +
        KDHP_WaterPumpFlt2_PCTOffset)) && (VDSF_WaterPwmIn_Duty >= (uint8_T)(50
        - KDHP_WaterPumpFlt2_PCTOffset))) || ((VDSF_WaterPwmIn_Duty <= (uint8_T)
        (10U + KDHP_WaterPumpFlt2_PCTOffset)) && (VDSF_WaterPwmIn_Duty >=
        (uint8_T)(10 - KDHP_WaterPumpFlt2_PCTOffset))))) &&
        (VDSF_WaterPwmIn_Duty > 0) && (VDSF_WaterPwmIn_Duty < 100));
    }

    /* End of Outputs for SubSystem: '<S1086>/waterpump for K11//X11' */
    /* End of Outputs for SubSystem: '<S1086>/waterpump for s11' */

    /* Logic: '<S1086>/Logical Operator1' incorporates:
     *  Constant: '<S1086>/Constant3'
     *  Constant: '<S1089>/Constant'
     *  Constant: '<S1090>/Constant'
     *  Constant: '<S1091>/Constant'
     *  Constant: '<S1092>/Constant'
     *  Constant: '<S1093>/Constant'
     *  Logic: '<S1086>/Logical Operator'
     *  Logic: '<S1086>/Logical Operator3'
     *  RelationalOperator: '<S1089>/Compare'
     *  RelationalOperator: '<S1090>/Compare'
     *  RelationalOperator: '<S1091>/Compare'
     *  RelationalOperator: '<S1092>/Compare'
     *  RelationalOperator: '<S1093>/Compare'
     */
    VDHP_WaterPump_InstFlt2_flg =
      (DHP_model_B.DHP_systemtick_Timer_n1.RelationalOperator && rtb_Compare_pvu);

    /* Logic: '<S1086>/Logical Operator2' */
    VDHP_WaterPumpPWMInstFlt_flg = (rtb_LogicalOperator5_bj &&
      DHP_model_B.DHP_systemtick_Timer_n1.RelationalOperator);

    /* Logic: '<S1086>/Logical Operator5' */
    VDHP_WaterPump_InstFlt1_flg =
      (DHP_model_B.DHP_systemtick_Timer_n1.RelationalOperator && rtb_Compare_pjf);

    /* Logic: '<S1086>/Logical Operator8' incorporates:
     *  Constant: '<S1086>/Constant14'
     *  RelationalOperator: '<S1086>/Relational Operator'
     */
    DHP_model_B.LogicalOperator8 = ((VDSF_WaterPwmIn_Duty >= 254) &&
      DHP_model_B.DHP_systemtick_Timer_n1.RelationalOperator);
  }

  /* End of RelationalOperator: '<S1082>/Compare' */
  /* End of Outputs for SubSystem: '<S1056>/WaterPump_InsFlt' */

  /* Outputs for Enabled SubSystem: '<S1056>/TestWaterPump_InsFlt' incorporates:
   *  EnablePort: '<S1084>/Enable'
   */
  if (VDHP_TestWorkDelay4s_Flg) {
    /* Logic: '<S1084>/Logical Operator2' incorporates:
     *  Constant: '<S1084>/Constant1'
     *  Constant: '<S1084>/Constant2'
     *  Constant: '<S1084>/Constant3'
     *  Constant: '<S1084>/Constant4'
     *  Logic: '<S1088>/FixPt Logical Operator'
     *  RelationalOperator: '<S1088>/Lower Test'
     *  RelationalOperator: '<S1088>/Upper Test'
     *  Sum: '<S1084>/Add'
     *  Sum: '<S1084>/Add1'
     */
    DHP_model_B.LogicalOperator2_o = !(((uint16_T)(KDHP_TestWaterpumpPWM_HZ -
      KDHP_TestPWMHZ_offset) <= rtb_DataTypeConversion1_m) &&
      (rtb_DataTypeConversion1_m <= (uint16_T)((uint32_T)
      KDHP_TestWaterpumpPWM_HZ + KDHP_TestPWMHZ_offset)));
  }

  /* End of Outputs for SubSystem: '<S1056>/TestWaterPump_InsFlt' */

  /* Switch: '<S1056>/Switch1' incorporates:
   *  DataStoreRead: '<S1056>/Data Store Read4'
   *  Logic: '<S1056>/Logical Operator2'
   */
  if (!bool_udsAgingTestStart_flag) {
    VDHP_WaterPumpHardwireInstFlt_flg = DHP_model_B.LogicalOperator8;
  } else {
    VDHP_WaterPumpHardwireInstFlt_flg = DHP_model_B.LogicalOperator2_o;
  }

  /* End of Switch: '<S1056>/Switch1' */

  /* DataTypeConversion: '<S1034>/Data Type Conversion' incorporates:
   *  Constant: '<S1034>/Constant3'
   */
  VDHP_Authentication_flg = (Authentication_flg != 0);

  /* DataTypeConversion: '<S1055>/Data Type  Conversion' incorporates:
   *  Inport: '<Root>/PEPS'
   */
  VDHP_VPEPS_Result_enum = PEPS_output.VPEPS_Result_enum;

  /* Logic: '<S1055>/Logical Operator4' incorporates:
   *  Constant: '<S1080>/Constant'
   *  RelationalOperator: '<S1080>/Compare'
   */
  VDHP_PEPSFailedInstFlt_flg = (VDHP_Authentication_flg &&
    (VDHP_VPEPS_Result_enum == 1));

  /* RelationalOperator: '<S1064>/Compare' */
  VDHP_TMSReqInvalid_flg = DHP_model_B.TMM_InvalidBattReq;

  /* RelationalOperator: '<S1060>/Compare' incorporates:
   *  Constant: '<S1060>/Constant'
   *  Inport: '<Root>/SPDCtl'
   */
  DHP_model_B.Compare_d = (SPDCtl_output.u1_M_SPDCtl_CRUISEDiagError_enum == 1);

  /* RelationalOperator: '<S1062>/Compare' incorporates:
   *  Constant: '<S1062>/Constant'
   *  Inport: '<Root>/SPDCtl'
   */
  DHP_model_B.Compare_c = (SPDCtl_output.u1_M_SPDCtl_CRUISEDiagError_enum == 2);

  /* Outputs for Enabled SubSystem: '<S1034>/InvalidBattReq1' incorporates:
   *  EnablePort: '<S1052>/Enable'
   */
  /* RelationalOperator: '<S1046>/Compare' incorporates:
   *  Constant: '<S1046>/Constant'
   *  Inport: '<Root>/Config'
   */
  if (Config_output.C_ESCL_En == 1) {
    /* RelationalOperator: '<S1065>/Compare' incorporates:
     *  Constant: '<S1065>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read'
     */
    VDHP_EsclLinCommFailed_flg = (EsclLinCommFailed == 1);

    /* RelationalOperator: '<S1066>/Compare' incorporates:
     *  Constant: '<S1066>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclChipHWFailed_flg = (EsclErrorCode == 1);

    /* RelationalOperator: '<S1067>/Compare' incorporates:
     *  Constant: '<S1067>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclMotorNoAct_flg = (EsclErrorCode == 10);

    /* RelationalOperator: '<S1068>/Compare' incorporates:
     *  Constant: '<S1068>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclMasterReqTimeout_flg = (EsclErrorCode == 11);

    /* RelationalOperator: '<S1069>/Compare' incorporates:
     *  Constant: '<S1069>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclUnlockTimeout_flg = (EsclErrorCode == 12);

    /* RelationalOperator: '<S1070>/Compare' incorporates:
     *  Constant: '<S1070>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclLockTimeout_flg = (EsclErrorCode == 13);

    /* RelationalOperator: '<S1071>/Compare' incorporates:
     *  Constant: '<S1071>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclMasterIReqInvalid_flg = (EsclErrorCode == 14);

    /* RelationalOperator: '<S1072>/Compare' incorporates:
     *  Constant: '<S1072>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclLockGndFailed_flg = (EsclErrorCode == 2);

    /* RelationalOperator: '<S1073>/Compare' incorporates:
     *  Constant: '<S1073>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclSensorStsFailed_flg = (EsclErrorCode == 3);

    /* RelationalOperator: '<S1074>/Compare' incorporates:
     *  Constant: '<S1074>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclMotorDriverFailed_flg = (EsclErrorCode == 4);

    /* RelationalOperator: '<S1075>/Compare' incorporates:
     *  Constant: '<S1075>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclSensorHWFailed_flg = (EsclErrorCode == 5);

    /* RelationalOperator: '<S1076>/Compare' incorporates:
     *  Constant: '<S1076>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclMotorOverload_flg = (EsclErrorCode == 6);

    /* RelationalOperator: '<S1077>/Compare' incorporates:
     *  Constant: '<S1077>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclPwrSupplyFailed_flg = (EsclErrorCode == 7);

    /* RelationalOperator: '<S1078>/Compare' incorporates:
     *  Constant: '<S1078>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclEEPROMFailed_flg = (EsclErrorCode == 8);

    /* RelationalOperator: '<S1079>/Compare' incorporates:
     *  Constant: '<S1079>/Constant'
     *  DataStoreRead: '<S1034>/Data Store Read1'
     */
    VDHP_EsclAuthenticFailed_flg = (EsclErrorCode == 9);
  }

  /* End of RelationalOperator: '<S1046>/Compare' */
  /* End of Outputs for SubSystem: '<S1034>/InvalidBattReq1' */

  /* RelationalOperator: '<S1059>/Compare' incorporates:
   *  Inport: '<Root>/ENM'
   */
  DHP_model_B.Compare_mj = ENM_output.ENM_Batt_EnergyToolow;

  /* RelationalOperator: '<S1063>/Compare' incorporates:
   *  Constant: '<S1063>/Constant'
   */
  DHP_model_B.Compare_ce = (DHP_model_B.VPMM_IChrgSts == 2);
}

/* Output and update for atomic system: '<S12>/VehPowerOnDelayWorkFlagCollect' */
void DHP_model_VehPowerOnDelayWorkFlagCollect(boolean_T rtu_VNM_SleepInd_flg,
  boolean_T rtu_VINP_15KeyOn_flg, boolean_T rtu_VHAL_VCUUp_flg, boolean_T
  rtu_VPMM_HVOn_flg, uint8_T rtu_VINP_MCUOperMdl_enum, boolean_T rtu_VPMM_LVEna,
  uint8_T rtu_deltaSystemTick_ms, uint8_T rtu_VINP_BMSOperMdl,
  B_VehPowerOnDelayWorkFlagCollect_DHP_model_T *localB,
  DW_VehPowerOnDelayWorkFlagCollect_DHP_model_T *localDW)
{
  boolean_T rtb_Switch1_cv;
  boolean_T rtb_Switch3_g;

  /* Switch: '<S526>/Switch1' incorporates:
   *  Constant: '<S1104>/Constant'
   *  Constant: '<S526>/Constant1'
   *  Constant: '<S526>/Constant3'
   *  DataStoreRead: '<S526>/Data Store Read'
   *  Logic: '<S526>/Logical Operator1'
   *  RelationalOperator: '<S1104>/Compare'
   *  Switch: '<S526>/Switch3'
   */
  if (rtu_VNM_SleepInd_flg) {
    rtb_Switch1_cv = false;
    rtb_Switch3_g = false;
  } else {
    rtb_Switch1_cv = (rtu_VPMM_LVEna && (rtu_VINP_BMSOperMdl != 0));
    rtb_Switch3_g = bool_udsAgingTestStart_flag;
  }

  /* End of Switch: '<S526>/Switch1' */

  /* Inport: '<S526>/VINP_15KeyOn_flg' */
  localB->VINP_15KeyOn_flg = rtu_VINP_15KeyOn_flg;

  /* Outputs for Atomic SubSystem: '<S1105>/DHP_systemtick_Timer' */

  /* Switch: '<S526>/Switch4' incorporates:
   *  Constant: '<S1105>/2s'
   */
  DHP_model_DHP_systemtick_Timer_gq((!rtu_VNM_SleepInd_flg) && rtu_VPMM_HVOn_flg,
    rtu_deltaSystemTick_ms, 2000U, &localDW->DHP_systemtick_Timer);

  /* End of Outputs for SubSystem: '<S1105>/DHP_systemtick_Timer' */

  /* Outputs for Atomic SubSystem: '<S1106>/DHP_systemtick_Timer' */

  /* Constant: '<S1106>/10s' */
  DHP_model_DHP_systemtick_Timer_na(rtb_Switch1_cv, rtu_deltaSystemTick_ms,
    10000U, &localDW->DHP_systemtick_Timer_n);

  /* End of Outputs for SubSystem: '<S1106>/DHP_systemtick_Timer' */

  /* Outputs for Atomic SubSystem: '<S1107>/DHP_systemtick_Timer' */

  /* Switch: '<S526>/Switch7' incorporates:
   *  Constant: '<S1107>/Constant1'
   */
  DHP_model_DHP_systemtick_Timer_c((!rtu_VNM_SleepInd_flg) && rtu_VPMM_HVOn_flg,
    rtu_deltaSystemTick_ms, KDHP_ABSFaultStart_ms,
    &localB->DHP_systemtick_Timer_d, &localDW->DHP_systemtick_Timer_d);

  /* End of Outputs for SubSystem: '<S1107>/DHP_systemtick_Timer' */

  /* Outputs for Atomic SubSystem: '<S1108>/DHP_systemtick_Timer' */

  /* Switch: '<S526>/Switch6' incorporates:
   *  Constant: '<S1108>/2s'
   */
  DHP_model_DHP_systemtick_Timer_c((!rtu_VNM_SleepInd_flg) &&
    localB->VINP_15KeyOn_flg, rtu_deltaSystemTick_ms, 2000U,
    &localB->DHP_systemtick_Timer_nq, &localDW->DHP_systemtick_Timer_nq);

  /* End of Outputs for SubSystem: '<S1108>/DHP_systemtick_Timer' */

  /* Outputs for Atomic SubSystem: '<S1109>/DHP_systemtick_Timer' */

  /* Switch: '<S526>/Switch10' incorporates:
   *  Constant: '<S1109>/2s'
   */
  DHP_model_DHP_systemtick_Timer_c((!rtu_VNM_SleepInd_flg) && rtu_VPMM_LVEna,
    rtu_deltaSystemTick_ms, 2000U, &localB->DHP_systemtick_Timer_g,
    &localDW->DHP_systemtick_Timer_g);

  /* End of Outputs for SubSystem: '<S1109>/DHP_systemtick_Timer' */

  /* Outputs for Atomic SubSystem: '<S1110>/DHP_systemtick_Timer' */

  /* Switch: '<S526>/Switch9' incorporates:
   *  Constant: '<S1110>/1.5s'
   */
  DHP_model_DHP_systemtick_Timer_c((!rtu_VNM_SleepInd_flg) && rtu_VHAL_VCUUp_flg,
    rtu_deltaSystemTick_ms, 1500U, &localB->DHP_systemtick_Timer_n5,
    &localDW->DHP_systemtick_Timer_n5);

  /* End of Outputs for SubSystem: '<S1110>/DHP_systemtick_Timer' */

  /* Outputs for Atomic SubSystem: '<S1111>/DHP_systemtick_Timer' */

  /* Switch: '<S526>/Switch2' incorporates:
   *  Constant: '<S1111>/2s'
   */
  DHP_model_DHP_systemtick_Timer_fy((!rtu_VNM_SleepInd_flg) &&
    rtu_VHAL_VCUUp_flg, rtu_deltaSystemTick_ms, 2000U,
    &localDW->DHP_systemtick_Timer_f);

  /* End of Outputs for SubSystem: '<S1111>/DHP_systemtick_Timer' */

  /* Switch: '<S526>/Switch8' incorporates:
   *  Constant: '<S1103>/Constant'
   *  Constant: '<S526>/Constant8'
   *  Logic: '<S526>/Logical Operator'
   *  RelationalOperator: '<S1103>/Compare'
   */
  if (rtu_VNM_SleepInd_flg) {
    rtb_Switch1_cv = false;
  } else {
    rtb_Switch1_cv = ((rtu_VINP_MCUOperMdl_enum != 0) && rtu_VPMM_LVEna);
  }

  /* End of Switch: '<S526>/Switch8' */

  /* Outputs for Atomic SubSystem: '<S1112>/DHP_systemtick_Timer' */

  /* Constant: '<S1112>/1s' */
  DHP_model_DHP_systemtick_Timer_oz(rtb_Switch1_cv, rtu_deltaSystemTick_ms,
    1000U, &localDW->DHP_systemtick_Timer_o);

  /* End of Outputs for SubSystem: '<S1112>/DHP_systemtick_Timer' */

  /* Outputs for Atomic SubSystem: '<S1113>/DHP_systemtick_Timer' */

  /* Constant: '<S1113>/4s' */
  DHP_model_DHP_systemtick_Timer_p3(rtb_Switch3_g, rtu_deltaSystemTick_ms, 4500U,
    &localDW->DHP_systemtick_Timer_p);

  /* End of Outputs for SubSystem: '<S1113>/DHP_systemtick_Timer' */
}

/* Output and update for atomic system: '<S12>/VehPowerSysInstErrGenerate' */
void DHP_model_VehPowerSysInstErrGenerate(void)
{
  boolean_T rtb_Compare_k0j;
  boolean_T rtb_Compare_oss;
  boolean_T rtb_Compare_bh;
  boolean_T rtb_LogicalOperator13_m;
  boolean_T rtb_LogicalOperator29_c;
  boolean_T rtb_LogicalOperator22;
  boolean_T rtb_LogicalOperator25_k;
  boolean_T rtb_LogicalOperator6_an;
  uint16_T tmp;
  int16_T tmp_0;

  /* RelationalOperator: '<S1143>/Compare' incorporates:
   *  Constant: '<S1143>/Constant'
   */
  rtb_Compare_k0j = (DHP_model_B.VINP_BMSFltRnk_enum == 3);

  /* RelationalOperator: '<S1144>/Compare' incorporates:
   *  Constant: '<S1144>/Constant'
   */
  rtb_Compare_oss = (DHP_model_B.VINP_BMSFltRnk_enum == 4);

  /* RelationalOperator: '<S1145>/Compare' incorporates:
   *  Constant: '<S1145>/Constant'
   */
  rtb_Compare_bh = (DHP_model_B.VINP_BMSFltRnk_enum == 2);

  /* RelationalOperator: '<S1147>/Compare' incorporates:
   *  Constant: '<S1147>/Constant'
   */
  DHP_model_B.Compare_nu = (DHP_model_B.VINP_BMSFltRnk_enum < 2);

  /* Logic: '<S1124>/Logical Operator13' incorporates:
   *  Constant: '<S1146>/Constant'
   *  Constant: '<S1148>/Constant'
   *  Constant: '<S1149>/Constant'
   *  Constant: '<S1150>/Constant'
   *  RelationalOperator: '<S1146>/Compare'
   *  RelationalOperator: '<S1148>/Compare'
   *  RelationalOperator: '<S1149>/Compare'
   *  RelationalOperator: '<S1150>/Compare'
   */
  rtb_LogicalOperator13_m = ((DHP_model_B.VINP_BMSErrNum == 1) ||
    (DHP_model_B.VINP_BMSErrNum == 108) || (DHP_model_B.VINP_BMSErrNum == 109) ||
    (DHP_model_B.VINP_BMSErrNum == 122));

  /* Logic: '<S1151>/Logical Operator29' incorporates:
   *  Constant: '<S1151>/Constant19'
   *  Constant: '<S1160>/Constant'
   *  Constant: '<S1161>/Constant'
   *  Constant: '<S1163>/Constant'
   *  Constant: '<S1166>/Constant'
   *  Constant: '<S1174>/Constant'
   *  Constant: '<S1175>/Constant'
   *  Constant: '<S1176>/Constant'
   *  Constant: '<S1206>/Constant'
   *  Constant: '<S1207>/Constant'
   *  Constant: '<S1208>/Constant'
   *  Constant: '<S1209>/Constant'
   *  Constant: '<S1210>/Constant'
   *  Constant: '<S1211>/Constant'
   *  Constant: '<S1213>/Constant'
   *  Constant: '<S1214>/Constant'
   *  Constant: '<S1215>/Constant'
   *  Constant: '<S1216>/Constant'
   *  Constant: '<S1217>/Constant'
   *  Constant: '<S1218>/Constant'
   *  Constant: '<S1219>/Constant'
   *  Constant: '<S1220>/Constant'
   *  Logic: '<S1151>/Logical Operator10'
   *  Logic: '<S1151>/Logical Operator27'
   *  Logic: '<S1151>/Logical Operator28'
   *  Logic: '<S1151>/Logical Operator7'
   *  RelationalOperator: '<S1160>/Compare'
   *  RelationalOperator: '<S1161>/Compare'
   *  RelationalOperator: '<S1163>/Compare'
   *  RelationalOperator: '<S1166>/Compare'
   *  RelationalOperator: '<S1174>/Compare'
   *  RelationalOperator: '<S1175>/Compare'
   *  RelationalOperator: '<S1176>/Compare'
   *  RelationalOperator: '<S1206>/Compare'
   *  RelationalOperator: '<S1207>/Compare'
   *  RelationalOperator: '<S1208>/Compare'
   *  RelationalOperator: '<S1209>/Compare'
   *  RelationalOperator: '<S1210>/Compare'
   *  RelationalOperator: '<S1211>/Compare'
   *  RelationalOperator: '<S1213>/Compare'
   *  RelationalOperator: '<S1214>/Compare'
   *  RelationalOperator: '<S1215>/Compare'
   *  RelationalOperator: '<S1216>/Compare'
   *  RelationalOperator: '<S1217>/Compare'
   *  RelationalOperator: '<S1218>/Compare'
   *  RelationalOperator: '<S1219>/Compare'
   *  RelationalOperator: '<S1220>/Compare'
   */
  rtb_LogicalOperator29_c = ((DHP_model_B.VINP_BMSErrNum == 3) ||
    ((DHP_model_B.VINP_BMSErrNum >= 38) && (DHP_model_B.VINP_BMSErrNum <= 41)) ||
    (DHP_model_B.VINP_BMSErrNum == 42) || (DHP_model_B.VINP_BMSErrNum == 43) ||
    ((DHP_model_B.VINP_BMSErrNum >= 45) && (DHP_model_B.VINP_BMSErrNum <= 47)) ||
    (DHP_model_B.VINP_BMSErrNum == 61) || (DHP_model_B.VINP_BMSErrNum == 63) ||
    ((DHP_model_B.VINP_BMSErrNum >= 69) && (DHP_model_B.VINP_BMSErrNum <= 86) &&
     (Vehicle_Type != S11P05_Mark)) || (DHP_model_B.VINP_BMSErrNum == 87) ||
    (DHP_model_B.VINP_BMSErrNum == 89) || (DHP_model_B.VINP_BMSErrNum == 93) ||
    (DHP_model_B.VINP_BMSErrNum == 94) || (DHP_model_B.VINP_BMSErrNum == 96) ||
    (DHP_model_B.VINP_BMSErrNum == 99) || (DHP_model_B.VINP_BMSErrNum == 103) ||
    (DHP_model_B.VINP_BMSErrNum == 111) || (DHP_model_B.VINP_BMSErrNum == 118));

  /* Logic: '<S1124>/Logical Operator22' */
  rtb_LogicalOperator22 =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && rtb_Compare_bh && rtb_LogicalOperator29_c);

  /* Logic: '<S1151>/Logical Operator25' incorporates:
   *  Constant: '<S1168>/Constant'
   *  Constant: '<S1170>/Constant'
   *  Constant: '<S1171>/Constant'
   *  Constant: '<S1172>/Constant'
   *  Constant: '<S1177>/Constant'
   *  Constant: '<S1178>/Constant'
   *  Constant: '<S1180>/Constant'
   *  Constant: '<S1181>/Constant'
   *  Constant: '<S1182>/Constant'
   *  Constant: '<S1183>/Constant'
   *  Constant: '<S1184>/Constant'
   *  Constant: '<S1185>/Constant'
   *  Constant: '<S1186>/Constant'
   *  Constant: '<S1187>/Constant'
   *  Constant: '<S1188>/Constant'
   *  Constant: '<S1189>/Constant'
   *  Constant: '<S1191>/Constant'
   *  Constant: '<S1192>/Constant'
   *  Constant: '<S1193>/Constant'
   *  Constant: '<S1194>/Constant'
   *  Constant: '<S1195>/Constant'
   *  Constant: '<S1196>/Constant'
   *  Constant: '<S1197>/Constant'
   *  Constant: '<S1198>/Constant'
   *  Constant: '<S1199>/Constant'
   *  Constant: '<S1200>/Constant'
   *  Constant: '<S1202>/Constant'
   *  Constant: '<S1203>/Constant'
   *  Constant: '<S1204>/Constant'
   *  Constant: '<S1205>/Constant'
   *  Logic: '<S1151>/Logical Operator15'
   *  Logic: '<S1151>/Logical Operator16'
   *  Logic: '<S1151>/Logical Operator17'
   *  Logic: '<S1151>/Logical Operator18'
   *  Logic: '<S1151>/Logical Operator19'
   *  Logic: '<S1151>/Logical Operator20'
   *  Logic: '<S1151>/Logical Operator21'
   *  Logic: '<S1151>/Logical Operator5'
   *  Logic: '<S1151>/Logical Operator8'
   *  Logic: '<S1151>/Logical Operator9'
   *  RelationalOperator: '<S1168>/Compare'
   *  RelationalOperator: '<S1170>/Compare'
   *  RelationalOperator: '<S1171>/Compare'
   *  RelationalOperator: '<S1172>/Compare'
   *  RelationalOperator: '<S1177>/Compare'
   *  RelationalOperator: '<S1178>/Compare'
   *  RelationalOperator: '<S1180>/Compare'
   *  RelationalOperator: '<S1181>/Compare'
   *  RelationalOperator: '<S1182>/Compare'
   *  RelationalOperator: '<S1183>/Compare'
   *  RelationalOperator: '<S1184>/Compare'
   *  RelationalOperator: '<S1185>/Compare'
   *  RelationalOperator: '<S1186>/Compare'
   *  RelationalOperator: '<S1187>/Compare'
   *  RelationalOperator: '<S1188>/Compare'
   *  RelationalOperator: '<S1189>/Compare'
   *  RelationalOperator: '<S1191>/Compare'
   *  RelationalOperator: '<S1192>/Compare'
   *  RelationalOperator: '<S1193>/Compare'
   *  RelationalOperator: '<S1194>/Compare'
   *  RelationalOperator: '<S1195>/Compare'
   *  RelationalOperator: '<S1196>/Compare'
   *  RelationalOperator: '<S1197>/Compare'
   *  RelationalOperator: '<S1198>/Compare'
   *  RelationalOperator: '<S1199>/Compare'
   *  RelationalOperator: '<S1200>/Compare'
   *  RelationalOperator: '<S1202>/Compare'
   *  RelationalOperator: '<S1203>/Compare'
   *  RelationalOperator: '<S1204>/Compare'
   *  RelationalOperator: '<S1205>/Compare'
   */
  rtb_LogicalOperator25_k = ((DHP_model_B.VINP_BMSErrNum == 2) ||
    ((DHP_model_B.VINP_BMSErrNum >= 4) && (DHP_model_B.VINP_BMSErrNum <= 13)) ||
    (DHP_model_B.VINP_BMSErrNum == 17) || (DHP_model_B.VINP_BMSErrNum == 18) ||
    (DHP_model_B.VINP_BMSErrNum == 28) || (DHP_model_B.VINP_BMSErrNum == 29) ||
    ((DHP_model_B.VINP_BMSErrNum >= 33) && (DHP_model_B.VINP_BMSErrNum <= 36)) ||
    ((DHP_model_B.VINP_BMSErrNum >= 39) && (DHP_model_B.VINP_BMSErrNum <= 40)) ||
    (DHP_model_B.VINP_BMSErrNum == 44) || ((DHP_model_B.VINP_BMSErrNum >= 48) &&
    (DHP_model_B.VINP_BMSErrNum <= 59)) || ((DHP_model_B.VINP_BMSErrNum >= 62) &&
    (DHP_model_B.VINP_BMSErrNum <= 66)) || (DHP_model_B.VINP_BMSErrNum == 88) ||
    ((DHP_model_B.VINP_BMSErrNum >= 90) && (DHP_model_B.VINP_BMSErrNum <= 92)) ||
    (DHP_model_B.VINP_BMSErrNum == 95) || (DHP_model_B.VINP_BMSErrNum == 97) ||
    (DHP_model_B.VINP_BMSErrNum == 98) || ((DHP_model_B.VINP_BMSErrNum >= 100) &&
    (DHP_model_B.VINP_BMSErrNum <= 102)) || ((DHP_model_B.VINP_BMSErrNum >= 104)
    && (DHP_model_B.VINP_BMSErrNum <= 107)) || ((DHP_model_B.VINP_BMSErrNum >=
    112) && (DHP_model_B.VINP_BMSErrNum <= 116)) || ((DHP_model_B.VINP_BMSErrNum
    >= 118) && (DHP_model_B.VINP_BMSErrNum <= 124)));

  /* Logic: '<S1124>/Logical Operator23' */
  rtb_LogicalOperator6_an =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && rtb_Compare_k0j && rtb_LogicalOperator25_k);

  /* Logic: '<S1124>/Logical Operator31' incorporates:
   *  Logic: '<S1124>/Logical Operator30'
   */
  VDHP_BMSInstFlt2_NoErrNum = (rtb_Compare_bh && (!rtb_LogicalOperator29_c) &&
    DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator);

  /* Logic: '<S1124>/Logical Operator32' */
  VDHP_BMSInstFlt3_RecoveryFlg = !rtb_LogicalOperator6_an;

  /* Logic: '<S1124>/Logical Operator34' */
  VDHP_BMSInstFlt2_RecoveryFlg = !rtb_LogicalOperator22;

  /* Logic: '<S1124>/Logical Operator6' */
  VDHP_BMSInstFlt4_flg =
    (DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator
     && rtb_Compare_oss && rtb_LogicalOperator13_m);

  /* Logic: '<S1124>/Logical Operator8' incorporates:
   *  Logic: '<S1124>/Logical Operator26'
   */
  VDHP_BMSInstFlt3_NoErrNum = (rtb_Compare_k0j && (!rtb_LogicalOperator25_k) &&
    DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator);

  /* Logic: '<S1124>/Logical Operator9' incorporates:
   *  Logic: '<S1124>/Logical Operator14'
   */
  VDHP_BMSInstFlt4_NoErrNum = (rtb_Compare_oss && (!rtb_LogicalOperator13_m) &&
    DHP_model_B.VehPowerOnDelayWorkFlagCollect.DHP_systemtick_Timer_g.RelationalOperator);

  /* Switch: '<S1124>/Switch' incorporates:
   *  Constant: '<S1152>/Constant'
   *  Constant: '<S1153>/Constant'
   *  Constant: '<S1154>/Constant'
   *  Constant: '<S1155>/Constant'
   *  Constant: '<S1156>/Constant'
   *  Constant: '<S1157>/Constant'
   *  Constant: '<S1162>/Constant'
   *  Constant: '<S1164>/Constant'
   *  Constant: '<S1169>/Constant'
   *  Constant: '<S1173>/Constant'
   *  Constant: '<S1179>/Constant'
   *  Constant: '<S1190>/Constant'
   *  Constant: '<S1201>/Constant'
   *  Constant: '<S1212>/Constant'
   *  Logic: '<S1151>/Logical Operator1'
   *  Logic: '<S1151>/Logical Operator3'
   *  RelationalOperator: '<S1152>/Compare'
   *  RelationalOperator: '<S1153>/Compare'
   *  RelationalOperator: '<S1154>/Compare'
   *  RelationalOperator: '<S1155>/Compare'
   *  RelationalOperator: '<S1156>/Compare'
   *  RelationalOperator: '<S1157>/Compare'
   *  RelationalOperator: '<S1162>/Compare'
   *  RelationalOperator: '<S1164>/Compare'
   *  RelationalOperator: '<S1169>/Compare'
   *  RelationalOperator: '<S1173>/Compare'
   *  RelationalOperator: '<S1179>/Compare'
   *  RelationalOperator: '<S1190>/Compare'
   *  RelationalOperator: '<S1201>/Compare'
   *  RelationalOperator: '<S1212>/Compare'
   */
  VDHP_BMSInstFlt3_flg = ((!(DHP_model_B.VPMM_PTReady_flg &&
    ((DHP_model_B.VINP_BMSErrNum == 10) || (DHP_model_B.VINP_BMSErrNum == 13) ||
     (DHP_model_B.VINP_BMSErrNum == 28) || (DHP_model_B.VINP_BMSErrNum == 39) ||
     (DHP_model_B.VINP_BMSErrNum == 40) || (DHP_model_B.VINP_BMSErrNum == 53) ||
     (DHP_model_B.VINP_BMSErrNum == 54) || (DHP_model_B.VINP_BMSErrNum == 56) ||
     (DHP_model_B.VINP_BMSErrNum == 64) || (DHP_model_B.VINP_BMSErrNum == 65) ||
     (DHP_model_B.VINP_BMSErrNum == 66) || (DHP_model_B.VINP_BMSErrNum == 101) ||
     (DHP_model_B.VINP_BMSErrNum == 102) || (DHP_model_B.VINP_BMSErrNum == 104))))
    && rtb_LogicalOperator6_an);

  /* Switch: '<S1124>/Switch1' incorporates:
   *  Constant: '<S1158>/Constant'
   *  Constant: '<S1159>/Constant'
   *  Constant: '<S1165>/Constant'
   *  Constant: '<S1167>/Constant'
   *  Logic: '<S1151>/Logical Operator2'
   *  Logic: '<S1151>/Logical Operator4'
   *  Logic: '<S1151>/Logical Operator6'
   *  RelationalOperator: '<S1158>/Compare'
   *  RelationalOperator: '<S1159>/Compare'
   *  RelationalOperator: '<S1165>/Compare'
   *  RelationalOperator: '<S1167>/Compare'
   */
  VDHP_BMSInstFlt2_flg = ((!(DHP_model_B.VPMM_PTReady_flg &&
    ((DHP_model_B.VINP_BMSErrNum == 39) || (DHP_model_B.VINP_BMSErrNum == 40) ||
     ((DHP_model_B.VINP_BMSErrNum >= 70) && (DHP_model_B.VINP_BMSErrNum <= 85)))))
    && rtb_LogicalOperator22);

  /* Logic: '<S1123>/Logical Operator1' incorporates:
   *  Logic: '<S1123>/Logical Operator2'
   */
  rtb_LogicalOperator6_an = (VDHP_BMSWakeupWork_Flg &&
    (!BMS_113LossCanNetInstFlt_flg));

  /* Switch: '<S1123>/Switch1' incorporates:
   *  Constant: '<S1123>/Constant5'
   *  Constant: '<S1127>/Constant'
   *  Constant: '<S1133>/Constant'
   *  DataTypeConversion: '<S1123>/Data Type Conversion13'
   *  Gain: '<S1123>/Gain14'
   *  Logic: '<S1123>/Logical Operator'
   *  RelationalOperator: '<S1127>/Compare'
   *  RelationalOperator: '<S1133>/Compare'
   */
  if ((DHP_model_B.VINP_BMSBattUOverU == 0.0F) ||
      (DHP_model_B.VINP_BMSBattUOverU == ((uint16_T)MAXUINT16_VAL))) {
    tmp = KDHP_BMS_OverUErrValue;
  } else {
    tmp = (uint16_T)(10.0F * DHP_model_B.VINP_BMSBattUOverU);
  }

  /* End of Switch: '<S1123>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S1123>/DHP_systemtick_Timer' */

  /* Logic: '<S1123>/Logical Operator4' incorporates:
   *  Constant: '<S1123>/10ms*10C'
   *  RelationalOperator: '<S1123>/Relational Operator'
   */
  DHP_model_DHP_systemtick_Timer_k0((DHP_model_B.DataTypeConversion3 > tmp) &&
    rtb_LogicalOperator6_an, VDHP_deltaSystemTick_ms, 100U,
    &DHP_model_DW.DHP_systemtick_Timer_k0);

  /* End of Outputs for SubSystem: '<S1123>/DHP_systemtick_Timer' */

  /* Switch: '<S1123>/Switch3' incorporates:
   *  Constant: '<S1123>/Constant13'
   *  Constant: '<S1128>/Constant'
   *  Constant: '<S1134>/Constant'
   *  DataTypeConversion: '<S1123>/Data Type Conversion12'
   *  Gain: '<S1123>/Gain13'
   *  Logic: '<S1123>/Logical Operator13'
   *  RelationalOperator: '<S1128>/Compare'
   *  RelationalOperator: '<S1134>/Compare'
   */
  if ((DHP_model_B.VINP_BMSBattUUnderU == 0.0F) ||
      (DHP_model_B.VINP_BMSBattUUnderU == ((uint16_T)MAXUINT16_VAL))) {
    tmp = KDHP_BMS_UnderUErrValue;
  } else {
    tmp = (uint16_T)(10.0F * DHP_model_B.VINP_BMSBattUUnderU);
  }

  /* End of Switch: '<S1123>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S1123>/DHP_systemtick_Timer1' */

  /* Logic: '<S1123>/Logical Operator5' incorporates:
   *  Constant: '<S1123>/10ms*10C1'
   *  RelationalOperator: '<S1123>/Relational Operator1'
   */
  DHP_model_DHP_systemtick_Timer1_f(rtb_LogicalOperator6_an &&
    (DHP_model_B.DataTypeConversion3 < tmp), VDHP_deltaSystemTick_ms, 100U,
    &DHP_model_DW.DHP_systemtick_Timer1_f);

  /* End of Outputs for SubSystem: '<S1123>/DHP_systemtick_Timer1' */

  /* Logic: '<S1123>/Logical Operator6' incorporates:
   *  Logic: '<S1123>/Logical Operator7'
   */
  rtb_LogicalOperator6_an = (VDHP_BMSWakeupWork_Flg &&
    (!BMS_633LossCanNetInstFlt_flg));

  /* Switch: '<S1123>/Switch5' incorporates:
   *  Constant: '<S1123>/Constant2'
   *  Constant: '<S1129>/Constant'
   *  Constant: '<S1135>/Constant'
   *  DataTypeConversion: '<S1123>/Data Type Conversion14'
   *  Gain: '<S1123>/Gain15'
   *  Logic: '<S1123>/Logical Operator17'
   *  RelationalOperator: '<S1129>/Compare'
   *  RelationalOperator: '<S1135>/Compare'
   */
  if ((DHP_model_B.VINP_BMSCellUMaxOverU == 0.0F) ||
      (DHP_model_B.VINP_BMSCellUMaxOverU == ((uint16_T)MAXUINT16_VAL))) {
    tmp = KDHP_BMSCell_OverUErrValue;
  } else {
    tmp = (uint16_T)(100.0F * DHP_model_B.VINP_BMSCellUMaxOverU);
  }

  /* End of Switch: '<S1123>/Switch5' */

  /* Outputs for Atomic SubSystem: '<S1123>/DHP_systemtick_Timer2' */

  /* Logic: '<S1123>/Logical Operator8' incorporates:
   *  Constant: '<S1123>/100ms*5C'
   *  RelationalOperator: '<S1123>/Relational Operator2'
   */
  DHP_model_DHP_systemtick_Timer2((DHP_model_B.DataTypeConversion2 > tmp) &&
    rtb_LogicalOperator6_an, VDHP_deltaSystemTick_ms, 500U,
    &DHP_model_DW.DHP_systemtick_Timer2);

  /* End of Outputs for SubSystem: '<S1123>/DHP_systemtick_Timer2' */

  /* Switch: '<S1123>/Switch7' incorporates:
   *  Constant: '<S1123>/Constant3'
   *  Constant: '<S1130>/Constant'
   *  Constant: '<S1136>/Constant'
   *  DataTypeConversion: '<S1123>/Data Type Conversion15'
   *  Gain: '<S1123>/Gain16'
   *  Logic: '<S1123>/Logical Operator18'
   *  RelationalOperator: '<S1130>/Compare'
   *  RelationalOperator: '<S1136>/Compare'
   */
  if ((DHP_model_B.VINP_BMSCellUMinUnderU == 0.0F) ||
      (DHP_model_B.VINP_BMSCellUMinUnderU == ((uint16_T)MAXUINT16_VAL))) {
    tmp = KDHP_BMSCell_UnderUErrValue;
  } else {
    tmp = (uint16_T)(int16_T)(real32_T)floor(100.0F *
      DHP_model_B.VINP_BMSCellUMinUnderU);
  }

  /* End of Switch: '<S1123>/Switch7' */

  /* Outputs for Atomic SubSystem: '<S1123>/DHP_systemtick_Timer3' */

  /* Logic: '<S1123>/Logical Operator9' incorporates:
   *  Constant: '<S1123>/100ms*5C1'
   *  RelationalOperator: '<S1123>/Relational Operator3'
   */
  DHP_model_DHP_systemtick_Timer3(rtb_LogicalOperator6_an &&
    (DHP_model_B.DataTypeConversion4 < tmp), VDHP_deltaSystemTick_ms, 500U,
    &DHP_model_DW.DHP_systemtick_Timer3);

  /* End of Outputs for SubSystem: '<S1123>/DHP_systemtick_Timer3' */

  /* Switch: '<S1123>/Switch9' incorporates:
   *  Constant: '<S1123>/Constant4'
   *  Constant: '<S1131>/Constant'
   *  Constant: '<S1137>/Constant'
   *  Logic: '<S1123>/Logical Operator19'
   *  RelationalOperator: '<S1131>/Compare'
   *  RelationalOperator: '<S1137>/Compare'
   */
  if ((DHP_model_B.VINP_BMSMaxBattTOverT <= 0) ||
      (DHP_model_B.VINP_BMSMaxBattTOverT == ((uint8_T)MAXUINT8_VAL))) {
    tmp_0 = KDHP_BMSBatt_OverTErrValue;
  } else {
    tmp_0 = DHP_model_B.VINP_BMSMaxBattTOverT;
  }

  /* End of Switch: '<S1123>/Switch9' */

  /* Outputs for Atomic SubSystem: '<S1123>/DHP_systemtick_Timer4' */

  /* Logic: '<S1123>/Logical Operator12' incorporates:
   *  Constant: '<S1123>/100ms*5C2'
   *  Logic: '<S1123>/Logical Operator10'
   *  Logic: '<S1123>/Logical Operator11'
   *  RelationalOperator: '<S1123>/Relational Operator4'
   */
  DHP_model_DHP_systemtick_Timer4(VDHP_BMSWakeupWork_Flg &&
    (!BMS_313LossCanNetInstFlt_flg) && (DHP_model_B.VINP_BMSMaxBattT > tmp_0),
    VDHP_deltaSystemTick_ms, 500U, &DHP_model_DW.DHP_systemtick_Timer4);

  /* End of Outputs for SubSystem: '<S1123>/DHP_systemtick_Timer4' */

  /* Logic: '<S1123>/Logical Operator15' incorporates:
   *  Constant: '<S1123>/Constant7'
   *  Constant: '<S1125>/Constant'
   *  Constant: '<S1126>/Constant'
   *  Inport: '<Root>/ENM'
   *  Logic: '<S1123>/Logical Operator14'
   *  Logic: '<S1123>/Logical Operator16'
   *  Logic: '<S1123>/Logical Operator20'
   *  RelationalOperator: '<S1123>/Relational Operator6'
   *  RelationalOperator: '<S1125>/Compare'
   *  RelationalOperator: '<S1126>/Compare'
   */
  VDHP_BMSDischrgPwrAbnormalInstFlt_flg = ((DHP_model_B.DataStoreRead1_j ==
    ((uint8_T)DHP_HW_VCU20)) && VDHP_HVPowerUpDelay2SWork_Flg &&
    ENM_output.ENM_BMSMaxDchaPwrFlt_flg && ((DHP_model_B.VINP_BMSFltRnk_enum ==
    0) || (DHP_model_B.VINP_BMSErrNum == 0) || VDHP_BMSInstFlt2_NoErrNum ||
    VDHP_BMSInstFlt3_NoErrNum || VDHP_BMSInstFlt4_NoErrNum));
}

/* System initialize for function-call system: '<S4>/SysErrProduct2' */
void DHP_model_SysErrProduct2_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S12>/VehDriveSysInstErrGenerate' */
  DHP_model_VehDriveSysInstErrGenerate_Init();

  /* End of SystemInitialize for SubSystem: '<S12>/VehDriveSysInstErrGenerate' */
}

/* Disable for function-call system: '<S4>/SysErrProduct2' */
void DHP_model_SysErrProduct2_Disable(void)
{
  /* Disable for Atomic SubSystem: '<S12>/VcuControlDevice1InstErrGenerate' */
  DHP_model_VcuControlDevice1InstErrGenerate_Disable();

  /* End of Disable for SubSystem: '<S12>/VcuControlDevice1InstErrGenerate' */
}

/* Output and update for function-call system: '<S4>/SysErrProduct2' */
void DHP_model_SysErrProduct2(void)
{
  /* DataStoreRead: '<S12>/Data Store Read1' */
  DHP_model_B.DataStoreRead1_j = VHALI_HWVersion;

  /* Outputs for Atomic SubSystem: '<S12>/VehPowerOnDelayWorkFlagCollect' */
  DHP_model_VehPowerOnDelayWorkFlagCollect(VDHP_NMSleepInd_flg,
    DHP_model_B.Switch, VDHP_VCU_Up_flg, DHP_model_B.LogicalOperator1,
    DHP_model_B.VINP_MCUOperMdl_enum, DHP_model_B.VPMM_LVEna,
    VDHP_deltaSystemTick_ms, DHP_model_B.VINP_BMSOperMod_enum,
    &DHP_model_B.VehPowerOnDelayWorkFlagCollect,
    &DHP_model_DW.VehPowerOnDelayWorkFlagCollect);

  /* End of Outputs for SubSystem: '<S12>/VehPowerOnDelayWorkFlagCollect' */

  /* Outputs for Atomic SubSystem: '<S12>/VcuControlDevice2InstErrGenerate' */
  DHP_model_VcuControlDevice2InstErrGenerate();

  /* End of Outputs for SubSystem: '<S12>/VcuControlDevice2InstErrGenerate' */

  /* Outputs for Atomic SubSystem: '<S12>/VcuControlDevice1InstErrGenerate' */
  DHP_model_VcuControlDevice1InstErrGenerate();

  /* End of Outputs for SubSystem: '<S12>/VcuControlDevice1InstErrGenerate' */

  /* Outputs for Atomic SubSystem: '<S12>/VehDriveSysInstErrGenerate' */
  DHP_model_VehDriveSysInstErrGenerate();

  /* End of Outputs for SubSystem: '<S12>/VehDriveSysInstErrGenerate' */

  /* Outputs for Atomic SubSystem: '<S12>/VehOtherDeviceInstErrGenerate' */
  DHP_model_VehOtherDeviceInstErrGenerate();

  /* End of Outputs for SubSystem: '<S12>/VehOtherDeviceInstErrGenerate' */

  /* Outputs for Atomic SubSystem: '<S12>/VehPowerSysInstErrGenerate' */
  DHP_model_VehPowerSysInstErrGenerate();

  /* End of Outputs for SubSystem: '<S12>/VehPowerSysInstErrGenerate' */
}

/* Output and update for atomic system: '<S1221>/AccPdlHVoltHigh' */
void DHP_model_AccPdlHVoltHigh(void)
{
  /* Outputs for Atomic SubSystem: '<S1242>/Fault_Valid_Time' */

  /* Constant: '<S1233>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1233>/Constant2'
   *  Constant: '<S1233>/KDHP_Allow_Recover'
   *  Constant: '<S1233>/KDHP_Clear_Time'
   *  Constant: '<S1233>/KDHP_Fault_Level'
   *  Constant: '<S1233>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1233>/KDHP_Pwr_limit'
   *  Constant: '<S1233>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AccPdlHVoltHighInstFlt_flg, ((uint16_T)
    KDHP_ACCPDLHVOLTHIGHCONFIRMTIME_MS), ((uint16_T)
    KDHP_ACCPDLHVOLTHIGHCLEARTIME_MS), KDHP_ACCPDLHVOLTHIGHALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_ACCPDLHVOLTHIGHFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ACCPDLHVOLTHIGHSPDLIMIT), ((uint8_T)KDHP_ACCPDLHVOLTHIGHPOWERLIMIT_PCT),
    ((uint16_T)KDHP_ACCPDLHVOLTHIGHHANDLERESPONSEBITS),
    KDHP_AccPdlHVoltHighActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time,
    &DHP_model_DW.Fault_Valid_Time);

  /* End of Outputs for SubSystem: '<S1242>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1221>/AccPdlHVoltLow' */
void DHP_model_AccPdlHVoltLow(void)
{
  /* Outputs for Atomic SubSystem: '<S1247>/Fault_Valid_Time' */

  /* Constant: '<S1234>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1234>/Constant2'
   *  Constant: '<S1234>/KDHP_Allow_Recover'
   *  Constant: '<S1234>/KDHP_Clear_Time'
   *  Constant: '<S1234>/KDHP_Fault_Level'
   *  Constant: '<S1234>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1234>/KDHP_Pwr_limit'
   *  Constant: '<S1234>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AccPdlHVoltLowInstFlt_flg, ((uint16_T)KDHP_ACCPDLHVOLTLOWCONFIRMTIME_MS),
    ((uint16_T)KDHP_ACCPDLHVOLTLOWCLEARTIME_MS),
    KDHP_ACCPDLHVOLTLOWALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ACCPDLHVOLTLOWFAULTLEVEL_ENUM), ((uint8_T)KDHP_ACCPDLHVOLTLOWSPDLIMIT),
    ((uint8_T)KDHP_ACCPDLHVOLTLOWPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ACCPDLHVOLTLOWHANDLERESPONSEBITS),
    KDHP_AccPdlHVoltLowActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_j,
    &DHP_model_DW.Fault_Valid_Time_j);

  /* End of Outputs for SubSystem: '<S1247>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1221>/AccPdlLHVoltDeath' */
void DHP_model_AccPdlLHVoltDeath(void)
{
  /* Outputs for Atomic SubSystem: '<S1252>/Fault_Valid_Time' */

  /* Constant: '<S1235>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1235>/Constant2'
   *  Constant: '<S1235>/KDHP_Allow_Recover'
   *  Constant: '<S1235>/KDHP_Clear_Time'
   *  Constant: '<S1235>/KDHP_Fault_Level'
   *  Constant: '<S1235>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1235>/KDHP_Pwr_limit'
   *  Constant: '<S1235>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AccPdlLHVoltDeathInstFlt_flg, ((uint16_T)
    KDHP_ACCPDLLHVOLTDEATHCONFIRMTIME_MS), ((uint16_T)
    KDHP_ACCPDLLHVOLTDEATHCLEARTIME_MS), KDHP_ACCPDLLHVOLTDEATHALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_ACCPDLLHVOLTDEATHFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ACCPDLLHVOLTDEATHSPDLIMIT), ((uint8_T)
    KDHP_ACCPDLLHVOLTDEATHPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ACCPDLLHVOLTDEATHHANDLERESPONSEBITS),
    KDHP_AccPdlLHVoltDeathActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_o,
    &DHP_model_DW.Fault_Valid_Time_o);

  /* End of Outputs for SubSystem: '<S1252>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1221>/AccPdlLVoltHigh' */
void DHP_model_AccPdlLVoltHigh(void)
{
  /* Outputs for Atomic SubSystem: '<S1257>/Fault_Valid_Time' */

  /* Constant: '<S1236>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1236>/Constant2'
   *  Constant: '<S1236>/KDHP_Allow_Recover'
   *  Constant: '<S1236>/KDHP_Clear_Time'
   *  Constant: '<S1236>/KDHP_Fault_Level'
   *  Constant: '<S1236>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1236>/KDHP_Pwr_limit'
   *  Constant: '<S1236>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AccPdlLVoltHighInstFlt_flg, ((uint16_T)
    KDHP_ACCPDLLVOLTHIGHCONFIRMTIME_MS), ((uint16_T)
    KDHP_ACCPDLLVOLTHIGHCLEARTIME_MS), KDHP_ACCPDLLVOLTHIGHALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_ACCPDLLVOLTHIGHFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ACCPDLLVOLTHIGHSPDLIMIT), ((uint8_T)KDHP_ACCPDLLVOLTHIGHPOWERLIMIT_PCT),
    ((uint16_T)KDHP_ACCPDLLVOLTHIGHHANDLERESPONSEBITS),
    KDHP_AccPdlLVoltHighActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_k,
    &DHP_model_DW.Fault_Valid_Time_k);

  /* End of Outputs for SubSystem: '<S1257>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1221>/AccPdlLVoltLow' */
void DHP_model_AccPdlLVoltLow(void)
{
  /* Outputs for Atomic SubSystem: '<S1262>/Fault_Valid_Time' */

  /* Constant: '<S1237>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1237>/Constant2'
   *  Constant: '<S1237>/KDHP_Allow_Recover'
   *  Constant: '<S1237>/KDHP_Clear_Time'
   *  Constant: '<S1237>/KDHP_Fault_Level'
   *  Constant: '<S1237>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1237>/KDHP_Pwr_limit'
   *  Constant: '<S1237>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AccPdlLVoltLowInstFlt_flg, ((uint16_T)KDHP_ACCPDLLVOLTLOWCONFIRMTIME_MS),
    ((uint16_T)KDHP_ACCPDLLVOLTLOWCLEARTIME_MS),
    KDHP_ACCPDLLVOLTLOWALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ACCPDLLVOLTLOWFAULTLEVEL_ENUM), ((uint8_T)KDHP_ACCPDLLVOLTLOWSPDLIMIT),
    ((uint8_T)KDHP_ACCPDLLVOLTLOWPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ACCPDLLVOLTLOWHANDLERESPONSEBITS),
    KDHP_AccPdlLVoltLowActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_c,
    &DHP_model_DW.Fault_Valid_Time_c);

  /* End of Outputs for SubSystem: '<S1262>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1221>/AccPdlSenRefVoltHigh' */
void DHP_model_AccPdlSenRefVoltHigh(void)
{
  /* Outputs for Atomic SubSystem: '<S1267>/Fault_Valid_Time' */

  /* Constant: '<S1238>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1238>/Constant2'
   *  Constant: '<S1238>/KDHP_Allow_Recover'
   *  Constant: '<S1238>/KDHP_Clear_Time'
   *  Constant: '<S1238>/KDHP_Fault_Level'
   *  Constant: '<S1238>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1238>/KDHP_Pwr_limit'
   *  Constant: '<S1238>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AccPdlSenRefVoltHighInstFlt_flg, ((uint16_T)
    KDHP_ACCPDLSENREFVOLTHIGHCONFIRMTIME_MS), ((uint16_T)
    KDHP_ACCPDLSENREFVOLTHIGHCLEARTIME_MS),
    KDHP_ACCPDLSENREFVOLTHIGHALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ACCPDLSENREFVOLTHIGHFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ACCPDLSENREFVOLTHIGHSPDLIMIT), ((uint8_T)
    KDHP_ACCPDLSENREFVOLTHIGHPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ACCPDLSENREFVOLTHIGHHANDLERESPONSEBITS),
    KDHP_AccPdlSenRefVoltHighActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_b, &DHP_model_DW.Fault_Valid_Time_b);

  /* End of Outputs for SubSystem: '<S1267>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1221>/AccPdlSenRefVoltLow' */
void DHP_model_AccPdlSenRefVoltLow(void)
{
  /* Outputs for Atomic SubSystem: '<S1272>/Fault_Valid_Time' */

  /* Constant: '<S1239>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1239>/Constant2'
   *  Constant: '<S1239>/KDHP_Allow_Recover'
   *  Constant: '<S1239>/KDHP_Clear_Time'
   *  Constant: '<S1239>/KDHP_Fault_Level'
   *  Constant: '<S1239>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1239>/KDHP_Pwr_limit'
   *  Constant: '<S1239>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AccPdlSenRefVoltLowInstFlt_flg, ((uint16_T)
    KDHP_ACCPDLSENREFVOLTLOWCONFIRMTIME_MS), ((uint16_T)
    KDHP_ACCPDLSENREFVOLTLOWCLEARTIME_MS),
    KDHP_ACCPDLSENREFVOLTLOWALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ACCPDLSENREFVOLTLOWFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ACCPDLSENREFVOLTLOWSPDLIMIT), ((uint8_T)
    KDHP_ACCPDLSENREFVOLTLOWPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ACCPDLSENREFVOLTLOWHANDLERESPONSEBITS),
    KDHP_AccPdlSenRefVoltLowActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_n, &DHP_model_DW.Fault_Valid_Time_n);

  /* End of Outputs for SubSystem: '<S1272>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1221>/AccelPdlRat' */
void DHP_model_AccelPdlRat(void)
{
  /* Outputs for Atomic SubSystem: '<S1277>/Fault_Valid_Time' */

  /* Constant: '<S1240>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1240>/Constant2'
   *  Constant: '<S1240>/KDHP_Allow_Recover'
   *  Constant: '<S1240>/KDHP_Clear_Time'
   *  Constant: '<S1240>/KDHP_Fault_Level'
   *  Constant: '<S1240>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1240>/KDHP_Pwr_limit'
   *  Constant: '<S1240>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AccelPdlRatInstFlt_flg, ((uint16_T)KDHP_ACCELPDLRATCONFIRMTIME_MS),
    ((uint16_T)KDHP_ACCELPDLRATCLEARTIME_MS), KDHP_ACCELPDLRATALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_ACCELPDLRATFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ACCELPDLRATSPDLIMIT), ((uint8_T)KDHP_ACCELPDLRATPOWERLIMIT_PCT),
    ((uint16_T)KDHP_ACCELPDLRATHANDLERESPONSEBITS),
    KDHP_AccelPdlRatActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_i,
    &DHP_model_DW.Fault_Valid_Time_i);

  /* End of Outputs for SubSystem: '<S1277>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1221>/AccelPdlRatDeath' */
void DHP_model_AccelPdlRatDeath(void)
{
  boolean_T rtb_Switch1;
  boolean_T rtb_LogicalOperator2_bk;

  /* Outputs for Atomic SubSystem: '<S1282>/Fault_Affirm' */

  /* Constant: '<S1241>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1241>/KDHP_Allow_Recover'
   *  Constant: '<S1241>/KDHP_Clear_Time'
   */
  DHP_model_Fault_Affirm(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AccelPdlRatDeathInstFlt_flg, ((uint16_T)
    KDHP_ACCELPDLRATDEATHCONFIRMTIME_MS), ((uint16_T)
    KDHP_ACCELPDLRATDEATHCLEARTIME_MS), KDHP_ACCELPDLRATDEATHALLOWRECOVERY_FLG,
    &DHP_model_B.Fault_Affirm, &DHP_model_DW.Fault_Affirm);

  /* End of Outputs for SubSystem: '<S1282>/Fault_Affirm' */

  /* Switch: '<S1283>/Switch1' incorporates:
   *  Constant: '<S1241>/Constant2'
   */
  rtb_Switch1 = (KDHP_AccelPdlRatDeathActionSwitchOpen_flg &&
                 DHP_model_B.Fault_Affirm.Switch2);

  /* Switch: '<S1283>/Switch4' incorporates:
   *  Constant: '<S1283>/Constant3'
   */
  if (rtb_Switch1) {
    /* Switch: '<S1283>/Switch5' incorporates:
     *  Constant: '<S1241>/KDHP_Spd_Limit'
     *  Constant: '<S1283>/Constant5'
     *  Constant: '<S1283>/Constant8'
     *  Delay: '<S1283>/Delay1'
     *  Logic: '<S1283>/Logical Operator'
     *  Logic: '<S1283>/Logical Operator1'
     *  RelationalOperator: '<S1283>/Relational Operator3'
     */
    if ((DHP_model_B.Gain9 > KDHP_GradsSpeed1) &&
        (!DHP_model_DW.Delay1_DSTATE_ki)) {
      DHP_model_B.Switch4_ft = KDHP_SpeedLimit_P10292F;
    } else {
      DHP_model_B.Switch4_ft = ((uint8_T)KDHP_ACCELPDLRATDEATHSPDLIMIT);
    }

    /* End of Switch: '<S1283>/Switch5' */
  } else {
    DHP_model_B.Switch4_ft = 200U;
  }

  /* End of Switch: '<S1283>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S1283>/DHP_systemtick_Timer' */

  /* RelationalOperator: '<S1283>/Relational Operator' incorporates:
   *  Constant: '<S1283>/Constant4'
   *  Constant: '<S1283>/Constant6'
   */
  DHP_model_DHP_systemtick_Timer_c(DHP_model_B.Switch4_ft ==
    KDHP_SpeedLimit_P10292F, VDHP_deltaSystemTick_ms,
    KDHP_WaitMoreForFltSecond_ms, &DHP_model_B.DHP_systemtick_Timer_kg,
    &DHP_model_DW.DHP_systemtick_Timer_kg);

  /* End of Outputs for SubSystem: '<S1283>/DHP_systemtick_Timer' */

  /* Logic: '<S1283>/Logical Operator2' */
  rtb_LogicalOperator2_bk = !rtb_Switch1;

  /* Switch: '<S1283>/Switch2' incorporates:
   *  Constant: '<S1241>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1241>/KDHP_Pwr_limit'
   *  Constant: '<S1283>/Constant1'
   *  Constant: '<S1283>/Constant2'
   *  Switch: '<S1283>/Switch3'
   */
  if (rtb_Switch1) {
    DHP_model_B.Switch2_c = ((uint16_T)KDHP_ACCELPDLRATDEATHHANDLERESPONSEBITS);
    DHP_model_B.Switch3_md = ((uint8_T)KDHP_ACCELPDLRATDEATHPOWERLIMIT_PCT);
  } else {
    DHP_model_B.Switch2_c = 0U;
    DHP_model_B.Switch3_md = 100U;
  }

  /* End of Switch: '<S1283>/Switch2' */

  /* Switch: '<S1283>/Switch6' incorporates:
   *  Constant: '<S1283>/Constant9'
   *  Delay: '<S1283>/Delay2'
   *  Logic: '<S1283>/Logical Operator4'
   *  Switch: '<S1283>/Switch7'
   */
  if (rtb_LogicalOperator2_bk || VDHP_NMSleepInd_flg) {
    rtb_Switch1 = false;
  } else {
    rtb_Switch1 = (DHP_model_B.DHP_systemtick_Timer_kg.RelationalOperator ||
                   DHP_model_DW.Delay2_DSTATE_me);
  }

  /* End of Switch: '<S1283>/Switch6' */

  /* Switch: '<S1283>/Switch9' incorporates:
   *  Switch: '<S1283>/Switch8'
   */
  if (VDHP_NMSleepInd_flg) {
    /* Update for Delay: '<S1283>/Delay1' incorporates:
     *  Constant: '<S1283>/Constant12'
     */
    DHP_model_DW.Delay1_DSTATE_ki = false;
  } else if (rtb_LogicalOperator2_bk) {
    /* Switch: '<S1283>/Switch8' incorporates:
     *  Update for Delay: '<S1283>/Delay1'
     */
    DHP_model_DW.Delay1_DSTATE_ki =
      DHP_model_B.DHP_systemtick_Timer_kg.RelationalOperator;
  } else {
    /* Update for Delay: '<S1283>/Delay1' incorporates:
     *  Switch: '<S1283>/Switch8'
     */
    DHP_model_DW.Delay1_DSTATE_ki = rtb_Switch1;
  }

  /* End of Switch: '<S1283>/Switch9' */

  /* Switch: '<S1282>/Switch2' incorporates:
   *  Constant: '<S1241>/Constant2'
   *  Constant: '<S1241>/KDHP_Fault_Level'
   *  Constant: '<S1282>/Constant'
   *  Logic: '<S1282>/Logical Operator'
   */
  if (KDHP_AccelPdlRatDeathActionSwitchOpen_flg &&
      DHP_model_B.Fault_Affirm.Switch2) {
    DHP_model_B.Switch2_bk = ((uint8_T)KDHP_ACCELPDLRATDEATHFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_bk = 0U;
  }

  /* End of Switch: '<S1282>/Switch2' */

  /* Update for Delay: '<S1283>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_me = rtb_Switch1;
}

/* Output and update for atomic system: '<S13>/ACC_Fault' */
void DHP_model_ACC_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1221>/AccPdlHVoltHigh' */
  DHP_model_AccPdlHVoltHigh();

  /* End of Outputs for SubSystem: '<S1221>/AccPdlHVoltHigh' */

  /* Outputs for Atomic SubSystem: '<S1221>/AccPdlHVoltLow' */
  DHP_model_AccPdlHVoltLow();

  /* End of Outputs for SubSystem: '<S1221>/AccPdlHVoltLow' */

  /* Outputs for Atomic SubSystem: '<S1221>/AccPdlLHVoltDeath' */
  DHP_model_AccPdlLHVoltDeath();

  /* End of Outputs for SubSystem: '<S1221>/AccPdlLHVoltDeath' */

  /* Outputs for Atomic SubSystem: '<S1221>/AccPdlLVoltHigh' */
  DHP_model_AccPdlLVoltHigh();

  /* End of Outputs for SubSystem: '<S1221>/AccPdlLVoltHigh' */

  /* Outputs for Atomic SubSystem: '<S1221>/AccPdlLVoltLow' */
  DHP_model_AccPdlLVoltLow();

  /* End of Outputs for SubSystem: '<S1221>/AccPdlLVoltLow' */

  /* Outputs for Atomic SubSystem: '<S1221>/AccPdlSenRefVoltHigh' */
  DHP_model_AccPdlSenRefVoltHigh();

  /* End of Outputs for SubSystem: '<S1221>/AccPdlSenRefVoltHigh' */

  /* Outputs for Atomic SubSystem: '<S1221>/AccPdlSenRefVoltLow' */
  DHP_model_AccPdlSenRefVoltLow();

  /* End of Outputs for SubSystem: '<S1221>/AccPdlSenRefVoltLow' */

  /* Outputs for Atomic SubSystem: '<S1221>/AccelPdlRat' */
  DHP_model_AccelPdlRat();

  /* End of Outputs for SubSystem: '<S1221>/AccelPdlRat' */

  /* Outputs for Atomic SubSystem: '<S1221>/AccelPdlRatDeath' */
  DHP_model_AccelPdlRatDeath();

  /* End of Outputs for SubSystem: '<S1221>/AccelPdlRatDeath' */
}

/* Output and update for atomic system: '<S1222>/OverDiagnVolt' */
void DHP_model_OverDiagnVolt(void)
{
  /* Outputs for Atomic SubSystem: '<S1292>/Fault_Valid_Time' */

  /* Constant: '<S1288>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1288>/Constant2'
   *  Constant: '<S1288>/KDHP_Allow_Recover'
   *  Constant: '<S1288>/KDHP_Clear_Time'
   *  Constant: '<S1288>/KDHP_Fault_Level'
   *  Constant: '<S1288>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1288>/KDHP_Pwr_limit'
   *  Constant: '<S1288>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_OverDiagnVoltInstFlt_Flg, ((uint16_T)KDHP_OVERDIAGNVOLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_OVERDIAGNVOLTCLEARTIME_MS),
    KDHP_OVERDIAGNVOLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_OVERDIAGNVOLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_OVERDIAGNVOLTSPDLIMIT),
    ((uint8_T)KDHP_OVERDIAGNVOLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_OVERDIAGNVOLTHANDLERESPONSEBITS),
    KDHP_OverDiagnVoltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_e,
    &DHP_model_DW.Fault_Valid_Time_e);

  /* End of Outputs for SubSystem: '<S1292>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1222>/PTBusOff' */
void DHP_model_PTBusOff(void)
{
  /* Outputs for Atomic SubSystem: '<S1297>/Fault_Valid_RT' */

  /* Constant: '<S1289>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1289>/Constant2'
   *  Constant: '<S1289>/KDHP_Fault_Level'
   *  Constant: '<S1289>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1289>/KDHP_Pwr_limit'
   *  Constant: '<S1289>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_PTBusOffInstFlt_Flg,
    KDHP_PTBUSOFFALLOWRECOVERY_FLG, ((uint8_T)KDHP_PTBUSOFFFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_PTBUSOFFSPDLIMIT), ((uint8_T)KDHP_PTBUSOFFPOWERLIMIT_PCT),
    ((uint16_T)KDHP_PTBUSOFFHANDLERESPONSEBITS),
    KDHP_PTBusOffActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT,
    &DHP_model_DW.Fault_Valid_RT);

  /* End of Outputs for SubSystem: '<S1297>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1222>/PTCanLoss' */
void DHP_model_PTCanLoss(void)
{
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_Switch1;

  /* Logic: '<S1302>/Logical Operator1' incorporates:
   *  Delay: '<S1302>/Delay2'
   *  Logic: '<S1302>/Logical Operator'
   */
  rtb_LogicalOperator1 = (((!(DHP_model_B.LogicalOperator8_n ||
    VDHP_NMSleepInd_flg)) && DHP_model_DW.Delay2_DSTATE_le) ||
    VDHP_PTCanLossInstFlt_Flg);

  /* Switch: '<S1302>/Switch1' incorporates:
   *  Constant: '<S1302>/Constant12'
   *  Constant: '<S1302>/Constant4'
   *  Delay: '<S1302>/Delay1'
   *  Switch: '<S1302>/Switch2'
   *  Switch: '<S1302>/Switch6'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch1 = false;
    DHP_model_B.Switch2_bz = false;
  } else {
    rtb_Switch1 = (rtb_LogicalOperator1 || DHP_model_DW.Delay1_DSTATE_ma);

    /* Switch: '<S1302>/Switch8' incorporates:
     *  Constant: '<S1290>/KDHP_Allow_Recover'
     *  Delay: '<S1302>/Delay1'
     *  Switch: '<S1302>/Switch6'
     */
    if (KDHP_PTCANLOSSALLOWRECOVERY_FLG) {
      DHP_model_B.Switch2_bz = rtb_LogicalOperator1;
    } else {
      DHP_model_B.Switch2_bz = rtb_Switch1;
    }

    /* End of Switch: '<S1302>/Switch8' */
  }

  /* End of Switch: '<S1302>/Switch1' */

  /* Switch: '<S1301>/Switch2' incorporates:
   *  Constant: '<S1290>/Constant2'
   *  Constant: '<S1290>/KDHP_Fault_Level'
   *  Constant: '<S1290>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1290>/KDHP_Pwr_limit'
   *  Constant: '<S1290>/KDHP_Spd_Limit'
   *  Constant: '<S1300>/Constant'
   *  Constant: '<S1301>/Constant1'
   *  Constant: '<S1301>/Constant2'
   *  Constant: '<S1301>/Constant3'
   *  Switch: '<S1300>/Switch2'
   *  Switch: '<S1301>/Switch1'
   *  Switch: '<S1301>/Switch3'
   *  Switch: '<S1301>/Switch4'
   */
  if (KDHP_PTCanLossActionSwitchOpen_flg && DHP_model_B.Switch2_bz) {
    DHP_model_B.Switch2_eb = ((uint16_T)KDHP_PTCANLOSSHANDLERESPONSEBITS);
    DHP_model_B.Switch3_p = ((uint8_T)KDHP_PTCANLOSSSPDLIMIT);
    DHP_model_B.Switch4_lt = ((uint8_T)KDHP_PTCANLOSSPOWERLIMIT_PCT);
    DHP_model_B.Switch2_p3 = ((uint8_T)KDHP_PTCANLOSSFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_eb = 0U;
    DHP_model_B.Switch3_p = 200U;
    DHP_model_B.Switch4_lt = 100U;
    DHP_model_B.Switch2_p3 = 0U;
  }

  /* End of Switch: '<S1301>/Switch2' */

  /* Update for Delay: '<S1302>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_le = rtb_LogicalOperator1;

  /* Update for Delay: '<S1302>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_ma = rtb_Switch1;
}

/* Output and update for atomic system: '<S1222>/UnderDiagnVolt' */
void DHP_model_UnderDiagnVolt(void)
{
  /* Outputs for Atomic SubSystem: '<S1303>/Fault_Valid_Time' */

  /* Constant: '<S1291>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1291>/Constant2'
   *  Constant: '<S1291>/KDHP_Allow_Recover'
   *  Constant: '<S1291>/KDHP_Clear_Time'
   *  Constant: '<S1291>/KDHP_Fault_Level'
   *  Constant: '<S1291>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1291>/KDHP_Pwr_limit'
   *  Constant: '<S1291>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_UnderDiagnVoltInstFlt_Flg, ((uint16_T)KDHP_UNDERDIAGNVOLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_UNDERDIAGNVOLTCLEARTIME_MS),
    KDHP_UNDERDIAGNVOLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_UNDERDIAGNVOLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_UNDERDIAGNVOLTSPDLIMIT),
    ((uint8_T)KDHP_UNDERDIAGNVOLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_UNDERDIAGNVOLTHANDLERESPONSEBITS),
    KDHP_UnderDiagnVoltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_a,
    &DHP_model_DW.Fault_Valid_Time_a);

  /* End of Outputs for SubSystem: '<S1303>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S13>/BUSOFF_Fault' */
void DHP_model_BUSOFF_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1222>/OverDiagnVolt' */
  DHP_model_OverDiagnVolt();

  /* End of Outputs for SubSystem: '<S1222>/OverDiagnVolt' */

  /* Outputs for Atomic SubSystem: '<S1222>/PTBusOff' */
  DHP_model_PTBusOff();

  /* End of Outputs for SubSystem: '<S1222>/PTBusOff' */

  /* Outputs for Atomic SubSystem: '<S1222>/PTCanLoss' */
  DHP_model_PTCanLoss();

  /* End of Outputs for SubSystem: '<S1222>/PTCanLoss' */

  /* Outputs for Atomic SubSystem: '<S1222>/UnderDiagnVolt' */
  DHP_model_UnderDiagnVolt();

  /* End of Outputs for SubSystem: '<S1222>/UnderDiagnVolt' */
}

/* Output and update for atomic system: '<S1223>/IGN1FeedVoltFlt' */
void DHP_model_IGN1FeedVoltFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1314>/Fault_Valid_RT' */

  /* Constant: '<S1308>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1308>/Constant2'
   *  Constant: '<S1308>/KDHP_Fault_Level'
   *  Constant: '<S1308>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1308>/KDHP_Pwr_limit'
   *  Constant: '<S1308>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_IGN1FeedVErrInstFlt_flg,
    KDHP_IGN1FEEDVOLTFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_IGN1FEEDVOLTFLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_IGN1FEEDVOLTFLTSPDLIMIT),
    ((uint8_T)KDHP_IGN1FEEDVOLTFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_IGN1FEEDVOLTFLTHANDLERESPONSEBITS),
    KDHP_IGN1FeedVoltFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_k,
    &DHP_model_DW.Fault_Valid_RT_k);

  /* End of Outputs for SubSystem: '<S1314>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1223>/IGN2FeedVoltFlt' */
void DHP_model_IGN2FeedVoltFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1317>/Fault_Valid_RT' */

  /* Constant: '<S1309>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1309>/Constant2'
   *  Constant: '<S1309>/KDHP_Fault_Level'
   *  Constant: '<S1309>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1309>/KDHP_Pwr_limit'
   *  Constant: '<S1309>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_IGN2FeedVErrInstFlt_flg,
    KDHP_IGN2FEEDVOLTFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_IGN2FEEDVOLTFLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_IGN2FEEDVOLTFLTSPDLIMIT),
    ((uint8_T)KDHP_IGN2FEEDVOLTFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_IGN2FEEDVOLTFLTHANDLERESPONSEBITS),
    KDHP_IGN2FeedVoltFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_b,
    &DHP_model_DW.Fault_Valid_RT_b);

  /* End of Outputs for SubSystem: '<S1317>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1223>/SSBSyncFlt' */
void DHP_model_SSBSyncFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1320>/Fault_Valid_RT' */

  /* Constant: '<S1310>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1310>/Constant2'
   *  Constant: '<S1310>/KDHP_Fault_Level'
   *  Constant: '<S1310>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1310>/KDHP_Pwr_limit'
   *  Constant: '<S1310>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_SSBSyncErrInstFlt_flg,
    KDHP_SSBSYNCFLTALLOWRECOVERY_FLG, ((uint8_T)KDHP_SSBSYNCFLTFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_SSBSYNCFLTSPDLIMIT), ((uint8_T)KDHP_SSBSYNCFLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_SSBSYNCFLTHANDLERESPONSEBITS),
    KDHP_SSBSyncFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_c,
    &DHP_model_DW.Fault_Valid_RT_c);

  /* End of Outputs for SubSystem: '<S1320>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1223>/VCUHwLSEsclPwrFlt' */
void DHP_model_VCUHwLSEsclPwrFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1323>/Fault_Valid_Time' */

  /* Constant: '<S1311>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1311>/Constant2'
   *  Constant: '<S1311>/KDHP_Allow_Recover'
   *  Constant: '<S1311>/KDHP_Clear_Time'
   *  Constant: '<S1311>/KDHP_Fault_Level'
   *  Constant: '<S1311>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1311>/KDHP_Pwr_limit'
   *  Constant: '<S1311>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHWLSEsclPwrInstFlt_flg, ((uint16_T)
    KDHP_VCUHWLSESCLPWRFLTCONFIRMTIME_MS), ((uint16_T)
    KDHP_VCUHWLSESCLPWRFLTCLEARTIME_MS), KDHP_VCUHWLSESCLPWRFLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWLSESCLPWRFLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWLSESCLPWRFLTSPDLIMIT), ((uint8_T)
    KDHP_VCUHWLSESCLPWRFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_VCUHWLSESCLPWRFLTHANDLERESPONSEBITS),
    KDHP_VCUHwLSEsclPwrFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_l,
    &DHP_model_DW.Fault_Valid_Time_l);

  /* End of Outputs for SubSystem: '<S1323>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1223>/VCUHwLSIGN1Flt' */
void DHP_model_VCUHwLSIGN1Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1328>/Fault_Valid_Time' */

  /* Constant: '<S1312>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1312>/Constant2'
   *  Constant: '<S1312>/KDHP_Allow_Recover'
   *  Constant: '<S1312>/KDHP_Clear_Time'
   *  Constant: '<S1312>/KDHP_Fault_Level'
   *  Constant: '<S1312>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1312>/KDHP_Pwr_limit'
   *  Constant: '<S1312>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLSIGN1InstFlt_flg, ((uint16_T)KDHP_VCUHWLSIGN1FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLSIGN1FLTCLEARTIME_MS),
    KDHP_VCUHWLSIGN1FLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_VCUHWLSIGN1FLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_VCUHWLSIGN1FLTSPDLIMIT),
    ((uint8_T)KDHP_VCUHWLSIGN1FLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_VCUHWLSIGN1FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLSIGN1FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_nv,
    &DHP_model_DW.Fault_Valid_Time_nv);

  /* End of Outputs for SubSystem: '<S1328>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1223>/VCUHwLSIGN2Flt' */
void DHP_model_VCUHwLSIGN2Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1333>/Fault_Valid_Time' */

  /* Constant: '<S1313>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1313>/Constant2'
   *  Constant: '<S1313>/KDHP_Allow_Recover'
   *  Constant: '<S1313>/KDHP_Clear_Time'
   *  Constant: '<S1313>/KDHP_Fault_Level'
   *  Constant: '<S1313>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1313>/KDHP_Pwr_limit'
   *  Constant: '<S1313>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLSIGN2InstFlt_flg, ((uint16_T)KDHP_VCUHWLSIGN2FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLSIGN2FLTCLEARTIME_MS),
    KDHP_VCUHWLSIGN2FLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_VCUHWLSIGN2FLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_VCUHWLSIGN2FLTSPDLIMIT),
    ((uint8_T)KDHP_VCUHWLSIGN2FLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_VCUHWLSIGN2FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLSIGN2FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_f,
    &DHP_model_DW.Fault_Valid_Time_f);

  /* End of Outputs for SubSystem: '<S1333>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S13>/BlueToothKey_Fault' */
void DHP_model_BlueToothKey_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1223>/IGN1FeedVoltFlt' */
  DHP_model_IGN1FeedVoltFlt();

  /* End of Outputs for SubSystem: '<S1223>/IGN1FeedVoltFlt' */

  /* Outputs for Atomic SubSystem: '<S1223>/IGN2FeedVoltFlt' */
  DHP_model_IGN2FeedVoltFlt();

  /* End of Outputs for SubSystem: '<S1223>/IGN2FeedVoltFlt' */

  /* Outputs for Atomic SubSystem: '<S1223>/SSBSyncFlt' */
  DHP_model_SSBSyncFlt();

  /* End of Outputs for SubSystem: '<S1223>/SSBSyncFlt' */

  /* Outputs for Atomic SubSystem: '<S1223>/VCUHwLSEsclPwrFlt' */
  DHP_model_VCUHwLSEsclPwrFlt();

  /* End of Outputs for SubSystem: '<S1223>/VCUHwLSEsclPwrFlt' */

  /* Outputs for Atomic SubSystem: '<S1223>/VCUHwLSIGN1Flt' */
  DHP_model_VCUHwLSIGN1Flt();

  /* End of Outputs for SubSystem: '<S1223>/VCUHwLSIGN1Flt' */

  /* Outputs for Atomic SubSystem: '<S1223>/VCUHwLSIGN2Flt' */
  DHP_model_VCUHwLSIGN2Flt();

  /* End of Outputs for SubSystem: '<S1223>/VCUHwLSIGN2Flt' */
}

/* Output and update for atomic system: '<S1224>/BrkDSCheck0' */
void DHP_model_BrkDSCheck0(void)
{
  /* Outputs for Atomic SubSystem: '<S1340>/Fault_Valid_Time' */

  /* Constant: '<S1338>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1338>/Constant2'
   *  Constant: '<S1338>/KDHP_Allow_Recover'
   *  Constant: '<S1338>/KDHP_Clear_Time'
   *  Constant: '<S1338>/KDHP_Fault_Level'
   *  Constant: '<S1338>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1338>/KDHP_Pwr_limit'
   *  Constant: '<S1338>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_BrkDSCheck0InstFlt_flg, ((uint16_T)KDHP_BRKDSCHECK0CONFIRMTIME_MS),
    ((uint16_T)KDHP_BRKDSCHECK0CLEARTIME_MS), KDHP_BRKDSCHECK0ALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_BRKDSCHECK0FAULTLEVEL_ENUM), ((uint8_T)
    KDHP_BRKDSCHECK0SPDLIMIT), ((uint8_T)KDHP_BRKDSCHECK0POWERLIMIT_PCT),
    ((uint16_T)KDHP_BRKDSCHECK0HANDLERESPONSEBITS),
    KDHP_BrkDSCheck0ActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_d,
    &DHP_model_DW.Fault_Valid_Time_d);

  /* End of Outputs for SubSystem: '<S1340>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1224>/BrkDSCheck1' */
void DHP_model_BrkDSCheck1(void)
{
  /* Outputs for Atomic SubSystem: '<S1345>/Fault_Valid_Time' */

  /* Constant: '<S1339>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1339>/Constant2'
   *  Constant: '<S1339>/KDHP_Allow_Recover'
   *  Constant: '<S1339>/KDHP_Clear_Time'
   *  Constant: '<S1339>/KDHP_Fault_Level'
   *  Constant: '<S1339>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1339>/KDHP_Pwr_limit'
   *  Constant: '<S1339>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_BrkDSCheck1InstFlt_flg, ((uint16_T)KDHP_BRKDSCHECK1CONFIRMTIME_MS),
    ((uint16_T)KDHP_BRKDSCHECK1CLEARTIME_MS), KDHP_BRKDSCHECK1ALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_BRKDSCHECK1FAULTLEVEL_ENUM), ((uint8_T)
    KDHP_BRKDSCHECK1SPDLIMIT), ((uint8_T)KDHP_BRKDSCHECK1POWERLIMIT_PCT),
    ((uint16_T)KDHP_BRKDSCHECK1HANDLERESPONSEBITS),
    KDHP_BrkDSCheck1ActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_am,
    &DHP_model_DW.Fault_Valid_Time_am);

  /* End of Outputs for SubSystem: '<S1345>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S13>/Brk_Fault' */
void DHP_model_Brk_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1224>/BrkDSCheck0' */
  DHP_model_BrkDSCheck0();

  /* End of Outputs for SubSystem: '<S1224>/BrkDSCheck0' */

  /* Outputs for Atomic SubSystem: '<S1224>/BrkDSCheck1' */
  DHP_model_BrkDSCheck1();

  /* End of Outputs for SubSystem: '<S1224>/BrkDSCheck1' */
}

/* Output and update for atomic system: '<S1225>/ABS232Missing' */
void DHP_model_ABS232Missing(void)
{
  /* Outputs for Atomic SubSystem: '<S1373>/Fault_Valid_RT' */

  /* Constant: '<S1350>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1350>/Constant2'
   *  Constant: '<S1350>/KDHP_Fault_Level'
   *  Constant: '<S1350>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1350>/KDHP_Pwr_limit'
   *  Constant: '<S1350>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ABS232MissingInstFlt_flg,
    KDHP_ABS232MISSINGALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ABS232MISSINGFAULTLEVEL_ENUM), ((uint8_T)KDHP_ABS232MISSINGSPDLIMIT),
    ((uint8_T)KDHP_ABS232MISSINGPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ABS232MISSINGHANDLERESPONSEBITS),
    KDHP_ABS232MissingActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_o,
    &DHP_model_DW.Fault_Valid_RT_o);

  /* End of Outputs for SubSystem: '<S1373>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/ABSLossCanNet' */
void DHP_model_ABSLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1376>/Fault_Valid_RT' */

  /* Constant: '<S1351>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1351>/Constant2'
   *  Constant: '<S1351>/KDHP_Fault_Level'
   *  Constant: '<S1351>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1351>/KDHP_Pwr_limit'
   *  Constant: '<S1351>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ABSLossCanNetInstFlt_flg,
    KDHP_ABSLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ABSLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_ABSLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_ABSLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ABSLOSSCANNETHANDLERESPONSEBITS),
    KDHP_ABSLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_i,
    &DHP_model_DW.Fault_Valid_RT_i);

  /* End of Outputs for SubSystem: '<S1376>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/BMS113Missing' */
void DHP_model_BMS113Missing(void)
{
  /* Outputs for Atomic SubSystem: '<S1379>/Fault_Valid_RT' */

  /* Constant: '<S1352>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1352>/Constant2'
   *  Constant: '<S1352>/KDHP_Fault_Level'
   *  Constant: '<S1352>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1352>/KDHP_Pwr_limit'
   *  Constant: '<S1352>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    DHP_model_B.DHP_systemtick_Timer_fl.RelationalOperator,
    KDHP_BMS113MISSINGALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BMS113MISSINGFAULTLEVEL_ENUM), ((uint8_T)KDHP_BMS113MISSINGSPDLIMIT),
    ((uint8_T)KDHP_BMS113MISSINGPOWERLIMIT_PCT), ((uint16_T)
    KDHP_BMS113MISSINGHANDLERESPONSEBITS),
    KDHP_BMS113MissingActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_m,
    &DHP_model_DW.Fault_Valid_RT_m);

  /* End of Outputs for SubSystem: '<S1379>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/BMS303Missing' */
void DHP_model_BMS303Missing(void)
{
  /* Outputs for Atomic SubSystem: '<S1382>/Fault_Valid_RT' */

  /* Constant: '<S1353>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1353>/Constant2'
   *  Constant: '<S1353>/KDHP_Fault_Level'
   *  Constant: '<S1353>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1353>/KDHP_Pwr_limit'
   *  Constant: '<S1353>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    DHP_model_B.DHP_systemtick_Timer_ns.RelationalOperator,
    KDHP_BMS303MISSINGALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BMS303MISSINGFAULTLEVEL_ENUM), ((uint8_T)KDHP_BMS303MISSINGSPDLIMIT),
    ((uint8_T)KDHP_BMS303MISSINGPOWERLIMIT_PCT), ((uint16_T)
    KDHP_BMS303MISSINGHANDLERESPONSEBITS),
    KDHP_BMS303MissingActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_c5,
    &DHP_model_DW.Fault_Valid_RT_c5);

  /* End of Outputs for SubSystem: '<S1382>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/BMSLossCanNet' */
void DHP_model_BMSLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1385>/Fault_Valid_RT' */

  /* Constant: '<S1354>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1354>/Constant2'
   *  Constant: '<S1354>/KDHP_Fault_Level'
   *  Constant: '<S1354>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1354>/KDHP_Pwr_limit'
   *  Constant: '<S1354>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_BMSLossCanNetInstFlt_flg,
    KDHP_BMSLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BMSLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_BMSLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_BMSLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_BMSLOSSCANNETHANDLERESPONSEBITS),
    KDHP_BMSLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_g,
    &DHP_model_DW.Fault_Valid_RT_g);

  /* End of Outputs for SubSystem: '<S1385>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/BMSMissing' */
void DHP_model_BMSMissing(void)
{
  boolean_T rtb_Switch1;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator4_g;
  boolean_T rtb_LogicalOperator2_g3;
  boolean_T rtb_Switch1_po;
  boolean_T rtb_Switch6;
  boolean_T rtb_Switch11_o;

  /* Logic: '<S1390>/Logical Operator1' incorporates:
   *  Delay: '<S1390>/Delay2'
   *  Logic: '<S1390>/Logical Operator'
   */
  rtb_LogicalOperator1 = (((!(DHP_model_B.LogicalOperator20 ||
    VDHP_NMSleepInd_flg)) && DHP_model_DW.Delay2_DSTATE_d) ||
    VDHP_BMSMissingInstFlt_flg);

  /* Switch: '<S1390>/Switch1' incorporates:
   *  Constant: '<S1390>/Constant12'
   *  Constant: '<S1390>/Constant4'
   *  Delay: '<S1390>/Delay1'
   *  Switch: '<S1390>/Switch2'
   *  Switch: '<S1390>/Switch6'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch1_po = false;
    DHP_model_B.Switch2_pe = false;
  } else {
    rtb_Switch1_po = (rtb_LogicalOperator1 || DHP_model_DW.Delay1_DSTATE_pl);

    /* Switch: '<S1390>/Switch8' incorporates:
     *  Constant: '<S1355>/KDHP_Allow_Recover'
     *  Delay: '<S1390>/Delay1'
     *  Switch: '<S1390>/Switch6'
     */
    if (KDHP_BMSMISSINGALLOWRECOVERY_FLG) {
      DHP_model_B.Switch2_pe = rtb_LogicalOperator1;
    } else {
      DHP_model_B.Switch2_pe = rtb_Switch1_po;
    }

    /* End of Switch: '<S1390>/Switch8' */
  }

  /* End of Switch: '<S1390>/Switch1' */

  /* Switch: '<S1389>/Switch1' incorporates:
   *  Constant: '<S1355>/Constant2'
   */
  rtb_Switch1 = (KDHP_BMSMissingActionSwitchOpen_flg && DHP_model_B.Switch2_pe);

  /* Logic: '<S1389>/Logical Operator4' incorporates:
   *  Constant: '<S1389>/Constant11'
   *  RelationalOperator: '<S1389>/Relational Operator2'
   */
  rtb_LogicalOperator4_g = (rtb_Switch1 && (DHP_model_B.Gain9 <
    KDHP_SpeedLimitThreshold_Grads));

  /* Switch: '<S1389>/Switch6' incorporates:
   *  Constant: '<S1389>/Constant14'
   *  Delay: '<S1389>/Delay2'
   *  Delay: '<S1389>/Delay3'
   *  Logic: '<S1389>/Logical Operator5'
   *  Logic: '<S1389>/Logical Operator6'
   *  Logic: '<S1389>/Logical Operator7'
   *  Logic: '<S1389>/Logical Operator8'
   *  Logic: '<S1389>/Logical Operator9'
   */
  if (VDHP_NMSleepInd_flg || (!rtb_Switch1)) {
    rtb_Switch6 = false;
  } else {
    rtb_Switch6 = (DHP_model_DW.Delay3_DSTATE_a ||
                   ((!DHP_model_DW.Delay2_DSTATE_ak) && rtb_LogicalOperator4_g));
  }

  /* End of Switch: '<S1389>/Switch6' */

  /* Switch: '<S1389>/Switch4' incorporates:
   *  Constant: '<S1389>/Constant3'
   */
  if (rtb_Switch1) {
    /* Switch: '<S1389>/Switch5' incorporates:
     *  Constant: '<S1389>/Constant5'
     *  Constant: '<S1389>/Constant8'
     *  Constant: '<S1389>/Constant9'
     *  Delay: '<S1389>/Delay1'
     *  Logic: '<S1389>/Logical Operator'
     *  Logic: '<S1389>/Logical Operator1'
     *  RelationalOperator: '<S1389>/Relational Operator3'
     *  Switch: '<S1389>/Switch10'
     */
    if ((DHP_model_B.Gain9 > KDHP_GradsSpeed1) && (!DHP_model_DW.Delay1_DSTATE_o))
    {
      DHP_model_B.Switch4_lp = KDHP_PwrLimit1_basisSpd;
    } else if (rtb_Switch6) {
      /* Switch: '<S1389>/Switch10' incorporates:
       *  Constant: '<S1355>/KDHP_Pwr_limit'
       */
      DHP_model_B.Switch4_lp = ((uint8_T)KDHP_BMSMISSINGPOWERLIMIT_PCT);
    } else {
      DHP_model_B.Switch4_lp = KDHP_PwrLimit2_basisSpd;
    }

    /* End of Switch: '<S1389>/Switch5' */
  } else {
    DHP_model_B.Switch4_lp = 100U;
  }

  /* End of Switch: '<S1389>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S1389>/DHP_systemtick_Timer' */

  /* RelationalOperator: '<S1389>/Relational Operator' incorporates:
   *  Constant: '<S1389>/Constant4'
   *  Constant: '<S1389>/Constant6'
   */
  DHP_model_DHP_systemtick_Timer_c(DHP_model_B.Switch4_lp ==
    KDHP_PwrLimit1_basisSpd, VDHP_deltaSystemTick_ms,
    KDHP_WaitMoreForFltSecond_ms, &DHP_model_B.DHP_systemtick_Timer_jg1,
    &DHP_model_DW.DHP_systemtick_Timer_jg1);

  /* End of Outputs for SubSystem: '<S1389>/DHP_systemtick_Timer' */

  /* Logic: '<S1389>/Logical Operator2' */
  rtb_LogicalOperator2_g3 = !rtb_Switch1;

  /* Switch: '<S1389>/Switch11' incorporates:
   *  Constant: '<S1389>/Constant17'
   *  Delay: '<S1389>/Delay4'
   *  Logic: '<S1389>/Logical Operator10'
   *  Switch: '<S1389>/Switch12'
   */
  if (rtb_LogicalOperator2_g3 || VDHP_NMSleepInd_flg) {
    rtb_Switch11_o = false;
  } else {
    rtb_Switch11_o = (DHP_model_B.DHP_systemtick_Timer_jg1.RelationalOperator ||
                      DHP_model_DW.Delay4_DSTATE_fxl);
  }

  /* End of Switch: '<S1389>/Switch11' */

  /* Switch: '<S1389>/Switch2' incorporates:
   *  Constant: '<S1355>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1389>/Constant1'
   */
  if (rtb_Switch1) {
    DHP_model_B.Switch2_l = ((uint16_T)KDHP_BMSMISSINGHANDLERESPONSEBITS);
  } else {
    DHP_model_B.Switch2_l = 0U;
  }

  /* End of Switch: '<S1389>/Switch2' */

  /* Switch: '<S1389>/Switch3' incorporates:
   *  Constant: '<S1355>/KDHP_Spd_Limit'
   *  Constant: '<S1389>/Constant2'
   */
  if (rtb_Switch6) {
    DHP_model_B.Switch3_e = ((uint8_T)KDHP_BMSMISSINGSPDLIMIT);
  } else {
    DHP_model_B.Switch3_e = 200U;
  }

  /* End of Switch: '<S1389>/Switch3' */

  /* Switch: '<S1389>/Switch9' incorporates:
   *  Switch: '<S1389>/Switch8'
   */
  if (VDHP_NMSleepInd_flg) {
    /* Update for Delay: '<S1389>/Delay1' incorporates:
     *  Constant: '<S1389>/Constant12'
     */
    DHP_model_DW.Delay1_DSTATE_o = false;
  } else if (rtb_LogicalOperator2_g3) {
    /* Switch: '<S1389>/Switch8' incorporates:
     *  Update for Delay: '<S1389>/Delay1'
     */
    DHP_model_DW.Delay1_DSTATE_o =
      DHP_model_B.DHP_systemtick_Timer_jg1.RelationalOperator;
  } else {
    /* Update for Delay: '<S1389>/Delay1' incorporates:
     *  Switch: '<S1389>/Switch8'
     */
    DHP_model_DW.Delay1_DSTATE_o = rtb_Switch11_o;
  }

  /* End of Switch: '<S1389>/Switch9' */

  /* Switch: '<S1388>/Switch2' incorporates:
   *  Constant: '<S1355>/Constant2'
   *  Constant: '<S1355>/KDHP_Fault_Level'
   *  Constant: '<S1388>/Constant'
   *  Logic: '<S1388>/Logical Operator'
   */
  if (KDHP_BMSMissingActionSwitchOpen_flg && DHP_model_B.Switch2_pe) {
    DHP_model_B.Switch2_nh = ((uint8_T)KDHP_BMSMISSINGFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_nh = 0U;
  }

  /* End of Switch: '<S1388>/Switch2' */

  /* Update for Delay: '<S1390>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_d = rtb_LogicalOperator1;

  /* Update for Delay: '<S1390>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_pl = rtb_Switch1_po;

  /* Update for Delay: '<S1389>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_a = rtb_Switch6;

  /* Update for Delay: '<S1389>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_ak = rtb_LogicalOperator4_g;

  /* Update for Delay: '<S1389>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_fxl = rtb_Switch11_o;
}

/* Output and update for atomic system: '<S1225>/DCDCLossCanNet' */
void DHP_model_DCDCLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1393>/Fault_Valid_RT' */

  /* Constant: '<S1356>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1356>/Constant2'
   *  Constant: '<S1356>/KDHP_Fault_Level'
   *  Constant: '<S1356>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1356>/KDHP_Pwr_limit'
   *  Constant: '<S1356>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_DCDCLossCanNetInstFlt_flg,
    KDHP_DCDCLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_DCDCLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_DCDCLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_DCDCLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_DCDCLOSSCANNETHANDLERESPONSEBITS),
    KDHP_DCDCLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_mf,
    &DHP_model_DW.Fault_Valid_RT_mf);

  /* End of Outputs for SubSystem: '<S1393>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/DCDCMissing' */
void DHP_model_DCDCMissing(void)
{
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_Switch1;

  /* Logic: '<S1398>/Logical Operator1' incorporates:
   *  Delay: '<S1398>/Delay2'
   *  Logic: '<S1398>/Logical Operator'
   */
  rtb_LogicalOperator1 = (((!(DHP_model_B.LogicalOperator4 ||
    VDHP_NMSleepInd_flg)) && DHP_model_DW.Delay2_DSTATE_nzg) ||
    VDHP_DCDCMissingInstFlt_flg);

  /* Switch: '<S1398>/Switch1' incorporates:
   *  Constant: '<S1398>/Constant12'
   *  Constant: '<S1398>/Constant4'
   *  Delay: '<S1398>/Delay1'
   *  Switch: '<S1398>/Switch2'
   *  Switch: '<S1398>/Switch6'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch1 = false;
    DHP_model_B.Switch2_il = false;
  } else {
    rtb_Switch1 = (rtb_LogicalOperator1 || DHP_model_DW.Delay1_DSTATE_p);

    /* Switch: '<S1398>/Switch8' incorporates:
     *  Constant: '<S1357>/KDHP_Allow_Recover'
     *  Delay: '<S1398>/Delay1'
     *  Switch: '<S1398>/Switch6'
     */
    if (KDHP_DCDCMISSINGALLOWRECOVERY_FLG) {
      DHP_model_B.Switch2_il = rtb_LogicalOperator1;
    } else {
      DHP_model_B.Switch2_il = rtb_Switch1;
    }

    /* End of Switch: '<S1398>/Switch8' */
  }

  /* End of Switch: '<S1398>/Switch1' */

  /* Switch: '<S1397>/Switch2' incorporates:
   *  Constant: '<S1357>/Constant2'
   *  Constant: '<S1357>/KDHP_Fault_Level'
   *  Constant: '<S1357>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1357>/KDHP_Pwr_limit'
   *  Constant: '<S1357>/KDHP_Spd_Limit'
   *  Constant: '<S1396>/Constant'
   *  Constant: '<S1397>/Constant1'
   *  Constant: '<S1397>/Constant2'
   *  Constant: '<S1397>/Constant3'
   *  Switch: '<S1396>/Switch2'
   *  Switch: '<S1397>/Switch1'
   *  Switch: '<S1397>/Switch3'
   *  Switch: '<S1397>/Switch4'
   */
  if (KDHP_DCDCMissingActionSwitchOpen_flg && DHP_model_B.Switch2_il) {
    DHP_model_B.Switch2_od = ((uint16_T)KDHP_DCDCMISSINGHANDLERESPONSEBITS);
    DHP_model_B.Switch3_k = ((uint8_T)KDHP_DCDCMISSINGSPDLIMIT);
    DHP_model_B.Switch4_l = ((uint8_T)KDHP_DCDCMISSINGPOWERLIMIT_PCT);
    DHP_model_B.Switch2_ph = ((uint8_T)KDHP_DCDCMISSINGFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_od = 0U;
    DHP_model_B.Switch3_k = 200U;
    DHP_model_B.Switch4_l = 100U;
    DHP_model_B.Switch2_ph = 0U;
  }

  /* End of Switch: '<S1397>/Switch2' */

  /* Update for Delay: '<S1398>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_nzg = rtb_LogicalOperator1;

  /* Update for Delay: '<S1398>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_p = rtb_Switch1;
}

/* Output and update for atomic system: '<S1225>/EACLossCanNet' */
void DHP_model_EACLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1399>/Fault_Valid_RT' */

  /* Constant: '<S1358>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1358>/Constant2'
   *  Constant: '<S1358>/KDHP_Fault_Level'
   *  Constant: '<S1358>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1358>/KDHP_Pwr_limit'
   *  Constant: '<S1358>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EACLossCanNetInstFlt_flg,
    KDHP_EACLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_EACLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_EACLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_EACLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_EACLOSSCANNETHANDLERESPONSEBITS),
    KDHP_EACLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ij,
    &DHP_model_DW.Fault_Valid_RT_ij);

  /* End of Outputs for SubSystem: '<S1399>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/ECCLossCanNet' */
void DHP_model_ECCLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1402>/Fault_Valid_RT' */

  /* Constant: '<S1359>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1359>/Constant2'
   *  Constant: '<S1359>/KDHP_Fault_Level'
   *  Constant: '<S1359>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1359>/KDHP_Pwr_limit'
   *  Constant: '<S1359>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ECCLossCanNetInstFlt_flg,
    KDHP_ECCLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ECCLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_ECCLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_ECCLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ECCLOSSCANNETHANDLERESPONSEBITS),
    KDHP_ECCLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_kt,
    &DHP_model_DW.Fault_Valid_RT_kt);

  /* End of Outputs for SubSystem: '<S1402>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/EHULossCanNet' */
void DHP_model_EHULossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1405>/Fault_Valid_RT' */

  /* Constant: '<S1360>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1360>/Constant2'
   *  Constant: '<S1360>/KDHP_Fault_Level'
   *  Constant: '<S1360>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1360>/KDHP_Pwr_limit'
   *  Constant: '<S1360>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EHULossCanNetInstFlt_flg,
    KDHP_EHULOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_EHULOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_EHULOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_EHULOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_EHULOSSCANNETHANDLERESPONSEBITS),
    KDHP_EHULossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_h,
    &DHP_model_DW.Fault_Valid_RT_h);

  /* End of Outputs for SubSystem: '<S1405>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/EPSLossCanNet' */
void DHP_model_EPSLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1408>/Fault_Valid_RT' */

  /* Constant: '<S1361>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1361>/Constant2'
   *  Constant: '<S1361>/KDHP_Fault_Level'
   *  Constant: '<S1361>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1361>/KDHP_Pwr_limit'
   *  Constant: '<S1361>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EPSLossCanNetInstFlt_flg,
    KDHP_EPSLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_EPSLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_EPSLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_EPSLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_EPSLOSSCANNETHANDLERESPONSEBITS),
    KDHP_EPSLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_cx,
    &DHP_model_DW.Fault_Valid_RT_cx);

  /* End of Outputs for SubSystem: '<S1408>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/GWLossCanNet' */
void DHP_model_GWLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1411>/Fault_Valid_RT' */

  /* Constant: '<S1362>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1362>/Constant2'
   *  Constant: '<S1362>/KDHP_Fault_Level'
   *  Constant: '<S1362>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1362>/KDHP_Pwr_limit'
   *  Constant: '<S1362>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_GWLossCanNetInstFlt_flg,
    KDHP_GWLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_GWLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_GWLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_GWLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_GWLOSSCANNETHANDLERESPONSEBITS), KDHP_GWLossCanNetActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_e, &DHP_model_DW.Fault_Valid_RT_e);

  /* End of Outputs for SubSystem: '<S1411>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/ICMLossCanNet' */
void DHP_model_ICMLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1414>/Fault_Valid_RT' */

  /* Constant: '<S1363>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1363>/Constant2'
   *  Constant: '<S1363>/KDHP_Fault_Level'
   *  Constant: '<S1363>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1363>/KDHP_Pwr_limit'
   *  Constant: '<S1363>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ICMLossCanNetInstFlt_flg,
    KDHP_ICMLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ICMLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_ICMLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_ICMLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ICMLOSSCANNETHANDLERESPONSEBITS),
    KDHP_ICMLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_k4,
    &DHP_model_DW.Fault_Valid_RT_k4);

  /* End of Outputs for SubSystem: '<S1414>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/MCULossCanNet' */
void DHP_model_MCULossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1417>/Fault_Valid_RT' */

  /* Constant: '<S1364>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1364>/Constant2'
   *  Constant: '<S1364>/KDHP_Fault_Level'
   *  Constant: '<S1364>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1364>/KDHP_Pwr_limit'
   *  Constant: '<S1364>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, MCU115LossCanNetInstFlt_flg,
    KDHP_MCULOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCULOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCULOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_MCULOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCULOSSCANNETHANDLERESPONSEBITS),
    KDHP_MCULossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_gf,
    &DHP_model_DW.Fault_Valid_RT_gf);

  /* End of Outputs for SubSystem: '<S1417>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/MCUMissing' */
void DHP_model_MCUMissing(void)
{
  boolean_T rtb_LogicalOperator8_dt;
  boolean_T rtb_LogicalOperator3_aov;
  boolean_T rtb_Switch9;
  uint8_T rtb_Switch5_l;
  boolean_T rtb_LogicalOperator9_j1;
  boolean_T rtb_LogicalOperator2_a5;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_Switch10_gr;
  boolean_T rtb_Switch10_h;
  uint8_T rtb_LogicalOperator3_ks;
  uint32_T rtb_LogicalOperator3_ks_0;
  uint32_T rtb_Switch9_c;
  uint32_T tmp;
  uint32_T tmp_0;
  uint16_T rtb_Switch9_c_0;

  /* Logic: '<S1422>/Logical Operator8' */
  rtb_LogicalOperator8_dt = (MCU115LossCanNetInstFlt_flg &&
    MCU125LossCanNetInstFlt_flg);

  /* Logic: '<S1423>/Logical Operator3' */
  rtb_LogicalOperator3_aov = !rtb_LogicalOperator8_dt;

  /* Switch: '<S1423>/Switch11' incorporates:
   *  Constant: '<S1423>/Constant3'
   *  Delay: '<S1423>/Delay'
   *  Logic: '<S1423>/Logical Operator1'
   *  Logic: '<S1423>/Logical Operator4'
   */
  if (rtb_LogicalOperator8_dt && (!DHP_model_DW.Delay_DSTATE_fm)) {
    rtb_Switch5_l = 0U;
  } else {
    rtb_Switch5_l = VDHP_deltaSystemTick_ms;
  }

  /* End of Switch: '<S1423>/Switch11' */

  /* Switch: '<S1423>/Switch5' incorporates:
   *  Constant: '<S1423>/Constant10'
   *  Constant: '<S1423>/Constant11'
   *  Delay: '<S1423>/Delay7'
   *  Switch: '<S1423>/Switch4'
   */
  if (rtb_LogicalOperator3_aov) {
    rtb_LogicalOperator3_ks = 0U;
    rtb_LogicalOperator3_ks_0 = 0U;
  } else {
    rtb_LogicalOperator3_ks = rtb_Switch5_l;
    rtb_LogicalOperator3_ks_0 = DHP_model_DW.Delay7_DSTATE_d;
  }

  /* End of Switch: '<S1423>/Switch5' */

  /* Sum: '<S1423>/Add6' */
  rtb_LogicalOperator3_ks_0 += rtb_LogicalOperator3_ks;
  if (rtb_LogicalOperator3_ks_0 < rtb_LogicalOperator3_ks) {
    rtb_LogicalOperator3_ks_0 = MAX_uint32_T;
  }

  /* Switch: '<S1423>/Switch1' incorporates:
   *  Constant: '<S1423>/Constant1'
   */
  if (!rtb_LogicalOperator8_dt) {
    rtb_Switch5_l = 0U;
  }

  /* End of Switch: '<S1423>/Switch1' */

  /* Switch: '<S1423>/Switch9' incorporates:
   *  Delay: '<S1423>/Delay4'
   *  Logic: '<S1422>/Logical Operator'
   *  Logic: '<S1422>/Logical Operator10'
   *  Logic: '<S1422>/Logical Operator3'
   *  Logic: '<S1423>/Logical Operator2'
   *  RelationalOperator: '<S1423>/Relational Operator5'
   *  Sum: '<S1423>/Add6'
   */
  if (DHP_model_DW.Delay4_DSTATE_l) {
    rtb_LogicalOperator3_aov = ((!MCU115LossCanNetInstFlt_flg) &&
      (!MCU125LossCanNetInstFlt_flg));
  } else {
    rtb_LogicalOperator3_aov = (rtb_LogicalOperator3_aov &&
      (rtb_LogicalOperator3_ks_0 < 100U));
  }

  /* End of Switch: '<S1423>/Switch9' */

  /* Switch: '<S1423>/Switch7' incorporates:
   *  Constant: '<S1423>/Constant7'
   *  Delay: '<S1423>/Delay2'
   *  Logic: '<S1423>/Logical Operator'
   */
  if (rtb_LogicalOperator3_aov || VDHP_NMSleepInd_flg) {
    rtb_Switch9_c_0 = 0U;
  } else {
    rtb_Switch9_c_0 = DHP_model_DW.Delay2_DSTATE_f;
  }

  /* End of Switch: '<S1423>/Switch7' */

  /* Sum: '<S1423>/Add3' */
  tmp_0 = (uint32_T)rtb_Switch9_c_0 + rtb_Switch5_l;
  if (tmp_0 > 65535U) {
    tmp_0 = 65535U;
  }

  /* RelationalOperator: '<S1423>/Relational Operator3' incorporates:
   *  Constant: '<S1422>/120ms'
   *  Sum: '<S1423>/Add3'
   */
  rtb_LogicalOperator3_aov = ((uint16_T)tmp_0 >= 100);

  /* Logic: '<S1422>/Logical Operator9' */
  rtb_LogicalOperator9_j1 = (MCU215LossCanNetInstFlt_flg &&
    MCU515LossCanNetInstFlt_flg);

  /* Logic: '<S1424>/Logical Operator3' */
  rtb_Switch9 = !rtb_LogicalOperator9_j1;

  /* Switch: '<S1424>/Switch11' incorporates:
   *  Constant: '<S1424>/Constant3'
   *  Delay: '<S1424>/Delay'
   *  Logic: '<S1424>/Logical Operator1'
   *  Logic: '<S1424>/Logical Operator4'
   */
  if (rtb_LogicalOperator9_j1 && (!DHP_model_DW.Delay_DSTATE_gw)) {
    rtb_Switch5_l = 0U;
  } else {
    rtb_Switch5_l = VDHP_deltaSystemTick_ms;
  }

  /* End of Switch: '<S1424>/Switch11' */

  /* Switch: '<S1424>/Switch5' incorporates:
   *  Constant: '<S1424>/Constant10'
   *  Constant: '<S1424>/Constant11'
   *  Delay: '<S1424>/Delay7'
   *  Switch: '<S1424>/Switch4'
   */
  if (rtb_Switch9) {
    rtb_LogicalOperator3_ks = 0U;
    rtb_Switch9_c = 0U;
  } else {
    rtb_LogicalOperator3_ks = rtb_Switch5_l;
    rtb_Switch9_c = DHP_model_DW.Delay7_DSTATE_lc;
  }

  /* End of Switch: '<S1424>/Switch5' */

  /* Sum: '<S1424>/Add6' */
  rtb_Switch9_c += rtb_LogicalOperator3_ks;
  if (rtb_Switch9_c < rtb_LogicalOperator3_ks) {
    rtb_Switch9_c = MAX_uint32_T;
  }

  /* Switch: '<S1424>/Switch9' incorporates:
   *  Delay: '<S1424>/Delay4'
   *  Logic: '<S1422>/Logical Operator11'
   *  Logic: '<S1422>/Logical Operator4'
   *  Logic: '<S1422>/Logical Operator5'
   *  Logic: '<S1424>/Logical Operator2'
   *  RelationalOperator: '<S1424>/Relational Operator5'
   *  Sum: '<S1424>/Add6'
   */
  if (DHP_model_DW.Delay4_DSTATE_bf) {
    rtb_Switch9 = ((!MCU215LossCanNetInstFlt_flg) &&
                   (!MCU515LossCanNetInstFlt_flg));
  } else {
    rtb_Switch9 = (rtb_Switch9 && (rtb_Switch9_c < 1000U));
  }

  /* End of Switch: '<S1424>/Switch9' */

  /* Switch: '<S1424>/Switch1' incorporates:
   *  Constant: '<S1424>/Constant1'
   */
  if (!rtb_LogicalOperator9_j1) {
    rtb_Switch5_l = 0U;
  }

  /* End of Switch: '<S1424>/Switch1' */

  /* Switch: '<S1424>/Switch7' incorporates:
   *  Constant: '<S1424>/Constant7'
   *  Delay: '<S1424>/Delay2'
   *  Logic: '<S1424>/Logical Operator'
   */
  if (rtb_Switch9 || VDHP_NMSleepInd_flg) {
    rtb_Switch9_c_0 = 0U;
  } else {
    rtb_Switch9_c_0 = DHP_model_DW.Delay2_DSTATE_pw;
  }

  /* End of Switch: '<S1424>/Switch7' */

  /* Sum: '<S1424>/Add3' */
  tmp = (uint32_T)rtb_Switch9_c_0 + rtb_Switch5_l;
  if (tmp > 65535U) {
    tmp = 65535U;
  }

  /* RelationalOperator: '<S1424>/Relational Operator3' incorporates:
   *  Constant: '<S1422>/1s'
   *  Sum: '<S1424>/Add3'
   */
  rtb_Switch9 = ((uint16_T)tmp >= 1000);

  /* Logic: '<S1422>/Logical Operator1' incorporates:
   *  Switch: '<S1423>/Switch2'
   *  Switch: '<S1424>/Switch2'
   */
  rtb_LogicalOperator1 = (((!VDHP_NMSleepInd_flg) && rtb_LogicalOperator3_aov) ||
    ((!VDHP_NMSleepInd_flg) && rtb_Switch9));

  /* Switch: '<S1423>/Switch10' incorporates:
   *  Constant: '<S1422>/5s'
   *  Constant: '<S1422>/920ms'
   *  Constant: '<S1423>/Constant13'
   *  Constant: '<S1424>/Constant13'
   *  Delay: '<S1423>/Delay6'
   *  Delay: '<S1424>/Delay6'
   *  RelationalOperator: '<S1423>/Relational Operator2'
   *  RelationalOperator: '<S1424>/Relational Operator2'
   *  Sum: '<S1423>/Add3'
   *  Sum: '<S1424>/Add3'
   *  Switch: '<S1424>/Switch10'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_gr = false;
    rtb_Switch10_h = false;
  } else {
    rtb_Switch10_gr = (((uint16_T)tmp_0 >= 900) || DHP_model_DW.Delay6_DSTATE_n);
    rtb_Switch10_h = (((uint16_T)tmp >= 5000) || DHP_model_DW.Delay6_DSTATE_mv);
  }

  /* End of Switch: '<S1423>/Switch10' */

  /* Logic: '<S1422>/Logical Operator2' incorporates:
   *  Switch: '<S1423>/Switch3'
   *  Switch: '<S1424>/Switch3'
   */
  rtb_LogicalOperator2_a5 = (((!VDHP_NMSleepInd_flg) && rtb_Switch10_gr) ||
    ((!VDHP_NMSleepInd_flg) && rtb_Switch10_h));

  /* Switch: '<S1421>/Switch13' incorporates:
   *  Constant: '<S1365>/Constant2'
   *  Constant: '<S1421>/Constant1'
   *  Constant: '<S1421>/Constant13'
   *  Constant: '<S1421>/Constant2'
   *  Constant: '<S1421>/Constant25'
   *  Constant: '<S1421>/Constant34'
   *  Constant: '<S1421>/下高压处理'
   *  Switch: '<S1421>/Switch1'
   *  Switch: '<S1421>/Switch12'
   *  Switch: '<S1421>/Switch2'
   *  Switch: '<S1421>/Switch26'
   *  Switch: '<S1421>/Switch3'
   *  Switch: '<S1421>/Switch35'
   *  Switch: '<S1421>/Switch4'
   */
  if (KDHP_MCUMissingActionSwitchOpen_flg && rtb_LogicalOperator2_a5) {
    DHP_model_B.Switch13_fa = 0U;
    DHP_model_B.Switch2_gk = 8191U;
    DHP_model_B.Switch3_n4 = 0U;
  } else if (KDHP_MCUMissingActionSwitchOpen_flg && rtb_LogicalOperator1) {
    /* Switch: '<S1421>/Switch26' incorporates:
     *  Constant: '<S1365>/KDHP_Spd_Limit'
     */
    DHP_model_B.Switch13_fa = ((uint8_T)KDHP_MCUMISSINGSPDLIMIT);

    /* Switch: '<S1421>/Switch4' incorporates:
     *  Constant: '<S1365>/KDHP_Handle_Response_Bits'
     */
    DHP_model_B.Switch2_gk = ((uint16_T)KDHP_MCUMISSINGHANDLERESPONSEBITS);

    /* Switch: '<S1421>/Switch35' incorporates:
     *  Constant: '<S1365>/KDHP_Pwr_limit'
     */
    DHP_model_B.Switch3_n4 = ((uint8_T)KDHP_MCUMISSINGPOWERLIMIT_PCT);
  } else {
    DHP_model_B.Switch13_fa = 200U;
    DHP_model_B.Switch2_gk = 0U;
    DHP_model_B.Switch3_n4 = 100U;
  }

  /* End of Switch: '<S1421>/Switch13' */

  /* Logic: '<S1420>/Logical Operator3' */
  DHP_model_B.LogicalOperator3_h = (rtb_LogicalOperator1 ||
    rtb_LogicalOperator2_a5);

  /* Switch: '<S1420>/Switch2' incorporates:
   *  Constant: '<S1365>/Constant2'
   *  Constant: '<S1420>/Constant'
   *  Constant: '<S1420>/Constant1'
   *  Logic: '<S1420>/Logical Operator'
   *  Logic: '<S1420>/Logical Operator4'
   *  Switch: '<S1420>/Switch1'
   */
  if (KDHP_MCUMissingActionSwitchOpen_flg && rtb_LogicalOperator2_a5) {
    DHP_model_B.Switch2_f3 = 3U;
  } else if (KDHP_MCUMissingActionSwitchOpen_flg && rtb_LogicalOperator1) {
    /* Switch: '<S1420>/Switch1' incorporates:
     *  Constant: '<S1365>/KDHP_Fault_Level'
     */
    DHP_model_B.Switch2_f3 = ((uint8_T)KDHP_MCUMISSINGFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_f3 = 0U;
  }

  /* End of Switch: '<S1420>/Switch2' */

  /* Update for Delay: '<S1423>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_l = rtb_LogicalOperator3_aov;

  /* Update for Delay: '<S1423>/Delay' */
  DHP_model_DW.Delay_DSTATE_fm = rtb_LogicalOperator8_dt;

  /* Update for Delay: '<S1423>/Delay7' incorporates:
   *  Sum: '<S1423>/Add6'
   */
  DHP_model_DW.Delay7_DSTATE_d = rtb_LogicalOperator3_ks_0;

  /* Update for Delay: '<S1423>/Delay2' incorporates:
   *  Sum: '<S1423>/Add3'
   */
  DHP_model_DW.Delay2_DSTATE_f = (uint16_T)tmp_0;

  /* Update for Delay: '<S1424>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_bf = rtb_Switch9;

  /* Update for Delay: '<S1424>/Delay' */
  DHP_model_DW.Delay_DSTATE_gw = rtb_LogicalOperator9_j1;

  /* Update for Delay: '<S1424>/Delay7' incorporates:
   *  Sum: '<S1424>/Add6'
   */
  DHP_model_DW.Delay7_DSTATE_lc = rtb_Switch9_c;

  /* Update for Delay: '<S1424>/Delay2' incorporates:
   *  Sum: '<S1424>/Add3'
   */
  DHP_model_DW.Delay2_DSTATE_pw = (uint16_T)tmp;

  /* Update for Delay: '<S1423>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_n = rtb_Switch10_gr;

  /* Update for Delay: '<S1424>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_mv = rtb_Switch10_h;
}

/* Output and update for atomic system: '<S1225>/NMLipHome' */
void DHP_model_NMLipHome(void)
{
  /* Outputs for Atomic SubSystem: '<S1425>/Fault_Valid_Time' */

  /* Constant: '<S1366>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1366>/Constant2'
   *  Constant: '<S1366>/KDHP_Allow_Recover'
   *  Constant: '<S1366>/KDHP_Clear_Time'
   *  Constant: '<S1366>/KDHP_Fault_Level'
   *  Constant: '<S1366>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1366>/KDHP_Pwr_limit'
   *  Constant: '<S1366>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_NMLiphomeInstFlt_flg, ((uint16_T)KDHP_NMLIPHOMECONFIRMTIME_MS),
    ((uint16_T)KDHP_NMLIPHOMECLEARTIME_MS), KDHP_NMLIPHOMEALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_NMLIPHOMEFAULTLEVEL_ENUM), ((uint8_T)KDHP_NMLIPHOMESPDLIMIT),
    ((uint8_T)KDHP_NMLIPHOMEPOWERLIMIT_PCT), ((uint16_T)
    KDHP_NMLIPHOMEHANDLERESPONSEBITS), KDHP_NMLipHomeActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_jx, &DHP_model_DW.Fault_Valid_Time_jx);

  /* End of Outputs for SubSystem: '<S1425>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1225>/OBCLossCanNet' */
void DHP_model_OBCLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1430>/Fault_Valid_RT' */

  /* Constant: '<S1367>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1367>/Constant2'
   *  Constant: '<S1367>/KDHP_Fault_Level'
   *  Constant: '<S1367>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1367>/KDHP_Pwr_limit'
   *  Constant: '<S1367>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_OBCLossCanNetInstFlt_flg,
    KDHP_OBCLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_OBCLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_OBCLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_OBCLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_OBCLOSSCANNETHANDLERESPONSEBITS),
    KDHP_OBCLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_j,
    &DHP_model_DW.Fault_Valid_RT_j);

  /* End of Outputs for SubSystem: '<S1430>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/OBCMissing' */
void DHP_model_OBCMissing(void)
{
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_Switch1;

  /* Logic: '<S1435>/Logical Operator1' incorporates:
   *  Delay: '<S1435>/Delay2'
   *  Logic: '<S1435>/Logical Operator'
   */
  rtb_LogicalOperator1 = (((!(DHP_model_B.LogicalOperator7 ||
    VDHP_NMSleepInd_flg)) && DHP_model_DW.Delay2_DSTATE_c) ||
    VDHP_OBCMissingtInstFlt_flg);

  /* Switch: '<S1435>/Switch1' incorporates:
   *  Constant: '<S1435>/Constant12'
   *  Constant: '<S1435>/Constant4'
   *  Delay: '<S1435>/Delay1'
   *  Switch: '<S1435>/Switch2'
   *  Switch: '<S1435>/Switch6'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch1 = false;
    DHP_model_B.Switch2_n2 = false;
  } else {
    rtb_Switch1 = (rtb_LogicalOperator1 || DHP_model_DW.Delay1_DSTATE_f3);

    /* Switch: '<S1435>/Switch8' incorporates:
     *  Delay: '<S1435>/Delay1'
     *  Switch: '<S1435>/Switch6'
     */
    if (DHP_model_B.Compare_ks) {
      DHP_model_B.Switch2_n2 = rtb_LogicalOperator1;
    } else {
      DHP_model_B.Switch2_n2 = rtb_Switch1;
    }

    /* End of Switch: '<S1435>/Switch8' */
  }

  /* End of Switch: '<S1435>/Switch1' */

  /* Switch: '<S1434>/Switch2' incorporates:
   *  Constant: '<S1368>/Constant2'
   *  Constant: '<S1368>/KDHP_Fault_Level'
   *  Constant: '<S1368>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1368>/KDHP_Pwr_limit'
   *  Constant: '<S1368>/KDHP_Spd_Limit'
   *  Constant: '<S1433>/Constant'
   *  Constant: '<S1434>/Constant1'
   *  Constant: '<S1434>/Constant2'
   *  Constant: '<S1434>/Constant3'
   *  Switch: '<S1433>/Switch2'
   *  Switch: '<S1434>/Switch1'
   *  Switch: '<S1434>/Switch3'
   *  Switch: '<S1434>/Switch4'
   */
  if (KDHP_OBCMissingActionSwitchOpen_flg && DHP_model_B.Switch2_n2) {
    DHP_model_B.Switch2_k = ((uint16_T)KDHP_OBCMISSINGHANDLERESPONSEBITS);
    DHP_model_B.Switch3_fp = ((uint8_T)KDHP_OBCMISSINGSPDLIMIT);
    DHP_model_B.Switch4_m = ((uint8_T)KDHP_OBCMISSINGPOWERLIMIT_PCT);
    DHP_model_B.Switch2_lj = ((uint8_T)KDHP_OBCMISSINGFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_k = 0U;
    DHP_model_B.Switch3_fp = 200U;
    DHP_model_B.Switch4_m = 100U;
    DHP_model_B.Switch2_lj = 0U;
  }

  /* End of Switch: '<S1434>/Switch2' */

  /* Update for Delay: '<S1435>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_c = rtb_LogicalOperator1;

  /* Update for Delay: '<S1435>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_f3 = rtb_Switch1;
}

/* Output and update for atomic system: '<S1225>/SRSLossCanNet' */
void DHP_model_SRSLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1436>/Fault_Valid_RT' */

  /* Constant: '<S1369>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1369>/Constant2'
   *  Constant: '<S1369>/KDHP_Fault_Level'
   *  Constant: '<S1369>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1369>/KDHP_Pwr_limit'
   *  Constant: '<S1369>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    DHP_model_B.DHP_systemtick_Timer_kn.RelationalOperator,
    KDHP_SRSLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_SRSLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_SRSLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_SRSLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_SRSLOSSCANNETHANDLERESPONSEBITS),
    KDHP_SRSLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_og,
    &DHP_model_DW.Fault_Valid_RT_og);

  /* End of Outputs for SubSystem: '<S1436>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/TBOXLossCanNet' */
void DHP_model_TBOXLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1439>/Fault_Valid_RT' */

  /* Constant: '<S1370>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1370>/Constant2'
   *  Constant: '<S1370>/KDHP_Fault_Level'
   *  Constant: '<S1370>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1370>/KDHP_Pwr_limit'
   *  Constant: '<S1370>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_TBOXLossCanNetInstFlt_flg,
    KDHP_TBOXLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_TBOXLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_TBOXLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_TBOXLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_TBOXLOSSCANNETHANDLERESPONSEBITS),
    KDHP_TBOXLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_l,
    &DHP_model_DW.Fault_Valid_RT_l);

  /* End of Outputs for SubSystem: '<S1439>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/TMSLossCanNet' */
void DHP_model_TMSLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1442>/Fault_Valid_RT' */

  /* Constant: '<S1371>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1371>/Constant2'
   *  Constant: '<S1371>/KDHP_Fault_Level'
   *  Constant: '<S1371>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1371>/KDHP_Pwr_limit'
   *  Constant: '<S1371>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_TMSLossCanNetInstFlt_flg,
    KDHP_TMSLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_TMSLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_TMSLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_TMSLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_TMSLOSSCANNETHANDLERESPONSEBITS),
    KDHP_TMSLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ez,
    &DHP_model_DW.Fault_Valid_RT_ez);

  /* End of Outputs for SubSystem: '<S1442>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1225>/XBSLossCanNet' */
void DHP_model_XBSLossCanNet(void)
{
  /* Outputs for Atomic SubSystem: '<S1445>/Fault_Valid_RT' */

  /* Constant: '<S1372>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1372>/Constant2'
   *  Constant: '<S1372>/KDHP_Fault_Level'
   *  Constant: '<S1372>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1372>/KDHP_Pwr_limit'
   *  Constant: '<S1372>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_XBSLossCanNetInstFlt_flg,
    KDHP_XBSLOSSCANNETALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_XBSLOSSCANNETFAULTLEVEL_ENUM), ((uint8_T)KDHP_XBSLOSSCANNETSPDLIMIT),
    ((uint8_T)KDHP_XBSLOSSCANNETPOWERLIMIT_PCT), ((uint16_T)
    KDHP_XBSLOSSCANNETHANDLERESPONSEBITS),
    KDHP_XBSLossCanNetActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_bn,
    &DHP_model_DW.Fault_Valid_RT_bn);

  /* End of Outputs for SubSystem: '<S1445>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S13>/CANComm_Fault' */
void DHP_model_CANComm_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1225>/ABS232Missing' */
  DHP_model_ABS232Missing();

  /* End of Outputs for SubSystem: '<S1225>/ABS232Missing' */

  /* Outputs for Atomic SubSystem: '<S1225>/ABSLossCanNet' */
  DHP_model_ABSLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/ABSLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/BMS113Missing' */
  DHP_model_BMS113Missing();

  /* End of Outputs for SubSystem: '<S1225>/BMS113Missing' */

  /* Outputs for Atomic SubSystem: '<S1225>/BMS303Missing' */
  DHP_model_BMS303Missing();

  /* End of Outputs for SubSystem: '<S1225>/BMS303Missing' */

  /* Outputs for Atomic SubSystem: '<S1225>/BMSLossCanNet' */
  DHP_model_BMSLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/BMSLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/BMSMissing' */
  DHP_model_BMSMissing();

  /* End of Outputs for SubSystem: '<S1225>/BMSMissing' */

  /* Outputs for Atomic SubSystem: '<S1225>/DCDCLossCanNet' */
  DHP_model_DCDCLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/DCDCLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/DCDCMissing' */
  DHP_model_DCDCMissing();

  /* End of Outputs for SubSystem: '<S1225>/DCDCMissing' */

  /* Outputs for Atomic SubSystem: '<S1225>/EACLossCanNet' */
  DHP_model_EACLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/EACLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/ECCLossCanNet' */
  DHP_model_ECCLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/ECCLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/EHULossCanNet' */
  DHP_model_EHULossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/EHULossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/EPSLossCanNet' */
  DHP_model_EPSLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/EPSLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/GWLossCanNet' */
  DHP_model_GWLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/GWLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/ICMLossCanNet' */
  DHP_model_ICMLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/ICMLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/MCULossCanNet' */
  DHP_model_MCULossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/MCULossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/MCUMissing' */
  DHP_model_MCUMissing();

  /* End of Outputs for SubSystem: '<S1225>/MCUMissing' */

  /* Outputs for Atomic SubSystem: '<S1225>/NMLipHome' */
  DHP_model_NMLipHome();

  /* End of Outputs for SubSystem: '<S1225>/NMLipHome' */

  /* Outputs for Atomic SubSystem: '<S1225>/OBCLossCanNet' */
  DHP_model_OBCLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/OBCLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/OBCMissing' */
  DHP_model_OBCMissing();

  /* End of Outputs for SubSystem: '<S1225>/OBCMissing' */

  /* Outputs for Atomic SubSystem: '<S1225>/SRSLossCanNet' */
  DHP_model_SRSLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/SRSLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/TBOXLossCanNet' */
  DHP_model_TBOXLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/TBOXLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/TMSLossCanNet' */
  DHP_model_TMSLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/TMSLossCanNet' */

  /* Outputs for Atomic SubSystem: '<S1225>/XBSLossCanNet' */
  DHP_model_XBSLossCanNet();

  /* End of Outputs for SubSystem: '<S1225>/XBSLossCanNet' */
}

/* Output and update for atomic system: '<S1226>/CoolSysErr' */
void DHP_model_CoolSysErr(void)
{
  /* Outputs for Atomic SubSystem: '<S1449>/Fault_Valid_Time' */

  /* Constant: '<S1448>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1448>/Constant2'
   *  Constant: '<S1448>/KDHP_Allow_Recover'
   *  Constant: '<S1448>/KDHP_Clear_Time'
   *  Constant: '<S1448>/KDHP_Fault_Level'
   *  Constant: '<S1448>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1448>/KDHP_Pwr_limit'
   *  Constant: '<S1448>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_CoolSysErrInstFlt_flg, ((uint16_T)KDHP_COOLSYSERRCONFIRMTIME_MS),
    ((uint16_T)KDHP_COOLSYSERRCLEARTIME_MS), KDHP_COOLSYSERRALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_COOLSYSERRFAULTLEVEL_ENUM), ((uint8_T)KDHP_COOLSYSERRSPDLIMIT),
    ((uint8_T)KDHP_COOLSYSERRPOWERLIMIT_PCT), ((uint16_T)
    KDHP_COOLSYSERRHANDLERESPONSEBITS), KDHP_CoolSysErrActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_nw, &DHP_model_DW.Fault_Valid_Time_nw);

  /* End of Outputs for SubSystem: '<S1449>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S13>/CoolSys_Fault' */
void DHP_model_CoolSys_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1226>/CoolSysErr' */
  DHP_model_CoolSysErr();

  /* End of Outputs for SubSystem: '<S1226>/CoolSysErr' */
}

/* Output and update for atomic system: '<S1227>/GearSingleNotInAera' */
void DHP_model_GearSingleNotInAera(void)
{
  /* Outputs for Atomic SubSystem: '<S1455>/Fault_Valid_Time' */

  /* Constant: '<S1454>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1454>/Constant2'
   *  Constant: '<S1454>/KDHP_Allow_Recover'
   *  Constant: '<S1454>/KDHP_Clear_Time'
   *  Constant: '<S1454>/KDHP_Fault_Level'
   *  Constant: '<S1454>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1454>/KDHP_Pwr_limit'
   *  Constant: '<S1454>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_GearSingleNotInAeraInstFlt_flg, ((uint16_T)
    KDHP_GEARSINGLENOTINAERACONFIRMTIME_MS), ((uint16_T)
    KDHP_GEARSINGLENOTINAERACLEARTIME_MS),
    KDHP_GEARSINGLENOTINAERAALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_GEARSINGLENOTINAERAFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_GEARSINGLENOTINAERASPDLIMIT), ((uint8_T)
    KDHP_GEARSINGLENOTINAERAPOWERLIMIT_PCT), ((uint16_T)
    KDHP_GEARSINGLENOTINAERAHANDLERESPONSEBITS),
    KDHP_GearSingleNotInAeraActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_nvm, &DHP_model_DW.Fault_Valid_Time_nvm);

  /* End of Outputs for SubSystem: '<S1455>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S13>/Gear_Fault' */
void DHP_model_Gear_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1227>/GearSingleNotInAera' */
  DHP_model_GearSingleNotInAera();

  /* End of Outputs for SubSystem: '<S1227>/GearSingleNotInAera' */
}

/* Output and update for atomic system: '<S1228>/AuxBattVoltHighFlt' */
void DHP_model_AuxBattVoltHighFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1464>/Fault_Valid_Time' */

  /* Constant: '<S1460>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1460>/Constant2'
   *  Constant: '<S1460>/KDHP_Allow_Recover'
   *  Constant: '<S1460>/KDHP_Clear_Time'
   *  Constant: '<S1460>/KDHP_Fault_Level'
   *  Constant: '<S1460>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1460>/KDHP_Pwr_limit'
   *  Constant: '<S1460>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AuxBattVoltHighInstFlt_flg, ((uint16_T)
    KDHP_AUXBATTVOLTHIGHFLTCONFIRMTIME_MS), ((uint16_T)
    KDHP_AUXBATTVOLTHIGHFLTCLEARTIME_MS),
    KDHP_AUXBATTVOLTHIGHFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_AUXBATTVOLTHIGHFLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_AUXBATTVOLTHIGHFLTSPDLIMIT), ((uint8_T)
    KDHP_AUXBATTVOLTHIGHFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_AUXBATTVOLTHIGHFLTHANDLERESPONSEBITS),
    KDHP_AuxBattVoltHighFltActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_la, &DHP_model_DW.Fault_Valid_Time_la);

  /* End of Outputs for SubSystem: '<S1464>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1228>/AuxBattVoltHighWarn' */
void DHP_model_AuxBattVoltHighWarn(void)
{
  /* Outputs for Atomic SubSystem: '<S1469>/Fault_Valid_Time' */

  /* Constant: '<S1461>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1461>/Constant2'
   *  Constant: '<S1461>/KDHP_Allow_Recover'
   *  Constant: '<S1461>/KDHP_Clear_Time'
   *  Constant: '<S1461>/KDHP_Fault_Level'
   *  Constant: '<S1461>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1461>/KDHP_Pwr_limit'
   *  Constant: '<S1461>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AuxBattVoltHighInstWarm_flg, ((uint16_T)
    KDHP_AUXBATTVOLTHIGHWARNCONFIRMTIME_MS), ((uint16_T)
    KDHP_AUXBATTVOLTHIGHWARNCLEARTIME_MS),
    KDHP_AUXBATTVOLTHIGHWARNALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_AUXBATTVOLTHIGHWARNFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_AUXBATTVOLTHIGHWARNSPDLIMIT), ((uint8_T)
    KDHP_AUXBATTVOLTHIGHWARNPOWERLIMIT_PCT), ((uint16_T)
    KDHP_AUXBATTVOLTHIGHWARNHANDLERESPONSEBITS),
    KDHP_AuxBattVoltHighWarnActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_h, &DHP_model_DW.Fault_Valid_Time_h);

  /* End of Outputs for SubSystem: '<S1469>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1228>/AuxBattVoltLowFlt' */
void DHP_model_AuxBattVoltLowFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1474>/Fault_Valid_Time' */

  /* Constant: '<S1462>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1462>/Constant2'
   *  Constant: '<S1462>/KDHP_Allow_Recover'
   *  Constant: '<S1462>/KDHP_Clear_Time'
   *  Constant: '<S1462>/KDHP_Fault_Level'
   *  Constant: '<S1462>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1462>/KDHP_Pwr_limit'
   *  Constant: '<S1462>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AuxBattVoltLowInstFlt_flg, ((uint16_T)
    KDHP_AUXBATTVOLTLOWFLTCONFIRMTIME_MS), ((uint16_T)
    KDHP_AUXBATTVOLTLOWFLTCLEARTIME_MS), KDHP_AUXBATTVOLTLOWFLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_AUXBATTVOLTLOWFLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_AUXBATTVOLTLOWFLTSPDLIMIT), ((uint8_T)
    KDHP_AUXBATTVOLTLOWFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_AUXBATTVOLTLOWFLTHANDLERESPONSEBITS),
    KDHP_AuxBattVoltLowFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_n1,
    &DHP_model_DW.Fault_Valid_Time_n1);

  /* End of Outputs for SubSystem: '<S1474>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1228>/AuxBattVoltLowWarn' */
void DHP_model_AuxBattVoltLowWarn(void)
{
  /* Outputs for Atomic SubSystem: '<S1479>/Fault_Valid_Time' */

  /* Constant: '<S1463>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1463>/Constant2'
   *  Constant: '<S1463>/KDHP_Allow_Recover'
   *  Constant: '<S1463>/KDHP_Clear_Time'
   *  Constant: '<S1463>/KDHP_Fault_Level'
   *  Constant: '<S1463>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1463>/KDHP_Pwr_limit'
   *  Constant: '<S1463>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_AuxBattVoltLowInstWarm_flg, ((uint16_T)
    KDHP_AUXBATTVOLTLOWWARNCONFIRMTIME_MS), ((uint16_T)
    KDHP_AUXBATTVOLTLOWWARNCLEARTIME_MS),
    KDHP_AUXBATTVOLTLOWWARNALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_AUXBATTVOLTLOWWARNFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_AUXBATTVOLTLOWWARNSPDLIMIT), ((uint8_T)
    KDHP_AUXBATTVOLTLOWWARNPOWERLIMIT_PCT), ((uint16_T)
    KDHP_AUXBATTVOLTLOWWARNHANDLERESPONSEBITS),
    KDHP_AuxBattVoltLowWarnActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_o0, &DHP_model_DW.Fault_Valid_Time_o0);

  /* End of Outputs for SubSystem: '<S1479>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S13>/LBattery_Fault' */
void DHP_model_LBattery_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1228>/AuxBattVoltHighFlt' */
  DHP_model_AuxBattVoltHighFlt();

  /* End of Outputs for SubSystem: '<S1228>/AuxBattVoltHighFlt' */

  /* Outputs for Atomic SubSystem: '<S1228>/AuxBattVoltHighWarn' */
  DHP_model_AuxBattVoltHighWarn();

  /* End of Outputs for SubSystem: '<S1228>/AuxBattVoltHighWarn' */

  /* Outputs for Atomic SubSystem: '<S1228>/AuxBattVoltLowFlt' */
  DHP_model_AuxBattVoltLowFlt();

  /* End of Outputs for SubSystem: '<S1228>/AuxBattVoltLowFlt' */

  /* Outputs for Atomic SubSystem: '<S1228>/AuxBattVoltLowWarn' */
  DHP_model_AuxBattVoltLowWarn();

  /* End of Outputs for SubSystem: '<S1228>/AuxBattVoltLowWarn' */
}

/* Output and update for atomic system: '<S1229>/ACCHWSignalAbnormal' */
void DHP_model_ACCHWSignalAbnormal(void)
{
  /* Outputs for Atomic SubSystem: '<S1485>/Fault_Valid_Time' */

  /* Constant: '<S1484>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1484>/Constant2'
   *  Constant: '<S1484>/KDHP_Allow_Recover'
   *  Constant: '<S1484>/KDHP_Clear_Time'
   *  Constant: '<S1484>/KDHP_Fault_Level'
   *  Constant: '<S1484>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1484>/KDHP_Pwr_limit'
   *  Constant: '<S1484>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_ACCHWSignalInstFlt_flg, ((uint16_T)
    KDHP_ACCHWSIGNALABNORMALCONFIRMTIME_MS), ((uint16_T)
    KDHP_ACCHWSIGNALABNORMALCLEARTIME_MS),
    KDHP_ACCHWSIGNALABNORMALALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ACCHWSIGNALABNORMALFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ACCHWSIGNALABNORMALSPDLIMIT), ((uint8_T)
    KDHP_ACCHWSIGNALABNORMALPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ACCHWSIGNALABNORMALHANDLERESPONSEBITS),
    KDHP_ACCHWSignalAbnormalActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_le, &DHP_model_DW.Fault_Valid_Time_le);

  /* End of Outputs for SubSystem: '<S1485>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S13>/MechanicalKey_Fault' */
void DHP_model_MechanicalKey_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1229>/ACCHWSignalAbnormal' */
  DHP_model_ACCHWSignalAbnormal();

  /* End of Outputs for SubSystem: '<S1229>/ACCHWSignalAbnormal' */
}

/* Output and update for atomic system: '<S1230>/ChrgFault' */
void DHP_model_ChrgFault(void)
{
  /* Outputs for Atomic SubSystem: '<S1520>/Fault_Valid_RT' */

  /* Constant: '<S1490>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1490>/Constant2'
   *  Constant: '<S1490>/KDHP_Fault_Level'
   *  Constant: '<S1490>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1490>/KDHP_Pwr_limit'
   *  Constant: '<S1490>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ChrgFaultInstFlt_flg,
    KDHP_CHRGFAULTALLOWRECOVERY_FLG, ((uint8_T)KDHP_CHRGFAULTFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_CHRGFAULTSPDLIMIT), ((uint8_T)KDHP_CHRGFAULTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_CHRGFAULTHANDLERESPONSEBITS),
    KDHP_ChrgFaultActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_p,
    &DHP_model_DW.Fault_Valid_RT_p);

  /* End of Outputs for SubSystem: '<S1520>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/ChrgLockCheckTimeout' */
void DHP_model_ChrgLockCheckTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1523>/Fault_Valid_RT' */

  /* Constant: '<S1491>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1491>/Constant2'
   *  Constant: '<S1491>/KDHP_Fault_Level'
   *  Constant: '<S1491>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1491>/KDHP_Pwr_limit'
   *  Constant: '<S1491>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ChrgLockCheckTOInstFlt_flg,
    KDHP_CHRGLOCKCHECKTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CHRGLOCKCHECKTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_CHRGLOCKCHECKTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_CHRGLOCKCHECKTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CHRGLOCKCHECKTIMEOUTHANDLERESPONSEBITS),
    KDHP_ChrgLockCheckTimeoutActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_ew, &DHP_model_DW.Fault_Valid_RT_ew);

  /* End of Outputs for SubSystem: '<S1523>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/ChrgModeAbnormal' */
void DHP_model_ChrgModeAbnormal(void)
{
  /* Outputs for Atomic SubSystem: '<S1526>/Fault_Valid_RT' */

  /* Constant: '<S1492>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1492>/Constant2'
   *  Constant: '<S1492>/KDHP_Fault_Level'
   *  Constant: '<S1492>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1492>/KDHP_Pwr_limit'
   *  Constant: '<S1492>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ChrgModeAbnormalInstFlt_flg,
    KDHP_CHRGMODEABNORMALALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CHRGMODEABNORMALFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_CHRGMODEABNORMALSPDLIMIT), ((uint8_T)
    KDHP_CHRGMODEABNORMALPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CHRGMODEABNORMALHANDLERESPONSEBITS),
    KDHP_ChrgModeAbnormalActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_j1,
    &DHP_model_DW.Fault_Valid_RT_j1);

  /* End of Outputs for SubSystem: '<S1526>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/ChrgModeInvalid' */
void DHP_model_ChrgModeInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1529>/Fault_Valid_RT' */

  /* Constant: '<S1493>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1493>/Constant2'
   *  Constant: '<S1493>/KDHP_Fault_Level'
   *  Constant: '<S1493>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1493>/KDHP_Pwr_limit'
   *  Constant: '<S1493>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ChrgModeInvalidInstFlt_flg,
    KDHP_CHRGMODEINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CHRGMODEINVALIDFAULTLEVEL_ENUM), ((uint8_T)KDHP_CHRGMODEINVALIDSPDLIMIT),
    ((uint8_T)KDHP_CHRGMODEINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CHRGMODEINVALIDHANDLERESPONSEBITS),
    KDHP_ChrgModeInvalidActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_a,
    &DHP_model_DW.Fault_Valid_RT_a);

  /* End of Outputs for SubSystem: '<S1529>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/ChrgOBCSleepTimeout' */
void DHP_model_ChrgOBCSleepTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1532>/Fault_Valid_RT' */

  /* Constant: '<S1494>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1494>/Constant2'
   *  Constant: '<S1494>/KDHP_Fault_Level'
   *  Constant: '<S1494>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1494>/KDHP_Pwr_limit'
   *  Constant: '<S1494>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.LogicalOperator_hq,
    KDHP_CHRGOBCSLEEPTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CHRGOBCSLEEPTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_CHRGOBCSLEEPTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_CHRGOBCSLEEPTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CHRGOBCSLEEPTIMEOUTHANDLERESPONSEBITS),
    KDHP_ChrgOBCSleepTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_cw,
    &DHP_model_DW.Fault_Valid_RT_cw);

  /* End of Outputs for SubSystem: '<S1532>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/ChrgStopAbnormal' */
void DHP_model_ChrgStopAbnormal(void)
{
  /* Outputs for Atomic SubSystem: '<S1535>/Fault_Valid_RT' */

  /* Constant: '<S1495>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1495>/Constant2'
   *  Constant: '<S1495>/KDHP_Fault_Level'
   *  Constant: '<S1495>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1495>/KDHP_Pwr_limit'
   *  Constant: '<S1495>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ChrgStopAbnormalInstFlt_flg,
    KDHP_CHRGSTOPABNORMALALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CHRGSTOPABNORMALFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_CHRGSTOPABNORMALSPDLIMIT), ((uint8_T)
    KDHP_CHRGSTOPABNORMALPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CHRGSTOPABNORMALHANDLERESPONSEBITS),
    KDHP_ChrgStopAbnormalActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ir,
    &DHP_model_DW.Fault_Valid_RT_ir);

  /* End of Outputs for SubSystem: '<S1535>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/ChrgStopLockErr' */
void DHP_model_ChrgStopLockErr(void)
{
  /* Outputs for Atomic SubSystem: '<S1538>/Fault_Valid_RT' */

  /* Constant: '<S1496>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1496>/Constant2'
   *  Constant: '<S1496>/KDHP_Fault_Level'
   *  Constant: '<S1496>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1496>/KDHP_Pwr_limit'
   *  Constant: '<S1496>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ChrgStopLockErrInstFlt_flg,
    KDHP_CHRGSTOPLOCKERRALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CHRGSTOPLOCKERRFAULTLEVEL_ENUM), ((uint8_T)KDHP_CHRGSTOPLOCKERRSPDLIMIT),
    ((uint8_T)KDHP_CHRGSTOPLOCKERRPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CHRGSTOPLOCKERRHANDLERESPONSEBITS),
    KDHP_ChrgStopLockErrActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_an,
    &DHP_model_DW.Fault_Valid_RT_an);

  /* End of Outputs for SubSystem: '<S1538>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/ChrgStopModeInvalid' */
void DHP_model_ChrgStopModeInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1541>/Fault_Valid_RT' */

  /* Constant: '<S1497>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1497>/Constant2'
   *  Constant: '<S1497>/KDHP_Fault_Level'
   *  Constant: '<S1497>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1497>/KDHP_Pwr_limit'
   *  Constant: '<S1497>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_ChrgStopModeInvalidInstFlt_flg,
    KDHP_CHRGSTOPMODEINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CHRGSTOPMODEINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_CHRGSTOPMODEINVALIDSPDLIMIT), ((uint8_T)
    KDHP_CHRGSTOPMODEINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CHRGSTOPMODEINVALIDHANDLERESPONSEBITS),
    KDHP_ChrgStopModeInvalidActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_b1,
    &DHP_model_DW.Fault_Valid_RT_b1);

  /* End of Outputs for SubSystem: '<S1541>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/ChrgStopOperTimeout' */
void DHP_model_ChrgStopOperTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1544>/Fault_Valid_RT' */

  /* Constant: '<S1498>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1498>/Constant2'
   *  Constant: '<S1498>/KDHP_Fault_Level'
   *  Constant: '<S1498>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1498>/KDHP_Pwr_limit'
   *  Constant: '<S1498>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ChrgStopOperTOInstFlt_flg,
    KDHP_CHRGSTOPOPERTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CHRGSTOPOPERTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_CHRGSTOPOPERTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_CHRGSTOPOPERTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CHRGSTOPOPERTIMEOUTHANDLERESPONSEBITS),
    KDHP_ChrgStopOperTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_e3,
    &DHP_model_DW.Fault_Valid_RT_e3);

  /* End of Outputs for SubSystem: '<S1544>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/DCDCStopWorkTimeout' */
void DHP_model_DCDCStopWorkTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1547>/Fault_Valid_RT' */

  /* Constant: '<S1499>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1499>/Constant2'
   *  Constant: '<S1499>/KDHP_Fault_Level'
   *  Constant: '<S1499>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1499>/KDHP_Pwr_limit'
   *  Constant: '<S1499>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_DCDCStopworkTOInstFlt_flg,
    KDHP_DCDCSTOPWORKTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_DCDCSTOPWORKTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_DCDCSTOPWORKTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_DCDCSTOPWORKTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_DCDCSTOPWORKTIMEOUTHANDLERESPONSEBITS),
    KDHP_DCDCStopWorkTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_bz,
    &DHP_model_DW.Fault_Valid_RT_bz);

  /* End of Outputs for SubSystem: '<S1547>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/HVActiveTimeout' */
void DHP_model_HVActiveTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1550>/Fault_Valid_RT' */

  /* Constant: '<S1500>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1500>/Constant2'
   *  Constant: '<S1500>/KDHP_Fault_Level'
   *  Constant: '<S1500>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1500>/KDHP_Pwr_limit'
   *  Constant: '<S1500>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_HVActiveTOInstFlt_flg,
    KDHP_HVACTIVETIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_HVACTIVETIMEOUTFAULTLEVEL_ENUM), ((uint8_T)KDHP_HVACTIVETIMEOUTSPDLIMIT),
    ((uint8_T)KDHP_HVACTIVETIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_HVACTIVETIMEOUTHANDLERESPONSEBITS),
    KDHP_HVActiveTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_n,
    &DHP_model_DW.Fault_Valid_RT_n);

  /* End of Outputs for SubSystem: '<S1550>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/HVDCDCActiveTimeout' */
void DHP_model_HVDCDCActiveTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1553>/Fault_Valid_RT' */

  /* Constant: '<S1501>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1501>/Constant2'
   *  Constant: '<S1501>/KDHP_Fault_Level'
   *  Constant: '<S1501>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1501>/KDHP_Pwr_limit'
   *  Constant: '<S1501>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_HVDCDCActiveTOInstFlt_flg,
    KDHP_HVDCDCACTIVETIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_HVDCDCACTIVETIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_HVDCDCACTIVETIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_HVDCDCACTIVETIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_HVDCDCACTIVETIMEOUTHANDLERESPONSEBITS),
    KDHP_HVDCDCActiveTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_oa,
    &DHP_model_DW.Fault_Valid_RT_oa);

  /* End of Outputs for SubSystem: '<S1553>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/HVDownTimeout' */
void DHP_model_HVDownTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1556>/Fault_Valid_RT' */

  /* Constant: '<S1502>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1502>/Constant2'
   *  Constant: '<S1502>/KDHP_Fault_Level'
   *  Constant: '<S1502>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1502>/KDHP_Pwr_limit'
   *  Constant: '<S1502>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_HVDownTOInstFlt_flg,
    KDHP_HVDOWNTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_HVDOWNTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)KDHP_HVDOWNTIMEOUTSPDLIMIT),
    ((uint8_T)KDHP_HVDOWNTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_HVDOWNTIMEOUTHANDLERESPONSEBITS),
    KDHP_HVDownTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ch,
    &DHP_model_DW.Fault_Valid_RT_ch);

  /* End of Outputs for SubSystem: '<S1556>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/HVILErr' */
void DHP_model_HVILErr(void)
{
  boolean_T rtb_RelationalOperator1_ig;
  boolean_T rtb_LogicalOperator3_f;
  uint8_T rtb_Switch4;
  boolean_T rtb_RelationalOperator3_f;
  uint8_T rtb_LogicalOperator3_ex;
  uint32_T rtb_LogicalOperator3_ex_0;
  uint32_T qY;
  uint32_T qY_0;
  uint32_T qY_1;

  /* Switch: '<S1561>/Switch12' incorporates:
   *  Constant: '<S1561>/Constant3'
   *  Delay: '<S1561>/Delay'
   *  Logic: '<S1561>/Logical Operator1'
   *  Logic: '<S1561>/Logical Operator4'
   */
  if (VDHP_HVILErrInstFlt_flg && (!DHP_model_DW.Delay_DSTATE_gt)) {
    rtb_Switch4 = 0U;
  } else {
    rtb_Switch4 = VDHP_deltaSystemTick_ms;
  }

  /* End of Switch: '<S1561>/Switch12' */

  /* Switch: '<S1561>/Switch' incorporates:
   *  Constant: '<S1561>/Constant2'
   *  Delay: '<S1561>/Delay3'
   *  Logic: '<S1561>/Logical Operator5'
   */
  if (VDHP_HVILErrInstFlt_flg || DHP_model_DW.Delay3_DSTATE_i) {
    rtb_LogicalOperator3_ex = 0U;
  } else {
    rtb_LogicalOperator3_ex = rtb_Switch4;
  }

  /* End of Switch: '<S1561>/Switch' */

  /* Switch: '<S1561>/Switch1' incorporates:
   *  Constant: '<S1561>/Constant1'
   *  Delay: '<S1561>/Delay1'
   */
  if (VDHP_HVILErrInstFlt_flg) {
    qY_1 = 0U;
  } else {
    qY_1 = DHP_model_DW.Delay1_DSTATE_is;
  }

  /* End of Switch: '<S1561>/Switch1' */

  /* Sum: '<S1561>/Add2' */
  qY_1 += rtb_LogicalOperator3_ex;
  if (qY_1 < rtb_LogicalOperator3_ex) {
    qY_1 = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1561>/Relational Operator1' incorporates:
   *  Constant: '<S1503>/KDHP_Clear_Time'
   *  Sum: '<S1561>/Add2'
   */
  rtb_RelationalOperator1_ig = (qY_1 >= ((uint16_T)KDHP_HVILERRCLEARTIME_MS));

  /* Logic: '<S1561>/Logical Operator3' */
  rtb_LogicalOperator3_f = !VDHP_HVILErrInstFlt_flg;

  /* Switch: '<S1561>/Switch6' incorporates:
   *  Constant: '<S1561>/Constant10'
   *  Constant: '<S1561>/Constant11'
   *  Delay: '<S1561>/Delay7'
   *  Switch: '<S1561>/Switch5'
   */
  if (rtb_LogicalOperator3_f) {
    rtb_LogicalOperator3_ex = 0U;
    rtb_LogicalOperator3_ex_0 = 0U;
  } else {
    rtb_LogicalOperator3_ex = rtb_Switch4;
    rtb_LogicalOperator3_ex_0 = DHP_model_DW.Delay7_DSTATE_e;
  }

  /* End of Switch: '<S1561>/Switch6' */

  /* Sum: '<S1561>/Add6' */
  qY_0 = rtb_LogicalOperator3_ex + rtb_LogicalOperator3_ex_0;
  if (qY_0 < rtb_LogicalOperator3_ex) {
    qY_0 = MAX_uint32_T;
  }

  /* Switch: '<S1561>/Switch11' incorporates:
   *  Constant: '<S1503>/Constant1'
   *  Delay: '<S1561>/Delay4'
   *  Logic: '<S1561>/Logical Operator2'
   *  RelationalOperator: '<S1561>/Relational Operator5'
   *  Sum: '<S1561>/Add6'
   */
  if (DHP_model_DW.Delay4_DSTATE_nd) {
    rtb_LogicalOperator3_f = rtb_RelationalOperator1_ig;
  } else {
    rtb_LogicalOperator3_f = (rtb_LogicalOperator3_f && (qY_0 <
      KDHP_HVIL_HVReady_ConfirmTime));
  }

  /* End of Switch: '<S1561>/Switch11' */

  /* Switch: '<S1561>/Switch4' incorporates:
   *  Constant: '<S1561>/Constant4'
   */
  if (!VDHP_HVILErrInstFlt_flg) {
    rtb_Switch4 = 0U;
  }

  /* End of Switch: '<S1561>/Switch4' */

  /* Switch: '<S1561>/Switch8' incorporates:
   *  Constant: '<S1561>/Constant7'
   *  Delay: '<S1561>/Delay2'
   *  Logic: '<S1561>/Logical Operator'
   */
  if (rtb_LogicalOperator3_f || VDHP_NMSleepInd_flg) {
    rtb_LogicalOperator3_ex_0 = 0U;
  } else {
    rtb_LogicalOperator3_ex_0 = DHP_model_DW.Delay2_DSTATE_l0;
  }

  /* End of Switch: '<S1561>/Switch8' */

  /* Sum: '<S1561>/Add3' */
  qY = rtb_LogicalOperator3_ex_0 + rtb_Switch4;
  if (qY < rtb_LogicalOperator3_ex_0) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1561>/Relational Operator3' incorporates:
   *  Constant: '<S1503>/Constant1'
   *  Sum: '<S1561>/Add3'
   */
  rtb_RelationalOperator3_f = (qY >= KDHP_HVIL_HVReady_ConfirmTime);

  /* Switch: '<S1561>/Switch10' incorporates:
   *  Constant: '<S1561>/Constant13'
   *  Delay: '<S1561>/Delay6'
   *  Switch: '<S1561>/Switch7'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_LogicalOperator3_f = false;
  } else {
    rtb_LogicalOperator3_f = (rtb_RelationalOperator3_f ||
      DHP_model_DW.Delay6_DSTATE_oc);
  }

  /* End of Switch: '<S1561>/Switch10' */

  /* Switch: '<S1561>/Switch9' */
  if (!HVIL_VehicleSpeed) {
    rtb_RelationalOperator3_f = rtb_LogicalOperator3_f;
  }

  /* End of Switch: '<S1561>/Switch9' */

  /* Switch: '<S1561>/Switch3' */
  DHP_model_B.Switch3_f5 = ((!VDHP_NMSleepInd_flg) && rtb_RelationalOperator3_f);

  /* Switch: '<S1560>/Switch13' incorporates:
   *  Constant: '<S1503>/Constant2'
   *  Constant: '<S1559>/Constant'
   *  Constant: '<S1560>/Constant1'
   *  Constant: '<S1560>/Constant13'
   *  Constant: '<S1560>/Constant2'
   *  Switch: '<S1559>/Switch2'
   *  Switch: '<S1560>/Switch1'
   *  Switch: '<S1560>/Switch2'
   *  Switch: '<S1560>/Switch3'
   */
  if (KDHP_HVILErrActionSwitchOpen_flg && DHP_model_B.Switch3_f5) {
    /* Switch: '<S1560>/Switch26' incorporates:
     *  Constant: '<S1503>/KDHP_Fault_Level'
     *  Constant: '<S1503>/KDHP_Handle_Response_Bits'
     *  Constant: '<S1503>/KDHP_Pwr_limit'
     *  Constant: '<S1503>/KDHP_Spd_Limit'
     *  Constant: '<S1559>/Constant1'
     *  Constant: '<S1560>/Constant25'
     *  Constant: '<S1560>/Constant34'
     *  Constant: '<S1560>/无车速时 3级故障下高压处理'
     *  Switch: '<S1559>/Switch1'
     *  Switch: '<S1560>/Switch35'
     *  Switch: '<S1560>/Switch4'
     */
    if (HVIL_VehicleSpeed) {
      DHP_model_B.Switch13_f = ((uint8_T)KDHP_HVILERRSPDLIMIT);
      DHP_model_B.Switch2_o3 = ((uint16_T)KDHP_HVILERRHANDLERESPONSEBITS);
      DHP_model_B.Switch3_oc = ((uint8_T)KDHP_HVILERRPOWERLIMIT_PCT);
      DHP_model_B.Switch2_jd = ((uint8_T)KDHP_HVILERRFAULTLEVEL_ENUM);
    } else {
      DHP_model_B.Switch13_f = 0U;
      DHP_model_B.Switch2_o3 = 8191U;
      DHP_model_B.Switch3_oc = 0U;
      DHP_model_B.Switch2_jd = 3U;
    }

    /* End of Switch: '<S1560>/Switch26' */
  } else {
    DHP_model_B.Switch13_f = 200U;
    DHP_model_B.Switch2_o3 = 0U;
    DHP_model_B.Switch3_oc = 100U;
    DHP_model_B.Switch2_jd = 0U;
  }

  /* End of Switch: '<S1560>/Switch13' */

  /* Update for Delay: '<S1561>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_i = rtb_RelationalOperator1_ig;

  /* Update for Delay: '<S1561>/Delay' */
  DHP_model_DW.Delay_DSTATE_gt = VDHP_HVILErrInstFlt_flg;

  /* Update for Delay: '<S1561>/Delay1' incorporates:
   *  Sum: '<S1561>/Add2'
   */
  DHP_model_DW.Delay1_DSTATE_is = qY_1;

  /* Update for Delay: '<S1561>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_nd = rtb_RelationalOperator3_f;

  /* Update for Delay: '<S1561>/Delay7' incorporates:
   *  Sum: '<S1561>/Add6'
   */
  DHP_model_DW.Delay7_DSTATE_e = qY_0;

  /* Update for Delay: '<S1561>/Delay2' incorporates:
   *  Sum: '<S1561>/Add3'
   */
  DHP_model_DW.Delay2_DSTATE_l0 = qY;

  /* Update for Delay: '<S1561>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_oc = rtb_LogicalOperator3_f;
}

/* Output and update for atomic system: '<S1230>/HVPwrUpTimeout' */
void DHP_model_HVPwrUpTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1562>/Fault_Valid_Time' */

  /* Constant: '<S1504>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1504>/Constant2'
   *  Constant: '<S1504>/KDHP_Allow_Recover'
   *  Constant: '<S1504>/KDHP_Clear_Time'
   *  Constant: '<S1504>/KDHP_Fault_Level'
   *  Constant: '<S1504>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1504>/KDHP_Pwr_limit'
   *  Constant: '<S1504>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_HVPwrUpTimeoutInstFlt_flg, ((uint16_T)KDHP_HVPWRUPTIMEOUTCONFIRMTIME_MS),
    ((uint16_T)KDHP_HVPWRUPTIMEOUTCLEARTIME_MS),
    KDHP_HVPWRUPTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_HVPWRUPTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)KDHP_HVPWRUPTIMEOUTSPDLIMIT),
    ((uint8_T)KDHP_HVPWRUPTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_HVPWRUPTIMEOUTHANDLERESPONSEBITS),
    KDHP_HVPwrUpTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_ai,
    &DHP_model_DW.Fault_Valid_Time_ai);

  /* End of Outputs for SubSystem: '<S1562>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1230>/HVUpTimeout' */
void DHP_model_HVUpTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1567>/Fault_Valid_RT' */

  /* Constant: '<S1505>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1505>/Constant2'
   *  Constant: '<S1505>/KDHP_Fault_Level'
   *  Constant: '<S1505>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1505>/KDHP_Pwr_limit'
   *  Constant: '<S1505>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_HVUpTOInstFlt_flg,
    KDHP_HVUPTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)KDHP_HVUPTIMEOUTFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_HVUPTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_HVUPTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_HVUPTIMEOUTHANDLERESPONSEBITS), KDHP_HVUpTimeoutActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_im, &DHP_model_DW.Fault_Valid_RT_im);

  /* End of Outputs for SubSystem: '<S1567>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/LVUpBMSPwrUpAllwTimeout' */
void DHP_model_LVUpBMSPwrUpAllwTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1570>/Fault_Valid_RT' */

  /* Constant: '<S1506>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1506>/Constant2'
   *  Constant: '<S1506>/KDHP_Fault_Level'
   *  Constant: '<S1506>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1506>/KDHP_Pwr_limit'
   *  Constant: '<S1506>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_LVUpBMSPwrUpAllwTOInstFlt_flg,
    KDHP_LVUPBMSPWRUPALLWTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_LVUPBMSPWRUPALLWTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_LVUPBMSPWRUPALLWTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_LVUPBMSPWRUPALLWTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_LVUPBMSPWRUPALLWTIMEOUTHANDLERESPONSEBITS),
    KDHP_LVUpBMSPwrUpAllwTimeoutActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_mv, &DHP_model_DW.Fault_Valid_RT_mv);

  /* End of Outputs for SubSystem: '<S1570>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/LVUpBMSTimeout' */
void DHP_model_LVUpBMSTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1573>/Fault_Valid_RT' */

  /* Constant: '<S1507>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1507>/Constant2'
   *  Constant: '<S1507>/KDHP_Fault_Level'
   *  Constant: '<S1507>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1507>/KDHP_Pwr_limit'
   *  Constant: '<S1507>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_LVUpBMSTOInstFlt_flg,
    KDHP_LVUPBMSTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_LVUPBMSTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)KDHP_LVUPBMSTIMEOUTSPDLIMIT),
    ((uint8_T)KDHP_LVUPBMSTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_LVUPBMSTIMEOUTHANDLERESPONSEBITS),
    KDHP_LVUpBMSTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_d,
    &DHP_model_DW.Fault_Valid_RT_d);

  /* End of Outputs for SubSystem: '<S1573>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/LVUpDCDCTimeout' */
void DHP_model_LVUpDCDCTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1576>/Fault_Valid_RT' */

  /* Constant: '<S1508>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1508>/Constant2'
   *  Constant: '<S1508>/KDHP_Fault_Level'
   *  Constant: '<S1508>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1508>/KDHP_Pwr_limit'
   *  Constant: '<S1508>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_LVUpDCDCTOInstFlt_flg,
    KDHP_LVUPDCDCTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_LVUPDCDCTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)KDHP_LVUPDCDCTIMEOUTSPDLIMIT),
    ((uint8_T)KDHP_LVUPDCDCTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_LVUPDCDCTIMEOUTHANDLERESPONSEBITS),
    KDHP_LVUpDCDCTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_f,
    &DHP_model_DW.Fault_Valid_RT_f);

  /* End of Outputs for SubSystem: '<S1576>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/LVUpMCUTimeout' */
void DHP_model_LVUpMCUTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1579>/Fault_Valid_RT' */

  /* Constant: '<S1509>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1509>/Constant2'
   *  Constant: '<S1509>/KDHP_Fault_Level'
   *  Constant: '<S1509>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1509>/KDHP_Pwr_limit'
   *  Constant: '<S1509>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_LVUpMCUTOInstFlt_flg,
    KDHP_LVUPMCUTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_LVUPMCUTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)KDHP_LVUPMCUTIMEOUTSPDLIMIT),
    ((uint8_T)KDHP_LVUPMCUTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_LVUPMCUTIMEOUTHANDLERESPONSEBITS),
    KDHP_LVUpMCUTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_l3,
    &DHP_model_DW.Fault_Valid_RT_l3);

  /* End of Outputs for SubSystem: '<S1579>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/MCUDischargeTimeout' */
void DHP_model_MCUDischargeTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1582>/Fault_Valid_RT' */

  /* Constant: '<S1510>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1510>/Constant2'
   *  Constant: '<S1510>/KDHP_Fault_Level'
   *  Constant: '<S1510>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1510>/KDHP_Pwr_limit'
   *  Constant: '<S1510>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUDischargeTOInstFlt_flg,
    KDHP_MCUDISCHARGETIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUDISCHARGETIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUDISCHARGETIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_MCUDISCHARGETIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUDISCHARGETIMEOUTHANDLERESPONSEBITS),
    KDHP_MCUDischargeTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_jv,
    &DHP_model_DW.Fault_Valid_RT_jv);

  /* End of Outputs for SubSystem: '<S1582>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/MCUExitTorqTimeout' */
void DHP_model_MCUExitTorqTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1585>/Fault_Valid_RT' */

  /* Constant: '<S1511>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1511>/Constant2'
   *  Constant: '<S1511>/KDHP_Fault_Level'
   *  Constant: '<S1511>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1511>/KDHP_Pwr_limit'
   *  Constant: '<S1511>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUExitTorqTOInstFlt_flg,
    KDHP_MCUEXITTORQTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUEXITTORQTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUEXITTORQTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_MCUEXITTORQTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUEXITTORQTIMEOUTHANDLERESPONSEBITS),
    KDHP_MCUExitTorqTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_bm,
    &DHP_model_DW.Fault_Valid_RT_bm);

  /* End of Outputs for SubSystem: '<S1585>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/MCUHVActiveTimeout' */
void DHP_model_MCUHVActiveTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1588>/Fault_Valid_RT' */

  /* Constant: '<S1512>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1512>/Constant2'
   *  Constant: '<S1512>/KDHP_Fault_Level'
   *  Constant: '<S1512>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1512>/KDHP_Pwr_limit'
   *  Constant: '<S1512>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUHVActiveTOInstFlt_flg,
    KDHP_MCUHVACTIVETIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUHVACTIVETIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUHVACTIVETIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_MCUHVACTIVETIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUHVACTIVETIMEOUTHANDLERESPONSEBITS),
    KDHP_MCUHVActiveTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_kz,
    &DHP_model_DW.Fault_Valid_RT_kz);

  /* End of Outputs for SubSystem: '<S1588>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/OBCWakeupTimeout' */
void DHP_model_OBCWakeupTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1591>/Fault_Valid_RT' */

  /* Constant: '<S1513>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1513>/Constant2'
   *  Constant: '<S1513>/KDHP_Fault_Level'
   *  Constant: '<S1513>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1513>/KDHP_Pwr_limit'
   *  Constant: '<S1513>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_OBCWakeupTOInstFlt_flg,
    KDHP_OBCWAKEUPTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_OBCWAKEUPTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_OBCWAKEUPTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_OBCWAKEUPTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_OBCWAKEUPTIMEOUTHANDLERESPONSEBITS),
    KDHP_OBCWakeupTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_c0,
    &DHP_model_DW.Fault_Valid_RT_c0);

  /* End of Outputs for SubSystem: '<S1591>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/SRSMissing' */
void DHP_model_SRSMissing(void)
{
  /* Outputs for Atomic SubSystem: '<S1594>/Fault_Valid_Time' */

  /* Constant: '<S1514>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1514>/Constant2'
   *  Constant: '<S1514>/KDHP_Allow_Recover'
   *  Constant: '<S1514>/KDHP_Clear_Time'
   *  Constant: '<S1514>/KDHP_Fault_Level'
   *  Constant: '<S1514>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1514>/KDHP_Pwr_limit'
   *  Constant: '<S1514>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VehCrashCanSignalInstFlt_flg, ((uint16_T)KDHP_SRSMISSINGCONFIRMTIME_MS),
    ((uint16_T)KDHP_SRSMISSINGCLEARTIME_MS), KDHP_SRSMISSINGALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_SRSMISSINGFAULTLEVEL_ENUM), ((uint8_T)KDHP_SRSMISSINGSPDLIMIT),
    ((uint8_T)KDHP_SRSMISSINGPOWERLIMIT_PCT), ((uint16_T)
    KDHP_SRSMISSINGHANDLERESPONSEBITS), KDHP_SRSMissingActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_os, &DHP_model_DW.Fault_Valid_Time_os);

  /* End of Outputs for SubSystem: '<S1594>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1230>/ShiftKnobCheckTimeout' */
void DHP_model_ShiftKnobCheckTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S1599>/Fault_Valid_RT' */

  /* Constant: '<S1515>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1515>/Constant2'
   *  Constant: '<S1515>/KDHP_Fault_Level'
   *  Constant: '<S1515>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1515>/KDHP_Pwr_limit'
   *  Constant: '<S1515>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ShiftKnobCheckTOInstFlt_flg,
    KDHP_SHIFTKNOBCHECKTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_SHIFTKNOBCHECKTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_SHIFTKNOBCHECKTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_SHIFTKNOBCHECKTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_SHIFTKNOBCHECKTIMEOUTHANDLERESPONSEBITS),
    KDHP_ShiftKnobCheckTimeoutActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_kv, &DHP_model_DW.Fault_Valid_RT_kv);

  /* End of Outputs for SubSystem: '<S1599>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/VCUChrgReqLimFac' */
void DHP_model_VCUChrgReqLimFac(void)
{
  /* Outputs for Atomic SubSystem: '<S1602>/Fault_Valid_RT' */

  /* Constant: '<S1516>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1516>/Constant2'
   *  Constant: '<S1516>/KDHP_Fault_Level'
   *  Constant: '<S1516>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1516>/KDHP_Pwr_limit'
   *  Constant: '<S1516>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ChrgReqLimFacInstFlt_flg,
    KDHP_VCUCHRGREQLIMFACALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_VCUCHRGREQLIMFACFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUCHRGREQLIMFACSPDLIMIT), ((uint8_T)
    KDHP_VCUCHRGREQLIMFACPOWERLIMIT_PCT), ((uint16_T)
    KDHP_VCUCHRGREQLIMFACHANDLERESPONSEBITS),
    KDHP_VCUChrgReqLimFacActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ho,
    &DHP_model_DW.Fault_Valid_RT_ho);

  /* End of Outputs for SubSystem: '<S1602>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/VehCrash' */
void DHP_model_VehCrash(void)
{
  /* Outputs for Atomic SubSystem: '<S1605>/Fault_Valid_RT' */

  /* Constant: '<S1517>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1517>/Constant2'
   *  Constant: '<S1517>/KDHP_Fault_Level'
   *  Constant: '<S1517>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1517>/KDHP_Pwr_limit'
   *  Constant: '<S1517>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_VehCrashInstFlt_flg,
    KDHP_VEHCRASHALLOWRECOVERY_FLG, ((uint8_T)KDHP_VEHCRASHFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_VEHCRASHSPDLIMIT), ((uint8_T)KDHP_VEHCRASHPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VEHCRASHHANDLERESPONSEBITS),
    KDHP_VehCrashActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_is,
    &DHP_model_DW.Fault_Valid_RT_is);

  /* End of Outputs for SubSystem: '<S1605>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1230>/VehCrashHardwareCanSignal' */
void DHP_model_VehCrashHardwareCanSignal(void)
{
  /* Outputs for Atomic SubSystem: '<S1608>/Fault_Valid_Time' */

  /* Constant: '<S1518>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1518>/Constant2'
   *  Constant: '<S1518>/KDHP_Allow_Recover'
   *  Constant: '<S1518>/KDHP_Clear_Time'
   *  Constant: '<S1518>/KDHP_Fault_Level'
   *  Constant: '<S1518>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1518>/KDHP_Pwr_limit'
   *  Constant: '<S1518>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VehCrashHardwareCanSignalInstFlt_flg, ((uint16_T)
    KDHP_VEHCRASHHARDWARECANSIGNALCONFIRMTIME_MS), ((uint16_T)
    KDHP_VEHCRASHHARDWARECANSIGNALCLEARTIME_MS),
    KDHP_VEHCRASHHARDWARECANSIGNALALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_VEHCRASHHARDWARECANSIGNALFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VEHCRASHHARDWARECANSIGNALSPDLIMIT), ((uint8_T)
    KDHP_VEHCRASHHARDWARECANSIGNALPOWERLIMIT_PCT), ((uint16_T)
    KDHP_VEHCRASHHARDWARECANSIGNALHANDLERESPONSEBITS),
    KDHP_VehCrashHardwareCanSignalActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_nm, &DHP_model_DW.Fault_Valid_Time_nm);

  /* End of Outputs for SubSystem: '<S1608>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1230>/VehCrashHardwareSignal' */
void DHP_model_VehCrashHardwareSignal(void)
{
  /* Outputs for Atomic SubSystem: '<S1613>/Fault_Valid_Time' */

  /* Constant: '<S1519>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1519>/Constant2'
   *  Constant: '<S1519>/KDHP_Allow_Recover'
   *  Constant: '<S1519>/KDHP_Clear_Time'
   *  Constant: '<S1519>/KDHP_Fault_Level'
   *  Constant: '<S1519>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1519>/KDHP_Pwr_limit'
   *  Constant: '<S1519>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VehCrashHardwareSignalInstFlt_flg, ((uint16_T)
    KDHP_VEHCRASHHARDWARESIGNALCONFIRMTIME_MS), ((uint16_T)
    KDHP_VEHCRASHHARDWARESIGNALCLEARTIME_MS),
    KDHP_VEHCRASHHARDWARESIGNALALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_VEHCRASHHARDWARESIGNALFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VEHCRASHHARDWARESIGNALSPDLIMIT), ((uint8_T)
    KDHP_VEHCRASHHARDWARESIGNALPOWERLIMIT_PCT), ((uint16_T)
    KDHP_VEHCRASHHARDWARESIGNALHANDLERESPONSEBITS),
    KDHP_VehCrashHardwareSignalActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_j5, &DHP_model_DW.Fault_Valid_Time_j5);

  /* End of Outputs for SubSystem: '<S1613>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S13>/VCUApplySW_Fault' */
void DHP_model_VCUApplySW_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1230>/ChrgFault' */
  DHP_model_ChrgFault();

  /* End of Outputs for SubSystem: '<S1230>/ChrgFault' */

  /* Outputs for Atomic SubSystem: '<S1230>/ChrgLockCheckTimeout' */
  DHP_model_ChrgLockCheckTimeout();

  /* End of Outputs for SubSystem: '<S1230>/ChrgLockCheckTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/ChrgModeAbnormal' */
  DHP_model_ChrgModeAbnormal();

  /* End of Outputs for SubSystem: '<S1230>/ChrgModeAbnormal' */

  /* Outputs for Atomic SubSystem: '<S1230>/ChrgModeInvalid' */
  DHP_model_ChrgModeInvalid();

  /* End of Outputs for SubSystem: '<S1230>/ChrgModeInvalid' */

  /* Outputs for Atomic SubSystem: '<S1230>/ChrgOBCSleepTimeout' */
  DHP_model_ChrgOBCSleepTimeout();

  /* End of Outputs for SubSystem: '<S1230>/ChrgOBCSleepTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/ChrgStopAbnormal' */
  DHP_model_ChrgStopAbnormal();

  /* End of Outputs for SubSystem: '<S1230>/ChrgStopAbnormal' */

  /* Outputs for Atomic SubSystem: '<S1230>/ChrgStopLockErr' */
  DHP_model_ChrgStopLockErr();

  /* End of Outputs for SubSystem: '<S1230>/ChrgStopLockErr' */

  /* Outputs for Atomic SubSystem: '<S1230>/ChrgStopModeInvalid' */
  DHP_model_ChrgStopModeInvalid();

  /* End of Outputs for SubSystem: '<S1230>/ChrgStopModeInvalid' */

  /* Outputs for Atomic SubSystem: '<S1230>/ChrgStopOperTimeout' */
  DHP_model_ChrgStopOperTimeout();

  /* End of Outputs for SubSystem: '<S1230>/ChrgStopOperTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/DCDCStopWorkTimeout' */
  DHP_model_DCDCStopWorkTimeout();

  /* End of Outputs for SubSystem: '<S1230>/DCDCStopWorkTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/HVActiveTimeout' */
  DHP_model_HVActiveTimeout();

  /* End of Outputs for SubSystem: '<S1230>/HVActiveTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/HVDCDCActiveTimeout' */
  DHP_model_HVDCDCActiveTimeout();

  /* End of Outputs for SubSystem: '<S1230>/HVDCDCActiveTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/HVDownTimeout' */
  DHP_model_HVDownTimeout();

  /* End of Outputs for SubSystem: '<S1230>/HVDownTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/HVILErr' */
  DHP_model_HVILErr();

  /* End of Outputs for SubSystem: '<S1230>/HVILErr' */

  /* Outputs for Atomic SubSystem: '<S1230>/HVPwrUpTimeout' */
  DHP_model_HVPwrUpTimeout();

  /* End of Outputs for SubSystem: '<S1230>/HVPwrUpTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/HVUpTimeout' */
  DHP_model_HVUpTimeout();

  /* End of Outputs for SubSystem: '<S1230>/HVUpTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/LVUpBMSPwrUpAllwTimeout' */
  DHP_model_LVUpBMSPwrUpAllwTimeout();

  /* End of Outputs for SubSystem: '<S1230>/LVUpBMSPwrUpAllwTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/LVUpBMSTimeout' */
  DHP_model_LVUpBMSTimeout();

  /* End of Outputs for SubSystem: '<S1230>/LVUpBMSTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/LVUpDCDCTimeout' */
  DHP_model_LVUpDCDCTimeout();

  /* End of Outputs for SubSystem: '<S1230>/LVUpDCDCTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/LVUpMCUTimeout' */
  DHP_model_LVUpMCUTimeout();

  /* End of Outputs for SubSystem: '<S1230>/LVUpMCUTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/MCUDischargeTimeout' */
  DHP_model_MCUDischargeTimeout();

  /* End of Outputs for SubSystem: '<S1230>/MCUDischargeTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/MCUExitTorqTimeout' */
  DHP_model_MCUExitTorqTimeout();

  /* End of Outputs for SubSystem: '<S1230>/MCUExitTorqTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/MCUHVActiveTimeout' */
  DHP_model_MCUHVActiveTimeout();

  /* End of Outputs for SubSystem: '<S1230>/MCUHVActiveTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/OBCWakeupTimeout' */
  DHP_model_OBCWakeupTimeout();

  /* End of Outputs for SubSystem: '<S1230>/OBCWakeupTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/SRSMissing' */
  DHP_model_SRSMissing();

  /* End of Outputs for SubSystem: '<S1230>/SRSMissing' */

  /* Outputs for Atomic SubSystem: '<S1230>/ShiftKnobCheckTimeout' */
  DHP_model_ShiftKnobCheckTimeout();

  /* End of Outputs for SubSystem: '<S1230>/ShiftKnobCheckTimeout' */

  /* Outputs for Atomic SubSystem: '<S1230>/VCUChrgReqLimFac' */
  DHP_model_VCUChrgReqLimFac();

  /* End of Outputs for SubSystem: '<S1230>/VCUChrgReqLimFac' */

  /* Outputs for Atomic SubSystem: '<S1230>/VehCrash' */
  DHP_model_VehCrash();

  /* End of Outputs for SubSystem: '<S1230>/VehCrash' */

  /* Outputs for Atomic SubSystem: '<S1230>/VehCrashHardwareCanSignal' */
  DHP_model_VehCrashHardwareCanSignal();

  /* End of Outputs for SubSystem: '<S1230>/VehCrashHardwareCanSignal' */

  /* Outputs for Atomic SubSystem: '<S1230>/VehCrashHardwareSignal' */
  DHP_model_VehCrashHardwareSignal();

  /* End of Outputs for SubSystem: '<S1230>/VehCrashHardwareSignal' */
}

/* Output and update for atomic system: '<S1231>/APPData12DFlashInvalid' */
void DHP_model_APPData12DFlashInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1644>/Fault_Valid_RT' */

  /* Constant: '<S1618>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1618>/Constant2'
   *  Constant: '<S1618>/KDHP_Fault_Level'
   *  Constant: '<S1618>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1618>/KDHP_Pwr_limit'
   *  Constant: '<S1618>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.DataStoreRead25_i,
    KDHP_APPDATA12DFLASHINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_APPDATA12DFLASHINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_APPDATA12DFLASHINVALIDSPDLIMIT), ((uint8_T)
    KDHP_APPDATA12DFLASHINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_APPDATA12DFLASHINVALIDHANDLERESPONSEBITS),
    KDHP_APPData12DFlashInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_ni, &DHP_model_DW.Fault_Valid_RT_ni);

  /* End of Outputs for SubSystem: '<S1644>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/APPData12EEPROMInvalid' */
void DHP_model_APPData12EEPROMInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1647>/Fault_Valid_RT' */

  /* Constant: '<S1619>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1619>/Constant2'
   *  Constant: '<S1619>/KDHP_Fault_Level'
   *  Constant: '<S1619>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1619>/KDHP_Pwr_limit'
   *  Constant: '<S1619>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.DataStoreRead26_g,
    KDHP_APPDATA12EEPROMINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_APPDATA12EEPROMINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_APPDATA12EEPROMINVALIDSPDLIMIT), ((uint8_T)
    KDHP_APPDATA12EEPROMINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_APPDATA12EEPROMINVALIDHANDLERESPONSEBITS),
    KDHP_APPData12EEPROMInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_dj, &DHP_model_DW.Fault_Valid_RT_dj);

  /* End of Outputs for SubSystem: '<S1647>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/APPData3DFlashInvalid' */
void DHP_model_APPData3DFlashInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1650>/Fault_Valid_RT' */

  /* Constant: '<S1620>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1620>/Constant2'
   *  Constant: '<S1620>/KDHP_Fault_Level'
   *  Constant: '<S1620>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1620>/KDHP_Pwr_limit'
   *  Constant: '<S1620>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.DataStoreRead27_k,
    KDHP_APPDATA3DFLASHINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_APPDATA3DFLASHINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_APPDATA3DFLASHINVALIDSPDLIMIT), ((uint8_T)
    KDHP_APPDATA3DFLASHINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_APPDATA3DFLASHINVALIDHANDLERESPONSEBITS),
    KDHP_APPData3DFlashInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_os, &DHP_model_DW.Fault_Valid_RT_os);

  /* End of Outputs for SubSystem: '<S1650>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/APPData3EEPROMInvalid' */
void DHP_model_APPData3EEPROMInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1653>/Fault_Valid_RT' */

  /* Constant: '<S1621>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1621>/Constant2'
   *  Constant: '<S1621>/KDHP_Fault_Level'
   *  Constant: '<S1621>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1621>/KDHP_Pwr_limit'
   *  Constant: '<S1621>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.DataStoreRead28_f,
    KDHP_APPDATA3EEPROMINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_APPDATA3EEPROMINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_APPDATA3EEPROMINVALIDSPDLIMIT), ((uint8_T)
    KDHP_APPDATA3EEPROMINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_APPDATA3EEPROMINVALIDHANDLERESPONSEBITS),
    KDHP_APPData3EEPROMInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_e34, &DHP_model_DW.Fault_Valid_RT_e34);

  /* End of Outputs for SubSystem: '<S1653>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/APPData4DFlashInvalid' */
void DHP_model_APPData4DFlashInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1656>/Fault_Valid_RT' */

  /* Constant: '<S1622>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1622>/Constant2'
   *  Constant: '<S1622>/KDHP_Fault_Level'
   *  Constant: '<S1622>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1622>/KDHP_Pwr_limit'
   *  Constant: '<S1622>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.DataStoreRead29_f,
    KDHP_APPDATA4DFLASHINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_APPDATA4DFLASHINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_APPDATA4DFLASHINVALIDSPDLIMIT), ((uint8_T)
    KDHP_APPDATA4DFLASHINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_APPDATA4DFLASHINVALIDHANDLERESPONSEBITS),
    KDHP_APPData4DFlashInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_k1, &DHP_model_DW.Fault_Valid_RT_k1);

  /* End of Outputs for SubSystem: '<S1656>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/APPData4EEPROMInvalid' */
void DHP_model_APPData4EEPROMInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1659>/Fault_Valid_RT' */

  /* Constant: '<S1623>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1623>/Constant2'
   *  Constant: '<S1623>/KDHP_Fault_Level'
   *  Constant: '<S1623>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1623>/KDHP_Pwr_limit'
   *  Constant: '<S1623>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.DataStoreRead30_j,
    KDHP_APPDATA4EEPROMINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_APPDATA4EEPROMINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_APPDATA4EEPROMINVALIDSPDLIMIT), ((uint8_T)
    KDHP_APPDATA4EEPROMINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_APPDATA4EEPROMINVALIDHANDLERESPONSEBITS),
    KDHP_APPData4EEPROMInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_i1, &DHP_model_DW.Fault_Valid_RT_i1);

  /* End of Outputs for SubSystem: '<S1659>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/AppDataCheckFailed' */
void DHP_model_AppDataCheckFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S1662>/Fault_Valid_RT' */

  /* Constant: '<S1624>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1624>/Constant2'
   *  Constant: '<S1624>/KDHP_Fault_Level'
   *  Constant: '<S1624>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1624>/KDHP_Pwr_limit'
   *  Constant: '<S1624>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_AppDataCheckFaliedInstFlt_flg, KDHP_APPDATACHECKFAILEDALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_APPDATACHECKFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_APPDATACHECKFAILEDSPDLIMIT), ((uint8_T)
    KDHP_APPDATACHECKFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_APPDATACHECKFAILEDHANDLERESPONSEBITS),
    KDHP_AppDataCheckFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_kvr,
    &DHP_model_DW.Fault_Valid_RT_kvr);

  /* End of Outputs for SubSystem: '<S1662>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/CalDataCheckFailed' */
void DHP_model_CalDataCheckFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S1665>/Fault_Valid_RT' */

  /* Constant: '<S1625>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1625>/Constant2'
   *  Constant: '<S1625>/KDHP_Fault_Level'
   *  Constant: '<S1625>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1625>/KDHP_Pwr_limit'
   *  Constant: '<S1625>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_CalDataCheckFailedInstFlt_flg, KDHP_CALDATACHECKFAILEDALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_CALDATACHECKFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_CALDATACHECKFAILEDSPDLIMIT), ((uint8_T)
    KDHP_CALDATACHECKFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CALDATACHECKFAILEDHANDLERESPONSEBITS),
    KDHP_CalDataCheckFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ae,
    &DHP_model_DW.Fault_Valid_RT_ae);

  /* End of Outputs for SubSystem: '<S1665>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/CruiseKeyJamFlt' */
void DHP_model_CruiseKeyJamFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1668>/Fault_Valid_RT' */

  /* Constant: '<S1626>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1626>/Constant2'
   *  Constant: '<S1626>/KDHP_Fault_Level'
   *  Constant: '<S1626>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1626>/KDHP_Pwr_limit'
   *  Constant: '<S1626>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.LogicalOperator_h,
    KDHP_CRUISEKEYJAMFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CRUISEKEYJAMFLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_CRUISEKEYJAMFLTSPDLIMIT),
    ((uint8_T)KDHP_CRUISEKEYJAMFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CRUISEKEYJAMFLTHANDLERESPONSEBITS),
    KDHP_CruiseKeyJamFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_et,
    &DHP_model_DW.Fault_Valid_RT_et);

  /* End of Outputs for SubSystem: '<S1668>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/CruiseKeyOpenFlt' */
void DHP_model_CruiseKeyOpenFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1671>/Fault_Valid_Time' */

  /* Constant: '<S1627>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1627>/Constant2'
   *  Constant: '<S1627>/KDHP_Allow_Recover'
   *  Constant: '<S1627>/KDHP_Clear_Time'
   *  Constant: '<S1627>/KDHP_Fault_Level'
   *  Constant: '<S1627>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1627>/KDHP_Pwr_limit'
   *  Constant: '<S1627>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_CruiseKeyOpenInstFlt_flg, ((uint16_T)
    KDHP_CRUISEKEYOPENFLTCONFIRMTIME_MS), ((uint16_T)
    KDHP_CRUISEKEYOPENFLTCLEARTIME_MS), KDHP_CRUISEKEYOPENFLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_CRUISEKEYOPENFLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_CRUISEKEYOPENFLTSPDLIMIT), ((uint8_T)
    KDHP_CRUISEKEYOPENFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CRUISEKEYOPENFLTHANDLERESPONSEBITS),
    KDHP_CruiseKeyOpenFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_ot,
    &DHP_model_DW.Fault_Valid_Time_ot);

  /* End of Outputs for SubSystem: '<S1671>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/CruiseKeyShortedFlt' */
void DHP_model_CruiseKeyShortedFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1676>/Fault_Valid_Time' */

  /* Constant: '<S1628>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1628>/Constant2'
   *  Constant: '<S1628>/KDHP_Allow_Recover'
   *  Constant: '<S1628>/KDHP_Clear_Time'
   *  Constant: '<S1628>/KDHP_Fault_Level'
   *  Constant: '<S1628>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1628>/KDHP_Pwr_limit'
   *  Constant: '<S1628>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_CruiseKeyShortedInstFlt_flg, ((uint16_T)
    KDHP_CRUISEKEYSHORTEDFLTCONFIRMTIME_MS), ((uint16_T)
    KDHP_CRUISEKEYSHORTEDFLTCLEARTIME_MS),
    KDHP_CRUISEKEYSHORTEDFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_CRUISEKEYSHORTEDFLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_CRUISEKEYSHORTEDFLTSPDLIMIT), ((uint8_T)
    KDHP_CRUISEKEYSHORTEDFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_CRUISEKEYSHORTEDFLTHANDLERESPONSEBITS),
    KDHP_CruiseKeyShortedFltActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_nvb, &DHP_model_DW.Fault_Valid_Time_nvb);

  /* End of Outputs for SubSystem: '<S1676>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/DIDDataDFlashInvalid' */
void DHP_model_DIDDataDFlashInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1681>/Fault_Valid_RT' */

  /* Constant: '<S1629>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1629>/Constant2'
   *  Constant: '<S1629>/KDHP_Fault_Level'
   *  Constant: '<S1629>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1629>/KDHP_Pwr_limit'
   *  Constant: '<S1629>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.DataStoreRead1_f,
    KDHP_DIDDATADFLASHINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_DIDDATADFLASHINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_DIDDATADFLASHINVALIDSPDLIMIT), ((uint8_T)
    KDHP_DIDDATADFLASHINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_DIDDATADFLASHINVALIDHANDLERESPONSEBITS),
    KDHP_DIDDataDFlashInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_nq, &DHP_model_DW.Fault_Valid_RT_nq);

  /* End of Outputs for SubSystem: '<S1681>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/DIDDataEEPROMInvalid' */
void DHP_model_DIDDataEEPROMInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1684>/Fault_Valid_RT' */

  /* Constant: '<S1630>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1630>/Constant2'
   *  Constant: '<S1630>/KDHP_Fault_Level'
   *  Constant: '<S1630>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1630>/KDHP_Pwr_limit'
   *  Constant: '<S1630>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.DataStoreRead17_o,
    KDHP_DIDDATAEEPROMINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_DIDDATAEEPROMINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_DIDDATAEEPROMINVALIDSPDLIMIT), ((uint8_T)
    KDHP_DIDDATAEEPROMINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_DIDDATAEEPROMINVALIDHANDLERESPONSEBITS),
    KDHP_DIDDataEEPROMInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_jt, &DHP_model_DW.Fault_Valid_RT_jt);

  /* End of Outputs for SubSystem: '<S1684>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/DidDataCheckFailed' */
void DHP_model_DidDataCheckFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S1687>/Fault_Valid_RT' */

  /* Constant: '<S1631>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1631>/Constant2'
   *  Constant: '<S1631>/KDHP_Fault_Level'
   *  Constant: '<S1631>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1631>/KDHP_Pwr_limit'
   *  Constant: '<S1631>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_DidDataCheckFailedInstFlt_flg, KDHP_DIDDATACHECKFAILEDALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_DIDDATACHECKFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_DIDDATACHECKFAILEDSPDLIMIT), ((uint8_T)
    KDHP_DIDDATACHECKFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_DIDDATACHECKFAILEDHANDLERESPONSEBITS),
    KDHP_DidDataCheckFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_kb,
    &DHP_model_DW.Fault_Valid_RT_kb);

  /* End of Outputs for SubSystem: '<S1687>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/HistDataCheckFailed' */
void DHP_model_HistDataCheckFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S1690>/Fault_Valid_RT' */

  /* Constant: '<S1632>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1632>/Constant2'
   *  Constant: '<S1632>/KDHP_Fault_Level'
   *  Constant: '<S1632>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1632>/KDHP_Pwr_limit'
   *  Constant: '<S1632>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_HistDataCheckFaliedInstFlt_flg,
    KDHP_HISTDATACHECKFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_HISTDATACHECKFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_HISTDATACHECKFAILEDSPDLIMIT), ((uint8_T)
    KDHP_HISTDATACHECKFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_HISTDATACHECKFAILEDHANDLERESPONSEBITS),
    KDHP_HistDataCheckFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_cg,
    &DHP_model_DW.Fault_Valid_RT_cg);

  /* End of Outputs for SubSystem: '<S1690>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1231>/VCUHwCanNetLineOff' */
void DHP_model_VCUHwCanNetLineOff(void)
{
  boolean_T rtb_RelationalOperator1_pv;
  boolean_T rtb_LogicalOperator3_gf;
  uint8_T rtb_Switch3;
  boolean_T rtb_RelationalOperator3_ig;
  uint8_T rtb_LogicalOperator3_l;
  uint32_T rtb_LogicalOperator3_l_0;
  uint32_T qY;
  uint32_T qY_0;
  uint32_T qY_1;

  /* Switch: '<S1695>/Switch11' incorporates:
   *  Constant: '<S1695>/Constant3'
   *  Delay: '<S1695>/Delay'
   *  Logic: '<S1695>/Logical Operator1'
   *  Logic: '<S1695>/Logical Operator4'
   */
  if (VDHP_VCUHCanNetLineOffInstFlt_flg && (!DHP_model_DW.Delay_DSTATE_n3)) {
    rtb_Switch3 = 0U;
  } else {
    rtb_Switch3 = VDHP_deltaSystemTick_ms;
  }

  /* End of Switch: '<S1695>/Switch11' */

  /* Switch: '<S1695>/Switch' incorporates:
   *  Constant: '<S1695>/Constant2'
   *  Delay: '<S1695>/Delay3'
   *  Logic: '<S1695>/Logical Operator5'
   *  Logic: '<S1695>/Logical Operator6'
   */
  if ((!DHP_model_B.LogicalOperator2_b) || DHP_model_DW.Delay3_DSTATE_p) {
    rtb_LogicalOperator3_l = 0U;
  } else {
    rtb_LogicalOperator3_l = rtb_Switch3;
  }

  /* End of Switch: '<S1695>/Switch' */

  /* Switch: '<S1695>/Switch1' incorporates:
   *  Constant: '<S1695>/Constant1'
   *  Delay: '<S1695>/Delay1'
   *  Logic: '<S1695>/Logical Operator7'
   */
  if (!DHP_model_B.LogicalOperator2_b) {
    qY_1 = 0U;
  } else {
    qY_1 = DHP_model_DW.Delay1_DSTATE_il;
  }

  /* End of Switch: '<S1695>/Switch1' */

  /* Sum: '<S1695>/Add2' */
  qY_1 += rtb_LogicalOperator3_l;
  if (qY_1 < rtb_LogicalOperator3_l) {
    qY_1 = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1695>/Relational Operator1' incorporates:
   *  Constant: '<S1633>/KDHP_Clear_Time'
   *  Sum: '<S1695>/Add2'
   */
  rtb_RelationalOperator1_pv = (qY_1 >= ((uint16_T)
    KDHP_VCUHWCANNETLINEOFFCLEARTIME_MS));

  /* Logic: '<S1695>/Logical Operator3' */
  rtb_LogicalOperator3_gf = !VDHP_VCUHCanNetLineOffInstFlt_flg;

  /* Switch: '<S1695>/Switch5' incorporates:
   *  Constant: '<S1695>/Constant10'
   *  Constant: '<S1695>/Constant11'
   *  Delay: '<S1695>/Delay7'
   *  Switch: '<S1695>/Switch4'
   */
  if (rtb_LogicalOperator3_gf) {
    rtb_LogicalOperator3_l = 0U;
    rtb_LogicalOperator3_l_0 = 0U;
  } else {
    rtb_LogicalOperator3_l = rtb_Switch3;
    rtb_LogicalOperator3_l_0 = DHP_model_DW.Delay7_DSTATE_i;
  }

  /* End of Switch: '<S1695>/Switch5' */

  /* Sum: '<S1695>/Add6' */
  qY_0 = rtb_LogicalOperator3_l + rtb_LogicalOperator3_l_0;
  if (qY_0 < rtb_LogicalOperator3_l) {
    qY_0 = MAX_uint32_T;
  }

  /* Switch: '<S1695>/Switch9' incorporates:
   *  Constant: '<S1633>/KDHP_Confirm_Time'
   *  Delay: '<S1695>/Delay4'
   *  Logic: '<S1695>/Logical Operator2'
   *  RelationalOperator: '<S1695>/Relational Operator5'
   *  Sum: '<S1695>/Add6'
   */
  if (DHP_model_DW.Delay4_DSTATE_c) {
    rtb_LogicalOperator3_gf = rtb_RelationalOperator1_pv;
  } else {
    rtb_LogicalOperator3_gf = (rtb_LogicalOperator3_gf && (qY_0 < ((uint16_T)
      KDHP_VCUHWCANNETLINEOFFCONFIRMTIME_MS)));
  }

  /* End of Switch: '<S1695>/Switch9' */

  /* Switch: '<S1695>/Switch3' incorporates:
   *  Constant: '<S1695>/Constant4'
   */
  if (!VDHP_VCUHCanNetLineOffInstFlt_flg) {
    rtb_Switch3 = 0U;
  }

  /* End of Switch: '<S1695>/Switch3' */

  /* Switch: '<S1695>/Switch7' incorporates:
   *  Constant: '<S1695>/Constant7'
   *  Delay: '<S1695>/Delay2'
   *  Logic: '<S1695>/Logical Operator'
   */
  if (rtb_LogicalOperator3_gf || VDHP_NMSleepInd_flg) {
    rtb_LogicalOperator3_l_0 = 0U;
  } else {
    rtb_LogicalOperator3_l_0 = DHP_model_DW.Delay2_DSTATE_l;
  }

  /* End of Switch: '<S1695>/Switch7' */

  /* Sum: '<S1695>/Add3' */
  qY = rtb_LogicalOperator3_l_0 + rtb_Switch3;
  if (qY < rtb_LogicalOperator3_l_0) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1695>/Relational Operator3' incorporates:
   *  Constant: '<S1633>/KDHP_Confirm_Time'
   *  Sum: '<S1695>/Add3'
   */
  rtb_RelationalOperator3_ig = (qY >= ((uint16_T)
    KDHP_VCUHWCANNETLINEOFFCONFIRMTIME_MS));

  /* Switch: '<S1695>/Switch10' incorporates:
   *  Constant: '<S1695>/Constant13'
   *  Delay: '<S1695>/Delay6'
   *  Switch: '<S1695>/Switch6'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_LogicalOperator3_gf = false;
  } else {
    rtb_LogicalOperator3_gf = (rtb_RelationalOperator3_ig ||
      DHP_model_DW.Delay6_DSTATE_h);
  }

  /* End of Switch: '<S1695>/Switch10' */

  /* Switch: '<S1695>/Switch8' incorporates:
   *  Constant: '<S1633>/KDHP_Allow_Recover'
   */
  if (!KDHP_VCUHWCANNETLINEOFFALLOWRECOVERY_FLG) {
    rtb_RelationalOperator3_ig = rtb_LogicalOperator3_gf;
  }

  /* End of Switch: '<S1695>/Switch8' */

  /* Switch: '<S1695>/Switch2' */
  DHP_model_B.Switch2_mf2 = ((!VDHP_NMSleepInd_flg) &&
    rtb_RelationalOperator3_ig);

  /* Outputs for Atomic SubSystem: '<S1693>/Fault_Action' */

  /* Constant: '<S1633>/KDHP_Spd_Limit' incorporates:
   *  Constant: '<S1633>/Constant2'
   *  Constant: '<S1633>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1633>/KDHP_Pwr_limit'
   */
  DHP_model_Fault_Action(DHP_model_B.Switch2_mf2, ((uint8_T)
    KDHP_VCUHWCANNETLINEOFFSPDLIMIT), ((uint8_T)
    KDHP_VCUHWCANNETLINEOFFPOWERLIMIT_PCT), ((uint16_T)
    KDHP_VCUHWCANNETLINEOFFHANDLERESPONSEBITS),
    KDHP_VCUHwCanNetLineOffActionSwitchOpen_flg, &DHP_model_B.Fault_Action);

  /* End of Outputs for SubSystem: '<S1693>/Fault_Action' */

  /* Switch: '<S1693>/Switch2' incorporates:
   *  Constant: '<S1633>/Constant2'
   *  Constant: '<S1633>/KDHP_Fault_Level'
   *  Constant: '<S1693>/Constant'
   *  Logic: '<S1693>/Logical Operator'
   */
  if (KDHP_VCUHwCanNetLineOffActionSwitchOpen_flg && DHP_model_B.Switch2_mf2) {
    DHP_model_B.Switch2_bf = ((uint8_T)KDHP_VCUHWCANNETLINEOFFFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_bf = 0U;
  }

  /* End of Switch: '<S1693>/Switch2' */

  /* Update for Delay: '<S1695>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_p = rtb_RelationalOperator1_pv;

  /* Update for Delay: '<S1695>/Delay' */
  DHP_model_DW.Delay_DSTATE_n3 = VDHP_VCUHCanNetLineOffInstFlt_flg;

  /* Update for Delay: '<S1695>/Delay1' incorporates:
   *  Sum: '<S1695>/Add2'
   */
  DHP_model_DW.Delay1_DSTATE_il = qY_1;

  /* Update for Delay: '<S1695>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_c = rtb_RelationalOperator3_ig;

  /* Update for Delay: '<S1695>/Delay7' incorporates:
   *  Sum: '<S1695>/Add6'
   */
  DHP_model_DW.Delay7_DSTATE_i = qY_0;

  /* Update for Delay: '<S1695>/Delay2' incorporates:
   *  Sum: '<S1695>/Add3'
   */
  DHP_model_DW.Delay2_DSTATE_l = qY;

  /* Update for Delay: '<S1695>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_h = rtb_LogicalOperator3_gf;
}

/* Output and update for atomic system: '<S1231>/VCUHwHS1Flt' */
void DHP_model_VCUHwHS1Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1696>/Fault_Valid_Time' */

  /* Constant: '<S1634>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1634>/Constant2'
   *  Constant: '<S1634>/KDHP_Allow_Recover'
   *  Constant: '<S1634>/KDHP_Clear_Time'
   *  Constant: '<S1634>/KDHP_Fault_Level'
   *  Constant: '<S1634>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1634>/KDHP_Pwr_limit'
   *  Constant: '<S1634>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwHS1ErrInstFlt_flg, ((uint16_T)KDHP_VCUHWHS1FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWHS1FLTCLEARTIME_MS), KDHP_VCUHWHS1FLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWHS1FLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWHS1FLTSPDLIMIT), ((uint8_T)KDHP_VCUHWHS1FLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VCUHWHS1FLTHANDLERESPONSEBITS),
    KDHP_VCUHwHS1FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_ds,
    &DHP_model_DW.Fault_Valid_Time_ds);

  /* End of Outputs for SubSystem: '<S1696>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/VCUHwLS1Flt' */
void DHP_model_VCUHwLS1Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1701>/Fault_Valid_Time' */

  /* Constant: '<S1635>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1635>/Constant2'
   *  Constant: '<S1635>/KDHP_Allow_Recover'
   *  Constant: '<S1635>/KDHP_Clear_Time'
   *  Constant: '<S1635>/KDHP_Fault_Level'
   *  Constant: '<S1635>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1635>/KDHP_Pwr_limit'
   *  Constant: '<S1635>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLS1ErrInstFlt_flg, ((uint16_T)KDHP_VCUHWLS1FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLS1FLTCLEARTIME_MS), KDHP_VCUHWLS1FLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWLS1FLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWLS1FLTSPDLIMIT), ((uint8_T)KDHP_VCUHWLS1FLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VCUHWLS1FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLS1FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_lp,
    &DHP_model_DW.Fault_Valid_Time_lp);

  /* End of Outputs for SubSystem: '<S1701>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/VCUHwLS2Flt' */
void DHP_model_VCUHwLS2Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1706>/Fault_Valid_Time' */

  /* Constant: '<S1636>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1636>/Constant2'
   *  Constant: '<S1636>/KDHP_Allow_Recover'
   *  Constant: '<S1636>/KDHP_Clear_Time'
   *  Constant: '<S1636>/KDHP_Fault_Level'
   *  Constant: '<S1636>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1636>/KDHP_Pwr_limit'
   *  Constant: '<S1636>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLS2ErrInstFlt_flg, ((uint16_T)KDHP_VCUHWLS2FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLS2FLTCLEARTIME_MS), KDHP_VCUHWLS2FLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWLS2FLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWLS2FLTSPDLIMIT), ((uint8_T)KDHP_VCUHWLS2FLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VCUHWLS2FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLS2FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_m,
    &DHP_model_DW.Fault_Valid_Time_m);

  /* End of Outputs for SubSystem: '<S1706>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/VCUHwLS3Flt' */
void DHP_model_VCUHwLS3Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1711>/Fault_Valid_Time' */

  /* Constant: '<S1637>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1637>/Constant2'
   *  Constant: '<S1637>/KDHP_Allow_Recover'
   *  Constant: '<S1637>/KDHP_Clear_Time'
   *  Constant: '<S1637>/KDHP_Fault_Level'
   *  Constant: '<S1637>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1637>/KDHP_Pwr_limit'
   *  Constant: '<S1637>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLS3ErrInstFlt_flg, ((uint16_T)KDHP_VCUHWLS3FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLS3FLTCLEARTIME_MS), KDHP_VCUHWLS3FLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWLS3FLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWLS3FLTSPDLIMIT), ((uint8_T)KDHP_VCUHWLS3FLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VCUHWLS3FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLS3FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_g,
    &DHP_model_DW.Fault_Valid_Time_g);

  /* End of Outputs for SubSystem: '<S1711>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/VCUHwLS4Flt' */
void DHP_model_VCUHwLS4Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1716>/Fault_Valid_Time' */

  /* Constant: '<S1638>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1638>/Constant2'
   *  Constant: '<S1638>/KDHP_Allow_Recover'
   *  Constant: '<S1638>/KDHP_Clear_Time'
   *  Constant: '<S1638>/KDHP_Fault_Level'
   *  Constant: '<S1638>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1638>/KDHP_Pwr_limit'
   *  Constant: '<S1638>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLS4ErrInstFlt_flg, ((uint16_T)KDHP_VCUHWLS4FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLS4FLTCLEARTIME_MS), KDHP_VCUHWLS4FLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWLS4FLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWLS4FLTSPDLIMIT), ((uint8_T)KDHP_VCUHWLS4FLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VCUHWLS4FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLS4FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_jy,
    &DHP_model_DW.Fault_Valid_Time_jy);

  /* End of Outputs for SubSystem: '<S1716>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/VCUHwLS5Flt' */
void DHP_model_VCUHwLS5Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1721>/Fault_Valid_Time' */

  /* Constant: '<S1639>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1639>/Constant2'
   *  Constant: '<S1639>/KDHP_Allow_Recover'
   *  Constant: '<S1639>/KDHP_Clear_Time'
   *  Constant: '<S1639>/KDHP_Fault_Level'
   *  Constant: '<S1639>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1639>/KDHP_Pwr_limit'
   *  Constant: '<S1639>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLS5ErrInstFlt_flg, ((uint16_T)KDHP_VCUHWLS5FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLS5FLTCLEARTIME_MS), KDHP_VCUHWLS5FLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWLS5FLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWLS5FLTSPDLIMIT), ((uint8_T)KDHP_VCUHWLS5FLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VCUHWLS5FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLS5FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_eo,
    &DHP_model_DW.Fault_Valid_Time_eo);

  /* End of Outputs for SubSystem: '<S1721>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/VCUHwLS6Flt' */
void DHP_model_VCUHwLS6Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1726>/Fault_Valid_Time' */

  /* Constant: '<S1640>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1640>/Constant2'
   *  Constant: '<S1640>/KDHP_Allow_Recover'
   *  Constant: '<S1640>/KDHP_Clear_Time'
   *  Constant: '<S1640>/KDHP_Fault_Level'
   *  Constant: '<S1640>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1640>/KDHP_Pwr_limit'
   *  Constant: '<S1640>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLS6ErrInstFlt_flg, ((uint16_T)KDHP_VCUHWLS6FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLS6FLTCLEARTIME_MS), KDHP_VCUHWLS6FLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWLS6FLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWLS6FLTSPDLIMIT), ((uint8_T)KDHP_VCUHWLS6FLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VCUHWLS6FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLS6FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_n1v,
    &DHP_model_DW.Fault_Valid_Time_n1v);

  /* End of Outputs for SubSystem: '<S1726>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/VCUHwLS7Flt' */
void DHP_model_VCUHwLS7Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1731>/Fault_Valid_Time' */

  /* Constant: '<S1641>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1641>/Constant2'
   *  Constant: '<S1641>/KDHP_Allow_Recover'
   *  Constant: '<S1641>/KDHP_Clear_Time'
   *  Constant: '<S1641>/KDHP_Fault_Level'
   *  Constant: '<S1641>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1641>/KDHP_Pwr_limit'
   *  Constant: '<S1641>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLS7ErrInstFlt_flg, ((uint16_T)KDHP_VCUHWLS7FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLS7FLTCLEARTIME_MS), KDHP_VCUHWLS7FLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWLS7FLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWLS7FLTSPDLIMIT), ((uint8_T)KDHP_VCUHWLS7FLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VCUHWLS7FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLS7FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_oe,
    &DHP_model_DW.Fault_Valid_Time_oe);

  /* End of Outputs for SubSystem: '<S1731>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/VCUHwLS8Flt' */
void DHP_model_VCUHwLS8Flt(void)
{
  /* Outputs for Atomic SubSystem: '<S1736>/Fault_Valid_Time' */

  /* Constant: '<S1642>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1642>/Constant2'
   *  Constant: '<S1642>/KDHP_Allow_Recover'
   *  Constant: '<S1642>/KDHP_Clear_Time'
   *  Constant: '<S1642>/KDHP_Fault_Level'
   *  Constant: '<S1642>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1642>/KDHP_Pwr_limit'
   *  Constant: '<S1642>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCUHwLS8ErrInstFlt_flg, ((uint16_T)KDHP_VCUHWLS8FLTCONFIRMTIME_MS),
    ((uint16_T)KDHP_VCUHWLS8FLTCLEARTIME_MS), KDHP_VCUHWLS8FLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VCUHWLS8FLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VCUHWLS8FLTSPDLIMIT), ((uint8_T)KDHP_VCUHWLS8FLTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VCUHWLS8FLTHANDLERESPONSEBITS),
    KDHP_VCUHwLS8FltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_jj,
    &DHP_model_DW.Fault_Valid_Time_jj);

  /* End of Outputs for SubSystem: '<S1736>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1231>/WriteToCalAreaInvalid' */
void DHP_model_WriteToCalAreaInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1741>/Fault_Valid_RT' */

  /* Constant: '<S1643>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1643>/Constant2'
   *  Constant: '<S1643>/KDHP_Fault_Level'
   *  Constant: '<S1643>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1643>/KDHP_Pwr_limit'
   *  Constant: '<S1643>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_gbInvalidWriteToCalAreaInstFlt_flg,
    KDHP_WRITETOCALAREAINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_WRITETOCALAREAINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_WRITETOCALAREAINVALIDSPDLIMIT), ((uint8_T)
    KDHP_WRITETOCALAREAINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_WRITETOCALAREAINVALIDHANDLERESPONSEBITS),
    KDHP_WriteToCalAreaInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_e5, &DHP_model_DW.Fault_Valid_RT_e5);

  /* End of Outputs for SubSystem: '<S1741>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S13>/VCUHW_Fault' */
void DHP_model_VCUHW_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1231>/APPData12DFlashInvalid' */
  DHP_model_APPData12DFlashInvalid();

  /* End of Outputs for SubSystem: '<S1231>/APPData12DFlashInvalid' */

  /* Outputs for Atomic SubSystem: '<S1231>/APPData12EEPROMInvalid' */
  DHP_model_APPData12EEPROMInvalid();

  /* End of Outputs for SubSystem: '<S1231>/APPData12EEPROMInvalid' */

  /* Outputs for Atomic SubSystem: '<S1231>/APPData3DFlashInvalid' */
  DHP_model_APPData3DFlashInvalid();

  /* End of Outputs for SubSystem: '<S1231>/APPData3DFlashInvalid' */

  /* Outputs for Atomic SubSystem: '<S1231>/APPData3EEPROMInvalid' */
  DHP_model_APPData3EEPROMInvalid();

  /* End of Outputs for SubSystem: '<S1231>/APPData3EEPROMInvalid' */

  /* Outputs for Atomic SubSystem: '<S1231>/APPData4DFlashInvalid' */
  DHP_model_APPData4DFlashInvalid();

  /* End of Outputs for SubSystem: '<S1231>/APPData4DFlashInvalid' */

  /* Outputs for Atomic SubSystem: '<S1231>/APPData4EEPROMInvalid' */
  DHP_model_APPData4EEPROMInvalid();

  /* End of Outputs for SubSystem: '<S1231>/APPData4EEPROMInvalid' */

  /* Outputs for Atomic SubSystem: '<S1231>/AppDataCheckFailed' */
  DHP_model_AppDataCheckFailed();

  /* End of Outputs for SubSystem: '<S1231>/AppDataCheckFailed' */

  /* Outputs for Atomic SubSystem: '<S1231>/CalDataCheckFailed' */
  DHP_model_CalDataCheckFailed();

  /* End of Outputs for SubSystem: '<S1231>/CalDataCheckFailed' */

  /* Logic: '<S1231>/Logical Operator' */
  DHP_model_B.LogicalOperator_h = (VDHP_CruiseKeySetFlt_flg ||
    VDHP_CruiseKeyResFlt_flg);

  /* Outputs for Atomic SubSystem: '<S1231>/CruiseKeyJamFlt' */
  DHP_model_CruiseKeyJamFlt();

  /* End of Outputs for SubSystem: '<S1231>/CruiseKeyJamFlt' */

  /* Outputs for Atomic SubSystem: '<S1231>/CruiseKeyOpenFlt' */
  DHP_model_CruiseKeyOpenFlt();

  /* End of Outputs for SubSystem: '<S1231>/CruiseKeyOpenFlt' */

  /* Outputs for Atomic SubSystem: '<S1231>/CruiseKeyShortedFlt' */
  DHP_model_CruiseKeyShortedFlt();

  /* End of Outputs for SubSystem: '<S1231>/CruiseKeyShortedFlt' */

  /* Outputs for Atomic SubSystem: '<S1231>/DIDDataDFlashInvalid' */
  DHP_model_DIDDataDFlashInvalid();

  /* End of Outputs for SubSystem: '<S1231>/DIDDataDFlashInvalid' */

  /* Outputs for Atomic SubSystem: '<S1231>/DIDDataEEPROMInvalid' */
  DHP_model_DIDDataEEPROMInvalid();

  /* End of Outputs for SubSystem: '<S1231>/DIDDataEEPROMInvalid' */

  /* Outputs for Atomic SubSystem: '<S1231>/DidDataCheckFailed' */
  DHP_model_DidDataCheckFailed();

  /* End of Outputs for SubSystem: '<S1231>/DidDataCheckFailed' */

  /* Outputs for Atomic SubSystem: '<S1231>/HistDataCheckFailed' */
  DHP_model_HistDataCheckFailed();

  /* End of Outputs for SubSystem: '<S1231>/HistDataCheckFailed' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwCanNetLineOff' */
  DHP_model_VCUHwCanNetLineOff();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwCanNetLineOff' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwHS1Flt' */
  DHP_model_VCUHwHS1Flt();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwHS1Flt' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwLS1Flt' */
  DHP_model_VCUHwLS1Flt();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwLS1Flt' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwLS2Flt' */
  DHP_model_VCUHwLS2Flt();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwLS2Flt' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwLS3Flt' */
  DHP_model_VCUHwLS3Flt();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwLS3Flt' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwLS4Flt' */
  DHP_model_VCUHwLS4Flt();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwLS4Flt' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwLS5Flt' */
  DHP_model_VCUHwLS5Flt();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwLS5Flt' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwLS6Flt' */
  DHP_model_VCUHwLS6Flt();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwLS6Flt' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwLS7Flt' */
  DHP_model_VCUHwLS7Flt();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwLS7Flt' */

  /* Outputs for Atomic SubSystem: '<S1231>/VCUHwLS8Flt' */
  DHP_model_VCUHwLS8Flt();

  /* End of Outputs for SubSystem: '<S1231>/VCUHwLS8Flt' */

  /* Outputs for Atomic SubSystem: '<S1231>/WriteToCalAreaInvalid' */
  DHP_model_WriteToCalAreaInvalid();

  /* End of Outputs for SubSystem: '<S1231>/WriteToCalAreaInvalid' */
}

/* Output and update for atomic system: '<S1232>/RegenAbnormal' */
void DHP_model_RegenAbnormal(void)
{
  /* Outputs for Atomic SubSystem: '<S1745>/Fault_Valid_Time' */

  /* Constant: '<S1745>/Constant' incorporates:
   *  Constant: '<S1744>/Constant2'
   *  Constant: '<S1744>/KDHP_Allow_Recover'
   *  Constant: '<S1744>/KDHP_Clear_Time'
   *  Constant: '<S1744>/KDHP_Fault_Level'
   *  Constant: '<S1744>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1744>/KDHP_Pwr_limit'
   *  Constant: '<S1744>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VCURegenAbnormal_flg, KDHP_RegenAbnormal_ms, ((uint16_T)
    KDHP_REGENABNORMALCLEARTIME_MS), KDHP_REGENABNORMALALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_REGENABNORMALFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_REGENABNORMALSPDLIMIT), ((uint8_T)KDHP_REGENABNORMALPOWERLIMIT_PCT),
    ((uint16_T)KDHP_REGENABNORMALHANDLERESPONSEBITS),
    KDHP_RegenAbnormalActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_p,
    &DHP_model_DW.Fault_Valid_Time_p);

  /* End of Outputs for SubSystem: '<S1745>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S13>/VCUTorqueAbnormal_Fault' */
void DHP_model_VCUTorqueAbnormal_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1232>/RegenAbnormal' */
  DHP_model_RegenAbnormal();

  /* End of Outputs for SubSystem: '<S1232>/RegenAbnormal' */
}

/* Output and update for function-call system: '<S4>/VcuControlDeviceErrValid' */
void DHP_model_VcuControlDeviceErrValid(void)
{
  /* Outputs for Atomic SubSystem: '<S13>/ACC_Fault' */
  DHP_model_ACC_Fault();

  /* End of Outputs for SubSystem: '<S13>/ACC_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/BUSOFF_Fault' */
  DHP_model_BUSOFF_Fault();

  /* End of Outputs for SubSystem: '<S13>/BUSOFF_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/BlueToothKey_Fault' */
  DHP_model_BlueToothKey_Fault();

  /* End of Outputs for SubSystem: '<S13>/BlueToothKey_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/Brk_Fault' */
  DHP_model_Brk_Fault();

  /* End of Outputs for SubSystem: '<S13>/Brk_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/CANComm_Fault' */
  DHP_model_CANComm_Fault();

  /* End of Outputs for SubSystem: '<S13>/CANComm_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/CoolSys_Fault' */
  DHP_model_CoolSys_Fault();

  /* End of Outputs for SubSystem: '<S13>/CoolSys_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/Gear_Fault' */
  DHP_model_Gear_Fault();

  /* End of Outputs for SubSystem: '<S13>/Gear_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/LBattery_Fault' */
  DHP_model_LBattery_Fault();

  /* End of Outputs for SubSystem: '<S13>/LBattery_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/MechanicalKey_Fault' */
  DHP_model_MechanicalKey_Fault();

  /* End of Outputs for SubSystem: '<S13>/MechanicalKey_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/VCUApplySW_Fault' */
  DHP_model_VCUApplySW_Fault();

  /* End of Outputs for SubSystem: '<S13>/VCUApplySW_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/VCUHW_Fault' */
  DHP_model_VCUHW_Fault();

  /* End of Outputs for SubSystem: '<S13>/VCUHW_Fault' */

  /* Outputs for Atomic SubSystem: '<S13>/VCUTorqueAbnormal_Fault' */
  DHP_model_VCUTorqueAbnormal_Fault();

  /* End of Outputs for SubSystem: '<S13>/VCUTorqueAbnormal_Fault' */
}

/* Output and update for atomic system: '<S1961>/ABSSpdInvalid' */
void DHP_model_ABSSpdInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1983>/Fault_Valid_RT' */

  /* Constant: '<S1975>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1975>/Constant2'
   *  Constant: '<S1975>/KDHP_Fault_Level'
   *  Constant: '<S1975>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1975>/KDHP_Pwr_limit'
   *  Constant: '<S1975>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ABSVehicleSpeedInvalid_flg,
    KDHP_ABSSPDINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ABSSPDINVALIDFAULTLEVEL_ENUM), ((uint8_T)KDHP_ABSSPDINVALIDSPDLIMIT),
    ((uint8_T)KDHP_ABSSPDINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ABSSPDINVALIDHANDLERESPONSEBITS),
    KDHP_ABSSpdInvalidActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_bf,
    &DHP_model_DW.Fault_Valid_RT_bf);

  /* End of Outputs for SubSystem: '<S1983>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1961>/ABSWorkErr' */
void DHP_model_ABSWorkErr(void)
{
  /* Outputs for Atomic SubSystem: '<S1986>/Fault_Valid_RT' */

  /* Constant: '<S1976>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1976>/Constant2'
   *  Constant: '<S1976>/KDHP_Fault_Level'
   *  Constant: '<S1976>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1976>/KDHP_Pwr_limit'
   *  Constant: '<S1976>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ABSWorkInstFlt_flg,
    KDHP_ABSWORKERRALLOWRECOVERY_FLG, ((uint8_T)KDHP_ABSWORKERRFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_ABSWORKERRSPDLIMIT), ((uint8_T)KDHP_ABSWORKERRPOWERLIMIT_PCT),
    ((uint16_T)KDHP_ABSWORKERRHANDLERESPONSEBITS),
    KDHP_ABSWorkErrActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_j1b,
    &DHP_model_DW.Fault_Valid_RT_j1b);

  /* End of Outputs for SubSystem: '<S1986>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1961>/EBDWorkErr' */
void DHP_model_EBDWorkErr(void)
{
  /* Outputs for Atomic SubSystem: '<S1989>/Fault_Valid_RT' */

  /* Constant: '<S1977>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1977>/Constant2'
   *  Constant: '<S1977>/KDHP_Fault_Level'
   *  Constant: '<S1977>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1977>/KDHP_Pwr_limit'
   *  Constant: '<S1977>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EBDWorkInstFlt_flg,
    KDHP_EBDWORKERRALLOWRECOVERY_FLG, ((uint8_T)KDHP_EBDWORKERRFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_EBDWORKERRSPDLIMIT), ((uint8_T)KDHP_EBDWORKERRPOWERLIMIT_PCT),
    ((uint16_T)KDHP_EBDWORKERRHANDLERESPONSEBITS),
    KDHP_EBDWorkErrActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_gv,
    &DHP_model_DW.Fault_Valid_RT_gv);

  /* End of Outputs for SubSystem: '<S1989>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1961>/EPBWorkErr' */
void DHP_model_EPBWorkErr(void)
{
  /* Outputs for Atomic SubSystem: '<S1992>/Fault_Valid_RT' */

  /* Constant: '<S1978>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1978>/Constant2'
   *  Constant: '<S1978>/KDHP_Fault_Level'
   *  Constant: '<S1978>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1978>/KDHP_Pwr_limit'
   *  Constant: '<S1978>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EPBWorkInstFlt_flg,
    KDHP_EPBWORKERRALLOWRECOVERY_FLG, ((uint8_T)KDHP_EPBWORKERRFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_EPBWORKERRSPDLIMIT), ((uint8_T)KDHP_EPBWORKERRPOWERLIMIT_PCT),
    ((uint16_T)KDHP_EPBWORKERRHANDLERESPONSEBITS),
    KDHP_EPBWorkErrActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ds,
    &DHP_model_DW.Fault_Valid_RT_ds);

  /* End of Outputs for SubSystem: '<S1992>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1961>/ESPWorkErr' */
void DHP_model_ESPWorkErr(void)
{
  /* Outputs for Atomic SubSystem: '<S1995>/Fault_Valid_RT' */

  /* Constant: '<S1979>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1979>/Constant2'
   *  Constant: '<S1979>/KDHP_Fault_Level'
   *  Constant: '<S1979>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1979>/KDHP_Pwr_limit'
   *  Constant: '<S1979>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ESPWorkErrInstFlt_flg,
    KDHP_ESPWORKERRALLOWRECOVERY_FLG, ((uint8_T)KDHP_ESPWORKERRFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_ESPWORKERRSPDLIMIT), ((uint8_T)KDHP_ESPWORKERRPOWERLIMIT_PCT),
    ((uint16_T)KDHP_ESPWORKERRHANDLERESPONSEBITS),
    KDHP_ESPWorkErrActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_kf,
    &DHP_model_DW.Fault_Valid_RT_kf);

  /* End of Outputs for SubSystem: '<S1995>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1961>/MCUSpdInvalid' */
void DHP_model_MCUSpdInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S1998>/Fault_Valid_RT' */

  /* Constant: '<S1980>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1980>/Constant2'
   *  Constant: '<S1980>/KDHP_Fault_Level'
   *  Constant: '<S1980>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1980>/KDHP_Pwr_limit'
   *  Constant: '<S1980>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUSpdInvalid_flg,
    KDHP_MCUSPDINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUSPDINVALIDFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUSPDINVALIDSPDLIMIT),
    ((uint8_T)KDHP_MCUSPDINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUSPDINVALIDHANDLERESPONSEBITS),
    KDHP_MCUSpdInvalidActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_en,
    &DHP_model_DW.Fault_Valid_RT_en);

  /* End of Outputs for SubSystem: '<S1998>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1961>/MCUTrqInvalid' */
void DHP_model_MCUTrqInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S2001>/Fault_Valid_RT' */

  /* Constant: '<S1981>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1981>/Constant2'
   *  Constant: '<S1981>/KDHP_Fault_Level'
   *  Constant: '<S1981>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1981>/KDHP_Pwr_limit'
   *  Constant: '<S1981>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUTrqInvalid_flg,
    KDHP_MCUTRQINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUTRQINVALIDFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUTRQINVALIDSPDLIMIT),
    ((uint8_T)KDHP_MCUTRQINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUTRQINVALIDHANDLERESPONSEBITS),
    KDHP_MCUTrqInvalidActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_hi,
    &DHP_model_DW.Fault_Valid_RT_hi);

  /* End of Outputs for SubSystem: '<S2001>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1961>/SpeedInvalid' */
void DHP_model_SpeedInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S2004>/Fault_Valid_Time' */

  /* Constant: '<S1982>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1982>/Constant2'
   *  Constant: '<S1982>/KDHP_Allow_Recover'
   *  Constant: '<S1982>/KDHP_Clear_Time'
   *  Constant: '<S1982>/KDHP_Fault_Level'
   *  Constant: '<S1982>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1982>/KDHP_Pwr_limit'
   *  Constant: '<S1982>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_SpeedInvalidInstFlt_flg, ((uint16_T)KDHP_SPEEDINVALIDCONFIRMTIME_MS),
    ((uint16_T)KDHP_SPEEDINVALIDCLEARTIME_MS),
    KDHP_SPEEDINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_SPEEDINVALIDFAULTLEVEL_ENUM), ((uint8_T)KDHP_SPEEDINVALIDSPDLIMIT),
    ((uint8_T)KDHP_SPEEDINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_SPEEDINVALIDHANDLERESPONSEBITS), KDHP_SpeedInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_ad, &DHP_model_DW.Fault_Valid_Time_ad);

  /* End of Outputs for SubSystem: '<S2004>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S15>/ABS_TQMWork_Fault' */
void DHP_model_ABS_TQMWork_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1961>/ABSSpdInvalid' */
  DHP_model_ABSSpdInvalid();

  /* End of Outputs for SubSystem: '<S1961>/ABSSpdInvalid' */

  /* Outputs for Atomic SubSystem: '<S1961>/ABSWorkErr' */
  DHP_model_ABSWorkErr();

  /* End of Outputs for SubSystem: '<S1961>/ABSWorkErr' */

  /* Outputs for Atomic SubSystem: '<S1961>/EBDWorkErr' */
  DHP_model_EBDWorkErr();

  /* End of Outputs for SubSystem: '<S1961>/EBDWorkErr' */

  /* Outputs for Atomic SubSystem: '<S1961>/EPBWorkErr' */
  DHP_model_EPBWorkErr();

  /* End of Outputs for SubSystem: '<S1961>/EPBWorkErr' */

  /* Outputs for Atomic SubSystem: '<S1961>/ESPWorkErr' */
  DHP_model_ESPWorkErr();

  /* End of Outputs for SubSystem: '<S1961>/ESPWorkErr' */

  /* Outputs for Atomic SubSystem: '<S1961>/MCUSpdInvalid' */
  DHP_model_MCUSpdInvalid();

  /* End of Outputs for SubSystem: '<S1961>/MCUSpdInvalid' */

  /* Outputs for Atomic SubSystem: '<S1961>/MCUTrqInvalid' */
  DHP_model_MCUTrqInvalid();

  /* End of Outputs for SubSystem: '<S1961>/MCUTrqInvalid' */

  /* Outputs for Atomic SubSystem: '<S1961>/SpeedInvalid' */
  DHP_model_SpeedInvalid();

  /* End of Outputs for SubSystem: '<S1961>/SpeedInvalid' */
}

/* Output and update for atomic system: '<S1962>/BattEnergyTooLow' */
void DHP_model_BattEnergyTooLow(void)
{
  /* Outputs for Atomic SubSystem: '<S2010>/Fault_Valid_RT' */

  /* Constant: '<S2009>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2009>/Constant2'
   *  Constant: '<S2009>/KDHP_Fault_Level'
   *  Constant: '<S2009>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2009>/KDHP_Pwr_limit'
   *  Constant: '<S2009>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.Compare_mj,
    KDHP_BATTENERGYTOOLOWALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BATTENERGYTOOLOWFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_BATTENERGYTOOLOWSPDLIMIT), ((uint8_T)
    KDHP_BATTENERGYTOOLOWPOWERLIMIT_PCT), ((uint16_T)
    KDHP_BATTENERGYTOOLOWHANDLERESPONSEBITS),
    KDHP_BattEnergyTooLowActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_j1y,
    &DHP_model_DW.Fault_Valid_RT_j1y);

  /* End of Outputs for SubSystem: '<S2010>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/BattEnergyTooLow' */
void DHP_model_BattEnergyTooLow_j(void)
{
  /* Outputs for Atomic SubSystem: '<S1962>/BattEnergyTooLow' */
  DHP_model_BattEnergyTooLow();

  /* End of Outputs for SubSystem: '<S1962>/BattEnergyTooLow' */
}

/* Output and update for atomic system: '<S1963>/DCChrgPortOverT' */
void DHP_model_DCChrgPortOverT(void)
{
  boolean_T rtb_RelationalOperator1_e1;
  boolean_T rtb_LogicalOperator3_d34;
  uint8_T rtb_Switch5_d;
  boolean_T rtb_RelationalOperator3_h0;
  boolean_T rtb_RelationalOperator1_m;
  boolean_T rtb_LogicalOperator3_ov;
  boolean_T rtb_Switch12;
  boolean_T rtb_Switch1;
  boolean_T rtb_LogicalOperator3_bu;
  boolean_T rtb_Switch10_h;
  uint8_T rtb_LogicalOperator3_dv;
  uint32_T rtb_LogicalOperator3_dv_0;
  uint32_T rtb_LogicalOperator3_bb;
  uint32_T qY;
  uint32_T qY_0;
  uint32_T qY_1;
  uint32_T qY_2;
  uint32_T qY_3;

  /* Switch: '<S2016>/Switch11' incorporates:
   *  Constant: '<S2016>/Constant3'
   *  Delay: '<S2016>/Delay'
   *  Logic: '<S2016>/Logical Operator1'
   *  Logic: '<S2016>/Logical Operator4'
   */
  if (VDHP_DCChrgPortOverT1InstFlt_flg && (!DHP_model_DW.Delay_DSTATE_fa)) {
    rtb_Switch5_d = 0U;
  } else {
    rtb_Switch5_d = VDHP_deltaSystemTick_ms;
  }

  /* End of Switch: '<S2016>/Switch11' */

  /* Switch: '<S2016>/Switch' incorporates:
   *  Constant: '<S2016>/Constant2'
   *  Delay: '<S2016>/Delay3'
   *  Logic: '<S2016>/Logical Operator5'
   *  Logic: '<S2016>/Logical Operator6'
   */
  if ((!DHP_model_B.LogicalOperator3_k) || DHP_model_DW.Delay3_DSTATE_k) {
    rtb_LogicalOperator3_dv = 0U;
  } else {
    rtb_LogicalOperator3_dv = rtb_Switch5_d;
  }

  /* End of Switch: '<S2016>/Switch' */

  /* Switch: '<S2016>/Switch1' incorporates:
   *  Constant: '<S2016>/Constant1'
   *  Delay: '<S2016>/Delay1'
   *  Logic: '<S2016>/Logical Operator7'
   */
  if (!DHP_model_B.LogicalOperator3_k) {
    rtb_LogicalOperator3_dv_0 = 0U;
  } else {
    rtb_LogicalOperator3_dv_0 = DHP_model_DW.Delay1_DSTATE_i;
  }

  /* End of Switch: '<S2016>/Switch1' */

  /* Sum: '<S2016>/Add2' */
  qY_3 = rtb_LogicalOperator3_dv + rtb_LogicalOperator3_dv_0;
  if (qY_3 < rtb_LogicalOperator3_dv) {
    qY_3 = MAX_uint32_T;
  }

  /* RelationalOperator: '<S2016>/Relational Operator1' incorporates:
   *  Constant: '<S2014>/Constant1'
   *  Sum: '<S2016>/Add2'
   */
  rtb_RelationalOperator1_e1 = (qY_3 >= KDHP_DCPortTFault_ms);

  /* Logic: '<S2016>/Logical Operator3' */
  rtb_LogicalOperator3_d34 = !VDHP_DCChrgPortOverT1InstFlt_flg;

  /* Switch: '<S2016>/Switch5' incorporates:
   *  Constant: '<S2016>/Constant10'
   *  Constant: '<S2016>/Constant11'
   *  Delay: '<S2016>/Delay7'
   *  Switch: '<S2016>/Switch4'
   */
  if (rtb_LogicalOperator3_d34) {
    rtb_LogicalOperator3_dv = 0U;
    rtb_LogicalOperator3_dv_0 = 0U;
  } else {
    rtb_LogicalOperator3_dv = rtb_Switch5_d;
    rtb_LogicalOperator3_dv_0 = DHP_model_DW.Delay7_DSTATE_l;
  }

  /* End of Switch: '<S2016>/Switch5' */

  /* Sum: '<S2016>/Add6' */
  qY_2 = rtb_LogicalOperator3_dv + rtb_LogicalOperator3_dv_0;
  if (qY_2 < rtb_LogicalOperator3_dv) {
    qY_2 = MAX_uint32_T;
  }

  /* Switch: '<S2016>/Switch9' incorporates:
   *  Constant: '<S2014>/Constant1'
   *  Delay: '<S2016>/Delay4'
   *  Logic: '<S2016>/Logical Operator2'
   *  RelationalOperator: '<S2016>/Relational Operator5'
   *  Sum: '<S2016>/Add6'
   */
  if (DHP_model_DW.Delay4_DSTATE_j) {
    rtb_LogicalOperator3_d34 = rtb_RelationalOperator1_e1;
  } else {
    rtb_LogicalOperator3_d34 = (rtb_LogicalOperator3_d34 && (qY_2 <
      KDHP_DCPortTFault_ms));
  }

  /* End of Switch: '<S2016>/Switch9' */

  /* Switch: '<S2016>/Switch3' incorporates:
   *  Constant: '<S2016>/Constant4'
   */
  if (!VDHP_DCChrgPortOverT1InstFlt_flg) {
    rtb_Switch5_d = 0U;
  }

  /* End of Switch: '<S2016>/Switch3' */

  /* Switch: '<S2016>/Switch7' incorporates:
   *  Constant: '<S2016>/Constant7'
   *  Delay: '<S2016>/Delay2'
   *  Logic: '<S2016>/Logical Operator'
   */
  if (rtb_LogicalOperator3_d34 || VDHP_NMSleepInd_flg) {
    rtb_LogicalOperator3_dv_0 = 0U;
  } else {
    rtb_LogicalOperator3_dv_0 = DHP_model_DW.Delay2_DSTATE_m;
  }

  /* End of Switch: '<S2016>/Switch7' */

  /* Sum: '<S2016>/Add3' */
  qY_1 = rtb_LogicalOperator3_dv_0 + rtb_Switch5_d;
  if (qY_1 < rtb_LogicalOperator3_dv_0) {
    qY_1 = MAX_uint32_T;
  }

  /* RelationalOperator: '<S2016>/Relational Operator3' incorporates:
   *  Constant: '<S2014>/Constant1'
   *  Sum: '<S2016>/Add3'
   */
  rtb_RelationalOperator3_h0 = (qY_1 >= KDHP_DCPortTFault_ms);

  /* Switch: '<S2016>/Switch2' */
  rtb_LogicalOperator3_d34 = ((!VDHP_NMSleepInd_flg) &&
    rtb_RelationalOperator3_h0);

  /* Switch: '<S2015>/Switch12' incorporates:
   *  Constant: '<S2013>/Constant2'
   */
  rtb_Switch12 = (KDHP_DCChrgPortOverTActionSwitchOpen_flg &&
                  rtb_LogicalOperator3_d34);

  /* Switch: '<S2017>/Switch11' incorporates:
   *  Constant: '<S2017>/Constant3'
   *  Delay: '<S2017>/Delay'
   *  Logic: '<S2017>/Logical Operator1'
   *  Logic: '<S2017>/Logical Operator4'
   */
  if (VDHP_DCChrgPortOverT2InstFlt_flg && (!DHP_model_DW.Delay_DSTATE_l)) {
    rtb_Switch5_d = 0U;
  } else {
    rtb_Switch5_d = VDHP_deltaSystemTick_ms;
  }

  /* End of Switch: '<S2017>/Switch11' */

  /* Switch: '<S2017>/Switch' incorporates:
   *  Constant: '<S2017>/Constant2'
   *  Delay: '<S2017>/Delay3'
   *  Logic: '<S2017>/Logical Operator5'
   *  Logic: '<S2017>/Logical Operator6'
   */
  if ((!DHP_model_B.LogicalOperator3_k) || DHP_model_DW.Delay3_DSTATE_fx) {
    rtb_LogicalOperator3_dv = 0U;
  } else {
    rtb_LogicalOperator3_dv = rtb_Switch5_d;
  }

  /* End of Switch: '<S2017>/Switch' */

  /* Switch: '<S2017>/Switch1' incorporates:
   *  Constant: '<S2017>/Constant1'
   *  Delay: '<S2017>/Delay1'
   *  Logic: '<S2017>/Logical Operator7'
   */
  if (!DHP_model_B.LogicalOperator3_k) {
    rtb_LogicalOperator3_dv_0 = 0U;
  } else {
    rtb_LogicalOperator3_dv_0 = DHP_model_DW.Delay1_DSTATE_j;
  }

  /* End of Switch: '<S2017>/Switch1' */

  /* Sum: '<S2017>/Add2' */
  rtb_LogicalOperator3_dv_0 += rtb_LogicalOperator3_dv;
  if (rtb_LogicalOperator3_dv_0 < rtb_LogicalOperator3_dv) {
    rtb_LogicalOperator3_dv_0 = MAX_uint32_T;
  }

  /* RelationalOperator: '<S2017>/Relational Operator1' incorporates:
   *  Constant: '<S2014>/Constant1'
   *  Sum: '<S2017>/Add2'
   */
  rtb_RelationalOperator1_m = (rtb_LogicalOperator3_dv_0 >= KDHP_DCPortTFault_ms);

  /* Logic: '<S2017>/Logical Operator3' */
  rtb_LogicalOperator3_ov = !VDHP_DCChrgPortOverT2InstFlt_flg;

  /* Switch: '<S2017>/Switch5' incorporates:
   *  Constant: '<S2017>/Constant10'
   *  Constant: '<S2017>/Constant11'
   *  Delay: '<S2017>/Delay7'
   *  Switch: '<S2017>/Switch4'
   */
  if (rtb_LogicalOperator3_ov) {
    rtb_LogicalOperator3_dv = 0U;
    rtb_LogicalOperator3_bb = 0U;
  } else {
    rtb_LogicalOperator3_dv = rtb_Switch5_d;
    rtb_LogicalOperator3_bb = DHP_model_DW.Delay7_DSTATE_j;
  }

  /* End of Switch: '<S2017>/Switch5' */

  /* Sum: '<S2017>/Add6' */
  qY_0 = rtb_LogicalOperator3_dv + rtb_LogicalOperator3_bb;
  if (qY_0 < rtb_LogicalOperator3_dv) {
    qY_0 = MAX_uint32_T;
  }

  /* Switch: '<S2017>/Switch9' incorporates:
   *  Constant: '<S2014>/Constant1'
   *  Delay: '<S2017>/Delay4'
   *  Logic: '<S2017>/Logical Operator2'
   *  RelationalOperator: '<S2017>/Relational Operator5'
   *  Sum: '<S2017>/Add6'
   */
  if (DHP_model_DW.Delay4_DSTATE_fu) {
    rtb_LogicalOperator3_ov = rtb_RelationalOperator1_m;
  } else {
    rtb_LogicalOperator3_ov = (rtb_LogicalOperator3_ov && (qY_0 <
      KDHP_DCPortTFault_ms));
  }

  /* End of Switch: '<S2017>/Switch9' */

  /* Switch: '<S2017>/Switch3' incorporates:
   *  Constant: '<S2017>/Constant4'
   */
  if (!VDHP_DCChrgPortOverT2InstFlt_flg) {
    rtb_Switch5_d = 0U;
  }

  /* End of Switch: '<S2017>/Switch3' */

  /* Switch: '<S2017>/Switch7' incorporates:
   *  Constant: '<S2017>/Constant7'
   *  Delay: '<S2017>/Delay2'
   *  Logic: '<S2017>/Logical Operator'
   */
  if (rtb_LogicalOperator3_ov || VDHP_NMSleepInd_flg) {
    rtb_LogicalOperator3_bb = 0U;
  } else {
    rtb_LogicalOperator3_bb = DHP_model_DW.Delay2_DSTATE_k;
  }

  /* End of Switch: '<S2017>/Switch7' */

  /* Sum: '<S2017>/Add3' */
  qY = rtb_LogicalOperator3_bb + rtb_Switch5_d;
  if (qY < rtb_LogicalOperator3_bb) {
    qY = MAX_uint32_T;
  }

  /* Switch: '<S2017>/Switch10' incorporates:
   *  Constant: '<S2014>/Constant1'
   *  Constant: '<S2017>/Constant13'
   *  Delay: '<S2017>/Delay6'
   *  RelationalOperator: '<S2017>/Relational Operator3'
   *  Sum: '<S2017>/Add3'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_h = false;
  } else {
    rtb_Switch10_h = ((qY >= KDHP_DCPortTFault_ms) ||
                      DHP_model_DW.Delay6_DSTATE_dz);
  }

  /* End of Switch: '<S2017>/Switch10' */

  /* Switch: '<S2017>/Switch2' */
  rtb_LogicalOperator3_ov = ((!VDHP_NMSleepInd_flg) && rtb_Switch10_h);

  /* Switch: '<S2015>/Switch1' incorporates:
   *  Constant: '<S2013>/Constant2'
   */
  rtb_Switch1 = (KDHP_DCChrgPortOverTActionSwitchOpen_flg &&
                 rtb_LogicalOperator3_ov);

  /* Logic: '<S2015>/Logical Operator3' */
  rtb_LogicalOperator3_bu = (rtb_Switch12 || rtb_Switch1);

  /* Switch: '<S2015>/Switch13' incorporates:
   *  Constant: '<S2013>/KDHP_Pwr_limit'
   *  Constant: '<S2013>/KDHP_Spd_Limit'
   *  Constant: '<S2015>/Constant13'
   *  Constant: '<S2015>/Constant2'
   *  Switch: '<S2015>/Switch3'
   */
  if (rtb_LogicalOperator3_bu) {
    DHP_model_B.Switch13_e = ((uint8_T)KDHP_DCCHRGPORTOVERTSPDLIMIT);
    DHP_model_B.Switch3_f = ((uint8_T)KDHP_DCCHRGPORTOVERTPOWERLIMIT_PCT);
  } else {
    DHP_model_B.Switch13_e = 200U;
    DHP_model_B.Switch3_f = 100U;
  }

  /* End of Switch: '<S2015>/Switch13' */

  /* Switch: '<S2015>/Switch2' incorporates:
   *  Constant: '<S2015>/Constant1'
   *  Constant: '<S2015>/禁止充电'
   *  Switch: '<S2015>/Switch4'
   */
  if (rtb_Switch1) {
    DHP_model_B.Switch2_ei = 1024U;
  } else if (rtb_Switch12) {
    /* Switch: '<S2015>/Switch4' incorporates:
     *  Constant: '<S2013>/KDHP_Handle_Response_Bits'
     */
    DHP_model_B.Switch2_ei = ((uint16_T)KDHP_DCCHRGPORTOVERTHANDLERESPONSEBITS);
  } else {
    DHP_model_B.Switch2_ei = 0U;
  }

  /* End of Switch: '<S2015>/Switch2' */

  /* Logic: '<S2014>/Logical Operator3' */
  DHP_model_B.LogicalOperator3 = (rtb_LogicalOperator3_d34 ||
    rtb_LogicalOperator3_ov);

  /* Switch: '<S2014>/Switch2' incorporates:
   *  Constant: '<S2013>/Constant2'
   *  Constant: '<S2013>/KDHP_Fault_Level'
   *  Constant: '<S2014>/Constant'
   *  Logic: '<S2014>/Logical Operator'
   */
  if (KDHP_DCChrgPortOverTActionSwitchOpen_flg && DHP_model_B.LogicalOperator3)
  {
    DHP_model_B.Switch2_fl = ((uint8_T)KDHP_DCCHRGPORTOVERTFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_fl = 0U;
  }

  /* End of Switch: '<S2014>/Switch2' */

  /* Update for Delay: '<S2016>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_k = rtb_RelationalOperator1_e1;

  /* Update for Delay: '<S2016>/Delay' */
  DHP_model_DW.Delay_DSTATE_fa = VDHP_DCChrgPortOverT1InstFlt_flg;

  /* Update for Delay: '<S2016>/Delay1' incorporates:
   *  Sum: '<S2016>/Add2'
   */
  DHP_model_DW.Delay1_DSTATE_i = qY_3;

  /* Update for Delay: '<S2016>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_j = rtb_RelationalOperator3_h0;

  /* Update for Delay: '<S2016>/Delay7' incorporates:
   *  Sum: '<S2016>/Add6'
   */
  DHP_model_DW.Delay7_DSTATE_l = qY_2;

  /* Update for Delay: '<S2016>/Delay2' incorporates:
   *  Sum: '<S2016>/Add3'
   */
  DHP_model_DW.Delay2_DSTATE_m = qY_1;

  /* Update for Delay: '<S2017>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_fx = rtb_RelationalOperator1_m;

  /* Update for Delay: '<S2017>/Delay' */
  DHP_model_DW.Delay_DSTATE_l = VDHP_DCChrgPortOverT2InstFlt_flg;

  /* Update for Delay: '<S2017>/Delay1' incorporates:
   *  Sum: '<S2017>/Add2'
   */
  DHP_model_DW.Delay1_DSTATE_j = rtb_LogicalOperator3_dv_0;

  /* Update for Delay: '<S2017>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_fu = rtb_Switch10_h;

  /* Update for Delay: '<S2017>/Delay7' incorporates:
   *  Sum: '<S2017>/Add6'
   */
  DHP_model_DW.Delay7_DSTATE_j = qY_0;

  /* Update for Delay: '<S2017>/Delay2' incorporates:
   *  Sum: '<S2017>/Add3'
   */
  DHP_model_DW.Delay2_DSTATE_k = qY;

  /* Update for Delay: '<S2017>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_dz = rtb_Switch10_h;
}

/* Output and update for atomic system: '<S15>/DCChrgPortOverT_Fault' */
void DHP_model_DCChrgPortOverT_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1963>/DCChrgPortOverT' */
  DHP_model_DCChrgPortOverT();

  /* End of Outputs for SubSystem: '<S1963>/DCChrgPortOverT' */
}

/* Output and update for atomic system: '<S1964>/DcdcFlt2' */
void DHP_model_DcdcFlt2(void)
{
  /* Outputs for Atomic SubSystem: '<S2019>/Fault_Valid_RT' */

  /* Constant: '<S2018>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2018>/Constant2'
   *  Constant: '<S2018>/KDHP_Fault_Level'
   *  Constant: '<S2018>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2018>/KDHP_Pwr_limit'
   *  Constant: '<S2018>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_DcdcFlt2_flg,
    KDHP_DCDCFLT2ALLOWRECOVERY_FLG, ((uint8_T)KDHP_DCDCFLT2FAULTLEVEL_ENUM),
    ((uint8_T)KDHP_DCDCFLT2SPDLIMIT), ((uint8_T)KDHP_DCDCFLT2POWERLIMIT_PCT),
    ((uint16_T)KDHP_DCDCFLT2HANDLERESPONSEBITS),
    KDHP_DcdcFlt2ActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_b3,
    &DHP_model_DW.Fault_Valid_RT_b3);

  /* End of Outputs for SubSystem: '<S2019>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/DCDC_Fault' */
void DHP_model_DCDC_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1964>/DcdcFlt2' */
  DHP_model_DcdcFlt2();

  /* End of Outputs for SubSystem: '<S1964>/DcdcFlt2' */
}

/* Output and update for atomic system: '<S1965>/EPSWorkErr' */
void DHP_model_EPSWorkErr(void)
{
  /* Outputs for Atomic SubSystem: '<S2023>/Fault_Valid_RT' */

  /* Constant: '<S2022>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2022>/Constant2'
   *  Constant: '<S2022>/KDHP_Fault_Level'
   *  Constant: '<S2022>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2022>/KDHP_Pwr_limit'
   *  Constant: '<S2022>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EPSWorkInstFlt_flg,
    KDHP_EPSWORKERRALLOWRECOVERY_FLG, ((uint8_T)KDHP_EPSWORKERRFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_EPSWORKERRSPDLIMIT), ((uint8_T)KDHP_EPSWORKERRPOWERLIMIT_PCT),
    ((uint16_T)KDHP_EPSWORKERRHANDLERESPONSEBITS),
    KDHP_EPSWorkErrActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_hb,
    &DHP_model_DW.Fault_Valid_RT_hb);

  /* End of Outputs for SubSystem: '<S2023>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/EPSWorkErr_Fault' */
void DHP_model_EPSWorkErr_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1965>/EPSWorkErr' */
  DHP_model_EPSWorkErr();

  /* End of Outputs for SubSystem: '<S1965>/EPSWorkErr' */
}

/* Output and update for atomic system: '<S1966>/EsclAuthenticFailed' */
void DHP_model_EsclAuthenticFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2041>/Fault_Valid_RT' */

  /* Constant: '<S2026>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2026>/Constant2'
   *  Constant: '<S2026>/KDHP_Fault_Level'
   *  Constant: '<S2026>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2026>/KDHP_Pwr_limit'
   *  Constant: '<S2026>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclAuthenticFailed_flg,
    KDHP_ESCLAUTHENTICFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLAUTHENTICFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLAUTHENTICFAILEDSPDLIMIT), ((uint8_T)
    KDHP_ESCLAUTHENTICFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLAUTHENTICFAILEDHANDLERESPONSEBITS),
    KDHP_EsclAuthenticFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_hg,
    &DHP_model_DW.Fault_Valid_RT_hg);

  /* End of Outputs for SubSystem: '<S2041>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclChipHWFailed' */
void DHP_model_EsclChipHWFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2044>/Fault_Valid_RT' */

  /* Constant: '<S2027>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2027>/Constant2'
   *  Constant: '<S2027>/KDHP_Fault_Level'
   *  Constant: '<S2027>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2027>/KDHP_Pwr_limit'
   *  Constant: '<S2027>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclChipHWFailed_flg,
    KDHP_ESCLCHIPHWFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLCHIPHWFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLCHIPHWFAILEDSPDLIMIT), ((uint8_T)
    KDHP_ESCLCHIPHWFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLCHIPHWFAILEDHANDLERESPONSEBITS),
    KDHP_EsclChipHWFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_lt,
    &DHP_model_DW.Fault_Valid_RT_lt);

  /* End of Outputs for SubSystem: '<S2044>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclEEPROMFailed' */
void DHP_model_EsclEEPROMFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2047>/Fault_Valid_RT' */

  /* Constant: '<S2028>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2028>/Constant2'
   *  Constant: '<S2028>/KDHP_Fault_Level'
   *  Constant: '<S2028>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2028>/KDHP_Pwr_limit'
   *  Constant: '<S2028>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclEEPROMFailed_flg,
    KDHP_ESCLEEPROMFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLEEPROMFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLEEPROMFAILEDSPDLIMIT), ((uint8_T)
    KDHP_ESCLEEPROMFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLEEPROMFAILEDHANDLERESPONSEBITS),
    KDHP_EsclEEPROMFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_etn,
    &DHP_model_DW.Fault_Valid_RT_etn);

  /* End of Outputs for SubSystem: '<S2047>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclLinCommFailed' */
void DHP_model_EsclLinCommFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2050>/Fault_Valid_RT' */

  /* Constant: '<S2029>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2029>/Constant2'
   *  Constant: '<S2029>/KDHP_Fault_Level'
   *  Constant: '<S2029>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2029>/KDHP_Pwr_limit'
   *  Constant: '<S2029>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclLinCommFailed_flg,
    KDHP_ESCLLINCOMMFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLLINCOMMFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLLINCOMMFAILEDSPDLIMIT), ((uint8_T)
    KDHP_ESCLLINCOMMFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLLINCOMMFAILEDHANDLERESPONSEBITS),
    KDHP_EsclLinCommFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_cu,
    &DHP_model_DW.Fault_Valid_RT_cu);

  /* End of Outputs for SubSystem: '<S2050>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclLockGndFailed' */
void DHP_model_EsclLockGndFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2053>/Fault_Valid_RT' */

  /* Constant: '<S2030>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2030>/Constant2'
   *  Constant: '<S2030>/KDHP_Fault_Level'
   *  Constant: '<S2030>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2030>/KDHP_Pwr_limit'
   *  Constant: '<S2030>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclLockGndFailed_flg,
    KDHP_ESCLLOCKGNDFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLLOCKGNDFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLLOCKGNDFAILEDSPDLIMIT), ((uint8_T)
    KDHP_ESCLLOCKGNDFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLLOCKGNDFAILEDHANDLERESPONSEBITS),
    KDHP_EsclLockGndFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_jk,
    &DHP_model_DW.Fault_Valid_RT_jk);

  /* End of Outputs for SubSystem: '<S2053>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclLockTimeout' */
void DHP_model_EsclLockTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S2056>/Fault_Valid_RT' */

  /* Constant: '<S2031>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2031>/Constant2'
   *  Constant: '<S2031>/KDHP_Fault_Level'
   *  Constant: '<S2031>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2031>/KDHP_Pwr_limit'
   *  Constant: '<S2031>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclLockTimeout_flg,
    KDHP_ESCLLOCKTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLLOCKTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)KDHP_ESCLLOCKTIMEOUTSPDLIMIT),
    ((uint8_T)KDHP_ESCLLOCKTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLLOCKTIMEOUTHANDLERESPONSEBITS),
    KDHP_EsclLockTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ax,
    &DHP_model_DW.Fault_Valid_RT_ax);

  /* End of Outputs for SubSystem: '<S2056>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclMasterIReqInvalid' */
void DHP_model_EsclMasterIReqInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S2059>/Fault_Valid_RT' */

  /* Constant: '<S2032>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2032>/Constant2'
   *  Constant: '<S2032>/KDHP_Fault_Level'
   *  Constant: '<S2032>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2032>/KDHP_Pwr_limit'
   *  Constant: '<S2032>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclMasterIReqInvalid_flg,
    KDHP_ESCLMASTERIREQINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLMASTERIREQINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLMASTERIREQINVALIDSPDLIMIT), ((uint8_T)
    KDHP_ESCLMASTERIREQINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLMASTERIREQINVALIDHANDLERESPONSEBITS),
    KDHP_EsclMasterIReqInvalidActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_ik, &DHP_model_DW.Fault_Valid_RT_ik);

  /* End of Outputs for SubSystem: '<S2059>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclMasterReqTimeout' */
void DHP_model_EsclMasterReqTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S2062>/Fault_Valid_RT' */

  /* Constant: '<S2033>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2033>/Constant2'
   *  Constant: '<S2033>/KDHP_Fault_Level'
   *  Constant: '<S2033>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2033>/KDHP_Pwr_limit'
   *  Constant: '<S2033>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclMasterReqTimeout_flg,
    KDHP_ESCLMASTERREQTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLMASTERREQTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLMASTERREQTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_ESCLMASTERREQTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLMASTERREQTIMEOUTHANDLERESPONSEBITS),
    KDHP_EsclMasterReqTimeoutActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_c2, &DHP_model_DW.Fault_Valid_RT_c2);

  /* End of Outputs for SubSystem: '<S2062>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclMotorDriverFailed' */
void DHP_model_EsclMotorDriverFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2065>/Fault_Valid_RT' */

  /* Constant: '<S2034>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2034>/Constant2'
   *  Constant: '<S2034>/KDHP_Fault_Level'
   *  Constant: '<S2034>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2034>/KDHP_Pwr_limit'
   *  Constant: '<S2034>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclMotorDriverFailed_flg,
    KDHP_ESCLMOTORDRIVERFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLMOTORDRIVERFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLMOTORDRIVERFAILEDSPDLIMIT), ((uint8_T)
    KDHP_ESCLMOTORDRIVERFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLMOTORDRIVERFAILEDHANDLERESPONSEBITS),
    KDHP_EsclMotorDriverFailedActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_g1, &DHP_model_DW.Fault_Valid_RT_g1);

  /* End of Outputs for SubSystem: '<S2065>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclMotorNoAct' */
void DHP_model_EsclMotorNoAct(void)
{
  /* Outputs for Atomic SubSystem: '<S2068>/Fault_Valid_RT' */

  /* Constant: '<S2035>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2035>/Constant2'
   *  Constant: '<S2035>/KDHP_Fault_Level'
   *  Constant: '<S2035>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2035>/KDHP_Pwr_limit'
   *  Constant: '<S2035>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclMotorNoAct_flg,
    KDHP_ESCLMOTORNOACTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLMOTORNOACTFAULTLEVEL_ENUM), ((uint8_T)KDHP_ESCLMOTORNOACTSPDLIMIT),
    ((uint8_T)KDHP_ESCLMOTORNOACTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLMOTORNOACTHANDLERESPONSEBITS),
    KDHP_EsclMotorNoActActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_iw,
    &DHP_model_DW.Fault_Valid_RT_iw);

  /* End of Outputs for SubSystem: '<S2068>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclMotorOverload' */
void DHP_model_EsclMotorOverload(void)
{
  /* Outputs for Atomic SubSystem: '<S2071>/Fault_Valid_RT' */

  /* Constant: '<S2036>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2036>/Constant2'
   *  Constant: '<S2036>/KDHP_Fault_Level'
   *  Constant: '<S2036>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2036>/KDHP_Pwr_limit'
   *  Constant: '<S2036>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclMotorOverload_flg,
    KDHP_ESCLMOTOROVERLOADALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLMOTOROVERLOADFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLMOTOROVERLOADSPDLIMIT), ((uint8_T)
    KDHP_ESCLMOTOROVERLOADPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLMOTOROVERLOADHANDLERESPONSEBITS),
    KDHP_EsclMotorOverloadActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ii,
    &DHP_model_DW.Fault_Valid_RT_ii);

  /* End of Outputs for SubSystem: '<S2071>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclPwrSupplyFailed' */
void DHP_model_EsclPwrSupplyFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2074>/Fault_Valid_RT' */

  /* Constant: '<S2037>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2037>/Constant2'
   *  Constant: '<S2037>/KDHP_Fault_Level'
   *  Constant: '<S2037>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2037>/KDHP_Pwr_limit'
   *  Constant: '<S2037>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclPwrSupplyFailed_flg,
    KDHP_ESCLPWRSUPPLYFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLPWRSUPPLYFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLPWRSUPPLYFAILEDSPDLIMIT), ((uint8_T)
    KDHP_ESCLPWRSUPPLYFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLPWRSUPPLYFAILEDHANDLERESPONSEBITS),
    KDHP_EsclPwrSupplyFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_e1,
    &DHP_model_DW.Fault_Valid_RT_e1);

  /* End of Outputs for SubSystem: '<S2074>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclSensorHWFailed' */
void DHP_model_EsclSensorHWFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2077>/Fault_Valid_RT' */

  /* Constant: '<S2038>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2038>/Constant2'
   *  Constant: '<S2038>/KDHP_Fault_Level'
   *  Constant: '<S2038>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2038>/KDHP_Pwr_limit'
   *  Constant: '<S2038>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclSensorHWFailed_flg,
    KDHP_ESCLSENSORHWFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLSENSORHWFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLSENSORHWFAILEDSPDLIMIT), ((uint8_T)
    KDHP_ESCLSENSORHWFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLSENSORHWFAILEDHANDLERESPONSEBITS),
    KDHP_EsclSensorHWFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_fm,
    &DHP_model_DW.Fault_Valid_RT_fm);

  /* End of Outputs for SubSystem: '<S2077>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclSensorStsFailed' */
void DHP_model_EsclSensorStsFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2080>/Fault_Valid_RT' */

  /* Constant: '<S2039>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2039>/Constant2'
   *  Constant: '<S2039>/KDHP_Fault_Level'
   *  Constant: '<S2039>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2039>/KDHP_Pwr_limit'
   *  Constant: '<S2039>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclSensorStsFailed_flg,
    KDHP_ESCLSENSORSTSFAILEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLSENSORSTSFAILEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLSENSORSTSFAILEDSPDLIMIT), ((uint8_T)
    KDHP_ESCLSENSORSTSFAILEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLSENSORSTSFAILEDHANDLERESPONSEBITS),
    KDHP_EsclSensorStsFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_oy,
    &DHP_model_DW.Fault_Valid_RT_oy);

  /* End of Outputs for SubSystem: '<S2080>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1966>/EsclUnlockTimeout' */
void DHP_model_EsclUnlockTimeout(void)
{
  /* Outputs for Atomic SubSystem: '<S2083>/Fault_Valid_RT' */

  /* Constant: '<S2040>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2040>/Constant2'
   *  Constant: '<S2040>/KDHP_Fault_Level'
   *  Constant: '<S2040>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2040>/KDHP_Pwr_limit'
   *  Constant: '<S2040>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_EsclUnlockTimeout_flg,
    KDHP_ESCLUNLOCKTIMEOUTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ESCLUNLOCKTIMEOUTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ESCLUNLOCKTIMEOUTSPDLIMIT), ((uint8_T)
    KDHP_ESCLUNLOCKTIMEOUTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ESCLUNLOCKTIMEOUTHANDLERESPONSEBITS),
    KDHP_EsclUnlockTimeoutActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_e2,
    &DHP_model_DW.Fault_Valid_RT_e2);

  /* End of Outputs for SubSystem: '<S2083>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/ESCL_Fault' */
void DHP_model_ESCL_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1966>/EsclAuthenticFailed' */
  DHP_model_EsclAuthenticFailed();

  /* End of Outputs for SubSystem: '<S1966>/EsclAuthenticFailed' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclChipHWFailed' */
  DHP_model_EsclChipHWFailed();

  /* End of Outputs for SubSystem: '<S1966>/EsclChipHWFailed' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclEEPROMFailed' */
  DHP_model_EsclEEPROMFailed();

  /* End of Outputs for SubSystem: '<S1966>/EsclEEPROMFailed' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclLinCommFailed' */
  DHP_model_EsclLinCommFailed();

  /* End of Outputs for SubSystem: '<S1966>/EsclLinCommFailed' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclLockGndFailed' */
  DHP_model_EsclLockGndFailed();

  /* End of Outputs for SubSystem: '<S1966>/EsclLockGndFailed' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclLockTimeout' */
  DHP_model_EsclLockTimeout();

  /* End of Outputs for SubSystem: '<S1966>/EsclLockTimeout' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclMasterIReqInvalid' */
  DHP_model_EsclMasterIReqInvalid();

  /* End of Outputs for SubSystem: '<S1966>/EsclMasterIReqInvalid' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclMasterReqTimeout' */
  DHP_model_EsclMasterReqTimeout();

  /* End of Outputs for SubSystem: '<S1966>/EsclMasterReqTimeout' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclMotorDriverFailed' */
  DHP_model_EsclMotorDriverFailed();

  /* End of Outputs for SubSystem: '<S1966>/EsclMotorDriverFailed' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclMotorNoAct' */
  DHP_model_EsclMotorNoAct();

  /* End of Outputs for SubSystem: '<S1966>/EsclMotorNoAct' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclMotorOverload' */
  DHP_model_EsclMotorOverload();

  /* End of Outputs for SubSystem: '<S1966>/EsclMotorOverload' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclPwrSupplyFailed' */
  DHP_model_EsclPwrSupplyFailed();

  /* End of Outputs for SubSystem: '<S1966>/EsclPwrSupplyFailed' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclSensorHWFailed' */
  DHP_model_EsclSensorHWFailed();

  /* End of Outputs for SubSystem: '<S1966>/EsclSensorHWFailed' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclSensorStsFailed' */
  DHP_model_EsclSensorStsFailed();

  /* End of Outputs for SubSystem: '<S1966>/EsclSensorStsFailed' */

  /* Outputs for Atomic SubSystem: '<S1966>/EsclUnlockTimeout' */
  DHP_model_EsclUnlockTimeout();

  /* End of Outputs for SubSystem: '<S1966>/EsclUnlockTimeout' */
}

/* Output and update for atomic system: '<S1967>/IChrgError' */
void DHP_model_IChrgError(void)
{
  /* Outputs for Atomic SubSystem: '<S2087>/Fault_Valid_RT' */

  /* Constant: '<S2086>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2086>/Constant2'
   *  Constant: '<S2086>/KDHP_Fault_Level'
   *  Constant: '<S2086>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2086>/KDHP_Pwr_limit'
   *  Constant: '<S2086>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.Compare_ce,
    KDHP_ICHRGERRORALLOWRECOVERY_FLG, ((uint8_T)KDHP_ICHRGERRORFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_ICHRGERRORSPDLIMIT), ((uint8_T)KDHP_ICHRGERRORPOWERLIMIT_PCT),
    ((uint16_T)KDHP_ICHRGERRORHANDLERESPONSEBITS),
    KDHP_IChrgErrorActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_j0,
    &DHP_model_DW.Fault_Valid_RT_j0);

  /* End of Outputs for SubSystem: '<S2087>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/IChrgError' */
void DHP_model_IChrgError_g(void)
{
  /* Outputs for Atomic SubSystem: '<S1967>/IChrgError' */
  DHP_model_IChrgError();

  /* End of Outputs for SubSystem: '<S1967>/IChrgError' */
}

/* Output and update for atomic system: '<S1968>/BMSModeErr' */
void DHP_model_BMSModeErr(void)
{
  boolean_T rtb_Switch50;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_Switch10_p;
  boolean_T rtb_Switch9;
  boolean_T rtb_Switch11_e;
  boolean_T rtb_Switch13_j;

  /* Switch: '<S2093>/Switch10' incorporates:
   *  Constant: '<S2093>/Constant12'
   *  Constant: '<S2093>/Constant13'
   *  Delay: '<S2093>/Delay6'
   *  Switch: '<S2093>/Switch6'
   *  Switch: '<S2093>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_p = false;
    DHP_model_B.Switch9_n = false;
  } else {
    rtb_Switch10_p = (VDHP_BMSModErrInstFlt_flg || DHP_model_DW.Delay6_DSTATE_i);

    /* Switch: '<S2093>/Switch8' incorporates:
     *  Constant: '<S2090>/KDHP_Allow_Recover'
     *  Delay: '<S2093>/Delay6'
     *  Switch: '<S2093>/Switch6'
     */
    if (KDHP_BMSMODEERRALLOWRECOVERY_FLG) {
      DHP_model_B.Switch9_n = VDHP_BMSModErrInstFlt_flg;
    } else {
      DHP_model_B.Switch9_n = rtb_Switch10_p;
    }

    /* End of Switch: '<S2093>/Switch8' */
  }

  /* End of Switch: '<S2093>/Switch10' */

  /* Switch: '<S2094>/Switch50' incorporates:
   *  Constant: '<S2090>/Constant2'
   */
  rtb_Switch50 = (KDHP_BMSModeErrActionSwitchOpen_flg && DHP_model_B.Switch9_n);

  /* Logic: '<S2094>/Logical Operator1' incorporates:
   *  Delay: '<S2094>/Delay2'
   *  Logic: '<S2094>/Logical Operator2'
   */
  rtb_LogicalOperator1 = ((!DHP_model_DW.Delay2_DSTATE_a) && rtb_Switch50);

  /* Switch: '<S2094>/Switch6' incorporates:
   *  Constant: '<S2094>/Constant5'
   *  Constant: '<S2094>/Constant8'
   *  Constant: '<S2095>/Constant14'
   *  Delay: '<S2094>/Delay1'
   *  Delay: '<S2095>/Delay2'
   *  Delay: '<S2095>/Delay3'
   *  Logic: '<S2094>/Logical Operator6'
   *  Logic: '<S2094>/Logical Operator7'
   *  Logic: '<S2095>/Logical Operator2'
   *  Logic: '<S2095>/Logical Operator3'
   *  Logic: '<S2095>/Logical Operator6'
   *  RelationalOperator: '<S2094>/Relational Operator3'
   *  Switch: '<S2095>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    DHP_model_B.Switch6_p = false;
    rtb_Switch9 = false;
  } else {
    DHP_model_B.Switch6_p = (DHP_model_B.Switch6_p || (rtb_LogicalOperator1 &&
      (DHP_model_B.Gain9 > KDHP_GradsSpeed_basisTime)));
    rtb_Switch9 = (DHP_model_DW.Delay3_DSTATE_le ||
                   ((!DHP_model_DW.Delay2_DSTATE_nz) && DHP_model_B.Switch6_p));
  }

  /* End of Switch: '<S2094>/Switch6' */

  /* Outputs for Atomic SubSystem: '<S2095>/DHP_systemtick_Timer' */

  /* Constant: '<S2095>/Constant21' */
  DHP_model_DHP_systemtick_Timer_c(rtb_Switch9, VDHP_deltaSystemTick_ms,
    KDHP_WaitTime1_GradsbasisTime_ms, &DHP_model_B.DHP_systemtick_Timer_ot,
    &DHP_model_DW.DHP_systemtick_Timer_ot);

  /* End of Outputs for SubSystem: '<S2095>/DHP_systemtick_Timer' */

  /* Switch: '<S2095>/Switch11' incorporates:
   *  Constant: '<S2095>/Constant17'
   *  Delay: '<S2095>/Delay1'
   *  Delay: '<S2095>/Delay4'
   *  Logic: '<S2095>/Logical Operator4'
   *  Logic: '<S2095>/Logical Operator5'
   *  Logic: '<S2095>/Logical Operator9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch11_e = false;
  } else {
    rtb_Switch11_e = (DHP_model_DW.Delay4_DSTATE_d ||
                      ((!DHP_model_DW.Delay1_DSTATE_l) &&
                       DHP_model_B.DHP_systemtick_Timer_ot.RelationalOperator));
  }

  /* End of Switch: '<S2095>/Switch11' */

  /* Outputs for Atomic SubSystem: '<S2095>/DHP_systemtick_Timer1' */

  /* Constant: '<S2095>/Constant18' */
  DHP_model_DHP_systemtick_Timer_c(rtb_Switch11_e, VDHP_deltaSystemTick_ms,
    KDHP_WaitTime2_GradsbasisTime_ms, &DHP_model_B.DHP_systemtick_Timer1_ff,
    &DHP_model_DW.DHP_systemtick_Timer1_ff);

  /* End of Outputs for SubSystem: '<S2095>/DHP_systemtick_Timer1' */

  /* Switch: '<S2095>/Switch13' incorporates:
   *  Constant: '<S2094>/Constant10'
   *  Constant: '<S2094>/Constant11'
   *  Constant: '<S2095>/Constant22'
   *  Delay: '<S2094>/Delay3'
   *  Delay: '<S2095>/Delay5'
   *  Delay: '<S2095>/Delay6'
   *  Logic: '<S2094>/Logical Operator10'
   *  Logic: '<S2094>/Logical Operator9'
   *  Logic: '<S2095>/Logical Operator10'
   *  Logic: '<S2095>/Logical Operator7'
   *  Logic: '<S2095>/Logical Operator8'
   *  RelationalOperator: '<S2094>/Relational Operator1'
   *  Switch: '<S2094>/Switch8'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch13_j = false;
    rtb_LogicalOperator1 = false;
  } else {
    rtb_Switch13_j = (DHP_model_DW.Delay6_DSTATE_l ||
                      ((!DHP_model_DW.Delay5_DSTATE_e) &&
                       DHP_model_B.DHP_systemtick_Timer1_ff.RelationalOperator));
    rtb_LogicalOperator1 = (DHP_model_DW.Delay3_DSTATE_c ||
      (rtb_LogicalOperator1 && (DHP_model_B.Gain9 <= KDHP_GradsSpeed_basisTime)));
  }

  /* End of Switch: '<S2095>/Switch13' */

  /* Switch: '<S2094>/Switch2' incorporates:
   *  Constant: '<S2090>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2090>/KDHP_Pwr_limit'
   *  Constant: '<S2090>/KDHP_Spd_Limit'
   *  Switch: '<S2094>/Switch11'
   *  Switch: '<S2094>/Switch13'
   *  Switch: '<S2094>/Switch3'
   *  Switch: '<S2094>/Switch4'
   *  Switch: '<S2095>/Switch14'
   */
  if (rtb_LogicalOperator1) {
    DHP_model_B.Switch2_gf = ((uint16_T)KDHP_BMSMODEERRHANDLERESPONSEBITS);
    DHP_model_B.Switch3_n = ((uint8_T)KDHP_BMSMODEERRSPDLIMIT);
    DHP_model_B.Switch4_ot = ((uint8_T)KDHP_BMSMODEERRPOWERLIMIT_PCT);
  } else {
    if (DHP_model_B.Switch6_p) {
      /* Switch: '<S2095>/Switch20' incorporates:
       *  Constant: '<S2090>/KDHP_Handle_Response_Bits'
       *  Constant: '<S2095>/Constant24'
       *  Switch: '<S2094>/Switch11'
       *  Switch: '<S2095>/Switch14'
       */
      if (rtb_Switch13_j) {
        DHP_model_B.Switch2_gf = ((uint16_T)KDHP_BMSMODEERRHANDLERESPONSEBITS);
      } else {
        DHP_model_B.Switch2_gf = KDHP_preResponseBits_Grads;
      }

      /* End of Switch: '<S2095>/Switch20' */

      /* Switch: '<S2095>/Switch15' incorporates:
       *  Constant: '<S2090>/KDHP_Spd_Limit'
       *  Constant: '<S2095>/Constant26'
       *  Logic: '<S2095>/Logical Operator11'
       *  Switch: '<S2094>/Switch13'
       */
      if (DHP_model_B.Switch6_p && rtb_Switch13_j) {
        DHP_model_B.Switch3_n = ((uint8_T)KDHP_BMSMODEERRSPDLIMIT);
      } else {
        DHP_model_B.Switch3_n = 200U;
      }

      /* End of Switch: '<S2095>/Switch15' */
    } else {
      /* Switch: '<S2094>/Switch11' incorporates:
       *  Constant: '<S2094>/Constant1'
       */
      DHP_model_B.Switch2_gf = 0U;

      /* Switch: '<S2094>/Switch13' incorporates:
       *  Constant: '<S2094>/Constant2'
       */
      DHP_model_B.Switch3_n = 200U;
    }

    /* Switch: '<S2095>/Switch16' incorporates:
     *  Constant: '<S2094>/Constant3'
     *  Switch: '<S2094>/Switch15'
     */
    if (DHP_model_B.Switch6_p) {
      /* Switch: '<S2095>/Switch19' incorporates:
       *  Constant: '<S2090>/KDHP_Pwr_limit'
       *  Constant: '<S2095>/Constant25'
       *  Logic: '<S2095>/Logical Operator12'
       *  Logic: '<S2095>/Logical Operator13'
       *  Logic: '<S2095>/Logical Operator14'
       *  Logic: '<S2095>/Logical Operator15'
       *  Switch: '<S2095>/Switch17'
       *  Switch: '<S2095>/Switch18'
       */
      if (rtb_Switch13_j) {
        DHP_model_B.Switch4_ot = ((uint8_T)KDHP_BMSMODEERRPOWERLIMIT_PCT);
      } else if ((!DHP_model_B.DHP_systemtick_Timer1_ff.RelationalOperator) &&
                 rtb_Switch11_e) {
        /* Switch: '<S2095>/Switch18' incorporates:
         *  Constant: '<S2095>/Constant29'
         */
        DHP_model_B.Switch4_ot = KDHP_PwrLimit2_basisTime;
      } else if ((!DHP_model_B.DHP_systemtick_Timer_ot.RelationalOperator) &&
                 rtb_Switch9) {
        /* Switch: '<S2095>/Switch17' incorporates:
         *  Constant: '<S2095>/Constant28'
         *  Switch: '<S2095>/Switch18'
         */
        DHP_model_B.Switch4_ot = KDHP_PwrLimit1_basisTime;
      } else {
        DHP_model_B.Switch4_ot = 100U;
      }

      /* End of Switch: '<S2095>/Switch19' */
    } else {
      DHP_model_B.Switch4_ot = 100U;
    }

    /* End of Switch: '<S2095>/Switch16' */
  }

  /* End of Switch: '<S2094>/Switch2' */

  /* Switch: '<S2093>/Switch2' incorporates:
   *  Constant: '<S2090>/Constant2'
   *  Constant: '<S2090>/KDHP_Fault_Level'
   *  Constant: '<S2093>/Constant'
   *  Logic: '<S2093>/Logical Operator'
   */
  if (KDHP_BMSModeErrActionSwitchOpen_flg && DHP_model_B.Switch9_n) {
    DHP_model_B.Switch2_fx = ((uint8_T)KDHP_BMSMODEERRFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_fx = 0U;
  }

  /* End of Switch: '<S2093>/Switch2' */

  /* Update for Delay: '<S2093>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_i = rtb_Switch10_p;

  /* Update for Delay: '<S2095>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_le = rtb_Switch9;

  /* Update for Delay: '<S2095>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_nz = DHP_model_B.Switch6_p;

  /* Update for Delay: '<S2094>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_a = rtb_Switch50;

  /* Update for Delay: '<S2095>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_d = rtb_Switch11_e;

  /* Update for Delay: '<S2095>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_l =
    DHP_model_B.DHP_systemtick_Timer_ot.RelationalOperator;

  /* Update for Delay: '<S2095>/Delay5' */
  DHP_model_DW.Delay5_DSTATE_e =
    DHP_model_B.DHP_systemtick_Timer1_ff.RelationalOperator;

  /* Update for Delay: '<S2095>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_l = rtb_Switch13_j;

  /* Update for Delay: '<S2094>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_c = rtb_LogicalOperator1;
}

/* Output and update for atomic system: '<S1968>/DCDCModeErr' */
void DHP_model_DCDCModeErr(void)
{
  /* Outputs for Atomic SubSystem: '<S2099>/Fault_Valid_RT' */

  /* Constant: '<S2091>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2091>/Constant2'
   *  Constant: '<S2091>/KDHP_Fault_Level'
   *  Constant: '<S2091>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2091>/KDHP_Pwr_limit'
   *  Constant: '<S2091>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_DCDCModErrInstFlt_flg,
    KDHP_DCDCMODEERRALLOWRECOVERY_FLG, ((uint8_T)KDHP_DCDCMODEERRFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_DCDCMODEERRSPDLIMIT), ((uint8_T)
    KDHP_DCDCMODEERRPOWERLIMIT_PCT), ((uint16_T)
    KDHP_DCDCMODEERRHANDLERESPONSEBITS), KDHP_DCDCModeErrActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_mn, &DHP_model_DW.Fault_Valid_RT_mn);

  /* End of Outputs for SubSystem: '<S2099>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1968>/MCUModeErr' */
void DHP_model_MCUModeErr(void)
{
  /* Outputs for Atomic SubSystem: '<S2102>/Fault_Valid_RT' */

  /* Constant: '<S2092>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2092>/Constant2'
   *  Constant: '<S2092>/KDHP_Fault_Level'
   *  Constant: '<S2092>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2092>/KDHP_Pwr_limit'
   *  Constant: '<S2092>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUModErrInstFlt_flg,
    KDHP_MCUMODEERRALLOWRECOVERY_FLG, ((uint8_T)KDHP_MCUMODEERRFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_MCUMODEERRSPDLIMIT), ((uint8_T)KDHP_MCUMODEERRPOWERLIMIT_PCT),
    ((uint16_T)KDHP_MCUMODEERRHANDLERESPONSEBITS),
    KDHP_MCUModeErrActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_a4,
    &DHP_model_DW.Fault_Valid_RT_a4);

  /* End of Outputs for SubSystem: '<S2102>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/ModeErr_Fault' */
void DHP_model_ModeErr_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1968>/BMSModeErr' */
  DHP_model_BMSModeErr();

  /* End of Outputs for SubSystem: '<S1968>/BMSModeErr' */

  /* Outputs for Atomic SubSystem: '<S1968>/DCDCModeErr' */
  DHP_model_DCDCModeErr();

  /* End of Outputs for SubSystem: '<S1968>/DCDCModeErr' */

  /* Outputs for Atomic SubSystem: '<S1968>/MCUModeErr' */
  DHP_model_MCUModeErr();

  /* End of Outputs for SubSystem: '<S1968>/MCUModeErr' */
}

/* Output and update for atomic system: '<S1969>/ObcFlt2' */
void DHP_model_ObcFlt2(void)
{
  /* Outputs for Atomic SubSystem: '<S2107>/Fault_Valid_RT' */

  /* Constant: '<S2105>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2105>/Constant2'
   *  Constant: '<S2105>/KDHP_Fault_Level'
   *  Constant: '<S2105>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2105>/KDHP_Pwr_limit'
   *  Constant: '<S2105>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ObcFlt2_flg,
    KDHP_OBCFLT2ALLOWRECOVERY_FLG, ((uint8_T)KDHP_OBCFLT2FAULTLEVEL_ENUM),
    ((uint8_T)KDHP_OBCFLT2SPDLIMIT), ((uint8_T)KDHP_OBCFLT2POWERLIMIT_PCT),
    ((uint16_T)KDHP_OBCFLT2HANDLERESPONSEBITS), KDHP_ObcFlt2ActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_mp, &DHP_model_DW.Fault_Valid_RT_mp);

  /* End of Outputs for SubSystem: '<S2107>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1969>/ObcFlt3' */
void DHP_model_ObcFlt3(void)
{
  /* Outputs for Atomic SubSystem: '<S2110>/Fault_Valid_RT' */

  /* Constant: '<S2106>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2106>/Constant2'
   *  Constant: '<S2106>/KDHP_Fault_Level'
   *  Constant: '<S2106>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2106>/KDHP_Pwr_limit'
   *  Constant: '<S2106>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_ObcFlt3_flg,
    KDHP_OBCFLT3ALLOWRECOVERY_FLG, ((uint8_T)KDHP_OBCFLT3FAULTLEVEL_ENUM),
    ((uint8_T)KDHP_OBCFLT3SPDLIMIT), ((uint8_T)KDHP_OBCFLT3POWERLIMIT_PCT),
    ((uint16_T)KDHP_OBCFLT3HANDLERESPONSEBITS), KDHP_ObcFlt3ActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_bzj, &DHP_model_DW.Fault_Valid_RT_bzj);

  /* End of Outputs for SubSystem: '<S2110>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/OBC_Fault' */
void DHP_model_OBC_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1969>/ObcFlt2' */
  DHP_model_ObcFlt2();

  /* End of Outputs for SubSystem: '<S1969>/ObcFlt2' */

  /* Outputs for Atomic SubSystem: '<S1969>/ObcFlt3' */
  DHP_model_ObcFlt3();

  /* End of Outputs for SubSystem: '<S1969>/ObcFlt3' */
}

/* Output and update for atomic system: '<S1970>/PEPSFailed' */
void DHP_model_PEPSFailed(void)
{
  /* Outputs for Atomic SubSystem: '<S2114>/Fault_Valid_RT' */

  /* Constant: '<S2113>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2113>/Constant2'
   *  Constant: '<S2113>/KDHP_Fault_Level'
   *  Constant: '<S2113>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2113>/KDHP_Pwr_limit'
   *  Constant: '<S2113>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_PEPSFailedInstFlt_flg,
    KDHP_PEPSFAILEDALLOWRECOVERY_FLG, ((uint8_T)KDHP_PEPSFAILEDFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_PEPSFAILEDSPDLIMIT), ((uint8_T)KDHP_PEPSFAILEDPOWERLIMIT_PCT),
    ((uint16_T)KDHP_PEPSFAILEDHANDLERESPONSEBITS),
    KDHP_PEPSFailedActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_hm,
    &DHP_model_DW.Fault_Valid_RT_hm);

  /* End of Outputs for SubSystem: '<S2114>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/PEPSFailed_Fault' */
void DHP_model_PEPSFailed_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1970>/PEPSFailed' */
  DHP_model_PEPSFailed();

  /* End of Outputs for SubSystem: '<S1970>/PEPSFailed' */
}

/* Output and update for atomic system: '<S1971>/ICMVehSpdChkInvalid' */
void DHP_model_ICMVehSpdChkInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S2120>/Fault_Valid_RT' */

  /* Constant: '<S2117>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2117>/Constant2'
   *  Constant: '<S2117>/KDHP_Fault_Level'
   *  Constant: '<S2117>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2117>/KDHP_Pwr_limit'
   *  Constant: '<S2117>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    DHP_model_B.VINP_ICM_VehSpdChkInvalidFlt_flg_m,
    KDHP_ICMVEHSPDCHKINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_ICMVEHSPDCHKINVALIDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_ICMVEHSPDCHKINVALIDSPDLIMIT), ((uint8_T)
    KDHP_ICMVEHSPDCHKINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_ICMVEHSPDCHKINVALIDHANDLERESPONSEBITS),
    KDHP_ICMVehSpdChkInvalidActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_nk,
    &DHP_model_DW.Fault_Valid_RT_nk);

  /* End of Outputs for SubSystem: '<S2120>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1971>/SCRActualSpeedLow' */
void DHP_model_SCRActualSpeedLow(void)
{
  /* Outputs for Atomic SubSystem: '<S2123>/Fault_Valid_RT' */

  /* Constant: '<S2118>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2118>/Constant2'
   *  Constant: '<S2118>/KDHP_Fault_Level'
   *  Constant: '<S2118>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2118>/KDHP_Pwr_limit'
   *  Constant: '<S2118>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.Compare_c,
    KDHP_SCRACTUALSPEEDLOWALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_SCRACTUALSPEEDLOWFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_SCRACTUALSPEEDLOWSPDLIMIT), ((uint8_T)
    KDHP_SCRACTUALSPEEDLOWPOWERLIMIT_PCT), ((uint16_T)
    KDHP_SCRACTUALSPEEDLOWHANDLERESPONSEBITS),
    KDHP_SCRActualSpeedLowActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ci,
    &DHP_model_DW.Fault_Valid_RT_ci);

  /* End of Outputs for SubSystem: '<S2123>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1971>/SCRTargetSpdUnfollowed' */
void DHP_model_SCRTargetSpdUnfollowed(void)
{
  /* Outputs for Atomic SubSystem: '<S2126>/Fault_Valid_RT' */

  /* Constant: '<S2119>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2119>/Constant2'
   *  Constant: '<S2119>/KDHP_Fault_Level'
   *  Constant: '<S2119>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2119>/KDHP_Pwr_limit'
   *  Constant: '<S2119>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, DHP_model_B.Compare_d,
    KDHP_SCRTARGETSPDUNFOLLOWEDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_SCRTARGETSPDUNFOLLOWEDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_SCRTARGETSPDUNFOLLOWEDSPDLIMIT), ((uint8_T)
    KDHP_SCRTARGETSPDUNFOLLOWEDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_SCRTARGETSPDUNFOLLOWEDHANDLERESPONSEBITS),
    KDHP_SCRTargetSpdUnfollowedActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_cii, &DHP_model_DW.Fault_Valid_RT_cii);

  /* End of Outputs for SubSystem: '<S2126>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/SCR_Fault' */
void DHP_model_SCR_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1971>/ICMVehSpdChkInvalid' */
  DHP_model_ICMVehSpdChkInvalid();

  /* End of Outputs for SubSystem: '<S1971>/ICMVehSpdChkInvalid' */

  /* Outputs for Atomic SubSystem: '<S1971>/SCRActualSpeedLow' */
  DHP_model_SCRActualSpeedLow();

  /* End of Outputs for SubSystem: '<S1971>/SCRActualSpeedLow' */

  /* Outputs for Atomic SubSystem: '<S1971>/SCRTargetSpdUnfollowed' */
  DHP_model_SCRTargetSpdUnfollowed();

  /* End of Outputs for SubSystem: '<S1971>/SCRTargetSpdUnfollowed' */
}

/* Output and update for atomic system: '<S1972>/TMSReqInvalid' */
void DHP_model_TMSReqInvalid(void)
{
  /* Outputs for Atomic SubSystem: '<S2130>/Fault_Valid_RT' */

  /* Constant: '<S2129>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2129>/Constant2'
   *  Constant: '<S2129>/KDHP_Fault_Level'
   *  Constant: '<S2129>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2129>/KDHP_Pwr_limit'
   *  Constant: '<S2129>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_TMSReqInvalid_flg,
    KDHP_TMSREQINVALIDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_TMSREQINVALIDFAULTLEVEL_ENUM), ((uint8_T)KDHP_TMSREQINVALIDSPDLIMIT),
    ((uint8_T)KDHP_TMSREQINVALIDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_TMSREQINVALIDHANDLERESPONSEBITS),
    KDHP_TMSReqInvalidActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_ke,
    &DHP_model_DW.Fault_Valid_RT_ke);

  /* End of Outputs for SubSystem: '<S2130>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S15>/TMSReqInvalid' */
void DHP_model_TMSReqInvalid_n(void)
{
  /* Outputs for Atomic SubSystem: '<S1972>/TMSReqInvalid' */
  DHP_model_TMSReqInvalid();

  /* End of Outputs for SubSystem: '<S1972>/TMSReqInvalid' */
}

/* Output and update for atomic system: '<S1973>/VACHzFlt1' */
void DHP_model_VACHzFlt1(void)
{
  /* Outputs for Atomic SubSystem: '<S2136>/Fault_Valid_Time' */

  /* Constant: '<S2133>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2133>/Constant2'
   *  Constant: '<S2133>/KDHP_Allow_Recover'
   *  Constant: '<S2133>/KDHP_Clear_Time'
   *  Constant: '<S2133>/KDHP_Fault_Level'
   *  Constant: '<S2133>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2133>/KDHP_Pwr_limit'
   *  Constant: '<S2133>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VacHzInstFlt1_flg, ((uint16_T)KDHP_VACHZFLT1CONFIRMTIME_MS), ((uint16_T)
    KDHP_VACHZFLT1CLEARTIME_MS), KDHP_VACHZFLT1ALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_VACHZFLT1FAULTLEVEL_ENUM), ((uint8_T)KDHP_VACHZFLT1SPDLIMIT), ((uint8_T)
    KDHP_VACHZFLT1POWERLIMIT_PCT), ((uint16_T)KDHP_VACHZFLT1HANDLERESPONSEBITS),
    KDHP_VACHzFlt1ActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_im,
    &DHP_model_DW.Fault_Valid_Time_im);

  /* End of Outputs for SubSystem: '<S2136>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1973>/VACHzFlt2' */
void DHP_model_VACHzFlt2(void)
{
  /* Outputs for Atomic SubSystem: '<S2141>/Fault_Valid_Time' */

  /* Constant: '<S2134>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2134>/Constant2'
   *  Constant: '<S2134>/KDHP_Allow_Recover'
   *  Constant: '<S2134>/KDHP_Clear_Time'
   *  Constant: '<S2134>/KDHP_Fault_Level'
   *  Constant: '<S2134>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2134>/KDHP_Pwr_limit'
   *  Constant: '<S2134>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VacHzInstFlt2_flg, ((uint16_T)KDHP_VACHZFLT2CONFIRMTIME_MS), ((uint16_T)
    KDHP_VACHZFLT2CLEARTIME_MS), KDHP_VACHZFLT2ALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_VACHZFLT2FAULTLEVEL_ENUM), ((uint8_T)KDHP_VACHZFLT2SPDLIMIT), ((uint8_T)
    KDHP_VACHZFLT2POWERLIMIT_PCT), ((uint16_T)KDHP_VACHZFLT2HANDLERESPONSEBITS),
    KDHP_VACHzFlt2ActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_k5,
    &DHP_model_DW.Fault_Valid_Time_k5);

  /* End of Outputs for SubSystem: '<S2141>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1973>/VacPumpHardwire' */
void DHP_model_VacPumpHardwire(void)
{
  /* Outputs for Atomic SubSystem: '<S2146>/Fault_Valid_Time' */

  /* Constant: '<S2135>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2135>/Constant2'
   *  Constant: '<S2135>/KDHP_Allow_Recover'
   *  Constant: '<S2135>/KDHP_Clear_Time'
   *  Constant: '<S2135>/KDHP_Fault_Level'
   *  Constant: '<S2135>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2135>/KDHP_Pwr_limit'
   *  Constant: '<S2135>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_VacPumpHardwireInstFlt_flg, ((uint16_T)
    KDHP_VACPUMPHARDWIRECONFIRMTIME_MS), ((uint16_T)
    KDHP_VACPUMPHARDWIRECLEARTIME_MS), KDHP_VACPUMPHARDWIREALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_VACPUMPHARDWIREFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_VACPUMPHARDWIRESPDLIMIT), ((uint8_T)KDHP_VACPUMPHARDWIREPOWERLIMIT_PCT),
    ((uint16_T)KDHP_VACPUMPHARDWIREHANDLERESPONSEBITS),
    KDHP_VacPumpHardwireActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_kh,
    &DHP_model_DW.Fault_Valid_Time_kh);

  /* End of Outputs for SubSystem: '<S2146>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S15>/VAC_Fault' */
void DHP_model_VAC_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1973>/VACHzFlt1' */
  DHP_model_VACHzFlt1();

  /* End of Outputs for SubSystem: '<S1973>/VACHzFlt1' */

  /* Outputs for Atomic SubSystem: '<S1973>/VACHzFlt2' */
  DHP_model_VACHzFlt2();

  /* End of Outputs for SubSystem: '<S1973>/VACHzFlt2' */

  /* Outputs for Atomic SubSystem: '<S1973>/VacPumpHardwire' */
  DHP_model_VacPumpHardwire();

  /* End of Outputs for SubSystem: '<S1973>/VacPumpHardwire' */
}

/* Output and update for atomic system: '<S1974>/WaterPumpFlt1' */
void DHP_model_WaterPumpFlt1(void)
{
  /* Outputs for Atomic SubSystem: '<S2155>/Fault_Valid_Time' */

  /* Constant: '<S2151>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2151>/Constant2'
   *  Constant: '<S2151>/KDHP_Allow_Recover'
   *  Constant: '<S2151>/KDHP_Clear_Time'
   *  Constant: '<S2151>/KDHP_Fault_Level'
   *  Constant: '<S2151>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2151>/KDHP_Pwr_limit'
   *  Constant: '<S2151>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_WaterPump_InstFlt1_flg, ((uint16_T)KDHP_WATERPUMPFLT1CONFIRMTIME_MS),
    ((uint16_T)KDHP_WATERPUMPFLT1CLEARTIME_MS),
    KDHP_WATERPUMPFLT1ALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_WATERPUMPFLT1FAULTLEVEL_ENUM), ((uint8_T)KDHP_WATERPUMPFLT1SPDLIMIT),
    ((uint8_T)KDHP_WATERPUMPFLT1POWERLIMIT_PCT), ((uint16_T)
    KDHP_WATERPUMPFLT1HANDLERESPONSEBITS),
    KDHP_WaterPumpFlt1ActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_pv,
    &DHP_model_DW.Fault_Valid_Time_pv);

  /* End of Outputs for SubSystem: '<S2155>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1974>/WaterPumpFlt2' */
void DHP_model_WaterPumpFlt2(void)
{
  /* Outputs for Atomic SubSystem: '<S2160>/Fault_Valid_Time' */

  /* Constant: '<S2152>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2152>/Constant2'
   *  Constant: '<S2152>/KDHP_Allow_Recover'
   *  Constant: '<S2152>/KDHP_Clear_Time'
   *  Constant: '<S2152>/KDHP_Fault_Level'
   *  Constant: '<S2152>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2152>/KDHP_Pwr_limit'
   *  Constant: '<S2152>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_WaterPump_InstFlt2_flg, ((uint16_T)KDHP_WATERPUMPFLT2CONFIRMTIME_MS),
    ((uint16_T)KDHP_WATERPUMPFLT2CLEARTIME_MS),
    KDHP_WATERPUMPFLT2ALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_WATERPUMPFLT2FAULTLEVEL_ENUM), ((uint8_T)KDHP_WATERPUMPFLT2SPDLIMIT),
    ((uint8_T)KDHP_WATERPUMPFLT2POWERLIMIT_PCT), ((uint16_T)
    KDHP_WATERPUMPFLT2HANDLERESPONSEBITS),
    KDHP_WaterPumpFlt2ActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_nj,
    &DHP_model_DW.Fault_Valid_Time_nj);

  /* End of Outputs for SubSystem: '<S2160>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1974>/WaterPumpHardwire' */
void DHP_model_WaterPumpHardwire(void)
{
  /* Outputs for Atomic SubSystem: '<S2165>/Fault_Valid_Time' */

  /* Constant: '<S2153>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2153>/Constant2'
   *  Constant: '<S2153>/KDHP_Allow_Recover'
   *  Constant: '<S2153>/KDHP_Clear_Time'
   *  Constant: '<S2153>/KDHP_Fault_Level'
   *  Constant: '<S2153>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2153>/KDHP_Pwr_limit'
   *  Constant: '<S2153>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_WaterPumpHardwireInstFlt_flg, ((uint16_T)
    KDHP_WATERPUMPHARDWIRECONFIRMTIME_MS), ((uint16_T)
    KDHP_WATERPUMPHARDWIRECLEARTIME_MS), KDHP_WATERPUMPHARDWIREALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_WATERPUMPHARDWIREFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_WATERPUMPHARDWIRESPDLIMIT), ((uint8_T)
    KDHP_WATERPUMPHARDWIREPOWERLIMIT_PCT), ((uint16_T)
    KDHP_WATERPUMPHARDWIREHANDLERESPONSEBITS),
    KDHP_WaterPumpHardwireActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_jc,
    &DHP_model_DW.Fault_Valid_Time_jc);

  /* End of Outputs for SubSystem: '<S2165>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1974>/WaterPumpPWM' */
void DHP_model_WaterPumpPWM(void)
{
  /* Outputs for Atomic SubSystem: '<S2170>/Fault_Valid_Time' */

  /* Constant: '<S2154>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2154>/Constant2'
   *  Constant: '<S2154>/KDHP_Allow_Recover'
   *  Constant: '<S2154>/KDHP_Clear_Time'
   *  Constant: '<S2154>/KDHP_Fault_Level'
   *  Constant: '<S2154>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2154>/KDHP_Pwr_limit'
   *  Constant: '<S2154>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_WaterPumpPWMInstFlt_flg, ((uint16_T)KDHP_WATERPUMPPWMCONFIRMTIME_MS),
    ((uint16_T)KDHP_WATERPUMPPWMCLEARTIME_MS),
    KDHP_WATERPUMPPWMALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_WATERPUMPPWMFAULTLEVEL_ENUM), ((uint8_T)KDHP_WATERPUMPPWMSPDLIMIT),
    ((uint8_T)KDHP_WATERPUMPPWMPOWERLIMIT_PCT), ((uint16_T)
    KDHP_WATERPUMPPWMHANDLERESPONSEBITS), KDHP_WaterPumpPWMActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_j4, &DHP_model_DW.Fault_Valid_Time_j4);

  /* End of Outputs for SubSystem: '<S2170>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S15>/WaterPump_Fault' */
void DHP_model_WaterPump_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1974>/WaterPumpFlt1' */
  DHP_model_WaterPumpFlt1();

  /* End of Outputs for SubSystem: '<S1974>/WaterPumpFlt1' */

  /* Outputs for Atomic SubSystem: '<S1974>/WaterPumpFlt2' */
  DHP_model_WaterPumpFlt2();

  /* End of Outputs for SubSystem: '<S1974>/WaterPumpFlt2' */

  /* Outputs for Atomic SubSystem: '<S1974>/WaterPumpHardwire' */
  DHP_model_WaterPumpHardwire();

  /* End of Outputs for SubSystem: '<S1974>/WaterPumpHardwire' */

  /* Outputs for Atomic SubSystem: '<S1974>/WaterPumpPWM' */
  DHP_model_WaterPumpPWM();

  /* End of Outputs for SubSystem: '<S1974>/WaterPumpPWM' */
}

/* Output and update for function-call system: '<S4>/VehOtherDeviceErrValid' */
void DHP_model_VehOtherDeviceErrValid(void)
{
  /* Outputs for Atomic SubSystem: '<S15>/ABS_TQMWork_Fault' */
  DHP_model_ABS_TQMWork_Fault();

  /* End of Outputs for SubSystem: '<S15>/ABS_TQMWork_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/BattEnergyTooLow' */
  DHP_model_BattEnergyTooLow_j();

  /* End of Outputs for SubSystem: '<S15>/BattEnergyTooLow' */

  /* Outputs for Atomic SubSystem: '<S15>/DCChrgPortOverT_Fault' */
  DHP_model_DCChrgPortOverT_Fault();

  /* End of Outputs for SubSystem: '<S15>/DCChrgPortOverT_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/DCDC_Fault' */
  DHP_model_DCDC_Fault();

  /* End of Outputs for SubSystem: '<S15>/DCDC_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/EPSWorkErr_Fault' */
  DHP_model_EPSWorkErr_Fault();

  /* End of Outputs for SubSystem: '<S15>/EPSWorkErr_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/ESCL_Fault' */
  DHP_model_ESCL_Fault();

  /* End of Outputs for SubSystem: '<S15>/ESCL_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/IChrgError' */
  DHP_model_IChrgError_g();

  /* End of Outputs for SubSystem: '<S15>/IChrgError' */

  /* Outputs for Atomic SubSystem: '<S15>/ModeErr_Fault' */
  DHP_model_ModeErr_Fault();

  /* End of Outputs for SubSystem: '<S15>/ModeErr_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/OBC_Fault' */
  DHP_model_OBC_Fault();

  /* End of Outputs for SubSystem: '<S15>/OBC_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/PEPSFailed_Fault' */
  DHP_model_PEPSFailed_Fault();

  /* End of Outputs for SubSystem: '<S15>/PEPSFailed_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/SCR_Fault' */
  DHP_model_SCR_Fault();

  /* End of Outputs for SubSystem: '<S15>/SCR_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/TMSReqInvalid' */
  DHP_model_TMSReqInvalid_n();

  /* End of Outputs for SubSystem: '<S15>/TMSReqInvalid' */

  /* Outputs for Atomic SubSystem: '<S15>/VAC_Fault' */
  DHP_model_VAC_Fault();

  /* End of Outputs for SubSystem: '<S15>/VAC_Fault' */

  /* Outputs for Atomic SubSystem: '<S15>/WaterPump_Fault' */
  DHP_model_WaterPump_Fault();

  /* End of Outputs for SubSystem: '<S15>/WaterPump_Fault' */
}

/* Output and update for atomic system: '<S1750>/MCUCANBusOff' */
void DHP_model_MCUCANBusOff(void)
{
  /* Outputs for Atomic SubSystem: '<S1797>/Fault_Valid_RT' */

  /* Constant: '<S1751>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1751>/Constant2'
   *  Constant: '<S1751>/KDHP_Fault_Level'
   *  Constant: '<S1751>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1751>/KDHP_Pwr_limit'
   *  Constant: '<S1751>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUCANBusOffInstFlt_Flg,
    KDHP_MCUCANBUSOFFALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUCANBUSOFFFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUCANBUSOFFSPDLIMIT),
    ((uint8_T)KDHP_MCUCANBUSOFFPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUCANBUSOFFHANDLERESPONSEBITS), KDHP_MCUCANBusOffActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_gk, &DHP_model_DW.Fault_Valid_RT_gk);

  /* End of Outputs for SubSystem: '<S1797>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUCANCom' */
void DHP_model_MCUCANCom(void)
{
  boolean_T rtb_Switch1;
  boolean_T rtb_LogicalOperator2_aj;
  boolean_T rtb_LogicalOperator4_j2;
  boolean_T rtb_Switch10_jd;
  boolean_T rtb_Switch7_jw;

  /* Switch: '<S1800>/Switch10' incorporates:
   *  Constant: '<S1800>/Constant12'
   *  Constant: '<S1800>/Constant13'
   *  Delay: '<S1800>/Delay6'
   *  Switch: '<S1800>/Switch6'
   *  Switch: '<S1800>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_jd = false;
    DHP_model_B.Switch9_i = false;
  } else {
    rtb_Switch10_jd = (VDHP_MCUCANComInstFlt_Flg ||
                       DHP_model_DW.Delay6_DSTATE_jr);

    /* Switch: '<S1800>/Switch8' incorporates:
     *  Constant: '<S1752>/KDHP_Allow_Recover'
     *  Delay: '<S1800>/Delay6'
     *  Switch: '<S1800>/Switch6'
     */
    if (KDHP_MCUCANCOMALLOWRECOVERY_FLG) {
      DHP_model_B.Switch9_i = VDHP_MCUCANComInstFlt_Flg;
    } else {
      DHP_model_B.Switch9_i = rtb_Switch10_jd;
    }

    /* End of Switch: '<S1800>/Switch8' */
  }

  /* End of Switch: '<S1800>/Switch10' */

  /* Switch: '<S1801>/Switch1' incorporates:
   *  Constant: '<S1752>/Constant2'
   */
  rtb_Switch1 = (KDHP_MCUCANComActionSwitchOpen_flg && DHP_model_B.Switch9_i);

  /* Switch: '<S1801>/Switch4' incorporates:
   *  Constant: '<S1801>/Constant3'
   */
  if (rtb_Switch1) {
    /* Switch: '<S1801>/Switch5' incorporates:
     *  Constant: '<S1801>/Constant5'
     *  Constant: '<S1801>/Constant8'
     *  Constant: '<S1801>/Constant9'
     *  Delay: '<S1801>/Delay1'
     *  Logic: '<S1801>/Logical Operator'
     *  Logic: '<S1801>/Logical Operator1'
     *  RelationalOperator: '<S1801>/Relational Operator3'
     */
    if ((DHP_model_B.Gain9 > KDHP_GradsSpeed1) && (!DHP_model_DW.Delay1_DSTATE_m))
    {
      DHP_model_B.Switch4_n = KDHP_PwrLimit1_basisSpd;
    } else {
      DHP_model_B.Switch4_n = KDHP_PwrLimit2_basisSpd;
    }

    /* End of Switch: '<S1801>/Switch5' */
  } else {
    DHP_model_B.Switch4_n = 100U;
  }

  /* End of Switch: '<S1801>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S1801>/DHP_systemtick_Timer' */

  /* RelationalOperator: '<S1801>/Relational Operator' incorporates:
   *  Constant: '<S1801>/Constant4'
   *  Constant: '<S1801>/Constant6'
   */
  DHP_model_DHP_systemtick_Timer_c(DHP_model_B.Switch4_n ==
    KDHP_PwrLimit1_basisSpd, VDHP_deltaSystemTick_ms,
    KDHP_WaitMoreForFltSecond_ms, &DHP_model_B.DHP_systemtick_Timer_gp,
    &DHP_model_DW.DHP_systemtick_Timer_gp);

  /* End of Outputs for SubSystem: '<S1801>/DHP_systemtick_Timer' */

  /* Logic: '<S1801>/Logical Operator2' */
  rtb_LogicalOperator2_aj = !rtb_Switch1;

  /* Logic: '<S1801>/Logical Operator4' incorporates:
   *  Constant: '<S1801>/Constant10'
   *  Constant: '<S1801>/Constant11'
   *  RelationalOperator: '<S1801>/Relational Operator1'
   *  RelationalOperator: '<S1801>/Relational Operator2'
   */
  rtb_LogicalOperator4_j2 = ((DHP_model_B.Switch4_n == KDHP_PwrLimit2_basisSpd) &&
    rtb_Switch1 && (DHP_model_B.Gain9 < KDHP_SpeedLimitThreshold_Grads));

  /* Switch: '<S1801>/Switch2' incorporates:
   *  Constant: '<S1752>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1801>/Constant1'
   */
  if (rtb_Switch1) {
    DHP_model_B.Switch2_or = ((uint16_T)KDHP_MCUCANCOMHANDLERESPONSEBITS);
  } else {
    DHP_model_B.Switch2_or = 0U;
  }

  /* End of Switch: '<S1801>/Switch2' */

  /* Switch: '<S1801>/Switch6' incorporates:
   *  Constant: '<S1801>/Constant14'
   *  Delay: '<S1801>/Delay2'
   *  Delay: '<S1801>/Delay3'
   *  Logic: '<S1801>/Logical Operator5'
   *  Logic: '<S1801>/Logical Operator6'
   *  Logic: '<S1801>/Logical Operator7'
   *  Logic: '<S1801>/Logical Operator8'
   *  Logic: '<S1801>/Logical Operator9'
   */
  if (VDHP_NMSleepInd_flg || (!rtb_Switch1)) {
    rtb_Switch1 = false;
  } else {
    rtb_Switch1 = (DHP_model_DW.Delay3_DSTATE_hv ||
                   ((!DHP_model_DW.Delay2_DSTATE_fn) && rtb_LogicalOperator4_j2));
  }

  /* End of Switch: '<S1801>/Switch6' */

  /* Switch: '<S1801>/Switch3' incorporates:
   *  Constant: '<S1752>/KDHP_Spd_Limit'
   *  Constant: '<S1801>/Constant2'
   */
  if (rtb_Switch1) {
    DHP_model_B.Switch3_m = ((uint8_T)KDHP_MCUCANCOMSPDLIMIT);
  } else {
    DHP_model_B.Switch3_m = 200U;
  }

  /* End of Switch: '<S1801>/Switch3' */

  /* Switch: '<S1801>/Switch7' incorporates:
   *  Constant: '<S1801>/Constant7'
   *  Delay: '<S1801>/Delay4'
   *  Logic: '<S1801>/Logical Operator3'
   *  Switch: '<S1801>/Switch10'
   */
  if (rtb_LogicalOperator2_aj || VDHP_NMSleepInd_flg) {
    rtb_Switch7_jw = false;
  } else {
    rtb_Switch7_jw = (DHP_model_B.DHP_systemtick_Timer_gp.RelationalOperator ||
                      DHP_model_DW.Delay4_DSTATE_e);
  }

  /* End of Switch: '<S1801>/Switch7' */

  /* Switch: '<S1801>/Switch9' incorporates:
   *  Switch: '<S1801>/Switch8'
   */
  if (VDHP_NMSleepInd_flg) {
    /* Update for Delay: '<S1801>/Delay1' incorporates:
     *  Constant: '<S1801>/Constant12'
     */
    DHP_model_DW.Delay1_DSTATE_m = false;
  } else if (rtb_LogicalOperator2_aj) {
    /* Switch: '<S1801>/Switch8' incorporates:
     *  Update for Delay: '<S1801>/Delay1'
     */
    DHP_model_DW.Delay1_DSTATE_m =
      DHP_model_B.DHP_systemtick_Timer_gp.RelationalOperator;
  } else {
    /* Update for Delay: '<S1801>/Delay1' incorporates:
     *  Switch: '<S1801>/Switch8'
     */
    DHP_model_DW.Delay1_DSTATE_m = rtb_Switch7_jw;
  }

  /* End of Switch: '<S1801>/Switch9' */

  /* Switch: '<S1800>/Switch2' incorporates:
   *  Constant: '<S1752>/Constant2'
   *  Constant: '<S1752>/KDHP_Fault_Level'
   *  Constant: '<S1800>/Constant'
   *  Logic: '<S1800>/Logical Operator'
   */
  if (KDHP_MCUCANComActionSwitchOpen_flg && DHP_model_B.Switch9_i) {
    DHP_model_B.Switch2_fe = ((uint8_T)KDHP_MCUCANCOMFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_fe = 0U;
  }

  /* End of Switch: '<S1800>/Switch2' */

  /* Update for Delay: '<S1800>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_jr = rtb_Switch10_jd;

  /* Update for Delay: '<S1801>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_fn = rtb_LogicalOperator4_j2;

  /* Update for Delay: '<S1801>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_hv = rtb_Switch1;

  /* Update for Delay: '<S1801>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_e = rtb_Switch7_jw;
}

/* Output and update for atomic system: '<S1750>/MCUChipPowerFlt' */
void DHP_model_MCUChipPowerFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1803>/Fault_Valid_RT' */

  /* Constant: '<S1753>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1753>/Constant2'
   *  Constant: '<S1753>/KDHP_Fault_Level'
   *  Constant: '<S1753>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1753>/KDHP_Pwr_limit'
   *  Constant: '<S1753>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUChipPowerInstFlt_Flg,
    KDHP_MCUCHIPPOWERFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUCHIPPOWERFLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUCHIPPOWERFLTSPDLIMIT),
    ((uint8_T)KDHP_MCUCHIPPOWERFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUCHIPPOWERFLTHANDLERESPONSEBITS),
    KDHP_MCUChipPowerFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_mz,
    &DHP_model_DW.Fault_Valid_RT_mz);

  /* End of Outputs for SubSystem: '<S1803>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUCoverFlt' */
void DHP_model_MCUCoverFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1806>/Fault_Valid_RT' */

  /* Constant: '<S1754>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1754>/Constant2'
   *  Constant: '<S1754>/KDHP_Fault_Level'
   *  Constant: '<S1754>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1754>/KDHP_Pwr_limit'
   *  Constant: '<S1754>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUCoverFltInstFlt_Flg,
    KDHP_MCUCOVERFLTALLOWRECOVERY_FLG, ((uint8_T)KDHP_MCUCOVERFLTFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_MCUCOVERFLTSPDLIMIT), ((uint8_T)
    KDHP_MCUCOVERFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUCOVERFLTHANDLERESPONSEBITS), KDHP_MCUCoverFltActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_m4, &DHP_model_DW.Fault_Valid_RT_m4);

  /* End of Outputs for SubSystem: '<S1806>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUCoverWarn' */
void DHP_model_MCUCoverWarn(void)
{
  boolean_T rtb_Switch10_jm;

  /* Switch: '<S1809>/Switch10' incorporates:
   *  Constant: '<S1809>/Constant12'
   *  Constant: '<S1809>/Constant13'
   *  Delay: '<S1809>/Delay6'
   *  Switch: '<S1809>/Switch6'
   *  Switch: '<S1809>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_jm = false;
    DHP_model_B.Switch9_h = false;
  } else {
    rtb_Switch10_jm = (VDHP_MCUCoverWarnInstFlt_Flg ||
                       DHP_model_DW.Delay6_DSTATE_o4);

    /* Switch: '<S1809>/Switch8' incorporates:
     *  Constant: '<S1755>/KDHP_Allow_Recover'
     *  Delay: '<S1809>/Delay6'
     *  Switch: '<S1809>/Switch6'
     */
    if (KDHP_MCUCOVERWARNALLOWRECOVERY_FLG) {
      DHP_model_B.Switch9_h = VDHP_MCUCoverWarnInstFlt_Flg;
    } else {
      DHP_model_B.Switch9_h = rtb_Switch10_jm;
    }

    /* End of Switch: '<S1809>/Switch8' */
  }

  /* End of Switch: '<S1809>/Switch10' */

  /* Switch: '<S1814>/Switch2' incorporates:
   *  Constant: '<S1755>/Constant2'
   *  Constant: '<S1755>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1755>/KDHP_Pwr_limit'
   *  Constant: '<S1755>/KDHP_Spd_Limit'
   *  Constant: '<S1809>/Constant'
   *  Constant: '<S1814>/Constant1'
   *  Constant: '<S1814>/Constant2'
   *  Constant: '<S1814>/Constant3'
   *  Switch: '<S1809>/Switch2'
   *  Switch: '<S1814>/Switch1'
   *  Switch: '<S1814>/Switch3'
   *  Switch: '<S1814>/Switch4'
   */
  if (KDHP_MCUCoverWarnActionSwitchOpen_flg && DHP_model_B.Switch9_h) {
    DHP_model_B.Switch2_g = ((uint16_T)KDHP_MCUCOVERWARNHANDLERESPONSEBITS);
    DHP_model_B.Switch3_d = ((uint8_T)KDHP_MCUCOVERWARNSPDLIMIT);
    DHP_model_B.Switch4_b = ((uint8_T)KDHP_MCUCOVERWARNPOWERLIMIT_PCT);

    /* Switch: '<S1809>/Switch' incorporates:
     *  Constant: '<S1755>/KDHP_Fault_Level'
     *  Constant: '<S1755>/KDHP_Handle_Response_Bits'
     *  Constant: '<S1755>/KDHP_Pwr_limit'
     *  Constant: '<S1755>/KDHP_Spd_Limit'
     *  Constant: '<S1809>/Constant1'
     *  Constant: '<S1809>/Constant2'
     *  Constant: '<S1810>/Constant'
     *  Constant: '<S1811>/Constant'
     *  Constant: '<S1812>/Constant'
     *  Constant: '<S1813>/Constant'
     *  Logic: '<S1809>/Logical Operator10'
     *  RelationalOperator: '<S1810>/Compare'
     *  RelationalOperator: '<S1811>/Compare'
     *  RelationalOperator: '<S1812>/Compare'
     *  RelationalOperator: '<S1813>/Compare'
     */
    if ((Vehicle_Type == S21_Mark) || (Vehicle_Type == S11P03_Mark) ||
        (Vehicle_Type == S11P01_Mark) || (Vehicle_Type == ((uint8_T)S11P04_MARK)))
    {
      DHP_model_B.Switch2_f = ((uint8_T)MCUERR40LEVEL_SP);
    } else {
      DHP_model_B.Switch2_f = ((uint8_T)KDHP_MCUCOVERWARNFAULTLEVEL_ENUM);
    }

    /* End of Switch: '<S1809>/Switch' */
  } else {
    DHP_model_B.Switch2_g = 0U;
    DHP_model_B.Switch3_d = 200U;
    DHP_model_B.Switch4_b = 100U;
    DHP_model_B.Switch2_f = 0U;
  }

  /* End of Switch: '<S1814>/Switch2' */

  /* Update for Delay: '<S1809>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_o4 = rtb_Switch10_jm;
}

/* Output and update for atomic system: '<S1750>/MCUDCUOverUHWFlt' */
void DHP_model_MCUDCUOverUHWFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1815>/Fault_Valid_RT' */

  /* Constant: '<S1756>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1756>/Constant2'
   *  Constant: '<S1756>/KDHP_Fault_Level'
   *  Constant: '<S1756>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1756>/KDHP_Pwr_limit'
   *  Constant: '<S1756>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUDCUOverUHWInstFlt_Flg,
    KDHP_MCUDCUOVERUHWFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUDCUOVERUHWFLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUDCUOVERUHWFLTSPDLIMIT), ((uint8_T)
    KDHP_MCUDCUOVERUHWFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUDCUOVERUHWFLTHANDLERESPONSEBITS),
    KDHP_MCUDCUOverUHWFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_lf,
    &DHP_model_DW.Fault_Valid_RT_lf);

  /* End of Outputs for SubSystem: '<S1815>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUDCUShoCirc' */
void DHP_model_MCUDCUShoCirc(void)
{
  boolean_T rtb_RelationalOperator4_k;
  boolean_T rtb_Switch1;
  boolean_T rtb_Switch10_aj;

  /* Switch: '<S1818>/Switch10' incorporates:
   *  Constant: '<S1818>/Constant12'
   *  Constant: '<S1818>/Constant13'
   *  Delay: '<S1818>/Delay6'
   *  Switch: '<S1818>/Switch6'
   *  Switch: '<S1818>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_aj = false;
    DHP_model_B.Switch9_fr = false;
  } else {
    rtb_Switch10_aj = (VDHP_MCUDcUShoCircInstFlt_Flg ||
                       DHP_model_DW.Delay6_DSTATE_g);

    /* Switch: '<S1818>/Switch8' incorporates:
     *  Constant: '<S1757>/KDHP_Allow_Recover'
     *  Delay: '<S1818>/Delay6'
     *  Switch: '<S1818>/Switch6'
     */
    if (KDHP_MCUDCUSHOCIRCALLOWRECOVERY_FLG) {
      DHP_model_B.Switch9_fr = VDHP_MCUDcUShoCircInstFlt_Flg;
    } else {
      DHP_model_B.Switch9_fr = rtb_Switch10_aj;
    }

    /* End of Switch: '<S1818>/Switch8' */
  }

  /* End of Switch: '<S1818>/Switch10' */

  /* Switch: '<S1819>/Switch1' incorporates:
   *  Constant: '<S1757>/Constant2'
   */
  rtb_Switch1 = (KDHP_MCUDCUShoCircActionSwitchOpen_flg &&
                 DHP_model_B.Switch9_fr);

  /* RelationalOperator: '<S1819>/Relational Operator4' incorporates:
   *  Constant: '<S1819>/Constant7'
   */
  rtb_RelationalOperator4_k = (DHP_model_B.Gain9 <= KDHP_GradsSpeed2);

  /* Switch: '<S1819>/Switch2' incorporates:
   *  Constant: '<S1819>/Constant1'
   */
  if (rtb_Switch1) {
    /* Switch: '<S1819>/Switch8' incorporates:
     *  Constant: '<S1757>/KDHP_Handle_Response_Bits'
     *  Constant: '<S1819>/Constant10'
     */
    if (rtb_RelationalOperator4_k) {
      DHP_model_B.Switch2_b = ((uint16_T)KDHP_MCUDCUSHOCIRCHANDLERESPONSEBITS);
    } else {
      DHP_model_B.Switch2_b = KDHP_preResponseBits_Grads;
    }

    /* End of Switch: '<S1819>/Switch8' */
  } else {
    DHP_model_B.Switch2_b = 0U;
  }

  /* End of Switch: '<S1819>/Switch2' */

  /* Switch: '<S1819>/Switch3' incorporates:
   *  Constant: '<S1757>/KDHP_Spd_Limit'
   *  Constant: '<S1819>/Constant2'
   *  Logic: '<S1819>/Logical Operator1'
   */
  if (rtb_Switch1 && rtb_RelationalOperator4_k) {
    DHP_model_B.Switch3_cw = ((uint8_T)KDHP_MCUDCUSHOCIRCSPDLIMIT);
  } else {
    DHP_model_B.Switch3_cw = 200U;
  }

  /* End of Switch: '<S1819>/Switch3' */

  /* Switch: '<S1819>/Switch4' incorporates:
   *  Constant: '<S1819>/Constant3'
   */
  if (rtb_Switch1) {
    /* Switch: '<S1819>/Switch5' incorporates:
     *  Constant: '<S1819>/Constant11'
     *  Constant: '<S1819>/Constant4'
     *  Constant: '<S1819>/Constant5'
     *  Constant: '<S1819>/Constant6'
     *  Constant: '<S1819>/Constant8'
     *  Logic: '<S1819>/Logical Operator'
     *  RelationalOperator: '<S1819>/Relational Operator1'
     *  RelationalOperator: '<S1819>/Relational Operator2'
     *  RelationalOperator: '<S1819>/Relational Operator3'
     *  Switch: '<S1819>/Switch6'
     *  Switch: '<S1819>/Switch7'
     */
    if (DHP_model_B.Gain9 > KDHP_GradsSpeed1) {
      DHP_model_B.Switch4_e = KDHP_PwrLimit1_basisSpd;
    } else if ((DHP_model_B.Gain9 <= KDHP_GradsSpeed1) && (DHP_model_B.Gain9 >
                KDHP_GradsSpeed2)) {
      /* Switch: '<S1819>/Switch6' incorporates:
       *  Constant: '<S1819>/Constant9'
       */
      DHP_model_B.Switch4_e = KDHP_PwrLimit2_basisSpd;
    } else if (rtb_RelationalOperator4_k) {
      /* Switch: '<S1819>/Switch7' incorporates:
       *  Constant: '<S1757>/KDHP_Pwr_limit'
       *  Switch: '<S1819>/Switch6'
       */
      DHP_model_B.Switch4_e = ((uint8_T)KDHP_MCUDCUSHOCIRCPOWERLIMIT_PCT);
    } else {
      DHP_model_B.Switch4_e = 100U;
    }

    /* End of Switch: '<S1819>/Switch5' */
  } else {
    DHP_model_B.Switch4_e = 100U;
  }

  /* End of Switch: '<S1819>/Switch4' */

  /* Switch: '<S1818>/Switch2' incorporates:
   *  Constant: '<S1757>/Constant2'
   *  Constant: '<S1757>/KDHP_Fault_Level'
   *  Constant: '<S1818>/Constant'
   *  Logic: '<S1818>/Logical Operator'
   */
  if (KDHP_MCUDCUShoCircActionSwitchOpen_flg && DHP_model_B.Switch9_fr) {
    DHP_model_B.Switch2_mf = ((uint8_T)KDHP_MCUDCUSHOCIRCFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_mf = 0U;
  }

  /* End of Switch: '<S1818>/Switch2' */

  /* Update for Delay: '<S1818>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_g = rtb_Switch10_aj;
}

/* Output and update for atomic system: '<S1750>/MCUDcCrrtOverRedund' */
void DHP_model_MCUDcCrrtOverRedund(void)
{
  /* Outputs for Atomic SubSystem: '<S1820>/Fault_Valid_Time' */

  /* Constant: '<S1758>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1758>/Constant2'
   *  Constant: '<S1758>/KDHP_Allow_Recover'
   *  Constant: '<S1758>/KDHP_Clear_Time'
   *  Constant: '<S1758>/KDHP_Fault_Level'
   *  Constant: '<S1758>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1758>/KDHP_Pwr_limit'
   *  Constant: '<S1758>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_MCUDcCrrtOverURedundInstFlt_flg, ((uint16_T)
    KDHP_MCUDCCRRTOVERREDUNDCONFIRMTIME_MS), ((uint16_T)
    KDHP_MCUDCCRRTOVERREDUNDCLEARTIME_MS),
    KDHP_MCUDCCRRTOVERREDUNDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUDCCRRTOVERREDUNDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUDCCRRTOVERREDUNDSPDLIMIT), ((uint8_T)
    KDHP_MCUDCCRRTOVERREDUNDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUDCCRRTOVERREDUNDHANDLERESPONSEBITS),
    KDHP_MCUDcCrrtOverRedundActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_iw, &DHP_model_DW.Fault_Valid_Time_iw);

  /* End of Outputs for SubSystem: '<S1820>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1750>/MCUDcUOverUFlt' */
void DHP_model_MCUDcUOverUFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1825>/Fault_Valid_RT' */

  /* Constant: '<S1759>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1759>/Constant2'
   *  Constant: '<S1759>/KDHP_Fault_Level'
   *  Constant: '<S1759>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1759>/KDHP_Pwr_limit'
   *  Constant: '<S1759>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUDcUOverUFltInstFlt_Flg,
    KDHP_MCUDCUOVERUFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUDCUOVERUFLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUDCUOVERUFLTSPDLIMIT),
    ((uint8_T)KDHP_MCUDCUOVERUFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUDCUOVERUFLTHANDLERESPONSEBITS),
    KDHP_MCUDcUOverUFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_iq,
    &DHP_model_DW.Fault_Valid_RT_iq);

  /* End of Outputs for SubSystem: '<S1825>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUDcUOverURedund' */
void DHP_model_MCUDcUOverURedund(void)
{
  /* Outputs for Atomic SubSystem: '<S1828>/Fault_Valid_Time' */

  /* Constant: '<S1760>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1760>/Constant2'
   *  Constant: '<S1760>/KDHP_Allow_Recover'
   *  Constant: '<S1760>/KDHP_Clear_Time'
   *  Constant: '<S1760>/KDHP_Fault_Level'
   *  Constant: '<S1760>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1760>/KDHP_Pwr_limit'
   *  Constant: '<S1760>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_MCUDcUOverURedundInstFlt_flg, ((uint16_T)
    KDHP_MCUDCUOVERUREDUNDCONFIRMTIME_MS), ((uint16_T)
    KDHP_MCUDCUOVERUREDUNDCLEARTIME_MS), KDHP_MCUDCUOVERUREDUNDALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_MCUDCUOVERUREDUNDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUDCUOVERUREDUNDSPDLIMIT), ((uint8_T)
    KDHP_MCUDCUOVERUREDUNDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUDCUOVERUREDUNDHANDLERESPONSEBITS),
    KDHP_MCUDcUOverURedundActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_ak,
    &DHP_model_DW.Fault_Valid_Time_ak);

  /* End of Outputs for SubSystem: '<S1828>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1750>/MCUDcUOverUWarn' */
void DHP_model_MCUDcUOverUWarn(void)
{
  /* Outputs for Atomic SubSystem: '<S1833>/Fault_Valid_RT' */

  /* Constant: '<S1761>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1761>/Constant2'
   *  Constant: '<S1761>/KDHP_Fault_Level'
   *  Constant: '<S1761>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1761>/KDHP_Pwr_limit'
   *  Constant: '<S1761>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUDcUOverUWarnInstFlt_Flg,
    KDHP_MCUDCUOVERUWARNALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUDCUOVERUWARNFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUDCUOVERUWARNSPDLIMIT),
    ((uint8_T)KDHP_MCUDCUOVERUWARNPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUDCUOVERUWARNHANDLERESPONSEBITS),
    KDHP_MCUDcUOverUWarnActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_pa,
    &DHP_model_DW.Fault_Valid_RT_pa);

  /* End of Outputs for SubSystem: '<S1833>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUDcUSnsrRati' */
void DHP_model_MCUDcUSnsrRati(void)
{
  /* Outputs for Atomic SubSystem: '<S1836>/Fault_Valid_RT' */

  /* Constant: '<S1762>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1762>/Constant2'
   *  Constant: '<S1762>/KDHP_Fault_Level'
   *  Constant: '<S1762>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1762>/KDHP_Pwr_limit'
   *  Constant: '<S1762>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUDcUSnsrRatiInstFlt_Flg,
    KDHP_MCUDCUSNSRRATIALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUDCUSNSRRATIFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUDCUSNSRRATISPDLIMIT),
    ((uint8_T)KDHP_MCUDCUSNSRRATIPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUDCUSNSRRATIHANDLERESPONSEBITS),
    KDHP_MCUDcUSnsrRatiActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_kbz,
    &DHP_model_DW.Fault_Valid_RT_kbz);

  /* End of Outputs for SubSystem: '<S1836>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUDcUUnderUFlt' */
void DHP_model_MCUDcUUnderUFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1839>/Fault_Valid_RT' */

  /* Constant: '<S1763>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1763>/Constant2'
   *  Constant: '<S1763>/KDHP_Fault_Level'
   *  Constant: '<S1763>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1763>/KDHP_Pwr_limit'
   *  Constant: '<S1763>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUDcUUnderUFltInstFlt_Flg,
    KDHP_MCUDCUUNDERUFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUDCUUNDERUFLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUDCUUNDERUFLTSPDLIMIT),
    ((uint8_T)KDHP_MCUDCUUNDERUFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUDCUUNDERUFLTHANDLERESPONSEBITS),
    KDHP_MCUDcUUnderUFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_n0,
    &DHP_model_DW.Fault_Valid_RT_n0);

  /* End of Outputs for SubSystem: '<S1839>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUDcUUnderUWarn' */
void DHP_model_MCUDcUUnderUWarn(void)
{
  /* Outputs for Atomic SubSystem: '<S1842>/Fault_Valid_RT' */

  /* Constant: '<S1764>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1764>/Constant2'
   *  Constant: '<S1764>/KDHP_Fault_Level'
   *  Constant: '<S1764>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1764>/KDHP_Pwr_limit'
   *  Constant: '<S1764>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUDcUUnderUWarnInstFlt_Flg,
    KDHP_MCUDCUUNDERUWARNALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUDCUUNDERUWARNFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUDCUUNDERUWARNSPDLIMIT), ((uint8_T)
    KDHP_MCUDCUUNDERUWARNPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUDCUUNDERUWARNHANDLERESPONSEBITS),
    KDHP_MCUDcUUnderUWarnActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_pi,
    &DHP_model_DW.Fault_Valid_RT_pi);

  /* End of Outputs for SubSystem: '<S1842>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUDischrg' */
void DHP_model_MCUDischrg(void)
{
  /* Outputs for Atomic SubSystem: '<S1845>/Fault_Valid_RT' */

  /* Constant: '<S1765>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1765>/Constant2'
   *  Constant: '<S1765>/KDHP_Fault_Level'
   *  Constant: '<S1765>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1765>/KDHP_Pwr_limit'
   *  Constant: '<S1765>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUDischrgInstFlt_Flg,
    KDHP_MCUDISCHRGALLOWRECOVERY_FLG, ((uint8_T)KDHP_MCUDISCHRGFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_MCUDISCHRGSPDLIMIT), ((uint8_T)KDHP_MCUDISCHRGPOWERLIMIT_PCT),
    ((uint16_T)KDHP_MCUDISCHRGHANDLERESPONSEBITS),
    KDHP_MCUDischrgActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_mb,
    &DHP_model_DW.Fault_Valid_RT_mb);

  /* End of Outputs for SubSystem: '<S1845>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUElecMotOverCrrt' */
void DHP_model_MCUElecMotOverCrrt(void)
{
  boolean_T rtb_Switch1;
  boolean_T rtb_LogicalOperator2_jw;
  boolean_T rtb_LogicalOperator4_ov;
  boolean_T rtb_Switch10_k;
  boolean_T rtb_Switch7_he;

  /* Switch: '<S1848>/Switch10' incorporates:
   *  Constant: '<S1848>/Constant12'
   *  Constant: '<S1848>/Constant13'
   *  Delay: '<S1848>/Delay6'
   *  Switch: '<S1848>/Switch6'
   *  Switch: '<S1848>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_k = false;
    DHP_model_B.Switch9_e = false;
  } else {
    rtb_Switch10_k = (VDHP_MCUElecMotOverCrrtInstFlt_Flg ||
                      DHP_model_DW.Delay6_DSTATE_pt);

    /* Switch: '<S1848>/Switch8' incorporates:
     *  Constant: '<S1766>/KDHP_Allow_Recover'
     *  Delay: '<S1848>/Delay6'
     *  Switch: '<S1848>/Switch6'
     */
    if (KDHP_MCUELECMOTOVERCRRTALLOWRECOVERY_FLG) {
      DHP_model_B.Switch9_e = VDHP_MCUElecMotOverCrrtInstFlt_Flg;
    } else {
      DHP_model_B.Switch9_e = rtb_Switch10_k;
    }

    /* End of Switch: '<S1848>/Switch8' */
  }

  /* End of Switch: '<S1848>/Switch10' */

  /* Switch: '<S1849>/Switch1' incorporates:
   *  Constant: '<S1766>/Constant2'
   */
  rtb_Switch1 = (KDHP_MCUElecMotOverCrrtActionSwitchOpen_flg &&
                 DHP_model_B.Switch9_e);

  /* Switch: '<S1849>/Switch4' incorporates:
   *  Constant: '<S1849>/Constant3'
   */
  if (rtb_Switch1) {
    /* Switch: '<S1849>/Switch5' incorporates:
     *  Constant: '<S1849>/Constant5'
     *  Constant: '<S1849>/Constant8'
     *  Constant: '<S1849>/Constant9'
     *  Delay: '<S1849>/Delay1'
     *  Logic: '<S1849>/Logical Operator'
     *  Logic: '<S1849>/Logical Operator1'
     *  RelationalOperator: '<S1849>/Relational Operator3'
     */
    if ((DHP_model_B.Gain9 > KDHP_GradsSpeed1) && (!DHP_model_DW.Delay1_DSTATE_f))
    {
      DHP_model_B.Switch4_cf = KDHP_PwrLimit1_basisSpd;
    } else {
      DHP_model_B.Switch4_cf = KDHP_PwrLimit2_basisSpd;
    }

    /* End of Switch: '<S1849>/Switch5' */
  } else {
    DHP_model_B.Switch4_cf = 100U;
  }

  /* End of Switch: '<S1849>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S1849>/DHP_systemtick_Timer' */

  /* RelationalOperator: '<S1849>/Relational Operator' incorporates:
   *  Constant: '<S1849>/Constant4'
   *  Constant: '<S1849>/Constant6'
   */
  DHP_model_DHP_systemtick_Timer_c(DHP_model_B.Switch4_cf ==
    KDHP_PwrLimit1_basisSpd, VDHP_deltaSystemTick_ms,
    KDHP_WaitMoreForFltSecond_ms, &DHP_model_B.DHP_systemtick_Timer_id,
    &DHP_model_DW.DHP_systemtick_Timer_id);

  /* End of Outputs for SubSystem: '<S1849>/DHP_systemtick_Timer' */

  /* Logic: '<S1849>/Logical Operator2' */
  rtb_LogicalOperator2_jw = !rtb_Switch1;

  /* Logic: '<S1849>/Logical Operator4' incorporates:
   *  Constant: '<S1849>/Constant10'
   *  Constant: '<S1849>/Constant11'
   *  RelationalOperator: '<S1849>/Relational Operator1'
   *  RelationalOperator: '<S1849>/Relational Operator2'
   */
  rtb_LogicalOperator4_ov = ((DHP_model_B.Switch4_cf == KDHP_PwrLimit2_basisSpd)
    && rtb_Switch1 && (DHP_model_B.Gain9 < KDHP_SpeedLimitThreshold_Grads));

  /* Switch: '<S1849>/Switch2' incorporates:
   *  Constant: '<S1766>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1849>/Constant1'
   */
  if (rtb_Switch1) {
    DHP_model_B.Switch2_d5 = ((uint16_T)
      KDHP_MCUELECMOTOVERCRRTHANDLERESPONSEBITS);
  } else {
    DHP_model_B.Switch2_d5 = 0U;
  }

  /* End of Switch: '<S1849>/Switch2' */

  /* Switch: '<S1849>/Switch6' incorporates:
   *  Constant: '<S1849>/Constant14'
   *  Delay: '<S1849>/Delay2'
   *  Delay: '<S1849>/Delay3'
   *  Logic: '<S1849>/Logical Operator5'
   *  Logic: '<S1849>/Logical Operator6'
   *  Logic: '<S1849>/Logical Operator7'
   *  Logic: '<S1849>/Logical Operator8'
   *  Logic: '<S1849>/Logical Operator9'
   */
  if (VDHP_NMSleepInd_flg || (!rtb_Switch1)) {
    rtb_Switch1 = false;
  } else {
    rtb_Switch1 = (DHP_model_DW.Delay3_DSTATE_g ||
                   ((!DHP_model_DW.Delay2_DSTATE_b) && rtb_LogicalOperator4_ov));
  }

  /* End of Switch: '<S1849>/Switch6' */

  /* Switch: '<S1849>/Switch3' incorporates:
   *  Constant: '<S1766>/KDHP_Spd_Limit'
   *  Constant: '<S1849>/Constant2'
   */
  if (rtb_Switch1) {
    DHP_model_B.Switch3_bz = ((uint8_T)KDHP_MCUELECMOTOVERCRRTSPDLIMIT);
  } else {
    DHP_model_B.Switch3_bz = 200U;
  }

  /* End of Switch: '<S1849>/Switch3' */

  /* Switch: '<S1849>/Switch7' incorporates:
   *  Constant: '<S1849>/Constant7'
   *  Delay: '<S1849>/Delay4'
   *  Logic: '<S1849>/Logical Operator3'
   *  Switch: '<S1849>/Switch10'
   */
  if (rtb_LogicalOperator2_jw || VDHP_NMSleepInd_flg) {
    rtb_Switch7_he = false;
  } else {
    rtb_Switch7_he = (DHP_model_B.DHP_systemtick_Timer_id.RelationalOperator ||
                      DHP_model_DW.Delay4_DSTATE_aj);
  }

  /* End of Switch: '<S1849>/Switch7' */

  /* Switch: '<S1849>/Switch9' incorporates:
   *  Switch: '<S1849>/Switch8'
   */
  if (VDHP_NMSleepInd_flg) {
    /* Update for Delay: '<S1849>/Delay1' incorporates:
     *  Constant: '<S1849>/Constant12'
     */
    DHP_model_DW.Delay1_DSTATE_f = false;
  } else if (rtb_LogicalOperator2_jw) {
    /* Switch: '<S1849>/Switch8' incorporates:
     *  Update for Delay: '<S1849>/Delay1'
     */
    DHP_model_DW.Delay1_DSTATE_f =
      DHP_model_B.DHP_systemtick_Timer_id.RelationalOperator;
  } else {
    /* Update for Delay: '<S1849>/Delay1' incorporates:
     *  Switch: '<S1849>/Switch8'
     */
    DHP_model_DW.Delay1_DSTATE_f = rtb_Switch7_he;
  }

  /* End of Switch: '<S1849>/Switch9' */

  /* Switch: '<S1848>/Switch2' incorporates:
   *  Constant: '<S1766>/Constant2'
   *  Constant: '<S1766>/KDHP_Fault_Level'
   *  Constant: '<S1848>/Constant'
   *  Logic: '<S1848>/Logical Operator'
   */
  if (KDHP_MCUElecMotOverCrrtActionSwitchOpen_flg && DHP_model_B.Switch9_e) {
    DHP_model_B.Switch2_ip = ((uint8_T)KDHP_MCUELECMOTOVERCRRTFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_ip = 0U;
  }

  /* End of Switch: '<S1848>/Switch2' */

  /* Update for Delay: '<S1848>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_pt = rtb_Switch10_k;

  /* Update for Delay: '<S1849>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_b = rtb_LogicalOperator4_ov;

  /* Update for Delay: '<S1849>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_g = rtb_Switch1;

  /* Update for Delay: '<S1849>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_aj = rtb_Switch7_he;
}

/* Output and update for atomic system: '<S1750>/MCUElecMotOverSpdFlt' */
void DHP_model_MCUElecMotOverSpdFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1851>/Fault_Valid_RT' */

  /* Constant: '<S1767>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1767>/Constant2'
   *  Constant: '<S1767>/KDHP_Fault_Level'
   *  Constant: '<S1767>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1767>/KDHP_Pwr_limit'
   *  Constant: '<S1767>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_MCUElecMotOverSpdFltInstFlt_Flg,
    KDHP_MCUELECMOTOVERSPDFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUELECMOTOVERSPDFLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUELECMOTOVERSPDFLTSPDLIMIT), ((uint8_T)
    KDHP_MCUELECMOTOVERSPDFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUELECMOTOVERSPDFLTHANDLERESPONSEBITS),
    KDHP_MCUElecMotOverSpdFltActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_at, &DHP_model_DW.Fault_Valid_RT_at);

  /* End of Outputs for SubSystem: '<S1851>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUElecMotOverSpdWarn' */
void DHP_model_MCUElecMotOverSpdWarn(void)
{
  /* Outputs for Atomic SubSystem: '<S1854>/Fault_Valid_RT' */

  /* Constant: '<S1768>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1768>/Constant2'
   *  Constant: '<S1768>/KDHP_Fault_Level'
   *  Constant: '<S1768>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1768>/KDHP_Pwr_limit'
   *  Constant: '<S1768>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_MCUElecMotOverSpdWarnInstFlt_Flg,
    KDHP_MCUELECMOTOVERSPDWARNALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUELECMOTOVERSPDWARNFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUELECMOTOVERSPDWARNSPDLIMIT), ((uint8_T)
    KDHP_MCUELECMOTOVERSPDWARNPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUELECMOTOVERSPDWARNHANDLERESPONSEBITS),
    KDHP_MCUElecMotOverSpdWarnActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_ad, &DHP_model_DW.Fault_Valid_RT_ad);

  /* End of Outputs for SubSystem: '<S1854>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUElecMotOverTFlt' */
void DHP_model_MCUElecMotOverTFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1857>/Fault_Valid_RT' */

  /* Constant: '<S1769>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1769>/Constant2'
   *  Constant: '<S1769>/KDHP_Fault_Level'
   *  Constant: '<S1769>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1769>/KDHP_Pwr_limit'
   *  Constant: '<S1769>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_MCUElecMotOverTFltInstFlt_Flg, KDHP_MCUELECMOTOVERTFLTALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_MCUELECMOTOVERTFLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUELECMOTOVERTFLTSPDLIMIT), ((uint8_T)
    KDHP_MCUELECMOTOVERTFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUELECMOTOVERTFLTHANDLERESPONSEBITS),
    KDHP_MCUElecMotOverTFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_gt,
    &DHP_model_DW.Fault_Valid_RT_gt);

  /* End of Outputs for SubSystem: '<S1857>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUElecMotOverTWarn' */
void DHP_model_MCUElecMotOverTWarn(void)
{
  /* Outputs for Atomic SubSystem: '<S1860>/Fault_Valid_RT' */

  /* Constant: '<S1770>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1770>/Constant2'
   *  Constant: '<S1770>/KDHP_Fault_Level'
   *  Constant: '<S1770>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1770>/KDHP_Pwr_limit'
   *  Constant: '<S1770>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_MCUElecMotOverTWarnInstFlt_Flg,
    KDHP_MCUELECMOTOVERTWARNALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUELECMOTOVERTWARNFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUELECMOTOVERTWARNSPDLIMIT), ((uint8_T)
    KDHP_MCUELECMOTOVERTWARNPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUELECMOTOVERTWARNHANDLERESPONSEBITS),
    KDHP_MCUElecMotOverTWarnActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_k1s, &DHP_model_DW.Fault_Valid_RT_k1s);

  /* End of Outputs for SubSystem: '<S1860>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUElecMotReslv' */
void DHP_model_MCUElecMotReslv(void)
{
  /* Outputs for Atomic SubSystem: '<S1863>/Fault_Valid_RT' */

  /* Constant: '<S1771>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1771>/Constant2'
   *  Constant: '<S1771>/KDHP_Fault_Level'
   *  Constant: '<S1771>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1771>/KDHP_Pwr_limit'
   *  Constant: '<S1771>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUElecMotReslvInstFlt_Flg,
    KDHP_MCUELECMOTRESLVALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUELECMOTRESLVFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUELECMOTRESLVSPDLIMIT),
    ((uint8_T)KDHP_MCUELECMOTRESLVPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUELECMOTRESLVHANDLERESPONSEBITS),
    KDHP_MCUElecMotReslvActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_mr,
    &DHP_model_DW.Fault_Valid_RT_mr);

  /* End of Outputs for SubSystem: '<S1863>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUElecMotStopTurn' */
void DHP_model_MCUElecMotStopTurn(void)
{
  /* Outputs for Atomic SubSystem: '<S1866>/Fault_Valid_RT' */

  /* Constant: '<S1772>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1772>/Constant2'
   *  Constant: '<S1772>/KDHP_Fault_Level'
   *  Constant: '<S1772>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1772>/KDHP_Pwr_limit'
   *  Constant: '<S1772>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_MCUElecMotStopTurnInstFlt_Flg, KDHP_MCUELECMOTSTOPTURNALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_MCUELECMOTSTOPTURNFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUELECMOTSTOPTURNSPDLIMIT), ((uint8_T)
    KDHP_MCUELECMOTSTOPTURNPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUELECMOTSTOPTURNHANDLERESPONSEBITS),
    KDHP_MCUElecMotStopTurnActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_bt,
    &DHP_model_DW.Fault_Valid_RT_bt);

  /* End of Outputs for SubSystem: '<S1866>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUElecMotTSnsrRati' */
void DHP_model_MCUElecMotTSnsrRati(void)
{
  boolean_T rtb_Switch10_ij;

  /* Switch: '<S1869>/Switch10' incorporates:
   *  Constant: '<S1869>/Constant12'
   *  Constant: '<S1869>/Constant13'
   *  Delay: '<S1869>/Delay6'
   *  Switch: '<S1869>/Switch6'
   *  Switch: '<S1869>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_ij = false;
    DHP_model_B.Switch9_f = false;
  } else {
    rtb_Switch10_ij = (VDHP_MCUElecMotTSnsrRatiInstFlt_Flg ||
                       DHP_model_DW.Delay6_DSTATE_o);

    /* Switch: '<S1869>/Switch8' incorporates:
     *  Constant: '<S1773>/KDHP_Allow_Recover'
     *  Delay: '<S1869>/Delay6'
     *  Switch: '<S1869>/Switch6'
     */
    if (KDHP_MCUELECMOTTSNSRRATIALLOWRECOVERY_FLG) {
      DHP_model_B.Switch9_f = VDHP_MCUElecMotTSnsrRatiInstFlt_Flg;
    } else {
      DHP_model_B.Switch9_f = rtb_Switch10_ij;
    }

    /* End of Switch: '<S1869>/Switch8' */
  }

  /* End of Switch: '<S1869>/Switch10' */

  /* Switch: '<S1874>/Switch2' incorporates:
   *  Constant: '<S1773>/Constant2'
   *  Constant: '<S1773>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1773>/KDHP_Pwr_limit'
   *  Constant: '<S1773>/KDHP_Spd_Limit'
   *  Constant: '<S1869>/Constant'
   *  Constant: '<S1874>/Constant1'
   *  Constant: '<S1874>/Constant2'
   *  Constant: '<S1874>/Constant3'
   *  Switch: '<S1869>/Switch2'
   *  Switch: '<S1874>/Switch1'
   *  Switch: '<S1874>/Switch3'
   *  Switch: '<S1874>/Switch4'
   */
  if (KDHP_MCUElecMotTSnsrRatiActionSwitchOpen_flg && DHP_model_B.Switch9_f) {
    DHP_model_B.Switch2_j = ((uint16_T)
      KDHP_MCUELECMOTTSNSRRATIHANDLERESPONSEBITS);
    DHP_model_B.Switch3_b = ((uint8_T)KDHP_MCUELECMOTTSNSRRATISPDLIMIT);
    DHP_model_B.Switch4_pt = ((uint8_T)KDHP_MCUELECMOTTSNSRRATIPOWERLIMIT_PCT);

    /* Switch: '<S1869>/Switch1' incorporates:
     *  Constant: '<S1773>/KDHP_Fault_Level'
     *  Constant: '<S1773>/KDHP_Handle_Response_Bits'
     *  Constant: '<S1773>/KDHP_Pwr_limit'
     *  Constant: '<S1773>/KDHP_Spd_Limit'
     *  Constant: '<S1869>/Constant1'
     *  Constant: '<S1869>/Constant7'
     *  Constant: '<S1870>/Constant'
     *  Constant: '<S1871>/Constant'
     *  Constant: '<S1872>/Constant'
     *  Constant: '<S1873>/Constant'
     *  Logic: '<S1869>/Logical Operator10'
     *  RelationalOperator: '<S1870>/Compare'
     *  RelationalOperator: '<S1871>/Compare'
     *  RelationalOperator: '<S1872>/Compare'
     *  RelationalOperator: '<S1873>/Compare'
     */
    if ((Vehicle_Type == S21_Mark) || (Vehicle_Type == S11P03_Mark) ||
        (Vehicle_Type == S11P01_Mark) || (Vehicle_Type == ((uint8_T)S11P04_MARK)))
    {
      DHP_model_B.Switch2_bh = ((uint8_T)MCUERR26LEVEL_SP);
    } else {
      DHP_model_B.Switch2_bh = ((uint8_T)KDHP_MCUELECMOTTSNSRRATIFAULTLEVEL_ENUM);
    }

    /* End of Switch: '<S1869>/Switch1' */
  } else {
    DHP_model_B.Switch2_j = 0U;
    DHP_model_B.Switch3_b = 200U;
    DHP_model_B.Switch4_pt = 100U;
    DHP_model_B.Switch2_bh = 0U;
  }

  /* End of Switch: '<S1874>/Switch2' */

  /* Update for Delay: '<S1869>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_o = rtb_Switch10_ij;
}

/* Output and update for atomic system: '<S1750>/MCUElecMotUnderT' */
void DHP_model_MCUElecMotUnderT(void)
{
  /* Outputs for Atomic SubSystem: '<S1875>/Fault_Valid_RT' */

  /* Constant: '<S1774>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1774>/Constant2'
   *  Constant: '<S1774>/KDHP_Fault_Level'
   *  Constant: '<S1774>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1774>/KDHP_Pwr_limit'
   *  Constant: '<S1774>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUElecMotUnderTInstFlt_Flg,
    KDHP_MCUELECMOTUNDERTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUELECMOTUNDERTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUELECMOTUNDERTSPDLIMIT), ((uint8_T)
    KDHP_MCUELECMOTUNDERTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUELECMOTUNDERTHANDLERESPONSEBITS),
    KDHP_MCUElecMotUnderTActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_l4,
    &DHP_model_DW.Fault_Valid_RT_l4);

  /* End of Outputs for SubSystem: '<S1875>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUFlt1' */
void DHP_model_MCUFlt1(void)
{
  /* Outputs for Atomic SubSystem: '<S1878>/Fault_Valid_RT' */

  /* Constant: '<S1775>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1775>/Constant2'
   *  Constant: '<S1775>/KDHP_Fault_Level'
   *  Constant: '<S1775>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1775>/KDHP_Pwr_limit'
   *  Constant: '<S1775>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUInstFlt1_flg,
    KDHP_MCUFLT1ALLOWRECOVERY_FLG, ((uint8_T)KDHP_MCUFLT1FAULTLEVEL_ENUM),
    ((uint8_T)KDHP_MCUFLT1SPDLIMIT), ((uint8_T)KDHP_MCUFLT1POWERLIMIT_PCT),
    ((uint16_T)KDHP_MCUFLT1HANDLERESPONSEBITS), KDHP_MCUFlt1ActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_kj, &DHP_model_DW.Fault_Valid_RT_kj);

  /* End of Outputs for SubSystem: '<S1878>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUFlt2' */
void DHP_model_MCUFlt2(void)
{
  /* Outputs for Atomic SubSystem: '<S1881>/Fault_Valid_RT' */

  /* Constant: '<S1776>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1776>/Constant2'
   *  Constant: '<S1776>/KDHP_Fault_Level'
   *  Constant: '<S1776>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1776>/KDHP_Pwr_limit'
   *  Constant: '<S1776>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUInstFlt2_flg,
    KDHP_MCUFLT2ALLOWRECOVERY_FLG, ((uint8_T)KDHP_MCUFLT2FAULTLEVEL_ENUM),
    ((uint8_T)KDHP_MCUFLT2SPDLIMIT), ((uint8_T)KDHP_MCUFLT2POWERLIMIT_PCT),
    ((uint16_T)KDHP_MCUFLT2HANDLERESPONSEBITS), KDHP_MCUFlt2ActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_du, &DHP_model_DW.Fault_Valid_RT_du);

  /* End of Outputs for SubSystem: '<S1881>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUFlt3' */
void DHP_model_MCUFlt3(void)
{
  /* Outputs for Atomic SubSystem: '<S1884>/Fault_Valid_RT' */

  /* Constant: '<S1777>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1777>/Constant2'
   *  Constant: '<S1777>/KDHP_Fault_Level'
   *  Constant: '<S1777>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1777>/KDHP_Pwr_limit'
   *  Constant: '<S1777>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUInstFlt3_flg,
    KDHP_MCUFLT3ALLOWRECOVERY_FLG, ((uint8_T)KDHP_MCUFLT3FAULTLEVEL_ENUM),
    ((uint8_T)KDHP_MCUFLT3SPDLIMIT), ((uint8_T)KDHP_MCUFLT3POWERLIMIT_PCT),
    ((uint16_T)KDHP_MCUFLT3HANDLERESPONSEBITS), KDHP_MCUFlt3ActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_jm, &DHP_model_DW.Fault_Valid_RT_jm);

  /* End of Outputs for SubSystem: '<S1884>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUFltUnmatch' */
void DHP_model_MCUFltUnmatch(void)
{
  boolean_T rtb_LogicalOperator3_nm;
  boolean_T rtb_Switch1;

  /* Logic: '<S1889>/Logical Operator3' incorporates:
   *  Delay: '<S1889>/Delay3'
   *  Logic: '<S1889>/Logical Operator1'
   *  Logic: '<S1889>/Logical Operator2'
   *  Logic: '<S1889>/Logical Operator8'
   */
  rtb_LogicalOperator3_nm = (((!((!VDHP_MCUFltUnmatchInstFlt_Flg) ||
    DHP_model_B.Compare_hq || VDHP_NMSleepInd_flg)) &&
    DHP_model_DW.Delay3_DSTATE_ld) || VDHP_MCUFltUnmatchInstFlt_Flg);

  /* Switch: '<S1889>/Switch1' incorporates:
   *  Constant: '<S1889>/Constant1'
   *  Constant: '<S1889>/Constant4'
   *  Delay: '<S1889>/Delay1'
   *  Switch: '<S1889>/Switch3'
   *  Switch: '<S1889>/Switch6'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch1 = false;
    DHP_model_B.Switch3_kd = false;
  } else {
    rtb_Switch1 = (rtb_LogicalOperator3_nm || DHP_model_DW.Delay1_DSTATE_k);

    /* Switch: '<S1889>/Switch5' incorporates:
     *  Constant: '<S1778>/KDHP_Allow_Recover'
     *  Delay: '<S1889>/Delay1'
     *  Switch: '<S1889>/Switch6'
     */
    if (KDHP_MCUFLTUNMATCHALLOWRECOVERY_FLG) {
      DHP_model_B.Switch3_kd = rtb_LogicalOperator3_nm;
    } else {
      DHP_model_B.Switch3_kd = rtb_Switch1;
    }

    /* End of Switch: '<S1889>/Switch5' */
  }

  /* End of Switch: '<S1889>/Switch1' */

  /* Switch: '<S1888>/Switch2' incorporates:
   *  Constant: '<S1778>/Constant2'
   *  Constant: '<S1778>/KDHP_Fault_Level'
   *  Constant: '<S1778>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1778>/KDHP_Pwr_limit'
   *  Constant: '<S1778>/KDHP_Spd_Limit'
   *  Constant: '<S1887>/Constant'
   *  Constant: '<S1888>/Constant1'
   *  Constant: '<S1888>/Constant2'
   *  Constant: '<S1888>/Constant3'
   *  Switch: '<S1887>/Switch2'
   *  Switch: '<S1888>/Switch1'
   *  Switch: '<S1888>/Switch3'
   *  Switch: '<S1888>/Switch4'
   */
  if (KDHP_MCUFltUnmatchActionSwitchOpen_flg && DHP_model_B.Switch3_kd) {
    DHP_model_B.Switch2_m = ((uint16_T)KDHP_MCUFLTUNMATCHHANDLERESPONSEBITS);
    DHP_model_B.Switch3_a = ((uint8_T)KDHP_MCUFLTUNMATCHSPDLIMIT);
    DHP_model_B.Switch4_j = ((uint8_T)KDHP_MCUFLTUNMATCHPOWERLIMIT_PCT);
    DHP_model_B.Switch2_gz = ((uint8_T)KDHP_MCUFLTUNMATCHFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_m = 0U;
    DHP_model_B.Switch3_a = 200U;
    DHP_model_B.Switch4_j = 100U;
    DHP_model_B.Switch2_gz = 0U;
  }

  /* End of Switch: '<S1888>/Switch2' */

  /* Update for Delay: '<S1889>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_ld = rtb_LogicalOperator3_nm;

  /* Update for Delay: '<S1889>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_k = rtb_Switch1;
}

/* Output and update for atomic system: '<S1750>/MCUHWSamplingFlt' */
void DHP_model_MCUHWSamplingFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1890>/Fault_Valid_RT' */

  /* Constant: '<S1779>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1779>/Constant2'
   *  Constant: '<S1779>/KDHP_Fault_Level'
   *  Constant: '<S1779>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1779>/KDHP_Pwr_limit'
   *  Constant: '<S1779>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUHWSamplingInstFlt_Flg,
    KDHP_MCUHWSAMPLINGFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUHWSAMPLINGFLTFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUHWSAMPLINGFLTSPDLIMIT), ((uint8_T)
    KDHP_MCUHWSAMPLINGFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUHWSAMPLINGFLTHANDLERESPONSEBITS),
    KDHP_MCUHWSamplingFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_hj,
    &DHP_model_DW.Fault_Valid_RT_hj);

  /* End of Outputs for SubSystem: '<S1890>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUHwCurrOver' */
void DHP_model_MCUHwCurrOver(void)
{
  boolean_T rtb_LogicalOperator11_pp;
  boolean_T rtb_RelationalOperator4_ho;
  boolean_T rtb_Switch10_a;
  boolean_T rtb_Switch1;

  /* Logic: '<S1893>/Logical Operator11' incorporates:
   *  Constant: '<S1893>/Constant3'
   *  Constant: '<S1893>/Constant7'
   *  Constant: '<S1894>/Constant'
   *  Constant: '<S1895>/Constant'
   *  Constant: '<S1896>/Constant'
   *  Constant: '<S1897>/Constant'
   *  Constant: '<S1898>/Constant'
   *  Constant: '<S1899>/Constant'
   *  Constant: '<S1900>/Constant'
   *  Constant: '<S1901>/Constant'
   *  Logic: '<S1893>/Logical Operator10'
   *  RelationalOperator: '<S1894>/Compare'
   *  RelationalOperator: '<S1895>/Compare'
   *  RelationalOperator: '<S1896>/Compare'
   *  RelationalOperator: '<S1897>/Compare'
   *  RelationalOperator: '<S1898>/Compare'
   *  RelationalOperator: '<S1899>/Compare'
   *  RelationalOperator: '<S1900>/Compare'
   *  RelationalOperator: '<S1901>/Compare'
   */
  rtb_LogicalOperator11_pp = ((Vehicle_Type == K11P06_Mark) || (Vehicle_Type ==
    K11P01_Mark) || ((Vehicle_Type == S21_Mark) || (Vehicle_Type == S11P03_Mark)
                     || (Vehicle_Type == S11P01_Mark) || (Vehicle_Type ==
    ((uint8_T)S11P04_MARK)) || (Vehicle_Type == S11P05_Mark)) || (Vehicle_Type ==
    ((uint8_T)Z18_MARK)));

  /* Switch: '<S1893>/Switch10' incorporates:
   *  Constant: '<S1893>/Constant12'
   *  Constant: '<S1893>/Constant13'
   *  Delay: '<S1893>/Delay6'
   *  Switch: '<S1893>/Switch6'
   *  Switch: '<S1893>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_a = false;
    DHP_model_B.Switch9_ma = false;
  } else {
    rtb_Switch10_a = (VDHP_MCUHWCurrOverInstFlt_Flg ||
                      DHP_model_DW.Delay6_DSTATE_j);

    /* Switch: '<S1893>/Switch8' incorporates:
     *  Constant: '<S1780>/KDHP_Allow_Recover'
     *  Delay: '<S1893>/Delay6'
     *  Switch: '<S1893>/Switch3'
     *  Switch: '<S1893>/Switch6'
     */
    if (rtb_LogicalOperator11_pp || KDHP_MCUHWCURROVERALLOWRECOVERY_FLG) {
      DHP_model_B.Switch9_ma = VDHP_MCUHWCurrOverInstFlt_Flg;
    } else {
      DHP_model_B.Switch9_ma = rtb_Switch10_a;
    }

    /* End of Switch: '<S1893>/Switch8' */
  }

  /* End of Switch: '<S1893>/Switch10' */

  /* Switch: '<S1902>/Switch1' incorporates:
   *  Constant: '<S1780>/Constant2'
   */
  rtb_Switch1 = (KDHP_MCUHwCurrOverActionSwitchOpen_flg &&
                 DHP_model_B.Switch9_ma);

  /* RelationalOperator: '<S1902>/Relational Operator4' incorporates:
   *  Constant: '<S1902>/Constant7'
   */
  rtb_RelationalOperator4_ho = (DHP_model_B.Gain9 <= KDHP_GradsSpeed2);

  /* Switch: '<S1902>/Switch13' incorporates:
   *  Constant: '<S1902>/Constant13'
   *  Constant: '<S1902>/Constant14'
   *  Constant: '<S1902>/Constant15'
   *  Constant: '<S1902>/Constant2'
   *  Logic: '<S1902>/Logical Operator1'
   *  Switch: '<S1902>/Switch14'
   *  Switch: '<S1902>/Switch3'
   *  Switch: '<S1902>/Switch9'
   */
  if (rtb_LogicalOperator11_pp) {
    DHP_model_B.Switch13_k = 200U;
    DHP_model_B.Switch14_o = 0U;
    DHP_model_B.Switch9_m = 100U;
  } else {
    if (rtb_Switch1 && rtb_RelationalOperator4_ho) {
      /* Switch: '<S1902>/Switch3' incorporates:
       *  Constant: '<S1780>/KDHP_Spd_Limit'
       */
      DHP_model_B.Switch13_k = ((uint8_T)KDHP_MCUHWCURROVERSPDLIMIT);
    } else {
      DHP_model_B.Switch13_k = 200U;
    }

    /* Switch: '<S1902>/Switch2' incorporates:
     *  Constant: '<S1902>/Constant1'
     *  Constant: '<S1902>/Constant2'
     *  Constant: '<S1902>/Constant3'
     *  Switch: '<S1902>/Switch3'
     *  Switch: '<S1902>/Switch4'
     */
    if (rtb_Switch1) {
      /* Switch: '<S1902>/Switch8' incorporates:
       *  Constant: '<S1780>/KDHP_Handle_Response_Bits'
       *  Constant: '<S1902>/Constant10'
       */
      if (rtb_RelationalOperator4_ho) {
        DHP_model_B.Switch14_o = ((uint16_T)KDHP_MCUHWCURROVERHANDLERESPONSEBITS);
      } else {
        DHP_model_B.Switch14_o = KDHP_preResponseBits_Grads;
      }

      /* End of Switch: '<S1902>/Switch8' */

      /* Switch: '<S1902>/Switch5' incorporates:
       *  Constant: '<S1902>/Constant11'
       *  Constant: '<S1902>/Constant4'
       *  Constant: '<S1902>/Constant5'
       *  Constant: '<S1902>/Constant6'
       *  Constant: '<S1902>/Constant8'
       *  Logic: '<S1902>/Logical Operator'
       *  RelationalOperator: '<S1902>/Relational Operator1'
       *  RelationalOperator: '<S1902>/Relational Operator2'
       *  RelationalOperator: '<S1902>/Relational Operator3'
       *  Switch: '<S1902>/Switch6'
       *  Switch: '<S1902>/Switch7'
       */
      if (DHP_model_B.Gain9 > KDHP_GradsSpeed1) {
        DHP_model_B.Switch9_m = KDHP_PwrLimit1_basisSpd;
      } else if ((DHP_model_B.Gain9 <= KDHP_GradsSpeed1) && (DHP_model_B.Gain9 >
                  KDHP_GradsSpeed2)) {
        /* Switch: '<S1902>/Switch6' incorporates:
         *  Constant: '<S1902>/Constant9'
         */
        DHP_model_B.Switch9_m = KDHP_PwrLimit2_basisSpd;
      } else if (rtb_RelationalOperator4_ho) {
        /* Switch: '<S1902>/Switch7' incorporates:
         *  Constant: '<S1780>/KDHP_Pwr_limit'
         *  Switch: '<S1902>/Switch6'
         */
        DHP_model_B.Switch9_m = ((uint8_T)KDHP_MCUHWCURROVERPOWERLIMIT_PCT);
      } else {
        DHP_model_B.Switch9_m = 100U;
      }

      /* End of Switch: '<S1902>/Switch5' */
    } else {
      DHP_model_B.Switch14_o = 0U;
      DHP_model_B.Switch9_m = 100U;
    }

    /* End of Switch: '<S1902>/Switch2' */
  }

  /* End of Switch: '<S1902>/Switch13' */

  /* Switch: '<S1893>/Switch2' incorporates:
   *  Constant: '<S1780>/Constant2'
   *  Constant: '<S1893>/Constant'
   *  Logic: '<S1893>/Logical Operator'
   */
  if (KDHP_MCUHwCurrOverActionSwitchOpen_flg && DHP_model_B.Switch9_ma) {
    /* Switch: '<S1893>/Switch1' incorporates:
     *  Constant: '<S1780>/KDHP_Fault_Level'
     *  Constant: '<S1893>/Constant1'
     */
    if (rtb_LogicalOperator11_pp) {
      DHP_model_B.Switch2_dh = ((uint8_T)MCUERR8LEVEL_SP);
    } else {
      DHP_model_B.Switch2_dh = ((uint8_T)KDHP_MCUHWCURROVERFAULTLEVEL_ENUM);
    }

    /* End of Switch: '<S1893>/Switch1' */
  } else {
    DHP_model_B.Switch2_dh = 0U;
  }

  /* End of Switch: '<S1893>/Switch2' */

  /* Update for Delay: '<S1893>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_j = rtb_Switch10_a;
}

/* Output and update for atomic system: '<S1750>/MCUHwCurrOverRedund' */
void DHP_model_MCUHwCurrOverRedund(void)
{
  /* Outputs for Atomic SubSystem: '<S1904>/Fault_Valid_Time' */

  /* Constant: '<S1781>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1781>/Constant2'
   *  Constant: '<S1781>/KDHP_Allow_Recover'
   *  Constant: '<S1781>/KDHP_Clear_Time'
   *  Constant: '<S1781>/KDHP_Fault_Level'
   *  Constant: '<S1781>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1781>/KDHP_Pwr_limit'
   *  Constant: '<S1781>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_MCUHwCurrOverRedundInstFlt_flg, ((uint16_T)
    KDHP_MCUHWCURROVERREDUNDCONFIRMTIME_MS), ((uint16_T)
    KDHP_MCUHWCURROVERREDUNDCLEARTIME_MS),
    KDHP_MCUHWCURROVERREDUNDALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUHWCURROVERREDUNDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUHWCURROVERREDUNDSPDLIMIT), ((uint8_T)
    KDHP_MCUHWCURROVERREDUNDPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUHWCURROVERREDUNDHANDLERESPONSEBITS),
    KDHP_MCUHwCurrOverRedundActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_ix, &DHP_model_DW.Fault_Valid_Time_ix);

  /* End of Outputs for SubSystem: '<S1904>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1750>/MCUIGBTHW' */
void DHP_model_MCUIGBTHW(void)
{
  boolean_T rtb_LogicalOperator10_bm;
  boolean_T rtb_RelationalOperator4_p;
  boolean_T rtb_Switch10_p;
  boolean_T rtb_Switch1;

  /* Logic: '<S1909>/Logical Operator10' incorporates:
   *  Constant: '<S1909>/Constant7'
   *  Constant: '<S1910>/Constant'
   *  Constant: '<S1911>/Constant'
   *  Constant: '<S1912>/Constant'
   *  Constant: '<S1913>/Constant'
   *  Constant: '<S1914>/Constant'
   *  RelationalOperator: '<S1910>/Compare'
   *  RelationalOperator: '<S1911>/Compare'
   *  RelationalOperator: '<S1912>/Compare'
   *  RelationalOperator: '<S1913>/Compare'
   *  RelationalOperator: '<S1914>/Compare'
   */
  rtb_LogicalOperator10_bm = ((Vehicle_Type == S21_Mark) || (Vehicle_Type ==
    S11P03_Mark) || (Vehicle_Type == S11P01_Mark) || (Vehicle_Type == ((uint8_T)
    S11P04_MARK)) || (Vehicle_Type == S11P05_Mark));

  /* Switch: '<S1909>/Switch10' incorporates:
   *  Constant: '<S1909>/Constant12'
   *  Constant: '<S1909>/Constant13'
   *  Delay: '<S1909>/Delay6'
   *  Switch: '<S1909>/Switch6'
   *  Switch: '<S1909>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_p = false;
    DHP_model_B.Switch9_g = false;
  } else {
    rtb_Switch10_p = (VDHP_MCUIGBTHWInstFlt_Flg || DHP_model_DW.Delay6_DSTATE_d);

    /* Switch: '<S1909>/Switch8' incorporates:
     *  Constant: '<S1782>/KDHP_Allow_Recover'
     *  Delay: '<S1909>/Delay6'
     *  Switch: '<S1909>/Switch3'
     *  Switch: '<S1909>/Switch6'
     */
    if (rtb_LogicalOperator10_bm || KDHP_MCUIGBTHWALLOWRECOVERY_FLG) {
      DHP_model_B.Switch9_g = VDHP_MCUIGBTHWInstFlt_Flg;
    } else {
      DHP_model_B.Switch9_g = rtb_Switch10_p;
    }

    /* End of Switch: '<S1909>/Switch8' */
  }

  /* End of Switch: '<S1909>/Switch10' */

  /* Switch: '<S1915>/Switch1' incorporates:
   *  Constant: '<S1782>/Constant2'
   */
  rtb_Switch1 = (KDHP_MCUIGBTHWActionSwitchOpen_flg && DHP_model_B.Switch9_g);

  /* RelationalOperator: '<S1915>/Relational Operator4' incorporates:
   *  Constant: '<S1915>/Constant7'
   */
  rtb_RelationalOperator4_p = (DHP_model_B.Gain9 <= KDHP_GradsSpeed2);

  /* Switch: '<S1915>/Switch13' incorporates:
   *  Constant: '<S1915>/Constant13'
   *  Constant: '<S1915>/Constant14'
   *  Constant: '<S1915>/Constant15'
   *  Constant: '<S1915>/Constant2'
   *  Logic: '<S1915>/Logical Operator1'
   *  Switch: '<S1915>/Switch14'
   *  Switch: '<S1915>/Switch3'
   *  Switch: '<S1915>/Switch9'
   */
  if (rtb_LogicalOperator10_bm) {
    DHP_model_B.Switch13 = 200U;
    DHP_model_B.Switch14 = 0U;
    DHP_model_B.Switch9 = 100U;
  } else {
    if (rtb_Switch1 && rtb_RelationalOperator4_p) {
      /* Switch: '<S1915>/Switch3' incorporates:
       *  Constant: '<S1782>/KDHP_Spd_Limit'
       */
      DHP_model_B.Switch13 = ((uint8_T)KDHP_MCUIGBTHWSPDLIMIT);
    } else {
      DHP_model_B.Switch13 = 200U;
    }

    /* Switch: '<S1915>/Switch2' incorporates:
     *  Constant: '<S1915>/Constant1'
     *  Constant: '<S1915>/Constant2'
     *  Constant: '<S1915>/Constant3'
     *  Switch: '<S1915>/Switch3'
     *  Switch: '<S1915>/Switch4'
     */
    if (rtb_Switch1) {
      /* Switch: '<S1915>/Switch8' incorporates:
       *  Constant: '<S1782>/KDHP_Handle_Response_Bits'
       *  Constant: '<S1915>/Constant10'
       */
      if (rtb_RelationalOperator4_p) {
        DHP_model_B.Switch14 = ((uint16_T)KDHP_MCUIGBTHWHANDLERESPONSEBITS);
      } else {
        DHP_model_B.Switch14 = KDHP_preResponseBits_Grads;
      }

      /* End of Switch: '<S1915>/Switch8' */

      /* Switch: '<S1915>/Switch5' incorporates:
       *  Constant: '<S1915>/Constant11'
       *  Constant: '<S1915>/Constant4'
       *  Constant: '<S1915>/Constant5'
       *  Constant: '<S1915>/Constant6'
       *  Constant: '<S1915>/Constant8'
       *  Logic: '<S1915>/Logical Operator'
       *  RelationalOperator: '<S1915>/Relational Operator1'
       *  RelationalOperator: '<S1915>/Relational Operator2'
       *  RelationalOperator: '<S1915>/Relational Operator3'
       *  Switch: '<S1915>/Switch6'
       *  Switch: '<S1915>/Switch7'
       */
      if (DHP_model_B.Gain9 > KDHP_GradsSpeed1) {
        DHP_model_B.Switch9 = KDHP_PwrLimit1_basisSpd;
      } else if ((DHP_model_B.Gain9 <= KDHP_GradsSpeed1) && (DHP_model_B.Gain9 >
                  KDHP_GradsSpeed2)) {
        /* Switch: '<S1915>/Switch6' incorporates:
         *  Constant: '<S1915>/Constant9'
         */
        DHP_model_B.Switch9 = KDHP_PwrLimit2_basisSpd;
      } else if (rtb_RelationalOperator4_p) {
        /* Switch: '<S1915>/Switch7' incorporates:
         *  Constant: '<S1782>/KDHP_Pwr_limit'
         *  Switch: '<S1915>/Switch6'
         */
        DHP_model_B.Switch9 = ((uint8_T)KDHP_MCUIGBTHWPOWERLIMIT_PCT);
      } else {
        DHP_model_B.Switch9 = 100U;
      }

      /* End of Switch: '<S1915>/Switch5' */
    } else {
      DHP_model_B.Switch14 = 0U;
      DHP_model_B.Switch9 = 100U;
    }

    /* End of Switch: '<S1915>/Switch2' */
  }

  /* End of Switch: '<S1915>/Switch13' */

  /* Switch: '<S1909>/Switch2' incorporates:
   *  Constant: '<S1782>/Constant2'
   *  Constant: '<S1909>/Constant'
   *  Logic: '<S1909>/Logical Operator'
   */
  if (KDHP_MCUIGBTHWActionSwitchOpen_flg && DHP_model_B.Switch9_g) {
    /* Switch: '<S1909>/Switch1' incorporates:
     *  Constant: '<S1782>/KDHP_Fault_Level'
     *  Constant: '<S1909>/Constant1'
     */
    if (rtb_LogicalOperator10_bm) {
      DHP_model_B.Switch2_i = ((uint8_T)MCUERR15LEVEL_SP);
    } else {
      DHP_model_B.Switch2_i = ((uint8_T)KDHP_MCUIGBTHWFAULTLEVEL_ENUM);
    }

    /* End of Switch: '<S1909>/Switch1' */
  } else {
    DHP_model_B.Switch2_i = 0U;
  }

  /* End of Switch: '<S1909>/Switch2' */

  /* Update for Delay: '<S1909>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_d = rtb_Switch10_p;
}

/* Output and update for atomic system: '<S1750>/MCUIGBTOverTFlt' */
void DHP_model_MCUIGBTOverTFlt(void)
{
  /* Outputs for Atomic SubSystem: '<S1916>/Fault_Valid_RT' */

  /* Constant: '<S1783>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1783>/Constant2'
   *  Constant: '<S1783>/KDHP_Fault_Level'
   *  Constant: '<S1783>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1783>/KDHP_Pwr_limit'
   *  Constant: '<S1783>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUIGBTOverTFltInstFlt_Flg,
    KDHP_MCUIGBTOVERTFLTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUIGBTOVERTFLTFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUIGBTOVERTFLTSPDLIMIT),
    ((uint8_T)KDHP_MCUIGBTOVERTFLTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUIGBTOVERTFLTHANDLERESPONSEBITS),
    KDHP_MCUIGBTOverTFltActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_c5o,
    &DHP_model_DW.Fault_Valid_RT_c5o);

  /* End of Outputs for SubSystem: '<S1916>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUIGBTOverTWarn' */
void DHP_model_MCUIGBTOverTWarn(void)
{
  /* Outputs for Atomic SubSystem: '<S1919>/Fault_Valid_RT' */

  /* Constant: '<S1784>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1784>/Constant2'
   *  Constant: '<S1784>/KDHP_Fault_Level'
   *  Constant: '<S1784>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1784>/KDHP_Pwr_limit'
   *  Constant: '<S1784>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUIGBTOverTWarnInstFlt_Flg,
    KDHP_MCUIGBTOVERTWARNALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUIGBTOVERTWARNFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUIGBTOVERTWARNSPDLIMIT), ((uint8_T)
    KDHP_MCUIGBTOVERTWARNPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUIGBTOVERTWARNHANDLERESPONSEBITS),
    KDHP_MCUIGBTOverTWarnActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_m5,
    &DHP_model_DW.Fault_Valid_RT_m5);

  /* End of Outputs for SubSystem: '<S1919>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUIGBTUnderT' */
void DHP_model_MCUIGBTUnderT(void)
{
  /* Outputs for Atomic SubSystem: '<S1922>/Fault_Valid_RT' */

  /* Constant: '<S1785>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1785>/Constant2'
   *  Constant: '<S1785>/KDHP_Fault_Level'
   *  Constant: '<S1785>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1785>/KDHP_Pwr_limit'
   *  Constant: '<S1785>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUIGBTUnderTInstFlt_Flg,
    KDHP_MCUIGBTUNDERTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUIGBTUNDERTFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUIGBTUNDERTSPDLIMIT),
    ((uint8_T)KDHP_MCUIGBTUNDERTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUIGBTUNDERTHANDLERESPONSEBITS),
    KDHP_MCUIGBTUnderTActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_if,
    &DHP_model_DW.Fault_Valid_RT_if);

  /* End of Outputs for SubSystem: '<S1922>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUIGBTphaseTCheckErr' */
void DHP_model_MCUIGBTphaseTCheckErr(void)
{
  /* Outputs for Atomic SubSystem: '<S1925>/Fault_Valid_RT' */

  /* Constant: '<S1786>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1786>/Constant2'
   *  Constant: '<S1786>/KDHP_Fault_Level'
   *  Constant: '<S1786>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1786>/KDHP_Pwr_limit'
   *  Constant: '<S1786>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_MCUIGBTphaseTCheckErrInstFlt_Flg,
    KDHP_MCUIGBTPHASETCHECKERRALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUIGBTPHASETCHECKERRFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUIGBTPHASETCHECKERRSPDLIMIT), ((uint8_T)
    KDHP_MCUIGBTPHASETCHECKERRPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUIGBTPHASETCHECKERRHANDLERESPONSEBITS),
    KDHP_MCUIGBTphaseTCheckErrActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_h3, &DHP_model_DW.Fault_Valid_RT_h3);

  /* End of Outputs for SubSystem: '<S1925>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCULowBattUnderU' */
void DHP_model_MCULowBattUnderU(void)
{
  /* Outputs for Atomic SubSystem: '<S1928>/Fault_Valid_RT' */

  /* Constant: '<S1787>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1787>/Constant2'
   *  Constant: '<S1787>/KDHP_Fault_Level'
   *  Constant: '<S1787>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1787>/KDHP_Pwr_limit'
   *  Constant: '<S1787>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCULowBattUnderUInstFlt_Flg,
    KDHP_MCULOWBATTUNDERUALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCULOWBATTUNDERUFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCULOWBATTUNDERUSPDLIMIT), ((uint8_T)
    KDHP_MCULOWBATTUNDERUPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCULOWBATTUNDERUHANDLERESPONSEBITS),
    KDHP_MCULowBattUnderUActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_py,
    &DHP_model_DW.Fault_Valid_RT_py);

  /* End of Outputs for SubSystem: '<S1928>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUMotTUpRate' */
void DHP_model_MCUMotTUpRate(void)
{
  boolean_T rtb_Switch1;
  boolean_T rtb_RelationalOperator1_ho;
  boolean_T rtb_LogicalOperator3_ox;
  uint8_T rtb_Switch3;
  boolean_T rtb_LogicalOperator4_af;
  boolean_T rtb_LogicalOperator2_oj2;
  boolean_T rtb_Switch8_c4;
  boolean_T rtb_Switch6;
  boolean_T rtb_Switch10_h;
  uint8_T rtb_LogicalOperator3_k2;
  uint32_T rtb_Switch1_a;
  uint32_T rtb_LogicalOperator3_k2_0;
  uint32_T qY;
  uint32_T qY_0;

  /* Switch: '<S1933>/Switch11' incorporates:
   *  Constant: '<S1933>/Constant3'
   *  Delay: '<S1933>/Delay'
   *  Logic: '<S1933>/Logical Operator1'
   *  Logic: '<S1933>/Logical Operator4'
   */
  if (VDHP_MCUTUpRateInstFlt_flg && (!DHP_model_DW.Delay_DSTATE_f0)) {
    rtb_Switch3 = 0U;
  } else {
    rtb_Switch3 = VDHP_deltaSystemTick_ms;
  }

  /* End of Switch: '<S1933>/Switch11' */

  /* Switch: '<S1933>/Switch' incorporates:
   *  Constant: '<S1933>/Constant2'
   *  Delay: '<S1933>/Delay3'
   *  Logic: '<S1933>/Logical Operator5'
   *  Logic: '<S1933>/Logical Operator6'
   */
  if ((!DHP_model_B.LogicalOperator2_a) || DHP_model_DW.Delay3_DSTATE_h) {
    rtb_LogicalOperator3_k2 = 0U;
  } else {
    rtb_LogicalOperator3_k2 = rtb_Switch3;
  }

  /* End of Switch: '<S1933>/Switch' */

  /* Switch: '<S1933>/Switch1' incorporates:
   *  Constant: '<S1933>/Constant1'
   *  Delay: '<S1933>/Delay1'
   *  Logic: '<S1933>/Logical Operator7'
   */
  if (!DHP_model_B.LogicalOperator2_a) {
    qY_0 = 0U;
  } else {
    qY_0 = DHP_model_DW.Delay1_DSTATE;
  }

  /* End of Switch: '<S1933>/Switch1' */

  /* Sum: '<S1933>/Add2' */
  qY_0 += rtb_LogicalOperator3_k2;
  if (qY_0 < rtb_LogicalOperator3_k2) {
    qY_0 = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1933>/Relational Operator1' incorporates:
   *  Constant: '<S1788>/KDHP_Clear_Time'
   *  Sum: '<S1933>/Add2'
   */
  rtb_RelationalOperator1_ho = (qY_0 >= ((uint16_T)
    KDHP_MCUMOTTUPRATECLEARTIME_MS));

  /* Logic: '<S1933>/Logical Operator3' */
  rtb_LogicalOperator3_ox = !VDHP_MCUTUpRateInstFlt_flg;

  /* Switch: '<S1933>/Switch5' incorporates:
   *  Constant: '<S1933>/Constant10'
   *  Constant: '<S1933>/Constant11'
   *  Delay: '<S1933>/Delay7'
   *  Switch: '<S1933>/Switch4'
   */
  if (rtb_LogicalOperator3_ox) {
    rtb_LogicalOperator3_k2 = 0U;
    rtb_LogicalOperator3_k2_0 = 0U;
  } else {
    rtb_LogicalOperator3_k2 = rtb_Switch3;
    rtb_LogicalOperator3_k2_0 = DHP_model_DW.Delay7_DSTATE;
  }

  /* End of Switch: '<S1933>/Switch5' */

  /* Sum: '<S1933>/Add6' */
  rtb_LogicalOperator3_k2_0 += rtb_LogicalOperator3_k2;
  if (rtb_LogicalOperator3_k2_0 < rtb_LogicalOperator3_k2) {
    rtb_LogicalOperator3_k2_0 = MAX_uint32_T;
  }

  /* Switch: '<S1933>/Switch3' incorporates:
   *  Constant: '<S1933>/Constant4'
   */
  if (!VDHP_MCUTUpRateInstFlt_flg) {
    rtb_Switch3 = 0U;
  }

  /* End of Switch: '<S1933>/Switch3' */

  /* Switch: '<S1933>/Switch9' incorporates:
   *  Constant: '<S1788>/KDHP_Confirm_Time'
   *  Delay: '<S1933>/Delay4'
   *  Logic: '<S1933>/Logical Operator2'
   *  RelationalOperator: '<S1933>/Relational Operator5'
   *  Sum: '<S1933>/Add6'
   */
  if (DHP_model_DW.Delay4_DSTATE_b) {
    rtb_LogicalOperator3_ox = rtb_RelationalOperator1_ho;
  } else {
    rtb_LogicalOperator3_ox = (rtb_LogicalOperator3_ox &&
      (rtb_LogicalOperator3_k2_0 < ((uint16_T)KDHP_MCUMOTTUPRATECONFIRMTIME_MS)));
  }

  /* End of Switch: '<S1933>/Switch9' */

  /* Switch: '<S1933>/Switch7' incorporates:
   *  Constant: '<S1933>/Constant7'
   *  Delay: '<S1933>/Delay2'
   *  Logic: '<S1933>/Logical Operator'
   */
  if (rtb_LogicalOperator3_ox || VDHP_NMSleepInd_flg) {
    rtb_Switch1_a = 0U;
  } else {
    rtb_Switch1_a = DHP_model_DW.Delay2_DSTATE;
  }

  /* End of Switch: '<S1933>/Switch7' */

  /* Sum: '<S1933>/Add3' */
  qY = rtb_Switch1_a + rtb_Switch3;
  if (qY < rtb_Switch1_a) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1933>/Relational Operator3' incorporates:
   *  Constant: '<S1788>/KDHP_Confirm_Time'
   *  Sum: '<S1933>/Add3'
   */
  rtb_Switch1 = (qY >= ((uint16_T)KDHP_MCUMOTTUPRATECONFIRMTIME_MS));

  /* Switch: '<S1933>/Switch10' incorporates:
   *  Constant: '<S1933>/Constant13'
   *  Delay: '<S1933>/Delay6'
   *  Switch: '<S1933>/Switch6'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_LogicalOperator3_ox = false;
  } else {
    rtb_LogicalOperator3_ox = (rtb_Switch1 || DHP_model_DW.Delay6_DSTATE_f);
  }

  /* End of Switch: '<S1933>/Switch10' */

  /* Switch: '<S1933>/Switch8' incorporates:
   *  Constant: '<S1788>/KDHP_Allow_Recover'
   */
  if (KDHP_MCUMOTTUPRATEALLOWRECOVERY_FLG) {
    rtb_Switch8_c4 = rtb_Switch1;
  } else {
    rtb_Switch8_c4 = rtb_LogicalOperator3_ox;
  }

  /* End of Switch: '<S1933>/Switch8' */

  /* Switch: '<S1933>/Switch2' */
  DHP_model_B.Switch2_h = ((!VDHP_NMSleepInd_flg) && rtb_Switch8_c4);

  /* Switch: '<S1932>/Switch1' incorporates:
   *  Constant: '<S1788>/Constant2'
   */
  rtb_Switch1 = (KDHP_MCUMotTUpRateActionSwitchOpen_flg && DHP_model_B.Switch2_h);

  /* Logic: '<S1932>/Logical Operator4' incorporates:
   *  Constant: '<S1932>/Constant11'
   *  RelationalOperator: '<S1932>/Relational Operator2'
   */
  rtb_LogicalOperator4_af = (rtb_Switch1 && (DHP_model_B.Gain9 <
    KDHP_SpeedLimitThreshold_Grads));

  /* Switch: '<S1932>/Switch6' incorporates:
   *  Constant: '<S1932>/Constant14'
   *  Delay: '<S1932>/Delay2'
   *  Delay: '<S1932>/Delay3'
   *  Logic: '<S1932>/Logical Operator5'
   *  Logic: '<S1932>/Logical Operator6'
   *  Logic: '<S1932>/Logical Operator7'
   *  Logic: '<S1932>/Logical Operator8'
   *  Logic: '<S1932>/Logical Operator9'
   */
  if (VDHP_NMSleepInd_flg || (!rtb_Switch1)) {
    rtb_Switch6 = false;
  } else {
    rtb_Switch6 = (DHP_model_DW.Delay3_DSTATE_f ||
                   ((!DHP_model_DW.Delay2_DSTATE_n) && rtb_LogicalOperator4_af));
  }

  /* End of Switch: '<S1932>/Switch6' */

  /* Switch: '<S1932>/Switch4' incorporates:
   *  Constant: '<S1932>/Constant3'
   */
  if (rtb_Switch1) {
    /* Switch: '<S1932>/Switch5' incorporates:
     *  Constant: '<S1932>/Constant5'
     *  Constant: '<S1932>/Constant7'
     *  Constant: '<S1932>/Constant8'
     *  Delay: '<S1932>/Delay1'
     *  Logic: '<S1932>/Logical Operator'
     *  Logic: '<S1932>/Logical Operator1'
     *  RelationalOperator: '<S1932>/Relational Operator3'
     *  Switch: '<S1932>/Switch11'
     */
    if ((DHP_model_B.Gain9 > KDHP_GradsSpeed1) &&
        (!DHP_model_DW.Delay1_DSTATE_er)) {
      DHP_model_B.Switch4_o = KDHP_PwrLimit1_basisSpd;
    } else if (rtb_Switch6) {
      /* Switch: '<S1932>/Switch11' incorporates:
       *  Constant: '<S1788>/KDHP_Pwr_limit'
       */
      DHP_model_B.Switch4_o = ((uint8_T)KDHP_MCUMOTTUPRATEPOWERLIMIT_PCT);
    } else {
      DHP_model_B.Switch4_o = KDHP_PwrLimit2_basisSpd;
    }

    /* End of Switch: '<S1932>/Switch5' */
  } else {
    DHP_model_B.Switch4_o = 100U;
  }

  /* End of Switch: '<S1932>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S1932>/DHP_systemtick_Timer' */

  /* RelationalOperator: '<S1932>/Relational Operator' incorporates:
   *  Constant: '<S1932>/Constant4'
   *  Constant: '<S1932>/Constant6'
   */
  DHP_model_DHP_systemtick_Timer_c(DHP_model_B.Switch4_o ==
    KDHP_PwrLimit1_basisSpd, VDHP_deltaSystemTick_ms,
    KDHP_WaitMoreForFltSecond_ms, &DHP_model_B.DHP_systemtick_Timer_kgu,
    &DHP_model_DW.DHP_systemtick_Timer_kgu);

  /* End of Outputs for SubSystem: '<S1932>/DHP_systemtick_Timer' */

  /* Logic: '<S1932>/Logical Operator2' */
  rtb_LogicalOperator2_oj2 = !rtb_Switch1;

  /* Switch: '<S1932>/Switch10' incorporates:
   *  Constant: '<S1932>/Constant13'
   *  Delay: '<S1932>/Delay6'
   *  Logic: '<S1932>/Logical Operator3'
   *  Switch: '<S1932>/Switch7'
   */
  if (rtb_LogicalOperator2_oj2 || VDHP_NMSleepInd_flg) {
    rtb_Switch10_h = false;
  } else {
    rtb_Switch10_h = (DHP_model_B.DHP_systemtick_Timer_kgu.RelationalOperator ||
                      DHP_model_DW.Delay6_DSTATE_p);
  }

  /* End of Switch: '<S1932>/Switch10' */

  /* Switch: '<S1932>/Switch2' incorporates:
   *  Constant: '<S1788>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1932>/Constant1'
   */
  if (rtb_Switch1) {
    DHP_model_B.Switch2_d = ((uint16_T)KDHP_MCUMOTTUPRATEHANDLERESPONSEBITS);
  } else {
    DHP_model_B.Switch2_d = 0U;
  }

  /* End of Switch: '<S1932>/Switch2' */

  /* Switch: '<S1932>/Switch3' incorporates:
   *  Constant: '<S1788>/KDHP_Spd_Limit'
   *  Constant: '<S1932>/Constant2'
   */
  if (rtb_Switch6) {
    DHP_model_B.Switch3_o = ((uint8_T)KDHP_MCUMOTTUPRATESPDLIMIT);
  } else {
    DHP_model_B.Switch3_o = 200U;
  }

  /* End of Switch: '<S1932>/Switch3' */

  /* Switch: '<S1932>/Switch9' incorporates:
   *  Switch: '<S1932>/Switch8'
   */
  if (VDHP_NMSleepInd_flg) {
    /* Update for Delay: '<S1932>/Delay1' incorporates:
     *  Constant: '<S1932>/Constant12'
     */
    DHP_model_DW.Delay1_DSTATE_er = false;
  } else if (rtb_LogicalOperator2_oj2) {
    /* Switch: '<S1932>/Switch8' incorporates:
     *  Update for Delay: '<S1932>/Delay1'
     */
    DHP_model_DW.Delay1_DSTATE_er =
      DHP_model_B.DHP_systemtick_Timer_kgu.RelationalOperator;
  } else {
    /* Update for Delay: '<S1932>/Delay1' incorporates:
     *  Switch: '<S1932>/Switch8'
     */
    DHP_model_DW.Delay1_DSTATE_er = rtb_Switch10_h;
  }

  /* End of Switch: '<S1932>/Switch9' */

  /* Switch: '<S1931>/Switch2' incorporates:
   *  Constant: '<S1788>/Constant2'
   *  Constant: '<S1788>/KDHP_Fault_Level'
   *  Constant: '<S1931>/Constant'
   *  Logic: '<S1931>/Logical Operator'
   */
  if (KDHP_MCUMotTUpRateActionSwitchOpen_flg && DHP_model_B.Switch2_h) {
    DHP_model_B.Switch2_bc = ((uint8_T)KDHP_MCUMOTTUPRATEFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_bc = 0U;
  }

  /* End of Switch: '<S1931>/Switch2' */

  /* Update for Delay: '<S1933>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_h = rtb_RelationalOperator1_ho;

  /* Update for Delay: '<S1933>/Delay' */
  DHP_model_DW.Delay_DSTATE_f0 = VDHP_MCUTUpRateInstFlt_flg;

  /* Update for Delay: '<S1933>/Delay1' incorporates:
   *  Sum: '<S1933>/Add2'
   */
  DHP_model_DW.Delay1_DSTATE = qY_0;

  /* Update for Delay: '<S1933>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_b = rtb_Switch8_c4;

  /* Update for Delay: '<S1933>/Delay7' incorporates:
   *  Sum: '<S1933>/Add6'
   */
  DHP_model_DW.Delay7_DSTATE = rtb_LogicalOperator3_k2_0;

  /* Update for Delay: '<S1933>/Delay2' incorporates:
   *  Sum: '<S1933>/Add3'
   */
  DHP_model_DW.Delay2_DSTATE = qY;

  /* Update for Delay: '<S1933>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_f = rtb_LogicalOperator3_ox;

  /* Update for Delay: '<S1932>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_f = rtb_Switch6;

  /* Update for Delay: '<S1932>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_n = rtb_LogicalOperator4_af;

  /* Update for Delay: '<S1932>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_p = rtb_Switch10_h;
}

/* Output and update for atomic system: '<S1750>/MCUOverT' */
void DHP_model_MCUOverT(void)
{
  /* Outputs for Atomic SubSystem: '<S1935>/Fault_Valid_RT' */

  /* Constant: '<S1789>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1789>/Constant2'
   *  Constant: '<S1789>/KDHP_Fault_Level'
   *  Constant: '<S1789>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1789>/KDHP_Pwr_limit'
   *  Constant: '<S1789>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUOverTInstFlt_Flg,
    KDHP_MCUOVERTALLOWRECOVERY_FLG, ((uint8_T)KDHP_MCUOVERTFAULTLEVEL_ENUM),
    ((uint8_T)KDHP_MCUOVERTSPDLIMIT), ((uint8_T)KDHP_MCUOVERTPOWERLIMIT_PCT),
    ((uint16_T)KDHP_MCUOVERTHANDLERESPONSEBITS),
    KDHP_MCUOverTActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_bne,
    &DHP_model_DW.Fault_Valid_RT_bne);

  /* End of Outputs for SubSystem: '<S1935>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUPhaACCrrtSnsrRati' */
void DHP_model_MCUPhaACCrrtSnsrRati(void)
{
  /* Outputs for Atomic SubSystem: '<S1938>/Fault_Valid_RT' */

  /* Constant: '<S1790>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1790>/Constant2'
   *  Constant: '<S1790>/KDHP_Fault_Level'
   *  Constant: '<S1790>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1790>/KDHP_Pwr_limit'
   *  Constant: '<S1790>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_MCUPhaACCrrtSnsrRatiInstFlt_Flg,
    KDHP_MCUPHAACCRRTSNSRRATIALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUPHAACCRRTSNSRRATIFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUPHAACCRRTSNSRRATISPDLIMIT), ((uint8_T)
    KDHP_MCUPHAACCRRTSNSRRATIPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUPHAACCRRTSNSRRATIHANDLERESPONSEBITS),
    KDHP_MCUPhaACCrrtSnsrRatiActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_ag, &DHP_model_DW.Fault_Valid_RT_ag);

  /* End of Outputs for SubSystem: '<S1938>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUPhaseLoss' */
void DHP_model_MCUPhaseLoss(void)
{
  /* Outputs for Atomic SubSystem: '<S1941>/Fault_Valid_RT' */

  /* Constant: '<S1791>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1791>/Constant2'
   *  Constant: '<S1791>/KDHP_Fault_Level'
   *  Constant: '<S1791>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1791>/KDHP_Pwr_limit'
   *  Constant: '<S1791>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUPhaseLossInstFlt_Flg,
    KDHP_MCUPHASELOSSALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUPHASELOSSFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUPHASELOSSSPDLIMIT),
    ((uint8_T)KDHP_MCUPHASELOSSPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUPHASELOSSHANDLERESPONSEBITS), KDHP_MCUPhaseLossActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_co, &DHP_model_DW.Fault_Valid_RT_co);

  /* End of Outputs for SubSystem: '<S1941>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUPwrModRedund' */
void DHP_model_MCUPwrModRedund(void)
{
  /* Outputs for Atomic SubSystem: '<S1944>/Fault_Valid_Time' */

  /* Constant: '<S1792>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S1792>/Constant2'
   *  Constant: '<S1792>/KDHP_Allow_Recover'
   *  Constant: '<S1792>/KDHP_Clear_Time'
   *  Constant: '<S1792>/KDHP_Fault_Level'
   *  Constant: '<S1792>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1792>/KDHP_Pwr_limit'
   *  Constant: '<S1792>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_MCUPwrModRedundInstFlt_flg, ((uint16_T)
    KDHP_MCUPWRMODREDUNDCONFIRMTIME_MS), ((uint16_T)
    KDHP_MCUPWRMODREDUNDCLEARTIME_MS), KDHP_MCUPWRMODREDUNDALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_MCUPWRMODREDUNDFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUPWRMODREDUNDSPDLIMIT), ((uint8_T)KDHP_MCUPWRMODREDUNDPOWERLIMIT_PCT),
    ((uint16_T)KDHP_MCUPWRMODREDUNDHANDLERESPONSEBITS),
    KDHP_MCUPwrModRedundActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_a0,
    &DHP_model_DW.Fault_Valid_Time_a0);

  /* End of Outputs for SubSystem: '<S1944>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S1750>/MCUTSnsrRati' */
void DHP_model_MCUTSnsrRati(void)
{
  /* Outputs for Atomic SubSystem: '<S1949>/Fault_Valid_RT' */

  /* Constant: '<S1793>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1793>/Constant2'
   *  Constant: '<S1793>/KDHP_Fault_Level'
   *  Constant: '<S1793>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1793>/KDHP_Pwr_limit'
   *  Constant: '<S1793>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUTSnsrRatiInstFlt_Flg,
    KDHP_MCUTSNSRRATIALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUTSNSRRATIFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUTSNSRRATISPDLIMIT),
    ((uint8_T)KDHP_MCUTSNSRRATIPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUTSNSRRATIHANDLERESPONSEBITS), KDHP_MCUTSnsrRatiActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_ewi, &DHP_model_DW.Fault_Valid_RT_ewi);

  /* End of Outputs for SubSystem: '<S1949>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUTorqCheckErr' */
void DHP_model_MCUTorqCheckErr(void)
{
  /* Outputs for Atomic SubSystem: '<S1952>/Fault_Valid_RT' */

  /* Constant: '<S1794>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1794>/Constant2'
   *  Constant: '<S1794>/KDHP_Fault_Level'
   *  Constant: '<S1794>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1794>/KDHP_Pwr_limit'
   *  Constant: '<S1794>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg, VDHP_MCUTorqCheckInstFlt_Flg,
    KDHP_MCUTORQCHECKERRALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_MCUTORQCHECKERRFAULTLEVEL_ENUM), ((uint8_T)KDHP_MCUTORQCHECKERRSPDLIMIT),
    ((uint8_T)KDHP_MCUTORQCHECKERRPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUTORQCHECKERRHANDLERESPONSEBITS),
    KDHP_MCUTorqCheckErrActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_id,
    &DHP_model_DW.Fault_Valid_RT_id);

  /* End of Outputs for SubSystem: '<S1952>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUTorqOuterRange' */
void DHP_model_MCUTorqOuterRange(void)
{
  /* Outputs for Atomic SubSystem: '<S1955>/Fault_Valid_RT' */

  /* Constant: '<S1795>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1795>/Constant2'
   *  Constant: '<S1795>/KDHP_Fault_Level'
   *  Constant: '<S1795>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1795>/KDHP_Pwr_limit'
   *  Constant: '<S1795>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_MCUTorqOuterRangeInstFlt_Flg, KDHP_MCUTORQOUTERRANGEALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_MCUTORQOUTERRANGEFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUTORQOUTERRANGESPDLIMIT), ((uint8_T)
    KDHP_MCUTORQOUTERRANGEPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUTORQOUTERRANGEHANDLERESPONSEBITS),
    KDHP_MCUTorqOuterRangeActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_kl,
    &DHP_model_DW.Fault_Valid_RT_kl);

  /* End of Outputs for SubSystem: '<S1955>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S1750>/MCUVersionMismatch' */
void DHP_model_MCUVersionMismatch(void)
{
  /* Outputs for Atomic SubSystem: '<S1958>/Fault_Valid_RT' */

  /* Constant: '<S1796>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S1796>/Constant2'
   *  Constant: '<S1796>/KDHP_Fault_Level'
   *  Constant: '<S1796>/KDHP_Handle_Response_Bits'
   *  Constant: '<S1796>/KDHP_Pwr_limit'
   *  Constant: '<S1796>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_MCUVersionMismatchInstFlt_Flg, KDHP_MCUVERSIONMISMATCHALLOWRECOVERY_FLG,
    ((uint8_T)KDHP_MCUVERSIONMISMATCHFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_MCUVERSIONMISMATCHSPDLIMIT), ((uint8_T)
    KDHP_MCUVERSIONMISMATCHPOWERLIMIT_PCT), ((uint16_T)
    KDHP_MCUVERSIONMISMATCHHANDLERESPONSEBITS),
    KDHP_MCUVersionMismatchActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_RT_de,
    &DHP_model_DW.Fault_Valid_RT_de);

  /* End of Outputs for SubSystem: '<S1958>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S14>/MCU_Fault' */
void DHP_model_MCU_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S1750>/MCUCANBusOff' */
  DHP_model_MCUCANBusOff();

  /* End of Outputs for SubSystem: '<S1750>/MCUCANBusOff' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUCANCom' */
  DHP_model_MCUCANCom();

  /* End of Outputs for SubSystem: '<S1750>/MCUCANCom' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUChipPowerFlt' */
  DHP_model_MCUChipPowerFlt();

  /* End of Outputs for SubSystem: '<S1750>/MCUChipPowerFlt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUCoverFlt' */
  DHP_model_MCUCoverFlt();

  /* End of Outputs for SubSystem: '<S1750>/MCUCoverFlt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUCoverWarn' */
  DHP_model_MCUCoverWarn();

  /* End of Outputs for SubSystem: '<S1750>/MCUCoverWarn' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDCUOverUHWFlt' */
  DHP_model_MCUDCUOverUHWFlt();

  /* End of Outputs for SubSystem: '<S1750>/MCUDCUOverUHWFlt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDCUShoCirc' */
  DHP_model_MCUDCUShoCirc();

  /* End of Outputs for SubSystem: '<S1750>/MCUDCUShoCirc' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDcCrrtOverRedund' */
  DHP_model_MCUDcCrrtOverRedund();

  /* End of Outputs for SubSystem: '<S1750>/MCUDcCrrtOverRedund' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDcUOverUFlt' */
  DHP_model_MCUDcUOverUFlt();

  /* End of Outputs for SubSystem: '<S1750>/MCUDcUOverUFlt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDcUOverURedund' */
  DHP_model_MCUDcUOverURedund();

  /* End of Outputs for SubSystem: '<S1750>/MCUDcUOverURedund' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDcUOverUWarn' */
  DHP_model_MCUDcUOverUWarn();

  /* End of Outputs for SubSystem: '<S1750>/MCUDcUOverUWarn' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDcUSnsrRati' */
  DHP_model_MCUDcUSnsrRati();

  /* End of Outputs for SubSystem: '<S1750>/MCUDcUSnsrRati' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDcUUnderUFlt' */
  DHP_model_MCUDcUUnderUFlt();

  /* End of Outputs for SubSystem: '<S1750>/MCUDcUUnderUFlt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDcUUnderUWarn' */
  DHP_model_MCUDcUUnderUWarn();

  /* End of Outputs for SubSystem: '<S1750>/MCUDcUUnderUWarn' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUDischrg' */
  DHP_model_MCUDischrg();

  /* End of Outputs for SubSystem: '<S1750>/MCUDischrg' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUElecMotOverCrrt' */
  DHP_model_MCUElecMotOverCrrt();

  /* End of Outputs for SubSystem: '<S1750>/MCUElecMotOverCrrt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUElecMotOverSpdFlt' */
  DHP_model_MCUElecMotOverSpdFlt();

  /* End of Outputs for SubSystem: '<S1750>/MCUElecMotOverSpdFlt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUElecMotOverSpdWarn' */
  DHP_model_MCUElecMotOverSpdWarn();

  /* End of Outputs for SubSystem: '<S1750>/MCUElecMotOverSpdWarn' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUElecMotOverTFlt' */
  DHP_model_MCUElecMotOverTFlt();

  /* End of Outputs for SubSystem: '<S1750>/MCUElecMotOverTFlt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUElecMotOverTWarn' */
  DHP_model_MCUElecMotOverTWarn();

  /* End of Outputs for SubSystem: '<S1750>/MCUElecMotOverTWarn' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUElecMotReslv' */
  DHP_model_MCUElecMotReslv();

  /* End of Outputs for SubSystem: '<S1750>/MCUElecMotReslv' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUElecMotStopTurn' */
  DHP_model_MCUElecMotStopTurn();

  /* End of Outputs for SubSystem: '<S1750>/MCUElecMotStopTurn' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUElecMotTSnsrRati' */
  DHP_model_MCUElecMotTSnsrRati();

  /* End of Outputs for SubSystem: '<S1750>/MCUElecMotTSnsrRati' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUElecMotUnderT' */
  DHP_model_MCUElecMotUnderT();

  /* End of Outputs for SubSystem: '<S1750>/MCUElecMotUnderT' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUFlt1' */
  DHP_model_MCUFlt1();

  /* End of Outputs for SubSystem: '<S1750>/MCUFlt1' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUFlt2' */
  DHP_model_MCUFlt2();

  /* End of Outputs for SubSystem: '<S1750>/MCUFlt2' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUFlt3' */
  DHP_model_MCUFlt3();

  /* End of Outputs for SubSystem: '<S1750>/MCUFlt3' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUFltUnmatch' */
  DHP_model_MCUFltUnmatch();

  /* End of Outputs for SubSystem: '<S1750>/MCUFltUnmatch' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUHWSamplingFlt' */
  DHP_model_MCUHWSamplingFlt();

  /* End of Outputs for SubSystem: '<S1750>/MCUHWSamplingFlt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUHwCurrOver' */
  DHP_model_MCUHwCurrOver();

  /* End of Outputs for SubSystem: '<S1750>/MCUHwCurrOver' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUHwCurrOverRedund' */
  DHP_model_MCUHwCurrOverRedund();

  /* End of Outputs for SubSystem: '<S1750>/MCUHwCurrOverRedund' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUIGBTHW' */
  DHP_model_MCUIGBTHW();

  /* End of Outputs for SubSystem: '<S1750>/MCUIGBTHW' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUIGBTOverTFlt' */
  DHP_model_MCUIGBTOverTFlt();

  /* End of Outputs for SubSystem: '<S1750>/MCUIGBTOverTFlt' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUIGBTOverTWarn' */
  DHP_model_MCUIGBTOverTWarn();

  /* End of Outputs for SubSystem: '<S1750>/MCUIGBTOverTWarn' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUIGBTUnderT' */
  DHP_model_MCUIGBTUnderT();

  /* End of Outputs for SubSystem: '<S1750>/MCUIGBTUnderT' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUIGBTphaseTCheckErr' */
  DHP_model_MCUIGBTphaseTCheckErr();

  /* End of Outputs for SubSystem: '<S1750>/MCUIGBTphaseTCheckErr' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCULowBattUnderU' */
  DHP_model_MCULowBattUnderU();

  /* End of Outputs for SubSystem: '<S1750>/MCULowBattUnderU' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUMotTUpRate' */
  DHP_model_MCUMotTUpRate();

  /* End of Outputs for SubSystem: '<S1750>/MCUMotTUpRate' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUOverT' */
  DHP_model_MCUOverT();

  /* End of Outputs for SubSystem: '<S1750>/MCUOverT' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUPhaACCrrtSnsrRati' */
  DHP_model_MCUPhaACCrrtSnsrRati();

  /* End of Outputs for SubSystem: '<S1750>/MCUPhaACCrrtSnsrRati' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUPhaseLoss' */
  DHP_model_MCUPhaseLoss();

  /* End of Outputs for SubSystem: '<S1750>/MCUPhaseLoss' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUPwrModRedund' */
  DHP_model_MCUPwrModRedund();

  /* End of Outputs for SubSystem: '<S1750>/MCUPwrModRedund' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUTSnsrRati' */
  DHP_model_MCUTSnsrRati();

  /* End of Outputs for SubSystem: '<S1750>/MCUTSnsrRati' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUTorqCheckErr' */
  DHP_model_MCUTorqCheckErr();

  /* End of Outputs for SubSystem: '<S1750>/MCUTorqCheckErr' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUTorqOuterRange' */
  DHP_model_MCUTorqOuterRange();

  /* End of Outputs for SubSystem: '<S1750>/MCUTorqOuterRange' */

  /* Outputs for Atomic SubSystem: '<S1750>/MCUVersionMismatch' */
  DHP_model_MCUVersionMismatch();

  /* End of Outputs for SubSystem: '<S1750>/MCUVersionMismatch' */
}

/* Output and update for function-call system: '<S4>/VehDriveSysErrValid' */
void DHP_model_VehDriveSysErrValid(void)
{
  /* Outputs for Atomic SubSystem: '<S14>/MCU_Fault' */
  DHP_model_MCU_Fault();

  /* End of Outputs for SubSystem: '<S14>/MCU_Fault' */
}

/* Output and update for atomic system: '<S2175>/BMSBattOverT' */
void DHP_model_BMSBattOverT(void)
{
  /* Outputs for Atomic SubSystem: '<S2186>/Fault_Valid_Time' */

  /* Constant: '<S2176>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2176>/Constant2'
   *  Constant: '<S2176>/KDHP_Allow_Recover'
   *  Constant: '<S2176>/KDHP_Clear_Time'
   *  Constant: '<S2176>/KDHP_Fault_Level'
   *  Constant: '<S2176>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2176>/KDHP_Pwr_limit'
   *  Constant: '<S2176>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_BMSBatt_OverTFlt_flg, ((uint16_T)KDHP_BMSBATTOVERTCONFIRMTIME_MS),
    ((uint16_T)KDHP_BMSBATTOVERTCLEARTIME_MS),
    KDHP_BMSBATTOVERTALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BMSBATTOVERTFAULTLEVEL_ENUM), ((uint8_T)KDHP_BMSBATTOVERTSPDLIMIT),
    ((uint8_T)KDHP_BMSBATTOVERTPOWERLIMIT_PCT), ((uint16_T)
    KDHP_BMSBATTOVERTHANDLERESPONSEBITS), KDHP_BMSBattOverTActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_cb, &DHP_model_DW.Fault_Valid_Time_cb);

  /* End of Outputs for SubSystem: '<S2186>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S2175>/BMSCellOverU' */
void DHP_model_BMSCellOverU(void)
{
  /* Outputs for Atomic SubSystem: '<S2191>/Fault_Valid_Time' */

  /* Constant: '<S2177>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2177>/Constant2'
   *  Constant: '<S2177>/KDHP_Allow_Recover'
   *  Constant: '<S2177>/KDHP_Clear_Time'
   *  Constant: '<S2177>/KDHP_Fault_Level'
   *  Constant: '<S2177>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2177>/KDHP_Pwr_limit'
   *  Constant: '<S2177>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_BMSCell_OverUFlt_flg, ((uint16_T)KDHP_BMSCELLOVERUCONFIRMTIME_MS),
    ((uint16_T)KDHP_BMSCELLOVERUCLEARTIME_MS),
    KDHP_BMSCELLOVERUALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BMSCELLOVERUFAULTLEVEL_ENUM), ((uint8_T)KDHP_BMSCELLOVERUSPDLIMIT),
    ((uint8_T)KDHP_BMSCELLOVERUPOWERLIMIT_PCT), ((uint16_T)
    KDHP_BMSCELLOVERUHANDLERESPONSEBITS), KDHP_BMSCellOverUActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_Time_gy, &DHP_model_DW.Fault_Valid_Time_gy);

  /* End of Outputs for SubSystem: '<S2191>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S2175>/BMSCellUnderU' */
void DHP_model_BMSCellUnderU(void)
{
  /* Outputs for Atomic SubSystem: '<S2196>/Fault_Valid_Time' */

  /* Constant: '<S2178>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2178>/Constant2'
   *  Constant: '<S2178>/KDHP_Allow_Recover'
   *  Constant: '<S2178>/KDHP_Clear_Time'
   *  Constant: '<S2178>/KDHP_Fault_Level'
   *  Constant: '<S2178>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2178>/KDHP_Pwr_limit'
   *  Constant: '<S2178>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_BMSCell_UnderUFlt_flg, ((uint16_T)KDHP_BMSCELLUNDERUCONFIRMTIME_MS),
    ((uint16_T)KDHP_BMSCELLUNDERUCLEARTIME_MS),
    KDHP_BMSCELLUNDERUALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BMSCELLUNDERUFAULTLEVEL_ENUM), ((uint8_T)KDHP_BMSCELLUNDERUSPDLIMIT),
    ((uint8_T)KDHP_BMSCELLUNDERUPOWERLIMIT_PCT), ((uint16_T)
    KDHP_BMSCELLUNDERUHANDLERESPONSEBITS),
    KDHP_BMSCellUnderUActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_fa,
    &DHP_model_DW.Fault_Valid_Time_fa);

  /* End of Outputs for SubSystem: '<S2196>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S2175>/BMSDischrgPwrAbnormal' */
void DHP_model_BMSDischrgPwrAbnormal(void)
{
  /* Outputs for Atomic SubSystem: '<S2201>/Fault_Valid_RT' */

  /* Constant: '<S2179>/KDHP_Allow_Recover' incorporates:
   *  Constant: '<S2179>/Constant2'
   *  Constant: '<S2179>/KDHP_Fault_Level'
   *  Constant: '<S2179>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2179>/KDHP_Pwr_limit'
   *  Constant: '<S2179>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_RT(VDHP_NMSleepInd_flg,
    VDHP_BMSDischrgPwrAbnormalInstFlt_flg,
    KDHP_BMSDISCHRGPWRABNORMALALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BMSDISCHRGPWRABNORMALFAULTLEVEL_ENUM), ((uint8_T)
    KDHP_BMSDISCHRGPWRABNORMALSPDLIMIT), ((uint8_T)
    KDHP_BMSDISCHRGPWRABNORMALPOWERLIMIT_PCT), ((uint16_T)
    KDHP_BMSDISCHRGPWRABNORMALHANDLERESPONSEBITS),
    KDHP_BMSDischrgPwrAbnormalActionSwitchOpen_flg,
    &DHP_model_B.Fault_Valid_RT_my, &DHP_model_DW.Fault_Valid_RT_my);

  /* End of Outputs for SubSystem: '<S2201>/Fault_Valid_RT' */
}

/* Output and update for atomic system: '<S2175>/BMSFlt2' */
void DHP_model_BMSFlt2(void)
{
  boolean_T rtb_Switch3;
  boolean_T rtb_LogicalOperator2_j2;
  boolean_T rtb_Switch9;
  boolean_T rtb_Switch1;
  boolean_T rtb_Switch1_c;

  /* Logic: '<S2206>/Logical Operator2' incorporates:
   *  Delay: '<S2206>/Delay3'
   *  Logic: '<S2206>/Logical Operator1'
   */
  rtb_LogicalOperator2_j2 = (((!(VDHP_BMSInstFlt2_RecoveryFlg ||
    VDHP_NMSleepInd_flg)) && DHP_model_DW.Delay3_DSTATE_j) ||
    VDHP_BMSInstFlt2_flg);

  /* Switch: '<S2206>/Switch1' incorporates:
   *  Constant: '<S2206>/Constant1'
   *  Constant: '<S2206>/Constant4'
   *  Constant: '<S2207>/Constant12'
   *  Constant: '<S2207>/Constant4'
   *  Delay: '<S2206>/Delay1'
   *  Delay: '<S2207>/Delay1'
   *  Switch: '<S2206>/Switch3'
   *  Switch: '<S2206>/Switch6'
   *  Switch: '<S2207>/Switch1'
   *  Switch: '<S2207>/Switch6'
   *  Switch: '<S2207>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch1 = false;
    rtb_Switch3 = false;
    rtb_Switch1_c = false;
    rtb_Switch9 = false;
  } else {
    rtb_Switch1 = (rtb_LogicalOperator2_j2 || DHP_model_DW.Delay1_DSTATE_e);

    /* Switch: '<S2206>/Switch5' incorporates:
     *  Constant: '<S2180>/KDHP_Allow_Recover'
     *  Delay: '<S2206>/Delay1'
     *  Switch: '<S2206>/Switch6'
     */
    if (KDHP_BMSFLT2ALLOWRECOVERY_FLG) {
      rtb_Switch3 = rtb_LogicalOperator2_j2;
    } else {
      rtb_Switch3 = rtb_Switch1;
    }

    /* End of Switch: '<S2206>/Switch5' */
    rtb_Switch1_c = (VDHP_BMSInstFlt2_NoErrNum || DHP_model_DW.Delay1_DSTATE_g);

    /* Switch: '<S2207>/Switch8' incorporates:
     *  Constant: '<S2180>/KDHP_Allow_Recover'
     *  Delay: '<S2207>/Delay1'
     *  Switch: '<S2207>/Switch6'
     */
    if (KDHP_BMSFLT2ALLOWRECOVERY_FLG) {
      rtb_Switch9 = VDHP_BMSInstFlt2_NoErrNum;
    } else {
      rtb_Switch9 = rtb_Switch1_c;
    }

    /* End of Switch: '<S2207>/Switch8' */
  }

  /* End of Switch: '<S2206>/Switch1' */

  /* Switch: '<S2205>/Switch2' incorporates:
   *  Constant: '<S2180>/Constant2'
   *  Constant: '<S2180>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2180>/KDHP_Pwr_limit'
   *  Constant: '<S2180>/KDHP_Spd_Limit'
   *  Constant: '<S2205>/Constant1'
   *  Constant: '<S2205>/Constant2'
   *  Constant: '<S2205>/Constant3'
   *  Switch: '<S2205>/Switch3'
   *  Switch: '<S2205>/Switch4'
   *  Switch: '<S2205>/Switch50'
   */
  if (KDHP_BMSFlt2ActionSwitchOpen_flg && rtb_Switch3) {
    DHP_model_B.Switch2_e = ((uint16_T)KDHP_BMSFLT2HANDLERESPONSEBITS);
    DHP_model_B.Switch3_c = ((uint8_T)KDHP_BMSFLT2SPDLIMIT);
    DHP_model_B.Switch4_f = ((uint8_T)KDHP_BMSFLT2POWERLIMIT_PCT);
  } else {
    DHP_model_B.Switch2_e = 0U;
    DHP_model_B.Switch3_c = 200U;
    DHP_model_B.Switch4_f = 100U;
  }

  /* End of Switch: '<S2205>/Switch2' */

  /* Logic: '<S2204>/Logical Operator1' */
  DHP_model_B.LogicalOperator1_e = (rtb_Switch3 || rtb_Switch9);

  /* Switch: '<S2204>/Switch2' incorporates:
   *  Constant: '<S2180>/Constant2'
   *  Constant: '<S2180>/KDHP_Fault_Level'
   *  Constant: '<S2204>/Constant'
   *  Logic: '<S2204>/Logical Operator'
   */
  if (KDHP_BMSFlt2ActionSwitchOpen_flg && DHP_model_B.LogicalOperator1_e) {
    DHP_model_B.Switch2_a = ((uint8_T)KDHP_BMSFLT2FAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_a = 0U;
  }

  /* End of Switch: '<S2204>/Switch2' */

  /* Update for Delay: '<S2206>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_j = rtb_LogicalOperator2_j2;

  /* Update for Delay: '<S2206>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_e = rtb_Switch1;

  /* Update for Delay: '<S2207>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_g = rtb_Switch1_c;
}

/* Output and update for atomic system: '<S2175>/BMSFlt3' */
void DHP_model_BMSFlt3(void)
{
  boolean_T rtb_Switch3;
  boolean_T rtb_LogicalOperator2_oj;
  boolean_T rtb_Switch50;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator25_l;
  boolean_T rtb_LogicalOperator3_pe;
  boolean_T rtb_RelationalOperator4_ez;
  boolean_T rtb_Switch1;
  boolean_T rtb_Switch9;
  boolean_T rtb_Switch11_ft;
  boolean_T rtb_Switch13_h;

  /* Logic: '<S2210>/Logical Operator2' incorporates:
   *  Delay: '<S2210>/Delay3'
   *  Logic: '<S2210>/Logical Operator1'
   */
  rtb_LogicalOperator2_oj = (((!(VDHP_BMSInstFlt3_RecoveryFlg ||
    VDHP_NMSleepInd_flg)) && DHP_model_DW.Delay3_DSTATE_b) ||
    VDHP_BMSInstFlt3_flg);

  /* Switch: '<S2210>/Switch1' incorporates:
   *  Constant: '<S2210>/Constant12'
   *  Constant: '<S2210>/Constant4'
   *  Delay: '<S2210>/Delay1'
   *  Switch: '<S2210>/Switch3'
   *  Switch: '<S2210>/Switch6'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch1 = false;
    rtb_Switch3 = false;
  } else {
    rtb_Switch1 = (rtb_LogicalOperator2_oj || DHP_model_DW.Delay1_DSTATE_c);

    /* Switch: '<S2210>/Switch5' incorporates:
     *  Constant: '<S2181>/KDHP_Allow_Recover'
     *  Delay: '<S2210>/Delay1'
     *  Switch: '<S2210>/Switch6'
     */
    if (KDHP_BMSFLT3ALLOWRECOVERY_FLG) {
      rtb_Switch3 = rtb_LogicalOperator2_oj;
    } else {
      rtb_Switch3 = rtb_Switch1;
    }

    /* End of Switch: '<S2210>/Switch5' */
  }

  /* End of Switch: '<S2210>/Switch1' */

  /* Switch: '<S2209>/Switch50' incorporates:
   *  Constant: '<S2181>/Constant2'
   */
  rtb_Switch50 = (KDHP_BMSFlt3ActionSwitchOpen_flg && rtb_Switch3);

  /* Logic: '<S2209>/Logical Operator1' incorporates:
   *  Delay: '<S2209>/Delay2'
   *  Logic: '<S2209>/Logical Operator2'
   */
  rtb_LogicalOperator1 = ((!DHP_model_DW.Delay2_DSTATE_i) && rtb_Switch50);

  /* Logic: '<S2209>/Logical Operator25' incorporates:
   *  Constant: '<S2216>/Constant'
   *  Constant: '<S2217>/Constant'
   *  Constant: '<S2218>/Constant'
   *  Constant: '<S2219>/Constant'
   *  Constant: '<S2220>/Constant'
   *  Constant: '<S2221>/Constant'
   *  Constant: '<S2222>/Constant'
   *  Logic: '<S2209>/Logical Operator19'
   *  RelationalOperator: '<S2216>/Compare'
   *  RelationalOperator: '<S2217>/Compare'
   *  RelationalOperator: '<S2218>/Compare'
   *  RelationalOperator: '<S2219>/Compare'
   *  RelationalOperator: '<S2220>/Compare'
   *  RelationalOperator: '<S2221>/Compare'
   *  RelationalOperator: '<S2222>/Compare'
   */
  rtb_LogicalOperator25_l = ((DHP_model_B.VINP_BMSErrNum == 63) ||
    (DHP_model_B.VINP_BMSErrNum == 88) || ((DHP_model_B.VINP_BMSErrNum >= 90) &&
    (DHP_model_B.VINP_BMSErrNum <= 92)) || (DHP_model_B.VINP_BMSErrNum == 95) ||
    (DHP_model_B.VINP_BMSErrNum == 97) || (DHP_model_B.VINP_BMSErrNum == 98));

  /* Logic: '<S2209>/Logical Operator3' incorporates:
   *  Constant: '<S2212>/Constant'
   *  Constant: '<S2213>/Constant'
   *  Constant: '<S2214>/Constant'
   *  Constant: '<S2215>/Constant'
   *  RelationalOperator: '<S2212>/Compare'
   *  RelationalOperator: '<S2213>/Compare'
   *  RelationalOperator: '<S2214>/Compare'
   *  RelationalOperator: '<S2215>/Compare'
   */
  rtb_LogicalOperator3_pe = ((DHP_model_B.VINP_BMSErrNum == 4) ||
    (DHP_model_B.VINP_BMSErrNum == 58) || (DHP_model_B.VINP_BMSErrNum == 59) ||
    (DHP_model_B.VINP_BMSErrNum == 105));

  /* Switch: '<S2209>/Switch10' incorporates:
   *  Constant: '<S2209>/Constant14'
   *  Constant: '<S2209>/Constant5'
   *  Constant: '<S2209>/Constant8'
   *  Constant: '<S2224>/Constant14'
   *  Delay: '<S2209>/Delay1'
   *  Delay: '<S2209>/Delay4'
   *  Delay: '<S2224>/Delay2'
   *  Delay: '<S2224>/Delay3'
   *  Logic: '<S2209>/Logical Operator11'
   *  Logic: '<S2209>/Logical Operator12'
   *  Logic: '<S2209>/Logical Operator6'
   *  Logic: '<S2209>/Logical Operator7'
   *  Logic: '<S2224>/Logical Operator2'
   *  Logic: '<S2224>/Logical Operator3'
   *  Logic: '<S2224>/Logical Operator6'
   *  RelationalOperator: '<S2209>/Relational Operator3'
   *  Switch: '<S2209>/Switch6'
   *  Switch: '<S2224>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    DHP_model_B.Switch10 = false;
    DHP_model_B.Switch6 = false;
    rtb_Switch9 = false;
  } else {
    DHP_model_B.Switch10 = (DHP_model_B.Switch10 || (rtb_LogicalOperator1 &&
      rtb_LogicalOperator3_pe));
    DHP_model_B.Switch6 = (DHP_model_B.Switch6 || (rtb_LogicalOperator1 &&
      (DHP_model_B.Gain9 > KDHP_GradsSpeed_basisTime) && rtb_LogicalOperator25_l));
    rtb_Switch9 = (DHP_model_DW.Delay3_DSTATE_o ||
                   ((!DHP_model_DW.Delay2_DSTATE_e) && DHP_model_B.Switch6));
  }

  /* End of Switch: '<S2209>/Switch10' */

  /* Outputs for Atomic SubSystem: '<S2224>/DHP_systemtick_Timer' */

  /* Constant: '<S2224>/Constant21' */
  DHP_model_DHP_systemtick_Timer_c(rtb_Switch9, VDHP_deltaSystemTick_ms,
    KDHP_WaitTime1_GradsbasisTime_ms, &DHP_model_B.DHP_systemtick_Timer_i4,
    &DHP_model_DW.DHP_systemtick_Timer_i4);

  /* End of Outputs for SubSystem: '<S2224>/DHP_systemtick_Timer' */

  /* Switch: '<S2224>/Switch11' incorporates:
   *  Constant: '<S2224>/Constant17'
   *  Delay: '<S2224>/Delay1'
   *  Delay: '<S2224>/Delay4'
   *  Logic: '<S2224>/Logical Operator4'
   *  Logic: '<S2224>/Logical Operator5'
   *  Logic: '<S2224>/Logical Operator9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch11_ft = false;
  } else {
    rtb_Switch11_ft = (DHP_model_DW.Delay4_DSTATE_fx ||
                       ((!DHP_model_DW.Delay1_DSTATE_b) &&
                        DHP_model_B.DHP_systemtick_Timer_i4.RelationalOperator));
  }

  /* End of Switch: '<S2224>/Switch11' */

  /* Outputs for Atomic SubSystem: '<S2224>/DHP_systemtick_Timer1' */

  /* Constant: '<S2224>/Constant18' */
  DHP_model_DHP_systemtick_Timer_c(rtb_Switch11_ft, VDHP_deltaSystemTick_ms,
    KDHP_WaitTime2_GradsbasisTime_ms, &DHP_model_B.DHP_systemtick_Timer1_b,
    &DHP_model_DW.DHP_systemtick_Timer1_b);

  /* End of Outputs for SubSystem: '<S2224>/DHP_systemtick_Timer1' */

  /* RelationalOperator: '<S2224>/Relational Operator4' incorporates:
   *  Constant: '<S2224>/Constant7'
   */
  rtb_RelationalOperator4_ez = (DHP_model_B.Gain9 <= KDHP_GradsSpeed2);

  /* Switch: '<S2224>/Switch13' incorporates:
   *  Constant: '<S2209>/Constant10'
   *  Constant: '<S2209>/Constant11'
   *  Constant: '<S2224>/Constant22'
   *  Delay: '<S2209>/Delay3'
   *  Delay: '<S2224>/Delay5'
   *  Delay: '<S2224>/Delay6'
   *  Logic: '<S2209>/Logical Operator10'
   *  Logic: '<S2209>/Logical Operator4'
   *  Logic: '<S2209>/Logical Operator5'
   *  Logic: '<S2209>/Logical Operator8'
   *  Logic: '<S2209>/Logical Operator9'
   *  Logic: '<S2224>/Logical Operator10'
   *  Logic: '<S2224>/Logical Operator7'
   *  Logic: '<S2224>/Logical Operator8'
   *  RelationalOperator: '<S2209>/Relational Operator1'
   *  Switch: '<S2209>/Switch8'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch13_h = false;
    rtb_LogicalOperator1 = false;
  } else {
    rtb_Switch13_h = (DHP_model_DW.Delay6_DSTATE_m ||
                      ((!DHP_model_DW.Delay5_DSTATE) &&
                       DHP_model_B.DHP_systemtick_Timer1_b.RelationalOperator));
    rtb_LogicalOperator1 = (DHP_model_DW.Delay3_DSTATE_l ||
      (rtb_LogicalOperator1 && (!rtb_LogicalOperator3_pe) &&
       (!rtb_LogicalOperator25_l)) || (rtb_LogicalOperator1 &&
      (DHP_model_B.Gain9 <= KDHP_GradsSpeed_basisTime) &&
      rtb_LogicalOperator25_l));
  }

  /* End of Switch: '<S2224>/Switch13' */

  /* Switch: '<S2209>/Switch2' incorporates:
   *  Constant: '<S2181>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2181>/KDHP_Pwr_limit'
   *  Constant: '<S2181>/KDHP_Spd_Limit'
   *  Constant: '<S2209>/Constant1'
   *  Constant: '<S2209>/Constant2'
   *  Switch: '<S2209>/Switch11'
   *  Switch: '<S2209>/Switch12'
   *  Switch: '<S2209>/Switch13'
   *  Switch: '<S2209>/Switch14'
   *  Switch: '<S2209>/Switch3'
   *  Switch: '<S2209>/Switch4'
   *  Switch: '<S2224>/Switch14'
   *  Switch: '<S2224>/Switch2'
   */
  if (rtb_LogicalOperator1) {
    DHP_model_B.Switch2_p = ((uint16_T)KDHP_BMSFLT3HANDLERESPONSEBITS);
    DHP_model_B.Switch3_h = ((uint8_T)KDHP_BMSFLT3SPDLIMIT);
    DHP_model_B.Switch4_c = ((uint8_T)KDHP_BMSFLT3POWERLIMIT_PCT);
  } else {
    if (DHP_model_B.Switch6) {
      /* Switch: '<S2224>/Switch20' incorporates:
       *  Constant: '<S2181>/KDHP_Handle_Response_Bits'
       *  Constant: '<S2224>/Constant24'
       *  Switch: '<S2209>/Switch11'
       *  Switch: '<S2224>/Switch14'
       */
      if (rtb_Switch13_h) {
        DHP_model_B.Switch2_p = ((uint16_T)KDHP_BMSFLT3HANDLERESPONSEBITS);
      } else {
        DHP_model_B.Switch2_p = KDHP_preResponseBits_Grads;
      }

      /* End of Switch: '<S2224>/Switch20' */

      /* Switch: '<S2224>/Switch15' incorporates:
       *  Constant: '<S2181>/KDHP_Spd_Limit'
       *  Constant: '<S2224>/Constant26'
       *  Logic: '<S2224>/Logical Operator11'
       *  Switch: '<S2209>/Switch13'
       */
      if (DHP_model_B.Switch6 && rtb_Switch13_h) {
        DHP_model_B.Switch3_h = ((uint8_T)KDHP_BMSFLT3SPDLIMIT);
      } else {
        DHP_model_B.Switch3_h = 200U;
      }

      /* End of Switch: '<S2224>/Switch15' */
    } else if (DHP_model_B.Switch10) {
      /* Switch: '<S2224>/Switch8' incorporates:
       *  Constant: '<S2181>/KDHP_Handle_Response_Bits'
       *  Constant: '<S2224>/Constant10'
       *  Switch: '<S2209>/Switch11'
       *  Switch: '<S2209>/Switch12'
       *  Switch: '<S2224>/Switch2'
       */
      if (rtb_RelationalOperator4_ez) {
        DHP_model_B.Switch2_p = ((uint16_T)KDHP_BMSFLT3HANDLERESPONSEBITS);
      } else {
        DHP_model_B.Switch2_p = KDHP_preResponseBits_Grads;
      }

      /* End of Switch: '<S2224>/Switch8' */

      /* Switch: '<S2224>/Switch3' incorporates:
       *  Constant: '<S2181>/KDHP_Spd_Limit'
       *  Constant: '<S2224>/Constant2'
       *  Logic: '<S2224>/Logical Operator1'
       *  Switch: '<S2209>/Switch13'
       *  Switch: '<S2209>/Switch14'
       */
      if (DHP_model_B.Switch10 && rtb_RelationalOperator4_ez) {
        DHP_model_B.Switch3_h = ((uint8_T)KDHP_BMSFLT3SPDLIMIT);
      } else {
        DHP_model_B.Switch3_h = 200U;
      }

      /* End of Switch: '<S2224>/Switch3' */
    } else {
      DHP_model_B.Switch2_p = 0U;
      DHP_model_B.Switch3_h = 200U;
    }

    /* Switch: '<S2224>/Switch16' incorporates:
     *  Constant: '<S2209>/Constant1'
     *  Constant: '<S2209>/Constant2'
     *  Constant: '<S2209>/Constant3'
     *  Switch: '<S2209>/Switch11'
     *  Switch: '<S2209>/Switch12'
     *  Switch: '<S2209>/Switch13'
     *  Switch: '<S2209>/Switch14'
     *  Switch: '<S2209>/Switch15'
     *  Switch: '<S2209>/Switch16'
     *  Switch: '<S2224>/Switch2'
     *  Switch: '<S2224>/Switch4'
     */
    if (DHP_model_B.Switch6) {
      /* Switch: '<S2224>/Switch19' incorporates:
       *  Constant: '<S2181>/KDHP_Pwr_limit'
       *  Constant: '<S2224>/Constant25'
       *  Logic: '<S2224>/Logical Operator12'
       *  Logic: '<S2224>/Logical Operator13'
       *  Logic: '<S2224>/Logical Operator14'
       *  Logic: '<S2224>/Logical Operator15'
       *  Switch: '<S2224>/Switch17'
       *  Switch: '<S2224>/Switch18'
       */
      if (rtb_Switch13_h) {
        DHP_model_B.Switch4_c = ((uint8_T)KDHP_BMSFLT3POWERLIMIT_PCT);
      } else if ((!DHP_model_B.DHP_systemtick_Timer1_b.RelationalOperator) &&
                 rtb_Switch11_ft) {
        /* Switch: '<S2224>/Switch18' incorporates:
         *  Constant: '<S2224>/Constant29'
         */
        DHP_model_B.Switch4_c = KDHP_PwrLimit2_basisTime;
      } else if ((!DHP_model_B.DHP_systemtick_Timer_i4.RelationalOperator) &&
                 rtb_Switch9) {
        /* Switch: '<S2224>/Switch17' incorporates:
         *  Constant: '<S2224>/Constant28'
         *  Switch: '<S2224>/Switch18'
         */
        DHP_model_B.Switch4_c = KDHP_PwrLimit1_basisTime;
      } else {
        DHP_model_B.Switch4_c = 100U;
      }

      /* End of Switch: '<S2224>/Switch19' */
    } else if (DHP_model_B.Switch10) {
      /* Switch: '<S2224>/Switch5' incorporates:
       *  Constant: '<S2181>/KDHP_Pwr_limit'
       *  Constant: '<S2224>/Constant11'
       *  Constant: '<S2224>/Constant4'
       *  Constant: '<S2224>/Constant5'
       *  Constant: '<S2224>/Constant6'
       *  Logic: '<S2224>/Logical Operator'
       *  RelationalOperator: '<S2224>/Relational Operator1'
       *  RelationalOperator: '<S2224>/Relational Operator2'
       *  RelationalOperator: '<S2224>/Relational Operator3'
       *  Switch: '<S2209>/Switch16'
       *  Switch: '<S2224>/Switch4'
       *  Switch: '<S2224>/Switch6'
       *  Switch: '<S2224>/Switch7'
       */
      if (rtb_RelationalOperator4_ez) {
        DHP_model_B.Switch4_c = ((uint8_T)KDHP_BMSFLT3POWERLIMIT_PCT);
      } else if ((DHP_model_B.Gain9 <= KDHP_GradsSpeed1) && (DHP_model_B.Gain9 >
                  KDHP_GradsSpeed2)) {
        /* Switch: '<S2224>/Switch6' incorporates:
         *  Constant: '<S2224>/Constant9'
         */
        DHP_model_B.Switch4_c = KDHP_PwrLimit2_basisSpd;
      } else if (DHP_model_B.Gain9 > KDHP_GradsSpeed1) {
        /* Switch: '<S2224>/Switch7' incorporates:
         *  Constant: '<S2224>/Constant8'
         *  Switch: '<S2224>/Switch6'
         */
        DHP_model_B.Switch4_c = KDHP_PwrLimit1_basisSpd;
      } else {
        DHP_model_B.Switch4_c = 100U;
      }

      /* End of Switch: '<S2224>/Switch5' */
    } else {
      DHP_model_B.Switch4_c = 100U;
    }

    /* End of Switch: '<S2224>/Switch16' */
  }

  /* End of Switch: '<S2209>/Switch2' */

  /* Logic: '<S2208>/Logical Operator1' incorporates:
   *  Switch: '<S2211>/Switch9'
   */
  DHP_model_B.LogicalOperator1_k = (rtb_Switch3 || ((!VDHP_NMSleepInd_flg) &&
    VDHP_BMSInstFlt3_NoErrNum));

  /* Switch: '<S2208>/Switch2' incorporates:
   *  Constant: '<S2181>/Constant2'
   *  Constant: '<S2181>/KDHP_Fault_Level'
   *  Constant: '<S2208>/Constant'
   *  Logic: '<S2208>/Logical Operator'
   */
  if (KDHP_BMSFlt3ActionSwitchOpen_flg && DHP_model_B.LogicalOperator1_k) {
    DHP_model_B.Switch2_d5d = ((uint8_T)KDHP_BMSFLT3FAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_d5d = 0U;
  }

  /* End of Switch: '<S2208>/Switch2' */

  /* Update for Delay: '<S2209>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_i = rtb_Switch50;

  /* Update for Delay: '<S2209>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_l = rtb_LogicalOperator1;

  /* Update for Delay: '<S2210>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_b = rtb_LogicalOperator2_oj;

  /* Update for Delay: '<S2210>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_c = rtb_Switch1;

  /* Update for Delay: '<S2224>/Delay6' */
  DHP_model_DW.Delay6_DSTATE_m = rtb_Switch13_h;

  /* Update for Delay: '<S2224>/Delay5' */
  DHP_model_DW.Delay5_DSTATE =
    DHP_model_B.DHP_systemtick_Timer1_b.RelationalOperator;

  /* Update for Delay: '<S2224>/Delay4' */
  DHP_model_DW.Delay4_DSTATE_fx = rtb_Switch11_ft;

  /* Update for Delay: '<S2224>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_b =
    DHP_model_B.DHP_systemtick_Timer_i4.RelationalOperator;

  /* Update for Delay: '<S2224>/Delay3' */
  DHP_model_DW.Delay3_DSTATE_o = rtb_Switch9;

  /* Update for Delay: '<S2224>/Delay2' */
  DHP_model_DW.Delay2_DSTATE_e = DHP_model_B.Switch6;
}

/* Output and update for atomic system: '<S2175>/BMSFlt4' */
void DHP_model_BMSFlt4(void)
{
  boolean_T rtb_Switch9;
  boolean_T rtb_Switch10_h;

  /* Switch: '<S2229>/Switch10' incorporates:
   *  Constant: '<S2229>/Constant12'
   *  Constant: '<S2229>/Constant13'
   *  Delay: '<S2229>/Delay6'
   *  Switch: '<S2229>/Switch6'
   *  Switch: '<S2229>/Switch9'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch10_h = false;
    rtb_Switch9 = false;
  } else {
    rtb_Switch10_h = (VDHP_BMSInstFlt4_flg || DHP_model_DW.Delay6_DSTATE);

    /* Switch: '<S2229>/Switch8' incorporates:
     *  Constant: '<S2182>/KDHP_Allow_Recover'
     *  Delay: '<S2229>/Delay6'
     *  Switch: '<S2229>/Switch6'
     */
    if (KDHP_BMSFLT4ALLOWRECOVERY_FLG) {
      rtb_Switch9 = VDHP_BMSInstFlt4_flg;
    } else {
      rtb_Switch9 = rtb_Switch10_h;
    }

    /* End of Switch: '<S2229>/Switch8' */
  }

  /* End of Switch: '<S2229>/Switch10' */

  /* Switch: '<S2228>/Switch2' incorporates:
   *  Constant: '<S2182>/Constant2'
   *  Constant: '<S2182>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2182>/KDHP_Pwr_limit'
   *  Constant: '<S2182>/KDHP_Spd_Limit'
   *  Constant: '<S2228>/Constant1'
   *  Constant: '<S2228>/Constant2'
   *  Constant: '<S2228>/Constant3'
   *  Switch: '<S2228>/Switch3'
   *  Switch: '<S2228>/Switch4'
   *  Switch: '<S2228>/Switch50'
   */
  if (KDHP_BMSFlt4ActionSwitchOpen_flg && rtb_Switch9) {
    DHP_model_B.Switch2_o = ((uint16_T)KDHP_BMSFLT4HANDLERESPONSEBITS);
    DHP_model_B.Switch3_g = ((uint8_T)KDHP_BMSFLT4SPDLIMIT);
    DHP_model_B.Switch4_p = ((uint8_T)KDHP_BMSFLT4POWERLIMIT_PCT);
  } else {
    DHP_model_B.Switch2_o = 0U;
    DHP_model_B.Switch3_g = 200U;
    DHP_model_B.Switch4_p = 100U;
  }

  /* End of Switch: '<S2228>/Switch2' */

  /* Logic: '<S2227>/Logical Operator1' incorporates:
   *  Switch: '<S2230>/Switch9'
   */
  DHP_model_B.LogicalOperator1_h = (rtb_Switch9 || ((!VDHP_NMSleepInd_flg) &&
    VDHP_BMSInstFlt4_NoErrNum));

  /* Switch: '<S2227>/Switch2' incorporates:
   *  Constant: '<S2182>/Constant2'
   *  Constant: '<S2182>/KDHP_Fault_Level'
   *  Constant: '<S2227>/Constant'
   *  Logic: '<S2227>/Logical Operator'
   */
  if (KDHP_BMSFlt4ActionSwitchOpen_flg && DHP_model_B.LogicalOperator1_h) {
    DHP_model_B.Switch2_bp = ((uint8_T)KDHP_BMSFLT4FAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2_bp = 0U;
  }

  /* End of Switch: '<S2227>/Switch2' */

  /* Update for Delay: '<S2229>/Delay6' */
  DHP_model_DW.Delay6_DSTATE = rtb_Switch10_h;
}

/* Output and update for atomic system: '<S2175>/BMSFltUnmatch' */
void DHP_model_BMSFltUnmatch(void)
{
  boolean_T rtb_LogicalOperator3_gi;
  boolean_T rtb_Switch1;

  /* Logic: '<S2233>/Logical Operator3' incorporates:
   *  Delay: '<S2233>/Delay3'
   *  Logic: '<S2233>/Logical Operator1'
   *  Logic: '<S2233>/Logical Operator2'
   *  Logic: '<S2233>/Logical Operator8'
   */
  rtb_LogicalOperator3_gi = (((!((!DHP_model_B.LogicalOperator) ||
    DHP_model_B.Compare_nu || VDHP_NMSleepInd_flg)) &&
    DHP_model_DW.Delay3_DSTATE) || DHP_model_B.LogicalOperator);

  /* Switch: '<S2233>/Switch1' incorporates:
   *  Constant: '<S2233>/Constant1'
   *  Constant: '<S2233>/Constant4'
   *  Delay: '<S2233>/Delay1'
   *  Switch: '<S2233>/Switch3'
   *  Switch: '<S2233>/Switch6'
   */
  if (VDHP_NMSleepInd_flg) {
    rtb_Switch1 = false;
    DHP_model_B.Switch3_nn = false;
  } else {
    rtb_Switch1 = (rtb_LogicalOperator3_gi || DHP_model_DW.Delay1_DSTATE_h);

    /* Switch: '<S2233>/Switch5' incorporates:
     *  Constant: '<S2183>/KDHP_Allow_Recover'
     *  Delay: '<S2233>/Delay1'
     *  Switch: '<S2233>/Switch6'
     */
    if (KDHP_BMSFLTUNMATCHALLOWRECOVERY_FLG) {
      DHP_model_B.Switch3_nn = rtb_LogicalOperator3_gi;
    } else {
      DHP_model_B.Switch3_nn = rtb_Switch1;
    }

    /* End of Switch: '<S2233>/Switch5' */
  }

  /* End of Switch: '<S2233>/Switch1' */

  /* Switch: '<S2232>/Switch2' incorporates:
   *  Constant: '<S2183>/Constant2'
   *  Constant: '<S2183>/KDHP_Fault_Level'
   *  Constant: '<S2183>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2183>/KDHP_Pwr_limit'
   *  Constant: '<S2183>/KDHP_Spd_Limit'
   *  Constant: '<S2231>/Constant'
   *  Constant: '<S2232>/Constant1'
   *  Constant: '<S2232>/Constant2'
   *  Constant: '<S2232>/Constant3'
   *  Switch: '<S2231>/Switch2'
   *  Switch: '<S2232>/Switch1'
   *  Switch: '<S2232>/Switch3'
   *  Switch: '<S2232>/Switch4'
   */
  if (KDHP_BMSFltUnmatchActionSwitchOpen_flg && DHP_model_B.Switch3_nn) {
    DHP_model_B.Switch2 = ((uint16_T)KDHP_BMSFLTUNMATCHHANDLERESPONSEBITS);
    DHP_model_B.Switch3 = ((uint8_T)KDHP_BMSFLTUNMATCHSPDLIMIT);
    DHP_model_B.Switch4 = ((uint8_T)KDHP_BMSFLTUNMATCHPOWERLIMIT_PCT);
    DHP_model_B.Switch2_n = ((uint8_T)KDHP_BMSFLTUNMATCHFAULTLEVEL_ENUM);
  } else {
    DHP_model_B.Switch2 = 0U;
    DHP_model_B.Switch3 = 200U;
    DHP_model_B.Switch4 = 100U;
    DHP_model_B.Switch2_n = 0U;
  }

  /* End of Switch: '<S2232>/Switch2' */

  /* Update for Delay: '<S2233>/Delay3' */
  DHP_model_DW.Delay3_DSTATE = rtb_LogicalOperator3_gi;

  /* Update for Delay: '<S2233>/Delay1' */
  DHP_model_DW.Delay1_DSTATE_h = rtb_Switch1;
}

/* Output and update for atomic system: '<S2175>/BMSOverU' */
void DHP_model_BMSOverU(void)
{
  /* Outputs for Atomic SubSystem: '<S2234>/Fault_Valid_Time' */

  /* Constant: '<S2184>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2184>/Constant2'
   *  Constant: '<S2184>/KDHP_Allow_Recover'
   *  Constant: '<S2184>/KDHP_Clear_Time'
   *  Constant: '<S2184>/KDHP_Fault_Level'
   *  Constant: '<S2184>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2184>/KDHP_Pwr_limit'
   *  Constant: '<S2184>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_BMS_OverUFlt_flg, ((uint16_T)KDHP_BMSOVERUCONFIRMTIME_MS), ((uint16_T)
    KDHP_BMSOVERUCLEARTIME_MS), KDHP_BMSOVERUALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BMSOVERUFAULTLEVEL_ENUM), ((uint8_T)KDHP_BMSOVERUSPDLIMIT), ((uint8_T)
    KDHP_BMSOVERUPOWERLIMIT_PCT), ((uint16_T)KDHP_BMSOVERUHANDLERESPONSEBITS),
    KDHP_BMSOverUActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_as,
    &DHP_model_DW.Fault_Valid_Time_as);

  /* End of Outputs for SubSystem: '<S2234>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S2175>/BMSUnderU' */
void DHP_model_BMSUnderU(void)
{
  /* Outputs for Atomic SubSystem: '<S2239>/Fault_Valid_Time' */

  /* Constant: '<S2185>/KDHP_Confirm_Time' incorporates:
   *  Constant: '<S2185>/Constant2'
   *  Constant: '<S2185>/KDHP_Allow_Recover'
   *  Constant: '<S2185>/KDHP_Clear_Time'
   *  Constant: '<S2185>/KDHP_Fault_Level'
   *  Constant: '<S2185>/KDHP_Handle_Response_Bits'
   *  Constant: '<S2185>/KDHP_Pwr_limit'
   *  Constant: '<S2185>/KDHP_Spd_Limit'
   */
  DHP_model_Fault_Valid_Time(VDHP_NMSleepInd_flg, VDHP_deltaSystemTick_ms,
    VDHP_BMS_UnderUFlt_flg, ((uint16_T)KDHP_BMSUNDERUCONFIRMTIME_MS), ((uint16_T)
    KDHP_BMSUNDERUCLEARTIME_MS), KDHP_BMSUNDERUALLOWRECOVERY_FLG, ((uint8_T)
    KDHP_BMSUNDERUFAULTLEVEL_ENUM), ((uint8_T)KDHP_BMSUNDERUSPDLIMIT), ((uint8_T)
    KDHP_BMSUNDERUPOWERLIMIT_PCT), ((uint16_T)KDHP_BMSUNDERUHANDLERESPONSEBITS),
    KDHP_BMSUnderUActionSwitchOpen_flg, &DHP_model_B.Fault_Valid_Time_iy,
    &DHP_model_DW.Fault_Valid_Time_iy);

  /* End of Outputs for SubSystem: '<S2239>/Fault_Valid_Time' */
}

/* Output and update for atomic system: '<S16>/BMS_Fault' */
void DHP_model_BMS_Fault(void)
{
  /* Outputs for Atomic SubSystem: '<S2175>/BMSBattOverT' */
  DHP_model_BMSBattOverT();

  /* End of Outputs for SubSystem: '<S2175>/BMSBattOverT' */

  /* Outputs for Atomic SubSystem: '<S2175>/BMSCellOverU' */
  DHP_model_BMSCellOverU();

  /* End of Outputs for SubSystem: '<S2175>/BMSCellOverU' */

  /* Outputs for Atomic SubSystem: '<S2175>/BMSCellUnderU' */
  DHP_model_BMSCellUnderU();

  /* End of Outputs for SubSystem: '<S2175>/BMSCellUnderU' */

  /* Outputs for Atomic SubSystem: '<S2175>/BMSDischrgPwrAbnormal' */
  DHP_model_BMSDischrgPwrAbnormal();

  /* End of Outputs for SubSystem: '<S2175>/BMSDischrgPwrAbnormal' */

  /* Outputs for Atomic SubSystem: '<S2175>/BMSFlt2' */
  DHP_model_BMSFlt2();

  /* End of Outputs for SubSystem: '<S2175>/BMSFlt2' */

  /* Outputs for Atomic SubSystem: '<S2175>/BMSFlt3' */
  DHP_model_BMSFlt3();

  /* End of Outputs for SubSystem: '<S2175>/BMSFlt3' */

  /* Outputs for Atomic SubSystem: '<S2175>/BMSFlt4' */
  DHP_model_BMSFlt4();

  /* End of Outputs for SubSystem: '<S2175>/BMSFlt4' */

  /* Logic: '<S2175>/Logical Operator' */
  DHP_model_B.LogicalOperator = (VDHP_BMSInstFlt2_NoErrNum ||
    VDHP_BMSInstFlt3_NoErrNum || VDHP_BMSInstFlt4_NoErrNum);

  /* Outputs for Atomic SubSystem: '<S2175>/BMSFltUnmatch' */
  DHP_model_BMSFltUnmatch();

  /* End of Outputs for SubSystem: '<S2175>/BMSFltUnmatch' */

  /* Outputs for Atomic SubSystem: '<S2175>/BMSOverU' */
  DHP_model_BMSOverU();

  /* End of Outputs for SubSystem: '<S2175>/BMSOverU' */

  /* Outputs for Atomic SubSystem: '<S2175>/BMSUnderU' */
  DHP_model_BMSUnderU();

  /* End of Outputs for SubSystem: '<S2175>/BMSUnderU' */
}

/* Output and update for function-call system: '<S4>/VehPowerSysErrValid' */
void DHP_model_VehPowerSysErrValid(void)
{
  /* Outputs for Atomic SubSystem: '<S16>/BMS_Fault' */
  DHP_model_BMS_Fault();

  /* End of Outputs for SubSystem: '<S16>/BMS_Fault' */
}

/* System initialize for atomic system: '<Root>/DHP' */
void DHP_model_DHP_Init(void)
{
  /* SystemInitialize for Enabled SubSystem: '<S1>/DHP' */

  /* SystemInitialize for S-Function (fcncallgen): '<S4>/Function-Call Generator2' incorporates:
   *  SystemInitialize for SubSystem: '<S4>/SysErrProduct2'
   */
  DHP_model_SysErrProduct2_Init();

  /* End of SystemInitialize for S-Function (fcncallgen): '<S4>/Function-Call Generator2' */

  /* End of SystemInitialize for SubSystem: '<S1>/DHP' */
}

/* Output and update for atomic system: '<Root>/DHP' */
void DHP_model_DHP(void)
{
  uint32_T rtb_DataStoreRead1_cg;
  uint32_T rtb_Switch;
  boolean_T rtb_Switch_h;
  boolean_T rtb_LogicalOperator1;
  uint16_T rtb_Gain4;
  uint8_T u0;
  real32_T u;
  real32_T v;
  uint8_T tmp;
  uint8_T tmp_0;

  /* DataStoreRead: '<S1>/Data Store Read1' */
  rtb_DataStoreRead1_cg = SystemTickMs;

  /* Sum: '<S1>/Add1' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   *  Delay: '<S1>/Delay'
   */
  rtb_Switch = SystemTickMs - DHP_model_DW.Delay_DSTATE;
  if (rtb_Switch > SystemTickMs) {
    rtb_Switch = 0U;
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S3>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read1'
   *  Delay: '<S1>/Delay'
   *  Logic: '<S1>/Logical Operator1'
   *  RelationalOperator: '<S1>/Relational Operator1'
   *  RelationalOperator: '<S3>/Compare'
   *  Sum: '<S1>/Add1'
   */
  if (!((rtb_Switch < 100U) && (DHP_model_DW.Delay_DSTATE <= SystemTickMs))) {
    rtb_Switch = 10U;
  }

  /* End of Switch: '<S1>/Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  VDHP_deltaSystemTick_ms = (uint8_T)rtb_Switch;

  /* DataStoreRead: '<S1>/Data Store Read' */
  VDHP_DisRecordDTC = DisRecordDTC;

  /* Outputs for Enabled SubSystem: '<S1>/DHP' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Logic: '<S1>/Logical Operator' */
  if (!VDHP_DisRecordDTC) {
    if (!DHP_model_DW.DHP_MODE) {
      DHP_model_DW.DHP_MODE = true;
    }

    /* DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
     *  Inport: '<Root>/NM'
     */
    VDHP_NMSleepInd_flg = (NM_output.VNM_TxSleepInd_flg != 0);

    /* Gain: '<S4>/Gain9' incorporates:
     *  Inport: '<Root>/TQM'
     */
    DHP_model_B.Gain9 = (uint16_T)(10.0F * TQM_output.TQM_VehSpd);

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSErrNum = DHP_model_DW.Delay5_104_DSTATE;

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S6>/Constant'
     *  Delay: '<S4>/Delay5'
     *  Inport: '<Root>/BTK'
     *  Inport: '<Root>/Config'
     *  RelationalOperator: '<S6>/Compare'
     */
    if (Config_output.C_PMSC_En == 2) {
      DHP_model_B.Switch = BTK_output.BTK_SSB2Sts;
    } else {
      DHP_model_B.Switch = DHP_model_DW.Delay5_9_DSTATE;
    }

    /* End of Switch: '<S4>/Switch' */

    /* RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read1'
     */
    VDHP_VCU_Up_flg = (SystemTickMs >= 2000U);

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_PTReady_flg = DHP_model_DW.Delay6_6_DSTATE;

    /* Logic: '<S4>/Logical Operator1' incorporates:
     *  Delay: '<S4>/Delay6'
     */
    DHP_model_B.LogicalOperator1 = (DHP_model_B.VPMM_PTReady_flg ||
      DHP_model_DW.Delay6_26_DSTATE);

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_LVEna = DHP_model_DW.Delay6_24_DSTATE;

    /* Gain: '<S4>/Gain2' */
    DHP_model_B.Gain2 = (uint16_T)(1000.0F * VDSF_AccelPedalL_V);

    /* Gain: '<S4>/Gain4' */
    DHP_model_B.Gain4 = (uint16_T)(1000.0F * VDSF_AccelPedalH_V);

    /* DataTypeConversion: '<S4>/Data Type Conversion10' incorporates:
     *  Gain: '<S4>/Gain3'
     */
    DHP_model_B.DataTypeConversion10 = (uint16_T)(2000.0F *
      DHP_model_B.VHALI_Sensor5V1_V);

    /* DataTypeConversion: '<S4>/Data Type Conversion11' incorporates:
     *  Gain: '<S4>/Gain12'
     */
    DHP_model_B.DataTypeConversion11 = (uint16_T)(2000.0F *
      DHP_model_B.VHALI_Sensor5V2_V);

    /* Gain: '<S4>/Gain1' */
    DHP_model_B.Gain1 = (uint16_T)(10.0F * DHP_model_B.VHALI_LVBattVoltage_V);

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.VHALI_SRS_CrashOutputStatus = DHP_model_DW.Delay1_231_DSTATE;

    /* DataStoreRead: '<S4>/Data Store Read18' */
    DHP_model_B.DataStoreRead18 = VHAL_VCUCanTickCount;

    /* DataStoreRead: '<S4>/Data Store Read19' */
    DHP_model_B.DataStoreRead19 = VHALI_BMS_113_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read20' */
    DHP_model_B.DataStoreRead20 = VHALI_BMS_213_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read21' */
    DHP_model_B.DataStoreRead21 = VHALI_BMS_233_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read22' */
    DHP_model_B.DataStoreRead22 = VHALI_BMS_303_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read23' */
    DHP_model_B.DataStoreRead23 = VHALI_BMS_313_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read24' */
    DHP_model_B.DataStoreRead24 = VHALI_BMS_323_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read25' */
    DHP_model_B.DataStoreRead25 = VHALI_BMS_377_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read26' */
    DHP_model_B.DataStoreRead26 = VHALI_BMS_633_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read27' */
    DHP_model_B.DataStoreRead27 = VHALI_BMS_653_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read28' */
    DHP_model_B.DataStoreRead28 = VHALI_MCU_115_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read29' */
    DHP_model_B.DataStoreRead29 = VHALI_MCU_125_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read30' */
    DHP_model_B.DataStoreRead30 = VHALI_MCU_215_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read31' */
    DHP_model_B.DataStoreRead31 = VHALI_MCU_515_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read32' */
    DHP_model_B.DataStoreRead32 = VHALI_DCDC_231_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read33' */
    DHP_model_B.DataStoreRead33 = VHALI_DCDC_251_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read34' */
    DHP_model_B.DataStoreRead34 = VHALI_OBC_311_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read35' */
    DHP_model_B.DataStoreRead35 = VHALI_OBC_321_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read36' */
    DHP_model_B.DataStoreRead36 = VHALI_OBC_331_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read38' */
    DHP_model_B.DataStoreRead38 = VHALI_ECC_34C_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read55' */
    DHP_model_B.DataStoreRead55 = VHALI_SRS_050_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read41' */
    DHP_model_B.DataStoreRead41 = VHALI_ABS_232_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read43' */
    DHP_model_B.DataStoreRead43 = VHALI_GW_217_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read44' */
    DHP_model_B.DataStoreRead44 = VHALI_GW_522_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read46' */
    DHP_model_B.DataStoreRead46 = VHALI_EPS_180_MsgTicks;

    /* Delay: '<S4>/Delay1' */
    VDHP_LS1to10FaultCode = DHP_model_DW.Delay1_23_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.VHALI_HSFaultCode_enum = DHP_model_DW.Delay1_24_DSTATE;

    /* DataStoreRead: '<S4>/Data Store Read17' */
    DHP_model_B.DataStoreRead17 = VHAL_VCUPTCanTickCount;

    /* DataStoreRead: '<S4>/Data Store Read47' */
    DHP_model_B.DataStoreRead47 = VHALI_EAC_349_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read48' */
    DHP_model_B.DataStoreRead48 = VHALI_TBOX_298_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read51' */
    DHP_model_B.DataStoreRead51 = VHALI_TMS_2C0_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read3' */
    DHP_model_B.DataStoreRead3 = VHALI_ABS_229_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read4' */
    DHP_model_B.DataStoreRead4 = VHALI_BMS_304_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read5' */
    DHP_model_B.DataStoreRead5 = VHALI_BMS_513_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read6' */
    DHP_model_B.DataStoreRead6 = VHALI_BMS_603_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read7' */
    DHP_model_B.DataStoreRead7 = VHALI_BMS_613_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read1' */
    DHP_model_B.DataStoreRead1 = VHALI_ICM_234_MsgTicks;

    /* DataStoreRead: '<S4>/Data Store Read2' */
    DHP_model_B.DataStoreRead2 = VHALI_EHU_345_MsgTicks;

    /* DataTypeConversion: '<S4>/Data Type Conversion45' incorporates:
     *  Delay: '<S4>/Delay5'
     */
    DHP_model_B.DataTypeConversion45 = (int16_T)(real32_T)floor
      (DHP_model_DW.Delay5_152_DSTATE);

    /* DataTypeConversion: '<S4>/Data Type Conversion46' incorporates:
     *  Delay: '<S4>/Delay5'
     */
    DHP_model_B.DataTypeConversion46 = (int16_T)(real32_T)floor
      (DHP_model_DW.Delay5_149_DSTATE);

    /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
     *  Delay: '<S4>/Delay5'
     */
    DHP_model_B.DataTypeConversion1 = (int16_T)(real32_T)floor
      (DHP_model_DW.Delay5_153_DSTATE);

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_DCDCFltRnk_enum = DHP_model_DW.Delay5_242_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_OBCFltRnk_enum = DHP_model_DW.Delay5_205_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_MCUFltRnk_enum = DHP_model_DW.Delay5_148_DSTATE;

    /* DataTypeConversion: '<S4>/Data Type Conversion5' incorporates:
     *  Delay: '<S4>/Delay5'
     *  Gain: '<S4>/Gain7'
     */
    DHP_model_B.DataTypeConversion5 = (uint16_T)(10.0F *
      DHP_model_DW.Delay5_145_DSTATE);

    /* DataTypeConversion: '<S4>/Data Type Conversion6' incorporates:
     *  Delay: '<S4>/Delay5'
     *  Gain: '<S4>/Gain8'
     */
    DHP_model_B.DataTypeConversion6 = (int16_T)(real32_T)floor(10.0F *
      DHP_model_DW.Delay5_146_DSTATE);

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.MCUHWCurrOverErr = DHP_model_DW.Delay5_194_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_MCUPwrModErr_flg = DHP_model_DW.Delay5_160_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSFltRnk_enum = DHP_model_DW.Delay5_53_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSOperMod_enum = DHP_model_DW.Delay5_54_DSTATE;

    /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
     *  Delay: '<S4>/Delay5'
     *  Gain: '<S4>/Gain6'
     */
    DHP_model_B.DataTypeConversion3 = (uint16_T)(10.0F *
      DHP_model_DW.Delay5_50_DSTATE);

    /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
     *  Delay: '<S4>/Delay5'
     *  Gain: '<S4>/Gain'
     */
    DHP_model_B.DataTypeConversion2 = (uint16_T)(100.0F *
      DHP_model_DW.Delay5_109_DSTATE);

    /* DataTypeConversion: '<S4>/Data Type Conversion4' incorporates:
     *  Delay: '<S4>/Delay5'
     *  Gain: '<S4>/Gain5'
     */
    DHP_model_B.DataTypeConversion4 = (uint16_T)(100.0F *
      DHP_model_DW.Delay5_106_DSTATE);

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSMaxBattT = DHP_model_DW.Delay5_86_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSChrgMod_enum = DHP_model_DW.Delay5_80_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_MCUErrNum = DHP_model_DW.Delay5_155_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_MCUOperMdl_enum = DHP_model_DW.Delay5_141_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_ABS_AbsFlgFlt = DHP_model_DW.Delay5_314_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_EPS_EpasFailed = DHP_model_DW.Delay5_359_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_ABS_EbdFlgFlt = DHP_model_DW.Delay5_313_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_EPB_Status = DHP_model_DW.Delay5_356_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_ABS_VehicleSpeedValid_flg = DHP_model_DW.Delay5_317_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_MotTqRealValid_flg = DHP_model_DW.Delay5_140_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_MCUElecMotSpdValid_flg = DHP_model_DW.Delay5_138_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSBattUOverU = DHP_model_DW.Delay5_124_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSBattUUnderU = DHP_model_DW.Delay5_125_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSCellUMaxOverU = DHP_model_DW.Delay5_126_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSCellUMinUnderU = DHP_model_DW.Delay5_123_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSMaxBattTOverT = DHP_model_DW.Delay5_127_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_ESP_ESPFailStatus = DHP_model_DW.Delay5_333_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_LVUpTimeout_flg = DHP_model_DW.Delay6_15_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_HVUpTimeout_flg = DHP_model_DW.Delay6_16_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_HVActiveTimeout_flg = DHP_model_DW.Delay6_17_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_HVDownTimeout_flg = DHP_model_DW.Delay6_19_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_MCUDischargeTimeout_flg = DHP_model_DW.Delay6_20_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_LVUpBMSPwrUpAllwTimeout_flg = DHP_model_DW.Delay6_11_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_LVUpBMSTimeout_flg = DHP_model_DW.Delay6_12_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_LVUpDCDCTimeout_flg = DHP_model_DW.Delay6_13_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_LVUpMCUTimeout_flg = DHP_model_DW.Delay6_14_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_MCUHVActiveTimeout_flg = DHP_model_DW.Delay6_22_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_HVDCDCActiveTimeout_flg = DHP_model_DW.Delay6_21_DSTATE;

    /* Logic: '<S4>/Logical Operator2' incorporates:
     *  Delay: '<S4>/Delay6'
     */
    DHP_model_B.LogicalOperator2 = (DHP_model_B.VPMM_PTReady_flg ||
      DHP_model_DW.Delay6_26_DSTATE);

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_BMSModError = DHP_model_DW.Delay6_30_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_MCUModError = DHP_model_DW.Delay6_29_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_DCDCModError = DHP_model_DW.Delay6_31_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_MCUExitTqlTimeout_flg = DHP_model_DW.Delay6_33_DSTATE;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_DCDCStopworkTimeout_flg = DHP_model_DW.Delay6_34_DSTATE;

    /* Delay: '<S4>/Delay2' */
    DHP_model_B.VCHRG_ChrgStsLampReq_flg = DHP_model_DW.Delay2_6_DSTATE;

    /* Delay: '<S4>/Delay2' */
    DHP_model_B.VCHRG_VCUChrgAllwd_flg = DHP_model_DW.Delay2_2_DSTATE;

    /* Delay: '<S4>/Delay3' */
    DHP_model_B.TMM_WaterPumpEnReq_flg = DHP_model_DW.Delay3_2_DSTATE;

    /* Delay: '<S4>/Delay3' */
    DHP_model_B.TMM_VCUChrgReqLimFac_enum = DHP_model_DW.Delay3_9_DSTATE;

    /* Delay: '<S4>/Delay3' */
    DHP_model_B.TMM_InvalidBattReq = DHP_model_DW.Delay3_41_DSTATE;

    /* DataTypeConversion: '<S4>/Data Type Conversion9' incorporates:
     *  Delay: '<S4>/Delay1'
     *  Gain: '<S4>/Gain10'
     */
    DHP_model_B.DataTypeConversion9 = (int16_T)(real32_T)floor(10.0F *
      DHP_model_DW.Delay1_16_DSTATE);

    /* DataTypeConversion: '<S4>/Data Type Conversion8' incorporates:
     *  Delay: '<S4>/Delay1'
     *  Gain: '<S4>/Gain11'
     */
    DHP_model_B.DataTypeConversion8 = (int16_T)(real32_T)floor(10.0F *
      DHP_model_DW.Delay1_17_DSTATE);

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_SlowChargeAwakeActive_flg = DHP_model_DW.Delay5_27_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_FastChargeAwakeActiveIn_flg = DHP_model_DW.Delay5_28_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_ICM_VehSpdChkInvalidFlt_flg =
      DHP_model_DW.Delay5_525_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BrkLightSwitchActive_flg = DHP_model_DW.Delay5_7_DSTATE;

    /* DataStoreRead: '<S4>/Data Store Read8' */
    DHP_model_B.DataStoreRead8 = VHALI_BMS_623_MsgTicks;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.VPMM_IChrgSts = DHP_model_DW.Delay6_28_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.VHALI_SSB_Switch_1 = DHP_model_DW.Delay1_99_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.VHALI_SSB_Switch_2 = DHP_model_DW.Delay1_100_DSTATE;

    /* S-Function (fcncallgen): '<S4>/Function-Call Generator2' incorporates:
     *  SubSystem: '<S4>/SysErrProduct2'
     */
    DHP_model_SysErrProduct2();

    /* S-Function (fcncallgen): '<S4>/Function-Call Generator2' incorporates:
     *  SubSystem: '<S4>/VcuControlDeviceErrValid'
     */
    DHP_model_VcuControlDeviceErrValid();

    /* S-Function (fcncallgen): '<S4>/Function-Call Generator2' incorporates:
     *  SubSystem: '<S4>/VehOtherDeviceErrValid'
     */
    DHP_model_VehOtherDeviceErrValid();

    /* S-Function (fcncallgen): '<S4>/Function-Call Generator2' incorporates:
     *  SubSystem: '<S4>/VehDriveSysErrValid'
     */
    DHP_model_VehDriveSysErrValid();

    /* S-Function (fcncallgen): '<S4>/Function-Call Generator2' incorporates:
     *  SubSystem: '<S4>/VehPowerSysErrValid'
     */
    DHP_model_VehPowerSysErrValid();

    /* End of Outputs for S-Function (fcncallgen): '<S4>/Function-Call Generator2' */

    /* MinMax: '<S502>/MinMax' */
    if (DHP_model_B.Fault_Valid_Time_lp.Switch2_i >=
        DHP_model_B.Fault_Valid_Time_m.Switch2_i) {
      u0 = DHP_model_B.Fault_Valid_Time_lp.Switch2_i;
    } else {
      u0 = DHP_model_B.Fault_Valid_Time_m.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_g.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_g.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_jy.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_jy.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_eo.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_eo.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_n1v.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_n1v.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_oe.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_oe.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_jj.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_jj.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_ds.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_ds.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_h.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_h.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_o0.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_o0.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_b.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_b.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_n.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_n.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_nm.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_nm.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Switch2_jd)) {
      u0 = DHP_model_B.Switch2_jd;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_kh.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_kh.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_jc.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_jc.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_ot.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_ot.Switch2_i;
    }

    /* End of MinMax: '<S502>/MinMax' */

    /* Switch: '<S502>/Switch' incorporates:
     *  Constant: '<S511>/Constant'
     *  Logic: '<S502>/Logical Operator'
     *  RelationalOperator: '<S511>/Compare'
     *  UnitDelay: '<S502>/Unit Delay'
     */
    rtb_Switch_h = (((u0 >= 1) && VDHP_TestWorkDelay4s_Flg) ||
                    DHP_model_DW.UnitDelay_DSTATE_h);

    /* DataStoreWrite: '<S502>/Data Store Write' */
    bool_udsAgingTestError_flag = rtb_Switch_h;

    /* MinMax: '<S482>/MinMax5' */
    if (DHP_model_B.Fault_Valid_Time_c.Switch2_i >=
        DHP_model_B.Fault_Valid_Time_k.Switch2_i) {
      u0 = DHP_model_B.Fault_Valid_Time_c.Switch2_i;
    } else {
      u0 = DHP_model_B.Fault_Valid_Time_k.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_j.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_j.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_o.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_o.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_i.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_i.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Switch2_bk)) {
      u0 = DHP_model_B.Switch2_bk;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_b.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_b.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_n.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_n.Switch2_i;
    }

    /* End of MinMax: '<S482>/MinMax5' */

    /* RelationalOperator: '<S482>/Relational Operator' */
    VDHP_AccPedalFault_Flg = (u0 >= 2);

    /* Logic: '<S483>/Logical Operator' */
    VDHP_BMSFailTimeBased_Flg = (DHP_model_B.Switch6 || DHP_model_B.Switch6_p);

    /* MinMax: '<S483>/MinMax' */
    if (DHP_model_B.Switch2_a >= DHP_model_B.Switch2_d5d) {
      u0 = DHP_model_B.Switch2_a;
    } else {
      u0 = DHP_model_B.Switch2_d5d;
    }

    if (!(u0 >= DHP_model_B.Switch2_bp)) {
      u0 = DHP_model_B.Switch2_bp;
    }

    if (!(u0 >= DHP_model_B.Switch2_nh)) {
      u0 = DHP_model_B.Switch2_nh;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_as.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_as.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_iy.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_iy.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_gy.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_gy.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_fa.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_fa.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_cb.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_cb.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Switch2_fx)) {
      u0 = DHP_model_B.Switch2_fx;
    }

    /* End of MinMax: '<S483>/MinMax' */

    /* RelationalOperator: '<S483>/Relational Operator' */
    VDHP_BMSFault_Flg = (u0 >= 2);

    /* RelationalOperator: '<S503>/Compare' incorporates:
     *  Constant: '<S503>/Constant'
     */
    DHP_output.VDHP_BrakeFault_Flg = (DHP_model_B.Fault_Valid_Time_d.Switch2_i >=
      2);

    /* MinMax: '<S484>/MinMax5' */
    if (DHP_model_B.Fault_Valid_Time_d.Switch2_i >=
        DHP_model_B.Fault_Valid_Time_am.Switch2_i) {
      u0 = DHP_model_B.Fault_Valid_Time_d.Switch2_i;
    } else {
      u0 = DHP_model_B.Fault_Valid_Time_am.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_im.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_im.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_k5.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_k5.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_kh.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_kh.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_o.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_o.Switch2_m;
    }

    /* End of MinMax: '<S484>/MinMax5' */

    /* Logic: '<S484>/Logical Operator' incorporates:
     *  Constant: '<S504>/Constant'
     *  RelationalOperator: '<S484>/Relational Operator'
     *  RelationalOperator: '<S504>/Compare'
     */
    VDHP_BrakeSysFault_Flg = ((u0 >= 2) ||
      (DHP_model_B.Fault_Valid_RT_gv.Switch2_m >= 1));

    /* MinMax: '<S484>/MinMax' */
    if (DHP_model_B.Fault_Valid_Time_d.Switch2_i >=
        DHP_model_B.Fault_Valid_Time_am.Switch2_i) {
      DHP_output.VDHP_BrkDSCheckFaultLevel_enum =
        DHP_model_B.Fault_Valid_Time_d.Switch2_i;
    } else {
      DHP_output.VDHP_BrkDSCheckFaultLevel_enum =
        DHP_model_B.Fault_Valid_Time_am.Switch2_i;
    }

    /* End of MinMax: '<S484>/MinMax' */

    /* RelationalOperator: '<S485>/Compare' incorporates:
     *  Constant: '<S485>/Constant'
     */
    DHP_output.VDHP_VCUtoBMSLossCanNetFault_flg = (DHP_model_B.Switch2_nh > 0);

    /* RelationalOperator: '<S486>/Compare' incorporates:
     *  Constant: '<S486>/Constant'
     */
    DHP_output.VDHP_VCUtoMCULossCanNetFault_flg = (DHP_model_B.Switch2_f3 > 0);

    /* MinMax: '<S9>/MinMax2' */
    if (DHP_model_B.Fault_Valid_Time_pv.Switch2_i >=
        DHP_model_B.Fault_Valid_Time_nj.Switch2_i) {
      u0 = DHP_model_B.Fault_Valid_Time_pv.Switch2_i;
    } else {
      u0 = DHP_model_B.Fault_Valid_Time_nj.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_jc.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_jc.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_j4.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_j4.Switch2_i;
    }

    /* End of MinMax: '<S9>/MinMax2' */

    /* RelationalOperator: '<S487>/Compare' incorporates:
     *  Constant: '<S487>/Constant'
     */
    DHP_output.VDHP_WaterPumpFault_flg = (u0 >= 2);

    /* RelationalOperator: '<S488>/Compare' incorporates:
     *  Constant: '<S488>/Constant'
     */
    DHP_output.VDHP_CalDataCorrupted_flg =
      (DHP_model_B.Fault_Valid_RT_ae.Switch2_m >= 2);

    /* MinMax: '<S9>/MinMax1' */
    if (DHP_model_B.Fault_Valid_Time_nm.Switch2_i >=
        DHP_model_B.Fault_Valid_Time_os.Switch2_i) {
      u0 = DHP_model_B.Fault_Valid_Time_nm.Switch2_i;
    } else {
      u0 = DHP_model_B.Fault_Valid_Time_os.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_j5.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_j5.Switch2_i;
    }

    /* End of MinMax: '<S9>/MinMax1' */

    /* RelationalOperator: '<S489>/Compare' incorporates:
     *  Constant: '<S489>/Constant'
     */
    DHP_output.VDHP_SRSFault_flg = (u0 >= 2);

    /* RelationalOperator: '<S490>/Compare' incorporates:
     *  Constant: '<S490>/Constant'
     */
    DHP_output.VDHP_VCUtoDCDCLossCanNetFault_flg = (DHP_model_B.Switch2_ph > 0);

    /* RelationalOperator: '<S491>/Compare' incorporates:
     *  Constant: '<S491>/Constant'
     */
    DHP_output.VDHP_VCUtoOBCLossCanNetFault_flg = (DHP_model_B.Switch2_lj > 0);

    /* RelationalOperator: '<S492>/Compare' incorporates:
     *  Constant: '<S492>/Constant'
     */
    DHP_output.VDHP_VCUtoABSLossCanNetFlt_flg =
      (DHP_model_B.Fault_Valid_RT_o.Switch2_m > 0);

    /* RelationalOperator: '<S493>/Compare' incorporates:
     *  Constant: '<S493>/Constant'
     */
    DHP_output.VDHP_HVILErrFault_flg = (DHP_model_B.Switch2_jd > 0);

    /* RelationalOperator: '<S494>/Compare' incorporates:
     *  Constant: '<S494>/Constant'
     */
    DHP_output.VDHP_VehCrashFault_flg = (DHP_model_B.Fault_Valid_RT_is.Switch2_m
      > 0);

    /* MinMax: '<S495>/MinMax' */
    if (DHP_model_B.Fault_Valid_Time_nw.Switch2_i >= DHP_model_B.Switch2_bc) {
      u0 = DHP_model_B.Fault_Valid_Time_nw.Switch2_i;
    } else {
      u0 = DHP_model_B.Switch2_bc;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_jc.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_jc.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_j4.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_j4.Switch2_i;
    }

    /* End of MinMax: '<S495>/MinMax' */

    /* RelationalOperator: '<S495>/Relational Operator' */
    VDHP_CoolingSysFault_Flg = (u0 >= 2);

    /* MinMax: '<S496>/MinMax' */
    if (DHP_model_B.Fault_Valid_Time_ot.Switch2_i >=
        DHP_model_B.Fault_Valid_Time_nvb.Switch2_i) {
      tmp = DHP_model_B.Fault_Valid_Time_ot.Switch2_i;
    } else {
      tmp = DHP_model_B.Fault_Valid_Time_nvb.Switch2_i;
    }

    /* End of MinMax: '<S496>/MinMax' */

    /* RelationalOperator: '<S496>/Relational Operator' */
    VDHP_CruiseHWFault_Flg = (tmp >= 1);

    /* MinMax: '<S497>/MinMax' */
    if (DHP_model_B.Fault_Valid_RT_b3.Switch2_m >= DHP_model_B.Switch2_ph) {
      tmp = DHP_model_B.Fault_Valid_RT_b3.Switch2_m;
    } else {
      tmp = DHP_model_B.Switch2_ph;
    }

    /* End of MinMax: '<S497>/MinMax' */

    /* RelationalOperator: '<S497>/Relational Operator' */
    VDHP_DCDCFault_Flg = (tmp >= 2);

    /* MinMax: '<S497>/MinMax1' */
    if (DHP_model_B.Fault_Valid_RT_b3.Switch2_m >= DHP_model_B.Switch2_ph) {
      u0 = DHP_model_B.Fault_Valid_RT_b3.Switch2_m;
    } else {
      u0 = DHP_model_B.Switch2_ph;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_h.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_h.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_o0.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_o0.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_la.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_la.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_n1.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_n1.Switch2_i;
    }

    /* End of MinMax: '<S497>/MinMax1' */

    /* RelationalOperator: '<S497>/Relational Operator1' */
    VDHP_VCUBattChrgErr_Flg = (u0 >= 2);

    /* RelationalOperator: '<S498>/Relational Operator' */
    VDHP_GearSingleNotInAeraFlt_Flg =
      (DHP_model_B.Fault_Valid_Time_nvm.Switch2_i >= 2);

    /* Switch: '<S499>/Switch1' incorporates:
     *  Constant: '<S499>/Constant2'
     *  Constant: '<S499>/Constant7'
     *  Constant: '<S510>/Constant'
     *  RelationalOperator: '<S510>/Compare'
     */
    if (Vehicle_Type == S11_Mark) {
      tmp = DHP_model_B.Fault_Valid_RT_iq.Switch2_m;
    } else {
      tmp = 0U;
    }

    /* End of Switch: '<S499>/Switch1' */

    /* RelationalOperator: '<S505>/Compare' incorporates:
     *  Constant: '<S505>/Constant'
     */
    VDHP_MCUFltExitReady_Flg = (tmp >= 2);

    /* MinMax: '<S499>/MinMax1' */
    if (DHP_model_B.Fault_Valid_RT_k1s.Switch2_m >=
        DHP_model_B.Fault_Valid_RT_gt.Switch2_m) {
      tmp = DHP_model_B.Fault_Valid_RT_k1s.Switch2_m;
    } else {
      tmp = DHP_model_B.Fault_Valid_RT_gt.Switch2_m;
    }

    /* End of MinMax: '<S499>/MinMax1' */

    /* Switch: '<S499>/Switch' incorporates:
     *  Constant: '<S499>/Constant1'
     *  Constant: '<S508>/Constant'
     *  RelationalOperator: '<S508>/Compare'
     */
    if (tmp >= 2) {
      u0 = 0U;
    } else {
      u0 = DHP_model_B.Fault_Valid_RT_du.Switch2_m;
    }

    /* End of Switch: '<S499>/Switch' */

    /* MinMax: '<S499>/MinMax5' */
    if (!(u0 >= DHP_model_B.Fault_Valid_RT_jm.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_jm.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_ad.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_ad.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_pi.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_pi.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_pa.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_pa.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_iq.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_iq.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Switch2_ip)) {
      u0 = DHP_model_B.Switch2_ip;
    }

    if (!(u0 >= DHP_model_B.Switch2_fe)) {
      u0 = DHP_model_B.Switch2_fe;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_bt.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_bt.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Switch2_dh)) {
      u0 = DHP_model_B.Switch2_dh;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_py.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_py.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_mb.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_mb.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_m5.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_m5.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_bne.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_bne.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Switch2_mf)) {
      u0 = DHP_model_B.Switch2_mf;
    }

    if (!(u0 >= DHP_model_B.Switch2_i)) {
      u0 = DHP_model_B.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_ag.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_ag.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_mr.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_mr.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_kbz.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_kbz.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_ewi.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_ewi.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Switch2_bh)) {
      u0 = DHP_model_B.Switch2_bh;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_ak.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_ak.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_iw.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_iw.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_ix.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_ix.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_Time_a0.Switch2_i)) {
      u0 = DHP_model_B.Fault_Valid_Time_a0.Switch2_i;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_id.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_id.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Switch2_gz)) {
      u0 = DHP_model_B.Switch2_gz;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_h3.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_h3.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_co.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_co.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_l4.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_l4.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_if.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_if.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_at.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_at.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_n0.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_n0.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_gt.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_gt.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_c5o.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_c5o.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_de.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_de.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_gk.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_gk.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_lf.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_lf.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_hj.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_hj.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_mz.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_mz.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Fault_Valid_RT_m4.Switch2_m)) {
      u0 = DHP_model_B.Fault_Valid_RT_m4.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Switch2_f)) {
      u0 = DHP_model_B.Switch2_f;
    }

    if (!(u0 >= DHP_model_B.Switch2_bc)) {
      u0 = DHP_model_B.Switch2_bc;
    }

    if (!(u0 >= DHP_model_B.Switch2_f3)) {
      u0 = DHP_model_B.Switch2_f3;
    }

    /* End of MinMax: '<S499>/MinMax5' */

    /* RelationalOperator: '<S506>/Compare' incorporates:
     *  Constant: '<S506>/Constant'
     */
    VDHP_MCUFault_Flg = (u0 >= 2);

    /* MinMax: '<S499>/MinMax2' */
    if (DHP_model_B.Switch2_dh >= DHP_model_B.Switch2_mf) {
      u0 = DHP_model_B.Switch2_dh;
    } else {
      u0 = DHP_model_B.Switch2_mf;
    }

    if (!(u0 >= DHP_model_B.Switch2_i)) {
      u0 = DHP_model_B.Switch2_i;
    }

    /* End of MinMax: '<S499>/MinMax2' */

    /* MinMax: '<S499>/MinMax3' */
    if (DHP_model_B.Switch2_ip >= DHP_model_B.Switch2_fe) {
      tmp = DHP_model_B.Switch2_ip;
    } else {
      tmp = DHP_model_B.Switch2_fe;
    }

    /* End of MinMax: '<S499>/MinMax3' */

    /* Logic: '<S499>/Logical Operator' incorporates:
     *  Constant: '<S507>/Constant'
     *  Constant: '<S509>/Constant'
     *  RelationalOperator: '<S507>/Compare'
     *  RelationalOperator: '<S509>/Compare'
     */
    VDHP_MCUFaultSpeedBased_Flg = ((u0 > 2) || (tmp >= 2));

    /* MinMax: '<S499>/MinMax' */
    if (DHP_model_B.Switch2_bc >= DHP_model_B.Fault_Valid_Time_nw.Switch2_i) {
      tmp = DHP_model_B.Switch2_bc;
    } else {
      tmp = DHP_model_B.Fault_Valid_Time_nw.Switch2_i;
    }

    /* End of MinMax: '<S499>/MinMax' */

    /* RelationalOperator: '<S499>/Relational Operator' incorporates:
     *  Constant: '<S499>/Constant'
     */
    VDHP_MCUSysOverTFault_Flg = (tmp >= 2);

    /* MinMax: '<S500>/MinMax' */
    if (DHP_model_B.Fault_Valid_RT_mp.Switch2_m >=
        DHP_model_B.Fault_Valid_RT_bzj.Switch2_m) {
      u0 = DHP_model_B.Fault_Valid_RT_mp.Switch2_m;
    } else {
      u0 = DHP_model_B.Fault_Valid_RT_bzj.Switch2_m;
    }

    if (!(u0 >= DHP_model_B.Switch2_lj)) {
      u0 = DHP_model_B.Switch2_lj;
    }

    /* End of MinMax: '<S500>/MinMax' */

    /* RelationalOperator: '<S500>/Relational Operator' */
    VDHP_OBCFault_Flg = (u0 >= 2);

    /* MinMax: '<S501>/MinMax' */
    if (DHP_model_B.Switch2_nh >= DHP_model_B.Switch2_bk) {
      u0 = DHP_model_B.Switch2_nh;
    } else {
      u0 = DHP_model_B.Switch2_bk;
    }

    if (!(u0 >= DHP_model_B.Switch2_bc)) {
      u0 = DHP_model_B.Switch2_bc;
    }

    /* End of MinMax: '<S501>/MinMax' */

    /* RelationalOperator: '<S501>/Relational Operator' */
    VDHP_VCUFaultSpeedBased_Flg = (u0 >= 2);

    /* DataStoreRead: '<S10>/Data Store Read' */
    DHP_model_B.BusCreator.VDHP_TMTqReq = VHALO_MotTqReq;

    /* Delay: '<S4>/Delay6' */
    DHP_model_B.BusCreator.VDHP_VehSts_enum = DHP_model_DW.Delay6_10_DSTATE;

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.BusCreator.VDHP_PEPS_PDU_enum = DHP_model_DW.Delay5_303_DSTATE;

    /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/TQM'
     */
    VDHP_GearOut_enum = TQM_output.TQM_GearDisp;

    /* Gain: '<S10>/Gain1' incorporates:
     *  Delay: '<S4>/Delay1'
     */
    u = 10.0F * DHP_model_DW.Delay1_20_DSTATE;

    /* DataTypeConversion: '<S10>/Data Type Conversion2' */
    v = (real32_T)fabs(u);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        DHP_model_B.BusCreator.VDHP_LVBattVoltage_V = (uint8_T)(real32_T)floor(u
          + 0.5F);
      } else {
        DHP_model_B.BusCreator.VDHP_LVBattVoltage_V = (uint8_T)(u * 0.0F);
      }
    } else {
      DHP_model_B.BusCreator.VDHP_LVBattVoltage_V = (uint8_T)u;
    }

    /* End of DataTypeConversion: '<S10>/Data Type Conversion2' */

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_BMSChrgSts_enum = DHP_model_DW.Delay1_321_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_MotTqReal = DHP_model_DW.Delay1_377_DSTATE;

    /* Switch: '<S10>/Switch13' incorporates:
     *  Constant: '<S10>/Constant17'
     *  Constant: '<S517>/Constant'
     *  Constant: '<S518>/Constant'
     *  Constant: '<S519>/Constant'
     *  Constant: '<S520>/Constant'
     *  Constant: '<S521>/Constant'
     *  Logic: '<S10>/Logical Operator'
     *  RelationalOperator: '<S517>/Compare'
     *  RelationalOperator: '<S518>/Compare'
     *  RelationalOperator: '<S519>/Compare'
     *  RelationalOperator: '<S520>/Compare'
     *  RelationalOperator: '<S521>/Compare'
     */
    if ((Vehicle_Type == K11_Mark) || (Vehicle_Type == K11P01_Mark) ||
        (Vehicle_Type == K11E01R_Mark) || (Vehicle_Type == K11P06_Mark) ||
        (Vehicle_Type == ((uint8_T)Z18_MARK))) {
      /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
       *  Constant: '<S10>/Constant19'
       */
      DHP_model_B.BusCreator.VDHP_MCUIGBTT = MAX_uint8_T;
    } else {
      /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
       *  Delay: '<S4>/Delay1'
       */
      DHP_model_B.BusCreator.VDHP_MCUIGBTT = (uint8_T)
        DHP_model_DW.Delay1_391_DSTATE;
    }

    /* End of Switch: '<S10>/Switch13' */

    /* DataTypeConversion: '<S10>/Data Type Conversion4' incorporates:
     *  Delay: '<S4>/Delay1'
     */
    DHP_model_B.BusCreator.VDHP_MCUElecMotT = (uint8_T)
      DHP_model_DW.Delay1_388_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_MCUElecMotSpd = DHP_model_DW.Delay1_376_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_BMSSOC = DHP_model_DW.Delay1_291_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_BMSBattU = DHP_model_DW.Delay1_289_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_BMSBattI = DHP_model_DW.Delay1_290_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_BMSAvrgBattT = DHP_model_DW.Delay1_331_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_DCDCT = DHP_model_DW.Delay1_452_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_TotalVehDistance_km =
      DHP_model_DW.Delay1_272_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_FltTime_Year = DHP_model_DW.Delay1_517_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_FltTime_Month = DHP_model_DW.Delay1_518_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_FltTime_Day = DHP_model_DW.Delay1_519_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_FltTime_Hour = DHP_model_DW.Delay1_520_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_FltTime_Minute = DHP_model_DW.Delay1_521_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_FltTime_Second = DHP_model_DW.Delay1_522_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_BMSErrNum = DHP_model_DW.Delay1_343_DSTATE;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_MCUErrNum = DHP_model_DW.Delay1_394_DSTATE;

    /* Switch: '<S10>/Switch3' incorporates:
     *  Constant: '<S10>/Constant7'
     *  Constant: '<S10>/Constant8'
     *  DataStoreRead: '<S10>/Data Store Read14'
     */
    if (hIOP_GearSwitch1_flg > 0) {
      tmp = 2U;
    } else {
      tmp = 0U;
    }

    /* End of Switch: '<S10>/Switch3' */

    /* Switch: '<S10>/Switch4' incorporates:
     *  Constant: '<S10>/Constant10'
     *  Constant: '<S10>/Constant9'
     *  DataStoreRead: '<S10>/Data Store Read15'
     */
    if (hIOP_GearSwitch3_flg > 0) {
      u0 = 4U;
    } else {
      u0 = 0U;
    }

    /* End of Switch: '<S10>/Switch4' */

    /* Switch: '<S10>/Switch5' incorporates:
     *  Constant: '<S10>/Constant11'
     *  Constant: '<S10>/Constant12'
     *  DataStoreRead: '<S10>/Data Store Read16'
     */
    if (hIOP_GearSwitch2_flg > 0) {
      tmp_0 = 8U;
    } else {
      tmp_0 = 0U;
    }

    /* End of Switch: '<S10>/Switch5' */

    /* Sum: '<S10>/Add1' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read13'
     *  Switch: '<S10>/Switch2'
     */
    DHP_model_B.BusCreator.VDHP_GearSwitch = (uint8_T)((((uint32_T)
      (hIOP_GearSwitch4_flg > 0) + tmp) + u0) + tmp_0);

    /* Gain: '<S10>/Gain3' incorporates:
     *  Delay: '<S4>/Delay1'
     */
    DHP_model_B.BusCreator.VDHP_AccelPedalL_kv = (uint16_T)(1000.0F *
      DHP_model_DW.Delay1_14_DSTATE);

    /* Gain: '<S10>/Gain4' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read1'
     */
    rtb_Gain4 = (uint16_T)(100.0F * hIOP_WaterPwm_Duty);

    /* Logic: '<S10>/Logical Operator1' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read19'
     */
    rtb_LogicalOperator1 = !bool_udsAgingTestStart_flag;

    /* Switch: '<S10>/Switch14' incorporates:
     *  Switch: '<S10>/Switch8'
     */
    if (rtb_LogicalOperator1) {
      /* Switch: '<S10>/Switch8' incorporates:
       *  Constant: '<S512>/Constant'
       *  Delay: '<S4>/Delay1'
       *  RelationalOperator: '<S512>/Compare'
       */
      if (DHP_model_DW.Delay1_67_DSTATE == 255) {
        DHP_model_B.BusCreator.VDHP_WaterPWM_Duty =
          DHP_model_DW.Delay1_67_DSTATE;
      } else {
        DHP_model_B.BusCreator.VDHP_WaterPWM_Duty = rtb_Gain4;
      }
    } else {
      DHP_model_B.BusCreator.VDHP_WaterPWM_Duty = rtb_Gain4;
    }

    /* End of Switch: '<S10>/Switch14' */

    /* Gain: '<S10>/Gain5' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read2'
     */
    rtb_Gain4 = (uint16_T)(10.0F * hIOP_Fin4_Hz);

    /* Switch: '<S10>/Switch17' incorporates:
     *  Switch: '<S10>/Switch9'
     */
    if (rtb_LogicalOperator1) {
      /* Switch: '<S10>/Switch9' incorporates:
       *  Constant: '<S513>/Constant'
       *  Delay: '<S4>/Delay1'
       *  RelationalOperator: '<S513>/Compare'
       */
      if (DHP_model_DW.Delay1_40_DSTATE == 65535) {
        DHP_model_B.BusCreator.VDHP_VacuumPump_HZ =
          DHP_model_DW.Delay1_40_DSTATE;
      } else {
        DHP_model_B.BusCreator.VDHP_VacuumPump_HZ = rtb_Gain4;
      }
    } else {
      DHP_model_B.BusCreator.VDHP_VacuumPump_HZ = rtb_Gain4;
    }

    /* End of Switch: '<S10>/Switch17' */

    /* Gain: '<S10>/Gain6' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read3'
     */
    rtb_Gain4 = (uint16_T)(100.0F * hIOP_CollisionSw_Duty);

    /* Switch: '<S10>/Switch18' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read4'
     *  DataStoreRead: '<S10>/Data Store Read5'
     *  Gain: '<S10>/Gain10'
     *  Gain: '<S10>/Gain9'
     *  Switch: '<S10>/Switch15'
     *  Switch: '<S10>/Switch16'
     */
    if (rtb_LogicalOperator1) {
      /* Switch: '<S10>/Switch10' incorporates:
       *  Constant: '<S514>/Constant'
       *  Delay: '<S4>/Delay1'
       *  RelationalOperator: '<S514>/Compare'
       */
      if (DHP_model_DW.Delay1_7_DSTATE == 255) {
        DHP_model_B.BusCreator.VDHP_SRSPWM_Duty = DHP_model_DW.Delay1_7_DSTATE;
      } else {
        DHP_model_B.BusCreator.VDHP_SRSPWM_Duty = rtb_Gain4;
      }

      /* End of Switch: '<S10>/Switch10' */

      /* Switch: '<S10>/Switch11' incorporates:
       *  Constant: '<S515>/Constant'
       *  DataStoreRead: '<S10>/Data Store Read4'
       *  Delay: '<S4>/Delay1'
       *  Gain: '<S10>/Gain7'
       *  RelationalOperator: '<S515>/Compare'
       */
      if (DHP_model_DW.Delay1_6_DSTATE == 255) {
        DHP_model_B.BusCreator.VDHP_SRSPWM_HZ = DHP_model_DW.Delay1_6_DSTATE;
      } else {
        DHP_model_B.BusCreator.VDHP_SRSPWM_HZ = (uint16_T)(100.0F *
          hIOP_CollisionSw_Hz);
      }

      /* End of Switch: '<S10>/Switch11' */

      /* Switch: '<S10>/Switch12' incorporates:
       *  Constant: '<S516>/Constant'
       *  DataStoreRead: '<S10>/Data Store Read5'
       *  Delay: '<S4>/Delay1'
       *  Gain: '<S10>/Gain8'
       *  RelationalOperator: '<S516>/Compare'
       */
      if (DHP_model_DW.Delay1_8_DSTATE == 255) {
        DHP_model_B.BusCreator.VDHP_HVInterlock_HZ =
          DHP_model_DW.Delay1_8_DSTATE;
      } else {
        DHP_model_B.BusCreator.VDHP_HVInterlock_HZ = (uint16_T)(100.0F *
          hIOP_HVInterlock_Hz);
      }

      /* End of Switch: '<S10>/Switch12' */
    } else {
      DHP_model_B.BusCreator.VDHP_SRSPWM_Duty = rtb_Gain4;
      DHP_model_B.BusCreator.VDHP_SRSPWM_HZ = (uint16_T)(10.0F *
        hIOP_CollisionSw_Hz);
      DHP_model_B.BusCreator.VDHP_HVInterlock_HZ = (uint16_T)(10.0F *
        hIOP_HVInterlock_Hz);
    }

    /* End of Switch: '<S10>/Switch18' */

    /* Switch: '<S10>/Switch7' incorporates:
     *  Constant: '<S10>/Constant15'
     *  Constant: '<S10>/Constant16'
     *  DataStoreRead: '<S10>/Data Store Read7'
     */
    if (hIOP_HSpdFan_flg > 0) {
      tmp = 2U;
    } else {
      tmp = 0U;
    }

    /* End of Switch: '<S10>/Switch7' */

    /* Sum: '<S10>/Add2' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read6'
     *  Switch: '<S10>/Switch6'
     */
    DHP_model_B.BusCreator.VDHP_HLspdFan = (uint8_T)((uint32_T)(hIOP_LSpdFan_flg
      > 0) + tmp);

    /* DataStoreRead: '<S10>/Data Store Read8' */
    DHP_model_B.BusCreator.VDHP_WaterPump_flg = hIOP_WaterPump_flg;

    /* Delay: '<S4>/Delay1' */
    DHP_model_B.BusCreator.VDHP_EPB_Status = DHP_model_DW.Delay1_282_DSTATE;

    /* DataStoreRead: '<S10>/Data Store Read10' */
    DHP_model_B.BusCreator.VDHP_FastChargeAwake_flg = hIOP_FastChargeAwake_flg;

    /* DataStoreRead: '<S10>/Data Store Read11' */
    DHP_model_B.BusCreator.VDHP_SlowChargeAwake_flg = hIOP_SlowChargeAwake_flg;

    /* DataStoreRead: '<S10>/Data Store Read12' */
    DHP_model_B.BusCreator.VDHP_MainRelay_flg = hIOP_MainRelay_flg;

    /* DataStoreRead: '<S10>/Data Store Read9' */
    DHP_model_B.BusCreator.VDHP_gbWhoWriteCalArea = gbWhoWriteCalArea;

    /* BusCreator: '<S10>/Bus Creator' */
    DHP_model_B.BusCreator.VDHP_GearOut_enum = VDHP_GearOut_enum;

    /* DataTypeConversion: '<S10>/Data Type Conversion13' incorporates:
     *  Delay: '<S4>/Delay5'
     */
    v = (real32_T)fabs(DHP_model_DW.Delay5_5_DSTATE);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        /* BusCreator: '<S10>/Bus Creator' */
        DHP_model_B.BusCreator.VDHP_AccelPedal_per = (uint8_T)(real32_T)floor
          (DHP_model_DW.Delay5_5_DSTATE + 0.5F);
      } else {
        /* BusCreator: '<S10>/Bus Creator' */
        DHP_model_B.BusCreator.VDHP_AccelPedal_per = (uint8_T)
          (DHP_model_DW.Delay5_5_DSTATE * 0.0F);
      }
    } else {
      /* BusCreator: '<S10>/Bus Creator' */
      DHP_model_B.BusCreator.VDHP_AccelPedal_per = (uint8_T)
        DHP_model_DW.Delay5_5_DSTATE;
    }

    /* End of DataTypeConversion: '<S10>/Data Type Conversion13' */

    /* BusCreator: '<S10>/Bus Creator' incorporates:
     *  Constant: '<S10>/Constant'
     *  DataTypeConversion: '<S10>/Data Type Conversion12'
     *  Inport: '<Root>/TQM'
     *  Product: '<S10>/Divide1'
     */
    DHP_model_B.BusCreator.VDHP_BrkLightSwitchActive_flg =
      DHP_model_B.VINP_BrkLightSwitchActive_flg;
    DHP_model_B.BusCreator.VDHP_ABS_VehicleSpeed = (uint16_T)
      (TQM_output.TQM_VehSpd / KDHP_VehSpd_Accuracy);

    /* Switch: '<S10>/Switch1' incorporates:
     *  Constant: '<S10>/Constant3'
     *  Constant: '<S10>/Constant4'
     *  DataStoreRead: '<S10>/Data Store Read18'
     */
    if (hIOP_BrkLightSwitch2_flg > 0) {
      tmp = 2U;
    } else {
      tmp = 0U;
    }

    /* End of Switch: '<S10>/Switch1' */

    /* BusCreator: '<S10>/Bus Creator' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read17'
     *  DataTypeConversion: '<S10>/Data Type Conversion40'
     *  Delay: '<S4>/Delay1'
     *  Gain: '<S10>/Gain2'
     *  Inport: '<Root>/TQM'
     *  Sum: '<S10>/Add'
     *  Switch: '<S10>/Switch'
     */
    DHP_model_B.BusCreator.VDHP_BrkLightSwitch = (uint8_T)((uint32_T)
      (hIOP_BrkLightSwitch1_flg > 0) + tmp);
    DHP_model_B.BusCreator.VDHP_AccelPedalH_kv = (uint16_T)(1000.0F *
      DHP_model_DW.Delay1_15_DSTATE);
    DHP_model_B.BusCreator.VDHP_EPBAppliedReq = TQM_output.TQM_EPBAppliedReq;

    /* Outputs for Atomic SubSystem: '<S4>/DHP_FaultStore_Interface' */
    DHP_model_DHP_FaultStore_Interface();

    /* End of Outputs for SubSystem: '<S4>/DHP_FaultStore_Interface' */

    /* Delay: '<S4>/Delay5' */
    DHP_model_B.VINP_BMSMaxDchaPwr_kW = DHP_model_DW.Delay5_70_DSTATE;

    /* Outputs for Atomic SubSystem: '<S4>/AllFaultPriorityCollect' */
    DHP_model_AllFaultPriorityCollect();

    /* End of Outputs for SubSystem: '<S4>/AllFaultPriorityCollect' */

    /* Switch: '<S466>/Switch' incorporates:
     *  Constant: '<S466>/Constant'
     */
    DHP_output.VDHP_AccPdlLHVoltDeathInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AccPdlLHVoltDeathInstFlt_flg);

    /* Switch: '<S468>/Switch' incorporates:
     *  Constant: '<S468>/Constant'
     */
    DHP_output.VDHP_VCUtoICM235LossCanNetFault_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_ICM235MissingInstFlt_flg);

    /* Switch: '<S469>/Switch' incorporates:
     *  Constant: '<S469>/Constant'
     */
    DHP_output.VDHP_AuxBattVoltHighInstWarm_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AuxBattVoltHighInstWarm_flg);

    /* Switch: '<S470>/Switch' incorporates:
     *  Constant: '<S470>/Constant'
     */
    DHP_output.VDHP_AuxBattVoltHighInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AuxBattVoltHighInstFlt_flg);

    /* Switch: '<S471>/Switch' incorporates:
     *  Constant: '<S471>/Constant'
     */
    DHP_output.VDHP_AuxBattVoltLowInstWarm_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AuxBattVoltLowInstWarm_flg);

    /* Switch: '<S472>/Switch' incorporates:
     *  Constant: '<S472>/Constant'
     */
    DHP_output.VDHP_AuxBattVoltLowInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AuxBattVoltLowInstFlt_flg);

    /* Switch: '<S473>/Switch' incorporates:
     *  Constant: '<S473>/Constant'
     */
    DHP_output.VDHP_AccPdlLVoltHighInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AccPdlLVoltHighInstFlt_flg);

    /* Switch: '<S474>/Switch' incorporates:
     *  Constant: '<S474>/Constant'
     */
    DHP_output.VDHP_AccPdlHVoltLowInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AccPdlHVoltLowInstFlt_flg);

    /* Switch: '<S475>/Switch' incorporates:
     *  Constant: '<S475>/Constant'
     */
    DHP_output.VDHP_AccPdlHVoltHighInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AccPdlHVoltHighInstFlt_flg);

    /* Switch: '<S476>/Switch' incorporates:
     *  Constant: '<S476>/Constant'
     */
    DHP_output.VDHP_AccPdlLVoltLowInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AccPdlLVoltLowInstFlt_flg);

    /* Switch: '<S477>/Switch' incorporates:
     *  Constant: '<S477>/Constant'
     */
    DHP_output.VDHP_AccelPdlRatInstFlt_flg = (KDHP_VcuControlDeviceInstErrValid &&
      VDHP_AccelPdlRatInstFlt_flg);

    /* Switch: '<S478>/Switch' incorporates:
     *  Constant: '<S478>/Constant'
     */
    DHP_output.VDHP_AccPdlSenRefVoltHighInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AccPdlSenRefVoltHighInstFlt_flg);

    /* Switch: '<S479>/Switch' incorporates:
     *  Constant: '<S479>/Constant'
     */
    DHP_output.VDHP_AccPdlSenRefVoltLowInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AccPdlSenRefVoltLowInstFlt_flg);

    /* Switch: '<S480>/Switch' incorporates:
     *  Constant: '<S480>/Constant'
     */
    DHP_output.VDHP_AccelPdlRatDeathInstFlt_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_AccelPdlRatDeathInstFlt_flg);

    /* Switch: '<S481>/Switch' incorporates:
     *  Constant: '<S481>/Constant'
     */
    DHP_output.VDHP_VCUtoABS232LossCanNetFault_flg =
      (KDHP_VcuControlDeviceInstErrValid && VDHP_ABS232MissingInstFlt_flg);

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_104_DSTATE = INP_output.CANBMS_signal.VINP_BMSErrNum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_9_DSTATE =
      INP_output.Hardwire_signal.VINP_IgnitionOn_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_6_DSTATE = PMM_output.VPMM_PTReady_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_26_DSTATE = PMM_output.VPMM_UpToHVMode_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_25_DSTATE = PMM_output.VPMM_LVComplete_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_8_DSTATE = PMM_output.VPMM_HVPowerDownReq_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_24_DSTATE = PMM_output.VPMM_LVEna;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_231_DSTATE =
      HALI_output.CAN_Inputs.HALI_SRS.VHALI_SRS_CrashOutputStatus;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_23_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_LSFaultCode_enum;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_24_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_HSFaultCode_enum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_152_DSTATE = INP_output.CANMCU_signal.VINP_MCUIGBTT_C;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_149_DSTATE = INP_output.CANMCU_signal.VINP_MCUElecMotT_C;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_153_DSTATE = INP_output.CANMCU_signal.VINP_MCUT_C;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_242_DSTATE =
      INP_output.CANDCDC_signal.VINP_DCDCFltRnk_enum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_205_DSTATE =
      INP_output.CANOBC_signal.VINP_OBCFltRnk_enum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_148_DSTATE =
      INP_output.CANMCU_signal.VINP_MCUFltRnk_enum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_145_DSTATE = INP_output.CANMCU_signal.VINP_MCUDcU_V;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_146_DSTATE = INP_output.CANMCU_signal.VINP_MCUDcCrrt_A;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_194_DSTATE = INP_output.CANMCU_signal.MCUHWCurrOverErr;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_160_DSTATE =
      INP_output.CANMCU_signal.VINP_MCUPwrModErr_flg;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_53_DSTATE = INP_output.CANBMS_signal.VINP_BMSFltRnk_enum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_54_DSTATE =
      INP_output.CANBMS_signal.VINP_BMSOperMod_enum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_50_DSTATE = INP_output.CANBMS_signal.VINP_BMSBattU_V;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_109_DSTATE = INP_output.CANBMS_signal.VINP_BMSCellUMax;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_106_DSTATE = INP_output.CANBMS_signal.VINP_BMSCellUMin;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_86_DSTATE = INP_output.CANBMS_signal.VINP_BMSMaxBattT;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_80_DSTATE =
      INP_output.CANBMS_signal.VINP_BMSChrgMod_enum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_155_DSTATE = INP_output.CANMCU_signal.VINP_MCUErrNum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_141_DSTATE =
      INP_output.CANMCU_signal.VINP_MCUOperMdl_enum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_314_DSTATE = INP_output.ABS.VINP_ABS_AbsFlgFlt;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_359_DSTATE = INP_output.EPB.VINP_EPS_EpasFailed;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_313_DSTATE = INP_output.ABS.VINP_ABS_EbdFlgFlt;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_356_DSTATE = INP_output.EPB.VINP_EPB_Status;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_317_DSTATE =
      INP_output.ABS.VINP_ABS_VehicleSpeedValid_flg;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_140_DSTATE =
      INP_output.CANMCU_signal.VINP_MotTqRealValid_flg;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_138_DSTATE =
      INP_output.CANMCU_signal.VINP_MCUElecMotSpdValid_flg;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_124_DSTATE = INP_output.CANBMS_signal.VINP_BMSBattUOverU;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_125_DSTATE =
      INP_output.CANBMS_signal.VINP_BMSBattUUnderU;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_126_DSTATE =
      INP_output.CANBMS_signal.VINP_BMSCellUMaxOverU;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_123_DSTATE =
      INP_output.CANBMS_signal.VINP_BMSCellUMinUnderU;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_127_DSTATE =
      INP_output.CANBMS_signal.VINP_BMSMaxBattTOverT;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_333_DSTATE = INP_output.ABS.VINP_ESP_ESPFailStatus;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_15_DSTATE = PMM_output.VPMM_LVUpTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_16_DSTATE = PMM_output.VPMM_HVUpTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_17_DSTATE = PMM_output.VPMM_HVActiveTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_19_DSTATE = PMM_output.VPMM_HVDownTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_20_DSTATE = PMM_output.VPMM_MCUDischargeTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_11_DSTATE = PMM_output.VPMM_LVUpBMSPwrUpAllwTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_12_DSTATE = PMM_output.VPMM_LVUpBMSTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_13_DSTATE = PMM_output.VPMM_LVUpDCDCTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_14_DSTATE = PMM_output.VPMM_LVUpMCUTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_22_DSTATE = PMM_output.VPMM_MCUHVActiveTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_21_DSTATE = PMM_output.VPMM_HVDCDCActiveTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_30_DSTATE = PMM_output.VPMM_BMSModError;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_29_DSTATE = PMM_output.VPMM_MCUModError;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_31_DSTATE = PMM_output.VPMM_DCDCModError;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_33_DSTATE = PMM_output.VPMM_MCUExitTqlTimeout_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_34_DSTATE = PMM_output.VPMM_DCDCStopworkTimeout_flg;

    /* Update for Delay: '<S4>/Delay2' incorporates:
     *  Update for Inport: '<Root>/CHRG'
     */
    DHP_model_DW.Delay2_6_DSTATE = CHRG_output.VCHRG_ChrgStsLampReq_flg;

    /* Update for Delay: '<S4>/Delay2' incorporates:
     *  Update for Inport: '<Root>/CHRG'
     */
    DHP_model_DW.Delay2_2_DSTATE = CHRG_output.VCHRG_VCUChrgAllwd_flg;

    /* Update for Delay: '<S4>/Delay3' incorporates:
     *  Update for Inport: '<Root>/TMM'
     */
    DHP_model_DW.Delay3_2_DSTATE = TMM_output.TMM_WaterPumpEnReq_flg;

    /* Update for Delay: '<S4>/Delay3' incorporates:
     *  Update for Inport: '<Root>/TMM'
     */
    DHP_model_DW.Delay3_9_DSTATE = TMM_output.TMM_VCUChrgReqLimFac_enum;

    /* Update for Delay: '<S4>/Delay3' incorporates:
     *  Update for Inport: '<Root>/TMM'
     */
    DHP_model_DW.Delay3_41_DSTATE = TMM_output.TMM_InvalidBattReq;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_16_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_FastChargeTemp1_C;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_17_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_FastChargeTemp2_C;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_27_DSTATE =
      INP_output.Hardwire_signal.VINP_SlowChargeAwakeActive_flg;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_28_DSTATE =
      INP_output.Hardwire_signal.VINP_FastChargeAwakeActiveIn_flg;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_525_DSTATE =
      INP_output.ICM.VINP_ICM_VehSpdChkInvalidFlt_flg;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_7_DSTATE =
      INP_output.Hardwire_signal.VINP_BrkLightSwitchActive_flg;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_28_DSTATE = PMM_output.VPMM_IChrgSts;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_99_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_SSB_Switch_1;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_100_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_SSB_Switch_2;

    /* Update for UnitDelay: '<S502>/Unit Delay' */
    DHP_model_DW.UnitDelay_DSTATE_h = rtb_Switch_h;

    /* Update for Delay: '<S4>/Delay6' incorporates:
     *  Update for Inport: '<Root>/PMM'
     */
    DHP_model_DW.Delay6_10_DSTATE = PMM_output.VPMM_VehSts_enum;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_303_DSTATE = INP_output.PEPS.VINP_PEPS_PDU;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_5_DSTATE =
      INP_output.Hardwire_signal.VINP_AccelPedal_per;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_20_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_LVBattVoltage_V;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_321_DSTATE =
      HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSChrgSts;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_377_DSTATE =
      HALI_output.CAN_Inputs.HALI_MCU.VHALI_MotTqReal;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_391_DSTATE =
      HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUIGBTT;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_388_DSTATE =
      HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUElecMotT;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_376_DSTATE =
      HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUElecMotSpd;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_291_DSTATE =
      HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSSOC;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_289_DSTATE =
      HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSBattU;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_290_DSTATE =
      HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSBattI;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_331_DSTATE =
      HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSAvrgBattT;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_452_DSTATE =
      HALI_output.CAN_Inputs.HALI_DCDC.VHALI_DCDCT;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_272_DSTATE =
      HALI_output.CAN_Inputs.HALI_EHU.VHALI_ClstrOdo;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_517_DSTATE =
      HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeYear;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_518_DSTATE =
      HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeMonth;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_519_DSTATE =
      HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeDate;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_520_DSTATE =
      HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeHour;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_521_DSTATE =
      HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeMinute;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_522_DSTATE =
      HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeSecond;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_343_DSTATE =
      HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSErrNum;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_394_DSTATE =
      HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUErrNum;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_15_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_AccelPedalH_V;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_14_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_AccelPedalL_V;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_67_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_WaterPwmIn_Duty;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_40_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_VacuumPumpIn_Hz;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_7_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_CollisionDuty_pct;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_6_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_Collisionfre_Hz;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_8_DSTATE =
      HALI_output.Hardwire_Inputs.VHALI_HVInterlockFreIn_Hz;

    /* Update for Delay: '<S4>/Delay1' incorporates:
     *  Update for Inport: '<Root>/HALI'
     */
    DHP_model_DW.Delay1_282_DSTATE =
      HALI_output.CAN_Inputs.HALI_EPB.VHALI_EPB_Status;

    /* Update for Delay: '<S4>/Delay5' incorporates:
     *  Update for Inport: '<Root>/INP'
     */
    DHP_model_DW.Delay5_70_DSTATE =
      INP_output.CANBMS_signal.VINP_BMSMaxDchaPwr_kW;
  } else {
    if (DHP_model_DW.DHP_MODE) {
      /* Disable for S-Function (fcncallgen): '<S4>/Function-Call Generator2' incorporates:
       *  Disable for SubSystem: '<S4>/SysErrProduct2'
       */
      DHP_model_SysErrProduct2_Disable();

      /* End of Disable for S-Function (fcncallgen): '<S4>/Function-Call Generator2' */
      DHP_model_DW.DHP_MODE = false;
    }
  }

  /* End of Logic: '<S1>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S1>/DHP' */

  /* BusCreator: '<S1>/Bus Creator' */
  DHP_output.VDHP_BrakeSysFault_Flg = VDHP_BrakeSysFault_Flg;
  DHP_output.VDHP_AccPedalFault_Flg = VDHP_AccPedalFault_Flg;
  DHP_output.VDHP_GearSingleNotInAeraFlt_Flg = VDHP_GearSingleNotInAeraFlt_Flg;
  DHP_output.DCDCFault_Flg = VDHP_DCDCFault_Flg;
  DHP_output.OBCFault_Flg = VDHP_OBCFault_Flg;
  DHP_output.MCUFault_Flg = VDHP_MCUFault_Flg;
  DHP_output.BMSFault_Flg = VDHP_BMSFault_Flg;
  DHP_output.VDHP_MaxFaultLever = VDHP_MaxFaultLever;
  DHP_output.VDHP_MCU_DisEnableFlg = VDHP_MCU_DisEnableFlg;
  DHP_output.VDHP_Forbid_DCDCFlg = VDHP_Forbid_DCDCFlg;
  DHP_output.VDHP_Forbid_ConditionFlg = VDHP_Forbid_ConditionFlg;
  DHP_output.VDHP_Forbid_PTCFlg = VDHP_Forbid_PTCFlg;
  DHP_output.VDHP_Spd_Limit = VDHP_Spd_Limit;
  DHP_output.VDHP_Pwr_Limit_Pct = VDHP_Pwr_Limit_Pct;
  DHP_output.VDHP_Forbid_ChargeFlg = VDHP_Forbid_ChargeFlg;
  DHP_output.VDHP_Forbid_ActiveDischargeFlg = VDHP_Forbid_ActiveDischargeFlg;
  DHP_output.VDHP_Forbid_PreChargeFlg = VDHP_Forbid_PreChargeFlg;
  DHP_output.VDHP_Off_DeviceRelayFlg = VDHP_Off_DeviceRelayFlg;
  DHP_output.VDHP_OFFMainRelayFlg = VDHP_OFFMainRelayFlg;
  DHP_output.VDHP_OFFAllHVRelayFlg = VDHP_OFFAllHVRelayFlg;
  DHP_output.VDHP_Normal_PowerDownFlg = VDHP_Normal_PowerDownFlg;
  DHP_output.VDHP_AccPdlLVoltLowFault_flg =
    DHP_model_B.Fault_Valid_Time_c.Fault_Affirm.Switch2;
  DHP_output.VDHP_AccPdlLVoltHighFault_flg =
    DHP_model_B.Fault_Valid_Time_k.Fault_Affirm.Switch2;
  DHP_output.VDHP_AccPdlLHVoltDeathFault_flg =
    DHP_model_B.Fault_Valid_Time_o.Fault_Affirm.Switch2;
  DHP_output.VDHP_AccPdlHVoltLowFault_flg =
    DHP_model_B.Fault_Valid_Time_j.Fault_Affirm.Switch2;
  DHP_output.VDHP_AccPdlHVoltHighFault_flg =
    DHP_model_B.Fault_Valid_Time.Fault_Affirm.Switch2;
  DHP_output.VDHP_AccelPdlRatFault_flg =
    DHP_model_B.Fault_Valid_Time_i.Fault_Affirm.Switch2;
  DHP_output.VDHP_AccPdlSenRefVoltHighFault_flg =
    DHP_model_B.Fault_Valid_Time_b.Fault_Affirm.Switch2;
  DHP_output.VDHP_AccPdlSenRefVoltLowFault_flg =
    DHP_model_B.Fault_Valid_Time_n.Fault_Affirm.Switch2;
  DHP_output.VDHP_AuxBattVoltHighWarnFault_flg =
    DHP_model_B.Fault_Valid_Time_h.Fault_Affirm.Switch2;
  DHP_output.VDHP_AuxBattVoltLowWarnFault_flg =
    DHP_model_B.Fault_Valid_Time_o0.Fault_Affirm.Switch2;
  DHP_output.VDHP_AuxBattVoltHighFltFault_flg =
    DHP_model_B.Fault_Valid_Time_la.Fault_Affirm.Switch2;
  DHP_output.VDHP_AuxBattVoltLowFltFault_flg =
    DHP_model_B.Fault_Valid_Time_n1.Fault_Affirm.Switch2;
  DHP_output.VDHP_CoolingSysFault_Flg = VDHP_CoolingSysFault_Flg;
  DHP_output.VDHP_MCUOverSpdFault_Flg = false;
  DHP_output.VDHP_MCUSysOverTFault_Flg = VDHP_MCUSysOverTFault_Flg;
  DHP_output.VDHP_MCUFltExitReady_Flg = VDHP_MCUFltExitReady_Flg;
  DHP_output.VDHP_Forbid_FeedbackFlg = VDHP_Forbid_FeedbackFlg;
  DHP_output.VDHP_Forbid_CreepFlg = VDHP_Forbid_CreepFlg;
  DHP_output.VDHP_Forbid_CruiseFlg = VDHP_Forbid_CruiseFlg;
  DHP_output.VDHP_AccelPdlRatDeathFault_flg = DHP_model_B.Fault_Affirm.Switch2;
  DHP_output.VDHP_VCUBattChrgErr_Flg = VDHP_VCUBattChrgErr_Flg;
  DHP_output.VDHP_MCUFaultSpeedBased_Flg = VDHP_MCUFaultSpeedBased_Flg;
  DHP_output.VDHP_BMSFaultSpeedBased_Flg = DHP_model_B.Switch10;
  DHP_output.VDHP_BMSFaultTimeBased_Flg = VDHP_BMSFailTimeBased_Flg;
  DHP_output.VDHP_CruiseHWFault_Flg = VDHP_CruiseHWFault_Flg;
  DHP_output.VDHP_VCUFaultSpeedBased_Flg = VDHP_VCUFaultSpeedBased_Flg;

  /* Update for Delay: '<S1>/Delay' */
  DHP_model_DW.Delay_DSTATE = rtb_DataStoreRead1_cg;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
