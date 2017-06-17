//	���������� ��� ������ � �������������� �������� ���������� HC-SR04: http://iarduino.ru/shop/Sensory-Datchiki/ultrazvukovogo-datchika-hc-sr04-rasstoyaniya-dvizheniya.html
//  ������: 1.0.0 (� �������������� ����������)
//  ��������� ������ ���������� �� ������ ������� �� ������: http://iarduino.ru/file/283.html
//  ��������� �������� ������� ����������� �������� �� ������: http://wiki.iarduino.ru/page/ultrazvukovoy-datchik-izmereniya-rasstoyaniya-hc-sr04/
//  ���������� �������� �������������� �������� �������� iarduino.ru � ����� �������� �������������� � ����������������!
//  ��� ���������� ��������� ��� ������� � �������������� ������ ����������, ��� �������, ��� � � ������,
//  � ��� ����� � � �������������� �����, ������ ��� ������������ ������: http://iarduino.ru
//  ����� ����������: ������� ����� sajaem@narod.ru
//  ���� � ��� �������� ����������� �������, �������� ���: shop@iarduino.ru

#ifndef iarduino_HC_SR04_int_h
#define iarduino_HC_SR04_int_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class	iarduino_HC_SR04_int{
	public:			iarduino_HC_SR04_int(uint8_t, uint8_t);	//	������������� ������	(����� TRIG, ����� ECHO)
		long		distance			(int8_t=23);		//	����������� ����������	([t�C])
	private:
		uint8_t		HC_pins_TRIG;							//	� ������ ������������� � TRIG
		uint8_t		HC_pins_ECHO;							//	� ������ ������������� � ECHO
		uint8_t		HC_ints_IRQ;							//	� ���������� ��� ������  ECHO
		long		HC_data_ANSWER;							//	���������� ��� �������� ������
};

class	iarduino_HC_SR04_int_volatile_class{
	public:
		bool		HC_flag_REQUEST[10];					//	���� ������� ������� ������
		bool		HC_flag_ANSWER[10];						//	���� ������ �������� ������
		uint32_t	HC_time_REQUEST[10];					//	����� �������� ������� ������
		uint32_t	HC_time_ANSWER[10];						//	����� ��������� � ������� ������� �� ��������� ������
};


#endif
