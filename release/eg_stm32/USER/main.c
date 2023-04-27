#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "key.h"

#include "stdint.h"

volatile unsigned int taskNo = 0;

int16_t test1 = -1;
int32_t test2 = 2;
uint16_t test3 = 3;
uint32_t test4 = -4;
float test5 = 3.14;

float test6[10] = { 0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };

typedef struct {
    int16_t mTest1;
    int32_t mTest2;
    uint16_t mTest3;
    uint32_t mTest4;
    float mTest5;
} testStruct;

testStruct tStruct1 = { 1,-2,-3,4,5.5 };

testStruct tStruct2[10] = {
    { 1,-2,-3,4,5.5},
    { 1,-2,-3,4,5.5},
};

char lcdBuff[100];

/**
 * ��ʼ��������ָ������1�����ʣ�һ��Ϊ460800���������
 * ʹ����UART1������ԭ�ӵ�printf�����ͻ�������ã�������Ӧ�ط�ע�͵��ˣ�
 * �����ٵ�������ԭ�ӵ� uart_init ������
 * ע�⣬��ʵ��ʹ����DMA2 STREAM2��DMA2 STREAM7!ʹ����˫����ģʽ��
 * DMA �� NVIC �ж����ȼ�Ϊ 4-0 �� 4-1 �����ж����ȼ�����ڴ�!
 */
void DMAOfUart1_DBG_init(uint32_t baud);

int main(void)
{
    //����ϵͳ�ж����ȼ�����2
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    //��ʼ����ʱ����
    delay_init(168);
    //��ʼ�����Դ���
    DMAOfUart1_DBG_init(460800);
    //��ʼ��LED 
    LED_Init();
    //LCD��ʼ��
    LCD_Init();
    //������ʼ��
    KEY_Init();

    POINT_COLOR = RED;
    LCD_ShowString(50, 50, 300, 24, 24, "MOTOR CONTROL DEBUG e.g.");
    POINT_COLOR = BLACK;


    while (1)
    {
        snprintf(lcdBuff, 100, "test1:%d", test1);
        LCD_ShowString(50, 100, 300, 24, 24, "                                                           ");
        LCD_ShowString(50, 100, 300, 24, 24, lcdBuff);

        snprintf(lcdBuff, 100, "test2:%d", test2);
        LCD_ShowString(50, 150, 300, 24, 24, "                                                           ");
        LCD_ShowString(50, 150, 300, 24, 24, lcdBuff);

        snprintf(lcdBuff, 100, "test3:%u", test3);
        LCD_ShowString(50, 200, 300, 24, 24, "                                                           ");
        LCD_ShowString(50, 200, 300, 24, 24, lcdBuff);

        snprintf(lcdBuff, 100, "test4:%u", test4);
        LCD_ShowString(50, 250, 300, 24, 24, "                                                           ");
        LCD_ShowString(50, 250, 300, 24, 24, lcdBuff);

        snprintf(lcdBuff, 100, "test1:%f", test5);
        LCD_ShowString(50, 300, 300, 24, 24, "                                                           ");
        LCD_ShowString(50, 300, 300, 24, 24, lcdBuff);

        snprintf(lcdBuff, 100, "test6[5]:%f", test6[5]);
        LCD_ShowString(50, 350, 300, 24, 24, "                                                           ");
        LCD_ShowString(50, 350, 300, 24, 24, lcdBuff);

        snprintf(lcdBuff, 100, "tStruct1.mTest3:%u", tStruct1.mTest3);
        LCD_ShowString(50, 400, 300, 24, 24, "                                                           ");
        LCD_ShowString(50, 400, 300, 24, 24, lcdBuff);

        snprintf(lcdBuff, 100, "tStruct2[1].mTest2:%d", tStruct2[1].mTest2);
        LCD_ShowString(50, 450, 300, 24, 24, "                                                           ");
        LCD_ShowString(50, 450, 300, 24, 24, lcdBuff);
    }

    return 0;
}

void uart1Init(uint32_t baud) {
    //GPIO�˿�����
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //ʹ��GPIOAʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//ʹ��USART1ʱ��

    // �ȸ�λ
    USART_DeInit(USART1);

    //����1��Ӧ���Ÿ���ӳ��
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1); //GPIOA9����ΪUSART1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); //GPIOA10����ΪUSART1

    //USART1�˿�����
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //GPIOA9��GPIOA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
    GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ��PA9��PA10

    //USART1 ��ʼ������
    USART_InitStructure.USART_BaudRate = baud;//����������
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
    USART_Init(USART1, &USART_InitStructure); //��ʼ������1

    USART_Cmd(USART1, ENABLE);  //ʹ�ܴ���1 
}

/**
 * ////////////// �ṩ��λ��֧�ַ��� /////////////////////////
 */

#include "scd_inc.h"

 /**
  * @brief ע�����ʼ��β׺��ʶ����ʵ������
  */
