#include "iarduino_HC_SR04_int.h"

volatile	iarduino_HC_SR04_int_volatile_class	iHCSR04iVC;

//		���������� ����������
void	HC_func_IRQ0(){if(iHCSR04iVC.HC_flag_REQUEST[0]){if(iHCSR04iVC.HC_flag_ANSWER[0]){iHCSR04iVC.HC_flag_REQUEST[0]=0; iHCSR04iVC.HC_time_ANSWER[0]=micros()-iHCSR04iVC.HC_time_REQUEST[0];}else{iHCSR04iVC.HC_flag_ANSWER[0]=1; iHCSR04iVC.HC_time_REQUEST[0]=micros();}}}
void	HC_func_IRQ1(){if(iHCSR04iVC.HC_flag_REQUEST[1]){if(iHCSR04iVC.HC_flag_ANSWER[1]){iHCSR04iVC.HC_flag_REQUEST[1]=0; iHCSR04iVC.HC_time_ANSWER[1]=micros()-iHCSR04iVC.HC_time_REQUEST[1];}else{iHCSR04iVC.HC_flag_ANSWER[1]=1; iHCSR04iVC.HC_time_REQUEST[1]=micros();}}}
void	HC_func_IRQ2(){if(iHCSR04iVC.HC_flag_REQUEST[2]){if(iHCSR04iVC.HC_flag_ANSWER[2]){iHCSR04iVC.HC_flag_REQUEST[2]=0; iHCSR04iVC.HC_time_ANSWER[2]=micros()-iHCSR04iVC.HC_time_REQUEST[2];}else{iHCSR04iVC.HC_flag_ANSWER[2]=1; iHCSR04iVC.HC_time_REQUEST[2]=micros();}}}
void	HC_func_IRQ3(){if(iHCSR04iVC.HC_flag_REQUEST[3]){if(iHCSR04iVC.HC_flag_ANSWER[3]){iHCSR04iVC.HC_flag_REQUEST[3]=0; iHCSR04iVC.HC_time_ANSWER[3]=micros()-iHCSR04iVC.HC_time_REQUEST[3];}else{iHCSR04iVC.HC_flag_ANSWER[3]=1; iHCSR04iVC.HC_time_REQUEST[3]=micros();}}}
void	HC_func_IRQ4(){if(iHCSR04iVC.HC_flag_REQUEST[4]){if(iHCSR04iVC.HC_flag_ANSWER[4]){iHCSR04iVC.HC_flag_REQUEST[4]=0; iHCSR04iVC.HC_time_ANSWER[4]=micros()-iHCSR04iVC.HC_time_REQUEST[4];}else{iHCSR04iVC.HC_flag_ANSWER[4]=1; iHCSR04iVC.HC_time_REQUEST[4]=micros();}}}
void	HC_func_IRQ5(){if(iHCSR04iVC.HC_flag_REQUEST[5]){if(iHCSR04iVC.HC_flag_ANSWER[5]){iHCSR04iVC.HC_flag_REQUEST[5]=0; iHCSR04iVC.HC_time_ANSWER[5]=micros()-iHCSR04iVC.HC_time_REQUEST[5];}else{iHCSR04iVC.HC_flag_ANSWER[5]=1; iHCSR04iVC.HC_time_REQUEST[5]=micros();}}}
void	HC_func_IRQ6(){if(iHCSR04iVC.HC_flag_REQUEST[6]){if(iHCSR04iVC.HC_flag_ANSWER[6]){iHCSR04iVC.HC_flag_REQUEST[6]=0; iHCSR04iVC.HC_time_ANSWER[6]=micros()-iHCSR04iVC.HC_time_REQUEST[6];}else{iHCSR04iVC.HC_flag_ANSWER[6]=1; iHCSR04iVC.HC_time_REQUEST[6]=micros();}}}
void	HC_func_IRQ7(){if(iHCSR04iVC.HC_flag_REQUEST[7]){if(iHCSR04iVC.HC_flag_ANSWER[7]){iHCSR04iVC.HC_flag_REQUEST[7]=0; iHCSR04iVC.HC_time_ANSWER[7]=micros()-iHCSR04iVC.HC_time_REQUEST[7];}else{iHCSR04iVC.HC_flag_ANSWER[7]=1; iHCSR04iVC.HC_time_REQUEST[7]=micros();}}}
void	HC_func_IRQ8(){if(iHCSR04iVC.HC_flag_REQUEST[8]){if(iHCSR04iVC.HC_flag_ANSWER[8]){iHCSR04iVC.HC_flag_REQUEST[8]=0; iHCSR04iVC.HC_time_ANSWER[8]=micros()-iHCSR04iVC.HC_time_REQUEST[8];}else{iHCSR04iVC.HC_flag_ANSWER[8]=1; iHCSR04iVC.HC_time_REQUEST[8]=micros();}}}
void	HC_func_IRQ9(){if(iHCSR04iVC.HC_flag_REQUEST[9]){if(iHCSR04iVC.HC_flag_ANSWER[9]){iHCSR04iVC.HC_flag_REQUEST[9]=0; iHCSR04iVC.HC_time_ANSWER[9]=micros()-iHCSR04iVC.HC_time_REQUEST[9];}else{iHCSR04iVC.HC_flag_ANSWER[9]=1; iHCSR04iVC.HC_time_REQUEST[9]=micros();}}}

