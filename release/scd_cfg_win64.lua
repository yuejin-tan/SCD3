--[[

基于LUA脚本的初始化配置文件
保证此文件为本地ansi编码！！！

]] -- 调用测试
scd_callTest("version info: " .. mainVer);

-- 是否启用周期（约0.1s）运行特性
scd_enable_periodically_run_feature = false;

-- 会被周期（0.1s）调用的函数，注意不要加返回值
function scd_periodRun(elapsedMsFromStart)
    if cnt == nil then
        cnt = 0;
    end
    cnt = cnt + 1;
    if (cnt == 20) then
        cnt = 0;
    end
    if (cnt == 0) then
        -- print("scd周期运行测试@"..elapsedMsFromStart.."ms");
    end
end

-- 保存文件夹的默认位置
scd_save_dir = [[
.
]]

-- 是否预载入脚本文件中的C代码
scd_preload_init_c_code_in_script = true;

-- 预载入C代码
scd_init_c_code = [[
SCD_REG_BEGIN(_1)
SCD_REG_ADD(CH1_cur_mode, int16_t)
SCD_REG_ADD(CH2_cur_mode, int16_t)
SCD_REG_ADD(speed_mode, int16_t)
SCD_REG_ADD(torque_mode, int16_t)
SCD_REG_ADD(channel_mode, int16_t)
SCD_REG_ADD(CH1_angle_mode, int16_t)
SCD_REG_ADD(CH2_angle_mode, int16_t)
SCD_REG_ADD(CH1_ext_fcn, int16_t)
SCD_REG_ADD(CH2_ext_fcn, int16_t)
SCD_REG_ADD(thetaRDC_raw, uint16_t)
SCD_REG_ADD(IProtectFlg_CH1, int16_t)
SCD_REG_ADD(IProtectFlg_CH2, int16_t)
SCD_REG_ADD(SPDProtectFlg, int16_t)
SCD_REG_ADD(UdcProtectFlg_CH1, int16_t)
SCD_REG_ADD(UdcProtectFlg_CH2, int16_t)
SCD_REG_ADD(tempProtectFlg, int16_t)
SCD_REG_ADD(isr_start_pwm_cnt, uint16_t)
SCD_REG_ADD(isr_end_pwm_cnt, uint16_t)
SCD_REG_ADD(ad2s1210ErrGPIO, hex16)
SCD_REG_ADD(dbg_ad2s1210Err, hex16)
SCD_REG_ADD(targetWaveMode, int16_t)
SCD_REG_ADD(targetWaveFreq, float)
SCD_REG_ADD(targetWaveAmp, float)
SCD_REG_ADD(targetWaveOffset, float)
SCD_REG_ADD(targetRampVal, float)
SCD_REG_ADD(targetRampGrad, float)
SCD_REG_ADD(targetTe, float)
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
SCD_REG_ADD(CH1_powerTempMax, float)
SCD_REG_ADD(CH2_powerTempMax, float)
SCD_REG_ADD(PT100_1_2_temp[0], float)
SCD_REG_ADD(PT100_1_2_temp[1], float)
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
SCD_REG_ADD(thetaRDC_raw_offset_CH1, uint16_t)
SCD_REG_ADD(thetaRDC_raw_offset_CH2, uint16_t)
SCD_REG_ADD(UdcAdrc.x1, float)
SCD_REG_ADD(UdcAdrc.e_u, float)
SCD_REG_ADD(UdcAdrc.e1, float)
SCD_REG_ADD(UdcAdrc.z1, float)
SCD_REG_ADD(UdcAdrc.z2, float)
SCD_REG_ADD(UdcAdrc.out_pi, float)
SCD_REG_ADD(UdcAdrc.out_smc, float)
SCD_REG_ADD(UdcAdrc.out_eso, float)
SCD_REG_ADD(UdcAdrc.u, float)
SCD_REG_ADD(RDV_err_check, function)
SCD_REG_ADD(adcOffset_init, function)
SCD_REG_ADD(scd_Udc_set, function)
SCD_REG_ADD(sram_init, function)
SCD_REG_ADD(ad2s1210_ClaAccModeEn, function)
SCD_REG_END(_1)
]]

-- 以下为scd内部执行函数，勿随便更改
function scd_dump(listNum, dumpNums)
    -- 参数检查
    if type(listNum) ~= "number" then
        print("参数listNum错误");
        return;
    end

    if type(dumpNums) ~= "number" then
        print("参数dumpNums错误");
        return;
    end

    scd_dump_impl(listNum, dumpNums);
end

