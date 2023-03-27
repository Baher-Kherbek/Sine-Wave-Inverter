// Created by: Baher Kher Bek

int state1 =0;
int state2 =0;
int count1 = 0 ;int count2 = 0 ;
int b = 1 ;
short int sine[32]={0,25,49,73,96,118,137,159,177,193,208,220,231,239,245,249,250,249,245,239,231,220,208,193,177,159,137,118,96,73,49,25};
void interrupt(){    
TMR0=216;
INTCON.T0IF = 0 ;
if (count1<=31)
{
state1 = sine[count1];
state2 = 0 ;
count1 =count1 +1;
}
else if (count2<31)
{
state1 = 0;
state2 = sine[count2] ;
count2 =count2 +1;
}
else
{
count1 =0 ;
count2 =0 ;
 }

}
void main() {
TRISC = 0X00 ;
PWM1_init(16000);
PWM2_init(16000);
PWM1_Start();
PWM2_Start();
OPTION_REG = 0X07;
TMR0=216;
INTCON.GIE=1;
INTCON.T0IE = 1 ;
INTCON.T0IF = 0 ;
          // CLEAR TIMER0
while(1)
{

PWM1_Set_Duty(state1);
PWM2_Set_Duty(state2);
}
}