#define SCD_REG_BEGIN(TYJ_SUFFIX)                                                                      \
    volatile unsigned char recBuff##TYJ_SUFFIX[2][SCD_REVBUFF_SIZE];                                   \
    volatile unsigned char printBuff##TYJ_SUFFIX[SCD_PRINTBUFF_SIZE];                                  \
    volatile unsigned char endBuff1##TYJ_SUFFIX[4] = {0x00, 0x00, 0x81, 0x7f};                         \
    volatile unsigned char endBuff2##TYJ_SUFFIX[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x7f}; \
    volatile unsigned char endBuff3##TYJ_SUFFIX[4] = {0x00, 0x00, 0x83, 0x7f};                         \
    static const int _begin_index##TYJ_SUFFIX = __LINE__;                                              \
    const struct TYJ_UNIT_STRUCT tyj_unit_struct##TYJ_SUFFIX[] = {

  /**
   * @brief ע��꣬�м䲻�ɼ�����л�ע��
   * @param TYJ_NAME �����Ĳ�������
   * @param TYJ_TYPE �����Ĳ�������
   */
  #define SCD_REG_ADD(TYJ_NAME, TYJ_TYPE)     \
       {                                       \
           (void *)&(TYJ_NAME), TYJ_##TYJ_TYPE \
                                               \
       },

   /**
    * @brief ע����β��β׺��ʶ����ʵ������
    */
   #define SCD_REG_END(TYJ_SUFFIX)                                                            \
    }                                                                                      \
    ;                                                                                      \
    static const int _end_index##TYJ_SUFFIX = __LINE__;                                    \
    struct SCD_CTRL_STRUCT scd##TYJ_SUFFIX;                                                \
    void scd_init##TYJ_SUFFIX()                                                            \
    {                                                                                      \
        scd##TYJ_SUFFIX._unit_struct = tyj_unit_struct##TYJ_SUFFIX;                        \
        scd##TYJ_SUFFIX.structToSendTab[0] = 0;                                            \
        scd##TYJ_SUFFIX.structToSendTab[1] = 9999;                                         \
        scd##TYJ_SUFFIX._recBuff = recBuff##TYJ_SUFFIX;                                    \
        scd##TYJ_SUFFIX._printBuff = printBuff##TYJ_SUFFIX;                                \
        scd##TYJ_SUFFIX._endbyte1 = endBuff1##TYJ_SUFFIX;                                  \
        scd##TYJ_SUFFIX._endbyte2 = endBuff2##TYJ_SUFFIX;                                  \
        scd##TYJ_SUFFIX._endbyte3 = endBuff3##TYJ_SUFFIX;                                  \
        scd##TYJ_SUFFIX.structNum = _end_index##TYJ_SUFFIX - _begin_index##TYJ_SUFFIX - 1; \
        scd##TYJ_SUFFIX.bufNum = 0;                                                        \
        scd##TYJ_SUFFIX.bytesRec = 0;                                                      \
        scd##TYJ_SUFFIX.structToSend = 0;                                                  \
        scd##TYJ_SUFFIX.byteToSend = 0;                                                    \
        scd##TYJ_SUFFIX.tempBuff = 0;                                                      \
        scd##TYJ_SUFFIX.sco_protocol_num = 0;                                              \
        scd##TYJ_SUFFIX.sco_protocol_num_next = 0;                                         \
        scd##TYJ_SUFFIX.structToSend2 = 0;                                                 \
        scd##TYJ_SUFFIX.byteToSend2 = 0;                                                   \
        scd##TYJ_SUFFIX.byteToSend3 = 0;                                                   \
        scd##TYJ_SUFFIX.structToSend3 = 0;                                                 \
        scd##TYJ_SUFFIX.dumpTarget = 0;                                                    \
        scd##TYJ_SUFFIX.dumpNumCnt = 0;                                                    \
        scd##TYJ_SUFFIX.dumpPkgCnt = 0;                                                    \
        scd##TYJ_SUFFIX.ifContPkg = 0;                                                     \
        scd##TYJ_SUFFIX.isPrintBusyFlg = 0;                                                \
        scd##TYJ_SUFFIX.byteToPrint = 0;                                                   \
        scd##TYJ_SUFFIX.byteToSend4 = 0;                                                   \
    }


    /**
     * @brief ע���1#scd�Ĺ۲�����
     * SCD_REG_BEGIN �� SCD_REG_END �䲻����ӿ��л�ע�ͣ�
     */
SCD_REG_BEGIN(_1)
SCD_REG_ADD(test1, int16_t)
SCD_REG_ADD(test2, int32_t)
SCD_REG_ADD(test3, uint16_t)
SCD_REG_ADD(test4, uint32_t)
SCD_REG_ADD(test5, float)
SCD_REG_ADD(test6[5], float)
SCD_REG_ADD(tStruct1.mTest3, uint16_t)
SCD_REG_ADD(tStruct2[1].mTest2, int32_t)
SCD_REG_END(_1)

