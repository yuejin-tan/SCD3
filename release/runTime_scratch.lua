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
scd_valRangeSet("CH1_cur_mode", 8, 0)
scd_valRangeSet("CH2_cur_mode", 8, 0)
scd_valRangeSet("speed_mode", 17, 0)
scd_valRangeSet("channel_mode", 7, 0)
scd_valRangeSet("CH1_angle_mode", 3, 0)
scd_valRangeSet("CH2_angle_mode", 3, 0)
scd_valRangeSet("thetaRDC_raw_offset_CH1", 65535, 0)
scd_valRangeSet("thetaRDC_raw_offset_CH2", 65535, 0)
scd_valRangeSet("IProtectFlg_CH1", 0, 0)
scd_valRangeSet("IProtectFlg_CH2", 0, 0)
scd_valRangeSet("SPDProtectFlg", 0, 0)
scd_valRangeSet("UdcProtectFlg_CH1", 0, 0)
scd_valRangeSet("UdcProtectFlg_CH2", 0, 0)
scd_valRangeSet("tempProtectFlg", 0, 0)
scd_valRangeSet("targetIs", 200, -200)
scd_valRangeSet("targetThetaMTPA", 1, 0)
scd_valRangeSet("targetId_CH1", 200, -200)
scd_valRangeSet("targetIq_CH1", 200, -200)
scd_valRangeSet("CH1_Utar.d", 100, -100)
scd_valRangeSet("CH1_Utar.q", 100, -100)
scd_valRangeSet("targetThetaE_CH1", 1, 0)
scd_valRangeSet("targetId_CH2", 200, -200)
scd_valRangeSet("targetIq_CH2", 200, -200)
scd_valRangeSet("CH2_Utar.d", 100, -100)
scd_valRangeSet("CH2_Utar.q", 100, -100)
scd_valRangeSet("targetThetaE_CH2", 1, 0)
scd_valRangeSet("targetUdc", 300, 30)
scd_valRangeSet("targetN", 13000, 0)
scd_valRangeSet("targetOmegaM", 1200, 0)
scd_valRangeSet("targetWaveMode", 1, 0)
scd_valRangeSet("targetWaveFreq", 5000, 0)
scd_valRangeSet("targetWaveAmp", 100, 0)
scd_valRangeSet("targetWaveOffset", 100, -100)
scd_valRangeSet("targetRampVal", 12000, 0)
scd_valRangeSet("targetRampGrad", 1000, 0)
scd_valRangeSet("CH1_Iv_raw_offset", 4095, 0)
scd_valRangeSet("CH1_Iw_raw_offset", 4095, 0)
scd_valRangeSet("CH1_Idc_raw_offset", 4095, 0)
scd_valRangeSet("CH2_Iu_raw_offset", 4095, 0)
scd_valRangeSet("CH2_Iv_raw_offset", 4095, 0)
scd_valRangeSet("CH2_Idc_raw_offset", 4095, 0)
scd_valRangeSet("ad2s1210ErrGPIO", 0, 0)
