-------------------
--ET4100: COM7
--开始
scd_mdbNewPort(7, 9600, 80, 1)
--转速
rev=scd_mdbReadRegF32(1, 320)
--扭矩
rev=scd_mdbReadRegF32(1, 322)
--结束
scd_mdbClosePort()

--------------------
--scd : com13

--------------------
--电阻箱 ：com8
scd_rBox_init(8)

--------------------
--双余度422 ：com9

--画图位置调节
scd_YaxisSet("thetaRDC_raw", -300000, 300000)
scd_YaxisSet("CH1_Udc", -800, 500)
scd_YaxisSet("CH1_Idc", -300, 300)
scd_YaxisSet("CH1_Id", -300, 300)
scd_YaxisSet("targetId_CH1", -300, 300)
scd_YaxisSet("CH1_Iq", -300, 300)
scd_YaxisSet("targetIq_CH1", -300, 300)
scd_YaxisSet("CH1_Utar.d", -600, 600)
scd_YaxisSet("CH1_Utar.q", -600, 600)
scd_YaxisSet("CH2_Udc", -800, 500)
scd_YaxisSet("CH2_Idc", -300, 300)
scd_YaxisSet("CH2_Id", -300, 300)
scd_YaxisSet("targetId_CH2", -300, 300)
scd_YaxisSet("CH2_Iq", -300, 300)
scd_YaxisSet("targetIq_CH2", -300, 300)
scd_YaxisSet("CH2_Utar.d", -600, 600)
scd_YaxisSet("CH2_Utar.q", -600, 600)
scd_YaxisSet("targetUdc", -800, 500)
scd_YaxisSet("targetN", -20000, 50000)
scd_YaxisSet("targetOmegaM", -2000, 5000)
scd_YaxisSet("omegaMfbk", -2000, 5000)
scd_YaxisSet("CH1_Iv_raw", -20000, 50000)
scd_YaxisSet("CH1_Iw_raw", -20000, 50000)
scd_YaxisSet("CH1_Idc_raw", -20000, 50000)
scd_YaxisSet("CH2_Iu_raw", -20000, 50000)
scd_YaxisSet("CH2_Iv_raw", -20000, 50000)
scd_YaxisSet("CH2_Idc_raw", -20000, 50000)
scd_YaxisSet("CH1_powerTempMax", -100, 1000)
scd_YaxisSet("CH2_powerTempMax", -100, 1000)
scd_YaxisSet("PT100_1_2_temp[0]", -100, 1000)
scd_YaxisSet("PT100_1_2_temp[1]", -100, 1000)

--变量范围设定
function scd_YaxisSet(name, low, up)