function scd_dumpOut(colCnt, method)
    -- 参数检查
    if type(colCnt) ~= "number" then
        print("参数colCnt错误");
        return;
    end

    if type(method) ~= "string" then
        print("参数method错误");
        return;
    end

    scd_dumpOut_impl(colCnt, method);
end

function scd_sendStr(strToSend)
    -- 参数检查
    if type(strToSend) ~= "string" then
        print("参数strToSend错误");
    end

    scd_sendStr_impl(strToSend);
end

function scd_setVar(listNum, setVar)
    -- 参数检查
    if type(listNum) ~= "number" then
        print("参数listNum错误");
        return;
    end

    if type(setVar) ~= "number" then
        print("参数setVar错误");
        return;
    end

    scd_sendStr("set" .. (listNum - 1) .. [[#]] .. setVar .. [[!!!!]]);
    scd_sendStr("set" .. (listNum - 1) .. [[#]] .. setVar .. [[!!!!]]);
end

function scd_refresh()
    scd_sendStr([[chg0#1!!!!]]);
    scd_sendStr([[chg0#1!!!!]]);
end

function scd_getVar(listNum)
    -- 参数检查
    if type(listNum) ~= "number" then
        print("参数listNum错误");
        return;
    end

    return scd_getVar_impl(listNum);
end

function scd_call(listNum, paraNum)
    -- 参数检查
    if type(listNum) ~= "number" then
        print("参数listNum错误");
        return;
    end

    if type(paraNum) ~= "number" then
        print("参数paraNum错误");
        return;
    end

    scd_sendStr("call" .. (listNum - 1) .. [[#]] .. paraNum .. [[!!!!]]);
    scd_sendStr("call" .. (listNum - 1) .. [[#]] .. paraNum .. [[!!!!]]);
end

function scd_delayMs(ms)
    -- 参数检查
    if type(ms) ~= "number" then
        print("参数ms类型错误");
        return;
    end

    if ms < 20 then
        print("参数ms范围错误，至少20ms，误差50ms");
        return;
    end

    scd_delayMs_impl(ms)
end

-- 新增modbus API

function scd_mdbNewPort(portNum, baud, timeout, retryNum)
    -- 参数检查
    if type(portNum) ~= "number" then
        print("参数portNum类型错误");
        return;
    end
    if type(baud) ~= "number" then
        print("参数baud类型错误");
        return;
    end
    if type(timeout) ~= "number" then
        print("参数timeout类型错误");
        return;
    end
    if type(retryNum) ~= "number" then
        print("参数retryNum类型错误");
        return;
    end

    scd_mdbNewPort_impl(portNum, baud, timeout, retryNum)
end

function scd_mdbClosePort()

    scd_mdbClosePort_impl()
end

function scd_mdbReadRegF32(mdbAddr, regAddr)
    -- 参数检查
    if type(mdbAddr) ~= "number" then
        print("参数mdbAddr类型错误");
        return;
    end
    if type(regAddr) ~= "number" then
        print("参数regAddr类型错误");
        return;
    end

    return scd_mdbReadRegF32_impl(mdbAddr, regAddr)
end

function scd_rBox_init(portNum)
    -- 参数检查
    if type(portNum) ~= "number" then
        print("参数portNum类型错误");
        return;
    end

    scd_rBox_init_impl(portNum)
end

function scd_rBox_ctrl(rNo, sta)
    -- 参数检查
    if type(rNo) ~= "number" then
        print("参数rNo类型错误");
        return;
    end
    if type(sta) ~= "number" then
        print("参数sta类型错误");
        return;
    end

    scd_rBox_ctrl_impl(rNo, sta)
    scd_delayMs(250)
end

function scd_YaxisSet(name, low, up)
    -- 参数检查
    if type(name) ~= "string" then
        print("参数name类型错误");
        return;
    end
    if type(low) ~= "number" then
        print("参数low类型错误");
        return;
    end
    if type(up) ~= "number" then
        print("参数up类型错误");
        return;
    end

    scd_YaxisSet_impl(name, low, up)
end

function scd_valRangeSet(name, max1, min1)
    -- 参数检查
    if type(name) ~= "string" then
        print("参数name类型错误");
        return;
    end
    if type(max1) ~= "number" then
        print("参数max1类型错误");
        return;
    end
    if type(min1) ~= "number" then
        print("参数min1类型错误");
        return;
    end

    scd_valRangeSet_impl(name, max1, min1)
end

function scd_tabItemSelect(name)
    -- 参数检查
    if type(name) ~= "string" then
        print("参数name类型错误");
        return;
    end

    scd_tabItemSelect_impl(name)
end

function scd_plotItemSelect(name)
    -- 参数检查
    if type(name) ~= "string" then
        print("参数name类型错误");
        return;
    end

    scd_plotItemSelect_impl(name)
end
