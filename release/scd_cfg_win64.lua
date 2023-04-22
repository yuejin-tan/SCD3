--[[

����LUA�ű��ĳ�ʼ�������ļ�
��֤���ļ�Ϊ����ansi���룡����

]]

--���ò���
scd_callTest("version info: "..mainVer);

--�Ƿ��������ڣ�Լ0.1s����������
scd_enable_periodically_run_feature = false;

--�ᱻ���ڣ�0.1s�����õĺ�����ע�ⲻҪ�ӷ���ֵ
function scd_periodRun(elapsedMsFromStart)
	if cnt==nil then
	cnt=0;
	end
	cnt=cnt+1;
	if (cnt==20) then
	cnt=0;
	end
	if (cnt==0) then
	--print("scd�������в���@"..elapsedMsFromStart.."ms");
	end
end

--�����ļ��е�Ĭ��λ��
scd_save_dir = [[
.
]]

--�Ƿ�Ԥ����ű��ļ��е�C����
scd_preload_init_c_code_in_script = true;

--Ԥ����C����
scd_init_c_code = [[

SCD_REG_BEGIN(_1)
SCD_REG_ADD(CH1_cur_mode, int16_t)
SCD_REG_ADD(CH2_cur_mode, int16_t)
SCD_REG_ADD(speed_mode, int16_t)
SCD_REG_ADD(channel_mode, int16_t)
SCD_REG_ADD(CH1_angle_mode, int16_t)
SCD_REG_ADD(CH2_angle_mode, int16_t)
SCD_REG_ADD(thetaRDC_raw_offset_CH1, uint16_t)
SCD_REG_ADD(thetaRDC_raw_offset_CH2, uint16_t)
SCD_REG_ADD(thetaRDC_raw, uint16_t)
SCD_REG_ADD(IProtectFlg_CH1, int16_t)
SCD_REG_ADD(IProtectFlg_CH2, int16_t)
SCD_REG_ADD(SPDProtectFlg, int16_t)
SCD_REG_ADD(UdcProtectFlg_CH1, int16_t)
SCD_REG_ADD(UdcProtectFlg_CH2, int16_t)
SCD_REG_ADD(tempProtectFlg, int16_t)
SCD_REG_ADD(isr_start_pwm_cnt, uint16_t)
SCD_REG_ADD(isr_end_pwm_cnt, uint16_t)
SCD_REG_ADD(targetIs, float)
SCD_REG_ADD(targetThetaMTPA, float)
SCD_REG_ADD(CH1_Udc, float)
SCD_REG_ADD(CH1_Idc, float)
SCD_REG_ADD(CH1_Id, float)
SCD_REG_ADD(targetId_CH1, float)
SCD_REG_ADD(CH1_Iq, float)
SCD_REG_ADD(targetIq_CH1, float)
SCD_REG_ADD(CH1_Utar.d, float)
SCD_REG_ADD(CH1_Utar.q, float)
SCD_REG_ADD(CH1_thetaI.theta, float)
SCD_REG_ADD(CH1_thetaU.theta, float)
SCD_REG_ADD(CH1_svpwm.Udc, float)
SCD_REG_ADD(targetThetaE_CH1, float)
SCD_REG_ADD(CH2_Udc, float)
SCD_REG_ADD(CH2_Idc, float)
SCD_REG_ADD(CH2_Id, float)
SCD_REG_ADD(targetId_CH2, float)
SCD_REG_ADD(CH2_Iq, float)
SCD_REG_ADD(targetIq_CH2, float)
SCD_REG_ADD(CH2_Utar.d, float)
SCD_REG_ADD(CH2_Utar.q, float)
SCD_REG_ADD(CH2_thetaI.theta, float)
SCD_REG_ADD(CH2_thetaU.theta, float)
SCD_REG_ADD(CH2_svpwm.Udc, float)
SCD_REG_ADD(targetThetaE_CH2, float)
SCD_REG_ADD(thetaEInc, float)
SCD_REG_ADD(targetUdc, float)
SCD_REG_ADD(targetN, float)
SCD_REG_ADD(targetOmegaM, float)
SCD_REG_ADD(omegaMfbk, float)
SCD_REG_ADD(targetWaveMode, int16_t)
SCD_REG_ADD(targetWaveFreq, float)
SCD_REG_ADD(targetWaveAmp, float)
SCD_REG_ADD(targetWaveOffset, float)
SCD_REG_ADD(targetRampVal, float)
SCD_REG_ADD(targetRampGrad, float)
SCD_REG_ADD(CH1_Iv_raw, int16_t)
SCD_REG_ADD(CH1_Iw_raw, int16_t)
SCD_REG_ADD(CH1_Idc_raw, int16_t)
SCD_REG_ADD(CH1_Iv_raw_offset, int16_t)
SCD_REG_ADD(CH1_Iw_raw_offset, int16_t)
SCD_REG_ADD(CH1_Idc_raw_offset, int16_t)
SCD_REG_ADD(CH2_Iu_raw, int16_t)
SCD_REG_ADD(CH2_Iv_raw, int16_t)
SCD_REG_ADD(CH2_Idc_raw, int16_t)
SCD_REG_ADD(CH2_Iu_raw_offset, int16_t)
SCD_REG_ADD(CH2_Iv_raw_offset, int16_t)
SCD_REG_ADD(CH2_Idc_raw_offset, int16_t)
SCD_REG_ADD(CH1_powerTempMax, float)
SCD_REG_ADD(CH2_powerTempMax, float)
SCD_REG_ADD(PT100_1_2_temp[0], float)
SCD_REG_ADD(PT100_1_2_temp[1], float)
SCD_REG_ADD(UdcPI.kp, float)
SCD_REG_ADD(UdcPI.ki, float)
SCD_REG_ADD(UdcPI_kp_base, float)
SCD_REG_ADD(UdcPI_ki_base, float)
SCD_REG_ADD(omegaPI.kp, float)
SCD_REG_ADD(omegaPI.ki, float)
SCD_REG_ADD(omegaPI.kb, float)
SCD_REG_ADD(CH1_IdPI.kp, float)
SCD_REG_ADD(CH1_IdPI.ki, float)
SCD_REG_ADD(CH2_IdPI.kp, float)
SCD_REG_ADD(CH2_IdPI.ki, float)
SCD_REG_ADD(CH1_IqPI.kp, float)
SCD_REG_ADD(CH1_IqPI.ki, float)
SCD_REG_ADD(CH2_IqPI.kp, float)
SCD_REG_ADD(CH2_IqPI.ki, float)
SCD_REG_ADD(ad2s1210ErrGPIO, hex16)
SCD_REG_ADD(dbg_ad2s1210Err, hex16)
SCD_REG_ADD(RDV_err_check, function)
SCD_REG_ADD(adcOffset_init, function)
SCD_REG_ADD(scd_Udc_set, function)
SCD_REG_ADD(sram_init, function)
SCD_REG_ADD(ad2s1210_ClaAccModeEn, function)
SCD_REG_END(_1)
]]