//		���������� ���������� ������					(TRIG,		ECHO		)
		iarduino_HC_SR04_int::iarduino_HC_SR04_int		(uint8_t i, uint8_t j	){
//			��������� ������ ������� � ����������
			HC_pins_TRIG=i;
			HC_pins_ECHO=(digitalPinToInterrupt(j)==NOT_AN_INTERRUPT)?2:j;
			HC_ints_IRQ = digitalPinToInterrupt(HC_pins_ECHO);
//			������������� ����� ������ �������
			pinMode(HC_pins_TRIG, OUTPUT);
			pinMode(HC_pins_ECHO, INPUT);
//			���������� ��������� ���������� HC_ints_IRQ �� ���� �� ������� HC_func_IRQ
			#ifdef __SAM3X8E__ 
				switch(HC_ints_IRQ){
					case 0:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ0, CHANGE); break;
					case 1:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ1, CHANGE); break;
					case 2:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ2, CHANGE); break;
					case 3:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ3, CHANGE); break;
					case 4:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ4, CHANGE); break;
					case 5:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ5, CHANGE); break;
					case 6:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ6, CHANGE); break;
					case 7:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ7, CHANGE); break;
					case 8:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ8, CHANGE); break;
					case 9:	attachInterrupt(HC_pins_ECHO, HC_func_IRQ9, CHANGE); break;
				}
			#else              
				switch(HC_ints_IRQ){
					case 0:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ0, CHANGE); break;
					case 1:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ1, CHANGE); break;
					case 2:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ2, CHANGE); break;
					case 3:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ3, CHANGE); break;
					case 4:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ4, CHANGE); break;
					case 5:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ5, CHANGE); break;
					case 6:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ6, CHANGE); break;
					case 7:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ7, CHANGE); break;
					case 8:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ8, CHANGE); break;
					case 9:	attachInterrupt(HC_ints_IRQ, HC_func_IRQ9, CHANGE); break;
				}
			#endif
//			������������� ������� ����������� �0� �� ������ TRIG
			digitalWrite(HC_pins_TRIG, LOW);
}

long	iarduino_HC_SR04_int::distance(int8_t i){								//	i: ������� ����������� � ����c���
			if(!iHCSR04iVC.HC_flag_REQUEST[HC_ints_IRQ]){						//	���� ������ ����� �� �����������, ��
				digitalWrite(HC_pins_TRIG, HIGH);								//	������������ ����� ������ ������� �� �� TRIG
				delayMicroseconds(10);											//	������ 10 ���
				digitalWrite(HC_pins_TRIG, LOW);								//	������������ ����� �������� ���� �� �� TRIG
				iHCSR04iVC.HC_flag_REQUEST[HC_ints_IRQ]=1;						//	������������ ���� �������� �����
				iHCSR04iVC.HC_flag_ANSWER[HC_ints_IRQ]=0;						//	������� ���� ������� �������� ������
			}	HC_data_ANSWER =iHCSR04iVC.HC_time_ANSWER[HC_ints_IRQ];			//	�������� ��� ������
				HC_data_ANSWER*=sqrt(273+i);									//	������ ��������� �� �����������
				HC_data_ANSWER/=1000;											//	����� �� 1000
				if(HC_data_ANSWER>400){HC_data_ANSWER=400;}						//	���� ��������� ����� 400 �� (4 �) ������� �� �������
			return HC_data_ANSWER;
}