--����Ϊscd�ڲ�ִ�к�������������
function scd_dump(listNum, dumpNums)
	--�������
	if type(listNum) ~= "number" then
	print("����listNum����");
	return;
	end
	
	if type(dumpNums) ~= "number" then
	print("����dumpNums����");
	return;
	end

	scd_dump_impl(listNum, dumpNums);
end

function scd_dumpOut(colCnt, method)
	--�������
	if type(colCnt) ~= "number" then
	print("����colCnt����");
	return;
	end
	
	if type(method) ~= "string" then
	print("����method����");
	return;
	end
	
	scd_dumpOut_impl(colCnt, method);
end

function scd_sendStr(strToSend)
	--�������
	if type(strToSend) ~= "string" then
	print("����strToSend����");
	end

	scd_sendStr_impl(strToSend);
end

function scd_setVar(listNum, setVar)
	--�������
	if type(listNum) ~= "number" then
	print("����listNum����");
	return;
	end
	
	if type(setVar) ~= "number" then
	print("����setVar����");
	return;
	end
	
	scd_sendStr("set"..(listNum-1)..[[#]]..setVar..[[!!!!]]);
	scd_sendStr("set"..(listNum-1)..[[#]]..setVar..[[!!!!]]);
end

function scd_refresh()
	scd_sendStr([[chg0#1!!!!]]);
	scd_sendStr([[chg0#1!!!!]]);
end

function scd_getVar(listNum)
	--�������
	if type(listNum) ~= "number" then
	print("����listNum����");
	return;
	end
	
	return scd_getVar_impl(listNum);
end

function scd_call(listNum, paraNum)
	--�������
	if type(listNum) ~= "number" then
	print("����listNum����");
	return;
	end
	
	if type(paraNum) ~= "number" then
	print("����paraNum����");
	return;
	end
	
	scd_sendStr("call"..(listNum-1)..[[#]]..paraNum..[[!!!!]]);
	scd_sendStr("call"..(listNum-1)..[[#]]..paraNum..[[!!!!]]);
end

function scd_delayMs(ms)
	--�������
	if type(ms) ~= "number" then
	print("����ms���ʹ���");
	return;
	end
	
	if ms < 20 then
	print("����ms��Χ��������20ms�����50ms");
	return;
	end
	
	scd_delayMs_impl(ms)
end

--����modbus API

function scd_mdbNewPort(portNum, baud, timeout, retryNum)
	--�������
	if type(portNum) ~= "number" then
	print("����portNum���ʹ���");
	return;
	end
	if type(baud) ~= "number" then
	print("����baud���ʹ���");
	return;
	end
	if type(timeout) ~= "number" then
	print("����timeout���ʹ���");
	return;
	end
	if type(retryNum) ~= "number" then
	print("����retryNum���ʹ���");
	return;
	end
	
	scd_mdbNewPort_impl(portNum, baud, timeout, retryNum)
end

function scd_mdbClosePort()

	scd_mdbClosePort_impl()
end

function scd_mdbReadRegF32(mdbAddr, regAddr)
	--�������
	if type(mdbAddr) ~= "number" then
	print("����mdbAddr���ʹ���");
	return;
	end
	if type(regAddr) ~= "number" then
	print("����regAddr���ʹ���");
	return;
	end
	
	return scd_mdbReadRegF32_impl(mdbAddr, regAddr)
end

function scd_rBox_init(portNum)
	--�������
	if type(portNum) ~= "number" then
	print("����portNum���ʹ���");
	return;
	end
	
	scd_rBox_init_impl(portNum)
end

function scd_rBox_ctrl(rNo, sta)
	--�������
	if type(rNo) ~= "number" then
	print("����rNo���ʹ���");
	return;
	end
	if type(sta) ~= "number" then
	print("����sta���ʹ���");
	return;
	end
	
	scd_rBox_ctrl_impl(rNo, sta)
	scd_delayMs(250)
end

function scd_YaxisSet(name, low, up)
	--�������
	if type(name) ~= "string" then
	print("����name���ʹ���");
	return;
	end
	if type(low) ~= "number" then
	print("����low���ʹ���");
	return;
	end
	if type(up) ~= "number" then
	print("����up���ʹ���");
	return;
	end

	scd_YaxisSet_impl(name, low, up)
end
